#include "dialog.h"

Dialog::Dialog(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	manager = new DPIManager();//assing DPIManager for application

	ui.setupUi(this);//make gui based of GUI form

	//conects events for choosing buttons from gui form
	connect(ui.dwFoChooseButton, SIGNAL(clicked()),
            this, SLOT(setExistingDirectory()));
	connect(ui.wFoChooseButton, SIGNAL(clicked()),
            this, SLOT(setExistingDirectory()));
    connect(ui.dFiChooseButton, SIGNAL(clicked()),
            this, SLOT(setOpenFileName()));
	connect(ui.dwFiChooseButton, SIGNAL(clicked()),
            this, SLOT(setOpenFileName()));
	connect(ui.wFiChooseButton, SIGNAL(clicked()),
            this, SLOT(setOpenFileName()));
	//connect events for action buttons and stopping buttons from gui form
	connect(ui.dFiActionButton, SIGNAL(clicked()),
            this, SLOT(DetectFileDpi()));
	connect(ui.dwFiActionButton, SIGNAL(clicked()),
            this, SLOT(DetectWriteFileDpi()));
	connect(ui.wFiActionButton, SIGNAL(clicked()),
            this, SLOT(WriteFileDpi()));
	connect(ui.dwFoActionButton, SIGNAL(clicked()),
            this, SLOT(DetectWriteFolderDpi()));
	connect(ui.wFoActionButton, SIGNAL(clicked()),
            this, SLOT(WriteFolderDpi()));
	connect(ui.cancelButton,SIGNAL(clicked()),
			this, SLOT(StopThread()));
	connect(ui.forceCancelButton,SIGNAL(clicked()),
			this, SLOT(KillThread()));
	//create name of translation file based of System locale
	m_langPath = QApplication::applicationDirPath();
	QString translatorFileName = QString("%1/languages/opendpidetector_").arg(m_langPath);
	translatorFileName += QLocale::system().name();
	if (m_translator.load(translatorFileName))
	{
		//load language of system locale if exists
		qApp->installTranslator(&m_translator);
	}
	else 
	{
		//load english as default language (if not available, default english will be used)
		m_translator.load(QString("%1/languages/opendpidetector_en.qm").arg(m_langPath));
		qApp->installTranslator(&m_translator);
	}
	//set main icon
	QString iconName = m_langPath;
	iconName +=QString("/opendpidetector-icon.png");
	setWindowIcon(QIcon(iconName));
	createLanguageMenu();//dynamically create language menu entries
}

Dialog::~Dialog()
{
}
	
	
void Dialog::setExistingDirectory()
{
	//call standard OS dialog for choosing directories
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    QString directory = QFileDialog::getExistingDirectory(this,
		QApplication::translate("Dialog", "Choose folder",0,QApplication::UnicodeUTF8),
								QDir::rootPath(),
                                options);
    if (!directory.isEmpty())
	{
		//set directory to both text fields
		ui.dwFoLineEdit->setText(directory);
		ui.wFoLineEdit->setText(directory);
	}
}

void Dialog::setOpenFileName()
{
    QFileDialog::Options options;
    QString selectedFilter;
	//calls standard OS dialog for choosing files
    QString fileName = QFileDialog::getOpenFileName(this,
		QApplication::translate("Dialog","Choose File",0,QApplication::UnicodeUTF8),
								QDir::rootPath(),
                                "Image Files(*.PNG;*.JPG;*.JPEG;*.TIF;*.TIFF;*.JP2;*.JPM)",
                                &selectedFilter,
                                options);
	//find directory part of path
	int index = fileName.lastIndexOf('/');
	int indexTmp = fileName.lastIndexOf('\\');
	if (indexTmp > index)
	{
		index = indexTmp;
	}
	QString folderName = fileName;
	folderName.chop(folderName.length()-index);
    if (!fileName.isEmpty())
	{
		//save file path to 3 line fields and directory part to other 2
		ui.dFiLineEdit->setText(fileName);
		ui.dwFiLineEdit->setText(fileName);
		ui.wFiLineEdit->setText(fileName);
		ui.dwFoLineEdit->setText(folderName);
		ui.wFoLineEdit->setText(folderName);
	}
}

