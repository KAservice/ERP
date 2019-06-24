//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UREM_DMGurAllDocImpl.h"
#include "UREM_DMGurAllDocCF.h"
#include "UREM_DMGurZAktPrImpl.h"
#include "UREM_DMGurZAktPrCF.h"

#include "UREM_DMGurProverokImpl.h"
#include "UREM_DMGurProverokCF.h"
#include "UREM_DMGurVigrusokImpl.h"
#include "UREM_DMGurVigrusokCF.h"

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
if (id_class==CLSID_TREM_DMGurAllDocImpl)
	{
	TREM_DMGurAllDocCF * ob=new TREM_DMGurAllDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_DMGurZAktPrImpl)
	{
	TREM_DMGurZAktPrCF * ob=new TREM_DMGurZAktPrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurProverokImpl)
	{
	TREM_DMGurProverokCF * ob=new TREM_DMGurProverokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_DMGurVigrusokImpl)
	{
	TREM_DMGurVigrusokCF * ob=new TREM_DMGurVigrusokCF();
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

if (icom->kanAddClass(CLSID_TREM_DMGurAllDocImpl,ProgId_REM_DMGurAllDoc,"RemDMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurAllDoc)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMGurZAktPrImpl,ProgId_REM_DMGurZAktPr,"RemDMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurZAktPr)+"  !");
	}

if (icom->kanAddClass(CLSID_TREM_DMGurProverokImpl,ProgId_REM_DMGurProverok,"RemDMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurProverok)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_DMGurVigrusokImpl,ProgId_REM_DMGurVigrusok,"RemDMGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_DMGurVigrusok)+"  !");
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
