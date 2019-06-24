//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaPriemPlat.h"
#include "UFiskReg.h"
#include "IDMSprUser.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IkasDMSpr.h"
#include "IDMQueryRead.h"
#include "DateUtils.hpp"
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
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaPriemPlat::TFormaPriemPlat(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
glFR=0;;
glDisplayPok=0;

}
//---------------------------------------------------------------------------
bool TFormaPriemPlat::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();

    //необходимо получить интерфейсы фискального регистратор и дисплея
	IDevices * i_dev;
	if (InterfaceMainObject->kanQueryInterface(IID_IDevices,(void**)&i_dev)==-1)
		{
		if (i_dev)
			{
			if(	i_dev->GetDeviceObject(2, (void**) &glDisplayPok)!=-1)
				{
                glDisplayPok=0;
				}
			i_dev->kanRelease();
			}
		}
	else
		{
		glFR=0;
        glDisplayPok=0;
		}
	}

Prim->Caption="";
CodeEdit->Text="";
NumberEdit->Text="";
NameKlientEdit->Text="";
ComboBox->ItemIndex=0;

DM=new TDMPriemPlat(Application);
DM->DM_Connection=DM_Connection;
DM->Init();


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM, (void**)&DMSprARM);
DMSprARM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck, (void**)&DMCheck);
DMCheck->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient, (void**)&DMKlient);
DMKlient->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNumTel.1",IID_IDMSprNumTel, (void**)&DMSprNumTel);
DMSprNumTel->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat, (void**)&DMGurPlat);
DMGurPlat->Init(InterfaceMainObject,InterfaceImpl);

CheckPrint=false;
CheckSave=false;

NumberKvitan=0;
NumKvLabel->Caption="Квитанция: "+IntToStr(NumberKvitan);

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


IdARM=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
UpdateForm();

flObrabatChangeCodeTel=false;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCodeTel,IID_IDMSprCodeTel,
			 (void**)&DMSprCodeTel);
DMSprCodeTel->Init(InterfaceMainObject,InterfaceImpl);
DMSprCodeTel->OpenTable();

cxGrid1DBTableViewOperators->DataController->DataSource=DMSprCodeTel->DataSourceTable;
DBTextNAME_CODETEL->DataSource=DMSprCodeTel->DataSourceTable;
DBTextCOM_DEPARTMENT_NUMOTDKKT_SDEPAR->DataSource=DMSprCodeTel->DataSourceTable;
DBTextNOM_DEPARTMENT_NUMOTDKKT_SDEPAR->DataSource=DMSprCodeTel->DataSourceTable;
DBTextNAMENOM->DataSource=DMSprCodeTel->DataSourceTable;
DBTextNAMENOMCOM->DataSource=DMSprCodeTel->DataSourceTable;
DBTextPRCOMIS_SCODETEL->DataSource=DMSprCodeTel->DataSourceTable;


flObrabatChangeCodeTel=true;

ConnectFR();

return result;
}
//---------------------------------------------------------------------------
int TFormaPriemPlat::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaPriemPlat::FormClose(TObject *Sender,
      TCloseAction &Action)
{

DisconnectFR();

delete DM;
DMSprARM->kanRelease();
DMSprOborud->kanRelease();
DMCheck->kanRelease();
DMKlient->kanRelease();
DMSprNumTel->kanRelease();
DMGurPlat->kanRelease();
DM_Connection->glSaveProtocol("Закрыта форма приема платежей");
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}


}
//---------------------------------------------------------------------------

void TFormaPriemPlat::UpdateForm(void)
{
DMSprARM->OpenElement(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString));
NameKKMLabel->Caption="ККМ: "+DMSprARM->ElementNAMEKKM->AsString;
SumCheckEdit->Text=FloatToStr(SumCheck);
if (DMSprARM->GetParameter("UCH")=="YES") UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

NumberTerminalString=DMSprARM->GetParameter("NumberTerminal");
LabelNumTerminal->Caption=NumberTerminalString;

IdTerminalString=DMSprARM->GetParameter("IdTerminal");
LabelIdTerminal->Caption=IdTerminalString;

