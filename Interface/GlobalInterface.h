#ifndef UGlobalInterfaceH
#define UGlobalInterfaceH

#include <guiddef.h>

class __declspec(uuid("{4F169CA2-8EAD-4075-8AB0-B5FB8934C15A}"))  IkanUnknown
{
public:
	virtual int kanQueryInterface(REFIID id_interface, void ** ppv)=0;
	virtual int kanAddRef(void)=0;
	virtual int kanRelease(void)=0;
};
#define IID_IkanUnknown __uuidof(IkanUnknown)





class __declspec(uuid("{948E1CBE-7590-419C-91E8-446DA997B2EC}")) IkanClassFactory : public IkanUnknown
{
public:
	virtual int kanCreateInstance(REFIID id_interface, void ** ppv)=0;
};
#define IID_IkanClassFactory __uuidof(IkanClassFactory)






class __declspec(uuid("{15188AFB-7898-494F-815E-B3F32189A622}")) IkanCom : public IkanUnknown
{
public:
	virtual int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)=0;
	virtual int kanProgIDFromCLSID(GUID guid, char *  prog_id )=0;
	virtual int kanCLSIDFromProgID(char * prog_id, GUID * guid)=0;
	virtual int kanAddClass(REFIID id_class, char * prog_id, char * file_name_modul)=0;
	virtual int kanRemoveClass(REFIID id_class)=0;
	virtual int kanRegisterClassInModule(char * file_name_modul)=0;
	virtual int kanUnregisterClassInModule(char * file_name_modul)=0;
	virtual int kanCreateObject(char * prog_id, REFIID id_interface, void**ppv)=0;
};
#define IID_IkanCom __uuidof(IkanCom)





class __declspec(uuid("{948E63BC-B0FE-44A8-8200-AC484A553A6F}")) IkanCallBack : public IkanUnknown
{
public:
	virtual int kanExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)=0;
};
#define IID_IkanCallBack __uuidof(IkanCallBack)

#endif
