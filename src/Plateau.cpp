#include "Plateau.h"
#include "Joueur.h"

Plateau::Plateau(std::vector<MurCassableAvecObjetPrenable*>& _listeMurCassableAvecObjetPrenable, int _nbBonus)
{
	m_tCase = new Case[NB_CASE];			//On alloue dynamiquement la memoire pour toutes les cases

	for (int i = 0; i < NB_CASE; i++)		//On remplit le plateau de Case
	{
		m_tCase[i].MSetPosition(i);
		m_setIndiceCaseVide.insert(i);
	}

	//On met dans la list des murs cassables, les murs avec objet ramener en parametre
	for (std::vector<MurCassableAvecObjetPrenable*>::iterator it = _listeMurCassableAvecObjetPrenable.begin(); it != _listeMurCassableAvecObjetPrenable.end(); it++)
	{
		m_listPMursCassables.push_back(*it);
	}

	//On remplit la liste de mur cassable de nouveaux murs
	for (int i = 0; i < NB_MURSCASSABLES-_nbBonus; i++)
	{
		m_listPMursCassables.push_back(new MurCassable());
	}

	//On place les murs incassables
	MPlacerMursIncassables();

	//On place les murs cassables
	MPlacerMursCassables();
	m_pTimer = new Timer();
}

Plateau::~Plateau()
{

	delete [] m_tCase;	//On detruit chaque case
	delete m_pTimer;	//On detruit le timer
	/*
	while (!m_listPBombes.empty())	//On detruit toutes les bombes
	{
		delete m_listPBombes.back();
		m_listPBombes.pop_back();
	}
	*/

	while (!m_listPMursCassables.empty())	// On detruit tous les murs
	{
		delete m_listPMursCassables.back();
		m_listPMursCassables.pop_back();
	}

}


//Place les MursIncassables, qui sont fixes
bool Plateau::MPlacerMursIncassables()
{
	MPlacerMursIncassablesBord();
	MPlacerMursIncassablesMilieu();
    return true;
}

//Place les murs incassables ds bords
bool Plateau::MPlacerMursIncassablesBord()
{
	//On remplit d'abord le bord haut
	for (int i = 0; i < NB_COLONNES; i++)
	{
		m_tCase[i].MFill(MurIncassable(m_tCase[i].MGetPosition()));
		m_setIndiceCaseVide.erase(i);	//On efface la case de la liste des cases vide
	}
	//Puis on remplit le bord gauche et droit
	for (int j = NB_COLONNES; j < (NB_LIGNES-1)*NB_COLONNES; j += NB_COLONNES) //On parcourt chaque ligne, et on met sur la 1ere et la derniere colonne
	{
		m_tCase[j].MFill(MurIncassable(m_tCase[j].MGetPosition()));
		m_setIndiceCaseVide.erase(j);	//On efface la case de la liste des cases vide
		m_tCase[j + NB_COLONNES - 1 ].MFill(MurIncassable(m_tCase[j + NB_COLONNES - 1].MGetPosition()));
		m_setIndiceCaseVide.erase(j + NB_COLONNES - 1);	//On efface la case de la liste des cases vide
	}
	//Enfin, on remplit le bord bas
	for (int k = (NB_LIGNES-1)*NB_COLONNES; k < NB_CASE; k++)
	{
		m_tCase[k].MFill(MurIncassable(m_tCase[k].MGetPosition()));
		m_setIndiceCaseVide.erase(k);
	}

	return true;
}

//Place les murs incassables au milieu
bool Plateau::MPlacerMursIncassablesMilieu()
{
	for (int i = 2; i < NB_COLONNES-1; i += 2)
	{
		for (int j = 2; j <NB_LIGNES-1; j += 2)
		{
			int indice = (j*NB_COLONNES) + i;
			m_tCase[indice].MFill(MurIncassable(m_tCase[indice].MGetPosition()));
			m_setIndiceCaseVide.erase(indice);
		}
	}
	return true;
}

