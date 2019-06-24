//---------------------------------------------------------------------------

#ifndef UArmKas2CFH
#define UArmKas2CFH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TArmKas2CF : public IkanClassFactory
{
public:
   TArmKas2CF();
   ~TArmKas2CF();

   int NumRefs;


	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);
   	virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};

#endif
