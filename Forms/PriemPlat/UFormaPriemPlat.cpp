//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaPriemPlat.h"
#include "UFiskReg.h"
#include "UDMSprUser.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxCalc"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


////фискальный регистратор
extern TFiskReg  *glFR;

//---------------------------------------------------------------------------
__fastcall TFormaPriemPlat::TFormaPriemPlat(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool TFormaPriemPlat::Init(void)
{
bool result=false;

TextCheck->Clear();
Prim->Caption="";
CodeEdit->Text="";
NumberEdit->Text="";
NameKlientEdit->Text="";
ComboBox->ItemIndex=0;

DM=new TDMPriemPlat(Application);
DM->DM_Connection=DM_Connection;
DM->Init();
DMSprARM=new TDMSprARM(Application);
DMSprARM->DM_Connection=DM_Connection;
DMSprARM->Init();
DMCheck= new TDMDocCheck(Application);
DMCheck->DM_Connection=DM_Connection;
DMCheck->Init();
DMKlient= new TDMSprKlient(Application);
DMKlient->DM_Connection=DM_Connection;
DMKlient->Init();
DMSprNumTel= new TDMSprNumTel(Application);
DMSprNumTel->DM_Connection=DM_Connection;
DMSprNumTel->Init();
DMGurPlat=new TDMGurPlat(Application);
DMGurPlat->DM_Connection=DM_Connection;
DMGurPlat->Init();

CheckPrint=false;
CheckSave=false;

NumberKvitan=0;
NumKvLabel->Caption="Квитанция: "+IntToStr(NumberKvitan);
NameOperatorLabel->Caption="";
CodOperLabel->Caption="";
ProcentLabel->Caption="";
SumKlLabel->Caption="";
Prim->Caption="";
KlNaydenLabel->Caption="";
SumCheckEdit->Text="0";
DM_Connection->glSaveProtocol("Открыта форма приема платежей");


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
void __fastcall TFormaPriemPlat::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}

delete DM;
delete DMSprARM;
delete DMCheck;
delete DMKlient;
delete DMSprNumTel;
delete DMGurPlat;
DM_Connection->glSaveProtocol("Закрыта форма приема платежей");
Action=caFree;
}
//---------------------------------------------------------------------------

void TFormaPriemPlat::UpdateForm(void)
{
DMSprARM->OpenElement(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString));
NameKKMLabel->Caption="ККМ: "+DMSprARM->ElementNAMEKKM->AsString;
SumCheckEdit->Text=FloatToStr(SumCheck);
if (DMSprARM->GetParameter("UCH")=="YES") UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::PrintCheck(void)
{
bool result=false;
// печатаем либо фискальный либо нефискальный чек
if(DMSprARM->GetParameter("PrintFiscalCheck")=="1")
	{
	result=PrintFiscalCheck();
	}
else
	{
	result=PrintNoFiscalCheck();
	}

return result;
}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::PrintFiscalCheck(void)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек");
bool Res=false;

if(glFR->ConnectFR==false) return Res;


