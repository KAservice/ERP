#ifndef UIFormaSpiskaSprDiscountCardH
#define UIFormaSpiskaSprDiscountCardH
#include "IMainInterface.h"
#include "IDMSprDiscountCard.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprDiscountCard)) IFormaSpiskaSprDiscountCard : public IMainInterface
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

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property AnsiString NameKlient = {read = get_NameKlient , write = set_NameKlient};
   virtual AnsiString get_NameKlient(void)=0;
   virtual void set_NameKlient(AnsiString NameKlient)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprDiscountCard __uuidof(IFormaSpiskaSprDiscountCard)
#endif
