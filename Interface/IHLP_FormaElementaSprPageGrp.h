#ifndef UIHLP_FormaElementaSprPageGrpH
#define UIHLP_FormaElementaSprPageGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprPageGrp.h"
class __declspec(uuid(Global_IID_IHLP_FormaElementaSprPageGrp)) IHLP_FormaElementaSprPageGrp : public IMainInterface
{
public:
   __property IHLP_DMSprPageGrp* DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprPageGrp* get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprPageGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IHLP_FormaElementaSprPageGrp __uuidof(IHLP_FormaElementaSprPageGrp)
#endif
