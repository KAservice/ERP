#ifndef UIFormaDocCheckTouchH
#define UIFormaDocCheckTouchH
#include "IMainInterface.h"
#include "IDMDocCheck.h"
class __declspec(uuid("{C494358E-EB15-49DF-8F2B-6A80F8ED69F8}")) IFormaDocCheckTouch : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMDocCheck * DM = {read = get_DM , write = set_DM};
   virtual IDMDocCheck * get_DM(void)=0;
   virtual void set_DM(IDMDocCheck * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdARM = {read = get_IdARM , write = set_IdARM};
   virtual __int64 get_IdARM(void)=0;
   virtual void set_IdARM(__int64 IdARM)=0;

   __property bool CheckSave = {read = get_CheckSave , write = set_CheckSave};
   virtual bool get_CheckSave(void)=0;
   virtual void set_CheckSave(bool CheckSave)=0;

   __property bool CheckPrint = {read = get_CheckPrint , write = set_CheckPrint};
   virtual bool get_CheckPrint(void)=0;
   virtual void set_CheckPrint(bool CheckPrint)=0;

   __property bool CheckCreate = {read = get_CheckCreate , write = set_CheckCreate};
   virtual bool get_CheckCreate(void)=0;
   virtual void set_CheckCreate(bool CheckCreate)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaDocCheckTouch __uuidof(IFormaDocCheckTouch)
#endif
