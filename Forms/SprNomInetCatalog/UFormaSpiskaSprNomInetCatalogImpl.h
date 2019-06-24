#ifndef UFormaSpiskaSprNomInetCatalogImplH
#define UFormaSpiskaSprNomInetCatalogImplH
#include "IFormaSpiskaSprNomInetCatalog.h"
#include "UFormaSpiskaSprNomInetCatalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaSpiskaSprNomInetCatalogImpl)) TFormaSpiskaSprNomInetCatalogImpl : public IFormaSpiskaSprNomInetCatalog, IkanCallBack
{
public:
   TFormaSpiskaSprNomInetCatalogImpl();
   ~TFormaSpiskaSprNomInetCatalogImpl();
   TFormaSpiskaSprNomInetCatalog * Object;
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

//IFormaSpiskaSprNomInetCatalog
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual IDMSprNomInetCatalog* get_DM(void);
   virtual void set_DM(IDMSprNomInetCatalog* DM);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual __int64 get_IdInetCatalog(void);
   virtual void set_IdInetCatalog(__int64 IdInetCatalog);

   virtual __int64 get_ViborIdNom(void);
   virtual void set_ViborIdNom(__int64 ViborIdNom);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual void DeleteElement();
   virtual void UpdateForm(void);
};
#define CLSID_TFormaSpiskaSprNomInetCatalogImpl __uuidof(TFormaSpiskaSprNomInetCatalogImpl)
#endif
