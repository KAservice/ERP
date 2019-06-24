//---------------------------------------------------------------------------

#ifndef UHOT_DMSprNFH
#define UHOT_DMSprNFH
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
class THOT_DMSprNF : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBIntegerField *TableKOLM_HOT_SNF;
	TFIBDateTimeField *TablePOSIN_HOT_SNF;
	TFIBDateTimeField *TablePOSOUT_HOT_SNF;
	TFIBIntegerField *ElementKOLM_HOT_SNF;
	TFIBDateTimeField *ElementPOSIN_HOT_SNF;
	TFIBDateTimeField *ElementPOSOUT_HOT_SNF;
	TFIBBCDField *ElementID_HOT_SNF;
	TFIBBCDField *ElementIDOB_HOT_SNF;
	TFIBBCDField *ElementIDCAT_HOT_SNF;
	TFIBBCDField *TableID_HOT_SNF;
	TFIBBCDField *TableIDOB_HOT_SNF;
	TFIBBCDField *TableIDCAT_HOT_SNF;
	TFIBWideStringField *ElementNAME_HOT_SNF;
	TFIBWideStringField *ElementNAME_HOT_SOBJECT;
	TFIBWideStringField *ElementNAME_HOT_SCATNOM;
	TFIBWideStringField *TableNAME_HOT_SNF;
	TFIBWideStringField *TableNAME_HOT_SOBJECT;
	TFIBWideStringField *TableNAME_HOT_SCATNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THOT_DMSprNF(TComponent* Owner);

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
		void UpdateTable(void);

		int OpenElement(__int64 Id);
		bool NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 Id);

		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMSprNF *HOT_DMSprNF;
//---------------------------------------------------------------------------
#endif
