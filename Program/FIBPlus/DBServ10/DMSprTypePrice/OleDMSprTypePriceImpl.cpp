// OLEDMSPRTYPEPRICEIMPL : Implementation of TOleDMSprTypePriceImpl (CoClass: OleDMSprTypePrice, Interface: IOleDMSprTypePrice)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRTYPEPRICEIMPL.H"

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


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElGID_STPRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElID_TPRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprTypePriceImpl::get_ElNAME_TPRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprTypePriceImpl::get_TableEOF(int* Value)
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


STDMETHODIMP TOleDMSprTypePriceImpl::OpenTable()
{
  try
  {
  DMSprTypePrice->OpenTable();;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::set_ElGID_STPRICE(BSTR Value)
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


STDMETHODIMP TOleDMSprTypePriceImpl::set_ElID_TPRICE(BSTR Value)
{
  try
  {
  DMSprTypePrice->Element->Edit();
  DMSprTypePrice->ElementID_TPRICE->AsInt64=StrToInt64(Value);
  DMSprTypePrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprTypePriceImpl::set_ElNAME_TPRICE(BSTR Value)
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



STDMETHODIMP TOleDMSprTypePriceImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  DMSprTypePrice->DeleteElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::GetIdElement(BSTR gid, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprTypePrice->GetIDElement(gid)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::GetIDTypePrice(BSTR name, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprTypePrice->GetIDTypePrice(name)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::NewElement()
{
  try
  {
  DMSprTypePrice->NewElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::OpenElement(BSTR Id)
{ 
  try
  {
  DMSprTypePrice->OpenElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::SaveElement()
{
  try
  {
  if(DMSprTypePrice->SaveElement()==true)
  {
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprTypePrice->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}


STDMETHODIMP TOleDMSprTypePriceImpl::TableFirst()
{
  try
  {
  DMSprTypePrice->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::TableNext()
{
  try
  {
  DMSprTypePrice->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprTypePriceImpl::CloseElement()
{
  try
  {
  DMSprTypePrice->CloseElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}


