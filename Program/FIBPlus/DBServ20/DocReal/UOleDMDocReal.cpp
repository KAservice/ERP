 // 1.1
// UNIT1 : Implementation of TOleDMDocRealImpl (CoClass: OleDMDocReal, Interface: IOleDMDocReal)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMDocReal.h"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocRealImpl
STDMETHODIMP TOleDMDocRealImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::NewDoc()
{
  try
  {
  Doc->NewDoc();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::OpenDoc(BSTR id)
{ 
  try
  {
  Doc->OpenDoc(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::SaveDoc(int* result)
{ 
  try
  {
  *result=Doc->SaveDoc();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::CloseDoc()
{
  try
  {
  Doc->CloseDoc();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::DeleteDoc(BSTR id, int* result)
{ 
  try
  {
  *result=Doc->DeleteDoc(glStrToInt64(id));
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::DocTFirst()
{
  try
  {
  Doc->DocT->First();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::DocTNext()
{
  try
  {
  Doc->DocT->Next();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::get_DocTEof(int* Value)
{
  try
  {
  if (Doc->DocT->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::GetIdDoc(int number_doc, BSTR date_doc,
  BSTR* id)
{ 
  try
  {
  *id=WideString(IntToStr(Doc->GetIDDocPoNomeruDoc(number_doc,StrToDate(date_doc))).c_str()).c_bstr();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMSprTypePrice);
  }
  return S_OK;
}


STDMETHODIMP TOleDMDocRealImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
  *Value=Doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",Doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
  *Value=Doc->DocAllNUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDBASE_GALLDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDFIRMDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDKLDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDSKLDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllNUMDOC->AsInteger=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllSUMDOC->AsFloat=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllTDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocRealImpl::get_DocIDBSCHETREA(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocIDBSCHETREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocIDDOCREA(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocIDDOCREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocIDGRPOLREA(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocIDGRPOLREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocIDREA(BSTR* Value)
{
  try
  {
	*Value=WideString(Doc->DocIDREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocIDTPRICEREA(BSTR* Value)
{
  try
  {
*Value=WideString(Doc->DocIDTPRICEREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocPRIMREA(BSTR* Value)
{
  try
  {
*Value=WideString(Doc->DocPRIMREA->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocIDBSCHETREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDBSCHETREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocIDDOCREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDDOCREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocIDGRPOLREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDGRPOLREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocIDREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocIDTPRICEREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDTPRICEREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocPRIMREA(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocPRIMREA->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocRealImpl::get_DocTIDDOCREAT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDDOCREAT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTIDEDREAT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDEDREAT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTIDNOMREAT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDNOMREAT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTIDREAT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDDOCREAT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTKFREAT(double* Value)
{
  try
  {
  *Value=Doc->DocTKFREAT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTKOLREAT(double* Value)
{
  try
  {
  *Value=Doc->DocTKOLREAT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTPRICEREAT(double* Value)
{
  try
  {
  *Value=Doc->DocTPRICEREAT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::get_DocTSUMREAT(double* Value)
{
  try
  {
  *Value=Doc->DocTSUMREAT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTIDDOCREAT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDDOCREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTIDEDREAT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDEDREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTIDNOMREAT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDNOMREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTIDREAT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTKFREAT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTKFREAT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTKOLREAT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTKOLREAT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTPRICEREAT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTPRICEREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRealImpl::set_DocTSUMREAT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTSUMREAT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocRealImpl::DocTAppend()
{
  try
  {
  Doc->DocT->Append();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRealImpl::DocTDelete()
{
  try
  {
  Doc->DocT->Delete();
  CodeError=0;
  TextError="Ошибок нет";
  }
  catch(Exception &e)
  {
  CodeError=1;
  TextError=e.Message;
	return Error(e.Message.c_str(), IID_IOleDMDocReal);
  }
  return S_OK;
}


