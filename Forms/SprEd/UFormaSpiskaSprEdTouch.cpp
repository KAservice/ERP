//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprEdTouch.h"

#include "IDMRegOstNom.h"
#include "IDMSprARM.h"
#include "IDMSprEd.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprEdTouch::TFormaSpiskaSprEdTouch(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprEdTouch::FormCreate(TObject *Sender)
{
IdNom=0;
Kol=1;
LabelKol->Caption="Количество : 1.00";
TypeEvent=0;

}
//---------------------------------------------------------------------------
bool TFormaSpiskaSprEdTouch::Init(void)
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
	}



IBTr->DefaultDatabase=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;

LabelNom->Caption=NameNom;

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
int TFormaSpiskaSprEdTouch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprEdTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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

El->Active=false;
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprEdTouch::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprEdTouch::BitBtnCloseClick(
      TObject *Sender)
{
TypeEvent=0;;
Close();
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprEdTouch::UpdateForm(void)
{
String StrOstatok="Остаток: ";
if (TypeNom==0)
        {
		IDMRegOstNom * DMRegOstNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMRegOstNom.1",IID_IDMRegOstNom,
													(void**)&DMRegOstNom);
		DMRegOstNom->Init(InterfaceMainObject,InterfaceImpl);
		if (IdFirm==0 && IdSklad==0)
			{
			DMRegOstNom->IdFirm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);
			DMRegOstNom->IdSklad=glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString);
			}
		else
			{
			DMRegOstNom->IdFirm=IdFirm;
			DMRegOstNom->IdSklad=IdSklad;
			}
        DMRegOstNom->IdNom=IdNom;
        if (DMRegOstNom->GetOstatok()>0)
                {
                StrOstatok=StrOstatok+" "+FloatToStrF(DMRegOstNom->KolOst,ffFixed,10,3);
                OstatokLabel->Font->Color= clGreen;
                }
        else
                {
                StrOstatok=StrOstatok+" 0";
                OstatokLabel->Font->Color= clMaroon;
                }

        DMRegOstNom->kanRelease();

		IDMSprEd *DMSprEd;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&DMSprEd);
		DMSprEd->Init(InterfaceMainObject,InterfaceImpl);
        if(DMSprEd->OpenElement(IdBasEd)>0)
                {
                StrOstatok=StrOstatok+" "+DMSprEd->ElementNAMEED->AsString;
                }
        DMSprEd->kanRelease();
        OstatokLabel->Caption=StrOstatok;
        }
