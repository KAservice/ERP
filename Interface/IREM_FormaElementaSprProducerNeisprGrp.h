#ifndef UIREM_FormaElementaSprProducerNeisprGrpH
#define UIREM_FormaElementaSprProducerNeisprGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerNeisprGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerNeisprGrp)) IREM_FormaElementaSprProducerNeisprGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprProducerNeisprGrp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerNeisprGrp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerNeisprGrp* DM)=0;

};
#define IID_IREM_FormaElementaSprProducerNeisprGrp __uuidof(IREM_FormaElementaSprProducerNeisprGrp)
#endif
