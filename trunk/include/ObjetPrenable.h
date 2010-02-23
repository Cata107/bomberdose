#ifndef ObjetPrenable_h
#define ObjetPrenable_h

#include "ObjetFixe.h"


class ObjetPrenable : public ObjetFixe {

 public:

    virtual bool MCreation()  = 0;

    virtual bool MObjetPris();
};

#endif // ObjetPrenable_h
