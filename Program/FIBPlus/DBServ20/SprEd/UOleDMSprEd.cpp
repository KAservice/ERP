 // 1.1
// UNIT1 : Implementation of TOleDMSprEdImpl (CoClass: OleDMSprEd, Interface: IOleDMSprEd)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprEd.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprEdImpl
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


STDMETHODIMP TOleDMSprEdImpl::OpenTable(BSTR id_nom)
{ 
  try
  {
  DMSprEd->OpenTable(glStrToInt64(id_nom));
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


STDMETHODIMP TOleDMSprEdImpl::NewElement(BSTR id_nom, int* result)
{ 
  try
  {
  *result=DMSprEd->NewElement(glStrToInt64(id_nom));
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

STDMETHODIMP TOleDMSprEdImpl::SaveElement(int* result)
{ 
  try
  {
  *result=DMSprEd->SaveElement();
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

STDMETHODIMP TOleDMSprEdImpl::FindEdPoSh(BSTR sh, BSTR* result)
{
  try
  {
  *result=WideString(IntToStr(DMSprEd->FindEdPoSh(sh)).c_str()).c_bstr();;
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

STDMETHODIMP TOleDMSprEdImpl::GetGidElement(BSTR id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprEd->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();
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

STDMETHODIMP TOleDMSprEdImpl::GetIdElement(BSTR gid, BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(DMSprEd->GetIDElement(gid)).c_str()).c_bstr();
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

STDMETHODIMP TOleDMSprEdImpl::get_TableEof(int* Value)
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


STDMETHODIMP TOleDMSprEdImpl::TableFirst()
{
  try
  {
  DMSprEd->Table->First();
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

STDMETHODIMP TOleDMSprEdImpl::TableNext()
{
  try
  {
  DMSprEd->Table->Next();
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

STDMETHODIMP TOleDMSprEdImpl::get_TableCODE_SED(int* Value)
{
  try
  {
  *Value=DMSprEd->TableCODE_SED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableGID_SED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->TableGID_SED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableIDED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->TableIDED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableIDNOMED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->TableIDNOMED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableIDOKEIED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->TableIDOKEIED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableKFED(double* Value)
{
  try
  {
  *Value=DMSprEd->TableKFED->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->TableNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableSHED(BSTR* Value)
{
  try
  {
   *Value=WideString(DMSprEd->TableSHED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_TableTSHED(int* Value)
{
  try
  {
  *Value=DMSprEd->TableTSHED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_ElementCODE_SED(int* Value)
{
  try
  {
  *Value=DMSprEd->ElementCODE_SED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_ElementGID_SED(BSTR* Value)
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


STDMETHODIMP TOleDMSprEdImpl::get_ElementIDED(BSTR* Value)
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


STDMETHODIMP TOleDMSprEdImpl::get_ElementIDOKEIED(BSTR* Value)
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


STDMETHODIMP TOleDMSprEdImpl::get_ElementKFED(double* Value)
{
  try
  {
  *Value=DMSprEd->ElementGID_SED->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_ElementNAMEED(BSTR* Value)
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


STDMETHODIMP TOleDMSprEdImpl::get_ElementNAMEOKEI(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprEd->ElementNAMEOKEI->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::get_ElementSHED(BSTR* Value)
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


STDMETHODIMP TOleDMSprEdImpl::get_ElementTSHED(int* Value)
{
  try
  {
  *Value=DMSprEd->ElementGID_SED->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ElementCODE_SED(int Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementCODE_SED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ElementGID_SED(BSTR Value)
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


STDMETHODIMP TOleDMSprEdImpl::set_ElementIDED(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementIDED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ElementIDOKEIED(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementIDOKEIED->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ElementKFED(double Value)
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


STDMETHODIMP TOleDMSprEdImpl::set_ElementNAMEED(BSTR Value)
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


STDMETHODIMP TOleDMSprEdImpl::set_ElementNAMEOKEI(BSTR Value)
{
  try
  {
  DMSprEd->Element->Edit();
  DMSprEd->ElementNAMEOKEI->AsString=Value;
  DMSprEd->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprEd);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprEdImpl::set_ElementSHED(BSTR Value)
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


STDMETHODIMP TOleDMSprEdImpl::set_ElementTSHED(int Value)
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


STDMETHODIMP TOleDMSprEdImpl::OpenElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprEd->OpenElement(glStrToInt64(id));
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

STDMETHODIMP TOleDMSprEdImpl::DeleteElement(BSTR id, int* result)
{ 
  try
  {
  *result=DMSprEd->DeleteElement(glStrToInt64(id));
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

