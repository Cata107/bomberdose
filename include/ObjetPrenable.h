#ifndef ObjetPrenable_h
#define ObjetPrenable_h

#include "ObjetFixe.h"


class ObjetPrenable : public ObjetFixe {

 public:

    virtual bool MCreation();

    virtual bool MObjetPris();

	virtual bool MDestruction()  = 0;

	virtual bool MAppliquerEffetObjet()  = 0;
};

#endif // ObjetPrenable_h
