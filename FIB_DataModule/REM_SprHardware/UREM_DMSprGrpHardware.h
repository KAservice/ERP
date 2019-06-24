//---------------------------------------------------------------------------

#ifndef UREM_DMSprGrpHardwareH
#define UREM_DMSprGrpHardwareH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------


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
class TREM_DMSprGrpHardware : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SGRP_HARDWARE;
	TFIBLargeIntField *TableIDBASE_REM_SGRP_HARDWARE;
	TFIBWideStringField *TableNAME_REM_SGRP_HARDWARE;
	TFIBLargeIntField *TableIDGRP_REM_SGRP_HARDWARE;
	TFIBLargeIntField *ElementID_REM_SGRP_HARDWARE;
	TFIBLargeIntField *ElementIDBASE_REM_SGRP_HARDWARE;
	TFIBWideStringField *ElementNAME_REM_SGRP_HARDWARE;
	TFIBLargeIntField *ElementIDGRP_REM_SGRP_HARDWARE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprGrpHardware(TComponent* Owner);

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

        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 FindPoName(AnsiString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprGrpHardware *REM_DMSprGrpHardware;
//---------------------------------------------------------------------------
#endif
