//---------------------------------------------------------------------------

#ifndef UREM_DMSprActCategoryH
#define UREM_DMSprActCategoryH
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
class TREM_DMSprActCategory : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SACTCATEGORY;
	TFIBLargeIntField *TableIDBASE_REM_SACTCATEGORY;
	TFIBWideStringField *TableGID_REM_SACTCATEGORY;
	TFIBWideStringField *TableNAME_REM_SACTCATEGORY;
	TFIBLargeIntField *ElementID_REM_SACTCATEGORY;
	TFIBLargeIntField *ElementIDBASE_REM_SACTCATEGORY;
	TFIBWideStringField *ElementGID_REM_SACTCATEGORY;
	TFIBWideStringField *ElementNAME_REM_SACTCATEGORY;
		void __fastcall DataModuleDestroy(TObject *Sender);
		void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TREM_DMSprActCategory(TComponent* Owner);

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
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(void);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprActCategory *REM_DMSprActCategory;
//---------------------------------------------------------------------------
#endif
