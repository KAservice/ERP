// OLEDMDOCREPKKMIMPL.H : Declaration of the TOleDMDocRepKKMImpl

#ifndef OleDMDocRepKKMImplH
#define OleDMDocRepKKMImplH

#define ATL_APARTMENT_THREADED

#include "DBServ10_TLB.H"
#include "UDMDocRepKKM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocRepKKMImpl     Implements IOleDMDocRepKKM, default interface of OleDMDocRepKKM
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ10.OleDMDocRepKKM
// Description    : Документ Отчет ККМ
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMDocRepKKMImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMDocRepKKMImpl, &CLSID_OleDMDocRepKKM>,
  public IDispatchImpl<IOleDMDocRepKKM, &IID_IOleDMDocRepKKM, &LIBID_DBServ10>
{
public:
  TOleDMDocRepKKMImpl()
  {
  Doc=new TDMDocRepKKM(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }
  ~TOleDMDocRepKKMImpl()
  {
  delete Doc;
  }
  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ10.OleDMDocRepKKM");
  DECLARE_DESCRIPTION("Документ Отчет ККМ");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMDocRepKKMImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TOleDMDocRepKKMImpl)
  COM_INTERFACE_ENTRY(IOleDMDocRepKKM)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMDocRepKKM)
END_COM_MAP()

