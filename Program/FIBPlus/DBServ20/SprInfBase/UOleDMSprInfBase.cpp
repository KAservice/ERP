 // 1.1
// UNIT1 : Implementation of TOleDMSprInfBaseImpl (CoClass: OleDMSprInfBase, Interface: IOleDMSprInfBase)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprInfBase.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprInfBaseImpl
STDMETHODIMP TOleDMSprInfBaseImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprInfBase->OpenElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::OpenTable()
{
  try
  {
  DMSprInfBase->OpenTable();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::NewElement()
{
  try
  {
  DMSprInfBase->NewElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::SaveElement(int* result)
{ 
  try
  {
  if (DMSprInfBase->SaveElement()==true)
	{
	*result=1;
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	*result=0;
	CodeError=1;
	TextError=DMSprInfBase->TextError;
	}
  }
  catch(Exception &e)
  {
  *result=0;
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::DeleteElement(BSTR id)
{ 
  try
  {
  DMSprInfBase->DeleteElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::GetIdPoName(BSTR name, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprInfBase->GetIdPoName(name)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::get_TableEof(int* Value)
{
  try
  {
  if (DMSprInfBase->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::TableFirst()
{
  try
  {
  DMSprInfBase->Table->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::TableNext()
{
  try
  {
  DMSprInfBase->Table->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::get_TableGID_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->TableGID_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_TableID_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->TableID_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_TableNAME_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->TableNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_ElementGID_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->ElementGID_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_ElementID_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->ElementID_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::get_ElementNAME_SINFBASE_OBMEN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprInfBase->ElementNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::set_ElementGID_SINFBASE_OBMEN(BSTR Value)
{
  try
  {
  DMSprInfBase->Element->Edit();
  DMSprInfBase->ElementGID_SINFBASE_OBMEN->AsString=Value;
  DMSprInfBase->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::set_ElementID_SINFBASE_OBMEN(BSTR Value)
{
  try
  {
  DMSprInfBase->Element->Edit();
  DMSprInfBase->ElementID_SINFBASE_OBMEN->AsString=Value;
  DMSprInfBase->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprInfBaseImpl::set_ElementNAME_SINFBASE_OBMEN(BSTR Value)
{
  try
  {
  DMSprInfBase->Element->Edit();
  DMSprInfBase->ElementNAME_SINFBASE_OBMEN->AsString=Value;
  DMSprInfBase->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};


