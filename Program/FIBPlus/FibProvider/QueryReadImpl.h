// 1.2
// Unit1.h : Declaration of the TQueryReadImpl

#ifndef QueryReadImplH
#define QueryReadImplH

#define _ATL_APARTMENT_THREADED

#include "FibProvider_TLB.h"
#include "UDMQueryRead.h"

/////////////////////////////////////////////////////////////////////////////
// TQueryReadImpl     Implements IQueryRead, default interface of QueryRead
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : FibProvider.QueryRead
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TQueryReadImpl :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TQueryReadImpl, &CLSID_QueryRead>,
  public IDispatchImpl<IQueryRead, &IID_IQueryRead, &LIBID_FibProvider>
{
public:
  TQueryReadImpl()
  {
  DM=new TDMQueryRead(Application);
  }

  ~TQueryReadImpl()
  {
  delete DM;
  }

  // Data used when registering Object
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("FibProvider.QueryRead");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TQueryReadImpl>
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(TQueryReadImpl)
  COM_INTERFACE_ENTRY(IQueryRead)
  COM_INTERFACE_ENTRY2(IDispatch, IQueryRead)
END_COM_MAP()

// IQueryRead
public:

TDMQueryRead *DM;

  STDMETHOD(ClearTextSQL());
  STDMETHOD(CloseQuery());
  STDMETHOD(ExecProc(int* result));
  STDMETHOD(ExecQuery(int* result));
  STDMETHOD(get_EOF_(int* result));
  STDMETHOD(get_flError(int* result));
  STDMETHOD(get_RecordCount(int* Value));
  STDMETHOD(get_TextError(BSTR* Value));
  STDMETHOD(GetStringValueField(BSTR field_name, BSTR* result));
  STDMETHOD(NextRecord(int* result));
  STDMETHOD(SetStringParamQuery(BSTR param_name, BSTR param_value, int* result));
  STDMETHOD(SetTextSQL(BSTR text_sql));
};

#endif //Unit1H
