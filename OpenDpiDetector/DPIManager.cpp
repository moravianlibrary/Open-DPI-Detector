#include "DPIManager.h"

using namespace std;

DPIManager::DPIManager()
{	
}
DPIManager::~DPIManager(void)
{
}

int DPIManager::DetectFileDPI(char* fileName, Orientation_t orientation, void* console)
{
	if (!fileExists(fileName))
	{
		throw IllegalParameterException("File does not exist - " + (string) fileName);
	}
	int dpi;
	DetectionCore detector = DetectionCore(orientation);
	DPIWriter writer;
	//register event handlers
	OperationFinishedEvent opFinished;
	OperationFinishedEventListener opFinishedListener;
	opFinishedListener.hookEvent(&opFinished);
	try
	{
		dpi = detector.detectDPI(fileName);//detect dpi
		__raise opFinished.OperationFinishedResultEvent(DETECT_FILE,fileName,dpi,1,0,console);
	}
	catch(DetectionFailureException ex)
	{
		//inform about unsuccessful operation and log exception
		logDPIRuntimeException(&ex);
		dpi = -1;
		__raise opFinished.OperationFinishedResultEvent(DETECT_FILE,fileName,dpi,0,1,console);
	}
	opFinishedListener.unhookEvent(&opFinished);
	return dpi;
}

int DPIManager::SaveFileDPI(char* fileName, int dpi, void* console)
{
	//register event handlers
	OperationFinishedEvent opFinished;
	OperationFinishedEventListener opFinishedListener;
	opFinishedListener.hookEvent(&opFinished);
	if (!fileExists(fileName))
	{
		throw IllegalParameterException("File does not exist - " + (string) fileName);
	}
	if(dpi<=0 || dpi>65535)
	{
		throw IllegalParameterException("DPI must be between 1 and 65535 inclusive");
	}
	int result;
	try
	{
		DPIWriter writer;
		if(!isSupportedType(string(fileName)))
		{
			throw FileManipulationException( "File "+string(fileName)+" is not supported", __FUNCTION__);
		}
		writer.writeDPI(fileName,dpi);//write DPI to file
		__raise opFinished.OperationFinishedResultEvent(WRITE_FILE,fileName,dpi,1,0,console);
		result = 0;
	}
	catch(FileManipulationException ex)
	{
		//log exception and inform about error
		logDPIRuntimeException(&ex);
		__raise opFinished.OperationFinishedResultEvent(WRITE_FILE,fileName,dpi,0,1,console);
		result = -1;
	}
	opFinishedListener.unhookEvent(&opFinished);
	return result;
}

int DPIManager::SaveFolderDPI(char* folderName, int dpi, void* console)
{
	int numOfGood = 0;
	int numOfErrors = 0;
	if (dpi <= 0 || dpi>65535)
	{
		throw IllegalParameterException("DPI must be between 1 and 65535 inclusive");
	}
	vector<string> folderContain = vector<string>();
	int total = getdir(folderName,folderContain);//save content of folder to vector
	string fullFolderName = createFullFolderName(folderName);//add / or \ to the foldername
	int counter = 0;
	//register event handlers
	ProgressEvent progress;
	OperationFinishedEvent opFinished;
	ProgressListener listener;
	OperationFinishedEventListener opFinishedListener;
	listener.hookEvent(&progress);
	opFinishedListener.hookEvent(&opFinished);
	IsProcessingStopped = false;//set stopping token to false
	for (vector<string>::iterator i = folderContain.begin(); i != folderContain.end(); i++)
	{
		if (IsProcessingStopped)//if signal for stopping was send
		{
			break;
		}
		counter++;
		string fileName = fullFolderName + i->data();
		if (SaveFileDPI((char*) fileName.c_str(),dpi,console)==0)
		{
			numOfGood++;//successfully processed
		}
		else
		{
			numOfErrors++;//error occured
		}
		__raise progress.ProgressChangedEvent(counter,total,console);//inform about progress
	}
	__raise opFinished.OperationFinishedResultEvent(WRITE_FOLDER,folderName,dpi,numOfGood,numOfErrors,console);
	opFinishedListener.unhookEvent(&opFinished);
	listener.unhookEvent(&progress);
	return numOfErrors;
}

