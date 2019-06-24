//---------------------------------------------------------------------------

#ifndef UREM_DMSprSostH
#define UREM_DMSprSostH
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
class TREM_DMSprSost : public TDataModule
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
	TFIBLargeIntField *TableID_REMSSOST;
	TFIBWideStringField *TableGID_REMSSOST;
	TFIBWideStringField *TableNAME_REMSSOST;
	TFIBLargeIntField *TableIDBASE_REM_SSOST;
	TFIBLargeIntField *ElementID_REMSSOST;
	TFIBWideStringField *ElementGID_REMSSOST;
	TFIBWideStringField *ElementNAME_REMSSOST;
	TFIBLargeIntField *ElementIDBASE_REM_SSOST;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TREM_DMSprSost(TComponent* Owner);

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
extern PACKAGE TREM_DMSprSost *REM_DMSprSost;
//---------------------------------------------------------------------------
#endif
