#ifndef UIREM_FormaSpiskaSprKKTH
#define UIREM_FormaSpiskaSprKKTH
#include "IMainInterface.h"
#include "IREM_DMSprKKT.h"
#include "IREM_DMSprGrpKKT.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprKKT)) IREM_FormaSpiskaSprKKT : public IMainInterface
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

   __property IREM_DMSprKKT* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprKKT* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprKKT* DM)=0;

   __property IREM_DMSprGrpKKT * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprGrpKKT * get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprGrpKKT * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool Podbor = {read = get_Podbor , write = set_Podbor};
   virtual bool get_Podbor(void)=0;
   virtual void set_Podbor(bool Podbor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprKKT __uuidof(IREM_FormaSpiskaSprKKT)
#endif
