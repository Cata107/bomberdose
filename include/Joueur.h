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
		
				bool					MPoserBombe();	//Methode appellee quand le joueur veut poser une bombe.

				bool					MIsDead();		//Retourne true si le joueur est mort

				bool					MMoveUp();		//Bouger en haut

				bool					MMoveDown();	//Bouger en bas

				bool					MMoveLeft();	//Bouger à gauche

				bool					MMoveRight();	//Bouger à droite	
				
				bool					MDie();	//Faire mourrir le joueur si il se fait toucher par une bombe

				bool					MReborn(const sf::Vector2i _coordonnees);	//Recreer le joueur apres une partie

				bool					MAugmenterScore();	//Augmente le score quand le joueur a gagne

	unsigned	int						MGetScore();	//Retourne le score du joueur

				bool					MSetPlateau(Plateau* _plateau);

				const Plateau*			MGetPlateau() const;	//Retourne le plateau

				const sf::Vector2i		MGetPositionPixel() const;	//Retourne les coordonnees pixel

				const sf::Vector2i		MGetPositionCase() const;	//Retourne les coordonnes de la case ou se situe le joueur

				const sf::Vector2i		MConvertirPixelEnCase()const;	//Converti la position pixel en position Case

				bool					MRamasserObjet(ObjetPrenable* _objet);	//Methode appellee quand le joueur ramasse un objet

				bool					MAjusterVitesse();	//Ajuster la vitesse si on prend un BonusRoller ou un malus de vitesse

				bool					MAjusterPositionCase();	//Ajuster la position de la case à chaque déplacement

				bool					MSetPosition(const sf::Vector2i& _coordonnees);	//Replacer le joueur a une position
	
				bool					MAugmenterNombreBombe();	//Permet d'incrementer le nombre de bombe maximum

				bool					MAugmenterPuissance();		//Permet d'augmenter la puissance de la bombe

				bool					MAugmenterVitesse();		//Permet d'augmenter la vitesse du joueur

				bool					MDiminuerNbBombesPosees();	//Decrementer le nombre de bombe posee quand une bombe explose

		std::vector<ObjetPrenable*>&	MGetListBonus();			//Retourne la liste de bonus recolte par le joueur. Ils sont eparpilles sur le terrain quand le joueur meurt
			
				int						MGetIndice();


 protected:
		int				m_indice;				//Indice du joueur
		int				m_score;				//Le score du joueur
		bool			m_mort;					//Savoir si le joueur est mort
		int				m_nbBombes;				//Nombre de bombe maximum que le joueur peut poser
		int				m_puissance;			//Puissance de ses bombes
		int				m_coefficientVitesse;	//Coefficient de vitesse, incrementer quand le joueur ramasse un BonusRoller
		float			m_vitesse;				//Vitesse du joueur apres calcul
		int				m_nbBombesPosees;		//Nombre de bombe pose par le joueur
		int				m_tmp;					//Conserve l'entier pour pouvoir le reattribuer quand une maladie disparait
		
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
		std::vector<ObjetPrenable*>		m_listBonus;			//La liste de bonus ramasse par le joueur
		sf::Vector2i					m_coordonneesPixel;		//Les coordonnees pixel du joueur		
		sf::Vector2i					m_coordonneesCase;		//La case sur laquelle se trouve le joueur
		Plateau*						m_plateau;				//Un pointeur vers le plateau, partage par tous les joueurs

};

#endif // Joueur_h
