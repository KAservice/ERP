#ifndef UFormaReportSostProdImplH
#define UFormaReportSostProdImplH
#include "IFormaReportSostProd.h"
#include "UFormaReportSostProd.h"
//---------------------------------------------------------------
class __declspec(uuid("{1341D1AA-F07B-47F4-8971-BC517668956B}")) TFormaReportSostProdImpl : public IFormaReportSostProd, IkanCallBack
{
public:
   TFormaReportSostProdImpl();
   ~TFormaReportSostProdImpl();
   TFormaReportSostProd * Object;
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

//IFormaReportSostProd
   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdNomRest(void);
   virtual void set_IdNomRest(__int64 IdNomRest);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual UnicodeString get_NameTypePrice(void);
   virtual void set_NameTypePrice(UnicodeString NameTypePrice);

   virtual void UpdateForm();
};
#define CLSID_TFormaReportSostProdImpl __uuidof(TFormaReportSostProdImpl)
#endif
