//---------------------------------------------------------------------------

#ifndef UHLP_DMSprNaborInfBlockSostavH
#define UHLP_DMSprNaborInfBlockSostavH
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
class THLP_DMSprNaborInfBlockSostav : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_HLP_N_IB_S;
	TFIBLargeIntField *TableIDBASE_HLP_N_IB_S;
	TFIBWideStringField *TableGUID_HLP_N_IB_S;
	TFIBDateTimeField *TablePOS_ISM_HLP_N_IB_S;
	TFIBLargeIntField *TableIDGRP_HLP_N_IB_S;
	TFIBLargeIntField *TableIDNABOR_HLP_N_IB_S;
	TFIBLargeIntField *TableIDIB_HLP_N_IB_S;
	TFIBIntegerField *TableINDEX_HLP_N_IB_S;
	TFIBWideStringField *TableNAME_HLP_IB;
	TFIBLargeIntField *ElementID_HLP_N_IB_S;
	TFIBLargeIntField *ElementIDBASE_HLP_N_IB_S;
	TFIBWideStringField *ElementGUID_HLP_N_IB_S;
	TFIBDateTimeField *ElementPOS_ISM_HLP_N_IB_S;
	TFIBLargeIntField *ElementIDGRP_HLP_N_IB_S;
	TFIBLargeIntField *ElementIDNABOR_HLP_N_IB_S;
	TFIBLargeIntField *ElementIDIB_HLP_N_IB_S;
	TFIBIntegerField *ElementINDEX_HLP_N_IB_S;
	TFIBWideStringField *ElementNAME_HLP_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THLP_DMSprNaborInfBlockSostav(TComponent* Owner);

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



		bool NewElement(__int64 id_group_element, __int64 id_grp);
		bool InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_ib);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);
		bool ChancheGrp(__int64 id_new_grp,__int64 id_element);



		bool OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
		bool TableSaveIsmen(void);
		bool TableCancelIsmen(void);
		bool TableNewElement(__int64 id_group_element, __int64 id_grp);
		bool TableAppend(void);
		bool TableDelete(void);
		bool TableEdit(void);
		bool TablePost(void);


};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprNaborInfBlockSostav *HLP_DMSprNaborInfBlockSostav;
//---------------------------------------------------------------------------
#endif
