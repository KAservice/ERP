//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaArmKassir.h"
#include "IDMSprBVNom.h"
#include "IDMSprKlient.h"
#include "IDMSprFirm.h"
#include "IDMSprSklad.h"
//#include "DMRegVsRasch.h"
#include "IDMGurOperDiscountCard.h"
#include "IDMSprVidDiscountCard.h"
#include "IDMSprNakSkidok.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSetup.h"
#include "IDMRegGoods.h"
#include "IDMSprProject.h"
#include "IDMQueryRead.h"

#include "math.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IkasDMSpr.h"
#include "IDMUserSetup.h"
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
#pragma link "cxPC"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaARMKassir::TFormaARMKassir(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
glFR=0;;
glScaner=0;
glDisplayPok=0;
}
//---------------------------------------------------------------------------
bool TFormaARMKassir::Init(void)
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
			//if (i_dev->GetDeviceObject(1, (void**) &glFR)!=-1)
			//	{
			//	glFR=0;
			//	}
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

//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
DM->AutoRaschet=true;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM,
												 (void**)&DMSprARM);
DMSprARM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&Nom);
Nom->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
												 (void**)&Ed);
Ed->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
												 (void**)&ObBar);
ObBar->Init(InterfaceMainObject,InterfaceImpl);
ObBar->SprNom=Nom;
ObBar->SprEd=Ed;
ObBar->GetValuePrefiksBarCode();

InterfaceGlobalCom->kanCreateObject(ProgId_ObjectCheckDiscount,IID_IObjectCheckDiscount,
												 (void**)&ObCheckDiscount);
ObCheckDiscount->Init(InterfaceMainObject,InterfaceImpl);


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
AllOplataDBText->DataSource=DM->DataSourceDoc;

DM_Connection->glSaveProtocol("Запуск формы АРМ кассира");

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
NameDCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


OplataPlatCardcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplataCreditCardcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
AllOplPlatCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
AllOplCreditCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
cxGrid2DBTableView1->DataController->DataSource=DM->DataSourceDocOpl;


IdTypePrice=0;
NameTypePrice="";
TypePriceLabel->Caption="Тип цен: "+NameTypePrice;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
												 (void**)&DMSprDiscountCard);
DMSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountAuto.1",IID_IDMSprDiscountAuto,
												 (void**)&DMSprDiscountAuto);
DMSprDiscountAuto->Init(InterfaceMainObject,InterfaceImpl);

NoOtrOstatok=false;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;


IdARM=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
UpdateSetup();
//UpdateParameterFR();
UpdateForm();
CheckDateTimeFR();


if (glDisplayPok>0)	glDisplayPok->ShowString1("Добро пожаловать!",1,0,0);
if (glDisplayPok>0)	glDisplayPok->ShowString2(DM_Connection->ARMInfoNAME_SARM->AsString,1,0,0);


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaArmKassirImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(MainMenu1);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = MainMenuExtModuleClick;
		MainMenuExtModule->Insert(MainMenuExtModule->Count,menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}


LoadFormSetup();


ConnectFR();


return result;
}

//---------------------------------------------------------------------------
int TFormaARMKassir::Done(void)
{

return -1;
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
if (glFR > 0)
	{
	if (glFR->ConnectFR==true)
		{
		glFR->GetSostKKM();
        StatusBar->Panels->Items[3]->Text="ФР №"+glFR->SerialNumberKKM;
        StatusBar->Panels->Items[4]->Text="КЛ №"+IntToStr(glFR->NumberKL);
        StatusBar->Panels->Items[5]->Text="Чек №"+IntToStr(glFR->NumberCheck);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::FormClose(TObject *Sender,
      TCloseAction &Action)
{

DisconnectFR();


if (glDisplayPok>0)	glDisplayPok->ShowString1("Извините, ",1,0,0);
if (glDisplayPok>0)	glDisplayPok->ShowString2("касса не работает!",1,0,0);

if(SprBV)SprBV->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaViborSprNom)FormaViborSprNom->kanRelease();
if(FormaInputCode)FormaInputCode->kanRelease();
if (FormaGurDocCheckKKM2)FormaGurDocCheckKKM2->kanRelease();
if(FormaInputText)FormaInputText->kanRelease();
if(FormaInputDiscountCard)FormaInputDiscountCard->kanRelease();

DMTableExtPrintForm->kanRelease();
DMSprARM->kanRelease();
DMSprOborud->kanRelease();
Nom->kanRelease();
Ed->kanRelease();
ObBar->kanRelease();
ObCheckDiscount->kanRelease();
DMSprDiscountCard->kanRelease();
DMSprDiscountAuto->kanRelease();
DM->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}


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
int TFormaARMKassir::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//EditRekvisit==ViborNomSpr)
        {
		if (type_event==1)
                {
				Nom->IdTypePrice=IdTypePrice;
				Nom->OpenElement(glStrToInt64(FormaViborSprNom->DM->TableIDNOM->AsString));

                DM->AddDocNewString();
                DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

				DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
				DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
				DM->DocTSHED->AsString=Nom->OsnEdSHED->AsString;

				DM->DocTKOLCHKT->AsFloat=1;
				DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
												*DM->DocTKFCHKT->AsFloat;


				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
                DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

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

				if (cxPageControl1->ActivePageIndex==0)
					{
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOLCHKT->Selected=true;
					cxGrid1DBTableView1KOLCHKT->Focused=true;
					}
                }
        FormaViborSprNom=0;
        }

if (number_procedure_end==2)//EditRekvisit==ViborTovarSprBV)
        {
		if (type_event==1)
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

				DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
				DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
				DM->DocTSHED->AsString=Nom->OsnEdSHED->AsString;

				DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
												*DM->DocTKFCHKT->AsFloat;


				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;
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

				if (cxPageControl1->ActivePageIndex==0)
					{
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOLCHKT->Selected=true;
					cxGrid1DBTableView1KOLCHKT->Focused=true;
					}
                }
        SprBV=0;
        }

if (number_procedure_end==3)//EditRekvisit==InputCodeBV)
        {
		if (type_event==1)
				{
                //получим ID номенклатуры
				IDMSprBVNom * DMSprBV;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
												 (void**)&DMSprBV);
				DMSprBV->Init(InterfaceMainObject,InterfaceImpl);
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

						DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
						DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
						DM->DocTSHED->AsString=Nom->OsnEdSHED->AsString;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
                        DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
                        DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
												*DM->DocTKFCHKT->AsFloat;


				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;
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
						if (cxPageControl1->ActivePageIndex==0)
							{
							cxGrid1->SetFocus();
							cxGrid1DBTableView1KOLCHKT->Selected=true;
							cxGrid1DBTableView1KOLCHKT->Focused=true;
							}
                        }
                else
                        {
                        ShowMessage("Товар не найден!");
                        }
				DMSprBV->kanRelease();
                }
        FormaInputCode=0;
        }


