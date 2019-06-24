#ifndef UIFormaSpiskaSprTypeAnalogH
#define UIFormaSpiskaSprTypeAnalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprTypeAnalog.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprTypeAnalog)) IFormaSpiskaSprTypeAnalog : public IMainInterface
{
public:
   __property IDMSprTypeAnalog * DM = {read = get_DM , write = set_DM};
   virtual IDMSprTypeAnalog * get_DM(void)=0;
   virtual void set_DM(IDMSprTypeAnalog * DM)=0;

   __property __int64 IdElement = {read = get_IdElement , write = set_IdElement};
   virtual __int64 get_IdElement(void)=0;
   virtual void set_IdElement(__int64 IdElement)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprTypeAnalog __uuidof(IFormaSpiskaSprTypeAnalog)
#endif
