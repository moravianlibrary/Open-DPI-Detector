#ifndef _DPIWRITER_H
#define _DPIWRITER_H

#include <fstream>
#include<stdio.h>
#include "FileManipulationException.h"
#include <iostream>
#include <Magick++.h>
#include <string>
#include <sstream>

//type for storing byte content of image file
struct BufferArray_t {
  char* buffer;
  int length;
};

/*
 * class for saving DPI to the file 
 */
class DPIWriter
{
public:
	/*
	 * constructor
	 */
	DPIWriter(void);
	/*i
	 * destructor
	 */
	~DPIWriter(void);
	/**
	 * public function for saving DPI into file
	 * @param fileName name of file to which will be DPI saved
	 * @param dpi value that will be saved
	 * @throw FileManipulationException if any error occured
	 */
	void writeDPI(char* fileName, int dpi);
private:
	BufferArray_t* readDataJP2(char* fileName);
	void processDataJP2(BufferArray_t* buffer, int dpi);
	void writeDataJP2(char* fileName, BufferArray_t* buffer);
	bool isJPEG2000(string fileName);
};
#endif
