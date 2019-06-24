//---------------------------------------------------------------------------

#ifndef UArmKas1CFH
#define UArmKas1CFH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TArmKas1CF : public IkanClassFactory
{
public:
   TArmKas1CF();
   ~TArmKas1CF();

   int NumRefs;


	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);
   	virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};

#endif
