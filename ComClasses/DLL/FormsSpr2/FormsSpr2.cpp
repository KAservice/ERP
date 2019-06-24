//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UFormaElementaSprFactorImpl.h"
#include "UFormaElementaSprFactorCF.h"
#include "UFormaSpiskaSprFactorImpl.h"
#include "UFormaSpiskaSprFactorCF.h"
#include "UFormaElementaSprGrpProduceImpl.h"
#include "UFormaElementaSprGrpProduceCF.h"
#include "UFormaElementaSprProduceImpl.h"
#include "UFormaElementaSprProduceCF.h"
#include "UFormaSpiskaSprProduceImpl.h"
#include "UFormaSpiskaSprProduceCF.h"
#include "UFormaElementaSprGrpLossFactorImpl.h"
#include "UFormaElementaSprGrpLossFactorCF.h"
#include "UFormaElementaSprLossFactorImpl.h"
#include "UFormaElementaSprLossFactorCF.h"
#include "UFormaSpiskaSprLossFactorImpl.h"
#include "UFormaSpiskaSprLossFactorCF.h"
#include "UFormaSprNomFindImpl.h"
#include "UFormaSprNomFindCF.h"
#include "UFormaElementaSprInetCatalogImpl.h"
#include "UFormaElementaSprInetCatalogCF.h"
#include "UFormaSpiskaSprInetCatalogImpl.h"
#include "UFormaSpiskaSprInetCatalogCF.h"
#include "UFormaElementaSprGrpNomInetCatalogImpl.h"
#include "UFormaElementaSprGrpNomInetCatalogCF.h"
#include "UFormaSpiskaSprNomInetCatalogImpl.h"
#include "UFormaSpiskaSprNomInetCatalogCF.h"
#include "UFormaElementaSprPropertiesGrpImpl.h"
#include "UFormaElementaSprPropertiesGrpCF.h"
#include "UFormaElementaSprPropertiesValuesListImpl.h"
#include "UFormaElementaSprPropertiesValuesListCF.h"
#include "UFormaSpiskaSprPropertiesValuesListImpl.h"
#include "UFormaSpiskaSprPropertiesValuesListCF.h"
#include "UFormaElementaSprPropertiesImpl.h"
#include "UFormaElementaSprPropertiesCF.h"
#include "UFormaSpiskaSprPropertiesImpl.h"
#include "UFormaSpiskaSprPropertiesCF.h"
#include "UFormaElementaSprNomPropertiesValueImpl.h"
#include "UFormaElementaSprNomPropertiesValueCF.h"
#include "UFormaSpiskaSprNomPropertiesValueImpl.h"
#include "UFormaSpiskaSprNomPropertiesValueCF.h"
#include "UFormaElementaSprVidImageGrpImpl.h"
#include "UFormaElementaSprVidImageGrpCF.h"
#include "UFormaElementaSprVidImageImpl.h"
#include "UFormaElementaSprVidImageCF.h"
#include "UFormaSpiskaSprVidImageImpl.h"
#include "UFormaSpiskaSprVidImageCF.h"
#include "UFormaElementaSprNomImageImpl.h"
#include "UFormaElementaSprNomImageCF.h"
#include "UFormaSpiskaSprNomImageImpl.h"
#include "UFormaSpiskaSprNomImageCF.h"

#include "UFormaElementaSprPropertiesNaborGrpImpl.h"
#include "UFormaElementaSprPropertiesNaborGrpCF.h"

#include "UFormaElementaSprPropertiesNaborSostavImpl.h"
#include "UFormaElementaSprPropertiesNaborSostavCF.h"

#include "UFormaSpiskaSprPropertiesNaborSostavImpl.h"
#include "UFormaSpiskaSprPropertiesNaborSostavCF.h"
#include "UFormaElementaSprPropertiesNaborImpl.h"
#include "UFormaElementaSprPropertiesNaborCF.h"
#include "UFormaSpiskaSprPropertiesNaborImpl.h"
#include "UFormaSpiskaSprPropertiesNaborCF.h"

