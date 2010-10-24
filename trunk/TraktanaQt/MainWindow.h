/* 
 * File:   MainWindow.h
 * Author: victor
 *
 * Created on 23 de Outubro de 2010, 13:32
 */

#ifndef _MAINWINDOW_H
#define	_MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
};

#endif	/* _MAINWINDOW_H */
