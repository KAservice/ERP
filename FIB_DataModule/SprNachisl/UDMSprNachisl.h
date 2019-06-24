//---------------------------------------------------------------------------

#ifndef UDMSprNachislH
#define UDMSprNachislH
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
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
class TDMSprNachisl : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *TypeNachisl;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TypeNachislID_STNACHISL;
	TFIBWideStringField *TypeNachislNAME_STNACHISL;
	TFIBLargeIntField *TableID_SNACHISL;
	TFIBLargeIntField *TableIDBASE_SNACHISL;
	TFIBWideStringField *TableGID_SNACHISL;
	TFIBLargeIntField *TableIDNOM_SNACHISL;
	TFIBLargeIntField *TableIDTNACH_SNACHISL;
	TFIBBCDField *TableVALUE_SNACHISL;
	TFIBWideStringField *TableNAME_STNACHISL;
	TStringField *TableNAME_TYPE_NACHISL_LOOKUP;
	TFIBBCDField *ElementID_SNACHISL;
	TFIBBCDField *ElementIDBASE_SNACHISL;
	TFIBWideStringField *ElementGID_SNACHISL;
	TFIBBCDField *ElementIDNOM_SNACHISL;
	TFIBBCDField *ElementIDTNACH_SNACHISL;
	TFIBBCDField *ElementVALUE_SNACHISL;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprNachisl(TComponent* Owner);

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

		void OpenTable(__int64 id_nom);
        bool SaveIsmen(void);
        void CancelIsmen(void);
		int OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);
		__int64 FindElement(__int64 id_type_nachisl, __int64 id_nom);

		__int64 IdNom;
		__int64 IdTypeNachisl;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNachisl *DMSprNachisl;
//---------------------------------------------------------------------------
#endif
