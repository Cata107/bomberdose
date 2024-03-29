#include "Animated.h"

    Animated::Animated(float time){
        myTime=time;
        myElapsedTime=time;
        myCurrentRect=0;
        myAnim = NULL;
        paused= false;

    }

    Animated::~Animated(){
    }

    void Animated::SetAnim(Anim* NewAnim){
        myAnim=NewAnim;
    }

    Anim* Animated::GetAnim(){
        return myAnim;
    }

    void Animated::SetRect(int Rect){
         if (myAnim->Size() > 0)
        {
            SetSubRect((*myAnim)[Rect]);
            myCurrentRect = Rect;
        }
    }

    int Animated::GetCurrentRect(){
        return myCurrentRect;
    }

    void Animated::SetFrameTime(float Time){
        myTime=Time;
    }

    float Animated::GetFrameTime(){
        return myTime;
    }

    bool Animated::isPaused(){
        return paused;
    }
    void Animated::stop(){
        SetRect(0);
        myElapsedTime=myTime;
    }
    bool Animated::isStoped(){
        return (myElapsedTime==myTime) && (myCurrentRect==0);
    }
    void Animated::anim(float ElapsedTime){

        std::cout<<paused;
        if(!paused){

            myElapsedTime-=ElapsedTime;
            if(myElapsedTime<=0.f){
                std::cout<<"DANS ELAPSED : "<<myElapsedTime<<std::endl;
                std::cout<<"TIME : "<<myTime<<std::endl;
                myElapsedTime=myTime;
                if(myCurrentRect + 1 < myAnim->Size()+1){
                    std::cout<<"ICIIIIIIIIIIIIIIIIII"<<std::endl;
                    myCurrentRect+1;

                }
                else {
                    myCurrentRect=0;
                }
                SetRect(myCurrentRect);

            }
        }
    }



