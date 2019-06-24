//---------------------------------------------------------------------------

#ifndef UDMSprBankH
#define UDMSprBankH
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
class TDMSprBank : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDBANK;
	TFIBBCDField *ElementIDBANK;
	TFIBWideStringField *TableNAMEBANK;
	TFIBWideStringField *TableGORBANK;
	TFIBWideStringField *ElementNAMEBANK;
	TFIBWideStringField *ElementBIKBANK;
	TFIBWideStringField *ElementGORBANK;
	TFIBWideStringField *ElementKSBANK;
	TFIBWideStringField *ElementGID_SBANK;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprBank(TComponent* Owner);


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

		void OpenTable();
		int  OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement();
        bool SaveElement(void);
        void DeleteElement(__int64 Id);
        bool Error;
        AnsiString TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprBank *DMSprBank;
//---------------------------------------------------------------------------
#endif
