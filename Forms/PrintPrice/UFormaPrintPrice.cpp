//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaPrintPrice.h"
#include "UDMSprARM.h"

#include "UPrintPriceNumber1.cpp"
#include "UPrintPriceNumber2.h"
#include "UPrintPriceNumber3.h"
#include "UPrintPriceNumber4.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaPrintPrice::TFormaPrintPrice(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaPrintPrice::Init(void)
{
bool result=false;

List=new TList;
UpdateGrid();

 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
void TFormaPrintPrice::UpdateGrid(void)
{
if (List->Count==0)
        {
        StringGrid1->RowCount=2;
        StringGrid1->Cells[1][1]="";
        StringGrid1->Cells[2][1]="";
        StringGrid1->Cells[3][1]="";
        StringGrid1->Cells[4][1]="";
        }
else
        {
        StringGrid1->RowCount=List->Count+1;
        }
        
        StringGrid1->Cells[1][0]="Группа";
        StringGrid1->Cells[2][0]="Наименование";
        StringGrid1->Cells[3][0]="Единица";
        StringGrid1->Cells[4][0]="Кол.";

for (int i=0; i<List->Count;i++)
        {
        ElementSpiska=(TElementSpiskaPrintPrice*)List->Items[i];
        StringGrid1->Cells[0][i+1]=IntToStr(i+1);
        StringGrid1->Cells[2][i+1]=ElementSpiska->Name;
        StringGrid1->Cells[3][i+1]=ElementSpiska->NameEd;
        StringGrid1->Cells[4][i+1]=IntToStr(ElementSpiska->Kol);
        }

}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintPrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{
for(int i=0;i<List->Count;i++)
		{
		ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[i];
		delete ElementSpiska;
		}
delete List;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintPrice::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborNom)
        {
        if (FormaViborSprNom->OutReady==true)
                {
				TElementSpiskaPrintPrice * el=new TElementSpiskaPrintPrice;
				el->Id=glStrToInt64(FormaViborSprNom->DM->ElementIDNOM->AsString);
				el->Name=FormaViborSprNom->DM->ElementNAMENOM->AsString;
				el->IdEd=glStrToInt64(FormaViborSprNom->DM->ElementIDBASEDNOM->AsString);
				el->NameEd=FormaViborSprNom->DM->BasEdNAMEED->AsString;
				el->Grp=false;
				el->Kol=1;
				List->Add(el);
                }
        }

if (EditRekvisit==ViborGrpNom)
        {
        if (FormaViborGrpNomSpr->OutReady==true)
                {
                TElementSpiskaPrintPrice * el=new TElementSpiskaPrintPrice;
				el->Id=glStrToInt64(FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString);
                el->Name=FormaViborGrpNomSpr->DMGrp->ElementNAMEGN->AsString;
                el->IdEd=0;
                el->NameEd="";
                el->Grp=true;
                el->Kol=1;
                List->Add(el);
                }
        }

if (EditRekvisit==InputKol)
        {
        if (FormaInputText->OutReady==true)
                {
                if (List->Count>0)
                        {
                        int num_str=StringGrid1->Row-1;
                        ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[num_str];
                        ElementSpiska->Kol=StrToInt(FormaInputText->InputTextEdit->Text);
                        }
                }
        FormaInputText=0;
        }

UpdateGrid();
IdDochForm=NULL;

}
//---------------------------------------------------------------------------
void TFormaPrintPrice::OpenFormViborSprNom(void)
{

if (IdDochForm==NULL)
        {
		FormaViborSprNom=new TFormaViborSprNom(Application);
		FormaViborSprNom->DM_Connection=DM_Connection;
		FormaViborSprNom->Init();
        if (!FormaViborSprNom) return;
        FormaViborSprNom->IdRodForm=Handle;
        FormaViborSprNom->FOnCloseForm=EndEdit;
        FormaViborSprNom->Vibor=true;
        IdDochForm=FormaViborSprNom->Handle;
        EditRekvisit=ViborNom;
		FormaViborSprNom->DM->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
        FormaViborSprNom->SpisokTypePrice->ItemIndex=FormaViborSprNom->DM->GetIndexTypePrice()-1;
        FormaViborSprNom->UpdateForm();
        FormaViborSprNom->Show();
        }
}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintPrice::AddNomToolButtonClick(TObject *Sender)
{
OpenFormViborSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::DelNomToolButtonClick(TObject *Sender)
{
if (List->Count>0)
        {
        DeleteString(StringGrid1->Row-1);
        }
}
//---------------------------------------------------------------------------
void TFormaPrintPrice::DeleteString(int num_str)
{
ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[num_str];
delete ElementSpiska;
List->Delete(num_str);
UpdateGrid();
}
//-----------------------------------------------------------------------------
void TFormaPrintPrice::OpenFormViborGrpNom(void)
{
if (IdDochForm==NULL)
        {
		FormaViborGrpNomSpr=new TFormaViborGrpNomSpr(this);
		FormaViborGrpNomSpr->DM_Connection=DM_Connection;
		FormaViborGrpNomSpr->Init();
        if (!FormaViborGrpNomSpr) return;
		FormaViborGrpNomSpr->IdRodForm=Handle;
        FormaViborGrpNomSpr->FOnCloseForm=EndEdit;
        FormaViborGrpNomSpr->Vibor=true;
        IdDochForm=FormaViborGrpNomSpr->Handle;
        EditRekvisit=ViborGrpNom;
        FormaViborGrpNomSpr->UpdateForm();
        FormaViborGrpNomSpr->ShowModal();
        }

}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintPrice::AddGrpToolButtonClick(TObject *Sender)
{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::StringGrid1DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{

if (ACol==1 && ARow>0 && List->Count>0)
        {
        ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[ARow-1];
        if  (ElementSpiska->Grp==true)
                {
                Graphics::TBitmap *Im1;
                Im1= new   Graphics::TBitmap;
                StringGrid1->Canvas->Brush->Color=clWhite;
                StringGrid1->Canvas->FillRect(Rect);
                ToolBar1->Images->GetBitmap(18,Im1);
                StringGrid1->Canvas->Draw((Rect.Left+Rect.Right-Im1->Width)/2,Rect.Top,Im1);
                delete Im1;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::ToolButton4Click(TObject *Sender)
{
TPrintPriceNumber1 * PrintPriceNumber1=new TPrintPriceNumber1();
PrintPriceNumber1->DM_Connection=DM_Connection;
PrintPriceNumber1->Init();
PrintPriceNumber1->List=List;
PrintPriceNumber1->NameFirm=DM_Connection->ARMInfoNAMEFIRM->AsString;
PrintPriceNumber1->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
PrintPriceNumber1->CreatePrice1();
delete PrintPriceNumber1;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::ToolButtonPrintNumber2Click(
      TObject *Sender)
{
TPrintPriceNumber2 * PrintPriceNumber2=new TPrintPriceNumber2();
PrintPriceNumber2->DM_Connection=DM_Connection;
PrintPriceNumber2->Init();
PrintPriceNumber2->List=List;
PrintPriceNumber2->NameFirm=DM_Connection->ARMInfoNAMEFIRM->AsString;
PrintPriceNumber2->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
PrintPriceNumber2->CreatePrice();
delete PrintPriceNumber2;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::ToolButtonPrintNumber3Click(
      TObject *Sender)
{
TPrintPriceNumber3 * PrintPriceNumber3=new TPrintPriceNumber3();
PrintPriceNumber3->DM_Connection=DM_Connection;
PrintPriceNumber3->Init();
PrintPriceNumber3->List=List;
PrintPriceNumber3->NameFirm=DM_Connection->ARMInfoNAMEFIRM->AsString;
PrintPriceNumber3->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
PrintPriceNumber3->CreatePrice();
delete PrintPriceNumber3;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::ToolButtonPrintNumber4Click(
      TObject *Sender)
{
TPrintPriceNumber4 * PrintPriceNumber4=new TPrintPriceNumber4();
PrintPriceNumber4->DM_Connection=DM_Connection;
PrintPriceNumber4->Init();
PrintPriceNumber4->List=List;
PrintPriceNumber4->NameFirm=DM_Connection->ARMInfoNAMEFIRM->AsString;
PrintPriceNumber4->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
PrintPriceNumber4->CreatePrice();
delete PrintPriceNumber4;
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrintPrice::ToolButtonEditKolClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        FormaInputText=new TFormaInputText(Application);
        FormaInputText->Vibor=true;
        FormaInputText->IdRodForm=Handle;
        IdDochForm=FormaInputText->Handle;
        EditRekvisit=InputKol;
        FormaInputText->NameLabel->Caption="Введите количество:";
        FormaInputText->Caption="Количество";
        FormaInputText->FOnCloseForm=EndEdit;
        FormaInputText->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPrice::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("PrintPrice");	
}
//---------------------------------------------------------------------------

