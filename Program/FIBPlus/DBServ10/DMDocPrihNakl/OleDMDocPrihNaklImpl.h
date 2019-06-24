// OLEDMDOCPRIHNAKLIMPL.H : Declaration of the TOleDMDocPrihNaklImpl

#ifndef OleDMDocPrihNaklImplH
#define OleDMDocPrihNaklImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocPrihNakl.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocPrihNaklImpl     Implements IOleDMDocPrihNakl, default interface of OleDMDocPrihNakl
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocPrihNakl
// Description    : Документ Приходная накладная
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocPrihNaklImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocPrihNaklImpl, &CLSID_OleDMDocPrihNakl>,
  public IDispatchImpl<IOleDMDocPrihNakl, &IID_IOleDMDocPrihNakl, &LIBID_DBServ10>
{
public:
  TOleDMDocPrihNaklImpl()
  {
  doc=new TDMDocPrihNakl(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  
  ~TOleDMDocPrihNaklImpl()
  {
  delete doc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocPrihNakl");
  DECLARE_DESCRIPTION("Документ Приходная накладная");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocPrihNaklImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocPrihNaklImpl)
  COM_INTERFACE_ENTRY(IOleDMDocPrihNakl)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocPrihNakl)
END_COM_MAP()

// IOleDMDocPrihNakl
public:

TDMDocPrihNakl * doc;
AnsiString TextError;
int CodeError;
 
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
  STDMETHOD(get_DocGID_DPRN(BSTR* Value));
  STDMETHOD(get_DocIDDOCPRN(BSTR* Value));
  STDMETHOD(get_DocIDPRN(BSTR* Value));
  STDMETHOD(get_DocIDTPRICE(BSTR* Value));
  STDMETHOD(get_DocPRIMDOC(BSTR* Value));
  STDMETHOD(get_DocTGID_DPRNT(BSTR* Value));
  STDMETHOD(get_DocTIDDOCPRNT(BSTR* Value));
  STDMETHOD(get_DocTIDEDPRNT(BSTR* Value));
  STDMETHOD(get_DocTIDNOMPRNT(BSTR* Value));
  STDMETHOD(get_DocTIDPARTPRNT(BSTR* Value));
  STDMETHOD(get_DocTIDPRNT(BSTR* Value));
  STDMETHOD(get_DocTKFPRNT(double* Value));
  STDMETHOD(get_DocTKOLPRNT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_DocTPRICEPRNT(double* Value));
  STDMETHOD(get_DocTSUMPRNT(double* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(set_DocAllFNAMEUSER(BSTR Value));
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
  STDMETHOD(set_DocGID_DPRN(BSTR Value));
  STDMETHOD(set_DocIDDOCPRN(BSTR Value));
  STDMETHOD(set_DocIDPRN(BSTR Value));
  STDMETHOD(set_DocIDTPRICE(BSTR Value));
  STDMETHOD(set_DocPRIMDOC(BSTR Value));
  STDMETHOD(set_DocTGID_DPRNT(BSTR Value));
  STDMETHOD(set_DocTIDDOCPRNT(BSTR Value));
  STDMETHOD(set_DocTIDEDPRNT(BSTR Value));
  STDMETHOD(set_DocTIDNOMPRNT(BSTR Value));
  STDMETHOD(set_DocTIDPARTPRNT(BSTR Value));
  STDMETHOD(set_DocTIDPRNT(BSTR Value));
  STDMETHOD(set_DocTKFPRNT(double Value));
  STDMETHOD(set_DocTKOLPRNT(double Value));
  STDMETHOD(set_DocTPRICEPRNT(double Value));
  STDMETHOD(set_DocTSUMPRNT(double Value));
  STDMETHOD(AddDocNewString());
  STDMETHOD(CancelDvRegDoc());
  STDMETHOD(DeleteDoc(BSTR Id));
  STDMETHOD(DeleteStringDoc());
  STDMETHOD(DvRegDoc());
  STDMETHOD(GetIdDocPoNomeruDoc(int number_doc, DATE date_doc, BSTR* id_doc));
  STDMETHOD(NewDoc());
  STDMETHOD(OpenDoc(BSTR IdDoc));
  STDMETHOD(SaveDoc());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocPrihNaklImplH
