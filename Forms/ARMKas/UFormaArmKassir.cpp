//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaArmKassir.h"
//#include <oleauto.hpp>
//#include "UDMSprEd.h"
#include "UFiskReg.h"
#include "UDMSprBVNom.h"
#include "UDMSprDogovor.h"
#include "UDMSprKlient.h"
//#include "UDMGurAllDoc.h"
#include "UScaner.h"
#include "UDMSprFirm.h"
#include "UDMSprSklad.h"
#include "UDMRegVsRasch.h"

#include "UDMGurOperDiscountCard.h"
#include "UDMSprVidDiscountCard.h"
#include "UDMSprNakSkidok.h"
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include "UDMSetup.h"
#include "UDMRegGoods.h"
#include "UDMSprProject.h"


#include "math.h"
#include "UDisplayPok.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
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
#pragma link "cxStyles"
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


////фискальный регистратор
extern TFiskReg  *glFR;
extern TScaner * glScaner;
extern TDisplayPok * glDisplayPok;

//---------------------------------------------------------------------------
__fastcall TFormaARMKassir::TFormaARMKassir(TComponent* Owner)
		: TForm(Owner)
{

}
//---------------------------------------------------------------------------
bool TFormaARMKassir::Init(void)
{
bool result=false;

EditRekvisit=NO;
DM= new TDMDocCheck(Application);
DM->DM_Connection=DM_Connection;
DM->Init();
DM->AutoRaschet=true;
DMSprARM=new TDMSprARM(Application);
DMSprARM->DM_Connection=DM_Connection;
DMSprARM->Init();

Nom=new TDMSprNom(Application);
Nom->DM_Connection=DM_Connection;
Nom->Init();
Ed=new TDMSprEd(Application);
Ed->DM_Connection=DM_Connection;
Ed->Init();
ObBar=new TObjectBarCode();
ObBar->DM_Connection=DM_Connection;
ObBar->Init();
ObBar->SprNom=Nom;
ObBar->SprEd=Ed;
ObBar->GetValuePrefiksBarCode();


Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
CheckSave=false;
CheckPrint=true;
CheckCreate=false;
OutReady=false;


NameNomDBText->DataSource=DM->DataSourceDocT;
KolDBText->DataSource=DM->DataSourceDocT;
KFDBText->DataSource=DM->DataSourceDocT;
PriceDBText->DataSource=DM->DataSourceDocT;

Nal->DataBinding->DataSource=DM->DataSourceDoc;
OplataPC->DataBinding->DataSource=DM->DataSourceDoc;

Oper->DataSource=DM->DataSourceDoc;
NumberDocDBText->DataSource=DM->DataSourceDocAll;
Sdacha->DataSource=DM->DataSourceDoc;
SumDoc->DataSource=DM->DataSourceDocAll;
NameKlientDBText->DataSource=DM->DataSourceDocAll;
DM_Connection->glSaveProtocol("Запуск формы АРМ кассира");

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
NameDCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

IdTypePrice=0;
NameTypePrice="";
TypePriceLabel->Caption="Тип цен: "+NameTypePrice;


DMSprDiscountCard=new TDMSprDiscountCard(Application);
DMSprDiscountCard->DM_Connection=DM_Connection;
DMSprDiscountCard->Init();
DMSprDiscountAuto=new TDMSprDiscountAuto(Application);
DMSprDiscountAuto->DM_Connection=DM_Connection;
DMSprDiscountAuto->Init();
NoOtrOstatok=false;

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
void TFormaARMKassir::UpdateForm(void)
{
NameKKMLabel->Caption="ККМ: "+DMSprARM->ElementNAMEKKM->AsString;
TypePriceLabel->Caption="Тип цен: "+NameTypePrice;

if (DMSprARM->GetParameter("UCH")=="YES") UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

StatusBar->Panels->Items[0]->Text="Фирма: "+DMSprARM->ElementNAMEFIRM->AsString;
StatusBar->Panels->Items[1]->Text="Склад: "+DMSprARM->ElementNAMESKLAD->AsString;
StatusBar->Panels->Items[2]->Text="ККМ: "+DMSprARM->ElementNAMEKKM->AsString;


}
//-----------------------------------------------------------------------------
void TFormaARMKassir::UpdateSetup(void)
{
DMSprARM->OpenElement(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString));
IdTypePrice=glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString);
NameTypePrice=DMSprARM->ElementNAME_TPRICE->AsString;

if (DMSprARM->GetParameter("No_edit_price")=="Yes")
	{
	cxGrid1DBTableView1PRICECHKT->Options->Editing=false;
	}

if (DMSprARM->GetParameter("NoOtrOstatok")=="Yes")
	{
	NoOtrOstatok=true;
	}

DMSprDiscountCard->OpenElement(0);
DMSprDiscountAuto->OpenTableDiscountAuto(glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));
}
//---------------------------------------------------------------------------
void TFormaARMKassir::UpdateParameterFR(void)
{
if (glFR->ConnectFR==true)
        {
        glFR->GetSostKKM();
        StatusBar->Panels->Items[3]->Text="ФР №"+glFR->SerialNumberKKM;
        StatusBar->Panels->Items[4]->Text="КЛ №"+IntToStr(glFR->NumberKL);
        StatusBar->Panels->Items[5]->Text="Чек №"+IntToStr(glFR->NumberCheck);

        }

}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SprBV)SprBV->Close();
if(SpisokEd)SpisokEd->Close();
if(FormaViborSprNom)FormaViborSprNom->Close();
if(FormaInputCode)FormaInputCode->Close();
if(FormaViborSprKlient)FormaViborSprKlient->Close();
if(FormaViborSprDogovor)FormaViborSprDogovor->Close();
if (FormaGurDocCheckKKM2)FormaGurDocCheckKKM2->Close();
if(FormaInputText)FormaInputText->Close();
if(FormaInputDiscountCard)FormaInputDiscountCard->Close();


try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DMSprARM;

delete Nom;
delete Ed;
delete ObBar;

delete DMSprDiscountCard;
delete DMSprDiscountAuto;

delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------
bool TFormaARMKassir::BeforeCreateNewCheck(void)
{
bool result=true;

UnicodeString V="";
UnicodeString Z="";

if (CheckPrint==false)
		{
		UnicodeString V="Предыдущий чек не напечатан! Создать новый чек?";
		UnicodeString Z="Создать новый чек?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
				{
				result=false;
				}
		}

return result;
}
//-----------------------------------------------------------------------------
bool TFormaARMKassir::BeforeEditCheck(void)
{
bool result=true;
if (CheckCreate==false)
		{
		ShowMessage("Необходимо создать новый чек!");
		result=false;
		}
if (CheckPrint==true)
	{
	ShowMessage("Нельзя изменять напечатанный чек!!");
	result=false;
	}
if (CheckSave==true)
	{
	ShowMessage("Нельзя изменять сохраненный чек!!");
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndEdit(TObject *Sender)
{

if (EditRekvisit==ViborNomSpr)
        {
        if (FormaViborSprNom->OutReady==true)
                {
				Nom->IdTypePrice=IdTypePrice;
				Nom->OpenElement(glStrToInt64(FormaViborSprNom->DM->TableIDNOM->AsString));
                
                DM->AddDocNewString();
                DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
				DM->DocTKOLCHKT->AsFloat=1;
				DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
                                                *DM->DocTKFCHKT->AsFloat;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
				DM_Connection->glSaveProtocol("Добавлена новая номенклатура из справочника Номенклатура"+
										Nom->ElementNAMENOM->AsString);

				//дисплей
				AnsiString string1=Nom->ElementNAMENOM->AsString;
				AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
				if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
                }
        FormaViborSprNom=0;
        }

if (EditRekvisit==ViborTovarSprBV)
        {
        if (SprBV->OutReady==true)
                {
				Nom->IdTypePrice=IdTypePrice;
                Nom->OpenElement(SprBV->ViborIdNom);
                DM->AddDocNewString();
                DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                DM->DocTKOLCHKT->AsFloat=1;

				DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
                                                *DM->DocTKFCHKT->AsFloat;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
				DM_Connection->glSaveProtocol("Добавлена новая номенклатура из справочника быстрого вызова"+
										Nom->ElementNAMENOM->AsString);

				//дисплей
				AnsiString string1=DM->DocTNAMENOM->AsString;
				AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
				if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
                }
        SprBV=0;
        }

if (EditRekvisit==InputCodeBV)
        {
        if (FormaInputCode->OutReady==true)
                {
                //получим ID номенклатуры
				TDMSprBVNom * DMSprBV=new TDMSprBVNom(Application);
				DMSprBV->DM_Connection=DM_Connection;
				DMSprBV->Init();
				DMSprBV->IdPod=glStrToInt64(DMSprARM->ElementIDPODR_SARM->AsString);
                if (DMSprBV->FindPoCoduBV(FormaInputCode->Code)>0)
                        {
						Nom->IdTypePrice=IdTypePrice;
                        Nom->OpenElement(DMSprBV->IdNomBV);

                        DM->AddDocNewString();
                        DM->DocT->Edit();
						DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLCHKT->AsFloat=FormaInputCode->Kol;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
                                                *DM->DocTKFCHKT->AsFloat;

						DM->DocT->Post();
						ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
						DM_Connection->glSaveProtocol("Добавлена новая номенклатура по коду БВ"+
										Nom->ElementNAMENOM->AsString);
										//дисплей
						AnsiString string1=DM->DocTNAMENOM->AsString;
						AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
						if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
                        }
                else
                        {
                        ShowMessage("Товар не найден!");
                        }
                delete DMSprBV;
                }
        FormaInputCode=0;
        }


if (EditRekvisit==InputCodeNom)
        {
		if (FormaInputCode->OutReady==true)
                {
				Nom->IdTypePrice=IdTypePrice;
                if (Nom->FindPoCodu(FormaInputCode->Code)>0)
                        {
                        DM->AddDocNewString();
						DM->DocT->Edit();
						DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
                        DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                        DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                        DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
                        DM->DocTKOLCHKT->AsFloat=FormaInputCode->Kol;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
                                                *DM->DocTKFCHKT->AsFloat;

						DM->DocT->Post();
						ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
						DM_Connection->glSaveProtocol("Добавлена новая номенклатура по коду номенклатуры"+
										Nom->ElementNAMENOM->AsString);
										//дисплей
						AnsiString string1=DM->DocTNAMENOM->AsString;
						AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
						if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
                        }
                else
						{
						 ShowMessage("Товар не найден!");
						}
				}
		FormaInputCode=0;
		}

if (EditRekvisit==InputBarCode)
		{

		FormaInputText=0;
		}

if (EditRekvisit==ViborEdinica)
        {
	   if (SpisokEd->OutReady==true)
				{
				DM->DocT->Edit();
				DM->DocTIDEDCHKT->AsString=SpisokEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

				Nom->IdTypePrice=IdTypePrice;
				Nom->OpenElement(SpisokEd->DM->ElementIDNOMED->AsInteger);

				//получим цену
				TDMSprPrice * dm_price=new TDMSprPrice(Application);
				dm_price->DM_Connection=DM_Connection;
				dm_price->Init();
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),
							glStrToInt64(DM->DocTIDEDCHKT->AsString),
							DM->DocTKFCHKT->AsFloat,
							0);
				delete dm_price;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
				DM_Connection->glSaveProtocol("Изменена единица товара");
								//дисплей
				AnsiString string1=DM->DocTNAMENOM->AsString;
				AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
				if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
				}
		SpisokEd=0;
        }


if (EditRekvisit==ViborKlientIsSpr)
        {
        }



if (EditRekvisit==AddSvobSumRekvisit)
		{
	   if (FormaInputText->OutReady==true)
				{
				Nom->IdTypePrice=IdTypePrice;
				if (Nom->FindPoCodu(1)>0)
						{
						DM->AddDocNewString();
						DM->DocT->Edit();
						DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
						DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
						DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
						DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
						DM->DocTKOLCHKT->AsFloat=1;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
						DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
						DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=StrToFloat(FormaInputText->InputText);

                        DM->DocT->Post();
						DM_Connection->glSaveProtocol("Добавлена свободная сумма");
										//дисплей
						AnsiString string1=DM->DocTNAMENOM->AsString;
						AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
						if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
                        }
                else
                        {
                         ShowMessage("Не найден товар с кодом свободной суммы (Код=1)!");
						 DM_Connection->glSaveProtocol("Не найден товар с кодом свободной суммы (Код=1)!");
                        }
                }
       FormaInputText=0;
        }


if (EditRekvisit==VnesenieRekvisit)
        {
       if (FormaInputText->OutReady==true)
                {
                VnestiSummu(StrToFloat(FormaInputText->InputText));
				DM_Connection->glSaveProtocol("Внесение суммы");
                }
       FormaInputText=0;
       }

if (EditRekvisit==SnatieRekvisit)
        {
       if (FormaInputText->OutReady==true)
                {
                SnatSummu(StrToFloat(FormaInputText->InputText));
				DM_Connection->glSaveProtocol("Снятие суммы");
                }
       FormaInputText=0;
       }

if (EditRekvisit==ViborDocCheck)
        {
       if (FormaGurDocCheckKKM2->OutReady==true)
				{

				DM->OpenDoc(glStrToInt64(FormaGurDocCheckKKM2->DM->TableIDDOC->AsString));
				IdProject=0;
                CheckCreate=true;
                CheckPrint=false;
				CheckSave=true;
				CheckOperation=OpenCheckSale_Operation;
				Prim->Caption="Открыт чек!";
				DM_Connection->glSaveProtocol("Открыт чек");
                }
       FormaGurDocCheckKKM2=0;
       }

UpdateForm();
EditRekvisit=NO;
IdDochForm=NULL;
cxGrid1->Focused();
cxGrid1DBTableView1KOLCHKT->Focused=true;
}

//---------------------------------------------------------------------------


void __fastcall TFormaARMKassir::FormResize(TObject *Sender)
{
int x=0;

NameKKMLabel->Left=ClientWidth-NameKKMLabel->Width-4;
TypePriceLabel->Left=ClientWidth-TypePriceLabel->Width-4;
PanelPrice->Left=ClientWidth-PanelPrice->Width-4;
x=PanelPrice->Left;
PanelKF->Left=x-PanelKF->Width;
x=PanelKF->Left;
PanelKol->Left=x-PanelKol->Width;
x=PanelKol->Left;
PanelName->Left=4;
PanelName->Width=x-4;
NameNomDBText->Width=x-10;

x=0;
ButtonClose->Left=ClientWidth-ButtonClose->Width-4;
x=ButtonClose->Left;
ButtonPrint->Left=x-ButtonPrint->Width-2;

x=0;
GroupBoxSdacha->Left=ClientWidth-GroupBoxSdacha->Width-4;
x=GroupBoxSdacha->Left;
GroupBoxSum->Left=x-GroupBoxSum->Width-2;
x=GroupBoxSum->Left;
GroupBoxPC->Left=x-GroupBoxPC->Width-2;
x=GroupBoxPC->Left;
GroupBoxNal->Left=x-GroupBoxNal->Width-2;
//x=GroupBoxNal->Left;

}
//--------------------------------------------------------------------------
//*******СОЗДАНИЕ НОВОГО ЧЕКА***********************************************
//---------------------------------------------------------------------------
void TFormaARMKassir::CreateNewDocCheck(void)
{
if (BeforeCreateNewCheck()==false) return;

IdProject=0;
CheckOperation=NewCheckSale_Operation;
CheckCreate=false;
CheckPrint=false;
CheckSave=false;
CheckProveden=false;


if(glFR->ConnectFR==true)
		{
		if(glFR->ProvVosmPrintCheck()==false)
				{
				ShowMessage("Нет возможности создать чек! "+glFR->TextError);
				return;

				}
		}

UpdateSetup();
UpdateParameterFR();
UpdateForm();
DM->NewDoc();



DM->DocAll->Edit();
if(glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString)!=0)
	{
	DM->DocAllIDFIRMDOC->AsString=DMSprARM->ElementIDFIRM_SARM->AsString;
	}
if(glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString)!=0)
	{
	DM->DocAllIDSKLDOC->AsString=DMSprARM->ElementIDSKLAD_SARM->AsString;
	}
if(glStrToInt64(DMSprARM->ElementIDBASE_SARM->AsString)!=0)
	{
	DM->DocAllIDBASE_GALLDOC->AsString=DMSprARM->ElementIDBASE_SARM->AsString;
	}
DM->DocAll->Post();
DM->Doc->Edit();
if (glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString)!=0)
	{
	DM->DocIDKKMCHK->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
	}
if ( IdTypePrice!=0)
	{
	DM->DocIDTPRICE->AsString=IdTypePrice;
	}
DM->Doc->Post();


Prim->Caption="Создан новый чек продажи!";

UpdateForm();
CheckCreate=true;

if (glDisplayPok>0) glDisplayPok->ShowString1("Новый чек ",1,0,0);
if (glDisplayPok>0) glDisplayPok->ShowString2("Продажа",1,0,0);
}
//---------------------------------------------------------------------------
void TFormaARMKassir::CreateNewDocCheckVosvrat(void)
{
if (BeforeCreateNewCheck()==false) return;


UnicodeString V="Создать новый чек на возврат?";
UnicodeString Z="Создать новый чек на возврат?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}


IdProject=0;
CheckOperation=NewCheckReturnSale_Operation;
CheckCreate=false;
CheckPrint=false;
CheckSave=false;
CheckProveden=false;
if(glFR->ConnectFR==true)
		{
        if(glFR->ProvVosmPrintCheck()==false)
				{
				ShowMessage("Нет возможности создать чек! "+glFR->TextError);
				return;
                }
		}

UpdateSetup();
UpdateParameterFR();

DM->NewDoc();




DM->DocAll->Edit();
if (glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString)!=0)
	{
	DM->DocAllIDFIRMDOC->AsString=DMSprARM->ElementIDFIRM_SARM->AsString;
	}
