#ifndef UIFormaViborSprEdH
#define UIFormaViborSprEdH
#include "IMainInterface.h"
#include "IDMSprEd.h"
class __declspec(uuid("{3378DC1B-6508-4F35-8E2B-2F48C00B32E5}")) IFormaViborSprEd : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property IDMSprEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprEd * get_DM(void)=0;
   virtual void set_DM(IDMSprEd * DM)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaViborSprEd __uuidof(IFormaViborSprEd)
#endif
