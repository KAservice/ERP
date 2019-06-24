//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "GlobalInterface.h"
#include "UDMSprSkladImpl.h"
#include "UDMSprSkladCF.h"
#include "UDMQueryReadImpl.h"
#include "UDMQueryReadCF.h"
#include "UDMQueryUpdateImpl.h"
#include "UDMQueryUpdateCF.h"
#include "UDMSprBankSchetImpl.h"
#include "UDMSprBankSchetCF.h"
#include "UDMSprARMImpl.h"
#include "UDMSprARMCF.h"
#include "UDMSprBankImpl.h"
#include "UDMSprBankCF.h"
#include "UDMSprBrandImpl.h"
#include "UDMSprBrandCF.h"
#include "UDMSprGrpBVNomImpl.h"
#include "UDMSprGrpBVNomCF.h"
#include "UDMSprBVNomImpl.h"
#include "UDMSprBVNomCF.h"
#include "UDMSprCodeTelImpl.h"
#include "UDMSprCodeTelCF.h"
#include "UDMSprCountryImpl.h"
#include "UDMSprCountryCF.h"
#include "UDMSprDiscountAutoImpl.h"
#include "UDMSprDiscountAutoCF.h"
#include "UDMSprDiscountCardImpl.h"
#include "UDMSprDiscountCardCF.h"
#include "UDMSprDiscountCard_1Impl.h"
#include "UDMSprDiscountCard_1CF.h"
#include "UDMSprDocKlientImpl.h"
#include "UDMSprDocKlientCF.h"
#include "UDMSprDogovorImpl.h"
#include "UDMSprDogovorCF.h"
#include "UDMSprEdImpl.h"
#include "UDMSprEdCF.h"
#include "UDMSprFirmImpl.h"
#include "UDMSprFirmCF.h"
#include "UDMSprGrafikPlatImpl.h"
#include "UDMSprGrafikPlatCF.h"
#include "UDMSprImportEdImpl.h"
#include "UDMSprImportEdCF.h"
#include "UDMSprImportNomImpl.h"
#include "UDMSprImportNomCF.h"
#include "UDMSprImportSetImpl.h"
#include "UDMSprImportSetCF.h"
#include "UDMSprInfBaseImpl.h"
#include "UDMSprInfBaseCF.h"
#include "UDMSprInvImpl.h"
#include "UDMSprInvCF.h"
#include "UDMSprKKMImpl.h"
#include "UDMSprKKMCF.h"
#include "UDMSprGrpKlientImpl.h"
#include "UDMSprGrpKlientCF.h"
#include "UDMSprKlientImpl.h"
#include "UDMSprKlientCF.h"
#include "UDMSprKlientDopFisLImpl.h"
#include "UDMSprKlientDopFisLCF.h"
#include "UDMSprKlientDopUrLImpl.h"
#include "UDMSprKlientDopUrLCF.h"
#include "UDMSprModImpl.h"
#include "UDMSprModCF.h"
#include "UDMSprMPrigImpl.h"
#include "UDMSprMPrigCF.h"
#include "UDMSprNacenkaImpl.h"
#include "UDMSprNacenkaCF.h"
#include "UDMSprNakSkidokImpl.h"
#include "UDMSprNakSkidokCF.h"
#include "UDMSprGrpNomImpl.h"
#include "UDMSprGrpNomCF.h"
#include "UDMSprNomImpl.h"
#include "UDMSprNomCF.h"
#include "UDMSprNomRestImpl.h"
#include "UDMSprNomRestCF.h"
#include "UDMSprNumTelImpl.h"
#include "UDMSprNumTelCF.h"
#include "UDMSprOborudImpl.h"
#include "UDMSprOborudCF.h"
#include "UDMViborOborudImpl.h"
#include "UDMViborOborudCF.h"
#include "UDMSprOKEIImpl.h"
#include "UDMSprOKEICF.h"
#include "UDMSprPartImpl.h"
#include "UDMSprPartCF.h"
#include "UDMSprPodrImpl.h"
#include "UDMSprPodrCF.h"
#include "UDMSprPriceImpl.h"
#include "UDMSprPriceCF.h"
#include "UDMSprPriceScheduleImpl.h"
#include "UDMSprPriceScheduleCF.h"
#include "UDMSprGrpProjectImpl.h"
#include "UDMSprGrpProjectCF.h"
#include "UDMSprProjectImpl.h"
#include "UDMSprProjectCF.h"
#include "UDMSprScaleImpl.h"
#include "UDMSprScaleCF.h"
#include "UDMSprSezKFImpl.h"
#include "UDMSprSezKFCF.h"
#include "UDMSprSezKFSProdImpl.h"
#include "UDMSprSezKFSProdCF.h"
#include "UDMSprSostProdImpl.h"
#include "UDMSprSostProdCF.h"
#include "UDMSprStrObjectImpl.h"
#include "UDMSprStrObjectCF.h"
#include "UDMSprTypePriceImpl.h"
#include "UDMSprTypePriceCF.h"
#include "UDMSprGrpUserImpl.h"
#include "UDMSprGrpUserCF.h"
#include "UDMSprUserImpl.h"
#include "UDMSprUserCF.h"
#include "UDMSprGrpVesNomImpl.h"
#include "UDMSprGrpVesNomCF.h"
#include "UDMSprVesNomImpl.h"
#include "UDMSprVesNomCF.h"
#include "UDMSprVidDiscountCardImpl.h"
#include "UDMSprVidDiscountCardCF.h"
#include "UDMSprRaschSchetImpl.h"
#include "UDMSprRaschSchetCF.h"
#include "UDMSprVidKlientImpl.h"
#include "UDMSprVidKlientCF.h"
#include "UDMSprVidNomImpl.h"
#include "UDMSprVidNomCF.h"
#include "UDMSetupImpl.h"
#include "UDMSetupCF.h"
#include "UDMXSetupObmenImpl.h"
#include "UDMXSetupObmenCF.h"
#include "UDMTableNumberDocImpl.h"
#include "UDMTableNumberDocCF.h"
#include "UDMXTableIsmImpl.h"
#include "UDMXTableIsmCF.h"
#include "UDMTableExtPrintFormImpl.h"
#include "UDMTableExtPrintFormCF.h"
#include "UDMUserSetupImpl.h"
#include "UDMUserSetupCF.h"
#include "UDMSprGrpBusinessOperImpl.h"
#include "UDMSprGrpBusinessOperCF.h"
#include "UDMSprBusinessOperImpl.h"
#include "UDMSprBusinessOperCF.h"


