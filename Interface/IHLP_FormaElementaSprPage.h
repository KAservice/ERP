#ifndef UIHLP_FormaElementaSprPageH
#define UIHLP_FormaElementaSprPageH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprPage.h"
class __declspec(uuid(Global_IID_IHLP_FormaElementaSprPage)) IHLP_FormaElementaSprPage : public IMainInterface
{
public:
   __property IHLP_DMSprPage * DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprPage * get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprPage * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdGrpPage = {read = get_IdGrpPage , write = set_IdGrpPage};
   virtual __int64 get_IdGrpPage(void)=0;
   virtual void set_IdGrpPage(__int64 IdGrpPage)=0;

   __property UnicodeString NameGrp = {read = get_NameGrp , write = set_NameGrp};
   virtual UnicodeString get_NameGrp(void)=0;
   virtual void set_NameGrp(UnicodeString NameGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IHLP_FormaElementaSprPage __uuidof(IHLP_FormaElementaSprPage)
#endif
