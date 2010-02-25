#include "Case.h"



//Creer une case
bool Case::MCreation()
{
    return false;
}

//Retourne true si la case est vide, c'est-a-dire qu'il ne possede aucun objet
bool Case::MIsEmpty()
{
    return myObjetFixe==NULL ;
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
    if (myObjetFixe->MIsMurCassable())
    {
        return CASE_AVECMURCASSABLE;
    }
    if (myObjetFixe->MIsMurIncassable())
    {
        return CASE_AVECMURINCASSABLE;
    }
    if (myObjetFixe->MIsBonusFlamme())
    {
        return CASE_AVECBONUS_FLAMME;
    }
    if (myObjetFixe->MIsBonusBombe())
    {
        return CASE_AVECBONUS_BOMBE;
    }
    if (myObjetFixe->MIsBonusRoller())
    {
        return CASE_AVECBONUS_ROLLER;
    }
    //reste à définir les autres cases, avec bonus, etc
}
