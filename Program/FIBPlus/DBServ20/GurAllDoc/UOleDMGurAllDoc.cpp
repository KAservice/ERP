 // 1.1
// UNIT1 : Implementation of TOleDMGurAllDocImpl (CoClass: OleDMGurAllDoc, Interface: IOleDMGurAllDoc)

#include <vcl.h>
#pragma hdrstop

#include "UOleDMGurAllDoc.h"



/////////////////////////////////////////////////////////////////////////////
// TOleDMGurAllDocImpl
STDMETHODIMP TOleDMGurAllDocImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TextError(BSTR* Value)
{
  try
  {
  *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_PosNach(BSTR* Value)
{
  try
  {
  *Value=WideString(DateTimeToStr(DMGurAllDoc->PosNach).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_PosNach(BSTR Value)
{
  try
  {
  DMGurAllDoc->PosNach=StrToDateTime(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_PosCon(BSTR* Value)
{
  try
  {
  *Value=WideString(DateTimeToStr(DMGurAllDoc->PosCon).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_PosCon(BSTR Value)
{
  try
  {
  DMGurAllDoc->PosCon=StrToDateTime(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_IdDoc(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_IdDoc(BSTR Value)
{
  try
  {

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_IdKlient(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_IdSklad(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_IdKlient(BSTR Value)
{
  try
  {
  DMGurAllDoc->IdKlient=StrToInt64(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_IdSklad(BSTR Value)
{
  try
  {
  DMGurAllDoc->IdSklad=StrToInt64(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_IdFirm(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_StringTypeDoc(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->StringTypeDoc.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_IdFirm(BSTR Value)
{
  try
  {
  DMGurAllDoc->IdFirm=StrToInt64(Value);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_StringTypeDoc(BSTR Value)
{
  try
  {
  DMGurAllDoc->StringTypeDoc=Value;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_OtborVkl(int* Value)
{
  try
  {
  if (DMGurAllDoc->OtborVkl==true)
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
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_OtborVkl(int Value)
{
  try
  {
  if (Value==1)
        {
         DMGurAllDoc->OtborVkl=true;
        }
  else
        {
        DMGurAllDoc->OtborVkl=false;
		}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_NoCheck(int* Value)
{
  try
  {
  if (DMGurAllDoc->NoCheck==true)
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
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::set_NoCheck(int Value)
{
  try
  {
  if (Value==1)
        {
		 DMGurAllDoc->NoCheck=true;
        }
  else
        {
		DMGurAllDoc->NoCheck=false;
		}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::OpenTable()
{
  try
  {
  DMGurAllDoc->OpenTable();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
}

STDMETHODIMP TOleDMGurAllDocImpl::get_TableEof(int* Value)
{
  try
  {
  if (DMGurAllDoc->Table->Eof==true)
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
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::UpdateTable()
{
  try
  {
  DMGurAllDoc->UpdateTable();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
}

STDMETHODIMP TOleDMGurAllDocImpl::TableFirst()
{
  try
  {
  DMGurAllDoc->Table->First();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
}

STDMETHODIMP TOleDMGurAllDocImpl::TableNext()
{
  try
  {
  DMGurAllDoc->Table->Next();
  }
  catch(Exception &e)
  {
	return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
}

STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDBASE_GALLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDBASE_GALLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDDOCOSNDOC(BSTR* Value)
{
  try
  {
   *Value=WideString(DMGurAllDoc->TableIDDOCOSNDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDDOGDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDDOGDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDFIRMDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDFIRMDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDSKLDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDSKLDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableIDUSERDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableIDUSERDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableNAME_USER(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableNAME_USER->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableNAMEFIRM(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableNAMEFIRM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableNAMEKLIENT(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableNAMEKLIENT->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableNAMESKLAD(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableNAMESKLAD->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableNUMDOC(int* Value)
{
  try
  {
  *Value=DMGurAllDoc->TableNUMDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TablePOSDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TablePOSDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TablePRDOC(int* Value)
{
  try
  {
  *Value=DMGurAllDoc->TablePRDOC->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableSUMDOC(double* Value)
{
  try
  {
  *Value=DMGurAllDoc->TableSUMDOC->AsFloat;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


STDMETHODIMP TOleDMGurAllDocImpl::get_TableTDOC(BSTR* Value)
{
  try
  {
  *Value=WideString(DMGurAllDoc->TableTDOC->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};


