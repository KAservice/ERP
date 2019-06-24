//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UFormaZakazOf.h"
#include "IDMSprNom.h"
#include "IDMSprARM.h"

#include "IDMSprNomRest.h"

#include "IDMGurOperDiscountCard.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSprBVNom.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IDMDocSchet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBLabel"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"




//---------------------------------------------------------------------------
__fastcall TFormaZakazOf::TFormaZakazOf(TComponent* Owner)
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
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaZakazOf::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMRegZak.1",IID_IDMRegZak,
									 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
									 (void**)&DMKlient);
DMKlient->Init(InterfaceMainObject,InterfaceImpl);

NameObjectZak->DataSource=DM->DataSourceOb;
SumDoc->DataSource=DM->DataSourceDoc;
IDZakDBText->DataSource=DM->DataSourceDoc;
KrNameNomDBText->DataSource=DM->DataSourceDocT;
MPrigDBText->DataSource=DM->DataSourceDocT;
NameKlientDBText->DataSource=DM->DataSourceDoc;
NameUserDBText->DataSource=DM->DataSourceDoc;

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;

ActionOperation=aoNO;

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameDiscountCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NameTypePricecxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


LabelDescr->Caption="";


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


ObnovitForm();

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaZakazOf::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaZakazOf::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokBVTouch)SpisokBVTouch->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(Check)Check->kanRelease();
if(Kalkulator)Kalkulator->kanRelease();
if(DocReal)DocReal->kanRelease();

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

DM->kanRelease();
Nom->kanRelease();
Ed->kanRelease();
ObBar->kanRelease();
DMKlient->kanRelease();

DMSprDiscountCard->kanRelease();
//delete DMSprNakSkidok;
DMSprDiscountAuto->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int TFormaZakazOf::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==Edinica)
        {
		if (type_event==1)
                {
				DM->DocT->Edit();

                DM->DocTIDED_ZAKT->AsString=SpisokEd->ElIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->ElNAMEED->AsString;
                DM->DocTKF_ZAKT->AsFloat=SpisokEd->ElKFED->AsFloat;

				DM->DocTKOLZ_ZAKT->AsInteger=SpisokEd->Kol;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICE_ZAKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOM_ZAKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDED_ZAKT->AsString),         //единица
							DM->DocTKF_ZAKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();


				DM->DocT->Post();
				UpdateValuesDiscount();
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
			   DM->Doc->Edit();
			   DM->DocSOST_ZAK->AsInteger=1;
			   DM->Doc->Post();

				Nom->IdTypePrice=IdTypePrice;
				DM->IdTypePrice=IdTypePrice;
				Nom->OpenElement(SpisokBVTouch->IdNom);


				DM->DocT->Edit();
				DM->DocTIDNOM_ZAKT->AsString=VibTovarId=glStrToInt64(Nom->ElementIDNOM->AsString);
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
				DM->DocTKOLZ_ZAKT->AsInteger=1;

				DM->DocTIDED_ZAKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
				DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICE_ZAKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOM_ZAKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDED_ZAKT->AsString),         //единица
							DM->DocTKF_ZAKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();


				//получим место приготовления
				IDMSprNomRest * DMSprNomRest;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest,
													(void**)&DMSprNomRest);
				DMSprNomRest->Init(InterfaceMainObject,InterfaceImpl);
				DMSprNomRest->GetTekSostav(glStrToInt64(DM->DocTIDNOM_ZAKT->AsString), Now()) ;
				if ( glStrToInt64(DMSprNomRest->ElementIDMPRIG_NOMREST->AsString)!=0)
						{
						DM->DocTIDMPRIG_ZAKT->AsString=
										DMSprNomRest->ElementIDMPRIG_NOMREST->AsString;
						DM->DocTNAME_MPRIG->AsString=
										DMSprNomRest->ElementNAME_MPRIG->AsString;
						}
				DMSprNomRest->kanRelease();

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
               DM->Doc->Edit();
               DM->DocSOST_ZAK->AsInteger=1;
               DM->Doc->Post();

				Nom->IdTypePrice=IdTypePrice;
                DM->IdTypePrice=IdTypePrice;
                Nom->OpenElement(SpisokBVTouch->IdNom);

                DM->DocT->Edit();
				DM->DocTIDNOM_ZAKT->AsString=VibTovarId=glStrToInt64(Nom->ElementIDNOM->AsString);
                DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
                DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

                DM->DocTKOLZ_ZAKT->AsInteger=SpisokBVTouch->Kol;

				DM->DocTIDED_ZAKT->AsString=SpisokBVTouch->IdEd;
                DM->DocTNAMEED->AsString=SpisokBVTouch->NameEd;
                DM->DocTKF_ZAKT->AsFloat=SpisokBVTouch->KFEd;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICE_ZAKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOM_ZAKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDED_ZAKT->AsString),         //единица
							DM->DocTKF_ZAKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();

                //получим место приготовления
				IDMSprNomRest * DMSprNomRest;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest,
													(void**)&DMSprNomRest);
				DMSprNomRest->Init(InterfaceMainObject,InterfaceImpl);
				DMSprNomRest->GetTekSostav(glStrToInt64(DM->DocTIDNOM_ZAKT->AsString), Now()) ;
				if ( glStrToInt64(DMSprNomRest->ElementIDMPRIG_NOMREST->AsString)!=0)
                        {
						DM->DocTIDMPRIG_ZAKT->AsString=
                                        DMSprNomRest->ElementIDMPRIG_NOMREST->AsString;
                        DM->DocTNAME_MPRIG->AsString=
                                        DMSprNomRest->ElementNAME_MPRIG->AsString;
                        }
                DMSprNomRest->kanRelease();

                DM->DocT->Post();

                }
        else
                {
				EditRekvisit=NO;
				ActionOperation=aoNO;
				SpisokBVTouch=0;
                }
        }

