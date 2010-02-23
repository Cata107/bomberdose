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
    null m_coordonee;

 public:

    Plateau *myPlateau;

    ObjetFixe *myObjetFixe;
};

#endif // Case_h
