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

}

bool TraktanaDebug::disconnectUSB() {

}

bool TraktanaDebug::connectDevice() {

}

bool TraktanaDebug::disconnectDevice() {

}

bool TraktanaDebug::connectDebug() {

}

bool TraktanaDebug::disconnectDebug() {

}

void TraktanaDebug::writeDevice(unsigned char* cmd) {

}

char* TraktanaDebug::receiveDevice() {

}

void TraktanaDebug::writeDebug(unsigned char* cmd) {

}

char* TraktanaDebug::receiveDebug() {

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
