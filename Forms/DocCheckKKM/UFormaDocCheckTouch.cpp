//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocCheckTouch.h"
#include "IDMSprNom.h"
#include "IFiskReg.h"
#include "IDMSprPrice.h"

#include "IDMGurOperDiscountCard.h"
#include "IDMSprTypePrice.h"
#include "IDMSprKlient.h"
#include "IDMSprBVNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IDMQueryRead.h"
#include "IDMSprFirm.h"
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
#pragma link "cxContainer"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocCheckTouch::TFormaDocCheckTouch(TComponent* Owner)
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
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaDocCheckTouch::Init(void)
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
			if (i_dev->GetDeviceObject(1, (void**) &glFR)!=-1)
				{
				glFR=0;
				}
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

EditRekvisit=NO;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM,
												 (void**)&ARM);
ARM->Init(InterfaceMainObject,InterfaceImpl);

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

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
CheckSave=false;
CheckPrint=false;
CheckCreate=false;
TypeEvent=0;
Prim->Caption="";


Oper->DataSource=DM->DataSourceDoc;

NumDocDBText->DataSource=DM->DataSourceDocAll;
KrNameNomDBText->DataSource=DM->DataSourceDocT;

NameKlientDBText->DataSource=DM->DataSourceDocAll;
NameDiscountCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
ActionOperation=aoNO;

//вкладка Доп

OplataPlatCardDBText->DataSource=DM->DataSourceDoc;
OplataCreditCardDBText->DataSource=DM->DataSourceDoc;
NameKlientDopDBText->DataSource=DM->DataSourceDocAll;
NameCardDopDBText->DataSource=DM->DataSourceDoc;
AllOplPlatCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
AllOplCreditCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NalChkDBText->DataSource=DM->DataSourceDoc;
OplataBankCardDBText->DataSource=DM->DataSourceDoc;
SumDocDBText->DataSource=DM->DataSourceDocAll;
AllOplDBText->DataSource=DM->DataSourceDoc;
SdachaDBText->DataSource=DM->DataSourceDoc;

cxGrid2DBTableView1->DataController->DataSource=DM->DataSourceDocOpl;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
												 (void**)&DMSprDiscountCard);
DMSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountAuto.1",IID_IDMSprDiscountAuto,
												 (void**)&DMSprDiscountAuto);
DMSprDiscountAuto->Init(InterfaceMainObject,InterfaceImpl);

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


IdARM=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
UpdateForm();
UpdateSetup();
result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaDocCheckTouch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::UpdateForm(void)
{
ARM->OpenElement(IdARM);
//NameFirmLabel->Caption=KKM->FirmaNAMEFIRM->AsString;
//NameSkladLabel->Caption=KKM->SkladNAMESKLAD->AsString;
//NameKKMLabel->Caption="ККМ: "+KKM->ElementNAMEKKM->AsString;
//TypePriceLabel->Caption="Тип цен: "+KKM->ElementNAME_TPRICE->AsString;

if (ARM->GetParameter("UCH")=="YES") UchLabel->Caption="Учебный режим!";
else UchLabel->Caption="";

StatusBar->Panels->Items[0]->Text="Фирма: "+ARM->ElementNAMEFIRM->AsString;
StatusBar->Panels->Items[1]->Text="ККМ: "+ARM->ElementNAMEKKM->AsString;
StatusBar->Panels->Items[2]->Text="Склад: "+ARM->ElementNAMESKLAD->AsString;

if (glFR!=0)
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
void TFormaDocCheckTouch::UpdateSetup(void)
{

ARM->OpenElement(IdARM);

//тип цен
IDMSprTypePrice * dm_spr_type_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
													(void**)&dm_spr_type_price);
dm_spr_type_price->Init(InterfaceMainObject,InterfaceImpl);
dm_spr_type_price->OpenElement(glStrToInt64(ARM->ElementIDTPRICEPOD->AsString));
NamePriceLabel->Caption="Тип цен:"+dm_spr_type_price->ElementNAME_TPRICE->AsString;
dm_spr_type_price->kanRelease();

DMSprDiscountCard->OpenElement(0);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Kalkulator)Kalkulator->kanRelease();
if(SpisokBVTouch)SpisokBVTouch->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(PanelButton)PanelButton->Close();


//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DM->kanRelease();
Nom->kanRelease();
Ed->kanRelease();
ObBar->kanRelease();
ARM->kanRelease();
Action=caFree;

DMSprDiscountCard->kanRelease();
DMSprDiscountAuto->kanRelease();

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------


int TFormaDocCheckTouch::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==EditNal)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocNALCHK->AsFloat=Kalkulator->Result;
               // DM->DocSDACHA->AsFloat=DM->DocNALCHK->AsFloat
               //         - (DM->DocAllSUMDOC->AsFloat
               //         +DM->DocOPLPCCHK->AsFloat);
                DM->Doc->Post();
                }
        Kalkulator=0;
        }

