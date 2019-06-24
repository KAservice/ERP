//---------------------------------------------------------------------------

#ifndef UDMSprLossFactorValueH
#define UDMSprLossFactorValueH
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
class TDMSprLossFactorValue : public TDataModule
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
	TFIBLargeIntField *TableID_SLOSS_FACTOR_VAL;
	TFIBWideStringField *TableGID_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *TableIDBASE_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *TableIDFACTOR_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
	TFIBBCDField *TableVAL_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *ElementID_SLOSS_FACTOR_VAL;
	TFIBWideStringField *ElementGID_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *ElementIDBASE_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *ElementIDFACTOR_SLOSS_FACTOR_VAL;
	TFIBLargeIntField *ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL;
	TFIBBCDField *ElementVAL_SLOSS_FACTOR_VAL;
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterInsert(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprLossFactorValue(TComponent* Owner);

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



		bool OpenTable(__int64 id_loss_factor);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		bool OpenElement(__int64 id);
		bool NewElement(void);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 FindElement(__int64 id_factor, __int64 id_loss_factor);

		__int64 IdFactor;
		__int64 IdLossFactor;

		bool UpdateSpisokFactors(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprLossFactorValue *DMSprLossFactorValue;
//---------------------------------------------------------------------------
#endif
