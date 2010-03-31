#include "Case.h"
#include "Macro.h"

//Constructeur par defaut. Est appele lors de la creation du tableau de Case dans le Plateau
Case::Case() : m_vide(true), m_pObjetFixe(NULL)
{

}

Case::~Case()
{

}

bool Case::operator==(const Case& _case)
{
	if (m_coordonnees == _case.m_coordonnees)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Case::MSetPosition(int _indiceCase)
{
	m_coordonnees.x = _indiceCase % NB_COLONNES;
	m_coordonnees.y = _indiceCase / NB_COLONNES;
	return true;
}

bool Case::MSetPosition(sf::Vector2i _coordonnees)
{
	m_coordonnees.x = _coordonnees.x;
	m_coordonnees.y = _coordonnees.y;
	return true;
}


bool Case::MIsEmpty()
{
    return m_vide ;
}


bool Case::MFill(const ObjetFixe& _objetFixe)
{
	m_pObjetFixe = _objetFixe.MClone();	//On remplit la case avec l'objet
	m_vide = false;
    return true;
}

sf::Vector2i Case::MGetPosition()
{
	return m_coordonnees;
}

bool Case::MClean()
{
	m_vide = true;
	return true;
}

ObjetFixe* Case::MGetObjetFixe() const
{
	return m_pObjetFixe;
}

//Converti une case en int en hexadécimal, utile pour communiquer le plateau par les sockets
char Case::MConvertToChar()
{
    if (Case::MIsEmpty())
    {
        return CASE_VIDE;
    }

    if (m_pObjetFixe->MIsMurCassable() || m_pObjetFixe->MIsMurAvecObjet())
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
    if ( m_pObjetFixe->MIsBombe())
    {
        return CASE_AVECBOMBE;
    }
    if ( m_pObjetFixe->MIsFlamme())
    {
        return CASE_ENFLAMMEE;
    }
}
