//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UDMGurOperDiscountCardImpl.h"
#include "UDMGurOperDiscountCardCF.h"
#include "UDMGurAllDocImpl.h"
#include "UDMGurAllDocCF.h"
#include "UDMGurDocCheckKKMImpl.h"
#include "UDMGurDocCheckKKMCF.h"
#include "UDMGurDocCheckKKM2Impl.h"
#include "UDMGurDocCheckKKM2CF.h"
#include "UDMGurDocPerImpl.h"
#include "UDMGurDocPerCF.h"
#include "UDMGurDocPrihNaklImpl.h"
#include "UDMGurDocPrihNaklCF.h"
#include "UDMGurPlatImpl.h"
#include "UDMGurPlatCF.h"
#include "UDMGurRoznDocImpl.h"
#include "UDMGurRoznDocCF.h"
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
if (id_class==CLSID_TDMGurOperDiscountCardImpl)
	{
	TDMGurOperDiscountCardCF * ob=new TDMGurOperDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurAllDocImpl)
	{
	TDMGurAllDocCF * ob=new TDMGurAllDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurDocCheckKKMImpl)
	{
	TDMGurDocCheckKKMCF * ob=new TDMGurDocCheckKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurDocCheckKKM2Impl)
	{
	TDMGurDocCheckKKM2CF * ob=new TDMGurDocCheckKKM2CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurDocPerImpl)
	{
	TDMGurDocPerCF * ob=new TDMGurDocPerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurDocPrihNaklImpl)
	{
	TDMGurDocPrihNaklCF * ob=new TDMGurDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurPlatImpl)
	{
	TDMGurPlatCF * ob=new TDMGurPlatCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMGurRoznDocImpl)
	{
	TDMGurRoznDocCF * ob=new TDMGurRoznDocCF();
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

if (icom->kanAddClass(CLSID_TDMGurOperDiscountCardImpl,"Oberon.DMGurOperDiscountCard.1","DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMGurOperDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TDMGurAllDocImpl,ProgId_DMGurAllDoc,"DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMGurAllDoc)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMGurDocCheckKKMImpl,ProgId_DMGurDocCheckKKM,"DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMGurDocCheckKKM)+" !");
	}
if (icom->kanAddClass(CLSID_TDMGurDocCheckKKM2Impl,"Oberon.DMGurDocCheckKKM2.1","DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMGurDocCheckKKM2.1  !");
	}
if (icom->kanAddClass(CLSID_TDMGurDocPerImpl,"Oberon.DMGurDocPer.1","DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMGurDocPer.1  !");
	}

if (icom->kanAddClass(CLSID_TDMGurPlatImpl,ProgId_DMGurPlat,"DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMGurPlat)+" !");
	}


if (icom->kanAddClass(CLSID_TDMGurRoznDocImpl,"Oberon.DMGurRoznDoc.1","DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMGurRoznDoc.1  !");
	}
if (icom->kanAddClass(CLSID_TDMGurDocPrihNaklImpl,"Oberon.DMGurDocPrihNakl.1","DMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMGurDocPrihNakl.1  !");
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

