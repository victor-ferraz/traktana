/* 
 * File:   USBInterface.h
 * Author: victor
 *
 * Created on 26 de Outubro de 2010, 21:32
 */

#ifndef USBINTERFACE_H
#define	USBINTERFACE_H

#include <ftdi.hpp>

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
    
    bool connected;
    bool connectedA;
    bool connectedB;
    bool connectedC;
    bool connectedD;

};

#endif	/* USBINTERFACE_H */

