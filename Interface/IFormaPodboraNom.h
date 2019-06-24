#ifndef UIFormaPodboraNomH
#define UIFormaPodboraNomH
#include "IMainInterface.h"
class __declspec(uuid("{DD514EF8-AC29-4421-897D-208EC55B7BDA}")) IFormaPodboraNom : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;


   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property double Price = {read = get_Price , write = set_Price};
   virtual double get_Price(void)=0;
   virtual void set_Price(double Price)=0;

   __property double PriceBasEd = {read = get_PriceBasEd , write = set_PriceBasEd};
   virtual double get_PriceBasEd(void)=0;
   virtual void set_PriceBasEd(double PriceBasEd)=0;

   __property double Kol = {read = get_Kol , write = set_Kol};
   virtual double get_Kol(void)=0;
   virtual void set_Kol(double Kol)=0;

   __property double Summa = {read = get_Summa , write = set_Summa};
   virtual double get_Summa(void)=0;
   virtual void set_Summa(double Summa)=0;

   __property int IdEd = {read = get_IdEd , write = set_IdEd};
   virtual int get_IdEd(void)=0;
   virtual void set_IdEd(int IdEd)=0;

   __property UnicodeString NameEd = {read = get_NameEd , write = set_NameEd};
   virtual UnicodeString get_NameEd(void)=0;
   virtual void set_NameEd(UnicodeString NameEd)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   __property double KFEd = {read = get_KFEd , write = set_KFEd};
   virtual double get_KFEd(void)=0;
   virtual void set_KFEd(double KFEd)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaPodboraNom __uuidof(IFormaPodboraNom)
#endif
