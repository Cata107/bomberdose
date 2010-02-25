#include "Plateau.h"



//Creer le Plateau
bool Plateau::MCreation(MurCassableAvecObjetPrenable _listeMurCassableAvecObjetPrenable)
{
    return false;
}

//Destruction du Plateau
bool Plateau::MDestruction()
{
    return false;
}

//Place une bombe a la case aux coordonnees passees en parametre
bool Plateau::MSetBombe(sf::Vector2i coordonnees)
{
    return false;
}

//Place les MursIncassables, qui sont fixes
bool Plateau::MPlacerMursIncassables()
{
    return false;
}

//Place les MursCassables, aleatoirement, sauf sur certaines Cases interdites
bool Plateau::MPlacerMursCassables(MurCassableAvecObjetPrenable _listMurCassableAvecObjetPrenable)
{
    return false;
}

//Retourne une case du plateau, selon les coordonnees donnees en parametre
Case Plateau::MGetCase(sf::Vector2i _coordonnees)
{
    int accesColonne = _coordonnees.x;
    int accesLigne = _coordonnees.y * NB_COLONNES;
    int coordUniDimensionnelle = accesColonne + accesLigne;

    return m_Case[ coordUniDimensionnelle ];
}

//Retourne le Plateau
Case Plateau::MGetPlateau()

{
	return *m_Case;
}
