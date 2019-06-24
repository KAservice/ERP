#ifndef UIFormaElementaSprBankSchetH
#define UIFormaElementaSprBankSchetH
#include "IMainInterface.h"
#include "IDMSprBankSchet.h"
class __declspec(uuid("{62F1A35B-E840-4382-85A8-8AF6954AD568}")) IFormaElementaSprBankSchet : public IMainInterface
{
public:
   __property IDMSprBankSchet * DM = {read = get_DM , write = set_DM};
   virtual IDMSprBankSchet * get_DM(void)=0;
   virtual void set_DM(IDMSprBankSchet * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


};
#define IID_IFormaElementaSprBankSchet __uuidof(IFormaElementaSprBankSchet)
#endif
