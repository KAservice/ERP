// OLEDMSPRINFBASEIMPL.H : Declaration of the TOleDMSprInfBaseImpl

#ifndef OleDMSprInfBaseImplH
#define OleDMSprInfBaseImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprInfBase.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprInfBaseImpl     Implements IOleDMSprInfBase, default interface of OleDMSprInfBase
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprInfBase
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprInfBaseImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprInfBaseImpl, &CLSID_OleDMSprInfBase>,
  public IDispatchImpl<IOleDMSprInfBase, &IID_IOleDMSprInfBase, &LIBID_DBServ10>
{
public:
  TOleDMSprInfBaseImpl()
  {
  DMSprInfBase=new TDMSprInfBase(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprInfBaseImpl()
  {
  delete DMSprInfBase;
  }

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprInfBase");
  DECLARE_DESCRIPTION("Справочник информационных баз");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprInfBaseImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprInfBaseImpl)
  COM_INTERFACE_ENTRY(IOleDMSprInfBase)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprInfBase)
END_COM_MAP()

// IOleDMSprInfBase
public:

        AnsiString  TextError;
        int CodeError;
        TDMSprInfBase *DMSprInfBase;
 
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksBase(BSTR* Value));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenTable());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(GetIdPoName(BSTR name, BSTR* id));
};

#endif //OleDMSprInfBaseImplH
