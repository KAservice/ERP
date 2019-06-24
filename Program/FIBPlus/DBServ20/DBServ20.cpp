//$$---- axlib proj source ---- (stAXLibProjectSource)
#pragma hdrstop
#include <vcl.h>
#include <atl\atlvcl.h>

#include "UOleDM.h"
#include "UOleDMGurAllDoc.h"
#include "UOleDMSprSklad.h"
#include "UOleDMSprInfBase.h"
#include "UOleDMSprFirm.h"
#include "UOleDMSprEd.h"
#include "UOleDMSprGrpNom.h"
#include "UOleDMSprNom.h"
#include "UOleDMSprTypePrice.h"
#include "UOleDMSprPrice.h"
#include "UOleDMDocReal.h"
USEFORM("DM\UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("DocReal\UDMDocReal.cpp", DMDocReal); /* TDataModule: File Type */
USEFORM("GurAllDoc\UDMGurAllDoc.cpp", DMGurAllDoc); /* TDataModule: File Type */
USEFORM("SprEd\UDMSprEd.cpp", DMSprEd); /* TDataModule: File Type */
USEFORM("SprFirm\UDMSprFirm.cpp", DMSprFirm); /* TDataModule: File Type */
USEFORM("SprInfBase\UDMSprInfBase.cpp", DMSprInfBase); /* TDataModule: File Type */
USEFORM("SprNom\UDMSprGrpNom.cpp", DMSprGrpNom); /* TDataModule: File Type */
USEFORM("SprNom\UDMSprNom.cpp", DMSprNom); /* TDataModule: File Type */
USEFORM("SprPrice\UDMSprPrice.cpp", DMSprPrice); /* TDataModule: File Type */
USEFORM("SprSklad\UDMSprSklad.cpp", DMSprSklad); /* TDataModule: File Type */
USEFORM("SprTypePrice\UDMSprTypePrice.cpp", DMSprTypePrice); /* TDataModule: File Type */
USEFORM("Setup\UDMSetup.cpp", DMSetup); /* TDataModule: File Type */
USEFORM("SprUser\UDMSprUser.cpp", DMSprUser); /* TDataModule: File Type */
USEFORM("DMQuery\UDMQueryRead.cpp", DMQueryRead); /* TDataModule: File Type */
USEFORM("SprNomRest\UDMSprNomRest.cpp", DMSprNomRest); /* TDataModule: File Type */
USEFORM("TableNumberDoc\UDMTableNumberDoc.cpp", DMTableNumberDoc); /* TDataModule: File Type */
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "vclnp.lib"
#pragma resource "*.tlb"
TComModule  Project2Module;
TComModule &_Module = Project2Module;

AnsiString BaseVersion;
AnsiString ProgramVersion="2.5";

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_OleDM, TOleDMImpl)
  OBJECT_ENTRY(CLSID_OleDMGurAllDoc, TOleDMGurAllDocImpl)
  OBJECT_ENTRY(CLSID_OleDMSprSklad, TOleDMSprSkladImpl)
  OBJECT_ENTRY(CLSID_OleDMSprFirm, TOleDMSprFirmImpl)
  OBJECT_ENTRY(CLSID_OleDMSprInfBase, TOleDMSprInfBaseImpl)
  OBJECT_ENTRY(CLSID_OleDMSprEd, TOleDMSprEdImpl)
  OBJECT_ENTRY(CLSID_OleDMSprGrpNom, TOleDMSprGrpNomImpl)
  OBJECT_ENTRY(CLSID_OleDMSprNom, TOleDMSprNomImpl)
  OBJECT_ENTRY(CLSID_OleDMSprTypePrice, TOleDMSprTypePriceImpl)
  OBJECT_ENTRY(CLSID_OleDMSprPrice, TOleDMSprPriceImpl)
  OBJECT_ENTRY(CLSID_OleDMDocReal, TOleDMDocRealImpl)
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
