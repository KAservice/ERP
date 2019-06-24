 // 1.1
// Unit1.h : Declaration of the TOleDMSprGrpNomImpl

#ifndef UOleDMSprGrpNomH
#define UOleDMSprGrpNomH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMSprGrpNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprGrpNomImpl     Implements IOleDMSprGrpNom, default interface of OleDMSprGrpNom
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprGrpNom
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprGrpNomImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprGrpNomImpl, &CLSID_OleDMSprGrpNom>,
  public IDispatchImpl<IOleDMSprGrpNom, &IID_IOleDMSprGrpNom, &LIBID_DBServ20>
{
public:
  TOleDMSprGrpNomImpl()
  {
  DMSprGrpNom=new TDMSprGrpNom(Application);
  CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprGrpNomImpl()
  {
  delete DMSprGrpNom;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMSprGrpNom");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprGrpNomImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprGrpNomImpl)
  COM_INTERFACE_ENTRY(IOleDMSprGrpNom)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprGrpNom)
END_COM_MAP()

// IOleDMSprGrpNom
public:

  TDMSprGrpNom *DMSprGrpNom;
  int CodeError;
  AnsiString TextError;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(NewElement(BSTR id_grp));
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(DeleteElement(BSTR id, int* result));
  STDMETHOD(OpenTable());
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(GetGidElement(BSTR id, BSTR* gid));
  STDMETHOD(GetIdElement(BSTR gid, BSTR* id));
  STDMETHOD(get_TableGID_SGRPNOM(BSTR* Value));
  STDMETHOD(get_TableIDGN(BSTR* Value));
  STDMETHOD(get_TableIDGRPGN(BSTR* Value));
  STDMETHOD(get_TableNAMEGN(BSTR* Value));
  STDMETHOD(get_ElementIDGN(BSTR* Value));
  STDMETHOD(set_ElementIDGN(BSTR Value));
  STDMETHOD(get_ElementGID_SGRPNOM(BSTR* Value));
  STDMETHOD(get_ElementIDGRPGN(BSTR* Value));
  STDMETHOD(get_ElementNAMEGN(BSTR* Value));
  STDMETHOD(set_ElementGID_SGRPNOM(BSTR Value));
  STDMETHOD(set_ElementIDGRPGN(BSTR Value));
  STDMETHOD(set_ElementNAMEGN(BSTR Value));
};

#endif //Unit1H
