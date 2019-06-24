//---------------------------------------------------------------------------

#ifndef UFormaRunExternalModuleCFH
#define UFormaRunExternalModuleCFH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TFormaRunExternalModuleCF : public IkanClassFactory
{
public:
   TFormaRunExternalModuleCF();
   ~TFormaRunExternalModuleCF();

   int NumRefs;


	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);
   	virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};
#endif
