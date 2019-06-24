#ifndef UIFormaDocCheckProsmotrH
#define UIFormaDocCheckProsmotrH
#include "IMainInterface.h"
#include "IDMDocCheck.h"
class __declspec(uuid("{4B3B7A75-C8C8-45E1-8040-D65C27C57595}"))IFormaDocCheckProsmotr : public IMainInterface
{
public:
   __property IDMDocCheck * DM = {read = get_DM , write = set_DM};
   virtual IDMDocCheck * get_DM(void)=0;
   virtual void set_DM(IDMDocCheck * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocCheckProsmotr __uuidof(IFormaDocCheckProsmotr)
#endif