CatalogCiberplat=DMSprARM->GetParameter("CatalogCiberplat");
LabelCatalogCiberplat->Caption=CatalogCiberplat;

}
//--------------------------------------------------------------------------
bool TFormaPriemPlat::PrintCheck(void)
{
bool result=false;
// печатаем либо фискальный либо нефискальный чек

if (glFR > 0)
	{
	if(glFR->ConnectFR==false)
		{
		ShowMessage("Фискальный регистратор не подключен!");
		return result;
		}
	}
else
	{
		ShowMessage("Фискальный регистратор не подключен!");
		return result;
	}


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
	glFR->InitDocument(2);

	if (DMSprARM->GetParameter("TaxVariant") != "")
			{
			glFR->TaxVariant=StrToInt(DMSprARM->GetParameter("TaxVariant"));
			}

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

	if (DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat > 0)
        {
		StrPrint="Комиссия: "+FloatToStr(DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat)
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

		//основная услуга
		glFR->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код
		glFR->NameNom=DMSprCodeTel->TableNAMENOM->AsString;
		glFR->Quantity=1;
		glFR->Price=SumKlient;
		glFR->Amount=SumKlient;
		glFR->Department=DMSprCodeTel->TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR->AsInteger;
		glFR->Tax=1;  //без ндс

		if (glFR->AddFiscalString()==false)
			{
			throw Exception(glFR->TextError);
			}


		if (DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat > 0)
			{
			//комиссия
			glFR->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код
			glFR->NameNom=DMSprCodeTel->TableNAMENOMCOM->AsString;
			glFR->Quantity=1;
			glFR->Price=StrToFloat(SumCheckEdit->Text)-SumKlient;
			glFR->Amount=StrToFloat(SumCheckEdit->Text)-SumKlient;
			glFR->Department=DMSprCodeTel->TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR->AsInteger;
			glFR->Tax=1;  //без ндс

			if (glFR->AddFiscalString()==false)
				{
				throw Exception(glFR->TextError);
				}
			}

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

if (glFR > 0)
	{
	if(glFR->ConnectFR==false)
		{
		ShowMessage("Фискальный регистратор не подключен!");
		return Res;
		}
	}
else
	{
		ShowMessage("Фискальный регистратор не подключен!");
		return Res;
	}


NumberDoc=0;
//без создания чека не получить номер
//IDMDocCheck * check;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
//									 (void**)&check);
//check->Init(InterfaceMainObject,InterfaceImpl);
//NumberDoc=check->GetNumberNewDoc();
//check->kanRelease();
//PosDoc=Now();

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

    glFR->InitDocument(1);
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

	if (DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat > 0)
        {
		StrPrint="Комиссия: "+FloatToStr(DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat)
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

if (glFR > 0)
	{
	if(glFR->ConnectFR==false)
		{
		ShowMessage("Фискальный регистратор не подключен!");
		return result;
		}
	}
else
	{
		ShowMessage("Фискальный регистратор не подключен!");
		return result;
	}

try
	{
		//получить сотояние ККМ и получить номер чека
	if(glFR->ProvVosmPrintCheck()==false)
        {
		throw Exception(glFR->TextError);
		}

	glFR->InitDocument(1);
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

	if (DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat > 0)
        {
        StrPrint="Комиссия: "+FloatToStr(DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat)
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
if (glFR > 0)
	{
	if(glFR->ConnectFR==false)
		{
		ShowMessage("Фискальный регистратор не подключен!");
		return;
		}
	}
else
	{
		ShowMessage("Фискальный регистратор не подключен!");
		return;
	}

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
if (glFR > 0)
	{
	if(glFR->ConnectFR==false)
		{
		ShowMessage("Фискальный регистратор не подключен!");
		return;
		}
	}
else
	{
		ShowMessage("Фискальный регистратор не подключен!");
		return;
	}

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

if (glFR > 0)
{
if (glFR->ConnectFR==true)
		{
		glFR->GetSostKKM();
		DMCheck->DocNKLCHK->AsInteger=glFR->NumberKL;
		DMCheck->DocNCHECKCHK->AsInteger=glFR->NumberCheck;
		DMCheck->DocREGNUMCHK->AsString=glFR->RegNumberKKM;
		DMCheck->DocSAVNUMCHK->AsString=glFR->SerialNumberKKM;
		DMCheck->DocMODELCHK->AsString=glFR->ModelKKM;
        } 
}


DMCheck->Doc->Post();

DM->OpenNom(glStrToInt64(DMSprCodeTel->TableID_CODETEL->AsString));
DM->OpenCom(glStrToInt64(DMSprCodeTel->TableID_CODETEL->AsString));

DMCheck->AddDocNewString();
DMCheck->DocT->Edit();
DMCheck->DocTIDNOMCHKT->AsString=DM->IBQNomIDNOM->AsString;
DMCheck->DocTIDEDCHKT->AsString=DM->IBQNomIDED->AsString;
DMCheck->DocTKOLCHKT->AsFloat=1;
DMCheck->DocTKFCHKT->AsFloat=DM->IBQNomKFED->AsFloat;
DMCheck->DocTPRICECHKT->AsFloat=SumKlient;//StrToFloat(SumCheckEdit->Text)-;
DMCheck->DocT->Post();

if (DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat > 0)
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


SumKlient=StrToFloat(SumCheckEdit->Text)*(1-DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat/100 );
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

if(glFR > 0)
	{
	if(glFR->ProvVosmPrintCheck()==false)
			{
			return result;
			}
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
					   NumberKvitan ,
					   IdVibCodeTel);

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
					   DMSprCodeTel->TableCODOPER_CODETEL->AsInteger,
					   DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString),
					   IdVibCodeTel);
				}
		}
else
		{
				DMGurPlat->AddPlat(CodeEdit->Text,
					   NumberEdit->Text,
					   StrToFloat(SumCheckEdit->Text),
					   NumberKvitan,
					   DMSprCodeTel->TableCODOPER_CODETEL->AsInteger,
					   DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString),
					   IdVibCodeTel);

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
NumberKvitan=StrToInt(DMGurPlat->GetNumberKv(CodeEdit->Text))+1;
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


void __fastcall TFormaPriemPlat::MaimMenuProvestiPlategClick(TObject *Sender)
{


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
					   NumberKvitan ,
					   IdVibCodeTel);

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
					   DMSprCodeTel->TableCODOPER_CODETEL->AsString,
					   DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString),
					   IdVibCodeTel);
				}
		}
