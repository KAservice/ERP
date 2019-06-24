// OLEDMDOCOSTNOMIMPL : Implementation of TOleDMDocOstNomImpl (CoClass: OleDMDocOstNom, Interface: IOleDMDocOstNom)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCOSTNOMIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocOstNomImpl
STDMETHODIMP TOleDMDocOstNomImpl::AddDocNewString()
{
  try
  {
  doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::CancelDvRegDoc()
{
  try
  {
  doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::CloseDoc()
{
  try
  {
  doc->CloseDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::DeleteDoc(BSTR Id)
{ 
  try
  {
  doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::DeleteStringDoc()
{
  try
  {
  doc->DeleteStringDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;

}

STDMETHODIMP TOleDMDocOstNomImpl::DvRegDoc()
{
  try
  {
  doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllFNAMEUSER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllFNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDUSERDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
   *Value=doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
  *Value=doc->DocAllSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocGID_DOSN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocGID_DOSN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocIDDOCOSN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDDOCOSN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocIDOCN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDOSN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocIDTPRICEOSN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDTPRICEOSN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocNAME_TPRICE(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocNAME_TPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocPRIMOSN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocPRIMOSN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTGID_DOSNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTGID_DOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTIDDOCOSNT(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTIDDOCOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTIDEDOSNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDEDOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTIDNOMOSNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDNOMOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTIDOSNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTIDPARTOSNT(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTIDPARTOSNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTKFOSNT(double* Value)
{
  try
  {
  *Value=doc->DocTKFOSNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTKOLOSNT(double* Value)
{
  try
  {
  *Value=doc->DocTKOLOSNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTPRICEOSNT(double* Value)
{
  try
  {
  *Value=doc->DocTPRICEOSNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_DocTSUMOSNT(double* Value)
{
  try
  {
  *Value=doc->DocTSUMOSNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_TableEOF(int* Value)
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
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_TextError(BSTR* Value)
{
  try
  {
   *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::NewDoc()
{
  try
  {
  doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::OpenDoc(BSTR IdDoc)
{ 
  try
  {
  doc->OpenDoc(StrToInt64(IdDoc));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::SaveDoc()
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
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllGID_DOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDUSERDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDUSERDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllNUMDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllPRDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPRDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllSUMDOC->AsFloat=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllTDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocGID_DOSN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocGID_DOSN->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocIDDOCOSN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDDOCOSN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocIDOCN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDOSN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocIDTPRICEOSN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDTPRICEOSN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocPRIMOSN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocPRIMOSN->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTGID_DOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTGID_DOSNT->AsString=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTIDDOCOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDDOCOSNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTIDEDOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDEDOSNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTIDNOMOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDNOMOSNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTIDOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDOSNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTIDPARTOSNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDPARTOSNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTKFOSNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKFOSNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTKOLOSNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLOSNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTPRICEOSNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTPRICEOSNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTSUMOSNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTSUMOSNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::GetIdDocPoNomeruDoc(int number_doc,
  DATE date_doc, BSTR* id_doc)
{ 
  try
  {
  *id_doc=WideString(IntToStr(doc->GetIDDocPoNomeruDoc(number_doc,date_doc)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::TableFirst()
{
  try
  {
  doc->DocT->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::TableNext()
{
  try
  {
  doc->DocT->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocOstNomImpl::get_DocTTNOM(int* Value)
{
  try
  {
  *Value=doc->DocTTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocTTNOM(int Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTTNOM->AsInteger=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_NameBase(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::get_PrefiksDoc(BSTR* Value)
{
  try
  {
  *Value="";//WideString(doc->DocAllPREFIKSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
//  doc->DocAll->Edit();
//  doc->DocAllPREFIKSDOC->AsString=Value;
//  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocOstNomImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
    *Value=WideString(doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocOstNomImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDBASE_GALLDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocOstNom);
  }
  return S_OK;
};



