#ifndef UIREM_FormaSpiskaSprKomplModelH
#define UIREM_FormaSpiskaSprKomplModelH
#include "IMainInterface.h"
#include "IREM_DMSprKomplModel.h"
class __declspec(uuid("{1AF7643E-1DDD-4907-9D78-711202E90AAF}"))IREM_FormaSpiskaSprKomplModel : public IMainInterface
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

   __property IREM_DMSprKomplModel * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprKomplModel * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprKomplModel * DM)=0;

   __property __int64 IdModel = {read = get_IdModel , write = set_IdModel};
   virtual __int64 get_IdModel(void)=0;
   virtual void set_IdModel(__int64 IdModel)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprKomplModel __uuidof(IREM_FormaSpiskaSprKomplModel)
#endif
