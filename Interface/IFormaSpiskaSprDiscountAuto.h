#ifndef UIFormaSpiskaSprDiscountAutoH
#define UIFormaSpiskaSprDiscountAutoH
#include "IMainInterface.h"
#include "IDMSprDiscountAuto.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprDiscountAuto)) IFormaSpiskaSprDiscountAuto : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprDiscountAuto * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDiscountAuto * get_DM(void)=0;
   virtual void set_DM(IDMSprDiscountAuto * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprDiscountAuto __uuidof(IFormaSpiskaSprDiscountAuto)
#endif
