#ifndef UIFormaSpiskaSprFirmH
#define UIFormaSpiskaSprFirmH
#include "IMainInterface.h"
#include "IDMSprFirm.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprFirm)) IFormaSpiskaSprFirm : public IMainInterface
{
public:
   __property IDMSprFirm * DM = {read = get_DM , write = set_DM};
   virtual IDMSprFirm * get_DM(void)=0;
   virtual void set_DM(IDMSprFirm * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaSpiskaSprFirm __uuidof(IFormaSpiskaSprFirm)
#endif
