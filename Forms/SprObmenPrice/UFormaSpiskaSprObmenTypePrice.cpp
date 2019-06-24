//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprObmenTypePrice.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
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
__fastcall TFormaSpiskaSprObmenTypePrice::TFormaSpiskaSprObmenTypePrice(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypePrice::FormCreate(TObject *Sender)
{
DM=new TDMSprObmenTypePrice(Application);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

Vibor=false;
OutReady=false;
Prosmotr=false;
ViborRekvisit=NO;


}
//---------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypePrice::UpdateForm(void)
{

DM->OpenTable(IdBase);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypePrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

delete DM;

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypePrice::EndEdit(TObject *Sender)
{

if(ViborRekvisit==ViborTypePrice)
        {
        if (SpisokTypePrice->OutReady==true)
                {
                DM->Table->Edit();
                DM->TableIDTPRICE_STYPEPRICE_OBMEN->AsInt64=SpisokTypePrice->DM->TableID_TPRICE->AsInt64;
                DM->TableNAME_TPRICE->AsString=SpisokTypePrice->DM->TableNAME_TPRICE->AsString;
                DM->Table->Post();
                }
        }


ViborRekvisit=NO;
IdDochForm=NULL;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypePrice::OpenFormSpiskaSprTypePrice()
{
if (IdDochForm==NULL)
        {
        SpisokTypePrice=new TFormaSpiskaSprTypePrice(Application);
        if (!SpisokTypePrice) return;
        SpisokTypePrice->IdRodForm=Handle;
        SpisokTypePrice->Vibor=true;
        IdDochForm=SpisokTypePrice->Handle;
        ViborRekvisit=ViborTypePrice;
        SpisokTypePrice->DM->OpenTable();
        //SpisokTypePrice->HintLabel->Caption="Выберите тип цен для обмена";
        SpisokTypePrice->Show();
        SpisokTypePrice->FOnCloseForm=EndEdit;

        }
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprObmenTypePrice::DeleteElement()
{

DM->DeleteElement();

}

//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypePrice::ToolButtonNewClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->NewElement(IdBase);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprObmenTypePrice::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->DeleteElement();
}
//---------------------------------------------------------------------------






void __fastcall TFormaSpiskaSprObmenTypePrice::ToolButtonEditClick(
      TObject *Sender)
{
OpenFormSpiskaSprTypePrice();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypePrice::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Spr/SprTypePriceForObmen");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypePrice::cxGrid1DBTableView1NAME_TPRICEPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprTypePrice();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypePrice::cxButtonCloseClick(
      TObject *Sender)
{
OutReady=false;
DM->CancelIsmen();
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprObmenTypePrice::cxButtonOKClick(TObject *Sender)
{
OutReady=false;
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------


