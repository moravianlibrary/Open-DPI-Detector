#include <QApplication>
#include "dialog.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <qtextcodec.h>
#ifdef Q_OS_WIN32
	#include <windows.h>
#endif

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	if(argc<=1)
	{
#ifdef Q_OS_WIN32
		FreeConsole();
#endif
		Dialog dialog;
		dialog.show();
		return app.exec();
	}
	else
	{
		DPIManager manager;
		string detectionType = string(argv[1]);
		transform(detectionType.begin(), detectionType.end(),detectionType.begin(), tolower );
		if(detectionType == "/h")
		{
			cout<<"SYNTAX: <type of operation>  <name of file or folder>  <orientation or DPI>"<<endl;
			cout<<"Type of operation can be:"<<endl;
			cout<<"		/d for detection of file"<<endl;
			cout<<"		/dw for detection and writing DPI for file or folder"<<endl;
			cout<<"		/w for writing DPI for file or folder"<<endl;
			cout<<"Name of file or folder is absolute path or relative path from application director"<<endl;
			cout<<"If parameters /d or /dw was used, third parameter is orientation"<<endl;
			cout<<"		orientation is position of calibration mark relative to document. Supported values: up, down, right, left"<<endl;
			cout<<"If parameter /w was used,  third parameter is DPI, that will be written"<<endl;
			cout<<"		DPI must be integer 1 - 65535 inclusive"<<endl;
			return 0;
		}
		else if(detectionType == "/w")
		{
			if(argc < 4)
			{
				cerr<<"Not enough parameters, syntax is: /w name dpi, where name is name of file or folder and dpi is integer larger than 0"<<endl;
				return -13;
			}
			DIR *dp;
			if (DPIManager::fileExists(argv[2]))
			{
				int dpi = atoi(argv[3]);
				if (dpi > 0)
				{
					cout<<"Starting saving DPI"<<endl;
					int result = manager.SaveFileDPI(argv[2],dpi);
					return result;
				}
				else
				{
					cerr << "DPI must be greater than 0"<<endl;
					return -3;
				}
			}
			else if ((dp = opendir(argv[2])) != NULL)
			{
				closedir(dp);
				int dpi = atoi(argv[3]);
				if (dpi >0)
				{
					cout<<"Starting saving DPI"<<endl;					
					int errors = manager.SaveFolderDPI(argv[2],dpi);
					return errors;
				}
				else
				{
					cerr << "DPI must be greater than 0"<<endl;
					return -3;
				}
			}
			else
			{
				cerr<<"File or folder " << argv[2]<< " does not exist"<<endl;
				return -2;
			}
		}
		else if(detectionType == "/d")
		{
			if(argc < 4)
			{
				cerr<<"Not enough parameters, syntax is: /d name orientation, where name is name of file orientation is up, right, down or left"<<endl;
				return -13;
			}
			if (DPIManager::fileExists(argv[2]))
			{
				string orientation = string(argv[3]);
				transform(orientation.begin(), orientation.end(),orientation.begin(), tolower );
				Orientation_t ori;
				if (orientation == "up")
				{
					ori = UPPER_SIDE;
				}
				else if(orientation == "down")
				{
					ori = BOTTOM_SIDE;
				}
				else if (orientation == "left" )
				{
					ori = LEFT_SIDE;
				}
				else if (orientation == "right" )
				{
				ori = RIGHT_SIDE;
				}
				else
				{
					cerr<<"orientation "<<argv[3]<<" is wrong, it must be up, down, left or right"<<endl;
					return -3;
				}
				cout<<"Starting detecting DPI"<<endl;
				int result = manager.DetectFileDPI(argv[2],ori);
				return result;
			}
			else
			{
				cerr<<"File " << argv[2]<< " does not exist"<<endl;
				return -2;
			}
		}
		else if(detectionType == "/dw")
		{
			if(argc < 4)
			{
				cerr<<"Not enough parameters, syntax is: /w name dpi, where name is name of file or folder and dpi is integer larger than 0"<<endl;
				return -13;
			}
			string orientation = string(argv[3]);
			transform(orientation.begin(), orientation.end(),orientation.begin(), tolower );
			Orientation_t ori;
			if (orientation == "up")
			{
				ori = UPPER_SIDE;
			}
			else if(orientation == "down")
			{
				ori = BOTTOM_SIDE;
			}
			else if (orientation == "left" )
			{
				ori = LEFT_SIDE;
			}
			else if (orientation == "right" )
			{
			ori = RIGHT_SIDE;
			}
			else
			{
				cerr<<"orientation "<<argv[3]<<" is wrong, it must be up, down, left or right"<<endl;
				return -3;
			}
			DIR *dp;
			if (DPIManager::fileExists(argv[2]))
			{
				cout<<"Starting detecting and saving DPI"<<endl;
				int result = manager.DetectAndSaveFileDPI(argv[2],ori);
				return result;
			}
			else if ((dp = opendir(argv[2])) != NULL)
			{
				closedir(dp);
				cout<<"Starting detecting and saving DPI"<<endl;
				int errors = manager.DetectAndSaveFolderDPI(argv[2],ori);
				return errors;
			}
			else
			{
			cerr<<"File or folder " << argv[2]<< " does not exist"<<endl;
			return -2;
			}
		}
		else
		{
			cerr<< "Wrong parameter first parameter, must be /d for detection,"
			<<"/w for writing specified DPI, /dw for detection and writing DPI";
			return -1;
		}
	}
}