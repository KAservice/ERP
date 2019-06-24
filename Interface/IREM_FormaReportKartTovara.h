#ifndef UIREM_FormaReportKartTovaraH
#define UIREM_FormaReportKartTovaraH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IREM_FormaReportKartTovara)) IREM_FormaReportKartTovara : public IMainInterface
{
public:
   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSkl = {read = get_IdSkl , write = set_IdSkl};
   virtual __int64 get_IdSkl(void)=0;
   virtual void set_IdSkl(__int64 IdSkl)=0;

   __property __int64 IdGrpNom = {read = get_IdGrpNom , write = set_IdGrpNom};
   virtual __int64 get_IdGrpNom(void)=0;
   virtual void set_IdGrpNom(__int64 IdGrpNom)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property TDateTime PosStart = {read = get_PosStart , write = set_PosStart};
   virtual TDateTime get_PosStart(void)=0;
   virtual void set_PosStart(TDateTime PosStart)=0;

   __property TDateTime PosEnd = {read = get_PosEnd , write = set_PosEnd};
   virtual TDateTime get_PosEnd(void)=0;
   virtual void set_PosEnd(TDateTime PosEnd)=0;

   __property UnicodeString NameFirm = {read = get_NameFirm , write = set_NameFirm};
   virtual UnicodeString get_NameFirm(void)=0;
   virtual void set_NameFirm(UnicodeString NameFirm)=0;

   __property UnicodeString NameSklad = {read = get_NameSklad , write = set_NameSklad};
   virtual UnicodeString get_NameSklad(void)=0;
   virtual void set_NameSklad(UnicodeString NameSklad)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IREM_FormaReportKartTovara __uuidof(IREM_FormaReportKartTovara)
#endif
