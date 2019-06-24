//---------------------------------------------------------------------------

#ifndef UHOT_DMSprTypePoselH
#define UHOT_DMSprTypePoselH
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
class THOT_DMSprTypePosel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBSmallIntField *TableKOLM_HOT_STYPEPOS;
	TFIBSmallIntField *TableALL_HOT_STYPEPOS;
	TFIBSmallIntField *ElementKOLM_HOT_STYPEPOS;
	TFIBSmallIntField *ElementALL_HOT_STYPEPOS;
	TFIBBCDField *TableID_HOT_STYPEPOS;
	TFIBBCDField *ElementID_HOT_STYPEPOS;
	TFIBWideStringField *TableNAME_HOT_STYPEPOS;
	TFIBWideStringField *ElementNAME_HOT_STYPEPOS;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall THOT_DMSprTypePosel(TComponent* Owner);

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
        void CloseElement(void);
		bool DeleteElement(__int64 Id);


		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMSprTypePosel *HOT_DMSprTypePosel;
//---------------------------------------------------------------------------
#endif
