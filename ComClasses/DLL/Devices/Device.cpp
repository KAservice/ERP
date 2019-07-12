//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "UFiskRegImpl.h"
#include "UFiskRegCF.h"
#include "UDisplayPokImpl.h"
#include "UDisplayPokCF.h"
#include "UScanerImpl.h"
#include "UScanerCF.h"

#include "UkasMSKFRImpl.h"
#include "UkasMSKFRCF.h"
#include "U1COnLineFRImpl.h"
#include "U1COnLineFRCF.h"

#include "U1COnLineFRCOMImpl.h"
#include "U1COnLineFRCOMCF.h"
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
//---------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{

	return 1;
}

//-----------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
//if (id_class==CLSID_TFiskRegImpl)
//	{
//	TFiskRegCF * ob=new TFiskRegCF();
//	result=ob->kanQueryInterface(id_interface, ppv);
//	if (result!=-1)
//		{
//		delete ob;
//		}
//	}
//else
if (id_class==CLSID_TDisplayPokImpl)
	{
	TDisplayPokCF * ob=new TDisplayPokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TScanerImpl)
	{
	TScanerCF * ob=new TScanerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
//else if (id_class==CLSID_TkasMSKFRImpl)
//	{
//	TkasMSKFRCF * ob=new TkasMSKFRCF();
//	result=ob->kanQueryInterface(id_interface, ppv);
//	if (result!=-1)
//		{
//		delete ob;
//		}
//	}
//else if (id_class==CLSID_T1COnLineFRImpl)
//	{
//	T1COnLineFRCF * ob=new T1COnLineFRCF();
//	result=ob->kanQueryInterface(id_interface, ppv);
//	if (result!=-1)
//		{
//		delete ob;
//		}
//	}

else if (id_class==CLSID_T1COnLineFRCOMImpl)
	{
	T1COnLineFRCOMCF * ob=new T1COnLineFRCOMCF();
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

//if (icom->kanAddClass(CLSID_TFiskRegImpl,"Oberon.FiskReg.1","Device.dll")!=-1)
//	{
//	ShowMessage("Error! Falid register class - Oberon.FiskReg.1  !");
//	}
if (icom->kanAddClass(CLSID_TDisplayPokImpl,"Oberon.DisplayPok.1","Device.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DisplayPok.1  !");
	}
if (icom->kanAddClass(CLSID_TScanerImpl,"Oberon.Scaner.1","Device.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.Scaner.1  !");
	}

//if (icom->kanAddClass(CLSID_TkasMSKFRImpl,ProgId_kasMSKFR,"Device.dll")!=-1)
//	{
//	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_kasMSKFR)+"  !");
//	}
//if (icom->kanAddClass(CLSID_T1COnLineFRImpl,ProgId_1COnLineFR,"Device.dll")!=-1)
//	{
//	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_1COnLineFR)+"  !");
//	}


if (icom->kanAddClass(CLSID_T1COnLineFRCOMImpl,ProgId_1COnLineFRCOM,"Device.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_1COnLineFRCOM)+"  !");
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

