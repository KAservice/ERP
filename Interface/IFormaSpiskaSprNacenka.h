#ifndef UIFormaSpiskaSprNacenkaH
#define UIFormaSpiskaSprNacenkaH
#include "IMainInterface.h"
#include "IDMSprNacenka.h"
class __declspec(uuid("{9BB3E3E3-B5E9-4C3A-8507-67AA11626BEF}")) IFormaSpiskaSprNacenka : public IMainInterface
{
public:
   __property IDMSprNacenka * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNacenka * get_DM(void)=0;
   virtual void set_DM(IDMSprNacenka * DM)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

};
#define IID_IFormaSpiskaSprNacenka __uuidof(IFormaSpiskaSprNacenka)
#endif