//Place les MursCassables, aleatoirement, sauf sur certaines Cases interdites
bool Plateau::MPlacerMursCassables()
{
	//On met dans des variables les cases interdites pour accelerer les verifications

	static const int tableau[12] =
	{
		POSITION_JOUEUR1,
		CASE_INTERDITE1,
		CASE_INTERDITE2,
		POSITION_JOUEUR2,
		CASE_INTERDITE3,
		CASE_INTERDITE4,
		CASE_INTERDITE5,
		CASE_INTERDITE6,
		POSITION_JOUEUR3,
		CASE_INTERDITE7,
		CASE_INTERDITE8,
		POSITION_JOUEUR4
	};

	int i = 0;
	int random;
	while(i < NB_MURSCASSABLES)
	{
		random = sf::Randomizer::Random(POSITION_JOUEUR1, POSITION_JOUEUR4);	//On genere un nombre pseudo aleatoire
		if (!std::binary_search(tableau, tableau+12, random) && ((m_setIndiceCaseVide.find(random)) != m_setIndiceCaseVide.end()))			//Si il n'est pas interdit
		{

			m_listPMursCassables[i]->MSetCoordonnees(((m_tCase[*m_setIndiceCaseVide.find(random)]).MGetPosition()));	//On fixe les coordonnees du mur avec la position de la case
			m_tCase[*m_setIndiceCaseVide.find(random)].MFill(*m_listPMursCassables[i]);							//Et on rempli la Case du MurCassable
			m_setIndiceCaseVide.erase(random);		//On efface la case du tableau des cases vides.
			i++;
		}
	}
    return true;
}

//Retourne une case du plateau, selon les coordonnees donnees en parametre
Case* Plateau::MGetCase(const sf::Vector2i _coordonnees)
{
    int accesColonne = _coordonnees.x;
    int accesLigne = _coordonnees.y * NB_COLONNES;
    int coordUniDimensionnelle = accesColonne + accesLigne;

    return &(m_tCase[ coordUniDimensionnelle ]);
}

Case* Plateau::MGetCase(const int _coordonneeUniDimensionnelle)
{
    return &(m_tCase[ _coordonneeUniDimensionnelle ]);
}


Case* Plateau::MGetPlateau()

{
	return &*m_tCase;
}

char* Plateau::MGetPlateauConverti()
{
    char* tableau = new char[NB_LIGNES*NB_COLONNES];
    for (int i = 0; i < NB_LIGNES*NB_COLONNES; i++)
    {
        tableau[i] = Plateau::MGetCase(i)->MConvertToChar();
    }
    return tableau;
}

Timer* Plateau::MGetTimer()
{
	return m_pTimer;
}

//Place une bombe a la case aux coordonnees passees en parametre
bool Plateau::MSetBombe(sf::Vector2i _coordonnees, int _puissance, int _indiceJoueur, int _maladie)
{
	m_listPBombes.push_back(new Bombe(_coordonnees, _puissance, _indiceJoueur, _maladie));	//On ajoute la bombe dans la liste des bombes
	MGetCase(_coordonnees)->MFill(*(m_listPBombes.back()));		//On remplit la case d'une bombe
	m_setIndiceCaseVide.erase(_coordonnees.x+(_coordonnees.y * NB_COLONNES));	//On efface l'indice de la case ou est la bombe de l'ensemble des indices de case vide
	return true;
}

bool Plateau::MSetJoueurs(std::vector< Joueur* >& _listJoueur)
{
	m_listJoueurs = _listJoueur;
	return true;
}

bool Plateau::MCreerFlamme(const sf::Vector2i&  _coordonnees, int _puissance)
{
	m_listPFlammes.push_back(new Flamme(_coordonnees));	//Rempli la liste de flamme avec une nouvelle bombe
	MGetCase(_coordonnees)->MFill(*(m_listPFlammes.back()));	//On remplit la case avec la flamme
	MCreerFlammeHaut(_coordonnees, _puissance);					//On cree les flammes en haut
	MCreerFlammeBas(_coordonnees, _puissance);					//On cree les flammes en bas
	MCreerFlammeGauche(_coordonnees, _puissance);				//On cree les flammes a gauche
	MCreerFlammeDroite(_coordonnees, _puissance);				//On cree les flamme a droite
	return true;
}

