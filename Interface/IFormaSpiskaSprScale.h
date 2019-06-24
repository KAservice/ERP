#ifndef UIFormaSpiskaSprScaleH
#define UIFormaSpiskaSprScaleH
#include "IMainInterface.h"
#include "IDMSprScale.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprScale))IFormaSpiskaSprScale : public IMainInterface
{
public:
   __property IDMSprScale * DM = {read = get_DM , write = set_DM};
   virtual IDMSprScale * get_DM(void)=0;
   virtual void set_DM(IDMSprScale * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaSpiskaSprScale __uuidof(IFormaSpiskaSprScale)
#endif