if (number_procedure_end==EditOplataPC)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
                DM->DocOPLPCCHK->AsFloat=Kalkulator->Result;
               // DM->DocSDACHA->AsFloat=DM->DocNALCHK->AsFloat
               //         - (DM->DocAllSUMDOC->AsFloat
               //         +DM->DocOPLPCCHK->AsFloat);
                DM->Doc->Post();
                }
        Kalkulator=0;
        }

if (number_procedure_end==EditEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDCHKT->AsString=SpisokEd->ElIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->ElNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=SpisokEd->ElKFED->AsFloat;
				DM->DocTKOLCHKT->AsFloat=SpisokEd->Kol;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDEDCHKT->AsString),         //единица
							DM->DocTKFCHKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();


				DM->DocT->Post();
			   }
		SpisokEd=0;
		}

if (number_procedure_end==EditNomBVTouch)
		{
		if (type_event==1)
			   {
			   if (ActionOperation==aoAddNewString)
						{
						DM->AddDocNewString();
						}
				Nom->IdTypePrice=glStrToInt64(ARM->ElementIDTPRICEPOD->AsString);
				Nom->OpenElement(SpisokBVTouch->IdNom);

				DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
				DM->DocTKOLCHKT->AsFloat=1;

				DM->DocTIDEDCHKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDEDCHKT->AsString),         //единица
							DM->DocTKFCHKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();
				DM->DocT->Post();
				UpdateValuesDiscount();
				}
        SpisokBVTouch=0;
        }

if (number_procedure_end==MnViborNom)
        {
		if (type_event==1)
               {
               if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
				Nom->IdTypePrice=glStrToInt64(ARM->ElementIDTPRICEPOD->AsString);
                Nom->OpenElement(SpisokBVTouch->IdNom);

                DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=Nom->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

                DM->DocTKOLCHKT->AsFloat=SpisokBVTouch->Kol;
				DM->DocTIDEDCHKT->AsString=SpisokBVTouch->IdEd;
                DM->DocTNAMEED->AsString=SpisokBVTouch->NameEd;
                DM->DocTKFCHKT->AsFloat=SpisokBVTouch->KFEd;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDEDCHKT->AsString),         //единица
							DM->DocTKFCHKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();
                DM->DocT->Post();

                }
        else
                {
                SpisokBVTouch=0;
				EditRekvisit=NO;
                ActionOperation=aoNO;
				UpdateValuesDiscount();
                }
        }

if (number_procedure_end==EditKol)
        {
		if (type_event==1)
			   {
                DM->DocT->Edit();
                DM->DocTKOLCHKT->AsFloat=Kalkulator->Result;
				DM->DocT->Post();
				UpdateValuesDiscount();
                }
		Kalkulator=0;
        }

if (number_procedure_end==EditPanelButton)
        {

        }

