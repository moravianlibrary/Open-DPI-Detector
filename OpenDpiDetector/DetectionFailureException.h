#ifndef _DETECTION_FAILURE_EXCEPTION_H
#define _DETECTION_FAILURE_EXCEPTION_H
#include <cstring>
#include <sstream>
#include "DPIRuntimeException.h"

using namespace std;

/**
 * Exception thrown if error occurs during detection phase
 */
class DetectionFailureException : public DPIRuntimeException
{
  public:
	  /**
	   * constructor
	   */
	  DetectionFailureException(string pMsg, string pFunc)
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
		out << "ERROR <" << msg << ">"
            << "in function " << funcName << ends;
        return out.str();
    }
  protected:
    string msg;/**< message of the exception */
    string funcName;/**< name of function where it was thrown */
};
#endif