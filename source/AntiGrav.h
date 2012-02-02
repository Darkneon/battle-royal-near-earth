/* 
 * File:   AntiGrav.h
 * Author: Stefanie Lavoie
 *
 */

#ifndef ANTIGRAV_H
#define	ANTIGRAV_H

#include "Model.h"

class AntiGrav {
public:
    AntiGrav();
    ~AntiGrav();
    void draw();
private:
    Model* model;

};

#endif

