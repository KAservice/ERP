//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaViborNomSpr.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormaViborNomSpr *FormaViborNomSpr;
//---------------------------------------------------------------------------
__fastcall TFormaViborNomSpr::TFormaViborNomSpr(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::FormCreate(TObject *Sender)
{
DM=new TDMSprNom(Application);
DMGrp=new TDMSprGrpNom(Application);
DBGrid1->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;
OutReady=false;
ViborRekvisit=NO;

DM->SpTPrice->Active=true;

SpisokTypePrice->Items->Clear();
DM->SpTPrice->First();
while (!DM->SpTPrice->Eof)
        {
        SpisokTypePrice->Items->Add(DM->SpTPriceNAME_TPRICE->AsString);
        DM->SpTPrice->Next();
        }

LabelNameGrp->Caption="Номенклатура\\...";
HintLabel->Caption="";

PoiskEdit->Visible=false;
}
//---------------------------------------------------------------------------
void TFormaViborNomSpr::UpdateForm(void)
{
SpisokTypePrice->ItemIndex=DM->GetIndexTypePrice()-1;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();
UpdateDerevo();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
delete DM;
delete DMGrp;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::CloseElementSpr(TObject *Sender)
{
if (ViborRekvisit==ViborGrp)
        {

        UpdateDerevo();
        }
if(ViborRekvisit==ViborElement)
        {
        DM->OpenTable(IdGrp,AllElement);
        }
ViborRekvisit=NO;
IdDochForm=NULL;
}

//--------------------------------------------------------------------------

void TFormaViborNomSpr::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (TreeView1->Items->Count>0)
        {
        for (int i=0;i<TreeView1->Items->Item[0]->Count;i++)
                {
                delete (int*)TreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
TreeView1->Items->Clear();
int *lpIDGrp=new int;
*lpIDGrp=0;

TreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

TreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
        int IDGrp=DMGrp->Table->FieldByName("IDGRPGN")->AsInteger;
        int IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
        for (int i=0;i<TreeView1->Items->Count;i++)
                {

                IDData=*(int*)TreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
                         lpIDGrp=new int;
                          *lpIDGrp=DMGrp->Table->FieldByName("IDGN")->AsInteger;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
                         TreeView1->Items->AddChildObjectFirst(TreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGN")->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
TreeView1->AlphaSort(true);

for (int i=0;i<TreeView1->Items->Count;i++)
        {
        int IDData=*(int*)TreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
                        TreeView1->Selected=TreeView1->Items->Item[i];
                        break;
                        }
        }
}
//---------------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
        LabelNameGrp->Caption="...\\ "+TreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
IdGrp=*(int*)TreeView1->Selected->Data;
DM->OpenTable(IdGrp,AllElement);        
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::TreeView1DblClick(TObject *Sender)
{
if (TreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
                LabelNameGrp->Caption="...\\ "+TreeView1->Selected->Text+" \\";
                }
        IdGrp=*(int*)TreeView1->Selected->Data;
        DM->OpenTable(IdGrp,AllElement);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::TreeView1KeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
        {
if (TreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
                LabelNameGrp->Caption="...\\ "+TreeView1->Selected->Text+" \\";
                }
        IdGrp=*(int*)TreeView1->Selected->Data;
        DM->OpenTable(IdGrp,AllElement);
        }
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborNomSpr::ButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::TreeView1CustomDrawItem(
      TCustomTreeView *Sender, TTreeNode *Node, TCustomDrawState State,
      bool &DefaultDraw)
{
if (TreeView1->Selected==Node)
        {
        TreeView1->Canvas->Font->Color=clRed;
        }        
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::DBGrid1DblClick(TObject *Sender)
{

if (Vibor==true)
        {
        OutReady=true;
        DM->OpenElement(DM->TableIDNOM->AsInteger);
        Close();
        }
else
        {

        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborNomSpr::DBGrid1KeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
        {
        if (Vibor==true)
                {
                OutReady=true;
                DM->OpenElement(DM->TableIDNOM->AsInteger);
                Close();
                }

        }

        else
                {

                //определяем по какому полю искать
                PolePoiska=PoiskPoName;
                if(DBGrid1->SelectedField==DM->TableNAMENOM)
                        {
                        PolePoiska=PoiskPoName;
                        }
                if(DBGrid1->SelectedField==DM->TableCODENOM)
                        {
                        PolePoiska=PoiskPoCodu;
                        }

                PoiskEdit->Left=DBGrid1->Left;
                PoiskEdit->Visible=true;
                PoiskEdit->Text=Key;
                PoiskEdit->SelStart=2;
                PoiskEdit->SetFocus();

                }



}
//---------------------------------------------------------------------------

void __fastcall TFormaViborNomSpr::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=476;
        DBGrid1->Columns->Items[0]->Width=74*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=288*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=73*TecSumWidth/SumWidth;
        SpisokTypePrice->Left=DBGrid1->Left+TecSumWidth-SpisokTypePrice->Width;
}
//---------------------------------------------------------------------------



void __fastcall TFormaViborNomSpr::SpisokTypePriceChange(TObject *Sender)
{
if (Vibor==true)
        {

        }
else
        {
        DM->SpTPrice->First();
        DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
        DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInteger;
        }
UpdateForm();
}
//---------------------------------------------------------------------------




void __fastcall TFormaViborNomSpr::PoiskEditChange(TObject *Sender)
{
TLocateOptions SearchOptions;
SearchOptions<<loPartialKey<<loCaseInsensitive;
if (PolePoiska==PoiskPoCodu)
        {
        DM->Table->Locate("CODENOM",PoiskEdit->Text,SearchOptions);
        }
if (PolePoiska==PoiskPoName)
        {
        DM->Table->Locate("NAMENOM",PoiskEdit->Text,SearchOptions);
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborNomSpr::PoiskEditExit(TObject *Sender)
{
PoiskEdit->Visible=false;        
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborNomSpr::PoiskEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
        {
        if (Vibor==true)
                {

                        OutReady=true;
                        DM->OpenElement(DM->TableIDNOM->AsInteger);
                        Close();
                }

        DBGrid1->SetFocus();
        }

if (Key==VK_ESCAPE)
        {
        DBGrid1->SetFocus();
        }
}
//---------------------------------------------------------------------------

