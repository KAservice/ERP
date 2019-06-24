//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UFormaElementaSprDepartmentImpl.h"
#include "UFormaElementaSprDepartmentCF.h"

#include "UFormaSpiskaSprDepartmentImpl.h"
#include "UFormaSpiskaSprDepartmentCF.h"

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

TDM *DM;


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
if (id_class==CLSID_TFormaElementaSprDepartmentImpl)
	{
	TFormaElementaSprDepartmentCF * ob=new TFormaElementaSprDepartmentCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaSpiskaSprDepartmentImpl)
	{
	TFormaSpiskaSprDepartmentCF * ob=new TFormaSpiskaSprDepartmentCF();
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



if (icom->kanAddClass(CLSID_TFormaElementaSprDepartmentImpl,ProgId_FormaElementaSprDepartment,"FormsSpr3.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprDepartment)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDepartmentImpl,ProgId_FormaSpiskaSprDepartment,"FormsSpr3.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprDepartment)+" !");
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