void Dialog::DetectFileDpi()
{
	QString fileName = ui.dFiLineEdit->text();
	QString orientationString = ui.dFiOrientationComboBox->currentText();
	Orientation_t orientation;
	if (fileName != "")
	{
		DPIManager *manager;
		ui.outputTextBrowser->append(QApplication::translate("Dialog", "Starting DPI detection",0,QApplication::UnicodeUTF8));
		//assing chosen orientation
		if(orientationString == QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8))
		{
			orientation = UPPER_SIDE;
		}
		else if(orientationString == QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8))
		{
			orientation = LEFT_SIDE;
		}
		else if (orientationString == QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8))
		{
			orientation = BOTTOM_SIDE;
		}
		else if (orientationString == QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8))
		{
			orientation = RIGHT_SIDE;
		}
			//create new char* on heap from path of fileName in QString
		std::string s = fileName.toStdString();
		const char* nameTmp = s.c_str();
		int length = s.length()+1;
		char* name = new char [length];
		for(int i=0;i<length;i++)
		{
			name[i] = (char) nameTmp[i];
		}
		//sends attributes to worker thread, disable buttons and start execution
		thread.setAttributes(manager,DETECT_FILE,name,0,orientation, &ui);
		DisableButtons();
		thread.start();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No filename entered",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","You must choose file that will be processed first.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::DetectWriteFileDpi()
{
	QString fileName = ui.dwFiLineEdit->text();
	QString orientationString = ui.dwFiOrientationComboBox->currentText();
	Orientation_t orientation;
	if (fileName != "")
	{
		ui.outputTextBrowser->append(QApplication::translate("Dialog","Starting detection and writing of DPI",0,QApplication::UnicodeUTF8));
		//create orientation from chosen value
		if(orientationString == QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8))
		{
			orientation = UPPER_SIDE;
		}
		else if(orientationString == QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8))
		{
			orientation = LEFT_SIDE;
		}
		else if (orientationString == QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8))
		{
			orientation = BOTTOM_SIDE;
		}
		else if (orientationString == QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8))
		{
			orientation = RIGHT_SIDE;
		}
			//make char* on heap from path to file that will be given to worker thread
		std::string s = fileName.toStdString();
		const char* nameTmp = s.c_str();
		int length = s.length()+1;
		char* name = new char [length];
		for(int i=0;i<length;i++)
		{
			name[i] = (char) nameTmp[i];
		}
		//sends attributes to worker thread, disable buttons and starts it
		thread.setAttributes(manager,DETECT_WRITE_FILE,name,0,orientation, &ui);
		DisableButtons();
		thread.start();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No filename entered",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","You must choose file that will be processed first.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::WriteFileDpi()
{
	int dpi = ui.wFiDpiSpinBox->value();
	QString fileName = ui.wFiLineEdit->text();
	if (fileName != "")
	{
		ui.outputTextBrowser->append(QApplication::translate("Dialog","Starting saving DPI",0,QApplication::UnicodeUTF8));	
		std::string s = fileName.toStdString();
		//create path to file on heap
		const char* nameTmp = s.c_str();
		int length = s.length()+1;
		char* name = new char [length];
		for(int i=0;i<length;i++)
		{
			name[i] = (char) nameTmp[i];
		}
		//sends attributes to thread, disable buttons and starts it
		thread.setAttributes(manager,WRITE_FILE,name,dpi,UPPER_SIDE, &ui);
		DisableButtons();
		thread.start();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No filename entered",0, QApplication::UnicodeUTF8),
			QApplication::translate("Dialog", "You must choose file that will be processed first.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::DetectWriteFolderDpi()
{
	QString folderName = ui.dwFoLineEdit->text();
	QString orientationString = ui.dwFoOrientationComboBox->currentText();
	Orientation_t orientation;
	if (folderName != "")
	{
		//create orientation from chosen value
		if(orientationString == QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8))
		{
			orientation = UPPER_SIDE;
		}
		else if(orientationString == QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8))
		{
			orientation = LEFT_SIDE;
		}
		else if (orientationString == QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8))
		{
			orientation = BOTTOM_SIDE;
		}
		else if(orientationString == QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8))
		{
			orientation = RIGHT_SIDE;
		}
		std::string s = folderName.toStdString();
		//create path to a file on heap
		const char* nameTmp = s.c_str();
		int length = s.length()+1;
		char* name = new char [length];
		for(int i=0;i<length;i++)
		{
			name[i] = (char) nameTmp[i];
		}
		//sends attributes to thread, inform about start, disable buttons and start processing
		ui.outputTextBrowser->append(QApplication::translate("Dialog","Starting detection and writing of DPI",0,QApplication::UnicodeUTF8));
		thread.setAttributes(manager,DETECT_WRITE_FOLDER,name,0,orientation, &ui);
		ui.outputTextBrowser->append(name);
		DisableButtons();
		thread.start();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No foldername entered",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","You must choose folder that will be processed first.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::WriteFolderDpi()
{
	int dpi = ui.wFoDpiSpinBox->value();
	QString folderName = ui.wFoLineEdit->text();
	if (folderName != "")
	{
		//create path to a file on a heap
		std::string s = folderName.toStdString();
		const char* nameTmp = s.c_str();
		int length = s.length()+1;
		char* name = new char [length];
		for(int i=0;i<length;i++)
		{
			name[i] = (char) nameTmp[i];
		}
		//sends attributes to worker thread, informs about starting, disables buttons and starts
		ui.outputTextBrowser->append(QApplication::translate("Dialog","Starting saving DPI",0,QApplication::UnicodeUTF8));	
		thread.setAttributes(manager,WRITE_FOLDER,name,dpi,UPPER_SIDE, &ui);
		ui.outputTextBrowser->append(name);
		DisableButtons();
		thread.start();
	}
	else
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No foldername entered",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","You must choose folder that will be processed first.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::StopThread(){
	if(thread.isRunning())
	{
		//inform abou consequences and set stopping token if yes was chosen
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, QApplication::translate("Dialog","Confirm stopping",0,QApplication::UnicodeUTF8),
                                    QApplication::translate("Dialog","Do you really want to stop processing?"
									"Processing will be stopped after completion of current file."
									"If you need to stop process immediately, use Force stop button.",
									0,QApplication::UnicodeUTF8),
                                    QMessageBox::Yes | QMessageBox::No);
		if(reply == QMessageBox::Yes)
		{
			manager->IsProcessingStopped = true;
		}
	}
	else
	{
		//nothing to stop
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No running operation",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","There is no running operation currently.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::KillThread(){
	if (thread.isRunning())
	{
		//inform about consequences and stop if Yes was clicked
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, QApplication::translate("Dialog","Confirm stopping",0,QApplication::UnicodeUTF8),
                                    QApplication::translate("Dialog","Do you really want to force stopping processing?"
									"This may cause existence of damaged backup file."
									"For safe stopping use Stop button instead.",
									0,QApplication::UnicodeUTF8),
                                    QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			thread.terminate();
			//enables buttons again
			QPushButton** buttons = GetAllButtons();
			for(int i=0; i<5;i++)
			{
				buttons[i]->setEnabled(true);
			}
		}
	}
	else
	{
		//nothing to stop
		QMessageBox::StandardButton reply;
		reply = QMessageBox::information(this, QApplication::translate("Dialog","No running operation",0,QApplication::UnicodeUTF8),
			QApplication::translate("Dialog","There is no running operation currently.",0,QApplication::UnicodeUTF8));
	}
}