if (glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString)!=0)
	{
	DM->DocAllIDSKLDOC->AsString=DMSprARM->ElementIDSKLAD_SARM->AsString;
	}
if (glStrToInt64(DMSprARM->ElementIDBASE_SARM->AsString)!=0)
	{
	DM->DocAllIDBASE_GALLDOC->AsString=DMSprARM->ElementIDBASE_SARM->AsString;
	}
DM->DocAll->Post();
DM->Doc->Edit();
if (glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString)!=0)
	{
	DM->DocIDKKMCHK->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
	}
if(IdTypePrice!=0)
	{
	DM->DocIDTPRICE->AsString=IdTypePrice;
	}
DM->DocOPERCHK->AsInteger=1;
DM->Doc->Post();


Prim->Caption="Создан новый чек на возврат!";
UpdateForm();
CheckCreate=true;

if (glDisplayPok>0) glDisplayPok->ShowString1("Новый чек ",1,0,0);
if (glDisplayPok>0) glDisplayPok->ShowString2("Возврат",1,0,0);
}
//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::OpenCheckClick(TObject *Sender)
{
if (BeforeCreateNewCheck()==false) return;


FormaGurDocCheckKKM2=new TFormaGurDocCheckKKM2(this);
FormaGurDocCheckKKM2->DM_Connection=DM_Connection;
FormaGurDocCheckKKM2->Init();

if (!FormaGurDocCheckKKM2) return;
FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
FormaGurDocCheckKKM2->Vibor=true;
FormaGurDocCheckKKM2->IdRodForm=Handle;
FormaGurDocCheckKKM2->FOnCloseForm=EndEdit;
IdDochForm=FormaGurDocCheckKKM2->Handle;
EditRekvisit=ViborDocCheck;
FormaGurDocCheckKKM2->UpdateForm();
FormaGurDocCheckKKM2->Show();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::ViborDocCheckForVosvrat(void)
{
if (BeforeCreateNewCheck()==false) return;

if (FormaGurDocCheckKKM2==0)
	{
	FormaGurDocCheckKKM2=new TFormaGurDocCheckKKM2(this);
	FormaGurDocCheckKKM2->DM_Connection=DM_Connection;
	FormaGurDocCheckKKM2->Init();
	if (!FormaGurDocCheckKKM2) return;
	FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
	FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
	FormaGurDocCheckKKM2->Vibor=true;
	FormaGurDocCheckKKM2->FOnCloseForm=EndViborDocCheckForVosvrat;
	FormaGurDocCheckKKM2->UpdateForm();
	FormaGurDocCheckKKM2->Show();
	}
}
//---------------------------------------------------------------------------------------
void __fastcall TFormaARMKassir::NewCheckSaleClick(TObject *Sender)
{
CreateNewDocCheck();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::DeleteStringClick(TObject *Sender)
{
if (BeforeEditCheck()==true)
	{
	DM->DeleteStringDoc();
	}
}
//---------------------------------------------------------------------------

void TFormaARMKassir::OpenFormViborSprBVNom(void)
{
if(Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}

if (BeforeEditCheck()==true)
	{
	if (IdDochForm==NULL)
        {
        
		SprBV=new TFormaViborBVNom(Application);
		SprBV->DM_Connection=DM_Connection;
		SprBV->Init();
        if (!SprBV) return;
        SprBV->IdRodForm=Handle;
        SprBV->FOnCloseForm=EndEdit;
        SprBV->Vibor=true;
        SprBV->Prosmotr=true;
		SprBV->IdPod=glStrToInt64(DMSprARM->ElementIDPODR_SARM->AsString);
        IdDochForm=SprBV->Handle;
        EditRekvisit=ViborTovarSprBV;
        SprBV->EditPodr->Text=DMSprARM->ElementNAMEPOD->AsString;
        SprBV->UpdateForm();
        SprBV->Show();

		}
	}
}
//-----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormViborSprEd(void)
{
if(Prosmotr==true) return;

if (BeforeEditCheck()==true)
	{

	if (IdDochForm==NULL)
        {
		SpisokEd=new TFormaViborSprEd(Application);
		SpisokEd->DM_Connection=DM_Connection;
		SpisokEd->Init();
        if (!SpisokEd) return;
        SpisokEd->IdRodForm=Handle;
        SpisokEd->FOnCloseForm=EndEdit;
        SpisokEd->Vibor=true;
        IdDochForm=SpisokEd->Handle;
        EditRekvisit=ViborEdinica;
		SpisokEd->IdNom=glStrToInt64(DM->DocTIDNOMCHKT->AsString);
        SpisokEd->UpdateForm();
        SpisokEd->HintLabel->Caption="Выберите единицу для документа чек ККМ";
        SpisokEd->LabelNom->Caption=DM->DocTNAMENOM->AsString;
        SpisokEd->Show();

		}
	}
}

//-----------------------------------------------------------------------------

void __fastcall TFormaARMKassir::N4Click(TObject *Sender)
{
OpenFormViborSprEd();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::N9Click(TObject *Sender)
{
Nal->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::N10Click(TObject *Sender)
{
OplataPC->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::MenuPrintCheckClick(TObject *Sender)
{
PrintDocCheck();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormViborSprNom(void)
{
if (BeforeEditCheck()==true)
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
        EditRekvisit=ViborNomSpr;
		FormaViborSprNom->DM->IdTypePrice=glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString);
        FormaViborSprNom->SpisokTypePrice->ItemIndex=FormaViborSprNom->DM->GetIndexTypePrice()-1;
        FormaViborSprNom->UpdateForm();
        FormaViborSprNom->Show();
		}
	}
}

//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::N8Click(TObject *Sender)
{
OpenFormViborSprBVNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::NewCheckReturnSaleClick(TObject *Sender)
{
CreateNewDocCheckVosvrat(); 
}

//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::PrintXreportClick(TObject *Sender)
{
if(glFR->ConnectFR==false)
	{
	ShowMessage("Фискальный регистратор не подключен!");
	return;
	}
glFR->OpenNoFiscalCheck();
if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->CloseNoFiscalCheck();
glFR->PrintXReport();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::PrintZreportClick(TObject *Sender)
{
if(glFR->ConnectFR==false)
	{
	ShowMessage("Фискальный регистратор не подключен!");
	return;
	}
 glFR->OpenNoFiscalCheck();
if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->CloseNoFiscalCheck();
glFR->PrintZReport();        
}
//---------------------------------------------------------------------------


void __fastcall TFormaARMKassir::N11Click(TObject *Sender)
{
	OpenFormViborSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::MenuInputCodeBVClick(TObject *Sender)
{
OpenFormInputCodeNomBV();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::MenuInputCodeNomClick(TObject *Sender)
{
OpenFormInputCodeNom();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormInputCodeNom(void)
{
if (BeforeEditCheck()==true)
	{
	if (IdDochForm==NULL)
        {
        FormaInputCode=new TFormaInputCode(Application);
        FormaInputCode->Vibor=true;
        FormaInputCode->IdRodForm=Handle;
        FormaInputCode->FOnCloseForm=EndEdit;
        IdDochForm=FormaInputCode->Handle;
        EditRekvisit=InputCodeNom;
        FormaInputCode->NameSprLabel->Caption="Справочник номенклатура:";
        FormaInputCode->ShowModal();
		}
	}
}
//----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormInputCodeNomBV(void)
{

if (BeforeEditCheck()==true)
	{
	if (IdDochForm==NULL)
        {
        FormaInputCode=new TFormaInputCode(Application);
        FormaInputCode->Vibor=true;
        FormaInputCode->IdRodForm=Handle;
        FormaInputCode->FOnCloseForm=EndEdit;
        IdDochForm=FormaInputCode->Handle;
        EditRekvisit=InputCodeBV;
        FormaInputCode->NameSprLabel->Caption="Справочник быстрого вызова:";
        FormaInputCode->ShowModal();
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::AddSvobSumClick(TObject *Sender)
{
OpenFormAddSvobSumm();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormAddSvobSumm(void)
{
if (BeforeEditCheck()==true)
	{

	if (IdDochForm==NULL)
		{
		FormaInputText=new TFormaInputText(Application);
		FormaInputText->Vibor=true;
		FormaInputText->IdRodForm=Handle;
		FormaInputText->FOnCloseForm=EndEdit;
		IdDochForm=FormaInputText->Handle;
		EditRekvisit=AddSvobSumRekvisit;
		FormaInputText->NameLabel->Caption="Введите сумму:";
		FormaInputText->Caption="Сумма";
		FormaInputText->ShowModal();
		}
	}
}
//----------------------------------------------------------
void __fastcall TFormaARMKassir::VnesenieClick(TObject *Sender)
{
OpenFormVnesenie();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::SnatieClick(TObject *Sender)
{
OpenFormSnatie();
}

//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormVnesenie(void)
{
if (IdDochForm==NULL)
        {
        FormaInputText=new TFormaInputText(Application);
        FormaInputText->Vibor=true;
        FormaInputText->IdRodForm=Handle;
        FormaInputText->FOnCloseForm=EndEdit;
        IdDochForm=FormaInputText->Handle;
        EditRekvisit=VnesenieRekvisit;
        FormaInputText->NameLabel->Caption="Введите сумму:";
        FormaInputText->Caption="Внесение";
        FormaInputText->ShowModal();
        }

}
//----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormSnatie(void)
{
if (IdDochForm==NULL)
        {
        FormaInputText=new TFormaInputText(Application);
        FormaInputText->Vibor=true;
        FormaInputText->IdRodForm=Handle;
        FormaInputText->FOnCloseForm=EndEdit;
        IdDochForm=FormaInputText->Handle;
        EditRekvisit=SnatieRekvisit;
        FormaInputText->NameLabel->Caption="Введите сумму:";
        FormaInputText->Caption="Снятие";
        FormaInputText->ShowModal();
        }
}
//---------------------------------------------------------------------------
void TFormaARMKassir::VnestiSummu(float sum)
{
if(glFR->ConnectFR==false)
	{
	ShowMessage("Фискальный регистратор не подключен!");
	return;
	}
glFR->OpenNoFiscalCheck();
if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->CloseNoFiscalCheck();
if (glFR->Vnesenie(sum)==false)
	{
    ShowMessage("Ошибка: "+glFR->TextError);
	}
}
//----------------------------------------------------------------------------
void TFormaARMKassir::SnatSummu(float sum)
{
if(glFR->ConnectFR==false)
	{
	ShowMessage("Фискальный регистратор не подключен!");
	return;
	}
glFR->OpenNoFiscalCheck();
if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }
glFR->CloseNoFiscalCheck();
if (glFR->Snatie(sum)==false)
	{
    ShowMessage("Ошибка: "+glFR->TextError);
	}
}
//-----------------------------------------------------------------------

void __fastcall TFormaARMKassir::SaveCheckMainMenuClick(TObject *Sender)
{
if (DM->SaveDoc()==true)
        {
        CheckSave=true;
        Prim->Caption="Чек сохранен!";
        //DM->CloseDoc();
        }
else
        {
		Prim->Caption="Не удалось записать чек!";
		ShowMessage("Ошибка: "+DM->TextError);
        }
}
//---------------------------------------------------------------------------



void __fastcall TFormaARMKassir::CloseDocClick(TObject *Sender)
{
DM->CloseDoc();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::FormActivate(TObject *Sender)
{
if (glScaner)if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::FormDeactivate(TObject *Sender)
{
if(glScaner) if(glScaner->ConnectScaner) glScaner->ReadSh=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::ReadShtrihCodEvent(int number, UnicodeString sh)
{
if (BeforeEditCheck()==true)
	{
	ObBar->IdTypePrice=IdTypePrice;
	ObBar->ObrabotatShtrihCod(sh);


	if (ObBar->OutReady==true)
		{

				DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

				DM->DocTIDEDCHKT->AsString=Ed->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=Ed->ElementNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=Ed->ElementKFED->AsFloat;

				//получим цену
				TDMSprPrice * dm_price=new TDMSprPrice(Application);
				dm_price->DM_Connection=DM_Connection;
				dm_price->Init();
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				delete dm_price;

				DM->DocTKOLCHKT->AsFloat=ObBar->Kol;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);

		//cxGrid1->Focused();
		//	cxGrid1->CanFocus();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLCHKT->Selected=true;
		cxGrid1DBTableView1KOLCHKT->Focused=true;

											//дисплей
						AnsiString string1=DM->DocTNAMENOM->AsString;
						AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
						if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
		}
	else
		{
		ShowMessage(ObBar->TextError);
		}
	}

}
//---------------------------------------------------------------
void __fastcall TFormaARMKassir::N12Click(TObject *Sender)
{
PrintGoodsCheck();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::PrintGoodsCheck(void)
{
//
IkanClassFactory * i_cf;
if (InterfaceGlobalCom->kanGetClassObject(InterfaceGlobalCom->kanGetCLSIDPoProgId("Oberon.SheetEditor.1"),
											IID_IkanClassFactory,
											(void**)&i_cf) !=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_IkanClassFactory объекта CLSID_TSheetEditorImpl!");
	}
if (i_cf->kanCreateInstance(IID_ISheetEditor,(void**)&SE)!=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_ISheetEditor!");
	return;
	}
i_cf->kanRelease();
SE->RowsAutoHeight=false;
if (!SE) return;

x = 1;
y = 0;
SE->BeginUpdate();
DM->DataSourceDocT->Enabled=false;
TBookmark BM;
BM=DM->DocT->GetBookmark();
PrintGoodsCheck_OutputHeadline();


DM->DocT->First();
while (!DM->DocT->Eof)
        {
        PrintGoodsCheck_OutputElement();
        DM->DocT->Next();
        }

DM->DocT->GotoBookmark(BM);
DM->DocT->FreeBookmark(BM);
DM->DataSourceDocT->Enabled=true;


PrintGoodsCheck_OutputPodval();

SE->EndUpdate();



}
//---------------------------------------------------------------------------
void TFormaARMKassir::PrintGoodsCheck_OutputHeadline(void)
{

SE->SetColumnWidth(0,10);
SE->SetColumnWidth(1,50);
SE->SetColumnWidth(2,250);
SE->SetColumnWidth(3,70);
SE->SetColumnWidth(4,70);
SE->SetColumnWidth(5,70);
SE->SetColumnWidth(6,70);
SE->SetColumnWidth(7,80);

SE->DefaultFontName="Arial";
SE->DefaultFontSize=10;
TDMSprFirm *DMSprFirm=new TDMSprFirm(Application);
DMSprFirm->DM_Connection=DM_Connection;
DMSprFirm->Init();
DMSprFirm->OpenElement(glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString));
TDMSprSklad * DMSprSklad=new TDMSprSklad(Application);
DMSprSklad->DM_Connection=DM_Connection;
DMSprSklad->Init();
DMSprSklad->OpenElement(glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));
x=1;
y=0;

        TRect rect;
        rect.Left = x;
        rect.Top = y;
		rect.Right = x+6;
        rect.Bottom = y;
		SE->SetMergeState(rect, true);
		

SE->TecCell_GetObject(x,y);
SE->TecCell_SetText( DMSprFirm->ElementFNAMEFIRM->AsString
				+", ИНН: "+DMSprFirm->ElementINNFIRM->AsString);
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->SetRowsHeight(y,20);
SE->TecCell_DeleteObject();
y++;

		rect.Left = x;
        rect.Top = y;
		rect.Right = x+6;
        rect.Bottom = y;
		SE->SetMergeState(rect, true);

SE->TecCell_GetObject(x,y);
SE->TecCell_SetText("Адрес: "+DMSprSklad->ElementADRSKLAD->AsString);
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_DeleteObject();
y++;
        rect.Left = x;
        rect.Top = y;
		rect.Right = x+5;
        rect.Bottom = y;
		SE->SetMergeState(rect, true);

SE->TecCell_GetObject(x,y);
SE->TecCell_SetText( "Телефон: "+DMSprFirm->ElementTELFIRM->AsString);
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->SetRowsHeight(y,20);
SE->TecCell_DeleteObject();
y++;
SE->SetRowsHeight(y,20);
y++;

        rect.Left = x+1;
        rect.Top = y;
		rect.Right = x+6;
        rect.Bottom = y;
		SE->SetMergeState(rect, true);

SE->TecCell_GetObject(x+1,y);
SE->TecCell_SetText( "Товарный чек №"+DM->DocAllNUMDOC->AsString
				+" от "+DateToStr(DM->DocAllPOSDOC->AsDateTime));
SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
SE->TecCell_SetFontSize(16);
SE->TecCell_DeleteObject();
y++; y++;



        x=1;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("№");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
        SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Наименование");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
        SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Кол-во");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Ед.");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("К");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Цена");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Сумма");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();

		SE->TecCell_GetObject(x,y-1);
		UnicodeString s="";
		if (DM->DocNCHECKCHK->AsString!="")
			{
			s="Чек ККМ №:"+DM->DocNCHECKCHK->AsString;
			}

		if(DM->DocNKLCHK->AsString!="")
			{
			s=s+", контрольная лента №"+DM->DocNKLCHK->AsString;
			}
		SE->TecCell_SetText(s);
		SE->TecCell_SetHorzTextAlign( ISheetEditor::haRIGHT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_DeleteObject();
        x++;

        y++;
delete DMSprFirm;
delete DMSprSklad;
}
//-----------------------------------------------------------------------------
void TFormaARMKassir::PrintGoodsCheck_OutputElement(void)
{
        x=1;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(DM->DocT->RecNo);
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
		x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(DM->DocTNAMENOM->AsString);
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText( FloatToStrF(DM->DocTKOLCHKT->AsFloat,ffFixed,10,3));
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(DM->DocTNAMEED->AsString);
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
        SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(FloatToStrF(DM->DocTKFCHKT->AsFloat,ffFixed,10,3));
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		if (DM->DocTKOLCHKT->AsFloat!=0)
			{
			SE->TecCell_SetText(FloatToStrF(DM->DocTSUMCHKT->AsFloat/DM->DocTKOLCHKT->AsFloat,ffFixed,10,2));
			}
		else
			{
			SE->TecCell_SetText(FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,10,2));
			}

		SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,10,2));
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;

        y++;


}
//---------------------------------------------------------------------------
void TFormaARMKassir::PrintGoodsCheck_OutputPodval(void)
{
		x=1;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
		x++;
		

				
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Всего: ");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
		x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText(FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2));
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
		SE->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
		SE->TecCell_DeleteObject();
        x++;
        y++;y++;

        x=2;

		TRect rect;
		rect.Left = x;
		rect.Top = y;
		rect.Right = x+5;
		rect.Bottom = y;
		SE->SetMergeState(rect, true);

		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat));
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		SE->TecCell_SetFontStyle(TFontStyles() << fsBold);
		SE->TecCell_SetWordBreake(true);
		SE->TecCell_DeleteObject();
        x++;
        y++; y++;
        x=2;
		SE->TecCell_GetObject(x,y);
		SE->TecCell_SetText("Продавец:________________________________ ");
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		x++;
        y++;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::PrintGoodsCheckOnFR(void)
{
bool Res=false;
if(glFR->ConnectFR==false)
        {
        Prim->Caption="Фискальный регистратор не подключен!";
        return Res;

        }

if (DM->DocOPERCHK->AsInteger!=3)
        {
        if (DM->DocT->RecordCount==0)
                {
                Prim->Caption="Нет строк в табличной части!";
                return Res;
                }
        }

if(glFR->ProvVosmPrintCheck()==false)
		{
		ShowMessage("Нет возможности напечатать товарный  чек! "+glFR->TextError);
        return Res;
        }

glFR->OpenNoFiscalCheck();


String StrPr="  ";

if (DMSprARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
        }

if (DMSprARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
        }

glFR->PrintString(" ",1,0,0,true,false, false);




glFR->PrintString("Товарный чек ",3,0,1,true,false, false);

glFR->PrintString("N"+DM->DocAllNUMDOC->AsString
				+" от "+DateToStr(DM->DocAllPOSDOC->AsDateTime),2,0,1,true,false, false);

glFR->PrintLine();//String("------------------------------------",1,0,0,true,false);
glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,false, false);

DM->DocT->First();
while(!DM->DocT->Eof)
        {

		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==true){Res=true;}else{ Res=false;}
		if (DM->DocTSKCHKT->AsFloat>0)
			{  //со скидкой
			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat,ffFixed,15,2);
			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}

			StrPr="-"+FloatToStr(DM->DocTPRSKCHKT->AsFloat)+" % "
				+FloatToStrF(DM->DocTSKCHKT->AsFloat,ffFixed,15,2)+
				" = "+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
			}
		else
			{//без скидки

			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
			}
        DM->DocT->Next();
        }
glFR->PrintLine();//("------------------------------------",1,0,0,true,false);
StrPr="Всего: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2);
glFR->PrintString(StrPr,1,0,2,true,false, false);

glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);

glFR->PrintString("Подпись  ___________________",1,0,0,true,false, false);

glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
glFR->PrintString(" ",1,0,0,true,false, false);
glFR->CloseNoFiscalCheck();

glFR->Cut(1);
return Res;
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::mmPrintCoodsCheckOnFRClick(
      TObject *Sender)
{
PrintGoodsCheckOnFR();        
}
//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormInputBarCode(void)
{
if (BeforeEditCheck()==true)
	{

	if (IdDochForm==NULL)
		{
		FormaInputText=new TFormaInputText(Application);
		FormaInputText->Vibor=true;
		FormaInputText->FOnCloseForm=EndInputBarCode;
		FormaInputText->NameLabel->Caption="Введите штрих-код:";
		FormaInputText->Caption="Штрих-код";
		FormaInputText->ShowModal();
		}
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndInputBarCode(TObject *Sender)
{
if (FormaInputText->OutReady==true)
	{
	ObBar->IdTypePrice=IdTypePrice;
	ObBar->ObrabotatShtrihCod(AnsiString(FormaInputText->InputText).c_str());


	if (ObBar->OutReady==true)
		{

				DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

				DM->DocTIDEDCHKT->AsString=Ed->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=Ed->ElementNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=Ed->ElementKFED->AsFloat;

				//получим цену
				TDMSprPrice * dm_price=new TDMSprPrice(Application);
				dm_price->DM_Connection=DM_Connection;
				dm_price->Init();
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				delete dm_price;

				DM->DocTKOLCHKT->AsFloat=ObBar->Kol;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);

		//cxGrid1->Focused();
		//	cxGrid1->CanFocus();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLCHKT->Selected=true;
		cxGrid1DBTableView1KOLCHKT->Focused=true;

											//дисплей
						AnsiString string1=DM->DocTNAMENOM->AsString;
						AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
						if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
		}
	else
		{
		ShowMessage(ObBar->TextError);
		}
	}
FormaInputText=0;
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::PoBarCodeClick(TObject *Sender)
{
OpenFormInputBarCode();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormViborSprBVNom() ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormViborSprEd() ;
}
//---------------------------------------------------------------------------



void __fastcall TFormaARMKassir::NalKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
if (Key==VK_RETURN) OplataPC->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::OplataPCKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
if (Key==VK_RETURN) ButtonPrint->SetFocus();
}
//---------------------------------------------------------------------------
		//выбор дисконтной карты

void  TFormaARMKassir::ViborDiscountCard(void)
{

if (BeforeEditCheck()==true)
	{

	if (FormaInputDiscountCard==NULL)
		{
		FormaInputDiscountCard=new TFormaInputDiscountCard(Application);
		FormaInputDiscountCard->Vibor=true;
		FormaInputDiscountCard->FOnCloseForm=EndViborDiscountCard;
		FormaInputDiscountCard->NameLabel->Caption="Введите код дисконтой карты:";
		FormaInputDiscountCard->Caption="Код дисконтной карты";
		FormaInputDiscountCard->ShowModal();
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborDiscountCard(TObject *Sender)
{
if (glScaner)if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;

if (FormaInputDiscountCard->OutReady==true)
	{
				AnsiString s=FormaInputDiscountCard->InputText;
				if (s.Length()>13) {s.SetLength(13);}
				__int64 id_card=0;
				if (s.Length()>6)
					{ //ищем карту по штрих коду
					id_card=DMSprDiscountCard->PoiskPoShCodu(s);
					}
				else
					{ //ищем карту по коду
					id_card=DMSprDiscountCard->PoiskPoCodu(s);
					}

				if (id_card>0)
					{
					DMSprDiscountCard->OpenElement(id_card);
					if (DMSprDiscountCard->ElementACT_SDISCOUNT_CARD->AsInteger==1)
						{   //карта активна
						DM->Doc->Edit();
						DM->DocIDDCARDCHK->AsString=DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString;
                        DM->DocNAME_SDISCOUNT_CARD->AsString=DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;
						DM->Doc->Post();
						DM->DocAll->Edit();
						DM->DocAllIDKLDOC->AsString=DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString;
						DM->DocAllNAMEKLIENT->AsString=DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						DM->DocAll->Post();
						UpdateValuesDiscount();

						}
					else
						{
                        DMSprDiscountCard->Element->Active=false;
						ShowMessage("Карта не активна!");
						}
					}
			else
					{
						ShowMessage("Карта не найдена!");
					}
	}

Nal->SetFocus();

FormaInputDiscountCard=0;
}

//---------------------------------------------------------------------------
void TFormaARMKassir::UpdateValuesDiscount(void)
{
if (DM->DocT->Active==false) return;

if (CheckOperation==OpenCheckReturnSale_Operation)
					{ //для открытых чеков возвратов скидки не начисляем
					//используем скидки открытых чеков
					return;
					}


DM->DataSourceDocT->Enabled=false;
TBookmark BM;
double summa_doc=0;
BM=DM->DocT->GetBookmark();

DM->DocT->First();
while (!DM->DocT->Eof)
		{
		summa_doc=summa_doc+DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat;
		DM->DocT->Next();
		}

GetProcentPoDiscountCard();
GetProcentAuto(summa_doc);

//расставляем проценты скидок
DM->DocT->First();
while (!DM->DocT->Eof)
		{
		if (DM->DocTPRSK_CARD_DCHKT->AsFloat>DM->DocTPRSK_AUTO_DCHKT->AsFloat)
			{
			DM->DocT->Edit();
			DM->DocTPRSKCHKT->AsFloat=DM->DocTPRSK_CARD_DCHKT->AsFloat;
			DM->DocT->Post();
			}
		else
			{
			DM->DocT->Edit();
			DM->DocTPRSKCHKT->AsFloat=DM->DocTPRSK_AUTO_DCHKT->AsFloat;
			DM->DocT->Post();
			}
		DM->DocT->Next();
		}

DM->DocT->GotoBookmark(BM);
DM->DocT->FreeBookmark(BM);
DM->DataSourceDocT->Enabled=true;


UpdateForm();
}
//----------------------------------------------------------------------------
void TFormaARMKassir::GetProcentPoDiscountCard(void)
{

//*****************************************************************************
//карта не задана или не активна, просто обнулим процент скидки по карте
if (DMSprDiscountCard->Element->Active==false ||
			glStrToInt64(DM->DocIDDCARDCHK->AsString)==0)
	{
	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_DCHKT->AsFloat=0;
		DM->DocT->Post();
		DM->DocT->Next();
		}

	}
//****************************************************************************
//фиксированная------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==1)
	{
	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_DCHKT->AsFloat=DMSprDiscountCard->ElementPRSK_SDISCOUNT_CARD->AsFloat;
		DM->DocT->Post();
		DM->DocT->Next();
		}
	}
//****************************************************************************
//накопительная------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==2)
	{
	double proc=0;
		TDMSprNakSkidok * dm_snak_skidok=new TDMSprNakSkidok(Application);
				dm_snak_skidok->DM_Connection=DM_Connection;
				dm_snak_skidok->Init();
		TDMGurOperDiscountCard * gur_oper=new TDMGurOperDiscountCard(Application);
				gur_oper->DM_Connection=DM_Connection;
				gur_oper->Init();

		dm_snak_skidok->GetSpisokSkidok( glStrToInt64(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsString),
									 glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));

		AnsiString text_descr="";
		
		while(!dm_snak_skidok->Query->Eof)
			{
			int kol_day=dm_snak_skidok->Query->FieldByName("PERIOD_SNAK_SKIDOK")->AsInteger;
			//получим сумму покупок
			TDateTime pos_nach=Now()-kol_day;
			double sum_pokupok=gur_oper->GetSumPokupok(glStrToInt64(DM->DocAllIDKLDOC->AsString),pos_nach)
														+DM->DocAllSUMDOC->AsFloat;
			double tek_procent=0;
			if (sum_pokupok>=dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)
				{
				tek_procent=dm_snak_skidok->Query->FieldByName("PROCENT_SNAK_SKIDOK")->AsFloat;
				}

			if (proc<tek_procent)
				{
				proc=tek_procent;
				text_descr="Накопленная сумма за "+IntToStr(kol_day)+" дней :"+FloatToStr(sum_pokupok);
				}

			dm_snak_skidok->Query->Next();
			}

		delete dm_snak_skidok;
		delete gur_oper;
		Prim->Caption=text_descr;

	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_DCHKT->AsFloat=proc;
		DM->DocT->Post();
		DM->DocT->Next();
		}
	}
//**************************************************************************
//заданный тип цен---------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==3)
	{
	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_DCHKT->AsFloat=0;
		DM->DocT->Post();
		DM->DocT->Next();
		}

		//получим тип цен

		TDMSprKlient * dm_spr_klient=new TDMSprKlient(Application);
				dm_spr_klient->DM_Connection=DM_Connection;
				dm_spr_klient->Init();
		dm_spr_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));

		if (glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString)!=0)
			{
			DM->Doc->Edit();
			DM->DocIDTPRICE->AsString=dm_spr_klient->ElementIDTPRICEKLIENT->AsString;
			DM->Doc->Post();
			TDMSprTypePrice * dm_spr_type_price=new TDMSprTypePrice(Application);
				dm_spr_type_price->DM_Connection=DM_Connection;
				dm_spr_type_price->Init();
			dm_spr_type_price->OpenElement(glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString));
			NameTypePrice=dm_spr_type_price->ElementNAME_TPRICE->AsString;
			delete  dm_spr_type_price;

			//проверим есть ли строки
			if(DM->DocT->RecordCount>0)
				{
				String V="В табличной части документа есть строки. Пересчитать цены?";
				String Z="Пересчитать цены?";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
						DMSprPrice->DM_Connection=DM_Connection;
						DMSprPrice->Init();
						DM->DocT->First();
						while(!DM->DocT->Eof)
								{
								DM->DocT->Edit();
								DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOMCHKT->AsString));
								if(DMSprPrice->ElementZNACH_PRICE->AsFloat==0)
									{
									DMSprPrice->FindElement(glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString),
											 glStrToInt64(DM->DocTIDNOMCHKT->AsString));
									}

								DM->DocTPRICECHKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFCHKT->AsFloat;

								DM->DocT->Post();
								DM->DocT->Next();
								}
						delete DMSprPrice;
						}
				}

			}

		delete  dm_spr_klient;
	}

