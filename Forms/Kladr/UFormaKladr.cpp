//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaKladr.h"
#include "UDMSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaKladr::TFormaKladr(TComponent* Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall TFormaKladr::FormCreate(TObject *Sender)
{
RegioncxButtonEdit->Text="";
RayoncxButtonEdit->Text="";
GorodcxButtonEdit->Text="";
NasPunktcxButtonEdit->Text="";
StreetcxButtonEdit->Text="";
DomcxTextEdit->Text="";
KorpuscxTextEdit->Text="";
KvartcxTextEdit->Text="";
IndexcxTextEdit->Text="";
NoKladr=false;



}


//-----------------------------------------------------------------------
bool TFormaKladr::Init(void)
{
bool result=false;

//проверим есть ли каталог с классификатором
TDMSetup *dm_setup=new TDMSetup(Application);
dm_setup->DM_Connection=DM_Connection;
dm_setup->Init();
dm_setup->OpenElement(29);
if (dm_setup->ElementVALUE_SETUP->AsString=="")
	{
	NoKladr=true;
	}
else
	{
	KladrPatch=dm_setup->ElementVALUE_SETUP->AsString;
	}
delete dm_setup;

if (DirectoryExists(KladrPatch)==true)
	{
	if (FileExists(KladrPatch+"\\KLADR.dbf")==true &&
		  FileExists(KladrPatch+"\\STREET.dbf")==true)
		  {

		  }
	else
		{
		NoKladr=true;
		}
	}
else
	{
	NoKladr=true;
	}



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladr::FormClose(TObject *Sender, TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Action=caFree;

}
//---------------------------------------------------------------------------
void TFormaKladr::ViborRegion(void)
{
if (NoKladr==true)
	{
	ShowMessage("Классификатор адресов не обнаружен!");
	return;
	}
if (FormaKladrViborRegion==0)
	{
	FormaKladrViborRegion=new TFormaKladrViborRegion(Application);
	if (!FormaKladrViborRegion) return;
	FormaKladrViborRegion->FOnCloseForm=EndViborRegion;
    FormaKladrViborRegion->Object=1;
	FormaKladrViborRegion->UpdateForm();
	FormaKladrViborRegion->ShowModal();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladr::EndViborRegion(TObject *Sender)
{
if (FormaKladrViborRegion->OutReady==true)
	{
	RegioncxButtonEdit->Text=FormaKladrViborRegion->TableNAME->AsString+
					   +" "+FormaKladrViborRegion->TableSOCR->AsString;
	NameRegion=FormaKladrViborRegion->TableNAME->AsString;
	}
FormaKladrViborRegion=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TFormaKladr::RegioncxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRegion();
}
//---------------------------------------------------------------------------
void TFormaKladr::ViborRayon(void)
{
if (NoKladr==true)
	{
	ShowMessage("Классификатор адресов не обнаружен!");
	return;
	}

if (FormaKladrViborRegion==0)
	{
	FormaKladrViborRegion=new TFormaKladrViborRegion(Application);
	if (!FormaKladrViborRegion) return;
	FormaKladrViborRegion->FOnCloseForm=EndViborRayon;
	FormaKladrViborRegion->Object=2;
	FormaKladrViborRegion->NameRegion=NameRegion;
	FormaKladrViborRegion->UpdateForm();
	FormaKladrViborRegion->ShowModal();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaKladr::EndViborRayon(TObject *Sender)
{
if (FormaKladrViborRegion->OutReady==true)
	{
	RayoncxButtonEdit->Text=FormaKladrViborRegion->TableNAME->AsString+
						+" "+FormaKladrViborRegion->TableSOCR->AsString;
	NameRayon=FormaKladrViborRegion->TableNAME->AsString;
	}
FormaKladrViborRegion=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TFormaKladr::RayoncxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRayon();
}
//---------------------------------------------------------------------------
void TFormaKladr::ViborGorod(void)
{
if (NoKladr==true)
	{
	ShowMessage("Классификатор адресов не обнаружен!");
	return;
	}

if (FormaKladrViborRegion==0)
	{
	FormaKladrViborRegion=new TFormaKladrViborRegion(Application);
	if (!FormaKladrViborRegion) return;
	FormaKladrViborRegion->FOnCloseForm=EndViborGorod;
	FormaKladrViborRegion->Object=3;
	FormaKladrViborRegion->NameRegion=NameRegion;
	FormaKladrViborRegion->NameRayon=NameRayon;
	FormaKladrViborRegion->UpdateForm();
	FormaKladrViborRegion->ShowModal();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaKladr::EndViborGorod(TObject *Sender)
{
if (FormaKladrViborRegion->OutReady==true)
	{
	GorodcxButtonEdit->Text=FormaKladrViborRegion->TableNAME->AsString+
						+" "+FormaKladrViborRegion->TableSOCR->AsString;
	NameGorod=FormaKladrViborRegion->TableNAME->AsString;
	}
FormaKladrViborRegion=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TFormaKladr::ViborNasPunkt(void)
{

if (NoKladr==true)
	{
	ShowMessage("Классификатор адресов не обнаружен!");
	return;
	}

if (FormaKladrViborRegion==0)
	{
	FormaKladrViborRegion=new TFormaKladrViborRegion(Application);
	if (!FormaKladrViborRegion) return;
	FormaKladrViborRegion->FOnCloseForm=EndViborNasPunkt;
	FormaKladrViborRegion->Object=4;
	FormaKladrViborRegion->NameRegion=NameRegion;
	FormaKladrViborRegion->NameRayon=NameRayon;
	FormaKladrViborRegion->NameGorod=NameGorod;
	FormaKladrViborRegion->UpdateForm();
	FormaKladrViborRegion->ShowModal();
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaKladr::EndViborNasPunkt(TObject *Sender)
{
if (FormaKladrViborRegion->OutReady==true)
	{
	NasPunktcxButtonEdit->Text=FormaKladrViborRegion->TableNAME->AsString +
						+" "+FormaKladrViborRegion->TableSOCR->AsString;
	NameNasPunkt=FormaKladrViborRegion->TableNAME->AsString;
	}
FormaKladrViborRegion=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaKladr::GorodcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGorod();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKladr::NasPunktcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNasPunkt();
}
//---------------------------------------------------------------------------
void TFormaKladr::ViborStreet(void)
{
if (NoKladr==true)
	{
	ShowMessage("Классификатор адресов не обнаружен!");
	return;
	}

if (FormaKladrViborStreet==0)
	{
	FormaKladrViborStreet=new TFormaKladrViborStreet(Application);
	if (!FormaKladrViborStreet) return;
	FormaKladrViborStreet->FOnCloseForm=EndViborStreet;
	FormaKladrViborStreet->NameRegion=NameRegion;
	FormaKladrViborStreet->NameRayon=NameRayon;
	FormaKladrViborStreet->NameGorod=NameGorod;
	FormaKladrViborStreet->NameNasPunkt=NameNasPunkt;
	FormaKladrViborStreet->UpdateForm();
	FormaKladrViborStreet->ShowModal();
	}  
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladr::EndViborStreet(TObject *Sender)
{
if (FormaKladrViborStreet->OutReady==true)
	{
	StreetcxButtonEdit->Text=FormaKladrViborStreet->TableNAME->AsString+
						+" "+FormaKladrViborStreet->TableSOCR->AsString;
						
	}
FormaKladrViborStreet=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaKladr::StreetcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborStreet();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKladr::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKladr::ActionOKExecute(TObject *Sender)
{
OutReady=true;
Close();
}
//---------------------------------------------------------------------------

