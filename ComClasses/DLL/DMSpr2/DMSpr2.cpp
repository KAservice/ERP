//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "GlobalInterface.h"

#include "UDMSprFactorImpl.h"
#include "UDMSprFactorCF.h"
#include "UDMSprFactorValueImpl.h"
#include "UDMSprFactorValueCF.h"
#include "UDMSprGrpProduceImpl.h"
#include "UDMSprGrpProduceCF.h"
#include "UDMSprProduceImpl.h"
#include "UDMSprProduceCF.h"
#include "UDMSprGrpLossFactorImpl.h"
#include "UDMSprGrpLossFactorCF.h"
#include "UDMSprLossFactorImpl.h"
#include "UDMSprLossFactorCF.h"
#include "UDMSprLossFactorValueImpl.h"
#include "UDMSprLossFactorValueCF.h"
#include "UDMSprNomFindImpl.h"
#include "UDMSprNomFindCF.h"
#include "UDMSprInetCatalogImpl.h"
#include "UDMSprInetCatalogCF.h"
#include "UDMSprGrpNomInetCatalogImpl.h"
#include "UDMSprGrpNomInetCatalogCF.h"
#include "UDMSprNomInetCatalogImpl.h"
#include "UDMSprNomInetCatalogCF.h"
#include "UDMSprPropertiesGrpImpl.h"
#include "UDMSprPropertiesGrpCF.h"
#include "UDMSprPropertiesImpl.h"
#include "UDMSprPropertiesCF.h"
#include "UDMSprPropertiesValuesListImpl.h"
#include "UDMSprPropertiesValuesListCF.h"
#include "UDMSprNomPropertiesValueImpl.h"
#include "UDMSprNomPropertiesValueCF.h"
#include "UDMSprVidImageImpl.h"
#include "UDMSprVidImageCF.h"
#include "UDMSprVidImageGrpImpl.h"
#include "UDMSprVidImageGrpCF.h"
#include "UDMSprNomImageImpl.h"
#include "UDMSprNomImageCF.h"

#include "UDMSprPropertiesNaborImpl.h"
#include "UDMSprPropertiesNaborCF.h"
#include "UDMSprPropertiesNaborGrpImpl.h"
#include "UDMSprPropertiesNaborGrpCF.h"
#include "UDMSprPropertiesNaborSostavImpl.h"
#include "UDMSprPropertiesNaborSostavCF.h"

#include "UDMSprTypeNachislImpl.h"
#include "UDMSprTypeNachislCF.h"
#include "UDMSprNachislImpl.h"
#include "UDMSprNachislCF.h"

#include "UDMSprProducerNomGrpImpl.h"
#include "UDMSprProducerNomGrpCF.h"
#include "UDMSprProducerNomImpl.h"
#include "UDMSprProducerNomCF.h"
#include "UDMSprProducerPriceImpl.h"
#include "UDMSprProducerPriceCF.h"
#include "UDMSprProducerEdImpl.h"
#include "UDMSprProducerEdCF.h"

#include "UDMSprProducerImpl.h"
#include "UDMSprProducerCF.h"

#include "UDMSprProducerTypePriceImpl.h"
#include "UDMSprProducerTypePriceCF.h"

#include "UDMSprTypeAnalogImpl.h"
#include "UDMSprTypeAnalogCF.h"
#include "UDMSprNomAnalogImpl.h"
#include "UDMSprNomAnalogCF.h"


#include "UDMSprCustomerAccountImpl.h"
#include "UDMSprCustomerAccountCF.h"
#include "UDMSprCustomerAccountGrpImpl.h"
#include "UDMSprCustomerAccountGrpCF.h"

#include "UDMSprCustomerKlientImpl.h"
#include "UDMSprCustomerKlientCF.h"


#include "UDMSprCustomerUserImpl.h"
#include "UDMSprCustomerUserCF.h"
#include "UDMSprCustomerUserGrpImpl.h"
#include "UDMSprCustomerUserGrpCF.h"

#include "UDMSprCustomerMainMenuImpl.h"
#include "UDMSprCustomerMainMenuCF.h"
#include "UDMSprCustomerMainMenuGrpImpl.h"
#include "UDMSprCustomerMainMenuGrpCF.h"


#include "UDMXVipolnObmenImpl.h"
#include "UDMXVipolnObmenCF.h"

