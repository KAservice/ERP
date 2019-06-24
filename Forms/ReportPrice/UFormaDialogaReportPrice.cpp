//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaDialogaReportPrice.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportPrice::TFormaDialogaReportPrice(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPrice::FormCreate(TObject *Sender)
{

NamePodrEdit->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokPodr) SpisokPodr->Close();
GrpBV->Active=false;
NomBV->Active=false;
Ed->Active=false;
Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportPrice::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborPodr)
        {
        if (SpisokPodr->OutReady==true)
                {
				IdPodr=SpisokPodr->DM->ElementIDPOD->AsInt64;
				IdTypePrice=SpisokPodr->DM->ElementIDTPRICEPOD->AsInt64;
                NamePodrEdit->Text=SpisokPodr->DM->ElementNAMEPOD->AsString;
                }
        SpisokPodr=0;
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportPrice::OpenFormSpiskaSprPodr(void)
{
if (IdDochForm==NULL)
        {
        SpisokPodr=new TFormaSpiskaSprPodr(Application);
        if (!SpisokPodr) return;
        SpisokPodr->IdRodForm=Handle;
        SpisokPodr->Vibor=true;
        IdDochForm=SpisokPodr->Handle;
		EditRekvisit=ViborPodr;
		SpisokPodr->FOnCloseForm=EndEdit;
		SpisokPodr->Show();
        }

}
//----------------------------------------------------------------------------
void TFormaDialogaReportPrice::OutputZagolovokReport(TSheetEditor *prForm)
{
numRow=2;
numCol=1;
numRow++;
}
//------------------------------------------------------------------------------
void TFormaDialogaReportPrice::OutputStringGrp(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
delete cell;
numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=GrpBVNAME_GBVNOM->AsString;
delete cell;
numCol++;
//prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);



}
//------------------------------------------------------------------------------
void TFormaDialogaReportPrice::OutputStringNom(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=NomBVFNAMENOM->AsString;
delete cell;
numCol++;

}
//------------------------------------------------------------------------------
void TFormaDialogaReportPrice::OutputStringEd(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=4;

//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=EdNAMEED->AsString;
delete cell;
numCol++;

//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(EdZNACH_PRICE->AsFloat*EdKFED->AsFloat, ffCurrency,10,2);
delete cell;
numCol++;

}
//------------------------------------------------------------------------------
void TFormaDialogaReportPrice::OutputPodavalReport(TSheetEditor *prForm)
{
//
}
//---------------------------------------------------------------

void __fastcall TFormaDialogaReportPrice::NamePodrEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprPodr();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPrice::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportPrice::cxButtonCreateClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStrGrp=1;
String ZaprosGrp="";



GrpBV->Active=false;
GrpBV->ParamByName("PARAM_IDPOD")->AsInt64=IdPodr;
GrpBV->Active=true;

//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

GrpBV->First();
while(!GrpBV->Eof)
        {
		numRow++; numRow++; numRow++;
        OutputStringGrp(PrintForm);numRow++; numRow++; numRow++;
		porNumStr=1;
        NomBV->Active=false;
		NomBV->ParamByName("PARAM_IDGRP_BVNOM")->AsInt64=GrpBVID_GBVNOM->AsInt64;
        NomBV->Active=true;
		NomBV->First();
        while(!NomBV->Eof)
				{
                OutputStringNom(PrintForm);

                Ed->Active=false;
				Ed->ParamByName("PARAM_IDNOM")->AsInt64=NomBVIDNOM->AsInt64;
                Ed->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=IdTypePrice;
				Ed->Active=true;

				Ed->First();
				while(!Ed->Eof)
						{
						OutputStringEd(PrintForm); numRow++;
						Ed->Next();
                        }
				numRow++;
                porNumStr++;
				NomBV->Next();
                }

		porNumStrGrp++;
		GrpBV->Next();
		}

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();	
}
//---------------------------------------------------------------------------


