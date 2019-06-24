//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaGurDocRecKDR.h"
#include "UFormaDocPrihNakl.h"
#include "UDMSprUser.h"
#include "UFormaDocRecKDR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TFormaGurDocRecKDR::TFormaGurDocRecKDR(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::FormCreate(TObject *Sender)
{
DM=new TDMGurDocRecKDR(Application);
DBGrid1->DataSource=DM->DataSourceTable;

PosNach=0;
PosCon=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
PosCon.DecodeDate(&Year,&Month,&Day);
PosNach=PosCon-Day+1;
PosCon++;
DM->PosNach=PosNach;
DM->PosCon=PosCon;
DM->OpenTable();
DM->Table->Last();
Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->Close();

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::EndEdit(TObject *Sender)
{
if (IdDochForm!=NULL)
        {

        if (ViborRekv==ViborPerioda)
                {
                if(FormaViborPerioda->OutReady==true)
                        {
                        PosNach=FormaViborPerioda->DateTimePicker1->DateTime;
                        PosCon=FormaViborPerioda->DateTimePicker2->DateTime;
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
                FormaViborPerioda=0;
                }


        IdDochForm=NULL;
        ViborRekv=NO;
        }

DM->UpdateTable();
}
//--------------------------------------------------------------------------
void TFormaGurDocRecKDR::OpenFormDoc()
{

        TFormaDocRecKDR * doc=new TFormaDocRecKDR(Application);
        if (!doc) return;
        doc->IdRodForm=Handle;
        //настройка формы
        doc->DM->OpenDoc(DM->TableIDDOC->AsInteger);
        doc->UpdateForm();
        doc->Show();
        doc->FOnCloseForm=EndEdit;
}
//----------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::DBGrid1DblClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocRecKDR::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->ClientWidth;
                DBGrid1->Columns->Items[4]->Width=TecSumWidth-
                DBGrid1->Columns->Items[0]->Width-
                DBGrid1->Columns->Items[1]->Width-
                DBGrid1->Columns->Items[2]->Width-
                DBGrid1->Columns->Items[3]->Width-
                DBGrid1->Columns->Items[5]->Width-
                DBGrid1->Columns->Items[6]->Width-20;
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocRecKDR::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocRecKDR::DeleteDoc(void)
{

        TDMDocRecKDR * doc=new TDMDocRecKDR(Application);
        if (!doc) return;
        //настройка формы
        doc->OpenDoc(DM->TableIDDOC->AsInteger);

        String V="Вы действительно хотите удалить документ Запись книги доходов и расходов №"
        +doc->DocAllNUMDOC->AsString+" от "+doc->DocAllPOSDOC->AsString+"?";
        String Z="Подтверждение удаления документа";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

        if (glUser->ElementID_USER->AsInteger==doc->DocAllIDUSERDOC->AsInteger
                                || glUser->ElementINTERF_USER->AsInteger==10)
                {
                if (doc->DeleteDoc(DM->TableIDDOC->AsInteger)==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
                        ShowMessage("Не удалось удалить документ!");
                        }
                }
        else
                {
                ShowMessage("Нельзя удалять чужие документы!");
                }
        delete doc;

}

//---------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::ToolButton3Click(TObject *Sender)
{
CanceDvRegDoc();
}
//---------------------------------------------------------------------------
void TFormaGurDocRecKDR::CanceDvRegDoc(void)
{

        TDMDocRecKDR *doc= new TDMDocRecKDR (Application);
        doc->OpenDoc( DM->TableIDDOC->AsInteger);
        doc->CancelDvRegDoc();
        delete doc;


DM->UpdateTable();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaGurDocRecKDR::ToolButtonViborPeriodaClick(
      TObject *Sender)
{
if (IdDochForm==NULL)
        {
        FormaViborPerioda=new TFormaViborPerioda(Application);
        FormaViborPerioda->IdRodForm=Handle;
        IdDochForm=FormaViborPerioda->Handle;
        ViborRekv=ViborPerioda;
        FormaViborPerioda->DateTimePicker1->DateTime=PosNach;
        FormaViborPerioda->DateTimePicker2->DateTime=PosCon;
        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
        FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
        FormaViborPerioda->FOnCloseForm=EndEdit;
        FormaViborPerioda->ShowModal();

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocRecKDR::ToolButtonNewDocClick(
      TObject *Sender)
{
TFormaDocRecKDR * doc=new TFormaDocRecKDR(Application);
if (!doc) return;
//настройка формы
doc->DM->NewDoc();
doc->UpdateForm();
doc->FOnCloseForm=EndEdit;
doc->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocRecKDR::ToolButton4Click(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaGurDocRecKDR::DBGrid1DrawColumnCell(
      TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
if (Column->FieldName=="PRDOC")
        {
        Graphics::TBitmap *Im1;
        Im1= new   Graphics::TBitmap;
        DBGrid1->Canvas->Brush->Color=clWhite;
        DBGrid1->Canvas->FillRect(Rect);
        if (DM->TablePRDOC->Value==1)
                {
                ToolBar1->Images->GetBitmap(16,Im1);
                }
        else
                {
                ToolBar1->Images->GetBitmap(17,Im1);
                }
        DBGrid1->Canvas->Draw((Rect.Left+Rect.Right-Im1->Width)/2,Rect.Top,Im1);
        delete Im1;
        }        
}
//---------------------------------------------------------------------------

