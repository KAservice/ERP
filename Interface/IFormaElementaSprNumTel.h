#ifndef UIFormaElementaSprNumTelH
#define UIFormaElementaSprNumTelH
#include "IMainInterface.h"
#include "IDMSprNumTel.h"
class __declspec(uuid("{D8DF48A5-F018-4949-A2A4-B0924277A19F}"))IFormaElementaSprNumTel : public IMainInterface
{
public:
   __property IDMSprNumTel * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNumTel * get_DM(void)=0;
   virtual void set_DM(IDMSprNumTel * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprNumTel __uuidof(IFormaElementaSprNumTel)
#endif
