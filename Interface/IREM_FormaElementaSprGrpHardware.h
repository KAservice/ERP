#ifndef UIREM_FormaElementaSprGrpHardwareH
#define UIREM_FormaElementaSprGrpHardwareH
#include "IMainInterface.h"
#include "IREM_DMSprGrpHardware.h"
class __declspec(uuid("{1B124ECE-D8D0-4A71-A5D9-9CF9687FEF9B}"))IREM_FormaElementaSprGrpHardware : public IMainInterface
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

   __property IREM_DMSprGrpHardware * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpHardware * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpHardware * DM)=0;

};
#define IID_IREM_FormaElementaSprGrpHardware __uuidof(IREM_FormaElementaSprGrpHardware)
#endif
