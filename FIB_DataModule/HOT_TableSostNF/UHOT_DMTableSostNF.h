//---------------------------------------------------------------------------

#ifndef UHOT_DMTableSostNFH
#define UHOT_DMTableSostNFH
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
class THOT_DMTableSostNF : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TFIBIntegerField *TableKOLM_HOT_SOSTNF;
	TFIBDateTimeField *TablePOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *TablePOSCON_HOT_SOSTNF;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementKOLM_HOT_SOSTNF;
	TFIBDateTimeField *ElementPOSNACH_HOT_SOSTNF;
	TFIBDateTimeField *ElementPOSCON_HOT_SOSTNF;
	TFIBBCDField *TableID_HOT_SOSTNF;
	TFIBBCDField *TableIDNOMER_HOT_SOSTNF;
	TFIBBCDField *TableIDPLAT_HOT_SOSTNF;
	TFIBBCDField *TableIDGUEST_HOT_SOSTNF;
	TFIBBCDField *TableIDSOST_HOT_SOSTNF;
	TFIBBCDField *TableIDTPOS_HOT_SOSTNF;
	TFIBBCDField *TableIDCAT_HOT_SOSTNF;
	TFIBBCDField *TableIDDOCH_HOT_SOSTNF;
	TFIBBCDField *ElementID_HOT_SOSTNF;
	TFIBBCDField *ElementIDNOMER_HOT_SOSTNF;
	TFIBBCDField *ElementIDPLAT_HOT_SOSTNF;
	TFIBBCDField *ElementIDGUEST_HOT_SOSTNF;
	TFIBBCDField *ElementIDSOST_HOT_SOSTNF;
	TFIBBCDField *ElementIDTPOS_HOT_SOSTNF;
	TFIBBCDField *ElementIDCAT_HOT_SOSTNF;
	TFIBBCDField *ElementIDDOCH_HOT_SOSTNF;
	TFIBBCDField *ElementIDCEL_HOT_SOSTNF;
	TFIBWideStringField *TableNAMEPLAT;
	TFIBWideStringField *TableNAMEGUEST;
	TFIBWideStringField *TableNAME_HOT_SNF;
	TFIBWideStringField *TableNAME_HOT_SSOSTNOM;
	TFIBWideStringField *TableNAME_HOT_STYPEPOS;
	TFIBWideStringField *ElementNAMEPLAT;
	TFIBWideStringField *ElementNAMEGUEST;
	TFIBWideStringField *ElementNAME_HOT_SNF;
	TFIBWideStringField *ElementNAME_HOT_SSOSTNOM;
	TFIBWideStringField *ElementNAME_HOT_STYPEPOS;
	TFIBWideStringField *ElementNAME_HOT_SCATNOM;
	TFIBWideStringField *ElementNAME_HOT_SCELPR;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Element1CalcFields(TDataSet *DataSet);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall THOT_DMTableSostNF(TComponent* Owner);

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
		int OpenElement(__int64 Id);
		bool NewElement(void);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);

		__int64 IdPlat;

};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMTableSostNF *HOT_DMTableSostNF;
//---------------------------------------------------------------------------
#endif