//**************************************************************************
//скидка из справочника Номенклатура  --------------------------------------

if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
	{
	TDMSprNom * spr_nom=new TDMSprNom(Application);
				spr_nom->DM_Connection=DM_Connection;
				spr_nom->Init();
	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOMCHKT->AsString));
		DM->DocT->Edit();
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4)
			{
			DM->DocTPRSK_CARD_DCHKT->AsFloat=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5)
			{
			DM->DocTPRSK_CARD_DCHKT->AsFloat=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
			{
			DM->DocTPRSK_CARD_DCHKT->AsFloat=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
			}

		DM->DocT->Post();
		DM->DocT->Next();
		}
	delete spr_nom;
	}


}
//----------------------------------------------------------------------------
void TFormaARMKassir::GetProcentAuto(double sum_doc)
{ //вызывается для каждой номенклатуры
double tek_skidka=0;

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	DMSprDiscountAuto->TableDiscountAuto->First();
	while (!DMSprDiscountAuto->TableDiscountAuto->Eof)
		{
		bool  ok=true;
		tek_skidka=0;
		if (DMSprDiscountAuto->TableDiscountAutoACT_SDISCOUNT_AUTO->AsInteger==1)
			{
			//период активности начало
			if (DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsFloat>1000)
				{
				if (Now()<DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//период активности конец
			if (DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsFloat>1000)
				{
				if (Now()>DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//сумма
			if (DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (sum_doc<DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat)
					{
					ok=false;
					}
				}

			//день недели
			if (DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger>0)
				{
				if (DayOfTheWeek(Now())!=DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger)
					{
					ShowMessage(DayOfTheWeek(Now()));
					ok=false;
					}
				}

			//время действия начало
			if (DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()<DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//время действия конец
			if (DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()>DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//тип номенклатуры
			if (glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString)>0)
				{
				TDMSprNom *spr_nom=new TDMSprNom(Application);
				spr_nom->DM_Connection=DM_Connection;
				spr_nom->Init();
				spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOMCHKT->AsString));
				if (glStrToInt64(spr_nom->ElementIDVID_SNOM->AsString)!=
						glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString))
					{
					ok=false;
					}
				delete spr_nom;
				}
			}

		double proc_tec_skidki_auto=0;
		if (ok==true)
			{
			//необходимо определить процент скидки по текущей позиции
			//скидка одинаковая на все позиции

			if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==0)
				{
				proc_tec_skidki_auto=DMSprDiscountAuto->TableDiscountAutoPRSK_SDISCOUNT_AUTO->AsFloat;
				}

			//скидка разная на позиции (из справочника Номенклатура)
			if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger>0)
				{
				TDMSprNom *spr_nom=new TDMSprNom(Application);
				spr_nom->DM_Connection=DM_Connection;
				spr_nom->Init();
				spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOMCHKT->AsString));
				//скидка 1
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==1)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
					}
				//скидка 2
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==2)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
					}
				//скидка 3
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==3)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
					}
				delete spr_nom;
				}
			}

		if (proc_tec_skidki_auto>tek_skidka)
			{
			tek_skidka=proc_tec_skidki_auto;
			}
		DMSprDiscountAuto->TableDiscountAuto->Next();
		}


	DM->DocT->Edit();
	DM->DocTPRSK_AUTO_DCHKT->AsFloat=tek_skidka;
	DM->DocT->Post();
	DM->DocT->Next();
	}






}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::ViborDiscCardMainmenuClick(TObject *Sender)
{
ViborDiscountCard();	
}
//---------------------------------------------------------------------------
void TFormaARMKassir::PrintDocCheck(void)
{
TextError="";
if (DM->DocSDACHA_DCHK->AsFloat<0)
	{
	ShowMessage("Недостаточно оплаты!");
	return;
	}

if (DM->DocOPLPCCHK->AsFloat>DM->DocAllSUMDOC->AsFloat)
	{
	ShowMessage("Оплата платежной картой не может быть больше суммы чека!!");
	return;
	}


if (DM->DocT->RecordCount==0)
	{
	Prim->Caption="Нет строк в табличной части!";
	DM_Connection->glSaveProtocol("Нет строк в табличной части!");
	return ;
	}

if (CheckPrint==true && CheckSave==true )
	{
    ShowMessage("Данный чек уже напечатан и сохранен!");
	}

AnsiString s="";
//**********  ПЕЧАТЬ ЧЕКА НА ФР *********************************************
if (CheckPrint==false)
	{
	if (PrintCheck()==true)
		{
		CheckPrint=true;
		s=s+" Чек напечатан.";
		}
	else
		{
		CheckPrint=false;
		s=s+" Чек не напечатан!";
		ShowMessage("Не удалось напечатать чек! Ошибка:"+TextError);
		}
	}
else
	{
	ShowMessage("Чек уже напечатан!");
	}

//*********СОХРАНЕНИЕ ДОКУМЕНТА В БАЗЕ  ************************************
if (SaveCheck()==true)
		{
		OutReady=true;
		CheckSave=true;
		CheckCreate=false;
		s=s+" Чек сохранен.";
		}
else
		{
		ShowMessage("Ошибка при записи чека: "+TextError);
		s=s+" Чек не сохранен!";
		}

if (CheckProveden==true)
	{
	s=s+" Чек проведен.";
	}
else
	{
	s=s+" Чек не проведен!";
	}

Prim->Caption=s+"  "+TextError;
DM_Connection->glSaveProtocol(s+"  "+TextError);

}
//--------------------------------------------------------------------------
bool TFormaARMKassir::PrintCheck(void)
{
bool result=false;

if (DMSprARM->GetParameter("NO_PRINT_FR")=="YES")
		{
		result=true;
		return result;
		}


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
//----------------------------------------------------------------------------
bool TFormaARMKassir::PrintFiscalCheck(void)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек "+DM->DocAllNUMDOC->AsString);
bool Res=false;
if(glFR->ConnectFR==false)
        {
        Prim->Caption="Фискальный регистратор не подключен!";
		DM_Connection->glSaveProtocol("Фискальный регистратор не подключен!");
		return Res;
        }



try
	{
		String StrPr="  ";
		DM->DocT->First();
		while(!DM->DocT->Eof)
			{

			StrPr="###"+DM->DocTKRNAMENOM->AsString+";";
			StrPr=StrPr+DM->DocTPRICECHKT->AsString+";"
				+DM->DocTKOLCHKT->AsString+";"
                +DM->DocTNAMEED->AsString+";"
				+DM->DocTSUMCHKT->AsString;

			DM_Connection->glSaveProtocol(StrPr);
			DM->DocT->Next();
			}
			

	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->OpenNoFiscalCheck()==false )
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


	if (glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}

	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if (DM->DocTSKCHKT->AsFloat>0)
			{  //со скидкой
			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat,ffFixed,15,2);
			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			StrPr="-"+FloatToStr(DM->DocTPRSKCHKT->AsFloat)+" % "
				+FloatToStrF(DM->DocTSKCHKT->AsFloat,ffFixed,15,2)+
				" = "+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}
		else
			{//без скидки

			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		DM->DocT->Next();
		}

	if (glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}
	if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

	if(glFR->CloseNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (DMSprARM->GetParameter("UCH")!="YES")
		{
		double SumCheck=DM->DocAllSUMDOC->AsFloat;
        double OplataNal=DM->DocNALCHK->AsFloat;
		double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;

		if(glFR->PrintFiscalCheck(SumCheck,
									1,
									OplataNal,
									OplataPlatCard,
									0,
									0,
									DM->DocOPERCHK->AsInteger)==false)
			{
			throw Exception(glFR->TextError);
			}

		}
	else
		{
		//0 продажа 1 возврат

		double SumCheck=DM->DocAllSUMDOC->AsFloat;
		double OplataNal=DM->DocNALCHK->AsFloat;
		double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;

		if(glFR->PrintNoFiscalCheck(SumCheck,
										1,
										OplataNal,
										OplataPlatCard,
										0,
										0,
										DM->DocOPERCHK->AsInteger)==false)
			{
			throw Exception(glFR->TextError);
			}
		}
	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	}


