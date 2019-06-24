//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocPerTouch.h"
#include "UFormaSpiskaSprSkladTouch.h"
#include "UFiskReg.h"
#include "UDMSprARM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//----------- фискальный регистратор -----
extern TFiskReg  *glFR;

//---------------------------------------------------------------------------
__fastcall TFormaDocPerTouch::TFormaDocPerTouch(TComponent* Owner)
		: TForm(Owner)
{

}
//---------------------------------------------------------------------------
bool TFormaDocPerTouch::Init(void)
{
bool result=false;

EditRekvisit=NO;

DM= new TDMDocPer(Application);
DM->DM_Connection=DM_Connection;
DM->Init();
Nom=new TDMSprNom(Application);
Nom->DM_Connection=DM_Connection;
Nom->Init();
KKM=new TDMSprKKM(Application);
KKM->DM_Connection=DM_Connection;
KKM->Init();

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NameUserDBText->DataSource=DM->DataSourceDocAll;
NumDocDBText->DataSource=DM->DataSourceDocAll;
PosDocDBText->DataSource=DM->DataSourceDocAll;
DBGrid1->DataSource=DM->DataSourceDocT;

ActionOperation=aoNO;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//-------------------------------------------------------------------------
void TFormaDocPerTouch::UpdateForm(void)
{
KKM->OpenElement(IdKKM);

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Kalkulator)Kalkulator->Close();
if(SpisokBVTouch)SpisokBVTouch->Close();
if(SpisokEdTouch)SpisokEdTouch->Close();
if(SpisokSkladTouch)SpisokSkladTouch->Close();

try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
delete Nom;
delete KKM;
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaDocPerTouch::NewDoc(void)
{
DM->NewDoc();

DM->DocAll->Edit();
DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
DM->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
DM->DocAll->Post();

}
//---------------------------------------------------------------------------
void TFormaDocPerTouch::OpenFormSpiskaBVNomTouch(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
		SpisokBVTouch=new TFormaSpiskaSprBVNomTouch(Application);
		SpisokBVTouch->DM_Connection=DM_Connection;
		SpisokBVTouch->Init();
        if (!SpisokBVTouch) return;
        SpisokBVTouch->IdRodForm=Handle;
        SpisokBVTouch->FOnCloseForm=EndEdit;
        SpisokBVTouch->Vibor=true;
        IdDochForm=SpisokBVTouch->Handle;
        EditRekvisit=EditNomBVTouch;
        SpisokBVTouch->Show();

        }
}
//---------------------------------------------------------------------------
void TFormaDocPerTouch::OpenFormSpiskaSprEdTouch(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
		SpisokEdTouch=new TFormaSpiskaSprEdTouch(Application);
		SpisokEdTouch->DM_Connection=DM_Connection;
		SpisokEdTouch->Init();
        if (!SpisokEdTouch) return;
        SpisokEdTouch->IdRodForm=Handle;
        SpisokEdTouch->FOnCloseForm=EndEdit;
        SpisokEdTouch->Vibor=true;
        IdDochForm=SpisokEdTouch->Handle;
        EditRekvisit=EditEdinicaTouch;
		SpisokEdTouch->IdNom=glStrToInt64(DM->DocTIDNOMPERT->AsString);
        SpisokEdTouch->OpenSpisokEd();
        SpisokEdTouch->LabelNom->Caption=DM->DocTNAMENOM->AsString;
        SpisokEdTouch->ShowModal();

        }
}
//---------------------------------------------------------------------------
void TFormaDocPerTouch::OpenFormSpiskaSprSkladTouch(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
		SpisokSkladTouch=new TFormaSpiskaSprSkladTouch(Application);
		SpisokSkladTouch->DM_Connection=DM_Connection;
		SpisokSkladTouch->Init();
        if (!SpisokSkladTouch) return;
        SpisokSkladTouch->IdRodForm=Handle;
        SpisokSkladTouch->FOnCloseForm=EndEdit;
        SpisokSkladTouch->Vibor=true;
        IdDochForm=SpisokSkladTouch->Handle;
        EditRekvisit=EditSkladTouch;
        SpisokSkladTouch->OpenSpisokSkl();
        SpisokSkladTouch->ShowModal();

        }
}

