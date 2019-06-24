 // 1.1
// UNIT1 : Implementation of TOleDMSprTypePriceImpl (CoClass: OleDMSprTypePrice, Interface: IOleDMSprTypePrice)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprTypePrice.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprTypePriceImpl
STDMETHODIMP TOleDMSprTypePriceImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::NewElement()
{
  try
  {
  DMSprTypePrice->NewElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprTypePrice->OpenElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::SaveElement(int* result)
{ 
  try
  {
  *result=DMSprTypePrice->SaveElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
  result=0;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::DeleteElement(BSTR id)
{ 
  try
  {
  DMSprTypePrice->DeleteElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::OpenTable()
{
  try
  {
  DMSprTypePrice->OpenTable();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::get_TableEof(int* Value)
{
  try
  {
  if (DMSprTypePrice->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprTypePrice->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprTypePrice->GetIDElement(gid)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::TableFirst()
{
  try
  {
  DMSprTypePrice->Table->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::TableNext()
{
  try
  {
  DMSprTypePrice->Table->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::get_TableGID_STPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprTypePrice->TableGID_STPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_TableID_TPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprTypePrice->TableID_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_TableNAME_TPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprTypePrice->TableNAME_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElementGID_STPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprTypePrice->ElementGID_STPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElementID_TPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprTypePrice->ElementID_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElementNAME_TPRICE(BSTR* Value)
{
  try
  {
   *Value=WideString(DMSprTypePrice->ElementNAME_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::set_ElementGID_STPRICE(BSTR Value)
{
  try
  {
  DMSprTypePrice->Element->Edit();
  DMSprTypePrice->ElementGID_STPRICE->AsString=Value;
  DMSprTypePrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::set_ElementID_TPRICE(BSTR Value)
{
  try
  {
  DMSprTypePrice->Element->Edit();
  DMSprTypePrice->ElementID_TPRICE->AsString=Value;
  DMSprTypePrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::set_ElementNAME_TPRICE(BSTR Value)
{
  try
  {
  DMSprTypePrice->Element->Edit();
  DMSprTypePrice->ElementNAME_TPRICE->AsString=Value;
  DMSprTypePrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