else
        {
        StrOstatok=StrOstatok+" --- ";
        OstatokLabel->Font->Color= clGreen;
        OstatokLabel->Caption=StrOstatok;
        }
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprEdTouch::OpenSpisokEd(void)
{
El->Active=false;
El->ParamByName("IDNOM")->AsString=IdNom;
El->ParamByName("PARAM_IDTYPE_PRICE")->AsString=DM_Connection->ARMInfoIDTPRICEPOD->AsString;
El->Active=true;
El->First();

if(El->Eof!=true)
        {
        el1->Visible=true;
		el1->Caption=ElNAMEED->AsString;
        p1->Visible=true;
		//p1->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p1->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();

        }
else
        {
        el1->Visible=false;
        p1->Visible=false;
        }

El->Next();
if(El->Eof!=true)
        {
        el2->Visible=true;
        el2->Caption=ElNAMEED->AsString;
        p2->Visible=true;
		//p2->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);

				//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p2->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el2->Visible=false;
        p2->Visible=false;
        }

El->Next();
if(El->Eof!=true)
        {
        el3->Visible=true;
        el3->Caption=ElNAMEED->AsString;
        p3->Visible=true;
		//p3->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);

				p3->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el3->Visible=false;
        p3->Visible=false;
        }


El->Next();
if(El->Eof!=true)
        {
        el4->Visible=true;
        el4->Caption=ElNAMEED->AsString;
        p4->Visible=true;
		//p4->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);

				p4->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el4->Visible=false;
        p4->Visible=false;
        }


El->Next();
if(El->Eof!=true)
        {
        el5->Visible=true;
        el5->Caption=ElNAMEED->AsString;
        p5->Visible=true;
		//p5->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p5->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el5->Visible=false;
        p5->Visible=false;
        }

El->Next();
if(El->Eof!=true)
        {
        el6->Visible=true;
        el6->Caption=ElNAMEED->AsString;
        p6->Visible=true;
		//p6->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p6->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el6->Visible=false;
        p6->Visible=false;
        }


El->Next();
if(El->Eof!=true)
        {
        el7->Visible=true;
        el7->Caption=ElNAMEED->AsString;
        p7->Visible=true;
		//p7->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p7->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el7->Visible=false;
        p7->Visible=false;
        }


El->Next();
if(El->Eof!=true)
        {
        el8->Visible=true;
        el8->Caption=ElNAMEED->AsString;
        p8->Visible=true;
		//p8->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p8->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
		}
else
        {
        el8->Visible=false;
        p8->Visible=false;
        }

El->Next();
if(El->Eof!=true)
        {
        el9->Visible=true;
        el9->Caption=ElNAMEED->AsString;
        p9->Visible=true;
		//p9->Caption=FloatToStrF(ElZNACH_PRICE->AsFloat*ElKFED->AsFloat, ffCurrency,10,2);
						//получим цену
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				p9->Caption=FloatToStrF(
					dm_price->GetValuePrice(glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString),                          //тип цен
							IdNom,       //номенклатура
							glStrToInt64(ElIDED->AsString),         //единица
							ElKFED->AsFloat,                        //коэффициент единицы
							0), //базовая единица
							 ffCurrency,10,2);
				dm_price->kanRelease();
        }
else
        {
        el9->Visible=false;
        p9->Visible=false;
        }
UpdateForm();
}
//----------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TFormaSpiskaSprEdTouch::OpenElement(int Num)
{
El->First();
El->MoveBy(Num-1);
if(El->Eof!=true)
		{
		TypeEvent=1;
		Close();
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprEdTouch::el1Click(TObject *Sender)
{
OpenElement(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el2Click(TObject *Sender)
{
OpenElement(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el3Click(TObject *Sender)
{
OpenElement(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el4Click(TObject *Sender)
{
OpenElement(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el5Click(TObject *Sender)
{
OpenElement(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el6Click(TObject *Sender)
{
OpenElement(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el7Click(TObject *Sender)
{
OpenElement(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el8Click(TObject *Sender)
{
OpenElement(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::el9Click(TObject *Sender)
{
 OpenElement(9);
}
//---------------------------------------------------------------------------






















void __fastcall TFormaSpiskaSprEdTouch::b1Click(TObject *Sender)
{
Kol=1;
LabelKol->Caption="Количество : 1.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b2Click(TObject *Sender)
{
Kol=2;
LabelKol->Caption="Количество : 2.00";
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b3Click(TObject *Sender)
{
Kol=3;
LabelKol->Caption="Количество : 3.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b4Click(TObject *Sender)
{
 Kol=4;
LabelKol->Caption="Количество : 4.00";
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b5Click(TObject *Sender)
{
Kol=5;
LabelKol->Caption="Количество : 5.00"  ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b6Click(TObject *Sender)
{
Kol=6;
LabelKol->Caption="Количество : 6.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b7Click(TObject *Sender)
{
 Kol=7;
LabelKol->Caption="Количество : 7.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b8Click(TObject *Sender)
{
Kol=8;
LabelKol->Caption="Количество : 8.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b9Click(TObject *Sender)
{
Kol=9;
LabelKol->Caption="Количество : 9.00" ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprEdTouch::b10Click(TObject *Sender)
{
Kol=10;
LabelKol->Caption="Количество : 10.00";
}
//---------------------------------------------------------------------------

