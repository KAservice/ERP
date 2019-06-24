//---------------------------------------------------------------------------

#ifndef UDMSprNomInetCatalogH
#define UDMSprNomInetCatalogH
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
class TDMSprNomInetCatalog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_SNOMINETCAT;
	TFIBLargeIntField *TableIDBASE_SNOMINETCAT;
	TFIBWideStringField *TableGID_SNOMINETCAT;
	TFIBLargeIntField *TableIDINETCAT_SNOMINETCAT;
	TFIBLargeIntField *TableIDGRP_SNOMINETCAT;
	TFIBLargeIntField *TableIDNOM_SNOMINETCAT;
	TFIBWideStringField *TableNAMENOM;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBWideStringField *TableNAMEED;
	TFIBLargeIntField *ElementID_SNOMINETCAT;
	TFIBLargeIntField *ElementIDBASE_SNOMINETCAT;
	TFIBWideStringField *ElementGID_SNOMINETCAT;
	TFIBLargeIntField *ElementIDINETCAT_SNOMINETCAT;
	TFIBLargeIntField *ElementIDGRP_SNOMINETCAT;
	TFIBLargeIntField *ElementIDNOM_SNOMINETCAT;
	TIntegerField *TableRECNO;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBWideStringField *TableSHED;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprNomInetCatalog(TComponent* Owner);

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


		__int64 IdInetCatalog;
		__int64 IdGrp;
		bool AllElement;
		__int64 IdTypePrice;

		void OpenTable(__int64 id_inet_catalog, __int64 id_grp,bool all);
		void NewElement(__int64 id_inet_catalog, __int64 id_grp);
		bool OpenElement(__int64 id);
		void InsertElement(__int64 id_inet_catalog, __int64 id_grp, __int64 id_nom);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();
		void ChancheGrp(__int64 id_new_grp);



		bool FindPoInetCatalogAndNom(__int64 id_inet_catalog, __int64 id_nom);

		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomInetCatalog *DMSprNomInetCatalog;
//---------------------------------------------------------------------------
#endif
