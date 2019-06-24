// OLEDMDOCPERIMPL.H : Declaration of the TOleDMDocPerImpl

#ifndef OleDMDocPerImplH
#define OleDMDocPerImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocPer.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocPerImpl     Implements IOleDMDocPer, default interface of OleDMDocPer
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocPer
// Description    : Документ перемещение
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocPerImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocPerImpl, &CLSID_OleDMDocPer>,
  public IDispatchImpl<IOleDMDocPer, &IID_IOleDMDocPer, &LIBID_DBServ10>
{
public:
  TOleDMDocPerImpl()
  {
  doc=new TDMDocPer(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMDocPerImpl()
  {
  delete doc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocPer");
  DECLARE_DESCRIPTION("Документ перемещение");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocPerImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocPerImpl)
  COM_INTERFACE_ENTRY(IOleDMDocPer)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocPer)
END_COM_MAP()

// IOleDMDocPer
public:

AnsiString TextError;
int CodeError;
TDMDocPer *doc;
 
  STDMETHOD(AddDocNewString());
  STDMETHOD(CancelDvRegDoc());
  STDMETHOD(CloseDoc());
  STDMETHOD(DeleteDoc(BSTR Id));
  STDMETHOD(DeleteStringDoc());
  STDMETHOD(DvRegDoc());
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_DocAllFNAMEUSER(BSTR* Value));
  STDMETHOD(get_DocAllGID_DOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDSKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDUSERDOC(BSTR* Value));
  STDMETHOD(get_DocAllNUMDOC(int* Value));
  STDMETHOD(get_DocAllPOSDOC(BSTR* Value));
  STDMETHOD(get_DocAllPRDOC(int* Value));
  STDMETHOD(get_DocAllSUMDOC(double* Value));
  STDMETHOD(get_DocAllTDOC(BSTR* Value));
  STDMETHOD(get_DocGID_DPER(BSTR* Value));
  STDMETHOD(get_DocIDDOCPER(BSTR* Value));
  STDMETHOD(get_DocIDPER(BSTR* Value));
  STDMETHOD(get_DocIDSKLPOLPER(BSTR* Value));
  STDMETHOD(get_DocPRIMPER(BSTR* Value));
  STDMETHOD(get_DocTGID_DPERT(BSTR* Value));
  STDMETHOD(get_DocTIDDOCPERT(BSTR* Value));
  STDMETHOD(get_DocTIDEDPERT(BSTR* Value));
  STDMETHOD(get_DocTIDNOMPERT(BSTR* Value));
  STDMETHOD(get_DocTIDPERT(BSTR* Value));
  STDMETHOD(get_DocTKFPERT(double* Value));
  STDMETHOD(get_DocTKOLPERT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_DocTPRICEPERT(double* Value));
  STDMETHOD(get_DocTSUMPERT(double* Value));
  STDMETHOD(get_DocTTNOM(int* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(GetIdDocPoNomeruDoc(int number_doc, BSTR date_doc, BSTR* IdDoc));
  STDMETHOD(NewDoc());
  STDMETHOD(OpenDoc(BSTR IdDoc));
  STDMETHOD(SaveDoc());
  STDMETHOD(set_DocAllGID_DOC(BSTR Value));
  STDMETHOD(set_DocAllIDDOC(BSTR Value));
  STDMETHOD(set_DocAllIDFIRMDOC(BSTR Value));
  STDMETHOD(set_DocAllIDKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDSKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDUSERDOC(BSTR Value));
  STDMETHOD(set_DocAllNUMDOC(int Value));
  STDMETHOD(set_DocAllPOSDOC(BSTR Value));
  STDMETHOD(set_DocAllPRDOC(int Value));
  STDMETHOD(set_DocAllSUMDOC(double Value));
  STDMETHOD(set_DocAllTDOC(BSTR Value));
  STDMETHOD(set_DocGID_DPER(BSTR Value));
  STDMETHOD(set_DocIDDOCPER(BSTR Value));
  STDMETHOD(set_DocIDPER(BSTR Value));
  STDMETHOD(set_DocIDSKLPOLPER(BSTR Value));
  STDMETHOD(set_DocPRIMPER(BSTR Value));
  STDMETHOD(set_DocTGID_DPERT(BSTR Value));
  STDMETHOD(set_DocTIDDOCPERT(BSTR Value));
  STDMETHOD(set_DocTIDEDPERT(BSTR Value));
  STDMETHOD(set_DocTIDNOMPERT(BSTR Value));
  
  STDMETHOD(set_DocTIDPERT(BSTR Value));
  STDMETHOD(set_DocTKFPERT(double Value));
  STDMETHOD(set_DocTKOLPERT(double Value));
  STDMETHOD(set_DocTPRICEPERT(double Value));
  STDMETHOD(set_DocTSUMPERT(double Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocPerImplH
