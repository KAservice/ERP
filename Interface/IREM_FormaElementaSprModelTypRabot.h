#ifndef UIREM_FormaElementaSprModelTypRabotH
#define UIREM_FormaElementaSprModelTypRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModelTypRabot.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprModelTypRabot)) IREM_FormaElementaSprModelTypRabot : public IMainInterface
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

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprModelTypRabot __uuidof(IREM_FormaElementaSprModelTypRabot)
#endif
