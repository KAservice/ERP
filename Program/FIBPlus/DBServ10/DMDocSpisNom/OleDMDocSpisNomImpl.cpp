// OLEDMDOCSPISNOMIMPL : Implementation of TOleDMDocSpisNomImpl (CoClass: OleDMDocSpisNom, Interface: IOleDMDocSpisNom)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCSPISNOMIMPL.H"
#include "UDMDocSpisNom.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMDocSpisNomImpl
STDMETHODIMP TOleDMDocSpisNomImpl::AddDocNewString()
{
  try
  {
   doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::CancelDvRegDoc()
{
  try
  {
   doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::CloseDoc()
{
  try
  {
   doc->CloseDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::DeleteDoc(BSTR Id)
{ 
  try
  {
   doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::DeleteStringDoc()
{
  try
  {
   doc->DeleteStringDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::DvRegDoc()
{
  try
  {
   doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
    *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
  *Value=doc->DocAllSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocGID_DSPN(BSTR* Value)
{
  try
  {
*Value=WideString(doc->DocGID_DSPN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocIDDOCSPN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDDOCSPN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocIDSPN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocIDSPN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocPRIMSPN(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocPRIMSPN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTGID_DSPNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTGID_DSPNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTIDDOCSPNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDDOCSPNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTIDEDSPNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDEDSPNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTIDNOMSPNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDNOMSPNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTIDSPNT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDSPNT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTKFSPNT(double* Value)
{
  try
  {
   *Value=doc->DocTKFSPNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTKOLSPNT(double* Value)
{
  try
  {
   *Value=doc->DocTKOLSPNT->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTPRICESPNT(double* Value)
{
  try
  {
  *Value=doc->DocTPRICESPNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_DocTSUMSPNT(double* Value)
{
  try
  {
  *Value=doc->DocTSUMSPNT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_TableEOF(int* Value)
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
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::NewDoc()
{
  try
  {
  doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::OpenDoc(BSTR IdDoc)
{ 
  try
  {
  doc->OpenDoc(StrToInt64(IdDoc));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::SaveDoc()
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
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllGID_DOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllNUMDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllPRDOC(int Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPRDOC->AsInteger=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllSUMDOC->AsFloat=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllTDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocGID_DSPN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocGID_DSPN->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocIDDOCSPN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocIDDOCSPN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocIDSPN(BSTR Value)
{
  try
  {
   doc->Doc->Edit();
  doc->DocIDSPN->AsInt64=StrToInt64(Value);
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocPRIMSPN(BSTR Value)
{
  try
  {
  doc->Doc->Edit();
  doc->DocPRIMSPN->AsString=Value;
  doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTGID_DSPNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTGID_DSPNT->AsString=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTIDDOCSPNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDDOCSPNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTIDEDSPNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDEDSPNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTIDNOMSPNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDNOMSPNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTIDSPNT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDSPNT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTKFSPNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKFSPNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTKOLSPNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLSPNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTPRICESPNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTPRICESPNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocTSUMSPNT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTSUMSPNT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::TableFirst()
{
  try
  {
  doc->DocT->First();

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::TableNext()
{
  try
  {
  doc->DocT->Next();

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocSpisNomImpl::get_NameBase(BSTR* Value)
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


STDMETHODIMP TOleDMDocSpisNomImpl::get_PrefiksDoc(BSTR* Value)
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


STDMETHODIMP TOleDMDocSpisNomImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
//  doc->DocAll->Edit();
//  doc->DocAllPREFIKSDOC->AsString=Value;
//  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocSpisNomImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
    *Value=WideString(doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocSpisNomImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDBASE_GALLDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocSpisNom);
  }
  return S_OK;
};



