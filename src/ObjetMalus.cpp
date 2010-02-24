#include "ObjetMalus.h"

//Si un ObjetMalus est touche par une flamme, l'ObjetMalus change de place, sur une Case vide
bool ObjetMalus::MDestruction()
{
    return false;
}

//Si un ObjetMalus est ramasse par un joueur, on applique un des effets choisi aleatoirement dans la totalite des malus
bool ObjetMalus::MAppliquerEffet(Joueur _joueur)
{
    return false;
}
