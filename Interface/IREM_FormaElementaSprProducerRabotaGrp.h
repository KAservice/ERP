#ifndef UIREM_FormaElementaSprProducerRabotaGrpH
#define UIREM_FormaElementaSprProducerRabotaGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerRabotaGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerRabotaGrp)) IREM_FormaElementaSprProducerRabotaGrp : public IMainInterface
{
public:
   __property IREM_DMSprProducerRabotaGrp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerRabotaGrp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerRabotaGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IREM_FormaElementaSprProducerRabotaGrp __uuidof(IREM_FormaElementaSprProducerRabotaGrp)
#endif
