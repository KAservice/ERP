#ifndef UIFormaElementaSprCodeTelH
#define UIFormaElementaSprCodeTelH
#include "IMainInterface.h"
#include "IDMSprCodeTel.h"
class __declspec(uuid("{DC49A659-4E8E-4DF4-86FF-9E25045F0CF6}")) IFormaElementaSprCodeTel : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprCodeTel * DM = {read = get_DM , write = set_DM};
   virtual IDMSprCodeTel * get_DM(void)=0;
   virtual void set_DM(IDMSprCodeTel * DM)=0;

};
#define IID_IFormaElementaSprCodeTel __uuidof(IFormaElementaSprCodeTel)
#endif
