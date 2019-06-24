//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"

#include "UREM_FormaZayavkaDvImpl.h"
#include "UREM_FormaZayavkaDvCF.h"
#include "UREM_FormaZayavkaImpl.h"
#include "UREM_FormaZayavkaCF.h"
#include "UREM_FormaGurZImpl.h"
#include "UREM_FormaGurZCF.h"

#include "UREM_FormaElementaSprSostCustQueryImpl.h"
#include "UREM_FormaElementaSprSostCustQueryCF.h"
#include "UREM_FormaSpiskaSprSostCustQueryImpl.h"
#include "UREM_FormaSpiskaSprSostCustQueryCF.h"
#include "UREM_FormaCustQueryDvImpl.h"
#include "UREM_FormaCustQueryDvCF.h"

#include "UREM_FormaCustQueryImpl.h"
#include "UREM_FormaCustQueryCF.h"
#include "UREM_FormaGurCustQueryImpl.h"
#include "UREM_FormaGurCustQueryCF.h"
#include "UREM_FormaElementaZayavkaImageImpl.h"
#include "UREM_FormaElementaZayavkaImageCF.h"
#include "UREM_FormaSpiskaZayavkaImageImpl.h"
#include "UREM_FormaSpiskaZayavkaImageCF.h"

#include "UREM_FormaGurZDopImpl.h"
#include "UREM_FormaGurZDopCF.h"

#include "UREM_FormaGurCustQueryDetalImpl.h"
#include "UREM_FormaGurCustQueryDetalCF.h"

#include "UREM_FormaInfoPriemImpl.h"
#include "UREM_FormaInfoPriemCF.h"


#include "UREM_FormaZayavkaPredvImpl.h"
#include "UREM_FormaZayavkaPredvCF.h"
#include "UREM_FormaGurZPredvImpl.h"
#include "UREM_FormaGurZPredvCF.h"
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

if (id_class==CLSID_TREM_FormaZayavkaDvImpl)
	{
	TREM_FormaZayavkaDvCF * ob=new TREM_FormaZayavkaDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaZayavkaImpl)
	{
	TREM_FormaZayavkaCF * ob=new TREM_FormaZayavkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurZImpl)
	{
	TREM_FormaGurZCF * ob=new TREM_FormaGurZCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TREM_FormaZayavkaPredvImpl)
	{
	TREM_FormaZayavkaPredvCF * ob=new TREM_FormaZayavkaPredvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurZPredvImpl)
	{
	TREM_FormaGurZPredvCF * ob=new TREM_FormaGurZPredvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaSprSostCustQueryImpl)
	{
	TREM_FormaElementaSprSostCustQueryCF * ob=new TREM_FormaElementaSprSostCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaSprSostCustQueryImpl)
	{
	TREM_FormaSpiskaSprSostCustQueryCF * ob=new TREM_FormaSpiskaSprSostCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaCustQueryDvImpl)
	{
	TREM_FormaCustQueryDvCF * ob=new TREM_FormaCustQueryDvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaCustQueryImpl)
	{
	TREM_FormaCustQueryCF * ob=new TREM_FormaCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurCustQueryImpl)
	{
	TREM_FormaGurCustQueryCF * ob=new TREM_FormaGurCustQueryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaElementaZayavkaImageImpl)
	{
	TREM_FormaElementaZayavkaImageCF * ob=new TREM_FormaElementaZayavkaImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaSpiskaZayavkaImageImpl)
	{
	TREM_FormaSpiskaZayavkaImageCF * ob=new TREM_FormaSpiskaZayavkaImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurZDopImpl)
	{
	TREM_FormaGurZDopCF * ob=new TREM_FormaGurZDopCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaGurCustQueryDetalImpl)
	{
	TREM_FormaGurCustQueryDetalCF * ob=new TREM_FormaGurCustQueryDetalCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TREM_FormaInfoPriemImpl)
	{
	TREM_FormaInfoPriemCF * ob=new TREM_FormaInfoPriemCF();
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


if (icom->kanAddClass(CLSID_TREM_FormaZayavkaDvImpl,"Oberon.REM_FormaZayavkaDv.1","RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.REM_FormaZayavkaDv.1  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaZayavkaImpl,ProgId_REM_FormaZayavka,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaZayavka)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaGurZImpl,ProgId_REM_FormaGurZ,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurZ)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaSprSostCustQueryImpl,ProgId_REM_FormaSpiskaSprSostCustQuery,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaSprSostCustQuery)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaSprSostCustQueryImpl,ProgId_REM_FormaElementaSprSostCustQuery,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaSprSostCustQuery)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaCustQueryDvImpl,ProgId_REM_FormaCustQueryDv,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaCustQueryDv)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaCustQueryImpl,ProgId_REM_FormaCustQuery,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaCustQuery)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaGurCustQueryImpl,ProgId_REM_FormaGurCustQuery,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurCustQuery)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaElementaZayavkaImageImpl,ProgId_REM_FormaElementaZayavkaImage,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaElementaZayavkaImage)+" !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaSpiskaZayavkaImageImpl,ProgId_REM_FormaSpiskaZayavkaImage,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaSpiskaZayavkaImage)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaGurZDopImpl,ProgId_REM_FormaGurZDop,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurZDop)+" !");
	}


if (icom->kanAddClass(CLSID_TREM_FormaGurCustQueryDetalImpl,ProgId_REM_FormaGurCustQueryDetal,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurCustQueryDetal)+" !");
	}

if (icom->kanAddClass(CLSID_TREM_FormaInfoPriemImpl,ProgId_REM_FormaInfoPriem,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaInfoPriem)+" !");
	}



if (icom->kanAddClass(CLSID_TREM_FormaZayavkaPredvImpl,ProgId_REM_FormaZayavkaPredv,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaZayavkaPredv)+"  !");
	}
if (icom->kanAddClass(CLSID_TREM_FormaGurZPredvImpl,ProgId_REM_FormaGurZPredv,"RemFormsZayavka.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_REM_FormaGurZPredv)+" !");
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
