//---------------------------------------------------------------------------

#ifndef UHOT_DMSprPrOsnUslugH
#define UHOT_DMSprPrOsnUslugH
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
class THOT_DMSprPrOsnUslug : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBBCDField *ElementID_HOT_SPROSNUSL;
	TFIBBCDField *ElementIDCAT_HOT_SPROSNUSL;
	TFIBBCDField *ElementIDNOMPR_HOT_SPROSNUSL;
	TFIBBCDField *ElementIDNOMBR_HOT_SPROSNUSL;
	TFIBBCDField *ElementIDTPOS_HOT_SPROSNUSL;
	TFIBBCDField *TableID_HOT_SPROSNUSL;
	TFIBBCDField *TableIDCAT_HOT_SPROSNUSL;
	TFIBBCDField *TableIDNOMPR_HOT_SPROSNUSL;
	TFIBBCDField *TableIDNOMBR_HOT_SPROSNUSL;
	TFIBBCDField *TableIDTPOS_HOT_SPROSNUSL;
	TFIBBCDField *TableIDBASE_HOT_SPROSNUSL;
	TIntegerField *TableRECNO;
	TFIBWideStringField *TableNAME_HOT_SCATNOM;
	TFIBWideStringField *TableNAME_HOT_STYPEPOS;
	TFIBWideStringField *TableNAMENOMPR;
	TFIBWideStringField *TableNAMENOMBR;
	TFIBWideStringField *ElementNAME_HOT_SCATNOM;
	TFIBWideStringField *ElementNAME_HOT_STYPEPOS;
	TFIBWideStringField *ElementNAMENOMPR;
	TFIBWideStringField *ElementNAMENOMBR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall THOT_DMSprPrOsnUslug(TComponent* Owner);

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
        void UpdateTable(void);
		int OpenElement(__int64 Id);
		bool NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 Id);

		int GetIndexElementaPoID(__int64 id);

		__int64 IdNomBron;
		__int64 IdNomProg;
		void GetNomBronAndProg(__int64 id_cat,__int64 id_type_pos);


};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMSprPrOsnUslug *HOT_DMSprPrOsnUslug;
//---------------------------------------------------------------------------
#endif
