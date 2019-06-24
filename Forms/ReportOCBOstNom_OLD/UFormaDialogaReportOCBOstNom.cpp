//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaDialogaReportOCBOstNom.h"
#include "UDMSetup.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportOCBOstNom::TFormaDialogaReportOCBOstNom(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

NameSkladEdit->Text="";
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
TDMSetup * DMSetup=new TDMSetup(Application);
DMSetup->OpenElement(15);
if(DMSetup->ElementVALUE_SETUP->AsString=="")
        {
        GrPosledLabel->Visible=false;
        }
else
        {
        GrPosledLabel->Visible=true;
        GrPosledLabel->Caption="ѕозици€ правильного проведени€ документов: "
                +DMSetup->ElementVALUE_SETUP->AsString;
        }
delete DMSetup;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (SpisokSklad) SpisokSklad->Close();
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
				IdSkl=SpisokSklad->DM->ElementIDSKLAD->AsInt64;
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OpenFormSpiskaSprSklad(void)
{
if (IdDochForm==NULL)
        {
        SpisokSklad=new TFormaSpiskaSprSklad(Application);
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        EditRekvisit=ViborSklad;
        SpisokSklad->FOnCloseForm=EndEdit;
        SpisokSklad->Show();
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------
//          select
//NAME,
//SUM(PRIHOD_KOL) AS PRIHODKOL,
//SUM(PRIHOD_SUM) AS PRIHODSUM,
//SUM(RASHOD_KOL) AS RASHODKOL,
//SUM(RASHOD_SUM) AS RASHODSUM,
//SUM(PRIHOD_DO_CON_KOL) AS PR_DOCON_KOL,
//SUM(PRIHOD_DO_CON_SUM) AS PR_DOCON_SUM,
//SUM(RASHOD_DO_CON_KOL) AS RAS_DOCON_KOL,
//SUM(RASHOD_DO_CON_SUM) AS RAS_DOCON_SUM,
//SUM(TEC_OST_KOL) AS OSTKOL,
//SUM(TEC_OST_SUM) AS OSTSUM ,
//(SUM(TEC_OST_KOL)-SUM(PRIHOD_DO_CON_KOL)+SUM(RASHOD_DO_CON_KOL)  - SUM(PRIHOD_KOL)  +SUM(RASHOD_KOL)           )  AS  NACHOSTKOL,
//(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM)  -SUM(PRIHOD_SUM)  +SUM(RASHOD_SUM)           )  AS  NACHOSTSUM,

//(SUM(TEC_OST_KOL)-SUM(PRIHOD_DO_CON_KOL)+SUM(RASHOD_DO_CON_KOL)            )  AS  CONOSTKOL,
//(SUM(TEC_OST_SUM)-SUM(PRIHOD_DO_CON_SUM)+SUM(RASHOD_DO_CON_SUM)         )  AS  CONOSTSUM
//from OCB_OSTNOM_PROC (:DATENACH, :DATECON, :PAR_IDSKLAD)
//group by NAME

//-----------------------------------------------------------------------------
//---------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBOstNom::ButtonRunClick(
      TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

ReportSklad(PrintForm,0,true);

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::ReportSklad(TSheetEditor *prForm, __int64 idSkl, bool allSkl)
{
if (IdSkl==0)
        {

        IBQSkl->Active=false;
        IBQSkl->ParamByName("DATENACH")->AsDateTime=DateNach->DateTime;
        IBQSkl->ParamByName("DATECON")->AsDateTime=DateCon->DateTime;
        IBQSkl->Active=true;

        IBQSkl->First();
        while(!IBQSkl->Eof)
        
                {

                OutputStringSklad(prForm);

                numRow++;
				ReportGrpNom(prForm,IBQSklIDSKLAD->AsInt64, false);
                IBQSkl->Next();
                }
        }
else
        {
        ReportGrpNom(prForm,IdSkl, false);
        }

}

//--------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::ReportGrpNom( TSheetEditor *prForm, __int64 idSkl, bool allSkl)
{

                IBQGrp->Active=false;
                IBQGrp->ParamByName("DATENACH")->AsDateTime=DateNach->DateTime;
                IBQGrp->ParamByName("DATECON")->AsDateTime=DateCon->DateTime;
				IBQGrp->ParamByName("PAR_IDSKLAD")->AsInt64=idSkl;
                IBQGrp->Active=true;
                porNumStrGrp=1;
                IBQGrp->First();
                while(!IBQGrp->Eof)
                        {

                        OutputStringGrp(prForm);
                        numRow++;
                        ReportNom(prForm,idSkl,allSkl,IBQGrp->FieldByName("IDGN")->AsInteger);
                        porNumStrGrp++;
                        IBQGrp->Next();
                        }




}
//-----------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::ReportNom( TSheetEditor *prForm, __int64 idSkl, bool allSkl,  __int64 idGrp)
{

                IBQEl->Active=false;
                IBQEl->ParamByName("DATENACH")->AsDateTime=DateNach->DateTime;
                IBQEl->ParamByName("DATECON")->AsDateTime=DateCon->DateTime;
				IBQEl->ParamByName("PAR_IDGRPNOM")->AsInt64=idGrp;
				IBQEl->ParamByName("PAR_IDSKLAD")->AsInt64=idSkl;

                IBQEl->Active=true;
                porNumStr=1;
                IBQEl->First();
                while(!IBQEl->Eof)
                        {
                        OutputString(prForm);numRow++;


                        AllNachOst=AllNachOst+IBQElNACHOSTSUM->AsFloat;
                        AllPrihod=AllPrihod+IBQElPRIHODSUM->AsFloat;
                        AllRashod=AllRashod+IBQElRASHODSUM->AsFloat;
                        AllConOst=AllConOst+IBQElCONOSTSUM->AsFloat;

                        porNumStr++;
                        IBQEl->Next();
                        }
}
//---------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 100;
        cHeader->Size[4] = 100;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;

numRow=2;
numCol=3;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "ќстатки и движени€ товаров за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 10;
if (IdSkl==0)
        {
        cell->Text="—клад: по всем складам. ";
        }
else
        {
        cell->Text="—клад: "+NameSkladEdit->Text;;
        }
delete cell;
numRow++;



numCol=1;

//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="є";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Ќаименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Ќач. остаток";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ѕриход";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="–асход";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=" он. остаток";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}

//------------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OutputStringSklad( TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Font->Size = 14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//склад
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="—клад: "+IBQSkl->FieldByName("NAMESKLAD")->AsString;
cell->Style->Font->Size = 14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQSklNACHOSTSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQSklPRIHODSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQSklRASHODSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQSklCONOSTSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
}

//----------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OutputStringGrp(TSheetEditor *prForm)
{
 TcxSSCellObject *cell;
numCol=1;
//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStrGrp);
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//группа ном.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQGrpNAMEGN->AsString;
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQGrpNACHOSTSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQGrpPRIHODSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQGrpRASHODSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQGrpCONOSTSUM->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 12;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

}
//------------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQElNAME->AsString;
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQElNACHOSTSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQElNACHOSTSUM->AsFloat,ffFixed,10,2);
		}
