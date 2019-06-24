//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"



#include "UART_FormaSpiskaSprImageImpl.h"
#include "UART_FormaSpiskaSprImageCF.h"
#include "UART_FormaElementaSprImageGrpImpl.h"
#include "UART_FormaElementaSprImageGrpCF.h"
#include "UART_FormaElementaSprImageImpl.h"
#include "UART_FormaElementaSprImageCF.h"


#include "UART_FormaSpiskaSprInfBlockImpl.h"
#include "UART_FormaSpiskaSprInfBlockCF.h"
#include "UART_FormaElementaSprInfBlockGrpImpl.h"
#include "UART_FormaElementaSprInfBlockGrpCF.h"
#include "UART_FormaElementaSprInfBlockImpl.h"
#include "UART_FormaElementaSprInfBlockCF.h"

#include "UART_FormaSpiskaSprInfBlockSostavImpl.h"
#include "UART_FormaSpiskaSprInfBlockSostavCF.h"

#include "UART_FormaSpiskaSprNaborInfBlockImpl.h"
#include "UART_FormaSpiskaSprNaborInfBlockCF.h"
#include "UART_FormaElementaSprNaborInfBlockGrpImpl.h"
#include "UART_FormaElementaSprNaborInfBlockGrpCF.h"
#include "UART_FormaElementaSprNaborInfBlockImpl.h"
#include "UART_FormaElementaSprNaborInfBlockCF.h"


#include "UART_FormaSpiskaSprNaborInfBlockSostavImpl.h"
#include "UART_FormaSpiskaSprNaborInfBlockSostavCF.h"
#include "UART_FormaElementaSprNaborInfBlockSostavGrpImpl.h"
#include "UART_FormaElementaSprNaborInfBlockSostavGrpCF.h"




#include "UHLP_FormaSpiskaSprImageImpl.h"
#include "UHLP_FormaSpiskaSprImageCF.h"
#include "UHLP_FormaElementaSprImageGrpImpl.h"
#include "UHLP_FormaElementaSprImageGrpCF.h"
#include "UHLP_FormaElementaSprImageImpl.h"
#include "UHLP_FormaElementaSprImageCF.h"


#include "UHLP_FormaSpiskaSprInfBlockImpl.h"
#include "UHLP_FormaSpiskaSprInfBlockCF.h"
#include "UHLP_FormaElementaSprInfBlockGrpImpl.h"
#include "UHLP_FormaElementaSprInfBlockGrpCF.h"
#include "UHLP_FormaElementaSprInfBlockImpl.h"
#include "UHLP_FormaElementaSprInfBlockCF.h"

#include "UHLP_FormaSpiskaSprInfBlockSostavImpl.h"
#include "UHLP_FormaSpiskaSprInfBlockSostavCF.h"

#include "UHLP_FormaSpiskaSprNaborInfBlockImpl.h"
#include "UHLP_FormaSpiskaSprNaborInfBlockCF.h"
#include "UHLP_FormaElementaSprNaborInfBlockGrpImpl.h"
#include "UHLP_FormaElementaSprNaborInfBlockGrpCF.h"
#include "UHLP_FormaElementaSprNaborInfBlockImpl.h"
#include "UHLP_FormaElementaSprNaborInfBlockCF.h"


#include "UHLP_FormaSpiskaSprNaborInfBlockSostavImpl.h"
#include "UHLP_FormaSpiskaSprNaborInfBlockSostavCF.h"
#include "UHLP_FormaElementaSprNaborInfBlockSostavGrpImpl.h"
#include "UHLP_FormaElementaSprNaborInfBlockSostavGrpCF.h"


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


