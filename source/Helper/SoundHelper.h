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
#include <map>
#include <iostream> //For NULL
#include "Wav.h"

using namespace std;

typedef std::pair<string, ALuint*> bufferPair; 

class SoundHelper {
public:
    SoundHelper(string path);
    ~SoundHelper();
    
    static SoundHelper* getInstance();

    
    void play(string filename, bool isLoop);
    void play(string filename, int sourceNumber, bool isLoop);

private:
    static ALuint* loadWav(string filename, int sourceNumber);
    
    static SoundHelper *instance;
    
    static ALCcontext *context;
    static ALCdevice *device;
    static ALuint source[3];                                                           
    static map<string, ALuint*> buffers;
    static string path;
    static Wav *wavFile;
};

#endif	/* SOUNDHELPER_H */

