//---------------------------------------------------------------------------

#ifndef UART_DMSprInfBlockPrivH
#define UART_DMSprInfBlockPrivH
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
class TART_DMSprInfBlockPriv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBDataSet *GrpUser;
	TFIBLargeIntField *GrpUserID_SGRPUSER;
	TFIBWideStringField *GrpUserNAME_SGRPUSER;
	TFIBLargeIntField *TableID_ART_IB_PRIV;
	TFIBLargeIntField *TableIDBASE_ART_IB_PRIV;
	TFIBLargeIntField *TableIDIB_ART_IB_PRIV;
	TFIBLargeIntField *TableIDGRPUSER_ART_IB_PRIV;
	TFIBSmallIntField *TableSEL_ART_IB_PRIV;
	TFIBSmallIntField *TableINS_ART_IB_PRIV;
	TFIBSmallIntField *TableUPD_ART_IB_PRIV;
	TFIBSmallIntField *TableDEL_ART_IB_PRIV;
	TFIBWideStringField *TableNAME_SGRPUSER;
	TStringField *TableNAME_GRPUSER_LOOKUP;
	TFIBLargeIntField *ElementID_ART_IB_PRIV;
	TFIBLargeIntField *ElementIDBASE_ART_IB_PRIV;
	TFIBLargeIntField *ElementIDIB_ART_IB_PRIV;
	TFIBLargeIntField *ElementIDGRPUSER_ART_IB_PRIV;
	TFIBSmallIntField *ElementSEL_ART_IB_PRIV;
	TFIBSmallIntField *ElementINS_ART_IB_PRIV;
	TFIBSmallIntField *ElementUPD_ART_IB_PRIV;
	TFIBSmallIntField *ElementDEL_ART_IB_PRIV;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TART_DMSprInfBlockPriv(TComponent* Owner);

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
extern PACKAGE TART_DMSprInfBlockPriv *ART_DMSprInfBlockPriv;
//---------------------------------------------------------------------------
#endif
