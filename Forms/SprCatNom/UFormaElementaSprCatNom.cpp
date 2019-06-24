//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaElementaSprCatNom.h"

#include "UFormaSpiskaSprNom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprCatNom::TFormaElementaSprCatNom(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprCatNom::FormCreate(TObject *Sender)
{
DM=new TDMSprCatNom(Application);
NameCatNom->DataSource=DM->DataSourceElement;
NameNom->DataSource=DM->DataSourceElement;
KolCatNom->DataSource=DM->DataSourceElement;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprCatNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FOnCloseForm) FOnCloseForm(this);
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprCatNom::EndVibor(TObject *Sender)
{
if (IdDochForm!=NULL)
        {
        
        if (ViborRekv==ViborNom)
                {
                DM->Element->Edit();
                DM->ElementIDNOM_CATNOM->AsInteger=FormaSpiskaSprNom->DM->ElementIDNOM->AsInteger;
                DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
                DM->Element->Post();
                }

        IdDochForm=NULL;
        ViborRekv=NO;
        }

}
//----------------------------------------------------------------------------


void __fastcall TFormaElementaSprCatNom::ButtonOKClick(TObject *Sender)
{
DM->SaveElement();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCatNom::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprCatNom::ButtonVoborNomClick(TObject *Sender)
{
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------
void TFormaElementaSprCatNom::OpenFormSpiskaSprNom(void)
{
if (IdDochForm==NULL)
        {
        FormaSpiskaSprNom=new TFormaSpiskaSprNom(Application);
        FormaSpiskaSprNom->Vibor=true;
        FormaSpiskaSprNom->IdRodForm=Handle;
        FormaSpiskaSprNom->UpdateForm();
        FormaSpiskaSprNom->Show();
        IdDochForm=FormaSpiskaSprNom->Handle;
        FormaSpiskaSprNom->FOnCloseForm=EndVibor;
        FormaSpiskaSprNom->FOnCloseForm=EndVibor;
        ViborRekv=ViborNom;
        }
}
//-------------------------------------------------------------------------
