 // 1.1
// Unit1.h : Declaration of the TOleDMImpl

#ifndef UOleDMH
#define UOleDMH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMImpl     Implements IOleDM, default interface of OleDM
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDM
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMImpl, &CLSID_OleDM>,
  public IDispatchImpl<IOleDM, &IID_IOleDM, &LIBID_DBServ20>
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
  DECLARE_PROGID("DBServ20.OleDM");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMImpl)
  COM_INTERFACE_ENTRY(IOleDM)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDM)
END_COM_MAP()

// IOleDM
public:
  TDM *DM;
  int CodeError;
  int ConnectOK;
  AnsiString TextError;

   
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_ConnectString(BSTR* Value));
  STDMETHOD(set_ConnectString(BSTR Value));
  STDMETHOD(get_NameUser(BSTR* Value));
  STDMETHOD(set_NameUser(BSTR Value));
  STDMETHOD(set_PasswordUser(BSTR Value));
  STDMETHOD(GlobConnect());
  STDMETHOD(get_ConnectOK(int* Value));
};

#endif //Unit1H
