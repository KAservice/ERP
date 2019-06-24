//---------------------------------------------------------------------------

#ifndef UDMSprGrpKlientH
#define UDMSprGrpKlientH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------
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
class TDMSprGrpKlient : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDGRPKL;
	TFIBBCDField *TableGRPKL;
	TFIBBCDField *ElementIDGRPKL;
	TFIBBCDField *ElementGRPKL;
	TFIBWideStringField *TableNAMEGRPKL;
	TFIBWideStringField *TableGID_SGRPKL;
	TFIBWideStringField *ElementNAMEGRPKL;
	TFIBWideStringField *ElementGID_SGRPKL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprGrpKlient(TComponent* Owner);
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


        bool OpenTable(void);
		int OpenElement(__int64 Id);
		void NewElement(__int64 IdGrp);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);
				bool Error;
		AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpKlient *DMSprGrpKlient;
//---------------------------------------------------------------------------
#endif
