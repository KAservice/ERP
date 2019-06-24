// OLEDMSPRPRICEIMPL : Implementation of TOleDMSprPriceImpl (CoClass: OleDMSprPrice, Interface: IOleDMSprPrice)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRPRICEIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprPriceImpl

STDMETHODIMP TOleDMSprPriceImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  DMSprPrice->DeleteElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::FindElement(BSTR IdTypePrice, BSTR IdNom,
  int* kol_record)
{ 
  try
  {
  *kol_record=DMSprPrice->FindElement(StrToInt64(IdTypePrice),StrToInt64(IdNom));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_ElGID_SPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->ElementGID_SPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_ElID_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->ElementID_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_ElIDNOM_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->ElementIDNOM_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_ElIDTYPE_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->ElementIDTYPE_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_ElZNACH_PRICE(double* Value)
{
  try
  {
   *Value=DMSprPrice->ElementZNACH_PRICE->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_IdNom(BSTR* Value)
{
  try
  {
  *Value=WideString(IntToStr(DMSprPrice->IdNom).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_IdTypePrice(BSTR* Value)
{
  try
  {
  *Value=WideString(IntToStr(DMSprPrice->IdTypePrice).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprPrice->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::NewElement()
{
  try
  {
  DMSprPrice->NewElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::OpenTable(BSTR IdNom)
{ 
  try
  {
  DMSprPrice->OpenTable(StrToInt64(IdNom));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::SaveElement()
{
  try
  {
  if (DMSprPrice->SaveElement()==true)
	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprPrice->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::set_ElGID_SPRICE(BSTR Value)
{
  try
  {
   DMSprPrice->Element->Edit();
   DMSprPrice->ElementGID_SPRICE->AsString=Value;
   DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElID_PRICE(BSTR Value)
{
  try
  {
   DMSprPrice->Element->Edit();
   DMSprPrice->ElementID_PRICE->AsInt64=StrToInt64(Value);
   DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElIDNOM_PRICE(BSTR Value)
{
  try
  {
   DMSprPrice->Element->Edit();
   DMSprPrice->ElementIDNOM_PRICE->AsInt64=StrToInt64(Value);
   DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElIDTYPE_PRICE(BSTR Value)
{
  try
  {
   DMSprPrice->Element->Edit();
   DMSprPrice->ElementIDTYPE_PRICE->AsInt64=StrToInt64(Value);
   DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElZNACH_PRICE(double Value)
{
  try
  {
   DMSprPrice->Element->Edit();
   DMSprPrice->ElementZNACH_PRICE->AsFloat=Value;
   DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_IdNom(BSTR Value)
{
  try
  {
   DMSprPrice->IdNom=StrToInt64(Value);

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_IdTypePrice(BSTR Value)
{
  try
  {
  DMSprPrice->IdTypePrice=StrToInt64(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


 