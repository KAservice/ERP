#ifndef UFormaSpiskaSprSezKFSProdImplH
#define UFormaSpiskaSprSezKFSProdImplH
#include "IFormaSpiskaSprSezKFSProd.h"
#include "UFormaSpiskaSprSezKFSProd.h"
//---------------------------------------------------------------
class __declspec(uuid("{7C29389F-C82A-4507-8C38-6C2B85DE0947}"))TFormaSpiskaSprSezKFSProdImpl : public IFormaSpiskaSprSezKFSProd, IkanCallBack
{
public:
   TFormaSpiskaSprSezKFSProdImpl();
   ~TFormaSpiskaSprSezKFSProdImpl();
   TFormaSpiskaSprSezKFSProd * Object;
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

//IFormaSpiskaSprSezKFSProd
   virtual IDMSprSezKFSProd * get_DM(void);
   virtual void set_DM(IDMSprSezKFSProd * DM);

   virtual __int64 get_IdSProd(void);
   virtual void set_IdSProd(__int64 IdSProd);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void DeleteElement();
};
#define CLSID_TFormaSpiskaSprSezKFSProdImpl __uuidof(TFormaSpiskaSprSezKFSProdImpl)
#endif
