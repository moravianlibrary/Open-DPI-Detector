#ifndef _OPERATION_FINISHED_LISTENER_H
#define _OPERATION_FINISHED_LISTENER_H
#include "OperationFinishedEvent.h"
#include <cstdio>
#include <QtGui/qtextbrowser.h>
#include  "EnumTypes.h"
/**
 * listener for displaying information about result of operation
 * @remarks THIS CLASS MUST BE UPDATED IF GUI LIBRARY IS CHANGED!
 */
[event_receiver(native)]
class OperationFinishedEventListener {
public:
	/**
	 * display information about result of operation
	 * @operation operation that was executed
	 * @name name of file or folder that was processed 
	 * @dpi dpi that was detected
	 * @good number of successfully processed files
	 * @errors number of unsuccessfully processed files
	 * @console pointer to QTextBrowser that will be used to display
	 *          informations or 0 for standard output (console)
	 */
	void OutputHandler(DpiOperation_t operation, char* name, int dpi, int good, int errors, void* console) {
		QTextBrowser* con = (QTextBrowser*) console;
		switch(operation)
		{
		case DETECT_FILE:
			if (con == 0)
			{
				if (good == 1)
				{
					cout<<name<<" Detected DPI: "<<dpi<<endl;
				}
				else
				{
					cerr<<name<<" DPI could not be detected"<<endl;
				}
			}
			else
			{
				if (good == 1)
				{
					QString qDpi = QString::number(dpi);
					con->append(QObject::trUtf8("%1 Detected DPI: %2").arg(name).arg(dpi));
				}
				else
				{
					con->append(QObject::trUtf8("%1 Error of DPI detection").arg(name));
				}
			}
			break;
		case WRITE_FILE:
			if (con == 0)
			{
				if (good == 1)
				{
					cout<<name<<" DPI saved"<<endl;
				}
				else
				{
					cerr<<name<<" DPI could not be saved"<<endl;
				}
			}
			else
			{
				if (good == 1)
				{
					QString qDpi = QString::number(dpi);
					con->append(QObject::trUtf8("%1 DPI saved").arg(name));
				}
				else
				{
					con->append(QObject::trUtf8("%1 DPI could not beed saved").arg(name));
				}
			}
			break;
		case DETECT_WRITE_FILE:
			//this should never be called, it is processed by DETECT_FILE and WRITE_FILE completely
			break;
		case DETECT_WRITE_FOLDER:
			if (con == 0)
			{
				cout<<name<<" Detection and writing completed"<<endl;
				cout<<"Correctly processed files: "<<good<<endl;
				cout<<"Errors: "<<errors<<endl;
				cout<<"Errors are saved in error.log";
			}
			else
			{
				con->append(QObject::trUtf8("%1 Done - Detection and writing finished").arg(name));
				con->append(QObject::trUtf8("Successfully detected and saved: %1").arg(good));
				con->append(QObject::trUtf8("Errors: %1").arg(errors));
				con->append(QObject::trUtf8("Errors are saved in error.log"));
			}
			break;
		case WRITE_FOLDER:
			if (con == 0)
			{
				cout<<name<<" Writing completed"<<endl;
				cout<<"Correctly saved files: "<<good<<endl;
				cout<<"Errors: "<<errors<<endl;
				cout<<"Errors are saved in error.log";
			}
			else
			{
				con->append(QObject::trUtf8("%1 Done - Writing finished").arg(name));
				con->append(QObject::trUtf8("Successfully detected and saved: %1").arg(good));
				con->append(QObject::trUtf8("Errors: %1").arg(errors));
				con->append(QObject::trUtf8("Errors are saved in error.log"));
			}
			break;
		}
   }

   void hookEvent(OperationFinishedEvent* pSource) {
	   __hook(&OperationFinishedEvent::OperationFinishedResultEvent, pSource, &OperationFinishedEventListener::OutputHandler);
   }

   void unhookEvent(OperationFinishedEvent* pSource) {
	   __unhook(&OperationFinishedEvent::OperationFinishedResultEvent, pSource, &OperationFinishedEventListener::OutputHandler);
   }
};
#endif