#ifndef UIFormaElementaSprDiscountCardH
#define UIFormaElementaSprDiscountCardH
#include "IMainInterface.h"
#include "IDMSprDiscountCard.h"
class __declspec(uuid("{A95440E0-E67C-415C-97AA-8A0DB52412C0}")) IFormaElementaSprDiscountCard : public IMainInterface
{
public:
   __property IDMSprDiscountCard * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDiscountCard * get_DM(void)=0;
   virtual void set_DM(IDMSprDiscountCard * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprDiscountCard __uuidof(IFormaElementaSprDiscountCard)
#endif