int DPIManager::DetectAndSaveFileDPI(char* fileName, Orientation_t orientation, void* console)
{
	//this method does not need events, it is fully covered by detectFileDPI and saveFileDPI
	if (!fileExists(fileName))
	{
		throw IllegalParameterException("File does not exist - " + (string) fileName);
	}
	if (isSupportedType(string(fileName)))
	{
		int dpi = DetectFileDPI(fileName,orientation,console);
		if(dpi>0)
		{
			if(SaveFileDPI(fileName,dpi,console)==0)
			{
				return dpi;
			}
		}
		return -1;
	}
	else
	{
		logDPIRuntimeException(&FileManipulationException("File "+string(fileName)+" is not supported",__FUNCTION__));
		return -1;
	}
}
int DPIManager::DetectAndSaveFolderDPI(char* folderName, Orientation_t orientation, void* console)
{
	int numOfGood = 0;
	int numOfErrors = 0;
	vector<string> folderContain = vector<string>();
	int total = getdir(folderName,folderContain);
	string fullFolderName = createFullFolderName(folderName);
	int counter = 0;
	//register event handlers
	ProgressEvent progress;
	OperationFinishedEvent opFinished;
	ProgressListener listener;
	OperationFinishedEventListener opFinishedListener;
	listener.hookEvent(&progress);
	opFinishedListener.hookEvent(&opFinished);
	IsProcessingStopped = false;//reset token
	for (vector<string>::iterator i = folderContain.begin(); i != folderContain.end(); i++)
	{
		if (IsProcessingStopped)//processing was stopped
		{
			break;
		}
		counter++;
		string fileName = fullFolderName + i->data();
		if(DetectAndSaveFileDPI((char*)fileName.c_str(), orientation, console) > 0)
			{
				numOfGood++;
			}
		else
			{
				numOfErrors++;
			}
		__raise progress.ProgressChangedEvent(counter,total, console);//inform about progress
	}
	//show result info
	__raise opFinished.OperationFinishedResultEvent(DETECT_WRITE_FOLDER,folderName,0,numOfGood,numOfErrors,console);
	opFinishedListener.unhookEvent(&opFinished);
	listener.unhookEvent(&progress);
	return numOfErrors;
}
	//saves content of directory to vector
int DPIManager::getdir (string dir, vector<string> &files)
 {
	DIR *dp;
	struct dirent *dirp;
	if((dp = opendir(dir.c_str())) == NULL) 
	{
		throw IllegalParameterException("Could not open entered folder "+ dir);
	}
	int counter = 0;
	while ((dirp = readdir(dp)) != NULL) 
	{
		if (isSupportedType(dirp->d_name))
		{
			//add it to vector
			files.push_back(string(dirp->d_name));
			counter++;
		}
		if(isBackupType(dirp->d_name))
		{

			string backupName = dirp->d_name;
			string originalName = backupName.substr(0,backupName.length()-10);
			string previousName = files.back();//pop last file added to vector
			//if these names are same, delete backup, else cut extension and add it
			//to vector for processing
			if (previousName != originalName)
			{
				rename((char*)backupName.c_str(),(char*)originalName.c_str());
				files.push_back(originalName);
				counter++;
			}
			else
			{
				remove(dirp->d_name);
			}
		}
	}
	closedir(dp);
	return counter;
 }

string DPIManager::createFullFolderName(char* folderName)
{
	string fullFolderName = (string) folderName;
		// add / behind folder name if on OS with / and not already at the end
		if (fullFolderName.rfind('/') != -1 && fullFolderName.rfind('/') != fullFolderName.length()-1 )
		{
			fullFolderName += "/";
		}
		// add \ behind folder name if on OS with \ and not already at the end
		else if(fullFolderName.rfind('\\') != -1 && fullFolderName.rfind('\\') != fullFolderName.length()-1)
		{
			fullFolderName += "\\";
		}
		return fullFolderName;
}
//adds info about date and time and log exception to file error.log
void DPIManager::logDPIRuntimeException(DPIRuntimeException *ex)
	{
		time_t rawtime;
		struct tm * timeinfo;
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		ofstream fos("error.log", ios::out | ios::app);
		fos << "\n"<<asctime(timeinfo) <<"	" << ex->display();
		fos.close();
	}
//tells whether file exists
bool DPIManager::fileExists(char *filename)
{
  ifstream ifile(filename);
  bool exist = ifile;
  ifile.close();
  return exist;
}

bool DPIManager::isSupportedType(string fileName)
{
	int idx;
	idx = fileName.rfind('.');
	if(idx != std::string::npos)
	{
		string extension = fileName.substr(idx+1);
		return (stricmp(extension.c_str(), "jp2")==0 || stricmp(extension.c_str(), "jpg")==0 
			|| stricmp(extension.c_str(), "jpeg")==0 || stricmp(extension.c_str(), "tif")==0
			|| stricmp(extension.c_str(), "tiff")==0 || stricmp(extension.c_str(), "png")==0
			|| stricmp(extension.c_str(), "jpm")==0);
	}
	else
	{
		return false;
	}
}

bool DPIManager::isBackupType(string fileName)
{
	int idx;
	idx = fileName.rfind('.');
	if(idx != std::string::npos)
	{
		string extension = fileName.substr(idx+1);
		return (stricmp(extension.c_str(), "dpibackup") == 0);
	}
	else
	{
		return false;
	}
}