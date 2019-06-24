//---------------------------------------------------------------------------

#ifndef UDMSprImportSetH
#define UDMSprImportSetH
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
class TDMSprImportSet : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SIMPORTSET;
	TFIBBCDField *TableIDBASE_SIMPORTSET;
	TFIBSmallIntField *TableTYPE_SEARCH_SIMPORTSET;
	TFIBSmallIntField *TableTYPE_OBR_SIMPORTSET;
	TFIBBCDField *ElementID_SIMPORTSET;
	TFIBBCDField *ElementIDBASE_SIMPORTSET;
	TFIBSmallIntField *ElementTYPE_SEARCH_SIMPORTSET;
	TFIBSmallIntField *ElementTYPE_OBR_SIMPORTSET;
	TIntegerField *TableRECNO;
	TFIBWideStringField *TableNAME_SIMPORTSET;
	TFIBWideStringField *TableSTRPAR_SIMPORTSET;
	TFIBWideStringField *TableDIR_SIMPORTSET;
	TFIBWideStringField *ElementNAME_SIMPORTSET;
	TFIBWideStringField *ElementSTRPAR_SIMPORTSET;
	TFIBWideStringField *ElementDIR_SIMPORTSET;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprImportSet(TComponent* Owner);

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
		int TypeObr;

        void OpenTable(void);
		int OpenElement(__int64 id);
		bool NewElement(void);
        bool SaveElement(void);
		void CloseElement(void);
		bool DeleteElement(__int64 id);


		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
		int GetIndexElementaPoID(__int64 id);
		AnsiString GetParameter(AnsiString parameter);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprImportSet *DMSprImportSet;
//---------------------------------------------------------------------------
#endif
