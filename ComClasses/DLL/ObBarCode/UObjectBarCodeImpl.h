#ifndef UObjectBarCodeImplH
#define UObjectBarCodeImplH
#include "IObjectBarCode.h"
#include "UObjectBarCode.h"
//---------------------------------------------------------------
class __declspec(uuid("{59300240-1833-4072-B5C7-4523F7DBD87E}")) TObjectBarCodeImpl : public IObjectBarCode
{
public:
   TObjectBarCodeImpl();
   ~TObjectBarCodeImpl();
   TObjectBarCode * Object;
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

//IObjectBarCode
   virtual double get_Kol(void);
   virtual void set_Kol(double Kol);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual double get_Price(void);
   virtual void set_Price(double Price);

   virtual IDMSprNom * get_SprNom(void);
   virtual void set_SprNom(IDMSprNom * SprNom);

   virtual IDMSprEd * get_SprEd(void);
   virtual void set_SprEd(IDMSprEd * SprEd);

   virtual bool get_OutReady(void);
   virtual void set_OutReady(bool OutReady);

   virtual UnicodeString get_Prefiks1(void);
   virtual void set_Prefiks1(UnicodeString Prefiks1);

   virtual UnicodeString get_Prefiks2(void);
   virtual void set_Prefiks2(UnicodeString Prefiks2);

   virtual UnicodeString get_Prefiks3(void);
   virtual void set_Prefiks3(UnicodeString Prefiks3);

   virtual UnicodeString get_Prefiks4(void);
   virtual void set_Prefiks4(UnicodeString Prefiks4);

   virtual UnicodeString get_Prefiks5(void);
   virtual void set_Prefiks5(UnicodeString Prefiks5);

   virtual UnicodeString AddEAN13(UnicodeString cod);
   virtual void  ObrabotatShtrihCod(UnicodeString sh);
   virtual void ObrabotatPrefiks2(UnicodeString bar_code);
   virtual void ObrabotatPrefiks3(UnicodeString bar_code);
   virtual void ObrabotatPrefiks4(UnicodeString bar_code);
   virtual void ObrabotatPrefiks5(UnicodeString bar_code);
   virtual UnicodeString GetNewBarCode(UnicodeString code, int type_bar_code);
   virtual void GetValuePrefiksBarCode(void);
};
#define CLSID_TObjectBarCodeImpl __uuidof(TObjectBarCodeImpl)
#endif
