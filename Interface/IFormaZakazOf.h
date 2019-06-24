#ifndef UIFormaZakazOfH
#define UIFormaZakazOfH
#include "IMainInterface.h"
#include "IDMRegZak.h"
class __declspec(uuid("{519C8E16-3EDE-4020-BB89-97E4C66C94AC}")) IFormaZakazOf : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMRegZak * DM = {read = get_DM , write = set_DM};
   virtual IDMRegZak * get_DM(void)=0;
   virtual void set_DM(IDMRegZak * DM)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdPod = {read = get_IdPod , write = set_IdPod};
   virtual __int64 get_IdPod(void)=0;
   virtual void set_IdPod(__int64 IdPod)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool ObjectSave = {read = get_ObjectSave , write = set_ObjectSave};
   virtual bool get_ObjectSave(void)=0;
   virtual void set_ObjectSave(bool ObjectSave)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property UnicodeString NameTypePrice = {read = get_NameTypePrice , write = set_NameTypePrice};
   virtual UnicodeString get_NameTypePrice(void)=0;
   virtual void set_NameTypePrice(UnicodeString NameTypePrice)=0;

   __property UnicodeString NameObjectZakaza = {read = get_NameObjectZakaza , write = set_NameObjectZakaza};
   virtual UnicodeString get_NameObjectZakaza(void)=0;
   virtual void set_NameObjectZakaza(UnicodeString NameObjectZakaza)=0;

   virtual void ObnovitForm(void)=0;
   virtual void UpdateForm(void)=0;
   virtual void OpenZakaz(void)=0;
};
#define IID_IFormaZakazOf __uuidof(IFormaZakazOf)
#endif
