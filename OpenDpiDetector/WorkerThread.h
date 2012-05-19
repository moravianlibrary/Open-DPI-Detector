#ifndef _WORKER_THREAD_H
#define _WORKER_THREAD_H
#include "DPIManager.h"
#include "qthread.h"
#include "ui_opendpigui.h"
/**
 * Working thread for Qt GUI
 */
class WorkerThread : public QThread
 {
     Q_OBJECT
 private:
	 Ui::openDPIdetectorGui *ui;/**< pointer to GUI components */
	 DPIManager *manager;		/**< pointer to DPIManager used for operations */
	 DpiOperation_t operation;	/**< type of operation of DPIManager*/
	 char* name;			/**< name of file or folder that will be processed*/
	 Orientation_t orientation; /**< position of calibration mark relative to document (if any) */
	 int dpi;					/**< dpi that should be written (if any) */
	 /**
	  * this method will be run when thread is started
	  */
     void run();
	 /**
	  * enables all locked buttons
	  */
	 void enableButtons();
 public:
	 /**
	  * Sets all needed attributes of thread
	  * @param mgr DPIManager used for calling operations
	  * @param type type of operation called od DPIManager
	  * @param dpi dpi that will be saved if a save operation performed
	  * @param orientation position of calibration mark relative to document,
	  *                    if detection or detection and writing
	  * @param pui pointer to GUI form class, containing all static GUI elements
	  */
	 void setAttributes(DPIManager* mgr, DpiOperation_t type, char* resourceName, int dpi,
		 Orientation_t orientation,Ui::openDPIdetectorGui *pui);
 };
#endif