#include "UDMSprSellerImpl.h"
#include "UDMSprSellerCF.h"

#include "UDMDataSetImpl.h"
#include "UDMDataSetCF.h"

#include "UDMSprAddressRegionImpl.h"
#include "UDMSprAddressRegionCF.h"
#include "UDMSprAddressRayonImpl.h"
#include "UDMSprAddressRayonCF.h"
#include "UDMSprAddressNasPunktImpl.h"
#include "UDMSprAddressNasPunktCF.h"
#include "UDMSprAddressStreetImpl.h"
#include "UDMSprAddressStreetCF.h"
#include "UDMSprAddressDomImpl.h"
#include "UDMSprAddressDomCF.h"
#include "UDMSprAddressStroenImpl.h"
#include "UDMSprAddressStroenCF.h"
#include "UDMSprAddressKVImpl.h"
#include "UDMSprAddressKVCF.h"


#include "UDMSprObjectImpl.h"
#include "UDMSprObjectCF.h"
#include "UDMSprTypeNomImpl.h"
#include "UDMSprTypeNomCF.h"

#include "UDMSprNomVZipImpl.h"
#include "UDMSprNomVZipCF.h"

#include "UDMSprStorageLocationGrpImpl.h"
#include "UDMSprStorageLocationGrpCF.h"

