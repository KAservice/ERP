//---------------------------------------------------------------------------

#ifndef UDMSprProducerPriceH
#define UDMSprProducerPriceH
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMSprProducerPrice : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *TPrice;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TPriceID_SPRTYPE_PRICE;
	TFIBWideStringField *TPriceNAME_SPRTYPE_PRICE;
	TFIBLargeIntField *TableID_SPRPRICE;
	TFIBLargeIntField *TableIDBASE_SPRPRICE;
	TFIBWideStringField *TableGID_SPRPRICE;
	TFIBLargeIntField *TableIDPRNOM_SPRPRICE;
	TFIBLargeIntField *TableIDPRTPRICE_SPRPRICE;
	TFIBBCDField *TableVALUE_SPRPRICE;
	TFIBWideStringField *TableNAME_SPRTYPE_PRICE;
	TFIBBCDField *ElementID_SPRPRICE;
	TFIBBCDField *ElementIDBASE_SPRPRICE;
	TFIBWideStringField *ElementGID_SPRPRICE;
	TFIBBCDField *ElementIDPRNOM_SPRPRICE;
	TFIBBCDField *ElementIDPRTPRICE_SPRPRICE;
	TFIBBCDField *ElementVALUE_SPRPRICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprProducerPrice(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс

		void OpenTable(__int64 id_producer_nom);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		int OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		__int64 FindElement(__int64 id_producer_type_price, __int64 id_producer_nom);

		__int64 IdProducerNom;
		__int64 IdProducerTypePrice;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProducerPrice *DMSprProducerPrice;
//---------------------------------------------------------------------------
#endif
