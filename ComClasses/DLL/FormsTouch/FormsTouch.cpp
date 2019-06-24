//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UFormaSpiskaSprEdTouchCF.h"
#include "UFormaSpiskaSprEdTouchImpl.h"
#include "UFormaSpiskaSprBVNomTouchCF.h"
#include "UFormaSpiskaSprBVNomTouchImpl.h"
#include "UKalkulatorCF.h"
#include "UKalkulatorImpl.h"
#include "UFormaDocCheckTouchCF.h"
#include "UFormaDocCheckTouchImpl.h"
#include "UFormaDocRealRoznTouchCF.h"
#include "UFormaDocRealRoznTouchImpl.h"
#include "UDMRegZakCF.h"
#include "UDMRegZakImpl.h"
#include "UFormaZakazOfCF.h"
#include "UFormaZakazOfImpl.h"
#include "UFormaStrObjectTouchCF.h"
#include "UFormaStrObjectTouchImpl.h"
#include "UFormaReportTouchForFRCF.h"
#include "UFormaReportTouchForFRImpl.h"
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
if (id_class==CLSID_TFormaSpiskaSprEdTouchImpl)
	{
	TFormaSpiskaSprEdTouchCF * ob=new TFormaSpiskaSprEdTouchCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaSprBVNomTouchImpl)
	{
	TFormaSpiskaSprBVNomTouchCF * ob=new TFormaSpiskaSprBVNomTouchCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TKalkulatorImpl)
	{
	TKalkulatorCF * ob=new TKalkulatorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocCheckTouchImpl)
	{
	TFormaDocCheckTouchCF * ob=new TFormaDocCheckTouchCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDocRealRoznTouchImpl)
	{
	TFormaDocRealRoznTouchCF * ob=new TFormaDocRealRoznTouchCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegZakImpl)
	{
	TDMRegZakCF * ob=new TDMRegZakCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaZakazOfImpl)
	{
	TFormaZakazOfCF * ob=new TFormaZakazOfCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaStrObjectTouchImpl)
	{
	TFormaStrObjectTouchCF * ob=new TFormaStrObjectTouchCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportTouchForFRImpl)
	{
	TFormaReportTouchForFRCF * ob=new TFormaReportTouchForFRCF();
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

if (icom->kanAddClass(CLSID_TFormaSpiskaSprEdTouchImpl,"Oberon.FormaSpSprEdTouch.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpSprEdTouch.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBVNomTouchImpl,"Oberon.FormaSpSprBVNomTouch.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpSprBVNomTouch.1  !");
	}
if (icom->kanAddClass(CLSID_TKalkulatorImpl,"Oberon.Kalkulator.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.Kalkulator.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocCheckTouchImpl,"Oberon.FormaDocCheckTouch.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaDocCheckTouch.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaDocRealRoznTouchImpl,"Oberon.FormaDocRealRoznTouch.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaDocRealRoznTouch.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegZakImpl,"Oberon.DMRegZak.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegZak.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaZakazOfImpl,"Oberon.FormaZakazOf.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaZakazOf.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaStrObjectTouchImpl,"Oberon.FormaStrObjectTouch.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaStrObjectTouch.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportTouchForFRImpl,"Oberon.FormaReportTouchForFR.1","FormsTouch.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaReportTouchForFR.1  !");
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
