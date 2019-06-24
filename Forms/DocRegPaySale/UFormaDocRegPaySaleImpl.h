#ifndef UFormaDocRegPaySaleImplH
#define UFormaDocRegPaySaleImplH
#include "IFormaDocRegPaySale.h"
#include "UFormaDocRegPaySale.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TFormaDocRegPaySaleImpl)) TFormaDocRegPaySaleImpl : public IFormaDocRegPaySale, IkanCallBack
{
public:
   TFormaDocRegPaySaleImpl();
   ~TFormaDocRegPaySaleImpl();
   TFormaDocRegPaySale * Object;
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

//IFormaDocRegPaySale
   virtual IDMDocRegPaySale * get_DM(void);
   virtual void set_DM(IDMDocRegPaySale * DM);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual void UpdateForm(void);
};
#define CLSID_TFormaDocRegPaySaleImpl __uuidof(TFormaDocRegPaySaleImpl)
#endif
