//---------------------------------------------------------------------------

#ifndef UDMSprNomFindH
#define UDMSprNomFindH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TDMSprNomFind : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *SpTPrice;
	TFIBLargeIntField *TableIDNOM;
	TFIBWideStringField *TableARTNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBSmallIntField *TableTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBLargeIntField *TableIDGRPNOM;
	TFIBBCDField *TableSUMKOL;
	TDataSource *DataSourceTPrice;
	TFIBLargeIntField *SpTPriceID_TPRICE;
	TFIBWideStringField *SpTPriceNAME_TPRICE;
	TFIBWideStringField *TableNAMEGN;
	TFIBWideStringField *TableSHED;
	TFIBBCDField *TableREM_OST;
		void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMSprNomFind(TComponent* Owner);

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

		bool SetTextQuery(UnicodeString text);
		bool SetIntegerParam(UnicodeString name_param, int value_param);
		bool SetInt64Param(UnicodeString name_param, __int64 value_param);
		bool SetStringParam(UnicodeString name_param, UnicodeString value_param);
		bool OpenTableResult(void);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 IdFirm;
		__int64 IdSklad;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomFind *DMSprNomFind;
//---------------------------------------------------------------------------
#endif
