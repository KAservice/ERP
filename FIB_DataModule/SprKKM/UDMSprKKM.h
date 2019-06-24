//---------------------------------------------------------------------------

#ifndef UDMSprKKMH
#define UDMSprKKMH
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
class TDMSprKKM : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDKKM;
	TFIBBCDField *ElementIDKKM;
	TFIBWideStringField *TableNAMEKKM;
	TFIBWideStringField *TableGID_SKKM;
	TFIBWideStringField *TableCATOBMKKM;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementGID_SKKM;
	TFIBWideStringField *ElementCATOBMKKM;
	TFIBWideStringField *ElementPREFIKS_NUM_SKKM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprKKM(TComponent* Owner);

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
		void DeleteElement(__int64 Id);

		AnsiString GetGIDElement(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprKKM *DMSprKKM;
//---------------------------------------------------------------------------
#endif
