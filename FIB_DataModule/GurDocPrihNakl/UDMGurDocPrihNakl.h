//---------------------------------------------------------------------------

#ifndef UDMGurDocPrihNaklH
#define UDMGurDocPrihNaklH
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
class TDMGurDocPrihNakl : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *TableNUMDOC;
	TFIBDateTimeField *TablePOSDOC;
	TFIBSmallIntField *TablePRDOC;
	TFIBBCDField *TableSUMDOC;
	TFIBBCDField *TableIDDOC;
	TFIBBCDField *TableRSUM_DPRN;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TablePRIMDOC;
	TFIBWideStringField *TableNUMDOCPOST_DPRN;
	TFIBDateTimeField *TablePOSDOCPOST_DPRN;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMGurDocPrihNakl(TComponent* Owner);

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
		UnicodeString TextError;
		bool Init(void);
		int Done(void);

        void OpenTable();
        void UpdateTable(void);
        __int64 IdDoc;
        TDateTime PosNach;
        TDateTime PosCon;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurDocPrihNakl *DMGurDocPrihNakl;
//---------------------------------------------------------------------------
#endif
