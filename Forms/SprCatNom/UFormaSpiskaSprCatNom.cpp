//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaSpiskaSprCatNom.h"
#include "UFormaElementaSprCatNom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprCatNom::TFormaSpiskaSprCatNom(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::FormCreate(TObject *Sender)
{
DM=new TDMSprCatNom(Application);
DBGrid1->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
OutReady=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FOnCloseForm) FOnCloseForm(this);
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::CloseElementSpr(TObject *Sender)
{
DM->OpenTable();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprCatNom::OpenFormElement()
{
TFormaElementaSprCatNom * FormaElementa=new TFormaElementaSprCatNom(Application);
if (!FormaElementa) return;
FormaElementa->DM->OpenElement(DM->TableID_CATNOM->AsInteger);
FormaElementa->IdRodForm=Handle;
FormaElementa->FOnCloseForm=CloseElementSpr;
FormaElementa->Show();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprCatNom::OpenFormNewElement()
{
TFormaElementaSprCatNom * FormaElementa=new TFormaElementaSprCatNom(Application);
if (!FormaElementa) return;
FormaElementa->DM->NewElement();
FormaElementa->IdRodForm=Handle;
FormaElementa->FOnCloseForm=CloseElementSpr;
FormaElementa->Show();

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprCatNom::DeleteElement()
{
DM->DeleteElement(DM->TableID_CATNOM->AsInteger);
DM->OpenTable();
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCatNom::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::ButtonCloseClick(TObject *Sender)
{
Close();         
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::DBGrid1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
        DM->OpenElement(DM->TableID_CATNOM->AsInteger);
        Close();
        }
else
        {
        OpenFormElement();
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCatNom::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=487;
        DBGrid1->Columns->Items[0]->Width=64*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=272*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=115*TecSumWidth/SumWidth;

}
//---------------------------------------------------------------------------

