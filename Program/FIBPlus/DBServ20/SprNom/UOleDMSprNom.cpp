 // 1.1
// UNIT1 : Implementation of TOleDMSprNomImpl (CoClass: OleDMSprNom, Interface: IOleDMSprNom)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprNom.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprNomImpl
STDMETHODIMP TOleDMSprNomImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::NewElement(BSTR id_grp, int* result)
{
  try
  {
  *result=DMSprNom->NewElement(glStrToInt64(id_grp));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprNom->OpenElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::SaveElement(int* result)
{ 
  try
  {
  *result=DMSprNom->SaveElement();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::DeleteElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprNom->DeleteElement(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::OpenTable(BSTR id_grp, int all)
{
  try
  {
  DMSprNom->OpenTable(glStrToInt64(id_grp),all);
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::get_TableEof(int* Value)
{
  try
  {
  if (DMSprNom->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprNom->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprNom->GetIDElement(gid)).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::TableFirst()
{
  try
  {
  DMSprNom->Table->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::TableNext()
{
  try
  {
  DMSprNom->Table->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::get_TableCODENOM(int* Value)
{
  try
  {
  *Value=DMSprNom->TableCODENOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TableIDGRPNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->TableIDGRPNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TableIDNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->TableIDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TableNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->TableNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TableNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->TableNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_TableTNOM(int* Value)
{
  try
  {
  *Value=DMSprNom->TableTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementARTNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementARTNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementCODENOM(int* Value)
{
  try
  {
  *Value=DMSprNom->ElementCODENOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementFNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementFNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementGID_SNOM(BSTR* Value)
{
  try
  {
   *Value=WideString(DMSprNom->ElementGID_SNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDBASEDNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDBASEDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDCOUNTRYNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDCOUNTRYNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDFIRMNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDFIRMNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDGRPNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDGRPNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDOSNEDNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDOSNEDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementIDVID_SNOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDVID_SNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementKRNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementKRNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementNAMENOM(BSTR* Value)
{
  try
  {
   *Value=WideString(DMSprNom->ElementNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementSTNDSNOM(double* Value)
{
  try
  {
   *Value=DMSprNom->ElementSTNDSNOM->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::get_ElementTNOM(int* Value)
{
  try
  {
   *Value=DMSprNom->ElementTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementARTNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementARTNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementCODENOM(int Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementCODENOM->AsInteger=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementFNAMENOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementFNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementGID_SNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementGID_SNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDBASEDNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDBASEDNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDCOUNTRYNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDCOUNTRYNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDFIRMNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDFIRMNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDGRPNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDGRPNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDOSNEDNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDOSNEDNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementIDVID_SNOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDVID_SNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementKRNAMENOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementKRNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementNAMENOM(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementSTNDSNOM(double Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementSTNDSNOM->AsFloat=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_ElementTNOM(int Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementTNOM->AsInteger=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


