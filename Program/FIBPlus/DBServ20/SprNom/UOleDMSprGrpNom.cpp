 // 1.1
// UNIT1 : Implementation of TOleDMSprGrpNomImpl (CoClass: OleDMSprGrpNom, Interface: IOleDMSprGrpNom)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprGrpNom.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprGrpNomImpl
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


STDMETHODIMP TOleDMSprGrpNomImpl::NewElement(BSTR id_grp)
{ 
  try
  {
  DMSprGrpNom->NewElement(glStrToInt64(id_grp));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::SaveElement(int* result)
{ 
  try
  {
  *result=DMSprGrpNom->SaveElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
  result=0;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprGrpNom->OpenElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::DeleteElement(BSTR id, int* result)
{
  try
  {
  *result=DMSprGrpNom->DeleteElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::OpenTable()
{
  try
  {
  DMSprGrpNom->OpenTable();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::get_TableEof(int* Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::TableFirst()
{
  try
  {
  DMSprGrpNom->Table->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::TableNext()
{
  try
  {
  DMSprGrpNom->Table->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprGrpNom->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprGrpNom->GetIDElement(gid)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprGrpNomImpl::get_TableGID_SGRPNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->TableGID_SGRPNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_TableIDGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->TableIDGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_TableIDGRPGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->TableIDGRPGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_TableNAMEGN(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprGrpNom->TableNAMEGN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElementIDGN(BSTR* Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElementIDGN(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementIDGN->AsString=Value;
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElementGID_SGRPNOM(BSTR* Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElementIDGRPGN(BSTR* Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::get_ElementNAMEGN(BSTR* Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElementGID_SGRPNOM(BSTR Value)
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


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElementIDGRPGN(BSTR Value)
{
  try
  {
  DMSprGrpNom->Element->Edit();
  DMSprGrpNom->ElementIDGRPGN->AsString=Value;
  DMSprGrpNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprGrpNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprGrpNomImpl::set_ElementNAMEGN(BSTR Value)
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


