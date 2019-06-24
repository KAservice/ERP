//---------------------------------------------------------------------------

#ifndef UFibConnectionCFH
#define UFibConnectionCFH
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TFibConnectionCF : public IkanClassFactory
{
public:
   TFibConnectionCF();
   ~TFibConnectionCF();

   virtual bool kanQueryInterface(int id_interface,void**ppv);
   virtual bool kanCreateInstance(int id_class, int id_interface, void ** ppv);
};

#endif
