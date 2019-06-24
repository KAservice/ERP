//---------------------------------------------------------------------------

#ifndef UDMGurDocCheckKKMH
#define UDMGurDocCheckKKMH
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
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
class TDMGurDocCheckKKM : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *TableNUMDOC;
	TFIBDateTimeField *TablePOSDOC;
	TFIBSmallIntField *TablePRDOC;
	TFIBBCDField *TableSUMDOC;
	TFIBLargeIntField *TableIDDOC;
	TFIBIntegerField *TableNCHECKCHK;
	TFIBIntegerField *TableNKLCHK;
	TFIBIntegerField *TableOPERCHK;
	TFIBWideStringField *TableNAMEKKM;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBBCDField *TableOPLNALCHK;
	TFIBBCDField *TableOPLPCCHK;
	TFIBBCDField *TableOPLPLATCARD_ALL_DCHK;
	TFIBBCDField *TableOPLCREDITCARD_ALL_DCHK;
	TFIBBCDField *TableOPL_OTHER_DCHK;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMGurDocCheckKKM(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);


        void OpenTable();
        void UpdateTable(void);
		__int64 IdDoc;
        TDateTime PosNach;
        TDateTime PosCon;

        __int64 IdKKM;
        int NumberKL;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurDocCheckKKM *DMGurDocCheckKKM;
//---------------------------------------------------------------------------
#endif
