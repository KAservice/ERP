//---------------------------------------------------------------------------

#ifndef UDMSprFactorH
#define UDMSprFactorH
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
class TDMSprFactor : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_SFACTOR;
	TFIBWideStringField *TableGID_SFACTOR;
	TFIBLargeIntField *TableIDBASE_SFACTOR;
	TFIBWideStringField *TableNAME_SFACTOR;
	TFIBIntegerField *TableINDEX_SFACTOR;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_SFACTOR;
	TFIBWideStringField *ElementGID_SFACTOR;
	TFIBLargeIntField *ElementIDBASE_SFACTOR;
	TFIBWideStringField *ElementNAME_SFACTOR;
	TFIBIntegerField *ElementINDEX_SFACTOR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprFactor(TComponent* Owner);

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

		bool SaveIsmen(void);
		bool CancelIsmen(void);

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprFactor *DMSprFactor;
//---------------------------------------------------------------------------
#endif
