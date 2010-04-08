#ifndef Bombe_h
#define Bombe_h
#include "ObjetFixe.h"

class Bombe : public ObjetFixe {

 public:

	/* Constructeur */				Bombe(const sf::Vector2i _coordonnees,int puissance, int _indiceJoueur, int _maladie);

	/* Destructeur */ virtual		~Bombe();

		virtual ObjetFixe*			MClone() const;		//Permet de cloner une bombe

				//bool				Bombe::operator==(const Bombe &_bombe);

				int					MGetPuissance();	//Retourne la puissance du joueur lorsqu'il a pose la bombe

				int					MGetIndice();		//Retourne l'indice du joueur qui a pose la bombe

				int					MGetMaladie();		//Retourne la maladie que le joueur possedait quand il a pose la bombe

 protected:

		int							m_puissance;	//La puissance de la bombe

		int							m_indiceJoueur;	//Indice du joueur qui a pose la bombe

		int							m_maladie;		//Maladie influencant les bombes. Vaut 1 si explosion rapide, vaut 2 si explosion lente
};

#endif // Bombe_h
