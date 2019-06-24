// OLEDMSPRGRPNOMIMPL : Implementation of TOleDMSprGrpNomImpl (CoClass: OleDMSprGrpNom, Interface: IOleDMSprGrpNom)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRGRPNOMIMPL.H"
#include "UDMSprTypePrice.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprGrpNomImpl

STDMETHODIMP TOleDMSprGrpNomImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  if (DMSprGrpNom->DeleteElement(StrToInt64(Id))==true)
	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprGrpNom->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElGID_SGRPNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->ElementGID_SGRPNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElIDGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->ElementIDGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElIDGRPGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->ElementIDGRPGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElNAMEGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->ElementNAMEGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprGrpNom->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::GetIdElement(BSTR gid, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprGrpNom->GetIDElement(gid)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::NewElement(BSTR IdGrp)
{ 
  try
  {
  DMSprGrpNom->NewElement(StrToInt64(IdGrp));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::OpenElement(BSTR Id)
{ 
  try
  {
  DMSprGrpNom->OpenElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::OpenTable()
{
  try
  {
  DMSprGrpNom->OpenTable();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::SaveElement()
{
  try
  {
  if(DMSprGrpNom->SaveElement()==true)
  	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprGrpNom->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::set_ElGID_SGRPNOM(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementGID_SGRPNOM->AsString=Value;
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElIDGN(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementIDGN->AsInt64=StrToInt64(Value);
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElIDGRPGN(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementIDGRPGN->AsInt64=StrToInt64(Value);
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElNAMEGN(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementNAMEGN->AsString=Value;
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};



STDMETHODIMP TOleDMSprGrpNomImpl::TableFirst()
{
  try
  {
  DMSprGrpNom->Table->First();

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::TableNext()
{
  try
  {
  DMSprGrpNom->Table->Next();

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

