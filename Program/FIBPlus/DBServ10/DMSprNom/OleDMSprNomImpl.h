// OLEDMSPRNOMIMPL.H : Declaration of the TOleDMSprNomImpl

#ifndef OleDMSprNomImplH
#define OleDMSprNomImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprNomImpl     Implements IOleDMSprNom, default interface of OleDMSprNom
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprNom
// Description    : Справочник "Номенклатура"
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprNomImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprNomImpl, &CLSID_OleDMSprNom>,
  public IDispatchImpl<IOleDMSprNom, &IID_IOleDMSprNom, &LIBID_DBServ10>
{
public:
  TOleDMSprNomImpl()
  {
  DMSprNom=new TDMSprNom(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprNomImpl()
  {
  delete DMSprNom;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprNom");
  DECLARE_DESCRIPTION("Справочник \"Номенклатура\"");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprNomImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprNomImpl)
  COM_INTERFACE_ENTRY(IOleDMSprNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprNom)
END_COM_MAP()

// IOleDMSprNom
public:
 
  STDMETHOD(ChancheGrp(BSTR NewGrp));
  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(FindPoCodu(int Code));
  STDMETHOD(get_AllElement(int* Value));
  STDMETHOD(get_ArtNom(BSTR* Value));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_CodeNom(int* Value));
  STDMETHOD(get_FNameNom(BSTR* Value));
  STDMETHOD(get_GID_SNom(BSTR* Value));
  STDMETHOD(get_IdBasEdNom(BSTR* Value));
  STDMETHOD(get_IdGrpNom(BSTR* Value));
  STDMETHOD(get_IdNom(BSTR* Value));
  STDMETHOD(get_IdOsnEdNom(BSTR* Value));
  STDMETHOD(get_IdTypePrice(BSTR* Value));
  STDMETHOD(get_KrNameNom(BSTR* Value));
  STDMETHOD(get_NameNom(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_TNom(int* Value));
  STDMETHOD(GetGidElement(BSTR Id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* Id));
  STDMETHOD(NewElement(BSTR IdGrp));
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(OpenTable(BSTR Grp, int All));
  STDMETHOD(SaveElement());
  STDMETHOD(set_AllElement(int Value));
  STDMETHOD(set_ArtNom(BSTR Value));
  STDMETHOD(set_CodeNom(int Value));
  STDMETHOD(set_FNameNom(BSTR Value));
  STDMETHOD(set_GID_SNom(BSTR Value));
  STDMETHOD(set_IdBasEdNom(BSTR Value));
  STDMETHOD(set_IdGrpNom(BSTR Value));
  STDMETHOD(set_IdNom(BSTR Value));
  STDMETHOD(set_IdOsnEdNom(BSTR Value));
  STDMETHOD(set_IdTypePrice(BSTR Value));
  STDMETHOD(set_KrNameNom(BSTR Value));
  STDMETHOD(set_NameNom(BSTR Value));
  STDMETHOD(set_TNom(int Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());

  TDMSprNom *DMSprNom;
  int CodeError;
  AnsiString TextError;
};

#endif //OleDMSprNomImplH
