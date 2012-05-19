#ifndef _PROGRESS_LISTENER_H
#define _PROGRESS_LISTENER_H
#include "ProgressEvent.h"
#include <cstdio>
#include <QtGui/qtextbrowser.h>

/**
 * listener for events about progress
 * @remarks this class must be updated when changed library for GUI
 */
[event_receiver(native)]
class ProgressListener {
public:
	/**
	 * displays information about progress on the given resource
	 * @param active currently processed file
	 * @param total total count of files
	 * @param console pointer to QTextBrowser where will be information displayed,
	 *                0 means standard output (console)
	 */
   void OutputHandler(int active, int total, void* console) {
	    QTextBrowser* con = (QTextBrowser*) console;
		if (con == 0)
		{
		  std::cout<<"Processed: "<<active<<"/"<<total<<endl;
		}
		else
		{
		  con->append(QObject::trUtf8("Processed: %1/%2").arg(active).arg(total));
		}
   }
   /**
    * register listener to event
	*/
   void hookEvent(ProgressEvent* pSource) {
      __hook(&ProgressEvent::ProgressChangedEvent, pSource, &ProgressListener::OutputHandler);
   }
   /**
    * unregister listener from event
	*/
   void unhookEvent(ProgressEvent* pSource) {
      __unhook(&ProgressEvent::ProgressChangedEvent, pSource, &ProgressListener::OutputHandler);
   }
};
#endif