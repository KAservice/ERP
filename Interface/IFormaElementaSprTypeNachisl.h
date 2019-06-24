#ifndef UIFormaElementaSprTypeNachislH
#define UIFormaElementaSprTypeNachislH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprTypeNachisl.h"
class __declspec(uuid(Global_IID_IFormaElementaSprTypeNachisl)) IFormaElementaSprTypeNachisl : public IMainInterface
{
public:
   __property IDMSprTypeNachisl * DM = {read = get_DM , write = set_DM};
   virtual IDMSprTypeNachisl * get_DM(void)=0;
   virtual void set_DM(IDMSprTypeNachisl * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaElementaSprTypeNachisl __uuidof(IFormaElementaSprTypeNachisl)
#endif
