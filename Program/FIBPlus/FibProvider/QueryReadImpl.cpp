 // 1.1
// UNIT1 : Implementation of TQueryReadImpl (CoClass: QueryRead, Interface: IQueryRead)

#include <vcl.h>
#pragma hdrstop

#include "QueryReadImpl.h"

/////////////////////////////////////////////////////////////////////////////
// TQueryReadImpl
STDMETHODIMP TQueryReadImpl::ClearTextSQL()
{
  try
  {
  DM->ClearTextSQL();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::CloseQuery()
{
  try
  {
  DM->CloseQuery();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::ExecProc(int* result)
{
  try
  {
  if (DM->ExecProc()==true)
	{
	*result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}

STDMETHODIMP TQueryReadImpl::ExecQuery(int* result)
{
  try
  {
  if (DM->ExecQuery()==true)
	{
	*result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}

STDMETHODIMP TQueryReadImpl::get_EOF_(int* result)
{
  try
  {
  if (DM->Query->Eof==true)
	{
	*result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::get_flError(int* result)
{
  try
  {
  if (DM->flError==true)
	{
	*result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::get_RecordCount(int* Value)
{
  try
  {
  *Value=DM->Query->RecordCount;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(DM->TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryReadImpl::GetStringValueField(BSTR field_name, BSTR* result)
{
  try
  {
  *result=WideString(DM->GetStringValueField(field_name).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}

STDMETHODIMP TQueryReadImpl::NextRecord(int* result)
{
  try
  {
  if(DM->NextRecord()==true)
	{
	*result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}

STDMETHODIMP TQueryReadImpl::SetStringParamQuery(BSTR param_name, BSTR param_value,
          int* result)
{
  try
  {
  if (DM->SetStringParamQuery(param_name,param_value)==true)
	{
	 *result=1;
	}
  else
	{
    *result=0;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}

STDMETHODIMP TQueryReadImpl::SetTextSQL(BSTR text_sql)
{
  try
  {
  DM->SetTextSQL(text_sql);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
}


