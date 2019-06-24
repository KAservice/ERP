//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaGurPKO.h"
#include "UDM.h"
#include "UFormaCheckKKMkPKO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern bool IspFR;
extern TDMSprKKM *glKKM;
//---------------------------------------------------------------------------
__fastcall TFormaGurPKO::TFormaGurPKO(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurPKO::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void TFormaGurPKO::UpdateForm(void)
{
IBQGurnal->Active=false;
IBQGurnal->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurPKO::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;

        int  SumWidth=744;
        DBGrid1->Columns->Items[0]->Width=23*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=108*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=64*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[3]->Width=136*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[4]->Width=67*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[5]->Width=220*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[6]->Width=74*TecSumWidth/SumWidth;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurPKO::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQGurnal->Active=false;
IBQDoc->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------

