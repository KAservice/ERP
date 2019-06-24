// OLEDMDOCPRIHNAKLIMPL : Implementation of TOleDMDocPrihNaklImpl (CoClass: OleDMDocPrihNakl, Interface: IOleDMDocPrihNakl)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCPRIHNAKLIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocPrihNaklImpl
STDMETHODIMP TOleDMDocPrihNaklImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllFNAMEUSER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllFNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDUSERDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
*Value=doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
*Value=doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
*Value=doc->DocAllSUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocGID_DPRN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocGID_DPRN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocIDDOCPRN(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocIDDOCPRN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocIDPRN(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocIDPRN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocIDTPRICE(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocIDTPRICE->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocPRIMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocPRIMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTGID_DPRNT(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocTGID_DPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTIDDOCPRNT(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocTIDDOCPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTIDEDPRNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDEDPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTIDNOMPRNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDNOMPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTIDPARTPRNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDPARTPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTIDPRNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDPRNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTKFPRNT(double* Value)
{
  try
  {
  *Value=doc->DocTKFPRNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTKOLPRNT(double* Value)
{
  try
  {
  *Value=doc->DocTKOLPRNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTPRICEPRNT(double* Value)
{
  try
  {
  *Value=doc->DocTPRICEPRNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocTSUMPRNT(double* Value)
{
  try
  {
    *Value=doc->DocTSUMPRNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_TableEOF(int* Value)
{
  try
  {
  if (doc->DocT->Eof)
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
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllFNAMEUSER(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllFNAME_USER->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllGID_DOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDUSERDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDUSERDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllNUMDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllPRDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPRDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllSUMDOC->AsFloat=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllTDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocGID_DPRN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocGID_DPRN->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocIDDOCPRN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDDOCPRN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocIDPRN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDPRN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocIDTPRICE(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDTPRICE->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocPRIMDOC(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocPRIMDOC->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTGID_DPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTGID_DPRNT->AsString=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTIDDOCPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDDOCPRNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTIDEDPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDEDPRNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTIDNOMPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDNOMPRNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTIDPARTPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDPARTPRNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTIDPRNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDPRNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTKFPRNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKFPRNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTKOLPRNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLPRNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTPRICEPRNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTPRICEPRNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocTSUMPRNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTSUMPRNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::AddDocNewString()
{
  try
  {
  doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::CancelDvRegDoc()
{
  try
  {
  doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::DeleteDoc(BSTR Id)
{ 
  try
  {
  doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::DeleteStringDoc()
{
  try
  {
  doc->DeleteStringDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::DvRegDoc()
{
  try
  {
  doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::GetIdDocPoNomeruDoc(int number_doc,
  DATE date_doc, BSTR* id_doc)
{ 
  try
  {
  *id_doc=WideString(IntToStr(doc->GetIDDocPoNomeruDoc(number_doc, date_doc)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::NewDoc()
{
  try
  {
  doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::OpenDoc(BSTR IdDoc)
{ 
  try
  {
  doc->OpenDoc(StrToInt64(IdDoc));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::SaveDoc()
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
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::TableFirst()
{
  try
  {
  doc->DocT->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::TableNext()
{
  try
  {
  doc->DocT->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocPrihNaklImpl::get_PrefiksDoc(BSTR* Value)
{
  try
  {
  *Value="";//WideString(doc->DocAllPREFIKSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
//  doc->DocAll->Edit();
//  doc->DocAllPREFIKSDOC->AsString=Value;
//  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocPrihNaklImpl::get_NameBase(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};





STDMETHODIMP TOleDMDocPrihNaklImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
	*Value=WideString(doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocPrihNaklImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDBASE_GALLDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocPrihNakl);
  }
  return S_OK;
};