try
	{
	//получить сотояние ККМ и получить номер чека
	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->GetSostKKM()==false)
		{
		throw Exception(glFR->TextError);
		}
	if (glFR->OpenNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (DMSprARM->GetParameter("STR_ZAG_1")!="")
		{
		if(glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_2")!="")
		{
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_3")!="")
		{
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (glFR->PrintString(" ",1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if (glFR->PrintString(DM->IBQNomKRNAMENOM->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
	if (NameKlientEdit->Text!="")
		{
		if (glFR->PrintString("Абонент:",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if (glFR->PrintString(NameKlientEdit->Text,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	StrPrint="("+CodeEdit->Text+") "+NumberEdit->Text;

	if (glFR->PrintString(StrPrint,4,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}


	if (glFR->PrintString("Квитанция: "+IntToStr(NumberKvitan),1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

	if (ProcentCommission>0)
        {
		StrPrint="Комиссия: "+FloatToStr(ProcentCommission)
                +"% -- "
				+FloatToStrF(StrToFloat(SumCheckEdit->Text)-SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        StrPrint="На счет: "+FloatToStrF(SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}
        
	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
	if (glFR->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

	if (glFR->CloseNoFiscalCheck()==false)
			{
			throw Exception(glFR->TextError);
			}

	if (DMSprARM->GetParameter("UCH")!="YES")
		{
        //glFR->Operation=glFR->Sale;
		double SumCheck=StrToFloat(SumCheckEdit->Text);
        double OplataNal=StrToFloat(SumCheckEdit->Text);
		double OplataPlatCard=0;

		if(glFR->PrintFiscalCheck(SumCheck,2,OplataNal,OplataPlatCard,0,0,0)==false)
			{
			throw Exception(glFR->TextError);
			}
		}
	else
		{
		//glFR->Operation=glFR->Sale;
		double SumCheck=StrToFloat(SumCheckEdit->Text);
		double OplataNal=StrToFloat(SumCheckEdit->Text);
		double OplataPlatCard=0;

		if(glFR->PrintNoFiscalCheck(SumCheck,2,OplataNal,OplataPlatCard,0,0,0)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	DM_Connection->glSaveProtocol("Чек напечатан!");
	CheckPrint=true;

	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	DM_Connection->glSaveProtocol("Чек не напечатан! ошибка:"+TextError);
	}
return Res;

}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::PrintNoFiscalCheck(void)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек");
bool Res=false;

if(glFR->ConnectFR==false) return Res;


NumberDoc=0;
TDMDocCheck * check=new TDMDocCheck(Application);
check->DM_Connection=DM_Connection;
check->Init();
NumberDoc=check->GetNumberNewDoc();
delete check;
PosDoc=Now();

try
	{
	//получить сотояние ККМ и получить номер чека
	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->GetSostKKM()==false)
		{
		throw Exception(glFR->TextError);
		}
	if (glFR->OpenNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (DMSprARM->GetParameter("STR_ZAG_1")!="")
		{
		if(glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_2")!="")
		{
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_3")!="")
		{
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (glFR->PrintString("Товарный чек №"+IntToStr(NumberDoc),1,0,1,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

	if (glFR->PrintString("от "+DateTimeToStr(PosDoc),1,0,1,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

	if (glFR->PrintString(" ",1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if (glFR->PrintString(DM->IBQNomKRNAMENOM->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
	if (NameKlientEdit->Text!="")
		{
		if (glFR->PrintString("Абонент:",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if (glFR->PrintString(NameKlientEdit->Text,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	StrPrint="("+CodeEdit->Text+") "+NumberEdit->Text;

	if (glFR->PrintString(StrPrint,4,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}


	if (glFR->PrintString("Квитанция: "+IntToStr(NumberKvitan),1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

	if (ProcentCommission>0)
        {
		StrPrint="Комиссия: "+FloatToStr(ProcentCommission)
                +"% -- "
				+FloatToStrF(StrToFloat(SumCheckEdit->Text)-SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        StrPrint="На счет: "+FloatToStrF(SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}
        
	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
	if (glFR->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		double SumCheck=StrToFloat(SumCheckEdit->Text);
        //double OplataNal=StrToFloat(SumCheckEdit->Text);
		//double OplataPlatCard=0;

		if(glFR->PrintString("Итог: "+FloatToStrF(SumCheck,ffFixed,15,2),4,1,2,true,false,false)==false)
				{
				throw Exception(glFR->TextError);
				}

		for (int i=0;i<3;i++)
			{
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			 }

		if(glFR->PrintString("Подпись _____________ ",1,0,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		for (int i=0;i<6;i++)
			{
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			 }

		if(glFR->CloseNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}

    glFR->Cut(1);

	DM_Connection->glSaveProtocol("Чек напечатан!");
	CheckPrint=true;

	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	DM_Connection->glSaveProtocol("Чек не напечатан! ошибка:"+TextError);
	}
return Res;

}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::PrintKvitan(void)
{
DM_Connection->glSaveProtocol("Попытка напечать квитанцию");
bool result=false;

if(glFR->ConnectFR==false) return result;

try
	{
		//получить сотояние ККМ и получить номер чека
	if(glFR->ProvVosmPrintCheck()==false)
        {
		throw Exception(glFR->TextError);
        }
	if (glFR->OpenNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false)==false)
			{
            throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		if (glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (glFR->PrintString(" ",1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->PrintString("Квитанция "+IntToStr(NumberKvitan),4,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->PrintString(" ",1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->PrintString(DM->IBQNomKRNAMENOM->AsString,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint="Дата: "+DateTimeToStr(Now());
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if (NameKlientEdit->Text!="")
		{
		if (glFR->PrintString("Абонент:",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if (glFR->PrintString(NameKlientEdit->Text,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (glFR->PrintString("Номер:",1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint="("+CodeEdit->Text+") "+NumberEdit->Text;
	if (glFR->PrintString(StrPrint,4,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint="Сумма:"+SumCheckEdit->Text+"руб.";
	if (glFR->PrintString(StrPrint,4,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if (ProcentCommission>0)
        {
        StrPrint="Комиссия: "+FloatToStr(ProcentCommission)
                +"% -- "
				+FloatToStrF(StrToFloat(SumCheckEdit->Text)-SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        StrPrint="На счет: "+FloatToStrF(SumKlient,ffFixed,10,2)+"руб.";
		if (glFR->PrintString(StrPrint,1,0,2,true,false, false)==false)
			{
            throw Exception(glFR->TextError);
			}
        }

	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint="Подпись абонента:";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint=" ";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	StrPrint="Подпись касcира:";
	if (glFR->PrintString(StrPrint,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	for(int i=0;i<3;i++)
        {
		if (glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }
        
	if (glFR->CloseNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->Cut(1)==false)
		{
		throw Exception(glFR->TextError);
		}
		
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}
DM_Connection->glSaveProtocol("Квитанция напечатана");
DM_Connection->glSaveProtocol(TextError);
return result;
}

//--------------------------------------------------------------------------
void __fastcall TFormaPriemPlat::X1Click(TObject *Sender)
{
if(glFR->ConnectFR==false) return;

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->PrintXReport();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::Z1Click(TObject *Sender)
{
if(glFR->ConnectFR==false) return;

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {

		glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->PrintZReport();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::N3Click(TObject *Sender)
{
//FR.OleProcedure("PrintDepartmentReport");        
}
//---------------------------------------------------------------------------
bool TFormaPriemPlat::PoiskKlienta(void)
{
DM_Connection->glSaveProtocol("Поиск клиента");
bool result=false;
KlNayden=false;


DM->GetIDKlientPoNumTel(CodeEdit->Text,NumberEdit->Text);


if(DM->IBQNumTel->RecordCount>0)
        {
         result=true;
         KlNayden=true;
         KlNaydenLabel->Caption="Клиент найден!";
		 DM_Connection->glSaveProtocol("клиент найден");

        }
else
        {
        KlNayden=false;
        result=false;
        KlNaydenLabel->Caption="Клиент не найден!";
		DM_Connection->glSaveProtocol("Клиент не найден");
        }
DMKlient->OpenElement(glStrToInt64(DM->IBQNumTelIDKLIENT_NUMTEL->AsString));
NameKlientEdit->Text=DMKlient->ElementNAMEKLIENT->AsString;

CheckPrint=false;
CheckSave=false;
return result;
}
//----------------------------------------------------------------------------
bool TFormaPriemPlat::PoiskUslugi(void)
{
bool result=false;
UslNayden=false;

DM->OpenNomPoCoduTel(CodeEdit->Text);


NameOperatorLabel->Caption=DM->IBQNomNAME_CODETEL->AsString;
CodOperator=Trim(DM->IBQNomCODOPER_CODETEL->AsString);
CodOperLabel->Caption="Код оператора: "+CodOperator;
AnsiString commission_str="";
commission_str=DMSprARM->GetParameter("commission_"+Trim(DM->IBQNomCODE_CODETEL->AsString));
if (commission_str=="")
        {
        commission_str=DMSprARM->GetParameter("commission_default");
        if (commission_str=="")
                {
                commission_str="0";
                }
        }
ProcentLabel->Caption="Комиссия: "+commission_str+"%";
ProcentCommission=StrToFloat(commission_str);
IdNomCommission=glStrToInt64(DM->IBQNomIDNOMCOM_CODETEL->AsString);


DM->OpenCom(IdNomCommission);

NameNomCommissionLabel->Caption=DM->IBQComKRNAMENOM->AsString;

if (DM->IBQNom->RecordCount==0)
        {
        ShowMessage("Не найдена услуга по коду телефона!");
        result=false;
        }
else
        {
        result=true;
        UslNayden=true;
        }

return result;
}
//----------------------------------------------------------------------------
bool TFormaPriemPlat::AddNewKlient(void)
{
bool result=false;
__int64 id_grp=0;
if (Trim(DMSprARM->GetParameter("ID_GRP"))!="")
        {
        id_grp=glStrToInt64(DMSprARM->GetParameter("ID_GRP"));
		}

//проверим, а нет ли уже такого клиента по наименованию
//если есть то добавим ему номер, не будем создавать нового
__int64 id_kl=DMKlient->GetIDKlientPoName(Trim(NameKlientEdit->Text ));
if (id_kl==0)
	{
	DMKlient->NewElement(id_grp);
	DMKlient->Element->Edit();
	DMKlient->ElementNAMEKLIENT->AsString=NameKlientEdit->Text;
	DMKlient->ElementFNAME->AsString=NameKlientEdit->Text;
	DMKlient->Element->Post();
	DMKlient->SaveElement();
	DMSprNumTel->NewElement(glStrToInt64(DMKlient->ElementIDKLIENT->AsString));
	}
else
	{
    DMSprNumTel->NewElement(id_kl);
	}

DMSprNumTel->Element->Edit();
DMSprNumTel->ElementCODE_NUMTEL->AsString=CodeEdit->Text;
DMSprNumTel->ElementNUMBER_NUMTEL->AsString=NumberEdit->Text;
DMSprNumTel->Element->Post();
DMSprNumTel->SaveElement();
result=true;
return result;
}
//------------------------------------------------------------------------------
bool TFormaPriemPlat::CreateDocCheck(void)
{
DM_Connection->glSaveProtocol("Попытка создать новый чек");
bool result=false;

if (Trim(NameKlientEdit->Text)!="")
	{
	if (KlNayden==false)
        {
        AddNewKlient();
        }
	else
        { //исправить наименование клиента
        if(Trim(DMKlient->ElementNAMEKLIENT->AsString)!=Trim(NameKlientEdit->Text))
                {
                DMKlient->Element->Edit();
                DMKlient->ElementNAMEKLIENT->AsString=NameKlientEdit->Text;
                DMKlient->ElementFNAME->AsString=NameKlientEdit->Text;
                DMKlient->Element->Post();
                DMKlient->SaveElement();

                }
        }
	}

DMCheck->NewDoc();


DMCheck->DocAll->Edit();

if(NumberDoc!=0)
	{
	DMCheck->DocAllNUMDOC->AsInteger=NumberDoc;
	}
if (PosDoc > (Now()-10000))
	{   //позиция документа задана
	DMCheck->DocAllPOSDOC->AsString=PosDoc;
	}

DMCheck->DocAllIDBASE_GALLDOC->AsString=DMSprARM->ElementIDBASE_SARM->AsString;

if (glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString)>0)
	{
	DMCheck->DocAllIDFIRMDOC->AsString=DMSprARM->ElementIDFIRM_SARM->AsString;
	}
if (glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString)>0)
	{
	DMCheck->DocAllIDSKLDOC->AsString=DMSprARM->ElementIDSKLAD_SARM->AsString;
	}
	

if (glStrToInt64(DMKlient->ElementIDKLIENT->AsString)!=0)
	{
	DMCheck->DocAllIDKLDOC->AsString=DMKlient->ElementIDKLIENT->AsString;
	}

DMCheck->DocAll->Post();

DMCheck->Doc->Edit();
DMCheck->DocIDKKMCHK->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
DMCheck->DocIDTPRICE->AsString=DMSprARM->ElementIDTPRICEPOD->AsString;

if (glFR->ConnectFR==true)
		{
		glFR->GetSostKKM();
		DMCheck->DocNKLCHK->AsInteger=glFR->NumberKL;
		DMCheck->DocNCHECKCHK->AsInteger=glFR->NumberCheck;
		DMCheck->DocREGNUMCHK->AsString=glFR->RegNumberKKM;
		DMCheck->DocSAVNUMCHK->AsString=glFR->SerialNumberKKM;
		DMCheck->DocMODELCHK->AsString=glFR->ModelKKM;
        } 

DMCheck->Doc->Post();

DMCheck->AddDocNewString();
DMCheck->DocT->Edit();
DMCheck->DocTIDNOMCHKT->AsString=DM->IBQNomIDNOM->AsString;
DMCheck->DocTIDEDCHKT->AsString=DM->IBQNomIDED->AsString;
DMCheck->DocTKOLCHKT->AsFloat=1;
DMCheck->DocTKFCHKT->AsFloat=DM->IBQNomKFED->AsFloat;
DMCheck->DocTPRICECHKT->AsFloat=SumKlient;//StrToFloat(SumCheckEdit->Text)-;
DMCheck->DocT->Post();
if (ProcentCommission>0)
        {
        DMCheck->AddDocNewString();
        DMCheck->DocT->Edit();
		DMCheck->DocTIDNOMCHKT->AsString=DM->IBQComIDNOM->AsString;
        DMCheck->DocTIDEDCHKT->AsString=DM->IBQComIDBASEDNOM->AsString;
        DMCheck->DocTKOLCHKT->AsFloat=1;
        DMCheck->DocTKFCHKT->AsFloat=1;
        DMCheck->DocTPRICECHKT->AsFloat=StrToFloat(SumCheckEdit->Text)-SumKlient;//StrToFloat(SumCheckEdit->Text)-;
        DMCheck->DocT->Post();


        }






if (DMCheck->SaveDoc()==true )
        {
        CheckSave=true;
        if(DMCheck->DvRegDoc()==true)
                {
                Prim->Caption="Чек успешно сформирован!";
				DM_Connection->glSaveProtocol("Чек на платеж успешно сформирован");

                }
        else
                {
                Prim->Caption="Не удалось провести чек!";
				DM_Connection->glSaveProtocol("Чек на платеж не проведен");
				}
        result=true;
        }
else
        {
        Prim->Caption="Не удалось записать чек!";
		DM_Connection->glSaveProtocol("Чек на платеж не записан");
		ShowMessage("Ошибка при записи чека! "+DMCheck->TextError);
        result=false;
        }
return result;
}
//----------------------------------------------------------------------------
bool TFormaPriemPlat::UpdateTextCheck(void)
{
bool result=false;
TextCheck->Clear();

if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		TextCheck->Lines->Add(DM_Connection->Arm_GetParameter("STR_ZAG_1"));
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		TextCheck->Lines->Add(DM_Connection->Arm_GetParameter("STR_ZAG_2"));
        }

if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {
        TextCheck->Lines->Add(DM_Connection->Arm_GetParameter("STR_ZAG_3"));
        }


TextCheck->Lines->Add("");
TextCheck->Lines->Add(DM->IBQNomKRNAMENOM->AsString);


TextCheck->Lines->Add("Абонент:");
TextCheck->Lines->Add(NameKlientEdit->Text);
TextCheck->Lines->Add("("+CodeEdit->Text+")  "+NumberEdit->Text);

TextCheck->Lines->Add("");
TextCheck->Lines->Add("Сумма: "+SumCheckEdit->Text);

SumKlient=StrToFloat(SumCheckEdit->Text)*(1-ProcentCommission/100 );
SumKlLabel->Caption="Сумма клиенту: "+FloatToStr(SumKlient);

return result;
//
}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::EnablePrintCheck(void)
{
bool result=false;

if (DMSprARM->Element->RecordCount==0)
        {
        ShowMessage("Не найденa ККМ в справочнике!");
        return result;
        }

if(glFR->ProvVosmPrintCheck()==false)
        {
        return result;
        }

result=true;
return result;
}
//----------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::ButtonPrintKvitanClick(TObject *Sender)
{
PrintKvitan();
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::ButtonPrintCheckClick(TObject *Sender)
{
if (CheckPrint==true)
        {
        String V="Кассовый чек уже пробит! Пробить ещё один?";
		DM_Connection->glSaveProtocol(V);
        String Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
                DM_Connection->glSaveProtocol("Нажата конопка Да");
                if (EnablePrintCheck()==true )
						{
                        PrintCheck();
                        }
				}
        }
else
		{
        if (EnablePrintCheck()==true )
                {
				PrintCheck();
                }
        }

if (CheckSave==true)
        {
		String V="Кассовый чек уже добавлен в журнал! Добавить ещё один?";
		DM_Connection->glSaveProtocol("Повторное добавление чека в журнал");
        String Z="Внимание!";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                CreateDocCheck();
				}
        }
else
		{
        CreateDocCheck();
		}

        
//проверим а нет ли уже такого платежа
//добавим платеж в журнал платежей
bool est=false;
est=DMGurPlat->CheckPlat(CodeEdit->Text,
					   NumberEdit->Text,
                       StrToFloat(SumCheckEdit->Text),
                       NumberKvitan );

if (est==true)
        {
		String V="Платеж с такими реквизитами уже есть в журнале платежей. Добавить ещё один?";
		DM_Connection->glSaveProtocol("Добавление повторного платежа в журнал платежей");
		String Z="Внимание! Повторный платеж!";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				DMGurPlat->AddPlat(CodeEdit->Text,
					   NumberEdit->Text,
					   StrToFloat(SumCheckEdit->Text),
					   NumberKvitan,
					   CodOperator,
					   ProcentCommission,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString));
				}
		}
else
		{
				DMGurPlat->AddPlat(CodeEdit->Text,
					   NumberEdit->Text,
					   StrToFloat(SumCheckEdit->Text),
					   NumberKvitan,
					   CodOperator,
					   ProcentCommission,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString));

		}
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaPriemPlat::CodeEditKeyPress(TObject *Sender, char &Key)
{
if (Key!=VK_RETURN) return;
NumberEdit->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::CodeEditExit(TObject *Sender)
{
PoiskUslugi();
UpdateTextCheck();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::NumberEditKeyPress(TObject *Sender, char &Key)
{
if (Key!=VK_RETURN) return;

//NumberKvitan=DMGurPlat->GetNumberKv(CodeEdit->Text)+1;
//NumKvLabel->Caption="Квитанция: "+IntToStr(NumberKvitan);
//
//PoiskKlienta();
//UpdateTextCheck();
NameKlientEdit->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::NumberEditExit(TObject *Sender)
{
PoiskKlienta();
UpdateTextCheck();
NumberKvitan=DMGurPlat->GetNumberKv(CodeEdit->Text)+1;
NumKvLabel->Caption="Квитанция: "+IntToStr(NumberKvitan);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::NameKlientEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key!=VK_RETURN) return;
UpdateTextCheck();
ComboBox->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::NameKlientEditExit(TObject *Sender)
{
UpdateTextCheck();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::ComboBoxKeyPress(TObject *Sender, char &Key)
{
if (Key!=VK_RETURN) return;

OtdelEdit->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::OtdelEditKeyPress(TObject *Sender, char &Key)
{
if (Key!=VK_RETURN) return;

SumCheckEdit->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::SumCheckEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		UpdateTextCheck();
		ButtonPrintKvitan->SetFocus();
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::SumCheckEditExit(TObject *Sender)
{
UpdateTextCheck();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("PriemPlat");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPriemPlat::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

