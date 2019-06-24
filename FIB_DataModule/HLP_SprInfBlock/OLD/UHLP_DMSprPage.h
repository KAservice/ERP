//---------------------------------------------------------------------------

#ifndef UHLP_DMSprPageH
#define UHLP_DMSprPageH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class THLP_DMSprPage : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_HLP_PAGE;
	TFIBLargeIntField *TableIDBASE_HLP_PAGE;
	TFIBWideStringField *TableGID_HLP_PAGE;
	TFIBLargeIntField *TableIDGRP_HLP_PAGE;
	TFIBWideStringField *TableNAME_HLP_PAGE;
	TFIBWideStringField *TableKEYWORDS_HLP_PAGE;
	TFIBWideStringField *TableTITLE_HLP_PAGE;
	TFIBWideStringField *TableDESCR_HLP_PAGE;
	TFIBIntegerField *TableINDEX_HLP_PAGE;
	TFIBWideStringField *TableWEBKEYWORDS_HLP_PAGE;
	TFIBWideStringField *TableWEBTITLE_HLP_PAGE;
	TFIBWideStringField *TableWEBDESCR_HLP_PAGE;
	TFIBWideStringField *TableGUIDGRP_HLP_PAGE;
	TFIBWideStringField *TableSTRCODE_HLP_PAGE;
	TFIBWideStringField *TableGUID_HLP_PAGE;
	TFIBLargeIntField *ElementID_HLP_PAGE;
	TFIBLargeIntField *ElementIDBASE_HLP_PAGE;
	TFIBWideStringField *ElementGID_HLP_PAGE;
	TFIBLargeIntField *ElementIDGRP_HLP_PAGE;
	TFIBWideStringField *ElementNAME_HLP_PAGE;
	TFIBWideStringField *ElementKEYWORDS_HLP_PAGE;
	TFIBWideStringField *ElementTITLE_HLP_PAGE;
	TFIBWideStringField *ElementDESCR_HLP_PAGE;
	TFIBIntegerField *ElementINDEX_HLP_PAGE;
	TFIBWideStringField *ElementWEBKEYWORDS_HLP_PAGE;
	TFIBWideStringField *ElementWEBTITLE_HLP_PAGE;
	TFIBWideStringField *ElementWEBDESCR_HLP_PAGE;
	TFIBWideStringField *ElementGUIDGRP_HLP_PAGE;
	TFIBWideStringField *ElementSTRCODE_HLP_PAGE;
	TFIBWideStringField *ElementGUID_HLP_PAGE;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall THLP_DMSprPage(TComponent* Owner);

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

		bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

		//поиск
		__int64 FindPoName(UnicodeString name);


		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprPage *HLP_DMSprPage;
//---------------------------------------------------------------------------
#endif
