//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UDMInterfMainMenuGrpImpl.h"
#include "UDMInterfMainMenuGrpCF.h"
#include "UDMInterfMainMenuImpl.h"
#include "UDMInterfMainMenuCF.h"
#include "UDMInterfToolBarImpl.h"
#include "UDMInterfToolBarCF.h"
#include "UDMObjectBaseGrpImpl.h"
#include "UDMObjectBaseGrpCF.h"
#include "UDMObjectBasePrivImpl.h"
#include "UDMObjectBasePrivCF.h"
#include "UFormaElementaInterfMainMenuGrpImpl.h"
#include "UFormaElementaInterfMainMenuGrpCF.h"
#include "UFormaSpiskaInterfMainMenuImpl.h"
#include "UFormaSpiskaInterfMainMenuCF.h"
#include "UFormaSpiskaInterfToolBarImpl.h"
#include "UFormaSpiskaInterfToolBarCF.h"
#include "UFormaElementaObjectBaseGrpImpl.h"
#include "UFormaElementaObjectBaseGrpCF.h"
#include "UFormaSpiskaObjectBasePrivImpl.h"
#include "UFormaSpiskaObjectBasePrivCF.h"
#include "UDMSprProgramModuleImpl.h"
#include "UDMSprProgramModuleCF.h"
#include "UFormaElementaSprProgramModuleImpl.h"
#include "UFormaElementaSprProgramModuleCF.h"
#include "UFormaSpiskaSprProgramModuleImpl.h"
#include "UFormaSpiskaSprProgramModuleCF.h"

#include "UDMProgramSetupImpl.h"
#include "UDMProgramSetupCF.h"

#include "UDMInterfMainMenuParImpl.h"
#include "UDMInterfMainMenuParCF.h"
#include "UFormaSpiskaInterfMainMenuParImpl.h"
#include "UFormaSpiskaInterfMainMenuParCF.h"
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

TDM * DM=0;


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
//---------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TDMInterfMainMenuGrpImpl)
	{
	TDMInterfMainMenuGrpCF * ob=new TDMInterfMainMenuGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMInterfMainMenuImpl)
	{
	TDMInterfMainMenuCF * ob=new TDMInterfMainMenuCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMInterfMainMenuParImpl)
	{
	TDMInterfMainMenuParCF * ob=new TDMInterfMainMenuParCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaInterfMainMenuParImpl)
	{
	TFormaSpiskaInterfMainMenuParCF * ob=new TFormaSpiskaInterfMainMenuParCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMInterfToolBarImpl)
	{
	TDMInterfToolBarCF * ob=new TDMInterfToolBarCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMObjectBaseGrpImpl)
	{
	TDMObjectBaseGrpCF * ob=new TDMObjectBaseGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMObjectBasePrivImpl)
	{
	TDMObjectBasePrivCF * ob=new TDMObjectBasePrivCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaInterfMainMenuGrpImpl)
	{
	TFormaElementaInterfMainMenuGrpCF * ob=new TFormaElementaInterfMainMenuGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaInterfMainMenuImpl)
	{
	TFormaSpiskaInterfMainMenuCF * ob=new TFormaSpiskaInterfMainMenuCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaInterfToolBarImpl)
	{
	TFormaSpiskaInterfToolBarCF * ob=new TFormaSpiskaInterfToolBarCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaObjectBaseGrpImpl)
	{
	TFormaElementaObjectBaseGrpCF * ob=new TFormaElementaObjectBaseGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaObjectBasePrivImpl)
	{
	TFormaSpiskaObjectBasePrivCF * ob=new TFormaSpiskaObjectBasePrivCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMSprProgramModuleImpl)
	{
	TDMSprProgramModuleCF * ob=new TDMSprProgramModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaElementaSprProgramModuleImpl)
	{
	TFormaElementaSprProgramModuleCF * ob=new TFormaElementaSprProgramModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaSprProgramModuleImpl)
	{
	TFormaSpiskaSprProgramModuleCF * ob=new TFormaSpiskaSprProgramModuleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMProgramSetupImpl)
	{
	TDMProgramSetupCF * ob=new TDMProgramSetupCF();
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

if (icom->kanAddClass(CLSID_TDMInterfMainMenuGrpImpl,ProgId_DMInterfMainMenuGrp,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMInterfMainMenuGrp)+"!");
	}
if (icom->kanAddClass(CLSID_TDMInterfMainMenuImpl,ProgId_DMInterfMainMenu,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMInterfMainMenu)+"!");
	}
if (icom->kanAddClass(CLSID_TDMInterfMainMenuParImpl,ProgId_DMInterfMainMenuPar,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMInterfMainMenuPar)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaInterfMainMenuParImpl,ProgId_FormaSpiskaInterfMainMenuPar,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaInterfMainMenuPar)+"!");
	}

if (icom->kanAddClass(CLSID_TDMInterfToolBarImpl,ProgId_DMInterfToolBar,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMInterfToolBar)+"!");
	}
if (icom->kanAddClass(CLSID_TDMObjectBaseGrpImpl,ProgId_DMObjectBaseGrp,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMObjectBaseGrp)+"");
	}
if (icom->kanAddClass(CLSID_TDMObjectBasePrivImpl,ProgId_DMObjectBasePriv,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMObjectBasePriv)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaInterfMainMenuGrpImpl,ProgId_FormaElementaInterfMainMenuGrp,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaInterfMainMenuGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaInterfMainMenuImpl,ProgId_FormaSpiskaInterfMainMenu,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaInterfMainMenu)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaInterfToolBarImpl,ProgId_FormaSpiskaInterfToolBar,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaSpiskaInterfToolBar)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaObjectBaseGrpImpl,"Oberon.FormaElementaObjectBaseGrp.1","Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaObjectBaseGrp.1!");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaObjectBasePrivImpl,ProgId_FormaSpiskaObjectBasePriv,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaObjectBasePriv)+"!");
	}
if (icom->kanAddClass(CLSID_TDMSprProgramModuleImpl,ProgId_DMSprProgramModule,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProgramModule)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprProgramModuleImpl,ProgId_FormaElementaSprProgramModule,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProgramModule)+"!");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprProgramModuleImpl,ProgId_FormaSpiskaSprProgramModule,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProgramModule)+"!");
	}

if (icom->kanAddClass(CLSID_TDMProgramSetupImpl,ProgId_DMProgramSetup,"Interface.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMProgramSetup)+"!");
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

