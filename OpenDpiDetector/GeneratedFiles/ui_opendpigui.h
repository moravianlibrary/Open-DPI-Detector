/********************************************************************************
** Form generated from reading UI file 'opendpigui.ui'
**
** Created: Sat 19. May 15:28:30 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENDPIGUI_H
#define UI_OPENDPIGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openDPIdetectorGui
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *dwFiLabel;
    QPushButton *wFiActionButton;
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
    QLabel *wFoDpiLabel;
    QPushButton *wFiChooseButton;
    QLabel *dwFoOrientationLabel;
    QPushButton *dFiActionButton;
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
    QLabel *dwFoLabel;
    QGridLayout *gridLayout_4;
    QTextBrowser *outputTextBrowser;
    QPushButton *forceCancelButton;
    QPushButton *cancelButton;
    QMenuBar *menuBar;
    QMenu *menuLanguage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *openDPIdetectorGui)
    {
        if (openDPIdetectorGui->objectName().isEmpty())
            openDPIdetectorGui->setObjectName(QString::fromUtf8("openDPIdetectorGui"));
        openDPIdetectorGui->setEnabled(true);
        openDPIdetectorGui->resize(769, 306);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openDPIdetectorGui->sizePolicy().hasHeightForWidth());
        openDPIdetectorGui->setSizePolicy(sizePolicy);
        openDPIdetectorGui->setMinimumSize(QSize(769, 306));
        openDPIdetectorGui->setMaximumSize(QSize(769, 306));
        openDPIdetectorGui->setWindowTitle(QString::fromUtf8("Open DPI Detector"));
        centralWidget = new QWidget(openDPIdetectorGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 752, 233));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(10, -1, 10, -1);
        dwFiLabel = new QLabel(verticalLayoutWidget);
        dwFiLabel->setObjectName(QString::fromUtf8("dwFiLabel"));
        dwFiLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dwFiLabel, 1, 0, 1, 1, Qt::AlignRight);

        wFiActionButton = new QPushButton(verticalLayoutWidget);
        wFiActionButton->setObjectName(QString::fromUtf8("wFiActionButton"));
        wFiActionButton->setMinimumSize(QSize(160, 0));
        wFiActionButton->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(wFiActionButton, 2, 5, 1, 1);

        wFiLabel = new QLabel(verticalLayoutWidget);
        wFiLabel->setObjectName(QString::fromUtf8("wFiLabel"));

        gridLayout->addWidget(wFiLabel, 2, 0, 1, 1, Qt::AlignRight);

        wFiLineEdit = new QLineEdit(verticalLayoutWidget);
        wFiLineEdit->setObjectName(QString::fromUtf8("wFiLineEdit"));
        wFiLineEdit->setReadOnly(true);

        gridLayout->addWidget(wFiLineEdit, 2, 1, 1, 1);

        dFiLabel = new QLabel(verticalLayoutWidget);
        dFiLabel->setObjectName(QString::fromUtf8("dFiLabel"));
        dFiLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dFiLabel, 0, 0, 1, 1, Qt::AlignRight);

        wFiDpiLabel = new QLabel(verticalLayoutWidget);
        wFiDpiLabel->setObjectName(QString::fromUtf8("wFiDpiLabel"));

        gridLayout->addWidget(wFiDpiLabel, 2, 3, 1, 1, Qt::AlignRight);

        dwFoOrientationComboBox = new QComboBox(verticalLayoutWidget);
        dwFoOrientationComboBox->setObjectName(QString::fromUtf8("dwFoOrientationComboBox"));
        dwFoOrientationComboBox->setMinimumSize(QSize(65, 0));
        dwFoOrientationComboBox->setMaximumSize(QSize(16777215, 16777215));
#ifndef QT_NO_WHATSTHIS
        dwFoOrientationComboBox->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS

        gridLayout->addWidget(dwFoOrientationComboBox, 3, 4, 1, 1);

        dwFoLineEdit = new QLineEdit(verticalLayoutWidget);
        dwFoLineEdit->setObjectName(QString::fromUtf8("dwFoLineEdit"));
        dwFoLineEdit->setReadOnly(true);

        gridLayout->addWidget(dwFoLineEdit, 3, 1, 1, 1);

        dwFoChooseButton = new QPushButton(verticalLayoutWidget);
        dwFoChooseButton->setObjectName(QString::fromUtf8("dwFoChooseButton"));
        dwFoChooseButton->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(dwFoChooseButton, 3, 2, 1, 1);

        dwFoActionButton = new QPushButton(verticalLayoutWidget);
        dwFoActionButton->setObjectName(QString::fromUtf8("dwFoActionButton"));
        dwFoActionButton->setMinimumSize(QSize(160, 0));
        dwFoActionButton->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(dwFoActionButton, 3, 5, 1, 1);

        dwFiActionButton = new QPushButton(verticalLayoutWidget);
        dwFiActionButton->setObjectName(QString::fromUtf8("dwFiActionButton"));
        dwFiActionButton->setMinimumSize(QSize(160, 0));
        dwFiActionButton->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(dwFiActionButton, 1, 5, 1, 1);

        dwFiOrientationComboBox = new QComboBox(verticalLayoutWidget);
        dwFiOrientationComboBox->setObjectName(QString::fromUtf8("dwFiOrientationComboBox"));
        dwFiOrientationComboBox->setMinimumSize(QSize(65, 0));
        dwFiOrientationComboBox->setMaximumSize(QSize(16777215, 16777215));
#ifndef QT_NO_WHATSTHIS
        dwFiOrientationComboBox->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS

        gridLayout->addWidget(dwFiOrientationComboBox, 1, 4, 1, 1);

        wFoDpiLabel = new QLabel(verticalLayoutWidget);
        wFoDpiLabel->setObjectName(QString::fromUtf8("wFoDpiLabel"));

        gridLayout->addWidget(wFoDpiLabel, 4, 3, 1, 1, Qt::AlignRight);

        wFiChooseButton = new QPushButton(verticalLayoutWidget);
        wFiChooseButton->setObjectName(QString::fromUtf8("wFiChooseButton"));
        wFiChooseButton->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(wFiChooseButton, 2, 2, 1, 1);

        dwFoOrientationLabel = new QLabel(verticalLayoutWidget);
        dwFoOrientationLabel->setObjectName(QString::fromUtf8("dwFoOrientationLabel"));

        gridLayout->addWidget(dwFoOrientationLabel, 3, 3, 1, 1, Qt::AlignRight);

        dFiActionButton = new QPushButton(verticalLayoutWidget);
        dFiActionButton->setObjectName(QString::fromUtf8("dFiActionButton"));
        dFiActionButton->setMinimumSize(QSize(160, 0));
        dFiActionButton->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(dFiActionButton, 0, 5, 1, 1);

        wFoChooseButton = new QPushButton(verticalLayoutWidget);
        wFoChooseButton->setObjectName(QString::fromUtf8("wFoChooseButton"));
        wFoChooseButton->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(wFoChooseButton, 4, 2, 1, 1);

        wFoLineEdit = new QLineEdit(verticalLayoutWidget);
        wFoLineEdit->setObjectName(QString::fromUtf8("wFoLineEdit"));
        wFoLineEdit->setReadOnly(true);

        gridLayout->addWidget(wFoLineEdit, 4, 1, 1, 1);

        dwFiOrientationLabel = new QLabel(verticalLayoutWidget);
        dwFiOrientationLabel->setObjectName(QString::fromUtf8("dwFiOrientationLabel"));

        gridLayout->addWidget(dwFiOrientationLabel, 1, 3, 1, 1, Qt::AlignRight);

        wFoActionButton = new QPushButton(verticalLayoutWidget);
        wFoActionButton->setObjectName(QString::fromUtf8("wFoActionButton"));
        wFoActionButton->setMinimumSize(QSize(160, 0));
        wFoActionButton->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(wFoActionButton, 4, 5, 1, 1);

        wFoLabel = new QLabel(verticalLayoutWidget);
        wFoLabel->setObjectName(QString::fromUtf8("wFoLabel"));

        gridLayout->addWidget(wFoLabel, 4, 0, 1, 1, Qt::AlignRight);

        dFiChooseButton = new QPushButton(verticalLayoutWidget);
        dFiChooseButton->setObjectName(QString::fromUtf8("dFiChooseButton"));
        dFiChooseButton->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(dFiChooseButton, 0, 2, 1, 1);

        dFiOrientationLabel = new QLabel(verticalLayoutWidget);
        dFiOrientationLabel->setObjectName(QString::fromUtf8("dFiOrientationLabel"));

        gridLayout->addWidget(dFiOrientationLabel, 0, 3, 1, 1, Qt::AlignRight);

        dFiOrientationComboBox = new QComboBox(verticalLayoutWidget);
        dFiOrientationComboBox->setObjectName(QString::fromUtf8("dFiOrientationComboBox"));
        dFiOrientationComboBox->setMinimumSize(QSize(65, 0));
        dFiOrientationComboBox->setMaximumSize(QSize(16777215, 16777215));
#ifndef QT_NO_WHATSTHIS
        dFiOrientationComboBox->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS

        gridLayout->addWidget(dFiOrientationComboBox, 0, 4, 1, 1);

        dwFiLineEdit = new QLineEdit(verticalLayoutWidget);
        dwFiLineEdit->setObjectName(QString::fromUtf8("dwFiLineEdit"));
        dwFiLineEdit->setEnabled(true);
        dwFiLineEdit->setReadOnly(true);

        gridLayout->addWidget(dwFiLineEdit, 1, 1, 1, 1);

        dwFiChooseButton = new QPushButton(verticalLayoutWidget);
        dwFiChooseButton->setObjectName(QString::fromUtf8("dwFiChooseButton"));
        dwFiChooseButton->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(dwFiChooseButton, 1, 2, 1, 1);

        wFiDpiSpinBox = new QSpinBox(verticalLayoutWidget);
        wFiDpiSpinBox->setObjectName(QString::fromUtf8("wFiDpiSpinBox"));
#ifndef QT_NO_WHATSTHIS
        wFiDpiSpinBox->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
        wFiDpiSpinBox->setMinimum(1);
        wFiDpiSpinBox->setMaximum(65535);
        wFiDpiSpinBox->setValue(1);

        gridLayout->addWidget(wFiDpiSpinBox, 2, 4, 1, 1);

        wFoDpiSpinBox = new QSpinBox(verticalLayoutWidget);
        wFoDpiSpinBox->setObjectName(QString::fromUtf8("wFoDpiSpinBox"));
#ifndef QT_NO_WHATSTHIS
        wFoDpiSpinBox->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
        wFoDpiSpinBox->setMinimum(1);
        wFoDpiSpinBox->setMaximum(65535);
        wFoDpiSpinBox->setValue(1);

        gridLayout->addWidget(wFoDpiSpinBox, 4, 4, 1, 1);

        dFiLineEdit = new QLineEdit(verticalLayoutWidget);
        dFiLineEdit->setObjectName(QString::fromUtf8("dFiLineEdit"));
        dFiLineEdit->setReadOnly(true);

        gridLayout->addWidget(dFiLineEdit, 0, 1, 1, 1);

        dwFoLabel = new QLabel(verticalLayoutWidget);
        dwFoLabel->setObjectName(QString::fromUtf8("dwFoLabel"));

        gridLayout->addWidget(dwFoLabel, 3, 0, 1, 1, Qt::AlignRight);


        verticalLayout->addLayout(gridLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        outputTextBrowser = new QTextBrowser(verticalLayoutWidget);
        outputTextBrowser->setObjectName(QString::fromUtf8("outputTextBrowser"));
        outputTextBrowser->setUndoRedoEnabled(false);
        outputTextBrowser->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>"));
        outputTextBrowser->setAcceptRichText(false);
        outputTextBrowser->setCursorWidth(3);
        outputTextBrowser->setTextInteractionFlags(Qt::TextSelectableByMouse);
        outputTextBrowser->setOpenLinks(false);

        gridLayout_4->addWidget(outputTextBrowser, 0, 1, 1, 1);

        forceCancelButton = new QPushButton(verticalLayoutWidget);
        forceCancelButton->setObjectName(QString::fromUtf8("forceCancelButton"));
        forceCancelButton->setMinimumSize(QSize(90, 0));

        gridLayout_4->addWidget(forceCancelButton, 0, 3, 1, 1);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(80, 0));

        gridLayout_4->addWidget(cancelButton, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        openDPIdetectorGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(openDPIdetectorGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 769, 21));
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        openDPIdetectorGui->setMenuBar(menuBar);
        statusBar = new QStatusBar(openDPIdetectorGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        openDPIdetectorGui->setStatusBar(statusBar);

        menuBar->addAction(menuLanguage->menuAction());

        retranslateUi(openDPIdetectorGui);

        QMetaObject::connectSlotsByName(openDPIdetectorGui);
    } // setupUi

    void retranslateUi(QMainWindow *openDPIdetectorGui)
    {
        dwFiLabel->setText(QApplication::translate("openDPIdetectorGui", "File:", 0, QApplication::UnicodeUTF8));
        wFiActionButton->setText(QApplication::translate("openDPIdetectorGui", "Save DPI of file", 0, QApplication::UnicodeUTF8));
        wFiLabel->setText(QApplication::translate("openDPIdetectorGui", "File:", 0, QApplication::UnicodeUTF8));
        dFiLabel->setText(QApplication::translate("openDPIdetectorGui", "File:", 0, QApplication::UnicodeUTF8));
        wFiDpiLabel->setText(QApplication::translate("openDPIdetectorGui", "DPI:", 0, QApplication::UnicodeUTF8));
        dwFoOrientationComboBox->clear();
        dwFoOrientationComboBox->insertItems(0, QStringList()
         << QApplication::translate("openDPIdetectorGui", "up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "left", 0, QApplication::UnicodeUTF8)
        );
        dwFoChooseButton->setText(QApplication::translate("openDPIdetectorGui", "Choose", 0, QApplication::UnicodeUTF8));
        dwFoActionButton->setText(QApplication::translate("openDPIdetectorGui", "Detect and save DPI of folder", 0, QApplication::UnicodeUTF8));
        dwFiActionButton->setText(QApplication::translate("openDPIdetectorGui", "Detect and save DPI of file", 0, QApplication::UnicodeUTF8));
        dwFiOrientationComboBox->clear();
        dwFiOrientationComboBox->insertItems(0, QStringList()
         << QApplication::translate("openDPIdetectorGui", "up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "left", 0, QApplication::UnicodeUTF8)
        );
        wFoDpiLabel->setText(QApplication::translate("openDPIdetectorGui", "DPI:", 0, QApplication::UnicodeUTF8));
        wFiChooseButton->setText(QApplication::translate("openDPIdetectorGui", "Choose", 0, QApplication::UnicodeUTF8));
        dwFoOrientationLabel->setText(QApplication::translate("openDPIdetectorGui", "Mark orientation:", 0, QApplication::UnicodeUTF8));
        dFiActionButton->setText(QApplication::translate("openDPIdetectorGui", "Detect DPI of file", 0, QApplication::UnicodeUTF8));
        wFoChooseButton->setText(QApplication::translate("openDPIdetectorGui", "Choose", 0, QApplication::UnicodeUTF8));
        dwFiOrientationLabel->setText(QApplication::translate("openDPIdetectorGui", "Mark orientation:", 0, QApplication::UnicodeUTF8));
        wFoActionButton->setText(QApplication::translate("openDPIdetectorGui", "Save DPI of folder", 0, QApplication::UnicodeUTF8));
        wFoLabel->setText(QApplication::translate("openDPIdetectorGui", "Folder:", 0, QApplication::UnicodeUTF8));
        dFiChooseButton->setText(QApplication::translate("openDPIdetectorGui", "Choose", 0, QApplication::UnicodeUTF8));
        dFiOrientationLabel->setText(QApplication::translate("openDPIdetectorGui", "Mark orientation:", 0, QApplication::UnicodeUTF8));
        dFiOrientationComboBox->clear();
        dFiOrientationComboBox->insertItems(0, QStringList()
         << QApplication::translate("openDPIdetectorGui", "up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openDPIdetectorGui", "left", 0, QApplication::UnicodeUTF8)
        );
        dwFiChooseButton->setText(QApplication::translate("openDPIdetectorGui", "Choose", 0, QApplication::UnicodeUTF8));
        dwFoLabel->setText(QApplication::translate("openDPIdetectorGui", "Folder:", 0, QApplication::UnicodeUTF8));
        forceCancelButton->setText(QApplication::translate("openDPIdetectorGui", "Force stop", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("openDPIdetectorGui", "Stop", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("openDPIdetectorGui", "Language", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(openDPIdetectorGui);
    } // retranslateUi

};

namespace Ui {
    class openDPIdetectorGui: public Ui_openDPIdetectorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDPIGUI_H
