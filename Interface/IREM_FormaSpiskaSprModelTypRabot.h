#ifndef UIREM_FormaSpiskaSprModelTypRabotH
#define UIREM_FormaSpiskaSprModelTypRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModelTypRabot.h"
class __declspec(uuid(Global_IID_IREM_FormaSpiskaSprModelTypRabot)) IREM_FormaSpiskaSprModelTypRabot : public IMainInterface
{
public:
   __property IREM_DMSprModelTypRabot * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModelTypRabot * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModelTypRabot * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};
   virtual __int64 get_IdOwner(void)=0;
   virtual void set_IdOwner(__int64 IdOwner)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IREM_FormaSpiskaSprModelTypRabot __uuidof(IREM_FormaSpiskaSprModelTypRabot)
#endif
