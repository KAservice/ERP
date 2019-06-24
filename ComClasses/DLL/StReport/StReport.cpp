//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UFormaReportBankCF.h"
#include "UFormaReportBankImpl.h"
#include "UFormaReportOCBRegGoodsCF.h"
#include "UFormaReportOCBRegGoodsImpl.h"
#include "UFormaDialogaRepSaleCheckCF.h"
#include "UFormaDialogaRepSaleCheckImpl.h"
#include "UFormaReportOCBRegVSRaschCF.h"
#include "UFormaReportOCBRegVSRaschImpl.h"
#include "UFormaReportResultRealCF.h"
#include "UFormaReportResultRealImpl.h"
#include "UFormaReportVipuskProdCF.h"
#include "UFormaReportVipuskProdImpl.h"
#include "UFormaReportKartTovaraCF.h"
#include "UFormaReportKartTovaraImpl.h"
#include "UFormaReportKartKlientCF.h"
#include "UFormaReportKartKlientImpl.h"
#include "UFormaReportKalkKartaCF.h"
#include "UFormaReportKalkKartaImpl.h"
#include "UFormaReportOCBRegOstNomCF.h"
#include "UFormaReportOCBRegOstNomImpl.h"
#include "UFormaReportRashodProductCF.h"
#include "UFormaReportRashodProductImpl.h"
#include "UFormaReportOCBPaySaleCF.h"
#include "UFormaReportOCBPaySaleImpl.h"
#include "UFormaReportKassaCF.h"
#include "UFormaReportKassaImpl.h"
#include "UFormaReportDiscountDocCheckCF.h"
#include "UFormaReportDiscountDocCheckImpl.h"
#include "UFormaReportGoodsReportCF.h"
#include "UFormaReportGoodsReportImpl.h"
#include "UFormaDialogaReportPoProjectCF.h"
#include "UFormaDialogaReportPoProjectImpl.h"
#include "UFormaReportOCBRegCardBalanceCF.h"
#include "UFormaReportOCBRegCardBalanceImpl.h"
#include "UFormaReportRealCF.h"
#include "UFormaReportRealImpl.h"
#include "UFormaReportDiscountDocCheckForCashierCF.h"
#include "UFormaReportDiscountDocCheckForCashierImpl.h"
#include "UFormaReportSostProdCF.h"
#include "UFormaReportSostProdImpl.h"
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
if (id_class==CLSID_TFormaReportBankImpl)
	{
	TFormaReportBankCF * ob=new TFormaReportBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportOCBRegGoodsImpl)
	{
	TFormaReportOCBRegGoodsCF * ob=new TFormaReportOCBRegGoodsCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDialogaRepSaleCheckImpl)
	{
	TFormaDialogaRepSaleCheckCF * ob=new TFormaDialogaRepSaleCheckCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportOCBRegVSRaschImpl)
	{
	TFormaReportOCBRegVSRaschCF * ob=new TFormaReportOCBRegVSRaschCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportResultRealImpl)
	{
	TFormaReportResultRealCF * ob=new TFormaReportResultRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportVipuskProdImpl)
	{
	TFormaReportVipuskProdCF * ob=new TFormaReportVipuskProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportKartTovaraImpl)
	{
	TFormaReportKartTovaraCF * ob=new TFormaReportKartTovaraCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportKartKlientImpl)
	{
	TFormaReportKartKlientCF * ob=new TFormaReportKartKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportKalkKartaImpl)
	{
	TFormaReportKalkKartaCF * ob=new TFormaReportKalkKartaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportOCBRegOstNomImpl)
	{
	TFormaReportOCBRegOstNomCF * ob=new TFormaReportOCBRegOstNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportRashodProductImpl)
	{
	TFormaReportRashodProductCF * ob=new TFormaReportRashodProductCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportOCBPaySaleImpl)
	{
	TFormaReportOCBPaySaleCF * ob=new TFormaReportOCBPaySaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportKassaImpl)
	{
	TFormaReportKassaCF * ob=new TFormaReportKassaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportDiscountDocCheckImpl)
	{
	TFormaReportDiscountDocCheckCF * ob=new TFormaReportDiscountDocCheckCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportGoodsReportImpl)
	{
	TFormaReportGoodsReportCF * ob=new TFormaReportGoodsReportCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaDialogaReportPoProjectImpl)
	{
	TFormaDialogaReportPoProjectCF * ob=new TFormaDialogaReportPoProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportOCBRegCardBalanceImpl)
	{
	TFormaReportOCBRegCardBalanceCF * ob=new TFormaReportOCBRegCardBalanceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportRealImpl)
	{
	TFormaReportRealCF * ob=new TFormaReportRealCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportDiscountDocCheckForCashierImpl)
	{
	TFormaReportDiscountDocCheckForCashierCF * ob=new TFormaReportDiscountDocCheckForCashierCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaReportSostProdImpl)
	{
	TFormaReportSostProdCF * ob=new TFormaReportSostProdCF();
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

if (icom->kanAddClass(CLSID_TFormaReportBankImpl,ProgId_FormaReportBank,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportBank)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportOCBRegGoodsImpl,ProgId_FormaReportOCBRegGoods,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaReportOCBRegGoods)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDialogaRepSaleCheckImpl,ProgId_FormaDialogaReportSaleCheck,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDialogaReportSaleCheck)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportOCBRegVSRaschImpl,ProgId_FormaReportOCBRegVSRasch,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportOCBRegVSRasch)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportResultRealImpl,ProgId_FormaDialogaReportResultReal,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDialogaReportResultReal)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportVipuskProdImpl,ProgId_FormaReportVipuskProd,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportVipuskProd)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportKartTovaraImpl,ProgId_FormaReportKartTovara,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportKartTovara)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportKartKlientImpl,ProgId_FormaReportKartKlient,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportKartKlient)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportKalkKartaImpl,ProgId_FormaReportKalkKarta,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportKalkKarta)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportOCBRegOstNomImpl,ProgId_FormaReportOCBRegOstNom,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportOCBRegOstNom)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportRashodProductImpl,ProgId_FormaReportRashodProduct,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportRashodProduct)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportOCBPaySaleImpl,ProgId_FormaReportOCBPaySale,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportOCBPaySale)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportKassaImpl,ProgId_FormaReportKassa,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportKassa)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportDiscountDocCheckImpl,ProgId_FormaReportDiscountDocCheck,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportDiscountDocCheck)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportGoodsReportImpl,ProgId_FormaReportGoodsReport,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportGoodsReport)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaDialogaReportPoProjectImpl,ProgId_FormaDialogaReportPoProject,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaDialogaReportPoProject)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportOCBRegCardBalanceImpl,ProgId_FormaReportOCBCardBalance,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportOCBCardBalance)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaReportRealImpl,ProgId_FormaReportSaleForCashiers,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportSaleForCashiers)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportDiscountDocCheckForCashierImpl,ProgId_FormaReportDiscountForCashiers,"StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaReportDiscountForCashiers)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaReportSostProdImpl,"Oberon.FormaReportSostProd.1","StReport.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaReportSostProd.1  !");
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
