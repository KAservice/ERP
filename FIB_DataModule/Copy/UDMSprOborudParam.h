//---------------------------------------------------------------------------

#ifndef UDMSprOborudParamH
#define UDMSprOborudParamH
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
class TDMSprOborudParam : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_SOBORUD_PAR;
	TFIBLargeIntField *TableIDBASE_SOBORUD_PAR;
	TFIBWideStringField *TableGID_SOBORUD_PAR;
	TFIBLargeIntField *TableIDOBORUD_SOBORUD_PAR;
	TFIBWideStringField *TableNAME_SOBORUD_PAR;
	TFIBWideStringField *TableVALUE_SOBORUD_PAR;
	TFIBDateTimeField *TableVALUE_TIMESTAMP_SOBORUD_PAR;
	TFIBIntegerField *TableINDEX_SOBORUD_PAR;
	TFIBSmallIntField *TableBEFORE_CONNECT_SOBORUD_PAR;
	TFIBSmallIntField *TableAFTER_CONNECT_SOBORUD_PAR;
	TFIBSmallIntField *TableON_CONNECT_SOBORUD_PAR;
	TFIBWideStringField *TableNAME_GRP_SOBORUD_PAR;
	TFIBLargeIntField *ElementID_SOBORUD_PAR;
	TFIBLargeIntField *ElementIDBASE_SOBORUD_PAR;
	TFIBWideStringField *ElementGID_SOBORUD_PAR;
	TFIBLargeIntField *ElementIDOBORUD_SOBORUD_PAR;
	TFIBWideStringField *ElementNAME_SOBORUD_PAR;
	TFIBWideStringField *ElementVALUE_SOBORUD_PAR;
	TFIBDateTimeField *ElementVALUE_TIMESTAMP_SOBORUD_PAR;
	TFIBIntegerField *ElementINDEX_SOBORUD_PAR;
	TFIBSmallIntField *ElementBEFORE_CONNECT_SOBORUD_PAR;
	TFIBSmallIntField *ElementAFTER_CONNECT_SOBORUD_PAR;
	TFIBSmallIntField *ElementON_CONNECT_SOBORUD_PAR;
	TFIBWideStringField *ElementNAME_GRP_SOBORUD_PAR;
	TFIBIntegerField *TableTYPE_PARAMETER_SOBORUD_PAR;
	TFIBIntegerField *ElementTYPE_PARAMETER_SOBORUD_PAR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprOborudParam(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
        bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


       //IkasDM
	//параметры
	bool SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set);
	bool SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set);
	bool SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set);
	bool SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set);
	bool SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set);
	bool SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set);


	bool OpenDataSet(int index_data_set);
	bool CloseDataSet(int index_data_set);

	// значения полей
	bool SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set);
	int GetValueFieldAsInt (UnicodeString name_field, int index_data_set);

	bool SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set);
	__int64 GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set);

	bool SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set);
	double GetValueFieldAsFloat (UnicodeString name_field, int index_data_set);

	bool SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set);
	UnicodeString GetValueFieldAsString (UnicodeString name_field, int index_data_set);

	bool SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set);
	TDateTime GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set);

	bool SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set);
	bool GetValueFieldAsBool (UnicodeString name_field, int index_data_set);


	bool SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set);
	bool SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set);
	bool LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set);
	bool LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set);

	//навиация
	int GetRecordCount(int index_data_set);
	int GetIndexTecRecord(int index_data_set);
	bool GetEof(int index_data_set);
	bool First(int index_data_set);
	bool Next(int index_data_set);
	bool Last(int index_data_set);
	bool MoveBy(int kol_rec,int index_data_set);

	//сохранение удаление записей
	bool Edit(int index_data_set);
	bool Post(int index_data_set);


		 //IkasDMSpr


	__int64 IdGroupEl1;
	__int64 IdGroupEl2;
	__int64 IdOwner;
	__int64 IdGrp;
	__int64 IdEl;

	bool All;


	//таблица
	bool OpenTable(int type_search);  //0 без поиска, 1 по наименованию, 2 по реквизиту
	bool CloseTable(void);
	bool DeleteString(void);
	bool AppendString(void);
	bool SaveChanges(void);
	bool CancelChanges(void);
	bool SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter);
	bool SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter);

	//элемент
   bool NewElement();
   bool OpenElement(__int64 id);
   bool DeleteElement(__int64 id);
   bool SaveElement(void);
   bool ChangeGrp(__int64 new_id_grp, __int64 id_el);

   	//интерфейс IkasDMDataSet

	TDataSource * kanGetDataSource(int index_data_source);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprOborudParam *DMSprOborudParam;
//---------------------------------------------------------------------------
#endif
