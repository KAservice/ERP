 // 1.1
// UNIT1 : Implementation of TQueryUpdateImpl (CoClass: QueryUpdate, Interface: IQueryUpdate)

#include <vcl.h>
#pragma hdrstop

#include "QueryUpdateImpl.h"

/////////////////////////////////////////////////////////////////////////////
// TQueryUpdateImpl
STDMETHODIMP TQueryUpdateImpl::ClearTextSQL()
{
  try
  {
  DM->ClearTextSQL();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryUpdate);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::CloseQuery()
{
  try
  {
  DM->CloseQuery();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryUpdate);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::ExecProc(int* result)
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

STDMETHODIMP TQueryUpdateImpl::ExecQuery(int* result)
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

STDMETHODIMP TQueryUpdateImpl::get_EOF_(int* Value)
{
  try
  {
  if (DM->Query->Eof==true)
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
    return Error(e.Message.c_str(), IID_IQueryRead);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::get_flError(int* Value)
{
  try
  {
  if (DM->flError==true)
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
    return Error(e.Message.c_str(), IID_IQueryUpdate);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::get_RecordCount(int* Value)
{
  try
  {
  *Value=DM->Query->RecordCount;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryUpdate);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(DM->TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IQueryUpdate);
  }
  return S_OK;
};


STDMETHODIMP TQueryUpdateImpl::GetStringValueField(BSTR field_name, BSTR* result)




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

STDMETHODIMP TQueryUpdateImpl::NextRecord(int* result)
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

STDMETHODIMP TQueryUpdateImpl::SetStringParamQuery(BSTR param_name, BSTR param_value,
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

STDMETHODIMP TQueryUpdateImpl::SetTextSQL(BSTR text_sql)
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


STDMETHODIMP TQueryUpdateImpl::CommitTransaction(int* result)
{
  try
  {
  if (DM->CommitTransaction()==true)
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

STDMETHODIMP TQueryUpdateImpl::RollbackTransaction(int* result)
{
  try
  {
  if (DM->RollbackTransaction()==true)
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

STDMETHODIMP TQueryUpdateImpl::StartTransaction(int* result)
{
  try
  {
  if (DM->StartTransaction()==true)
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


