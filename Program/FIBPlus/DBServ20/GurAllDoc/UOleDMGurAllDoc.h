 // 1.1
// Unit1.h : Declaration of the TOleDMGurAllDocImpl

#ifndef UOleDMGurAllDocH
#define UOleDMGurAllDocH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDMGurAllDoc.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMGurAllDocImpl     Implements IOleDMGurAllDoc, default interface of OleDMGurAllDoc
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMGurAllDoc
// Description    : Полный журнал
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMGurAllDocImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMGurAllDocImpl, &CLSID_OleDMGurAllDoc>,
  public IDispatchImpl<IOleDMGurAllDoc, &IID_IOleDMGurAllDoc, &LIBID_DBServ20>
{
public:
  TOleDMGurAllDocImpl()
  {
  DMGurAllDoc=new TDMGurAllDoc(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMGurAllDocImpl()
  {
  delete DMGurAllDoc;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMGurAllDoc");
  DECLARE_DESCRIPTION("Полный журнал");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMGurAllDocImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMGurAllDocImpl)
  COM_INTERFACE_ENTRY(IOleDMGurAllDoc)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMGurAllDoc)
END_COM_MAP()

// IOleDMGurAllDoc
public:
  TDMGurAllDoc *DMGurAllDoc;
  AnsiString TextError;
  int CodeError;

   
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(get_PosNach(BSTR* Value));
  STDMETHOD(set_PosNach(BSTR Value));
  STDMETHOD(get_PosCon(BSTR* Value));
  STDMETHOD(set_PosCon(BSTR Value));
  STDMETHOD(get_IdDoc(BSTR* Value));
  STDMETHOD(set_IdDoc(BSTR Value));
  STDMETHOD(get_IdKlient(BSTR* Value));
  STDMETHOD(get_IdSklad(BSTR* Value));
  STDMETHOD(set_IdKlient(BSTR Value));
  STDMETHOD(set_IdSklad(BSTR Value));
  STDMETHOD(get_IdFirm(BSTR* Value));
  STDMETHOD(get_StringTypeDoc(BSTR* Value));
  STDMETHOD(set_IdFirm(BSTR Value));
  STDMETHOD(set_StringTypeDoc(BSTR Value));
  STDMETHOD(get_OtborVkl(int* Value));
  STDMETHOD(set_OtborVkl(int Value));
  STDMETHOD(get_NoCheck(int* Value));
  STDMETHOD(set_NoCheck(int Value));
  STDMETHOD(OpenTable());
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(UpdateTable());
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableIDBASE_GALLDOC(BSTR* Value));
  STDMETHOD(get_TableIDDOC(BSTR* Value));
  STDMETHOD(get_TableIDDOCOSNDOC(BSTR* Value));
  STDMETHOD(get_TableIDDOGDOC(BSTR* Value));
  STDMETHOD(get_TableIDFIRMDOC(BSTR* Value));
  STDMETHOD(get_TableIDKLDOC(BSTR* Value));
  STDMETHOD(get_TableIDSKLDOC(BSTR* Value));
  STDMETHOD(get_TableIDUSERDOC(BSTR* Value));
  STDMETHOD(get_TableNAME_USER(BSTR* Value));
  STDMETHOD(get_TableNAMEFIRM(BSTR* Value));
  STDMETHOD(get_TableNAMEKLIENT(BSTR* Value));
  STDMETHOD(get_TableNAMESKLAD(BSTR* Value));
  STDMETHOD(get_TableNUMDOC(int* Value));
  STDMETHOD(get_TablePOSDOC(BSTR* Value));
  STDMETHOD(get_TablePRDOC(int* Value));
  STDMETHOD(get_TableSUMDOC(double* Value));
  STDMETHOD(get_TableTDOC(BSTR* Value));
};

#endif //Unit1H
