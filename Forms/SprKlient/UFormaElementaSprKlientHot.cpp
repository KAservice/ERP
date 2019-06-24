//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaElementaSprKlientHot.h"
#include "UDMSprARM.h"
#include "UFormaElementaSprDocKlient.h"
#include "UFormaElementaSprDocKlientMod.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern TDMSprARM *glARM;
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprKlientHot::TFormaElementaSprKlientHot(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::FormCreate(TObject *Sender)
{
DM=new TDMSprKlient(Application);
DMSprKlientDopFisL=new TDMSprKlientDopFisL(Application);
DMSprDocKlient=new TDMSprDocKlient(Application);

DBGrid1->DataSource=DM->DataSourceTable;
NameEdit->Text="";

OutReady=false;
Nayden=false;
PageControl1->ActivePage=TabSheet1;

NameKlientDBEdit->DataSource=DM->DataSourceElement;
AdrKlientDBEdit->DataSource=DM->DataSourceElement;

MestoRogDBEdit->DataSource=DMSprKlientDopFisL->DataSourceElement;
MestoRabDBEdit->DataSource=DMSprKlientDopFisL->DataSourceElement;
DolRabDBEdit->DataSource=DMSprKlientDopFisL->DataSourceElement;

SerDBText->DataSource=DMSprDocKlient->DataSourceTable;
NumDBText->DataSource=DMSprDocKlient->DataSourceTable;
VidDBText->DataSource=DMSprDocKlient->DataSourceTable;
DateVidDBText->DataSource=DMSprDocKlient->DataSourceTable;
NewKlient=false;
}
//---------------------------------------------------------------------------
void TFormaElementaSprKlientHot::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (FOnCloseForm) FOnCloseForm(this);

delete DMSprDocKlient;
delete DMSprKlientDopFisL;
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::EndEdit(TObject *Sender)
{
if (EditRekvisit==EditDocKlient)
        {
        if (FormaElementaSprDocKlient->OutReady==true)
                {    //обновить список документов
                ZapolnitSpisokDoc();
                }
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::ButtonFindClick(
      TObject *Sender)
{
DM->FindPoName(NameEdit->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::ButtonVibrat1Click(
      TObject *Sender)
{
if (Vibor==true)
        {
        //DM->OpenElement(DM->TableIDKLIENT->AsInteger);
        //OutReady=true;
        //Close();
        PageControl1->ActivePage=TabSheet2;
        Nayden=true;
        Step2();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::DBGrid1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        //DM->OpenElement(DM->TableIDKLIENT->AsInteger);
        //OutReady=true;
        //Close();
        PageControl1->ActivePage=TabSheet2;
        Nayden=true;
        Step2();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprKlientHot::NameEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
        {
        DM->FindPoName(NameEdit->Text);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::DBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key!=VK_RETURN) return;
if (Vibor==true)
        {
        //DM->OpenElement(DM->TableIDKLIENT->AsInteger);
        //OutReady=true;
        //Close();
        PageControl1->ActivePage=TabSheet2;
        Nayden=true;
        Step2();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::ButtonClose1Click(
      TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::ButtonOK2Click(TObject *Sender)
{
DM->Element->Edit();
DM->ElementFNAME->AsString=DM->ElementNAMEKLIENT->AsString;
DM->Element->Post();
DM->SaveElement();

DMSprKlientDopFisL->Element->Edit();
DMSprKlientDopFisL->ElementDATEROG_SKLIENT_DOPFISL->AsDateTime=DateRogDateTimePicker->DateTime;
DMSprKlientDopFisL->Element->Post();
DMSprKlientDopFisL->SaveElement();

OutReady=true;
Close();
}
//---------------------------------------------------------------------------
void TFormaElementaSprKlientHot::CreateNewKlient(void)
{
NewKlient=true;
DM->NewElement(0);
DM->ElementNAMEKLIENT->AsString=NameEdit->Text;

int id_grp=0;
if (Trim(glARM->GetParameter("ID_GRP"))!="")
        {
        id_grp=StrToInt(glARM->GetParameter("ID_GRP"));
        DM->ElementIDGRPKLIENT->AsInteger=StrToInt(id_grp);
        }

DM->ElementTKLIENT->AsInteger=1;

//запишем элемент
DM->SaveElement();
//созданим новый элемент доп. сведений о физ. лице
DMSprKlientDopFisL->IdKlient=DM->ElementIDKLIENT->AsInteger;
DMSprKlientDopFisL->NewElement();

//

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlientHot::ButtonClose2Click(
      TObject *Sender)
{
OutReady=false;
if(NewKlient==true)
        {
         //удалим записи доп. сведений
         DMSprKlientDopFisL->IdKlient=DM->ElementIDKLIENT->AsInteger;
         DMSprKlientDopFisL->DeleteElement();

         //удалим записи документов
         DMSprDocKlient->Table->First();
         while (!DMSprDocKlient->Table->Eof)
                {
                DMSprDocKlient->DeleteElement(DMSprDocKlient->TableID_SDOCKLIENT->AsInteger);
                //DMSprDocKlient->Table->Next();
                }

         //удалим самого клиента
         DM->DeleteElement(DM->ElementIDKLIENT->AsInteger);
        }
Close();
}
//---------------------------------------------------------------------------
void TFormaElementaSprKlientHot::Step2(void)
{

if (Nayden==true) //заполняем форму данными
        {
        DM->OpenElement(DM->TableIDKLIENT->AsInteger);

        DMSprKlientDopFisL->IdKlient=DM->TableIDKLIENT->AsInteger;
        DMSprKlientDopFisL->OpenElement();
        DateRogDateTimePicker->DateTime=DMSprKlientDopFisL->ElementDATEROG_SKLIENT_DOPFISL->AsDateTime;

        // получим документы клиента
        ZapolnitSpisokDoc();
        }
else    //оставляем форму чистой
        {
        CreateNewKlient();
        }     
}
//----------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::ButtonStep2Click(
      TObject *Sender)
{
PageControl1->ActivePage=TabSheet2;
Nayden=false;
Step2();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::DocumentComboBoxChange(
      TObject *Sender)
{
DMSprDocKlient->Table->First();
DMSprDocKlient->Table->MoveBy(DocumentComboBox->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::ButtonIsmdocClick(
      TObject *Sender)
{
if (IdDochForm==NULL)
        {
        FormaElementaSprDocKlient=new TFormaElementaSprDocKlientMod(Application);
        if (!FormaElementaSprDocKlient) return;
        FormaElementaSprDocKlient->IdRodForm=Handle;
        FormaElementaSprDocKlient->DM->OpenElement(DMSprDocKlient->TableID_SDOCKLIENT->AsInteger);
        FormaElementaSprDocKlient->UpdateForm();
        IdDochForm=FormaElementaSprDocKlient->Handle;
        EditRekvisit=EditDocKlient;
        FormaElementaSprDocKlient->FOnCloseForm=EndEdit;
        FormaElementaSprDocKlient->ShowModal();

        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientHot::ButtonNewDocClick(
      TObject *Sender)
{

if (IdDochForm==NULL)
        {
        FormaElementaSprDocKlient=new TFormaElementaSprDocKlientMod(Application);
        if (!FormaElementaSprDocKlient) return;
        FormaElementaSprDocKlient->IdRodForm=Handle;
        FormaElementaSprDocKlient->DM->NewElement(DM->ElementIDKLIENT->AsInteger);
        FormaElementaSprDocKlient->UpdateForm();
        IdDochForm=FormaElementaSprDocKlient->Handle;
        EditRekvisit=EditDocKlient;
        FormaElementaSprDocKlient->FOnCloseForm=EndEdit;
        FormaElementaSprDocKlient->ShowModal();

        }
}
//---------------------------------------------------------------------------

void TFormaElementaSprKlientHot::ZapolnitSpisokDoc(void)
{
DMSprDocKlient->OpenTable(DM->ElementIDKLIENT->AsInteger);
DocumentComboBox->Items->Clear();
DMSprDocKlient->Table->First();
while(!DMSprDocKlient->Table->Eof)
        {
        DocumentComboBox->Items->Add(DMSprDocKlient->TableNAME_SDOCKLIENT->AsString);
        DMSprDocKlient->Table->Next();
        }

DocumentComboBox->ItemIndex=0;
DMSprDocKlient->Table->First();
}
//----------------------------------------------------------------------------
