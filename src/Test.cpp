#include <iostream>
#include <vector>
#include "Plateau.h"
#include "MurCassableAvecObjetPrenable.h"
#include "Macro.h"
#include "BomberDose.h"

int main()
{
/*------------------------------------------Test Bomberdose--------------------------------------------------*/

	//Creation d'un plateau via bomberdose, et test de MRecreer Plateau
	/*

	BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);

	Plateau* plateau = bomberdose->MGetPlateau();
	for (int i = 0; i < NB_CASE; i++)
	{
		if (plateau->MGetCase(i)->MIsEmpty())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis vide." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurIncassable())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur incassable." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurAvecObjet())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur cassable avec objet." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurCassable())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur cassable." << std::endl;
		}
	}

	getchar();
	bomberdose->MRecreerPlateau();
	plateau = bomberdose->MGetPlateau();

	for (int i = 0; i < NB_CASE; i++)
	{
		if (plateau->MGetCase(i)->MIsEmpty())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis vide." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurIncassable())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur incassable." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurAvecObjet())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur cassable avec objet." << std::endl;
		}
		else if (plateau->MGetCase(i)->MGetObjetFixe()->MIsMurCassable())
		{
			std::cout << "Je suis la case (" <<  plateau->MGetCase(i)->MGetPosition().y << ", " << plateau->MGetCase(i)->MGetPosition().x << ") et je suis un mur cassable." << std::endl;
		}
	}

	std::cout << "Il reste " << bomberdose->MFinMatch() << "joueur(s)" << std::endl;
	bomberdose->MGetJoueur(3)->MDie();
	std::cout << "Il reste " << bomberdose->MFinMatch() << "joueur(s)" << std::endl;
	bomberdose->MRecreerPlateau();
	std::cout << "Il reste " << bomberdose->MFinMatch() << "joueur(s)" << std::endl;
	bomberdose->MGetJoueur(3)->MDie();
	bomberdose->MGetJoueur(2)->MDie();
	bomberdose->MGetJoueur(1)->MDie();
	std::cout << "Il reste " << bomberdose->MFinMatch() << "joueur(s)" << std::endl;
	std::cout << "Le gagnant est le joueur numero " << bomberdose->MGetGagnant()->MGetIndice() << "." << std::endl;
	getchar();

	delete bomberdose;
	*/

/*-------------------------------------------Test du Plateau--------------------------------------------*/

	//Test du timer
	/*
	BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);

	Plateau* plateau = bomberdose->MGetPlateau();
	while(true)
	{
		std::cout << "Timer du plateau : " << plateau->MGetTimer()->MGetTime() << std::endl;
		getchar();
	}
	delete bomberdose;
	*/

	//Test de update
	/*
	BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);

	Plateau* plateau = bomberdose->MGetPlateau();
	bomberdose->MGetJoueur(0)->MPoserBombe();
	bomberdose->MGetJoueur(1)->MPoserBombe();
	while (true)
	{
		plateau->MUpdate();
	}
	*/

	
	BomberDose* bomberdose = new BomberDose(4, 5, 5, 5, 3, 5, 5);

	Plateau* plateau = bomberdose->MGetPlateau();
	
	for (int i = 0; i < NB_CASE; i++)
	{
		if (plateau->MGetCase(i)->MIsEmpty())
		{
			plateau->MSetBombe(plateau->MGetCase(i)->MGetPosition(),3, 1, 0);
		}

	}
	
	plateau->MSetBombe(sf::Vector2i(1, 1),3, 1, 0);
	plateau->MSetBombe(sf::Vector2i(1, 2),3, 1, 0);
	while(true)
	{
		//bomberdose->MGetJoueur(0)->MMoveRight();
		//sf::Sleep(0.5);
		plateau->MUpdate();
	} 





}

