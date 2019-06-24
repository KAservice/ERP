#ifndef UIFormaSpiskaSprBankSchetH
#define UIFormaSpiskaSprBankSchetH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprBankSchet.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprBankSchet)) IFormaSpiskaSprBankSchet : public IMainInterface
{
public:
   __property IDMSprBankSchet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprBankSchet * get_DM(void)=0;
   virtual void set_DM(IDMSprBankSchet * DM)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaSpiskaSprBankSchet __uuidof(IFormaSpiskaSprBankSchet)
#endif
