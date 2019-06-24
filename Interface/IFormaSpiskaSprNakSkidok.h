#ifndef UIFormaSpiskaSprNakSkidokH
#define UIFormaSpiskaSprNakSkidokH
#include "IMainInterface.h"
#include "IDMSprNakSkidok.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprNakSkidok)) IFormaSpiskaSprNakSkidok : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprNakSkidok * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNakSkidok * get_DM(void)=0;
   virtual void set_DM(IDMSprNakSkidok * DM)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprNakSkidok __uuidof(IFormaSpiskaSprNakSkidok)
#endif
