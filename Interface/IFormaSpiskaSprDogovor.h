#ifndef UIFormaSpiskaSprDogovorH
#define UIFormaSpiskaSprDogovorH
#include "IMainInterface.h"
#include "IDMSprDogovor.h"
class __declspec(uuid("{E36D1FCE-B66C-4A00-B00D-E6F225C362B8}")) IFormaSpiskaSprDogovor : public IMainInterface
{
public:
   __property IDMSprDogovor * DM = {read = get_DM , write = set_DM};
   virtual IDMSprDogovor * get_DM(void)=0;
   virtual void set_DM(IDMSprDogovor * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprDogovor __uuidof(IFormaSpiskaSprDogovor)
#endif
