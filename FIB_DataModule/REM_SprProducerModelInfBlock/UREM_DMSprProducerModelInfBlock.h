//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerModelInfBlockH
#define UREM_DMSprProducerModelInfBlockH
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
class TREM_DMSprProducerModelInfBlock : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SPRMODEL_INF;
	TFIBLargeIntField *TableIDBASE_REM_SPRMODEL_INF;
	TFIBWideStringField *TableGID_REM_SPRMODEL_INF;
	TFIBLargeIntField *TableIDPRMODEL_REM_SPRMODEL_INF;
	TFIBLargeIntField *TableIDIB_REM_SPRMODEL_INF;
	TFIBDateTimeField *TableISM_REM_SPRMODEL_INF;
	TFIBWideStringField *TableNAME_ART_IB;
	TFIBWideStringField *TableDESCR_ART_IB;
	TFIBLargeIntField *ElementID_REM_SPRMODEL_INF;
	TFIBLargeIntField *ElementIDBASE_REM_SPRMODEL_INF;
	TFIBWideStringField *ElementGID_REM_SPRMODEL_INF;
	TFIBLargeIntField *ElementIDPRMODEL_REM_SPRMODEL_INF;
	TFIBLargeIntField *ElementIDIB_REM_SPRMODEL_INF;
	TFIBDateTimeField *ElementISM_REM_SPRMODEL_INF;
	TFIBWideStringField *ElementNAME_ART_IB;
	TFIBWideStringField *ElementDESCR_ART_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerModelInfBlock(TComponent* Owner);

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
extern PACKAGE TREM_DMSprProducerModelInfBlock *REM_DMSprProducerModelInfBlock;
//---------------------------------------------------------------------------
#endif
