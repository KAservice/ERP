#ifndef UIREM_FormaElementaSprProducerConditionGrpH
#define UIREM_FormaElementaSprProducerConditionGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerConditionGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerConditionGrp)) IREM_FormaElementaSprProducerConditionGrp : public IMainInterface
{
public:
   __property IREM_DMSprProducerConditionGrp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerConditionGrp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerConditionGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IREM_FormaElementaSprProducerConditionGrp __uuidof(IREM_FormaElementaSprProducerConditionGrp)
#endif
