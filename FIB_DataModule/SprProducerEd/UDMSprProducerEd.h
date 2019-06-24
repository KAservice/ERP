//---------------------------------------------------------------------------

#ifndef UDMSprProducerEdH
#define UDMSprProducerEdH
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
class TDMSprProducerEd : public TDataModule
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
	TFIBLargeIntField *TableID_SPRED;
	TFIBLargeIntField *TableIDBASE_SPRED;
	TFIBWideStringField *TableGID_SPRED;
	TFIBLargeIntField *TableIDPRNOM_SPRED;
	TFIBIntegerField *TableCODE_SPRED;
	TFIBWideStringField *TableBARCODE_SPRED;
	TFIBBCDField *TableKF_SPRED;
	TFIBWideStringField *TableNAME_SPRED;
	TFIBLargeIntField *ElementID_SPRED;
	TFIBLargeIntField *ElementIDBASE_SPRED;
	TFIBWideStringField *ElementGID_SPRED;
	TFIBLargeIntField *ElementIDPRNOM_SPRED;
	TFIBIntegerField *ElementCODE_SPRED;
	TFIBWideStringField *ElementBARCODE_SPRED;
	TFIBBCDField *ElementKF_SPRED;
	TFIBWideStringField *ElementNAME_SPRED;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TDMSprProducerEd(TComponent* Owner);

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

		void OpenTable(__int64 id_producer_nom);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_producer_nom);
        bool SaveElement(void);
		bool DeleteElement(__int64 num);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProducerEd *DMSprProducerEd;
//---------------------------------------------------------------------------
#endif
