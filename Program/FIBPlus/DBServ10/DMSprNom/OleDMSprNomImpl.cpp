// OLEDMSPRNOMIMPL : Implementation of TOleDMSprNomImpl (CoClass: OleDMSprNom, Interface: IOleDMSprNom)

#include <vcl.h>
#pragma hdrstop

#include "OLEDMSPRNOMIMPL.H"


/////////////////////////////////////////////////////////////////////////////
// TOleDMSprNomImpl

STDMETHODIMP TOleDMSprNomImpl::ChancheGrp(BSTR NewGrp)
{
  try
  {
  DMSprNom->ChancheGrp(StrToInt64(NewGrp));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;

}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::DeleteElement(BSTR Id)
{ 
  try
  {
  if(DMSprNom->DeleteElement(StrToInt64(Id))==true)
	{
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprNom->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::FindPoCodu(int Code)
{ 
  try
  {
  DMSprNom->FindPoCodu(Code);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_AllElement(int* Value)
{
  try
  {
  if (DMSprNom->AllElement==true)
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
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_ArtNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementARTNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_CodeError(int* Value)
{
  try
  {
  *Value=CodeError;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_CodeNom(int* Value)
{
  try
  {
  *Value=DMSprNom->ElementCODENOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_FNameNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementFNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_GID_SNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementGID_SNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_IdBasEdNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDBASEDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_IdGrpNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDGRPNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_IdNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementIDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//--------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_IdOsnEdNom(BSTR* Value)
{
  try
  {
   *Value=WideString(DMSprNom->ElementIDOSNEDNOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_IdTypePrice(BSTR* Value)
{
  try
  {
   *Value=WideString(IntToStr(DMSprNom->IdTypePrice).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_KrNameNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementKRNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_NameNom(BSTR* Value)
{
  try
  {
  *Value=WideString(DMSprNom->ElementNAMENOM->AsString.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_TableEOF(int* Value)
{
  try
  {
  if (DMSprNom->Table->Eof==true )
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
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_TextError(BSTR* Value)
{
  try
  {
    *Value=WideString(TextError.c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::get_TNom(int* Value)
{
  try
  {
  *Value=DMSprNom->ElementTNOM->AsInteger;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::GetGidElement(BSTR Id, BSTR* gid)
{ 
  try
  {
  *gid=WideString(DMSprNom->GetGIDElement(StrToInt64(Id)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::GetIdElement(BSTR gid, BSTR* Id)
{ 
  try
  {
  *Id=WideString(IntToStr(DMSprNom->GetIDElement(gid)).c_str()).c_bstr();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//---------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::NewElement(BSTR IdGrp)
{ 
  try
  {
  DMSprNom->NewElement(StrToInt64(IdGrp));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::OpenElement(BSTR Id)
{ 
  try
  {
  DMSprNom->OpenElement(StrToInt64(Id));
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::OpenTable(BSTR Grp, int All)
{ 
  try
  {
  bool a;
  if (All==1)
        {
        a=true;
        }
  else  {
        a=false;
        }
  DMSprNom->OpenTable(StrToInt64(Grp),a);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::SaveElement()
{
  try
  {
  if(DMSprNom->SaveElement()==true)
  {
	CodeError=0;
	TextError="Ошибок нет";
	}
  else
	{
	CodeError=1;
	TextError=DMSprNom->TextError;
	}
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}
//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::set_AllElement(int Value)
{
  try
  {
  if (Value==1)
        {
        DMSprNom->AllElement==true;
        }
  else
        {
        DMSprNom->AllElement==true;
        }
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//------------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::set_ArtNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementARTNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::set_CodeNom(int Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementCODENOM->AsInteger=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::set_FNameNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementFNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};

//-----------------------------------------------------------------------------
STDMETHODIMP TOleDMSprNomImpl::set_GID_SNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementGID_SNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_IdBasEdNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDBASEDNOM->AsInt64=StrToInt64(Value);
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_IdGrpNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDGRPNOM->AsInt64=StrToInt64(Value);
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_IdNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDNOM->AsInt64=StrToInt64(Value);
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_IdOsnEdNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementIDOSNEDNOM->AsInt64=StrToInt64(Value);
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_IdTypePrice(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->IdTypePrice=StrToInt64(Value);
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_KrNameNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementKRNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_NameNom(BSTR Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementNAMENOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::set_TNom(int Value)
{
  try
  {
  DMSprNom->Element->Edit();
  DMSprNom->ElementTNOM->AsString=Value;
  DMSprNom->Element->Post();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
};


STDMETHODIMP TOleDMSprNomImpl::TableFirst()
{
  try
  {
  DMSprNom->Table->First();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

STDMETHODIMP TOleDMSprNomImpl::TableNext()
{
  try
  {
  DMSprNom->Table->Next();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IOleDMSprNom);
  }
  return S_OK;
}

 