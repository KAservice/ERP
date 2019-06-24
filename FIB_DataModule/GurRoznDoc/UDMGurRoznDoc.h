//---------------------------------------------------------------------------

#ifndef UDMGurRoznDocH
#define UDMGurRoznDocH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMGurRoznDoc : public TDataModule
{
__published:	// IDE-managed Components
		TDataSource *DataSourceTable;
	TpFIBDataSet *IBQ;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBDateTimeField *TablePOSDOC;
	TFIBSmallIntField *TablePRDOC;
	TFIBIntegerField *TableNUMDOC;
	TFIBBCDField *TableSUMDOC;
	TFIBBCDField *TableIDDOC;
	TFIBBCDField *TableIDFIRMDOC;
	TFIBBCDField *TableIDSKLDOC;
	TFIBBCDField *TableIDKLDOC;
	TFIBBCDField *TableIDDOGDOC;
	TFIBBCDField *TableIDUSERDOC;
	TFIBBCDField *TableIDDOCOSNDOC;
	TFIBBCDField *TableIDEXTDOC;
	TFIBIntegerField *TableTYPEEXTDOC;
	TpFIBQuery *Query;
	TFIBBCDField *TableIDBASE_GALLDOC;
	TFIBWideStringField *TableTDOC;
	TFIBWideStringField *TableGID_DOC;
	TFIBWideStringField *TablePREFIKSDOC;
	TFIBBCDField *TableIDPROJECT_GALLDOC;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMGurRoznDoc(TComponent* Owner);

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

		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
		UnicodeString   StringTypeDoc;
        UnicodeString   StringFullTypeDoc;

        bool OtborVkl;
        bool OtborPoKlient ;
		bool OtborPoFirm;
        bool OtborPoSklad;
        bool OtborPoTypeDoc;

        TDateTime PosNach;
        TDateTime PosCon;
		int FindDocPoIdDog(__int64 iddogovor);

        __int64 IdBase;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurRoznDoc *DMGurRoznDoc;
//---------------------------------------------------------------------------
#endif
