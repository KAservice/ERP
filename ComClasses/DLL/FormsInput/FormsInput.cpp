//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"


#include "UFormaInputTextImpl.h"
#include "UFormaInputTextCF.h"
#include "UFormaInputCodeImpl.h"
#include "UFormaInputCodeCF.h"
#include "UFormaInputDiscountCardImpl.h"
#include "UFormaInputDiscountCardCF.h"
#include "UFormaViborPeriodaImpl.h"
#include "UFormaViborPeriodaCF.h"
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

if (id_class==CLSID_TFormaInputTextImpl)
	{
	TFormaInputTextCF * ob=new TFormaInputTextCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaInputCodeImpl)
	{
	TFormaInputCodeCF * ob=new TFormaInputCodeCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaInputDiscountCardImpl)
	{
	TFormaInputDiscountCardCF * ob=new TFormaInputDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaViborPeriodaImpl)
	{
	TFormaViborPeriodaCF * ob=new TFormaViborPeriodaCF();
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


if (icom->kanAddClass(CLSID_TFormaInputTextImpl,ProgId_FormaInputText,"FormsInput.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaInputText)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaInputCodeImpl,"Oberon.FormaInputCode.1","FormsInput.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaInputCode.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaInputDiscountCardImpl,"Oberon.FormaInputDiscountCard.1","FormsInput.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaInputDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaViborPeriodaImpl,"Oberon.FormaViborPerioda.1","FormsInput.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaViborPerioda.1  !");
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

