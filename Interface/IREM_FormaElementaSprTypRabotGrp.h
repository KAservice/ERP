#ifndef UIREM_FormaElementaSprTypRabotGrpH
#define UIREM_FormaElementaSprTypRabotGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprGrpTypRabot.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprTypRabotGrp)) IREM_FormaElementaSprTypRabotGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprGrpTypRabot* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpTypRabot* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpTypRabot* DM)=0;

};
#define IID_IREM_FormaElementaSprTypRabotGrp __uuidof(IREM_FormaElementaSprTypRabotGrp)
#endif
