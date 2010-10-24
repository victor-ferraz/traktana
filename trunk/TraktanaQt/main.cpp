/*
 * File:   main.cpp
 * Author: victor
 *
 * Created on 23 de Outubro de 2010, 12:58
 */

#include <QtGui/QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here

    MainWindow mainwindow;
    mainwindow.show();
    return app.exec();
}
