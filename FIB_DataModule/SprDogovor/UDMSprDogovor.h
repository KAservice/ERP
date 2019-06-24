//---------------------------------------------------------------------------

#ifndef UDMSprDogovorH
#define UDMSprDogovorH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
//---------------------------------------------------------------------------
class TDMSprDogovor : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateField *TableDO_SDOG;
	TFIBIntegerField *TableWAYPAY_SDOG;
	TFIBBCDField *TableMAXSUMCREDIT_SDOG;
	TFIBIntegerField *TableSROK_SDOG;
	TFIBDateField *TableDATE_SDOG;
	TIntegerField *TableRECNO;
	TFIBDateField *ElementDO_SDOG;
	TFIBIntegerField *ElementWAYPAY_SDOG;
	TFIBBCDField *ElementMAXSUMCREDIT_SDOG;
	TFIBIntegerField *ElementSROK_SDOG;
	TFIBDateField *ElementDATE_SDOG;
	TFIBBCDField *TableID_SDOG;
	TFIBBCDField *TableIDKLIENT_SDOG;
	TFIBBCDField *TableIDTPRICE_SDOG;
	TFIBBCDField *ElementID_SDOG;
	TFIBBCDField *ElementIDKLIENT_SDOG;
	TFIBBCDField *ElementIDTPRICE_SDOG;
	TFIBWideStringField *TableNAME_SDOG;
	TFIBWideStringField *TableGID_SDOG;
	TFIBWideStringField *TableNUMBER_SDOG;
	TFIBWideStringField *ElementNAME_SDOG;
	TFIBWideStringField *ElementGID_SDOG;
	TFIBWideStringField *ElementNUMBER_SDOG;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprDogovor(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		void OpenTable(__int64 IdKl);
		int OpenElement(__int64 Id);  //возвращает количество элементов
		void NewElement(__int64 IdKl);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        __int64 IdKlient;
        bool Error;
        String TextError;

        bool flSaveElement;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprDogovor *DMSprDogovor;
//---------------------------------------------------------------------------
#endif
