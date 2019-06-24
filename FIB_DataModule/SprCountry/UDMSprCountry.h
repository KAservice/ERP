//---------------------------------------------------------------------------

#ifndef UDMSprCountryH
#define UDMSprCountryH
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
class TDMSprCountry : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_SCOUNTRY;
	TFIBBCDField *ElementID_SCOUNTRY;
	TFIBWideStringField *TableCODE_SCOUNTRY;
	TFIBWideStringField *TableGID_SCOUNTRY;
	TFIBWideStringField *TableNAME_SCOUNTRY;
	TFIBWideStringField *ElementCODE_SCOUNTRY;
	TFIBWideStringField *ElementGID_SCOUNTRY;
	TFIBWideStringField *ElementNAME_SCOUNTRY;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprCountry(TComponent* Owner);

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


        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 Id);

        __int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);

		__int64 GetIdPoName(UnicodeString name);

        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCountry *DMSprCountry;
//---------------------------------------------------------------------------
#endif
