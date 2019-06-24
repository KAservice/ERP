#ifndef UFormaSpiskaSprSostProdImplH
#define UFormaSpiskaSprSostProdImplH
#include "IFormaSpiskaSprSostProd.h"
#include "UFormaSpiskaSprSostProd.h"
//---------------------------------------------------------------
class __declspec(uuid("{9AFC0D4B-E27F-4168-B3A8-BEAAD0897894}")) TFormaSpiskaSprSostProdImpl : public IFormaSpiskaSprSostProd, IkanCallBack
{
public:
   TFormaSpiskaSprSostProdImpl();
   ~TFormaSpiskaSprSostProdImpl();
   TFormaSpiskaSprSostProd * Object;
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

//IFormaSpiskaSprSostProd
   virtual IDMSprSostProd * get_DM(void);
   virtual void set_DM(IDMSprSostProd * DM);

   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual __int64 get_IdNomRest(void);
   virtual void set_IdNomRest(__int64 IdNomRest);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual UnicodeString get_NameNom(void);
   virtual void set_NameNom(UnicodeString NameNom);

   virtual double get_KolEdProd(void);
   virtual void set_KolEdProd(double KolEdProd);

   virtual UnicodeString get_NameEdProd(void);
   virtual void set_NameEdProd(UnicodeString NameEdProd);

   virtual double get_KFEdProd(void);
   virtual void set_KFEdProd(double KFEdProd);



};
#define CLSID_TFormaSpiskaSprSostProdImpl __uuidof(TFormaSpiskaSprSostProdImpl)
#endif
