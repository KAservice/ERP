#ifndef UIREM_FormaSpiskaSprNeisprH
#define UIREM_FormaSpiskaSprNeisprH
#include "IMainInterface.h"
#include "IREM_DMSprNeispr.h"
#include "IREM_DMSprGrpNeispr.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprNeispr)) IREM_FormaSpiskaSprNeispr : public IMainInterface
{
public:
   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   __property IREM_DMSprNeispr* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprNeispr* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprNeispr* DM)=0;

   __property IREM_DMSprGrpNeispr * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprGrpNeispr * get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprGrpNeispr * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdNeispr = {read = get_IdNeispr , write = set_IdNeispr};
   virtual __int64 get_IdNeispr(void)=0;
   virtual void set_IdNeispr(__int64 IdNeispr)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprNeispr __uuidof(IREM_FormaSpiskaSprNeispr)
#endif
