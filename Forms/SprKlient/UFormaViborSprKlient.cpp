//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaViborSprKlient.h"
#include "UDMSprGrpKlient.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxStyles"
#pragma link "cxTreeView"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborSprKlient::TFormaViborSprKlient(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprKlient::FormCreate(TObject *Sender)
{
DM=new TDMSprKlient(Application);
DMGrp=new TDMSprGrpKlient(Application);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();
Vibor=false;
OutReady=true;
ViborRekvisit=NO;
HintLabel->Caption="";
UpdateDerevo();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
delete DM;
delete DMGrp;
Action=caFree;
}

//---------------------------------------------------------------------------

void __fastcall TFormaViborSprKlient::CloseElementSpr(TObject *Sender)
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

//-------------------------------------------------------------------
//
void TFormaViborSprKlient::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Контрагенты",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=DMGrp->TableGRPKL->AsInteger;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableIDGRPKL->AsInteger;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGRPKL")->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);

for (int i=0;i<cxTreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
                        break;
                        }
        }
}

//-------------------------------------------------------------------------



void __fastcall TFormaViborSprKlient::ToolButtonAllElementClick(
      TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
IdGrp=*(__int64*)cxTreeView1->Selected->Data;
DM->OpenTable(IdGrp,AllElement);
}
//---------------------------------------------------------------------------






void __fastcall TFormaViborSprKlient::cxButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprKlient::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}
	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprKlient::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		DM->OpenElement(glStrToInt64(DM->TableIDKLIENT->AsString));
		Close();
		}	
}
//---------------------------------------------------------------------------

