//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocRecKDR.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String CurrencyPropis(double Value);
//---------------------------------------------------------------------------
__fastcall TFormaDocRecKDR::TFormaDocRecKDR(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::FormCreate(TObject *Sender)
{
EditRekvisit=NO;
DM= new TDMDocRecKDR(Application);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NumDoc->DataSource=DM->DataSourceDocAll;
OperationDBEdit->DataSource=DM->DataSourceDoc;
DohodDBEdit->DataSource=DM->DataSourceDoc;
RashodDBEdit->DataSource=DM->DataSourceDoc;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
NameBaseDBText->DataSource=DM->DataSourceDocAll;

}
//--------------------------------------------------------------------------
void TFormaDocRecKDR::UpdateForm(void)
{
PosDoc->DateTime=DM->DocAllPOSDOC->AsDateTime;

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
        }

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::ButtonCloseClick(TObject *Sender)
{

Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->Close();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->Close();

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRecKDR::ButtonSaveClick(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::EndEdit(TObject *Sender)
{

if (EditRekvisit==ViborFirm)
        {
        if (SpisokFirm->OutReady==true)
                {
                DM->DocAll->Edit();
                DM->DocAllIDFIRMDOC->AsInteger=SpisokFirm->DM->ElementIDFIRM->AsInteger;
                DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
                }
        SpisokFirm=0;
        }



if (EditRekvisit==ViborInfBase)
        {
        if (FormaSpiskaSprInfBase->OutReady==true)
                {
                DM->DocAll->Edit();
                DM->DocAllPREFIKSDOC->AsString=FormaSpiskaSprInfBase->DM->TablePREFIKS_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
        FormaSpiskaSprInfBase=0;
        }


EditRekvisit=NO;
IdDochForm=NULL;

}

//---------------------------------------------------------------------------

void __fastcall TFormaDocRecKDR::PosDocChange(TObject *Sender)
{
DM->DocAll->Edit();
DM->DocAllPOSDOC->AsDateTime=PosDoc->DateTime;
DM->DocAll->Post();
UpdateForm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::ButtonProvClick(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRecKDR::ButtonOKClick(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void TFormaDocRecKDR::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        SpisokFirm=new TFormaSpiskaSprFirm(Application);
        if (!SpisokFirm) return;
        SpisokFirm->IdRodForm=Handle;
        SpisokFirm->Vibor=true;
        IdDochForm=SpisokFirm->Handle;
        EditRekvisit=ViborFirm;
        SpisokFirm->FOnCloseForm=EndEdit;
        SpisokFirm->Show();
        }

}

//--------------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::ButtonEditFirmClick(TObject *Sender)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();
}
//---------------------------------------------------------------------------



void TFormaDocRecKDR::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllPREFIKSDOC->ReadOnly==true) return;
if (IdDochForm==NULL)
        {
        FormaSpiskaSprInfBase=new TFormaSpiskaSprInfBase(Application);
        if (!FormaSpiskaSprInfBase) return;
        FormaSpiskaSprInfBase->FOnCloseForm=EndEdit;
        FormaSpiskaSprInfBase->IdRodForm=Handle;
        FormaSpiskaSprInfBase->Vibor=true;
        IdDochForm=FormaSpiskaSprInfBase->Handle;
        EditRekvisit=ViborInfBase;
        FormaSpiskaSprInfBase->DM->OpenTable();
        FormaSpiskaSprInfBase->Show();
        }
}
//---------------------------------------------------------------------
void __fastcall TFormaDocRecKDR::ViborBaseButtonClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRecKDR::BitBtnDateTimeClick(TObject *Sender)
{
if(PosDoc->Kind==dtkTime)
        {
        PosDoc->Kind=dtkDate;
        }
else
        {
        PosDoc->Kind=dtkTime;
        }        
}
//---------------------------------------------------------------------------

