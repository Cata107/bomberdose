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
		
		virtual	bool				MPoserBombe();

		virtual bool				MIsDead();

		virtual bool				MUpdate();

		virtual bool				MJouer();

		virtual const Plateau*		MGetPlateau() const;

		virtual const sf::Vector2i	MGetPositionPixel() const;

		virtual const sf::Vector2i	MGetPositionCase() const;

		virtual const sf::Vector2i	MConvertirPixelEnCase()const;

		virtual	bool				MRamasserObjet(ObjetPrenable& _objet);

		virtual bool				MSetPosition(const sf::Vector2i& _coordonnees);
	
		virtual bool				MAugmenterNombreBombe();

		virtual bool				MAugmenterPuissance();

		virtual bool				MAugmenterVitesse();

		


 protected:
		int				m_indice;
		int				m_score;
		bool			m_mort;
		int				m_nbBombes;
		int				m_puissance;
		int				m_coefficientVitesse;
		float			m_vitesse;
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
		Maladie							m_maladie;
		std::vector<ObjetPrenable*>		m_listBonus;
		sf::Vector2i					m_coordonneesPixel;
		sf::Vector2i					m_coordonneesCase;
		Plateau*						m_plateau;

};

#endif // Joueur_h
