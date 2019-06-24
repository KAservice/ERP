 // 1.1
// UNIT1 : Implementation of TOleDMSprFirmImpl (CoClass: OleDMSprFirm, Interface: IOleDMSprFirm)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprFirm.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprFirmImpl
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


STDMETHODIMP TOleDMSprFirmImpl::OpenTable()
{
  try
  {
  DMSprFirm->OpenTable();
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

STDMETHODIMP TOleDMSprFirmImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprFirm->OpenElement(glStrToInt64(id));
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

STDMETHODIMP TOleDMSprFirmImpl::NewElement()
{
  try
  {
  DMSprFirm->NewElement();
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

STDMETHODIMP TOleDMSprFirmImpl::SaveElement(int* result)
{ 
  try
  {
  if (DMSprFirm->SaveElement()==true)
	{
	*result=1;
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	*result=0;
	CodeError=1;
	TextError=DMSprFirm->TextError;
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

STDMETHODIMP TOleDMSprFirmImpl::DeleteElement(BSTR id)
{ 
  try
  {
  DMSprFirm->DeleteElement(glStrToInt64(id));
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

STDMETHODIMP TOleDMSprFirmImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprFirm->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
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

STDMETHODIMP TOleDMSprFirmImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprFirm->GetIDElement(gid)).c_str()).c_bstr();
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

STDMETHODIMP TOleDMSprFirmImpl::get_TableIDFIRM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->TableIDFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::get_TableINNFIRM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->TableINNFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::get_TableNAMEFIRM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprFirm->TableNAMEFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::get_ElementIDFIRM(BSTR* Value)
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


STDMETHODIMP TOleDMSprFirmImpl::get_ElementINNFIRM(BSTR* Value)
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


STDMETHODIMP TOleDMSprFirmImpl::get_ElementNAMEFIRM(BSTR* Value)
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


STDMETHODIMP TOleDMSprFirmImpl::get_TableEof(int* Value)
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


STDMETHODIMP TOleDMSprFirmImpl::set_ElementIDFIRM(BSTR Value)
{
  try
  {
  DMSprFirm->Element->Edit();
  DMSprFirm->ElementIDFIRM->AsString=Value;
  DMSprFirm->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::set_ElementINNFIRM(BSTR Value)
{
  try
  {
  DMSprFirm->Element->Edit();
  DMSprFirm->ElementINNFIRM->AsString=Value;
  DMSprFirm->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::set_ElementNAMEFIRM(BSTR Value)
{
  try
  {
  DMSprFirm->Element->Edit();
  DMSprFirm->ElementNAMEFIRM->AsString=Value;
  DMSprFirm->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::TableFirst()
{
  try
  {
  DMSprFirm->Table->First();
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

STDMETHODIMP TOleDMSprFirmImpl::TableNext()
{
  try
  {
  DMSprFirm->Table->Next();
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

STDMETHODIMP TOleDMSprFirmImpl::get_ElementGID_SFIRM(BSTR* Value)
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


STDMETHODIMP TOleDMSprFirmImpl::get_TableGID_SFIRM(BSTR* Value)
{
  try
  {
  //*Value=WideString(DMSprFirm->TableGIDIDFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprFirmImpl::set_ElementGID_SFIRM(BSTR Value)
{
  try
  {
  DMSprFirm->Element->Edit();
  DMSprFirm->ElementGID_SFIRM->AsString=Value;
  DMSprFirm->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprFirm);
  }
  return S_OK;
};


