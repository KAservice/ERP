// OLEDMDOCINVIMPL : Implementation of TOleDMDocInvImpl (CoClass: OleDMDocInv, Interface: IOleDMDocInv)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCINVIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocInvImpl
STDMETHODIMP TOleDMDocInvImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllFNAMEUSER(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllFNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllIDUSERDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocAllIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
  *Value=doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",doc->DocAllPOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
    *Value=doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};




STDMETHODIMP TOleDMDocInvImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
    *Value=doc->DocAllSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocGID_INV(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocGID_INV->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocID_INV(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocID_INV->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocIDDOC_INV(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocIDDOC_INV->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocPRIM_INV(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocPRIM_INV->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTGID_INVT(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTGID_INVT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTID_INVT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTID_INVT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTIDDOC_INVT(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTIDDOC_INVT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTIDED_INVT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDED_INVT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTIDNOM_INVT(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTIDNOM_INVT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTKF_INVT(double* Value)
{
  try
  {
  *Value=doc->DocTKF_INVT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTKOLFAKT_INVT(double* Value)
{
  try
  {
  *Value=doc->DocTKOLFAKT_INVT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTKOLUCH_INVT(double* Value)
{
  try
  {
  *Value=doc->DocTKOLUCH_INVT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
   *Value=WideString(doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_TableEOF(int* Value)
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
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_TextError(BSTR* Value)
{
  try
  {
   *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllGID_DOC->AsString=Value;
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllIDUSERDOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllIDUSERDOC->AsInt64=StrToInt64(Value);
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllNUMDOC->AsInteger=Value;
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllPRDOC(int Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllPRDOC->AsInteger=Value;
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};




STDMETHODIMP TOleDMDocInvImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllSUMDOC->AsFloat=Value;
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
   doc->DocAll->Edit();
   doc->DocAllTDOC->AsString=Value;
   doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocGID_INV(BSTR Value)
{
  try
  {
   doc->Doc->Edit();
   doc->DocGID_INV->AsString=Value;
   doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocID_INV(BSTR Value)
{
  try
  {
   doc->Doc->Edit();
   doc->DocID_INV->AsInt64=StrToInt64(Value);
   doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocIDDOC_INV(BSTR Value)
{
  try
  {
   doc->Doc->Edit();
   doc->DocIDDOC_INV->AsInt64=StrToInt64(Value);
   doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocPRIM_INV(BSTR Value)
{
  try
  {
   doc->Doc->Edit();
   doc->DocPRIM_INV->AsString=Value;
   doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTGID_INVT(BSTR Value)
{
  try
  {
   doc->DocT->Edit();
   doc->DocTGID_INVT->AsString=Value;
   doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTID_INVT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTID_INVT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTIDDOC_INVT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDDOC_INVT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTIDED_INVT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDED_INVT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTIDNOM_INVT(BSTR Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTIDNOM_INVT->AsInt64=StrToInt64(Value);
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTKF_INVT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKF_INVT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTKOLFAKT_INVT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLFAKT_INVT->AsFloat=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocTKOLUCH_INVT(double Value)
{
  try
  {
  doc->DocT->Edit();
  doc->DocTKOLUCH_INVT->AsInteger=Value;
  doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::AddDocNewString()
{
  try
  {
  doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::CancelDvRegDoc()
{
  try
  {
  doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::DeleteDoc(BSTR Id)
{
  try
  {
  doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;

}

STDMETHODIMP TOleDMDocInvImpl::DeleteStringDoc()
{
  try
  {
  doc->DeleteStringDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::DvRegDoc()
{
  try
  {
  doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::GetIdDocPoNomeruDoc(int number_doc,
  DATE date_doc, BSTR* id_doc)
{ 
  try
  {
  *id_doc=WideString(IntToStr(doc->GetIDDocPoNomeruDoc(number_doc, date_doc)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::NewDoc()
{
  try
  {
  doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::OpenDoc(BSTR IdDoc)
{ 
  try
  {
  doc->OpenDoc(StrToInt64(IdDoc));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::SaveDoc()
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
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::TableFirst()
{
  try
  {
  doc->DocT->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::TableNext()
{
  try
  {
  doc->DocT->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocInvImpl::get_NameBase(BSTR* Value)
{
  try
  {
  *Value=WideString(doc->DocAllNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::get_PrefiksDoc(BSTR* Value)
{
  try
  {
  *Value="";//WideString(doc->DocAllPREFIKSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
//  doc->DocAll->Edit();
//  doc->DocAllPREFIKSDOC->AsString=Value;
//  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocInvImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
    *Value=WideString(doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocInvImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  doc->DocAll->Edit();
  doc->DocAllIDBASE_GALLDOC->AsString=Value;
  doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocInv);
  }
  return S_OK;
};



