//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaViborSprStrObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaViborSprStrObject::TFormaViborSprStrObject(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprStrObject::FormCreate(TObject *Sender)
{
DMGrp=new TDMSprStrObject(Application);
IdGrp=0;
AllElement=false;
DMGrp->OpenTable();
Vibor=false;
OutReady=false;
ViborRekvisit=NO;
UpdateDerevo();
TreeView1->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprStrObject::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FOnCloseForm) FOnCloseForm(this);
delete DMGrp;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprStrObject::CloseElementSpr(TObject *Sender)
{
if (ViborRekvisit==ViborGrp)
        {
        IdGrp=FormaGrpElementa->DM->ElementID_STROB->AsInteger;
        UpdateDerevo();
        }
ViborRekvisit=NO;
IdDochForm=NULL;
}
//-------------------------------------------------------------------
//
void TFormaViborSprStrObject::UpdateDerevo()
{
String NameUsel="";
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

TreeView1->Items->AddObject(NULL,"Ресторан",lpIDGrp);

TreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
        int IDGrp=DMGrp->TableIDGRP_STROB->AsInteger;
        int IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
        for (int i=0;i<TreeView1->Items->Count;i++)
                {

                IDData=*(int*)TreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
                         lpIDGrp=new int;
                          *lpIDGrp=DMGrp->TableID_STROB->AsInteger;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
                         NameUsel=DMGrp->TableNAME_STROB->AsString;
                               // +" (Код:"+IntToStr(DMGrp->TableCODE_STROB->AsInteger)+")";
                         TreeView1->Items->AddChildObjectFirst(TreeView1->Items->Item[i],
                         NameUsel, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
//TreeView1->AlphaSort(true);

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

//-------------------------------------------------------------------------
void __fastcall TFormaViborSprStrObject::ButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprStrObject::TreeView1CustomDrawItem(
      TCustomTreeView *Sender, TTreeNode *Node, TCustomDrawState State,
      bool &DefaultDraw)
{
if (TreeView1->Selected==Node)
        {
        TreeView1->Canvas->Font->Color=clRed;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprStrObject::TreeView1DblClick(TObject *Sender)
{
if (TreeView1->Selected!=NULL)
        {
        ViborIdObject=*(int*)TreeView1->Selected->Data;
        DMGrp->OpenElement(ViborIdObject);
        if (DMGrp->ElementGRP_STROB->AsInteger!=1)
                {
                OutReady=true;
                Close();
                }
        }
}
//---------------------------------------------------------------------------

