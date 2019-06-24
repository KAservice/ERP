//---------------------------------------------------------------------------

#ifndef UkanComClassFactoryH
#define UkanComClassFactoryH
#include "GlobalInterface.h"
#include "UkanBaseGuid.h"
//---------------------------------------------------------------------------
class __declspec(uuid("{7EC1A07A-155F-47B8-9C76-189FA365BA7E}")) TkanComClassFactory : public IkanCom
{
private:

	typedef int (__import  DllGetClassObjectType(REFIID id_class, REFIID id_interface, void ** ppv));
	DllGetClassObjectType * DllGetClassObject;

	typedef int (__import  DllSendApplicationType(TApplication * app));
	DllSendApplicationType * DllSendApplication;

	typedef int (__import  DllRegisterServerType(IkanCom * icom));
	DllRegisterServerType * DllRegisterServer;

	typedef int (__import  DllUnregisterServerType(IkanCom * icom));
	DllUnregisterServerType * DllUnregisterServer;

	typedef int (__import  DllCanUnloadNowType(void));
	DllCanUnloadNowType * DllCanUnloadNow;

	int NumRefs;

	struct TElementSpiska
			{
			HINSTANCE  DllInstance;
			AnsiString NameModul;
			};
	TList * List;

public:
   TkanComClassFactory();
   ~TkanComClassFactory();





   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void**ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);



   //IkanCOM
	virtual int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);
	virtual int kanProgIDFromCLSID(GUID guid, char *  prog_id );
	virtual int kanCLSIDFromProgID(char * prog_id, GUID * guid);
	virtual int kanAddClass(REFIID id_class, char * prog_id, char * file_name_modul);
	virtual int kanRemoveClass(REFIID id_class);
	virtual int kanRegisterClassInModule(char * file_name_modul);
	virtual int kanUnregisterClassInModule(char * file_name_modul);
	virtual int kanCreateObject(char * prog_id, REFIID id_interface, void** ppv);

	HINSTANCE GetModule(AnsiString name_modul);

	int UnloadModule(HINSTANCE dll_in);
	void UnloadFreeModules(void);
	void ShowListLoadModules(void);


	void UnloadAllModules(void);


	TElementSpiska * El;

};
#define CLSID_TkanComClassFactory __uuidof(TkanComClassFactory)
#endif
