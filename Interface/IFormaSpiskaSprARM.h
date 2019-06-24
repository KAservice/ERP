#ifndef UIFormaSpiskaSprARMH
#define UIFormaSpiskaSprARMH
#include "IMainInterface.h"
#include "IDMSprARM.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprARM))IFormaSpiskaSprARM : public IMainInterface
{
public:
   __property IDMSprARM * DM = {read = get_DM , write = set_DM};
   virtual IDMSprARM * get_DM(void)=0;
   virtual void set_DM(IDMSprARM * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaSpiskaSprARM __uuidof(IFormaSpiskaSprARM)
#endif
