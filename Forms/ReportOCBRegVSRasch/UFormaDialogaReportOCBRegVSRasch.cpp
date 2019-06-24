//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialogaReportOCBRegVSRasch.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String glGetNameDoc(String StrCodeDoc);
//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportOCBVSRasch::TFormaDialogaReportOCBVSRasch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBVSRasch::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;
IdKlient=0;
NameKlientEdit->Text="";
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBVSRasch::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBVSRasch::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBVSRasch::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborKlient)
        {
        if (FormaSpiskaSprKlient->OutReady==true)
                {
                IdKlient=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInteger;
                NameKlientEdit->Text=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
                }
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::OpenFormSpiskaSprKlient(void)
{
if (IdDochForm==NULL)
        {
        FormaSpiskaSprKlient=new TFormaSpiskaSprKlient(Application);
        if (!FormaSpiskaSprKlient) return;
        FormaSpiskaSprKlient->IdRodForm=Handle;
        FormaSpiskaSprKlient->Vibor=true;
        IdDochForm=FormaSpiskaSprKlient->Handle;
        EditRekvisit=ViborKlient;
        FormaSpiskaSprKlient->FOnCloseForm=EndEdit;
        FormaSpiskaSprKlient->Show();
        }
}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportOCBVSRasch::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprKlient();
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
void __fastcall TFormaDialogaReportOCBVSRasch::ButtonRunClick(
      TObject *Sender)
{
TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStrGrp=1;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;
//шапка
OutputZagolovokReport(PrintForm);

//таблица

        ReportKlient(PrintForm,IdKlient);


//if (IdSkl!=0)
//        {
//        ReportSklad(PrintForm,IdSkl,false,);
//        }

        OutputPodavalReport(PrintForm);

PrintForm->Show();
}

//--------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::ReportKlient( TPrintFormAll *prForm, int idKlient)
{

if(IdKlient==0)
        {
                IBQKl->Active=false;
                IBQKl->ParamByName("DATENACH")->AsDateTime=DateNach->DateTime;
                IBQKl->ParamByName("DATECON")->AsDateTime=DateCon->DateTime;
                IBQKl->Active=true;
                porNumStrGrp=1;
                IBQKl->First();
                while(!IBQKl->Eof)
                        {

                        OutputStringKlient(prForm);
                        numRow++;
                        ReportDoc(prForm,IBQKlIDKLIENT_PROC->AsInteger);
                        porNumStrGrp++;
                        IBQKl->Next();
                        }
         }
else
        {

        ReportDoc(prForm,idKlient);

        }


}
//-----------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::ReportDoc( TPrintFormAll *prForm, int idKlient)
{


        if (idKlient==0)
                {
                        //ZaprosEl=ZaprosEl+" and  IDSKLDOC IS NULL";
                }
        else
                {
                IBQDoc->Active=false;
                IBQDoc->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
                IBQDoc->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
                IBQDoc->ParamByName("PARAM_IDKLIENT")->AsInteger=idKlient;

                IBQDoc->Active=true;
                porNumStr=1;
                IBQDoc->First();
                while(!IBQDoc->Eof)
                        {
                        OutputStringDoc(prForm);numRow++;

                        porNumStr++;
                        IBQDoc->Next();
                        }
                }     
}
//---------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::OutputZagolovokReport(TPrintFormAll *prForm)
{
numRow=2;
numCol=1;

prForm->F1->SheetName[1]="Часть1";
prForm->F1->ShowGridLines=false;

prForm->F1->Row=numRow;
prForm->F1->Col=3;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->RowHeight[numRow]=500;
prForm->F1->Text="Взаиморасчеты с контрагентами за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date); numRow++;

prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdKlient==0)
        {
        prForm->F1->Text="Контрагент: по всем контрагентам. ";
        }
else
        {
        prForm->F1->Text="Контрагент: "+NameKlientEdit->Text;;
        }
numRow++;



numCol=2;
prForm->F1->Row=numRow;
prForm->F1->RowHeight[numRow]=500;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="№";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=500;
numCol++;

//номенклатура
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Контрагент";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=3000;
numCol++;
//нач остаток
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Нач. долг";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;
//приход
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=" Увеличение";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;

//расход
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Уменьшение";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;
//кон. остаток
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Кон. долг";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;

numRow++;
}

//----------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::OutputStringKlient(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IntToStr(porNumStrGrp); numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

//конрагент.
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IBQKlNAMEKLIENT_PROC->AsString;
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

numCol++;
//нач остаток
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQKlNACHOSTSUM->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

AllNachOst=AllNachOst+IBQKlNACHOSTSUM->AsFloat;

numCol++;
//приход
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQKlPRIHODSUM->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
AllPrihod=AllPrihod+IBQKlPRIHODSUM->AsFloat;

numCol++;
//расход
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQKlRASHODSUM->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
AllRashod=AllRashod+IBQKlRASHODSUM->AsFloat;

numCol++;
//кон. остаток
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQKlCONOSTSUM->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
AllConOst=AllConOst+IBQKlCONOSTSUM->AsFloat;
numCol++;

}
//------------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::OutputStringDoc(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=IntToStr(porNumStr);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,1,1);
numCol++;

//номенлатура
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 1, 2, 0);
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->Text=glGetNameDoc(IBQDocTDOC->AsString)+" №"
                +IBQDocNUMDOC->AsString+" от "
                +IBQDocPOSDOC_VSRASCH_DV->AsString;
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);


numCol++;
//нач остаток
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
//if (IBQElNACHOSTSUM->AsFloat!=0)
//        {
//        prForm->F1->Text=FloatToStrF(IBQElNACHOSTSUM->AsFloat,ffFixed,10,2);
//        }
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;
//приход
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
if(IBQDocTDV_VSRASCH_DV->AsInteger==0)
        {
        prForm->F1->Text=FloatToStrF(IBQDocSUM_VSRASCH_DV->AsFloat,ffFixed,10,2);
        }
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;
//расход
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
if (IBQDocTDV_VSRASCH_DV->AsInteger==1)
        {
        prForm->F1->Text=FloatToStrF(IBQDocSUM_VSRASCH_DV->AsFloat,ffFixed,10,2);
        }
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);
numCol++;
//кон. остаток
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
//if(IBQElCONOSTSUM->AsFloat!=0)
//        {
//        prForm->F1->Text=FloatToStrF(IBQElCONOSTSUM->AsFloat,ffFixed,10,2);
//        }
prForm->F1->SetBorder(-1,1,1,1,0,-1,1,1,1,clBlack,1);

numCol++;

}

//--------------------------------------------------------------------------
void TFormaDialogaReportOCBVSRasch::OutputPodavalReport(TPrintFormAll *prForm)
{
numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=""; numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

//конрагент.
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Всего";
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

numCol++;
//нач остаток
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(AllNachOst,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

numCol++;
//приход
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(AllPrihod,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);


numCol++;
//расход
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(AllRashod,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

numCol++;
//кон. остаток
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(AllConOst,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);

numCol++;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBVSRasch::DateNachChange(
      TObject *Sender)
{
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBVSRasch::DateConChange(
      TObject *Sender)
{
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportOCBVSRasch::BitBtnNachPeriodaClick(
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

void __fastcall TFormaDialogaReportOCBVSRasch::BitBtnConPeriodaClick(
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

