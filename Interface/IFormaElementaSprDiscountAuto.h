#ifndef UIFormaElementaSprDiscountAutoH
#define UIFormaElementaSprDiscountAutoH
#include "IMainInterface.h"
#include "IDMSprDiscountAuto.h"
class __declspec(uuid("{60DF4435-F2E5-494D-AA17-211703C81866}")) IFormaElementaSprDiscountAuto : public IMainInterface
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
#define IID_IFormaElementaSprDiscountAuto __uuidof(IFormaElementaSprDiscountAuto)
#endif
