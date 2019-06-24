//---------------------------------------------------------------------------

#ifndef UDMSprTypeNachislH
#define UDMSprTypeNachislH
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
class TDMSprTypeNachisl : public TDataModule
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
	TFIBBCDField *TableID_STNACHISL;
	TFIBBCDField *TableIDBASE_STNACHISL;
	TFIBWideStringField *TableNAME_STNACHISL;
	TFIBWideStringField *TableGID_STNACHISL;
	TFIBBCDField *ElementID_STNACHISL;
	TFIBBCDField *ElementIDBASE_STNACHISL;
	TFIBWideStringField *ElementNAME_STNACHISL;
	TFIBWideStringField *ElementGID_STNACHISL;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprTypeNachisl(TComponent* Owner);

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

        void OpenTable();
		int  OpenElement(__int64 Id);  //возвращает количество элементов
        void NewElement();
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

		__int64 GetIDTypePrice(String   name);
		int GetIndexTypePricePoId(__int64 id_type_price);

        __int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprTypeNachisl *DMSprTypeNachisl;
//---------------------------------------------------------------------------
#endif
