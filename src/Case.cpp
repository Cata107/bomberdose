#include "Case.h"



//Creer une case
bool Case::MCreation()
{
    return false;
}

//Retourne true si la case est vide, c'est-a-dire qu'il ne possede aucun objet
bool Case::MIsEmpty()
{
    return false;
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