if (number_procedure_end==4)//EditRekvisit==InputCodeNom)
        {
		if (type_event==1)
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

						DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
						DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
						DM->DocTSHED->AsString=Nom->OsnEdSHED->AsString;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
						DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
						DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=Nom->ElementZNACH_PRICE->AsFloat
												*DM->DocTKFCHKT->AsFloat;

				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

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
						if (cxPageControl1->ActivePageIndex==0)
							{
							cxGrid1->SetFocus();
							cxGrid1DBTableView1KOLCHKT->Selected=true;
							cxGrid1DBTableView1KOLCHKT->Focused=true;
							}
                        }
                else
						{
						 ShowMessage("Товар не найден!");
						}
				}
		FormaInputCode=0;
		}

if (number_procedure_end==5)//EditRekvisit==InputBarCode)
		{

		FormaInputText=0;
		}

if (number_procedure_end==6)//EditRekvisit==ViborEdinica)
        {
	   if (type_event==1)
				{
				DM->DocT->Edit();
				DM->DocTIDEDCHKT->AsString=SpisokEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

				DM->DocTSHED->AsString=SpisokEd->DM->ElementSHED->AsString;

				Nom->IdTypePrice=IdTypePrice;
				Nom->OpenElement(SpisokEd->DM->ElementIDNOMED->AsInteger);

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				DM->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),
							glStrToInt64(DM->DocTIDEDCHKT->AsString),
							DM->DocTKFCHKT->AsFloat,
							0);
				dm_price->kanRelease();

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


if (number_procedure_end==7)//EditRekvisit==ViborKlientIsSpr)
        {
        }



if (number_procedure_end==8)//EditRekvisit==AddSvobSumRekvisit)
		{
	   if (type_event==1)
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

						DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
						DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
						DM->DocTSHED->AsString=Nom->OsnEdSHED->AsString;

						DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
						DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
						DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

						DM->DocTPRICECHKT->AsFloat=StrToFloat(FormaInputText->InputText);

				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

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


if (number_procedure_end==9)//EditRekvisit==VnesenieRekvisit)
        {
	   if (type_event==1)
				{
                VnestiSummu(StrToFloat(FormaInputText->InputText));
				DM_Connection->glSaveProtocol("Внесение суммы");
                }
       FormaInputText=0;
       }

if (number_procedure_end==10)//EditRekvisit==SnatieRekvisit)
        {
	   if (type_event==1)
                {
                SnatSummu(StrToFloat(FormaInputText->InputText));
				DM_Connection->glSaveProtocol("Снятие суммы");
                }
       FormaInputText=0;
       }

if (number_procedure_end==11)//EditRekvisit==ViborDocCheck)
		{
	   if (type_event==1)
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


if (number_procedure_end==12)
	{
	if (type_event==1)
		{
		EndViborDocCheckForVosvrat();
		}
	FormaGurDocCheckKKM2=0;
	}


if (number_procedure_end==13)
	{
	if (type_event==1)
		{
		EndInputBarCode();
		}
	FormaInputText=0;
	}

if (number_procedure_end==14)
	{
	if (type_event==1)
		{
		EndViborDiscountCard();
		}
	FormaInputDiscountCard=0;
	}


if (number_procedure_end==15)
	{
	if (type_event==1)
		{
		EndViborProject();
		}
	FormaInputText=0;
	}

if (number_procedure_end==16)
	{
	if (type_event==1)
		{
		EndInputArtikul();
		}
	FormaInputText=0;
	}

UpdateForm();
cxGrid1->Focused();
cxGrid1DBTableView1KOLCHKT->Focused=true;

return -1;
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

//x=0;
//GroupBoxSum->Left=x-GroupBoxSum->Width-2;
//x=GroupBoxSum->Left;
//GroupBoxPC->Left=x-GroupBoxPC->Width-2;
//x=GroupBoxPC->Left;
//GroupBoxNal->Left=x-GroupBoxNal->Width-2;
//x=GroupBoxNal->Left;
//GroupBoxAllOplata->Left=ClientWidth-GroupBoxAllOplata->Width-4;
//x=GroupBoxAllOplata->Left;
//GroupBoxSdacha->Left=ClientWidth-GroupBoxSdacha->Width-4;
//x=GroupBoxSdacha->Left;
Prim->Width=x-ButtonPrint->Width-20-Prim->Left;


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

if (glFR > 0)
	{
	if(glFR->ConnectFR==true)
		{
		if(glFR->ProvVosmPrintCheck()==false)
				{
				ShowMessage("Нет возможности создать чек! "+glFR->TextError);
				return;

				}
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

__int64 id_oper=GetIdOperSale();
if (id_oper > 0)
	{
	DM->DocAllIDBUSINOP_GALLDOC->AsString=id_oper;
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

if (glFR)
	{
	if(glFR->ConnectFR==true)
		{
		if(glFR->ProvVosmPrintCheck()==false)
				{
				ShowMessage("Нет возможности создать чек! "+glFR->TextError);
				return;

				}
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

__int64 id_oper=GetIdOperReturnSale();
if (id_oper > 0)
	{
	DM->DocAllIDBUSINOP_GALLDOC->AsString=id_oper;
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

InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM2.1",IID_IFormaGurDocCheckKKM2,
												 (void**)&FormaGurDocCheckKKM2);
FormaGurDocCheckKKM2->Init(InterfaceMainObject,InterfaceImpl);

FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
//FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
FormaGurDocCheckKKM2->Vibor=true;
FormaGurDocCheckKKM2->UpdateForm();
FormaGurDocCheckKKM2->NumberProcVibor=11;
}
//---------------------------------------------------------------------------
void TFormaARMKassir::ViborDocCheckForVosvrat(void)
{
if (BeforeCreateNewCheck()==false) return;

if (FormaGurDocCheckKKM2==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM2.1",IID_IFormaGurDocCheckKKM2,
												 (void**)&FormaGurDocCheckKKM2);
	FormaGurDocCheckKKM2->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
	//FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
	FormaGurDocCheckKKM2->Vibor=true;
	FormaGurDocCheckKKM2->UpdateForm();
	FormaGurDocCheckKKM2->NumberProcVibor=12;
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

//дисплей
AnsiString string1="ВСЕГО:"+DM->DocAllSUMDOC->AsString+
	"  ОПЛ:"+FloatToStr(DM->DocALLOPL->AsFloat);
AnsiString string2="СДАЧА:"+DM->DocSDACHA_DCHK->AsString;
if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
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
	if (SprBV==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborBVNom.1",IID_IFormaViborBVNom,
												 (void**)&SprBV);
		SprBV->Init(InterfaceMainObject,InterfaceImpl);
        SprBV->Vibor=true;
        SprBV->Prosmotr=true;
		SprBV->IdPod=glStrToInt64(DMSprARM->ElementIDPODR_SARM->AsString);
        //SprBV->EditPodr->Text=DMSprARM->ElementNAMEPOD->AsString;
		SprBV->UpdateForm();
		SprBV->NumberProcVibor=2;
		}
	}
}
//-----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormViborSprEd(void)
{
if(Prosmotr==true) return;

if (BeforeEditCheck()==true)
	{

	if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprEd.1",IID_IFormaViborSprEd,
												 (void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->Vibor=true;
		SpisokEd->IdNom=glStrToInt64(DM->DocTIDNOMCHKT->AsString);
        SpisokEd->UpdateForm();
		//SpisokEd->HintLabel->Caption="Выберите единицу для документа чек ККМ";
		//SpisokEd->LabelNom->Caption=DM->DocTNAMENOM->AsString;
		SprBV->NumberProcVibor=6;

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
	if (FormaViborSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
												 (void**)&FormaViborSprNom);
		FormaViborSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborSprNom->Vibor=true;
		FormaViborSprNom->DM->IdTypePrice=glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString);
        //FormaViborSprNom->SpisokTypePrice->ItemIndex=FormaViborSprNom->DM->GetIndexTypePrice()-1;
		FormaViborSprNom->UpdateForm();
		FormaViborSprNom->NumberProcVibor=1;
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

glFR->InitDocument(1);
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

glFR->InitDocument(1);
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
	if (FormaInputCode==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputCode.1",IID_IFormaInputCode,
												 (void**)&FormaInputCode);
		FormaInputCode->Init(InterfaceMainObject,InterfaceImpl);
        FormaInputCode->Vibor=true;
		//FormaInputCode->NameSprLabel->Caption="Справочник номенклатура:";
		FormaInputCode->NumberProcVibor=4;
		}
	}
}
//----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormInputCodeNomBV(void)
{

if (BeforeEditCheck()==true)
	{
	if (FormaInputCode==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputCode.1",IID_IFormaInputCode,
												 (void**)&FormaInputCode);
		FormaInputCode->Init(InterfaceMainObject,InterfaceImpl);
        FormaInputCode->Vibor=true;
		//FormaInputCode->NameSprLabel->Caption="Справочник быстрого вызова:";
		FormaInputCode->NumberProcVibor=3;
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

	if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите сумму:";
		//FormaInputText->Caption="Сумма";
		FormaInputText->NumberProcVibor=8;
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
if (FormaInputText==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите сумму:";
        //FormaInputText->Caption="Внесение";
		FormaInputText->NumberProcVibor=9;
		}

}
//----------------------------------------------------------------------------
void TFormaARMKassir::OpenFormSnatie(void)
{
if (FormaInputText==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите сумму:";
		//FormaInputText->Caption="Снятие";
		FormaInputText->NumberProcVibor=10;
        }
}
//---------------------------------------------------------------------------
void TFormaARMKassir::VnestiSummu(float sum)
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

glFR->InitDocument(1);
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

glFR->InitDocument(1);
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
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
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


				DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
				DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
				DM->DocTSHED->AsString=Ed->ElementSHED->AsString;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				DM->DocTKOLCHKT->AsFloat=ObBar->Kol;

				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);

		//cxGrid1->Focused();
		//	cxGrid1->CanFocus();
		if (cxPageControl1->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOLCHKT->Selected=true;
			cxGrid1DBTableView1KOLCHKT->Focused=true;
            }
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
CLSID clsid;
InterfaceGlobalCom->kanCLSIDFromProgID("Oberon.SheetEditor.1",&clsid);
if (InterfaceGlobalCom->kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) !=-1)
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
IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
												 (void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);

DMSprFirm->OpenElement(glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString));
IDMSprSklad * DMSprSklad;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSklad.1",IID_IDMSprSklad,
												 (void**)&DMSprSklad);