else
		{
				DMGurPlat->AddPlat(CodeEdit->Text,
					   NumberEdit->Text,
					   StrToFloat(SumCheckEdit->Text),
					   NumberKvitan,
					   DMSprCodeTel->TableCODOPER_CODETEL->AsString,
					   DMSprCodeTel->TablePRCOMIS_SCODETEL->AsFloat,
					   SumKlient,
					   glStrToInt64(DMKlient->ElementIDKLIENT->AsString),
					   IdVibCodeTel);

		}

}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
bool TFormaPriemPlat::ConnectFR(void)
{
bool result=false;
DMSprOborud->OpenTablePoTypeOborud(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString), "fr");
		if (Trim(DMSprOborud->TableTYPE_OBORUD->AsString)=="fr")
				{
				DM_Connection->glSaveProtocol("Попытка подключить фискальный регистратор");

					DMSprOborud->OpenElement(glStrToInt64(DMSprOborud->TableID_OBORUD->AsString));
					AnsiString prog_id=DMSprOborud->ElementPROGID_SOBORUD->AsString;
					InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
																(void**)&glFR);
					glFR->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
					glFR->Init(InterfaceMainObject,0);
					glFR->Number=1;
					//glFR->InitDevice();
					int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
					AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

					AnsiString password=DMSprOborud->GetParameter("password");



				IkasDMSpr * oborud_param;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborudParam,IID_IkasDMSpr,
																 (void**)&oborud_param);
				oborud_param->Init(InterfaceMainObject,0);
				oborud_param->IdOwner=glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString);
				oborud_param->OpenTable(0);
				//установим параметры подключения
				oborud_param->First(0);
				while(!oborud_param->GetEof(0))
					{
					TkasVariant * kv=new TkasVariant;
					if (oborud_param->GetValueFieldAsBool("ON_CONNECT_SOBORUD_PAR", 0)==true &&
									oborud_param->GetValueFieldAsBool("BEFORE_CONNECT_SOBORUD_PAR", 0)==true)
						{ //устанавливаем данный параметр
						int type_value=oborud_param->GetValueFieldAsInt("TYPE_PARAMETER_SOBORUD_PAR", 0);
						if (type_value == 1) //int
							{
							kv->type=1; kv->int_value=oborud_param->GetValueFieldAsInt("VALUE_SOBORUD_PAR", 0);
							}
						if (type_value == 2) //string
							{
							kv->type=2; kv->string_value=oborud_param->GetValueFieldAsString("VALUE_SOBORUD_PAR", 0).c_str(); kv->len_string=wcslen(kv->string_value);
							}
						if (type_value == 4) //booulean
							{
							kv->type=4; kv->bool_value=oborud_param->GetValueFieldAsBool("VALUE_SOBORUD_PAR", 0);
							}

						if (glFR->SetParameter(oborud_param->GetValueFieldAsString("NAME_SOBORUD_PAR", 0), kv) == false)
							{
							ShowMessage("Ошибка при установке параметра подключения");
							}
						}
					oborud_param->Next(0);
					delete kv;
					}


					if(glFR->Connect(number_port, baud_rate, password)==true)
						{
						glFR->ConnectFR=true;
						result=true;
						}
					else
						{
						glFR->ConnectFR=false;
						result=false;
						ShowMessage("Ошибка при подключении фискального регистратора: "+glFR->TextError);
						DM_Connection->glSaveProtocol("Ошибка при подключении фискального регистратора: "+glFR->TextError);
						DisconnectFR();

						}
				oborud_param->kanRelease();
			   }