if (IBQElNACHOSTSUM->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=10;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQElPRIHODSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQElPRIHODSUM->AsFloat,ffFixed,10,2);
        }
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQElRASHODSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQElRASHODSUM->AsFloat,ffFixed,10,2);
        }
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQElCONOSTSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQElCONOSTSUM->AsFloat,ffFixed,10,2);
		}
if (IBQElCONOSTSUM->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=10;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=1;
//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQElNACHOSTKOL->AsFloat!=0)
        {
        cell->Text=FloatToStr(IBQElNACHOSTKOL->AsFloat)+" "+IBQElNAMEED->AsString;
		}
if (IBQElNACHOSTKOL->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=10;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( IBQElPRIHODKOL->AsFloat!=0)
        {
        cell->Text=FloatToStr(IBQElPRIHODKOL->AsFloat)+" "+IBQElNAMEED->AsString;
        }
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQElRASHODKOL->AsFloat!=0)
        {
        cell->Text=FloatToStr(IBQElRASHODKOL->AsFloat)+" "+IBQElNAMEED->AsString;
        }
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQElCONOSTKOL->AsFloat!=0)
        {
        cell->Text=FloatToStr(IBQElCONOSTKOL->AsFloat)+" "+IBQElNAMEED->AsString;
		}

if (IBQElCONOSTKOL->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=10;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
}

//--------------------------------------------------------------------------
void TFormaDialogaReportOCBOstNom::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//пор€дковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllRashod, ffFixed,15,2);
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(AllConOst, ffFixed,15,2);
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBOstNom::BitBtnNachPeriodaClick(
      TObject *Sender)
{
if(DateNach->Kind==dtkTime)
        {
        DateNach->Kind=dtkDate;
        }
else
        {
        DateNach->Kind=dtkTime;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBOstNom::BitBtnConPeriodaClick(
      TObject *Sender)
{
if(DateCon->Kind==dtkTime)
        {
        DateCon->Kind=dtkDate;
        }
else
        {
        DateCon->Kind=dtkTime;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBOstNom::DateNachChange(
      TObject *Sender)
{
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBOstNom::DateConChange(
      TObject *Sender)
{
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBOstNom::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Report/RepOstNom");
}
//---------------------------------------------------------------------------

