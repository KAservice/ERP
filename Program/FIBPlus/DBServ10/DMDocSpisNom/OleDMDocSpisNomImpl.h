// OLEDMDOCSPISNOMIMPL.H : Declaration of the TOleDMDocSpisNomImpl

#ifndef OleDMDocSpisNomImplH
#define OleDMDocSpisNomImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocSpisNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocSpisNomImpl     Implements IOleDMDocSpisNom, default interface of OleDMDocSpisNom
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocSpisNom
// Description    : Документ списание номенклатуры
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocSpisNomImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocSpisNomImpl, &CLSID_OleDMDocSpisNom>,
  public IDispatchImpl<IOleDMDocSpisNom, &IID_IOleDMDocSpisNom, &LIBID_DBServ10>
{
public:
  TOleDMDocSpisNomImpl()
  {
  doc=new TDMDocSpisNom(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMDocSpisNomImpl()
  {
  delete doc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocSpisNom");
  DECLARE_DESCRIPTION("Документ списание номенклатуры");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocSpisNomImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocSpisNomImpl)
  COM_INTERFACE_ENTRY(IOleDMDocSpisNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocSpisNom)
END_COM_MAP()

// IOleDMDocSpisNom
public:

        int CodeError;
        AnsiString TextError;
        TDMDocSpisNom *doc;
 
  STDMETHOD(AddDocNewString());
  STDMETHOD(CancelDvRegDoc());
  STDMETHOD(CloseDoc());
  STDMETHOD(DeleteDoc(BSTR Id));
  STDMETHOD(DeleteStringDoc());
  STDMETHOD(DvRegDoc());
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_DocAllGID_DOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDSKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllNUMDOC(int* Value));
  STDMETHOD(get_DocAllPOSDOC(BSTR* Value));
  STDMETHOD(get_DocAllPRDOC(int* Value));
  STDMETHOD(get_DocAllSUMDOC(double* Value));
  STDMETHOD(get_DocAllTDOC(BSTR* Value));
  STDMETHOD(get_DocGID_DSPN(BSTR* Value));
  STDMETHOD(get_DocIDDOCSPN(BSTR* Value));
  STDMETHOD(get_DocIDSPN(BSTR* Value));
  STDMETHOD(get_DocPRIMSPN(BSTR* Value));
  STDMETHOD(get_DocTGID_DSPNT(BSTR* Value));
  STDMETHOD(get_DocTIDDOCSPNT(BSTR* Value));
  STDMETHOD(get_DocTIDEDSPNT(BSTR* Value));
  STDMETHOD(get_DocTIDNOMSPNT(BSTR* Value));
  STDMETHOD(get_DocTIDSPNT(BSTR* Value));
  STDMETHOD(get_DocTKFSPNT(double* Value));
  STDMETHOD(get_DocTKOLSPNT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_DocTPRICESPNT(double* Value));
  STDMETHOD(get_DocTSUMSPNT(double* Value));
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
  STDMETHOD(set_DocAllNUMDOC(int Value));
  STDMETHOD(set_DocAllPOSDOC(BSTR Value));
  STDMETHOD(set_DocAllPRDOC(int Value));
  STDMETHOD(set_DocAllSUMDOC(double Value));
  STDMETHOD(set_DocAllTDOC(BSTR Value));
  STDMETHOD(set_DocGID_DSPN(BSTR Value));
  STDMETHOD(set_DocIDDOCSPN(BSTR Value));
  STDMETHOD(set_DocIDSPN(BSTR Value));
  STDMETHOD(set_DocPRIMSPN(BSTR Value));
  STDMETHOD(set_DocTGID_DSPNT(BSTR Value));
  STDMETHOD(set_DocTIDDOCSPNT(BSTR Value));
  STDMETHOD(set_DocTIDEDSPNT(BSTR Value));
  STDMETHOD(set_DocTIDNOMSPNT(BSTR Value));
  STDMETHOD(set_DocTIDSPNT(BSTR Value));
  STDMETHOD(set_DocTKFSPNT(double Value));
  STDMETHOD(set_DocTKOLSPNT(double Value));
  STDMETHOD(set_DocTPRICESPNT(double Value));
  STDMETHOD(set_DocTSUMSPNT(double Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocSpisNomImplH
