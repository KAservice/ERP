//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprSkladTouch.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprSkladTouch::TFormaSpiskaSprSkladTouch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaSpiskaSprSkladTouch::Init(void)
{
bool result=false;

IBTr->DefaultDatabase=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;

//ÏÐÈÂÅËÅÃÈÈ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSkladTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

El->Active=false;
Action=caFree;

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSkladTouch::BitBtnCloseClick(
      TObject *Sender)
{
OutReady=false;
Close();
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprSkladTouch::OpenSpisokSkl(void)
{
El->Active=false;
El->Active=true;
El->First();

if(El->Eof!=true){el1->Visible=true;el1->Caption=ElNAMESKLAD->AsString;}else{el1->Visible=false;}
El->Next();
if(El->Eof!=true){el2->Visible=true;el2->Caption=ElNAMESKLAD->AsString;}else{el2->Visible=false;}
El->Next();
if(El->Eof!=true){el3->Visible=true;el3->Caption=ElNAMESKLAD->AsString;}else{el3->Visible=false;}
El->Next();
if(El->Eof!=true){el4->Visible=true;el4->Caption=ElNAMESKLAD->AsString;}else{el4->Visible=false;}
El->Next();
if(El->Eof!=true){el5->Visible=true;el5->Caption=ElNAMESKLAD->AsString;}else{el5->Visible=false;}
El->Next();
if(El->Eof!=true){el6->Visible=true;el6->Caption=ElNAMESKLAD->AsString;}else{el6->Visible=false;}
El->Next();
if(El->Eof!=true){el7->Visible=true;el7->Caption=ElNAMESKLAD->AsString;}else{el7->Visible=false;}
El->Next();
if(El->Eof!=true){el8->Visible=true;el8->Caption=ElNAMESKLAD->AsString;}else{el8->Visible=false;}
El->Next();
if(El->Eof!=true){el9->Visible=true;el9->Caption=ElNAMESKLAD->AsString;}else{el9->Visible=false;}
}
//----------------------------------------------------------------------------

void TFormaSpiskaSprSkladTouch::OpenFormInKol(void)
{

///

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprSkladTouch::OpenElement(int Num)
{
El->First();
El->MoveBy(Num-1);
if(El->Eof!=true)
        {
        OutReady=true;

        if (IdRodForm!=NULL)
                {
                if(FOnCloseForm) FOnCloseForm(this);
                Close();
                }

        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSkladTouch::el1Click(TObject *Sender)
{
OpenElement(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el2Click(TObject *Sender)
{
OpenElement(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el3Click(TObject *Sender)
{
OpenElement(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el4Click(TObject *Sender)
{
OpenElement(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el5Click(TObject *Sender)
{
OpenElement(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el6Click(TObject *Sender)
{
OpenElement(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el7Click(TObject *Sender)
{
OpenElement(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el8Click(TObject *Sender)
{
OpenElement(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSkladTouch::el9Click(TObject *Sender)
{
 OpenElement(9);
}
//---------------------------------------------------------------------------






















