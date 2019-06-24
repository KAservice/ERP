#ifndef UIHLP_FormaSpiskaSprPageElementH
#define UIHLP_FormaSpiskaSprPageElementH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprPageElement.h"
class __declspec(uuid(Global_IID_IHLP_FormaSpiskaSprPageElement)) IHLP_FormaSpiskaSprPageElement : public IMainInterface
{
public:
   __property IHLP_DMSprPageElement * DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprPageElement * get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprPageElement * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdPage = {read = get_IdPage , write = set_IdPage};
   virtual __int64 get_IdPage(void)=0;
   virtual void set_IdPage(__int64 IdPage)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IHLP_FormaSpiskaSprPageElement __uuidof(IHLP_FormaSpiskaSprPageElement)
#endif