bool Plateau::MCreerFlammeHaut(const sf::Vector2i& _coordonnees, int _puissance)
{
	int i = _puissance;	//Compteur
	int y = _coordonnees.y;	//Coordonnees y
	while (i > 0 && MGetCase(sf::Vector2i(_coordonnees.x, (y -1)))->MIsEmpty())	//On verifie si la case du dessus est vide ou si i != 0
	{
		sf::Vector2i coordonnees(_coordonnees.x, (y -1));
		m_listPFlammes.push_back(new Flamme(coordonnees));	//On cree une nouvelle flamme dans la case au dessus
		MGetCase(coordonnees)->MFill(*(m_listPFlammes.back()));	//On remplit la case avec la flamme cree
		m_setIndiceCaseVide.erase(coordonnees.x + (coordonnees.y * NB_COLONNES));	//On enleve la case de l'ensemble des indices des cases vides
		y--;
		i--;
		//On recommence jusqu'a que i == 0 ou que la case au dessus n'est pas vide
	}
	if (i > 0 && !(MGetCase(sf::Vector2i(_coordonnees.x, (y -1)))->MIsEmpty()))	//Si la flamme n'a pas atteint la portee maximum
	{
		sf::Vector2i coordonnees(_coordonnees.x, (y-1));
		MDestructionObjetFixe(MGetCase(coordonnees)->MGetObjetFixe());	//On detruit l'objet sur le chemin
	}

	return true;
}

//Analogie avec MCreerFlammehaut en remplacant (y-1) par (y+1)
bool Plateau::MCreerFlammeBas(const sf::Vector2i& _coordonnees, int _puissance)
{
	int i = _puissance;
	int y = _coordonnees.y;
	while (i > 0 && MGetCase(sf::Vector2i(_coordonnees.x, (y +1)))->MIsEmpty())
	{
		sf::Vector2i coordonnees(_coordonnees.x, (y +1));
		m_listPFlammes.push_back(new Flamme(coordonnees));
		MGetCase(coordonnees)->MFill(*(m_listPFlammes.back()));
		m_setIndiceCaseVide.erase(coordonnees.x + (coordonnees.y * NB_COLONNES));
		y++;
		i--;
	}
	if (i > 0 && !(MGetCase(sf::Vector2i(_coordonnees.x, (y +1)))->MIsEmpty()))
	{
		sf::Vector2i coordonnees(_coordonnees.x, (y+1));
		MDestructionObjetFixe(MGetCase(coordonnees)->MGetObjetFixe());
	}

	return true;
}
//Analogie avec MCreerFlammeHaut avec la coordonnees x
bool Plateau::MCreerFlammeGauche(const sf::Vector2i& _coordonnees, int _puissance)
{
	int i = _puissance;
	int x = _coordonnees.x;
	while (i > 0 && MGetCase(sf::Vector2i( (x-1), _coordonnees.y))->MIsEmpty())
	{
		sf::Vector2i coordonnees((x-1), _coordonnees.y);
		m_listPFlammes.push_back(new Flamme(coordonnees));
		MGetCase(coordonnees)->MFill(*(m_listPFlammes.back()));
		m_setIndiceCaseVide.erase(coordonnees.x + (coordonnees.y * NB_COLONNES));
		x--;
		i--;
	}
	if (i > 0 && !(MGetCase(sf::Vector2i((x-1), _coordonnees.y))->MIsEmpty()))
	{
		sf::Vector2i coordonnees((x-1), _coordonnees.y);
		MDestructionObjetFixe(MGetCase(coordonnees)->MGetObjetFixe());
	}

	return true;
}
//Analogie avec MCreerFlammeGauche en remplacant (x-1) par (x+1)
bool Plateau::MCreerFlammeDroite(const sf::Vector2i& _coordonnees, int _puissance)
{
	int i = _puissance;
	int x = _coordonnees.x;
	while (i > 0 && MGetCase(sf::Vector2i( (x+1), _coordonnees.y))->MIsEmpty())
	{
		sf::Vector2i coordonnees((x+1), _coordonnees.y);
		m_listPFlammes.push_back(new Flamme(coordonnees));
		MGetCase(coordonnees)->MFill(*(m_listPFlammes.back()));
		m_setIndiceCaseVide.erase(coordonnees.x + (coordonnees.y * NB_COLONNES));
		x++;
		i--;
	}
	if (i > 0 && !(MGetCase(sf::Vector2i((x+1), _coordonnees.y))->MIsEmpty()))
	{
		sf::Vector2i coordonnees((x+1), _coordonnees.y);
		MDestructionObjetFixe(MGetCase(coordonnees)->MGetObjetFixe());
	}

	return true;
}

