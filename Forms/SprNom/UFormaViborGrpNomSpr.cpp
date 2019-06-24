//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaViborGrpNomSpr.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTreeView"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//TFormaSpiskaSprNom *FormaSpiskaSprNom;

//---------------------------------------------------------------------------
__fastcall TFormaViborGrpNomSpr::TFormaViborGrpNomSpr(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaViborGrpNomSpr::Init(void)
{
bool result=false;

DMGrp=new TDMSprGrpNom(Application);
DMGrp->DM_Connection=DM_Connection;
DMGrp->Init();

IdGrp=0;
AllElement=false;
Vibor=false;
OutReady=false;
ViborRekvisit=NO;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
void TFormaViborGrpNomSpr::UpdateForm(void)
{   
UpdateDerevo();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborGrpNomSpr::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FOnCloseForm) FOnCloseForm(this);

delete DMGrp;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborGrpNomSpr::CloseElementSpr(TObject *Sender)
{
if (ViborRekvisit==ViborGrp)
        {

        UpdateDerevo();
        }


        ViborRekvisit=NO;
        IdDochForm=NULL;

}

//-------------------------------------------------------------------
//
void TFormaViborGrpNomSpr::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRPGN->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
                          *lpIDGrp=glStrToInt64(DMGrp->TableIDGN->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGN")->AsString, lpIDGrp);
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
//---------------------------------------------------------------------------------


void __fastcall TFormaViborGrpNomSpr::cxButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborGrpNomSpr::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		IdGrp=*(int*)cxTreeView1->Selected->Data;
		OutReady=true;
		DMGrp->OpenElement(IdGrp);
		Close();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborGrpNomSpr::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ViborGrpNomSpr");
}
//---------------------------------------------------------------------------

