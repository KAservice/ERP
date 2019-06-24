#ifndef UIFormaSpiskaSprDiscountCard_1H
#define UIFormaSpiskaSprDiscountCard_1H
#include "IMainInterface.h"
#include "IDMSprDiscountCard_1.h"
#include "IDMSprGrpKlient.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprDiscountCard1)) IFormaSpiskaSprDiscountCard_1 : public IMainInterface
{
public:
   __property IDMSprDiscountCard_1* DM = {read = get_DM , write = set_DM};
   virtual IDMSprDiscountCard_1* get_DM(void)=0;
   virtual void set_DM(IDMSprDiscountCard_1* DM)=0;

   __property IDMSprGrpKlient * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IDMSprGrpKlient * get_DMGrp(void)=0;
   virtual void set_DMGrp(IDMSprGrpKlient * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrpKlient = {read = get_IdGrpKlient , write = set_IdGrpKlient};
   virtual __int64 get_IdGrpKlient(void)=0;
   virtual void set_IdGrpKlient(__int64 IdGrpKlient)=0;

   __property __int64 IdDiscountCard = {read = get_IdDiscountCard , write = set_IdDiscountCard};
   virtual __int64 get_IdDiscountCard(void)=0;
   virtual void set_IdDiscountCard(__int64 IdDiscountCard)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprDiscountCard_1 __uuidof(IFormaSpiskaSprDiscountCard_1)
#endif
