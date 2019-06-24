//$$---- axlib proj source ---- (stAXLibProjectSource)
#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include "OleDMGurAllDocImpl.h"
#include "OleDMImpl.h"
#include "OleDMSprSkladImpl.h"
#include "OleDMSprFirmImpl.h"
#include "OleDMSprNomImpl.h"
#include "OleDMSprEdImpl.h"
#include "OleDMDocRepKKMImpl.h"
#include "OleDMSprGrpNomImpl.h"
#include "OleDMSprTypePriceImpl.h"
#include "OleDMSprPriceImpl.h"
#include "OleDMDocPerImpl.h"
#include "OleDMDocPrihNaklImpl.h"
#include "OleDMDocSpisNomImpl.h"
#include "OleDMDocOstNomImpl.h"
#include "OleDMSprInfBaseImpl.h"
USEFORM("..\DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("..\GurAllDoc\UDMGurAllDoc.cpp", DMGurAllDoc); /* TDataModule: File Type */
USEFORM("..\Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("..\SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("..\SprSklad\UDMSprSklad.cpp", DMSprSklad); /* TDataModule: File Type */
USEFORM("..\DMXTableIsm\UDMXTableIsm.cpp", DMXTableIsm); /* TDataModule: File Type */
USEFORM("..\SprNom\UDMSprNom.cpp", DMSprNom); /* TDataModule: File Type */
USEFORM("..\SprEd\UDMSprEd.cpp", DMSprEd); /* TDataModule: File Type */
USEFORM("..\DocRepKKM\UDMDocRepKKM.cpp", DMDocRepKKM); /* TDataModule: File Type */
USEFORM("..\RegOtrSpisNom\UDMRegOtrSpisNom.cpp", DMRegOtrSpisNom); /* TDataModule: File Type */
USEFORM("..\RegReal\UDMRegReal.cpp", DMRegReal); /* TDataModule: File Type */
USEFORM("..\RegSebProd\UDMRegSebProd.cpp", DMRegSebProd); /* TDataModule: File Type */
USEFORM("..\RegVipuskProd\UDMRegVipuskProd.cpp", DMRegVipuskProd); /* TDataModule: File Type */
USEFORM("..\RegOstNom\UDMRegOstNom.cpp", DMRegOstNom); /* TDataModule: File Type */
USEFORM("..\RegVsRasch\UDMRegVsRasch.cpp", DMRegVsRasch); /* TDataModule: File Type */
USEFORM("..\SprSostProd\UDMSostProd.cpp", DMSprSostProd); /* TDataModule: File Type */
USEFORM("..\SprNomRest\UDMSprNomRest.cpp", DMSprNomRest); /* TDataModule: File Type */
USEFORM("..\SprNom\UDMSprGrpNom.cpp", DMSprGrpNom); /* TDataModule: File Type */
USEFORM("..\SprTypePrice\UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("..\SprPrice\UDMSprPrice.cpp", DMSprPrice); /* TDataModule: File Type */
USEFORM("..\DocPer\UDMDocPer.cpp", DMDocPer); /* TDataModule: File Type */
USEFORM("..\SprPart\UDMSprPart.cpp", DMSprPart); /* TDataModule: File Type */
USEFORM("..\DocPrihNakl\UDMDocPrihNakl.cpp", DMDocPrihNakl); /* TDataModule: File Type */
USEFORM("..\DocInv\UDMDocInv.cpp", DMDocInv); /* TDataModule: File Type */
USEFORM("..\DocSpisNom\UDMDocSpisNom.cpp", DMDocSpisNom); /* TDataModule: File Type */
USEFORM("..\DocOstNom\UDMDocOstNom.cpp", DMDocOstNom); /* TDataModule: File Type */
USEFORM("..\SprInfBase\UDMSprInfBase.cpp", DMSprInfBase); /* TDataModule: File Type */
USEFORM("..\DocCheckKKM\UDMDocCheck.cpp", DMDocCheck); /* TDataModule: File Type */
USEFORM("..\DocPlP\UDMDocPlP.cpp", DMDocPLP); /* TDataModule: File Type */
USEFORM("..\DocPostNaSchet\UDMDocPostNaSchet.cpp", DMDocPostNaSchet); /* TDataModule: File Type */
USEFORM("..\DocReal\UDMDocReal.cpp", DMDocReal); /* TDataModule: File Type */
USEFORM("..\DocRealRest\UDMDocRealRest.cpp", DMDocRealRest); /* TDataModule: File Type */
USEFORM("..\DocVosvratPost\UDMDocVosvratPost.cpp", DMDocVosvratPost); /* TDataModule: File Type */
USEFORM("..\DocPKO\UDMDocPKO.cpp", DMDocPKO); /* TDataModule: File Type */
USEFORM("..\DocRealRozn\UDMDocRealRozn.cpp", DMDocRealRozn); /* TDataModule: File Type */
USEFORM("..\DocRKORozn\UDMDocRKORozn.cpp", DMDocRKORozn); /* TDataModule: File Type */
USEFORM("..\DocShet\UDMDocSchet.cpp", DMDocSchet); /* TDataModule: File Type */
USEFORM("..\DocRecKDR\UDMDocRecKDR.cpp", DMDocRecKDR); /* TDataModule: File Type */
USEFORM("..\RegKassa\UDMRegKassa.cpp", DMRegKassa); /* TDataModule: File Type */
USEFORM("..\RegBank\UDMRegBank.cpp", DMRegBank); /* TDataModule: File Type */
USEFORM("..\RegAdvanceCustomer\UDMRegAdvanceCustomer.cpp", DMRegAdvanceCustomer); /* TDataModule: File Type */
USEFORM("..\RegPaySale\UDMRegPaySale.cpp", DMRegPaySale); /* TDataModule: File Type */
USEFORM("..\DocRKO\UDMDocRKO.cpp", DMDocRKO); /* TDataModule: File Type */
USEFORM("..\DocOstVs\UDMDocOstVs.cpp", DMDocOstVs); /* TDataModule: File Type */
USEFORM("..\DocSchetFact\UDMDocSchetFact.cpp", DMDocSchetFact); /* TDataModule: File Type */
USEFORM("..\DocPKORozn\UDMDocPKORozn.cpp", DMDocPKORozn); /* TDataModule: File Type */
USEFORM("..\SFirm\UDMSprFirm.cpp", DMSprFirm); /* TDataModule: File Type */
//---------------------------------------------------------------------------
#pragma package(smart_init)
TComModule  Project2Module;
TComModule &_Module = Project2Module;
AnsiString BaseVersion;
AnsiString ProgramVersion="2.7";

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_OleDMGurAllDoc, TOleDMGurAllDocImpl)
  OBJECT_ENTRY(CLSID_OleDM, TOleDMImpl)
  OBJECT_ENTRY(CLSID_OleDMSprSklad, TOleDMSprSkladImpl)
  OBJECT_ENTRY(CLSID_OleDMSprFirm, TOleDMSprFirmImpl)
  OBJECT_ENTRY(CLSID_OleDMSprNom, TOleDMSprNomImpl)
  OBJECT_ENTRY(CLSID_OleDMSprEd, TOleDMSprEdImpl)
  OBJECT_ENTRY(CLSID_OleDMDocRepKKM, TOleDMDocRepKKMImpl)
  OBJECT_ENTRY(CLSID_OleDMSprGrpNom, TOleDMSprGrpNomImpl)
  OBJECT_ENTRY(CLSID_OleDMSprTypePrice, TOleDMSprTypePriceImpl)
  OBJECT_ENTRY(CLSID_OleDMSprPrice, TOleDMSprPriceImpl)
  OBJECT_ENTRY(CLSID_OleDMDocPer, TOleDMDocPerImpl)
  OBJECT_ENTRY(CLSID_OleDMDocPrihNakl, TOleDMDocPrihNaklImpl)
  OBJECT_ENTRY(CLSID_OleDMDocSpisNom, TOleDMDocSpisNomImpl)
  OBJECT_ENTRY(CLSID_OleDMDocOstNom, TOleDMDocOstNomImpl)
  OBJECT_ENTRY(CLSID_OleDMSprInfBase, TOleDMSprInfBaseImpl)
END_OBJECT_MAP()

// Entry point of your Server invoked by Windows for processes or threads are
// initialized or terminated.
//
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hinst);
        DisableThreadLibraryCalls(hinst);
    }
    return TRUE;
}

// _Module.Term is typically invoked from the DLL_PROCESS_DETACH of your
// DllEntryPoint. However, this may result in an incorrect shutdown sequence.
// Instead an Exit routine is setup to invoke the cleanup routine
// CComModule::Term.
//
void ModuleTerm(void)
{
    _Module.Term();
}
#pragma exit ModuleTerm 63

// Entry point of your Server invoked to inquire whether the DLL is no
// longer in use and should be unloaded.
//
STDAPI __export DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

// Entry point of your Server allowing OLE to retrieve a class object from
// your Server
//
STDAPI __export DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

// Entry point of your Server invoked to instruct the server to create
// registry entries for all classes supported by the module
//
STDAPI __export DllRegisterServer(void)
{
    return _Module.RegisterServer(TRUE);
}

// Entry point of your Server invoked to instruct the server to remove
// all registry entries created through DllRegisterServer.
//
STDAPI __export DllUnregisterServer(void)
{
    return _Module.UnregisterServer();
}
//---------------------------------------------------------------------------
