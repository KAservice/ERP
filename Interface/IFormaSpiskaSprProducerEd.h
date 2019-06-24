#ifndef UIFormaSpiskaSprProducerEdH
#define UIFormaSpiskaSprProducerEdH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprProducerEd.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprProducerEd)) IFormaSpiskaSprProducerEd : public IMainInterface
{
public:
   __property IDMSprProducerEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprProducerEd * get_DM(void)=0;
   virtual void set_DM(IDMSprProducerEd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdProducerNom = {read = get_IdProducerNom , write = set_IdProducerNom};
   virtual __int64 get_IdProducerNom(void)=0;
   virtual void set_IdProducerNom(__int64 IdProducerNom)=0;

   __property __int64 IdProducerTypePrice = {read = get_IdProducerTypePrice , write = set_IdProducerTypePrice};
   virtual __int64 get_IdProducerTypePrice(void)=0;
   virtual void set_IdProducerTypePrice(__int64 IdProducerTypePrice)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprProducerEd __uuidof(IFormaSpiskaSprProducerEd)
#endif
