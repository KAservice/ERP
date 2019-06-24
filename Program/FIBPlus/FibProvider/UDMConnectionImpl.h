// 1.2
// Unit1.h : Declaration of the TDMConnectionImpl

#ifndef UDMConnectionImplH
#define UDMConnectionImplH

#define _ATL_APARTMENT_THREADED

#include "FibProvider_TLB.h"
#include "UDMConnection.h"
/////////////////////////////////////////////////////////////////////////////
// TDMConnectionImpl     Implements IDMConnection, default interface of DMConnection
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : FibProvider.DMConnection
// Description    : 
/////////////////////////////////////////////////////////////////////////////
//extern TDMConnection *DMConnection;

class ATL_NO_VTABLE TDMConnectionImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TDMConnectionImpl, &CLSID_DMConnectionImpl>,
  public IDispatchImpl<IDMConnectionImpl, &IID_IDMConnectionImpl, &LIBID_FibProvider>
{
public:
  TDMConnectionImpl()
  {
  DMConnection=new TDMConnection(Application);
  }

  ~TDMConnectionImpl()
  {
  delete DMConnection;
  }
  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("FibProvider.DMConnection");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TDMConnectionImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TDMConnectionImpl)
  COM_INTERFACE_ENTRY(IDMConnectionImpl)
  COM_INTERFACE_ENTRY2(IDispatch, IDMConnectionImpl)
END_COM_MAP()

// IDMConnection
public:


  STDMETHOD(ConnectBase(int* result));
  STDMETHOD(DisconnectBase());
  STDMETHOD(get_CharSet(BSTR* Value));
  STDMETHOD(get_ConnectString(BSTR* Value));
  STDMETHOD(get_RoleName(BSTR* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_UserName(BSTR* Value));
  STDMETHOD(get_UserName2(BSTR* Value));
  STDMETHOD(set_CharSet(BSTR Value));
  STDMETHOD(set_ConnectString(BSTR Value));
  STDMETHOD(set_Password(BSTR Value));
  STDMETHOD(set_RoleName(BSTR Value));
  STDMETHOD(set_UserName(BSTR Value));
  STDMETHOD(set_UserName2(BSTR Value));
  STDMETHOD(get_flError(int* Value));
  STDMETHOD(get_flConnected(int* Value));
};

#endif //Unit1H
