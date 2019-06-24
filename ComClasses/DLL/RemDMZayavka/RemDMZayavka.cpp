//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UREM_DMZayavkaDvImpl.h"
#include "UREM_DMZayavkaDvCF.h"
#include "UREM_DMZayavkaImpl.h"
#include "UREM_DMZayavkaCF.h"
#include "UREM_DMGurZImpl.h"
#include "UREM_DMGurZCF.h"
#include "UREM_DMCustQueryDvImpl.h"
#include "UREM_DMCustQueryDvCF.h"
#include "UREM_DMCustQueryImpl.h"
#include "UREM_DMCustQueryCF.h"
#include "UREM_DMGurCustQueryImpl.h"
#include "UREM_DMGurCustQueryCF.h"

#include "UREM_DMSprSostCustQueryImpl.h"
#include "UREM_DMSprSostCustQueryCF.h"

#include "UREM_DMZayavkaImageImpl.h"
#include "UREM_DMZayavkaImageCF.h"

#include "UREM_DMGurCustQueryDetalImpl.h"
#include "UREM_DMGurCustQueryDetalCF.h"

#include "UREM_DMZayavkaPredvImpl.h"
#include "UREM_DMZayavkaPredvCF.h"
#include "UREM_DMGurZPredvImpl.h"
#include "UREM_DMGurZPredvCF.h"
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
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TREM_DMZayavkaDvImpl)
	{
	TREM_DMZayavkaDvCF * ob=new TREM_DMZayavkaDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMZayavkaImpl)
	{
	TREM_DMZayavkaCF * ob=new TREM_DMZayavkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurZImpl)
	{
	TREM_DMGurZCF * ob=new TREM_DMGurZCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMZayavkaPredvImpl)
	{
	TREM_DMZayavkaPredvCF * ob=new TREM_DMZayavkaPredvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurZPredvImpl)
	{
	TREM_DMGurZPredvCF * ob=new TREM_DMGurZPredvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMSprSostCustQueryImpl)
	{
	TREM_DMSprSostCustQueryCF * ob=new TREM_DMSprSostCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurCustQueryImpl)
	{
	TREM_DMGurCustQueryCF * ob=new TREM_DMGurCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMCustQueryImpl)
	{
	TREM_DMCustQueryCF * ob=new TREM_DMCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMCustQueryDvImpl)
	{
	TREM_DMCustQueryDvCF * ob=new TREM_DMCustQueryDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMZayavkaImageImpl)
	{
	TREM_DMZayavkaImageCF * ob=new TREM_DMZayavkaImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurCustQueryDetalImpl)
	{
	TREM_DMGurCustQueryDetalCF * ob=new TREM_DMGurCustQueryDetalCF();
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

if (icom->kanAddClass(CLSID_TREM_DMZayavkaDvImpl,ProgId_REM_DMZayavkaDv,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMZayavkaDv)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMZayavkaImpl,ProgId_REM_DMZayavka,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMZayavka)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMGurZImpl,ProgId_REM_DMGurZ,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurZ)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMSprSostCustQueryImpl,ProgId_REM_DMSprSostCustQuery,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMSprSostCustQuery)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMGurCustQueryImpl,ProgId_REM_DMGurCustQuery,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurCustQuery)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMCustQueryImpl,ProgId_REM_DMCustQuery,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMCustQuery)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMCustQueryDvImpl,ProgId_REM_DMCustQueryDv,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMCustQueryDv)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMZayavkaImageImpl,ProgId_REM_DMZayavkaImage,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMZayavkaImage)+"  !");
	}


	if (icom->kanAddClass(CLSID_TREM_DMGurCustQueryDetalImpl,ProgId_REM_DMGurCustQueryDetal,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurCustQueryDetal)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMZayavkaPredvImpl,ProgId_REM_DMZayavkaPredv,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMZayavkaPredv)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_DMGurZPredvImpl,ProgId_REM_DMGurZPredv,"RemDMZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurZPredv)+"  !");
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