bool Plateau::MDestructionObjetFixe(ObjetFixe* _objetFixe)
{
	if(!_objetFixe->MIsMurIncassable() && !_objetFixe->MIsFlamme())
	{
		if(_objetFixe->MIsMurCassable() || _objetFixe->MIsBonusBombe() || _objetFixe->MIsBonusFlamme() || _objetFixe->MIsBonusRoller())	//Si l'objet n'a rien de particulier lors de la destruction
		{
			MGetCase(_objetFixe->MGetCoordonnees())->MClean();		//On vide la case
			m_setIndiceCaseVide.insert(_objetFixe->MGetCoordonnees().x + ((_objetFixe->MGetCoordonnees().y)* NB_COLONNES ));	//On met l'indice de la case maintenant vide dans l'ensemble des indices des cases vides
			std::cout << "Je suis un mur a la position (" << _objetFixe->MGetCoordonnees().y << ", " << _objetFixe->MGetCoordonnees().x << ") et je suis detruit." << std::endl;
			delete _objetFixe;
		}

		else if(_objetFixe->MIsMurAvecObjet())	//Si il y a un objet dans le mur cassable
		{
			 switch((dynamic_cast<MurCassableAvecObjetPrenable*>(_objetFixe))->m_objetContenu)	//On verifie l'objet contenu
			 {
				case 1:		//Cas d'un bonus bombe
					MGetCase(_objetFixe->MGetCoordonnees())->MClean();
					MGetCase(_objetFixe->MGetCoordonnees())->MFill(BonusBombe(_objetFixe->MGetCoordonnees()));
					break;
				case 2:		//Cas d'un Bonus Flamme
					MGetCase(_objetFixe->MGetCoordonnees())->MClean();
					MGetCase(_objetFixe->MGetCoordonnees())->MFill(BonusFlamme(_objetFixe->MGetCoordonnees()));
					break;
				case 3:		//Cas d'un Bonus Roller
					MGetCase(_objetFixe->MGetCoordonnees())->MClean();
					MGetCase(_objetFixe->MGetCoordonnees())->MFill(BonusRoller(_objetFixe->MGetCoordonnees()));
					break;
				case 0:		//Cas d'un malus
					MGetCase(_objetFixe->MGetCoordonnees())->MClean();
					MGetCase(_objetFixe->MGetCoordonnees())->MFill(ObjetMalus(_objetFixe->MGetCoordonnees()));
					break;
			 }
			 std::cout << "Je suis un mur avec objet a la position (" << _objetFixe->MGetCoordonnees().y << ", " << _objetFixe->MGetCoordonnees().x << ") et je suis detruit." << std::endl;
		}

		else if (_objetFixe->MIsMalus())	//Si on detruit un malus, il se teleporte sur une case vide
		{
			std::set<int>::iterator it = m_setIndiceCaseVide.end();
			int random;
			while (it == m_setIndiceCaseVide.end())
			{
				random = sf::Randomizer::Random(POSITION_JOUEUR1, POSITION_JOUEUR4);	//On prend une case du plateau
				it = m_setIndiceCaseVide.find(random);
			}
			MGetCase(_objetFixe->MGetCoordonnees())->MClean();
			m_setIndiceCaseVide.insert(_objetFixe->MGetCoordonnees().x + (_objetFixe->MGetCoordonnees().y * NB_COLONNES));
			MGetCase(*it)->MFill(ObjetMalus(_objetFixe->MGetCoordonnees()));
			delete _objetFixe;
		}

		else if (_objetFixe->MIsBombe())	//Si c'est une bombe, elle explose
		{
			MGetCase(_objetFixe->MGetCoordonnees())->MClean();
			MCreerFlamme( _objetFixe->MGetCoordonnees(), dynamic_cast<Bombe*>(_objetFixe)->MGetPuissance());
			m_listJoueurs[(dynamic_cast<Bombe*>(_objetFixe)->MGetIndice())-1]->MDiminuerNbBombesPosees();
			std::cout << "Je suis une bombe a la position (" << _objetFixe->MGetCoordonnees().y << ", " << _objetFixe->MGetCoordonnees().x << ") et je suis detruit par une autre bombe." << std::endl;
			delete _objetFixe;
		}
	}
	return true;
}

