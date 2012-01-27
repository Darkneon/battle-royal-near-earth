/* 
 * File:   Nuclear.h
 * Author: Jeffrey
 *
 * Created on January 27, 2012, 1:28 AM
 */

#ifndef NUCLEAR_H
#define	NUCLEAR_H

#include "Model.h"

class Nuclear {
public:
    Nuclear();
    ~Nuclear();
    void draw();     
private:
    Model *model;
    
};

#endif

