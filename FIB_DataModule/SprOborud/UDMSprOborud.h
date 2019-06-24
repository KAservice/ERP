//---------------------------------------------------------------------------

#ifndef UDMSprOborudH
#define UDMSprOborudH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include <DB.hpp>
//#include <IBCustomDataSet.hpp>
//#include <IBDatabase.hpp>
//#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMSprOborud : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBSmallIntField *TableON_START_SOBORUD;
	TFIBSmallIntField *ElementON_START_SOBORUD;
	TFIBWideStringField *TableNAME_OBORUD;
	TFIBWideStringField *TableCOMPNAME_OBORUD;
	TFIBWideStringField *TableCOMNAME_OBORUD;
	TFIBWideStringField *TableBAUDRATE_OBORUD;
	TFIBWideStringField *TableMODEL_OBORUD;
	TFIBWideStringField *TableGID_SOBORUD;
	TFIBWideStringField *TableSTRPAR_SOBORUD;
	TFIBWideStringField *TableMODUL_SOBORUD;
	TFIBWideStringField *ElementNAME_OBORUD;
	TFIBWideStringField *ElementCOMPNAME_OBORUD;
	TFIBWideStringField *ElementCOMNAME_OBORUD;
	TFIBWideStringField *ElementTYPE_OBORUD;
	TFIBWideStringField *ElementMODEL_OBORUD;
	TFIBWideStringField *ElementGID_SOBORUD;
	TFIBWideStringField *ElementSTRPAR_SOBORUD;
	TFIBWideStringField *ElementMODUL_SOBORUD;
	TFIBWideStringField *TableTYPE_OBORUD;
	TFIBWideStringField *ElementBAUDRATE_OBORUD;
	TFIBLargeIntField *TableID_OBORUD;
	TFIBLargeIntField *TableIDARM_SOBORUD;
	TFIBLargeIntField *TableIDBASE_SOBORUD;
	TFIBLargeIntField *ElementID_OBORUD;
	TFIBLargeIntField *ElementIDARM_SOBORUD;
	TFIBLargeIntField *ElementIDBASE_SOBORUD;
	TFIBWideStringField *TablePROGID_SOBORUD;
	TFIBWideStringField *ElementPROGID_SOBORUD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprOborud(TComponent* Owner);

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


		void OpenTable(__int64 id_kkm);
		void OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud);
		int OpenElement(__int64 Id);
		void NewElement(__int64 id_kkm);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        __int64 IdKKM;
		UnicodeString GetParameter(UnicodeString parameter);
		UnicodeString GetParameterPoTable(UnicodeString parameter);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprOborud *DMSprOborud;
//---------------------------------------------------------------------------
#endif
