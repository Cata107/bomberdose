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
int Case::MConvertToInt()
//Converti une case en int en hexadécimal, utile pour communiquer le plateau par les sockets
{
    if (Case::MIsEmpty())
    {
        return CASE_VIDE;
    }
    if (myObjetFixe->MIsMurDestructible())
    {
        return CASE_AVECMURINCASSABLE;
    }
    if (myObjetFixe->MIsMurIndestructible())
    {
        return CASE_AVECMURCASSABLE;
    }
    //reste à définir les autres cases, avec bonus, etc
}
