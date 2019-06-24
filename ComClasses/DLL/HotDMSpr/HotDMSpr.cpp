//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UHOT_DMSprCatNomImpl.h"
#include "UHOT_DMSprCatNomCF.h"
#include "UHOT_DMSprCelPriesdaImpl.h"
#include "UHOT_DMSprCelPriesdaCF.h"
#include "UHOT_DMSprNFImpl.h"
#include "UHOT_DMSprNFCF.h"
#include "UHOT_DMSprObjectImpl.h"
#include "UHOT_DMSprObjectCF.h"
#include "UHOT_DMSprPrOsnUslugImpl.h"
#include "UHOT_DMSprPrOsnUslugCF.h"
#include "UHOT_DMSprSostNomImpl.h"
#include "UHOT_DMSprSostNomCF.h"
#include "UHOT_DMSprTypePoselImpl.h"
#include "UHOT_DMSprTypePoselCF.h"
#include "UHOT_DMTableSostNFImpl.h"
#include "UHOT_DMTableSostNFCF.h"
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
if (id_class==CLSID_THOT_DMSprCatNomImpl)
	{
	THOT_DMSprCatNomCF * ob=new THOT_DMSprCatNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprCelPriesdaImpl)
	{
	THOT_DMSprCelPriesdaCF * ob=new THOT_DMSprCelPriesdaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprNFImpl)
	{
	THOT_DMSprNFCF * ob=new THOT_DMSprNFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprObjectImpl)
	{
	THOT_DMSprObjectCF * ob=new THOT_DMSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprPrOsnUslugImpl)
	{
	THOT_DMSprPrOsnUslugCF * ob=new THOT_DMSprPrOsnUslugCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprSostNomImpl)
	{
	THOT_DMSprSostNomCF * ob=new THOT_DMSprSostNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMSprTypePoselImpl)
	{
	THOT_DMSprTypePoselCF * ob=new THOT_DMSprTypePoselCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_DMTableSostNFImpl)
	{
	THOT_DMTableSostNFCF * ob=new THOT_DMTableSostNFCF();
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

if (icom->kanAddClass(CLSID_THOT_DMSprCatNomImpl,"Oberon.HOT_DMSprCatNom.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprCatNom.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprCelPriesdaImpl,"Oberon.HOT_DMSprCelPriesda.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprCelPriesda.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprNFImpl,"Oberon.HOT_DMSprNF.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprNF.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprObjectImpl,"Oberon.HOT_DMSprObject.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprObject.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprPrOsnUslugImpl,"Oberon.HOT_DMSprPrOsnUslug.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprPrOsnUslug.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprSostNomImpl,"Oberon.HOT_DMSprSostNom.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprSostNom.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMSprTypePoselImpl,"Oberon.HOT_DMSprTypePosel.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMSprTypePosel.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_DMTableSostNFImpl,"Oberon.HOT_DMTableSostNF.1","HotDMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_DMTableSostNF.1  !");
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
