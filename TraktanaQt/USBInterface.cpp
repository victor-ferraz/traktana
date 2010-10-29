/* 
 * File:   USBInterface.cpp
 * Author: victor
 * 
 * Created on 26 de Outubro de 2010, 21:32
 */

#include <iostream>
#include "USBInterface.h"


USBInterface::USBInterface() {

    connected = false;
    connectedA = false;
    connectedB = false;
    connectedC = false;
    connectedD = false;

    vid = 0x0403;
    pid = 0x6010;
    baudrate = 115200;
    interface = INTERFACE_A;
}

USBInterface::~USBInterface() {
}

bool USBInterface::connect() {
//    int ret;
//    ret = ftdih.open(vid, pid);
//    if (ret == 0) {
//        return true;
//    } else {
//        return false;
//    }

    return true;

}

bool USBInterfacedisconnect() {
    return false;
}

bool USBInterfaceconnectInterfaceA() {
    return false;
}

bool USBInterfaceconnectInterfaceB() {
    return false;
}

bool USBInterfaceconnectInterfaceC() {
    return false;
}

bool USBInterfaceconnectInterfaceD() {
    return false;
}

bool USBInterfacedisconnectInterfaceA() {
    return false;
}

bool USBInterfacedisconnectInterfaceB() {
    return false;
}

bool USBInterfacedisconnectInterfaceC() {
    return false;
}

bool USBInterfacedisconnectInterfaceD() {
    return false;
}
