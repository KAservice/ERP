//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialogaReportRealRest.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportRealRest::TFormaDialogaReportRealRest(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

NameSkladEdit->Text="";
NameKlientEdit->Text="";
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->Close();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->Close();
IBQGrp->Active=false;

Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                IdSkl=SpisokSklad->DM->ElementIDSKLAD->AsInteger;
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
        }

if (EditRekvisit==ViborKlient)
        {
        if (FormaSpiskaSprKlient->OutReady==true)
                {
                IdKlient=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInteger;
                NameKlientEdit->Text=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
                }
        FormaSpiskaSprKlient=0;
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OpenFormSpiskaSprSklad(void)
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
void TFormaDialogaReportRealRest::VibratKlienta(void)
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
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::ButtonRunClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
SumReport=0;
porNumStrGrp=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
if (IdSkl==0 && IdKlient==0)
        {
        ReportSklad(PrintForm,0,true,0,true);
        }

if (IdSkl!=0 && IdKlient==0)
        {
        ReportSklad(PrintForm,IdSkl,false,0,true);
        }

if (IdSkl==0 && IdKlient!=0)
        {
        ReportSklad(PrintForm,0,true,IdKlient,false);
        }

if (IdSkl!=0 && IdKlient!=0)
        {
        ReportSklad(PrintForm,IdSkl,false,IdKlient,false);
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDialogaReportRealRest::ReportSklad(TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String Zapros="";

Zapros=          " select  NAMESKLAD, IDSKLAD,SUM(SUM_REALRESTT)  AS SUMMA, SUM(KF_REALRESTT*KOL_REALRESTT)  AS SUMKOL" ;
Zapros=Zapros+" from DREALRESTT ";
Zapros=Zapros+" left outer join SNOM on IDNOM_REALRESTT=IDNOM";
Zapros=Zapros+" left outer join GALLDOC on IDDOC_REALRESTT=IDDOC ";
Zapros=Zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD";
Zapros=Zapros+" where POSDOC  between :PARAM_POSNACH and :PARAM_POSCON ";

if (allSkl!=true)
        {

        if (idSkl==0)
                {
                Zapros=Zapros+" and  IDSKLDOC IS NULL";
                }
        else
                {
                Zapros=Zapros+" and  IDSKLDOC="+IntToStr(idSkl);
                }
        }

if (allKl!=true)
        {
        if (idKl==0)
                {
                Zapros=Zapros+" and  IDKLDOC IS NULL";
                }
        else
                {
                Zapros=Zapros+" and  IDKLDOC="+IntToStr(idKl);
                }
        }

Zapros=Zapros+" group by NAMESKLAD, IDSKLAD ";
SumReport=0;
IBQSkl->Active=false;
IBQSkl->SelectSQL->Clear();
IBQSkl->SelectSQL->Add(Zapros);
IBQSkl->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
IBQSkl->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
IBQSkl->Active=true;

IBQSkl->First();
while(!IBQSkl->Eof)
        {

        OutputStringSklad(prForm);
        SumReport=SumReport+IBQSkl->FieldByName("SUMMA")->AsFloat;
        numRow++;
        ReportKlient(prForm,IBQSkl->FieldByName("IDSKLAD")->AsInteger, false,idKl,allKl);
        IBQSkl->Next();
        }
}
//----------------------------------------------------------------------------
void TFormaDialogaReportRealRest::ReportKlient( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String Zapros="";

Zapros=       " select NAMEKLIENT,IDKLIENT,SUM(SUM_REALRESTT)  AS SUMMA, SUM(KF_REALRESTT*KOL_REALRESTT)  AS SUMKOL" ;
Zapros=Zapros+" from DREALRESTT ";
Zapros=Zapros+" left outer join SNOM on IDNOM_REALRESTT=IDNOM";
Zapros=Zapros+" left outer join GALLDOC on IDDOC_REALRESTT=IDDOC ";
Zapros=Zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
Zapros=Zapros+" where POSDOC  between :PARAM_POSNACH and :PARAM_POSCON ";

if (allSkl!=true)
        {

        if (idSkl==0)
                {
                Zapros=Zapros+" and  IDSKLDOC IS NULL";
                }
        else
                {
                Zapros=Zapros+" and  IDSKLDOC="+IntToStr(idSkl);
                }
        }

if (allKl!=true)
        {
        if (idKl==0)
                {
                Zapros=Zapros+" and  IDKLDOC IS NULL";
                }
        else
                {
                Zapros=Zapros+" and  IDKLDOC="+IntToStr(idKl);
                }
        }

Zapros=Zapros+" group by NAMEKLIENT, IDKLIENT ";

IBQKl->Active=false;
IBQKl->SelectSQL->Clear();
IBQKl->SelectSQL->Add(Zapros);
IBQKl->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
IBQKl->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
IBQKl->Active=true;

IBQKl->First();
while(!IBQKl->Eof)
        {

        OutputStringKlient(prForm);
        numRow++;
        ReportGrpNom(prForm,idSkl,allSkl,IBQKl->FieldByName("IDKLIENT")->AsInteger,false);
        IBQKl->Next();
        }
}
//--------------------------------------------------------------------------
void TFormaDialogaReportRealRest::ReportGrpNom( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String ZaprosGrp="";

ZaprosGrp=          " select  NAMEGN, IDGN,SUM(SUM_REALRESTT)  AS SUMMA, SUM(KF_REALRESTT*KOL_REALRESTT)  AS SUMKOL" ;
ZaprosGrp=ZaprosGrp+" from DREALRESTT ";
ZaprosGrp=ZaprosGrp+" left outer join SNOM on IDNOM_REALRESTT=IDNOM";
ZaprosGrp=ZaprosGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";
ZaprosGrp=ZaprosGrp+" left outer join GALLDOC on IDDOC_REALRESTT=IDDOC ";
ZaprosGrp=ZaprosGrp+" where POSDOC  between :PARAM_POSNACH and :PARAM_POSCON ";

if (allSkl!=true)
        {

        if (idSkl==0)
                {
                ZaprosGrp=ZaprosGrp+" and  IDSKLDOC IS NULL";
                }
        else
                {
                ZaprosGrp=ZaprosGrp+" and  IDSKLDOC="+IntToStr(idSkl);
                }
        }

if (allKl!=true)
        {
        if (idKl==0)
                {
                ZaprosGrp=ZaprosGrp+" and  IDKLDOC IS NULL";
                }
        else
                {
                ZaprosGrp=ZaprosGrp+" and  IDKLDOC="+IntToStr(idKl);
                }
        }


ZaprosGrp=ZaprosGrp+" group by NAMEGN, IDGN ";

IBQGrp->Active=false;
IBQGrp->SelectSQL->Clear();
IBQGrp->SelectSQL->Add(ZaprosGrp);
IBQGrp->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
IBQGrp->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
IBQGrp->Active=true;
porNumStrGrp=1;
IBQGrp->First();
while(!IBQGrp->Eof)
        {

        OutputStringGrp(prForm);
        numRow++;
        ReportNom(prForm,idSkl,allSkl,idKl,allKl,IBQGrp->FieldByName("IDGN")->AsInteger);
        porNumStrGrp++;
        IBQGrp->Next();
        }
}
//-----------------------------------------------------------------------
void TFormaDialogaReportRealRest::ReportNom( TSheetEditor *prForm, int idSkl, bool allSkl, int idKl, bool allKl, int idGrp)
{
        IBQEl->Active=false;

        String ZaprosEl="select  NAMENOM, NAMEED, SUM(SUM_REALRESTT)  AS SUMMA, SUM(KF_REALRESTT*KOL_REALRESTT)  AS SUMKOL";
        ZaprosEl=ZaprosEl+" from  DREALRESTT ";
        ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOM_REALRESTT=IDNOM";
        ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosEl=ZaprosEl+" left outer join GALLDOC on IDDOC_REALRESTT=IDDOC";
        ZaprosEl=ZaprosEl+" where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)";
        ZaprosEl=ZaprosEl+" and  (IDGN=:PARAM_IDGN) ";

        if (allSkl!=true)
                {

                if (idSkl==0)
                        {
                        ZaprosEl=ZaprosEl+" and  IDSKLDOC IS NULL";
                        }
                else
                        {
                        ZaprosEl=ZaprosEl+" and  IDSKLDOC="+IntToStr(idSkl);
                        }
                }

        if (allKl!=true)
                {
                if (idKl==0)
                        {
                        ZaprosEl=ZaprosEl+" and  IDKLDOC IS NULL";
                        }
                else
                        {
                        ZaprosEl=ZaprosEl+" and  IDKLDOC="+IntToStr(idKl);
                        }
                }

        ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED ";

		IBQEl->SelectSQL->Clear();
        IBQEl->SelectSQL->Add(ZaprosEl);
        IBQEl->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->DateTime;
        IBQEl->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->DateTime;
        IBQEl->ParamByName("PARAM_IDGN")->AsInteger=IBQGrpIDGN->AsInteger;
        IBQEl->Active=true;
        porNumStr=1;
        IBQEl->First();
        while(!IBQEl->Eof)
                {
                OutputString(prForm);numRow++;
                porNumStr++;
                IBQEl->Next();
                }

}
//---------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputZagolovokReport(TSheetEditor *prForm)
{
numRow=2;
numCol=2;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 20;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 300;
        cHeader->Size[3] = 80;
        cHeader->Size[4] = 80;
  
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Отчет о реализации за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IdSkl==0)
        {
        cell->Text="Склад: по всем складам. ";
        }
else
        {
        cell->Text="Склад: "+NameSkladEdit->Text;;
        }
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IdKlient==0)
        {
        cell->Text="Контрагент: по всем контрагентам ";
        }
else
        {
        cell->Text="Контрагент: "+NameKlientEdit->Text;;
        }
delete cell;
numRow++;

numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Количество";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
}

