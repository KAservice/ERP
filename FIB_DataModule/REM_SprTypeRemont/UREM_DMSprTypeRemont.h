//---------------------------------------------------------------------------

#ifndef UREM_DMSprTypeRemontH
#define UREM_DMSprTypeRemontH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------

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
class TREM_DMSprTypeRemont : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBWideStringField *ElementGID_STREMONT;
	TFIBWideStringField *ElementNAME_STREMONT;
	TFIBLargeIntField *ElementIDBASE_REM_STREMONT;
	TFIBLargeIntField *TableID_STREMONT;
	TFIBWideStringField *TableGID_STREMONT;
	TFIBWideStringField *TableNAME_STREMONT;
	TFIBLargeIntField *TableIDBASE_REM_STREMONT;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *ElementID_STREMONT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TREM_DMSprTypeRemont(TComponent* Owner);

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
		int OpenElement(__int64 id);
		void NewElement(void);
		bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 id);

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTypeRemont *REM_DMSprTypeRemont;
//---------------------------------------------------------------------------
#endif
