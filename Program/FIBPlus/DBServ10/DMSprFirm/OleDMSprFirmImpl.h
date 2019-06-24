// OLEDMSPRFIRMIMPL.H : Declaration of the TOleDMSprFirmImpl

#ifndef OleDMSprFirmImplH
#define OleDMSprFirmImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprFirm.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprFirmImpl     Implements IOleDMSprFirm, default interface of OleDMSprFirm
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprFirm
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprFirmImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprFirmImpl, &CLSID_OleDMSprFirm>,
  public IDispatchImpl<IOleDMSprFirm, &IID_IOleDMSprFirm, &LIBID_DBServ10>
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
  DECLARE_PROGID("DBServ10.OleDMSprFirm");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprFirmImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprFirmImpl)
  COM_INTERFACE_ENTRY(IOleDMSprFirm)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprFirm)
END_COM_MAP()

// IOleDMSprFirm
public:


TDMSprFirm *DMSprFirm;
  int CodeError;
  AnsiString TextError;
 
  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(ElementEdit());
  STDMETHOD(ElementPost());
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_FNameNom(BSTR* Value));
  STDMETHOD(get_GID_Firm(BSTR* Value));
  STDMETHOD(get_IdFirm(BSTR* Value));
  STDMETHOD(get_INNFirm(BSTR* Value));
  STDMETHOD(get_KPPFirm(BSTR* Value));
  STDMETHOD(get_NameFirm(BSTR* Value));
  STDMETHOD(get_PAdrFirm(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_UAdrFirm(BSTR* Value));
  STDMETHOD(GetGidElement(BSTR Id, BSTR* gid));
  STDMETHOD(NewElement());
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(OpenTable());
  STDMETHOD(SaveElement());
  STDMETHOD(set_FNameNom(BSTR Value));
  STDMETHOD(set_GID_Firm(BSTR Value));
  STDMETHOD(set_IdFirm(BSTR Value));
  STDMETHOD(set_INNFirm(BSTR Value));
  STDMETHOD(set_KPPFirm(BSTR Value));
  STDMETHOD(set_NameFirm(BSTR Value));
  STDMETHOD(set_PAdrFirm(BSTR Value));
  STDMETHOD(set_UAdrFirm(BSTR Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
};

#endif //OleDMSprFirmImplH
