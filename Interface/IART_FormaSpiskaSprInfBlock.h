#ifndef UIART_FormaSpiskaSprInfBlockH
#define UIART_FormaSpiskaSprInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IART_DMSprInfBlock.h"
#include "IART_DMSprInfBlockGrp.h"
class __declspec(uuid(Global_IID_IART_FormaSpiskaSprInfBlock)) IART_FormaSpiskaSprInfBlock : public IMainInterface
{
public:
   __property IART_DMSprInfBlock* DM = {read = get_DM , write = set_DM};
   virtual IART_DMSprInfBlock* get_DM(void)=0;
   virtual void set_DM(IART_DMSprInfBlock* DM)=0;

   __property IART_DMSprInfBlockGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IART_DMSprInfBlockGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IART_DMSprInfBlockGrp * DMGrp)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrpElement = {read = get_IdGrpElement , write = set_IdGrpElement};
   virtual __int64 get_IdGrpElement(void)=0;
   virtual void set_IdGrpElement(__int64 IdGrpElement)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IART_FormaSpiskaSprInfBlock __uuidof(IART_FormaSpiskaSprInfBlock)
#endif
