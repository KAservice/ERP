// OLEDMDOCREPKKMIMPL : Implementation of TOleDMDocRepKKMImpl (CoClass: OleDMDocRepKKM, Interface: IOleDMDocRepKKM)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMDOCREPKKMIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMDocRepKKMImpl

STDMETHODIMP TOleDMDocRepKKMImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllFNAME_USER(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllFNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllGID_DOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllGID_DOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDDOGDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDDOGDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDSKLDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocAllIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDUSERDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllNAME_SDOG(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocAllNAME_SDOG->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllNAMEFIRM(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocAllNAMEFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllNAMEKLIENT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllNAMEKLIENT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllNAMESKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllNAMESKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllNUMDOC(int* Value)
{
  try
  {
   *Value=Doc->DocAllNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllPOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllPOSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllPRDOC(int* Value)
{
  try
  {
  *Value=Doc->DocAllPRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllSUMDOC(double* Value)
{
  try
  {
  *Value=Doc->DocAllSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocDVREG_DREPKKM(int* Value)
{
  try
  {
  *Value=Doc->DocDVREG_DREPKKM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocGID_DREPKKM(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocGID_DREPKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocID_DREPKKM(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocID_DREPKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocIDDOC_DREPKKM(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocIDDOC_DREPKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocIDKKM_DREPKKM(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocIDKKM_DREPKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocNAD_DREPKKM(double* Value)
{
  try
  {
  *Value=Doc->DocNAD_DREPKKM->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocNAMEKKM(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocNAMEKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocNKL_DREPKKM(int* Value)
{
  try
  {
  *Value=Doc->DocNKL_DREPKKM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocOPLNAL_DREPKKM(double* Value)
{
  try
  {
  *Value=Doc->DocOPLNAL_DREPKKM->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocOPLPC_DREPKKM(double* Value)
{
  try
  {
  *Value=Doc->DocOPLPC_DREPKKM->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocPRIM_DREPKKM(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocPRIM_DREPKKM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocSK_DREPKKM(double* Value)
{
  try
  {
  *Value=Doc->DocSK_DREPKKM->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTGID_DREPKKMT(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocTGID_DREPKKMT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTID_DREPKKMT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTID_DREPKKMT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTIDDOC_DREPKKMT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDDOC_DREPKKMT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTIDED_DREPKKMT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDED_DREPKKMT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTIDNOM_DREPKKMT(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocTIDNOM_DREPKKMT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTKF_DREPKKMT(double* Value)
{
  try
  {
   *Value=Doc->DocTKF_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTKOL_DREPKKMT(double* Value)
{
  try
  {
   *Value=Doc->DocTKOL_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTNAD_REPKKMT(double* Value)
{
  try
  {
   *Value=Doc->DocTNAD_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTNAMEED(BSTR* Value)
{
  try
  {
   *Value=WideString(Doc->DocTNAMEED->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTNAMENOM(BSTR* Value)
{
  try
  {
    *Value=WideString(Doc->DocTNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTPRICE_DREPKKMT(double* Value)
{
  try
  {
  *Value=Doc->DocTPRICE_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTPRICEFULL_DREPKKMT(double* Value)
{
  try
  {
  *Value=Doc->DocTPRICEFULL_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTSK_DREPKKMT(double* Value)
{
  try
  {
  *Value=Doc->DocTSK_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTSUM_DREPKKMT(double* Value)
{
  try
  {
  *Value=Doc->DocTSUM_DREPKKMT->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_DocTTNOM(int* Value)
{
  try
  {
  *Value=Doc->DocTTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_TextError(BSTR* Value)
{
  try
  {
   *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllGID_DOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllGID_DOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDDOGDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDDOGDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDFIRMDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDFIRMDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDKLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDKLDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDSKLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDSKLDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDUSERDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDUSERDOC->AsInt64=StrToInt64(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllNUMDOC(int Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllNUMDOC->AsInteger=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllPOSDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllPOSDOC->AsDateTime=StrToDateTime(Value);
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllPRDOC(int Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllPRDOC->AsInteger=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllSUMDOC(double Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllSUMDOC->AsFloat=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllTDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllTDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocDVREG_DREPKKM(int Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocDVREG_DREPKKM->AsInteger=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocGID_DREPKKM(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocGID_DREPKKM->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocID_DREPKKM(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocID_DREPKKM->AsInt64=StrToInt64(Value);
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocIDDOC_DREPKKM(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDDOC_DREPKKM->AsInt64=StrToInt64(Value);
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocIDKKM_DREPKKM(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocIDKKM_DREPKKM->AsInt64=StrToInt64(Value);
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocNAD_DREPKKM(double Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocNAD_DREPKKM->AsFloat=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocNKL_DREPKKM(int Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocNKL_DREPKKM->AsInteger=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocOPLNAL_DREPKKM(double Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocOPLNAL_DREPKKM->AsFloat=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocOPLPC_DREPKKM(double Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocOPLPC_DREPKKM->AsFloat=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocPRIM_DREPKKM(BSTR Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocPRIM_DREPKKM->AsString=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocSK_DREPKKM(double Value)
{
  try
  {
  Doc->Doc->Edit();
  Doc->DocSK_DREPKKM->AsInteger=Value;
  Doc->Doc->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTGID_DREPKKMT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTGID_DREPKKMT->AsString=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTID_DREPKKMT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTID_DREPKKMT->AsInt64=StrToInt64(Value);
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTIDDOC_DREPKKMT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDDOC_DREPKKMT->AsInt64=StrToInt64(Value);
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTIDED_DREPKKMT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDED_DREPKKMT->AsInt64=StrToInt64(Value);
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTIDNOM_DREPKKMT(BSTR Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTIDNOM_DREPKKMT->AsInt64=StrToInt64(Value);
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTKF_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTKF_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTKOL_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTKOL_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTNAD_REPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTNAD_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTPRICE_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTPRICE_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTPRICEFULL_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTPRICEFULL_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTSK_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTSK_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocTSUM_DREPKKMT(double Value)
{
  try
  {
  Doc->DocT->Edit();
  Doc->DocTSUM_DREPKKMT->AsFloat=Value;
  Doc->DocT->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocRepKKMImpl::AddDocNewString()
{
  try
  {
  Doc->AddDocNewString();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::CancelDvRegDoc()
{
  try
  {
  Doc->CancelDvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::CloseDoc()
{
  try
  {
  Doc->CloseDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::DeleteDoc(BSTR Id)
{ 
  try
  {
  Doc->DeleteDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::DeleteStringDoc()
{
  try
  {
  Doc->DeleteStringDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::DvRegDoc()
{
  try
  {
  Doc->DvRegDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::get_TableEOF(int* Value)
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
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::NewDoc()
{
  try
  {
  Doc->NewDoc();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::OpenDoc(BSTR Id)
{ 
  try
  {
  Doc->OpenDoc(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::SaveDoc()
{
  try
  {
  if (Doc->SaveDoc()==true)
    {
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=Doc->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::TableFirst()
{
  try
  {
  Doc->DocT->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}

STDMETHODIMP TOleDMDocRepKKMImpl::TableNext()
{
  try
  {
  Doc->DocT->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
}


STDMETHODIMP TOleDMDocRepKKMImpl::get_NameBase(BSTR* Value)
{
  try
  {
  *Value=WideString(Doc->DocAllNAME_SINFBASE_OBMEN->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::get_PrefiksDoc(BSTR* Value)
{
  try
  {
  *Value="";//WideString(Doc->DocAllPREFIKSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_PrefiksDoc(BSTR Value)
{
  try
  {
//  Doc->DocAll->Edit();
//  Doc->DocAllPREFIKSDOC->AsString=Value;
//  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};



STDMETHODIMP TOleDMDocRepKKMImpl::get_DocAllIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
    *Value=WideString(Doc->DocAllIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};


STDMETHODIMP TOleDMDocRepKKMImpl::set_DocAllIDBASE_GALLDOC(BSTR Value)
{
  try
  {
  Doc->DocAll->Edit();
  Doc->DocAllIDBASE_GALLDOC->AsString=Value;
  Doc->DocAll->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMDocRepKKM);
  }
  return S_OK;
};



