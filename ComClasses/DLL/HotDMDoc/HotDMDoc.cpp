//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UHOT_DMDocBronImpl.h"
#include "UHOT_DMDocBronCF.h"
#include "UHOT_DMDocOtmenaBronImpl.h"
#include "UHOT_DMDocOtmenaBronCF.h"
#include "UHOT_DMDocRaschetImpl.h"
#include "UHOT_DMDocRaschetCF.h"
#include "UHOT_DMDocRasmImpl.h"
#include "UHOT_DMDocRasmCF.h"
#include "UHOT_DMDocRealImpl.h"
#include "UHOT_DMDocRealCF.h"
#include "UHOT_DMDocViezdImpl.h"
#include "UHOT_DMDocViezdCF.h"
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


}
//---------------------------------------------------------------------------
void kanDone(void)
{

if (dllApp!=0) Application=dllApp;
}

//---------------------------------------------------------------------------
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}
//----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_THOT_DMDocBronImpl)
	{
	THOT_DMDocBronCF * ob=new THOT_DMDocBronCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMDocOtmenaBronImpl)
	{
	THOT_DMDocOtmenaBronCF * ob=new THOT_DMDocOtmenaBronCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMDocRaschetImpl)
	{
	THOT_DMDocRaschetCF * ob=new THOT_DMDocRaschetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMDocRasmImpl)
	{
	THOT_DMDocRasmCF * ob=new THOT_DMDocRasmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMDocRealImpl)
	{
	THOT_DMDocRealCF * ob=new THOT_DMDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMDocViezdImpl)
	{
	THOT_DMDocViezdCF * ob=new THOT_DMDocViezdCF();
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

if (icom->kanAddClass(CLSID_THOT_DMDocBronImpl,"Oberon.HOT_DMDocBron.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocBron.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMDocOtmenaBronImpl,"Oberon.HOT_DMDocOtmenaBron.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocOtmenaBron.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMDocRaschetImpl,"Oberon.HOT_DMDocRaschet.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocRaschet.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMDocRasmImpl,"Oberon.HOT_DMDocRasm.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocRasm.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMDocRealImpl,"Oberon.HOT_DMDocReal.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocReal.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMDocViezdImpl,"Oberon.HOT_DMDocViezd.1","HotDMDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMDocViezd.1  !");
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
