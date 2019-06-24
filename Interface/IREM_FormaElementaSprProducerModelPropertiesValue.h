#ifndef UIREM_FormaElementaSprProducerModelPropertiesValueH
#define UIREM_FormaElementaSprProducerModelPropertiesValueH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IREM_DMSprProducerModelPropertiesValue.h"
class __declspec(uuid(Global_IID_IREM_FormaElementaSprProducerModelPropertiesValue)) IREM_FormaElementaSprProducerModelPropertiesValue : public IMainInterface
{
public:
   __property IREM_DMSprProducerModelPropertiesValue * DM = {read = get_DM , write = set_DM};
   virtual IREM_DMSprProducerModelPropertiesValue * get_DM(void)=0;
   virtual void set_DM(IREM_DMSprProducerModelPropertiesValue * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaElementaSprProducerModelPropertiesValue __uuidof(IREM_FormaElementaSprProducerModelPropertiesValue)
#endif
