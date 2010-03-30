#ifndef Joueur_h
#define Joueur_h

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <vector>
#include "Plateau.h"
#include "Macro.h"
#include "ObjetPrenable.h"

class Joueur {

 public:


	/* Constructeur */	Joueur(int _indice, sf::Vector2i _coordonnees, Plateau* _plateau);
		
		virtual	bool					MPoserBombe();	//Methode appellee quand le joueur veut poser une bombe.

		virtual bool					MIsDead();		//retourne true si le joueur est mort

		virtual bool					MUpdate();

		virtual bool					MJouer();

				bool					MMoveUp();

				bool					MMoveDown();

				bool					MMoveLeft();

				bool					MMoveRight();
				
				bool					MDie();

				bool					MReborn(const sf::Vector2i _coordonnees);

				bool					MAugmenterScore();

	unsigned	int						MGetScore();

				bool					MSetPlateau(Plateau* _plateau);

		virtual const Plateau*			MGetPlateau() const;	//retourne le plateau

		virtual const sf::Vector2i		MGetPositionPixel() const;	//retourne les coordonnees pixel

		virtual const sf::Vector2i		MGetPositionCase() const;	//retourne les coordonnes de la case ou se situe le joueur

		virtual const sf::Vector2i		MConvertirPixelEnCase()const;	//Converti la position pixel en position Case

		virtual	bool					MRamasserObjet(ObjetPrenable* _objet);	//Methode appellee quand le joueur ramasse un objet

				bool					MAjusterVitesse();

		virtual bool					MSetPosition(const sf::Vector2i& _coordonnees);	
	
		virtual bool					MAugmenterNombreBombe();	//Permet d'incrementer le nombre de bombe maximum

		virtual bool					MAugmenterPuissance();		//Permet d'augmenter la puissance de la bombe

		virtual bool					MAugmenterVitesse();		//Permet d'augmenter la vitesse du joueur

		bool							MDiminuerNbBombesPosees();	//Decrementer le nombre de bombe posee quand une bombe explose

		std::vector<ObjetPrenable*>&		MGetListBonus();			//Retourne la liste de bonus recolte par le joueur. Ils sont eparpilles sur le terrain quand le joueur meurt
		


 protected:
		int				m_indice;				//Indice du joueur
		int				m_score;
		bool			m_mort;					//Savoir si le joueur est mort
		int				m_nbBombes;				//Nombre de bombe maximum que le joueur peut poser
		int				m_puissance;			//Puissance de ses bombes
		int				m_coefficientVitesse;	//Coefficient de vitesse, incrementer quand le joueur ramasse un BonusRoller
		float			m_vitesse;				//Vitesse du joueur apres calcul
		int				m_nbBombesPosees;
		int				m_tmp;	//Conserve l'entier pour pouvoir le reattribuer quand une maladie disparait
		enum Maladie
		{
			aucune,
			rapidite,
			lenteur,
			flamme1,
			pasDeBombe,
			explosionRapide,
			explosionLente,
			toucheInversee,
			toujoursBouger,
			toujoursPoserBombe
		};
		Maladie							m_maladie;				//Le type de la maladie
		std::vector<ObjetPrenable*>		m_listBonus;			//la liste de bonus
		sf::Vector2i					m_coordonneesPixel;		
		sf::Vector2i					m_coordonneesCase;
		Plateau*						m_plateau;

};

#endif // Joueur_h
