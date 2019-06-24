// OLEDMDOCOSTNOMIMPL.H : Declaration of the TOleDMDocOstNomImpl

#ifndef OleDMDocOstNomImplH
#define OleDMDocOstNomImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocOstNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocOstNomImpl     Implements IOleDMDocOstNom, default interface of OleDMDocOstNom
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocOstNom
// Description    : ƒÓÍÛÏÂÌÚ ¬¬Œƒ Œ—“¿“ Œ¬ ÕŒÃ≈Õ À¿“”–€
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocOstNomImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocOstNomImpl, &CLSID_OleDMDocOstNom>,
  public IDispatchImpl<IOleDMDocOstNom, &IID_IOleDMDocOstNom, &LIBID_DBServ10>
{
public:
  TOleDMDocOstNomImpl()
  {
  doc=new TDMDocOstNom(Application);
    CodeError=0;
  TextError="Œ¯Ë·ÓÍ ÌÂÚ";
  }
  ~TOleDMDocOstNomImpl()
  {
  delete doc;
  }



  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocOstNom");
  DECLARE_DESCRIPTION("ƒÓÍÛÏÂÌÚ ¬¬Œƒ Œ—“¿“ Œ¬ ÕŒÃ≈Õ À¿“”–€");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocOstNomImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocOstNomImpl)
  COM_INTERFACE_ENTRY(IOleDMDocOstNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocOstNom)
END_COM_MAP()

// IOleDMDocOstNom
public:

TDMDocOstNom *doc;
AnsiString TextError;
int CodeError;
 
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
  STDMETHOD(get_DocGID_DOSN(BSTR* Value));
  STDMETHOD(get_DocIDDOCOSN(BSTR* Value));
  STDMETHOD(get_DocIDOCN(BSTR* Value));
  STDMETHOD(get_DocIDTPRICEOSN(BSTR* Value));
  STDMETHOD(get_DocNAME_TPRICE(BSTR* Value));
  STDMETHOD(get_DocPRIMOSN(BSTR* Value));
  STDMETHOD(get_DocTGID_DOSNT(BSTR* Value));
  STDMETHOD(get_DocTIDDOCOSNT(BSTR* Value));
  STDMETHOD(get_DocTIDEDOSNT(BSTR* Value));
  STDMETHOD(get_DocTIDNOMOSNT(BSTR* Value));
  STDMETHOD(get_DocTIDOSNT(BSTR* Value));
  STDMETHOD(get_DocTIDPARTOSNT(BSTR* Value));
  STDMETHOD(get_DocTKFOSNT(double* Value));
  STDMETHOD(get_DocTKOLOSNT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_DocTPRICEOSNT(double* Value));
  STDMETHOD(get_DocTSUMOSNT(double* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
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
  STDMETHOD(set_DocGID_DOSN(BSTR Value));
  STDMETHOD(set_DocIDDOCOSN(BSTR Value));
  STDMETHOD(set_DocIDOCN(BSTR Value));
  STDMETHOD(set_DocIDTPRICEOSN(BSTR Value));
  STDMETHOD(set_DocPRIMOSN(BSTR Value));
  STDMETHOD(set_DocTGID_DOSNT(BSTR Value));
  STDMETHOD(set_DocTIDDOCOSNT(BSTR Value));
  STDMETHOD(set_DocTIDEDOSNT(BSTR Value));
  STDMETHOD(set_DocTIDNOMOSNT(BSTR Value));
  STDMETHOD(set_DocTIDOSNT(BSTR Value));
  STDMETHOD(set_DocTIDPARTOSNT(BSTR Value));
  STDMETHOD(set_DocTKFOSNT(double Value));
  STDMETHOD(set_DocTKOLOSNT(double Value));
  STDMETHOD(set_DocTPRICEOSNT(double Value));
  STDMETHOD(set_DocTSUMOSNT(double Value));
  STDMETHOD(GetIdDocPoNomeruDoc(int number_doc, DATE date_doc, BSTR* id_doc));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_DocTTNOM(int* Value));
  STDMETHOD(set_DocTTNOM(int Value));
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocOstNomImplH
