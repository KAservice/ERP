#ifndef UIHOT_FormaSpiskaSprCelPriesdaH
#define UIHOT_FormaSpiskaSprCelPriesdaH
#include "IMainInterface.h"
#include "IHOT_DMSprCelPriesda.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_FormaSpiskaSprCelPriesda)) IHOT_FormaSpiskaSprCelPriesda : public IMainInterface
{
public:
   __property IHOT_DMSprCelPriesda * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprCelPriesda * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprCelPriesda * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHOT_FormaSpiskaSprCelPriesda __uuidof(IHOT_FormaSpiskaSprCelPriesda)
#endif
