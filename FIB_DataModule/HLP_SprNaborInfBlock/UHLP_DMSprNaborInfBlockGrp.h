//---------------------------------------------------------------------------

#ifndef UHLP_DMSprNaborInfBlockGrpH
#define UHLP_DMSprNaborInfBlockGrpH
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
class THLP_DMSprNaborInfBlockGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_HLP_N_IB_GRP;
	TFIBLargeIntField *TableIDBASE_HLP_N_IB_GRP;
	TFIBWideStringField *TableGUID_HLP_N_IB_GRP;
	TFIBDateTimeField *TablePOS_ISM_HLP_N_IB_GRP;
	TFIBLargeIntField *TableIDGRP_HLP_N_IB_GRP;
	TFIBWideStringField *TableNAME_HLP_N_IB_GRP;
	TFIBIntegerField *TableINDEX_HLP_N_IB_GRP;
	TFIBLargeIntField *ElementID_HLP_N_IB_GRP;
	TFIBLargeIntField *ElementIDBASE_HLP_N_IB_GRP;
	TFIBWideStringField *ElementGUID_HLP_N_IB_GRP;
	TFIBDateTimeField *ElementPOS_ISM_HLP_N_IB_GRP;
	TFIBLargeIntField *ElementIDGRP_HLP_N_IB_GRP;
	TFIBWideStringField *ElementNAME_HLP_N_IB_GRP;
	TFIBIntegerField *ElementINDEX_HLP_N_IB_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall THLP_DMSprNaborInfBlockGrp(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
		__int64 IdGroupElement;
		__int64 IdGrp;
		__int64 IdElement;
		bool AllElement;


		bool OpenTable(void);
		bool OpenElement(__int64 id);
		bool NewElement( __int64 id_grp);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprNaborInfBlockGrp *HLP_DMSprNaborInfBlockGrp;
//---------------------------------------------------------------------------
#endif
