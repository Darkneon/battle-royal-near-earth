/* 
 * File:   Wav.h
 * Author: robert
 *
 * Created on April 1, 2012, 3:45 AM
 */

#ifndef WAV_H
#define	WAV_H

#include <string>
#include <stdio.h>
#include <cstdlib>


using namespace std;

typedef unsigned char BYTE;
typedef unsigned int  INT32;

enum Format {
    UNKNOWN, BPS_8_MONO, BPS_8_STEREO, BPS_16_MONO, BPS_16_STEREO
};

class Wav {
public:
    Wav(string filename);
    ~Wav();
    
    int load();
    BYTE* getData() { return data; }
    INT32 getSampleRate() { return sampleRate; }
    INT32 getDataSize() { return dataSize; }
    Format getFormat();
    
private:
    int returnError(string message, FILE *fileToClose);
    BYTE* data;
    INT32 sampleRate;
    INT32 dataSize;
    short bitsPerSample;
    short channels;
    string filename;
};

#endif	/* WAV_H */

