#ifndef UIFormaElementaSprNomRestH
#define UIFormaElementaSprNomRestH
#include "IMainInterface.h"
#include "IDMSprNomRest.h"
class __declspec(uuid("{E9009D97-66A3-4538-98AD-EF9376500511}")) IFormaElementaSprNomRest : public IMainInterface
{
public:
   __property IDMSprNomRest * DM = {read = get_DM , write = set_DM};
   virtual IDMSprNomRest * get_DM(void)=0;
   virtual void set_DM(IDMSprNomRest * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaElementaSprNomRest __uuidof(IFormaElementaSprNomRest)
#endif
