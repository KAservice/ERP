//---------------------------------------------------------------------------

#ifndef UREM_DMSprModelTypRabotH
#define UREM_DMSprModelTypRabotH
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
class TREM_DMSprModelTypRabot : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SMODEL_TRAB;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL_TRAB;
	TFIBLargeIntField *TableIDTR_REM_SMODEL_TRAB;
	TFIBLargeIntField *TableIDMODEL_REM_SMODEL_TRAB;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableNAME_REM_STYPRABOT;
	TFIBLargeIntField *ElementID_REM_SMODEL_TRAB;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL_TRAB;
	TFIBLargeIntField *ElementIDTR_REM_SMODEL_TRAB;
	TFIBLargeIntField *ElementIDMODEL_REM_SMODEL_TRAB;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBWideStringField *ElementNAME_REM_STYPRABOT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprModelTypRabot(TComponent* Owner);

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


		__int64 IdOwner;
		__int64 IdElement;

		void OpenTable(__int64 id_owner);
		bool NewElement(__int64 id_owner);

		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprModelTypRabot *REM_DMSprModelTypRabot;
//---------------------------------------------------------------------------
#endif
