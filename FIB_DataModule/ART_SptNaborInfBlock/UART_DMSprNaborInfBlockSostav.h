//---------------------------------------------------------------------------

#ifndef UART_DMSprNaborInfBlockSostavH
#define UART_DMSprNaborInfBlockSostavH
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
class TART_DMSprNaborInfBlockSostav : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_ART_N_IB_S;
	TFIBLargeIntField *TableIDBASE_ART_N_IB_S;
	TFIBWideStringField *TableGUID_ART_N_IB_S;
	TFIBDateTimeField *TablePOS_ISM_ART_N_IB_S;
	TFIBLargeIntField *TableIDGRP_ART_N_IB_S;
	TFIBLargeIntField *TableIDNABOR_ART_N_IB_S;
	TFIBLargeIntField *TableIDIB_ART_N_IB_S;
	TFIBWideStringField *TableNAME_ART_IB;
	TFIBLargeIntField *ElementID_ART_N_IB_S;
	TFIBLargeIntField *ElementIDBASE_ART_N_IB_S;
	TFIBWideStringField *ElementGUID_ART_N_IB_S;
	TFIBDateTimeField *ElementPOS_ISM_ART_N_IB_S;
	TFIBLargeIntField *ElementIDGRP_ART_N_IB_S;
	TFIBLargeIntField *ElementIDNABOR_ART_N_IB_S;
	TFIBLargeIntField *ElementIDIB_ART_N_IB_S;
	TFIBWideStringField *ElementNAME_ART_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TART_DMSprNaborInfBlockSostav(TComponent* Owner);

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
extern PACKAGE TART_DMSprNaborInfBlockSostav *ART_DMSprNaborInfBlockSostav;
//---------------------------------------------------------------------------
#endif
