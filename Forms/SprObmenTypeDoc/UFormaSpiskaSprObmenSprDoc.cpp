//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprObmenSprDoc.h"
#include "UFormaElementaSprGrpBVNom.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprObmenTypeDoc::TFormaSpiskaSprObmenTypeDoc(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::FormCreate(TObject *Sender)
{
DM=new TDMSprObmenSklad(Application);

DBGrid1->DataSource=DM->DataSourceTable;

Vibor=false;
OutReady=false;
Prosmotr=false;
ViborRekvisit=NO;


}
//---------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypeDoc::UpdateForm(void)
{

DM->OpenTable(IdBase);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (Vibor==true)
        {
        SendMessage(IdRodForm,MESSAGE_READY,0,0);
        }
delete DM;

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::EndEdit(TMessage&Message)
{

if(ViborRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                DM->Table->Edit();
                DM->TableIDSKLAD_SSKLAD_OBMEN->AsInteger=SpisokSklad->DM->TableIDSKLAD->AsInteger;
                DM->TableNAMESKLAD->AsString=SpisokSklad->DM->TableNAMESKLAD->AsString;
                DM->Table->Post();
                }
        }


ViborRekvisit=NO;
IdDochForm=NULL;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypeDoc::OpenFormSpiskaSprSklad()
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

        }
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypeDoc::DeleteElement()
{

DM->DeleteElement();

}

//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::ToolButtonNewClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->NewElement(IdBase);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::ButtonCloseClick(TObject *Sender)
{
OutReady=false;
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypeDoc::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=440;
        DBGrid1->Columns->Items[0]->Width=37*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=360*TecSumWidth/SumWidth;

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::DBGrid1EditButtonClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprObmenTypeDoc::ButtonOKClick(TObject *Sender)
{

DM->SaveIsmen();        
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprObmenTypeDoc::ToolButtonEditClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------

