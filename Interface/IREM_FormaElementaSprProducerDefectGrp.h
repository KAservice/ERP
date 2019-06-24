#ifndef UIREM_FormaElementaSprProducerDefectGrpH
#define UIREM_FormaElementaSprProducerDefectGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerDefectGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerDefectGrp)) IREM_FormaElementaSprProducerDefectGrp : public IMainInterface
{
public:
   __property IREM_DMSprProducerDefectGrp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerDefectGrp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerDefectGrp* DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IREM_FormaElementaSprProducerDefectGrp __uuidof(IREM_FormaElementaSprProducerDefectGrp)
#endif