DMSprSklad->Init(InterfaceMainObject,InterfaceImpl);

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
DMSprFirm->kanRelease();
DMSprSklad->kanRelease();
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
		SE->TecCell_SetText("Продавец:________________________________ "+
					   DM->DocAllFNAME_USER->AsString);
		SE->TecCell_SetHorzTextAlign(ISheetEditor::haLEFT);
		SE->TecCell_SetVertTextAlign(ISheetEditor::vaCENTER);
		x++;
        y++;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::PrintGoodsCheckOnFR(void)
{
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

glFR->InitDocument(1);
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
	if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите штрих-код:";
		//FormaInputText->Caption="Штрих-код";
		FormaInputText->NumberProcVibor=13;
		}
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndInputBarCode(void)
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

				DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
				DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
				DM->DocTSHED->AsString=Ed->ElementSHED->AsString;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				DM->DocTKOLCHKT->AsFloat=ObBar->Kol;

				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

				DM->DocT->Post();
				ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);

				if (cxPageControl1->ActivePageIndex==0)
					{
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOLCHKT->Selected=true;
					cxGrid1DBTableView1KOLCHKT->Focused=true;
					}

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
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputDiscountCard.1",IID_IFormaInputDiscountCard,
												 (void**)&FormaInputDiscountCard);
		FormaInputDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputDiscountCard->Vibor=true;
		//FormaInputDiscountCard->NameLabel->Caption="Введите код дисконтой карты:";
		//FormaInputDiscountCard->Caption="Код дисконтной карты";
		FormaInputDiscountCard->NumberProcVibor=14;
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborDiscountCard(void)
{
AnsiString s=FormaInputDiscountCard->InputText;
if (ObCheckDiscount->FindCardPoCodu(s)==true)
	{
	DM->Doc->Edit();
	if (ObCheckDiscount->IdDiscountCard!=0)
		{
		DM->DocIDDCARDCHK->AsString=ObCheckDiscount->IdDiscountCard;
		DM->DocNAME_SDISCOUNT_CARD->AsString=ObCheckDiscount->NameDiscountCard;
		DM->Doc->Post();
		}
	if (ObCheckDiscount->IdKlient!=0)
		{
		DM->DocAll->Edit();
		DM->DocAllIDKLDOC->AsString=ObCheckDiscount->IdKlient;
		DM->DocAllNAMEKLIENT->AsString=ObCheckDiscount->NameKlient;
		DM->DocAll->Post();
		}
	}
else
	{
	ShowMessage(ObCheckDiscount->TextMessageAtention);
	}

FormaInputDiscountCard=0;
UpdateValuesDiscount();
Nal->SetFocus();
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
BM=DM->DocT->GetBookmark();

ObCheckDiscount->ClearList();
ObCheckDiscount->IdDiscountCard=glStrToInt64(DM->DocIDDCARDCHK->AsString);
ObCheckDiscount->NameDiscountCard=DM->DocNAME_SDISCOUNT_CARD->AsString;
ObCheckDiscount->IdTypePrice=IdTypePrice;
ObCheckDiscount->NameTypePrice=NameTypePrice;
ObCheckDiscount->IdSklad=glStrToInt64(DM->DocAllIDSKLDOC->AsString);
ObCheckDiscount->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
ObCheckDiscount->NameKlient=DM->DocAllNAMEKLIENT->AsString;

DM->DocT->First();
while (!DM->DocT->Eof)
		{
		ObCheckDiscount->AddString(
				glStrToInt64(DM->DocTIDCHKT->AsString),
				glStrToInt64(DM->DocTIDNOMCHKT->AsString),
				glStrToInt64(DM->DocTIDEDCHKT->AsString),
				glStrToInt64(DM->DocTIDGRPNOM->AsString),
				glStrToInt64(DM->DocTIDVID_SNOM->AsString),
				DM->DocTPRICECHKT->AsFloat,
				DM->DocTKOLCHKT->AsFloat,
				DM->DocTKFCHKT->AsFloat,
				DM->DocTSUMCHKT->AsFloat,
				DM->DocTSKCHKT->AsFloat,
				DM->DocTPRSKCHKT->AsFloat,
				DM->DocTPRSK_AUTO_DCHKT->AsFloat,
				DM->DocTPRSK_CARD_DCHKT->AsFloat,
				DM->DocTPRSK_HAND_DCHKT->AsFloat,
				DM->DocTNO_SK_DCHKT->AsInteger
							);
		DM->DocT->Next();
		}


	ObCheckDiscount->CheckDiscount();
	DM->DocT->First();

	while (ObCheckDiscount->GetString()==true)
		{
		if (ObCheckDiscount->StringDoc->IdString == glStrToInt64(DM->DocTIDCHKT->AsString))
			{
			DM->DocT->Edit();
				DM->DocTPRICECHKT->AsFloat = ObCheckDiscount->StringDoc->Price;
				DM->DocTPRSK_AUTO_DCHKT->AsFloat = ObCheckDiscount->StringDoc->ProcentDiscountAuto;
				DM->DocTPRSK_CARD_DCHKT->AsFloat = ObCheckDiscount->StringDoc->ProcentDiscountCard;
				DM->DocTPRSK_HAND_DCHKT->AsFloat = ObCheckDiscount->StringDoc->ProcentDiscountHand;
				DM->DocTPRSKCHKT->AsFloat = ObCheckDiscount->StringDoc->ProcentDiscount;
				if (ObCheckDiscount->StringDoc->NoDiscount==true)
					{
					DM->DocTNO_SK_DCHKT->AsInteger=1;
					}
				else
					{
                    DM->DocTNO_SK_DCHKT->AsInteger=0;
					}

			DM->DocT->Post();
			}
        DM->DocT->Next();
		}

IdTypePrice=ObCheckDiscount->IdTypePrice;
NameTypePrice=ObCheckDiscount->NameTypePrice;
Prim->Caption=ObCheckDiscount->TextMessage;

if (ObCheckDiscount->TextMessageAtention !="")
	{
	ShowMessage(ObCheckDiscount->TextMessageAtention);
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
		IDMSprNakSkidok * dm_snak_skidok;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNakSkidok.1",IID_IDMSprNakSkidok,
												 (void**)&dm_snak_skidok);
		dm_snak_skidok->Init(InterfaceMainObject,InterfaceImpl);

		IDMGurOperDiscountCard * gur_oper;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard,
												 (void**)&gur_oper);
		gur_oper->Init(InterfaceMainObject,InterfaceImpl);

		dm_snak_skidok->GetSpisokSkidok( glStrToInt64(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsString),
									 glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));

		AnsiString text_descr="";
		AnsiString text_descr_next="";
		double min_summa=10000000;

		
		while(!dm_snak_skidok->Query->Eof)
			{
			int kol_day=dm_snak_skidok->Query->FieldByName("PERIOD_SNAK_SKIDOK")->AsInteger;
			//получим сумму покупок
			TDateTime pos_nach=Now()-kol_day;
			double sum_pokupok=gur_oper->GetSumPokupok(glStrToInt64(DM->DocAllIDKLDOC->AsString),pos_nach)
														+DM->DocAllSUMDOC->AsFloat;
			double tek_procent=0;
			double tek_rasnica=0;
			if (sum_pokupok >= dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)
				{
				tek_procent=dm_snak_skidok->Query->FieldByName("PROCENT_SNAK_SKIDOK")->AsFloat;
				}
			else
				{  //определяем разницу
				tek_rasnica=dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat-sum_pokupok;
				}

			if (proc<tek_procent)
				{
				proc=tek_procent;
				text_descr="Накопленная сумма за "+IntToStr(kol_day)+" дней :"+FloatToStr(sum_pokupok);
				}

			if (min_summa > tek_rasnica && tek_rasnica > 0.001 )
				{
				min_summa=tek_rasnica;
				text_descr_next="\nДля след. скидки надо за "+IntToStr(kol_day)+
									" дней :"+FloatToStr(dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)+
									" Не хватает "+FloatToStr(dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat-
													sum_pokupok);
				}

			dm_snak_skidok->Query->Next();
			}

		dm_snak_skidok->kanRelease();
		gur_oper->kanRelease();
		Prim->Caption=text_descr+text_descr_next;

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

		IDMSprKlient * dm_spr_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
												 (void**)&dm_spr_klient);
		dm_spr_klient->Init(InterfaceMainObject,InterfaceImpl);

		dm_spr_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));

		if (glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString)!=0)
			{
			DM->Doc->Edit();
			DM->DocIDTPRICE->AsString=dm_spr_klient->ElementIDTPRICEKLIENT->AsString;
			DM->Doc->Post();
			IDMSprTypePrice * dm_spr_type_price;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&dm_spr_type_price);
			dm_spr_type_price->Init(InterfaceMainObject,InterfaceImpl);
			dm_spr_type_price->OpenElement(glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString));
			NameTypePrice=dm_spr_type_price->ElementNAME_TPRICE->AsString;
			dm_spr_type_price->kanRelease();

			//проверим есть ли строки
			if(DM->DocT->RecordCount>0)
				{
				String V="В табличной части документа есть строки. Пересчитать цены?";
				String Z="Пересчитать цены?";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						IDMSprPrice * DMSprPrice;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&DMSprPrice);
						DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
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
						DMSprPrice->kanRelease();
						}
				}

			}

	dm_spr_klient->kanRelease();
	}

