// OLEDMSPRPRICEIMPL.H : Declaration of the TOleDMSprPriceImpl

#ifndef OleDMSprPriceImplH
#define OleDMSprPriceImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprPrice.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprPriceImpl     Implements IOleDMSprPrice, default interface of OleDMSprPrice
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprPrice
// Description    : Справочник цен номенклатуры
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprPriceImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprPriceImpl, &CLSID_OleDMSprPrice>,
  public IDispatchImpl<IOleDMSprPrice, &IID_IOleDMSprPrice, &LIBID_DBServ10>
{
public:
  TOleDMSprPriceImpl()
  {
  DMSprPrice=new TDMSprPrice(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMSprPriceImpl()
  {
  delete DMSprPrice;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprPrice");
  DECLARE_DESCRIPTION("Справочник цен номенклатуры");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprPriceImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprPriceImpl)
  COM_INTERFACE_ENTRY(IOleDMSprPrice)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprPrice)
END_COM_MAP()

// IOleDMSprPrice
public:
        AnsiString  TextError;
        int CodeError;
        TDMSprPrice *DMSprPrice;



  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(FindElement(BSTR IdTypePrice, BSTR IdNom, int* kol_record));
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_ElGID_SPRICE(BSTR* Value));
  STDMETHOD(get_ElID_PRICE(BSTR* Value));
  STDMETHOD(get_ElIDNOM_PRICE(BSTR* Value));
  STDMETHOD(get_ElIDTYPE_PRICE(BSTR* Value));
  STDMETHOD(get_ElZNACH_PRICE(double* Value));
  STDMETHOD(get_IdNom(BSTR* Value));
  STDMETHOD(get_IdTypePrice(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewElement());
  STDMETHOD(OpenTable(BSTR IdNom));
  STDMETHOD(SaveElement());
  STDMETHOD(set_ElGID_SPRICE(BSTR Value));
  STDMETHOD(set_ElID_PRICE(BSTR Value));
  STDMETHOD(set_ElIDNOM_PRICE(BSTR Value));
  STDMETHOD(set_ElIDTYPE_PRICE(BSTR Value));
  STDMETHOD(set_ElZNACH_PRICE(double Value));
  STDMETHOD(set_IdNom(BSTR Value));
  STDMETHOD(set_IdTypePrice(BSTR Value));
};

#endif //OleDMSprPriceImplH
