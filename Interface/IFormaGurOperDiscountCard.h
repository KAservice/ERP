#ifndef UIFormaGurOperDiscountCardH
#define UIFormaGurOperDiscountCardH
#include "IMainInterface.h"
#include "IDMGurOperDiscountCard.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaGurOperDiscountCard)) IFormaGurOperDiscountCard : public IMainInterface
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

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaGurOperDiscountCard __uuidof(IFormaGurOperDiscountCard)
#endif
