//---------------------------------------------------------------------------

#ifndef UFormaPriemPlatCFH
#define UFormaPriemPlatCFH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TFormaPriemPlatCF : public IkanClassFactory
{
public:
   TFormaPriemPlatCF();
   ~TFormaPriemPlatCF();

   int NumRefs;


	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);
   	virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};

#endif
