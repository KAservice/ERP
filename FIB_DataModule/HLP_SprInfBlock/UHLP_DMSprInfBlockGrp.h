//---------------------------------------------------------------------------

#ifndef UHLP_DMSprInfBlockGrpH
#define UHLP_DMSprInfBlockGrpH
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
class THLP_DMSprInfBlockGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_HLP_IB_GRP;
	TFIBLargeIntField *TableIDBASE_HLP_IB_GRP;
	TFIBWideStringField *TableGUID_HLP_IB_GRP;
	TFIBWideStringField *TableNAME_HLP_IB_GRP;
	TFIBLargeIntField *TableIDGRP_HLP_IB_GRP;
	TFIBWideStringField *TableGUID_GRP_HLP_IB_GRP;
	TFIBDateTimeField *TablePOS_ISM_HLP_IB_GRP;
	TFIBIntegerField *TableINDEX_HLP_IB_GRP;
	TFIBLargeIntField *ElementID_HLP_IB_GRP;
	TFIBLargeIntField *ElementIDBASE_HLP_IB_GRP;
	TFIBWideStringField *ElementGUID_HLP_IB_GRP;
	TFIBWideStringField *ElementNAME_HLP_IB_GRP;
	TFIBLargeIntField *ElementIDGRP_HLP_IB_GRP;
	TFIBWideStringField *ElementGUID_GRP_HLP_IB_GRP;
	TFIBDateTimeField *ElementPOS_ISM_HLP_IB_GRP;
	TFIBIntegerField *ElementINDEX_HLP_IB_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall THLP_DMSprInfBlockGrp(TComponent* Owner);

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
extern PACKAGE THLP_DMSprInfBlockGrp *HLP_DMSprInfBlockGrp;
//---------------------------------------------------------------------------
#endif
