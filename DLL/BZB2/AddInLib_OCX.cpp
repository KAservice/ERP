// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 5081 $
// File generated on 25.03.2009 20:57:27 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\Program Files\SCANCODE\Компонента 1С для принтеров Godex (ESC)\GodexESC.dll (1)
// LIBID: {4F0D4571-0E7B-11D1-A486-004095E1DAEA}
// LCID: 0
// Helpfile: 
// HelpString: V7 AddIn 1.0 Type Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\system32\stdole2.tlb)
// Errors:
//   Error creating palette bitmap of (TAddIn) : No Server registered for this CoClass
//   Error creating palette bitmap of (TAddInConnection) : No Server registered for this CoClass
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "AddInLib_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Addinlib_tlb
{

IInitDonePtr& TAddIn::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAddIn::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAddIn::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAddIn::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAddIn::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAddIn::ConnectTo(IInitDonePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAddIn::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AddIn;
  sd.IntfIID = __uuidof(IInitDone);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TAddIn::Init(LPDISPATCH pConnection/*[in]*/)
{
  GetDefaultInterface()->Init(pConnection/*[in]*/);
}

void __fastcall TAddIn::Done(void)
{
  GetDefaultInterface()->Done();
}

void __fastcall TAddIn::GetInfo(LPSAFEARRAY* pInfo/*[in,out]*/)
{
  GetDefaultInterface()->GetInfo(pInfo/*[in,out]*/);
}

IPropertyProfilePtr& TAddInConnection::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TAddInConnection::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TAddInConnection::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TAddInConnection::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TAddInConnection::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TAddInConnection::ConnectTo(IPropertyProfilePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TAddInConnection::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_AddInConnection;
  sd.IntfIID = __uuidof(IPropertyProfile);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TAddInConnection::RemoteRead(LPWSTR pszPropName/*[in]*/, VARIANT* pVar/*[out]*/, 
                                             Addinlib_tlb::IErrorLog* pErrorLog/*[in]*/, 
                                             unsigned_long varType/*[in]*/, 
                                             LPUNKNOWN pUnkObj/*[in]*/)
{
  GetDefaultInterface()->RemoteRead(pszPropName/*[in]*/, pVar/*[out]*/, pErrorLog/*[in]*/, 
                                    varType/*[in]*/, pUnkObj/*[in]*/);
}

void __fastcall TAddInConnection::Write(LPWSTR pszPropName/*[in]*/, VARIANT* pVar/*[in]*/)
{
  GetDefaultInterface()->Write(pszPropName/*[in]*/, pVar/*[in]*/);
}

void __fastcall TAddInConnection::RegisterProfileAs(BSTR bstrProfileName)
{
  GetDefaultInterface()->RegisterProfileAs(bstrProfileName);
}


};     // namespace Addinlib_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Addinlib_ocx
{

void __fastcall PACKAGE Register()
{
  // [2]
  TComponentClass cls_svr[] = {
                              __classid(Addinlib_tlb::TAddIn), 
                              __classid(Addinlib_tlb::TAddInConnection)
                           };
  RegisterComponents("(none)", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Addinlib_ocx
