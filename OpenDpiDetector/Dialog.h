#ifndef DIALOG_H
#define DIALOG_H
#include "ui_opendpigui.h"
#include <QtGui/QMainWindow>
#include "DPIManager.h"
#include "WorkerThread.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <qtgui/qfiledialog.h>
#include <qdir.h>
#include <QtGui/qmessagebox.h>
#include <QCloseEvent>

/**
 * Class providing functionality for GUI and generation of dynamic GUI elements
 * form and all static elements are included in ui_opendpigui.h file
 */
class Dialog : public QMainWindow
{
    Q_OBJECT

public:
	/**
	 * constructor
	 */
    Dialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	/**
	 * destructor
	 */
	~Dialog();
	
private slots:
	/**
	 * choooses existing directory via standard dialog window
	 */
    void setExistingDirectory();
	/**
	 * chooses existing file via standard dialog window
	 */
    void setOpenFileName();
	/**
	 * starts detection of dpi of file
	 */
    void DetectFileDpi();
	/**
	 * starts detection and saving of dpi of file
	 */
	void DetectWriteFileDpi();
	/**
	 * starts writing dpi to a file
	 */
	void WriteFileDpi();
	/**
	 * starts detection and writing of dpi for a folder
	 */
	void DetectWriteFolderDpi();
	/**
	 * starts writing of dpi for a folder
	 */
	void WriteFolderDpi();
	/**
	 * stops processing after completion of current file
	 */
	void StopThread();
	/**
	 * kills thread, immediately stopping processing
	 */
	void KillThread();
	/**
	 * actions performed if another language is chosen
	 * installs language
	 */
	void slotLanguageChanged(QAction* action);
	/**
	 * actions performed when closing application
	 * asks whether exit, if thread is still working
	 */
	void closeEvent(QCloseEvent* ev);
private:
	Ui::openDPIdetectorGui ui;		/**< visual form of GUI */ 
	DPIManager *manager;			/**< DPIManager for resolving operations */
	WorkerThread thread;			/**< WorkerThread for resolving operations out of GUI thread */
	//helper functions
    void DisableButtons();//disable action buttons
	QPushButton** GetAllButtons();//get all 5 action buttons
	//internationalization part
	/**
	 * This event is generated on change of many things including locale
	 * @param event original change event that was generated
	 */
	void changeEvent(QEvent* event);
	/**
	 * loads given language
	 * @param rLanguage language that will be loaded
	 */
	void loadLanguage(const QString& rLanguage);
	/**
	 * Dynamically creates language menu from language file in folder /languages
	 */
    void createLanguageMenu(void);
	QTranslator     m_translator;   /**< contains the translations for this application */
    QString         m_currLang;     /**< contains the currently loaded language */
    QString         m_langPath;     /**< Path of language files, fixed to /languages */
};
#endif