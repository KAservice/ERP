#ifndef UIREM_FormaElementaSprModelInfBlockH
#define UIREM_FormaElementaSprModelInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprModelInfBlock.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprModelInfBlock)) IREM_FormaElementaSprModelInfBlock : public IMainInterface
{
public:
   __property IREM_DMSprModelInfBlock * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprModelInfBlock * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprModelInfBlock * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprModelInfBlock __uuidof(IREM_FormaElementaSprModelInfBlock)
#endif
