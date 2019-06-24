//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDMRegGoodsCF.h"
#include "UDMRegGoodsImpl.h"
#include "UDMRegBankCF.h"
#include "UDMRegBankImpl.h"
#include "UDMRegAdvanceCustomerCF.h"
#include "UDMRegAdvanceCustomerImpl.h"
#include "UDMRegKassaCF.h"
#include "UDMRegKassaImpl.h"
#include "UDMRegOstNomCF.h"
#include "UDMRegOstNomImpl.h"
#include "UDMRegPaySaleCF.h"
#include "UDMRegPaySaleImpl.h"
#include "UDMRegVsRaschCF.h"
#include "UDMRegVsRaschImpl.h"
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
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TDMRegGoodsImpl)
	{
	TDMRegGoodsCF * ob=new TDMRegGoodsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegBankImpl)
	{
	TDMRegBankCF * ob=new TDMRegBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegAdvanceCustomerImpl)
	{
	TDMRegAdvanceCustomerCF * ob=new TDMRegAdvanceCustomerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegKassaImpl)
	{
	TDMRegKassaCF * ob=new TDMRegKassaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegOstNomImpl)
	{
	TDMRegOstNomCF * ob=new TDMRegOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegPaySaleImpl)
	{
	TDMRegPaySaleCF * ob=new TDMRegPaySaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMRegVsRaschImpl)
	{
	TDMRegVsRaschCF * ob=new TDMRegVsRaschCF();
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

if (icom->kanAddClass(CLSID_TDMRegGoodsImpl,"Oberon.DMRegGoods.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegGoods.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegBankImpl,"Oberon.DMRegBank.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegBank.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegAdvanceCustomerImpl,"Oberon.DMRegAdvanceCustomer.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegAdvanceCustomer.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegKassaImpl,"Oberon.DMRegKassa.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegKassa.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegOstNomImpl,"Oberon.DMRegOstNom.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegOstNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegPaySaleImpl,"Oberon.DMRegPaySale.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegPaySale.1  !");
	}
if (icom->kanAddClass(CLSID_TDMRegVsRaschImpl,"Oberon.DMRegVsRasch.1","DMReg.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMRegVsRasch.1  !");
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

