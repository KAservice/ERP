#ifndef UIFormaReportSostProdH
#define UIFormaReportSostProdH
#include "IMainInterface.h"
class __declspec(uuid("{214C2182-EB87-4F36-BA15-E564E66DA6DB}")) IFormaReportSostProd : public IMainInterface
{
public:
   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdNomRest = {read = get_IdNomRest , write = set_IdNomRest};
   virtual __int64 get_IdNomRest(void)=0;
   virtual void set_IdNomRest(__int64 IdNomRest)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   __property UnicodeString NameTypePrice = {read = get_NameTypePrice , write = set_NameTypePrice};
   virtual UnicodeString get_NameTypePrice(void)=0;
   virtual void set_NameTypePrice(UnicodeString NameTypePrice)=0;

   virtual void UpdateForm()=0;
};
#define IID_IFormaReportSostProd __uuidof(IFormaReportSostProd)
#endif
