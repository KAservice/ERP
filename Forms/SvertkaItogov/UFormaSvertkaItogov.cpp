//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSvertkaItogov.h"
#include "UFormaDocOstNom.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSvertkaItogov::TFormaSvertkaItogov(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

NameSkladEdit->Text="";
NameFirmaEdit->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad)SpisokSklad->Close();
if(SpisokFirm)SpisokFirm->Close();

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                IdSkl=SpisokSklad->DM->ElementIDSKLAD->AsInteger;
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        }

if (EditRekvisit==ViborFirm)
        {
        if (SpisokFirm->OutReady==true)
                {
                IdFirm=SpisokFirm->DM->ElementIDFIRM->AsInteger;
                NameFirmaEdit->Text=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                }

         }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaSvertkaItogov::OpenFormSpiskaSprSklad(void)
{
if (IdDochForm==NULL)
        {
        SpisokSklad=new TFormaSpiskaSprSklad(Application);
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        EditRekvisit=ViborSklad;
        SpisokSklad->Show();
        SpisokSklad->FOnCloseForm=EndEdit;
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}

//---------------------------------------------------------------
void __fastcall TFormaSvertkaItogov::ButtonCreateDocOstNomClick(
      TObject *Sender)
{

IBQEl->Active=false;
IBQEl->ParamByName("PARAM_IDFIRM")->AsInteger=IdFirm;
IBQEl->ParamByName("PARAM_IDSKLAD")->AsInteger=IdSkl;
IBQEl->Active=true;

TFormaDocOstNom *FormaDocOstNom=new TFormaDocOstNom(Application);
FormaDocOstNom->DM->NewDoc();

FormaDocOstNom->DM->DocAll->Edit();
FormaDocOstNom->DM->DocAllIDFIRMDOC->AsInteger=IdFirm;
FormaDocOstNom->DM->DocAllIDSKLDOC->AsInteger=IdSkl;
FormaDocOstNom->DM->DocAll->Post();

IBQEl->First();
while(!IBQEl->Eof)
        {
        FormaDocOstNom->DM->AddDocNewString();
        FormaDocOstNom->DM->DocT->Edit();
        FormaDocOstNom->DM->DocTIDNOMOSNT->AsInteger=IBQElIDNOM->AsInteger;
        FormaDocOstNom->DM->DocTNAMENOM->AsString=IBQElNAMENOM->AsString;
        FormaDocOstNom->DM->DocTIDEDOSNT->AsInteger=IBQElIDED->AsInteger;
        FormaDocOstNom->DM->DocTNAMEED->AsString=IBQElNAMEED->AsString;
        FormaDocOstNom->DM->DocTKFOSNT->AsFloat=1;
        FormaDocOstNom->DM->DocTKOLOSNT->AsFloat=IBQElSUMKOL->AsFloat;
        FormaDocOstNom->DM->DocTSUMOSNT->AsFloat=IBQElSUM->AsFloat;
        FormaDocOstNom->DM->DocTTNOM->AsInteger=0;
        if(FormaDocOstNom->DM->DocTKOLOSNT!=0 && FormaDocOstNom->DM->DocTSUMOSNT->AsFloat!=0)
                {
                if ( FormaDocOstNom->DM->DocTSUMOSNT->AsFloat>0.1)
                        {
                        FormaDocOstNom->DM->DocTPRICEOSNT->AsFloat=
                        FormaDocOstNom->DM->DocTSUMOSNT->AsFloat/
                        FormaDocOstNom->DM->DocTKOLOSNT->AsFloat;
                        }
                }
        FormaDocOstNom->DM->DocT->Post();
        IBQEl->Next();
        }


FormaDocOstNom->DM->DocAll->Edit();
FormaDocOstNom->DM->DocAllSUMDOC->AsFloat=FormaDocOstNom->DM->Summa();
FormaDocOstNom->DM->DocAll->Post();
FormaDocOstNom->Show();        
}
//----------------------------------------------------------------------------

void __fastcall TFormaSvertkaItogov::BitBtnDateTimeClick(TObject *Sender)
{
if(DateCon->Kind==dtkTime)
        {
        DateCon->Kind=dtkDate;
        }
else
        {
        DateCon->Kind=dtkTime;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaSvertkaItogov::ButtonVibFirmClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        SpisokFirm=new TFormaSpiskaSprFirm(Application);
        if (!SpisokFirm) return;
        SpisokFirm->IdRodForm=Handle;
        SpisokFirm->Vibor=true;
        IdDochForm=SpisokFirm->Handle;
        EditRekvisit=ViborFirm;
        SpisokFirm->DM->OpenTable();
        SpisokFirm->Show();
        SpisokFirm->FOnCloseForm=EndEdit;
        }
}
//---------------------------------------------------------------------------

