#ifndef UIREM_FormaElementaSprModelTypeRabotH
#define UIREM_FormaElementaSprModelTypeRabotH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprModelTypeRabot)) IREM_FormaElementaSprModelTypeRabot : public IMainInterface
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
#define IID_IREM_FormaElementaSprModelTypeRabot __uuidof(IREM_FormaElementaSprModelTypeRabot)
#endif
