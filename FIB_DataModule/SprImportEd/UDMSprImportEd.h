//---------------------------------------------------------------------------

#ifndef UDMSprImportEdH
#define UDMSprImportEdH
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
class TDMSprImportEd : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SIMPORTED;
	TFIBBCDField *TableIDBASE_SIMPORTED;
	TFIBBCDField *TableIDNOM_SIMPORTED;
	TFIBBCDField *TableIDKLIENT_SIMPORTED;
	TFIBBCDField *TableIDED_SIMPORTED;
	TIntegerField *TableRECNO;
	TFIBBCDField *ElementID_SIMPORTED;
	TFIBBCDField *ElementIDBASE_SIMPORTED;
	TFIBBCDField *ElementIDNOM_SIMPORTED;
	TFIBBCDField *ElementIDKLIENT_SIMPORTED;
	TFIBBCDField *ElementIDED_SIMPORTED;
	TFIBWideStringField *TableBARCODE_SIMPORTED;
	TFIBWideStringField *TableCODE_SIMPORTED;
	TFIBWideStringField *TableNAME_SIMPORTED;
	TFIBWideStringField *ElementBARCODE_SIMPORTED;
	TFIBWideStringField *ElementCODE_SIMPORTED;
	TFIBWideStringField *ElementNAME_SIMPORTED;
	TFIBWideStringField *ElementNAMEKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprImportEd(TComponent* Owner);


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

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		bool Error;
		AnsiString TextError;

		void OpenTable(__int64 id_ed);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_nom,__int64 id_ed);
        bool SaveElement(void);
		bool DeleteElement(__int64 dd);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprImportEd *DMSprImportEd;
//---------------------------------------------------------------------------
#endif
