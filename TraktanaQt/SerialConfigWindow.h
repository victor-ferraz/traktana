/* 
 * File:   SerialConfigWindow.h
 * Author: victor
 *
 * Created on 24 de Outubro de 2010, 19:35
 */

#ifndef _SERIALCONFIGWINDOW_H
#define	_SERIALCONFIGWINDOW_H

#include "ui_SerialConfigWindow.h"

class SerialConfigWindow : public QDialog {
    Q_OBJECT
public:
    SerialConfigWindow();
    virtual ~SerialConfigWindow();
private:
    Ui::SerialConfigWindow widget;
};

#endif	/* _SERIALCONFIGWINDOW_H */
