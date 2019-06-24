//---------------------------------------------------------------------------

#ifndef UDMGurDocCheckKKM2H
#define UDMGurDocCheckKKM2H
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
//---------------------------------------------------------------------------
class TDMGurDocCheckKKM2 : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Table;
	TFIBIntegerField *TableNUMDOC;
	TFIBDateTimeField *TablePOSDOC;
	TFIBSmallIntField *TablePRDOC;
	TFIBBCDField *TableSUMDOC;
	TFIBBCDField *TableIDDOC;
	TFIBIntegerField *TableNCHECKCHK;
	TFIBIntegerField *TableNKLCHK;
	TFIBIntegerField *TableOPERCHK;
	TFIBWideStringField *TableNAMEKKM;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMGurDocCheckKKM2(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);


        bool OpenTable(void);
        void UpdateTable(void);
		__int64 IdDoc;
        TDateTime PosNach;
        TDateTime PosCon;

        __int64 IdKKM;
        int NumberKL;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurDocCheckKKM2 *DMGurDocCheckKKM2;
//---------------------------------------------------------------------------
#endif
