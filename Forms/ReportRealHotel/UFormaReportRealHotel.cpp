//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportRealHotel.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportRealHotel::TFormaReportRealHotel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
DateCon->Date.DecodeDate(&Year,&Month,&Day);
DateNach->Date=DateCon->Date-Day+1;

NameGrpNomEdit->Text="";
NameSkladEdit->Text="";
NameKlientEdit->Text="";
IdSkl=0;
IdKlient=0;
NumberStrKlient=1;
NumberStrSklad=1;
NumberStrGrp=1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQGrp->Active=false;

Action=caFree;
}

//---------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::ButtonCloseClick(
      TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::EndEdit(TObject *Sender)
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

if (EditRekvisit==ViborGrpNom)
        {
        if (SprGrpNom->OutReady==true)
                {
                IdGrpNom=SprGrpNom->DMGrp->ElementIDGN->AsInteger;
                NameGrpNomEdit->Text=SprGrpNom->DMGrp->ElementNAMEGN->AsString;
                }
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void TFormaReportRealHotel::OpenFormSpiskaSprSklad(void)
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
void TFormaReportRealHotel::VibratKlienta(void)
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
void __fastcall TFormaReportRealHotel::ButtonViborSkladClick(
      TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::ButtonRunClick(TObject *Sender)
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
void TFormaReportRealHotel::ReportSklad(TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String Zapros="";

Zapros=          " select  NAMESKLAD, IDSKLAD,SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL" ;
Zapros=Zapros+" from DSCHET_HOT_T ";
Zapros=Zapros+" left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM";
Zapros=Zapros+" left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC ";
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
void TFormaReportRealHotel::ReportKlient( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String Zapros="";

Zapros=       " select NAMEKLIENT,IDKLIENT,SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL" ;
Zapros=Zapros+" from DSCHET_HOT_T ";
Zapros=Zapros+" left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM";
Zapros=Zapros+" left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC ";
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
void TFormaReportRealHotel::ReportGrpNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl)
{
String ZaprosGrp="";

ZaprosGrp=          " select  NAMEGN, IDGN,SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL" ;
ZaprosGrp=ZaprosGrp+" from DSCHET_HOT_T ";
ZaprosGrp=ZaprosGrp+" left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM";
ZaprosGrp=ZaprosGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";
ZaprosGrp=ZaprosGrp+" left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC ";
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
void TFormaReportRealHotel::ReportNom( TPrintFormAll *prForm, int idSkl, bool allSkl, int idKl, bool allKl, int idGrp)
{
        IBQEl->Active=false;

        String ZaprosEl="select  NAMENOM, NAMEED, SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL";
        ZaprosEl=ZaprosEl+" from  DSCHET_HOT_T ";
        ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM";
        ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosEl=ZaprosEl+" left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC";
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
void TFormaReportRealHotel::OutputZagolovokReport(TPrintFormAll *prForm)
{
//numRow=2;
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
void TFormaReportRealHotel::OutputStringSklad( TPrintFormAll *prForm)
{
NumberStrSklad=numRow;
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
prForm->F1->Text="Склад: "+IBQ->FieldByName("NAMESKLAD")->AsString;
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clGray,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 14, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
numRow++;
}
//--------------------------------------------------------------------------
void TFormaReportRealHotel::OutputStringKlient(TPrintFormAll *prForm)
{
NumberStrKlient=numRow;
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
prForm->F1->Text="Контрагент: "+IBQ->FieldByName("NAMEKLIENT")->AsString;
prForm->F1->SetBorder(-1,0,0,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetPattern(1,clSilver,clSilver);
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 12, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text="";
prForm->F1->SetBorder(-1,1,1,1,1,-1,1,1,1,clBlack,1);
prForm->F1->SetRowHeightAuto(numRow,numCol,numRow,numCol,true);
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
void TFormaReportRealHotel::OutputStringGrp(TPrintFormAll *prForm)
{
NumberStrGrp=numRow;
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
prForm->F1->Text=IBQ->FieldByName("NAMEGN")->AsString;numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
//количество
prForm->F1->Col=numCol;
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=""; numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
prForm->F1->Text=""; numCol++;
prForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);

numRow++;
}
//------------------------------------------------------------------------------
void TFormaReportRealHotel::OutputString(TPrintFormAll *prForm)
{

numCol=2;
prForm->F1->Row=numRow;
//порядковый номер строки
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text="";
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,1,0,0,0,-1,1,1,1,1,1);
numCol++;

//номенклатура
prForm->F1->Col=numCol;
prForm->F1->Text=IBQ->FieldByName("NAMENOM")->AsString;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,0,0,0,-1,1,1,1,1,1);
numCol++;
//количество
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=IBQ->FieldByName("SUMKOL")->AsString+" "+IBQElNAMEED->AsString;
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,0,0,0,-1,1,1,1,1,1);
numCol++;
//сумма
prForm->F1->Col=numCol;
prForm->F1->SetAlignment( 4, 0, 2, 0);
prForm->F1->Text=FloatToStrF(IBQ->FieldByName("SUMMA")->AsFloat,ffFixed,10,2);
prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
prForm->F1->SetBorder(-1,0,1,0,0,-1,1,1,1,1,1);
numCol++;
numRow++;

//        if ( RasvorotKlientCheckBox->Checked==true)
//                {
//prForm->F1->Col=numCol;
//prForm->F1->SetAlignment( 4, 0, 2, 0);
//prForm->F1->Text=IBQ->FieldByName("NAMEKLIENT")->AsString;
//prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
//prForm->F1->SetBorder(-1,0,1,0,0,-1,1,1,1,1,1);
//numCol++;
//                }
//        if ( RasvorotSkladCheckBox->Checked==true)
//                {
//prForm->F1->Col=numCol;
//prForm->F1->SetAlignment( 4, 0, 2, 0);
//prForm->F1->Text=IBQ->FieldByName("NAMESKLAD")->AsString;
//prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
//prForm->F1->SetBorder(-1,0,1,0,0,-1,1,1,1,1,1);
//numCol++;
//                }
//
//prForm->F1->Col=numCol;
//prForm->F1->SetAlignment( 4, 0, 2, 0);
//prForm->F1->Text=IBQ->FieldByName("NAMEGN")->AsString;
//prForm->F1->SetFont ( "MS Sans Serif", 8, 0, 0, 0, 0, clNavy, clNavy, 1 );
//prForm->F1->SetBorder(-1,0,1,0,0,-1,1,1,1,1,1);
//numCol++;

}

//--------------------------------------------------------------------------
void TFormaReportRealHotel::OutputPodavalReport(TPrintFormAll *prForm)
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
numRow++;   numRow++;numRow++;


}
//---------------------------------------------------------------

void __fastcall TFormaReportRealHotel::ButtonViborKlientaClick(
      TObject *Sender)
{
VibratKlienta();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRealHotel::ButtonCreateReportClick(
      TObject *Sender)
{
numRow=1;
numCol=1;

TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;

if (PoDateCheckBox->Checked==true)
        {
        TDateTime TekDateTime=DateNach->DateTime;
        while (DateCon->DateTime>=TekDateTime)
                {
                CreateReport(PrintForm, TekDateTime, TekDateTime+1);
                TekDateTime=TekDateTime+1;
                }
        }
else
        {
        CreateReport(PrintForm, DateNach->DateTime, DateCon->DateTime);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRealHotel::AllSkladCheckBoxClick(
      TObject *Sender)
{
if (AllSkladCheckBox->Checked==true)
        {
        NameSkladEdit->Text="Все склады";
        
        }
else
        {
        NameSkladEdit->Text="";
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRealHotel::AllKlientCheckBoxClick(
      TObject *Sender)
{
if (AllKlientCheckBox->Checked==true)
        {
        NameKlientEdit->Text="Все контрагенты";
        
        }
else
        {
        NameKlientEdit->Text="";
        }
}
//---------------------------------------------------------------------------
void TFormaReportRealHotel::CreateReport(TPrintFormAll *PrintForm, TDateTime nach, TDateTime con)
{


        IBQ->Active=false;

        String Zapros="select  NAMENOM, NAMEED, SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL, NAMEGN";
        if ( RasvorotKlientCheckBox->Checked==true)
                {
                Zapros=Zapros+", NAMEKLIENT";
                }
        if ( RasvorotSkladCheckBox->Checked==true)
                {
                Zapros=Zapros+", NAMESKLAD";
                }

        Zapros=Zapros+" from  DSCHET_HOT_T ";

        Zapros=Zapros+" left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM";
        Zapros=Zapros+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        Zapros=Zapros+" left outer join SED on IDBASEDNOM=IDED";
        Zapros=Zapros+" left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC";
        Zapros=Zapros+" left outer join SSKLAD on IDSKLAD=IDSKLDOC";
        Zapros=Zapros+" left outer join SKLIENT on IDKLIENT=IDKLDOC";


        Zapros=Zapros+" where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)";

        if (AllSkladCheckBox->Checked!=true)
                {
                if (IdSkl==0)
                        {
                        Zapros=Zapros+" and IDSKLAD IS NULL";
                        }
                else
                        {
                        Zapros=Zapros+" and IDSKLAD="+IntToStr(IdSkl);
                        }
                }

        if (AllKlientCheckBox->Checked!=true)
                {
                if (IdSkl==0)
                        {
                        Zapros=Zapros+" and IDKLIENT IS NULL";
                        }
                else
                        {
                        Zapros=Zapros+" and IDKLIENT="+IntToStr(IdKlient);
                        }
                }

                if (IdGrpNom==0)
                        {
                        }
                else
                        {
                        Zapros=Zapros+" and IDGN="+IntToStr(IdGrpNom);
                        }

        Zapros=Zapros+" group by NAMENOM, NAMEED, NAMEGN ";


        if ( RasvorotKlientCheckBox->Checked==true)
                {

                Zapros=Zapros+", NAMEKLIENT";
                }
        if ( RasvorotSkladCheckBox->Checked==true)
                {
                Zapros=Zapros+", NAMESKLAD";
                }

       Zapros=Zapros+" order by ";

       bool Comma=false;
       
        if ( RasvorotSkladCheckBox->Checked==true)
                {
                Zapros=Zapros+" NAMESKLAD";
                Comma=true;
                }

        if ( RasvorotKlientCheckBox->Checked==true)
                {
                if (Comma==true)
                        {
                        Zapros=Zapros+", NAMEKLIENT";
                        }
                else
                        {
                         Zapros=Zapros+" NAMEKLIENT";
                         Comma=true;
                        }
                }

        if (Comma==true)
                {
                Zapros=Zapros+", NAMEGN, NAMENOM ";
                }
        else
                {
                Zapros=Zapros+" NAMEGN, NAMENOM ";
                }

        //ShowMessage(Zapros);
        IBQ->SQL->Clear();
        IBQ->SQL->Add(Zapros);
        IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=nach;
        IBQ->ParamByName("PARAM_POSCON")->AsDateTime=con;
        IBQ->Active=true;

        if (IBQ->RecordCount==0)
                {
                return;
                }


SumReport=0;
porNumStrGrp=1;
SumSklad=0;
SumKlient=0;
SumGrp=0;

//шапка
//OutputZagolovokReport(PrintForm);
numCol=1;

PrintForm->F1->Row=numRow;
PrintForm->F1->Col=3;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
PrintForm->F1->RowHeight[numRow]=500;
if (PoDateCheckBox->Checked==true)
        {
PrintForm->F1->Text="Отчет о реализации за "+DateToStr(nach); numRow++;
        }
else
        {
PrintForm->F1->Text="Отчет о реализации за период с "+DateToStr(nach)
                        +" по "+DateToStr(con); numRow++;
        }

PrintForm->F1->Row=numRow;
PrintForm->F1->Col=2;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdSkl==0)
        {
        PrintForm->F1->Text="Склад: по всем складам. ";
        }
else
        {
        PrintForm->F1->Text="Склад: "+NameSkladEdit->Text;;
        }
numRow++;

PrintForm->F1->Row=numRow;
PrintForm->F1->Col=2;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdKlient==0)
        {
        PrintForm->F1->Text="Контрагент: по всем контрагентам ";
        }
else
        {
        PrintForm->F1->Text="Контрагент: "+NameKlientEdit->Text;;
        }
numRow++; 

PrintForm->F1->Row=numRow;
PrintForm->F1->Col=2;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
if (IdGrpNom==0)
        {
        }
else
        {
        PrintForm->F1->Text="Группа номенклатуры: "+NameGrpNomEdit->Text;
        }
numRow++;

numCol=2;
PrintForm->F1->Row=numRow;
PrintForm->F1->RowHeight[numRow]=500;
//порядковый номер строки
PrintForm->F1->Col=numCol;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
PrintForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
PrintForm->F1->Text="№";
PrintForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
PrintForm->F1->ColWidth[numCol]=500;
numCol++;

//номенклатура
PrintForm->F1->Col=numCol;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
PrintForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
PrintForm->F1->Text="Наименование";
PrintForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
PrintForm->F1->ColWidth[numCol]=5000;
numCol++;
//количество
PrintForm->F1->Col=numCol;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
PrintForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
PrintForm->F1->Text="Количество";
PrintForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
PrintForm->F1->ColWidth[numCol]=1500;
numCol++;
//Сумма
PrintForm->F1->Col=numCol;
PrintForm->F1->SetAlignment( 2, 0, 2, 0);
PrintForm->F1->SetFont ( "MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
PrintForm->F1->Text="Сумма";
PrintForm->F1->SetBorder(1,1,1,1,1,-1,1,1,1,200,1);
PrintForm->F1->ColWidth[numCol]=1500;
numCol++;


numRow++;

String TekSklad="";
String TekKlient="";
String TekGrp="";


        porNumStr=1;
        IBQ->First();

        if ( RasvorotSkladCheckBox->Checked==true)
                {
                TekSklad=IBQ->FieldByName("NAMESKLAD")->AsString;
                OutputStringSklad(PrintForm);
                //SumSklad=IBQ->FieldByName("SUMMA")->AsFloat;
                }
        if ( RasvorotKlientCheckBox->Checked==true)
                {
                TekKlient=IBQ->FieldByName("NAMEKLIENT")->AsString;
                OutputStringKlient(PrintForm);
                //SumKlient=IBQ->FieldByName("SUMMA")->AsFloat;
                }

        TekGrp=IBQ->FieldByName("NAMEGN")->AsString;
        //SumGrp=IBQ->FieldByName("SUMMA")->AsFloat;
        OutputStringGrp(PrintForm);

        while(!IBQ->Eof)
                {

                if ( RasvorotKlientCheckBox->Checked==true)
                        {
                        if (TekKlient!=IBQ->FieldByName("NAMEKLIENT")->AsString)
                                {     //новый клиент
                                //выведем сумму по клиенту
                                //сумма
                                PrintForm->F1->Col=5;
                                PrintForm->F1->Row=NumberStrKlient;
                                PrintForm->F1->Text=FloatToStrF(SumKlient, ffFixed,10,2);
                                OutputStringKlient(PrintForm);
                                TekKlient=IBQ->FieldByName("NAMEKLIENT")->AsString;
                                SumKlient=IBQ->FieldByName("SUMMA")->AsFloat;
                                }
                        else
                                {
                                SumKlient=SumKlient+IBQ->FieldByName("SUMMA")->AsFloat;
                                }
                        }
                if ( RasvorotSkladCheckBox->Checked==true)
                        {
                        if(TekSklad!=IBQ->FieldByName("NAMESKLAD")->AsString)
                                {
                                //выведем сумму по складу
                                //сумма
                                PrintForm->F1->Col=5;
                                PrintForm->F1->Row=NumberStrSklad;
                                PrintForm->F1->Text=FloatToStrF(SumSklad, ffFixed,10,2);
                                OutputStringSklad(PrintForm);
                                TekSklad=IBQ->FieldByName("NAMESKLAD")->AsString;
                                SumSklad=IBQ->FieldByName("SUMMA")->AsFloat;
                                }
                        else
                                {
                                SumSklad=SumSklad+IBQ->FieldByName("SUMMA")->AsFloat;
                                }

                        }

                if(TekGrp!=IBQ->FieldByName("NAMEGN")->AsString)
                        {
                                //выведем сумму по складу
                                //сумма
                                PrintForm->F1->Col=5;
                                PrintForm->F1->Row=NumberStrGrp;
                                PrintForm->F1->Text=FloatToStrF(SumGrp, ffFixed,10,2);

                        OutputStringGrp(PrintForm);

                        TekGrp=IBQ->FieldByName("NAMEGN")->AsString;
                        SumGrp=IBQ->FieldByName("SUMMA")->AsFloat;
                        }
                else
                        {
                        SumGrp=SumGrp+IBQ->FieldByName("SUMMA")->AsFloat;
                        }

                OutputString(PrintForm);
                porNumStr++;
                SumReport=SumReport+IBQ->FieldByName("SUMMA")->AsFloat;
                IBQ->Next();
                }


 //для последней записи
                if ( RasvorotKlientCheckBox->Checked==true)
                        {
                                PrintForm->F1->Col=5;
                                PrintForm->F1->Row=NumberStrKlient;
                                PrintForm->F1->Text=FloatToStrF(SumKlient, ffFixed,10,2);
                        }
                if ( RasvorotSkladCheckBox->Checked==true)
                        {
                                //выведем сумму по складу
                                //сумма
                                PrintForm->F1->Col=5;
                                PrintForm->F1->Row=NumberStrSklad;
                                PrintForm->F1->Text=FloatToStrF(SumSklad, ffFixed,10,2);
                        }

                        PrintForm->F1->Col=5;
                        PrintForm->F1->Row=NumberStrGrp;
                        PrintForm->F1->Text=FloatToStrF(SumGrp, ffFixed,10,2);




OutputPodavalReport(PrintForm);
}

//--------------------------------------------------------------------------
void __fastcall TFormaReportRealHotel::OpenGrpNomButtonClick(
      TObject *Sender)
{
SprGrpNom=new TFormaSpiskaSprGrpNom(Application);
if (!SprGrpNom) return;
//настройка формы
SprGrpNom->Vibor=True;
EditRekvisit=ViborGrpNom;
SprGrpNom->FOnCloseForm=EndEdit;
SprGrpNom->UpdateForm();
SprGrpNom->HintLabel->Caption="Выберите группу для отчета";
SprGrpNom->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRealHotel::ClearViborGrpNomButtonClick(
      TObject *Sender)
{
IdGrpNom=0;
NameGrpNomEdit->Text="";
}
//---------------------------------------------------------------------------

