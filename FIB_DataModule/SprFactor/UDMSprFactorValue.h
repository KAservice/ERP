//---------------------------------------------------------------------------

#ifndef UDMSprFactorValueH
#define UDMSprFactorValueH
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
class TDMSprFactorValue : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TpFIBDataSet *FactorList;
	TDataSource *DataSourceFactorList;
	TFIBLargeIntField *FactorListID_SFACTOR;
	TFIBWideStringField *FactorListNAME_SFACTOR;
	TFIBLargeIntField *TableID_SFACTOR_VAL;
	TFIBWideStringField *TableGID_SFACTOR_VAL;
	TFIBLargeIntField *TableIDBASE_SFACTOR_VAL;
	TFIBLargeIntField *TableIDPRODUCE_SFACTOR_VAL;
	TFIBLargeIntField *TableIDFACTOR_SFACTOR_VAL;
	TFIBBCDField *TableVALUE_SFACTOR_VAL;
	TFIBLargeIntField *ElementID_SFACTOR_VAL;
	TFIBWideStringField *ElementGID_SFACTOR_VAL;
	TFIBLargeIntField *ElementIDBASE_SFACTOR_VAL;
	TFIBLargeIntField *ElementIDPRODUCE_SFACTOR_VAL;
	TFIBLargeIntField *ElementIDFACTOR_SFACTOR_VAL;
	TFIBBCDField *ElementVALUE_SFACTOR_VAL;
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprFactorValue(TComponent* Owner);

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



		bool OpenTable(__int64 id_produce);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		bool OpenElement(__int64 Id);
		bool NewElement(void);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);

		__int64 FindElement(__int64 id_factor, __int64 id_produce);

		__int64 IdFactor;
		__int64 IdProduce;

		bool UpdateSpisokFactors(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprFactorValue *DMSprFactorValue;
//---------------------------------------------------------------------------
#endif
