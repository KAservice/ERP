//---------------------------------------------------------------------------

#ifndef UHLP_DMSprInfBlockSostavH
#define UHLP_DMSprInfBlockSostavH
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
class THLP_DMSprInfBlockSostav : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_HLP_IB_S;
	TFIBLargeIntField *TableIDBASE_HLP_IB_S;
	TFIBWideStringField *TableGUID_HLP_IB_S;
	TFIBDateTimeField *TablePOS_ISM_HLP_IB_S;
	TFIBLargeIntField *TableIDIB_HLP_IB_S;
	TFIBSmallIntField *TableTYPE_HLP_IB_S;
	TFIBWideStringField *TableTEXT_HLP_IB_S;
	TFIBLargeIntField *TableIDIMG_HLP_IB_S;
	TFIBIntegerField *TableINDEX_HLP_IB_S;
	TFIBIntegerField *TableH_ALIGN_HLP_IB_S;
	TFIBIntegerField *TableV_ALIGN_HLP_IB_S;
	TFIBIntegerField *TableTYPE_TEXT_HLP_IB_S;
	TFIBIntegerField *TableFONT_SIZE_HLP_IB_S;
	TFIBWideStringField *TableNAME_HLP_IMG;
	TFIBLargeIntField *ElementID_HLP_IB_S;
	TFIBLargeIntField *ElementIDBASE_HLP_IB_S;
	TFIBWideStringField *ElementGUID_HLP_IB_S;
	TFIBDateTimeField *ElementPOS_ISM_HLP_IB_S;
	TFIBLargeIntField *ElementIDIB_HLP_IB_S;
	TFIBSmallIntField *ElementTYPE_HLP_IB_S;
	TFIBWideStringField *ElementTEXT_HLP_IB_S;
	TFIBLargeIntField *ElementIDIMG_HLP_IB_S;
	TFIBIntegerField *ElementINDEX_HLP_IB_S;
	TFIBIntegerField *ElementH_ALIGN_HLP_IB_S;
	TFIBIntegerField *ElementV_ALIGN_HLP_IB_S;
	TFIBIntegerField *ElementTYPE_TEXT_HLP_IB_S;
	TFIBIntegerField *ElementFONT_SIZE_HLP_IB_S;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THLP_DMSprInfBlockSostav(TComponent* Owner);

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


		__int64 IdIB;
		__int64 IdElement;

		void OpenTable(__int64 id_ib);
		bool SaveIsmen(void);
		bool CancelIsmen(void);
		bool TableAppend(__int64 id_ib);
		bool TableDelete(void);

		bool NewElement(__int64 id_ib);
		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprInfBlockSostav *HLP_DMSprInfBlockSostav;
//---------------------------------------------------------------------------
#endif