#include "UDMSprStorageLocationImpl.h"
#include "UDMSprStorageLocationCF.h"
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
//----------------------------------------------------------------------------
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
if (id_class==CLSID_TDMSprFactorImpl)
	{
	TDMSprFactorCF * ob=new TDMSprFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMSprFactorValueImpl)
	{
	TDMSprFactorValueCF * ob=new TDMSprFactorValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMSprGrpProduceImpl)
   {
	TDMSprGrpProduceCF * ob=new TDMSprGrpProduceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProduceImpl)
   {
	TDMSprProduceCF * ob=new TDMSprProduceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpLossFactorImpl)
   {
	TDMSprGrpLossFactorCF * ob=new TDMSprGrpLossFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprLossFactorImpl)
   {
	TDMSprLossFactorCF * ob=new TDMSprLossFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprLossFactorValueImpl)
   {
	TDMSprLossFactorValueCF * ob=new TDMSprLossFactorValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomFindImpl)
   {
	TDMSprNomFindCF * ob=new TDMSprNomFindCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprInetCatalogImpl)
   {
	TDMSprInetCatalogCF * ob=new TDMSprInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpNomInetCatalogImpl)
   {
	TDMSprGrpNomInetCatalogCF * ob=new TDMSprGrpNomInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomInetCatalogImpl)
   {
	TDMSprNomInetCatalogCF * ob=new TDMSprNomInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesGrpImpl)
   {
	TDMSprPropertiesGrpCF * ob=new TDMSprPropertiesGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesImpl)
   {
	TDMSprPropertiesCF * ob=new TDMSprPropertiesCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesValuesListImpl)
   {
	TDMSprPropertiesValuesListCF * ob=new TDMSprPropertiesValuesListCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomPropertiesValueImpl)
   {
	TDMSprNomPropertiesValueCF * ob=new TDMSprNomPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVidImageImpl)
   {
	TDMSprVidImageCF * ob=new TDMSprVidImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVidImageGrpImpl)
   {
	TDMSprVidImageGrpCF * ob=new TDMSprVidImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomImageImpl)
   {
	TDMSprNomImageCF * ob=new TDMSprNomImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesNaborImpl)
   {
	TDMSprPropertiesNaborCF * ob=new TDMSprPropertiesNaborCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesNaborGrpImpl)
   {
	TDMSprPropertiesNaborGrpCF * ob=new TDMSprPropertiesNaborGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPropertiesNaborSostavImpl)
   {
	TDMSprPropertiesNaborSostavCF * ob=new TDMSprPropertiesNaborSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprTypeNachislImpl)
   {
	TDMSprTypeNachislCF * ob=new TDMSprTypeNachislCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNachislImpl)
   {
	TDMSprNachislCF * ob=new TDMSprNachislCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprProducerNomGrpImpl)
   {
	TDMSprProducerNomGrpCF * ob=new TDMSprProducerNomGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProducerNomImpl)
   {
	TDMSprProducerNomCF * ob=new TDMSprProducerNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProducerPriceImpl)
   {
	TDMSprProducerPriceCF * ob=new TDMSprProducerPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProducerEdImpl)
   {
	TDMSprProducerEdCF * ob=new TDMSprProducerEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprProducerImpl)
   {
	TDMSprProducerCF * ob=new TDMSprProducerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProducerTypePriceImpl)
   {
	TDMSprProducerTypePriceCF * ob=new TDMSprProducerTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprTypeAnalogImpl)
   {
	TDMSprTypeAnalogCF * ob=new TDMSprTypeAnalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomAnalogImpl)
   {
	TDMSprNomAnalogCF * ob=new TDMSprNomAnalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TDMSprCustomerAccountGrpImpl)
   {
	TDMSprCustomerAccountGrpCF * ob=new TDMSprCustomerAccountGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCustomerAccountImpl)
   {
	TDMSprCustomerAccountCF * ob=new TDMSprCustomerAccountCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCustomerUserGrpImpl)
   {
	TDMSprCustomerUserGrpCF * ob=new TDMSprCustomerUserGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCustomerUserImpl)
   {
	TDMSprCustomerUserCF * ob=new TDMSprCustomerUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprCustomerMainMenuGrpImpl)
   {
	TDMSprCustomerMainMenuGrpCF * ob=new TDMSprCustomerMainMenuGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCustomerMainMenuImpl)
   {
	TDMSprCustomerMainMenuCF * ob=new TDMSprCustomerMainMenuCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprCustomerKlientImpl)
   {
	TDMSprCustomerKlientCF * ob=new TDMSprCustomerKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMXVipolnObmenImpl)
   {
	TDMXVipolnObmenCF * ob=new TDMXVipolnObmenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprSellerImpl)
   {
	TDMSprSellerCF * ob=new TDMSprSellerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMDataSetImpl)
   {
	TDMDataSetCF * ob=new TDMDataSetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprAddressRegionImpl)
   {
	TDMSprAddressRegionCF * ob=new TDMSprAddressRegionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressRayonImpl)
   {
	TDMSprAddressRayonCF * ob=new TDMSprAddressRayonCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressNasPunktImpl)
   {
	TDMSprAddressNasPunktCF * ob=new TDMSprAddressNasPunktCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressStreetImpl)
   {
	TDMSprAddressStreetCF * ob=new TDMSprAddressStreetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressDomImpl)
   {
	TDMSprAddressDomCF * ob=new TDMSprAddressDomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressStroenImpl)
   {
	TDMSprAddressStroenCF * ob=new TDMSprAddressStroenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprAddressKVImpl)
   {
	TDMSprAddressKVCF * ob=new TDMSprAddressKVCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprObjectImpl)
   {
	TDMSprObjectCF * ob=new TDMSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprTypeNomImpl)
   {
	TDMSprTypeNomCF * ob=new TDMSprTypeNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprNomVZipImpl)
   {
	TDMSprNomVZipCF * ob=new TDMSprNomVZipCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprStorageLocationGrpImpl)
   {
	TDMSprStorageLocationGrpCF * ob=new TDMSprStorageLocationGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TDMSprStorageLocationImpl)
   {
	TDMSprStorageLocationCF * ob=new TDMSprStorageLocationCF();
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

if (icom->kanAddClass(CLSID_TDMSprFactorImpl,ProgId_DMSprFactor,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprFactor)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprFactorValueImpl,ProgId_DMSprFactorValue,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprFactorValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpProduceImpl,ProgId_DMSprGrpProduce,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprGrpProduce)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProduceImpl,ProgId_DMSprProduce,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProduce)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpLossFactorImpl,ProgId_DMSprGrpLossFactor,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprGrpLossFactor)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprLossFactorImpl,ProgId_DMSprLossFactor,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprLossFactor)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprLossFactorValueImpl,ProgId_DMSprLossFactorValue,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprLossFactorValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNomFindImpl,ProgId_DMSprNomFind,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomFind)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprInetCatalogImpl,ProgId_DMSprInetCatalog,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprInetCatalog)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpNomInetCatalogImpl,ProgId_DMSprGrpNomInetCatalog,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprGrpNomInetCatalog)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNomInetCatalogImpl,ProgId_DMSprNomInetCatalog,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomInetCatalog)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesGrpImpl,ProgId_DMSprPropertiesGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprPropertiesGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesImpl,ProgId_DMSprProperties,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProperties)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesValuesListImpl,ProgId_DMSprPropertiesValuesList,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprPropertiesValuesList)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNomPropertiesValueImpl,ProgId_DMSprNomPropertiesValue,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomPropertiesValue)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVidImageImpl,ProgId_DMSprVidImage,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprVidImage)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVidImageGrpImpl,ProgId_DMSprVidImageGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprVidImageGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNomImageImpl,ProgId_DMSprNomImage,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomImage)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesNaborImpl,ProgId_DMSprPropertiesNabor,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprPropertiesNabor)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesNaborGrpImpl,ProgId_DMSprPropertiesNaborGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprPropertiesNaborGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPropertiesNaborSostavImpl,ProgId_DMSprPropertiesNaborSostav,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprPropertiesNaborSostav)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprTypeNachislImpl,ProgId_DMSprTypeNachisl,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprTypeNachisl)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNachislImpl,ProgId_DMSprNachisl,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNachisl)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprProducerNomGrpImpl,ProgId_DMSprProducerNomGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducerNomGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProducerNomImpl,ProgId_DMSprProducerNom,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducerNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProducerEdImpl,ProgId_DMSprProducerEd,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducerEd)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProducerPriceImpl,ProgId_DMSprProducerPrice,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducerPrice)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprProducerImpl,ProgId_DMSprProducer,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducer)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProducerTypePriceImpl,ProgId_DMSprProducerTypePrice,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprProducerTypePrice)+"  !");
	}


