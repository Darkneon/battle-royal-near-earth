/* 
 * File:   Tracks.h
 * Author: Stefanie Lavoie
 *
 */

#ifndef TRACKS_H
#define	TRACKS_H

#include "Model.h"

class Tracks {
public:
    Tracks();
    ~Tracks();
    void draw();
private:
    Model* model;

};

#endif

