//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"



#include "UART_DMSprInfBlockCF.h"
#include "UART_DMSprInfBlockImpl.h"
#include "UART_DMSprInfBlockGrpCF.h"
#include "UART_DMSprInfBlockGrpImpl.h"
#include "UART_DMSprImageCF.h"
#include "UART_DMSprImageImpl.h"
#include "UART_DMSprImageGrpCF.h"
#include "UART_DMSprImageGrpImpl.h"

#include "UART_DMSprInfBlockSostavCF.h"
#include "UART_DMSprInfBlockSostavImpl.h"


#include "UART_DMSprNaborInfBlockCF.h"
#include "UART_DMSprNaborInfBlockImpl.h"
#include "UART_DMSprNaborInfBlockGrpCF.h"
#include "UART_DMSprNaborInfBlockGrpImpl.h"
#include "UART_DMSprNaborInfBlockSostavCF.h"
#include "UART_DMSprNaborInfBlockSostavImpl.h"
#include "UART_DMSprNaborInfBlockSostavGrpCF.h"
#include "UART_DMSprNaborInfBlockSostavGrpImpl.h"


#include "UHLP_DMSprInfBlockCF.h"
#include "UHLP_DMSprInfBlockImpl.h"
#include "UHLP_DMSprInfBlockGrpCF.h"
#include "UHLP_DMSprInfBlockGrpImpl.h"
#include "UHLP_DMSprImageCF.h"
#include "UHLP_DMSprImageImpl.h"
#include "UHLP_DMSprImageGrpCF.h"
#include "UHLP_DMSprImageGrpImpl.h"

#include "UHLP_DMSprInfBlockSostavCF.h"
#include "UHLP_DMSprInfBlockSostavImpl.h"


#include "UHLP_DMSprNaborInfBlockCF.h"
#include "UHLP_DMSprNaborInfBlockImpl.h"
#include "UHLP_DMSprNaborInfBlockGrpCF.h"
#include "UHLP_DMSprNaborInfBlockGrpImpl.h"
#include "UHLP_DMSprNaborInfBlockSostavCF.h"
#include "UHLP_DMSprNaborInfBlockSostavImpl.h"
#include "UHLP_DMSprNaborInfBlockSostavGrpCF.h"
#include "UHLP_DMSprNaborInfBlockSostavGrpImpl.h"


#include "UHLP_DMSprInfBlockPrivCF.h"
#include "UHLP_DMSprInfBlockPrivImpl.h"
#include "UART_DMSprInfBlockPrivCF.h"
#include "UART_DMSprInfBlockPrivImpl.h"
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
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;

if (id_class==CLSID_TART_DMSprImageImpl)
	{

	TART_DMSprImageCF * ob=new TART_DMSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprImageGrpImpl)
	{
	TART_DMSprImageGrpCF * ob=new TART_DMSprImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprInfBlockImpl)
	{
	TART_DMSprInfBlockCF * ob=new TART_DMSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprInfBlockSostavImpl)
	{
	TART_DMSprInfBlockSostavCF * ob=new TART_DMSprInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprInfBlockGrpImpl)
	{
	TART_DMSprInfBlockGrpCF * ob=new TART_DMSprInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprNaborInfBlockImpl)
	{
	TART_DMSprNaborInfBlockCF * ob=new TART_DMSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprNaborInfBlockGrpImpl)
	{
	TART_DMSprNaborInfBlockGrpCF * ob=new TART_DMSprNaborInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprNaborInfBlockSostavImpl)
	{
	TART_DMSprNaborInfBlockSostavCF * ob=new TART_DMSprNaborInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_DMSprNaborInfBlockSostavGrpImpl)
	{
	TART_DMSprNaborInfBlockSostavGrpCF * ob=new TART_DMSprNaborInfBlockSostavGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}






