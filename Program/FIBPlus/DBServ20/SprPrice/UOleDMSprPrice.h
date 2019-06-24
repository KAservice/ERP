 // 1.1
// Unit1.h : Declaration of the TOleDMSprPriceImpl

#ifndef UOleDMSprPriceH
#define UOleDMSprPriceH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMSprPrice.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprPriceImpl     Implements IOleDMSprPrice, default interface of OleDMSprPrice
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprPrice
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprPriceImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprPriceImpl, &CLSID_OleDMSprPrice>,
  public IDispatchImpl<IOleDMSprPrice, &IID_IOleDMSprPrice, &LIBID_DBServ20>
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
  DECLARE_PROGID("DBServ20.OleDMSprPrice");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprPriceImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprPriceImpl)
  COM_INTERFACE_ENTRY(IOleDMSprPrice)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprPrice)
END_COM_MAP()

// IOleDMSprPrice
public:
  TDMSprPrice *DMSprPrice;
  int CodeError;
  AnsiString TextError;

 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewElement(BSTR id_nom, BSTR id_type_price));
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(DeleteElement(BSTR id));
  STDMETHOD(OpenTable(BSTR id_nom));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableGID_SPRICE(BSTR* Value));
  STDMETHOD(get_TableID_PRICE(BSTR* Value));
  STDMETHOD(get_TableIDNOM_PRICE(BSTR* Value));
  STDMETHOD(get_TableIDTYPE_PRICE(BSTR* Value));
  STDMETHOD(get_TableNAME_TPRICE(BSTR* Value));
  STDMETHOD(get_ElementGID_SPRICE(BSTR* Value));
  STDMETHOD(get_ElementID_PRICE(BSTR* Value));
  STDMETHOD(get_ElementIDNOM_PRICE(BSTR* Value));
  STDMETHOD(get_ElementIDTYPE_PRICE(BSTR* Value));
  STDMETHOD(get_ElementZNACH_PRICE(double* Value));
  STDMETHOD(set_ElementGID_SPRICE(BSTR Value));
  STDMETHOD(set_ElementID_PRICE(BSTR Value));
  STDMETHOD(set_ElementIDNOM_PRICE(BSTR Value));
  STDMETHOD(set_ElementIDTYPE_PRICE(BSTR Value));
  STDMETHOD(set_ElementZNACH_PRICE(double Value));
  STDMETHOD(FindElement(BSTR id_type_price, BSTR id_nom, BSTR * result));
  STDMETHOD(get_TableZNACH_PRICE(double* Value));
};

#endif //Unit1H
