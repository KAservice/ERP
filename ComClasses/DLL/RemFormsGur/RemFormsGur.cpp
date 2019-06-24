//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UREM_FormaSetupOtborImpl.h"
#include "UREM_FormaSetupOtborCF.h"
#include "UREM_FormaGurAllDocImpl.h"
#include "UREM_FormaGurAllDocCF.h"
#include "UREM_FormaGurZAktPrImpl.h"
#include "UREM_FormaGurZAktPrCF.h"


#include "UREM_FormaGurProverokImpl.h"
#include "UREM_FormaGurProverokCF.h"
#include "UREM_FormaGurVigrusokImpl.h"
#include "UREM_FormaGurVigrusokCF.h"
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

if (id_class==CLSID_TREM_FormaSetupOtborImpl)
	{
	TREM_FormaSetupOtborCF * ob=new TREM_FormaSetupOtborCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurAllDocImpl)
	{
	TREM_FormaGurAllDocCF * ob=new TREM_FormaGurAllDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurZAktPrImpl)
	{
	TREM_FormaGurZAktPrCF * ob=new TREM_FormaGurZAktPrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaGurProverokImpl)
	{
	TREM_FormaGurProverokCF * ob=new TREM_FormaGurProverokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaGurVigrusokImpl)
	{
	TREM_FormaGurVigrusokCF * ob=new TREM_FormaGurVigrusokCF();
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


if (icom->kanAddClass(CLSID_TREM_FormaSetupOtborImpl,"Oberon.REM_FormaSetupOtbor.1","RemFormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaSetupOtbor.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaGurAllDocImpl,ProgId_REM_FormaGurAllDoc,"RemFormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurAllDoc)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaGurZAktPrImpl,ProgId_REM_FormaGurZAktPr,"RemFormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurZAktPr)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaGurProverokImpl,ProgId_REM_FormaGurProverok,"RemFormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurProverok)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaGurVigrusokImpl,ProgId_REM_FormaGurVigrusok,"RemFormsGur.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurVigrusok)+" !");
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
