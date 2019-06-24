#ifndef UIHLP_FormaElementaSprInfBlockGrpH
#define UIHLP_FormaElementaSprInfBlockGrpH
#include "IMainInterface.h"
#include "IHLP_DMSprInfBlockGrp.h"

class __declspec(uuid(Global_IID_IHLP_FormaElementaSprInfBlockGrp)) IHLP_FormaElementaSprInfBlockGrp : public IMainInterface
{
public:
   __property IHLP_DMSprInfBlockGrp* DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprInfBlockGrp* get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprInfBlockGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IHLP_FormaElementaSprInfBlockGrp __uuidof(IHLP_FormaElementaSprInfBlockGrp)
#endif
