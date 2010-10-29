/* 
 * File:   USBInterface.h
 * Author: victor
 *
 * Created on 26 de Outubro de 2010, 21:32
 */

#ifndef USBINTERFACE_H
#define	USBINTERFACE_H

#include "ftdi.hpp"
using namespace Ftdi;

class USBInterface {
public:
    USBInterface();
    virtual ~USBInterface();
    bool connect();
    bool disconnect();
    bool connectInterfaceA();
    bool connectInterfaceB();
    bool connectInterfaceC();
    bool connectInterfaceD();
    bool disconnectInterfaceA();
    bool disconnectInterfaceB();
    bool disconnectInterfaceC();
    bool disconnectInterfaceD();
private:

    //Ftdi::Context ftdih;
    bool connected;
    bool connectedA;
    bool connectedB;
    bool connectedC;
    bool connectedD;

    char buf[1024];
    int f, i;
    int vid;
    int pid;
    int baudrate;
    int interface;

};

#endif	/* USBINTERFACE_H */

