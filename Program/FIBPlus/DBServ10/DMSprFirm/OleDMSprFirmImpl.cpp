// OLEDMSPRFIRMIMPL : Implementation of TOleDMSprFirmImpl (CoClass: OleDMSprFirm, Interface: IOleDMSprFirm)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRFIRMIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprFirmImpl
STDMETHODIMP TOleDMSprFirmImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  DMSprFirm->DeleteElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::ElementEdit()
{
  try
  {
  DMSprFirm->Element->Edit();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::ElementPost()
{
  try
  {
  DMSprFirm->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_FNameNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementFNAMEFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_GID_Firm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementGID_SFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_IdFirm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementIDFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_INNFirm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementINNFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_KPPFirm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementKPPFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_NameFirm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->ElementNAMEFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_PAdrFirm(BSTR* Value)
{
  try
  {
    *Value=WideString(DMSprFirm->ElementPADRFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprFirm->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_TextError(BSTR* Value)
{
  try
  {
    *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::get_UAdrFirm(BSTR* Value)
{
  try
  {
    *Value=WideString(DMSprFirm->ElementUADRFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::GetGidElement(BSTR Id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprFirm->GetGIDElement(StrToInt64(Id)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::NewElement()
{
  try
  {
  DMSprFirm->NewElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::OpenElement(BSTR Id)
{ 
  try
  {
  DMSprFirm->OpenElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::OpenTable()
{
  try
  {
  DMSprFirm->OpenTable();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::SaveElement()
{
  try
  {
  DMSprFirm->SaveElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_FNameNom(BSTR Value)
{
  try
  {
  DMSprFirm->ElementFNAMEFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_GID_Firm(BSTR Value)
{
  try
  {
   DMSprFirm->ElementGID_SFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_IdFirm(BSTR Value)
{
  try
  {
   DMSprFirm->ElementIDFIRM->AsInt64=StrToInt64(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_INNFirm(BSTR Value)
{
  try
  {
   DMSprFirm->ElementINNFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_KPPFirm(BSTR Value)
{
  try
  {
  DMSprFirm->ElementKPPFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_NameFirm(BSTR Value)
{
  try
  {
  DMSprFirm->ElementNAMEFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_PAdrFirm(BSTR Value)
{
  try
  {
  DMSprFirm->ElementPADRFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//--------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::set_UAdrFirm(BSTR Value)
{
  try
  {
  DMSprFirm->ElementUADRFIRM->AsString=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::TableFirst()
{

  try
  {
  DMSprFirm->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprFirmImpl::TableNext()
{
  try
  {
  DMSprFirm->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
}

//-----------------------------------------------------------------------------