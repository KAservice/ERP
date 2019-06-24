 // 1.1
// Unit1.h : Declaration of the TOleDMSprInfBaseImpl

#ifndef UOleDMSprFirmH
#define UOleDMSprFirmH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprInfBaseImpl     Implements IOleDMSprInfBase, default interface of OleDMSprInfBase
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprInfBase
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprInfBaseImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprInfBaseImpl, &CLSID_OleDMSprInfBase>,
  public IDispatchImpl<IOleDMSprInfBase, &IID_IOleDMSprInfBase, &LIBID_DBServ20>
{
public:
  TOleDMSprInfBaseImpl()
  {
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMSprInfBase");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprInfBaseImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprInfBaseImpl)
  COM_INTERFACE_ENTRY(IOleDMSprInfBase)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprInfBase)
END_COM_MAP()

// IOleDMSprInfBase
public:

};

#endif //Unit1H
