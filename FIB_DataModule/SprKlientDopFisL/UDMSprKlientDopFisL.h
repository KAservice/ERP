//---------------------------------------------------------------------------

#ifndef UDMSprKlientDopFisLH
#define UDMSprKlientDopFisLH
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
class TDMSprKlientDopFisL : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *ElementPOL_SKLIENT_DOPFISL;
	TFIBBCDField *ElementID_SKLIENT_DOPFISL;
	TFIBBCDField *ElementIDKLIENT_SKLIENT_DOPFISL;
	TFIBDateField *ElementDATEROG_SKLIENT_DOPFISL;
	TFIBWideStringField *ElementMESTOROG_SKLIENT_DOPFISL;
	TFIBWideStringField *ElementDOLRAB_SKLIENT_DOPFISL;
	TFIBWideStringField *ElementMESTORAB_SKLIENT_DOPFISL;
	TFIBBCDField *ElementIDBASE_SKLIENT_DOPFISL;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementGID_SKLIENT_DOPFISL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
	void __fastcall ElementPOL_SKLIENT_DOPFISLGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall ElementPOL_SKLIENT_DOPFISLSetText(TField *Sender, const UnicodeString Text);

private:	// User declarations
public:		// User declarations
        __fastcall TDMSprKlientDopFisL(TComponent* Owner);

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

        int OpenElement(void);
        void NewElement(void);
        bool SaveElement(void);
        bool DeleteElement(void);

		__int64 Id;
        __int64 IdKlient;
        bool Error;
        String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprKlientDopFisL *DMSprKlientDopFisL;
//---------------------------------------------------------------------------
#endif
