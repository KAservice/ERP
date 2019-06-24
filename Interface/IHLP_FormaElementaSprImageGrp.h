#ifndef UIHLP_FormaElementaSprImageGrpH
#define UIHLP_FormaElementaSprImageGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprImageGrp.h"
class __declspec(uuid(Global_IID_IHLP_FormaElementaSprImageGrp)) IHLP_FormaElementaSprImageGrp : public IMainInterface
{
public:
   __property IHLP_DMSprImageGrp* DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprImageGrp* get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprImageGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IHLP_FormaElementaSprImageGrp __uuidof(IHLP_FormaElementaSprImageGrp)
#endif
