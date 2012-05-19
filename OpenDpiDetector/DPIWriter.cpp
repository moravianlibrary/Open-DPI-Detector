#include "DPIWriter.h"

using namespace std;
using namespace Magick;

DPIWriter::DPIWriter(void)
{
}

DPIWriter::~DPIWriter(void)
{
}

void DPIWriter::writeDPI(char* fileName, int dpi)
{
	// Initialize ImageMagick install location (needed for Windows)
	InitializeMagick(".");
	if(isJPEG2000(fileName))//if is .jpm or .jp2 (ImageMagick can't handle that)
	{
		BufferArray_t* buffer = readDataJP2(fileName);//read byte content from file
		try
		{
			processDataJP2(buffer, dpi);//add DPI to content of file
		}
		catch(FileManipulationException ex)
		{
			//release memory for buffer and throw exception
			delete [] buffer->buffer;
			delete [] buffer;
			string errMs= ex.getMessage() + " : " + fileName;
			throw FileManipulationException(errMs,ex.getfunction());
		}
		string newName = string(fileName)+".DPIBackup";//create backup filename
		writeDataJP2((char*) newName.c_str(), buffer);//save buffer to backup file
		remove(fileName);
		rename(newName.c_str(), fileName);//rename backup to original name
		//release used memory
		delete [] buffer->buffer;
		delete [] buffer;
		buffer=0;
	}
	else
	{
		string dpiString;
		stringstream out;
		out << dpi;
		dpiString = out.str();//change int to string
		try { 
		// Read a file into image object 
			Image image( fileName );
			string newName = string(fileName)+".DPIBackup";
			image.density(dpiString);
			image.resolutionUnits(MagickCore::ResolutionType::PixelsPerInchResolution);
			image.write(newName);
			remove(fileName);
			rename(newName.c_str(), fileName);
		}
		catch( Exception &error_ ) //catch Magick++ exception
		{ 
			throw FileManipulationException(error_.what(),__FUNCTION__);  
		}
		catch(...) //catch other possible exceptions
		{ 
			throw FileManipulationException("Error when renaming file",__FUNCTION__);  
		}
	}
}

//reads data and saves them to buffer
BufferArray_t* DPIWriter::readDataJP2(char* fileName)
{
	ifstream fis(fileName,ios::binary);
	if (!fis.is_open()){
		string errMs="Could not open file " + (string) fileName;
		throw FileManipulationException(errMs,__FUNCTION__);
	}
	fis.seekg (0, ios::end);
	int length = fis.tellg();// get length of file:
	fis.seekg (0, ios::beg);
	
	char* buffer = new char [length];
	try{
		fis.read (buffer,length);//read all data to buffer
		fis.close();
	}
	catch(...)
	{
		string errMs="Could not read/close file " + (string) fileName;
		throw FileManipulationException(errMs,__FUNCTION__);
	}
	BufferArray_t* bufferArray = new BufferArray_t;
	bufferArray->buffer = buffer;
	bufferArray->length = length;
	return bufferArray;
}

//adds or modify DPI value in data in buffer
void DPIWriter::processDataJP2(BufferArray_t* bufferArray, int dpi)
{
	if(bufferArray == 0 || bufferArray->buffer == 0)
	{
		throw FileManipulationException("Could not process data, buffer was null", __FUNCTION__);
	}
	if(dpi>65535)
	{
		throw FileManipulationException("Could not process data, dpi too high: "+dpi, __FUNCTION__);
	}
	char* buffer = bufferArray->buffer;
	
	int idx = 0;
	//finds resc string in data
	for (int i=0; i<bufferArray->length; i++)
	{
		if (buffer[i] == 'r'&& buffer[i+1]=='e' && buffer[i+2]=='s' && buffer[i+3]=='c')
		{
			idx = i;
		}
	}
	int a = dpi/256;//set first byte of DPI
	int b = dpi%256;//set second byte of DPI
	if(idx == 0)//DPI data not present in file
	{
		char endOfHeader = buffer[35] +35;//end of header, write new part imediately behind that
										  //on byte 35 starts header and on this byte is saved its length
		char* buffer1 = new char [(bufferArray->length)+26];//length of the DPI part is 26 bytes
		//copy old part of header
		for(int i = 0; i<endOfHeader;i++)
		{
			buffer1[i] = buffer[i];
		}
		buffer1[35] += 26;
		//structure of DPI part of header
		char temp [26] = {26,'r','e','s',0x20,0,0,0,0x12,'r','e','s','c',a,b,0,0xFE,a,b,0,0xFE,4,4,0,0,0};
		//add new part of header
		for (int i=endOfHeader; i<endOfHeader+26;i++)
		{
			buffer1[i]= temp[i-endOfHeader];
		}
		//copy rest of the file
		for(int i=endOfHeader+26;i<(bufferArray->length+26) ;i++)
		{
			buffer1[i] = buffer[i-26];
		}
		delete [] bufferArray->buffer;
		bufferArray->buffer = buffer1;
		bufferArray->length += 26;
	}
	else//DPI data already in file (modify them)
	{
		buffer[idx+4] = (unsigned char) a;//horizontal DPI
		buffer[idx+5] = (unsigned char) b;
		buffer[idx+6] = 0;
		buffer[idx+8] = (unsigned char) a;//vertical DPI
		buffer[idx+9] = (unsigned char) b;
		buffer[idx+10] = 0;
	}
}
//saves buffer to file
void DPIWriter::writeDataJP2(char* fileName, BufferArray_t* bufferArray)
{
	char* buffer = bufferArray->buffer;
	try
	{
		ofstream fos(fileName, ios::binary);
		fos.write(buffer,bufferArray->length);
		fos.close();
	}
	catch(...)
	{
		delete [] bufferArray->buffer;
		delete [] bufferArray;
		string errMs="Could not write/close file " + (string) fileName;
		throw FileManipulationException(errMs,__FUNCTION__);
	}
}
//return true if file is jpeg 2000 (jp2 or jpm)
bool DPIWriter::isJPEG2000(string fileName)
{
	int idx;
	idx = fileName.rfind('.');
	if(idx != std::string::npos)
	{
		string extension = fileName.substr(idx+1);
		return (stricmp(extension.c_str(), "jp2")==0 || stricmp(extension.c_str(), "jpm")==0);
	}
	else
	{
		return false;
	}
}
