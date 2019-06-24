#ifndef UIART_FormaElementaSprNaborInfBlockH
#define UIART_FormaElementaSprNaborInfBlockH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IART_DMSprNaborInfBlock.h"
class __declspec(uuid(Global_IID_IART_FormaElementaSprNaborInfBlock)) IART_FormaElementaSprNaborInfBlock : public IMainInterface
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

   __property IART_DMSprNaborInfBlock * DM = {read = get_DM , write = set_DM};
   virtual IART_DMSprNaborInfBlock * get_DM(void)=0;
   virtual void set_DM(IART_DMSprNaborInfBlock * DM)=0;

   __property bool SaveElement = {read = get_SaveElement , write = set_SaveElement};
   virtual bool get_SaveElement(void)=0;
   virtual void set_SaveElement(bool SaveElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IART_FormaElementaSprNaborInfBlock __uuidof(IART_FormaElementaSprNaborInfBlock)
#endif