#include "UDMSprOborudParamImpl.h"
#include "UDMSprOborudParamCF.h"
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
if (id_class==CLSID_TDMSprSkladImpl)
	{
	TDMSprSkladCF * ob=new TDMSprSkladCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TDMQueryReadImpl)
   {
	TDMQueryReadCF * ob=new TDMQueryReadCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMQueryUpdateImpl)
   {
	TDMQueryUpdateCF * ob=new TDMQueryUpdateCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprBankSchetImpl)
   {
	TDMSprBankSchetCF * ob=new TDMSprBankSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprARMImpl)
   {
	TDMSprARMCF * ob=new TDMSprARMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprBankImpl)
   {
	TDMSprBankCF * ob=new TDMSprBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprBrandImpl)
   {
	TDMSprBrandCF * ob=new TDMSprBrandCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpBVNomImpl)
   {
	TDMSprGrpBVNomCF * ob=new TDMSprGrpBVNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprBVNomImpl)
   {
	TDMSprBVNomCF * ob=new TDMSprBVNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCodeTelImpl)
   {
	TDMSprCodeTelCF * ob=new TDMSprCodeTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprCountryImpl)
   {
	TDMSprCountryCF * ob=new TDMSprCountryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprDiscountAutoImpl)
   {
	TDMSprDiscountAutoCF * ob=new TDMSprDiscountAutoCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprDiscountCardImpl)
   {
	TDMSprDiscountCardCF * ob=new TDMSprDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprDiscountCard_1Impl)
   {
	TDMSprDiscountCard_1CF * ob=new TDMSprDiscountCard_1CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprDocKlientImpl)
   {
	TDMSprDocKlientCF * ob=new TDMSprDocKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprDogovorImpl)
   {
	TDMSprDogovorCF * ob=new TDMSprDogovorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprEdImpl)
   {
	TDMSprEdCF * ob=new TDMSprEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprFirmImpl)
   {
	TDMSprFirmCF * ob=new TDMSprFirmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrafikPlatImpl)
   {
	TDMSprGrafikPlatCF * ob=new TDMSprGrafikPlatCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprImportEdImpl)
   {
	TDMSprImportEdCF * ob=new TDMSprImportEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprImportNomImpl)
   {
	TDMSprImportNomCF * ob=new TDMSprImportNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprImportSetImpl)
   {
	TDMSprImportSetCF * ob=new TDMSprImportSetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprInfBaseImpl)
   {
	TDMSprInfBaseCF * ob=new TDMSprInfBaseCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprInvImpl)
   {
	TDMSprInvCF * ob=new TDMSprInvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprKKMImpl)
   {
	TDMSprKKMCF * ob=new TDMSprKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpKlientImpl)
   {
	TDMSprGrpKlientCF * ob=new TDMSprGrpKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprKlientImpl)
   {
	TDMSprKlientCF * ob=new TDMSprKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprKlientDopFisLImpl)
   {
	TDMSprKlientDopFisLCF * ob=new TDMSprKlientDopFisLCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprKlientDopUrLImpl)
   {
	TDMSprKlientDopUrLCF * ob=new TDMSprKlientDopUrLCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprModImpl)
   {
	TDMSprModCF * ob=new TDMSprModCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprMPrigImpl)
   {
	TDMSprMPrigCF * ob=new TDMSprMPrigCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNacenkaImpl)
   {
	TDMSprNacenkaCF * ob=new TDMSprNacenkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNakSkidokImpl)
   {
	TDMSprNakSkidokCF * ob=new TDMSprNakSkidokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpNomImpl)
   {
	TDMSprGrpNomCF * ob=new TDMSprGrpNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomImpl)
   {
	TDMSprNomCF * ob=new TDMSprNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNomRestImpl)
   {
	TDMSprNomRestCF * ob=new TDMSprNomRestCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprNumTelImpl)
   {
	TDMSprNumTelCF * ob=new TDMSprNumTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprOborudImpl)
   {
	TDMSprOborudCF * ob=new TDMSprOborudCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMViborOborudImpl)
   {
	TDMViborOborudCF * ob=new TDMViborOborudCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprOKEIImpl)
   {
	TDMSprOKEICF * ob=new TDMSprOKEICF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPartImpl)
   {
	TDMSprPartCF * ob=new TDMSprPartCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPodrImpl)
   {
	TDMSprPodrCF * ob=new TDMSprPodrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPriceImpl)
   {
	TDMSprPriceCF * ob=new TDMSprPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprPriceScheduleImpl)
   {
	TDMSprPriceScheduleCF * ob=new TDMSprPriceScheduleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpProjectImpl)
   {
	TDMSprGrpProjectCF * ob=new TDMSprGrpProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprProjectImpl)
   {
	TDMSprProjectCF * ob=new TDMSprProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprScaleImpl)
   {
	TDMSprScaleCF * ob=new TDMSprScaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprSezKFImpl)
   {
	TDMSprSezKFCF * ob=new TDMSprSezKFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprSezKFSProdImpl)
   {
	TDMSprSezKFSProdCF * ob=new TDMSprSezKFSProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprSostProdImpl)
   {
	TDMSprSostProdCF * ob=new TDMSprSostProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprStrObjectImpl)
   {
	TDMSprStrObjectCF * ob=new TDMSprStrObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprTypePriceImpl)
   {
	TDMSprTypePriceCF * ob=new TDMSprTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpUserImpl)
   {
	TDMSprGrpUserCF * ob=new TDMSprGrpUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprUserImpl)
   {
	TDMSprUserCF * ob=new TDMSprUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpVesNomImpl)
   {
	TDMSprGrpVesNomCF * ob=new TDMSprGrpVesNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVesNomImpl)
   {
	TDMSprVesNomCF * ob=new TDMSprVesNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVidDiscountCardImpl)
   {
	TDMSprVidDiscountCardCF * ob=new TDMSprVidDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprRaschSchetImpl)
   {
	TDMSprRaschSchetCF * ob=new TDMSprRaschSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVidKlientImpl)
   {
	TDMSprVidKlientCF * ob=new TDMSprVidKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprVidNomImpl)
   {
	TDMSprVidNomCF * ob=new TDMSprVidNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSetupImpl)
   {
	TDMSetupCF * ob=new TDMSetupCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMXSetupObmenImpl)
   {
	TDMXSetupObmenCF * ob=new TDMXSetupObmenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMTableNumberDocImpl)
   {
	TDMTableNumberDocCF * ob=new TDMTableNumberDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMXTableIsmImpl)
   {
	TDMXTableIsmCF * ob=new TDMXTableIsmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMTableExtPrintFormImpl)
   {
	TDMTableExtPrintFormCF * ob=new TDMTableExtPrintFormCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMUserSetupImpl)
   {
	TDMUserSetupCF * ob=new TDMUserSetupCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprGrpBusinessOperImpl)
   {
	TDMSprGrpBusinessOperCF * ob=new TDMSprGrpBusinessOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TDMSprBusinessOperImpl)
   {
	TDMSprBusinessOperCF * ob=new TDMSprBusinessOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }


else if (id_class==CLSID_TDMSprOborudParamImpl)
   {
	TDMSprOborudParamCF * ob=new TDMSprOborudParamCF();
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

if (icom->kanAddClass(CLSID_TDMSprSkladImpl,ProgId_DMSprSklad,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprSklad)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMQueryReadImpl,"Oberon.DMQueryRead.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMQueryRead.1  !");
	}
if (icom->kanAddClass(CLSID_TDMQueryUpdateImpl,"Oberon.DMQueryUpdate.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMQueryUpdate.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprBankSchetImpl,ProgId_DMSprBankSchet,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprBankSchet)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprARMImpl,"Oberon.DMSprARM.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprARM.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprBankImpl,"Oberon.DMSprBank.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprBank.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprBrandImpl,"Oberon.DMSprBrand.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprBrand.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpBVNomImpl,"Oberon.DMSprGrpBVNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrpBVNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprBVNomImpl,"Oberon.DMSprBVNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprBVNom.1  !");
	}


if (icom->kanAddClass(CLSID_TDMSprCodeTelImpl,ProgId_DMSprCodeTel,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprCodeTel)+" !");
	}


if (icom->kanAddClass(CLSID_TDMSprCountryImpl,"Oberon.DMSprCountry.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprCountry.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprDiscountAutoImpl,ProgId_DMSprDiscountAuto,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprDiscountAuto)+" !");
	}
if (icom->kanAddClass(CLSID_TDMSprDiscountCardImpl,ProgId_DMSprDiscountCard,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprDiscountCard)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprDiscountCard_1Impl,ProgId_DMSprDiscountCard1,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprDiscountCard1)+" !");
	}
