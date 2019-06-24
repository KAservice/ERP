// OLEDMDOCINVIMPL.H : Declaration of the TOleDMDocInvImpl

#ifndef OleDMDocInvImplH
#define OleDMDocInvImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocInv.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocInvImpl     Implements IOleDMDocInv, default interface of OleDMDocInv
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocInv
// Description    : Документ Инвентаризация
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocInvImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocInvImpl, &CLSID_OleDMDocInv>,
  public IDispatchImpl<IOleDMDocInv, &IID_IOleDMDocInv, &LIBID_DBServ10>
{
public:
  TOleDMDocInvImpl()
  {
  doc=new TDMDocInv(Application);
  CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMDocInvImpl()
  {
  delete doc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocInv");
  DECLARE_DESCRIPTION("Документ Инвентаризация");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocInvImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocInvImpl)
  COM_INTERFACE_ENTRY(IOleDMDocInv)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocInv)
END_COM_MAP()

// IOleDMDocInv
public:

AnsiString TextError ;
int CodeError;
TDMDocInv *doc;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_DocAllFNAMEUSER(BSTR* Value));
  STDMETHOD(get_DocAllGID_DOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDSKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDUSERDOC(BSTR* Value));
  STDMETHOD(get_DocAllNUMDOC(int* Value));
  STDMETHOD(get_DocAllPOSDOC(BSTR* Value));
  STDMETHOD(get_DocAllPRDOC(int* Value));
  STDMETHOD(get_DocAllSUMDOC(double* Value));
  STDMETHOD(get_DocAllTDOC(BSTR* Value));
  STDMETHOD(get_DocGID_INV(BSTR* Value));
  STDMETHOD(get_DocID_INV(BSTR* Value));
  STDMETHOD(get_DocIDDOC_INV(BSTR* Value));
  STDMETHOD(get_DocPRIM_INV(BSTR* Value));
  STDMETHOD(get_DocTGID_INVT(BSTR* Value));
  STDMETHOD(get_DocTID_INVT(BSTR* Value));
  STDMETHOD(get_DocTIDDOC_INVT(BSTR* Value));
  STDMETHOD(get_DocTIDED_INVT(BSTR* Value));
  STDMETHOD(get_DocTIDNOM_INVT(BSTR* Value));
  STDMETHOD(get_DocTKF_INVT(double* Value));
  STDMETHOD(get_DocTKOLFAKT_INVT(double* Value));
  STDMETHOD(get_DocTKOLUCH_INVT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(set_DocAllGID_DOC(BSTR Value));
  STDMETHOD(set_DocAllIDDOC(BSTR Value));
  STDMETHOD(set_DocAllIDFIRMDOC(BSTR Value));
  STDMETHOD(set_DocAllIDSKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDUSERDOC(BSTR Value));
  STDMETHOD(set_DocAllNUMDOC(int Value));
  STDMETHOD(set_DocAllPOSDOC(BSTR Value));
  STDMETHOD(set_DocAllPRDOC(int Value));
  STDMETHOD(set_DocAllSUMDOC(double Value));
  STDMETHOD(set_DocAllTDOC(BSTR Value));
  STDMETHOD(set_DocGID_INV(BSTR Value));
  STDMETHOD(set_DocID_INV(BSTR Value));
  STDMETHOD(set_DocIDDOC_INV(BSTR Value));
  STDMETHOD(set_DocPRIM_INV(BSTR Value));
  STDMETHOD(set_DocTGID_INVT(BSTR Value));
  STDMETHOD(set_DocTID_INVT(BSTR Value));
  STDMETHOD(set_DocTIDDOC_INVT(BSTR Value));
  STDMETHOD(set_DocTIDED_INVT(BSTR Value));
  STDMETHOD(set_DocTIDNOM_INVT(BSTR Value));
  STDMETHOD(set_DocTKF_INVT(double Value));
  STDMETHOD(set_DocTKOLFAKT_INVT(double Value));
  STDMETHOD(set_DocTKOLUCH_INVT(double Value));
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
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocInvImplH
