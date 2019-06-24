//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UHOT_FormaReportDvNomFondaCF.h"
#include "UHOT_FormaReportDvNomFondaImpl.h"
#include "UHOT_FormaReportRasmCF.h"
#include "UHOT_FormaReportRasmImpl.h"
#include "UHOT_FormaReportRasmK_SCF.h"
#include "UHOT_FormaReportRasmK_SImpl.h"
#include "UHOT_FormaReportSostNFCF.h"
#include "UHOT_FormaReportSostNFImpl.h"
#include "UHOT_FormaReportSvobodNFCF.h"
#include "UHOT_FormaReportSvobodNFImpl.h"
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

TDM * DM=0;


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
if (id_class==CLSID_THOT_FormaReportDvNomFondaImpl)
	{
	THOT_FormaReportDvNomFondaCF * ob=new THOT_FormaReportDvNomFondaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaReportRasmImpl)
	{
	THOT_FormaReportRasmCF * ob=new THOT_FormaReportRasmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaReportRasmK_SImpl)
	{
	THOT_FormaReportRasmK_SCF * ob=new THOT_FormaReportRasmK_SCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaReportSostNFImpl)
	{
	THOT_FormaReportSostNFCF * ob=new THOT_FormaReportSostNFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaReportSvobodNFImpl)
	{
	THOT_FormaReportSvobodNFCF * ob=new THOT_FormaReportSvobodNFCF();
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

if (icom->kanAddClass(CLSID_THOT_FormaReportDvNomFondaImpl,ProgId_HOT_FormaReportDvNomFonda,"HotStReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaReportDvNomFonda)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaReportRasmImpl,ProgId_HOT_FormaReportRasm,"HotStReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaReportRasm)+"!");
	}
if (icom->kanAddClass(CLSID_THOT_FormaReportRasmK_SImpl,ProgId_HOT_FormaReportRasmK_S,"HotStReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaReportRasmK_S)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaReportSostNFImpl,ProgId_HOT_FormaReportSostNF,"HotStReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HOT_FormaReportSostNF)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaReportSvobodNFImpl,ProgId_HOT_FormaReportSvobodNF,"HotStReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaReportSvobodNF)+" !");
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
