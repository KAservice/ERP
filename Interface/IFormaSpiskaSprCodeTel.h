#ifndef UIFormaSpiskaSprCodeTelH
#define UIFormaSpiskaSprCodeTelH
#include "IMainInterface.h"
#include "IDMSprCodeTel.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprCodeTel)) IFormaSpiskaSprCodeTel : public IMainInterface
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
#define IID_IFormaSpiskaSprCodeTel __uuidof(IFormaSpiskaSprCodeTel)
#endif
