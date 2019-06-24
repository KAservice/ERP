//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportOdinCod.h"
#include "UDMSprEd.h"
#include "UDMSprNom.h"
#include "UDMSprSostProd.h"
#include "UDMSprPrice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaReportOdinCod::TFormaReportOdinCod(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFormaReportOdinCod::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Nom->Active=false;
SpisokNom->Active=false;

Action=caFree;
}

//-----------------------------------------------------------------------------
void __fastcall TFormaReportOdinCod::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportOdinCod::ButtonCreateReportClick(
      TObject *Sender)
{
TcxSSCellObject *cell;
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
prForm->SS->BeginUpdate();
numRow=1;
numCol=2;
//шапка
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ќдинаковые коды ";
delete cell;
numRow++;

SpisokNom->Active=false;
SpisokNom->Active=true;

SpisokNom->First();
while(!SpisokNom->Eof)
        {
        Nom->Active=false;
		Nom->ParamByName("PARAM_IDNOM")->AsInt64=SpisokNomIDNOM->AsInteger;
        Nom->ParamByName("PARAM_CODENOM")->AsInt64=SpisokNomCODENOM->AsInteger;
        Nom->Active=true;

        while(!Nom->Eof)
                {
                numCol=2;
                //пор€дковый номер строки
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=SpisokNomCODENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //списывать
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=SpisokNomNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numRow++;

                numCol=2;
                //пор€дковый номер строки
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=NomCODENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //списывать
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text=NomNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                numRow++;

                Nom->Next();
                }

        SpisokNom->Next();
        }


prForm->SS->EndUpdate();
prForm->Show();
}
//-----------------------------------------------------------------------
