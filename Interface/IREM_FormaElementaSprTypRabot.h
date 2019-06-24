#ifndef UIREM_FormaElementaSprTypRabotH
#define UIREM_FormaElementaSprTypRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprTypRabot.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprTypRabot)) IREM_FormaElementaSprTypRabot : public IMainInterface
{
public:
   __property IREM_DMSprTypRabot* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprTypRabot* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprTypRabot* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString NameGroup = {read = get_NameGroup , write = set_NameGroup};
   virtual UnicodeString get_NameGroup(void)=0;
   virtual void set_NameGroup(UnicodeString NameGroup)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprTypRabot __uuidof(IREM_FormaElementaSprTypRabot)
#endif
