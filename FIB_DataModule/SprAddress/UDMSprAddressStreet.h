//---------------------------------------------------------------------------

#ifndef UDMSprAddressStreetH
#define UDMSprAddressStreetH
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
class TDMSprAddressStreet : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_SADR_STREET;
	TFIBLargeIntField *TableIDBASE_SADR_STREET;
	TFIBWideStringField *TableNAME_SADR_STREET;
	TFIBWideStringField *TablePOSTCODE_SADR_STREET;
	TFIBLargeIntField *TableIDNASPUNKT_SADR_STREET;
	TFIBLargeIntField *ElementID_SADR_STREET;
	TFIBLargeIntField *ElementIDBASE_SADR_STREET;
	TFIBWideStringField *ElementNAME_SADR_STREET;
	TFIBWideStringField *ElementPOSTCODE_SADR_STREET;
	TFIBLargeIntField *ElementIDNASPUNKT_SADR_STREET;
	TFIBLargeIntField *ElementID_SADR_NASPUNKT;
	TFIBLargeIntField *ElementIDBASE_SADR_NASPUNKT;
	TFIBLargeIntField *ElementIDRAYON_SADR_NASPUNKT;
	TFIBWideStringField *ElementNAME_SADR_NASPUNKT;
	TFIBIntegerField *ElementFL_GOROD_SADR_NASPUNKT;
	TFIBLargeIntField *ElementID_SADR_RAYON;
	TFIBLargeIntField *ElementIDBASE_SADR_RAYON;
	TFIBLargeIntField *ElementIDREGION_SADR_RAYON;
	TFIBWideStringField *ElementNAME_SADR_RAYON;
	TFIBLargeIntField *ElementID_SADR_REGION;
	TFIBLargeIntField *ElementIDBASE_SADR_REGION;
	TFIBWideStringField *ElementNAME_SADR_REGION;
	TFIBWideStringField *ElementCODE_SADR_REGION;
        void __fastcall DataModuleDestroy(TObject *Sender);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprAddressStreet(TComponent* Owner);

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

		void OpenTable(__int64 id_owner);
		bool NewElement(__int64 id_owner);

		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprAddressStreet *DMSprAddressStreet;
//---------------------------------------------------------------------------
#endif
