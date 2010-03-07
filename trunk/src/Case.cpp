#include "Case.h"
#include "Macro.h"

//Constructeur par defaut. Est appele lors de la creation du tableau de Case dans le Plateau
Case::Case() : m_vide(true), m_pObjetFixe(NULL)
{
	
}

//Fixer la position d'une case en ayant l'indice en parametre
bool Case::MSetPosition(int _indiceCase)
{
	m_coordonnees.x = _indiceCase % NB_COLONNES;
	m_coordonnees.y = _indiceCase / NB_COLONNES;
	return true;
}

//Fixer la position d'une case avec des coordonnees en parametre
bool Case::MSetPosition(sf::Vector2i _coordonnees)
{
	m_coordonnees.x = _coordonnees.x;
	m_coordonnees.y = _coordonnees.y;
	return true;
}

//Creer une case
bool Case::MCreation()
{
    return false;
}

//Retourne true si la case est vide, c'est-a-dire qu'il ne possede aucun objet
bool Case::MIsEmpty()
{
    return m_pObjetFixe==NULL ;
}

//Permet de mettre la variable m_vide a vrai si un objet est creer sur la Case
bool Case::MFill(const ObjetFixe& _objetFixe)
{
	*m_pObjetFixe = _objetFixe;
	m_vide = false;
    return true;
}

sf::Vector2i Case::MGetPosition()
{
	return m_coordonnees;
}

//Vider la case
bool Case::MClean()
{
	m_vide = true;
	return true;
}
//Converti une case en int en hexadécimal, utile pour communiquer le plateau par les sockets
int Case::MConvertToInt()
{
    if (Case::MIsEmpty())
    {
        return CASE_VIDE;
    }

    if (m_pObjetFixe->MIsMurCassable())
    {
        return CASE_AVECMURCASSABLE;
    }

    if (m_pObjetFixe->MIsMurIncassable())
    {
        return CASE_AVECMURINCASSABLE;
    }
	
	if (m_pObjetFixe->MIsMalus())
	{
		return CASE_AVECMALUS;
	}
	
    if (m_pObjetFixe->MIsBonusFlamme())
    {
        return CASE_AVECBONUS_FLAMME;
    }

    if (m_pObjetFixe->MIsBonusBombe())
    {
        return CASE_AVECBONUS_BOMBE;
    }

    if (m_pObjetFixe->MIsBonusRoller())
    {
        return CASE_AVECBONUS_ROLLER;
    }
    //reste à définir les autres cases, avec bonus, etc
}
