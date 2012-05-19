///THIS FILE SHOULD BE REMOVED
#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

///THIS FILE IS NOT USED
///INSTEAD OF THIS IS USED AUTO-GENERATED UI IN GENERATED FILES
///THIS FILE SHOULD BE REMOVED
/*
QT_BEGIN_NAMESPACE

class Ui_DialogClass
{
public:
    QVBoxLayout *mainLayout;
	QGridLayout *gridLayout;
	QGridLayout * consoleLayout;
    QLabel *wFiLabel;
    QLineEdit *wFiLineEdit;
    QLabel *dFiLabel;
    QLabel *wFiDpiLabel;
    QComboBox *dwFoOrientationComboBox;
    QLineEdit *dwFoLineEdit;
    QPushButton *dwFoChooseButton;
    QPushButton *dwFoActionButton;
    QPushButton *dwFiActionButton;
    QComboBox *dwFiOrientationComboBox;
    QLabel *dwFoLabel;
    QLabel *wFoDpiLabel;
    QPushButton *wFiChooseButton;
    QLabel *dwFiLabel;
    QLabel *dwFoOrientationLabel;
    QPushButton *dFiActionButton;
    QPushButton *wFiActionButton;
    QPushButton *wFoChooseButton;
    QLineEdit *wFoLineEdit;
    QLabel *dwFiOrientationLabel;
    QPushButton *wFoActionButton;
    QLabel *wFoLabel;
    QPushButton *dFiChooseButton;
    QLabel *dFiOrientationLabel;
    QComboBox *dFiOrientationComboBox;
    QLineEdit *dwFiLineEdit;
    QPushButton *dwFiChooseButton;
    QSpinBox *wFiDpiSpinBox;
    QSpinBox *wFoDpiSpinBox;
    QLineEdit *dFiLineEdit;
    QTextBrowser *outputTextBrowser;
	QPushButton *cancelButton;
	QPushButton *forceCancelButton;
	QMenuBar *menuBar;
    QMenu *menuLanguage;
	
	void setupUi(QMainWindow *dialogClass)
	{
        menuBar = new QMenuBar(dialogClass);
		menuBar->setGeometry(QRect(0, 0, 16777215, 21));
		menuLanguage = new QMenu(dialogClass);
		menuBar->addMenu(menuLanguage);
		wFiLabel = new QLabel(dialogClass);
		wFiLineEdit = new QLineEdit(dialogClass);    
		wFiLineEdit->setReadOnly(dialogClass);
		dFiLabel = new QLabel(dialogClass);
		wFiDpiLabel = new QLabel(dialogClass);
		dwFoOrientationComboBox = new QComboBox(dialogClass);
		dwFoOrientationComboBox->setMaximumSize(QSize(60, 16777215));
		dwFoLineEdit = new QLineEdit(dialogClass);
		dwFoLineEdit->setReadOnly(true);
		dwFoChooseButton = new QPushButton(dialogClass);
		dwFoChooseButton->setMaximumSize(QSize(70, 16777215));
		dwFoActionButton = new QPushButton(dialogClass);
		dwFoActionButton->setMaximumSize(QSize(180, 16777215));
		dwFiActionButton = new QPushButton(dialogClass);
		dwFiActionButton->setMaximumSize(QSize(180, 16777215));
		dwFiOrientationComboBox = new QComboBox(dialogClass);
		dwFiOrientationComboBox->setMaximumSize(QSize(60, 16777215));
		dwFoLabel = new QLabel(dialogClass);
		wFoDpiLabel = new QLabel(dialogClass);
		wFiChooseButton = new QPushButton(dialogClass);
		wFiChooseButton->setMaximumSize(QSize(70, 16777215));
		dwFiLabel = new QLabel(dialogClass);
		dwFoOrientationLabel = new QLabel(dialogClass);
		dFiActionButton = new QPushButton(dialogClass);
		dFiActionButton->setMaximumSize(QSize(180, 16777215));
		wFiActionButton = new QPushButton(dialogClass);
		wFiActionButton->setMaximumSize(QSize(180, 16777215));
		wFoChooseButton = new QPushButton(dialogClass);
		wFoChooseButton->setMaximumSize(QSize(70, 16777215));
		wFoLineEdit = new QLineEdit(dialogClass);
		wFoLineEdit->setReadOnly(true);
		dwFiOrientationLabel = new QLabel(dialogClass);
		wFoActionButton = new QPushButton(dialogClass);
		wFoActionButton->setMaximumSize(QSize(180, 16777215));
		wFoLabel = new QLabel(dialogClass);
		dFiChooseButton = new QPushButton(dialogClass);
		dFiChooseButton->setMaximumSize(QSize(70, 16777215));
		dFiOrientationLabel = new QLabel(dialogClass);
		dFiOrientationComboBox = new QComboBox(dialogClass);
		dFiOrientationComboBox->setMaximumSize(QSize(60, 16777215));
		dwFiLineEdit = new QLineEdit(dialogClass);
		dwFiLineEdit->setReadOnly(true);
		dwFiChooseButton = new QPushButton(dialogClass);
		dwFiChooseButton->setMaximumSize(QSize(70, 16777215));
		wFiDpiSpinBox = new QSpinBox(dialogClass);
		wFiDpiSpinBox->setMinimum(1);
		wFiDpiSpinBox->setMaximum(65535);
		wFiDpiSpinBox->setValue(1);
		wFoDpiSpinBox = new QSpinBox(dialogClass);
		wFoDpiSpinBox->setMinimum(1);
		wFoDpiSpinBox->setMaximum(65535);
		wFoDpiSpinBox->setValue(1);
		dFiLineEdit = new QLineEdit(dialogClass);
		dFiLineEdit->setReadOnly(true);
		outputTextBrowser = new QTextBrowser(dialogClass);
		outputTextBrowser->setTextInteractionFlags(Qt::TextSelectableByMouse);
		cancelButton = new QPushButton(dialogClass);
		cancelButton->setMaximumSize(QSize(80, 16777215));
		forceCancelButton = new QPushButton(dialogClass);
		forceCancelButton->setMaximumSize(QSize(160, 16777215));
		QGridLayout *layout = new QGridLayout(dialogClass);
		layout->setContentsMargins(10, 20, 10, 0);
		layout->setColumnStretch(1, 1);
		layout->setColumnMinimumWidth(1, 250);
		layout->addWidget(dFiLabel,0,0,Qt::AlignRight);
		layout->addWidget(dFiLineEdit,0,1);
		layout->addWidget(dFiChooseButton,0,2);
		layout->addWidget(dFiOrientationLabel,0,3,Qt::AlignRight);
		layout->addWidget(dFiOrientationComboBox,0,4);
		layout->addWidget(dFiActionButton,0,5);
		layout->addWidget(dwFiLabel,1,0,Qt::AlignRight);
		layout->addWidget(dwFiLineEdit,1,1);
		layout->addWidget(dwFiChooseButton,1,2);
		layout->addWidget(dwFiOrientationLabel,1,3,Qt::AlignRight);
		layout->addWidget(dwFiOrientationComboBox,1,4);
		layout->addWidget(dwFiActionButton,1,5);
		layout->addWidget(wFiLabel,2,0,Qt::AlignRight);
		layout->addWidget(wFiLineEdit,2,1);
		layout->addWidget(wFiChooseButton,2,2);
		layout->addWidget(wFiDpiLabel,2,3,Qt::AlignRight);
		layout->addWidget(wFiDpiSpinBox,2,4);
		layout->addWidget(wFiActionButton,2,5);
		layout->addWidget(dwFoLabel,3,0,Qt::AlignRight);
		layout->addWidget(dwFoLineEdit,3,1);
		layout->addWidget(dwFoChooseButton,3,2);
		layout->addWidget(dwFoOrientationLabel,3,3,Qt::AlignRight);
		layout->addWidget(dwFoOrientationComboBox,3,4);
		layout->addWidget(dwFoActionButton,3,5);
		layout->addWidget(wFoLabel,4,0,Qt::AlignRight);
		layout->addWidget(wFoLineEdit,4,1);
		layout->addWidget(wFoChooseButton,4,2);
		layout->addWidget(wFoDpiLabel,4,3,Qt::AlignRight);
		layout->addWidget(wFoDpiSpinBox,4,4);
		layout->addWidget(wFoActionButton,4,5);
		
		consoleLayout = new QGridLayout(dialogClass);
		consoleLayout->addWidget(outputTextBrowser, 0,0);
		consoleLayout->addWidget(cancelButton,0,1);
		consoleLayout->addWidget(forceCancelButton,0,2);

		mainLayout = new QVBoxLayout(dialogClass);
		mainLayout->addLayout(layout);
		mainLayout->addLayout(consoleLayout);
	
		dialogClass->setLayout(mainLayout);
		dialogClass->setWindowTitle("Open DPI Detector");
		dialogClass->setFixedSize(652,306);	
		
		retranslateUi(dialogClass);
    } // setupUi

    void retranslateUi(QMainWindow *cuteClass)
    {
		menuLanguage->setTitle(QApplication::translate("Dialog","Language",0,QApplication::UnicodeUTF8));
		wFiLabel->setText(QApplication::translate("Dialog","File:",0,QApplication::UnicodeUTF8));
		dFiLabel->setText(QApplication::translate("Dialog","File:",0,QApplication::UnicodeUTF8));
		wFiDpiLabel->setText(QApplication::translate("Dialog","DPI:",0,QApplication::UnicodeUTF8));
		dwFoOrientationComboBox->clear();
		dwFoOrientationComboBox->insertItems(0, QStringList()
			<< QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8)
			<< QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8)
			<< QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8)
			<< QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8)
			);
		dwFoChooseButton->setText(QApplication::translate("Dialog","Choose",0,QApplication::UnicodeUTF8));
		dwFoActionButton->setText(QApplication::translate("Dialog","Detect and save DPI of folder",0,QApplication::UnicodeUTF8));
		dwFiActionButton->setText(QApplication::translate("Dialog","Detect and save DPI of file",0,QApplication::UnicodeUTF8));
		dwFiOrientationComboBox->clear();
		dwFiOrientationComboBox->insertItems(0, QStringList()
		     << QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8)
			);
		dwFoLabel->setText(QApplication::translate("Dialog","Folder:",0,QApplication::UnicodeUTF8));    
		wFoDpiLabel->setText(QApplication::translate("Dialog","DPI:",0,QApplication::UnicodeUTF8));    
		wFiChooseButton->setText(QApplication::translate("Dialog","Choose",0,QApplication::UnicodeUTF8));
		dwFiLabel->setText(QApplication::translate("Dialog","File:",0,QApplication::UnicodeUTF8));
		dwFoOrientationLabel->setText(QApplication::translate("Dialog","Mark orientation:",0,QApplication::UnicodeUTF8));
		dFiActionButton->setText(QApplication::translate("Dialog","Detect DPI of file",0,QApplication::UnicodeUTF8));
		wFiActionButton->setText(QApplication::translate("Dialog","Save DPI of file",0,QApplication::UnicodeUTF8));
		wFoChooseButton->setText(QApplication::translate("Dialog","Choose",0,QApplication::UnicodeUTF8));
		dwFiOrientationLabel->setText(QApplication::translate("Dialog","Mark orientation:",0,QApplication::UnicodeUTF8));
		wFoActionButton->setText(QApplication::translate("Dialog","Save DPI of folder",0,QApplication::UnicodeUTF8));
		wFoLabel->setText(QApplication::translate("Dialog","Folder:",0,QApplication::UnicodeUTF8));
		dFiChooseButton->setText(QApplication::translate("Dialog","Choose",0,QApplication::UnicodeUTF8));
		dFiOrientationLabel->setText(QApplication::translate("Dialog","Mark orientation:",0,QApplication::UnicodeUTF8));    
		dFiOrientationComboBox->clear();
		dFiOrientationComboBox->insertItems(0, QStringList()
			 << QApplication::translate("Dialog","up",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","right",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","down",0,QApplication::UnicodeUTF8)
			 << QApplication::translate("Dialog","left",0,QApplication::UnicodeUTF8)
			);    
		dwFiChooseButton->setText(QApplication::translate("Dialog","Choose",0,QApplication::UnicodeUTF8));
		cancelButton->setText(QApplication::translate("Dialog","Stop",0,QApplication::UnicodeUTF8));
		forceCancelButton->setText(QApplication::translate("Dialog","Force stop",0,QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
    class dialogClass: public Ui_DialogClass {};
} // namespace Ui

QT_END_NAMESPACE
*/
#endif // UI_DIALOG_H
