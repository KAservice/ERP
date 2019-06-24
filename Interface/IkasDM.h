#ifndef IkasDMInterfaceH
#define IkasDMInterfaceH

#include <guiddef.h>
#include <IMainInterface.h>


class __declspec(uuid("{634D80EA-B900-4ADD-AC06-F5AD24C74D45}")) IkasDM : public IMainInterface
{
public:

    //IkasDM
	//параметры
	virtual bool SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)=0;
	virtual bool SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)=0;
	virtual bool SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)=0;
	virtual bool SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)=0;
	virtual bool SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)=0;
	virtual bool SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)=0;


	virtual bool OpenDataSet(int index_data_set)=0;
	virtual bool CloseDataSet(int index_data_set)=0;

	// значения полей
	virtual bool SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)=0;
	virtual int GetValueFieldAsInt (UnicodeString name_field, int index_data_set)=0;

	virtual bool SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)=0;
	virtual __int64 GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)=0;

	virtual bool SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)=0;
	virtual double GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)=0;

	virtual bool SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)=0;
	virtual UnicodeString GetValueFieldAsString (UnicodeString name_field, int index_data_set)=0;

	virtual bool SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)=0;
	virtual TDateTime GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)=0;

	virtual bool SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)=0;
	virtual bool GetValueFieldAsBool (UnicodeString name_field, int index_data_set)=0;


	virtual bool SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)=0;
	virtual bool SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)=0;
	virtual bool LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)=0;
	virtual bool LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)=0;

	//навиация
	virtual int GetRecordCount(int index_data_set)=0;
	virtual int GetIndexTecRecord(int index_data_set)=0;
	virtual bool GetEof(int index_data_set)=0;
	virtual bool First(int index_data_set)=0;
	virtual bool Next(int index_data_set)=0;
	virtual bool Last(int index_data_set)=0;
	virtual bool MoveBy(int kol_rec,int index_data_set)=0;

	//сохранение удаление записей
	virtual bool Edit(int index_data_set)=0;
	virtual bool Post(int index_data_set)=0;
};
#define IID_IkasDM __uuidof(IkasDM)


#endif
