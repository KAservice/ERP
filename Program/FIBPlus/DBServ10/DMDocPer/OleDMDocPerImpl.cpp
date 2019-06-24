// OLEDMDOCPERIMPL : Implementation of TOleDMDocPerImpl (CoClass: OleDMDocPer, Interface: IOleDMDocPer)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCPERIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocPerImpl
STDMETHODIMP TOleDMDocPerImpl::AddDocNewString()
{
  try
  {
  doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::CancelDvRegDoc()
{
  try
  {
  doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::CloseDoc()
{
  try
  {
  doc->CloseDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::DeleteDoc(BSTR Id)
{ 
  try
  {
  doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::DeleteStringDoc()
{
  try
  {
  doc->DeleteStringDoc() ;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::DvRegDoc()
{
  try
  {
  doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllFNAMEUSER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllFNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDUSERDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
    *Value=doc->DocAllSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocGID_DPER(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocGID_DPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocIDDOCPER(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocIDDOCPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocIDPER(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocIDPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocIDSKLPOLPER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDSKLPOLPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocPRIMPER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocPRIMPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTGID_DPERT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocGID_DPER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTIDDOCPERT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDDOCPERT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTIDEDPERT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDEDPERT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTIDNOMPERT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDNOMPERT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTIDPERT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDPERT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTKFPERT(double* Value)
{
  try
  {
  *Value=doc->DocTKFPERT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTKOLPERT(double* Value)
{
  try
  {
  *Value=doc->DocTKOLPERT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTPRICEPERT(double* Value)
{
  try
  {
  *Value=doc->DocTPRICEPERT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTSUMPERT(double* Value)
{
  try
  {
  *Value=doc->DocTSUMPERT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_DocTTNOM(int* Value)
{
  try
  {
  *Value=doc->DocTTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_TableEOF(int* Value)
{
  try
  {
  if(doc->DocT->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::GetIdDocPoNomeruDoc(int number_doc,
  BSTR date_doc, BSTR* IdDoc)
{ 
  try
  {
  *IdDoc=WideString(IntToStr(doc->GetIDDocPoNomeruDoc(number_doc,StrToDate(date_doc))).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::NewDoc()
{
  try
  {
  doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::OpenDoc(BSTR IdDoc)
{ 
  try
  {
  doc->OpenDoc(StrToInt64(IdDoc));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::SaveDoc()
{
  try
  {
    if (doc->SaveDoc()==true)
    {
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=doc->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPerImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllGID_DOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDUSERDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDUSERDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllNUMDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllPRDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPRDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllSUMDOC->AsFloat=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllTDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocGID_DPER(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocGID_DPER->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocIDDOCPER(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDDOCPER->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocIDPER(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDPER->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocIDSKLPOLPER(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDSKLPOLPER->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocPRIMPER(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocPRIMPER->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTGID_DPERT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTGID_DPERT->AsString=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTIDDOCPERT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDDOCPERT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTIDEDPERT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDEDPERT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTIDNOMPERT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDNOMPERT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTIDPERT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDPERT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTKFPERT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKFPERT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTKOLPERT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLPERT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTPRICEPERT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTPRICEPERT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocTSUMPERT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTSUMPERT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};

STDMETHODIMP TOleDMDocPerImpl::TableFirst()
{
  try
  {
  doc->DocT->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};

STDMETHODIMP TOleDMDocPerImpl::TableNext()
{
  try
  {
  doc->DocT->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};

STDMETHODIMP TOleDMDocPerImpl::get_NameBase(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::get_PrefiksDoc(BSTR* Value)
{
  try
  {
  *Value="";//WideString(doc->DocAllPREFIKSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
  //doc->DocAll->Edit();
  //doc->DocAllPREFIKSDOC->AsString="";//Value;
  //doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};

STDMETHODIMP TOleDMDocPerImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPerImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDBASE_GALLDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPer);
  }
  return S_OK;
};