if (icom->kanAddClass(CLSID_TDMSprDocKlientImpl,"Oberon.DMSprDocKlient.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprDocKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprDogovorImpl,"Oberon.DMSprDogovor.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprDogovor.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprEdImpl,"Oberon.DMSprEd.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprEd.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprFirmImpl,ProgId_DMSprFirm,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprFirm)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrafikPlatImpl,"Oberon.DMSprGrafikPlat.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrafikPlat.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprImportEdImpl,"Oberon.DMSprImportEd.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprImportEd.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprImportNomImpl,"Oberon.DMSprImportNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprImportNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprImportSetImpl,"Oberon.DMSprImportSet.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprImportSet.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprInfBaseImpl,ProgId_DMSprInfBase,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMSprInfBase)+" !");
	}

if (icom->kanAddClass(CLSID_TDMSprKKMImpl,ProgId_DMSprKKM,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprKKM)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpKlientImpl,"Oberon.DMSprGrpKlient.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrpKlient.1  !");
	}

if (icom->kanAddClass(CLSID_TDMSprKlientImpl,ProgId_DMSprKlient,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprKlient)+"  !");
	}


if (icom->kanAddClass(CLSID_TDMSprKlientDopFisLImpl,"Oberon.DMSprKlientDopFisL.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprKlientDopFisL.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprKlientDopUrLImpl,"Oberon.DMSprKlientDopUrL.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprKlientDopUrL.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprModImpl,"Oberon.DMSprMod.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprMod.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprMPrigImpl,"Oberon.DMSprMPrig.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprMPrig.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNacenkaImpl,"Oberon.DMSprNacenka.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprNacenka.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprNakSkidokImpl,"Oberon.DMSprNakSkidok.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprNakSkidok.1  !");
	}

if (icom->kanAddClass(CLSID_TDMSprGrpNomImpl,ProgId_DMSprGrpNom,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprGrpNom)+" !");
	}

