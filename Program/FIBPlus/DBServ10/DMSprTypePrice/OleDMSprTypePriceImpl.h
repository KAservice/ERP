// OLEDMSPRTYPEPRICEIMPL.H : Declaration of the TOleDMSprTypePriceImpl

#ifndef OleDMSprTypePriceImplH
#define OleDMSprTypePriceImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMSprTypePrice.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprTypePriceImpl     Implements IOleDMSprTypePrice, default interface of OleDMSprTypePrice
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMSprTypePrice
// Description    : Справочник типов цен
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprTypePriceImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprTypePriceImpl, &CLSID_OleDMSprTypePrice>,
  public IDispatchImpl<IOleDMSprTypePrice, &IID_IOleDMSprTypePrice, &LIBID_DBServ10>
{
public:
  TOleDMSprTypePriceImpl()
  {
  DMSprTypePrice =new TDMSprTypePrice(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMSprTypePriceImpl()
  {
  delete DMSprTypePrice;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMSprTypePrice");
  DECLARE_DESCRIPTION("Справочник типов цен");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprTypePriceImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMSprTypePriceImpl)
  COM_INTERFACE_ENTRY(IOleDMSprTypePrice)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprTypePrice)
END_COM_MAP()

// IOleDMSprTypePrice
public:

        AnsiString TextError;
        int CodeError;
        TDMSprTypePrice *  DMSprTypePrice;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_ElGID_STPRICE(BSTR* Value));
  STDMETHOD(get_ElID_TPRICE(BSTR* Value));
  STDMETHOD(get_ElNAME_TPRICE(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenTable());
  STDMETHOD(set_ElGID_STPRICE(BSTR Value));
  STDMETHOD(set_ElID_TPRICE(BSTR Value));
  STDMETHOD(set_ElNAME_TPRICE(BSTR Value));
  STDMETHOD(DeleteElement(BSTR Id));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* Id));
  STDMETHOD(GetIDTypePrice(BSTR name, BSTR* Id));
  STDMETHOD(NewElement());
  STDMETHOD(OpenElement(BSTR Id));
  STDMETHOD(SaveElement());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(CloseElement());
};

#endif //OleDMSprTypePriceImplH
