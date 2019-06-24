//---------------------------------------------------------------------------

#ifndef UDMSprSellerH
#define UDMSprSellerH
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
class TDMSprSeller : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_SSELLER;
	TFIBLargeIntField *TableIDBASE_SSELLER;
	TFIBWideStringField *TableNAME_SSELLER;
	TFIBWideStringField *TableADR_SSELLER;
	TFIBWideStringField *TablePHONE_SSELLER;
	TFIBLargeIntField *TableIDKLIENT_SSELLER;
	TFIBWideStringField *TableNAME_FOR_PRINT_SSELLER;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBWideStringField *TableINNKLIENT;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_SSELLER;
	TFIBLargeIntField *ElementIDBASE_SSELLER;
	TFIBWideStringField *ElementNAME_SSELLER;
	TFIBWideStringField *ElementADR_SSELLER;
	TFIBWideStringField *ElementPHONE_SSELLER;
	TFIBLargeIntField *ElementIDKLIENT_SSELLER;
	TFIBWideStringField *ElementNAME_FOR_PRINT_SSELLER;
	TFIBWideStringField *ElementNAMEKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprSeller(TComponent* Owner);

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

        bool OpenTable();
		bool  OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement();
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 id);

		__int64 GetIdElementPoName(UnicodeString   name);
		int GetIndexInTablePoId(__int64 id_element);

		__int64 GetIdElementPoGid(UnicodeString gid);
		UnicodeString GetGidElementPoId(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprSeller *DMSprSeller;
//---------------------------------------------------------------------------
#endif
