#ifndef UIFormaSpiskaSprSostProdH
#define UIFormaSpiskaSprSostProdH
#include "IMainInterface.h"
#include "IDMSprSostProd.h"
class __declspec(uuid("{3564FCA7-435A-4395-A664-0C28A4BCACAB}"))IFormaSpiskaSprSostProd : public IMainInterface
{
public:
   __property IDMSprSostProd * DM = {read = get_DM , write = set_DM};
   virtual IDMSprSostProd * get_DM(void)=0;
   virtual void set_DM(IDMSprSostProd * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   __property __int64 IdNomRest = {read = get_IdNomRest , write = set_IdNomRest};
   virtual __int64 get_IdNomRest(void)=0;
   virtual void set_IdNomRest(__int64 IdNomRest)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   __property double KolEdProd = {read = get_KolEdProd , write = set_KolEdProd};
   virtual double get_KolEdProd(void)=0;
   virtual void set_KolEdProd(double KolEdProd)=0;

   __property UnicodeString NameEdProd = {read = get_NameEdProd , write = set_NameEdProd};
   virtual UnicodeString get_NameEdProd(void)=0;
   virtual void set_NameEdProd(UnicodeString NameEdProd)=0;

   __property double KFEdProd = {read = get_KFEdProd , write = set_KFEdProd};
   virtual double get_KFEdProd(void)=0;
   virtual void set_KFEdProd(double KFEdProd)=0;

};
#define IID_IFormaSpiskaSprSostProd __uuidof(IFormaSpiskaSprSostProd)
#endif
