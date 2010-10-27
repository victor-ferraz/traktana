/* 
 * File:   TraktanaDebug.h
 * Author: victor
 *
 * Created on 24 de Outubro de 2010, 19:28
 */

#ifndef TRAKTANADEBUG_H
#define	TRAKTANADEBUG_H

#include "USBInterface.h"

class TraktanaDebug {
public:
    TraktanaDebug();
    virtual ~TraktanaDebug();
    bool connectUSB();
    bool disconnectUSB();
    bool connectDevice();
    bool disconnectDevice();
    bool connectDebug();
    bool disconnectDebug();
    void writeDevice(unsigned char* cmd);
    char* receiveDevice();
    void writeDebug(unsigned char* cmd);
    char* receiveDebug();
    void rotateStepper(long steps, double freq, bool direction, int motor);
    void turnOnStepper(bool on);
    void readSensor(int sensor);
    void readConfiguration();
    void writeConfiguration();
    
private:
    USBInterface *usb;
    bool connectedDevice;
    bool connectedDebug;

};

#endif	/* TRAKTANADEBUG_H */

