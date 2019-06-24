#ifndef UIREM_FormaSpiskaSprModelH
#define UIREM_FormaSpiskaSprModelH
#include "IMainInterface.h"
#include "IREM_DMSprModel.h"
#include "IREM_DMSprGrpModel.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprModel)) IREM_FormaSpiskaSprModel : public IMainInterface
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

   __property IREM_DMSprModel* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModel* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModel* DM)=0;

   __property IREM_DMSprGrpModel * DMGrp = {read = get_DMGrp , write = set_DMGrp};
   virtual IREM_DMSprGrpModel * get_DMGrp(void)=0;
   virtual void set_DMGrp(IREM_DMSprGrpModel * DMGrp)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdModel = {read = get_IdModel , write = set_IdModel};
   virtual __int64 get_IdModel(void)=0;
   virtual void set_IdModel(__int64 IdModel)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaSpiskaSprModel __uuidof(IREM_FormaSpiskaSprModel)
#endif
