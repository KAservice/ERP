//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprObmenTypeDoc.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprObmenTypeDoc::TFormaSpiskaSprObmenTypeDoc(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::FormCreate(TObject *Sender)
{
DM=new TDMSprObmenTypeDoc(Application);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

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

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

delete DM;

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::EndEdit(TObject *Sender)
{

//if(ViborRekvisit==ViborSklad)
//        {
 //       if (SpisokSklad->OutReady==true)
 //               {
 //               DM->Table->Edit();
 //               DM->TableIDSKLAD_SSKLAD_OBMEN->AsInteger=SpisokSklad->DM->TableIDSKLAD->AsInteger;
//                DM->TableNAMESKLAD->AsString=SpisokSklad->DM->TableNAMESKLAD->AsString;
//                DM->Table->Post();
 //               }
//        }


ViborRekvisit=NO;
IdDochForm=NULL;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypeDoc::DeleteElement()
{

DM->DeleteElement();

}

//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::ToolButtonNewClick(TObject *Sender)
{
//if (Prosmotr==true)return;
DM->NewElement(IdBase);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypeDoc::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->DeleteElement();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprObmenTypeDoc::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Spr/SprTypeDocForObmen");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypeDoc::cxButtonOKClick(TObject *Sender)
{
DM->SaveIsmen(); 	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypeDoc::cxButtonCloseClick(TObject *Sender)
{
OutReady=false;
DM->CancelIsmen();
Close();	
}
//---------------------------------------------------------------------------