#include "UFormaSpiskaSprTypeNachislImpl.h"
#include "UFormaSpiskaSprTypeNachislCF.h"
#include "UFormaElementaSprTypeNachislImpl.h"
#include "UFormaElementaSprTypeNachislCF.h"
#include "UFormaSpiskaSprNachislImpl.h"
#include "UFormaSpiskaSprNachislCF.h"

#include "UFormaSpiskaSprProducerTypePriceImpl.h"
#include "UFormaSpiskaSprProducerTypePriceCF.h"
#include "UFormaElementaSprProducerTypePriceImpl.h"
#include "UFormaElementaSprProducerTypePriceCF.h"

#include "UFormaSpiskaSprProducerImpl.h"
#include "UFormaSpiskaSprProducerCF.h"
#include "UFormaElementaSprProducerImpl.h"
#include "UFormaElementaSprProducerCF.h"


#include "UFormaSpiskaSprTypeAnalogImpl.h"
#include "UFormaSpiskaSprTypeAnalogCF.h"
#include "UFormaSpiskaSprNomAnalogImpl.h"
#include "UFormaSpiskaSprNomAnalogCF.h"

#include "UFormaSpiskaSprProducerPriceImpl.h"
#include "UFormaSpiskaSprProducerPriceCF.h"

#include "UFormaSpiskaSprProducerEdImpl.h"
#include "UFormaSpiskaSprProducerEdCF.h"
#include "UFormaElementaSprProducerEdImpl.h"
#include "UFormaElementaSprProducerEdCF.h"
#include "UFormaElementaSprProducerNomImpl.h"
#include "UFormaElementaSprProducerNomCF.h"

#include "UFormaElementaSprProducerNomGrpImpl.h"
#include "UFormaElementaSprProducerNomGrpCF.h"
#include "UFormaSpiskaSprProducerNomImpl.h"
#include "UFormaSpiskaSprProducerNomCF.h"

#include "UFormaSpiskaSprCustomerKlientImpl.h"
#include "UFormaSpiskaSprCustomerKlientCF.h"

#include "UFormaElementaSprCustomerAccountImpl.h"
#include "UFormaElementaSprCustomerAccountCF.h"
#include "UFormaElementaSprCustomerAccountGrpImpl.h"
#include "UFormaElementaSprCustomerAccountGrpCF.h"
#include "UFormaSpiskaSprCustomerAccountImpl.h"
#include "UFormaSpiskaSprCustomerAccountCF.h"

#include "UFormaElementaSprCustomerMainMenuGrpImpl.h"
#include "UFormaElementaSprCustomerMainMenuGrpCF.h"
#include "UFormaSpiskaSprCustomerMainMenuImpl.h"
#include "UFormaSpiskaSprCustomerMainMenuCF.h"

#include "UFormaElementaSprCustomerUserGrpImpl.h"
#include "UFormaElementaSprCustomerUserGrpCF.h"
#include "UFormaElementaSprCustomerUserImpl.h"
#include "UFormaElementaSprCustomerUserCF.h"
#include "UFormaSpiskaSprCustomerUserImpl.h"
#include "UFormaSpiskaSprCustomerUserCF.h"


#include "UFormaSpiskaXVipolnObmenImpl.h"
#include "UFormaSpiskaXVipolnObmenCF.h"

#include "UFormaSpiskaSprSellerImpl.h"
#include "UFormaSpiskaSprSellerCF.h"
#include "UFormaElementaSprSellerImpl.h"
#include "UFormaElementaSprSellerCF.h"


