#ifndef UIREM_FormaSpiskaSprModelDetalH
#define UIREM_FormaSpiskaSprModelDetalH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModelDetal.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprModelDetal)) IREM_FormaSpiskaSprModelDetal : public IMainInterface
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

   __property IREM_DMSprModelDetal * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModelDetal * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModelDetal * DM)=0;

   __property __int64 IdModel = {read = get_IdModel , write = set_IdModel};
   virtual __int64 get_IdModel(void)=0;
   virtual void set_IdModel(__int64 IdModel)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprModelDetal __uuidof(IREM_FormaSpiskaSprModelDetal)
#endif
