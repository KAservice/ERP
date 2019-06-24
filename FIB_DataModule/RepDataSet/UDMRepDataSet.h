//---------------------------------------------------------------------------

#ifndef UDMRepDataSetH
#define UDMRepDataSetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMRepDataSet : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBTransaction *Transaction;
	TpFIBDataSet *DataSet;
	TDataSource *DataSource;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMRepDataSet(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации

	typedef  void (__closure * TFunctionDeleteImplType)(void);
	TFunctionDeleteImplType FunctionDeleteImpl;
	bool flDeleteImpl;


	bool Init(void);
	int Done(void);

	UnicodeString TextError;
	int CodeError;

	//интерфейс IkasDM


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


	//интерфейс IkasDMDataSet

	TDataSource * kanGetDataSource(int index_data_source);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMRepDataSet * DMRepDataSet;
//---------------------------------------------------------------------------
#endif
