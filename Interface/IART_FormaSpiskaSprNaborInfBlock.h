#ifndef UIART_FormaSpiskaSprNaborInfBlockH
#define UIART_FormaSpiskaSprNaborInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IART_DMSprNaborInfBlock.h"
#include "IART_DMSprNaborInfBlockGrp.h"
class __declspec(uuid(Global_IID_IART_FormaSpiskaSprNaborInfBlock)) IART_FormaSpiskaSprNaborInfBlock : public IMainInterface
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

   __property IART_DMSprNaborInfBlock* DM = {read = get_DM , write = set_DM};
   virtual IART_DMSprNaborInfBlock* get_DM(void)=0;
   virtual void set_DM(IART_DMSprNaborInfBlock* DM)=0;

   __property IART_DMSprNaborInfBlockGrp * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IART_DMSprNaborInfBlockGrp * get_DMGrp(void)=0;
   virtual void set_DMGrp(IART_DMSprNaborInfBlockGrp * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IART_FormaSpiskaSprNaborInfBlock __uuidof(IART_FormaSpiskaSprNaborInfBlock)
#endif
