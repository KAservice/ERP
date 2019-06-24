#ifndef UDMSprOborudParamImplH
#define UDMSprOborudParamImplH
#include "UDMSprOborudParam.h"
#include "UGlobalConstant.h"
#include "IkasDMSpr.h"
#include "IkasDMDataSet.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprOborudParamImpl)) TDMSprOborudParamImpl : public IkasDMSpr, IkasDMDataSet
{
public:
   TDMSprOborudParamImpl();
   ~TDMSprOborudParamImpl();
   TDMSprOborudParam * Object;
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



       //IkasDM
	//параметры
	virtual bool SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set);
	virtual bool SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set);
	virtual bool SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set);
	virtual bool SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set);
	virtual bool SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set);
	virtual bool SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set);


	virtual bool OpenDataSet(int index_data_set);
	virtual bool CloseDataSet(int index_data_set);

	// значения полей
	virtual bool SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set);
	virtual int GetValueFieldAsInt (UnicodeString name_field, int index_data_set);

	virtual bool SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set);
	virtual __int64 GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set);

	virtual bool SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set);
	virtual double GetValueFieldAsFloat (UnicodeString name_field, int index_data_set);

	virtual bool SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set);
	virtual UnicodeString GetValueFieldAsString (UnicodeString name_field, int index_data_set);

	virtual bool SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set);
	virtual TDateTime GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set);

	virtual bool SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set);
	virtual bool GetValueFieldAsBool (UnicodeString name_field, int index_data_set);


	virtual bool SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set);
	virtual bool SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set);
	virtual bool LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set);
	virtual bool LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set);

	//навиация
	virtual int GetRecordCount(int index_data_set);
	virtual int GetIndexTecRecord(int index_data_set);
	virtual bool GetEof(int index_data_set);
	virtual bool First(int index_data_set);
	virtual bool Next(int index_data_set);
	virtual bool Last(int index_data_set);
	virtual bool MoveBy(int kol_rec,int index_data_set);

	//сохранение удаление записей
	virtual bool Edit(int index_data_set);
	virtual bool Post(int index_data_set);


		 //IkasDMSpr


	__property __int64 IdGroupEl1 = {read = get_IdGroupEl1 , write = set_IdGroupEl1};   virtual __int64 get_IdGroupEl1(void);   virtual void set_IdGroupEl1(__int64 IdGroupEl1);
	__property __int64 IdGroupEl2 = {read = get_IdGroupEl2 , write = set_IdGroupEl2};   virtual __int64 get_IdGroupEl2(void);   virtual void set_IdGroupEl2(__int64 IdGroupEl2);
	__property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};   virtual __int64 get_IdOwner(void);   virtual void set_IdOwner(__int64 IdOwner);
	__property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};   virtual __int64 get_IdGrp(void);   virtual void set_IdGrp(__int64 IdGrp);
	__property __int64 IdEl = {read = get_IdEl , write = set_IdEl};   virtual __int64 get_IdEl(void);   virtual void set_IdEl(__int64 IdEl);

	__property bool All = {read = get_All , write = set_All};   virtual bool get_All(void);   virtual void set_All(bool All);


	//таблица
	virtual bool OpenTable(int type_search);  //0 без поиска, 1 по наименованию, 2 по реквизиту
	virtual bool CloseTable(void);
	virtual bool DeleteString(void);
	virtual bool AppendString(void);
	virtual bool SaveChanges(void);
	virtual bool CancelChanges(void);
	virtual bool SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter);
	virtual bool SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter);

	//элемент
   virtual bool NewElement();
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual bool ChangeGrp(__int64 new_id_grp, __int64 id_el);

   //IkasDMDataSet
	virtual TDataSource * kanGetDataSource(int index_data_source);
};
#define CLSID_TDMSprOborudParamImpl __uuidof(TDMSprOborudParamImpl)
#endif
