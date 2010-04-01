#ifndef ANIM_H
#define ANIM_H

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Anim {

    public:
    Anim();
    virtual ~Anim();
    // Ajoute un sprite
    void PushFrame(const sf::IntRect& NewSprite);
    const size_t Size();
    sf:: IntRect& operator [] (size_t N);

    private:

    std::vector<sf::IntRect> mySubRect;

};

#endif