#include "UFormaElementaSprAddressRegionImpl.h"
#include "UFormaElementaSprAddressRegionCF.h"
#include "UFormaElementaSprAddressRayonImpl.h"
#include "UFormaElementaSprAddressRayonCF.h"
#include "UFormaElementaSprAddressnasPunktImpl.h"
#include "UFormaElementaSprAddressNasPunktCF.h"
#include "UFormaElementaSprAddressStreetImpl.h"
#include "UFormaElementaSprAddressStreetCF.h"
#include "UFormaElementaSprAddressDomImpl.h"
#include "UFormaElementaSprAddressDomCF.h"
#include "UFormaElementaSprAddressStroenImpl.h"
#include "UFormaElementaSprAddressStroenCF.h"
#include "UFormaElementaSprAddressKVImpl.h"
#include "UFormaElementaSprAddressKVCF.h"

#include "UFormaElementaSprAddressViborImpl.h"
#include "UFormaElementaSprAddressViborCF.h"



#include "UFormaSpiskaSprObjectImpl.h"
#include "UFormaSpiskaSprObjectCF.h"
#include "UFormaElementaSprObjectImpl.h"
#include "UFormaElementaSprObjectCF.h"

#include "UFormaSpiskaSprTypeNomImpl.h"
#include "UFormaSpiskaSprTypeNomCF.h"
#include "UFormaElementaSprTypeNomImpl.h"
#include "UFormaElementaSprTypeNomCF.h"


#include "UFormaSpiskaSprNomVZipImpl.h"
#include "UFormaSpiskaSprNomVZipCF.h"

#include "UFormaElementaSprStorageLocationImpl.h"
#include "UFormaElementaSprStorageLocationCF.h"
#include "UFormaElementaSprStorageLocationGrpImpl.h"
#include "UFormaElementaSprStorageLocationGrpCF.h"
#include "UFormaSpiskaSprStorageLocationImpl.h"
#include "UFormaSpiskaSprStorageLocationCF.h"
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
if (id_class==CLSID_TFormaElementaSprFactorImpl)
	{
	TFormaElementaSprFactorCF * ob=new TFormaElementaSprFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaSprFactorImpl)
   {
	TFormaSpiskaSprFactorCF * ob=new TFormaSpiskaSprFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpProduceImpl)
   {
	TFormaElementaSprGrpProduceCF * ob=new TFormaElementaSprGrpProduceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProduceImpl)
   {
	TFormaElementaSprProduceCF * ob=new TFormaElementaSprProduceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprProduceImpl)
   {
	TFormaSpiskaSprProduceCF * ob=new TFormaSpiskaSprProduceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpLossFactorImpl)
   {
	TFormaElementaSprGrpLossFactorCF * ob=new TFormaElementaSprGrpLossFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprLossFactorImpl)
   {
	TFormaElementaSprLossFactorCF * ob=new TFormaElementaSprLossFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprLossFactorImpl)
   {
	TFormaSpiskaSprLossFactorCF * ob=new TFormaSpiskaSprLossFactorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSprNomFindImpl)
   {
	TFormaSprNomFindCF * ob=new TFormaSprNomFindCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprInetCatalogImpl)
   {
	TFormaElementaSprInetCatalogCF * ob=new TFormaElementaSprInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprInetCatalogImpl)
   {
	TFormaSpiskaSprInetCatalogCF * ob=new TFormaSpiskaSprInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpNomInetCatalogImpl)
   {
	TFormaElementaSprGrpNomInetCatalogCF * ob=new TFormaElementaSprGrpNomInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomInetCatalogImpl)
   {
	TFormaSpiskaSprNomInetCatalogCF * ob=new TFormaSpiskaSprNomInetCatalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesGrpImpl)
   {
	TFormaElementaSprPropertiesGrpCF * ob=new TFormaElementaSprPropertiesGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesValuesListImpl)
   {
	TFormaElementaSprPropertiesValuesListCF * ob=new TFormaElementaSprPropertiesValuesListCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPropertiesValuesListImpl)
   {
	TFormaSpiskaSprPropertiesValuesListCF * ob=new TFormaSpiskaSprPropertiesValuesListCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesImpl)
   {
	TFormaElementaSprPropertiesCF * ob=new TFormaElementaSprPropertiesCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPropertiesImpl)
   {
	TFormaSpiskaSprPropertiesCF * ob=new TFormaSpiskaSprPropertiesCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprNomPropertiesValueImpl)
   {
	TFormaElementaSprNomPropertiesValueCF * ob=new TFormaElementaSprNomPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomPropertiesValueImpl)
   {
	TFormaSpiskaSprNomPropertiesValueCF * ob=new TFormaSpiskaSprNomPropertiesValueCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprVidImageGrpImpl)
   {
	TFormaElementaSprVidImageGrpCF * ob=new TFormaElementaSprVidImageGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprVidImageImpl)
   {
	TFormaElementaSprVidImageCF * ob=new TFormaElementaSprVidImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprVidImageImpl)
   {
	TFormaSpiskaSprVidImageCF * ob=new TFormaSpiskaSprVidImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprNomImageImpl)
   {
	TFormaElementaSprNomImageCF * ob=new TFormaElementaSprNomImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomImageImpl)
   {
	TFormaSpiskaSprNomImageCF * ob=new TFormaSpiskaSprNomImageCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesNaborGrpImpl)
   {
	TFormaElementaSprPropertiesNaborGrpCF * ob=new TFormaElementaSprPropertiesNaborGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesNaborSostavImpl)
   {
	TFormaElementaSprPropertiesNaborSostavCF * ob=new TFormaElementaSprPropertiesNaborSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPropertiesNaborSostavImpl)
   {
	TFormaSpiskaSprPropertiesNaborSostavCF * ob=new TFormaSpiskaSprPropertiesNaborSostavCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPropertiesNaborImpl)
   {
	TFormaElementaSprPropertiesNaborCF * ob=new TFormaElementaSprPropertiesNaborCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPropertiesNaborImpl)
   {
	TFormaSpiskaSprPropertiesNaborCF * ob=new TFormaSpiskaSprPropertiesNaborCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprTypeNachislImpl)
   {
	TFormaSpiskaSprTypeNachislCF * ob=new TFormaSpiskaSprTypeNachislCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprTypeNachislImpl)
   {
	TFormaElementaSprTypeNachislCF * ob=new TFormaElementaSprTypeNachislCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNachislImpl)
   {
	TFormaSpiskaSprNachislCF * ob=new TFormaSpiskaSprNachislCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprProducerTypePriceImpl)
   {
	TFormaSpiskaSprProducerTypePriceCF * ob=new TFormaSpiskaSprProducerTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProducerTypePriceImpl)
   {
	TFormaElementaSprProducerTypePriceCF * ob=new TFormaElementaSprProducerTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaSpiskaSprProducerImpl)
   {
	TFormaSpiskaSprProducerCF * ob=new TFormaSpiskaSprProducerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProducerImpl)
   {
	TFormaElementaSprProducerCF * ob=new TFormaElementaSprProducerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaSpiskaSprTypeAnalogImpl)
   {
	TFormaSpiskaSprTypeAnalogCF * ob=new TFormaSpiskaSprTypeAnalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomAnalogImpl)
   {
	TFormaSpiskaSprNomAnalogCF * ob=new TFormaSpiskaSprNomAnalogCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaSpiskaSprProducerPriceImpl)
   {
	TFormaSpiskaSprProducerPriceCF * ob=new TFormaSpiskaSprProducerPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprProducerEdImpl)
   {
	TFormaSpiskaSprProducerEdCF * ob=new TFormaSpiskaSprProducerEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProducerEdImpl)
   {
	TFormaElementaSprProducerEdCF * ob=new TFormaElementaSprProducerEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProducerNomImpl)
   {
	TFormaElementaSprProducerNomCF * ob=new TFormaElementaSprProducerNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProducerNomGrpImpl)
   {
	TFormaElementaSprProducerNomGrpCF * ob=new TFormaElementaSprProducerNomGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprProducerNomImpl)
   {
	TFormaSpiskaSprProducerNomCF * ob=new TFormaSpiskaSprProducerNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaSpiskaSprCustomerKlientImpl)
   {
	TFormaSpiskaSprCustomerKlientCF * ob=new TFormaSpiskaSprCustomerKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCustomerAccountImpl)
   {
	TFormaElementaSprCustomerAccountCF * ob=new TFormaElementaSprCustomerAccountCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCustomerAccountGrpImpl)
   {
	TFormaElementaSprCustomerAccountGrpCF * ob=new TFormaElementaSprCustomerAccountGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprCustomerAccountImpl)
   {
	TFormaSpiskaSprCustomerAccountCF * ob=new TFormaSpiskaSprCustomerAccountCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCustomerMainMenuGrpImpl)
   {
	TFormaElementaSprCustomerMainMenuGrpCF * ob=new TFormaElementaSprCustomerMainMenuGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprCustomerMainMenuImpl)
   {
	TFormaSpiskaSprCustomerMainMenuCF * ob=new TFormaSpiskaSprCustomerMainMenuCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCustomerUserGrpImpl)
   {
	TFormaElementaSprCustomerUserGrpCF * ob=new TFormaElementaSprCustomerUserGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCustomerUserImpl)
   {
	TFormaElementaSprCustomerUserCF * ob=new TFormaElementaSprCustomerUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprCustomerUserImpl)
   {
	TFormaSpiskaSprCustomerUserCF * ob=new TFormaSpiskaSprCustomerUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaSpiskaXVipolnObmenImpl)
   {
	TFormaSpiskaXVipolnObmenCF * ob=new TFormaSpiskaXVipolnObmenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprSellerImpl)
   {
	TFormaSpiskaSprSellerCF * ob=new TFormaSpiskaSprSellerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprSellerImpl)
   {
	TFormaElementaSprSellerCF * ob=new TFormaElementaSprSellerCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprAddressRegionImpl)
   {
	TFormaElementaSprAddressRegionCF * ob=new TFormaElementaSprAddressRegionCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprAddressRayonImpl)
   {
	TFormaElementaSprAddressRayonCF * ob=new TFormaElementaSprAddressRayonCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprAddressNasPunktImpl)
   {
	TFormaElementaSprAddressNasPunktCF * ob=new TFormaElementaSprAddressNasPunktCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprAddressStreetImpl)
   {
	TFormaElementaSprAddressStreetCF * ob=new TFormaElementaSprAddressStreetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprAddressDomImpl)
   {
	TFormaElementaSprAddressDomCF * ob=new TFormaElementaSprAddressDomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprAddressStroenImpl)
   {
	TFormaElementaSprAddressStroenCF * ob=new TFormaElementaSprAddressStroenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprAddressKVImpl)
   {
	TFormaElementaSprAddressKVCF * ob=new TFormaElementaSprAddressKVCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprAddressViborImpl)
   {
	TFormaElementaSprAddressViborCF * ob=new TFormaElementaSprAddressViborCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaElementaSprObjectImpl)
   {
	TFormaElementaSprObjectCF * ob=new TFormaElementaSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprObjectImpl)
   {
	TFormaSpiskaSprObjectCF * ob=new TFormaSpiskaSprObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaElementaSprTypeNomImpl)
   {
	TFormaElementaSprTypeNomCF * ob=new TFormaElementaSprTypeNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprTypeNomImpl)
   {
	TFormaSpiskaSprTypeNomCF * ob=new TFormaSpiskaSprTypeNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaSpiskaSprNomVZipImpl)
   {
	TFormaSpiskaSprNomVZipCF * ob=new TFormaSpiskaSprNomVZipCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprStorageLocationImpl)
   {
	TFormaElementaSprStorageLocationCF * ob=new TFormaElementaSprStorageLocationCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprStorageLocationGrpImpl)
   {
	TFormaElementaSprStorageLocationGrpCF * ob=new TFormaElementaSprStorageLocationGrpCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TFormaSpiskaSprStorageLocationImpl)
   {
	TFormaSpiskaSprStorageLocationCF * ob=new TFormaSpiskaSprStorageLocationCF();
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

if (icom->kanAddClass(CLSID_TFormaElementaSprFactorImpl,ProgId_FormaElementaSprFactor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprFactor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprFactorImpl,ProgId_FormaSpiskaSprFactor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprFactor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpProduceImpl,ProgId_FormaElementaSprGrpProduce,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprGrpProduce)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprProduceImpl,ProgId_FormaElementaSprProduce,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProduce)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprProduceImpl,ProgId_FormaSpiskaSprProduce,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProduce)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpLossFactorImpl,ProgId_FormaElementaSprGrpLossFactor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprGrpLossFactor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprLossFactorImpl,ProgId_FormaElementaSprLossFactor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprLossFactor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprLossFactorImpl,ProgId_FormaSpiskaSprLossFactor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprLossFactor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSprNomFindImpl,ProgId_FormaSprNomFind,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSprNomFind)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprInetCatalogImpl,ProgId_FormaElementaSprInetCatalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprInetCatalog)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprInetCatalogImpl,ProgId_FormaSpiskaSprInetCatalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprInetCatalog)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpNomInetCatalogImpl,ProgId_FormaElementaSprGrpNomInetCatalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprGrpNomInetCatalog)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomInetCatalogImpl,ProgId_FormaSpiskaSprNomInetCatalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomInetCatalog)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesGrpImpl,ProgId_FormaElementaSprPropertiesGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprPropertiesGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesValuesListImpl,ProgId_FormaElementaSprPropertiesValuesList,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprPropertiesValuesList)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPropertiesValuesListImpl,ProgId_FormaSpiskaSprPropertiesValuesList,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprPropertiesValuesList)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesImpl,ProgId_FormaElementaSprProperties,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProperties)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPropertiesImpl,ProgId_FormaSpiskaSprProperties,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProperties)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNomPropertiesValueImpl,ProgId_FormaElementaSprNomPropertiesValue,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprNomPropertiesValue)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomPropertiesValueImpl,ProgId_FormaSpiskaSprNomPropertiesValue,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomPropertiesValue)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprVidImageGrpImpl,ProgId_FormaElementaSprVidImageGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprVidImageGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprVidImageImpl,ProgId_FormaElementaSprVidImage,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprVidImage)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprVidImageImpl,ProgId_FormaSpiskaSprVidImage,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprVidImage)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNomImageImpl,ProgId_FormaElementaSprNomImage,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprNomImage)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomImageImpl,ProgId_FormaSpiskaSprNomImage,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomImage)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesNaborGrpImpl,ProgId_FormaElementaSprPropertiesNaborGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprPropertiesNaborGrp)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesNaborSostavImpl,ProgId_FormaElementaSprPropertiesNaborSostav,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprPropertiesNaborSostav)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPropertiesNaborSostavImpl,ProgId_FormaSpiskaSprPropertiesNaborSostav,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprPropertiesNaborSostav)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPropertiesNaborImpl,ProgId_FormaElementaSprPropertiesNabor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprPropertiesNabor)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPropertiesNaborImpl,ProgId_FormaSpiskaSprPropertiesNabor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprPropertiesNabor)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprTypeNachislImpl,ProgId_FormaSpiskaSprTypeNachisl,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprTypeNachisl)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprTypeNachislImpl,ProgId_FormaElementaSprTypeNachisl,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprTypeNachisl)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaElementaSprProducerTypePriceImpl,ProgId_FormaElementaSprProducerTypePrice,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProducerTypePrice)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprProducerTypePriceImpl,ProgId_FormaSpiskaSprProducerTypePrice,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProducerTypePrice)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaElementaSprProducerImpl,ProgId_FormaElementaSprProducer,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProducer)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprProducerImpl,ProgId_FormaSpiskaSprProducer,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProducer)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprNachislImpl,ProgId_FormaSpiskaSprNachisl,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNachisl)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprTypeAnalogImpl,ProgId_FormaSpiskaSprTypeAnalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprTypeAnalog)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomAnalogImpl,ProgId_FormaSpiskaSprNomAnalog,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomAnalog)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprProducerPriceImpl,ProgId_FormaSpiskaSprProducerPrice,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProducerPrice)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprProducerEdImpl,ProgId_FormaSpiskaSprProducerEd,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProducerEd)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprProducerEdImpl,ProgId_FormaElementaSprProducerEd,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProducerEd)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprProducerNomImpl,ProgId_FormaElementaSprProducerNom,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProducerNom)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprProducerNomGrpImpl,ProgId_FormaElementaSprProducerNomGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprProducerNomGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprProducerNomImpl,ProgId_FormaSpiskaSprProducerNom,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProducerNom)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprCustomerKlientImpl,ProgId_FormaSpiskaSprCustomerKlient,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprCustomerKlient)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprCustomerAccountImpl,ProgId_FormaElementaSprCustomerAccount,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprCustomerAccount)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprCustomerAccountGrpImpl,ProgId_FormaElementaSprCustomerAccountGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprCustomerAccountGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprCustomerAccountImpl,ProgId_FormaSpiskaSprCustomerAccount,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprCustomerAccount)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprCustomerMainMenuGrpImpl,ProgId_FormaElementaSprCustomerMainMenuGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprCustomerMainMenuGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprCustomerMainMenuImpl,ProgId_FormaSpiskaSprCustomerMainMenu,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprCustomerMainMenu)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprCustomerUserImpl,ProgId_FormaSpiskaSprCustomerUser,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprCustomerUser)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprCustomerUserGrpImpl,ProgId_FormaElementaSprCustomerUserGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprCustomerUserGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprCustomerUserImpl,ProgId_FormaElementaSprCustomerUser,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprCustomerUser)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaXVipolnObmenImpl,ProgId_FormaSpiskaXVipolnObmen,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaXVipolnObmen)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprSellerImpl,ProgId_FormaSpiskaSprSeller,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprSeller)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprSellerImpl,ProgId_FormaElementaSprSeller,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprSeller)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprAddressRegionImpl,ProgId_FormaElementaSprAddressRegion,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressRegion)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressRayonImpl,ProgId_FormaElementaSprAddressRayon,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressRayon)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressNasPunktImpl,ProgId_FormaElementaSprAddressNasPunkt,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressNasPunkt)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressStreetImpl,ProgId_FormaElementaSprAddressStreet,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressStreet)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressDomImpl,ProgId_FormaElementaSprAddressDom,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressDom)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressStroenImpl,ProgId_FormaElementaSprAddressStroen,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressStroen)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprAddressKVImpl,ProgId_FormaElementaSprAddressKV,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressKV)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprAddressViborImpl,ProgId_FormaElementaSprAddressVibor,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprAddressVibor)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaElementaSprObjectImpl,ProgId_FormaElementaSprObject,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprObject)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprObjectImpl,ProgId_FormaSpiskaSprObject,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprObject)+" !");
	}


if (icom->kanAddClass(CLSID_TFormaElementaSprTypeNomImpl,ProgId_FormaElementaSprTypeNom,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprTypeNom)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprTypeNomImpl,ProgId_FormaSpiskaSprTypeNom,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprTypeNom)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomVZipImpl,ProgId_FormaSpiskaSprNomVZip,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomVZip)+" !");
	}



if (icom->kanAddClass(CLSID_TFormaElementaSprStorageLocationImpl,ProgId_FormaElementaSprStorageLocation,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprStorageLocation)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprStorageLocationGrpImpl,ProgId_FormaElementaSprStorageLocationGrp,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprStorageLocationGrp)+" !");
	}

if (icom->kanAddClass(CLSID_TFormaSpiskaSprStorageLocationImpl,ProgId_FormaSpiskaSprStorageLocation,"FormsSpr2.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprStorageLocation)+" !");
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