if (id_class==CLSID_TART_FormaSpiskaSprImageImpl)
	{
	TART_FormaSpiskaSprImageCF * ob=new TART_FormaSpiskaSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprImageImpl)
	{
	TART_FormaElementaSprImageCF * ob=new TART_FormaElementaSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprImageGrpImpl)
	{
	TART_FormaElementaSprImageGrpCF * ob=new TART_FormaElementaSprImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_TART_FormaSpiskaSprInfBlockImpl)
	{
	TART_FormaSpiskaSprInfBlockCF * ob=new TART_FormaSpiskaSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprInfBlockImpl)
	{
	TART_FormaElementaSprInfBlockCF * ob=new TART_FormaElementaSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprInfBlockGrpImpl)
	{
	TART_FormaElementaSprInfBlockGrpCF * ob=new TART_FormaElementaSprInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaSpiskaSprInfBlockSostavImpl)
	{
	TART_FormaSpiskaSprInfBlockSostavCF * ob=new TART_FormaSpiskaSprInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_TART_FormaSpiskaSprNaborInfBlockImpl)
	{
	TART_FormaSpiskaSprNaborInfBlockCF * ob=new TART_FormaSpiskaSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprNaborInfBlockImpl)
	{
	TART_FormaElementaSprNaborInfBlockCF * ob=new TART_FormaElementaSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprNaborInfBlockGrpImpl)
	{
	TART_FormaElementaSprNaborInfBlockGrpCF * ob=new TART_FormaElementaSprNaborInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl)
	{
	TART_FormaSpiskaSprNaborInfBlockSostavCF * ob=new TART_FormaSpiskaSprNaborInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl)
	{
	TART_FormaElementaSprNaborInfBlockSostavGrpCF * ob=new TART_FormaElementaSprNaborInfBlockSostavGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}





















else  if (id_class==CLSID_THLP_FormaSpiskaSprImageImpl)
	{
	THLP_FormaSpiskaSprImageCF * ob=new THLP_FormaSpiskaSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprImageImpl)
	{
	THLP_FormaElementaSprImageCF * ob=new THLP_FormaElementaSprImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprImageGrpImpl)
	{
	THLP_FormaElementaSprImageGrpCF * ob=new THLP_FormaElementaSprImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_THLP_FormaSpiskaSprInfBlockImpl)
	{
	THLP_FormaSpiskaSprInfBlockCF * ob=new THLP_FormaSpiskaSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprInfBlockImpl)
	{
	THLP_FormaElementaSprInfBlockCF * ob=new THLP_FormaElementaSprInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprInfBlockGrpImpl)
	{
	THLP_FormaElementaSprInfBlockGrpCF * ob=new THLP_FormaElementaSprInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaSpiskaSprInfBlockSostavImpl)
	{
	THLP_FormaSpiskaSprInfBlockSostavCF * ob=new THLP_FormaSpiskaSprInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_THLP_FormaSpiskaSprNaborInfBlockImpl)
	{
	THLP_FormaSpiskaSprNaborInfBlockCF * ob=new THLP_FormaSpiskaSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprNaborInfBlockImpl)
	{
	THLP_FormaElementaSprNaborInfBlockCF * ob=new THLP_FormaElementaSprNaborInfBlockCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl)
	{
	THLP_FormaElementaSprNaborInfBlockGrpCF * ob=new THLP_FormaElementaSprNaborInfBlockGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}



else if (id_class==CLSID_THLP_FormaSpiskaSprNaborInfBlockSostavImpl)
	{
	THLP_FormaSpiskaSprNaborInfBlockSostavCF * ob=new THLP_FormaSpiskaSprNaborInfBlockSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_THLP_FormaElementaSprNaborInfBlockSostavGrpImpl)
	{
	THLP_FormaElementaSprNaborInfBlockSostavGrpCF * ob=new THLP_FormaElementaSprNaborInfBlockSostavGrpCF();
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



if (icom->kanAddClass(CLSID_TART_FormaElementaSprImageGrpImpl,ProgId_ART_FormaElementaSprImageGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprImageGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaElementaSprImageImpl,ProgId_ART_FormaElementaSprImage,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprImage)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaSpiskaSprImageImpl,ProgId_ART_FormaSpiskaSprImage,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaSpiskaSprImage)+" !");
	}






