//---------------------------------------------------------------------------

#ifndef UDMSprOKEIH
#define UDMSprOKEIH
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
class TDMSprOKEI : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDOKEI;
	TFIBBCDField *ElementIDOKEI;
	TFIBWideStringField *TableNAMEOKEI;
	TFIBIntegerField *TableCODEOKEI;
	TFIBWideStringField *TableGID_SOKEI;
	TFIBBCDField *TableIDBASE_SOKEI;
	TFIBWideStringField *ElementNAMEOKEI;
	TFIBIntegerField *ElementCODEOKEI;
	TFIBWideStringField *ElementGID_SOKEI;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprOKEI(TComponent* Owner);

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

        void OpenTable();
		int  OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement();
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        bool Error;
        AnsiString TextError;		
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprOKEI *DMSprOKEI;
//---------------------------------------------------------------------------
#endif
