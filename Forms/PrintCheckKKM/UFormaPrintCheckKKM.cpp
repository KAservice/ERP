//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UFormaPrintCheckKKM.h"
#include "UFiskReg.h"
#include "UDMSprUser.h"
 #include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//----------- фискальный регистратор -----
extern TFiskReg  *glFR;

//---------------------------------------------------------------------------
__fastcall TFormaPrintCheckKKM::TFormaPrintCheckKKM(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
bool TFormaPrintCheckKKM::Init(void)
{
bool result=false;

Memo1->Clear();
Prim->Caption="";
ComboBox->ItemIndex=0;
DMSprARM= new TDMSprARM(Application);
DMSprARM->DM_Connection=DM_Connection;
DMSprARM->Init();
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
void __fastcall TFormaPrintCheckKKM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete DMSprARM;
Action=caFree;
}
//---------------------------------------------------------------------------

void TFormaPrintCheckKKM::UpdateForm(void)
{
if (DMSprARM->OpenElement(IdARM)>0)
        {
        }
else
        {
        ShowMessage("Не найдены настройки рабочего места!");
        }
NameKKMLabel->Caption="АРМ: "+DMSprARM->ElementNAME_SARM->AsString;
SumCheckEdit->Text=FloatToStr(SumCheck);
NalEdit->Text=FloatToStr(SumCheck);
PlatCardEdit->Text="0";
if (DMSprARM->GetParameter("UCH")=="YES") UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

}

//--------------------------------------------------------------------------
bool TFormaPrintCheckKKM::PrintCheck(void)
{
bool Res=false;
if(glFR->ConnectFR==false)
        {
        Prim->Caption="Фискальный регистратор не подключен!";
        return Res;
        }
        
if (glFR->ProvVosmPrintCheck()==false)
        {
        Prim->Caption="Чек не напечатан!";
        return Res;
        }

glFR->OpenNoFiscalCheck();

if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,0,1,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,0,1,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,0,1,true,false, false);
        }

glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintLine();

for (int i=0;i<Memo1->Lines->Count;i++)
        {
		glFR->PrintString(Memo1->Lines->Strings[i],1,0,0,true,false, false);
        }

glFR->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false, false);
glFR->PrintLine();

glFR->CloseNoFiscalCheck();

if (DMSprARM->GetParameter("UCH")!="YES") PrintFiscalCheck();
else PrintNoFiscalCheck();


Res=true;

