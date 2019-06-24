// OLEDMSPREDIMPL.H : Declaration of the TOleDMSprEdImpl

#ifndef OleDMSprEdImplH
#define OleDMSprEdImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprEd.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprEdImpl     Implements IOleDMSprEd, default interface of OleDMSprEd
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprEd
// Description    : Справочник "Единицы номенклатуры"
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprEdImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprEdImpl, &CLSID_OleDMSprEd>,
  public IDispatchImpl<IOleDMSprEd, &IID_IOleDMSprEd, &LIBID_DBServ10>
{
public:
  TOleDMSprEdImpl()
  {
  DMSprEd=new TDMSprEd(Application);
  CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprEdImpl()
  {
  delete DMSprEd;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprEd");
  DECLARE_DESCRIPTION("Справочник \"Единицы номенклатуры\"");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprEdImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprEdImpl)
  COM_INTERFACE_ENTRY(IOleDMSprEd)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprEd)
END_COM_MAP()

// IOleDMSprEd
public:

        int CodeError;
        AnsiString TextError;
        TDMSprEd *DMSprEd;
  STDMETHOD(get_GID_SEd(BSTR* Value));
  STDMETHOD(get_IdEd(BSTR* Value));
  STDMETHOD(get_IdNomEd(BSTR* Value));
  STDMETHOD(get_IdOKEIEd(BSTR* Value));
  STDMETHOD(get_KFEd(double* Value));
  STDMETHOD(get_NameEd(BSTR* Value));
  STDMETHOD(get_NeIspEd(int* Value));
  STDMETHOD(get_ShEd(BSTR* Value));
  STDMETHOD(get_TShEd(int* Value));
  STDMETHOD(set_GID_SEd(BSTR Value));
  STDMETHOD(set_IdEd(BSTR Value));
  STDMETHOD(set_IdNomEd(BSTR Value));
  STDMETHOD(set_IdOKEIEd(BSTR Value));
  STDMETHOD(set_KFEd(double Value));
  STDMETHOD(set_NameEd(BSTR Value));
  STDMETHOD(set_NeIspEd(int Value));
  STDMETHOD(set_ShEd(BSTR Value));
  STDMETHOD(set_TShEd(int Value));
  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(FindEdPoSh(BSTR ShtrihCod));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(GetGidElement(BSTR Id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* Id));
  STDMETHOD(NewElement(BSTR IdNom));
  STDMETHOD(NewShtrihCod());
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(OpenTable(BSTR IdNom));
  STDMETHOD(SaveElement());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
};

#endif //OleDMSprEdImplH
