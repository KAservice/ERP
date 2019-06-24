//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "GlobalInterface.h"
#include "UFormaRunExternalModuleCF.h"
#include "UFormaRunExternalModuleImpl.h"
//---------------------------------------------------------------------------
extern "C" int __declspec (dllexport) kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);
extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" int __declspec (dllexport) kanRegisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanUnregisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
//---------------------------------------------------------------------------

#pragma argsused
TApplication * glApp=0;
TApplication * dllApp=0;

int NumObject=0;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
if (fwdreason==DLL_PROCESS_DETACH)
	{
	if (dllApp!=0) Application=dllApp;
	}

	return 1;
}
//----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TFormaRunExternalModuleImpl)
	{
	TFormaRunExternalModuleCF * cf=new TFormaRunExternalModuleCF();
	result=cf->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete cf;
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
//----------------------------------------------------------------------------
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
int kanRegisterServer(IkanCom * icom)
{
int result=0;

if (icom->kanAddClass(CLSID_TFormaRunExternalModuleImpl,"Oberon.FormaRunExternalModule.1","DllRunExternalModule.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaRunExternalModule.1  !");
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
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}
//-----------------------------------------------------------------------------