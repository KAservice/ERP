//---------------------------------------------------------------------------

#ifndef U1COnLineFRCOMCFH
#define U1COnLineFRCOMCFH
//---------------------------------------------------------------------------

#include "GlobalInterface.h"
//---------------------------------------------------------------
class T1COnLineFRCOMCF : public IkanClassFactory
{
public:
   T1COnLineFRCOMCF();
   ~T1COnLineFRCOMCF();
   int NumRefs;
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	  virtual int kanAddRef(void);
	  virtual int kanRelease(void);
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};
//---------------------------------------------------------------


#endif
