#ifndef UIFormaSpiskaSprImportNomH
#define UIFormaSpiskaSprImportNomH
#include "IMainInterface.h"
#include "IDMSprImportNom.h"
class __declspec(uuid("{A4D0FD12-8068-4A2B-92DB-459252FA84C7}")) IFormaSpiskaSprImportNom : public IMainInterface
{
public:
   __property IDMSprImportNom * DM = {read = get_DM , write = set_DM};
   virtual IDMSprImportNom * get_DM(void)=0;
   virtual void set_DM(IDMSprImportNom * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property UnicodeString HeaderText = {read = get_HeaderText , write = set_HeaderText};
   virtual UnicodeString get_HeaderText(void)=0;
   virtual void set_HeaderText(UnicodeString HeaderText)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaSpiskaSprImportNom __uuidof(IFormaSpiskaSprImportNom)
#endif
