#ifndef UIFormaSpiskaSprBankH
#define UIFormaSpiskaSprBankH
#include "IMainInterface.h"
#include "IDMSprBank.h"
class __declspec(uuid("{85AF7494-DA8E-44D9-BF46-7F9096D3B854}")) IFormaSpiskaSprBank : public IMainInterface
{
public:
   __property IDMSprBank * DM = {read = get_DM , write = set_DM};
   virtual IDMSprBank * get_DM(void)=0;
   virtual void set_DM(IDMSprBank * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void OpenFormElement()=0;
   virtual void OpenFormNewElement()=0;
   virtual void DeleteElement()=0;
};
#define IID_IFormaSpiskaSprBank __uuidof(IFormaSpiskaSprBank)
#endif
