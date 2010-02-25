#ifndef Case_h
#define Case_h

class Case {

 public:

    virtual bool MCreation();

    virtual bool MIsEmpty();

    virtual bool MFill();

    int MConvertToInt();

	virtual bool MClean();

	int MConvertToInt();



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
