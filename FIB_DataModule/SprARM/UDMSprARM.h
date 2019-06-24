//---------------------------------------------------------------------------

#ifndef UDMSprARMH
#define UDMSprARMH
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
class TDMSprARM : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_SARM;
	TFIBWideStringField *TableGID_SARM;
	TFIBWideStringField *TableNAME_SARM;
	TFIBIntegerField *TableCODE_SARM;
	TFIBLargeIntField *TableIDFIRM_SARM;
	TFIBLargeIntField *TableIDSKLAD_SARM;
	TFIBLargeIntField *TableIDPODR_SARM;
	TFIBLargeIntField *TableIDKKM_SARM;
	TFIBWideStringField *TableSTRPAR_SARM;
	TFIBWideStringField *TablePREFIKS_SARM;
	TFIBLargeIntField *TableIDBASE_SARM;
	TFIBLargeIntField *TableIDACTCATEGORY_SARM;
	TFIBLargeIntField *ElementID_SARM;
	TFIBWideStringField *ElementGID_SARM;
	TFIBWideStringField *ElementNAME_SARM;
	TFIBIntegerField *ElementCODE_SARM;
	TFIBLargeIntField *ElementIDFIRM_SARM;
	TFIBLargeIntField *ElementIDSKLAD_SARM;
	TFIBLargeIntField *ElementIDPODR_SARM;
	TFIBLargeIntField *ElementIDKKM_SARM;
	TFIBWideStringField *ElementSTRPAR_SARM;
	TFIBWideStringField *ElementPREFIKS_SARM;
	TFIBLargeIntField *ElementIDBASE_SARM;
	TFIBLargeIntField *ElementIDACTCATEGORY_SARM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementNAMEPOD;
	TFIBLargeIntField *ElementIDTPRICEPOD;
	TFIBWideStringField *ElementNAME_TPRICE;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAME_REM_SACTCATEGORY;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Element1CalcFields(TDataSet *DataSet);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;
public:		// User declarations
        __fastcall TDMSprARM(TComponent* Owner);

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




        bool flSaveElement;
        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        int FindPoCodu(int code);
        int FindPoName(String name);
        AnsiString GetGIDElement(__int64 id);
		AnsiString GetParameter(AnsiString parameter);
		int GetMaxCode(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprARM *DMSprARM;
//---------------------------------------------------------------------------
#endif
