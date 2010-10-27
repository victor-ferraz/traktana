/* 
 * File:   USBInterface.cpp
 * Author: victor
 * 
 * Created on 26 de Outubro de 2010, 21:32
 */

#include "USBInterface.h"

USBInterface::USBInterface() {
    connected = false;
    connectedA = false;
    connectedB = false;
    connectedC = false;
    connectedD = false;
}

USBInterface::~USBInterface() {
}

bool USBInterface::connect() {
    return false;
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
