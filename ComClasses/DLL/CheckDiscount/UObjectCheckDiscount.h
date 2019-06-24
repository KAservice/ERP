//---------------------------------------------------------------------------

#ifndef UObjectCheckDiscountH
#define UObjectCheckDiscountH
//---------------------------------------------------------------------------

#include "IDMSprEd.h"
#include "IDMSprNom.h"
#include "IDMFibConnection.h"
#include "IDMSprDiscountCard.h"
#include "IDMSprDiscountAuto.h"
#include "UCheckDiscount_StringDoc.h"
//---------------------------------------------------------------------------


#include <Classes.hpp>


class TObjectCheckDiscount
{
private:
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IDMSprDiscountCard * DMSprDiscountCard;


public:
		TObjectCheckDiscount();
		~TObjectCheckDiscount();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

	typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int  Done(void);

		TList * List;


		TStringDoc * StringDoc;
		int NumberTecString;

		void CheckDiscount(void); //переходим на первую строку
		bool GetString(void);   //получаем строку, если есть строка то true

		void ClearList(void);
		void AddString(
				__int64 id_string,
				__int64 id_nom,
				__int64 id_ed,
				__int64 id_grp,
				__int64 id_vid_nom,
				double price,
				double kol,
				double kf,
				double sum,
				double sum_discount,
				double procent_discount,
				double procent_discount_auto,
				double procent_discount_card,
				double procent_discount_hand,
				bool no_discount
							);



	  UnicodeString TextMessage;
	  UnicodeString TextMessageAtention;

	  __int64 IdDiscountCard;
	  UnicodeString NameDiscountCard;
	  __int64 IdTypePrice;
	  UnicodeString NameTypePrice;
	  __int64 IdSklad;
	  __int64 IdKlient;
	  UnicodeString NameKlient;
	  double SummaDoc;

		void GetProcentPoDiscountCard(void);
		void GetProcentAuto(double sum_doc);
		bool FindCardPoCodu(UnicodeString code);

};
#endif
