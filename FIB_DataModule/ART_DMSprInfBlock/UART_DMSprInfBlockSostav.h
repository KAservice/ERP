//---------------------------------------------------------------------------

#ifndef UART_DMSprInfBlockSostavH
#define UART_DMSprInfBlockSostavH
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
class TART_DMSprInfBlockSostav : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_ART_IB_S;
	TFIBLargeIntField *TableIDBASE_ART_IB_S;
	TFIBWideStringField *TableGUID_ART_IB_S;
	TFIBDateTimeField *TablePOS_ISM_ART_IB_S;
	TFIBLargeIntField *TableIDIB_ART_IB_S;
	TFIBSmallIntField *TableTYPE_ART_IB_S;
	TFIBWideStringField *TableTEXT_ART_IB_S;
	TFIBLargeIntField *TableIDIMG_ART_IB_S;
	TFIBIntegerField *TableINDEX_ART_IB_S;
	TFIBIntegerField *TableH_ALIGN_ART_IB_S;
	TFIBWideStringField *TableNAME_ART_IMG;
	TFIBLargeIntField *ElementID_ART_IB_S;
	TFIBLargeIntField *ElementIDBASE_ART_IB_S;
	TFIBWideStringField *ElementGUID_ART_IB_S;
	TFIBDateTimeField *ElementPOS_ISM_ART_IB_S;
	TFIBLargeIntField *ElementIDIB_ART_IB_S;
	TFIBSmallIntField *ElementTYPE_ART_IB_S;
	TFIBWideStringField *ElementTEXT_ART_IB_S;
	TFIBLargeIntField *ElementIDIMG_ART_IB_S;
	TFIBIntegerField *ElementINDEX_ART_IB_S;
	TFIBIntegerField *ElementH_ALIGN_ART_IB_S;
	TFIBIntegerField *ElementV_ALIGN_ART_IB_S;
	TFIBIntegerField *ElementTYPE_TEXT_ART_IB_S;
	TFIBIntegerField *TableV_ALIGN_ART_IB_S;
	TFIBIntegerField *TableTYPE_TEXT_ART_IB_S;
	TFIBIntegerField *TableFONT_SIZE_ART_IB_S;
	TFIBIntegerField *ElementFONT_SIZE_ART_IB_S;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TART_DMSprInfBlockSostav(TComponent* Owner);

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
extern PACKAGE TART_DMSprInfBlockSostav *ART_DMSprInfBlockSostav;
//---------------------------------------------------------------------------
#endif
