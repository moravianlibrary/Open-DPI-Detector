#ifndef _ILLEGAL_PARAMETER_EXCEPTION_H
#define _ILLEGAL_PARAMETER_EXCEPTION_H
#include <cstring>
#include <sstream>
using namespace std;

/**
 * exception thrown when bad parameter inserted
 */
class IllegalParameterException : public exception
{
  public:
	  IllegalParameterException(string pMsg) : msg(pMsg) {}
	  /**
	   * returns message of exception
	   * @return message of exception
	   */
	 virtual string getMessage()
	{
		return msg;
	}
	/**
	 * display full format of exception
	 * @return string with message of exception and name of function where it was thrown
	 */
    virtual string display()
    {
        ostringstream out;
		out << "WRONG PARAMETER: <" << msg << ends;
        return out.str();
    }
  protected:
    string msg;/**< message of exception */
};
#endif