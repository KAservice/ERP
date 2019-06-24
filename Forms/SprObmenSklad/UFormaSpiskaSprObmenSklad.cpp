//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprObmenSklad.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprObmenSklad::TFormaSpiskaSprObmenSklad(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::FormCreate(TObject *Sender)
{
DM=new TDMSprObmenSklad(Application);

DBGrid1->DataSource=DM->DataSourceTable;

Vibor=false;
OutReady=false;
Prosmotr=false;
ViborRekvisit=NO;


}
//---------------------------------------------------------------------------
void TFormaSpiskaSprObmenSklad::UpdateForm(void)
{

DM->OpenTable(IdBase);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::FormClose(TObject *Sender,
      TCloseAction &Action)
{

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

delete DM;

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::EndEdit(TObject *Sender)
{

if(ViborRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                DM->Table->Edit();
                DM->TableIDSKLAD_SSKLAD_OBMEN->AsInt64=SpisokSklad->DM->TableIDSKLAD->AsInt64;
                DM->TableNAMESKLAD->AsString=SpisokSklad->DM->TableNAMESKLAD->AsString;
                DM->Table->Post();
                }
        }


ViborRekvisit=NO;
IdDochForm=NULL;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenSklad::OpenFormSpiskaSprSklad()
{
if (IdDochForm==NULL)
        {
        SpisokSklad=new TFormaSpiskaSprSklad(Application);
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        ViborRekvisit=ViborSklad;
        SpisokSklad->DM->OpenTable();
        SpisokSklad->HintLabel->Caption="Выберите склад";
        SpisokSklad->Show();
        SpisokSklad->FOnCloseForm=EndEdit;
        }
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenSklad::DeleteElement()
{

DM->DeleteElement();

}

//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::ToolButtonNewClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->NewElement(IdBase);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenSklad::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=440;
        DBGrid1->Columns->Items[0]->Width=37*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=360*TecSumWidth/SumWidth;

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenSklad::DBGrid1EditButtonClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------





void __fastcall TFormaSpiskaSprObmenSklad::ToolButtonEditClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenSklad::cxButtonCloseClick(TObject *Sender)
{
OutReady=false;
DM->CancelIsmen();
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenSklad::cxButtonOKClick(TObject *Sender)
{
DM->SaveIsmen(); 	
}
//---------------------------------------------------------------------------


