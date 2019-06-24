 // 1.1
// UNIT1 : Implementation of TDMConnectionImpl (CoClass: DMConnection, Interface: IDMConnection)

#include <vcl.h>
#pragma hdrstop

#include "UDMConnectionImpl.h"

/////////////////////////////////////////////////////////////////////////////
// TDMConnectionImpl
STDMETHODIMP TDMConnectionImpl::ConnectBase(int* result)
{
  try
  {
  *result=DMConnection->ConnectBase();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
}

STDMETHODIMP TDMConnectionImpl::DisconnectBase()
{
  try
  {
  DMConnection->DisconnectBase();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::get_CharSet(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->CharSet.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::get_ConnectString(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->ConnectString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};



STDMETHODIMP TDMConnectionImpl::get_RoleName(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->RoleName.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::get_UserName(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->UserName.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::get_UserName2(BSTR* Value)
{
  try
  {
  *Value=WideString(DMConnection->UserName2.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_CharSet(BSTR Value)
{
  try
  {
  DMConnection->CharSet=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_ConnectString(BSTR Value)
{
  try
  {
  DMConnection->ConnectString=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_Password(BSTR Value)
{
  try
  {
  DMConnection->Password=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_RoleName(BSTR Value)
{
  try
  {
  DMConnection->RoleName=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_UserName(BSTR Value)
{
  try
  {
  DMConnection->UserName=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};


STDMETHODIMP TDMConnectionImpl::set_UserName2(BSTR Value)
{
  try
  {
  DMConnection->UserName2=Value;
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};



STDMETHODIMP TDMConnectionImpl::get_flError(int* Value)
{
  try
  {
  if (DMConnection->flError==true)
	{
	*Value=1;
	}
  else
	{
    *Value=0;
	}
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};



STDMETHODIMP TDMConnectionImpl::get_flConnected(int* Value)
{
  try
  {
  if (DMConnection->Database->Connected==true)
	{
	 *Value=1;
	}
  else
	{
    *Value=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IDMConnectionImpl);
  }
  return S_OK;
};



