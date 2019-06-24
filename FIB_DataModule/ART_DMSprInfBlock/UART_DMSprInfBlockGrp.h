//---------------------------------------------------------------------------

#ifndef UART_DMSprInfBlockGrpH
#define UART_DMSprInfBlockGrpH
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
class TART_DMSprInfBlockGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_ART_IB_GRP;
	TFIBLargeIntField *TableIDBASE_ART_IB_GRP;
	TFIBWideStringField *TableGUID_ART_IB_GRP;
	TFIBWideStringField *TableNAME_ART_IB_GRP;
	TFIBLargeIntField *TableIDGRP_ART_IB_GRP;
	TFIBWideStringField *TableGUID_GRP_ART_IB_GRP;
	TFIBDateTimeField *TablePOS_ISM_ART_IB_GRP;
	TFIBLargeIntField *ElementID_ART_IB_GRP;
	TFIBLargeIntField *ElementIDBASE_ART_IB_GRP;
	TFIBWideStringField *ElementGUID_ART_IB_GRP;
	TFIBWideStringField *ElementNAME_ART_IB_GRP;
	TFIBLargeIntField *ElementIDGRP_ART_IB_GRP;
	TFIBWideStringField *ElementGUID_GRP_ART_IB_GRP;
	TFIBDateTimeField *ElementPOS_ISM_ART_IB_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TART_DMSprInfBlockGrp(TComponent* Owner);

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


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TART_DMSprInfBlockGrp *ART_DMSprInfBlockGrp;
//---------------------------------------------------------------------------
#endif
