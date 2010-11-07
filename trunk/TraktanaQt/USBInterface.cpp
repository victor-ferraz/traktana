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

    ftdih = new Context();
}

USBInterface::~USBInterface() {
}

bool USBInterface::connect() {
        int ret;
        std::cout << "Opening... \n";
        ret = this->ftdih->open(0x0403,0x6010);
//        ret = ftdih.open("FT2232H MiniModule");
//        ret = ftdih.open(0x0403,0x6010,"FT2232H MiniModule");
        std::cout << "ret: " << ret << "\n";
        if (ret == 0) {
            std::cout << "true \n";
            return true;
        } else {
            std::cout << "false \n";
            return false;
        }
//        std::cout << "Searching... \n";
//        List* list = List::find_all(0x0403,0x6010);
//        for (List::iterator it = list->begin(); it != list->end(); it++)
//        {
//            std::cout << "FTDI (" << &*it << "): "
//            << it->vendor() << ", "
//            << it->description() << ", "
//            << it->serial();
//
//            // Open test
//            if(it->open() == 0){
//               std::cout << " (Open OK)";
//            }else{
//               std::cout << " (Open FAILED)";
//               it->close();
//            }
//            std::cout << std::endl;
//
//        }
//        std::cout << "Finished\n";
//
//            return false;
//    struct ftdi_context ftdih;
//    // Init
//    std::cout << "Init...\n";
//    if (ftdi_init(&ftdih) < 0) {
//        std::cout << "ftdi_init failed\n";
//    }
//
//    // Select first interface
//    //ftdi_set_interface(&ftdih, 1);
//    std::cout << "Opening...\n";
//    // Open device
//    int f = ftdi_usb_open(&ftdih, 0x0403, 0x6010);
//    if (f < 0) {
//        std::cout << "unable to open ftdi device: \n";
//    }
//    // Select first interface
//    ftdi_set_interface(&ftdih, INTERFACE_A);
//    // Set baudrate
//    f = ftdi_set_baudrate(&ftdih, 115200);
//    if (f < 0) {
//        std::cout << "unable to set baudrate: \n";
//    }
//
//    std::cout << "Finished\n";
//    return false;
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
