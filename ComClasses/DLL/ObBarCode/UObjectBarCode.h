//---------------------------------------------------------------------------

#ifndef UObjectBarCodeH
#define UObjectBarCodeH
#include <Classes.hpp>
#include "IDMSprEd.h"
#include "IDMSprNom.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
class TObjectBarCode
{
private:
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

public:
		TObjectBarCode();
		~TObjectBarCode();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

	typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		bool Init(void);
		int  Done(void);

		//параметры товара
		double Kol;
		__int64 IdTypePrice;
		double Price;
		IDMSprNom * SprNom;
		IDMSprEd * SprEd;
		bool OutReady;

		UnicodeString AddEAN13(UnicodeString cod);

        void  ObrabotatShtrihCod(UnicodeString sh);
		UnicodeString Prefiks1;  //обычный локальный шк, поиск по шк единицы
		UnicodeString Prefiks2; //колич. поиск по коду номенклатуры,  код в первой половине
		UnicodeString Prefiks3; //колич. поиск по коду номенклатуры, код во второй половине
		UnicodeString Prefiks4; //колич. поиск по шк единицы, вес в первой половине
		UnicodeString Prefiks5; //колич. поиск по шк единицы, вес во второй половине


		void ObrabotatPrefiks2(UnicodeString bar_code);
		void ObrabotatPrefiks3(UnicodeString bar_code);
		void ObrabotatPrefiks4(UnicodeString bar_code);
		void ObrabotatPrefiks5(UnicodeString bar_code);



		UnicodeString GetNewBarCode(UnicodeString code, int type_bar_code);
		void GetValuePrefiksBarCode(void);

		UnicodeString TextError;
};
#endif
