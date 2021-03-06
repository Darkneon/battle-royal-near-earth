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

SoundHelper *SoundHelper::instance = NULL;    
ALCcontext *SoundHelper::context;
ALCdevice *SoundHelper::device;
ALuint SoundHelper::source[3];                                                           
map<string, ALuint*> SoundHelper::buffers;
string SoundHelper::path;
Wav *SoundHelper::wavFile;

SoundHelper::SoundHelper(string path) {
    this->path = path;
    
    device = alcOpenDevice(NULL);                                             
    if (device) {                        
        context = alcCreateContext(device, NULL);                                  
        alcMakeContextCurrent(context);  
        alGenSources(3, source);  

    }
}

SoundHelper::~SoundHelper() {
    if (wavFile != NULL) {
        delete wavFile;
    }
    
    alDeleteSources(3, source);                                                
    //alDeleteBuffers(1, &buffer);                                                
    alcMakeContextCurrent(NULL);                                                
    alcDestroyContext(context);
    alcCloseDevice(device);
}

SoundHelper* SoundHelper::getInstance(){
	if(instance == NULL){
		instance = new SoundHelper(TextureManager::getInstance()->getResourcePath() + "music/");
	}
	return instance;
}

ALuint* SoundHelper::loadWav(string filename, int sourceNumber) {
    if (device) {
        ALuint* buffer = new ALuint;
        
        wavFile = new Wav(path + filename);
        wavFile->load();
        
        if (wavFile->getDataSize() == 0) {
            return NULL;
        }
        
        ALenum format = 0;                                                            //The audio format (bits per sample, number of channels)

        alGenBuffers(1, buffer);                                                    //Generate one OpenAL Buffer and link to "buffer"

        switch(wavFile->getFormat()) {
            case BPS_8_MONO:    format = AL_FORMAT_MONO8;    break;
            case BPS_16_MONO:   format = AL_FORMAT_MONO16;   break;
            case BPS_8_STEREO:  format = AL_FORMAT_STEREO8;  break;
            case BPS_16_STEREO: format = AL_FORMAT_STEREO16; break;
        }
        
        if (format) {           
            alBufferData(*buffer, format, 
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
            alSourcef (source[sourceNumber], AL_PITCH,    1.0f     );                                 //Set the pitch of the source
            alSourcef (source[sourceNumber], AL_GAIN,     1.0f     );                                 //Set the gain of the source
            alSourcefv(source[sourceNumber], AL_POSITION, SourcePos);                                 //Set the position of the source
            alSourcefv(source[sourceNumber], AL_VELOCITY, SourceVel); 
        }
        
        //TO DO: Fix memory leak
        //delete[] wavFile->getData();
        delete wavFile;
        wavFile = NULL;
    
        return buffer;
    }
    
    return NULL;
 
}

void SoundHelper::play(string fileName, int sourceNumber, bool isLoop) {
    
    bool containsFilename = (buffers.end() != buffers.find(fileName));
    if (!containsFilename) {
        ALuint *buffer = loadWav(fileName, sourceNumber);
        if (buffer != NULL) {
            buffers.insert(bufferPair(fileName, buffer));
        }
    }
        
    ALint state; 
    alGetSourcei(source[sourceNumber], AL_SOURCE_STATE, &state); 
    if (state == AL_PLAYING) {
        alSourceStop(source[sourceNumber]);
    }
            
    if (buffers[fileName] != NULL) {
        alSourcei(source[sourceNumber], AL_BUFFER, *buffers[fileName]); 
        
        if (isLoop) {
            alSourcei(source[sourceNumber], AL_LOOPING, AL_TRUE);                                 //Set if source is looping sound    
        }
        else {
            alSourcei(source[sourceNumber], AL_LOOPING, AL_FALSE);                                 //Set if source is looping sound
        }
        
        //PLAY 
        alSourcePlay(source[sourceNumber]);            
    }
}

void SoundHelper::play(string filename, bool isLoop) {
    play(filename, 0, isLoop);
}