//**************************************************************************
//скидка из справочника Номенклатура  --------------------------------------

if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
	{
	IDMSprNom * spr_nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
	spr_nom->Init(InterfaceMainObject,InterfaceImpl);
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
	spr_nom->kanRelease();
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
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
				spr_nom->Init(InterfaceMainObject,InterfaceImpl);
				spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOMCHKT->AsString));
				if (glStrToInt64(spr_nom->ElementIDVID_SNOM->AsString)!=
						glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString))
					{
					ok=false;
					}
				spr_nom->kanRelease();
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
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&spr_nom);
				spr_nom->Init(InterfaceMainObject,InterfaceImpl);
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
				spr_nom->kanRelease();;
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

if (CheckOplataBeforePrintCheck()==false)
	{
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
	if (PrintCheck(false)==true)
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
bool TFormaARMKassir::PrintCheck(bool povtor)
{
bool result=false;

DM_Connection->glSaveProtocol("Попытка напечатать чек "+DM->DocAllNUMDOC->AsString);
	UnicodeString StrPr="  ";
	if (povtor==false)
		{
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
		}


if (DMSprARM->GetParameter("NO_PRINT_FR")=="YES")
		{
		result=true;
		return result;
		}

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





double oplata_for_no_fiscal_check=DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat+
						 DM->DocOPLPLATCARD_ALL_DCHK->AsFloat;

double oplata_for_fiscal_check=DM->DocAllSUMDOC->AsFloat-oplata_for_no_fiscal_check;


//**********************************************
if ((oplata_for_fiscal_check > 0.001) && (oplata_for_no_fiscal_check < 0.01))
	{  //фискальная оплата, есть нефискальной нет
	// печатаем либо фискальный либо нефискальный чек
	if(DMSprARM->GetParameter("PrintFiscalCheck")=="1")
		{
		result=PrintStandartFiscalCheck(povtor);
		}
	else
		{
		result=PrintStandartNoFiscalCheck(povtor);
		}
	}

//************************************************
if ((oplata_for_fiscal_check < 0.01) && (oplata_for_no_fiscal_check > 0.001))
	{  //фискальной оплаты нет, нефискальная есть
	// печатаем либо фискальный либо нефискальный чек
	result=PrintCheckForNoFiscalOplat(povtor);
	}

//************************************************
if ((oplata_for_fiscal_check > 0.001) && (oplata_for_no_fiscal_check > 0.001))
	{  //фискальная оплата есть,  нефискальная оплата есть
	// печатаем либо фискальный либо нефискальный чек
	if(DMSprARM->GetParameter("PrintFiscalCheck")=="1")
		{
		result=PrintFiscalCheckForKombOplat(povtor);
		}
	else
		{
		result=PrintNoFiscalCheckForKombOplat(povtor);
		}
	}



return result;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::PrintStandartFiscalCheck(bool povtor)
{

bool Res=false;



try
	{


	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (povtor==true)
		{
		glFR->InitDocument(1);
		}
	else
		{
		glFR->InitDocument(2);
		if (DMSprARM->GetParameter("TaxVariant") != "")
			{
			glFR->TaxVariant=StrToInt(DMSprARM->GetParameter("TaxVariant"));
			}
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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



	if (DM->DocOPERCHK->AsInteger==0) //ПРОДАЖА
		{
		if (glFR->PrintString("ПРОДАЖА",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM->DocOPERCHK->AsInteger==1) //ПРОДАЖА
		{
		if (glFR->PrintString("ВОЗВРАТ",1,1,0,true,false, false)==false)
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

		glFR->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код
		glFR->NameNom=DM->DocTKRNAMENOM->AsString;
		glFR->Quantity=DM->DocTKOLCHKT->AsFloat;
		glFR->Price=DM->DocTPRICECHKT->AsFloat;
		glFR->Amount=DM->DocTSUMCHKT->AsFloat;
		glFR->Department=1;
		glFR->Tax=1;  //без ндс

		if (glFR->AddFiscalString()==false)
			{
			throw Exception(glFR->TextError);
			}




//		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==false)
//			{
//			throw Exception(glFR->TextError);
//			}
//
//		if (DM->DocTSKCHKT->AsFloat>0)
//			{  //со скидкой
//			UnicodeString StrPr="";
//			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
//				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
//				+DM->DocTNAMEED->AsString+" = "
//				+FloatToStrF(DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat,ffFixed,15,2);
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
//				{
//				throw Exception(glFR->TextError);
//				}
//
//			StrPr="-"+FloatToStr(DM->DocTPRSKCHKT->AsFloat)+" % "
//				+FloatToStrF(DM->DocTSKCHKT->AsFloat,ffFixed,15,2)+
//				" = "+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);
//
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
//				{
//				throw Exception(glFR->TextError);
//				}
//			}
//		else
//			{//без скидки
//
//			UnicodeString StrPr="";
//			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
//				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
//				+DM->DocTNAMEED->AsString+" = "
//				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);
//
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
//				{
//				throw Exception(glFR->TextError);
//				}
//			}

		DM->DocT->Next();
		}

	if (glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}


		//нет дополнительных оплат
		if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->CloseNoFiscalCheck()==false)
			{
			throw Exception(glFR->TextError);
			}




		double SumCheck=DM->DocAllSUMDOC->AsFloat;
		double OplataNal=DM->DocNALCHK->AsFloat;
		double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;
		if (povtor==false)
			{  //не повтор
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
			if(glFR->OpenNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Фискальная часть чека:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Сумма: "+FloatToStrF(SumCheck,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Наличными: "+FloatToStrF(OplataNal,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Банк. картой: "+FloatToStrF(OplataPlatCard,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			if(glFR->CloseNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}
			glFR->Cut(1);
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
bool TFormaARMKassir::PrintStandartNoFiscalCheck(bool povtor)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек "+DM->DocAllNUMDOC->AsString);
bool Res=false;



try
	{
			

	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}


    glFR->InitDocument(1);
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
			UnicodeString StrPr="";
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

			UnicodeString  StrPr="";
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
bool TFormaARMKassir::PrintCheckForNoFiscalOplat(bool povtor)
{
bool Res=false;



try
	{


	if(glFR->ProvVosmPrintCheck()==false)
		{
		throw Exception(glFR->TextError);
		}
    glFR->InitDocument(1);
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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



	if (DM->DocOPERCHK->AsInteger==0) //ПРОДАЖА
		{
		if (glFR->PrintString("ПРОДАЖА",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM->DocOPERCHK->AsInteger==1) //ПРОДАЖА
		{
		if (glFR->PrintString("ВОЗВРАТ",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (glFR->PrintString("Чек ККМ №"+DM->DocAllNUMDOC->AsString,1,0,1,true,false, false)==false)
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
			UnicodeString StrPr="";
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

			UnicodeString  StrPr="";
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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



		//фискальный чек надо печатать только на наличные и банковскую карты

	//double oplata_for_no_fiscal_check=DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat+
	//					 DM->DocOPLPLATCARD_ALL_DCHK->AsFloat;





		if(glFR->PrintString("Всего:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2),
									4,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Оплата:",1,0,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if (DM->DocNALCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Наличными:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocNALCHK->AsFloat,ffFixed,15,2),
									1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}

		if (DM->DocOPLPCCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Банковской картой:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPCCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOPLPLATCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная плат. карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPLATCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}


		if (DM->DocOPLCREDITCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная кредитная карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLCREDITCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOpl->RecordCount > 0)
			{
			if(glFR->PrintString("Доп. платежные карты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			DM->DocOpl->First();
			while (!DM->DocOpl->Eof)
				{
				if(glFR->PrintString(DM->DocOplNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}
				if(glFR->PrintString(FloatToStrF(DM->DocOplSUMPLAT_DCHK_OPL->AsFloat,ffFixed,15,2),
													1,0,2,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

				DM->DocOpl->Next();
				}
			}

		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Всего оплаты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if(glFR->PrintString(FloatToStrF(DM->DocALLOPL->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Сдача:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocSDACHA_DCHK->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}


		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString("Подпись клиента  ______________",1,0,1,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->CloseNoFiscalCheck()==false)
			{
			throw Exception(glFR->TextError);
			}

  //нет фискальной оплаты
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
bool TFormaARMKassir::PrintFiscalCheckForKombOplat(bool povtor)
{

bool Res=false;



try
	{


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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



	if (DM->DocOPERCHK->AsInteger==0) //ПРОДАЖА
		{
		if (glFR->PrintString("ПРОДАЖА",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM->DocOPERCHK->AsInteger==1) //ПРОДАЖА
		{
		if (glFR->PrintString("ВОЗВРАТ",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (glFR->PrintString("Чек ККМ №"+DM->DocAllNUMDOC->AsString,1,0,1,true,false, false)==false)
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
			UnicodeString StrPr="";
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

			UnicodeString StrPr="";
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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



		//фискальный чек надо печатать только на наличные и банковскую карты

	double oplata_for_no_fiscal_check=DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat+
						 DM->DocOPLPLATCARD_ALL_DCHK->AsFloat;

	double oplata_for_fiscal_check=DM->DocAllSUMDOC->AsFloat-oplata_for_no_fiscal_check;


		if(glFR->PrintString("Всего:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2),
									4,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Оплата:",1,0,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if (DM->DocNALCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Наличными:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocNALCHK->AsFloat,ffFixed,15,2),
									1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}

		if (DM->DocOPLPCCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Банковской картой:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPCCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOPLPLATCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная плат. карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPLATCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}


		if (DM->DocOPLCREDITCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная кредитная карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLCREDITCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOpl->RecordCount > 0)
			{
			if(glFR->PrintString("Доп. платежные карты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			DM->DocOpl->First();
			while (!DM->DocOpl->Eof)
				{
				if(glFR->PrintString(DM->DocOplNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}
				if(glFR->PrintString(FloatToStrF(DM->DocOplSUMPLAT_DCHK_OPL->AsFloat,ffFixed,15,2),
													1,0,2,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

				DM->DocOpl->Next();
				}
			}

		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Всего оплаты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if(glFR->PrintString(FloatToStrF(DM->DocALLOPL->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Сдача:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocSDACHA_DCHK->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}


		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString("Подпись клиента  ______________",1,0,1,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->CloseNoFiscalCheck()==false)
			{
			throw Exception(glFR->TextError);
			}

		 //еще есть фискальная оплата


		double SumCheck=oplata_for_fiscal_check;
		double OplataNal=DM->DocNALCHK->AsFloat;
		double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;
		if (povtor==false)
			{
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
			if(glFR->OpenNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Фискальная часть чека:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Сумма: "+FloatToStrF(SumCheck,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Наличными: "+FloatToStrF(OplataNal,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString("Банк. картой: "+FloatToStrF(OplataPlatCard,ffFixed,15,2),1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			if(glFR->CloseNoFiscalCheck()==false)
				{
				throw Exception(glFR->TextError);
				}
            glFR->Cut(1);
			}//конец повтора чека

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
bool TFormaARMKassir::PrintNoFiscalCheckForKombOplat(bool povtor)
{
DM_Connection->glSaveProtocol("Попытка напечатать чек "+DM->DocAllNUMDOC->AsString);
bool Res=false;



try
	{


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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



	if (DM->DocOPERCHK->AsInteger==0) //ПРОДАЖА
		{
		if (glFR->PrintString("ПРОДАЖА",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}

	if (DM->DocOPERCHK->AsInteger==1) //ПРОДАЖА
		{
		if (glFR->PrintString("ВОЗВРАТ",1,1,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		}
	if (glFR->PrintString("Чек ККМ №"+DM->DocAllNUMDOC->AsString,1,0,1,true,false, false)==false)
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
			UnicodeString StrPr="";
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

			UnicodeString StrPr="";
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

	if (povtor==true)
		{
			if (glFR->PrintString(" --- Повтор чека ---",1,1,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		}



		//фискальный чек надо печатать только на наличные и банковскую карты
	//double oplata_for_no_fiscal_check=DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat+
	//					 DM->DocOPLPLATCARD_ALL_DCHK->AsFloat;


	//double oplata_for_fiscal_check=DM->DocAllSUMDOC->AsFloat-oplata_for_no_fiscal_check;


		if(glFR->PrintString("Всего:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2),
									4,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Оплата:",1,0,1,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if (DM->DocNALCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Наличными:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocNALCHK->AsFloat,ffFixed,15,2),
									1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}

		if (DM->DocOPLPCCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Банковской картой:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPCCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOPLPLATCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная плат. карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLPLATCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			}


		if (DM->DocOPLCREDITCARD_DCHK->AsFloat > 0.001)
			{
			if(glFR->PrintString("Основная кредитная карта:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

			if(glFR->PrintString(DM->DocNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			if(glFR->PrintString(FloatToStrF(DM->DocOPLCREDITCARD_DCHK->AsFloat,ffFixed,15,2),
												1,0,2,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			}

		if (DM->DocOpl->RecordCount > 0)
			{
			if(glFR->PrintString("Доп. платежные карты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
			DM->DocOpl->First();
			while (!DM->DocOpl->Eof)
				{
				if(glFR->PrintString(DM->DocOplNAME_SDISCOUNT_CARD->AsString,1,0,0,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}
				if(glFR->PrintString(FloatToStrF(DM->DocOplSUMPLAT_DCHK_OPL->AsFloat,ffFixed,15,2),
													1,0,2,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

				DM->DocOpl->Next();
				}
			}

		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Всего оплаты:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}
		if(glFR->PrintString(FloatToStrF(DM->DocALLOPL->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString("Сдача:",1,0,0,true,false, false)==false)
				{
				throw Exception(glFR->TextError);
				}

		if(glFR->PrintString(FloatToStrF(DM->DocSDACHA_DCHK->AsFloat,ffFixed,15,2),
													4,0,2,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}


		if (glFR->PrintLine()==false)
			{
			throw Exception(glFR->TextError);
			}

		if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString("Подпись клиента  ______________",1,0,1,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
			}
		if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
			{
			throw Exception(glFR->TextError);
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

if (glFR)
	{
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
	IDMRegGoods * reg;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
												 (void**)&reg);
	reg->Init(InterfaceMainObject,InterfaceImpl);
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
	reg->kanRelease();
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::cxGrid1Exit(TObject *Sender)
{
UpdateValuesDiscount();	
}

//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborDocCheckForVosvrat(void)
{


	CreateNewDocCheckVosvrat();
	CheckOperation=OpenCheckReturnSale_Operation;
	DM->DocAll->Edit();
	DM->DocAllIDDOCOSNDOC->AsString=FormaGurDocCheckKKM2->DM->TableIDDOC->AsString;
	DM->DocAll->Post();

	IDMDocCheck * check;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
												 (void**)&check);
	check->Init(InterfaceMainObject,InterfaceImpl);

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

		DM->DocTCODENOM->AsString=check->DocTCODENOM->AsString;
		DM->DocTARTNOM->AsString=check->DocTARTNOM->AsString;
		DM->DocTSHED->AsString=check->DocTSHED->AsString;

		DM->DocTIDDEPARTMENT_DCHKT->AsString=DM->DocTIDDEPARTMENT_DCHKT->AsString;
		DM->DocTNAME_SDEPARTMENT->AsString=DM->DocTNAME_SDEPARTMENT->AsString;

		DM->DocT->Post();

		check->DocT->Next();
		}

	check->kanRelease();

	CheckCreate=true;
	CheckPrint=false;
	CheckSave=false;
	Prim->Caption="Создан новый чек возврата!";
	DM_Connection->glSaveProtocol("Создан новый чек возврата");



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
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&DM);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите код проекта:";
		//FormaInputText->Caption="Проект";
		FormaInputText->NumberProcVibor=15;
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndViborProject(void)
{

	if (FormaInputText->InputText!="")
		{
		IDMSprProject *p;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprProject.1",IID_IDMSprProject,
												 (void**)&p);
		p->Init(InterfaceMainObject,InterfaceImpl);
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
        p->kanRelease();
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::VibratProjectMainMenuClick(TObject *Sender)
{
ViborProject();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::CheckDateTimeFR(void)
{
if (glFR==0) return;
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
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
												 (void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		//FormaInputText->NameLabel->Caption="Введите артикул:";
		//FormaInputText->Caption="Артикул";
		FormaInputText->NumberProcVibor=16;
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::EndInputArtikul(void)
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

		DM->DocTCODENOM->AsString=Nom->ElementCODENOM->AsString;
		DM->DocTARTNOM->AsString=Nom->ElementARTNOM->AsString;
		DM->DocTSHED->AsString=Nom->BasEdSHED->AsString;

					//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),
							glStrToInt64(DM->DocTIDEDCHKT->AsString),
							DM->DocTKFCHKT->AsFloat,
							0);
				dm_price->kanRelease();

 				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

		DM->DocT->Post();

		ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);
		cxGrid1DBTableView1KOLCHKT->Selected=true;
                    				//дисплей
		UnicodeString string1=DM->DocTNAMENOM->AsString;
		UnicodeString string2="Цена:"+DM->DocTPRICECHKT->AsString
											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
		if (glDisplayPok>0) glDisplayPok->ShowString1(string1,1,0,0);
		if (glDisplayPok>0) glDisplayPok->ShowString2(string2,1,0,0);

		if (cxPageControl1->ActivePageIndex==0)
					{
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOLCHKT->Selected=true;
					cxGrid1DBTableView1KOLCHKT->Focused=true;
					}
		}
	else
		{
		ShowMessage("Товар с артикулом "+s+" не найден!");
		}




UpdateForm();

}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir::PoArtikuluClick(TObject *Sender)
{
OpenFormInputArtikul();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::ActionSetMainTabScheetExecute(TObject *Sender)
{
cxPageControl1->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::ActionSetOplataTabScheetExecute(TObject *Sender)

{
cxPageControl1->ActivePageIndex=1;
}
//---------------------------------------------------------------------------
bool TFormaARMKassir::CheckOplataBeforePrintCheck(void)
{
bool result=true;     //true если можно продолжить

if (DM->DocSDACHA_DCHK->AsFloat < 0)
	{
	ShowMessage("Недостаточно оплаты!");
	result=false;
	}

if (DM->DocOPLPCCHK->AsFloat > DM->DocAllSUMDOC->AsFloat)
	{
	ShowMessage("Оплата платежной картой не может быть больше суммы чека!!");
	result=false;
	}



if (CheckSumPlatCard()==false)
	{
	result=false;
	}

if (CheckSumCreditCard()==false)
	{
    result=false;
	}


return result;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::CheckSumPlatCard(void)
{
bool result=true;


if (DM->DocOPLPLATCARD_DCHK->AsFloat >0 )
	{
	if (DMSprDiscountCard->ElementFL_PLAT_SDISCOUNT_CARD->AsInteger==1)
		{//проверим сумму на основной платежной карте
		IDMQueryRead *q;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
		q->Init(InterfaceMainObject,InterfaceOwnerObject);
		q->pFIBQ->Close();
		q->pFIBQ->SQL->Clear();
		UnicodeString zapros="select rgcard_balance.sum_rgcard_balance   \
								from rgcard_balance                      \
								where rgcard_balance.idfirm_rgcard_balance=:PARAM_IDFIRM and  \
								rgcard_balance.idcard_rgcard_balance=:PARAM_IDCARD  ";
		q->pFIBQ->SQL->Add(zapros);
		q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
		q->pFIBQ->ParamByName("PARAM_IDCARD")->AsString=DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString;
		q->pFIBQ->ExecQuery();


		if (glCompareDoubleValue(q->pFIBQ->FieldByName("sum_rgcard_balance")->AsFloat,
										 DM->DocOPLPLATCARD_DCHK->AsFloat, 3)  >= 0)
			{

			}
		else
			{
			result=false;
			ShowMessage("На основной карте недостаточно средств!\n\
							   Требуется 	"+DM->DocOPLPLATCARD_DCHK->AsString+
							   "\nНа карте    "+q->pFIBQ->FieldByName("sum_rgcard_balance")->AsString);
			}




		q->kanRelease();

		}
	else
		{
		result=false;
		ShowMessage("Выбранная основная карта не является платежной картой! \
									Выберите другую карту!");

		}
	}

//проверим остатки на доп. картах

return result;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::CheckSumCreditCard(void)
{
bool result=true;

//проверим максимальную сумму кредита
if (DM->DocOPLCREDITCARD_DCHK->AsFloat >0 )
	{
    DMSprDiscountCard->OpenElement(glStrToInt64(DM->DocIDDCARDCHK->AsString));
	if (DMSprDiscountCard->ElementFL_CREDIT_SDISCOUNT_CARD->AsInteger==1)
		{//получим сумму кредита

		IDMQueryRead *q;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
		q->Init(InterfaceMainObject,InterfaceOwnerObject);
		q->pFIBQ->Close();
		q->pFIBQ->SQL->Clear();
		UnicodeString zapros="select sdog.maxsumcredit_sdog    \
								from sdog                      \
								where sdog.id_sdog=:PARAM_ID ";
		q->pFIBQ->SQL->Add(zapros);
		q->pFIBQ->ParamByName("PARAM_ID")->AsString=DMSprDiscountCard->ElementIDDOG_SDISCOUNT_CARD->AsString;
		q->pFIBQ->ExecQuery();
		double max_sum_credit=q->pFIBQ->FieldByName("maxsumcredit_sdog")->AsFloat;

		//текущая задолженность
		q->pFIBQ->Close();
		q->pFIBQ->SQL->Clear();
		zapros="select rgvsrasch.sum_vsrasch   \
									from rgvsrasch        \
									where rgvsrasch.idfirm_vsrasch=:PARAM_IDFIRM and  \
									rgvsrasch.idklient_vsrasch=:PARAM_IDKLIENT ";
		q->pFIBQ->SQL->Add(zapros);
		q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
		q->pFIBQ->ParamByName("PARAM_IDKLIENT")->AsString=DM->DocAllIDKLDOC->AsString;
		q->pFIBQ->ExecQuery();
		double tec_dolg=q->pFIBQ->FieldByName("sum_vsrasch")->AsFloat;



		if (glCompareDoubleValue(DM->DocOPLCREDITCARD_DCHK->AsFloat+tec_dolg,
										 max_sum_credit, 3) == 1)
			{
			result=false;
			ShowMessage("Сумма кредита по текущему чеку и текущего долга клиента превышает максимальную сумму кредита!\n\
							   Текущий долг 	"+FloatToStr(tec_dolg)+
							   "\n   Сумма кредита по чеку    "+DM->DocOPLCREDITCARD_DCHK->AsString+
							   "\n   Максимальная сумма кредита    "+FloatToStr(max_sum_credit));
			}

		q->kanRelease();

		}
	else
		{
		result=false;
		ShowMessage("Выбранная основная карта не является кредитной картой! \
									Выберите другую карту!");

		}
	}

//проверим текущую задолженность

return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::PrintPovtorCheckOnFRClick(TObject *Sender)
{
PrintCheck(true);
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::OplataPlatCardcxDBCalcEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir::OplataCreditCardcxDBCalcEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaARMKassir::MainMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaARMKassir::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();

//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));


module->ExecuteModule();
}
//---------------------------------------------------------------------------
bool TFormaARMKassir::CreateCheckNaOsnRealRemont(__int64 id_doc_real_remont)
{
bool result=true;


		IDMQueryRead *q;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
		q->Init(InterfaceMainObject,InterfaceOwnerObject);
		q->pFIBQ->Close();
		q->pFIBQ->SQL->Clear();
UnicodeString zapros="select rem_drealt.idnom_rem_drealt,                     \
		snom.namenom,                                                         \
		snom.krnamenom,                                                       \
		snom.codenom,                                                         \
		snom.artnom,                                                          \
		sed.ided,                                                             \
		sed.nameed,                                                           \
		sed.shed,                                                             \
		sum(rem_drealt.kol_rem_drealt * rem_drealt.kf_rem_drealt)             \
	from rem_drealt                                                           \
	left outer join snom on rem_drealt.idnom_rem_drealt = snom.idnom          \
	left outer join sed on snom.idbasednom=sed.ided                           \
	where rem_drealt.iddoc_rem_drealt=:PARAM_IDDOC_REM                        \
	group by rem_drealt.idnom_rem_drealt,                                     \
		snom.namenom,                                                         \
		snom.krnamenom,                                                       \
		snom.codenom,                                                         \
		snom.artnom,                                                          \
		sed.ided,                                                             \
		sed.nameed,                                                           \
		sed.shed   ";

		q->pFIBQ->SQL->Add(zapros);
		q->pFIBQ->ParamByName("PARAM_IDDOC_REM")->AsString=id_doc_real_remont;
		q->pFIBQ->ExecQuery();

		while (!q->pFIBQ->Eof)
			{
				DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=q->pFIBQ->FieldByName("idnom_rem_drealt")->AsString;

				//Nom->IdTypePrice=IdTypePrice;
				Nom->OpenElement(glStrToInt64(q->pFIBQ->FieldByName("idnom_rem_drealt")->AsString));


				DM->DocTNAMENOM->AsString=q->pFIBQ->FieldByName("namenom")->AsString;
				DM->DocTKRNAMENOM->AsString=q->pFIBQ->FieldByName("krnamenom")->AsString;

				DM->DocTIDEDCHKT->AsString=q->pFIBQ->FieldByName("ided")->AsString;
				DM->DocTNAMEED->AsString=q->pFIBQ->FieldByName("nameed")->AsString;
				DM->DocTKFCHKT->AsFloat=1;

				DM->DocTCODENOM->AsString=q->pFIBQ->FieldByName("codenom")->AsString;
				DM->DocTARTNOM->AsString=q->pFIBQ->FieldByName("artnom")->AsString;
				DM->DocTSHED->AsString=q->pFIBQ->FieldByName("shed")->AsString;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),
							glStrToInt64(DM->DocTIDEDCHKT->AsString),
							1,
							glStrToInt64(DM->DocTIDEDCHKT->AsString));
				dm_price->kanRelease();

				DM->DocTKOLCHKT->AsFloat=q->pFIBQ->FieldByName("sum")->AsFloat;

				DM->DocTIDDEPARTMENT_DCHKT->AsString=Nom->ElementIDDEPARTMENT_SNOM->AsString;
				DM->DocTNAME_SDEPARTMENT->AsString=Nom->ElementNAME_SDEPARTMENT->AsString;

				DM->DocT->Post();

            q->pFIBQ->Next();
			}
		q->kanRelease();


return result;
}
//----------------------------------------------------------------------------
__int64 TFormaARMKassir::GetIdOperSale(void)
{
__int64 result=0;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
DMSetup->OpenElement(51);
result=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);


DMSetup->kanRelease();

return result;
}
//---------------------------------------------------------------------------
__int64 TFormaARMKassir::GetIdOperReturnSale(void)
{
__int64 result=0;

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
DMSetup->OpenElement(52);
result=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);


DMSetup->kanRelease();

return result;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir::ConnectFR(void)
{
bool result=false;
glFR=0;
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
bool TFormaARMKassir::DisconnectFR(void)
{
bool result=true;

if (glFR > 0)
	{
	 glFR->Disconnect();
	 glFR->Done();
	 glFR->kanRelease();
	}

glFR=0;
return result;
}

//---------------------------------------------------------------------------
void TFormaARMKassir::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);


dm->SaveSetupBool(ProgId_FormaArmKassir,"SetVisible",true);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1CodeNom",cxGrid1DBTableView1CodeNom->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1ArtNom",cxGrid1DBTableView1ArtNom->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1BarCode",cxGrid1DBTableView1BarCode->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT",cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1PRSKCHKT",cxGrid1DBTableView1PRSKCHKT->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1PRNADCHKT",cxGrid1DBTableView1PRNADCHKT->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1SKCHKT",cxGrid1DBTableView1SKCHKT->Visible);
dm->SaveSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1NADCHKT",cxGrid1DBTableView1NADCHKT->Visible);



dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaARMKassir::LoadFormSetup(void)
{

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);

if (dm->LoadSetupBool(ProgId_FormaArmKassir,"SetVisible") == true)
	{
	cxGrid1DBTableView1CodeNom->Visible=dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1CodeNom");
	cxGrid1DBTableView1ArtNom->Visible=dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1ArtNom");
	cxGrid1DBTableView1BarCode->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1BarCode");
	cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT");
	cxGrid1DBTableView1PRSKCHKT->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1PRSKCHKT");
	cxGrid1DBTableView1PRNADCHKT->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1PRNADCHKT");
	cxGrid1DBTableView1SKCHKT->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1SKCHKT");
	cxGrid1DBTableView1NADCHKT->Visible = dm->LoadSetupBool(ProgId_FormaArmKassir,"cxGrid1DBTableView1NADCHKT");
	}
else
	{
	cxGrid1DBTableView1CodeNom->Visible = true;
	cxGrid1DBTableView1ArtNom->Visible = true;
	cxGrid1DBTableView1BarCode->Visible = true;
	cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT->Visible = true;
	cxGrid1DBTableView1PRSKCHKT->Visible = true;
	cxGrid1DBTableView1PRNADCHKT->Visible = true;
	cxGrid1DBTableView1SKCHKT->Visible = true;
	cxGrid1DBTableView1NADCHKT->Visible = true;
	}

dm->kanRelease();


}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir::N13Click(TObject *Sender)
{
SaveFormSetup();
}
//---------------------------------------------------------------------------

