/* 
 * File:   Program.cpp
 * Author: victor
 * 
 * Created on 24 de Outubro de 2010, 19:33
 */

#include "Program.h"

Program::Program() {
    traktana = new Traktana();
}

Program::~Program() {
}

bool Program::connectUSB(){
    // traktana->connect();
    return true;
}
