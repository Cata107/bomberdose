#include "Case.h"
#include "Macro.h"



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
bool Case::MFill()
{
	m_vide = false;
    return true;
}

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
