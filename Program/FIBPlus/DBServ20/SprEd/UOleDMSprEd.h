 // 1.1
// Unit1.h : Declaration of the TOleDMSprEdImpl

#ifndef UOleDMSprEdH
#define UOleDMSprEdH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMSprEd.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprEdImpl     Implements IOleDMSprEd, default interface of OleDMSprEd
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprEd
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprEdImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprEdImpl, &CLSID_OleDMSprEd>,
  public IDispatchImpl<IOleDMSprEd, &IID_IOleDMSprEd, &LIBID_DBServ20>
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
  DECLARE_PROGID("DBServ20.OleDMSprEd");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprEdImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprEdImpl)
  COM_INTERFACE_ENTRY(IOleDMSprEd)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprEd)
END_COM_MAP()

// IOleDMSprEd
public:

  TDMSprEd *DMSprEd;
  int CodeError;
  AnsiString TextError;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenTable(BSTR id_nom));
  STDMETHOD(NewElement(BSTR id_nom, int* result));
  STDMETHOD(SaveElement(int* result)); 
  STDMETHOD(FindEdPoSh(BSTR sh, BSTR* result));
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableCODE_SED(int* Value));
  STDMETHOD(get_TableGID_SED(BSTR* Value));
  STDMETHOD(get_TableIDED(BSTR* Value));
  STDMETHOD(get_TableIDNOMED(BSTR* Value));
  STDMETHOD(get_TableIDOKEIED(BSTR* Value));
  STDMETHOD(get_TableKFED(double* Value));
  STDMETHOD(get_TableNAMEED(BSTR* Value));
  STDMETHOD(get_TableSHED(BSTR* Value));
  STDMETHOD(get_TableTSHED(int* Value));
  STDMETHOD(get_ElementCODE_SED(int* Value));
  STDMETHOD(get_ElementGID_SED(BSTR* Value));
  STDMETHOD(get_ElementIDED(BSTR* Value));
  STDMETHOD(get_ElementIDOKEIED(BSTR* Value));
  STDMETHOD(get_ElementKFED(double* Value));
  STDMETHOD(get_ElementNAMEED(BSTR* Value));
  STDMETHOD(get_ElementNAMEOKEI(BSTR* Value));
  STDMETHOD(get_ElementSHED(BSTR* Value));
  STDMETHOD(get_ElementTSHED(int* Value));
  STDMETHOD(set_ElementCODE_SED(int Value));
  STDMETHOD(set_ElementGID_SED(BSTR Value));
  STDMETHOD(set_ElementIDED(BSTR Value));
  STDMETHOD(set_ElementIDOKEIED(BSTR Value));
  STDMETHOD(set_ElementKFED(double Value));
  STDMETHOD(set_ElementNAMEED(BSTR Value));
  STDMETHOD(set_ElementNAMEOKEI(BSTR Value));
  STDMETHOD(set_ElementSHED(BSTR Value));
  STDMETHOD(set_ElementTSHED(int Value));
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(DeleteElement(BSTR id, int* result));
};

#endif //Unit1H