if (number_procedure_end==ZakazKol)
        {
		if (type_event==1)
               {
                DM->DocT->Edit();
                DM->DocTKOLZ_ZAKT->AsFloat=Kalkulator->Result;
				DM->DocT->Post();
				UpdateValuesDiscount();
				}
		Kalkulator=0;
        }

if (number_procedure_end==OtpKol)
        {
		if (type_event==1)
               {
				DM->DocT->Edit();
                DM->DocTKOLOT_ZAKT->AsFloat=Kalkulator->Result;
				DM->DocT->Post();
				UpdateValuesDiscount();
				}
		Kalkulator=0;
        }

if (number_procedure_end==EditCheck)
        {

			   if (type_event==1)
                        {
                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=2;
                        DM->Doc->Post();
                        DM->SaveDoc();
						ObnovitForm();
                        Prosmotr=true;
                        }

		Check=0;
        }

if (number_procedure_end==CreateRealRest)
        {
		if (type_event==1)
               {

                        DM->Doc->Edit();
                        DM->DocSOST_ZAK->AsInteger=2;
                        DM->Doc->Post();
                        DM->SaveDoc();
                        ObnovitForm();
                        Prosmotr=true;

				}
		DocReal=0;
        }

if (number_procedure_end==ViborCard)
		{
		if (type_event==1)
			   {
			   EndViborDiscountCard();
			   }
		Kalkulator=0;
		}

if (number_procedure_end==InputCodeBV)
		{
		if (type_event==1)
			   {
			   EndInputCodeBV();
			   }
		Kalkulator=0;
		}

if (number_procedure_end==ViborKlient)
        {
		if (type_event==1)
               {
			   if (DMKlient->OpenElement((__int64)(Kalkulator->Result))>0)
                        {
                        DM->Doc->Edit();
                        DM->DocIDKLIENT_ZAK->AsString=DMKlient->ElementIDKLIENT->AsString;
                        DM->DocNAMEKLIENT->AsString=DMKlient->ElementNAMEKLIENT->AsString;
                        DM->Doc->Post();
						}
			   else
					{
					ShowMessage("Не найден клиент с кодом "+FloatToStr(Kalkulator->Result));
					}
				}
		Kalkulator=0;
		}

if (number_procedure_end==OtkazKol)
        {
		if (type_event==1)
               {
               if (DM->DocTKOLZ_ZAKT->AsFloat-DM->DocTOTKAZ_ZAKT->AsFloat<=Kalkulator->Result)  //отменяем все количество
                        {
                        if (DM->DocTKOLPR_ZAKT->AsFloat==0 &&
                                                DM->DocTOTKAZ_ZAKT->AsFloat==0 &&
                                                DM->DocSOST_ZAK->AsInteger!=3)
                                {  //если не печатана то строку удаляем
                                DM->DeleteStringDoc();
                                }
                        else
                                {   //если печатана то оказ равен заказу
                                DM->DocT->Edit();
                                DM->DocTOTKAZ_ZAKT->AsFloat=DM->DocTKOLZ_ZAKT->AsFloat;
                                DM->DocT->Post();
                                }
                        }
                else
                        {

                        if (DM->DocTKOLPR_ZAKT->AsFloat==0 &&
                                                DM->DocTOTKAZ_ZAKT->AsFloat==0 &&
                                                DM->DocSOST_ZAK->AsInteger!=3)
                                {  //если не печатана то можно росто исправить заказ
                                DM->DocT->Edit();
								DM->DocTKOLZ_ZAKT->AsFloat=DM->DocTKOLZ_ZAKT->AsFloat-Kalkulator->Result;
                                DM->DocT->Post();
                                }
                        else
                                {   //если печатана то оказ
                                DM->DocT->Edit();
                                DM->DocTOTKAZ_ZAKT->AsFloat=DM->DocTOTKAZ_ZAKT->AsFloat
                                                                +Kalkulator->Result;
                                DM->DocT->Post();
                                }
						}
				UpdateValuesDiscount();
				//добавим в log
				DM_Connection->AddLog(glStrToInt64(DM_Connection->UserInfoID_USER->AsString),
					2,
					2,
					3,
					"Отказ в заказе ID-"+DM->DocID_ZAK->AsString+" Номенклатура:"+DM->DocTNAMENOM->AsString+
									"Кол. отказа:"+Kalkulator->Result,
					"REG_ZAK",
					glStrToInt64(DM->DocID_ZAK->AsString),
					0);

				//type
				//1 сообщение
				//2 предупреждение
				//3 ошибка
				//4 запрещенное действие
				//object
				//1 справочник
				//2 документ
				//3 журнал
				//4 отчет
				//5 сервис
				//oper
				//  1 вставка
				//  2 редактирование
				//  3 удаление
				}
		Kalkulator=0;
        }


if (number_procedure_end!=MnViborNom)
        {
		EditRekvisit=NO;
		ActionOperation=aoNO;
		UpdateValuesDiscount();
		}

