//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UDM.h"
#include "UDisplayPok.h"
#include "UScaner.h"
#include "UFiskReg.h"
#include "UFormaElementaSprSkladImpl.h"
#include "UFormaElementaSprSkladCF.h"
#include "UFormaSpiskaSprSkladImpl.h"
#include "UFormaSpiskaSprSkladCF.h"
#include "UFormaSpiskaSetupImpl.h"
#include "UFormaSpiskaSetupCF.h"
#include "UFormaElementaSprBankImpl.h"
#include "UFormaElementaSprBankCF.h"
#include "UFormaSpiskaSprBankImpl.h"
#include "UFormaSpiskaSprBankCF.h"
#include "UFormaElementaSprBankSchetImpl.h"
#include "UFormaElementaSprBankSchetCF.h"
#include "UFormaSpiskaSprBankSchetImpl.h"
#include "UFormaSpiskaSprBankSchetCF.h"
#include "UFormaElementaSprBrandImpl.h"
#include "UFormaElementaSprBrandCF.h"
#include "UFormaSpiskaSprBrandImpl.h"
#include "UFormaSpiskaSprBrandCF.h"
#include "UFormaElementaSprCountryImpl.h"
#include "UFormaElementaSprCountryCF.h"
#include "UFormaSpiskaSprCountryImpl.h"
#include "UFormaSpiskaSprCountryCF.h"
#include "UFormaElementaSprDocKlientImpl.h"
#include "UFormaElementaSprDocKlientCF.h"
#include "UFormaSpiskaSprDocKlientImpl.h"
#include "UFormaSpiskaSprDocKlientCF.h"
#include "UFormaElementaSprFirmImpl.h"
#include "UFormaElementaSprFirmCF.h"
#include "UFormaSpiskaSprFirmImpl.h"
#include "UFormaSpiskaSprFirmCF.h"
#include "UFormaSpiskaSprGrafikPlatImpl.h"
#include "UFormaSpiskaSprGrafikPlatCF.h"
#include "UFormaElementaSprInfBaseImpl.h"
#include "UFormaElementaSprInfBaseCF.h"
#include "UFormaSpiskaSprInfBaseImpl.h"
#include "UFormaSpiskaSprInfBaseCF.h"
#include "UFormaElementaSprInvImpl.h"
#include "UFormaElementaSprInvCF.h"
#include "UFormaSpiskaSprInvImpl.h"
#include "UFormaSpiskaSprInvCF.h"
#include "UFormaElementaSprKKMImpl.h"
#include "UFormaElementaSprKKMCF.h"
#include "UFormaSpiskaSprKKMImpl.h"
#include "UFormaSpiskaSprKKMCF.h"
#include "UFormaElementaSprKlientDopFisLImpl.h"
#include "UFormaElementaSprKlientDopFisLCF.h"
#include "UFormaElementaSprKlientDopUrLImpl.h"
#include "UFormaElementaSprKlientDopUrLCF.h"
#include "UFormaSpiskaSprModImpl.h"
#include "UFormaSpiskaSprModCF.h"
#include "UFormaSpiskaSprNacenkaImpl.h"
#include "UFormaSpiskaSprNacenkaCF.h"
#include "UFormaElementaSprNumTelImpl.h"
#include "UFormaElementaSprNumTelCF.h"
#include "UFormaSpiskaSprNumTelImpl.h"
#include "UFormaSpiskaSprNumTelCF.h"
#include "UFormaElementaSprOKEIImpl.h"
#include "UFormaElementaSprOKEICF.h"
#include "UFormaSpiskaSprOKEIImpl.h"
#include "UFormaSpiskaSprOKEICF.h"
#include "UFormaSpiskaSprPriceImpl.h"
#include "UFormaSpiskaSprPriceCF.h"
#include "UFormaSpiskaSprPriceScheduleImpl.h"
#include "UFormaSpiskaSprPriceScheduleCF.h"
#include "UFormaElementaSprGrpProjectImpl.h"
#include "UFormaElementaSprGrpProjectCF.h"
#include "UFormaElementaSprProjectImpl.h"
#include "UFormaElementaSprProjectCF.h"
#include "UFormaSpiskaSprProjectImpl.h"
#include "UFormaSpiskaSprProjectCF.h"
#include "UFormaElementaSprRaschSchetImpl.h"
#include "UFormaElementaSprRaschSchetCF.h"
#include "UFormaSpiskaSprRaschSchetImpl.h"
#include "UFormaSpiskaSprRaschSchetCF.h"
#include "UFormaElementaSprScaleImpl.h"
#include "UFormaElementaSprScaleCF.h"
#include "UFormaSpiskaSprScaleImpl.h"
#include "UFormaSpiskaSprScaleCF.h"
#include "UFormaSpiskaSprSezKFImpl.h"
#include "UFormaSpiskaSprSezKFCF.h"
#include "UFormaSpiskaSprSezKFSProdImpl.h"
#include "UFormaSpiskaSprSezKFSProdCF.h"
#include "UFormaElementaSprStrObjectImpl.h"
#include "UFormaElementaSprStrObjectCF.h"
#include "UFormaSpiskaSprStrObjectImpl.h"
#include "UFormaSpiskaSprStrObjectCF.h"
#include "UFormaElementaSprTypePriceImpl.h"
#include "UFormaElementaSprTypePriceCF.h"
#include "UFormaSpiskaSprTypePriceImpl.h"
#include "UFormaSpiskaSprTypePriceCF.h"
#include "UFormaElementaSprVidDiscountCardImpl.h"
#include "UFormaElementaSprVidDiscountCardCF.h"
#include "UFormaSpiskaSprVidDiscountCardImpl.h"
#include "UFormaSpiskaSprVidDiscountCardCF.h"
#include "UFormaSpiskaSprVidKlientImpl.h"
#include "UFormaSpiskaSprVidKlientCF.h"
#include "UFormaSpiskaSprVidNomImpl.h"
#include "UFormaSpiskaSprVidNomCF.h"
#include "UFormaSpiskaTableNumberDocImpl.h"
#include "UFormaSpiskaTableNumberDocCF.h"
#include "UFormaElementaSprPodrImpl.h"
#include "UFormaElementaSprPodrCF.h"
#include "UFormaSpiskaSprPodrImpl.h"
#include "UFormaSpiskaSprPodrCF.h"
#include "UFormaElementaXSetupObmenImpl.h"
#include "UFormaElementaXSetupObmenCF.h"
#include "UFormaSpiskaXSetupObmenImpl.h"
#include "UFormaSpiskaXSetupObmenCF.h"
#include "UFormaElementaSprGrpNomImpl.h"
#include "UFormaElementaSprGrpNomCF.h"
#include "UFormaElementaSprEdImpl.h"
#include "UFormaElementaSprEdCF.h"
#include "UFormaSpiskaSprEdImpl.h"
#include "UFormaSpiskaSprEdCF.h"
#include "UFormaElementaSprNomImpl.h"
#include "UFormaElementaSprNomCF.h"
#include "UFormaPodboraNomImpl.h"
#include "UFormaPodboraNomCF.h"
#include "UFormaSpiskaSprNomImpl.h"
#include "UFormaSpiskaSprNomCF.h"
#include "UFormaElementaSprGrpKlientImpl.h"
#include "UFormaElementaSprGrpKlientCF.h"
#include "UFormaElementaSprKlientImpl.h"
#include "UFormaElementaSprKlientCF.h"
#include "UFormaSpiskaSprKlientImpl.h"
#include "UFormaSpiskaSprKlientCF.h"
#include "UFormaElementaSprPartImpl.h"
#include "UFormaElementaSprPartCF.h"
#include "UFormaSpiskaSprPartImpl.h"
#include "UFormaSpiskaSprPartCF.h"
#include "UFormaSpiskaSprSostProdImpl.h"
#include "UFormaSpiskaSprSostProdCF.h"
#include "UFormaElementaSprOborudImpl.h"
#include "UFormaElementaSprOborudCF.h"
#include "UFormaSpiskaSprOborudImpl.h"
#include "UFormaSpiskaSprOborudCF.h"
#include "UFormaElementaSprMPrigImpl.h"
#include "UFormaElementaSprMPrigCF.h"
#include "UFormaSpiskaSprMPrigImpl.h"
#include "UFormaSpiskaSprMPrigCF.h"
#include "UFormaElementaSprNomRestImpl.h"
#include "UFormaElementaSprNomRestCF.h"
#include "UFormaSpiskaSprNomRestImpl.h"
#include "UFormaSpiskaSprNomRestCF.h"
#include "UFormaElementaSprImportNomImpl.h"
#include "UFormaElementaSprImportNomCF.h"
#include "UFormaSpiskaSprImportNomImpl.h"
#include "UFormaSpiskaSprImportNomCF.h"
#include "UFormaElementaSprDogovorImpl.h"
#include "UFormaElementaSprDogovorCF.h"
#include "UFormaSpiskaSprDogovorImpl.h"
#include "UFormaSpiskaSprDogovorCF.h"
#include "UFormaElementaSprDiscountCardImpl.h"
#include "UFormaElementaSprDiscountCardCF.h"
#include "UFormaSpiskaSprDiscountCardImpl.h"
#include "UFormaSpiskaSprDiscountCardCF.h"
#include "UFormaSpiskaSprDiscountCard_1Impl.h"
#include "UFormaSpiskaSprDiscountCard_1CF.h"
#include "UFormaElementaSprARMImpl.h"
#include "UFormaElementaSprARMCF.h"
#include "UFormaSpiskaSprARMImpl.h"
#include "UFormaSpiskaSprARMCF.h"
#include "UFormaElementaSprImportSetImpl.h"
#include "UFormaElementaSprImportSetCF.h"
#include "UFormaSpiskaSprImportSetImpl.h"
#include "UFormaSpiskaSprImportSetCF.h"
#include "UFormaSpiskaSprGrpNomImpl.h"
#include "UFormaSpiskaSprGrpNomCF.h"
#include "UFormaElementaSprImportEdImpl.h"
#include "UFormaElementaSprImportEdCF.h"
#include "UFormaSpiskaSprImportEdImpl.h"
#include "UFormaSpiskaSprImportEdCF.h"
#include "UFormaElementaSprGrpBVNomImpl.h"
#include "UFormaElementaSprGrpBVNomCF.h"
#include "UFormaSpiskaSprBVNomImpl.h"
#include "UFormaSpiskaSprBVNomCF.h"
#include "UFormaElementaSprGrpUserImpl.h"
#include "UFormaElementaSprGrpUserCF.h"
#include "UFormaElementaSprUserImpl.h"
#include "UFormaElementaSprUserCF.h"
#include "UFormaSpiskaSprUserImpl.h"
#include "UFormaSpiskaSprUserCF.h"
#include "UFormaElementaSprCodeTelImpl.h"
#include "UFormaElementaSprCodeTelCF.h"
#include "UFormaSpiskaSprCodeTelImpl.h"
#include "UFormaSpiskaSprCodeTelCF.h"
#include "UFormaElementaSprGrpVesNomImpl.h"
#include "UFormaElementaSprGrpVesNomCF.h"
#include "UFormaSpiskaSprVesNomImpl.h"
#include "UFormaSpiskaSprVesNomCF.h"
#include "UFormaElementaTableExtPrintFormImpl.h"
#include "UFormaElementaTableExtPrintFormCF.h"
#include "UFormaSpiskaTableExtPrintFormImpl.h"
#include "UFormaSpiskaTableExtPrintFormCF.h"
#include "UFormaElementaSprDiscountAutoImpl.h"
#include "UFormaElementaSprDiscountAutoCF.h"
#include "UFormaSpiskaSprDiscountAutoImpl.h"
#include "UFormaSpiskaSprDiscountAutoCF.h"
#include "UFormaElementaSprNakSkidokImpl.h"
#include "UFormaElementaSprNakSkidokCF.h"
#include "UFormaSpiskaSprNakSkidokImpl.h"
#include "UFormaSpiskaSprNakSkidokCF.h"
#include "UFormaSpiskaSprGrpKlientImpl.h"
#include "UFormaSpiskaSprGrpKlientCF.h"
#include "UFormaViborOborudImpl.h"
#include "UFormaViborOborudCF.h"
#include "UFormaElementaSprGrpBusinessOperImpl.h"
#include "UFormaElementaSprGrpBusinessOperCF.h"
#include "UFormaElementaSprBusinessOperImpl.h"
#include "UFormaElementaSprBusinessOperCF.h"
#include "UFormaSpiskaSprBusinessOperImpl.h"
#include "UFormaSpiskaSprBusinessOperCF.h"
#include "UFormaCreateCardImpl.h"
#include "UFormaCreateCardCF.h"


