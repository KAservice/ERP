 // 1.1
// UNIT1 : Implementation of TOleDMSprPriceImpl (CoClass: OleDMSprPrice, Interface: IOleDMSprPrice)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprPrice.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprPriceImpl
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


STDMETHODIMP TOleDMSprPriceImpl::NewElement(BSTR id_nom, BSTR id_type_price)
{
  try
  {
  DMSprPrice->IdNom=glStrToInt64(id_nom);
  DMSprPrice->IdTypePrice=glStrToInt64(id_type_price);
  DMSprPrice->NewElement();
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

STDMETHODIMP TOleDMSprPriceImpl::SaveElement(int* result)
{ 
  try
  {
  *result=DMSprPrice->SaveElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
  result=0;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprPrice->OpenElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::DeleteElement(BSTR id)
{
  try
  {
  DMSprPrice->DeleteElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::OpenTable(BSTR id_nom)
{
  try
  {
  DMSprPrice->OpenTable(glStrToInt64(id_nom));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::get_TableEof(int* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  //*gid=WideString(DMSprPrice->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  //*id=WideString(IntToStr(DMSprPrice->GetIDElement(gid)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::TableFirst()
{
  try
  {
  DMSprPrice->Table->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::TableNext()
{
  try
  {
  DMSprPrice->Table->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::get_TableGID_SPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->TableGID_SPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TableID_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->TableID_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TableIDNOM_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->TableIDNOM_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TableIDTYPE_PRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->TableIDTYPE_PRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::get_TableNAME_TPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprPrice->TableNAME_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


//STDMETHODIMP TOleDMSprPriceImpl::get_TableZNACH_PRICE(double* Value)
//{
//  try
//  {
//  *Value=DMSprPrice->TableZNACH_PRICE->AsFloat;
//  }
//  catch(Exception &e)
//  {
//    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
//  }
//  return S_OK;
//};


STDMETHODIMP TOleDMSprPriceImpl::get_ElementGID_SPRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::get_ElementID_PRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::get_ElementIDNOM_PRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::get_ElementIDTYPE_PRICE(BSTR* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::get_ElementZNACH_PRICE(double* Value)
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


STDMETHODIMP TOleDMSprPriceImpl::set_ElementGID_SPRICE(BSTR Value)
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


STDMETHODIMP TOleDMSprPriceImpl::set_ElementID_PRICE(BSTR Value)
{
  try
  {
  DMSprPrice->Element->Edit();
  DMSprPrice->ElementID_PRICE->AsString=Value;
  DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElementIDNOM_PRICE(BSTR Value)
{
  try
  {
  DMSprPrice->Element->Edit();
  DMSprPrice->ElementIDNOM_PRICE->AsString=Value;
  DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElementIDTYPE_PRICE(BSTR Value)
{
  try
  {
  DMSprPrice->Element->Edit();
  DMSprPrice->ElementIDTYPE_PRICE->AsString=Value;
  DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::set_ElementZNACH_PRICE(double Value)
{
  try
  {
  DMSprPrice->Element->Edit();
  DMSprPrice->ElementZNACH_PRICE->AsString=Value;
  DMSprPrice->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprPriceImpl::FindElement(BSTR id_type_price, BSTR id_nom, BSTR * result)
{ 
  try
  {
  *result=WideString(IntToStr(DMSprPrice->FindElement(glStrToInt64(id_type_price), glStrToInt64(id_nom))).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprPriceImpl::get_TableZNACH_PRICE(double* Value)
{
  try
  {
  *Value=DMSprPrice->TableZNACH_PRICE->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
};



