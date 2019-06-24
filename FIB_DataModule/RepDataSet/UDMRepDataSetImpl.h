#ifndef UDMRepDataSetImplH
#define UDMRepDataSetImplH
#include "IkasDM.h"
#include "IkasDMDataSet.h"
#include "UDMRepDataSet.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMRepDataSetImpl)) TDMRepDataSetImpl : public IkasDM, IkasDMDataSet
{
public:
   TDMRepDataSetImpl();
   ~TDMRepDataSetImpl();
   TDMRepDataSet * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

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
#define CLSID_TDMRepDataSetImpl __uuidof(TDMRepDataSetImpl)
#endif
