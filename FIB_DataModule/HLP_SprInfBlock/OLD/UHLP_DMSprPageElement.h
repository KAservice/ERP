//---------------------------------------------------------------------------

#ifndef UHLP_DMSprPageElementH
#define UHLP_DMSprPageElementH
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
class THLP_DMSprPageElement : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *TableIDBASE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableGID_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableGUID_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *TableIDPAGE_HLP_PAGE_ELEMENT;
	TFIBSmallIntField *TableTYPE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableTEXT_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableGUIDPAGE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableGUIDIMAGE_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *ElementID_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *ElementIDBASE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *ElementGID_HLP_PAGE_ELEMENT;
	TFIBWideStringField *ElementGUID_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *ElementIDPAGE_HLP_PAGE_ELEMENT;
	TFIBSmallIntField *ElementTYPE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *ElementTEXT_HLP_PAGE_ELEMENT;
	TFIBWideStringField *ElementGUIDPAGE_HLP_PAGE_ELEMENT;
	TFIBWideStringField *ElementGUIDIMAGE_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *TableIDIMAGE_HLP_PAGE_ELEMENT;
	TFIBIntegerField *TableINDEX_HLP_PAGE_ELEMENT;
	TFIBLargeIntField *ElementIDIMAGE_HLP_PAGE_ELEMENT;
	TFIBSmallIntField *ElementTYPE_TBL_HLP_PAGE_ELEMENT;
	TFIBIntegerField *ElementINDEX_HLP_PAGE_ELEMENT;
	TFIBWideStringField *TableNAME_HLP_IMAGE;
	TFIBBlobField *TableIMAGE_HLP_IMAGE;
	TFIBSmallIntField *TableTYPE_HLP_IMAGE;
	TFIBIntegerField *TableH_ALIGN_HLP_PAGE_ELEMENT;
	TFIBIntegerField *ElementH_ALIGN_HLP_PAGE_ELEMENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THLP_DMSprPageElement(TComponent* Owner);

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


		__int64 IdPage;
		__int64 IdElement;

		void OpenTable(__int64 id_page);
		bool SaveIsmen(void);
		bool CancelIsmen(void);
		bool TableAppend(__int64 id_page);
		bool TableDelete(void);

		bool NewElement(__int64 id_page);
		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprPageElement *HLP_DMSprPageElement;
//---------------------------------------------------------------------------
#endif