//------------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringSklad( TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+IBQSkl->FieldByName("NAMESKLAD")->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQSkl->FieldByName("SUMKOL")->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQSkl->FieldByName("SUMMA")->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;

}
//--------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringKlient(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Font->Size = 12;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Контрагент: "+IBQKl->FieldByName("NAMEKLIENT")->AsString;
cell->Style->Font->Size = 12;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQKl->FieldByName("SUMKOL")->AsString;
cell->Style->Font->Size = 12;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQKl->FieldByName("SUMMA")->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 12;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}
//----------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringGrp(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStrGrp);
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQGrpNAMEGN->AsString;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQGrpSUMKOL->AsString;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQGrpSUMMA->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


}
//------------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQElNAMENOM->AsString;
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQElSUMKOL->AsString+" "+IBQElNAMEED->AsString;
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQElSUMMA->AsFloat,ffFixed,10,2);
cell->Style->Font->FontColor=10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
}

//--------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;

//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Всего: ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(SumReport,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}
//---------------------------------------------------------------

void __fastcall TFormaDialogaReportRealRest::ButtonViborKlientaClick(
      TObject *Sender)
{
VibratKlienta();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportRealRest::BitBtnNachPeriodaClick(
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

void __fastcall TFormaDialogaReportRealRest::BitBtnConPeriodaClick(
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

void __fastcall TFormaDialogaReportRealRest::DateNachChange(
      TObject *Sender)
{
PosNachLabel->Caption=DateTimeToStr(DateNach->DateTime);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportRealRest::DateConChange(TObject *Sender)
{
PosConLabel->Caption=DateTimeToStr(DateCon->DateTime);
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportRealRest::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Report/RepRealRest");	
}
//---------------------------------------------------------------------------