else if (id_class==CLSID_THLP_DMSprImageImpl)
	{

	THLP_DMSprImageCF * ob=new THLP_DMSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprImageGrpImpl)
	{
	THLP_DMSprImageGrpCF * ob=new THLP_DMSprImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprInfBlockImpl)
	{
	THLP_DMSprInfBlockCF * ob=new THLP_DMSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprInfBlockSostavImpl)
	{
	THLP_DMSprInfBlockSostavCF * ob=new THLP_DMSprInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprInfBlockGrpImpl)
	{
	THLP_DMSprInfBlockGrpCF * ob=new THLP_DMSprInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprNaborInfBlockImpl)
	{
	THLP_DMSprNaborInfBlockCF * ob=new THLP_DMSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprNaborInfBlockGrpImpl)
	{
	THLP_DMSprNaborInfBlockGrpCF * ob=new THLP_DMSprNaborInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprNaborInfBlockSostavImpl)
	{
	THLP_DMSprNaborInfBlockSostavCF * ob=new THLP_DMSprNaborInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_DMSprNaborInfBlockSostavGrpImpl)
	{
	THLP_DMSprNaborInfBlockSostavGrpCF * ob=new THLP_DMSprNaborInfBlockSostavGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_THLP_DMSprInfBlockPrivImpl)
	{
	THLP_DMSprInfBlockPrivCF * ob=new THLP_DMSprInfBlockPrivCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TART_DMSprInfBlockPrivImpl)
	{
	TART_DMSprInfBlockPrivCF * ob=new TART_DMSprInfBlockPrivCF();
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



if (icom->kanAddClass(CLSID_TART_DMSprImageImpl,ProgId_ART_DMSprImage,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprImage)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprImageGrpImpl,ProgId_ART_DMSprImageGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprImageGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TART_DMSprInfBlockImpl,ProgId_ART_DMSprInfBlock,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprInfBlockGrpImpl,ProgId_ART_DMSprInfBlockGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprInfBlockGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprInfBlockSostavImpl,ProgId_ART_DMSprInfBlockSostav,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprInfBlockSostav)+" !");
	}





if (icom->kanAddClass(CLSID_TART_DMSprNaborInfBlockImpl,ProgId_ART_DMSprNaborInfBlock,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprNaborInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprNaborInfBlockGrpImpl,ProgId_ART_DMSprNaborInfBlockGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprNaborInfBlockGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprNaborInfBlockSostavImpl,ProgId_ART_DMSprNaborInfBlockSostav,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprNaborInfBlockSostav)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprNaborInfBlockSostavGrpImpl,ProgId_ART_DMSprNaborInfBlockSostavGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprNaborInfBlockSostavGrp)+" !");
	}



 if (icom->kanAddClass(CLSID_THLP_DMSprImageImpl,ProgId_HLP_DMSprImage,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprImage)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprImageGrpImpl,ProgId_HLP_DMSprImageGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprImageGrp)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprInfBlockImpl,ProgId_HLP_DMSprInfBlock,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprInfBlockGrpImpl,ProgId_HLP_DMSprInfBlockGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprInfBlockGrp)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprInfBlockSostavImpl,ProgId_HLP_DMSprInfBlockSostav,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprInfBlockSostav)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprNaborInfBlockImpl,ProgId_HLP_DMSprNaborInfBlock,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprNaborInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprNaborInfBlockGrpImpl,ProgId_HLP_DMSprNaborInfBlockGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprNaborInfBlockGrp)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprNaborInfBlockSostavImpl,ProgId_HLP_DMSprNaborInfBlockSostav,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprNaborInfBlockSostav)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_DMSprNaborInfBlockSostavGrpImpl,ProgId_HLP_DMSprNaborInfBlockSostavGrp,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprNaborInfBlockSostavGrp)+" !");
	}


if (icom->kanAddClass(CLSID_THLP_DMSprInfBlockPrivImpl,ProgId_HLP_DMSprInfBlockPriv,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_HLP_DMSprInfBlockPriv)+" !");
	}
if (icom->kanAddClass(CLSID_TART_DMSprInfBlockPrivImpl,ProgId_ART_DMSprInfBlockPriv,"PDMHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_ART_DMSprInfBlockPriv)+" !");
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