// IOleDMDocRepKKM
public:
int CodeError;
AnsiString TextError;
TDMDocRepKKM * Doc;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_DocAllFNAME_USER(BSTR* Value));
  STDMETHOD(get_DocAllGID_DOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDDOGDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDSKLDOC(BSTR* Value));
  STDMETHOD(get_DocAllIDUSERDOC(BSTR* Value));
  STDMETHOD(get_DocAllNAME_SDOG(BSTR* Value));
  STDMETHOD(get_DocAllNAMEFIRM(BSTR* Value));
  STDMETHOD(get_DocAllNAMEKLIENT(BSTR* Value));
  STDMETHOD(get_DocAllNAMESKLAD(BSTR* Value));
  STDMETHOD(get_DocAllNUMDOC(int* Value));
  STDMETHOD(get_DocAllPOSDOC(BSTR* Value));
  STDMETHOD(get_DocAllPRDOC(int* Value));
  STDMETHOD(get_DocAllSUMDOC(double* Value));
  STDMETHOD(get_DocAllTDOC(BSTR* Value));
  STDMETHOD(get_DocDVREG_DREPKKM(int* Value));
  STDMETHOD(get_DocGID_DREPKKM(BSTR* Value));
  STDMETHOD(get_DocID_DREPKKM(BSTR* Value));
  STDMETHOD(get_DocIDDOC_DREPKKM(BSTR* Value));
  STDMETHOD(get_DocIDKKM_DREPKKM(BSTR* Value));
  STDMETHOD(get_DocNAD_DREPKKM(double* Value));
  STDMETHOD(get_DocNAMEKKM(BSTR* Value));
  STDMETHOD(get_DocNKL_DREPKKM(int* Value));
  STDMETHOD(get_DocOPLNAL_DREPKKM(double* Value));
  STDMETHOD(get_DocOPLPC_DREPKKM(double* Value));
  STDMETHOD(get_DocPRIM_DREPKKM(BSTR* Value));
  STDMETHOD(get_DocSK_DREPKKM(double* Value));
  STDMETHOD(get_DocTGID_DREPKKMT(BSTR* Value));
  STDMETHOD(get_DocTID_DREPKKMT(BSTR* Value));
  STDMETHOD(get_DocTIDDOC_DREPKKMT(BSTR* Value));
  STDMETHOD(get_DocTIDED_DREPKKMT(BSTR* Value));
  STDMETHOD(get_DocTIDNOM_DREPKKMT(BSTR* Value));
  STDMETHOD(get_DocTKF_DREPKKMT(double* Value));
  STDMETHOD(get_DocTKOL_DREPKKMT(double* Value));
  STDMETHOD(get_DocTNAD_REPKKMT(double* Value));
  STDMETHOD(get_DocTNAMEED(BSTR* Value));
  STDMETHOD(get_DocTNAMENOM(BSTR* Value));
  STDMETHOD(get_DocTPRICE_DREPKKMT(double* Value));
  STDMETHOD(get_DocTPRICEFULL_DREPKKMT(double* Value));
  STDMETHOD(get_DocTSK_DREPKKMT(double* Value));
  STDMETHOD(get_DocTSUM_DREPKKMT(double* Value));
  STDMETHOD(get_DocTTNOM(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(set_DocAllGID_DOC(BSTR Value));
  STDMETHOD(set_DocAllIDDOC(BSTR Value));
  STDMETHOD(set_DocAllIDDOGDOC(BSTR Value));
  STDMETHOD(set_DocAllIDFIRMDOC(BSTR Value));
  STDMETHOD(set_DocAllIDKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDSKLDOC(BSTR Value));
  STDMETHOD(set_DocAllIDUSERDOC(BSTR Value));
  STDMETHOD(set_DocAllNUMDOC(int Value));
  STDMETHOD(set_DocAllPOSDOC(BSTR Value));
  STDMETHOD(set_DocAllPRDOC(int Value));
  STDMETHOD(set_DocAllSUMDOC(double Value));
  STDMETHOD(set_DocAllTDOC(BSTR Value));
  STDMETHOD(set_DocDVREG_DREPKKM(int Value));
  STDMETHOD(set_DocGID_DREPKKM(BSTR Value));
  STDMETHOD(set_DocID_DREPKKM(BSTR Value));
  STDMETHOD(set_DocIDDOC_DREPKKM(BSTR Value));
  STDMETHOD(set_DocIDKKM_DREPKKM(BSTR Value));
  STDMETHOD(set_DocNAD_DREPKKM(double Value));
  STDMETHOD(set_DocNKL_DREPKKM(int Value));
  STDMETHOD(set_DocOPLNAL_DREPKKM(double Value));
  STDMETHOD(set_DocOPLPC_DREPKKM(double Value));
  STDMETHOD(set_DocPRIM_DREPKKM(BSTR Value));
  STDMETHOD(set_DocSK_DREPKKM(double Value));
  STDMETHOD(set_DocTGID_DREPKKMT(BSTR Value));
  STDMETHOD(set_DocTID_DREPKKMT(BSTR Value));
  STDMETHOD(set_DocTIDDOC_DREPKKMT(BSTR Value));
  STDMETHOD(set_DocTIDED_DREPKKMT(BSTR Value));
  STDMETHOD(set_DocTIDNOM_DREPKKMT(BSTR Value));
  STDMETHOD(set_DocTKF_DREPKKMT(double Value));
  STDMETHOD(set_DocTKOL_DREPKKMT(double Value));
  STDMETHOD(set_DocTNAD_REPKKMT(double Value));
  STDMETHOD(set_DocTPRICE_DREPKKMT(double Value));
  STDMETHOD(set_DocTPRICEFULL_DREPKKMT(double Value));
  STDMETHOD(set_DocTSK_DREPKKMT(double Value));
  STDMETHOD(set_DocTSUM_DREPKKMT(double Value));
  STDMETHOD(AddDocNewString());
  STDMETHOD(CancelDvRegDoc());
  STDMETHOD(CloseDoc());
  STDMETHOD(DeleteDoc(BSTR Id));
  STDMETHOD(DeleteStringDoc());
  STDMETHOD(DvRegDoc());
  STDMETHOD(get_TableEOF(int* Value));
  STDMETHOD(NewDoc());
  STDMETHOD(OpenDoc(BSTR Id));
  STDMETHOD(SaveDoc());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_NameBase(BSTR* Value));
  STDMETHOD(get_PrefiksDoc(BSTR* Value));
  STDMETHOD(set_PrefiksDoc(BSTR Value));
  STDMETHOD(get_DocAllIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(set_DocAllIDBASE_GALLDOC(BSTR Value));
};

#endif //OleDMDocRepKKMImplH