if (icom->kanAddClass(CLSID_TDMSprNomImpl,ProgId_DMSprNom,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNom)+" !");
	}
if (icom->kanAddClass(CLSID_TDMSprNomRestImpl,ProgId_DMSprNomRest,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_DMSprNomRest)+" !");
	}
if (icom->kanAddClass(CLSID_TDMSprNumTelImpl,"Oberon.DMSprNumTel.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprNumTel.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprOborudImpl,"Oberon.DMSprOborud.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprOborud.1  !");
	}
if (icom->kanAddClass(CLSID_TDMViborOborudImpl,"Oberon.DMViborOborud.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMViborOborud.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprOKEIImpl,"Oberon.DMSprOKEI.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprOKEI.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPartImpl,"Oberon.DMSprPart.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprPart.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPodrImpl,"Oberon.DMSprPodr.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprPodr.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPriceImpl,"Oberon.DMSprPrice.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprPrice.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprPriceScheduleImpl,"Oberon.DMSprPriceSchedule.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprPriceSchedule.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpProjectImpl,"Oberon.DMSprGrpProject.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrpProject.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprProjectImpl,"Oberon.DMSprProject.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprProject.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprScaleImpl,"Oberon.DMSprScale.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprScale.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprSezKFImpl,"Oberon.DMSprSezKF.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprSezKF.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprSezKFSProdImpl,"Oberon.DMSprSezKFSProd.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprSezKFSProd.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprSostProdImpl,ProgId_DMSprSostProd,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMSprSostProd)+"  !");
	}
if (icom->kanAddClass(CLSID_TDMSprStrObjectImpl,"Oberon.DMSprStrObject.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprStrobject.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprTypePriceImpl,"Oberon.DMSprTypePrice.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprTypePrice.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpUserImpl,"Oberon.DMSprGrpUser.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrpUser.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprUserImpl,"Oberon.DMSprUser.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprUser.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprGrpVesNomImpl,"Oberon.DMSprGrpVesNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprGrpVesNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVesNomImpl,"Oberon.DMSprVesNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprVesNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVidDiscountCardImpl,"Oberon.DMSprVidDiscountCard.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprVidDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVidKlientImpl,"Oberon.DMSprVidKlient.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprVidKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprVidNomImpl,"Oberon.DMSprVidNom.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprVidNom.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSetupImpl,"Oberon.DMSetup.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSetup.1  !");
	}
if (icom->kanAddClass(CLSID_TDMXSetupObmenImpl,"Oberon.DMXSetupObmen.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMXSetupObmen.1  !");
	}
if (icom->kanAddClass(CLSID_TDMTableNumberDocImpl,"Oberon.DMTableNumberDoc.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMTableNumberDoc.1  !");
	}
if (icom->kanAddClass(CLSID_TDMXTableIsmImpl,"Oberon.DMXTableIsm.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMXTableIsm.1  !");
	}
if (icom->kanAddClass(CLSID_TDMTableExtPrintFormImpl,ProgId_DMTableExtPrintForm,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMTableExtPrintForm)+"!");
	}
if (icom->kanAddClass(CLSID_TDMUserSetupImpl,"Oberon.DMUserSetup.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMUserSetup.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprInvImpl,"Oberon.DMSprInv.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprInv.1  !");
	}
if (icom->kanAddClass(CLSID_TDMSprRaschSchetImpl,"Oberon.DMSprRaschSchet.1","DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.DMSprRaschSchet.1  !");
	}

if (icom->kanAddClass(CLSID_TDMSprGrpBusinessOperImpl,ProgId_DMSprGrpBusinessOper,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMSprGrpBusinessOper)+"!");
	}
if (icom->kanAddClass(CLSID_TDMSprBusinessOperImpl,ProgId_DMSprBusinessOper,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMSprBusinessOper)+"!");
	}


if (icom->kanAddClass(CLSID_TDMSprOborudParamImpl,ProgId_DMSprOborudParam,"DMSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_DMSprOborudParam)+"!");
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

