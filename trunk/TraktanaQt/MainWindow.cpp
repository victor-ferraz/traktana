/*
 * File:   MainWindow.cpp
 * Author: victor
 *
 * Created on 23 de Outubro de 2010, 13:32
 */

#include "MainWindow.h"
#include <QIcon>
#include <QString>
#include <iostream>

MainWindow::MainWindow() {
    widget.setupUi(this);
}

MainWindow::~MainWindow() {
}

void MainWindow::on_actionExit_triggered() {
    exit(0);
}

void MainWindow::on_actionStart_triggered() {
    if (widget.actionStart->isChecked()) {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionStart->setIcon(ic);
        widget.actionStart->setText("Pause");
    } else {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionStart->setIcon(ic);
        widget.actionStart->setText("Start");
    }
}

void MainWindow::on_actionRestart_triggered() {

}

void MainWindow::on_actionOperation_triggered() {
    if (widget.actionOperation->isChecked()) {
        widget.subwindowOperation->showNormal();
        widget.subwindowOperation->activateWindow();
    } else {
        widget.subwindowOperation->showMinimized();
    }
}

void MainWindow::on_actionStatus_triggered() {
    if (widget.actionStatus->isChecked()) {
        widget.subwindowStatus->showNormal();
        widget.subwindowStatus->activateWindow();
    } else {
        widget.subwindowStatus->showMinimized();
    }
}

void MainWindow::on_actionDebug_triggered() {
    if (widget.actionDebug->isChecked()) {
        widget.subwindowDebug->showNormal();
        widget.subwindowDebug->activateWindow();
    } else {
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

void MainWindow::on_actionDeviceTool_triggered() {
    if (widget.actionDeviceTool->isChecked()) {
        widget.toolBarConnect->show();
    } else {
        widget.toolBarConnect->hide();
    }
}

void MainWindow::on_actionConnect_triggered() {
    if (widget.actionConnect->isChecked()) {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionConnect->setIcon(ic);
    } else {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionConnect->setIcon(ic);
    }
}

void MainWindow::on_actionConnect_Debug_triggered() {
    if (widget.actionConnect_Debug->isChecked()) {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/disconnectbug.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionConnect_Debug->setIcon(ic);
    } else {
        QIcon ic;
        ic.addFile(QString::fromUtf8("icons/connectbug.png"), QSize(), QIcon::Normal, QIcon::Off);
        widget.actionConnect_Debug->setIcon(ic);
    }
}

void MainWindow::on_actionSerialDeviceConfig_triggered() {

}

void MainWindow::on_actionSerialDebugConfig_triggered() {

}

void MainWindow::on_actionAbout_triggered() {

}

void MainWindow::on_pushButtonSend_clicked() {
    widget.textEditDebug->append("Connecting...");
    bool ret = program->connectUSB();
    if (ret) {
        widget.textEditDebug->append("retorno: true");
    } else {
        widget.textEditDebug->append("retorno: false");
    }
}

