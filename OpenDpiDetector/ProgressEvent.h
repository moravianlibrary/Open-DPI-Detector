#ifndef _PROGRESS_EVENT_H
#define _PROGRESS_EVENT_H

/**
 * class for sending events about progress
 */
[event_source(native)]
class ProgressEvent {
public:
	/**
	 * event informing about current progress
	 * @param active number of currently processed file
	 * @param total total count of files
	 * @param console pointer to resource, where will be information
	 *                send, 0 means standard output (console)
	 */
   __event void ProgressChangedEvent(int active, int total, void* console);
};
#endif