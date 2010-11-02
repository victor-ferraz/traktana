/* 
 * File:   MainWindow.h
 * Author: victor
 *
 * Created on 23 de Outubro de 2010, 13:32
 */

#ifndef _MAINWINDOW_H
#define	_MAINWINDOW_H

#include "ui_MainWindow.h"
#include "Program.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();
public slots:
    // Menu File
    void on_actionExit_triggered();
    // Menu Operation
    void on_actionStart_triggered();
    void on_actionRestart_triggered();
    // Menu View
    void on_actionOperation_triggered();
    void on_actionStatus_triggered();
    void on_actionDebug_triggered();
    void on_actionOperationTool_triggered();
    void on_actionDeviceTool_triggered();
    // Menu Device
    void on_actionConnect_triggered();
    void on_actionConnect_Debug_triggered();
    // Menu Configuration
    void on_actionSerialDeviceConfig_triggered();
    void on_actionSerialDebugConfig_triggered();
    // Menu Help
    void on_actionAbout_triggered();
    // Interface Buttons
    void on_pushButtonSend_clicked();
private:
    Ui::MainWindow widget;
    Program *program;
};

#endif	/* _MAINWINDOW_H */
