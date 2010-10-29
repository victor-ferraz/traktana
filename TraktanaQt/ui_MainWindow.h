/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Fri Oct 29 14:52:52 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionOperation;
    QAction *actionStatus;
    QAction *actionDebug;
    QAction *actionOperationTool;
    QAction *actionDeviceTool;
    QAction *actionStart;
    QAction *actionPause;
    QAction *actionRestart;
    QAction *actionConnect;
    QAction *actionConnect_Debug;
    QAction *actionOptions;
    QAction *actionSerialDeviceConfig;
    QAction *actionSerialDebugConfig;
    QAction *actionAbout;
    QAction *actionDisconnect;
    QAction *actionDisconnectDebug;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QWidget *subwindowStatus;
    QLabel *labelTime;
    QLabel *labelCycles;
    QLabel *labelPlain;
    QLineEdit *lineEditTime;
    QLineEdit *lineEditCycles;
    QLineEdit *lineEditPlain;
    QTextEdit *textEdit;
    QWidget *subwindowOperation;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *subwindowDebug;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuToolBars;
    QMenu *menuOperation;
    QMenu *menuDevice;
    QMenu *menuConfiguration;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBarOperation;
    QToolBar *toolBarConnect;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(795, 427);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/layers.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOperation = new QAction(MainWindow);
        actionOperation->setObjectName(QString::fromUtf8("actionOperation"));
        actionOperation->setCheckable(true);
        actionOperation->setChecked(true);
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName(QString::fromUtf8("actionStatus"));
        actionStatus->setCheckable(true);
        actionStatus->setChecked(true);
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        actionDebug->setCheckable(true);
        actionDebug->setChecked(true);
        actionOperationTool = new QAction(MainWindow);
        actionOperationTool->setObjectName(QString::fromUtf8("actionOperationTool"));
        actionOperationTool->setCheckable(true);
        actionOperationTool->setChecked(true);
        actionDeviceTool = new QAction(MainWindow);
        actionDeviceTool->setObjectName(QString::fromUtf8("actionDeviceTool"));
        actionDeviceTool->setCheckable(true);
        actionDeviceTool->setChecked(true);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/play.png"), QSize(), QIcon::Normal, QIcon::On);
        actionStart->setIcon(icon1);
        actionStart->setIconVisibleInMenu(false);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon2);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/refresh_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon3);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon4);
        actionConnect_Debug = new QAction(MainWindow);
        actionConnect_Debug->setObjectName(QString::fromUtf8("actionConnect_Debug"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/connectbug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_Debug->setIcon(icon5);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionSerialDeviceConfig = new QAction(MainWindow);
        actionSerialDeviceConfig->setObjectName(QString::fromUtf8("actionSerialDeviceConfig"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/cog.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSerialDeviceConfig->setIcon(icon6);
        actionSerialDebugConfig = new QAction(MainWindow);
        actionSerialDebugConfig->setObjectName(QString::fromUtf8("actionSerialDebugConfig"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/cogbug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSerialDebugConfig->setIcon(icon7);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("icons/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon8);
        actionDisconnectDebug = new QAction(MainWindow);
        actionDisconnectDebug->setObjectName(QString::fromUtf8("actionDisconnectDebug"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("icons/disconnectbug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnectDebug->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 791, 351));
        mdiArea->setMinimumSize(QSize(791, 351));
        mdiArea->setFrameShape(QFrame::NoFrame);
        mdiArea->setFrameShadow(QFrame::Plain);
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setViewMode(QMdiArea::SubWindowView);
        mdiArea->setDocumentMode(false);
        subwindowStatus = new QWidget();
        subwindowStatus->setObjectName(QString::fromUtf8("subwindowStatus"));
        subwindowStatus->setEnabled(true);
        subwindowStatus->setMinimumSize(QSize(228, 226));
        subwindowStatus->setMouseTracking(false);
        labelTime = new QLabel(subwindowStatus);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(20, 30, 62, 17));
        labelCycles = new QLabel(subwindowStatus);
        labelCycles->setObjectName(QString::fromUtf8("labelCycles"));
        labelCycles->setGeometry(QRect(20, 60, 62, 17));
        labelPlain = new QLabel(subwindowStatus);
        labelPlain->setObjectName(QString::fromUtf8("labelPlain"));
        labelPlain->setGeometry(QRect(20, 90, 91, 17));
        lineEditTime = new QLineEdit(subwindowStatus);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));
        lineEditTime->setGeometry(QRect(110, 20, 113, 27));
        lineEditCycles = new QLineEdit(subwindowStatus);
        lineEditCycles->setObjectName(QString::fromUtf8("lineEditCycles"));
        lineEditCycles->setGeometry(QRect(110, 50, 113, 27));
        lineEditPlain = new QLineEdit(subwindowStatus);
        lineEditPlain->setObjectName(QString::fromUtf8("lineEditPlain"));
        lineEditPlain->setGeometry(QRect(110, 80, 113, 27));
        textEdit = new QTextEdit(subwindowStatus);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 120, 211, 101));
        mdiArea->addSubWindow(subwindowStatus);
        subwindowOperation = new QWidget();
        subwindowOperation->setObjectName(QString::fromUtf8("subwindowOperation"));
        subwindowOperation->setMinimumSize(QSize(249, 202));
        subwindowOperation->setMouseTracking(true);
        label = new QLabel(subwindowOperation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 62, 17));
        label_2 = new QLabel(subwindowOperation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 42, 62, 17));
        label_3 = new QLabel(subwindowOperation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(9, 75, 62, 17));
        label_4 = new QLabel(subwindowOperation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(9, 108, 62, 17));
        spinBox = new QSpinBox(subwindowOperation);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(77, 9, 43, 27));
        doubleSpinBox = new QDoubleSpinBox(subwindowOperation);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(77, 42, 63, 27));
        doubleSpinBox_2 = new QDoubleSpinBox(subwindowOperation);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(77, 75, 63, 27));
        doubleSpinBox_3 = new QDoubleSpinBox(subwindowOperation);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(77, 108, 63, 27));
        mdiArea->addSubWindow(subwindowOperation);
        subwindowDebug = new QWidget();
        subwindowDebug->setObjectName(QString::fromUtf8("subwindowDebug"));
        subwindowDebug->setMinimumSize(QSize(266, 195));
        mdiArea->addSubWindow(subwindowDebug);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 795, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuToolBars = new QMenu(menuView);
        menuToolBars->setObjectName(QString::fromUtf8("menuToolBars"));
        menuOperation = new QMenu(menubar);
        menuOperation->setObjectName(QString::fromUtf8("menuOperation"));
        menuDevice = new QMenu(menubar);
        menuDevice->setObjectName(QString::fromUtf8("menuDevice"));
        menuConfiguration = new QMenu(menubar);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBarOperation = new QToolBar(MainWindow);
        toolBarOperation->setObjectName(QString::fromUtf8("toolBarOperation"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarOperation);
        toolBarConnect = new QToolBar(MainWindow);
        toolBarConnect->setObjectName(QString::fromUtf8("toolBarConnect"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarConnect);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOperation->menuAction());
        menubar->addAction(menuDevice->menuAction());
        menubar->addAction(menuConfiguration->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuView->addAction(actionOperation);
        menuView->addAction(actionStatus);
        menuView->addAction(actionDebug);
        menuView->addSeparator();
        menuView->addAction(menuToolBars->menuAction());
        menuToolBars->addAction(actionOperationTool);
        menuToolBars->addAction(actionDeviceTool);
        menuOperation->addAction(actionStart);
        menuOperation->addAction(actionPause);
        menuOperation->addAction(actionRestart);
        menuDevice->addAction(actionConnect);
        menuDevice->addAction(actionConnect_Debug);
        menuConfiguration->addAction(actionOptions);
        menuConfiguration->addAction(actionSerialDeviceConfig);
        menuConfiguration->addAction(actionSerialDebugConfig);
        menuHelp->addAction(actionAbout);
        toolBarOperation->addAction(actionStart);
        toolBarOperation->addAction(actionRestart);
        toolBarConnect->addAction(actionConnect);
        toolBarConnect->addAction(actionSerialDeviceConfig);
        toolBarConnect->addAction(actionConnect_Debug);
        toolBarConnect->addAction(actionSerialDebugConfig);
        toolBarConnect->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Traktana - Centro Brasileiro de Pesquisas F\303\255sicas", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOperation->setText(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        actionStatus->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        actionDebug->setText(QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
        actionOperationTool->setText(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        actionDeviceTool->setText(QApplication::translate("MainWindow", "Device/Configuration", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionStart->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionPause->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0, QApplication::UnicodeUTF8));
        actionRestart->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionConnect_Debug->setText(QApplication::translate("MainWindow", "Connect Debug", 0, QApplication::UnicodeUTF8));
        actionConnect_Debug->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        actionSerialDeviceConfig->setText(QApplication::translate("MainWindow", "Serial Device", 0, QApplication::UnicodeUTF8));
        actionSerialDebugConfig->setText(QApplication::translate("MainWindow", "Serial Debug", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        actionDisconnectDebug->setText(QApplication::translate("MainWindow", "DisconnectDebug", 0, QApplication::UnicodeUTF8));
        subwindowStatus->setWindowTitle(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        subwindowStatus->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        labelTime->setText(QApplication::translate("MainWindow", "Time:", 0, QApplication::UnicodeUTF8));
        labelCycles->setText(QApplication::translate("MainWindow", "Cycles:", 0, QApplication::UnicodeUTF8));
        labelPlain->setText(QApplication::translate("MainWindow", "Length plain:", 0, QApplication::UnicodeUTF8));
        subwindowOperation->setWindowTitle(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        subwindowDebug->setWindowTitle(QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuToolBars->setTitle(QApplication::translate("MainWindow", "ToolBars", 0, QApplication::UnicodeUTF8));
        menuOperation->setTitle(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        menuDevice->setTitle(QApplication::translate("MainWindow", "Device", 0, QApplication::UnicodeUTF8));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBarOperation->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBarConnect->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