return result;
}
//-----------------------------------------------------------------------------
bool TFormaPriemPlat::DisconnectFR(void)
{
bool result=true;

if (glFR > 0)
	{
	 glFR->Disconnect();
	 glFR->Done();
	 glFR->kanRelease();
	 glFR=0;
	}
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TFormaPriemPlat::CreateZaprosProverki(void)
{
UnicodeString result="";

UnicodeString name_file_blok=CatalogCiberplat+"\\"+"$int__p$."+NumberTerminalString;
if (FileExists(name_file_blok)==true)
		{
		ShowMessage("Сервер Киберплат занят. Не удален файл блокировки! Не формируем запрос.");
		return result;
		}



result="=10 C";

result=result+GetNumberZaprosa();

if (IdTerminalString.Length()==26)
	{
    result=result+IdTerminalString;
	}
else
	{
	if (IdTerminalString.Length() > 26 )
		{
		result=result+IdTerminalString.SetLength(26);
		}
	else
		{
		result=result+glDopStrR(IdTerminalString," ",26);
		}
	}

result=result+kasDecodeDateTime (Now());

if (DMSprCodeTel->TableCODOPER_CODETEL->AsString.Length()==2)
	{
	result=result+DMSprCodeTel->TableCODOPER_CODETEL->AsString;
	}
else
	{
	if (DMSprCodeTel->TableCODOPER_CODETEL->AsString.Length() > 2 )
		{
		result=result+DMSprCodeTel->TableCODOPER_CODETEL->AsString.Delete(1,DMSprCodeTel->TableCODOPER_CODETEL->AsString.Length()-2);
		}
	else
		{
		result=result+glDopStrL(DMSprCodeTel->TableCODOPER_CODETEL->AsString," ",2);
		}
	}



if (SumCheckEdit->Text.Length()==8)
	{
	result=result+SumCheckEdit->Text;
	}
else
	{
	if (SumCheckEdit->Text.Length() > 8 )
		{
		result=result+SumCheckEdit->Text.Delete(1,SumCheckEdit->Text.Length()-8);
		}
	else
		{
		result=result+glDopStrL(SumCheckEdit->Text," ",8);
		}
	}

UnicodeString number_phone=CodeEdit->Text+NumberEdit->Text;

if (number_phone.Length()==20)
	{
	result=result+number_phone;
	}
else
	{
	if (number_phone.Length() > 20 )
		{
		result=result+number_phone.Delete(1,number_phone.Length()-20);
		}
	else
		{
		result=result+glDopStrL(number_phone," ",20);
		}
	}


if (cxTextEditLicSchet->Text.Length()==30)
	{
	result=result+cxTextEditLicSchet->Text;
	}
else
	{
	if (cxTextEditLicSchet->Text.Length() > 30 )
		{
		result=result+cxTextEditLicSchet->Text.SetLength(30);
		}
	else
		{
		result=result+glDopStrL(cxTextEditLicSchet->Text," ",30);
		}
	}


result=result+"  ";  //код ответа

UnicodeString auth_code="";
result=result+glDopStrL(auth_code," ",20);

UnicodeString op_name="";
result=result+glDopStrL(op_name," ",20);

UnicodeString msg="";
result=result+glDopStrL(msg," ",49);

result=result+"\\0d\\0a";


LabelZaprosProverkaRekvisitov->Caption=result;


if(result.Length()!=200)
	{
	ShowMessage("Не формируем запрос. Длина пакета не равна 200 символам! Длина: "+IntToStr(result.Length()));
	return result;
	}


UnicodeString name_file_zapros=CatalogCiberplat+"\\"+"$int__i$."+NumberTerminalString;

if (FileExists(name_file_zapros)==true)
		{
		ShowMessage("Не удален предыдущий файл запроса! Не формируем запрос");
		return result;
		}


return result;
}
//-----------------------------------------------------------------------------
void TFormaPriemPlat::SaveZaprosProverki(void)
{


}
//-----------------------------------------------------------------------------
UnicodeString TFormaPriemPlat::GetNumberZaprosa(void)
{
UnicodeString result="";
//сначала надо попытаться найти старую проверку
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros="SELECT NEXT VALUE FOR GEN_CIBERPLAT_NUM_ZAPROSA FROM RDB$DATABASE";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ExecQuery();
result=dm_qr->pFIBQ->FieldByName("GEN_ID")->AsString;
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();


if (result.Length()==4)
	{

	}
else
	{
	if (result.Length()> 4)
		{
		result = result.Delete(1,result.Length()-4);     //проверял работает, индекс начинается с 1, если 0 то не удаляется
		}
	else
		{
		result=glDopStrL(result,"0",4);
		}

	}

NumberZaprosa=result;

return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaPriemPlat::cxButton1Click(TObject *Sender)
{
CreateZaprosProverki();
}
//---------------------------------------------------------------------------
UnicodeString TFormaPriemPlat::kasDecodeDateTime (TDateTime value)
{
UnicodeString result="";

unsigned short year,month, day, hour, min,sec,msec;

DecodeDateTime(value,year,month, day, hour, min,sec,msec);

UnicodeString str_year,str_month, str_day, str_hour, str_min,str_sec,str_msec;

str_year=IntToStr(year);
str_month=IntToStr(month);
str_day=IntToStr(day);
str_hour=IntToStr(hour);
str_min=IntToStr(min);
str_sec=IntToStr(sec);


if (str_year.Length()==2)
	{
	result=result+str_year;
	}
else
	{
	if (str_year.Length()>2)
		{
		str_year=str_year.Delete(1,str_year.Length()-2);
		}
	else
		{
		str_year=glDopStrL(str_year,"0",2);
		}
	}

if (str_month.Length()==2)
	{
	result=result+str_month;
	}
else
	{
	if (str_month.Length()>2)
		{
		str_month=str_month.Delete(1,str_month.Length()-2);
		}
	else
		{
		str_month=glDopStrL(str_month,"0",2);
		}
	}

if (str_day.Length()==2)
	{
	result=result+str_day;
	}
else
	{
	if (str_day.Length()>2)
		{
		str_day=str_day.Delete(1,str_day.Length()-2);
		}
	else
		{
		str_day=glDopStrL(str_day,"0",2);
		}
	}

if (str_hour.Length()==2)
	{
	result=result+str_hour;
	}
else
	{
	if (str_hour.Length()>2)
		{
		str_hour=str_hour.Delete(1,str_hour.Length()-2);
		}
	else
		{
		str_hour=glDopStrL(str_hour,"0",2);
		}
	}

if (str_min.Length()==2)
	{
	result=result+str_min;
	}
else
	{
	if (str_min.Length()>2)
		{
		str_min=str_min.Delete(1,str_min.Length()-2);
		}
	else
		{
		str_min=glDopStrL(str_min,"0",2);
		}
	}

if (str_sec.Length()==2)
	{
	result=result+str_sec;
	}
else
	{
	if (str_sec.Length()>2)
		{
		str_sec=str_sec.Delete(1,str_sec.Length()-2);
		}
	else
		{
		str_sec=glDopStrL(str_sec,"0",2);
		}
	}



result=str_day+str_month+str_year+str_hour+str_min+str_sec;

return result;
}
//---------------------------------------------------------------------------