#include "UFormaSpiskaSprOborudParamImpl.h"
#include "UFormaSpiskaSprOborudParamCF.h"
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

TFiskReg  *glFR;
TScaner * glScaner;
TDisplayPok * glDisplayPok;

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
if (id_class==CLSID_TFormaElementaSprSkladImpl)
	{
	TFormaElementaSprSkladCF * ob=new TFormaElementaSprSkladCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else if (id_class==CLSID_TFormaSpiskaSprSkladImpl)
   {
	TFormaSpiskaSprSkladCF * ob=new TFormaSpiskaSprSkladCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSetupImpl)
   {
	TFormaSpiskaSetupCF * ob=new TFormaSpiskaSetupCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprBankImpl)
   {
	TFormaElementaSprBankCF * ob=new TFormaElementaSprBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprBankImpl)
   {
	TFormaSpiskaSprBankCF * ob=new TFormaSpiskaSprBankCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprBankSchetImpl)
   {
	TFormaElementaSprBankSchetCF * ob=new TFormaElementaSprBankSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprBankSchetImpl)
   {
	TFormaSpiskaSprBankSchetCF * ob=new TFormaSpiskaSprBankSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprBrandImpl)
   {
	TFormaElementaSprBrandCF * ob=new TFormaElementaSprBrandCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprBrandImpl)
   {
	TFormaSpiskaSprBrandCF * ob=new TFormaSpiskaSprBrandCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCountryImpl)
   {
	TFormaElementaSprCountryCF * ob=new TFormaElementaSprCountryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprCountryImpl)
   {
	TFormaSpiskaSprCountryCF * ob=new TFormaSpiskaSprCountryCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprDocKlientImpl)
   {
	TFormaElementaSprDocKlientCF * ob=new TFormaElementaSprDocKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprDocKlientImpl)
   {
	TFormaSpiskaSprDocKlientCF * ob=new TFormaSpiskaSprDocKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprFirmImpl)
   {
	TFormaElementaSprFirmCF * ob=new TFormaElementaSprFirmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprFirmImpl)
   {
	TFormaSpiskaSprFirmCF * ob=new TFormaSpiskaSprFirmCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprGrafikPlatImpl)
   {
	TFormaSpiskaSprGrafikPlatCF * ob=new TFormaSpiskaSprGrafikPlatCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprInfBaseImpl)
   {
	TFormaElementaSprInfBaseCF * ob=new TFormaElementaSprInfBaseCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprInfBaseImpl)
   {
	TFormaSpiskaSprInfBaseCF * ob=new TFormaSpiskaSprInfBaseCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprInvImpl)
   {
	TFormaElementaSprInvCF * ob=new TFormaElementaSprInvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprInvImpl)
   {
	TFormaSpiskaSprInvCF * ob=new TFormaSpiskaSprInvCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprKKMImpl)
   {
	TFormaElementaSprKKMCF * ob=new TFormaElementaSprKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprKKMImpl)
   {
	TFormaSpiskaSprKKMCF * ob=new TFormaSpiskaSprKKMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprKlientDopFisLImpl)
   {
	TFormaElementaSprKlientDopFisLCF * ob=new TFormaElementaSprKlientDopFisLCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprKlientDopUrLImpl)
   {
	TFormaElementaSprKlientDopUrLCF * ob=new TFormaElementaSprKlientDopUrLCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprModImpl)
   {
	TFormaSpiskaSprModCF * ob=new TFormaSpiskaSprModCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNacenkaImpl)
   {
	TFormaSpiskaSprNacenkaCF * ob=new TFormaSpiskaSprNacenkaCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprNumTelImpl)
   {
	TFormaElementaSprNumTelCF * ob=new TFormaElementaSprNumTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNumTelImpl)
   {
	TFormaSpiskaSprNumTelCF * ob=new TFormaSpiskaSprNumTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprOKEIImpl)
   {
	TFormaElementaSprOKEICF * ob=new TFormaElementaSprOKEICF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprOKEIImpl)
   {
	TFormaSpiskaSprOKEICF * ob=new TFormaSpiskaSprOKEICF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPriceImpl)
   {
	TFormaSpiskaSprPriceCF * ob=new TFormaSpiskaSprPriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPriceScheduleImpl)
   {
	TFormaSpiskaSprPriceScheduleCF * ob=new TFormaSpiskaSprPriceScheduleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpProjectImpl)
   {
	TFormaElementaSprGrpProjectCF * ob=new TFormaElementaSprGrpProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprProjectImpl)
   {
	TFormaElementaSprProjectCF * ob=new TFormaElementaSprProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprProjectImpl)
   {
	TFormaSpiskaSprProjectCF * ob=new TFormaSpiskaSprProjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprRaschSchetImpl)
   {
	TFormaElementaSprRaschSchetCF * ob=new TFormaElementaSprRaschSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprRaschSchetImpl)
   {
	TFormaSpiskaSprRaschSchetCF * ob=new TFormaSpiskaSprRaschSchetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprScaleImpl)
   {
	TFormaElementaSprScaleCF * ob=new TFormaElementaSprScaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprScaleImpl)
   {
	TFormaSpiskaSprScaleCF * ob=new TFormaSpiskaSprScaleCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprSezKFImpl)
   {
	TFormaSpiskaSprSezKFCF * ob=new TFormaSpiskaSprSezKFCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprSezKFSProdImpl)
   {
	TFormaSpiskaSprSezKFSProdCF * ob=new TFormaSpiskaSprSezKFSProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprStrObjectImpl)
   {
	TFormaElementaSprStrObjectCF * ob=new TFormaElementaSprStrObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprStrObjectImpl)
   {
	TFormaSpiskaSprStrObjectCF * ob=new TFormaSpiskaSprStrObjectCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprTypePriceImpl)
   {
	TFormaElementaSprTypePriceCF * ob=new TFormaElementaSprTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprTypePriceImpl)
   {
	TFormaSpiskaSprTypePriceCF * ob=new TFormaSpiskaSprTypePriceCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprVidDiscountCardImpl)
   {
	TFormaElementaSprVidDiscountCardCF * ob=new TFormaElementaSprVidDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprVidDiscountCardImpl)
   {
	TFormaSpiskaSprVidDiscountCardCF * ob=new TFormaSpiskaSprVidDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprVidKlientImpl)
   {
	TFormaSpiskaSprVidKlientCF * ob=new TFormaSpiskaSprVidKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprVidNomImpl)
   {
	TFormaSpiskaSprVidNomCF * ob=new TFormaSpiskaSprVidNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaTableNumberDocImpl)
   {
	TFormaSpiskaTableNumberDocCF * ob=new TFormaSpiskaTableNumberDocCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPodrImpl)
   {
	TFormaElementaSprPodrCF * ob=new TFormaElementaSprPodrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPodrImpl)
   {
	TFormaSpiskaSprPodrCF * ob=new TFormaSpiskaSprPodrCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaXSetupObmenImpl)
   {
	TFormaElementaXSetupObmenCF * ob=new TFormaElementaXSetupObmenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaXSetupObmenImpl)
   {
	TFormaSpiskaXSetupObmenCF * ob=new TFormaSpiskaXSetupObmenCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpNomImpl)
   {
	TFormaElementaSprGrpNomCF * ob=new TFormaElementaSprGrpNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprEdImpl)
   {
	TFormaElementaSprEdCF * ob=new TFormaElementaSprEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprEdImpl)
   {
	TFormaSpiskaSprEdCF * ob=new TFormaSpiskaSprEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprNomImpl)
   {
	TFormaElementaSprNomCF * ob=new TFormaElementaSprNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaPodboraNomImpl)
   {
	TFormaPodboraNomCF * ob=new TFormaPodboraNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomImpl)
   {
	TFormaSpiskaSprNomCF * ob=new TFormaSpiskaSprNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpKlientImpl)
   {
	TFormaElementaSprGrpKlientCF * ob=new TFormaElementaSprGrpKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprKlientImpl)
   {
	TFormaElementaSprKlientCF * ob=new TFormaElementaSprKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprKlientImpl)
   {
	TFormaSpiskaSprKlientCF * ob=new TFormaSpiskaSprKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprPartImpl)
   {
	TFormaElementaSprPartCF * ob=new TFormaElementaSprPartCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprPartImpl)
   {
	TFormaSpiskaSprPartCF * ob=new TFormaSpiskaSprPartCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprSostProdImpl)
   {
	TFormaSpiskaSprSostProdCF * ob=new TFormaSpiskaSprSostProdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprOborudImpl)
   {
	TFormaElementaSprOborudCF * ob=new TFormaElementaSprOborudCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprOborudImpl)
   {
	TFormaSpiskaSprOborudCF * ob=new TFormaSpiskaSprOborudCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprMPrigImpl)
   {
	TFormaElementaSprMPrigCF * ob=new TFormaElementaSprMPrigCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprMPrigImpl)
   {
	TFormaSpiskaSprMPrigCF * ob=new TFormaSpiskaSprMPrigCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprNomRestImpl)
   {
	TFormaElementaSprNomRestCF * ob=new TFormaElementaSprNomRestCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNomRestImpl)
   {
	TFormaSpiskaSprNomRestCF * ob=new TFormaSpiskaSprNomRestCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprImportNomImpl)
   {
	TFormaElementaSprImportNomCF * ob=new TFormaElementaSprImportNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprImportNomImpl)
   {
	TFormaSpiskaSprImportNomCF * ob=new TFormaSpiskaSprImportNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprDogovorImpl)
   {
	TFormaElementaSprDogovorCF * ob=new TFormaElementaSprDogovorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprDogovorImpl)
   {
	TFormaSpiskaSprDogovorCF * ob=new TFormaSpiskaSprDogovorCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprDiscountCardImpl)
   {
	TFormaElementaSprDiscountCardCF * ob=new TFormaElementaSprDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprDiscountCardImpl)
   {
	TFormaSpiskaSprDiscountCardCF * ob=new TFormaSpiskaSprDiscountCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprDiscountCard_1Impl)
   {
	TFormaSpiskaSprDiscountCard_1CF * ob=new TFormaSpiskaSprDiscountCard_1CF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprARMImpl)
   {
	TFormaElementaSprARMCF * ob=new TFormaElementaSprARMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprARMImpl)
   {
	TFormaSpiskaSprARMCF * ob=new TFormaSpiskaSprARMCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprImportSetImpl)
   {
	TFormaElementaSprImportSetCF * ob=new TFormaElementaSprImportSetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaSpiskaSprImportSetImpl)
   {
	TFormaSpiskaSprImportSetCF * ob=new TFormaSpiskaSprImportSetCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprGrpNomImpl)
   {
	TFormaSpiskaSprGrpNomCF * ob=new TFormaSpiskaSprGrpNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
   else if (id_class==CLSID_TFormaElementaSprImportEdImpl)
   {
	TFormaElementaSprImportEdCF * ob=new TFormaElementaSprImportEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprImportEdImpl)
   {
	TFormaSpiskaSprImportEdCF * ob=new TFormaSpiskaSprImportEdCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpBVNomImpl)
   {
	TFormaElementaSprGrpBVNomCF * ob=new TFormaElementaSprGrpBVNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprBVNomImpl)
   {
	TFormaSpiskaSprBVNomCF * ob=new TFormaSpiskaSprBVNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpUserImpl)
   {
	TFormaElementaSprGrpUserCF * ob=new TFormaElementaSprGrpUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprUserImpl)
   {
	TFormaElementaSprUserCF * ob=new TFormaElementaSprUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprUserImpl)
   {
	TFormaSpiskaSprUserCF * ob=new TFormaSpiskaSprUserCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprCodeTelImpl)
   {
	TFormaElementaSprCodeTelCF * ob=new TFormaElementaSprCodeTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprCodeTelImpl)
   {
	TFormaSpiskaSprCodeTelCF * ob=new TFormaSpiskaSprCodeTelCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpVesNomImpl)
   {
	TFormaElementaSprGrpVesNomCF * ob=new TFormaElementaSprGrpVesNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprVesNomImpl)
   {
	TFormaSpiskaSprVesNomCF * ob=new TFormaSpiskaSprVesNomCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaTableExtPrintFormImpl)
   {
	TFormaElementaTableExtPrintFormCF * ob=new TFormaElementaTableExtPrintFormCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaTableExtPrintFormImpl)
   {
	TFormaSpiskaTableExtPrintFormCF * ob=new TFormaSpiskaTableExtPrintFormCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprDiscountAutoImpl)
   {
	TFormaElementaSprDiscountAutoCF * ob=new TFormaElementaSprDiscountAutoCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprDiscountAutoImpl)
   {
	TFormaSpiskaSprDiscountAutoCF * ob=new TFormaSpiskaSprDiscountAutoCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprNakSkidokImpl)
   {
	TFormaElementaSprNakSkidokCF * ob=new TFormaElementaSprNakSkidokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprNakSkidokImpl)
   {
	TFormaSpiskaSprNakSkidokCF * ob=new TFormaSpiskaSprNakSkidokCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprGrpKlientImpl)
   {
	TFormaSpiskaSprGrpKlientCF * ob=new TFormaSpiskaSprGrpKlientCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaViborOborudImpl)
   {
	TFormaViborOborudCF * ob=new TFormaViborOborudCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaElementaSprGrpBusinessOperImpl)
   {
	TFormaElementaSprGrpBusinessOperCF * ob=new TFormaElementaSprGrpBusinessOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }

else if (id_class==CLSID_TFormaElementaSprBusinessOperImpl)
   {
	TFormaElementaSprBusinessOperCF * ob=new TFormaElementaSprBusinessOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprBusinessOperImpl)
   {
	TFormaSpiskaSprBusinessOperCF * ob=new TFormaSpiskaSprBusinessOperCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaCreateCardImpl)
   {
	TFormaCreateCardCF * ob=new TFormaCreateCardCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
   }
else if (id_class==CLSID_TFormaSpiskaSprOborudParamImpl)
   {
	TFormaSpiskaSprOborudParamCF * ob=new TFormaSpiskaSprOborudParamCF();
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

if (icom->kanAddClass(CLSID_TFormaElementaSprSkladImpl,ProgId_FormaSpiskaSprSklad,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprSklad)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprSkladImpl,"Oberon.FormaSpiskaSprSklad.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprSklad.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSetupImpl,ProgId_FormaSpiskaSetup,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSetup)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprBankImpl,"Oberon.FormaElementaSprBank.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprBank.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBankImpl,"Oberon.FormaSpiskaSprBank.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprBank.1  !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprBankSchetImpl,"Oberon.FormaElementaSprBankSchet.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprBankSchet.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBankSchetImpl,ProgId_FormaSpiskaSprBankSchet,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprBankSchet.1  !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprBrandImpl,ProgId_FormaSpiskaSprBrand,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprBrand)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprBrandImpl,"Oberon.FormaElementaSprBrand.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprBrand.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBrandImpl,"Oberon.FormaSpiskaSprBrand.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprBrand.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprCountryImpl,"Oberon.FormaElementaSprCountry.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprCountry.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprCountryImpl,"Oberon.FormaSpiskaSprCountry.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprCountry.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprDocKlientImpl,"Oberon.FormaElementaSprDocKlient.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprDocKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDocKlientImpl,"Oberon.FormaSpiskaSprDocKlient.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprDocKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprFirmImpl,"Oberon.FormaElementaSprFirm.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprFirm.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprFirmImpl,ProgId_FormaSpiskaSprFirm,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprFirm)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprGrafikPlatImpl,"Oberon.FormaSpiskaSprGrafikPlat.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprGrafikPlat.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprInfBaseImpl,ProgId_FormaSpiskaSprInfBase,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprInfBase)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprInfBaseImpl,"Oberon.FormaSpiskaSprInfBase.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprInfBase.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprInvImpl,"Oberon.FormaElementaSprInv.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprInv.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprInvImpl,ProgId_FormaSpiskaSprInv,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprInv)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprKKMImpl,"Oberon.FormaElementaSprKKM.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprKKM.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprKKMImpl,ProgId_FormaSpiskaSprKKM,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprKKM)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprKlientDopFisLImpl,"Oberon.FormaElementaSprKlientDopFisL.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprKlientDopFisL.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprKlientDopUrLImpl,"Oberon.FormaElementaSprKlientDopUrL.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprKlientDopUrL.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprModImpl,"Oberon.FormaSpiskaSprMod.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprMod.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNacenkaImpl,"Oberon.FormaSpiskaSprNacenka.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprNacenka.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNumTelImpl,"Oberon.FormaElementaSprNumTel.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprNumTel.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNumTelImpl,"Oberon.FormaSpiskaSprNumTel.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprNumTel.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprOKEIImpl,"Oberon.FormaElementaSprOKEI.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprOKEI.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprOKEIImpl,"Oberon.FormaSpiskaSprOKEI.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprOKEI.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPriceImpl,"Oberon.FormaSpiskaSprPrice.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprPrice.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPriceScheduleImpl,"Oberon.FormaSpiskaSprPriceSchedule.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprPriceSchedule.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpProjectImpl,"Oberon.FormaElementaSprGrpProject.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpProject.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprProjectImpl,"Oberon.FormaElementaSprProject.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprProject.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprProjectImpl,ProgId_FormaSpiskaSprProject,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprProject)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprRaschSchetImpl,"Oberon.FormaElementaSprRaschSchet.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprRaschSchet.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprRaschSchetImpl,"Oberon.FormaSpiskaSprRaschSchet.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprRaschSchet.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprScaleImpl,"Oberon.FormaElementaSprScale.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprScale.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprScaleImpl,ProgId_FormaSpiskaSprScale,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaSpiskaSprScale)+"!");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprSezKFImpl,"Oberon.FormaSpiskaSprSezKF.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprSezKF.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprSezKFSProdImpl,"Oberon.FormaSpiskaSprSezKFSProd.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprSezKFSProd.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprStrObjectImpl,ProgId_FormaSpiskaSprStrObject,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprStrObject)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprStrObjectImpl,"Oberon.FormaSpiskaSprStrObject.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprStrObject.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprTypePriceImpl, ProgId_FormaElementaSprTypePrice,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprTypePrice)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprTypePriceImpl,ProgId_FormaSpiskaSprTypePrice,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprTypePrice)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprVidDiscountCardImpl,"Oberon.FormaElSprVidDiscountCard.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElSprVidDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprVidDiscountCardImpl,ProgId_FormaSpiskaSprVidDiscountCard,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprVidDiscountCard)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprVidKlientImpl,ProgId_FormaSpiskaSprVidKlient,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprVidKlient)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprVidNomImpl,ProgId_FormaSpiskaSprVidNom,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprVidNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaTableNumberDocImpl,ProgId_FormaSpiskaTableNumberDoc,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaSpiskaTableNumberDoc)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPodrImpl,"Oberon.FormaElementaSprPodr.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprPodr.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPodrImpl,ProgId_FormaSpiskaSprPodr,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprPodr)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaXSetupObmenImpl,"Oberon.FormaElementaXSetupObmen.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaXSetupObmen.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaXSetupObmenImpl,ProgId_FormaSpiskaXSetupObmen,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaXSetupObmen)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpNomImpl,"Oberon.FormaElementaSprGrpNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprEdImpl,"Oberon.FormaElementaSprEd.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprEd.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprEdImpl,ProgId_FormaSpiskaSprEd,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprEd)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNomImpl,"Oberon.FormaElementaSprNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaPodboraNomImpl,"Oberon.FormaPodboraNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaPodboraNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomImpl,ProgId_FormaSpiskaSprNom,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpKlientImpl,"Oberon.FormaElementaSprGrpKlient.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprKlientImpl,"Oberon.FormaElementaSprKlient.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprKlientImpl,ProgId_FormaSpiskaSprKlient,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaSpiskaSprKlient)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprPartImpl,"Oberon.FormaElementaSprPart.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprPart.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprSostProdImpl,"Oberon.FormaSpiskaSprSostProd.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprSostProd.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprOborudImpl,"Oberon.FormaElementaSprOborud.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprOborud.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprOborudImpl,"Oberon.FormaSpiskaSprOborud.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprOborud.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprMPrigImpl,"Oberon.FormaElementaSprMPrig.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprMPrig.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprMPrigImpl,ProgId_FormaSpiskaSprMPrig,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprMPrig)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNomRestImpl,"Oberon.FormaElementaSprNomRest.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprNomRest.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNomRestImpl,ProgId_FormaSpiskaSprNomRest,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNomRest)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprImportNomImpl,"Oberon.FormaElementaSprImportNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprImportNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprImportNomImpl,"Oberon.FormaSpiskaSprImportNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprImportNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprDogovorImpl,"Oberon.FormaElementaSprDogovor.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprDogovor.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDogovorImpl,"Oberon.FormaSpiskaSprDogovor.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprDogovor.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprDiscountCardImpl,"Oberon.FormaElementaSprDiscountCard.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprDiscountCard.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDiscountCardImpl,ProgId_FormaSpiskaSprDiscountCard,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprDiscountCard)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDiscountCard_1Impl,ProgId_FormaSpiskaSprDiscountCard1,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprDiscountCard1)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprARMImpl,"Oberon.FormaElementaSprARM.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprARM.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprARMImpl,ProgId_FormaSpiskaSprARM,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprARM)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprImportSetImpl,"Oberon.FormaElementaSprImportSet.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprImportSet.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprImportSetImpl,ProgId_FormaSpiskaSprImportSet,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprImportSet)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprGrpNomImpl,"Oberon.FormaSpiskaSprGrpNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprGrpNom.1  !");
	}

