//---------------------------------------------------------------------------

#ifndef UART_DMSprInfBlockH
#define UART_DMSprInfBlockH
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
class TART_DMSprInfBlock : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_ART_IB;
	TFIBLargeIntField *TableIDBASE_ART_IB;
	TFIBDateTimeField *TablePOS_ISM_ART_IB;
	TFIBWideStringField *TableGUID_ART_IB;
	TFIBLargeIntField *TableIDGRP_ART_IB;
	TFIBWideStringField *TableGUIDGRP_ART_IB;
	TFIBWideStringField *TableNAME_ART_IB;
	TFIBWideStringField *TableKEYWORDS_ART_IB;
	TFIBWideStringField *TableTITLE_ART_IB;
	TFIBWideStringField *TableDESCR_ART_IB;
	TFIBIntegerField *TableINDEX_ART_IB;
	TFIBLargeIntField *ElementID_ART_IB;
	TFIBLargeIntField *ElementIDBASE_ART_IB;
	TFIBDateTimeField *ElementPOS_ISM_ART_IB;
	TFIBWideStringField *ElementGUID_ART_IB;
	TFIBLargeIntField *ElementIDGRP_ART_IB;
	TFIBWideStringField *ElementGUIDGRP_ART_IB;
	TFIBWideStringField *ElementNAME_ART_IB;
	TFIBWideStringField *ElementKEYWORDS_ART_IB;
	TFIBWideStringField *ElementTITLE_ART_IB;
	TFIBWideStringField *ElementDESCR_ART_IB;
	TFIBIntegerField *ElementINDEX_ART_IB;
	TFIBWideStringField *ElementWEB_KEYWORDS_ART_IB;
	TFIBWideStringField *ElementWEB_TITLE_ART_IB;
	TFIBWideStringField *ElementWEB_DESCR_ART_IB;
	TFIBWideStringField *TableWEB_KEYWORDS_ART_IB;
	TFIBWideStringField *TableWEB_TITLE_ART_IB;
	TFIBWideStringField *TableWEB_DESCR_ART_IB;
	TFIBSmallIntField *ElementFL_ADD_SITEMAP_ART_IB;
	TFIBSmallIntField *TableFL_ADD_SITEMAP_ART_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TART_DMSprInfBlock(TComponent* Owner);

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
extern PACKAGE TART_DMSprInfBlock *ART_DMSprInfBlock;
//---------------------------------------------------------------------------
#endif
