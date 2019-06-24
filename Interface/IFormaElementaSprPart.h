#ifndef UIFormaElementaSprPartH
#define UIFormaElementaSprPartH
#include "IMainInterface.h"
#include "IDMSprPart.h"
class __declspec(uuid("{0EBE970E-DADB-4602-B463-DBF225BFDD7A}"))IFormaElementaSprPart : public IMainInterface
{
public:
   __property IDMSprPart * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPart * get_DM(void)=0;
   virtual void set_DM(IDMSprPart * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprPart __uuidof(IFormaElementaSprPart)
#endif
