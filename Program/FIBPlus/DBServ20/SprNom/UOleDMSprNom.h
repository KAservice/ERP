 // 1.1
// Unit1.h : Declaration of the TOleDMSprNomImpl

#ifndef UOleDMSprNomH
#define UOleDMSprNomH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDMSprNom.h"
#include "UDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprNomImpl     Implements IOleDMSprNom, default interface of OleDMSprNom
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprNom
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprNomImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprNomImpl, &CLSID_OleDMSprNom>,
  public IDispatchImpl<IOleDMSprNom, &IID_IOleDMSprNom, &LIBID_DBServ20>
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
  DECLARE_PROGID("DBServ20.OleDMSprNom");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprNomImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprNomImpl)
  COM_INTERFACE_ENTRY(IOleDMSprNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprNom)
END_COM_MAP()

// IOleDMSprNom
public:
  TDMSprNom *DMSprNom;
  int CodeError;
  AnsiString TextError;

 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewElement(BSTR id_grp, int* result));
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(DeleteElement(BSTR id, int* result));
  STDMETHOD(OpenTable(BSTR id_grp, int all));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableCODENOM(int* Value));
  STDMETHOD(get_TableIDGRPNOM(BSTR* Value));
  STDMETHOD(get_TableIDNOM(BSTR* Value));
  STDMETHOD(get_TableNAMEED(BSTR* Value));
  STDMETHOD(get_TableNAMENOM(BSTR* Value));
  STDMETHOD(get_TableTNOM(int* Value));
  STDMETHOD(get_ElementARTNOM(BSTR* Value));
  STDMETHOD(get_ElementCODENOM(int* Value));
  STDMETHOD(get_ElementFNAMENOM(BSTR* Value));
  STDMETHOD(get_ElementGID_SNOM(BSTR* Value));
  STDMETHOD(get_ElementIDBASEDNOM(BSTR* Value));
  STDMETHOD(get_ElementIDCOUNTRYNOM(BSTR* Value));
  STDMETHOD(get_ElementIDFIRMNOM(BSTR* Value));
  STDMETHOD(get_ElementIDGRPNOM(BSTR* Value));
  STDMETHOD(get_ElementIDNOM(BSTR* Value));
  STDMETHOD(get_ElementIDOSNEDNOM(BSTR* Value));
  STDMETHOD(get_ElementIDVID_SNOM(BSTR* Value));
  STDMETHOD(get_ElementKRNAMENOM(BSTR* Value));
  STDMETHOD(get_ElementNAMENOM(BSTR* Value));
  STDMETHOD(get_ElementSTNDSNOM(double* Value));
  STDMETHOD(get_ElementTNOM(int* Value));
  STDMETHOD(set_ElementARTNOM(BSTR Value));
  STDMETHOD(set_ElementCODENOM(int Value));
  STDMETHOD(set_ElementFNAMENOM(BSTR Value));
  STDMETHOD(set_ElementGID_SNOM(BSTR Value));
  STDMETHOD(set_ElementIDBASEDNOM(BSTR Value));
  STDMETHOD(set_ElementIDCOUNTRYNOM(BSTR Value));
  STDMETHOD(set_ElementIDFIRMNOM(BSTR Value));
  STDMETHOD(set_ElementIDGRPNOM(BSTR Value));
  STDMETHOD(set_ElementIDNOM(BSTR Value));
  STDMETHOD(set_ElementIDOSNEDNOM(BSTR Value));
  STDMETHOD(set_ElementIDVID_SNOM(BSTR Value));
  STDMETHOD(set_ElementKRNAMENOM(BSTR Value));
  STDMETHOD(set_ElementNAMENOM(BSTR Value));
  STDMETHOD(set_ElementSTNDSNOM(double Value));
  STDMETHOD(set_ElementTNOM(int Value));
};

#endif //Unit1H
