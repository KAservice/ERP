// OLEDMGURALLDOCIMPL.H : Declaration of the TOleDMGurAllDocImpl

#ifndef OleDMGurAllDocImplH
#define OleDMGurAllDocImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMGurAllDoc.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMGurAllDocImpl     Implements IOleDMGurAllDoc, default interface of OleDMGurAllDoc
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMGurAllDoc
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMGurAllDocImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMGurAllDocImpl, &CLSID_OleDMGurAllDoc>,
  public IDispatchImpl<IOleDMGurAllDoc, &IID_IOleDMGurAllDoc, &LIBID_DBServ10>
{
public:
  TOleDMGurAllDocImpl()
  {
  DMGurAllDoc=new TDMGurAllDoc(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMGurAllDocImpl()
  {
  delete DMGurAllDoc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMGurAllDoc");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMGurAllDocImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMGurAllDocImpl)
  COM_INTERFACE_ENTRY(IOleDMGurAllDoc)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMGurAllDoc)
END_COM_MAP()

// IOleDMGurAllDoc
public:
 
  STDMETHOD(FindDocPoIdDog(int iddogovor));
  STDMETHOD(get_IdDoc(BSTR* Value));
  STDMETHOD(get_IdFirmDoc(BSTR* Value));
  STDMETHOD(get_IdKlDoc(BSTR* Value));
  STDMETHOD(get_IdSklDoc(BSTR* Value));
  STDMETHOD(get_IdUserDoc(BSTR* Value));
  STDMETHOD(get_NameFirm(BSTR* Value));
  STDMETHOD(get_NameKlient(BSTR* Value));
  STDMETHOD(get_NameSklad(BSTR* Value));
  STDMETHOD(get_NameUser(BSTR* Value));
  STDMETHOD(get_NumDoc(int* Value));
  STDMETHOD(get_PosDoc(BSTR* Value));
  STDMETHOD(get_PrDoc(int* Value));
  STDMETHOD(get_SumDoc(double* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TDoc(BSTR* Value));
  STDMETHOD(OpenTable());
  STDMETHOD(set_IdDoc(BSTR Value));
  STDMETHOD(set_IdFirmDoc(BSTR Value));
  STDMETHOD(set_IdKlDoc(BSTR Value));
  STDMETHOD(set_IdSklDoc(BSTR Value));
  STDMETHOD(set_IdUserDoc(BSTR Value));
  STDMETHOD(set_NameFirm(BSTR Value));
  STDMETHOD(set_NameKlient(BSTR Value));
  STDMETHOD(set_NameSklad(BSTR Value));
  STDMETHOD(set_NameUser(BSTR Value));
  STDMETHOD(set_NumDoc(int Value));
  STDMETHOD(set_PosDoc(BSTR Value));
  STDMETHOD(set_PrDoc(int Value));
  STDMETHOD(set_SumDoc(double Value));
  STDMETHOD(set_TDoc(BSTR Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(UpdateTable());


  STDMETHOD(get_OtborVkl(int* Value));
  STDMETHOD(get_PosCon(BSTR* Value));
  STDMETHOD(get_PosNach(BSTR* Value));
  STDMETHOD(get_StringTypeDoc(BSTR* Value));
  STDMETHOD(set_OtborVkl(int Value));
  STDMETHOD(set_PosCon(BSTR Value));
  STDMETHOD(set_PosNach(BSTR Value));
  STDMETHOD(set_StringTypeDoc(BSTR Value));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  TDMGurAllDoc *DMGurAllDoc;
  AnsiString TextError;
  int CodeError;
};

#endif //OleDMGurAllDocImplH
