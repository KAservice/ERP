//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UHOT_FormaDocBronImpl.h"
#include "UHOT_FormaDocBronCF.h"
#include "UHOT_FormaDocOtmenaBronImpl.h"
#include "UHOT_FormaDocOtmenaBronCF.h"
#include "UHOT_FormaDocRaschetImpl.h"
#include "UHOT_FormaDocRaschetCF.h"
#include "UHOT_FormaDocRasmImpl.h"
#include "UHOT_FormaDocRasmCF.h"
#include "UHOT_FormaDocRealImpl.h"
#include "UHOT_FormaDocRealCF.h"
#include "UHOT_FormaDocViezdImpl.h"
#include "UHOT_FormaDocViezdCF.h"
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
if(DM) delete DM;
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
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;

if (id_class==CLSID_THOT_FormaDocBronImpl)
	{
	THOT_FormaDocBronCF * ob=new THOT_FormaDocBronCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaDocOtmenaBronImpl)
	{
	THOT_FormaDocOtmenaBronCF * ob=new THOT_FormaDocOtmenaBronCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaDocRaschetImpl)
	{
	THOT_FormaDocRaschetCF * ob=new THOT_FormaDocRaschetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaDocRasmImpl)
	{
	THOT_FormaDocRasmCF * ob=new THOT_FormaDocRasmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaDocRealImpl)
	{
	THOT_FormaDocRealCF * ob=new THOT_FormaDocRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaDocViezdImpl)
	{
	THOT_FormaDocViezdCF * ob=new THOT_FormaDocViezdCF();
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


if (icom->kanAddClass(CLSID_THOT_FormaDocBronImpl,ProgId_HOT_FormaDocBron,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaDocBron)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaDocOtmenaBronImpl,ProgId_HOT_FormaDocOtmenaBron,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HOT_FormaDocOtmenaBron)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaDocRaschetImpl,ProgId_HOT_FormaDocRaschet,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+ UnicodeString(ProgId_HOT_FormaDocRaschet)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaDocRasmImpl,ProgId_HOT_FormaDocRasm,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaDocRasm)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaDocRealImpl,ProgId_HOT_FormaDocReal,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaDocReal)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaDocViezdImpl,ProgId_HOT_FormaDocViesd,"HotFormsDoc.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HOT_FormaDocViesd)+"  !");
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
