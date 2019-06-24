// OLEDMIMPL : Implementation of TOleDMImpl (CoClass: OleDM, Interface: IOleDM)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMIMPL.H"
#include "UDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMImpl

STDMETHODIMP TOleDMImpl::get_ConnectString(BSTR* Value)
{
  try
  {
  *Value=WideString(DM->ConnectString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};
//----------------------------------------------------------------------------

STDMETHODIMP TOleDMImpl::get_NameUser(BSTR* Value)
{
  try
  {
  *Value=WideString(DM->NameUser.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMImpl::get_PasswordUser(BSTR* Value)
{
  try
  {
  *Value=WideString(DM->PasswordUser.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMImpl::GlobConnect()
{
if(DM->GlobConnect2()==true)
        {
        ConnectOK=1;
        }
else
        {
        ConnectOK=0;
        TextError=DM->TextError;
        }
return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMImpl::set_ConnectString(BSTR Value)
{
  try
  {
  DM->ConnectString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMImpl::set_NameUser(BSTR Value)
{
  try
  {
  DM->NameUser=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMImpl::set_PasswordUser(BSTR Value)
{
  try
  {
  DM->PasswordUser=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};
//------------------------------------------------------------------------------


STDMETHODIMP TOleDMImpl::get_ConnectOK(int* Value)
{
  try
  {
  *Value=ConnectOK;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};
//----------------------------------------------------------------------------

STDMETHODIMP TOleDMImpl::get_OleCodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};
//------------------------------------------------------------------------------

STDMETHODIMP TOleDMImpl::get_OleTextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDM);
  }
  return S_OK;
};
//------------------------------------------------------------------------------

