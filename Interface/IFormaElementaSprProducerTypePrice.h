#ifndef UIFormaElementaSprProducerTypePriceH
#define UIFormaElementaSprProducerTypePriceH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProducerTypePrice.h"
class __declspec(uuid(Global_IID_IFormaElementaSprProducerTypePrice)) IFormaElementaSprProducerTypePrice : public IMainInterface
{
public:
   __property IDMSprProducerTypePrice * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProducerTypePrice * get_DM(void)=0;
   virtual void set_DM(IDMSprProducerTypePrice * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprProducerTypePrice __uuidof(IFormaElementaSprProducerTypePrice)
#endif
