#ifndef UIFormaViborOborudH
#define UIFormaViborOborudH
#include "IMainInterface.h"
#include "IDMSprOborud.h"
class __declspec(uuid("{E90B0F73-CA3F-4B19-8A9F-44A51DC48B6A}")) IFormaViborOborud : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprOborud * DM = {read = get_DM , write = set_DM};
   virtual IDMSprOborud * get_DM(void)=0;
   virtual void set_DM(IDMSprOborud * DM)=0;

   __property __int64 IdArm = {read = get_IdArm , write = set_IdArm};
   virtual __int64 get_IdArm(void)=0;
   virtual void set_IdArm(__int64 IdArm)=0;

   __property AnsiString TypeOborud = {read = get_TypeOborud , write = set_TypeOborud};
   virtual AnsiString get_TypeOborud(void)=0;
   virtual void set_TypeOborud(AnsiString TypeOborud)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaViborOborud __uuidof(IFormaViborOborud)
#endif
