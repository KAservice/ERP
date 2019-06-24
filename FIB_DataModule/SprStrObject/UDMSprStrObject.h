//---------------------------------------------------------------------------

#ifndef UDMSprStrObjectH
#define UDMSprStrObjectH
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
class TDMSprStrObject : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBDataSet *Code;
	TFIBIntegerField *CodeMAXCODE;
	TFIBBCDField *TableID_STROB;
	TFIBBCDField *TableIDGRP_STROB;
	TFIBSmallIntField *TableGRP_STROB;
	TFIBBCDField *ElementID_STROB;
	TFIBBCDField *ElementIDGRP_STROB;
	TFIBSmallIntField *ElementGRP_STROB;
	TFIBWideStringField *TableNAME_STROB;
	TFIBIntegerField *TableCODE_STROB;
	TFIBWideStringField *TableGID_SSTROB;
	TFIBWideStringField *ElementNAME_STROB;
	TFIBIntegerField *ElementCODE_STROB;
	TFIBWideStringField *ElementGID_SSTROB;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprStrObject(TComponent* Owner);



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
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

        void OpenTable(void);
		int OpenElement(__int64 Id);
		void NewElement(__int64 IdGrp);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);
        __int64 Id;

		__int64 FindPoCodu(int code);
        bool Error;
        AnsiString TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprStrObject *DMSprStrObject;
//---------------------------------------------------------------------------
#endif
