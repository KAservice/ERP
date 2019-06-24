#ifndef UIREM_FormaElementaSprProducerModelGrpH
#define UIREM_FormaElementaSprProducerModelGrpH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerModelGrp.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerModelGrp)) IREM_FormaElementaSprProducerModelGrp : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IREM_DMSprProducerModelGrp* DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerModelGrp* get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerModelGrp* DM)=0;

};
#define IID_IREM_FormaElementaSprProducerModelGrp __uuidof(IREM_FormaElementaSprProducerModelGrp)
#endif
