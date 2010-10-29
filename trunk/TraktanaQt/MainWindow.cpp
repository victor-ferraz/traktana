/*
 * File:   MainWindow.cpp
 * Author: victor
 *
 * Created on 23 de Outubro de 2010, 13:32
 */

#include "MainWindow.h"
#include <stdio.h>

MainWindow::MainWindow() {
    widget.setupUi(this);
}

MainWindow::~MainWindow() {
}

void MainWindow::on_actionExit_triggered(){
 
}
void MainWindow::on_actionStart_triggered(){

}
void MainWindow::on_actionPause_triggered(){

}
void MainWindow::on_actionRestart_triggered(){

}
void MainWindow::on_actionOperation_triggered(){
    if(widget.actionOperation->isChecked()){
        widget.subwindowOperation->showNormal();
        widget.subwindowOperation->activateWindow();
    }else{
        widget.subwindowOperation->showMinimized();
    }
}
void MainWindow::on_actionStatus_triggered(){
    if(widget.actionStatus->isChecked()){
        widget.subwindowStatus->showNormal();
        widget.subwindowStatus->activateWindow();
    }else{
        widget.subwindowStatus->showMinimized();
    }
}
void MainWindow::on_actionDebug_triggered(){
    if(widget.actionDebug->isChecked()){
        widget.subwindowDebug->showNormal();
        widget.subwindowDebug->activateWindow();
    }else{
        widget.subwindowDebug->showMinimized();
    }
}
void MainWindow::on_actionOperationTool_triggered() {
    if (widget.actionOperationTool->isChecked()) {
        widget.toolBarOperation->show();
    } else {
        widget.toolBarOperation->hide();
    }
}
void MainWindow::on_actionDeviceTool_triggered(){
    if (widget.actionDeviceTool->isChecked()) {
        widget.toolBarConnect->show();
    } else {
        widget.toolBarConnect->hide();
    }
}
void MainWindow::on_actionConnect_triggered(){

}
void MainWindow::on_actionConnect_Debug_triggered(){

}
void MainWindow::on_actionSerialDeviceConfig_triggered(){

}
void MainWindow::on_actionSerialDebugConfig_triggered(){

}
void MainWindow::on_actionAbout_triggered(){

}