bool Plateau::MUpdate()
{
	//On verifie le timer de toutes les bombes
	if (!m_listPBombes.empty())
	{
		for (std::list<Bombe*>::iterator it = m_listPBombes.begin(); it != m_listPBombes.end();)
		{

			if ((((*it)->MGetMaladie() == 0) && ((*it)->MGetTimer()->MGetTime() > TEMPS_BOMBE_DEFAUT)) ||	//Si aucune maladie affectant les bombes et temps supérieur au temps par defaut d'une bombe
				(((*it)->MGetMaladie() == 1) && ((*it)->MGetTimer()->MGetTime() > TEMPS_BOMBE_RAPIDE)) ||	//Ou si maladie de la bombe qui explose vite et depassement du temps fixe pour cette maladie
				(((*it)->MGetMaladie() == 2) && ((*it)->MGetTimer()->MGetTime() > TEMPS_BOMBE_LENTE)))		//Ou si maladie de la bombe qui explose lentement et depassement du temps fixe pour cette maladie
			{
				MGetCase((*it)->MGetCoordonnees())->MClean();	//On efface la bombe de la case
				std::cout << "Je suis une bombe initiale a la position (" << (*it)->MGetCoordonnees().y << ", " << (*it)->MGetCoordonnees().x << ") et je suis detruit." << std::endl;
				m_listJoueurs[((*it)->MGetIndice())-1]->MDiminuerNbBombesPosees();			//Diminue le nombre de bombe posee par le joueur
                std::cout << "Flamme cree" << std::endl;
				MCreerFlamme((*it)->MGetCoordonnees(), (*it)->MGetPuissance());				//Les flammes se creent sur les cases adjacentes selon la puissance de la bombe


				delete *it;					//On supprime la bombe en question de la memoire
				it = m_listPBombes.erase(it);	//On supprime la bombe de la liste
			}
			else
			{
				it++;
			}
		}
	}

	//On verifie le timer de toutes les flammes
	if (!m_listPFlammes.empty())
	{
		for (std::list<Flamme*>::iterator it = m_listPFlammes.begin(); it != m_listPFlammes.end();)
		{
			if ((*it)->MGetTimer()->MGetTime() > TEMPS_FLAMME)	//Si le temps de la flamme est ecoule
			{
				m_setIndiceCaseVide.insert((*it)->MGetCoordonnees().x * ((*it)->MGetCoordonnees().y * NB_COLONNES) );	//On rajoute l'indice de la case ou la flamme a disparu dans l'ensemble des indices des cases vides
				MGetCase((*it)->MGetCoordonnees())->MClean();	//On detruit la flamme
				delete *it;										//On efface la flamme de la memoire
				it = m_listPFlammes.erase(it);						//On supprime la flamme du tableau

			}
			else
			{
				it++;	//On incrémente l'iterateur pour passer au prochain element sinon
			}
		}
	}

	//On regarde si les joueurs ne sont pas sur une case avec un objet
	for (std::vector<Joueur*>::iterator it = m_listJoueurs.begin(); it != m_listJoueurs.end(); it++)
	{
		if (!(*it)->MIsDead())	//Si le joueur est mort, on ne verifie pas
		{
			if (!(MGetCase((*it)->MGetPositionCase())->MIsEmpty()))	//On verifie si la case n'est pas vide, sinan, il ne se passe rien
			{
				if (!MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()->MIsMurCassable() && !MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()->MIsMurAvecObjet() && !MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()->MIsMurIncassable())
				{
					if (MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()->MIsFlamme())	//Si le joueur est sur une case enflammee
					{
						(*it)->MDie();	//Il meurt
						MPlacerObjetBonusApresMort((*it)->MGetListBonus());
					}

					else if (!(MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()->MIsBombe()))	//On verifie que le joueur n'est pas sur une bombe, car ce n'est pas un objet prenable
					{
						(*it)->MRamasserObjet(dynamic_cast<ObjetPrenable*>(MGetCase((*it)->MGetPositionCase())->MGetObjetFixe()));	//Le joueur ramasse l'objet et on applique l'effet
						m_setIndiceCaseVide.insert((*it)->MGetPositionCase().x + ((*it)->MGetPositionCase().y)*NB_COLONNES);			//On met l'indice ou etait l'objet dans l'ensemble des indices des cases vides
					}
				}
			}
		}
	}


		return true;
}

bool Plateau::MPlacerObjetBonusApresMort(std::vector<ObjetPrenable*>& _listObjet)
{
	int random;

	while(!(_listObjet.empty()))	//On parcours la liste des objets que le joueur avait ramasse
	{
		random = sf::Randomizer::Random(POSITION_JOUEUR1, POSITION_JOUEUR4);
		if (m_setIndiceCaseVide.find(random) != m_setIndiceCaseVide.end())
		{
			MGetCase(random)->MFill(*(_listObjet.back()));
			_listObjet.pop_back();
			m_setIndiceCaseVide.erase(random);
		}
	}
	return true;
}
