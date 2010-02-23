#ifndef ObjetFixe_h
#define ObjetFixe_h

class Case;

class ObjetFixe {

 public:

    virtual bool MCreation()  = 0;

    virtual bool MDestruction()  = 0;

 public:

    Case ** myCase;
};

#endif // ObjetFixe_h
