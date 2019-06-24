#ifndef UREM_FormaReportKartTovaraImplH
#define UREM_FormaReportKartTovaraImplH
#include "IREM_FormaReportKartTovara.h"
#include "UREM_FormaReportKartTovara.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_FormaReportKartTovaraImpl)) TREM_FormaReportKartTovaraImpl : public IREM_FormaReportKartTovara, IkanCallBack
{
public:
   TREM_FormaReportKartTovaraImpl();
   ~TREM_FormaReportKartTovaraImpl();
   TREM_FormaReportKartTovara * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

   //IkanCallBack  
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);

//IREM_FormaReportKartTovara
   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSkl(void);
   virtual void set_IdSkl(__int64 IdSkl);

   virtual __int64 get_IdGrpNom(void);
   virtual void set_IdGrpNom(__int64 IdGrpNom);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual TDateTime get_PosStart(void);
   virtual void set_PosStart(TDateTime PosStart);

   virtual TDateTime get_PosEnd(void);
   virtual void set_PosEnd(TDateTime PosEnd);

   virtual UnicodeString get_NameFirm(void);
   virtual void set_NameFirm(UnicodeString NameFirm);

   virtual UnicodeString get_NameSklad(void);
   virtual void set_NameSklad(UnicodeString NameSklad);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual void UpdateForm(void);
};
#define CLSID_TREM_FormaReportKartTovaraImpl __uuidof(TREM_FormaReportKartTovaraImpl)
#endif
