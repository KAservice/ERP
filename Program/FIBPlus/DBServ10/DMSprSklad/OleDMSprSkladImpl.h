// OLEDMSPRSKLADIMPL.H : Declaration of the TOleDMSprSkladImpl

#ifndef OleDMSprSkladImplH
#define OleDMSprSkladImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprSklad.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprSkladImpl     Implements IOleDMSprSklad, default interface of OleDMSprSklad
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprSklad
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprSkladImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprSkladImpl, &CLSID_OleDMSprSklad>,
  public IDispatchImpl<IOleDMSprSklad, &IID_IOleDMSprSklad, &LIBID_DBServ10>
{
public:
  TOleDMSprSkladImpl()
  {
  DMSprSklad=new TDMSprSklad(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprSkladImpl()
  {
  delete DMSprSklad;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprSklad");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprSkladImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprSkladImpl)
  COM_INTERFACE_ENTRY(IOleDMSprSklad)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprSklad)
END_COM_MAP()

// IOleDMSprSklad
public:
 
  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(get_AdrSklad(BSTR* Value));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_GID_Sklad(BSTR* Value));
  STDMETHOD(get_IdSklad(BSTR* Value));
  STDMETHOD(get_MolSklad(BSTR* Value));
  STDMETHOD(get_NameSklad(BSTR* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_TSklad(int* Value));
  STDMETHOD(GetGidElement(BSTR Id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* Id));
  STDMETHOD(NewElement());
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(SaveElement());
  STDMETHOD(set_AdrSklad(BSTR Value));
  STDMETHOD(set_GID_Sklad(BSTR Value));
  STDMETHOD(set_IdSklad(BSTR Value));
  STDMETHOD(set_MolSklad(BSTR Value));
  STDMETHOD(set_NameSklad(BSTR Value));
  STDMETHOD(set_TSklad(int Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(CloseElement());
  TDMSprSklad * DMSprSklad;
  int CodeError;
  AnsiString TextError;
};

#endif //OleDMSprSkladImplH
