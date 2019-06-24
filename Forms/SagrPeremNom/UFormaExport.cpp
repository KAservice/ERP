//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaExport.h"
#include "UDM.h"
#include "UDMSprKKM.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaExport::TFormaExport(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormaExport::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQuery2->Close();
ADOTable1->Close();
ADOTable2->Close();
Action=caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TFormaExport::FormCreate(TObject *Sender)
{
DateCon->Date=Date();
DateNach->Date=Date()-3;
RichEdit1->Clear();

}
//---------------------------------------------------------------------------


//формируем отчет о продажах в каталоге обмена
void  TFormaExport::CreateReport(TDMGurDocCheckKKM * gurnal)
{

//  подключим таблицу отчетов 1
try
        {
        ADOTable1->Active=false;
        ADOTable1->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=Файлы dBASE;Initial Catalog="+
                                        CatalogOtcheta;
        ADOTable1->TableName="Otchet1";
        ADOTable1->Open();
        }
catch(...)
        {
        }

//  поключим таблицу отчетов 2
try
        {
        ADOTable2->Active=false;
        ADOTable2->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=Файлы dBASE;Initial Catalog="+
                                        CatalogOtcheta;
        ADOTable2->TableName="Otchet2";
        ADOTable2->Open();
        }
catch(...)
        {
        }

//сформируем запрос к журналу чеков
//gurnal->Table->First();

        while (!gurnal->Table->Eof)
                {

                ADOTable1->Insert();

                ADOTable1->FieldByName("ID")->AsInteger=gurnal->TableIDDOC->AsInteger;
                ADOTable1->FieldByName("PREFIKS")->AsString="";
                ADOTable1->FieldByName("NDOC")->AsString=gurnal->TableNUMDOC->AsInteger;
                ADOTable1->FieldByName("NUMCHECK")->AsInteger=gurnal->TableNCHECKCHK->AsInteger;
             //   ADOTable1->FieldByName("DATEDOC")->AsString=gurnal->TablePOSDOC->AsString;
                //ADOTable1->FieldByName("TIMEDOC")->AsString=IBQuery1->FieldByName("TIME_DOC")->AsString;
                //ADOTable1->FieldByName("NKKM")->AsString=gurnal->Table"STR_NUMBER_KKM")->AsString;
                ADOTable1->FieldByName("CODEOPER")->AsInteger=gurnal->TableOPERCHK->AsInteger;

                ADOTable1->FieldByName("SUMMA")->AsFloat=gurnal->TableSUMDOC->AsFloat;
                //ADOTable1->FieldByName("DISCAUNT")->AsFloat=IBQueryCheck1->FieldByName("DISCAUNT")->AsFloat;


                //сформируем запрос к табличной части чеков
                IBQuery2->Active=false;
                IBQuery2->ParamByName("IDDOC")->AsInteger=gurnal->TableIDDOC->AsInteger;
                IBQuery2->Open();

                IBQuery2->First();

                while (!IBQuery2->Eof)
                       {
                        ADOTable2->Insert();
                        ADOTable2->FieldByName("ID")->AsInteger=IBQuery2->FieldByName("IDDOCCHKT")->AsInteger;
                        ADOTable2->FieldByName("ID_CHECK")->AsInteger=gurnal->TableIDDOC->AsInteger;
                        ADOTable2->FieldByName("PREFIKS")->AsString="";
                        //ADOTable2->FieldByName("NKKM")->AsString=IBQuery1->FieldByName("STR_NUMBER_KKM")->AsString;
                        ADOTable2->FieldByName("CODETOVAR")->AsString=IBQuery2->FieldByName("CODENOM")->AsString;
                        ADOTable2->FieldByName("SHCODE")->AsString=IBQuery2->FieldByName("SHED")->AsString;
                        ADOTable2->FieldByName("NAMETOVAR")->AsString=IBQuery2->FieldByName("NAMENOM")->AsString;
                        ADOTable2->FieldByName("K")->AsFloat=IBQuery2->FieldByName("KFCHKT")->AsFloat;
                        ADOTable2->FieldByName("KOL")->AsFloat=IBQuery2->FieldByName("KOLCHKT")->AsFloat;
                        //ADOTable2->FieldByName("PRICE")->AsFloat=IBQuery2->FieldByName("PRICECHKT")->AsFloat;
                        if (IBQuery2->FieldByName("KOLCHKT")->AsFloat!=0)
                                {
                                ADOTable2->FieldByName("PRICE")->AsFloat=(IBQuery2->FieldByName("SUMCHKT")->AsFloat
                                                       + IBQuery2->FieldByName("SKCHKT")->AsFloat)
                                                       /IBQuery2->FieldByName("KOLCHKT")->AsFloat;
                                }


                        ADOTable2->FieldByName("SUMMA")->AsFloat=IBQuery2->FieldByName("SUMCHKT")->AsFloat;
                       // ADOTable2->FieldByName("DISCAUNT")->AsFloat=IBQuery2->FieldByName("SUMMA_SKIDOK")->AsFloat;
                        ADOTable2->Post();
                        IBQuery2->Next();
                        }

                ADOTable1->Post();
                gurnal->Table->Next();
                }

        ADOTable1->Close();
        ADOTable2->Close();

}

