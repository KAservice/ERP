//---------------------------------------------------------------------------

#ifndef UART_DMSprNaborInfBlockSostavGrpH
#define UART_DMSprNaborInfBlockSostavGrpH
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
class TART_DMSprNaborInfBlockSostavGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_ART_N_IB_S_GRP;
	TFIBLargeIntField *TableIDBASE_ART_N_IB_S_GRP;
	TFIBWideStringField *TableGUID_ART_N_IB_S_GRP;
	TFIBDateTimeField *TablePOS_ISM_ART_N_IB_S_GRP;
	TFIBLargeIntField *TableIDGRP_ART_N_IB_S_GRP;
	TFIBWideStringField *TableNAME_ART_N_IB_S_GRP;
	TFIBLargeIntField *TableIDNABOR_ART_N_IB_S_GRP;
	TFIBLargeIntField *ElementID_ART_N_IB_S_GRP;
	TFIBLargeIntField *ElementIDBASE_ART_N_IB_S_GRP;
	TFIBWideStringField *ElementGUID_ART_N_IB_S_GRP;
	TFIBDateTimeField *ElementPOS_ISM_ART_N_IB_S_GRP;
	TFIBLargeIntField *ElementIDGRP_ART_N_IB_S_GRP;
	TFIBWideStringField *ElementNAME_ART_N_IB_S_GRP;
	TFIBLargeIntField *ElementIDNABOR_ART_N_IB_S_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TART_DMSprNaborInfBlockSostavGrp(TComponent* Owner);

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


		bool OpenTable(__int64 id_group_element);
		bool OpenElement(__int64 id);
		bool NewElement(__int64 id_group_element, __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TART_DMSprNaborInfBlockSostavGrp *ART_DMSprNaborInfBlockSostavGrp;
//---------------------------------------------------------------------------
#endif
