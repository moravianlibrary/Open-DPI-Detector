#ifndef _DPI_MANAGER_H
#define _DPI_MANAGER_H

#include <sys/types.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include "DetectionCore.h"
#include "DPIWriter.h"
#include "DetectionFailureException.h"
#include "IllegalParameterException.h"
#include "DPIRuntimeException.h"
#include "EnumTypes.h"
#include "ProgressEvent.h"
#include "ProgressListener.h"
#include "OperationFinishedEvent.h"
#include "OperationFinishedListener.h"

using namespace std;

/**
 * class providing interface for manipulation with detector and writer class
 */
class DPIManager
{
public:
	/**
	 * constructor
	 */
	DPIManager();
	/**
	 * destructor
	 */
	~DPIManager(void);
	/**
	 * detects DPI of a file
	 * @param fileName name of file that will be detected
	 * @param orientation position of calibration mark relative to document
	 * @param console pointer to resource for displaying of information, 0 means 
	 *        that standard output will be used
	 * @return detected DPI or -1 if error occured
	 */
	int DetectFileDPI(char* fileName, Orientation_t orientation, void* console=0);
	/**
	 * detects and saves DPI of a file
	 * @param fileName name of file that will be detected
	 * @param orientation position of calibration mark relative to document
	 * @param console pointer to resource for displaying of information, 0 means 
	 *        that standard output will be used
	 * @return detected DPI or -1 if error occured
	 */
	int DetectAndSaveFileDPI(char* fileName, Orientation_t orientation, void* console=0);
	/**
	 * detects and saves DPI of a folder
	 * @param folderName name of folder that's content will be detected
	 * @param orientation position of calibration mark relative to document
	 * @param console pointer to resource for displaying of information, 0 means 
	 *        that standard output will be used
	 * @return number of errors during the process
	 */
	int DetectAndSaveFolderDPI(char* folderName, Orientation_t orientation, void* console=0);
	/**
	 * savess DPI of a file
	 * @param fileName name of file that will be detected
	 * @param dpi dpi that will be saved
	 * @param console pointer to resource for displaying of information, 0 means 
	 *        that standard output will be used
	 * @return 0 if successful or -1 if error occured
	 */
	int SaveFileDPI(char* fileName, int dpi, void* console=0);
	/**
	 * saves DPI of a folder
	 * @param folderName name of folder that will be detected
	 * @param orientation position of calibration mark relative to document
	 * @param console pointer to resource for displaying of information, 0 means 
	 *        that standard output will be used
	 * @return number of errors during process
	 */
	int SaveFolderDPI(char* folderName, int dpi, void* console=0);
	/**
	 * indicates whether file exist
	 * @param fileName file that is looking for
	 * @return true if file exists false otherwise
	 */
	static bool fileExists(char* fileName);
	/**
	 * token indicating whether processing should be stopped
	 */
	bool IsProcessingStopped;

private:
	bool isSupportedType(string fileName);//if is one of the currently supported types
	bool isBackupType(string fileName);//if is .DPIBackup
	int getdir(string dir, vector<string> &files);//get content of directory
	string createFullFolderName(char* folderName);//adds / or \ to the directory
	void logDPIRuntimeException(DPIRuntimeException* ex);//logs exception to the file
};
#endif