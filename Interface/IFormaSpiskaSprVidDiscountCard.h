#ifndef UIFormaSpiskaSprVidDiscountCardH
#define UIFormaSpiskaSprVidDiscountCardH
#include "IMainInterface.h"
#include "IDMSprVidDiscountCard.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprVidDiscountCard))IFormaSpiskaSprVidDiscountCard : public IMainInterface
{
public:
   __property IDMSprVidDiscountCard * DM = {read = get_DM , write = set_DM};
   virtual IDMSprVidDiscountCard * get_DM(void)=0;
   virtual void set_DM(IDMSprVidDiscountCard * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprVidDiscountCard __uuidof(IFormaSpiskaSprVidDiscountCard)
#endif
