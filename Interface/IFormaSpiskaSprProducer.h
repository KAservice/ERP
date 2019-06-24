#ifndef UIFormaSpiskaSprProducerH
#define UIFormaSpiskaSprProducerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProducer.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprProducer)) IFormaSpiskaSprProducer : public IMainInterface
{
public:
   __property IDMSprProducer * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProducer * get_DM(void)=0;
   virtual void set_DM(IDMSprProducer * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaSpiskaSprProducer __uuidof(IFormaSpiskaSprProducer)
#endif
