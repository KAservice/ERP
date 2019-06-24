//---------------------------------------------------------------------------

#ifndef UDMGurAllDocH
#define UDMGurAllDocH
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
class TDMGurAllDoc : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TFIBSmallIntField *TablePRDOC;
	TFIBIntegerField *TableNUMDOC;
	TFIBBCDField *TableSUMDOC;
	TpFIBDataSet *IBQ;
	TFIBDateTimeField *TablePOSDOC;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDDOC;
	TFIBBCDField *TableIDFIRMDOC;
	TFIBBCDField *TableIDSKLDOC;
	TFIBBCDField *TableIDKLDOC;
	TFIBBCDField *TableIDDOGDOC;
	TFIBBCDField *TableIDUSERDOC;
	TFIBBCDField *TableIDDOCOSNDOC;
	TFIBBCDField *TableIDEXTDOC;
	TFIBBCDField *TableIDBASE_GALLDOC;
	TFIBBCDField *TableIDPROJECT_GALLDOC;
	TFIBWideStringField *TableTDOC;
	TFIBWideStringField *TableGID_DOC;
	TFIBWideStringField *TablePREFIKSDOC;
	TFIBIntegerField *TableTYPEEXTDOC;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_SPROJECT;
	TFIBWideStringField *TablePREFIKS_NUM_GALLDOC;
	TFIBBCDField *TableIDBUSINOP_GALLDOC;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableSUMDOCGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall TableTDOCGetText(TField *Sender, UnicodeString &Text, bool DisplayText);

private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TDMGurAllDoc(TComponent* Owner);

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


		TDateTime PosNach;
		TDateTime PosCon;
		__int64 IdDoc;
		__int64 IdKlient;
		__int64 IdSklad;
		__int64 IdFirm;
		UnicodeString   StringTypeDoc;
		bool OtborVkl;
		bool NoCheck;

        void OpenTable();
		void UpdateTable(void);
		__int64 FindDocPoIdDog(__int64 iddogovor);
		bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc);
		bool DvRegDoc(AnsiString type_doc, __int64 id_doc);

        void AllCancelDvRegDoc(void);
		void AllDvRegDoc(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurAllDoc *DMGurAllDoc;
//---------------------------------------------------------------------------
#endif
