// OLEDMIMPL.H : Declaration of the TOleDMImpl

#ifndef OleDMImplH
#define OleDMImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMImpl     Implements IOleDM, default interface of OleDM
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDM
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMImpl, &CLSID_OleDM>,
  public IDispatchImpl<IOleDM, &IID_IOleDM, &LIBID_DBServ10>
{
public:
  TOleDMImpl()
  {
  DM=new TDM(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMImpl()
  {
  delete DM;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDM");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMImpl)
  COM_INTERFACE_ENTRY(IOleDM)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDM)
END_COM_MAP()

// IOleDM
public:
 
  STDMETHOD(get_ConnectString(BSTR* Value));
  STDMETHOD(get_NameUser(BSTR* Value));
  STDMETHOD(get_PasswordUser(BSTR* Value));
  STDMETHOD(GlobConnect());
  STDMETHOD(set_ConnectString(BSTR Value));
  STDMETHOD(set_NameUser(BSTR Value));
  STDMETHOD(set_PasswordUser(BSTR Value));

  STDMETHOD(get_ConnectOK(int* Value));
  STDMETHOD(get_OleCodeError(int* Value));
  STDMETHOD(get_OleTextError(BSTR* Value));
  TDM *DM;
  int CodeError;
  int ConnectOK;
  AnsiString TextError;
};

#endif //OleDMImplH
