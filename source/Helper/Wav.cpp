/* 
 * File:   Wav.cpp
 * Author: robert
 * 
 * Created on April 1, 2012, 3:45 AM
 */

#include "Wav.h"
#include <iostream>


Wav::Wav(string filename) {
    this->filename = filename;
    data = NULL;
}

Wav::~Wav() {
    if (data != NULL) {
        delete[] data;
    }
}

int Wav::returnError(string message, FILE *fileToClose) {
    cout << message << endl;
    
    if (fileToClose != NULL) {
        fclose(fileToClose);
    }
    
    return 1;
}

int Wav::load() {
    
    FILE *fp = NULL;        
    fp = fopen(filename.c_str(),"rb");                                          
    if (!fp) {
        returnError("Failed to open file", NULL);
    }  
    
    //Variables to store info about the WAVE file (all of them is not needed for OpenAL)
    char type[4];
    INT32 size;
    INT32 chunkSize;
    short formatType;
    INT32 avgBytesPerSec;
    short bytesPerSample;
    
    //Check that the WAVE file is OK - RIFF
    fread(type, sizeof(char), 4, fp);                                              
    if (type[0]!='R' || type[1]!='I' || type[2]!='F' || type[3]!='F') {         
        return returnError("No RIFF", fp);                                   
    }

    fread(&size, sizeof(INT32), 1, fp);
    
    //Check that the WAVE file is OK - WAVE
    fread(type, sizeof(char), 4, fp);                                          
    if (type[0]!='W' || type[1]!='A' || type[2]!='V' || type[3]!='E') {        
        return returnError("not WAVE", fp);                                   
    }
    
    //Check that the WAVE file is OK - FMT
    fread(type, sizeof(char), 4, fp);                                             
    if (type[0]!='f' || type[1]!='m' || type[2]!='t' || type[3]!=' ') {          
        return returnError("not fmt ", fp);                                    
    }
    
    //Now we know that the file is a acceptable WAVE file
    //Info about the WAVE data is now read and stored
    fread(&chunkSize,       sizeof(INT32), 1, fp);
    fread(&formatType,      sizeof(short), 1, fp);
    fread(&channels,        sizeof(short), 1, fp);
    fread(&sampleRate,      sizeof(INT32), 1, fp);
    fread(&avgBytesPerSec,  sizeof(INT32), 1, fp);
    fread(&bytesPerSample,  sizeof(short), 1, fp);
    fread(&bitsPerSample,   sizeof(short), 1, fp);
    
    //Check that the WAVE file is OK - DATA
    fread(type, sizeof(char), 4, fp);
    if (type[0]!='d' || type[1]!='a' || type[2]!='t' || type[3]!='a') {
        return returnError("Missing DATA", fp);                               
    }
    
    fread(&dataSize, sizeof(INT32), 1, fp);                                  
    
    //Display the info about the WAVE file
    cout << "Chunk Size: "       << chunkSize  << "\n";
    cout << "Format Type: "      << formatType << "\n";
    cout << "Channels: "         << channels   << "\n";
    cout << "Sample Rate: "      << sampleRate << "\n";
    cout << "Average Bytes Per Second: "  << avgBytesPerSec << "\n";
    cout << "Bytes Per Sample: " << bytesPerSample << "\n";
    cout << "Bits Per Sample: "  << bitsPerSample  << "\n";
    cout << "Data Size: "        << dataSize       << "\n";
        
    BYTE* buf = new BYTE[dataSize];  //Allocate memory for the sound data
    //Should be the same as the Data Size if OK
    cout << fread(buf, sizeof(BYTE), dataSize, fp) << " bytes loaded\n";         
                
    fclose(fp); 
    
    data = buf;
    
    return 0;
}

Format Wav::getFormat() {
    Format result = UNKNOWN;                                                      
    
    //Figure out the format of the WAVE file
    if(bitsPerSample == 8) {
        if(channels == 1) {
            result = BPS_8_MONO;
        } 
        else if(channels == 2) {
            result = BPS_8_STEREO;
        }
    }
    else if(bitsPerSample == 16) {
        if(channels == 1) {
            result = BPS_16_MONO;
        }
        else if(channels == 2) {
            result = BPS_16_MONO;
        }
    }
    
    return result;
}