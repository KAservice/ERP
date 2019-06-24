//---------------------------------------------------------------------------

#ifndef UDMSprSkladH
#define UDMSprSkladH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>

//---------------------------------------------------------------------------
class TDMSprSklad : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableTSKLAD;
	TIntegerField *TableRECNO;
	TFIBIntegerField *ElementTSKLAD;
	TpFIBQuery *pFIBQ;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableMOLSKLAD;
	TFIBWideStringField *TableADRSKLAD;
	TFIBWideStringField *TableGID_SSKLAD;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementMOLSKLAD;
	TFIBWideStringField *ElementADRSKLAD;
	TFIBWideStringField *ElementGID_SSKLAD;
	TFIBSmallIntField *ElementDBLUCHETALLNOM_SSKLAD;
	TFIBSmallIntField *ElementDBLUCHET_SSKLAD;
	TFIBWideStringField *ElementPREFIKS_NUM_SSKLAD;
	TFIBWideStringField *ElementPHONE_SSKLAD;
	TFIBWideStringField *ElementEMAIL_SSKLAD;
	TFIBWideStringField *ElementVKONTAKTE_SSKLAD;
	TFIBWideStringField *ElementWEBSITE_SSKLAD;
	TFIBWideStringField *ElementDOPINFO_SSKLAD;
	TFIBWideStringField *ElementREGIM_RABOTI_SSKLAD;
	TFIBLargeIntField *TableIDSKLAD;
	TFIBLargeIntField *TableIDBASE_SSKLAD;
	TFIBSmallIntField *TableDBLUCHETALLNOM_SSKLAD;
	TFIBSmallIntField *TableDBLUCHET_SSKLAD;
	TFIBWideStringField *TablePREFIKS_NUM_SSKLAD;
	TFIBWideStringField *TablePHONE_SSKLAD;
	TFIBWideStringField *TableEMAIL_SSKLAD;
	TFIBWideStringField *TableVKONTAKTE_SSKLAD;
	TFIBWideStringField *TableWEBSITE_SSKLAD;
	TFIBWideStringField *TableDOPINFO_SSKLAD;
	TFIBWideStringField *TableREGIM_RABOTI_SSKLAD;
	TFIBLargeIntField *ElementIDSKLAD;
	TFIBLargeIntField *ElementIDBASE_SSKLAD;
		void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprSklad(TComponent* Owner);

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

        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprSklad *DMSprSklad;
//---------------------------------------------------------------------------
#endif
