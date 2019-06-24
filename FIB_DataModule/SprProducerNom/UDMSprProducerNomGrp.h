//---------------------------------------------------------------------------

#ifndef UDMSprProducerNomGrpH
#define UDMSprProducerNomGrpH
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
class TDMSprProducerNomGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SPRNOMGRP;
	TFIBLargeIntField *TableIDBASE_SPRNOMGRP;
	TFIBWideStringField *TableGID_SPRNOMGRP;
	TFIBLargeIntField *TableIDGRP_SPRNOMGRP;
	TFIBLargeIntField *TableIDPROD_SPRNOMGRP;
	TFIBWideStringField *TableNAME_SPRNOMGRP;
	TFIBLargeIntField *ElementID_SPRNOMGRP;
	TFIBLargeIntField *ElementIDBASE_SPRNOMGRP;
	TFIBWideStringField *ElementGID_SPRNOMGRP;
	TFIBLargeIntField *ElementIDGRP_SPRNOMGRP;
	TFIBLargeIntField *ElementIDPROD_SPRNOMGRP;
	TFIBWideStringField *ElementNAME_SPRNOMGRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprProducerNomGrp(TComponent* Owner);

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

		void OpenTable(__int64 id_producer);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_producer, __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		__int64 IdProducer;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProducerNomGrp *DMSprProducerNomGrp;
//---------------------------------------------------------------------------
#endif
