#ifndef UIART_FormaElementaSprNaborInfBlockSostavGrpH
#define UIART_FormaElementaSprNaborInfBlockSostavGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IART_DMSprNaborInfBlockSostavGrp.h"
class __declspec(uuid(Global_IID_IART_FormaElementaSprNaborInfBlockSostavGrp)) IART_FormaElementaSprNaborInfBlockSostavGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IART_DMSprNaborInfBlockSostavGrp* DM = {read = get_DM , write = set_DM};
   virtual IART_DMSprNaborInfBlockSostavGrp* get_DM(void)=0;
   virtual void set_DM(IART_DMSprNaborInfBlockSostavGrp* DM)=0;

};
#define IID_IART_FormaElementaSprNaborInfBlockSostavGrp __uuidof(IART_FormaElementaSprNaborInfBlockSostavGrp)
#endif