if (icom->kanAddClass(CLSID_TART_FormaElementaSprInfBlockGrpImpl,ProgId_ART_FormaElementaSprInfBlockGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprInfBlockGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaElementaSprInfBlockImpl,ProgId_ART_FormaElementaSprInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaSpiskaSprInfBlockImpl,ProgId_ART_FormaSpiskaSprInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaSpiskaSprInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_TART_FormaSpiskaSprInfBlockSostavImpl,ProgId_ART_FormaSpiskaSprInfBlockSostav,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaSpiskaSprInfBlockSostav)+" !");
	}


if (icom->kanAddClass(CLSID_TART_FormaElementaSprNaborInfBlockGrpImpl,ProgId_ART_FormaElementaSprNaborInfBlockGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprNaborInfBlockGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaElementaSprNaborInfBlockImpl,ProgId_ART_FormaElementaSprNaborInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprNaborInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaSpiskaSprNaborInfBlockImpl,ProgId_ART_FormaSpiskaSprNaborInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaSpiskaSprNaborInfBlock)+" !");
	}



if (icom->kanAddClass(CLSID_TART_FormaElementaSprNaborInfBlockSostavGrpImpl,ProgId_ART_FormaElementaSprNaborInfBlockSostavGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaElementaSprNaborInfBlockSostavGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TART_FormaSpiskaSprNaborInfBlockSostavImpl,ProgId_ART_FormaSpiskaSprNaborInfBlockSostav,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_ART_FormaSpiskaSprNaborInfBlockSostav)+" !");
	}





	if (icom->kanAddClass(CLSID_THLP_FormaElementaSprImageGrpImpl,ProgId_HLP_FormaElementaSprImageGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprImageGrp)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaElementaSprImageImpl,ProgId_HLP_FormaElementaSprImage,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprImage)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaSpiskaSprImageImpl,ProgId_HLP_FormaSpiskaSprImage,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaSpiskaSprImage)+" !");
	}






if (icom->kanAddClass(CLSID_THLP_FormaElementaSprInfBlockGrpImpl,ProgId_HLP_FormaElementaSprInfBlockGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprInfBlockGrp)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaElementaSprInfBlockImpl,ProgId_HLP_FormaElementaSprInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaSpiskaSprInfBlockImpl,ProgId_HLP_FormaSpiskaSprInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaSpiskaSprInfBlock)+" !");
	}
if (icom->kanAddClass(CLSID_THLP_FormaSpiskaSprInfBlockSostavImpl,ProgId_HLP_FormaSpiskaSprInfBlockSostav,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaSpiskaSprInfBlockSostav)+" !");
	}


if (icom->kanAddClass(CLSID_THLP_FormaElementaSprNaborInfBlockGrpImpl,ProgId_HLP_FormaElementaSprNaborInfBlockGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprNaborInfBlockGrp)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaElementaSprNaborInfBlockImpl,ProgId_HLP_FormaElementaSprNaborInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprNaborInfBlock)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaSpiskaSprNaborInfBlockImpl,ProgId_HLP_FormaSpiskaSprNaborInfBlock,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaSpiskaSprNaborInfBlock)+" !");
	}



if (icom->kanAddClass(CLSID_THLP_FormaElementaSprNaborInfBlockSostavGrpImpl,ProgId_HLP_FormaElementaSprNaborInfBlockSostavGrp,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaElementaSprNaborInfBlockSostavGrp)+" !");
	}

if (icom->kanAddClass(CLSID_THLP_FormaSpiskaSprNaborInfBlockSostavImpl,ProgId_HLP_FormaSpiskaSprNaborInfBlockSostav,"PFormsHlp.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_HLP_FormaSpiskaSprNaborInfBlockSostav)+" !");
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
