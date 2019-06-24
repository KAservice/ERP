// OLEDMGURALLDOCIMPL : Implementation of TOleDMGurAllDocImpl (CoClass: OleDMGurAllDoc, Interface: IOleDMGurAllDoc)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMGURALLDOCIMPL.H"
#include "UDMGurAllDoc.h"

/////////////////////////////////////////////////////////////////////////////
// TOleDMGurAllDocImpl

STDMETHODIMP TOleDMGurAllDocImpl::FindDocPoIdDog(int iddogovor)
{ 
return S_OK;
}
//----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------

STDMETHODIMP TOleDMGurAllDocImpl::get_IdFirmDoc(BSTR* Value)
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
//------------------------------------------------------------------------------

STDMETHODIMP TOleDMGurAllDocImpl::get_IdKlDoc(BSTR* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_IdSklDoc(BSTR* Value)
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

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_IdUserDoc(BSTR* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_NameFirm(BSTR* Value)
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

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_NameKlient(BSTR* Value)
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

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_NameSklad(BSTR* Value)
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

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_NameUser(BSTR* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_NumDoc(int* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_PosDoc(BSTR* Value)
{
  try
  {
  *Value=WideString(FormatDateTime("dd.mm.yyyy hh\":\"nn\":\"ss",DMGurAllDoc->TablePOSDOC->AsDateTime).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_PrDoc(int* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_SumDoc(double* Value)
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

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_TableEOF(int* Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::get_TDoc(BSTR* Value)
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

//-----------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::set_IdFirmDoc(BSTR Value)
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

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::set_IdKlDoc(BSTR Value)
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

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMGurAllDocImpl::set_IdSklDoc(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_IdUserDoc(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_NameFirm(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_NameKlient(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_NameSklad(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_NameUser(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_NumDoc(int Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_PosDoc(BSTR Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_PrDoc(int Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_SumDoc(double Value)
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


STDMETHODIMP TOleDMGurAllDocImpl::set_TDoc(BSTR Value)
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

//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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
         *Value=false;
        }

  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMGurAllDoc);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

 //----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------


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

//-------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------

