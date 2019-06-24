//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaElementaSprDocKlientMod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprDocKlientMod::TFormaElementaSprDocKlientMod(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDocKlientMod::FormCreate(TObject *Sender)
{
DM=new TDMSprDocKlient(Application);
NameDocDBEdit->DataSource=DM->DataSourceElement;
SerDBEdit->DataSource=DM->DataSourceElement;
NumDBEdit->DataSource=DM->DataSourceElement;
VidDBEdit->DataSource=DM->DataSourceElement;
IdDochForm=NULL;
OutReady=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDocKlientMod::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FOnCloseForm) FOnCloseForm(this);
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaElementaSprDocKlientMod::UpdateForm(void)
{
DateVid->Date=DM->ElementDATEVID_SDOCKLIENT->AsDateTime;

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDocKlientMod::EndVibor(TObject *Sender)
{
if (IdDochForm!=NULL)
        {
        IdDochForm=NULL;
        ViborRekv=NO;
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprDocKlientMod::ButtonOKClick(TObject *Sender)
{
DM->SaveElement();
OutReady=true;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprDocKlientMod::ButtonCloseClick(TObject *Sender)
{
OutReady=false ;
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprDocKlientMod::DateVidChange(TObject *Sender)
{
DM->Element->Edit();
DM->ElementDATEVID_SDOCKLIENT->AsDateTime=DateVid->Date;
DM->Element->Post();        
}
//---------------------------------------------------------------------------


