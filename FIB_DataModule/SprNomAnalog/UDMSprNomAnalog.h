//---------------------------------------------------------------------------

#ifndef UDMSprNomAnalogH
#define UDMSprNomAnalogH
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
class TDMSprNomAnalog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_SNOM_ANALOG;
	TFIBLargeIntField *TableIDBASE_SNOM_ANALOG;
	TFIBWideStringField *TableGID_SNOM_ANALOG;
	TFIBLargeIntField *TableIDNOM_SNOM_ANALOG;
	TFIBLargeIntField *TableIDNOMANALOG_SNOM_ANALOG;
	TFIBLargeIntField *TableIDTYPEANALOG_SNOM_ANALOG;
	TFIBWideStringField *TableNAME_STYPE_ANALOG;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBWideStringField *TableSHED;
	TFIBBCDField *TableZNACH_PRICE;
	TFIBLargeIntField *ElementID_SNOM_ANALOG;
	TFIBLargeIntField *ElementIDBASE_SNOM_ANALOG;
	TFIBWideStringField *ElementGID_SNOM_ANALOG;
	TFIBLargeIntField *ElementIDNOM_SNOM_ANALOG;
	TFIBLargeIntField *ElementIDNOMANALOG_SNOM_ANALOG;
	TFIBLargeIntField *ElementIDTYPEANALOG_SNOM_ANALOG;
	TFIBWideStringField *ElementNAME_STYPE_ANALOG;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBWideStringField *ElementNAMEED;
	TFIBWideStringField *ElementSHED;
	TpFIBDataSet *SpisokTypeAnalog;
	TDataSource *DataSourceSpisokTypeAnalog;
	TFIBWideStringField *SpisokTypeAnalogNAME_STYPE_ANALOG;
	TFIBLargeIntField *SpisokTypeAnalogID_STYPE_ANALOG;
	TStringField *TableNAME_TYPE_ANALOG_LOOKUP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprNomAnalog(TComponent* Owner);

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

		__int64 IdRodElement;
		__int64 IdElement;
		__int64 IdTypePrice;


		bool NewElement(__int64 id_rod_element);
		bool InsertElement(__int64 id_rod_element, __int64 id_nom);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);



		bool OpenTable(__int64 id_rod_element, __int64 id_type_price);
		bool TableSaveIsmen(void);
		bool TableCancelIsmen(void);
		bool TableNewElement(__int64 id_rod_element);
		bool TableAppend(void);
		bool TableDelete(void);
		bool TableEdit(void);
		bool TablePost(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomAnalog *DMSprNomAnalog;
//---------------------------------------------------------------------------
#endif
