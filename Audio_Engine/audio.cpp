#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define PATH_BGM "Assets/Tetris.wav"
#define PATH_SE_CLEAR "Assets/ClearSound.wav"
#define PATH_SE_FALL "Assets/FallTetris.wav"

class Audio {
protected: 
    Mix_Music *audioMusic;
    Mix_Chunk *audioChunk;
    bool runningStatus = false;
    int volume = 50;
public:
    void load(Mix_Music*);       // Overloading - to load different types of audio
    void load(Mix_Chunk*);       // Overloading - to load different types of audio
    void play();
    void stop();
    void setStatus(bool);
    bool getStatus();
};

void Audio::load(Mix_Music *audio) {
    audioMusic = audio;
    Mix_VolumeMusic(volume);    // Set the volume with default value
}

void Audio::load(Mix_Chunk *audio) {
    audioChunk = audio;
}

void Audio::play() {
    if(!Mix_PlayingMusic()){
        Mix_PlayMusic(audioMusic,-1);   // Put -1 so that it runs in a loop
    }
    if(Mix_PlayingMusic()){
        Mix_ResumeMusic();
    }
}

void Audio::stop() {
    Mix_HaltMusic();
}

void Audio::setStatus(bool status){
    runningStatus = status;
}

bool Audio::getStatus(){
    return runningStatus;
}