return -1;
}
//--------------------------------------------------------------------------
void TFormaZakazOf::ObnovitForm(void)
{
if (DM->DocSOST_ZAK->AsInteger==0){SostZakaz->Caption="Открыт";}
if (DM->DocSOST_ZAK->AsInteger==1){SostZakaz->Caption="Принят";}
if (DM->DocSOST_ZAK->AsInteger==3){SostZakaz->Caption="Счет";}
if (DM->DocSOST_ZAK->AsInteger==2){SostZakaz->Caption="Оплачен";Prosmotr=true;}

NameObjectZak->Caption=NameObjectZakaza;

UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::UpdateForm(void)
{
Prosmotr=false;

if (DM_Connection->UserInfoID_USER->AsString!=DM->DocIDUSER_ZAK->AsString)
	{
	Prosmotr=true;
	if (DM_Connection->UserInfoEDIT_CHUG_DOC_SUSER->AsInteger==1)
		{
        Prosmotr=false;
		}
	}

if (DM->DocSOST_ZAK->AsInteger ==2) //оплачен   по любому только просмотр
	{
	Prosmotr==true;
	}

if (DM_Connection->UserInfoNAME_USER->AsString == "SYSDBA")
	{
    Prosmotr=false;
	}

if(Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
        }
UpdateSetup();

}
//---------------------------------------------------------------------------
void TFormaZakazOf::UpdateSetup(void)
{

IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
//NamePriceLabel->Caption="Тип цен:"+glARM->ElementNAME_TPRICE->AsString;

}
//---------------------------------------------------------------------------
void TFormaZakazOf::OpenZakaz(void)
{

if (glStrToInt64(DM->DocIDDISCOUNTCARD_ZAK->AsString)!=0)
	{
	DMSprDiscountCard->OpenElement(glStrToInt64(DM->DocIDDISCOUNTCARD_ZAK->AsString));
//	DMSprNakSkidok->OpenTableNakSkidok(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsInteger,
//									   glARM->ElementIDSKLAD_SARM->AsInteger);
	}
DMSprDiscountAuto->OpenTableDiscountAuto(glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString));

}
//-----------------------------------------------------------------------------
//******************************************************************************
//-----------------------------------------------------------------------------
void __fastcall TFormaZakazOf::ButtonCloseClick(TObject *Sender)
{
DM->CloseDoc();
Close();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::OpenFormSpiskaBVNomTouch(void)
{
if(Prosmotr==true) return;

if (SpisokBVTouch==NULL)
        {
        UpdateSetup();
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprBVNomTouch.1",IID_IFormaSpiskaSprBVNomTouch,
									 (void**)&SpisokBVTouch);
		SpisokBVTouch->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBVTouch->Vibor=true;
		SpisokBVTouch->NumberProcVibor=EditNomBVTouch;
		}
}
//-------------------------------------------------------------------------
void TFormaZakazOf::OpenFormMnViborSpiskaSprBVNom(void)
{
if(Prosmotr==true) return;

if (SpisokBVTouch==NULL)
        {
        UpdateSetup();
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprBVNomTouch.1",IID_IFormaSpiskaSprBVNomTouch,
									 (void**)&SpisokBVTouch);
		SpisokBVTouch->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBVTouch->MnVibor=true;
		SpisokBVTouch->Vibor=true;
		SpisokBVTouch->NumberProcVibor=MnViborNom;
		}
}

