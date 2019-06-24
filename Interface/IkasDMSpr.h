#ifndef IkasDMSprInterfaceH
#define IkasDMSprInterfaceH

#include <guiddef.h>
#include <IkasDM.h>


class __declspec(uuid("{D93F4ABB-B146-46FC-86D6-E54577E13DA9}")) IkasDMSpr : public IkasDM

{
public:

	 //IkasDMSpr


	__property __int64 IdGroupEl1 = {read = get_IdGroupEl1 , write = set_IdGroupEl1};   virtual __int64 get_IdGroupEl1(void)=0;   virtual void set_IdGroupEl1(__int64 IdGroupEl1)=0;
	__property __int64 IdGroupEl2 = {read = get_IdGroupEl2 , write = set_IdGroupEl2};   virtual __int64 get_IdGroupEl2(void)=0;   virtual void set_IdGroupEl2(__int64 IdGroupEl2)=0;
	__property __int64 IdOwner = {read = get_IdOwner , write = set_IdOwner};   virtual __int64 get_IdOwner(void)=0;   virtual void set_IdOwner(__int64 IdOwner)=0;
	__property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};   virtual __int64 get_IdGrp(void)=0;   virtual void set_IdGrp(__int64 IdGrp)=0;
	__property __int64 IdEl = {read = get_IdEl , write = set_IdEl};   virtual __int64 get_IdEl(void)=0;   virtual void set_IdEl(__int64 IdEl)=0;

	__property bool All = {read = get_All , write = set_All};   virtual bool get_All(void)=0;   virtual void set_All(bool All)=0;


	//таблица
	virtual bool OpenTable(int type_search)=0;  //0 без поиска, 1 по наименованию, 2 по реквизиту
	virtual bool CloseTable(void)=0;
	virtual bool DeleteString(void)=0;
	virtual bool AppendString(void)=0;
	virtual bool SaveChanges(void)=0;
	virtual bool CancelChanges(void)=0;
	virtual bool SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter)=0;
	virtual bool SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter)=0;

	//элемент
   virtual bool NewElement()=0;
   virtual bool OpenElement(__int64 id)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual bool SaveElement(void)=0;
   virtual bool ChangeGrp(__int64 new_id_grp, __int64 id_el)=0;

};
#define IID_IkasDMSpr __uuidof(IkasDMSpr)


#endif