return Res;

}
//----------------------------------------------------------------------------
bool TFormaARMKassir::PrintNoFiscalCheck(void)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек "+DM->DocAllNUMDOC->AsString);
bool Res=false;
if(glFR->ConnectFR==false)
		{
		Prim->Caption="Фискальный регистратор не подключен!";
		DM_Connection->glSaveProtocol("Фискальный регистратор не подключен!");
		return Res;
		}


try
	{
		String StrPr="  ";
		DM->DocT->First();
		while(!DM->DocT->Eof)
			{

			StrPr="###"+DM->DocTKRNAMENOM->AsString+";";
			StrPr=StrPr+DM->DocTPRICECHKT->AsString+";"
				+DM->DocTKOLCHKT->AsString+";"
                +DM->DocTNAMEED->AsString+";"
				+DM->DocTSUMCHKT->AsString;

			DM_Connection->glSaveProtocol(StrPr);
			DM->DocT->Next();
			}
			

	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (glFR->OpenNoFiscalCheck()==false )
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

	if (glFR->PrintString("Товарный чек №"+DM->DocAllNUMDOC->AsString,1,0,1,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

	if (glFR->PrintString("от "+DM->DocAllPOSDOC->AsString,1,0,1,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

	if (glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}

	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if (DM->DocTSKCHKT->AsFloat>0)
			{  //со скидкой
			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat,ffFixed,15,2);
			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			StrPr="-"+FloatToStr(DM->DocTPRSKCHKT->AsFloat)+" % "
				+FloatToStrF(DM->DocTSKCHKT->AsFloat,ffFixed,15,2)+
				" = "+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}
		else
			{//без скидки

			StrPr="";
			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		DM->DocT->Next();
		}

	if (glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}
	if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
		{
		throw Exception(glFR->TextError);
		}

		double SumCheck=DM->DocAllSUMDOC->AsFloat;
		//double OplataNal=DM->DocNALCHK->AsFloat;
		//double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;


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
	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	}


return Res;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::SaveCheck(void)
{
bool result=false;

if (glFR->ConnectFR==true)
	{
	if (CheckPrint==true)
		{
		if (glFR->GetSostKKM()==true)
			{
			DM->Doc->Edit();
			DM->DocNKLCHK->AsInteger=glFR->NumberKL;
			DM->DocNCHECKCHK->AsInteger=glFR->NumberCheck;
			DM->DocREGNUMCHK->AsString=glFR->RegNumberKKM;
			DM->DocSAVNUMCHK->AsString=glFR->SerialNumberKKM;
			DM->DocMODELCHK->AsString=glFR->ModelKKM;
			DM->Doc->Post();
			}
		}
	}

DM->DocAll->Edit();
DM->DocAllPOSDOC->AsDateTime=Now();
DM->DocAll->Post();


//установим банковский счет
	if (DM->DocOPLPCCHK->AsFloat > 0)
		{
		if (DMSprARM->GetParameter("IdBankSchet")!="")
			{
			DM->Doc->Edit();
			DM->DocIDBSCHET_DCHK->AsString=glStrToInt64(DMSprARM->GetParameter("IdBankSchet"));
			DM->Doc->Post();
			}
		}


	if (DM->SaveDoc()==true)
		{
		result=true;
		if (DM->DvRegDoc()==true)
				{
				CheckProveden=true;
				}
		else
			{
			CheckProveden=false;
			}
		}
	else
		{
		TextError=DM->TextError;
		result=false;
		} 

return result;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaARMKassir::cxGrid1DBTableView1KOLCHKTPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ValidateOstatok(DisplayValue);
}
//---------------------------------------------------------------------------
void TFormaARMKassir::ValidateOstatok(double treb_kol)
{
if (NoOtrOstatok==true && DM->DocTTNOM->AsInteger==0)
	{   //проверим остаток и не дадим добавить больше чем есть на складе
		//проверяем только товары
	double tec_ostatok=0;
	TDMRegGoods * reg=new TDMRegGoods(Application);
				reg->DM_Connection=DM_Connection;
				reg->Init();
	tec_ostatok=reg->GetOstatok(glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString),
								glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString),
								glStrToInt64(DM->DocTIDNOMCHKT->AsString));

	if (tec_ostatok<treb_kol)
		{
		ShowMessage("Недостаточно товара на складе!\n\n Требуется:   "+
							FloatToStrF(treb_kol,ffFixed,14,3)+
							"\n\n На складе:   "+FloatToStrF(tec_ostatok,ffFixed,14,3));
		if (DM->DocTKFCHKT->AsFloat!=0)
			{
			DM->DocT->Edit();
			DM->DocTKOLCHKT->AsFloat=tec_ostatok/DM->DocTKFCHKT->AsFloat;
			DM->DocT->Post();
			}
		}
	delete reg;
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::cxGrid1Exit(TObject *Sender)
{
UpdateValuesDiscount();	
}

//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborDocCheckForVosvrat(TObject *Sender)
{

if (FormaGurDocCheckKKM2->OutReady==true)
	{
	CreateNewDocCheckVosvrat();
	CheckOperation=OpenCheckReturnSale_Operation;
	DM->DocAll->Edit();
	DM->DocAllIDDOCOSNDOC->AsString=FormaGurDocCheckKKM2->DM->TableIDDOC->AsString;
	DM->DocAll->Post();

	TDMDocCheck * check=new TDMDocCheck(Application);
				check->DM_Connection=DM_Connection;
				check->Init();
	check->OpenDoc(glStrToInt64(FormaGurDocCheckKKM2->DM->TableIDDOC->AsString));

	DMSprDiscountCard->OpenElement(glStrToInt64(DM->DocIDDCARDCHK->AsString));

	check->DocT->First();
	while (!check->DocT->Eof)
		{
		DM->AddDocNewString();
		DM->DocT->Edit();
		DM->DocTIDNOMCHKT->AsString=check->DocTIDNOMCHKT->AsString;
		DM->DocTNAMENOM->AsString=check->DocTNAMENOM->AsString;
		DM->DocTKRNAMENOM->AsString=check->DocTKRNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=check->DocTTNOM->AsInteger;
		DM->DocTKOLCHKT->AsFloat=check->DocTKOLCHKT->AsFloat;

		DM->DocTIDEDCHKT->AsString=check->DocTIDEDCHKT->AsString;
		DM->DocTNAMEED->AsString=check->DocTNAMEED->AsString;
		DM->DocTKFCHKT->AsFloat=check->DocTKFCHKT->AsFloat;
        DM->DocTPRSKCHKT->AsFloat=check->DocTPRSKCHKT->AsFloat;
		DM->DocTSKCHKT->AsFloat=check->DocTSKCHKT->AsFloat;
		DM->DocTPRICECHKT->AsFloat=check->DocTPRICECHKT->AsFloat;

		DM->DocT->Post();

		check->DocT->Next();
		}

	delete check;

	CheckCreate=true;
	CheckPrint=false;
	CheckSave=false;
	Prim->Caption="Создан новый чек возврата!";
	DM_Connection->glSaveProtocol("Создан новый чек возврата");
	}
FormaGurDocCheckKKM2=0;

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::OpenCheckForVosvratMainMenuClick(
      TObject *Sender)
{
ViborDocCheckForVosvrat();
}
//---------------------------------------------------------------------------
//выбор проекта
void  TFormaARMKassir::ViborProject(void)
{
if (BeforeEditCheck()==true)
	{
	if (FormaInputText==0)
		{
		FormaInputText=new TFormaInputText(Application);
		FormaInputText->Vibor=true;
		FormaInputText->FOnCloseForm=EndViborProject;
		FormaInputText->NameLabel->Caption="Введите код проекта:";
		FormaInputText->Caption="Проект";
		FormaInputText->ShowModal();
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborProject(TObject *Sender)
{
if (FormaInputText->OutReady==true)
	{
	if (FormaInputText->InputText!="")
		{
		TDMSprProject *p=new TDMSprProject(Application);
		p->DM_Connection=DM_Connection;
		p->Init();
		if (p->FindPoCodu(StrToInt(FormaInputText->InputText))>0)
			{
			IdProject=glStrToInt64(p->ElementID_SPROJECT->AsString);
			Prim->Caption=p->ElementNAME_SPROJECT->AsString;

			DM->DocAll->Edit();
			DM->DocAllIDPROJECT_GALLDOC->AsString=p->ElementID_SPROJECT->AsString;
            DM->DocAll->Post();
			}
		else
			{
			ShowMessage("Не найден проект!"); 
			}

        }
	}
FormaInputText=0;
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::VibratProjectMainMenuClick(TObject *Sender)
{
ViborProject();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::CheckDateTimeFR(void)
{
bool set_date_time=false;
			try
				{
				//время и дата
				TTime time_fr=glFR->GetTime();
				TTime time_pc=Time();
				TDate date_fr=glFR->GetDate();
				TDate date_pc=Date();
				if (date_fr==date_pc)
					{ //проверим время
					//ShowMessage(TimeToStr(fabs(time_fr-time_pc))+"  "+TimeToStr(EncodeTime(0,5,0,0)));
					if (fabs(time_fr-time_pc) > EncodeTime(0,5,0,0))
						{ //разница больше 5 минут
						set_date_time=true;
						}
					}
				else
					{
					set_date_time=true;
					}

				if (set_date_time==true && glFR->ConnectFR==true)
					{
					UnicodeString V="Разница в показаниях часов компьютера и фискального регистратора более 5 минут.\n\n";
					V=V+DateToStr(date_pc)+"  "+TimeToStr(time_pc)+" - компьютер\n";
					V=V+DateToStr(date_fr)+"  "+TimeToStr(time_fr)+" - фискальный регистратор\n\n";
					V=V+"Установить дату и время в фискальном регистраторе по показаниям часов компьютера?";
					UnicodeString Z="Внимание!";
					if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						V="Будет установлено следующее значение "+DateTimeToStr(Now())+
								". Подтверждаеете изменение в фискальном регистраторе?";
						if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
							{
							if  (glFR->SetTime(Time())==true)
								{
								}
							else
								{
								ShowMessage("Ошибка при установке времени: "+glFR->TextError);
								}

							if(glFR->SetDate(Date())==true)
								{
								}
							else
								{
								ShowMessage("Ошибка при установке даты: "+glFR->TextError);
								}
							}
						}
					}
				}
			catch (Exception &exception)
				{
				ShowMessage("Ошибка при проверке даты и времени фискального регистратора - "+
						exception.Message);
				}



}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::NalExit(TObject *Sender)
{
//дисплей
AnsiString string1="ВСЕГО:"+DM->DocAllSUMDOC->AsString+
	"  ОПЛ:"+FloatToStr(DM->DocNALCHK->AsFloat+
						 DM->DocOPLPCCHK->AsFloat);
AnsiString string2="СДАЧА:"+DM->DocSDACHA_DCHK->AsString;
if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::OplataPCExit(TObject *Sender)
{
//дисплей
AnsiString string1="ВСЕГО:"+DM->DocAllSUMDOC->AsString+
	"  ОПЛ:"+FloatToStr(DM->DocNALCHK->AsFloat+
						 DM->DocOPLPCCHK->AsFloat);
AnsiString string2="СДАЧА:"+DM->DocSDACHA_DCHK->AsString;
if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::ActionPrintExecute(TObject *Sender)
{
PrintDocCheck();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::ActionCloseExecute(TObject *Sender)
{
if (DM->DocAll->Active==true)
	{
	DM->CloseDoc();
	}
Close();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::OpenFormInputArtikul(void)
{
if (BeforeEditCheck()==true)
	{
	if (FormaInputText==0)
		{
		FormaInputText=new TFormaInputText(Application);
		FormaInputText->Vibor=true;
		FormaInputText->FOnCloseForm=EndInputArtikul;
		FormaInputText->NameLabel->Caption="Введите артикул:";
		FormaInputText->Caption="Артикул";
		FormaInputText->ShowModal();
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndInputArtikul(TObject *Sender)
{

if (FormaInputText->OutReady==true)
	{
	UnicodeString s=Trim(FormaInputText->InputText);
	Nom->IdTypePrice=IdTypePrice;
	__int64 id_nom=Nom->FindPoArtikulu(s);
	if (id_nom>0)
		{

		Nom->IdTypePrice=IdTypePrice;
		Nom->OpenElement(id_nom);

		DM->AddDocNewString();
		DM->DocT->Edit();
		//номенклатура
		DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
		DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
		DM->DocTKOLCHKT->AsFloat=1;
		//единица
		DM->DocTIDEDCHKT->AsString=Nom->BasEdIDED->AsString;
		DM->DocTNAMEED->AsString=Nom->BasEdNAMEED->AsString;
		DM->DocTKFCHKT->AsFloat=Nom->BasEdKFED->AsFloat;

					//получим цену
				TDMSprPrice * dm_price=new TDMSprPrice(Application);
				dm_price->DM_Connection=DM_Connection;
				dm_price->Init();
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),
							glStrToInt64(DM->DocTIDEDCHKT->AsString),
							DM->DocTKFCHKT->AsFloat,
							0);
				delete dm_price;

		DM->DocT->Post();

		ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
		cxGrid1DBTableView1KOLCHKT->Selected=true;
                    				//дисплей
		UnicodeString string1=DM->DocTNAMENOM->AsString;
		UnicodeString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
		if (glDisplayPok>0) glDisplayPok->ShowString1(string1,1,0,0);
		if (glDisplayPok>0) glDisplayPok->ShowString2(string2,1,0,0);
		}
	else
		{
		ShowMessage("Товар с артикулом "+s+" не найден!");
		}


	}
FormaInputText=0;
UpdateForm();
cxGrid1->Focused();
cxGrid1DBTableView1KOLCHKT->Focused=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::PoArtikuluClick(TObject *Sender)
{
OpenFormInputArtikul();
}
//---------------------------------------------------------------------------

