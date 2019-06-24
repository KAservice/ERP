//---------------------------------------------------------------------------

#ifndef UDMSprCodeTelH
#define UDMSprCodeTelH
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
class TDMSprCodeTel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *ElementID_CODETEL;
	TFIBLargeIntField *ElementIDNOM_CODETEL;
	TFIBWideStringField *ElementCODE_CODETEL;
	TFIBWideStringField *ElementGID_SCODETEL;
	TFIBWideStringField *ElementNAME_CODETEL;
	TFIBWideStringField *ElementCODOPER_CODETEL;
	TFIBLargeIntField *ElementIDNOMCOM_CODETEL;
	TFIBLargeIntField *ElementIDBASE_SCODETEL;
	TFIBBCDField *ElementPRCOMIS_SCODETEL;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementNAMENOMCOM;
	TFIBLargeIntField *TableID_CODETEL;
	TFIBLargeIntField *TableIDNOM_CODETEL;
	TFIBWideStringField *TableCODE_CODETEL;
	TFIBWideStringField *TableGID_SCODETEL;
	TFIBWideStringField *TableNAME_CODETEL;
	TFIBWideStringField *TableCODOPER_CODETEL;
	TFIBLargeIntField *TableIDNOMCOM_CODETEL;
	TFIBLargeIntField *TableIDBASE_SCODETEL;
	TFIBBCDField *TablePRCOMIS_SCODETEL;
	TFIBWideStringField *TableNAMENOM;
	TFIBIntegerField *TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
	TFIBLargeIntField *TableNOM_DEPARTMENT_ID_SDEPARTMENT;
	TFIBWideStringField *TableNAMENOMCOM;
	TFIBIntegerField *TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR;
	TFIBLargeIntField *TableCOM_DEPARTMENT_ID_SDEPARTMENT;
		void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprCodeTel(TComponent* Owner);
	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void DeleteElement(__int64 Id);

        bool Error;
        String TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCodeTel *DMSprCodeTel;
//---------------------------------------------------------------------------
#endif
