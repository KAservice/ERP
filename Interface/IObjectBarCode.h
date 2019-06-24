#ifndef UIObjectBarCodeH
#define UIObjectBarCodeH
#include "IMainInterface.h"
#include "IDMSprNom.h"
#include "IDMSprEd.h"
class __declspec(uuid("{81DABA82-D371-4655-8D13-B035D94AF02B}")) IObjectBarCode : public IMainInterface
{
public:
   __property double Kol = {read = get_Kol , write = set_Kol};
   virtual double get_Kol(void)=0;
   virtual void set_Kol(double Kol)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property double Price = {read = get_Price , write = set_Price};
   virtual double get_Price(void)=0;
   virtual void set_Price(double Price)=0;

   __property IDMSprNom * SprNom = {read = get_SprNom , write = set_SprNom};
   virtual IDMSprNom * get_SprNom(void)=0;
   virtual void set_SprNom(IDMSprNom * SprNom)=0;

   __property IDMSprEd * SprEd = {read = get_SprEd , write = set_SprEd};
   virtual IDMSprEd * get_SprEd(void)=0;
   virtual void set_SprEd(IDMSprEd * SprEd)=0;

   __property bool OutReady = {read = get_OutReady , write = set_OutReady};
   virtual bool get_OutReady(void)=0;
   virtual void set_OutReady(bool OutReady)=0;

   __property UnicodeString Prefiks1 = {read = get_Prefiks1 , write = set_Prefiks1};
   virtual UnicodeString get_Prefiks1(void)=0;
   virtual void set_Prefiks1(UnicodeString Prefiks1)=0;

   __property UnicodeString Prefiks2 = {read = get_Prefiks2 , write = set_Prefiks2};
   virtual UnicodeString get_Prefiks2(void)=0;
   virtual void set_Prefiks2(UnicodeString Prefiks2)=0;

   __property UnicodeString Prefiks3 = {read = get_Prefiks3 , write = set_Prefiks3};
   virtual UnicodeString get_Prefiks3(void)=0;
   virtual void set_Prefiks3(UnicodeString Prefiks3)=0;

   __property UnicodeString Prefiks4 = {read = get_Prefiks4 , write = set_Prefiks4};
   virtual UnicodeString get_Prefiks4(void)=0;
   virtual void set_Prefiks4(UnicodeString Prefiks4)=0;

   __property UnicodeString Prefiks5 = {read = get_Prefiks5 , write = set_Prefiks5};
   virtual UnicodeString get_Prefiks5(void)=0;
   virtual void set_Prefiks5(UnicodeString Prefiks5)=0;

   __property UnicodeString TextError = {read = get_TextError , write = set_TextError};
   virtual UnicodeString get_TextError(void)=0;
   virtual void set_TextError(UnicodeString TextError)=0;

   virtual UnicodeString AddEAN13(UnicodeString cod)=0;
   virtual void  ObrabotatShtrihCod(UnicodeString sh)=0;
   virtual void ObrabotatPrefiks2(UnicodeString bar_code)=0;
   virtual void ObrabotatPrefiks3(UnicodeString bar_code)=0;
   virtual void ObrabotatPrefiks4(UnicodeString bar_code)=0;
   virtual void ObrabotatPrefiks5(UnicodeString bar_code)=0;
   virtual UnicodeString GetNewBarCode(UnicodeString code, int type_bar_code)=0;
   virtual void GetValuePrefiksBarCode(void)=0;
};
#define IID_IObjectBarCode __uuidof(IObjectBarCode)
#endif