return Res;
}
//-------------------------------------------------------------------------
bool TFormaPrintCheckKKM::PrintFiscalCheck(void)
{
bool res=false;
int department=1;


department=StrToInt(OtdelEdit->Text);


double SumCheck=0;
if ( SumCheckEdit->Text==" " || SumCheckEdit->Text=="")
        {
        SumCheckEdit->Text=0;
        }
SumCheck=StrToFloat(SumCheckEdit->Text);

double OplataNal=0;
if ( NalEdit->Text==" " || NalEdit->Text=="")
        {
        NalEdit->Text=0;
        }
OplataNal=StrToFloat(NalEdit->Text);

double OplataPlatCard=0;
if (PlatCardEdit->Text==" " || PlatCardEdit->Text=="")
        {
        PlatCardEdit->Text=0;
        }
OplataPlatCard=StrToFloat(PlatCardEdit->Text);


if (ComboBox->ItemIndex==1)
        {  //возврат
        if(glFR->PrintFiscalCheck(SumCheck,
                                        department,
                                        OplataNal,
										OplataPlatCard,
										0,
										0,
                                        1)==true)
                {
                res=true;
                }
        else
                {
                res=false;
                }
        }
else    //продажа
        {
        if(glFR->PrintFiscalCheck(SumCheck,
                                        department,
                                        OplataNal,
										OplataPlatCard,
										0,
										0,
										0)==true)
                {
                res=true;
                }
        else
                {
                res=false;
                }
        }

res=true;
return res;
}
//--------------------------------------------------------------------------
bool TFormaPrintCheckKKM::PrintNoFiscalCheck(void)
{
bool res=false;

int department=1;


department=StrToInt(OtdelEdit->Text);


double SumCheck=0;
if ( SumCheckEdit->Text==" " || SumCheckEdit->Text=="")
        {
        SumCheckEdit->Text=0;
        }
SumCheck=StrToFloat(SumCheckEdit->Text);

double OplataNal=0;
if ( NalEdit->Text==" " || NalEdit->Text=="")
        {
        NalEdit->Text=0;
        }
OplataNal=StrToFloat(NalEdit->Text);

double OplataPlatCard=0;
if (PlatCardEdit->Text==" " || PlatCardEdit->Text=="")
        {
        PlatCardEdit->Text=0;
        }
OplataPlatCard=StrToFloat(PlatCardEdit->Text);

if (ComboBox->ItemIndex==1)
        {  //возврат
        if(glFR->PrintFiscalCheck(SumCheck,
                                        department,
                                        OplataNal,
										OplataPlatCard,
										0,
										0,
										1)==true)
                {
                res=true;
                }
        else
                {
                res=false;
                }
        }
else    //продажа
        {
        if(glFR->PrintFiscalCheck(SumCheck,
                                        department,
                                        OplataNal,
										OplataPlatCard,
										0,
										0,
										0)==true)
                {
                res=true;
                }
        else
                {
                res=false;
                }
        }
        
res=true;
return res;
}
//--------------------------------------------------------------------------
void __fastcall TFormaPrintCheckKKM::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintCheckKKM::ButtonPrintCheckClick(TObject *Sender)
{
PrintCheck();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::X1Click(TObject *Sender)
{
glFR->PrintXReport();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::Z1Click(TObject *Sender)
{
glFR->PrintZReport();
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrintCheckKKM::BitBtnOtdelClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        Kalk=new TKalkulator(Application);
        if (!Kalk) return;
        Kalk->IdRodForm=Handle;
        Kalk->FOnCloseForm=EndEdit;
        IdDochForm=Kalk->Handle;
        EditRekvisit=InputOtdel;
        Kalk->FOnCloseForm=EndEdit;
        Kalk->ShowModal();

        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintCheckKKM::EndEdit(TObject *Sender)
{
if (EditRekvisit==InputOtdel)
        {
        if(Kalk->OutReady==true)
                {
                OtdelEdit->Text=Kalk->Result;
                }
        Kalk=0;
        }
if (EditRekvisit==InputSumma)
        {
        if(Kalk->OutReady==true)
                {
                SumCheckEdit->Text=Kalk->Result;
                NalEdit->Text=Kalk->Result;
                }
        Kalk=0;
        }

if (EditRekvisit==InputNal)
        {
        if(Kalk->OutReady==true)
                {
                NalEdit->Text=Kalk->Result;
                }
        Kalk=0;
        }

if (EditRekvisit==InputPlatCard)
        {
        if(Kalk->OutReady==true)
                {
                PlatCardEdit->Text=Kalk->Result;
                }
        Kalk=0;
        }

EditRekvisit=NO;
IdDochForm=NULL;
}
//------------------------------------------------------------------------------------
void __fastcall TFormaPrintCheckKKM::BitBtnSummaClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        Kalk=new TKalkulator(Application);
        if (!Kalk) return;
        Kalk->IdRodForm=Handle;
        Kalk->FOnCloseForm=EndEdit;
        IdDochForm=Kalk->Handle;
        EditRekvisit=InputSumma;
        Kalk->FOnCloseForm=EndEdit;
        Kalk->ShowModal();

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::BitBtnNalClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        Kalk=new TKalkulator(Application);
        if (!Kalk) return;
        Kalk->IdRodForm=Handle;
        Kalk->FOnCloseForm=EndEdit;
        IdDochForm=Kalk->Handle;
        EditRekvisit=InputNal;
        Kalk->FOnCloseForm=EndEdit;
        Kalk->ShowModal();

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::BitBtnPlatCardClick(TObject *Sender)
{
if (IdDochForm==NULL)
        {
        Kalk=new TKalkulator(Application);
        if (!Kalk) return;
        Kalk->IdRodForm=Handle;
        Kalk->FOnCloseForm=EndEdit;
        IdDochForm=Kalk->Handle;
        EditRekvisit=InputPlatCard;
        Kalk->FOnCloseForm=EndEdit;
        Kalk->ShowModal();

        }
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrintCheckKKM::BitBtnSaleClick(TObject *Sender)
{
ComboBox->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::BitBtnReturnSaleClick(TObject *Sender)
{
ComboBox->ItemIndex=1; 
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::BitBtnPrintClick(TObject *Sender)
{
PrintCheck();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintCheckKKM::BitBtnCloseClick(TObject *Sender)
{
Close();         
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrintCheckKKM::N3Click(TObject *Sender)
{
glFR->PrintPoOtdelamReport();        
}
//---------------------------------------------------------------------------

