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
#include <stdint.h>

using namespace std;

typedef unsigned char BYTE;

enum Format {
    UNKNOWN, BPS_8_MONO, BPS_8_STEREO, BPS_16_MONO, BPS_16_STEREO
};

class Wav {
public:
    Wav(string filename);
    ~Wav();
    
    int load();
    BYTE* getData() { return data; }
    int32_t getSampleRate() { return sampleRate; }
    int32_t getDataSize() { return dataSize; }
    Format getFormat();
    
private:
    int returnError(string message, FILE *fileToClose);
    BYTE* data;
    int32_t sampleRate;
    int32_t dataSize;
    short bitsPerSample;
    short channels;
    string filename;
};

#endif	/* WAV_H */

