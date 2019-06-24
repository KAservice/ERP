 // 1.1
// Unit1.h : Declaration of the TOleDMSprSkladImpl

#ifndef UOleDMSprSkladH
#define UOleDMSprSkladH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDMSprSklad.h"
#include "UDM.h"
/////////////////////////////////////////////////////////////////////////////
// TOleDMSprSkladImpl     Implements IOleDMSprSklad, default interface of OleDMSprSklad
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprSklad
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprSkladImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprSkladImpl, &CLSID_OleDMSprSklad>,
  public IDispatchImpl<IOleDMSprSklad, &IID_IOleDMSprSklad, &LIBID_DBServ20>
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
  DECLARE_PROGID("DBServ20.OleDMSprSklad");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprSkladImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprSkladImpl)
  COM_INTERFACE_ENTRY(IOleDMSprSklad)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprSklad)
END_COM_MAP()

// IOleDMSprSklad
public:
  TDMSprSklad *DMSprSklad;
  AnsiString TextError;
  int CodeError;

 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenTable());
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(NewElement());
  STDMETHOD(SaveElement());
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(DeleteElement(BSTR id));
  STDMETHOD(get_TableADRSKLAD(BSTR* Value));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(get_TableGID_SSKLAD(BSTR* Value));
  STDMETHOD(get_TableIDSKLAD(BSTR* Value));
  STDMETHOD(get_TableMOLSKLAD(BSTR* Value));
  STDMETHOD(get_TableNAMESKLAD(BSTR* Value));
  STDMETHOD(get_TableTSklad(int* Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_ElementADRSKLAD(BSTR* Value));
  STDMETHOD(get_ElementGID_SSKLAD(BSTR* Value));
  STDMETHOD(get_ElementIDSKLAD(BSTR* Value));
  STDMETHOD(get_ElementMOLSKLAD(BSTR* Value));
  STDMETHOD(get_ElementNAMESKLAD(BSTR* Value));
  STDMETHOD(get_ElementTSKLAD(int* Value));
  STDMETHOD(set_ElementADRSKLAD(BSTR Value));
  STDMETHOD(set_ElementGID_SSKLAD(BSTR Value));
  STDMETHOD(set_ElementIDSKLAD(BSTR Value));
  STDMETHOD(set_ElementMOLSKLAD(BSTR Value));
  STDMETHOD(set_ElementNAMESKLAD(BSTR Value));
  STDMETHOD(set_ElementTSKLAD(int Value));
};

#endif //Unit1H
