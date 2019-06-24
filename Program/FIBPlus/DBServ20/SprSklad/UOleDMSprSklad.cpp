 // 1.1
// UNIT1 : Implementation of TOleDMSprSkladImpl (CoClass: OleDMSprSklad, Interface: IOleDMSprSklad)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMSprSklad.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprSkladImpl
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


STDMETHODIMP TOleDMSprSkladImpl::OpenTable()
{
  try
  {
  DMSprSklad->OpenTable();
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

STDMETHODIMP TOleDMSprSkladImpl::OpenElement(BSTR id, int* result)
{
  try
  {
  *result=DMSprSklad->OpenElement(glStrToInt64(id));
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

STDMETHODIMP TOleDMSprSkladImpl::NewElement()
{
  try
  {
  DMSprSklad->NewElement();
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

STDMETHODIMP TOleDMSprSkladImpl::SaveElement()
{
  try
  {
  if (DMSprSklad->SaveElement()==true)
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
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprSkladImpl::GetGidElement(BSTR id, BSTR* gid)
{
  try
  {
  *gid=WideString(DMSprSklad->GetGIDElement(glStrToInt64(id)).c_str()).c_bstr();;
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

STDMETHODIMP TOleDMSprSkladImpl::GetIdElement(BSTR gid, BSTR* id)
{
  try
  {
  *id=WideString(IntToStr(DMSprSklad->GetIDElement(gid)).c_str()).c_bstr();;
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

STDMETHODIMP TOleDMSprSkladImpl::DeleteElement(BSTR id)
{
  try
  {
  DMSprSklad->DeleteElement(glStrToInt64(id));
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

STDMETHODIMP TOleDMSprSkladImpl::get_TableADRSKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_TableEof(int* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_TableGID_SSKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->TableGID_SSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprSkladImpl::get_TableIDSKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->TableIDSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprSkladImpl::get_TableMOLSKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->TableMOLSKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprSkladImpl::get_TableNAMESKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprSklad->TableNAMESKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprSkladImpl::get_TableTSklad(int* Value)
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

STDMETHODIMP TOleDMSprSkladImpl::get_ElementADRSKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_ElementGID_SSKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_ElementIDSKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_ElementMOLSKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_ElementNAMESKLAD(BSTR* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::get_ElementTSKLAD(int* Value)
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


STDMETHODIMP TOleDMSprSkladImpl::set_ElementADRSKLAD(BSTR Value)
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


STDMETHODIMP TOleDMSprSkladImpl::set_ElementGID_SSKLAD(BSTR Value)
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


STDMETHODIMP TOleDMSprSkladImpl::set_ElementIDSKLAD(BSTR Value)
{
  try
  {
  DMSprSklad->Element->Edit();
  DMSprSklad->ElementIDSKLAD->AsString=Value;
  DMSprSklad->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprSklad);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprSkladImpl::set_ElementMOLSKLAD(BSTR Value)
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


STDMETHODIMP TOleDMSprSkladImpl::set_ElementNAMESKLAD(BSTR Value)
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


STDMETHODIMP TOleDMSprSkladImpl::set_ElementTSKLAD(int Value)
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


