//---------------------------------------------------------------------------

#ifndef U1COnLineFRCFH
#define U1COnLineFRCFH
//---------------------------------------------------------------------------

#include "GlobalInterface.h"
//---------------------------------------------------------------
class T1COnLineFRCF : public IkanClassFactory
{
public:
   T1COnLineFRCF();
   ~T1COnLineFRCF();
   int NumRefs;
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	  virtual int kanAddRef(void);
	  virtual int kanRelease(void);
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};
//---------------------------------------------------------------


#endif