//---------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::EndEdit(TObject *Sender)
{


if (EditRekvisit==EditEdinicaTouch)
        {
        if (SpisokEdTouch->OutReady==true)
                {
                DM->DocT->Edit();
                DM->DocTIDEDPERT->AsString=SpisokEdTouch->ElIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEdTouch->ElNAMEED->AsString;
                DM->DocTKFPERT->AsFloat=SpisokEdTouch->ElKFED->AsFloat;
                DM->DocT->Post();
               }
        SpisokEdTouch=0;
        }

if (EditRekvisit==EditNomBVTouch)
        {
        if (SpisokBVTouch->OutReady==true)
               {
               if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
				Nom->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
                Nom->OpenElement(SpisokBVTouch->IdNom);

                DM->DocT->Edit();
				DM->DocTIDNOMPERT->AsString=Nom->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                //DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                DM->DocTKOLPERT->AsFloat=1;

                DM->DocTIDEDPERT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                DM->DocTKFPERT->AsFloat=Nom->OsnEdKFED->AsFloat;

                DM->DocT->Post();

                }
        SpisokBVTouch=0;
        }

if (EditRekvisit==EditKol)
        {
        if (Kalkulator->OutReady==true)
               {
                DM->DocT->Edit();
                DM->DocTKOLPERT->AsFloat=Kalkulator->Result;
                DM->DocT->Post();
                }
        Kalkulator=0;
        }

if (EditRekvisit==EditSkladTouch)
        {
        if (SpisokSkladTouch->OutReady==true)
               {
                DM->Doc->Edit();
				DM->DocIDSKLPOLPER->AsString=SpisokSkladTouch->ElIDSKLAD->AsString;
                LabelNameSkladPol->Caption="Склад получатель: "+SpisokSkladTouch->ElNAMESKLAD->AsString;
                DM->Doc->Post();
                }
        SpisokSkladTouch=0;
        }


EditRekvisit=NO;
IdDochForm=NULL;

}
//--------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::BitBtnViborSkladClick(TObject *Sender)
{
OpenFormSpiskaSprSkladTouch();
}
//---------------------------------------------------------------------------

//-------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::BitBtnViborEdClick(TObject *Sender)
{
OpenFormSpiskaSprEdTouch();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::ButtonSaveClick(TObject *Sender)
{
DM->SaveDoc();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::ButtonCloseClick(TObject *Sender)
{

Close();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::ButtonProvClick(TObject *Sender)
{
if (DM->SaveDoc()==true)
        {
        DM->DvRegDoc();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::ButtonOKClick(TObject *Sender)
{
if(glStrToInt64(DM->DocIDSKLPOLPER->AsString)==0)
        {
        ShowMessage("Выберите склад получатель!");
        return;
        }
if (DM->SaveDoc()==true)
        {
        if (DM->DvRegDoc()==true)
                {
                Close();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::FormResize(TObject *Sender)
{
        int TecSumWidth=DBGrid1->Width;
        int  SumWidth=658;
        DBGrid1->Columns->Items[0]->Width=58*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[1]->Width=275*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[2]->Width=83*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[3]->Width=105*TecSumWidth/SumWidth;
        DBGrid1->Columns->Items[4]->Width=93*TecSumWidth/SumWidth;
}

//--------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::BitBtnNewStrClick(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaBVNomTouch();           
}

//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::BitBtnDelClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();          
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::BitBtnEditKolClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        Kalkulator=new TKalkulator(Application);
        if (!Kalkulator) return;
        Kalkulator->IdRodForm=Handle;
        Kalkulator->FOnCloseForm=EndEdit;
        IdDochForm=Kalkulator->Handle;
        EditRekvisit=EditKol;
        Kalkulator->ShowModal();

        }
}
//-------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::BitBtnUpClick(TObject *Sender)
{
DM->DocT->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPerTouch::BitBtnDownClick(TObject *Sender)
{
DM->DocT->Next();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPerTouch::BitBtnPrintClick(TObject *Sender)
{
if(glStrToInt64(DM->DocIDSKLPOLPER->AsString)==0)
        {
        ShowMessage("Выберите склад получатель!");
        return;
        }
if (PrintDoc()==false)
        {
        ShowMessage("Не удалось напечатать документ!");
        }
}

//--------------------------------------------------------------------------
bool TFormaDocPerTouch::PrintDoc(void)
{
bool Res=false;
if(glFR->ConnectFR==false) return Res;

String StrPr="";

glFR->OpenNoFiscalCheck();

glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(LabelNameFirm->Caption,1,0,0,true,false, false);
glFR->PrintString(LabelNameSklad->Caption,1,0,0,true,false, false);

StrPr="Перемещение №"+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
glFR->PrintString(StrPr,1,0,0,true,false, false);
glFR->PrintString(LabelNameSkladPol->Caption,1,0,0,true,false, false);
glFR->PrintLine();



DM->DocT->First();
while(!DM->DocT->Eof)
        {
		glFR->PrintString(DM->DocTNAMENOM->AsString,1,0,0,true,false, false);

        StrPr=FloatToStr(DM->DocTKOLPERT->AsFloat)+" "
                +DM->DocTNAMEED->AsString;
		glFR->PrintString(StrPr,1,0,2,true,false, false);
        DM->DocT->Next();
        }

glFR->PrintLine();
glFR->PrintString(" ",1,0,0,true,false, false);



StrPr=DM->DocAllFNAME_USER->AsString;
glFR->PrintString(StrPr,1,0,0,true,false, false);

glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString("Отпустил  ------------------",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
if (glFR->PrintString("Получил  ------------------",1,0,0,true,false, false)==true)
        {
        Res=true;
        }

for(int i=0;i<7;i++)
        {
        glFR->PrintString(" ",1,0,0,true,false, false);
        }

glFR->CloseNoFiscalCheck();

if (glFR->Cut(1)==true) {Res=true;}

return Res;
}
//---------------------------------------------------------------------------






