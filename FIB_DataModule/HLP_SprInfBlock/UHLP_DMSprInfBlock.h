//---------------------------------------------------------------------------

#ifndef UHLP_DMSprInfBlockH
#define UHLP_DMSprInfBlockH
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
class THLP_DMSprInfBlock : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_HLP_IB;
	TFIBLargeIntField *TableIDBASE_HLP_IB;
	TFIBDateTimeField *TablePOS_ISM_HLP_IB;
	TFIBWideStringField *TableGUID_HLP_IB;
	TFIBLargeIntField *TableIDGRP_HLP_IB;
	TFIBWideStringField *TableGUIDGRP_HLP_IB;
	TFIBWideStringField *TableNAME_HLP_IB;
	TFIBWideStringField *TableKEYWORDS_HLP_IB;
	TFIBWideStringField *TableTITLE_HLP_IB;
	TFIBWideStringField *TableDESCR_HLP_IB;
	TFIBIntegerField *TableINDEX_HLP_IB;
	TFIBWideStringField *TableWEB_KEYWORDS_HLP_IB;
	TFIBWideStringField *TableWEB_TITLE_HLP_IB;
	TFIBWideStringField *TableWEB_DESCR_HLP_IB;
	TFIBLargeIntField *ElementID_HLP_IB;
	TFIBLargeIntField *ElementIDBASE_HLP_IB;
	TFIBDateTimeField *ElementPOS_ISM_HLP_IB;
	TFIBWideStringField *ElementGUID_HLP_IB;
	TFIBLargeIntField *ElementIDGRP_HLP_IB;
	TFIBWideStringField *ElementGUIDGRP_HLP_IB;
	TFIBWideStringField *ElementNAME_HLP_IB;
	TFIBWideStringField *ElementKEYWORDS_HLP_IB;
	TFIBWideStringField *ElementTITLE_HLP_IB;
	TFIBWideStringField *ElementDESCR_HLP_IB;
	TFIBIntegerField *ElementINDEX_HLP_IB;
	TFIBWideStringField *ElementWEB_KEYWORDS_HLP_IB;
	TFIBWideStringField *ElementWEB_TITLE_HLP_IB;
	TFIBWideStringField *ElementWEB_DESCR_HLP_IB;
	TFIBWideStringField *TableGUID_PROG_MODULE_HLP_IB;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TableMODULE_PROGRAM_MODULE;
	TFIBWideStringField *TableDESCR_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBWideStringField *ElementGUID_PROG_MODULE_HLP_IB;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementMODULE_PROGRAM_MODULE;
	TFIBWideStringField *ElementDESCR_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
	TFIBSmallIntField *TableFL_ADD_SITEMAP_HLP_IB;
	TFIBSmallIntField *ElementFL_ADD_SITEMAP_HLP_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall THLP_DMSprInfBlock(TComponent* Owner);

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
		__int64 GetIdPoGuidProgModule(UnicodeString guid_str);

};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprInfBlock *HLP_DMSprInfBlock;
//---------------------------------------------------------------------------
#endif
