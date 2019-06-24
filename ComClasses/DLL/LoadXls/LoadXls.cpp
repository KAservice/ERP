//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UFormaImportDocPrihNaklCF.h"
#include "UFormaImportDocPrihNaklImpl.h"
#include "UFormaImportSprProducerNomCF.h"
#include "UFormaImportSprProducerNomImpl.h"

#include "UFormaImportSprProducerNeisprImpl.h"
#include "UFormaImportSprProducerNeisprCF.h"
#include "UFormaImportSprProducerDefectImpl.h"
#include "UFormaImportSprProducerDefectCF.h"
#include "UFormaImportSprProducerRabotaImpl.h"
#include "UFormaImportSprProducerRabotaCF.h"

#include "UFormaImportSprProducerSectionImpl.h"
#include "UFormaImportSprProducerSectionCF.h"

#include "UFormaImportSprProducerConditionImpl.h"
#include "UFormaImportSprProducerConditionCF.h"
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
if (id_class==CLSID_TFormaImportDocPrihNaklImpl)
	{

	TFormaImportDocPrihNaklCF * ob=new TFormaImportDocPrihNaklCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaImportSprProducerNomImpl)
	{

	TFormaImportSprProducerNomCF * ob=new TFormaImportSprProducerNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaImportSprProducerNeisprImpl)
	{

	TFormaImportSprProducerNeisprCF * ob=new TFormaImportSprProducerNeisprCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaImportSprProducerDefectImpl)
	{

	TFormaImportSprProducerDefectCF * ob=new TFormaImportSprProducerDefectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaImportSprProducerRabotaImpl)
	{

	TFormaImportSprProducerRabotaCF * ob=new TFormaImportSprProducerRabotaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaImportSprProducerConditionImpl)
	{

	TFormaImportSprProducerConditionCF * ob=new TFormaImportSprProducerConditionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}

else if (id_class==CLSID_TFormaImportSprProducerSectionImpl)
	{

	TFormaImportSprProducerSectionCF * ob=new TFormaImportSprProducerSectionCF();
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

if (icom->kanAddClass(CLSID_TFormaImportDocPrihNaklImpl,ProgId_FormaImportDocPrihNakl,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportDocPrihNakl)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaImportSprProducerNomImpl,ProgId_FormaImportSprProducerNom,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerNom)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaImportSprProducerNeisprImpl,ProgId_FormaImportSprProducerNeispr,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerNeispr)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaImportSprProducerDefectImpl,ProgId_FormaImportSprProducerDefect,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerDefect)+" !");
	}

	if (icom->kanAddClass(CLSID_TFormaImportSprProducerRabotaImpl,ProgId_FormaImportSprProducerRabota,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerRabota)+" !");
	}

	if (icom->kanAddClass(CLSID_TFormaImportSprProducerConditionImpl,ProgId_FormaImportSprProducerCondition,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerCondition)+" !");
	}

	if (icom->kanAddClass(CLSID_TFormaImportSprProducerSectionImpl,ProgId_FormaImportSprProducerSection,"LoadXls.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaImportSprProducerSection)+" !");
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