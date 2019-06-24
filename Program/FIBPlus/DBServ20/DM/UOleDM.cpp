 // 1.1
// UNIT1 : Implementation of TOleDMImpl (CoClass: OleDM, Interface: IOleDM)

#include <vcl.h>
#pragma hdrstop

#include "UOleDM.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMImpl
STDMETHODIMP TOleDMImpl::get_CodeError(int* Value)
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


STDMETHODIMP TOleDMImpl::get_TextError(BSTR* Value)
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


STDMETHODIMP TOleDMImpl::GlobConnect()
{
if(DM->GlobConnect2()==true)
        {
		ConnectOK=1;
		CodeError=0;
        }
else
		{
		CodeError=1;
        ConnectOK=0;
        TextError=DM->TextError;
		}
return S_OK;
}

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


