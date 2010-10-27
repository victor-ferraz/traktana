/* 
 * File:   Program.h
 * Author: victor
 *
 * Created on 24 de Outubro de 2010, 19:33
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include "Traktana.h"

class Program {
public:
    Program();
    virtual ~Program();
    bool connectUSB();
private:
    Traktana *traktana;

};

#endif	/* PROGRAM_H */

