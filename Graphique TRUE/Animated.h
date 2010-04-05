#ifndef ANIMATED_H
#define ANIMATED_H

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Anim.h"

class Animated : public sf::Sprite {

    public:
    Animated(float Time);
    virtual ~Animated();
    void SetAnim(Anim* NewAnim);
    Anim* GetAnim();
    void SetRect(int Rect);
    int GetCurrentRect();
    void SetFrameTime(float Time);
    float GetFrameTime();
    void anim(float ElapsedTime);

    bool isPaused();
    void stop();
    bool isStoped();


    private:
    float myTime;
    float myElapsedTime;
    Anim* myAnim;
    int myCurrentRect;
    bool paused;



};

#endif
