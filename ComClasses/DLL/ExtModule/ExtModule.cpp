//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"


#include "UDMExtModuleImpl.h"
#include "UDMExtModuleCF.h"
#include "UDMExtModuleGrpImpl.h"
#include "UDMExtModuleGrpCF.h"
#include "UDMExtModulePrivImpl.h"
#include "UDMExtModulePrivCF.h"
#include "UFormaElementaExtModuleImpl.h"
#include "UFormaElementaExtModuleCF.h"
#include "UFormaElementaExtModuleGrpImpl.h"
#include "UFormaElementaExtModuleGrpCF.h"
#include "UFormaSpiskaExtModuleImpl.h"
#include "UFormaSpiskaExtModuleCF.h"
//---------------------------------------------------------------------------
extern "C" int __declspec (dllexport) kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);


extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" int __declspec (dllexport) kanRegisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanUnregisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
extern "C" void __declspec (dllexport) kanInit(void);
extern "C" void __declspec (dllexport) kanDone(void);
//---------------------------------------------------------------------------
int NumObject=0;
TApplication * glApp=0;
TApplication * dllApp=0;

TDM *DM=0;

#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{

	return 1;
}
//---------------------------------------------------------------------------
int kanSendApplication(TApplication * app)
{
int result=0;
if (app!=0)
	{
	glApp=app;
	dllApp=Application;
	Application=glApp;
	}


return result;
}
//-----------------------------------------------------------------------------
void kanInit(void)
{

DM=new TDM(Application);
}
//---------------------------------------------------------------------------
void kanDone(void)
{
if (DM!=0) delete DM;
if (dllApp!=0) Application=dllApp;
}
//--------------------------------------------------------------------------

int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}

//---------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TDMExtModuleImpl)
	{
	TDMExtModuleCF * ob=new TDMExtModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMExtModuleGrpImpl)
	{
	TDMExtModuleGrpCF * ob=new TDMExtModuleGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMExtModulePrivImpl)
	{
	TDMExtModulePrivCF * ob=new TDMExtModulePrivCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaExtModuleImpl)
	{
	TFormaElementaExtModuleCF * ob=new TFormaElementaExtModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaExtModuleGrpImpl)
	{
	TFormaElementaExtModuleGrpCF * ob=new TFormaElementaExtModuleGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaExtModuleImpl)
	{
	TFormaSpiskaExtModuleCF * ob=new TFormaSpiskaExtModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else
	{
	result=0;
	*ppv=NULL;
	}


return result;
}
//----------------------------------------------------------------------------

int kanRegisterServer(IkanCom * icom)
{
int result=0;

if (icom->kanAddClass(CLSID_TDMExtModuleImpl,"Oberon.DMExtModule.1","ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMExtModule.1!");
	}
if (icom->kanAddClass(CLSID_TDMExtModuleGrpImpl,"Oberon.DMExtModuleGrp.1","ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMExtModuleGrp.1!");
	}
if (icom->kanAddClass(CLSID_TDMExtModulePrivImpl,"Oberon.DMExtModulePriv.1","ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMExtModulePriv.1!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaExtModuleImpl,"Oberon.FormaElementaExtModule.1","ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaExtModule.1!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaExtModuleGrpImpl,"Oberon.FormaElementaExtModuleGrp.1","ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaExtModuleGrp.1!");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaExtModuleImpl,ProgId_FormaSpiskaExtModule,"ExtModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaExtModule)+"!");
	}
return result;
}
//-----------------------------------------------------------------------------
int kanUnregisterServer(IkanCom * icom)
{
int result=0;

return result;
}
//-----------------------------------------------------------------------------

