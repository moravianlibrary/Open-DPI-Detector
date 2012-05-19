#ifndef _OPERATION_FINISHED_EVENT_H
#define _OPERATION_FINISHED_EVENT_H
#include "EnumTypes.h"

/**
 * class with event generated when operation is completed
 */
[event_source(native)]
class OperationFinishedEvent {
public:
	/**
	 * event generateed when operation finish
	 * @param operation operation type that was executing
	 * @param name name of file or folder that was processed
	 * @param dpi dpi that was detected if any
	 * @param good number of successfully processed files
	 * @param errors number of unsuccessfully processed files
	 * @console pointer to resource that will be result writen into,
	 *          0 means standard output (console)
	 */
   __event void OperationFinishedResultEvent(DpiOperation_t operation,char* name, int dpi,
											int good, int errors,  void* console);
};
#endif