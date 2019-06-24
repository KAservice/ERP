// 1.2
// Unit1.h : Declaration of the TQueryUpdateImpl

#ifndef QueryUpdateImplH
#define QueryUpdateImplH

#define _ATL_APARTMENT_THREADED

#include "FibProvider_TLB.h"
#include "UDMQueryUpdate.h"

/////////////////////////////////////////////////////////////////////////////
// TQueryUpdateImpl     Implements IQueryUpdate, default interface of QueryUpdate
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : FibProvider.QueryUpdate
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TQueryUpdateImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TQueryUpdateImpl, &CLSID_QueryUpdate>,
  public IDispatchImpl<IQueryUpdate, &IID_IQueryUpdate, &LIBID_FibProvider>
{
public:
  TQueryUpdateImpl()
  {
  DM=new TDMQueryUpdate(Application);
  }

  ~TQueryUpdateImpl()
  {
  delete DM;
  }
  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("FibProvider.QueryUpdate");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TQueryUpdateImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TQueryUpdateImpl)
  COM_INTERFACE_ENTRY(IQueryUpdate)
  COM_INTERFACE_ENTRY2(IDispatch, IQueryUpdate)
END_COM_MAP()

// IQueryUpdate
public:
	TDMQueryUpdate *DM;

  STDMETHOD(ClearTextSQL());
  STDMETHOD(CloseQuery());
  STDMETHOD(ExecProc(int* result));
  STDMETHOD(ExecQuery(int* result));
  STDMETHOD(get_EOF_(int* Value));
  STDMETHOD(get_flError(int* Value));
  STDMETHOD(get_RecordCount(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(GetStringValueField(BSTR field_name, BSTR* result));
  STDMETHOD(NextRecord(int* result));
  STDMETHOD(SetStringParamQuery(BSTR param_name, BSTR param_value, int* result));
  STDMETHOD(SetTextSQL(BSTR text_sql));
  STDMETHOD(CommitTransaction(int* result));
  STDMETHOD(RollbackTransaction(int* result));
  STDMETHOD(StartTransaction(int* result));
};

#endif //Unit1H
