#include "WorkerThread.h"
void WorkerThread::run()
 {
	 switch(operation)
	 {
	 case DETECT_FILE:
		 dpi = manager->DetectFileDPI(name,orientation,ui->outputTextBrowser);
		 if(dpi > 0)
		 {
			 ui->wFiDpiSpinBox->setValue(dpi);
			 ui->wFoDpiSpinBox->setValue(dpi);
		 }
		 enableButtons();
		 break;
	 case DETECT_WRITE_FILE:
		 manager->DetectAndSaveFileDPI(name,orientation,ui->outputTextBrowser);
		 enableButtons();
		 break;
	 case WRITE_FILE:
		 manager->SaveFileDPI(name,dpi,ui->outputTextBrowser);
		 enableButtons();
		 break;
	 case DETECT_WRITE_FOLDER:
		 manager->DetectAndSaveFolderDPI(name, orientation, ui->outputTextBrowser);
		 enableButtons();
		 break;
	 case WRITE_FOLDER:
		 manager->SaveFolderDPI(name, dpi,ui->outputTextBrowser);
		 enableButtons();
		 break;
	 }
	 delete [] name;
 }

void WorkerThread::setAttributes(DPIManager* mgr,DpiOperation_t type, char* resourceName, int dpiValue,
								Orientation_t ori, Ui::openDPIdetectorGui *pui)

{
	ui = pui;
	manager = mgr;
	operation = type;
	name = resourceName;
	dpi = dpiValue;
	orientation = ori;
}

void WorkerThread::enableButtons()
{
	ui->dFiActionButton->setEnabled(true);
	ui->dwFiActionButton->setEnabled(true);
	ui->wFiActionButton->setEnabled(true);
	ui->dwFoActionButton->setEnabled(true);
	ui->wFoActionButton->setEnabled(true);			
}