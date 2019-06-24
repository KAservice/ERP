// OLEDMSPRINFBASEIMPL : Implementation of TOleDMSprInfBaseImpl (CoClass: OleDMSprInfBase, Interface: IOleDMSprInfBase)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRINFBASEIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprInfBaseImpl

STDMETHODIMP TOleDMSprInfBaseImpl::get_NameBase(BSTR* Value)
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


STDMETHODIMP TOleDMSprInfBaseImpl::get_PrefiksBase(BSTR* Value)
{
  try
  {
  //*Value=WideString(DMSprInfBase->TablePREFIKS_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
};



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


STDMETHODIMP TOleDMSprInfBaseImpl::get_TableEOF(int* Value)
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


STDMETHODIMP TOleDMSprInfBaseImpl::OpenTable()
{

  try
  {
  DMSprInfBase->OpenTable();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::TableFirst()
{

  try
  {
  DMSprInfBase->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::TableNext()
{

  try
  {
  DMSprInfBase->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprPrice);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprInfBaseImpl::GetIdPoName(BSTR name, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprInfBase->GetIdPoName(name)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMSprInfBase);
  }
  return S_OK;
}


