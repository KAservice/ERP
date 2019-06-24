 // 1.1
// Unit1.h : Declaration of the TOleDMSprInfBaseImpl

#ifndef UOleDMSprInfBaseH
#define UOleDMSprInfBaseH

#define _ATL_APARTMENT_THREADED

#include "DBServ20_TLB.h"
#include "UDM.h"
#include "UDMSprInfBase.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprInfBaseImpl     Implements IOleDMSprInfBase, default interface of OleDMSprInfBase
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : DBServ20.OleDMSprInfBase
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TOleDMSprInfBaseImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TOleDMSprInfBaseImpl, &CLSID_OleDMSprInfBase>,
  public IDispatchImpl<IOleDMSprInfBase, &IID_IOleDMSprInfBase, &LIBID_DBServ20>
{
public:
  TOleDMSprInfBaseImpl()
  {
  DMSprInfBase=new TDMSprInfBase(Application);
    CodeError=0;
  TextError="Ошибок нет";
  }

  ~TOleDMSprInfBaseImpl()
  {
  delete DMSprInfBase;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("DBServ20.OleDMSprInfBase");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TOleDMSprInfBaseImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TOleDMSprInfBaseImpl)
  COM_INTERFACE_ENTRY(IOleDMSprInfBase)
  COM_INTERFACE_ENTRY2(IDispatch, IOleDMSprInfBase)
END_COM_MAP()

// IOleDMSprInfBase
public:
  TDMSprInfBase *DMSprInfBase;
  int CodeError;
  AnsiString TextError;
 
  STDMETHOD(get_CodeError(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(OpenElement(BSTR id, int* result));
  STDMETHOD(OpenTable());
  STDMETHOD(NewElement());
  STDMETHOD(SaveElement(int* result));
  STDMETHOD(DeleteElement(BSTR id));
  STDMETHOD(GetIdPoName(BSTR name, BSTR* id));
  STDMETHOD(get_TableEof(int* Value));
  STDMETHOD(TableFirst());
  STDMETHOD(TableNext());
  STDMETHOD(get_TableGID_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(get_TableID_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(get_TableNAME_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(get_ElementGID_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(get_ElementID_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(get_ElementNAME_SINFBASE_OBMEN(BSTR* Value));
  STDMETHOD(set_ElementGID_SINFBASE_OBMEN(BSTR Value));
  STDMETHOD(set_ElementID_SINFBASE_OBMEN(BSTR Value));
  STDMETHOD(set_ElementNAME_SINFBASE_OBMEN(BSTR Value));
};

#endif //Unit1H
