//---------------------------------------------------------------------------

#ifndef UDMTableExtPrintFormH
#define UDMTableExtPrintFormH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
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
class TDMTableExtPrintForm : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_EXTPRINT_FORM;
	TFIBWideStringField *TableNAME_EXTPRINT_FORM;
	TFIBWideStringField *TableOBJECT_EXTPRINT_FORM;
	TFIBWideStringField *TableFILE_NAME_EXTPRINT_FORM;
	TFIBIntegerField *TableISPCONST_EXTPRINT_FORM;
	TFIBWideStringField *TableGID_EXTPRINT_FORM;
	TFIBLargeIntField *TableIDBASE_EXTPRINT_FORM;
	TFIBIntegerField *TableTYPEMODULE_EXTPRINT_FORM;
	TFIBIntegerField *TableRESIDENCE_EXTPRINT_FORM;
	TFIBBlobField *TableBODY_EXTPRINT_FORM;
	TFIBWideStringField *TableGUID_OB_EXTPRINT_FORM;
	TFIBWideStringField *TableNAME_PROGRAM_MODULE;
	TFIBWideStringField *TablePROGID_PROGRAM_MODULE;
	TFIBWideStringField *TablePATCH_PROGRAM_MODULE;
	TFIBLargeIntField *ElementID_EXTPRINT_FORM;
	TFIBWideStringField *ElementNAME_EXTPRINT_FORM;
	TFIBWideStringField *ElementOBJECT_EXTPRINT_FORM;
	TFIBWideStringField *ElementFILE_NAME_EXTPRINT_FORM;
	TFIBIntegerField *ElementISPCONST_EXTPRINT_FORM;
	TFIBWideStringField *ElementGID_EXTPRINT_FORM;
	TFIBLargeIntField *ElementIDBASE_EXTPRINT_FORM;
	TFIBIntegerField *ElementTYPEMODULE_EXTPRINT_FORM;
	TFIBIntegerField *ElementRESIDENCE_EXTPRINT_FORM;
	TFIBBlobField *ElementBODY_EXTPRINT_FORM;
	TFIBWideStringField *ElementGUID_OB_EXTPRINT_FORM;
	TFIBWideStringField *ElementNAME_PROGRAM_MODULE;
	TFIBWideStringField *ElementPROGID_PROGRAM_MODULE;
	TFIBWideStringField *ElementPATCH_PROGRAM_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMTableExtPrintForm(TComponent* Owner);

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
	UnicodeString TextError;
	bool Init(void);
	int Done(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


        void OpenTable(REFIID guid, bool all);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

        __int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMTableExtPrintForm *DMTableExtPrintForm;
//---------------------------------------------------------------------------
#endif
