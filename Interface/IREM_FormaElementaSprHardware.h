#ifndef UIREM_FormaElementaSprHardwareH
#define UIREM_FormaElementaSprHardwareH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprHardware.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprHardware)) IREM_FormaElementaSprHardware : public IMainInterface
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

   __property IREM_DMSprHardware * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprHardware * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprHardware * DM)=0;

   __property bool SaveElement = {read = get_SaveElement , write = set_SaveElement};
   virtual bool get_SaveElement(void)=0;
   virtual void set_SaveElement(bool SaveElement)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprHardware __uuidof(IREM_FormaElementaSprHardware)
#endif