void Dialog::DisableButtons()
{
	//disable action buttons
	QPushButton** buttons = GetAllButtons();
	for(int i=0; i<5;i++)
	{
		buttons[i]->setEnabled(false);
	}
}
QPushButton** Dialog::GetAllButtons()
{
	//get all action buttons
	QPushButton** allButtons = new QPushButton*[5];
	allButtons[0] = ui.dFiActionButton;
	allButtons[1] = ui.dwFiActionButton;
	allButtons[2] = ui.wFiActionButton;
	allButtons[3] = ui.dwFoActionButton;
	allButtons[4] = ui.wFoActionButton;
	return allButtons;
}

    //create the menu entries dynamically, dependant on the existing translations.

void Dialog::createLanguageMenu(void)
    {
        QActionGroup* langGroup = new QActionGroup(ui.menuLanguage);
        langGroup->setExclusive(true);
     
        connect(langGroup, SIGNAL(triggered(QAction *)), this, SLOT(slotLanguageChanged(QAction *)));
     
        // format systems language
        QString defaultLocale = QLocale::system().name();       // e.g. "cs_CZ"
        defaultLocale.truncate(defaultLocale.lastIndexOf('_')); // e.g. "cs"
		//finds all available .qm files in languages folder
        m_langPath = QApplication::applicationDirPath();
        m_langPath.append("/languages");
        QDir dir(m_langPath);
        QStringList fileNames = dir.entryList(QStringList("opendpidetector_*.qm"));
     
        for (int i = 0; i < fileNames.size(); ++i)
        {
            // get locale extracted by filename
            QString locale;
            locale = fileNames[i];                  // "opendpidetector_cs.qm"
            locale.truncate(locale.lastIndexOf('.'));   // "opendpidetector_cs"
            locale.remove(0, locale.indexOf('_') + 1);   // "cs"
     
            QString lang = QLocale::languageToString(QLocale(locale).language());
			//load language icon from /languages
			QIcon ico(QString("%1/%2.png").arg(m_langPath).arg(locale));
			QAction *action = new QAction(ico, lang, this);
            action->setCheckable(true);
            action->setData(locale);
     
            ui.menuLanguage->addAction(action);
            langGroup->addAction(action);
     
            // set default translators and language checked
            if (defaultLocale == locale)
            {
                action->setChecked(true);
            }
        }
    }

