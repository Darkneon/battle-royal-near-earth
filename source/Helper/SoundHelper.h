/* 
 * File:   SoundHelper.h
 * Author: robert
 *
 * Created on March 31, 2012, 7:45 PM
 */

#ifndef SOUNDHELPER_H
#define	SOUNDHELPER_H

#ifdef __APPLE__   
    #include <OpenAL/al.h>
    #include <OpenAL/alc.h>
#else
    #include "AL/al.h"
	#include "AL/alc.h"
#endif

#include <string>
#include <iostream> //For NULL
#include "Wav.h"

using namespace std;

class SoundHelper {
public:
    SoundHelper();
    ~SoundHelper();
    
    void loadWav(string filename);
    void play();
 
private:
    
    ALCcontext *context;
    ALCdevice *device;
    ALuint source;                                                           
    ALuint buffer;
    
    Wav *wavFile;
};

#endif	/* SOUNDHELPER_H */

