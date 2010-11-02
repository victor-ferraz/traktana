/* 
 * File:   USBInterface.cpp
 * Author: victor
 * 
 * Created on 26 de Outubro de 2010, 21:32
 */

#include "USBInterface.h"
#include <iostream>

USBInterface::USBInterface() {

    connected = false;
    connectedA = false;
    connectedB = false;
    connectedC = false;
    connectedD = false;

    vid = 0x0403, pid = 0x6010;
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
    std::cout << "Searching... \n";
    List* list = List::find_all(0x0403,0x6010);
    for (List::iterator it = list->begin(); it != list->end(); it++)
    {
        std::cout << "FTDI (" << &*it << "): "
        << it->vendor() << ", "
        << it->description() << ", "
        << it->serial();

        // Open test
        if(it->open() == 0){
           std::cout << " (Open OK)";
        }else{
           std::cout << " (Open FAILED)";
           it->close();
        }
        std::cout << std::endl;

    }
    std::cout << "Finished\n";

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
