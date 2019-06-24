//---------------------------------------------------------------------------

#ifndef UDMStSpr1H
#define UDMStSpr1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UkasObjectInfoBuilder.h"

//----------------------------------------------------------------------------
class TDMStSpr1 : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TDataSource *DataSourceTable;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
	__fastcall TDMStSpr1(TComponent* Owner);

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


	bool CreateObject(UnicodeString name_object);
	bool OpenTable(void);


	void UpdateParameterForm(TkasObjectInfo * ob);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMStSpr1 *DMStSpr1;
//---------------------------------------------------------------------------
#endif
