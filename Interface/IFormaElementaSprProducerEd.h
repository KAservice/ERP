#ifndef UIFormaElementaSprProducerEdH
#define UIFormaElementaSprProducerEdH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProducerEd.h"
class __declspec(uuid(Global_IID_IFormaElementaSprProducerEd)) IFormaElementaSprProducerEd : public IMainInterface
{
public:
   __property IDMSprProducerEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProducerEd * get_DM(void)=0;
   virtual void set_DM(IDMSprProducerEd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprProducerEd __uuidof(IFormaElementaSprProducerEd)
#endif
