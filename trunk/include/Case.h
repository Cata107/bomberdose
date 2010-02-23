#ifndef Case_h
#define Case_h

class Plateau;
class ObjetFixe;

class Case {

 public:

    virtual bool MCreation();

    virtual bool MIsEmpty();

    virtual bool MFill();

 public:
    bool m_vide;

 protected:
    struct m_coordonees
    {
        int x;
        int y;
    }

 public:

    Plateau *myPlateau;

    ObjetFixe *myObjetFixe;
};

#endif // Case_h
