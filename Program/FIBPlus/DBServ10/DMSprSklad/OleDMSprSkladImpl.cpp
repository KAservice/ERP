// OLEDMSPRSKLADIMPL : Implementation of TOleDMSprSkladImpl (CoClass: OleDMSprSklad, Interface: IOleDMSprSklad)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRSKLADIMPL.H"
#include "UDMSprSklad.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMSprSkladImpl

STDMETHODIMP TOleDMSprSkladImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  DMSprSklad->DeleteElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_AdrSklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->ElementADRSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_GID_Sklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->ElementGID_SSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_IdSklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->ElementIDSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_MolSklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->ElementMOLSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_NameSklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->ElementNAMESKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_TSklad(int* Value)
{
  try
  {
   *Value=DMSprSklad->ElementTSKLAD->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::GetGidElement(BSTR Id, BSTR* gid)
{
  try
  {
  *gid=WideString(DMSprSklad->GetGIDElement(StrToInt64(Id)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::GetIdElement(BSTR gid, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprSklad->GetIDElement(gid)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//----------------------------------------------------------------------------

STDMETHODIMP TOleDMSprSkladImpl::NewElement()
{
  try
  {
  DMSprSklad->NewElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::OpenElement(BSTR Id)
{ 
   try
  {
  DMSprSklad->OpenElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::SaveElement()
{
  try
  {
  if(DMSprSklad->SaveElement()==true)
  	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprSklad->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_AdrSklad(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementADRSKLAD->AsString=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_GID_Sklad(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementGID_SSKLAD->AsString=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_IdSklad(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementIDSKLAD->AsInt64=StrToInt64(Value);
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//-------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_MolSklad(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementMOLSKLAD->AsString=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//--------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_NameSklad(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementNAMESKLAD->AsString=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::set_TSklad(int Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementTSKLAD->AsInteger=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprSklad->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TOleDMSprSkladImpl::TableFirst()
{
  try
  {
  DMSprSklad->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::TableNext()
{
  try
  {

  DMSprSklad->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}


//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprSkladImpl::CloseElement()
{
  try
  {
  DMSprSklad->CloseElement();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}


