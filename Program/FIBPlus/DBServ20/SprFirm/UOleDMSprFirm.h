 // 1.1
// Unit1.h : Declaration of the TOleDMSprFirmImpl

#ifndef UOleDMSprFirmH
#define UOleDMSprFirmH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDMSprFirm.h"
#include "UDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprFirmImpl     Implements IOleDMSprFirm, default interface of OleDMSprFirm
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprFirm
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprFirmImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprFirmImpl, &CLSID_OleDMSprFirm>,
  public IDispatchImpl<IOleDMSprFirm, &IID_IOleDMSprFirm, &LIBID_DBServ20>
{
public:
  TOleDMSprFirmImpl()
  {
  DMSprFirm=new TDMSprFirm(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprFirmImpl()
  {
  delete DMSprFirm;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMSprFirm");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprFirmImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprFirmImpl)
  COM_INTERFACE_ENTRY(IOleDMSprFirm)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprFirm)
END_COM_MAP()

// IOleDMSprFirm
public:

  TDMSprFirm *DMSprFirm;
  int CodeError;
  AnsiString TextError;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenTable());
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(NewElement());
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(DeleteElement(BSTR id));
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(get_TableIDFIRM(BSTR* Value));
  STDMETHOD(get_TableINNFIRM(BSTR* Value));
  STDMETHOD(get_TableNAMEFIRM(BSTR* Value));
  STDMETHOD(get_ElementIDFIRM(BSTR* Value));
  STDMETHOD(get_ElementINNFIRM(BSTR* Value));
  STDMETHOD(get_ElementNAMEFIRM(BSTR* Value));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(set_ElementIDFIRM(BSTR Value));
  STDMETHOD(set_ElementINNFIRM(BSTR Value));
  STDMETHOD(set_ElementNAMEFIRM(BSTR Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_ElementGID_SFIRM(BSTR* Value));
  STDMETHOD(get_TableGID_SFIRM(BSTR* Value));
  STDMETHOD(set_ElementGID_SFIRM(BSTR Value));
};

#endif //Unit1H
