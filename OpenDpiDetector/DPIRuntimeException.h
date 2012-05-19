#ifndef _DPI_RUNTIME_EXCEPTION_H
#define _DPI_RUNTIME_EXCEPTION_H
#include <cstring>
#include <sstream>
using namespace std;

/**
 * virtual class for derivation of other exceptions
 */
class DPIRuntimeException : public exception
{
  public:
	  /**
	   * returns message  of exception
	   */
	  virtual string getMessage()=0;
	  /**
	   * returns name of function where exception occured
	   */
	  virtual string getfunction()=0;
	  /**
	   * display full format of exception
	   */
	  virtual string display()=0;
};
#endif