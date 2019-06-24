 // 1.1
// Unit1.h : Declaration of the TOleDMDocRealImpl

#ifndef UOleDMDocRealH
#define UOleDMDocRealH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMDocReal.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocRealImpl     Implements IOleDMDocReal, default interface of OleDMDocReal
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMDocReal
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocRealImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocRealImpl, &CLSID_OleDMDocReal>,
  public IDispatchImpl<IOleDMDocReal, &IID_IOleDMDocReal, &LIBID_DBServ20>
{
public:
  TOleDMDocRealImpl()
  {
  Doc=new TDMDocReal(Application);
  CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMDocRealImpl()
  {
  delete Doc;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMDocReal");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocRealImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMDocRealImpl)
  COM_INTERFACE_ENTRY(IOleDMDocReal)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocReal)
END_COM_MAP()

// IOleDMDocReal
public:
  TDMDocReal * Doc;
  int CodeError;
  AnsiString TextError;

  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewDoc());
  STDMETHOD(OpenDoc(BSTR id));
  STDMETHOD(SaveDoc(int* result));
  STDMETHOD(CloseDoc());
  STDMETHOD(DeleteDoc(BSTR id, int* result));
  STDMETHOD(DocTFirst());
  STDMETHOD(DocTNext());
  STDMETHOD(get_DocTEof(int* Value));
  STDMETHOD(GetIdDoc(int number_doc, BSTR date_doc, BSTR* id));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDSKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllNUMDOC(int* Value));
  STDMETHOD(get_DocAllPOSDOC(BSTR* Value));
  STDMETHOD(get_DocAllSUMDOC(double* Value));
  STDMETHOD(get_DocAllTDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDFIRMDOC(BSTR Value));
  STDMETHOD(set_DocAllIDKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDSKLDOC(BSTR Value));
  STDMETHOD(set_DocAllNUMDOC(int Value));
  STDMETHOD(set_DocAllPOSDOC(BSTR Value));
  STDMETHOD(set_DocAllSUMDOC(double Value));
  STDMETHOD(set_DocAllTDOC(BSTR Value));
  STDMETHOD(get_DocIDBSCHETREA(BSTR* Value));
  STDMETHOD(get_DocIDDOCREA(BSTR* Value));
  STDMETHOD(get_DocIDGRPOLREA(BSTR* Value));
  STDMETHOD(get_DocIDREA(BSTR* Value));
  STDMETHOD(get_DocIDTPRICEREA(BSTR* Value));
  STDMETHOD(get_DocPRIMREA(BSTR* Value));
  STDMETHOD(set_DocIDBSCHETREA(BSTR Value));
  STDMETHOD(set_DocIDDOCREA(BSTR Value));
  STDMETHOD(set_DocIDGRPOLREA(BSTR Value));
  STDMETHOD(set_DocIDREA(BSTR Value));
  STDMETHOD(set_DocIDTPRICEREA(BSTR Value));
  STDMETHOD(set_DocPRIMREA(BSTR Value));
  STDMETHOD(get_DocTIDDOCREAT(BSTR* Value));
  STDMETHOD(get_DocTIDEDREAT(BSTR* Value));
  STDMETHOD(get_DocTIDNOMREAT(BSTR* Value));
  STDMETHOD(get_DocTIDREAT(BSTR* Value));
  STDMETHOD(get_DocTKFREAT(double* Value));
  STDMETHOD(get_DocTKOLREAT(double* Value));
  STDMETHOD(get_DocTPRICEREAT(double* Value));
  STDMETHOD(get_DocTSUMREAT(double* Value));
  STDMETHOD(set_DocTIDDOCREAT(BSTR Value));
  STDMETHOD(set_DocTIDEDREAT(BSTR Value));
  STDMETHOD(set_DocTIDNOMREAT(BSTR Value));
  STDMETHOD(set_DocTIDREAT(BSTR Value));
  STDMETHOD(set_DocTKFREAT(double Value));
  STDMETHOD(set_DocTKOLREAT(double Value));
  STDMETHOD(set_DocTPRICEREAT(double Value));
  STDMETHOD(set_DocTSUMREAT(double Value));
  STDMETHOD(DocTAppend());
  STDMETHOD(DocTDelete());
};

#endif //Unit1H
