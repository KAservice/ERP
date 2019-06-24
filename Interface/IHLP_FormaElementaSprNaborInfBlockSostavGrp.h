#ifndef UIHLP_FormaElementaSprNaborInfBlockSostavGrpH
#define UIHLP_FormaElementaSprNaborInfBlockSostavGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IHLP_DMSprNaborInfBlockSostavGrp.h"
class __declspec(uuid(Global_IID_IHLP_FormaElementaSprNaborInfBlockSostavGrp)) IHLP_FormaElementaSprNaborInfBlockSostavGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IHLP_DMSprNaborInfBlockSostavGrp* DM = {read = get_DM , write = set_DM};
   virtual IHLP_DMSprNaborInfBlockSostavGrp* get_DM(void)=0;
   virtual void set_DM(IHLP_DMSprNaborInfBlockSostavGrp* DM)=0;

};
#define IID_IHLP_FormaElementaSprNaborInfBlockSostavGrp __uuidof(IHLP_FormaElementaSprNaborInfBlockSostavGrp)
#endif