if (number_procedure_end==InputCodeBV)
		{
		if (type_event==1)
				{
				EndInputCodeBV();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ViborCard)
		{
		if (type_event==1)
				{
				EndViborDiscountCard();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ER_InputSumOsnPlatCard)
		{
		if (type_event==1)
				{
				EndInputSumOsnPlatCard();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ER_InputSumOsnCreditCard)
		{
		if (type_event==1)
				{
				EndInputSumOsnCreditCard();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ER_InputSumProchee)
		{
		if (type_event==1)
				{
				EndInputSumProchee();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ER_AddDopPlatCard)
		{
		if (type_event==1)
				{
				EndAddDopPlatCard();
				}
		Kalkulator=0;
		}

if (number_procedure_end==ER_InputSumDopPlatCard)
		{
		if (type_event==1)
				{
				EndInputSumDopPlatCard();
				}
		Kalkulator=0;
		}


if (number_procedure_end==ER_InputSumDopCreditCard)
		{
		if (type_event==1)
				{
				EndInputSumDopCreditCard();
				}
		Kalkulator=0;
		}

if (number_procedure_end!=MnViborNom)
        {
		EditRekvisit=NO;
		ActionOperation=aoNO;
		
		}


return -1;
}

//---------------------------------------------------------------------------





void __fastcall TFormaDocCheckTouch::BitBtn4Click(TObject *Sender)
{
if(CheckPrint==true) return;
if(CheckCreate==false) return;
if (Kalkulator==NULL)
        {
        InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=EditKol;
        }
}

//---------------------------------------------------------------------------
void TFormaDocCheckTouch::OpenFormSpiskaBVNomTouch(void)
{
if(Prosmotr==true) return;
if (SpisokBVTouch==NULL)
        {
        UpdateSetup();
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprBVNomTouch.1",IID_IFormaSpiskaSprBVNomTouch,
									 (void**)&SpisokBVTouch);
		SpisokBVTouch->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBVTouch->Vibor=true;
		SpisokBVTouch->MnVibor=false;
		SpisokBVTouch->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBVTouch->IdSklad=glStrToInt64(DM->DocAllIDSKLDOC->AsString);
		SpisokBVTouch->NumberProcVibor=EditNomBVTouch;
		}
}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::OpenFormMnViborSpiskaSprBVNom(void)
{
if(Prosmotr==true) return;
if (SpisokBVTouch==NULL)
        {
        UpdateSetup();
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprBVNomTouch.1",IID_IFormaSpiskaSprBVNomTouch,
									 (void**)&SpisokBVTouch);
		SpisokBVTouch->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBVTouch->Vibor=true;
		SpisokBVTouch->MnVibor=true;
		SpisokBVTouch->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBVTouch->IdSklad=glStrToInt64(DM->DocAllIDSKLDOC->AsString);
		SpisokBVTouch->NumberProcVibor=MnViborNom;
		}
}

//-----------------------------------------------------------------------------
void TFormaDocCheckTouch::OpenFormSpiskaSprEd(void)
{
if(Prosmotr==true) return;
if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprEdTouch.1",IID_IFormaSpiskaSprEdTouch,
									 (void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->Vibor=true;
		SpisokEd->NumberProcVibor=EditEdinica;
		SpisokEd->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokEd->IdSklad=glStrToInt64(DM->DocAllIDSKLDOC->AsString);
		SpisokEd->IdNom=glStrToInt64(DM->DocTIDNOMCHKT->AsString);
        SpisokEd->OpenSpisokEd();
		SpisokEd->NameNom=DM->DocTNAMENOM->AsString;
        }
}
//------------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::BitBtnAddSprBVNomClick(TObject *Sender)
{
if(CheckPrint==true) return;
if(Prosmotr==true) return;
if(CheckCreate==false) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaBVNomTouch();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn1Click(TObject *Sender)
{
UpdateForm();
UpdateSetup();
DM->NewDoc();

DM->DocAll->Edit();
DM->DocAllIDFIRMDOC->AsString=ARM->ElementIDFIRM_SARM->AsString;

__int64 id_sklad=glStrToInt64(ARM->GetParameter("ID_SKLAD_FOR_CHECK"));
if (id_sklad!=0)
	{
    DM->DocAllIDSKLDOC->AsString=id_sklad;
	}
else
	{
	DM->DocAllIDSKLDOC->AsString=ARM->ElementIDSKLAD_SARM->AsString;
	}

//if (DM->DocIDKLIENT_ZAK->AsInteger>0)
//        {
//        DM->DocAllIDKLDOC->AsInteger=DMKlient->ElementIDKLIENT->AsInteger;
//        }

DM->DocAll->Post();

DM->Doc->Edit();
DM->DocIDTPRICE->AsString=ARM->ElementIDTPRICEPOD->AsString;
DM->DocIDKKMCHK->AsString=ARM->ElementIDKKM_SARM->AsString;
DM->Doc->Post();
Prim->Caption="Открыт новый чек!";
CheckSave=false;
CheckPrint=false;
CheckCreate=true;

if (glStrToInt64(DM->DocIDDCARDCHK->AsString)!=0)
	{
	DMSprDiscountCard->OpenElement(glStrToInt64(DM->DocIDDCARDCHK->AsString));
	}
DMSprDiscountAuto->OpenTableDiscountAuto(glStrToInt64(ARM->ElementIDSKLAD_SARM->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn6Click(TObject *Sender)
{
DM->DocT->Next();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn7Click(TObject *Sender)
{
DM->DocT->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn3Click(TObject *Sender)
{
if(CheckPrint==true) return;
if(CheckCreate==false) return;
OpenFormSpiskaSprEd();
}

//-----------------------------------------------------------------------------
void TFormaDocCheckTouch::OpenPanelButton()
{
if(Prosmotr==true) return;
if (PanelButton==NULL)
        {
        PanelButton=new TFormaPanelButtonTouch(Application);
		if (!PanelButton) return;
		PanelButton->FOnCloseForm=EndEdit;
		PanelButton->ShowModal();
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::EndEdit(TObject *Sender)
{

        if (PanelButton->PressButton==PanelButton->DelButton)
                {
				DM->DeleteStringDoc();
				UpdateValuesDiscount();
				}
        PanelButton=0;

}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::BitBtn5Click(TObject *Sender)
{
OpenPanelButton();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocCheckTouch::BitBtnPodborClick(TObject *Sender)
{
if(CheckPrint==true) return;
if(Prosmotr==true) return;
if(CheckCreate==false) return;
ActionOperation=aoAddNewString;
OpenFormMnViborSpiskaSprBVNom();
}
//---------------------------------------------------------------------------
//***********************************************************************
//выбор дисконтной карты

void  TFormaDocCheckTouch::ViborDiscountCard(void)
{
if(Prosmotr==true) return;
if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
        Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=ViborCard;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::EndViborDiscountCard(void)
{


				AnsiString s=FloatToStr(Kalkulator->Result);
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
						GetProcentPoDiscountCard();
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


Kalkulator=0;

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::BitBtnInputDiscountCardClick(
	  TObject *Sender)
{
ViborDiscountCard();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::UpdateValuesDiscount(void)
{
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
void TFormaDocCheckTouch::GetProcentPoDiscountCard(void)
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
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprEdTouch.1",IID_IDMSprNakSkidok,
													(void**)&dm_snak_skidok);
		dm_snak_skidok->Init(InterfaceMainObject,InterfaceImpl);

		IDMGurOperDiscountCard * gur_oper;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard,
													(void**)&gur_oper);
		gur_oper->Init(InterfaceMainObject,InterfaceImpl);

		dm_snak_skidok->GetSpisokSkidok( glStrToInt64(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsString),
									 glStrToInt64(ARM->ElementIDSKLAD_SARM->AsString));

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

		dm_snak_skidok->kanRelease();
		gur_oper->kanRelease();
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
			NamePriceLabel->Caption=dm_spr_type_price->ElementNAME_TPRICE->AsString;
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
									DMSprPrice->FindElement(glStrToInt64(ARM->ElementIDTPRICEPOD->AsString),
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
void TFormaDocCheckTouch::GetProcentAuto(double sum_doc)
{
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
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom1",IID_IDMSprNom,
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
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom",IID_IDMSprNom,
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
				spr_nom->kanRelease();
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
//ввод кода быстрого вызова
void TFormaDocCheckTouch::OpenFormInputCodeNomBV(void)
{
if(Prosmotr==true) return;
if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
        Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=InputCodeBV;
		}


}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::EndInputCodeBV(void)
{

	int code_bv=StrToInt(Kalkulator->Result);
	//получим ID номенклатуры
	IDMSprBVNom * dm_bv;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
													(void**)&dm_bv);
		dm_bv->Init(InterfaceMainObject,InterfaceImpl);
	dm_bv->IdPod=glStrToInt64(ARM->ElementIDPODR_SARM->AsString);
	if (dm_bv->FindPoCoduBV(code_bv)>0)
		{
		Nom->OpenElement(dm_bv->IdNomBV);
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

				//получим цену
				IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOMCHKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDEDCHKT->AsString),         //единица
							DM->DocTKFCHKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();
				DM->DocT->Post();
				UpdateValuesDiscount();
		}
	else
		{
		 ShowMessage("Товар не найден!");
		}
    dm_bv->kanRelease();


Kalkulator=0;

}
//-----------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtnAddGoodsPoCoduClick(TObject *Sender)
{
OpenFormInputCodeNomBV();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn11Click(TObject *Sender)
{
if(CheckPrint==true) return;
if(CheckCreate==false) return;
if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=EditNal;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheckTouch::BitBtn14Click(TObject *Sender)
{
if(CheckPrint==true) return;
if(CheckCreate==false) return;
if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=EditOplataPC;
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocCheckTouch::BitBtn17Click(TObject *Sender)
{
DM->CloseDoc();
Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::InputSumOsnPlatCardBitBtnClick(TObject *Sender)
{
if(CheckPrint==true)
	{
	ShowMessage("Нельзя изменять напечатанный чек!");
	return;
	}

if(CheckCreate==false)
	{
	ShowMessage("Необходимо создать новый чек!");
	return;
	}

if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=ER_InputSumOsnPlatCard;
		}
}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndInputSumOsnPlatCard(void)
{

DM->Doc->Edit();
DM->DocOPLPLATCARD_DCHK->AsFloat=Kalkulator->Result;
DM->Doc->Post();

}

//---------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::InputSumOsnCreditCardBitBtnClick(TObject *Sender)

{
if(CheckPrint==true)
	{
	ShowMessage("Нельзя изменять напечатанный чек!");
	return;
	}

if(CheckCreate==false)
	{
	ShowMessage("Необходимо создать новый чек!");
	return;
	}


if (Kalkulator==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=ER_InputSumOsnCreditCard;
		}
}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndInputSumOsnCreditCard(void)
{
DM->Doc->Edit();
DM->DocOPLCREDITCARD_DCHK->AsFloat=Kalkulator->Result;
DM->Doc->Post();
}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndInputSumProchee(void)
{

}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndAddDopPlatCard(void)
{

}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndInputSumDopPlatCard(void)
{

}
//---------------------------------------------------------------------------
void TFormaDocCheckTouch::EndInputSumDopCreditCard(void)
{

}
//---------------------------------------------------------------------------

// ПЕЧАТЬ ЧЕКА
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheckTouch::PrintCheckBitBtnClick(TObject *Sender)
{
if(CheckCreate==false)
	{
	ShowMessage("Необходимо создать чек!");
	return;
	}

if (CheckOplataBeforePrintCheck()==false)
	{
	return;
	}

TextMessage="";

if (DM->SaveDoc()==true)
		{
		TextMessage=TextMessage+" Чек сохранен!";
		TypeEvent=1;
		CheckSave=true;
		CheckCreate=false;
		}
else
		{
		TextMessage=TextMessage+" Чек не сохранен!";
		}

if(CheckPrint==false)
		{
        CheckPrint=PrintCheck();
		}
else
        {
		TextMessage=TextMessage+" Данный чек уже напечатан!";
        }

if (CheckPrint==true)
	{
	TextMessage=TextMessage+" Чек напечатан!";
	}
else
	{
	TextMessage=TextMessage+" Не удалось напечатать чек!";
	}

DM->Doc->Edit();
DM->DocNCHECKCHK->AsInteger=glFR->NumberCheck;
DM->DocNKLCHK->AsInteger=glFR->NumberKL;
DM->Doc->Post();



if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				TextMessage=TextMessage+" Чек проведен!";
				}
		else
				{
				TextMessage=TextMessage+" Чек не проведен!";
				}
		}




Prim->Caption=TextMessage;
}
//---------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintCheck(void)
{
bool Res=false;
KolNoFiscalCheck=0;

if (ARM->GetParameter("PrintCheckPoFirm")==1)
	{
	__int64 id_firm_for_fiscal_check=glStrToInt64(ARM->GetParameter("IdFirmForFiscalCheck"));

	if (id_firm_for_fiscal_check==0)
		{
		Res=PrintPoFirmNoFiscalCheck(0);
		}
	else
		{
		if (ARM->GetParameter("PrintFiscalCheck")==1)
			{
			Res=PrintPoFirmFiscalCheck(id_firm_for_fiscal_check);
			PrintPoFirmNoFiscalCheck(id_firm_for_fiscal_check);
			}
		else
			{
			Res=PrintPoFirmNoFiscalCheck(0);
			}
		}
	}
else
	{
	if (ARM->GetParameter("PrintFiscalCheck")==1)
		{
		Res=PrintStandartFiscalCheck();
		}
	else
		{
		Res=PrintStandartNoFiscalCheck();
		}
	}

return Res;
}
//-----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintStandartFiscalCheck(void)
{
bool Res=true;

String StrPr="  ";
if (CheckPrint==true)
        {
		Res=true;
        return Res;
		}

try
	{

	if(glFR->OpenNoFiscalCheck()==false)
		{throw Exception(glFR->TextError);}

	if (ARM->GetParameter("STR_ZAG_1")!="")
        {
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_1"),1,0,0,true,true, false)==false)
					{throw Exception(glFR->TextError);}
		}

	if (ARM->GetParameter("STR_ZAG_2")!="")
        {
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_2"),1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
		}

	if (ARM->GetParameter("STR_ZAG_3")!="")
        {
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_3"),1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
        }


	if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintLine()==false)
		{throw Exception(glFR->TextError);}


	if (DM->DocPRIMCHK->AsString!="")
		{
		if(glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,true, false)==false)
			{throw Exception(glFR->TextError);}

		if(glFR->PrintLine()==false)
			{throw Exception(glFR->TextError);}
		}

	DM->DocT->First();
	while(!DM->DocT->Eof)
        {

		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,true, false)==false)
					{throw Exception(glFR->TextError);}

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

	if(glFR->PrintLine()==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}


	if(glFR->CloseNoFiscalCheck()==false)
		{throw Exception(glFR->TextError);}


		double SumCheck=DM->DocAllSUMDOC->AsFloat;
		double OplataNal=DM->DocNALCHK->AsFloat;
		double OplataPlatCard=DM->DocOPLPCCHK->AsFloat;

		if(glFR->PrintFiscalCheck(SumCheck,1,OplataNal,OplataPlatCard,0,0,DM->DocOPERCHK->AsInteger)==false)
		{throw Exception(glFR->TextError);}

	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	ShowMessage("Ошибка при печати чека: "+TextError);
	}

return Res;
}
//----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintStandartNoFiscalCheck(void)
{
bool Res=true;

String StrPr="  ";
if (CheckPrint==true)
		{
		Res=true;
		return Res;
		}

try
	{

	if(glFR->OpenNoFiscalCheck()==false)
		{throw Exception(glFR->TextError);}

	if (ARM->GetParameter("STR_ZAG_1")!="")
        {
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_1"),1,0,0,true,true, false)==false)
					{throw Exception(glFR->TextError);}
		}

	if (ARM->GetParameter("STR_ZAG_2")!="")
		{
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_2"),1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
		}

	if (ARM->GetParameter("STR_ZAG_3")!="")
		{
		if(glFR->PrintString(ARM->GetParameter("STR_ZAG_3"),1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
		}

IDMSprFirm * firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&firma);
firma->Init(InterfaceMainObject,0);
firma->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

	if(glFR->PrintString("ИНН "+firma->ElementINNFIRM->AsString,1,0,1,true,false, false)==false)
		{throw Exception(glFR->TextError);}

firma->kanRelease();

	if(glFR->PrintString(" Товарный чек ",1,0,1,true,false, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("№"+DM->DocAllNUMDOC->AsString+" от "+
								DateToStr(DM->DocAllPOSDOC->AsDateTime),1,0,1,true,false, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintLine()==false)
		{throw Exception(glFR->TextError);}

	if (DM->DocPRIMCHK->AsString!="")
		{
		if(glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,true, false)==false)
			{throw Exception(glFR->TextError);}
		if(glFR->PrintLine()==false)
			{throw Exception(glFR->TextError);}
		}

	DM->DocT->First();
	while(!DM->DocT->Eof)
        {

		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,true, false)==false)
			{throw Exception(glFR->TextError);}
		StrPr="";
		StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
				+DM->DocTNAMEED->AsString+" = "
				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);

		if(glFR->PrintString(StrPr,1,0,2,true,true, false)==false)
			{throw Exception(glFR->TextError);}

        DM->DocT->Next();
        }

	if(glFR->PrintLine()==false)
			{throw Exception(glFR->TextError);}



	if(glFR->PrintString("Всего: ",1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2),4,0,2,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString("Оплата: ",1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(FloatToStrF(DM->DocALLOPL->AsFloat,ffFixed,10,2),4,0,2,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString("Сдача: ",1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(FloatToStrF(DM->DocSDACHA_DCHK->AsFloat,ffFixed,10,2),4,0,2,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}


	if(glFR->PrintString("Подпись ______________",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->CloseNoFiscalCheck()==false)
		{throw Exception(glFR->TextError);}

	glFR->Cut(1);
	Res=true;
	}
catch(Exception &exception)
	{
	Res=false;
	TextError=exception.Message;
	ShowMessage("Ошибка при печати чека: "+TextError);
	}

return Res;
}
//-----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintPoFirmFiscalCheck(__int64 id_firm_for_fiscal_check)
{
bool result=false;
//получим чек с сортировкой по фирмам
UnicodeString zapros="select snom.krnamenom, sed.nameed,               \
		snom.idfirmnom,                                                \
		dchkt.kolchkt,                                                 \
		dchkt.kfchkt,                                                  \
		dchkt.pricechkt,                                               \
		dchkt.sumchkt,                                                 \
		dchkt.prskchkt,                                                \
		dchkt.skchkt                                                   \
from dchkt                                                             \
left outer join snom on dchkt.idnomchkt=snom.idnom                     \
left outer join sed on dchkt.idedchkt=sed.ided                         \
where dchkt.iddocchkt=:PARAM_IDDOC and snom.idfirmnom=:PARAM_IDFIRM";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=
												DM->DocAllIDDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=IntToStr(id_firm_for_fiscal_check);
DMQueryRead->pFIBQ->ExecQuery();

double sum=0;

try
	{
//печатаем заголовок
			if (DMQueryRead->pFIBQ->RecordCount > 0)
				{
				sum=0;
				if(glFR->OpenNoFiscalCheck()==false)
					{throw Exception(glFR->TextError);}

				if (ARM->GetParameter("STR_ZAG_1")!="")
					{
					if(glFR->PrintString(ARM->GetParameter("STR_ZAG_1"),1,0,0,true,true, false)==false)
						{throw Exception(glFR->TextError);}
					}

				if (ARM->GetParameter("STR_ZAG_2")!="")
					{
					if(glFR->PrintString(ARM->GetParameter("STR_ZAG_2"),1,0,0,true,true, false)==false)
						{throw Exception(glFR->TextError);}
					}

				if (ARM->GetParameter("STR_ZAG_3")!="")
					{
					if(glFR->PrintString(ARM->GetParameter("STR_ZAG_3"),1,0,0,true,true, false)==false)
						{throw Exception(glFR->TextError);}
					}


				if(glFR->PrintString(" ",1,0,0,true,false, false)==false)
					{throw Exception(glFR->TextError);}
				if(glFR->PrintLine()==false)
					{throw Exception(glFR->TextError);}

				if (DM->DocPRIMCHK->AsString!="")
					{
					if(glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,true, false)==false)
							{throw Exception(glFR->TextError);}
					if(glFR->PrintLine()==false)
							{throw Exception(glFR->TextError);}
					}

				}



	while(!DMQueryRead->pFIBQ->Eof)
		{
			UnicodeString StrPr="";
			StrPr=DMQueryRead->pFIBQ->FieldByName("KRNAMENOM")->AsString;
			if (glFR->PrintString(StrPr,1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
			StrPr="";
			StrPr=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("PRICECHKT")->AsFloat,ffFixed,15,2)
					+" x "+FloatToStr(DMQueryRead->pFIBQ->FieldByName("KOLCHKT")->AsFloat)+" "
					+DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString+" = "
					+FloatToStrF(DMQueryRead->pFIBQ->FieldByName("SUMCHKT")->AsFloat,ffFixed,15,2);

			if(glFR->PrintString(StrPr,1,0,2,true,true, false)==false)
				{throw Exception(glFR->TextError);}


			sum=sum+DMQueryRead->pFIBQ->FieldByName("SUMCHKT")->AsFloat;

		DMQueryRead->pFIBQ->Next();
		}


	//подвал чека
	if (DMQueryRead->pFIBQ->RecordCount > 0)
		{

		if(glFR->PrintLine()==false)
			{throw Exception(glFR->TextError);}

		if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,true, false)==false)
			{throw Exception(glFR->TextError);}

		if(glFR->CloseNoFiscalCheck()==false)
				{throw Exception(glFR->TextError);}

				double SumCheck=sum;
				double OplataNal=sum;
				double OplataPlatCard=0;

				if(glFR->PrintFiscalCheck(SumCheck,1,OplataNal,OplataPlatCard,0,0,DM->DocOPERCHK->AsInteger)==false)
					{throw Exception(glFR->TextError);}

		}

	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	ShowMessage("Ошибка при печати чека: "+TextError);
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
return result;
}
//----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintPoFirmNoFiscalCheck(__int64 id_firm_for_fiscal_check)
{
bool result;
//получим чек с сортировкой по фирмам
UnicodeString zapros="select snom.krnamenom, sed.nameed,               \
		snom.idfirmnom,                                                \
		dchkt.kolchkt,                                                 \
		dchkt.kfchkt,                                                  \
		dchkt.pricechkt,                                               \
		dchkt.sumchkt,                                                 \
		dchkt.prskchkt,                                                \
		dchkt.skchkt                                                   \
from dchkt                                                             \
left outer join snom on dchkt.idnomchkt=snom.idnom                     \
left outer join sed on dchkt.idedchkt=sed.ided                         \
where dchkt.iddocchkt=:PARAM_IDDOC   \
order by snom.idfirmnom";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=
												DM->DocAllIDDOC->AsString;
DMQueryRead->pFIBQ->ExecQuery();

double sum=0;
__int64 id_tec_firm=-1;
int kol_string=0;




try
	{

	while(!DMQueryRead->pFIBQ->Eof)
		{
		if (id_firm_for_fiscal_check>0)
			{//сравниваем только если задана фирма для печати фискального чека
			if (glStrToInt64(DMQueryRead->pFIBQ->FieldByName("idfirmnom")->AsString)
								==id_firm_for_fiscal_check)
				{
				DMQueryRead->pFIBQ->Next();
				continue;
				}
			}

		if (id_tec_firm!=glStrToInt64(DMQueryRead->pFIBQ->FieldByName("idfirmnom")->AsString))
			{ //новая фирма
			//закончим печать предыдущего чека
			if (kol_string>0)
				{
				if (PrintPoFirmNoFiscalCheck_Footer(id_tec_firm,sum)==false)
						 {throw Exception(TextError);}
				}

			sum=0;
			kol_string=0;
			id_tec_firm=glStrToInt64(DMQueryRead->pFIBQ->FieldByName("idfirmnom")->AsString);

			PrintPoFirmNoFiscalCheck_Header(id_tec_firm);
			}

			//эта же фирма
			//печатаем строку

		UnicodeString StrPr="";
		StrPr=DMQueryRead->pFIBQ->FieldByName("KRNAMENOM")->AsString;
		if (glFR->PrintString(StrPr,1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
		StrPr="";
		StrPr=FloatToStrF(DMQueryRead->pFIBQ->FieldByName("PRICECHKT")->AsFloat,ffFixed,15,2)
					+" x "+FloatToStr(DMQueryRead->pFIBQ->FieldByName("KOLCHKT")->AsFloat)+" "
					+DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString+" = "
					+FloatToStrF(DMQueryRead->pFIBQ->FieldByName("SUMCHKT")->AsFloat,ffFixed,15,2);

		if(glFR->PrintString(StrPr,1,0,2,true,true, false)==false)
				{throw Exception(glFR->TextError);}

		sum=sum+DMQueryRead->pFIBQ->FieldByName("SUMCHKT")->AsFloat;
		kol_string++;

		DMQueryRead->pFIBQ->Next();
		}


			//закончим печать предыдущего чека
			if (kol_string>0)
				{
				if(PrintPoFirmNoFiscalCheck_Footer(id_tec_firm,sum)==false)
						 {throw Exception(TextError);}
				}

	if (KolNoFiscalCheck > 0)
		{
		glFR->Cut(1);
		}

	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	ShowMessage("Ошибка при печати чека: "+TextError);
	}
DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();
return result;
}
//-----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintPoFirmNoFiscalCheck_Header(__int64 id_firm)
{
bool result=false;
KolNoFiscalCheck++;

IDMSprFirm * firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&firma);
firma->Init(InterfaceMainObject,0);
if (id_firm==0)
	{ //получим параметры фирмы по умолчанию
	__int64 id_default_firm=glStrToInt64(ARM->GetParameter("DefaultIdFirm"));
	if (id_default_firm!=0)
		{
		firma->OpenElement(id_default_firm);
		}
	}
else
	{
    firma->OpenElement(id_firm);
	}

try
	{
				if(glFR->OpenNoFiscalCheck()==false)
					{throw Exception(glFR->TextError);}


				if (firma->Element->RecordCount > 0)
					{
					if(glFR->PrintString(firma->ElementNAMEFIRM->AsString,1,0,1,true,true, false)==false)
						{throw Exception(glFR->TextError);}

					if(glFR->PrintString("ИНН "+firma->ElementINNFIRM->AsString,1,0,1,true,true, false)==false)
						{throw Exception(glFR->TextError);}

					if(glFR->PrintString("Адрес: "+firma->ElementPADRFIRM->AsString,1,0,1,true,true, true)==false)
						{throw Exception(glFR->TextError);}
					}

	if(glFR->PrintString(" Товарный чек ",1,0,1,true,false, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("№"+DM->DocAllNUMDOC->AsString+" от "+
								DateToStr(DM->DocAllPOSDOC->AsDateTime),1,0,1,true,false, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintLine()==false)
		{throw Exception(glFR->TextError);}

	if (DM->DocPRIMCHK->AsString!="")
		{
		if(glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,true, false)==false)
			{throw Exception(glFR->TextError);}
		if(glFR->PrintLine()==false)
			{throw Exception(glFR->TextError);}
		}

	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}

firma->kanRelease();
return result;
}
//----------------------------------------------------------------------------
bool TFormaDocCheckTouch::PrintPoFirmNoFiscalCheck_Footer(__int64 id_firm, double sum)
{
bool result=false;

try
	{
	if(glFR->PrintLine()==false)
					{throw Exception(glFR->TextError);}
	if(glFR->PrintString("Всего:",1,0,0,true,false, false)==false)
					{throw Exception(glFR->TextError);}
	if(glFR->PrintString(FloatToStrF(sum,ffFixed,10,2),4,0,2,true,false, false)==false)
					{throw Exception(glFR->TextError);}

	if(glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}


	if(glFR->PrintString("Подпись ______________",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString("",1,0,1,true,true, false)==false)
		{throw Exception(glFR->TextError);}

		if(glFR->CloseNoFiscalCheck()==false)
			{throw Exception(glFR->TextError);}


	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	}

return result;
}
//-----------------------------------------------------------------------------
bool TFormaDocCheckTouch::CheckOplataBeforePrintCheck(void)
{
bool result=true;     //true если можно продолжить

if (DM->DocSDACHA_DCHK->AsFloat < 0)
	{
	ShowMessage("Недостаточно оплаты!");
	result=false;
	}

if ((DM->DocOPLPCCHK->AsFloat+DM->DocOPLPLATCARD_ALL_DCHK->AsFloat+
							DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat) > DM->DocAllSUMDOC->AsFloat)
	{
	ShowMessage("Оплата картами не может быть больше суммы чека!!");
	result=false;
	}

if (glStrToInt64(DM->DocIDDCARDCHK->AsString)!=0)
	{
	if(glStrToInt64(DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString)==0)
		{
		DMSprDiscountCard->OpenElement(glStrToInt64(DM->DocIDDCARDCHK->AsString));
		}
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
bool TFormaDocCheckTouch::CheckSumPlatCard(void)
{
bool result=true;


if (DM->DocOPLPLATCARD_DCHK->AsFloat > 0 )
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
bool TFormaDocCheckTouch::CheckSumCreditCard(void)
{
bool result=true;

//проверим максимальную сумму кредита
if (DM->DocOPLCREDITCARD_DCHK->AsFloat >0 )
	{
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


void __fastcall TFormaDocCheckTouch::FormActivate(TObject *Sender)
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

void __fastcall TFormaDocCheckTouch::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaDocCheckTouch::ReadShtrihCodEvent(int number, UnicodeString sh)
{


	ObBar->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
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
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICECHKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				DM->DocTKOLCHKT->AsFloat=ObBar->Kol;

				DM->DocT->Post();
				//ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);

		if (cxPageControl1->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOLCHKT->Selected=true;
			cxGrid1DBTableView1KOLCHKT->Focused=true;
			}
		//дисплей
//		AnsiString string1=DM->DocTNAMENOM->AsString;
//		AnsiString string2="Цена:"+DM->DocTPRICECHKT->AsString
//											+"  ВСЕГО:"+DM->DocAllSUMDOC->AsString;
//		if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
//		if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
		}
	else
		{
		ShowMessage(ObBar->TextError);
		}


}
//---------------------------------------------------------------
