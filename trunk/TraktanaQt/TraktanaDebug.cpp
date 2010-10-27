/* 
 * File:   TraktanaDebug.cpp
 * Author: victor
 * 
 * Created on 24 de Outubro de 2010, 19:28
 */

#include "TraktanaDebug.h"

TraktanaDebug::TraktanaDebug() {
    usb = new USBInterface();
    connectedDevice = false;
    connectedDebug = false;
}

TraktanaDebug::~TraktanaDebug() {
}

bool TraktanaDebug::connectUSB() {
    return false;
}

bool TraktanaDebug::disconnectUSB() {
return false;
}

bool TraktanaDebug::connectDevice() {
return false;
}

bool TraktanaDebug::disconnectDevice() {
return false;
}

bool TraktanaDebug::connectDebug() {
return false;
}

bool TraktanaDebug::disconnectDebug() {
return false;
}

void TraktanaDebug::writeDevice(unsigned char* cmd) {

}

char* TraktanaDebug::receiveDevice() {
    char ch = 's';
    return &ch;
}

void TraktanaDebug::writeDebug(unsigned char* cmd) {

}

char* TraktanaDebug::receiveDebug() {
    char ch = 's';
    return &ch;
}

void TraktanaDebug::rotateStepper(long steps, double freq, bool direction, int motor) {

}

void TraktanaDebug::turnOnStepper(bool on) {

}

void TraktanaDebug::readSensor(int sensor) {

}

void TraktanaDebug::readConfiguration() {

}

void TraktanaDebug::writeConfiguration() {

}
