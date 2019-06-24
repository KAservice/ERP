//---------------------------------------------------------------------------

#ifndef UDMSprGrpNomInetCatalogH
#define UDMSprGrpNomInetCatalogH
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
class TDMSprGrpNomInetCatalog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *ElementID_SNOMINETCAT_GRP;
	TFIBLargeIntField *ElementIDBASE_SNOMINETCAT_GRP;
	TFIBWideStringField *ElementGID_SNOMINETCAT_GRP;
	TFIBLargeIntField *ElementIDGRP_SNOMINETCAT_GRP;
	TFIBLargeIntField *ElementIDINETCAT_SNOMINETCAT_GRP;
	TFIBWideStringField *ElementNAME_SNOMINETCAT_GRP;
	TFIBLargeIntField *TableID_SNOMINETCAT_GRP;
	TFIBLargeIntField *TableIDBASE_SNOMINETCAT_GRP;
	TFIBWideStringField *TableGID_SNOMINETCAT_GRP;
	TFIBLargeIntField *TableIDGRP_SNOMINETCAT_GRP;
	TFIBLargeIntField *TableIDINETCAT_SNOMINETCAT_GRP;
	TFIBWideStringField *TableNAME_SNOMINETCAT_GRP;
	TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprGrpNomInetCatalog(TComponent* Owner);

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


		void OpenTable(__int64 id_inet_catalog);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_inet_catalog, __int64 id_grp);
		bool SaveElement(void);
		void DeleteElement(__int64 id);
		__int64 IdInetCatalog;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpNomInetCatalog *DMSprGrpNomInetCatalog;
//---------------------------------------------------------------------------
#endif
