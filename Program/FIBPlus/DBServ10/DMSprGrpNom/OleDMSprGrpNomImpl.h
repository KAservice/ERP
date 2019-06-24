// OLEDMSPRGRPNOMIMPL.H : Declaration of the TOleDMSprGrpNomImpl

#ifndef OleDMSprGrpNomImplH
#define OleDMSprGrpNomImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprGrpNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprGrpNomImpl     Implements IOleDMSprGrpNom, default interface of OleDMSprGrpNom
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprGrpNom
// Description    : Справочник групп номенклатуры
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprGrpNomImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprGrpNomImpl, &CLSID_OleDMSprGrpNom>,
  public IDispatchImpl<IOleDMSprGrpNom, &IID_IOleDMSprGrpNom, &LIBID_DBServ10>
{
public:
  TOleDMSprGrpNomImpl()
  {
  DMSprGrpNom=new TDMSprGrpNom(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMSprGrpNomImpl()
  {
  delete DMSprGrpNom;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprGrpNom");
  DECLARE_DESCRIPTION("Справочник групп номенклатуры");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprGrpNomImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprGrpNomImpl)
  COM_INTERFACE_ENTRY(IOleDMSprGrpNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprGrpNom)
END_COM_MAP()

// IOleDMSprGrpNom
public:

  int CodeError;
  AnsiString TextError;
  TDMSprGrpNom * DMSprGrpNom;


  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_ElGID_SGRPNOM(BSTR* Value));
  STDMETHOD(get_ElIDGN(BSTR* Value));
  STDMETHOD(get_ElIDGRPGN(BSTR* Value));
  STDMETHOD(get_ElNAMEGN(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* Id));
  STDMETHOD(NewElement(BSTR IdGrp));
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(OpenTable());
  STDMETHOD(SaveElement());
  STDMETHOD(set_ElGID_SGRPNOM(BSTR Value));
  STDMETHOD(set_ElIDGN(BSTR Value));
  STDMETHOD(set_ElIDGRPGN(BSTR Value));
  STDMETHOD(set_ElNAMEGN(BSTR Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
};

#endif //OleDMSprGrpNomImplH
