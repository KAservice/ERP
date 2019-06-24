#ifndef UIFormaElementaSprBankH
#define UIFormaElementaSprBankH
#include "IMainInterface.h"
#include "IDMSprBank.h"
class __declspec(uuid("{6F585FC3-BB6B-43F3-906E-F04AF1106C67}")) IFormaElementaSprBank : public IMainInterface
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


};
#define IID_IFormaElementaSprBank __uuidof(IFormaElementaSprBank)
#endif
