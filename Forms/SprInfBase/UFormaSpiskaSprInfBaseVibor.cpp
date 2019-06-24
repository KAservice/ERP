//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprInfBaseVibor.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprInfBaseVibor::TFormaSpiskaSprInfBaseVibor(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInfBaseVibor::FormCreate(TObject *Sender)
{
DM=new TDMSprInfBase(Application);
DBGrid1->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;
OutReady=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprInfBaseVibor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Visible=false;
if(FOnCloseForm) FOnCloseForm(this);

delete DM;
Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprInfBaseVibor::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInfBaseVibor::DBGrid1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
        OutReady=true;
        DM->OpenElement(DM->TableID_SINFBASE_OBMEN->AsInteger);
        Close();
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprInfBaseVibor::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=543;
        DBGrid1->Columns->Items[0]->Width=64*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=138*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=304*TecSumWidth/SumWidth;


}
//---------------------------------------------------------------------------

