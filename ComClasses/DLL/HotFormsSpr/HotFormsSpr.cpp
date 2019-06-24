//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UHOT_FormaElementaSprCatNomImpl.h"
#include "UHOT_FormaElementaSprCatNomCF.h"
#include "UHOT_FormaSpiskaSprCatNomImpl.h"
#include "UHOT_FormaSpiskaSprCatNomCF.h"
#include "UHOT_FormaSpiskaSprCelPriesdaImpl.h"
#include "UHOT_FormaSpiskaSprCelPriesdaCF.h"
#include "UHOT_FormaElementaSprObjectImpl.h"
#include "UHOT_FormaElementaSprObjectCF.h"
#include "UHOT_FormaSpiskaSprObjectImpl.h"
#include "UHOT_FormaSpiskaSprObjectCF.h"
#include "UHOT_FormaElementaSprNFImpl.h"
#include "UHOT_FormaElementaSprNFCF.h"
#include "UHOT_FormaSpiskaSprNFImpl.h"
#include "UHOT_FormaSpiskaSprNFCF.h"
#include "UHOT_FormaElementaSprTypePoselImpl.h"
#include "UHOT_FormaElementaSprTypePoselCF.h"
#include "UHOT_FormaSpiskaSprTypePoselImpl.h"
#include "UHOT_FormaSpiskaSprTypePoselCF.h"
#include "UHOT_FormaElementaSprPrOsnUslugImpl.h"
#include "UHOT_FormaElementaSprPrOsnUslugCF.h"
#include "UHOT_FormaSpiskaSprPrOsnUslugImpl.h"
#include "UHOT_FormaSpiskaSprPrOsnUslugCF.h"
#include "UHOT_FormaElementaSprSostNomImpl.h"
#include "UHOT_FormaElementaSprSostNomCF.h"
#include "UHOT_FormaSpiskaSprSostNomImpl.h"
#include "UHOT_FormaSpiskaSprSostNomCF.h"
#include "UHOT_FormaElementaTableSostNFImpl.h"
#include "UHOT_FormaElementaTableSostNFCF.h"
#include "UHOT_FormaSpiskaTableSostNFImpl.h"
#include "UHOT_FormaSpiskaTableSostNFCF.h"
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

if (id_class==CLSID_THOT_FormaElementaSprCatNomImpl)
	{
	THOT_FormaElementaSprCatNomCF * ob=new THOT_FormaElementaSprCatNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprCatNomImpl)
	{
	THOT_FormaSpiskaSprCatNomCF * ob=new THOT_FormaSpiskaSprCatNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprCelPriesdaImpl)
	{
	THOT_FormaSpiskaSprCelPriesdaCF * ob=new THOT_FormaSpiskaSprCelPriesdaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaSprObjectImpl)
	{
	THOT_FormaElementaSprObjectCF * ob=new THOT_FormaElementaSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprObjectImpl)
	{
	THOT_FormaSpiskaSprObjectCF * ob=new THOT_FormaSpiskaSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaSprNFImpl)
	{
	THOT_FormaElementaSprNFCF * ob=new THOT_FormaElementaSprNFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprNFImpl)
	{
	THOT_FormaSpiskaSprNFCF * ob=new THOT_FormaSpiskaSprNFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaSprTypePoselImpl)
	{
	THOT_FormaElementaSprTypePoselCF * ob=new THOT_FormaElementaSprTypePoselCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprTypePoselImpl)
	{
	THOT_FormaSpiskaSprTypePoselCF * ob=new THOT_FormaSpiskaSprTypePoselCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaSprPrOsnUslugImpl)
	{
	THOT_FormaElementaSprPrOsnUslugCF * ob=new THOT_FormaElementaSprPrOsnUslugCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprPrOsnUslugImpl)
	{
	THOT_FormaSpiskaSprPrOsnUslugCF * ob=new THOT_FormaSpiskaSprPrOsnUslugCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaSprSostNomImpl)
	{
	THOT_FormaElementaSprSostNomCF * ob=new THOT_FormaElementaSprSostNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaSprSostNomImpl)
	{
	THOT_FormaSpiskaSprSostNomCF * ob=new THOT_FormaSpiskaSprSostNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaElementaTableSostNFImpl)
	{
	THOT_FormaElementaTableSostNFCF * ob=new THOT_FormaElementaTableSostNFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THOT_FormaSpiskaTableSostNFImpl)
	{
	THOT_FormaSpiskaTableSostNFCF * ob=new THOT_FormaSpiskaTableSostNFCF();
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

if (icom->kanAddClass(CLSID_THOT_FormaElementaSprCatNomImpl,"Oberon.HOT_FormaElSprCatNom.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprCatNom.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprCatNomImpl,ProgId_HOT_FormaSpiskaSprCatNom,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprCatNom)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprCelPriesdaImpl,ProgId_HOT_FormaSpiskaSprCelPriesda,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprCelPriesda)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaSprObjectImpl,"Oberon.HOT_FormaElSprObject.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprObject.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprObjectImpl,ProgId_HOT_FormaSpiskaSprObject,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprObject)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaSprNFImpl,"Oberon.HOT_FormaElSprNF.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprNF.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprNFImpl,ProgId_HOT_FormaSpiskaSprNF,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprNF)+" !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaSprTypePoselImpl,"Oberon.HOT_FormaElSprTypePosel.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprTypePosel.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprTypePoselImpl,ProgId_HOT_FormaSpiskaSprTypePos,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprTypePos)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaSprPrOsnUslugImpl,"Oberon.HOT_FormaElSprPrOsnUslug.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprPrOsnUslug.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprPrOsnUslugImpl,ProgId_HOT_FormaSpiskaSprPrOsnUsl,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprPrOsnUsl)+"!");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaSprSostNomImpl,"Oberon.HOT_FormaElSprSostNom.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElSprSostNom.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaSprSostNomImpl,ProgId_HOT_FormaSpiskaSprSostNom,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaSpiskaSprSostNom)+"  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaElementaTableSostNFImpl,"Oberon.HOT_FormaElTableSostNF.1","HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.HOT_FormaElTableSostNF.1  !");
	}
if (icom->kanAddClass(CLSID_THOT_FormaSpiskaTableSostNFImpl,ProgId_HOT_FormaTableSostNF,"HotFormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HOT_FormaTableSostNF)+" !");
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

