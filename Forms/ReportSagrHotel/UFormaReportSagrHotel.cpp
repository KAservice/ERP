//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaReportSagrHotel.h"
#include "UPrintFormAll.h"
#include <DateUtils.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormaReportSagrHotel *FormaReportSagrHotel;
//---------------------------------------------------------------------------
__fastcall TFormaReportSagrHotel::TFormaReportSagrHotel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::FormCreate(TObject *Sender)
{
IdCatNom=0;
DateCon->Date=Date()+10;
DateNach->Date=Date();
}
//---------------------------------------------------------------------------
void TFormaReportSagrHotel::UpdateForm()
{
IBQCatNom->Active=false;
IBQCatNom->ParamByName("PARAM_ID")->AsInteger=IdCatNom;
IBQCatNom->Active=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
IBQCatNom->Active=false;
RegBron->Active=false;
RegRasm->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::ButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborCatNom)
        {
        if (SpisokCatNom->OutReady==true)
                {
                IdCatNom=SpisokCatNom->DM->TableID_CATNOM->AsInteger;
                }
        }
UpdateForm();
EditRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void  TFormaReportSagrHotel::OpenFormSpiskaSprCatNom()
{
if (IdDochForm==NULL)
        { 
        SpisokCatNom=new TFormaSpiskaSprCatNom(Application);
        if (!SpisokCatNom) return;
        SpisokCatNom->IdRodForm=Handle;
        SpisokCatNom->Vibor=true;
        IdDochForm=SpisokCatNom->Handle;
        EditRekvisit=ViborCatNom;
//        SpisokCatNom->UpdateForm();
        SpisokCatNom->FOnCloseForm=EndEdit;
        SpisokCatNom->Show();
        }
}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::ButtonOpenCatNomClick(
      TObject *Sender)
{
OpenFormSpiskaSprCatNom();
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSagrHotel::ButtonCreateClick(TObject *Sender)
{
WORD Day;
WORD Month;
WORD Year;
TPrintFormAll  *PrintForm=new TPrintFormAll(Application);
if (!PrintForm) return;

PrintForm->F1->FixedCols=1;
PrintForm->F1->FixedRows=1;

numCol=1;
numRow=2;
PrintForm->F1->Col=numCol;
PrintForm->F1->ColWidth[numCol]=1500;

numCol=2;
numRow=1;

TDate TecDate=DateNach->Date;
PrintForm->F1->Row=numRow;

while(TecDate<DateCon->Date)
        {
        DecodeDate(TecDate,Year,Month,Day);
        PrintForm->F1->Col=numCol;
        PrintForm->F1->ColWidth[numCol]=400;
        PrintForm->F1->SetFont ("MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
        PrintForm->F1->Text=IntToStr(Day);

        numCol++;
        TecDate++;
        }

numRow=2;
CatNom->Active=false;
CatNom->Active=true;
CatNom->First();
while(!CatNom->Eof)
        {
        numCol=1;
        PrintForm->F1->Row=numRow;
        PrintForm->F1->Col=numCol;
        PrintForm->F1->SetFont ("MS Sans Serif", 10, 1, 0, 0, 0, 1, 1, 1 );
        PrintForm->F1->Text=CatNomNAME_CATNOM->AsString+
        numRow++;

        IBQNom->Active=false;
        IBQNom->ParamByName("PARAM_IDCAT")->AsInteger=CatNomID_CATNOM->AsInteger;
        IBQNom->Active=true;

        IBQNom->First();
        while(!IBQNom->Eof)
                {
                numCol=1;
                PrintForm->F1->Row=numRow;
                PrintForm->F1->Col=numCol;
                PrintForm->F1->SetFont ("MS Sans Serif", 8, 0, 0, 0, 0, 1, 1, 1 );
                PrintForm->F1->Text=IBQNomNAME_NOMHOT->AsString
                                +" ("+IBQNomKOLM_NOMHOT->AsInteger+")";

                WORD D;
                WORD M;
                WORD Y;
                DecodeDate(DateNach->Date,Y,M,D);
                TDateTime TecNachPos=EncodeDateTime(Y,M,D,0,0,0,0);
                TDateTime TecConPos=EncodeDateTime(Y,M,D,12,0,0,0);
                int Nom=1;
                while (TecNachPos<DateCon->DateTime)
                        {
                        Nom++;
                        //регистр бронирование
                        //1 половина суток
                        RegBron->Active=false;
                        RegBron->ParamByName("PARAM_IDNOMER")->AsInteger=IBQNomID_NOMHOT->AsInteger;
                        RegBron->ParamByName("NACH")->AsDateTime=TecNachPos;
                        RegBron->ParamByName("CON")->AsDateTime=TecConPos;
                        RegBron->Active=true;
                        int KolBronMest1=0;

                        RegBron->First();
                        while(!RegBron->Eof)
                                {
                                KolBronMest1=KolBronMest1+RegBronKOLMEST_RGBRON->AsInteger;
                                RegBron->Next();
                                }

                        //2 половина суток
                        RegBron->Active=false;
                        RegBron->ParamByName("PARAM_IDNOMER")->AsInteger=IBQNomID_NOMHOT->AsInteger;
                        RegBron->ParamByName("NACH")->AsDateTime=TecConPos;
                        RegBron->ParamByName("CON")->AsDateTime=TecNachPos+1;
                        RegBron->Active=true;
                        int KolBronMest2=0;

                        RegBron->First();
                        while(!RegBron->Eof)
                                {
                                KolBronMest2=KolBronMest2+RegBronKOLMEST_RGBRON->AsInteger;
                                RegBron->Next();
                                }

                        numCol=Nom;
                        PrintForm->F1->Row=numRow;
                        PrintForm->F1->Col=numCol;
                        PrintForm->F1->SetFont ( "MS Sans Serif", 8, 1, 0, 0, 0, clNavy, clNavy, 1 );

                        String Str="";
                        if ( KolBronMest1!=0)  Str=IntToStr(KolBronMest1);
                        else  Str=" ";
                        Str=Str+"/";
                        if ( KolBronMest2!=0)  Str=Str+IntToStr(KolBronMest2);
                        else Str=Str+" ";
                        if (Str!=" / "){PrintForm->F1->Text=Str;}
                        numRow++;



                        //регистр размещение
                        //1 половина суток
                        RegRasm->Active=false;
                        RegRasm->ParamByName("PARAM_IDNOMER")->AsInteger=IBQNomID_NOMHOT->AsInteger;
                        RegRasm->ParamByName("NACH")->AsDateTime=TecNachPos;
                        RegRasm->ParamByName("CON")->AsDateTime=TecConPos;
                        RegRasm->Active=true;
                        int KolRasmMest1=0;

                        RegRasm->First();
                        while(!RegRasm->Eof)
                                {
                                KolRasmMest1=KolRasmMest1+RegRasmKOLMEST_RGRASM->AsInteger;
                                RegRasm->Next();
                                }

                        //2 половина суток
                        RegRasm->Active=false;
                        RegRasm->ParamByName("PARAM_IDNOMER")->AsInteger=IBQNomID_NOMHOT->AsInteger;
                        RegRasm->ParamByName("NACH")->AsDateTime=TecConPos;
                        RegRasm->ParamByName("CON")->AsDateTime=TecNachPos+1;
                        RegRasm->Active=true;
                        int KolRasmMest2=0;

                        RegRasm->First();
                        while(!RegRasm->Eof)
                                {
                                KolRasmMest2=KolRasmMest2+RegRasmKOLMEST_RGRASM->AsInteger;
                                RegRasm->Next();
                                }

                        numCol=Nom;
                        PrintForm->F1->Row=numRow;
                        PrintForm->F1->Col=numCol;
                        PrintForm->F1->SetFont ( "MS Sans Serif", 8, 1, 0, 0, 0, clGreen, clGreen, 1 );

                        Str="";
                        if ( KolRasmMest1!=0)  Str=IntToStr(KolRasmMest1);
                        else  Str=" ";
                        Str=Str+"/";
                        if ( KolRasmMest2!=0)  Str=Str+IntToStr(KolRasmMest2);
                        else Str=Str+" ";
                        if (Str!=" / "){PrintForm->F1->Text=Str;}
                        numRow--;


                        TecNachPos=TecNachPos+1;
                        TecConPos=TecConPos+1;
                        }
                numRow++;
                numRow++;
                IBQNom->Next();
                }
        CatNom->Next();
        }




PrintForm->Show();

              //  for (int i=0; i<IBQNomKOLM_NOMHOT->AsInteger;i++)
              //          {
              //          numCol=1;
              //          PrintForm->F1->Row=numRow;
              //          PrintForm->F1->Col=numCol;
              //          PrintForm->F1->SetFont ("MS Sans Serif", 8, 0, 0, 0, 0, 1, 1, 1 );
              //          PrintForm->F1->Text=IBQNomNAME_NOMHOT->AsString
              //                  +" ("+IBQNomKOLM_NOMHOT->AsInteger+")";
              //          numRow++;
              //          }
}
//---------------------------------------------------------------------------

