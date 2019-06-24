#ifndef UIFormaSpiskaSprImportEdH
#define UIFormaSpiskaSprImportEdH
#include "IMainInterface.h"
#include "IDMSprImportEd.h"
class __declspec(uuid("{F6032A38-BFE7-47CB-BE1C-B3185ED10468}")) IFormaSpiskaSprImportEd : public IMainInterface
{
public:
   __property IDMSprImportEd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprImportEd * get_DM(void)=0;
   virtual void set_DM(IDMSprImportEd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdEd = {read = get_IdEd , write = set_IdEd};
   virtual __int64 get_IdEd(void)=0;
   virtual void set_IdEd(__int64 IdEd)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprImportEd __uuidof(IFormaSpiskaSprImportEd)
#endif
