//---------------------------------------------------------------------------

#ifndef UDMSprTypeAnalogH
#define UDMSprTypeAnalogH
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
class TDMSprTypeAnalog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_STYPE_ANALOG;
	TFIBLargeIntField *TableIDBASE_STYPE_ANALOG;
	TFIBWideStringField *TableGID_STYPE_ANALOG;
	TFIBWideStringField *TableNAME_STYPE_ANALOG;
	TFIBLargeIntField *ElementID_STYPE_ANALOG;
	TFIBLargeIntField *ElementIDBASE_STYPE_ANALOG;
	TFIBWideStringField *ElementGID_STYPE_ANALOG;
	TFIBWideStringField *ElementNAME_STYPE_ANALOG;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprTypeAnalog(TComponent* Owner);

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

		__int64 IdElement;



		bool NewElement(void);
		bool InsertElement(UnicodeString name);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);



		bool OpenTable(void);
		bool TableSaveIsmen(void);
		bool TableCancelIsmen(void);
		bool TableNewElement(void);
		bool TableAppend(void);
		bool TableDelete(void);
		bool TableEdit(void);
		bool TablePost(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprTypeAnalog *DMSprTypeAnalog;
//---------------------------------------------------------------------------
#endif
