// OLEDMSPREDIMPL : Implementation of TOleDMSprEdImpl (CoClass: OleDMSprEd, Interface: IOleDMSprEd)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPREDIMPL.H"

extern __int64 glStrToInt64(AnsiString value);
/////////////////////////////////////////////////////////////////////////////
// TOleDMSprEdImpl

STDMETHODIMP TOleDMSprEdImpl::get_GID_SEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementGID_SED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_IdEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementIDED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_IdNomEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementIDNOMED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_IdOKEIEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementIDOKEIED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_KFEd(double* Value)
{
  try
  {
  *Value=DMSprEd->ElementKFED->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_NameEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_NeIspEd(int* Value)
{
  try
  {
   *Value=DMSprEd->ElementNEISPED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_ShEd(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementSHED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TShEd(int* Value)
{
  try
  {
  *Value=DMSprEd->ElementTSHED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_GID_SEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementGID_SED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_IdEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementIDED->AsInt64=glStrToInt64(Value);
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_IdNomEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementIDNOMED->AsInt64=glStrToInt64(Value);
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_IdOKEIEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementIDOKEIED->AsInt64=glStrToInt64(Value);
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_KFEd(double Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementKFED->AsFloat=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_NameEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementNAMEED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_NeIspEd(int Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementNEISPED->AsInteger=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ShEd(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementSHED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_TShEd(int Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementTSHED->AsInteger=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};



STDMETHODIMP TOleDMSprEdImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  DMSprEd->DeleteElement(glStrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::FindEdPoSh(BSTR ShtrihCod)
{ 
  try
  {
  DMSprEd->FindEdPoSh(ShtrihCod);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::get_CodeError(int* Value)
{
  try
  {
   *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprEd->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::GetGidElement(BSTR Id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprEd->GetGIDElement(glStrToInt64(Id)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::GetIdElement(BSTR gid, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprEd->GetIDElement(gid)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::NewElement(BSTR IdNom)
{ 
  try
  {
  DMSprEd->NewElement(glStrToInt64(IdNom));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::NewShtrihCod()
{
  try
  {
  DMSprEd->NewShtrihCod();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::OpenElement(BSTR Id)
{ 
  try
  {
  DMSprEd->OpenElement(glStrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::OpenTable(BSTR IdNom)
{ 
  try
  {
  DMSprEd->OpenTable(glStrToInt64(IdNom));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::SaveElement()
{
  try
  {
  if (DMSprEd->SaveElement()==true)
  	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprEd->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::TableFirst()
{
  try
  {
  DMSprEd->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprEdImpl::TableNext()
{
  try
  {
  DMSprEd->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
}

 