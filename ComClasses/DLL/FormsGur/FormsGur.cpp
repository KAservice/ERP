//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UFormaGurDocCheckKKM2Impl.h"
#include "UFormaGurDocCheckKKM2CF.h"
#include "UFormaGurDocCheckKKMImpl.h"
#include "UFormaGurDocCheckKKMCF.h"
#include "UFormaGurDocPerImpl.h"
#include "UFormaGurDocPerCF.h"
#include "UFormaGurDocPrihNaklImpl.h"
#include "UFormaGurDocPrihNaklCF.h"
#include "UFormaGurAllDocImpl.h"
#include "UFormaGurAllDocCF.h"
#include "UFormaElementaGurOperDiscountCardImpl.h"
#include "UFormaElementaGurOperDiscountCardCF.h"
#include "UFormaGurOperDiscountCardImpl.h"
#include "UFormaGurOperDiscountCardCF.h"
#include "UFormaElementaGurPlatImpl.h"
#include "UFormaElementaGurPlatCF.h"
#include "UFormaGurPlatImpl.h"
#include "UFormaGurPlatCF.h"
#include "UFormaSetupOtborGurRoznDocImpl.h"
#include "UFormaSetupOtborGurRoznDocCF.h"
#include "UFormaGurRoznDocImpl.h"
#include "UFormaGurRoznDocCF.h"
#include "UFormaSetupOtborImpl.h"
#include "UFormaSetupOtborCF.h"
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
if (id_class==CLSID_TFormaGurDocCheckKKM2Impl)
	{
	TFormaGurDocCheckKKM2CF * ob=new TFormaGurDocCheckKKM2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurDocCheckKKMImpl)
	{
	TFormaGurDocCheckKKMCF * ob=new TFormaGurDocCheckKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurDocPerImpl)
	{
	TFormaGurDocPerCF * ob=new TFormaGurDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurDocPrihNaklImpl)
	{
	TFormaGurDocPrihNaklCF * ob=new TFormaGurDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurAllDocImpl)
	{
	TFormaGurAllDocCF * ob=new TFormaGurAllDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaGurOperDiscountCardImpl)
	{
	TFormaElementaGurOperDiscountCardCF * ob=new TFormaElementaGurOperDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurOperDiscountCardImpl)
	{
	TFormaGurOperDiscountCardCF * ob=new TFormaGurOperDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaGurPlatImpl)
	{
	TFormaElementaGurPlatCF * ob=new TFormaElementaGurPlatCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurPlatImpl)
	{
	TFormaGurPlatCF * ob=new TFormaGurPlatCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSetupOtborGurRoznDocImpl)
	{
	TFormaSetupOtborGurRoznDocCF * ob=new TFormaSetupOtborGurRoznDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaGurRoznDocImpl)
	{
	TFormaGurRoznDocCF * ob=new TFormaGurRoznDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSetupOtborImpl)
	{
	TFormaSetupOtborCF * ob=new TFormaSetupOtborCF();
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

if (icom->kanAddClass(CLSID_TFormaGurDocCheckKKM2Impl,ProgId_FormaGurCheckKKM2,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaGurCheckKKM2)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaGurDocCheckKKMImpl,ProgId_FormaGurDocCheckKKM,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurDocCheckKKM)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaGurDocPerImpl,ProgId_FormaGurDocPer,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaGurDocPer)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaGurDocPrihNaklImpl,ProgId_FormaGurDocPrihNakl,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurDocPrihNakl)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaGurAllDocImpl,ProgId_FormaGurAllDoc,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurAllDoc)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaGurOperDiscountCardImpl,"Oberon.FormaElGurOperDiscountCard.1","FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElGurOperDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaGurOperDiscountCardImpl,ProgId_FormaGurOperDiscountCard,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurOperDiscountCard)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaGurPlatImpl,"Oberon.FormaElementaGurPlat.1","FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaGurPlat.1!");
	}
if (icom->kanAddClass(CLSID_TFormaGurPlatImpl,ProgId_FormaGurPlat,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurPlat)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaSetupOtborGurRoznDocImpl,"Oberon.FormaSetOtbGurRoznDoc.1","FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSetupOtborGurRoznDoc.1!");
	}
if (icom->kanAddClass(CLSID_TFormaGurRoznDocImpl,ProgId_FormaGurRoznDoc,"FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaGurRoznDoc)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaSetupOtborImpl,"Oberon.FormaSetupOtbor.1","FormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSetupOtbor.1!");
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