if (icom->kanAddClass(CLSID_TFormaElementaSprImportEdImpl,"Oberon.FormaElementaSprImportEd.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprImportEd.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprImportEdImpl,"Oberon.FormaSpiskaSprImportEd.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprImportEd.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpBVNomImpl,"Oberon.FormaElementaSprGrpBVNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpBVNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBVNomImpl,ProgId_FormaSpiskaSprBVNom,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprBVNom)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpUserImpl,"Oberon.FormaElementaSprGrpUser.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpUser.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprUserImpl,"Oberon.FormaElementaSprUser.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprUser.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprUserImpl,ProgId_FormaSpiskaSprUser,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprUser)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprCodeTelImpl,"Oberon.FormaElementaSprCodeTel.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprCodeTel.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprCodeTelImpl,ProgId_FormaSpiskaSprCodeTel,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprCodeTel)+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpVesNomImpl,"Oberon.FormaElementaSprGrpVesNom.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprGrpVesNom.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprVesNomImpl,ProgId_FormaSpiskaSprVesNom,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprVesNom)+"!");
	}


if (icom->kanAddClass(CLSID_TFormaElementaTableExtPrintFormImpl,"Oberon.FormaElTableExtPrintForm.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaTableExtPrintForm)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaTableExtPrintFormImpl,ProgId_FormaSpiskaTableExtPrintForm,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaTableExtPrintForm)+"!");
	}



if (icom->kanAddClass(CLSID_TFormaElementaSprDiscountAutoImpl,"Oberon.FormaElementaSprDiscountAuto.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprDiscountAuto.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprDiscountAutoImpl,ProgId_FormaSpiskaSprDiscountAuto,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class -"+UnicodeString(ProgId_FormaSpiskaSprDiscountAuto)+" !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprNakSkidokImpl,"Oberon.FormaElementaSprNakSkidok.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaElementaSprNakSkidok.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprNakSkidokImpl,ProgId_FormaSpiskaSprNakSkidok ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprNakSkidok )+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprGrpKlientImpl,"Oberon.FormaSpiskaSprGrpKlient.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprGrpKlient.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprPartImpl,"Oberon.FormaSpiskaSprPart.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaSpiskaSprPart.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaViborOborudImpl,"Oberon.FormaViborOborud.1","FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Oberon.FormaViborOborud.1  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprGrpBusinessOperImpl,ProgId_FormaElementaSprGrpBusinessOper ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprGrpBusinessOper )+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaElementaSprBusinessOperImpl,ProgId_FormaElementaSprBusinessOper ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaElementaSprBusinessOper )+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaSpiskaSprBusinessOperImpl,ProgId_FormaSpiskaSprBusinessOper ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprBusinessOper )+"  !");
	}
if (icom->kanAddClass(CLSID_TFormaCreateCardImpl,ProgId_FormaCreateCard ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaCreateCard)+"  !");
	}


if (icom->kanAddClass(CLSID_TFormaSpiskaSprOborudParamImpl,ProgId_FormaSpiskaSprOborudParam ,"FormsSpr.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - "+UnicodeString(ProgId_FormaSpiskaSprOborudParam )+"  !");
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