//--------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnCloseClick(TObject *Sender)
{
String V="Сохранить изменения в заказе ?";
String Z="Сохранить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
        {

        if(Prosmotr==true)
                {
                V="Нельзя сохранить изменения в заказе! Заказ открыт только для просмотра!";
                Z="Сохранить?";
                Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
                Close();
                }
        else
                {
                if (DM->SaveDoc()==true)
                        {
                        Close();
                        }
                }

        }
else
        {
        DM->CloseDoc();
        Close();
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnNewStringClick(TObject *Sender)
{

if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaBVNomTouch();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnOKClick(TObject *Sender)
{
if(Prosmotr==true)
        {
        Close();
        }
else
        {
        if (DM->SaveDoc()==true)
                {
                Close();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnSaveClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->SaveDoc();
ObnovitForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtn1Click(TObject *Sender)
{
DM->DocT->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtn2Click(TObject *Sender)
{
DM->DocT->Next();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnDeletestringClick(TObject *Sender)
{
String St="";
if(Prosmotr==true) return;
if (Kalkulator==NULL)
        {
        InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=OtkazKol;
        }


}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnEditEdClick(TObject *Sender)
{

if(Prosmotr==true) return;
if (DM->DocTKOLPR_ZAKT->AsFloat>0) return;
if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprEdTouch.1",IID_IFormaSpiskaSprEdTouch,
									 (void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->Vibor=true;
		SpisokEd->NumberProcVibor=Edinica;
		SpisokEd->IdNom=glStrToInt64(DM->DocTIDNOM_ZAKT->AsString);
        SpisokEd->OpenSpisokEd();
		SpisokEd->NameNom=DM->DocTNAMENOM->AsString;

        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnEditKolZakClick(TObject *Sender)
{

if(Prosmotr==true) return;
if (DM->DocTKOLPR_ZAKT->AsFloat>0) return;
if (Kalkulator==NULL)
        {
        InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=ZakazKol;
        EditRekvisit=ZakazKol;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnEditKolOtpClick(TObject *Sender)
{

if(Prosmotr==true) return;
if (Kalkulator==NULL)
        {
        InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=OtpKol;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnOtpAllClick(TObject *Sender)
{

if(Prosmotr==true) return;
DM->DocT->First();

while (!DM->DocT->Eof)
        {
        DM->DocT->Edit();
        DM->DocTKOLOT_ZAKT->AsFloat=DM->DocTKOLZ_ZAKT->AsFloat
                                        -DM->DocTOTKAZ_ZAKT->AsFloat;
        DM->DocT->Post();
        DM->DocT->Next();
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnCreateCheckClick(TObject *Sender)
{

if(Prosmotr==true) return;
DM->SaveDoc();
CreateCheckKKM();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::CreateCheckKKM()
{
if(Prosmotr==true) return;
if (Check==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheckTouch.1",IID_IFormaDocCheckTouch,
									 (void**)&Check);
		Check->Init(InterfaceMainObject,InterfaceImpl);
		Check->Vibor=true;
		 Check->NumberProcVibor=EditCheck;
        //заполним параметы чека
        Check->DM->NewDoc();
		Check->DM->DocAll->Edit();
		if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
			{
			Check->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
			{
			Check->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			Check->DM->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
            }
		if (glStrToInt64(DM->DocIDKLIENT_ZAK->AsString)>0)
                {
				Check->DM->DocAllIDKLDOC->AsString=DM->DocIDKLIENT_ZAK->AsString;
				Check->DM->DocAllNAMEKLIENT->AsString=DM->DocNAMEKLIENT->AsString;
                }

        Check->DM->DocAll->Post();

  //      Check->NameFirm->Caption=KKM->FirmaNAMEFIRM->AsString;
  //      Check->NameKKM->Caption=KKM->ElementNAMEKKM->AsString;
  //      Check->NameSklad->Caption=KKM->SkladNAMESKLAD->AsString;
  //      Check->NameKlient->Caption="";
//        Check->NameDoc->Caption="Чек ККМ №"+Check->DM->DocAllNUMDOC->AsString
//                +" от " +Check->DM->DocAllPOSDOC->AsString;

        Check->DM->Doc->Edit();
		if(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString)!=0)
			{
			Check->DM->DocIDTPRICE->AsString=DM->DocIDTYPEPRICE_ZAK->AsString;
			}
		Check->DM->DocIDKKMCHK->AsString=DM_Connection->ARMInfoIDKKM_SARM->AsString;
        Check->DM->DocPRIMCHK->AsString="Заказ №"+DM->DocID_ZAK->AsString+" "+DM->ObNAME_STROB->AsString;
		if(glStrToInt64(DM->DocIDDISCOUNTCARD_ZAK->AsString)!=0)
			{
			Check->DM->DocIDDCARDCHK->AsString=DM->DocIDDISCOUNTCARD_ZAK->AsString;
			Check->DM->DocNAME_SDISCOUNT_CARD->AsString=DM->DocNAME_SDISCOUNT_CARD->AsString;
			}


		Check->DM->Doc->Post();

//        Check->Prim->Caption=Check->DM->DocPRIMCHK->AsString;


        DM->DocT->First();

        while(!DM->DocT->Eof)
                {
                Check->DM->AddDocNewString();
                Check->DM->DocT->Edit();
				Check->DM->DocTIDNOMCHKT->AsString=DM->DocTIDNOM_ZAKT->AsString;
                Check->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
                Check->DM->DocTKRNAMENOM->AsString=DM->DocTKRNAMENOM->AsString;
				Check->DM->DocTIDEDCHKT->AsString=DM->DocTIDED_ZAKT->AsString;
                Check->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
                Check->DM->DocTKOLCHKT->AsFloat=DM->DocTKOLOT_ZAKT->AsFloat;
                Check->DM->DocTKFCHKT->AsFloat=DM->DocTKF_ZAKT->AsFloat;
				Check->DM->DocTPRICECHKT->AsFloat=DM->DocTPRICE_ZAKT->AsFloat;
				Check->DM->DocTPRSKCHKT->AsFloat=DM->DocTPRSK_ZAKT->AsFloat;
                Check->DM->DocTSKCHKT->AsFloat=DM->DocTSUMSK_ZAKT->AsFloat;
                Check->DM->DocT->Post();
                DM->DocT->Next();
                }

       //  Check->SumCheck->Caption="Сумма: "+Check->DM->DocAllSUMDOC->AsString;
       //  Check->Nal->Caption="Наличные: "+Check->DM->DocNALCHK->AsString;
        // Check->OplataPC->Caption="Оплата плат. картой: "+Check->DM->DocOPLPCCHK->AsString;
        // Check->Sdacha->Caption="Сдача: "+Check->DM->DocSDACHA->AsString;
		Check->IdARM=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
        Check->CheckCreate=true;
		Check->UpdateForm();
        }



}
//---------------------------------------------------------------------------
void __fastcall TFormaZakazOf::BitBtnDelZakClick(TObject *Sender)
{
bool RasrDel=false;
String V;
String Z;
if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=glStrToInt64(DM->DocIDUSER_ZAK->AsString))
        {
        V="Нельзя удалять чужие заказы!";
        Z="Удалить?";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        RasrDel=false;
        }
else
        {
        RasrDel=true;
        }

if (DM->DocSOST_ZAK->AsInteger!=2)
        {
        V="Нельзя удалять неоплаченные заказы!";
        Z="Удалить?";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        RasrDel=false;
        }

//но администратору разрешим
if ((DM_Connection->UserInfoNAME2_USER->AsString=="SYSDBA"))
		{

		if (DM->DocSOST_ZAK->AsInteger==2)   //оплачен
			{
			V="Удалить заказ?";
			Z="Удалить?";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
					{
					RasrDel=true;
					}
			}
		else
			{
			V="Удалить неоплаченный заказ?";
			Z="Удалить?";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
					{
					RasrDel=true;
					}
			}
        }

if (RasrDel==true)
        {
        DM->DeleteDoc(glStrToInt64(DM->DocID_ZAK->AsString));
        }
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnPrintNaKuhClick(TObject *Sender)
{

if(Prosmotr==true) return;
DM->SaveDoc();
PrintZakaz();
}
//---------------------------------------------------------------------------


void __fastcall TFormaZakazOf::BitBtnPodbopClick(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormMnViborSpiskaSprBVNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtnPrintSchetClick(TObject *Sender)
{
CreateDocSchet();
if (PrintSchet()==true)
        {
        DM->Doc->Edit();
        DM->DocSOST_ZAK->AsInteger=3;
        DM->Doc->Post();
        DM->SaveDoc();
        ObnovitForm();
        
        }
else
        {
        String V="Не удалось напечатать счет!";
        String Z="Ошибка!";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        }
}
//---------------------------------------------------------------------------
bool TFormaZakazOf::PrintSchet(void)
{
bool result=false;
if(glFR->ConnectFR==false) return result;
if (glFR==0)
	{
	 ShowMessage("ФР не подключен!");
	 return result;
	}
String StrPr="";
try
	{
	if (glFR->OpenNoFiscalCheck()==false)
		{
		throw Exception(glFR->TextError);
		}

	if (DM_Connection->Arm_GetParameter("STR_ZAG_1")!="")
        {
		if(glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_1"),1,0,1,true,true, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DM_Connection->Arm_GetParameter("STR_ZAG_2")!="")
        {
		if(glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_2"),1,0,1,true,true, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if (DM_Connection->Arm_GetParameter("STR_ZAG_3")!="")
        {
		if(glFR->PrintString(DM_Connection->Arm_GetParameter("STR_ZAG_3"),1,0,1,true,true, false)==false)
			{
			throw Exception(glFR->TextError);
			}
        }

	if(glFR->PrintString(" ",1,0,1,true,true, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	StrPr="  СЧЕТ №"+DM->DocID_ZAK->AsString;
	if(glFR->PrintString(StrPr,3,0,1,true,true, false)==false)
		{
		throw Exception(glFR->TextError);
		}


	if(glFR->PrintString(" ",1,0,0,true,true, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if(glFR->PrintString(DM->DocNAME_STROB->AsString,1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(DateTimeToStr(Now()),1,0,0,true,true, false)==false)
		{
		throw Exception(glFR->TextError);
		}
	if(glFR->PrintLine()==false)
		{
		throw Exception(glFR->TextError);
		}

	DM->DocT->First();
	while(!DM->DocT->Eof)
        {
        if(DM->DocTKOLOT_ZAKT->AsFloat!=0)
				{ //печаем только не нулевые строки

				if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==false)
					{
					throw Exception(glFR->TextError);
					}

				if (DM->DocTSUMSK_ZAKT->AsFloat>0)
					{  //со скидкой
					StrPr="";
					StrPr=FloatToStrF(DM->DocTPRICE_ZAKT->AsFloat,ffFixed,15,2)
							+" x "+FloatToStr(DM->DocTKOLOT_ZAKT->AsFloat)+" "
							+DM->DocTNAMEED->AsString+" = "
							+FloatToStrF(DM->DocTPRICE_ZAKT->AsFloat*DM->DocTKOLOT_ZAKT->AsFloat,ffFixed,15,2);
					if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(glFR->TextError);
						}

					StrPr="-"+FloatToStr(DM->DocTPRSK_ZAKT->AsFloat)+" % "
						+FloatToStrF(DM->DocTSUMSK_ZAKT->AsFloat,ffFixed,15,2)+
						" = "+FloatToStrF(DM->DocTSUM_ZAKT->AsFloat,ffFixed,15,2);

					if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(glFR->TextError);
						}
					}
				else
					{//без скидки

					StrPr="";
					StrPr=FloatToStrF(DM->DocTPRICE_ZAKT->AsFloat,ffFixed,15,2)
						+" x "+FloatToStr(DM->DocTKOLOT_ZAKT->AsFloat)+" "
						+DM->DocTNAMEED->AsString+" = "
						+FloatToStrF(DM->DocTSUM_ZAKT->AsFloat,ffFixed,15,2);

					if(glFR->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(glFR->TextError);
						}
					}


                }
        DM->DocT->Next();
        }

	if(glFR->PrintLine()==false)
		{throw Exception(glFR->TextError);}
	if(glFR->PrintString(" ",1,0,0,true,true, false)==false)
		{throw Exception(glFR->TextError);}

	StrPr="Всего: ";

	if(glFR->PrintString(StrPr,1,0,0,true,true, false)==false)
	{throw Exception(glFR->TextError);}

	StrPr=FloatToStrF(DM->DocSUM_ZAK->AsFloat,ffFixed,10,2);

	if(glFR->PrintString(StrPr,3,0,2,true,true, false)==false)
	{throw Exception(glFR->TextError);}


	if(glFR->PrintString(" ",1,0,0,true,true, false)==false)
	{throw Exception(glFR->TextError);}
	if(glFR->PrintString(" ",1,0,0,true,true, false)==false)
	{throw Exception(glFR->TextError);}
	StrPr=DM_Connection->UserInfoFNAME_USER->AsString;
	if(glFR->PrintString(StrPr,1,0,2,true,true, false)==false)
	{throw Exception(glFR->TextError);}

	for(int i=0;i<7;i++)
        {
        if(glFR->PrintString(" ",1,0,0,true,true, false)==false)
				{throw Exception(glFR->TextError);}
		}
		
	if(glFR->CloseNoFiscalCheck()==false)
		{throw Exception(glFR->TextError);}

	if (glFR->Cut(1)==false)
		{throw Exception(glFR->TextError);}
	result=true;
	}
catch(Exception &exception)
	{
	result=false;
	TextError=exception.Message;
	ShowMessage("Ошибка при печати счета: "+TextError);
	}


return result;



}
//----------------------------------------------------------------------------
void __fastcall TFormaZakazOf::BitBtnNewDocRealClick(TObject *Sender)
{
if(Prosmotr==true) return;
CreateDocRealRest();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::CreateDocRealRest(void)
{
if(Prosmotr==true) return;
if (DocReal==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRoznTouch.1",IID_IFormaDocRealRoznTouch,
									 (void**)&DocReal);
		DocReal->Init(InterfaceMainObject,InterfaceImpl);
		DocReal->NumberProcVibor=CreateRealRest;
        //заполним параметы чека
        DocReal->DM->NewDoc();
		DocReal->DM->DocAll->Edit();
		if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
			{
			DocReal->DM->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
			{
			DocReal->DM->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
			DocReal->DM->DocAllNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			DocReal->DM->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
			DocReal->DM->DocAllNAMESKLAD->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
			}
		if (glStrToInt64(DM->DocIDKLIENT_ZAK->AsString)!=0)
			{
			DocReal->DM->DocAllIDKLDOC->AsString=DM->DocIDKLIENT_ZAK->AsString;
			DocReal->DM->DocAllNAMEKLIENT->AsString=DM->DocNAMEKLIENT->AsString;
			}

		if (glStrToInt64(DM->DocIDUSER_ZAK->AsString)!=0)
			{
			DocReal->DM->DocAllIDUSERDOC->AsString=DM->DocIDUSER_ZAK->AsString;
            DocReal->DM->DocAllFNAME_USER->AsString=DM->DocNAME_USER->AsString;
			}

        DocReal->DM->DocAll->Post();

		DocReal->DM->Doc->Edit();
		if (glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString)!=0)
			{
			DocReal->DM->DocIDTPRICE_DREALROZN->AsString=DM->DocIDTYPEPRICE_ZAK->AsString;
			}
		DocReal->DM->DocPRIM_DREALROZN->AsString="Заказ №"+DM->DocID_ZAK->AsString+" "+DM->ObNAME_STROB->AsString;

        DocReal->DM->Doc->Post();

        DM->DocT->First();

        while(!DM->DocT->Eof)
                {
                DocReal->DM->AddDocNewString();
                DocReal->DM->DocT->Edit();
				DocReal->DM->DocTIDNOM_DREALROZNT->AsString=DM->DocTIDNOM_ZAKT->AsString;
                DocReal->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
				DocReal->DM->DocTIDED_DREALROZNT->AsString=DM->DocTIDED_ZAKT->AsString;
                DocReal->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
				DocReal->DM->DocTKOL_DREALROZNT->AsFloat=DM->DocTKOLOT_ZAKT->AsFloat;
				DocReal->DM->DocTKF_DREALROZNT->AsFloat=DM->DocTKF_ZAKT->AsFloat;
				DocReal->DM->DocTPRICE_DREALROZNT->AsFloat=DM->DocTPRICE_ZAKT->AsFloat;
				DocReal->DM->DocTPRSK_DREALROZNT->AsFloat=DM->DocTPRSK_ZAKT->AsFloat;
				DocReal->DM->DocTSUMSK_DREALROZNT->AsFloat=DM->DocTSUMSK_ZAKT->AsFloat;
                DocReal->DM->DocT->Post();
                DM->DocT->Next();
                }


				DocReal->NameFirm="Фирма: "+DM_Connection->ARMInfoNAMEFIRM->AsString;
				DocReal->NameSklad="Склад: "+DM_Connection->ARMInfoNAMESKLAD->AsString;
				DocReal->NameKlient="Контрагент: "+DM->DocNAMEKLIENT->AsString;
				DocReal->NameDoc="Акт реализации №"+DocReal->DM->DocAllNUMDOC->AsString+" от "+DocReal->DM->DocAllPOSDOC->AsString;
				DocReal->Prim="Заказ на объекте "+DM->ObNAME_STROB->AsString;
		DocReal->UpdateForm();
        }

}
//----------------------------------------------------------------------------
void __fastcall TFormaZakazOf::BitBtnViborKlientClick(TObject *Sender)
{
VibratKlienta();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::VibratKlienta(void)
{
if(Prosmotr==true) return;
if (Kalkulator==NULL)
        {
        InterfaceGlobalCom->kanCreateObject("Oberon.Kalkulator.1",IID_IKalkulator,
									 (void**)&Kalkulator);
		Kalkulator->Init(InterfaceMainObject,InterfaceImpl);
		Kalkulator->Vibor=true;
		Kalkulator->NumberProcVibor=ViborKlient;
		}
}
//---------------------------------------------------------------------------
bool TFormaZakazOf::PrintZakaz(void)
{
bool result=false;
if (FormaPrintZakaz) return result;


AnsiString ip=DM_Connection->Arm_GetParameter("PrintServerIp");
if (ip=="")
        {
        ShowMessage("Не задан IP адрес сервера печати!");
        return result;
        }
AnsiString port=DM_Connection->Arm_GetParameter("PrintServerPort");
if (port=="")
        {
        ShowMessage("Не задан порт для обмена с сервером печати!");
        return result;
        }

FormaPrintZakaz=new TFormaPrintZakaz(Application);
if (!FormaPrintZakaz) return result;
FormaPrintZakaz->IP=ip;
FormaPrintZakaz->Port=StrToInt(port);
FormaPrintZakaz->IdZakaz=glStrToInt64(DM->DocID_ZAK->AsString);
FormaPrintZakaz->EventEndPrint=EndPrintZakaz;
FormaPrintZakaz->UpdateForm();
FormaPrintZakaz->Show();
FormaPrintZakaz->PrintZakaz();
return result;
}
//--------------------------------------------------------------------------
void __fastcall TFormaZakazOf::EndPrintZakaz(TObject *Sender)
{
if(FormaPrintZakaz->Error==true)
        {
        ShowMessage("Ошибка печати: "+FormaPrintZakaz->TextError);
        }
FormaPrintZakaz->Close();
FormaPrintZakaz=0;
IdDoc=glStrToInt64(DM->DocID_ZAK->AsString);
DM->OpenDoc(IdDoc);
}
//----------------------------------------------------------------------
//***********************************************************************
//выбор дисконтной карты

void  TFormaZakazOf::ViborDiscountCard(void)
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
void __fastcall TFormaZakazOf::EndViborDiscountCard(void)
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
						DM->DocIDDISCOUNTCARD_ZAK->AsString=DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString;
                        DM->DocNAME_SDISCOUNT_CARD->AsString=DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;
						DM->DocIDKLIENT_ZAK->AsString=DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString;
						DM->DocNAMEKLIENT->AsString=DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						DM->Doc->Post();
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



}
//----------------------------------------------------------------------------
void __fastcall TFormaZakazOf::BitBtnInputDiscountCardClick(TObject *Sender)
{
ViborDiscountCard();
}
//---------------------------------------------------------------------------
void TFormaZakazOf::UpdateValuesDiscount(void)
{
DM->DataSourceDocT->Enabled=false;
TBookmark BM;
double summa_doc=0;
BM=DM->DocT->GetBookmark();

DM->DocT->First();
while (!DM->DocT->Eof)
		{
		summa_doc=summa_doc+DM->DocTPRICE_ZAKT->AsFloat*DM->DocTKOLOT_ZAKT->AsFloat;
		DM->DocT->Next();
		}

GetProcentPoDiscountCard();
GetProcentAuto(summa_doc);

//расставляем проценты скидок
DM->DocT->First();
while (!DM->DocT->Eof)
		{
		if (DM->DocTPRSK_CARD_RGZAKT->AsFloat>DM->DocTPRSK_AUTO_RGZAKT->AsFloat)
			{
			DM->DocT->Edit();
			DM->DocTPRSK_ZAKT->AsFloat=DM->DocTPRSK_CARD_RGZAKT->AsFloat;
			DM->DocT->Post();
			}
		else
			{
			DM->DocT->Edit();
			DM->DocTPRSK_ZAKT->AsFloat=DM->DocTPRSK_AUTO_RGZAKT->AsFloat;
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
void TFormaZakazOf::GetProcentPoDiscountCard(void)
{
//*****************************************************************************
//карта не задана или не активна, просто обнулим процент скидки по карте
if (DMSprDiscountCard->Element->Active==false ||
			glStrToInt64(DM->DocIDDISCOUNTCARD_ZAK->AsString)==0)
	{
	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_RGZAKT->AsFloat=0;
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
		DM->DocTPRSK_CARD_RGZAKT->AsFloat=DMSprDiscountCard->ElementPRSK_SDISCOUNT_CARD->AsFloat;
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
									 glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString));

		AnsiString text_descr="";
		
		while(!dm_snak_skidok->Query->Eof)
			{
			int kol_day=dm_snak_skidok->Query->FieldByName("PERIOD_SNAK_SKIDOK")->AsInteger;
			//получим сумму покупок
			TDateTime pos_nach=Now()-kol_day;
			double sum_pokupok=gur_oper->GetSumPokupok(DM->DocIDKLIENT_ZAK->AsInt64,pos_nach)
														+DM->DocSUM_ZAK->AsFloat;
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
		LabelDescr->Caption=text_descr;

	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		DM->DocT->Edit();
		DM->DocTPRSK_CARD_RGZAKT->AsFloat=proc;
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
		DM->DocTPRSK_CARD_RGZAKT->AsFloat=0;
		DM->DocT->Post();
		DM->DocT->Next();
		}

		//получим тип цен

		IDMSprKlient * dm_spr_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_spr_klient);
		dm_spr_klient->Init(InterfaceMainObject,InterfaceImpl);
		dm_spr_klient->OpenElement(DM->DocIDKLIENT_ZAK->AsInt64);

		if (glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString)!=0)
			{
			DM->Doc->Edit();
			DM->DocIDTYPEPRICE_ZAK->AsString=dm_spr_klient->ElementIDTPRICEKLIENT->AsString;
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
								DMSprPrice->FindElement(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString),
											 glStrToInt64(DM->DocTIDNOM_ZAKT->AsString));
								if(DMSprPrice->ElementZNACH_PRICE->AsFloat==0)
									{
									DMSprPrice->FindElement(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),
											 glStrToInt64(DM->DocTIDNOM_ZAKT->AsString));
									}

								DM->DocTPRICE_ZAKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_ZAKT->AsFloat;

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
		spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOM_ZAKT->AsString));
		DM->DocT->Edit();
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4)
			{
			DM->DocTPRSK_CARD_RGZAKT->AsFloat=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5)
			{
			DM->DocTPRSK_CARD_RGZAKT->AsFloat=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
			{
			DM->DocTPRSK_CARD_RGZAKT->AsFloat=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
			}

		DM->DocT->Post();
		DM->DocT->Next();
		}
	spr_nom->kanRelease();
	}


}
//----------------------------------------------------------------------------
void TFormaZakazOf::GetProcentAuto(double sum_doc)
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
				spr_nom->OpenElement(DM->DocTIDNOM_ZAKT->AsInt64);
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
				spr_nom->OpenElement(glStrToInt64(DM->DocTIDNOM_ZAKT->AsString));
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
	DM->DocTPRSK_AUTO_RGZAKT->AsFloat=tek_skidka;
	DM->DocT->Post();
	DM->DocT->Next();
	}



}
//----------------------------------------------------------------------------
//ввод кода быстрого вызова
void TFormaZakazOf::OpenFormInputCodeNomBV(void)
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
void __fastcall TFormaZakazOf::EndInputCodeBV(void)
{


	int code_bv=StrToInt(Kalkulator->Result);
	//получим ID номенклатуры
	IDMSprBVNom * dm_bv;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
													(void**)&dm_bv);
		dm_bv->Init(InterfaceMainObject,InterfaceImpl);
	dm_bv->IdPod=glStrToInt64(DM_Connection->ARMInfoIDPODR_SARM->AsString);
	if (dm_bv->FindPoCoduBV(code_bv)>0)
		{
		Nom->OpenElement(dm_bv->IdNomBV);

			   DM->Doc->Edit();
			   DM->DocSOST_ZAK->AsInteger=1;
			   DM->Doc->Post();
			   
				DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOM_ZAKT->AsString=VibTovarId=glStrToInt64(Nom->ElementIDNOM->AsString);
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;
				DM->DocTKOLZ_ZAKT->AsInteger=1;

				DM->DocTIDED_ZAKT->AsString=Nom->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->OsnEdNAMEED->AsString;
				DM->DocTKF_ZAKT->AsFloat=Nom->OsnEdKFED->AsFloat;

				//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICE_ZAKT->AsFloat=
					dm_price->GetValuePrice(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString),                          //тип цен
							glStrToInt64(DM->DocTIDNOM_ZAKT->AsString),       //номенклатура
							glStrToInt64(DM->DocTIDED_ZAKT->AsString),         //единица
							DM->DocTKF_ZAKT->AsFloat,                        //коэффициент единицы
							0); //базовая единица
				dm_price->kanRelease();


				//получим место приготовления
				IDMSprNomRest * DMSprNomRest;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest,
													(void**)&DMSprNomRest);
				DMSprNomRest->Init(InterfaceMainObject,InterfaceImpl);
				DMSprNomRest->GetTekSostav(glStrToInt64(DM->DocTIDNOM_ZAKT->AsString), Now()) ;
				if ( glStrToInt64(DMSprNomRest->ElementIDMPRIG_NOMREST->AsString)!=0)
						{
						DM->DocTIDMPRIG_ZAKT->AsString=
										DMSprNomRest->ElementIDMPRIG_NOMREST->AsString;
						DM->DocTNAME_MPRIG->AsString=
										DMSprNomRest->ElementNAME_MPRIG->AsString;
						}
				DMSprNomRest->kanRelease();

				DM->DocT->Post();
				UpdateValuesDiscount();

		}
	else
		{
		 ShowMessage("Товар не найден!");
		}
    delete dm_bv;


}
//-----------------------------------------------------------------------------

void __fastcall TFormaZakazOf::BitBtn4Click(TObject *Sender)
{
OpenFormInputCodeNomBV();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaZakazOf::FormActivate(TObject *Sender)
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

void __fastcall TFormaZakazOf::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaZakazOf::ReadShtrihCodEvent(int number, UnicodeString sh)
{

	ObBar->IdTypePrice=glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString);
	ObBar->ObrabotatShtrihCod(sh);


	if (ObBar->OutReady==true)
		{

				DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOM_ZAKT->AsString=Nom->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=Nom->ElementNAMENOM->AsString;
				DM->DocTKRNAMENOM->AsString=Nom->ElementKRNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->ElementTNOM->AsInteger;

				DM->DocTIDED_ZAKT->AsString=Ed->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=Ed->ElementNAMEED->AsString;
				DM->DocTKF_ZAKT->AsFloat=Ed->ElementKFED->AsFloat;

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocTPRICE_ZAKT->AsFloat=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(Nom->ElementIDNOM->AsString),
							glStrToInt64(Ed->ElementIDED->AsString),
							Ed->ElementKFED->AsFloat,
							glStrToInt64(Nom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				DM->DocTKOLZ_ZAKT->AsFloat=ObBar->Kol;

				DM->DocT->Post();
				//ValidateOstatok(DM->DocTKOLCHKT->AsFloat*DM->DocTKFCHKT->AsFloat);


		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLZ_ZAKT->Selected=true;
		cxGrid1DBTableView1KOLZ_ZAKT->Focused=true;

		//дисплей
//		AnsiString string1=DM->DocTNAMENOM->AsString;
//		AnsiString string2="Цена:"+DM->DocTPRICE_ZAKT->AsString
//											+"  ВСЕГО:"+DM->DocSUM_ZAK->AsString;
//		if (glDisplayPok>0) glDisplayPok->ShowString1(string1.c_str(),1,0,0);
//		if (glDisplayPok>0) glDisplayPok->ShowString2(string2.c_str(),1,0,0);
		}
	else
		{
		ShowMessage(ObBar->TextError);
		}


}
//---------------------------------------------------------------
bool TFormaZakazOf::CreateDocSchet(void)
{
bool result=false;
UnicodeString create_schet = DM_Connection->Arm_GetParameter("CreateDocSchet");

if (create_schet=="1")
	{
	IDMDocSchet * doc;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocSchet,IID_IDMDocSchet,
									 (void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
        //заполним параметы чека
		doc->NewDoc();
		doc->DocAll->Edit();
		if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
			{
			doc->DocAllIDBASE_GALLDOC->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
			{
			doc->DocAllIDFIRMDOC->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
			}
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			doc->DocAllIDSKLDOC->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
            }
		if (glStrToInt64(DM->DocIDKLIENT_ZAK->AsString)>0)
                {
				doc->DocAllIDKLDOC->AsString=DM->DocIDKLIENT_ZAK->AsString;
				doc->DocAllNAMEKLIENT->AsString=DM->DocNAMEKLIENT->AsString;
                }

        doc->DocAll->Post();

		doc->Doc->Edit();
		if(glStrToInt64(DM->DocIDTYPEPRICE_ZAK->AsString)!=0)
			{
			doc->DocIDTPRICESCH->AsString=DM->DocIDTYPEPRICE_ZAK->AsString;
			}
		doc->DocPRIMSCH->AsString="Заказ №"+DM->DocID_ZAK->AsString+" "+DM->ObNAME_STROB->AsString;
		doc->Doc->Post();

//        Check->Prim->Caption=Check->DM->DocPRIMCHK->AsString;


        DM->DocT->First();

        while(!DM->DocT->Eof)
                {
				doc->AddDocNewString();
				doc->DocT->Edit();
				doc->DocTIDNOMSCHT->AsString=DM->DocTIDNOM_ZAKT->AsString;
				doc->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
				doc->DocTIDEDSCHT->AsString=DM->DocTIDED_ZAKT->AsString;
				doc->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
				doc->DocTKOLSCHT->AsFloat=DM->DocTKOLOT_ZAKT->AsFloat;
				doc->DocTKFSCHT->AsFloat=DM->DocTKF_ZAKT->AsFloat;
				if (DM->DocTKOLOT_ZAKT->AsFloat > 0.001)
					{
					doc->DocTPRICESCHT->AsFloat=DM->DocTSUM_ZAKT->AsFloat/
											DM->DocTKOLOT_ZAKT->AsFloat;
					}
				else
					{
					doc->DocTPRICESCHT->AsFloat=DM->DocTSUM_ZAKT->AsFloat;
					}
				doc->DocT->Post();
                DM->DocT->Next();
				}

	if (doc->SaveDoc()==true)
		{
		doc->DvRegDoc();
		}

    doc->kanRelease();
	}

result=true;

return result;
}
//----------------------------------------------------------------
