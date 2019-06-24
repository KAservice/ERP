#ifndef UIFormaSpiskaSprOborudH
#define UIFormaSpiskaSprOborudH
#include "IMainInterface.h"
#include "IDMSprOborud.h"
class __declspec(uuid("{211285D8-73AD-4BFA-AEFB-E3037F4D3921}"))IFormaSpiskaSprOborud : public IMainInterface
{
public:
   __property IDMSprOborud * DM = {read = get_DM , write = set_DM};
   virtual IDMSprOborud * get_DM(void)=0;
   virtual void set_DM(IDMSprOborud * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdKKM = {read = get_IdKKM , write = set_IdKKM};
   virtual __int64 get_IdKKM(void)=0;
   virtual void set_IdKKM(__int64 IdKKM)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprOborud __uuidof(IFormaSpiskaSprOborud)
#endif
