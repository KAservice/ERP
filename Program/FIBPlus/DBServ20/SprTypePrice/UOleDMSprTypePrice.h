 // 1.1
// Unit1.h : Declaration of the TOleDMSprTypePriceImpl

#ifndef UOleDMSprTypePriceH
#define UOleDMSprTypePriceH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMSprTypePrice.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprTypePriceImpl     Implements IOleDMSprTypePrice, default interface of OleDMSprTypePrice
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprTypePrice
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprTypePriceImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprTypePriceImpl, &CLSID_OleDMSprTypePrice>,
  public IDispatchImpl<IOleDMSprTypePrice, &IID_IOleDMSprTypePrice, &LIBID_DBServ20>
{
public:
  TOleDMSprTypePriceImpl()
  {
  DMSprTypePrice=new TDMSprTypePrice(Application);
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
  DECLARE_PROGID("DBServ20.OleDMSprTypePrice");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprTypePriceImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprTypePriceImpl)
  COM_INTERFACE_ENTRY(IOleDMSprTypePrice)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprTypePrice)
END_COM_MAP()

// IOleDMSprTypePrice
public:
  TDMSprTypePrice *DMSprTypePrice;
  int CodeError;
  AnsiString TextError; 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewElement());
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(DeleteElement(BSTR id));
  STDMETHOD(OpenTable());
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableGID_STPRICE(BSTR* Value));
  STDMETHOD(get_TableID_TPRICE(BSTR* Value));
  STDMETHOD(get_TableNAME_TPRICE(BSTR* Value));
  STDMETHOD(get_ElementGID_STPRICE(BSTR* Value));
  STDMETHOD(get_ElementID_TPRICE(BSTR* Value));
  STDMETHOD(get_ElementNAME_TPRICE(BSTR* Value));
  STDMETHOD(set_ElementGID_STPRICE(BSTR Value));
  STDMETHOD(set_ElementID_TPRICE(BSTR Value));
  STDMETHOD(set_ElementNAME_TPRICE(BSTR Value));
};

#endif //Unit1H
