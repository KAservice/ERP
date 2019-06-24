//---------------------------------------------------------------------------

#ifndef UDMSprAddressRegionH
#define UDMSprAddressRegionH
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
class TDMSprAddressRegion : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_SADR_REGION;
	TFIBLargeIntField *TableIDBASE_SADR_REGION;
	TFIBWideStringField *TableNAME_SADR_REGION;
	TFIBWideStringField *TableCODE_SADR_REGION;
	TFIBLargeIntField *ElementID_SADR_REGION;
	TFIBLargeIntField *ElementIDBASE_SADR_REGION;
	TFIBWideStringField *ElementNAME_SADR_REGION;
	TFIBWideStringField *ElementCODE_SADR_REGION;
        void __fastcall DataModuleDestroy(TObject *Sender);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprAddressRegion(TComponent* Owner);

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
        bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		__int64 IdOwner;
		__int64 IdElement;

		void OpenTable(void);
		bool NewElement(void);

		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprAddressRegion *DMSprAddressRegion;
//---------------------------------------------------------------------------
#endif
