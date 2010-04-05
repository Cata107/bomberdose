#include "Anim.h"

    Anim::Anim(){
    }

    Anim::~Anim(){
    }

    // Ajoute un sprite
    void Anim::PushFrame(const sf::IntRect& NewRect){
        mySubRect.push_back(NewRect);
    }

    const size_t Anim::Size(){
        return mySubRect.size();
    }

    sf::IntRect& Anim::operator [] (size_t N) {
        return mySubRect[N];
    }
