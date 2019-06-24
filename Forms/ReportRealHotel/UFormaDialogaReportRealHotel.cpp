//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialogaReportRealHotel.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
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
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportRealRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
void __fastcall TFormaDialogaReportRealRest::EndEdit(TMessage&a)
{
if (EditRekvisit==ViborSklad)
        {
        if (SpisokSklad->OutReady==true)
                {
                IdSkl=SpisokSklad->DM->ElementIDSKLAD->AsInteger;
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        }

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
TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
SumReport=0;
porNumStrGrp=1;


//шапка
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

PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDialogaReportRealRest::ReportSklad(TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
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
IBQSkl->SQL->Clear();
IBQSkl->SQL->Add(Zapros);
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
void TFormaDialogaReportRealRest::ReportKlient( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
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
IBQKl->SQL->Clear();
IBQKl->SQL->Add(Zapros);
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
void TFormaDialogaReportRealRest::ReportGrpNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
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
IBQGrp->SQL->Clear();
IBQGrp->SQL->Add(ZaprosGrp);
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
void TFormaDialogaReportRealRest::ReportNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl, int idGrp)
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

        IBQEl->SQL->Clear();
        IBQEl->SQL->Add(ZaprosEl);
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
void TFormaDialogaReportRealRest::OutputZagolovokReport(TPrintFormAll *prForm)
{
numRow=2;
numCol=1;

prForm->F1->Row=numRow;
prForm->F1->Col=3;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->RowHeight[numRow]=500;
prForm->F1->Text="Отчет о реализации за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date); numRow++;

prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdSkl==0)
        {
        prForm->F1->Text="Склад: по всем складам. ";
        }
else
        {
        prForm->F1->Text="Склад: "+NameSkladEdit->Text;;
        }
numRow++;

prForm->F1->Row=numRow;
prForm->F1->Col=2;
prForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdKlient==0)
        {
        prForm->F1->Text="Контрагент: по всем контрагентам ";
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
prForm->F1->Text="Наименование";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=5000;
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Количество";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;
//Сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 2, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Сумма";
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
prForm->F1->ColWidth[numCol]=1500;
numCol++;


numRow++;
}

//------------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringSklad( TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//номенклатура
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Склад: "+IBQSkl->FieldByName("NAMESKLAD")->AsString;
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IBQSkl->FieldByName("SUMKOL")->AsString;
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQSkl->FieldByName("SUMMA")->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;

}
//--------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringKlient(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//номенклатура
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Контрагент: "+IBQKl->FieldByName("NAMEKLIENT")->AsString;
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IBQKl->FieldByName("SUMKOL")->AsString;
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQKl->FieldByName("SUMMA")->AsFloat,ffFixed,10,2);
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;

}
//----------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputStringGrp(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IntToStr(porNumStrGrp); numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

//номенклатура
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IBQGrpNAMEGN->AsString;numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
//количество
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=IBQGrpSUMKOL->AsString; numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(IBQGrpSUMMA->AsFloat,ffFixed,10,2); numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);


}
//------------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputString(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=IntToStr(porNumStr);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,1,0,0,0,-1,1,1,1,1,1);
numCol++;

//номенклатура
prForm->F1->Col=numCol;
prForm->F1->Text=IBQElNAMENOM->AsString;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,0,0,0,-1,1,1,1,1,1);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->Text=IBQElSUMKOL->AsString+" "+IBQElNAMEED->AsString;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,0,0,0,-1,1,1,1,1,1);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=FloatToStrF(IBQElSUMMA->AsFloat,ffFixed,10,2);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,1,0,0,-1,1,1,1,1,1);
numCol++;
}

//--------------------------------------------------------------------------
void TFormaDialogaReportRealRest::OutputPodavalReport(TPrintFormAll *prForm)
{
numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=""; numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

//номенклатура
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="Всего: ";numCol++;
prForm->F1->SetBorder(1,1,0,1,1,-1,1,1,1,200,1);
//количество
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=""; numCol++;
prForm->F1->SetBorder(1,0,0,1,1,-1,1,1,1,200,1);
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=FloatToStrF(SumReport,ffFixed,10,2); numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
}
//---------------------------------------------------------------

void __fastcall TFormaDialogaReportRealRest::ButtonViborKlientaClick(
      TObject *Sender)
{
VibratKlienta();        
}
//---------------------------------------------------------------------------

