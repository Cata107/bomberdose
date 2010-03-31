#ifndef Plateau_h
#define Plateau_h

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "Case.h"
#include "MurCassableAvecObjetPrenable.h"
#include "MurIncassable.h"
#include "Timer.h"
#include "Macro.h"
#include "Bombe.h"
#include "Flamme.h"
#include "BonusBombe.h"
#include "BonusFlamme.h"
#include "BonusRoller.h"
#include "ObjetMalus.h"
class Joueur;

class Plateau {

 public:

 /*	Constructeur */	Plateau(std::vector<MurCassableAvecObjetPrenable*>& _listeMurCassableAvecObjetPrenable, int _nbBonus);

 /* Destructeur */ 	~Plateau();

			bool	MPlacerMursIncassables();	//Placer les murs incassables

			bool	MPlacerMursIncassablesBord();	//Au bord de l'écran

			bool	MPlacerMursIncassablesMilieu();	//Au milieu

			bool	MPlacerMursCassables();			//Placement des murs cassables. Ils sont places aleatoirement sur les cases vides

			Case*	MGetCase(const sf::Vector2i _coordonnees);				//Renvoi un poiteur sur la case, dont les coordonnees sont en parametre

			Case*	MGetCase(const int _coordonneeUniDimensionelle);		//Renvoi un pointeur sur la case

			Case*	MGetPlateau();	//Retourne le plateau

			char*	MGetPlateauConverti();	//Retourne le plateau converti

			Timer*	MGetTimer();			//Retourne le Timer du plateau

			bool	MSetBombe(sf::Vector2i _coordonnees, int _puissance, int indiceJoueur, int _maladie = 0);	//Permet de placer une bombe sur les coordonnees de la case en parametre

			bool	MSetJoueurs(std::vector< Joueur* >& _listJoueur);	//Placer les joueurs

			bool	MCreerFlamme(sf::Vector2i& _coordonnees, int _puissance);	//Creer des flammes quand une bombe explose

			bool	MCreerFlammeHaut(sf::Vector2i& _coordonnees, int _puissance);	//Creer les flammes du haut de l'origine l'explosion

			bool	MCreerFlammeBas(sf::Vector2i& _coordonnees, int _puissance);	//Creer les flammes en bas de l'origine de l'explosion

			bool	MCreerFlammeGauche(sf::Vector2i& _coordonnees, int _puissance);	//Creer les flammes a gauche de lorigine de l'explosion

			bool	MCreerFlammeDroite(sf::Vector2i& _coordonnees, int _puissance);	//Creer les flammes a droite de lorigine de l'explosion

			bool	MDestructionObjetFixe(ObjetFixe* _objetFixe);					//Destruction de l'objet si est sur le chemin d'une flamme

			bool	MUpdate();	//Met a jour le plateau

			bool	MPlacerObjetBonusApresMort(std::vector<ObjetPrenable*>& _listObjet);	//Quand un joueur meurt, les objets qu'il a ramasse sont eparpilles sur le plateau, sur des cases vides


 protected:

			Case*					m_tCase;	//Le tableau est représente par un tableau de Case

			Timer*					m_pTimer;	//Le timer du plateau. Si le temps est ecoule, la partie se termine sur une egalite

			std::list<Bombe*>		m_listPBombes;			//La liste de bombes posees par les joueurs

			std::list<Flamme*>		m_listPFlammes;			//Liste des cases enflammee

			std::vector<MurCassable*>	m_listPMursCassables;	//La liste des murs cassables pour la construction du plateau

			std::set<int>			m_setIndiceCaseVide;	//L'ensemble des cases vides

			std::vector<Joueur*>	m_listJoueurs;			//La liste des joueurs
};

#endif // Plateau_h
