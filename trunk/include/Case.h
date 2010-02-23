#ifndef Case_h
#define Case_h

class Plateau;
class ObjetFixe;

class Case {

 public:

    virtual bool MCreation();

    virtual bool MIsEmpty();

    virtual bool MFill();


 protected:
    struct m_coordonees
    {
        int x;
        int y;
    };

	bool m_vide;
	ObjetFixe *myObjetFixe;
};

#endif // Case_h
