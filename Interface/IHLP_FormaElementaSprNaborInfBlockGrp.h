#ifndef UIHLP_FormaElementaSprNaborInfBlockGrpH
#define UIHLP_FormaElementaSprNaborInfBlockGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprNaborInfBlockGrp.h"
class __declspec(uuid(Global_IID_IHLP_FormaElementaSprNaborInfBlockGrp)) IHLP_FormaElementaSprNaborInfBlockGrp : public IMainInterface
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

   __property IHLP_DMSprNaborInfBlockGrp* DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprNaborInfBlockGrp* get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprNaborInfBlockGrp* DM)=0;

};
#define IID_IHLP_FormaElementaSprNaborInfBlockGrp __uuidof(IHLP_FormaElementaSprNaborInfBlockGrp)
#endif
