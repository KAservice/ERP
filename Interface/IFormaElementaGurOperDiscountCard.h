#ifndef UIFormaElementaGurOperDiscountCardH
#define UIFormaElementaGurOperDiscountCardH
#include "IMainInterface.h"
#include "IDMGurOperDiscountCard.h"
class __declspec(uuid("{8366406D-5BD4-417D-991E-6E1308648F1D}")) IFormaElementaGurOperDiscountCard : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMGurOperDiscountCard * DM = {read = get_DM , write = set_DM};
   virtual IDMGurOperDiscountCard * get_DM(void)=0;
   virtual void set_DM(IDMGurOperDiscountCard * DM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaGurOperDiscountCard __uuidof(IFormaElementaGurOperDiscountCard)
#endif