if (icom->kanAddClass(CLSID_TDMSprTypeAnalogImpl,ProgId_DMSprTypeAnalog,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprTypeAnalog)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprNomAnalogImpl,ProgId_DMSprNomAnalog,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomAnalog)+"  !");
	}



if (icom->kanAddClass(CLSID_TDMSprCustomerAccountGrpImpl,ProgId_DMSprCustomerAccountGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerAccountGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprCustomerAccountImpl,ProgId_DMSprCustomerAccount,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerAccount)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprCustomerUserGrpImpl,ProgId_DMSprCustomerUserGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerUserGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprCustomerUserImpl,ProgId_DMSprCustomerUser,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerUser)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprCustomerMainMenuGrpImpl,ProgId_DMSprCustomerMainMenuGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerMainMenuGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprCustomerMainMenuImpl,ProgId_DMSprCustomerMainMenu,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerMainMenu)+"  !");
	}


if (icom->kanAddClass(CLSID_TDMSprCustomerKlientImpl,ProgId_DMSprCustomerKlient,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCustomerKlient)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMXVipolnObmenImpl,ProgId_DMXVipolnObmen,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMXVipolnObmen)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprSellerImpl,ProgId_DMSprSeller,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprSeller)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMDataSetImpl,ProgId_DMDataSet,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMDataSet)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressRegionImpl,ProgId_DMSprAddressRegion,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressRegion)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressRayonImpl,ProgId_DMSprAddressRayon,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressRayon)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressNasPunktImpl,ProgId_DMSprAddressNasPunkt,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressNasPunkt)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressStreetImpl,ProgId_DMSprAddressStreet,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressStreet)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressDomImpl,ProgId_DMSprAddressDom,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressDom)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressStroenImpl,ProgId_DMSprAddressStroen,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressStroen)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprAddressKVImpl,ProgId_DMSprAddressKV,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprAddressKV)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprObjectImpl,ProgId_DMSprObject,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprObject)+"  !");
	}

if (icom->kanAddClass(CLSID_TDMSprTypeNomImpl,ProgId_DMSprTypeNom,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprTypeNom)+"  !");
	}


if (icom->kanAddClass(CLSID_TDMSprNomVZipImpl,ProgId_DMSprNomVZip,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomVZip)+"  !");
	}


if (icom->kanAddClass(CLSID_TDMSprStorageLocationGrpImpl,ProgId_DMSprStorageLocationGrp,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprStorageLocationGrp)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprStorageLocationImpl,ProgId_DMSprStorageLocation,"DMSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprStorageLocation)+"  !");
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

