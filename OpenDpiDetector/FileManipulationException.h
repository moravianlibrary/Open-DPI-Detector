#ifndef _FILE_MANIPULATION_EXCEPTION_H
#define _FILE_MANIPULATION_EXCEPTION_H
#include <cstring>
#include <sstream>
#include "DPIRuntimeException.h"
using namespace std;

/**
 * Exception thrown if error occurs during saving phase
 */
class FileManipulationException: public DPIRuntimeException
{
  public:
	  /**
	   * constructor
	   */
	  FileManipulationException(string pMsg, string pFunc)
				: msg(pMsg), funcName(pFunc) {}
	
	  /**
	   * returns message of exception
	   * @return message of exception
	   */
	 virtual string getMessage()
	{
		return msg;
	}
	 /**
	  * returns function where exception was thrown
	  * @return name of function where it was thrown
	  */
	virtual string getfunction()
	{
		return funcName;
	}
	/**
	 * display full format of exception
	 * @return string with message of exception and name of function where it was thrown
	 */
    virtual string display()
    {
        ostringstream out;
		out << "IO ERROR <" << msg << ">"
            << "in function " << funcName << ends;
        return out.str();
    }
  protected:
    string msg;/**< message of exception */
    string funcName;/**< name of function where it was thrown */
};
#endif