//---------------------------------------------------------------------------
//формирует файлы отчета в каталоге NameCatalog с текущими настройками TableCheck1//установим интервал дат//копируем чистые файлы отчета в каталог с новыми отчетами
void TFormaExport::CopyTableOtchet(String NameCatalog)
{
//копируем файл отчета 1
String FileName1=CatalogObmena+"\\Otchet1.DBF";
String FileName2=CatalogOtcheta+"\\Otchet1.dbf";

if (CopyFileA(FileName1.c_str(),FileName2.c_str(),1)==false)
        {
        ShowMessage("Ошибка копирования файла отчета 1!" );
        }

//копируем файл отчета 2
FileName1=CatalogObmena+"\\Otchet2.DBF";
FileName2=CatalogOtcheta+"\\Otchet2.dbf";
if (CopyFileA(FileName1.c_str(),FileName2.c_str(),1)==false)
        {
        ShowMessage("Ошибка копирования файла отчета 2!");
        }
}
//--------------------------------------------------------------------------



void __fastcall TFormaExport::cxButtonCreateClick(TObject *Sender)
{
RichEdit1->Clear();
TDMSprKKM * SpisokKKM=new TDMSprKKM(Application);
SpisokKKM->OpenTable();
SpisokKKM->Table->First();
while(!SpisokKKM->Table->Eof)
        {
        RichEdit1->Lines->Add(" Формирование отчета для ККМ:" +SpisokKKM->TableNAMEKKM->AsString);
        TDMGurDocCheckKKM * Gurnal=new TDMGurDocCheckKKM(Application);
        Gurnal->PosNach=DateNach->DateTime;
        Gurnal->PosCon=DateCon->DateTime;
        Gurnal->IdKKM=SpisokKKM->TableIDKKM->AsInteger;
        Gurnal->NumberKL=0;
        Gurnal->UpdateTable();
        int NachNumberKL=0;
        int ConNumberKL=0;
        int TekNumberKL=0;
        Gurnal->Table->First();
        NachNumberKL=Gurnal->TableNKLCHK->AsInteger;
        ConNumberKL=Gurnal->TableNKLCHK->AsInteger;

        while(!Gurnal->Table->Eof)
                {
                if (NachNumberKL>Gurnal->TableNKLCHK->AsInteger )
                        {
                        NachNumberKL=Gurnal->TableNKLCHK->AsInteger;
                        }

                if (ConNumberKL<Gurnal->TableNKLCHK->AsInteger)
                        {
                        ConNumberKL=Gurnal->TableNKLCHK->AsInteger;
                        }
                Gurnal->Table->Next();
                }
                
        RichEdit1->Lines->Add(" Начальный номер КЛ:" +IntToStr(NachNumberKL));
        RichEdit1->Lines->Add(" Конечный номер КЛ:" +IntToStr(ConNumberKL));
        TekNumberKL=NachNumberKL;

        while(TekNumberKL<=ConNumberKL && TekNumberKL>0)
                {
                Gurnal->PosNach=DateNach->DateTime-2;
                Gurnal->PosCon=DateCon->DateTime+2;
                Gurnal->IdKKM=SpisokKKM->TableIDKKM->AsInteger;
                Gurnal->NumberKL=TekNumberKL;
                Gurnal->UpdateTable();
                Gurnal->Table->Last();
                if (Gurnal->Table->RecordCount>0)
                        {
                        //формируем отчет в каталоге обмена
                        CatalogObmena=SpisokKKM->TableCATOBMKKM->AsString;
                        //ShowMessage("Задайте каталог где формировать файлы");
                        CatalogOtcheta=CatalogObmena+"\\CashServer\\"+IntToStr(TekNumberKL)
                                        +" "+DateToStr(Gurnal->TablePOSDOC->AsDateTime);
                        RichEdit1->Lines->Add("Отчет №: " +IntToStr(TekNumberKL));
                        // ShowMessage("Отчет №: " +IntToStr(TekNumberKL));
                        RichEdit1->Lines->Add("Каталог отчета: " +CatalogOtcheta);
                        RichEdit1->Update();
                        Gurnal->Table->First();
                        //удалим каталоги, которые формируются повторно

                        if (FileExists(CatalogOtcheta+"\\Otchet1.dbf")==true)
                                {

                                if (DeleteFile(CatalogOtcheta+"\\Otchet1.dbf")==false )
                                        {
                                        ShowMessage("Не удалось удалить файл отчета 1!");
                                        }
                                }

                        if (FileExists(CatalogOtcheta+"\\Otchet2.dbf")==true)
                                {

                                if (DeleteFile(CatalogOtcheta+"\\Otchet2.dbf")==false )
                                        {
                                        ShowMessage("Не удалось удалить файл отчета 2!");
                                        }
                                }

                        RemoveDir (CatalogOtcheta);

                        //создадим новый каnалог с отчетом

                        CreateDir(CatalogOtcheta);

                        //скопируем чистые файлы в каталог обмена

                        CopyTableOtchet(CatalogOtcheta);

                        CreateReport(Gurnal);
                        }
                else
                        {
                        RichEdit1->Lines->Add("Нет чеков с  КЛ:" +IntToStr(TekNumberKL));
                        }
                TekNumberKL++;
                }
        delete Gurnal;
        SpisokKKM->Table->Next();
        }
delete SpisokKKM;

ShowMessage("Отчеты сформированы!");	
}
//---------------------------------------------------------------------------

