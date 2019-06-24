#ifndef UIREM_FormaElementaSprGrpNeisprH
#define UIREM_FormaElementaSprGrpNeisprH
#include "IMainInterface.h"
#include "IREM_DMSprGrpNeispr.h"
class __declspec(uuid("{8FD48079-1F83-4FF3-B93E-C333B411EE2B}")) IREM_FormaElementaSprGrpNeispr : public IMainInterface
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

   __property IREM_DMSprGrpNeispr* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprGrpNeispr* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprGrpNeispr* DM)=0;

};
#define IID_IREM_FormaElementaSprGrpNeispr __uuidof(IREM_FormaElementaSprGrpNeispr)
#endif