// Called every time, when a menu entry of the language menu is called
void Dialog::slotLanguageChanged(QAction* action)
    {
        if(0 != action)
        {
            // load the language dependant on the action content
            loadLanguage(action->data().toString());
        }
    }
     
void switchTranslator(QTranslator& translator, const QString& filename)
    {
        // remove the old translator
        qApp->removeTranslator(&translator);
     
        // load the new translator
        if(translator.load(filename))
            qApp->installTranslator(&translator);
    }
     
void Dialog::loadLanguage(const QString& rLanguage)
    {
        if(m_currLang != rLanguage)
        {
            m_currLang = rLanguage;
            QLocale locale = QLocale(m_currLang);
            QLocale::setDefault(locale);
            QString languageName = QLocale::languageToString(locale.language());
			//unload old and load new language file
			switchTranslator(m_translator, QString("%1/opendpidetector_%2.qm").arg(m_langPath).arg(rLanguage));
        }
    }

void Dialog::changeEvent(QEvent* event)
    {
        if(0 != event)
        {
            switch(event->type())
            {
            // this event is send if a translator is loaded
            case QEvent::LanguageChange:
                ui.retranslateUi(this);
                break;
            // this event is send, if the system, language changes
            case QEvent::LocaleChange:
                {
                    QString locale = QLocale::system().name();
                    locale.truncate(locale.lastIndexOf('_'));
                    loadLanguage(locale);
                }
                break;
            }
        }
        QMainWindow::changeEvent(event);
    }

void Dialog::closeEvent(QCloseEvent* ev)
{
	if (thread.isRunning()) {
		//inform about consequences and exit if yes was chosen
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, QApplication::translate("Dialog","Confirm quit",0,QApplication::UnicodeUTF8),
                                    QApplication::translate("Dialog","Do you really want to close program during processing?"
									"This may cause existence of damaged backup file."
									"For safe shut down, use Stop button first and wait untill proccess stops.",
									0,QApplication::UnicodeUTF8),
                                    QMessageBox::Yes | QMessageBox::No);
		if(reply == QMessageBox::Yes)
		{
			ev->accept();
		}
		else
		{
			ev->ignore();
		}
    } 
	else 
	{
		//exit without asking, if not operation in progress
         ev->accept();
    }
}