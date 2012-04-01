/* 
 * File:   SoundHelper.cpp
 * Author: robert
 * 
 * Created on March 31, 2012, 7:45 PM
 */

#include "SoundHelper.h"
#include "Texture/TextureManager.h"
#include <stdio.h>
#include <string>




SoundHelper::SoundHelper() {                                                       
    device = alcOpenDevice(NULL);                                             
    if (device) {                        
        context = alcCreateContext(device, NULL);                                  
        alcMakeContextCurrent(context);                      
    }
}

SoundHelper::~SoundHelper() {
    if (wavFile != NULL) {
        delete wavFile;
    }
    
    alDeleteSources(1, &source);                                                //Delete the OpenAL Source
    alDeleteBuffers(1, &buffer);                                                 //Delete the OpenAL Buffer
    alcMakeContextCurrent(NULL);                                                //Make no context current
    alcDestroyContext(context);                                                 //Destroy the OpenAL Context
    alcCloseDevice(device);
}

void SoundHelper::loadWav(string filename) {
    if (device) {
        wavFile = new Wav(filename);
        wavFile->load();
        
        ALenum format = 0;                                                            //The audio format (bits per sample, number of channels)

        alGenBuffers(1, &buffer);                                                    //Generate one OpenAL Buffer and link to "buffer"
        alGenSources(1, &source);  

        switch(wavFile->getFormat()) {
            case BPS_8_MONO:    format = AL_FORMAT_MONO8;    break;
            case BPS_16_MONO:   format = AL_FORMAT_MONO16;   break;
            case BPS_8_STEREO:  format = AL_FORMAT_STEREO8;  break;
            case BPS_16_STEREO: format = AL_FORMAT_STEREO16; break;
        }
        
        if (format) {           
            alBufferData(buffer, format, 
                        wavFile->getData(), 
                        wavFile->getDataSize(), 
                        wavFile->getSampleRate()
                        );                   

            //Sound setting variables
            ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };                                    //Position of the source sound
            ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };                                    //Velocity of the source sound
            ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };                                  //Position of the listener
            ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };                                  //Velocity of the listener
            ALfloat ListenerOri[] = { 0.0, 0.0, -1.0 };                 //Orientation of the listener
                                                                                        //First direction vector, then vector pointing up) 
            //Listener                                                                               
            alListenerfv(AL_POSITION,    ListenerPos);                                  //Set position of the listener
            alListenerfv(AL_VELOCITY,    ListenerVel);                                  //Set velocity of the listener
            alListenerfv(AL_ORIENTATION, ListenerOri);                                  //Set orientation of the listener

            //Source
            alSourcei (source, AL_BUFFER,   buffer);                                 //Link the buffer to the source
            alSourcef (source, AL_PITCH,    1.0f     );                                 //Set the pitch of the source
            alSourcef (source, AL_GAIN,     1.0f     );                                 //Set the gain of the source
            alSourcefv(source, AL_POSITION, SourcePos);                                 //Set the position of the source
            alSourcefv(source, AL_VELOCITY, SourceVel); 
        }
    }
}

void SoundHelper::play() {
    alSourcei(source, AL_LOOPING,  AL_FALSE);                                 //Set if source is looping sound
    
    //PLAY 
    alSourcePlay(source);                                                       //Play the sound buffer linked to the source
}


