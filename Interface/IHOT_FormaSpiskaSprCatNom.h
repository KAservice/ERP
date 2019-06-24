#ifndef UIHOT_FormaSpiskaSprCatNomH
#define UIHOT_FormaSpiskaSprCatNomH
#include "IMainInterface.h"
#include "IHOT_DMSprCatNom.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IHOT_FormaSpiskaSprCatNom)) IHOT_FormaSpiskaSprCatNom : public IMainInterface
{
public:
   __property IHOT_DMSprCatNom * DM = {read = get_DM , write = set_DM};
   virtual IHOT_DMSprCatNom * get_DM(void)=0;
   virtual void set_DM(IHOT_DMSprCatNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IHOT_FormaSpiskaSprCatNom __uuidof(IHOT_FormaSpiskaSprCatNom)
#endif
