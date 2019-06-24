//---------------------------------------------------------------------------

#ifndef UREM_DMSprModelInfBlockH
#define UREM_DMSprModelInfBlockH
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
class TREM_DMSprModelInfBlock : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SMODEL_INF;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL_INF;
	TFIBWideStringField *TableGID_REM_SMODEL_INF;
	TFIBLargeIntField *TableIDMODEL_REM_SMODEL_INF;
	TFIBLargeIntField *TableIDIB_REM_SMODEL_INF;
	TFIBDateTimeField *TableISM_REM_SMODEL_INF;
	TFIBWideStringField *TableNAME_ART_IB;
	TFIBWideStringField *TableDESCR_ART_IB;
	TFIBLargeIntField *ElementID_REM_SMODEL_INF;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL_INF;
	TFIBWideStringField *ElementGID_REM_SMODEL_INF;
	TFIBLargeIntField *ElementIDMODEL_REM_SMODEL_INF;
	TFIBLargeIntField *ElementIDIB_REM_SMODEL_INF;
	TFIBDateTimeField *ElementISM_REM_SMODEL_INF;
	TFIBWideStringField *ElementNAME_ART_IB;
	TFIBWideStringField *ElementDESCR_ART_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprModelInfBlock(TComponent* Owner);

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
extern PACKAGE TREM_DMSprModelInfBlock *REM_DMSprModelInfBlock;
//---------------------------------------------------------------------------
#endif
