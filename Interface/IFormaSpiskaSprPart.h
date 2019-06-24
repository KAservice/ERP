#ifndef UIFormaSpiskaSprPartH
#define UIFormaSpiskaSprPartH
#include "IMainInterface.h"
#include "IDMSprPart.h"
class __declspec(uuid("{A6EEA79E-30EE-4975-960A-1C5815342324}")) IFormaSpiskaSprPart : public IMainInterface
{
public:
   __property IDMSprPart * DM = {read = get_DM , write = set_DM};
   virtual IDMSprPart * get_DM(void)=0;
   virtual void set_DM(IDMSprPart * DM)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

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
#define IID_IFormaSpiskaSprPart __uuidof(IFormaSpiskaSprPart)
#endif
