//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprNom.h"
#include "IFormaSpiskaSprSezKF.h"
#include "IDMSprTypePrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
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
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxSpinEdit"
#pragma link "cxCurrencyEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaElementaSprNom::TFormaElementaSprNom(TComponent* Owner)
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
bool TFormaElementaSprNom::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

MinOstcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
PogrcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ArtcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KrNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NDScxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
NameCountrycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
GTDcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

VidNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
Skidka1cxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
Skidka2cxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
Skidka3cxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

TypeSrokaGodncxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
SrokGodncxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
GodenDocxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

FisEdcxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceElement;
FisEdcxDBLookupComboBox->Properties->ListSource=DM->DataSourceSpisokEd;

OsnEdcxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceElement;
OsnEdcxDBLookupComboBox->Properties->ListSource=DM->DataSourceSpisokEd;

TNomcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SuppliercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

WarrantycxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
TransportcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
CreditcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
cxDBCheckBoxAddInSprOborud->DataBinding->DataSource=DM->DataSourceElement;
FlDvRegcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

cxDBButtonEditNAME_SDEPARTMENT->DataBinding->DataSource=DM->DataSourceElement;
cxDBButtonEditNAME_SPROPNABOR->DataBinding->DataSource=DM->DataSourceElement;
cxDBButtonEditNAME_SVIDIMAGE_NABOR->DataBinding->DataSource=DM->DataSourceElement;

//базовая единица
NameBasEdcxDBLabel->DataBinding->DataSource=DM->DataSourceBasEd;
CodeBasEdcxDBLabel->DataBinding->DataSource=DM->DataSourceBasEd;
BarCodeBasEdcxDBLabel->DataBinding->DataSource=DM->DataSourceBasEd;
KF2BasEdcxDBLabel->DataBinding->DataSource=DM->DataSourceBasEd;
KFBasEdcxDBLabel->DataBinding->DataSource=DM->DataSourceBasEd;

//основная единица
KFOsnEdcxDBLabel->DataBinding->DataSource=DM->DataSourceOsnEd;
KF2OsnEdcxDBLabel->DataBinding->DataSource=DM->DataSourceOsnEd;
CodeOsnEdcxDBLabel->DataBinding->DataSource=DM->DataSourceOsnEd;
BarCodeOsnEdcxDBLabel->DataBinding->DataSource=DM->DataSourceOsnEd;
OsnEdcxDBLookupComboBox->Properties->ListSource=DM->DataSourceSpisokEd;

//физическая единица
KFFisEdcxDBLabel->DataBinding->DataSource=DM->DataSourceFisEd;
KF2FisEdcxDBLabel->DataBinding->DataSource=DM->DataSourceFisEd;
CodeFisEdcxDBLabel->DataBinding->DataSource=DM->DataSourceFisEd;
BarCodeFisEdcxDBLabel->DataBinding->DataSource=DM->DataSourceFisEd;
FisEdcxDBLookupComboBox->Properties->ListSource=DM->DataSourceSpisokEd;

//цены
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice, (void**)&DMPrice);
DMPrice->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DMPrice->DataSourceTable;

TcxLookupComboBoxProperties  *  AProperties;
AProperties=(TcxLookupComboBoxProperties *) cxGrid1DBTableView1NameEd->GetProperties();
AProperties->ListSource=DMPrice->DataSourceSpisokEd;

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
int  TFormaElementaSprNom::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprPart)FormaSpiskaSprPart->kanRelease();
if(SostavProd)SostavProd->kanRelease();
if(FormaSpiskaSprPrice)FormaSpiskaSprPrice->kanRelease();
if(FormaSpiskaSprMod)FormaSpiskaSprMod->kanRelease();
if(FormaSpiskaSprNomRest)FormaSpiskaSprNomRest->kanRelease();
if(FormaSpiskaSprSezKF)FormaSpiskaSprSezKF->kanRelease();

if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprCountry)FormaSpiskaSprCountry->kanRelease();

if(FormaSpiskaSprVidNom)FormaSpiskaSprVidNom->kanRelease();
if(FormaSpiskaSprImportNom)FormaSpiskaSprImportNom->kanRelease();

if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(SpisokSprPriceSchedule)SpisokSprPriceSchedule->kanRelease();
if(SpisokBrand)SpisokBrand->kanRelease();
if(FormaSpiskaSprNomAnalog)FormaSpiskaSprNomAnalog->kanRelease();

if(kasFormSpr)kasFormSpr->kanRelease();

DM->kanRelease();
DMPrice->kanRelease();

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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprNom::UpdateForm(void)
{
DMPrice->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString ));
DMPrice->IdBasEd=glStrToInt64(DM->ElementIDBASEDNOM->AsString);


NameGrpLabel->Caption=NameGrpNom;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::FormActivate(TObject *Sender)
{
//if (glScaner) if(glScaner->ConnectScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::FormDeactivate(TObject *Sender)
{
//if (glScaner) if(glScaner->ConnectScaner) glScaner->ReadSh=0;
}

//----------------------------------------------------------------------------
int TFormaElementaSprNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==1)
                {
                if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDCOUNTRYNOM->AsString=
						FormaSpiskaSprCountry->DM->ElementID_SCOUNTRY->AsString;
                        DM->ElementNAME_SCOUNTRY->AsString=FormaSpiskaSprCountry->DM->ElementNAME_SCOUNTRY->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprCountry=0;
                }

		if (number_procedure_end==2)
                {
                DM->Element->Edit();
				DM->ElementIDFIRMNOM->AsString=
						FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
                DM->ElementNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
                DM->Element->Post();
                FormaSpiskaSprFirm=0;
                }

		if (number_procedure_end==3)
                {
                FormaSpiskaSprNomRest=0;
                }

		if (number_procedure_end==4)
                {
                FormaSpiskaSprEd=0;
                }

		if (number_procedure_end==5)
                {
                FormaSpiskaSprPart=0;
                }

		if (number_procedure_end==6)
                {
                SostavProd=0;
                }

		if (number_procedure_end==7)
                {
                FormaSpiskaSprPrice=0;
                }

		if (number_procedure_end==8)
                {
                FormaSpiskaSprMod=0;
                }

		if (number_procedure_end==9)
                {
                FormaSpiskaSprSezKF=0;
				}

		if (number_procedure_end==10)
				{
				FormaSpiskaSprImportNom=0;
				}

		if (number_procedure_end==11)
				{
				FormaSpiskaSprOKEI=0;
				}

		if (number_procedure_end==12)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborVidNom();
					}
				}
		if (number_procedure_end==13)
				{
				if (type_event==1)    //выбор сделан
					{
					EndEditBasEd();
					}
				FormaElementaSprEd=0;
				}
		if (number_procedure_end==14)
				{
				if (type_event==1)    //выбор сделан
					{
					EndEditOsnEd();
					}
				FormaElementaSprEd=0;
				}
		if (number_procedure_end==15)
				{
				if (type_event==1)    //выбор сделан
					{
					EndEditFisEd();
					}
				FormaElementaSprEd=0;
				}

		if (number_procedure_end==16)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborSupplier();
					}
				FormaSpiskaSprKlient=0;
				}

		if (number_procedure_end==17)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborProducer();
					}
				FormaSpiskaSprKlient=0;
				}

		if (number_procedure_end==18)
				{
				if (type_event==1)    //выбор сделан
					{
					EndEditPriceSchedule() ;
					}
				SpisokSprPriceSchedule=0;
				}
		if (number_procedure_end==19)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborBrand();
					}
				SpisokBrand=0;
				}

		if (number_procedure_end==20)
				{
				FormaSpiskaSprNomImage=0;
				}

		if (number_procedure_end==21)
				{
				FormaSpiskaSprNomPropertiesValue=0;
				}

		if (number_procedure_end==22)
				{
				FormaSpiskaSprNachisl=0;
				}

		if (number_procedure_end==23)
				{
				FormaSpiskaSprNomAnalog=0;
				}

		if (number_procedure_end==24)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborDepartment();
					}
				kasFormSpr=0;
				}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::NameNomKeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
        {
        DM->Element->Edit();
        DM->ElementFNAMENOM->AsString=DM->ElementNAMENOM->AsString;
        DM->ElementKRNAMENOM->AsString=DM->ElementNAMENOM->AsString;
        DM->Element->Post();
        }
}
//---------------------------------------------------------------------------

void TFormaElementaSprNom::OpenFormSpiskaSprNomRest(void)
{

if (FormaSpiskaSprNomRest==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNomRest.1",IID_IFormaSpiskaSprNomRest,
													(void**)&FormaSpiskaSprNomRest);
		FormaSpiskaSprNomRest->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNomRest->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);

        FormaSpiskaSprNomRest->NameNom=DM->ElementNAMENOM->AsString;

		FormaSpiskaSprNomRest->DM->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
        FormaSpiskaSprNomRest->DM->OpenTable();
        
		FormaSpiskaSprNomRest->UpdateForm();
		FormaSpiskaSprNomRest->NumberProcVibor=3;
		}

}
//-------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNom");	
}

//-----------------------------------------------------------------------------


void __fastcall TFormaElementaSprNom::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprFirm==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													 (void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=2;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::NameCountrycxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprCountry==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprCountry.1",IID_IFormaSpiskaSprCountry,
													 (void**)&FormaSpiskaSprCountry);
		FormaSpiskaSprCountry->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprCountry->Vibor=true;
		FormaSpiskaSprCountry->NumberProcVibor=1;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonPriceClick(TObject *Sender)
{

if (FormaSpiskaSprPrice==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPrice.1",IID_IFormaSpiskaSprPrice,
													 (void**)&FormaSpiskaSprPrice);
		FormaSpiskaSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPrice->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprPrice->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprPrice->DM->IdBasEd=glStrToInt64(DM->ElementIDBASEDNOM->AsString);
		FormaSpiskaSprPrice->HeaderText="Цены номенклатуры: "
						+DM->Element->FieldByName("NAMENOM")->AsString
						+" за "+DM->BasEdNAMEED->AsString;
		FormaSpiskaSprPrice->UpdateForm();
		FormaSpiskaSprPrice->NumberProcVibor=7;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonEdClick(TObject *Sender)
{

if (FormaSpiskaSprEd==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													 (void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprEd->HeaderText="Единицы номенклатуры: "+DM->Element->FieldByName("NAMENOM")->AsString;
		FormaSpiskaSprEd->IdTypePrice=IdTypePrice;
		FormaSpiskaSprEd->IdFirm=IdFirm;
        FormaSpiskaSprEd->UpdateForm();
		FormaSpiskaSprEd->NumberProcVibor=4;
		}


}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonPartClick(TObject *Sender)
{

if (FormaSpiskaSprPart==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPart.1",IID_IFormaSpiskaSprPart,
													 (void**)&FormaSpiskaSprPart);
		FormaSpiskaSprPart->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPart->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprPart->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprPart->HeaderText="Партии номенклатуры: "+DM->Element->FieldByName("NAMENOM")->AsString;
        FormaSpiskaSprPart->UpdateForm();
		FormaSpiskaSprPart->NumberProcVibor=5;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonModClick(TObject *Sender)
{


if (FormaSpiskaSprMod==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprMod.1",IID_IFormaSpiskaSprMod,
													 (void**)&FormaSpiskaSprMod);
		FormaSpiskaSprMod->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprMod->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprMod->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		//FormaSpiskaSprMod->LabelNom->Caption="Модификаторы продукции: "+DM->Element->FieldByName("NAMENOM")->AsString;
		FormaSpiskaSprMod->NumberProcVibor=8;
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonProdClick(TObject *Sender)
{
///*****
OpenFormSpiskaSprNomRest();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonSezKFClick(TObject *Sender)
{

if (FormaSpiskaSprSezKF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSezKF.1",IID_IFormaSpiskaSprSezKF,
													 (void**)&FormaSpiskaSprSezKF);
		FormaSpiskaSprSezKF->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSezKF->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprSezKF->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		//FormaSpiskaSprSezKF->LabelNom->Caption="Сезонные К: "+DM->Element->FieldByName("NAMENOM")->AsString;
		FormaSpiskaSprSezKF->NumberProcVibor=9;

		}

}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprNom::StNDScxDBCalcEditKeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprNom::MinOstcxDBCalcEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::NameBasEdPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													 (void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		//FormaSpiskaSprEd->LabelNom->Caption=DM->Element->FieldByName("NAMENOM")->AsString;
		//FormaSpiskaSprEd->HintLabel->Caption="Выберите базовую единицу";
		FormaSpiskaSprEd->NumberProcVibor=4;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ArtcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::Price2EditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void TFormaElementaSprNom::OpenFormaSpiskaSprVidNom(void)
{
if (FormaSpiskaSprVidNom==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidNom.1",IID_IFormaSpiskaSprVidNom,
													 (void**)&FormaSpiskaSprVidNom);
	FormaSpiskaSprVidNom->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprVidNom->Vibor=true;
	FormaSpiskaSprVidNom->NumberProcVibor=12;

	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndViborVidNom(void)
{

	DM->Element->Edit();
	DM->ElementIDVID_SNOM->AsString=FormaSpiskaSprVidNom->DM->TableID_SVIDNOM->AsString;
	DM->ElementNAME_SVIDNOM->AsString=FormaSpiskaSprVidNom->DM->TableNAME_SVIDNOM->AsString;
	DM->Element->Post();

FormaSpiskaSprVidNom=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::VidNomcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormaSpiskaSprVidNom();
}
//---------------------------------------------------------------------------
 
void __fastcall TFormaElementaSprNom::cxButtonOpenFormSpiskaSprImportNomClick(
      TObject *Sender)
{

if (FormaSpiskaSprImportNom==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprImportNom.1",IID_IFormaSpiskaSprImportNom,
													 (void**)&FormaSpiskaSprImportNom);
	FormaSpiskaSprImportNom->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprImportNom->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
	FormaSpiskaSprImportNom->UpdateForm();
	FormaSpiskaSprImportNom->NumberProcVibor=10;
	FormaSpiskaSprImportNom->HeaderText=DM->Element->FieldByName("NAMENOM")->AsString;
	FormaSpiskaSprImportNom->UpdateForm();
	}

}
//---------------------------------------------------------------------------
//редактирование базовой единицы

void TFormaElementaSprNom::EditBasEd(void)
{
if (FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
    FormaElementaSprEd->DM->OpenElement(glStrToInt64(DM->ElementIDBASEDNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=13;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndEditBasEd(void)
{

DM->OpenEd();
DMPrice->UpdateSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
FormaElementaSprEd=0;
}
//----------------------------------------------------------------------------
//редактирование основной единицы
void TFormaElementaSprNom::NewOsnEd(void)
{
if(FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaElementaSprEd->DM->NewElement(glStrToInt64(DM->ElementIDNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=14;

	}
}
//-----------------------------------------------------------------------------
void TFormaElementaSprNom::EditOsnEd(void)
{
if(FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaElementaSprEd->DM->OpenElement(glStrToInt64(DM->ElementIDOSNEDNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=14;
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndEditOsnEd(void)
{

	DM->Element->Edit();
	DM->ElementIDOSNEDNOM->AsString=FormaElementaSprEd->DM->ElementIDED->AsString;
	DM->Element->Post();
	DM->OpenSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
	DMPrice->UpdateSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
	DM->OpenEd();


}
//-----------------------------------------------------------------------------
//редактирование физической единицы
void TFormaElementaSprNom::NewFisEd(void)
{
if(FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaElementaSprEd->DM->NewElement(glStrToInt64(DM->ElementIDNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=15;
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprNom::EditFisEd(void)
{
if(FormaElementaSprEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
													 (void**)&FormaElementaSprEd);
	FormaElementaSprEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaElementaSprEd->DM->OpenElement(glStrToInt64(DM->ElementIDFISED_SNOM->AsString));
	FormaElementaSprEd->UpdateForm();
	FormaElementaSprEd->NumberProcVibor=15;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndEditFisEd(void)
{


	DM->Element->Edit();
	DM->ElementIDFISED_SNOM->AsString=FormaElementaSprEd->DM->ElementIDED->AsString;
	DM->Element->Post();
	DM->OpenSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
	DMPrice->UpdateSpisokEd(glStrToInt64(DM->ElementIDNOM->AsString));
	DM->OpenEd();


}
//----------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ToolButtonAddPriceClick(TObject *Sender)
{
DMPrice->Table->Append();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ToolButtonDeletePriceClick(
      TObject *Sender)
{
DMPrice->Table->Delete();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::OsnEdcxDBLookupComboBoxPropertiesChange(
      TObject *Sender)
{
DM->OpenOsnEd();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::FisEdcxDBLookupComboBoxPropertiesChange(
      TObject *Sender)
{
DM->OpenFisEd();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonEditBasEdClick(TObject *Sender)
{
EditBasEd();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonAddOsnEdClick(TObject *Sender)
{
NewOsnEd();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonEditOsnEdClick(TObject *Sender)
{
EditOsnEd();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonAddFisEdClick(TObject *Sender)
{
NewFisEd();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonEditFisEdClick(TObject *Sender)
{
EditFisEd();
}
//---------------------------------------------------------------------------






void TFormaElementaSprNom::ViborSupplier(void)
{

if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													 (void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	FormaSpiskaSprKlient->NumberProcVibor=16;
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprNom::ViborProducer(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													 (void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	FormaSpiskaSprKlient->NumberProcVibor=17;
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndViborSupplier(void)
{

	DM->Element->Edit();
	DM->ElementIDSUPPLIER_SNOM->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementSUPPLIER_NAME->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndViborProducer(void)
{

	DM->Element->Edit();
	DM->ElementIDPRODUCER_SNOM->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementPRODUCER_NAME->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

FormaSpiskaSprKlient=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//------------------------------------------------------------------------------


void __fastcall TFormaElementaSprNom::ProducercxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborProducer();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::SuppliercxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSupplier();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprNom::ActionSetMainTabSheetExecute(
      TObject *Sender)
{
cxPageControl1->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ActionSetAdditionallyTabSheetExecute(
      TObject *Sender)
{
cxPageControl1->ActivePageIndex=1;
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprNom::PogrcxDBCalcEditKeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonpriceScheduleClick(
      TObject *Sender)
{
EditPriceSchedule();
}
//---------------------------------------------------------------------------
void TFormaElementaSprNom::EditPriceSchedule(void)
{
if (SpisokSprPriceSchedule==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPriceSchedule.1",IID_IFormaSpiskaSprPriceSchedule,
													 (void**)&SpisokSprPriceSchedule);
		SpisokSprPriceSchedule->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSprPriceSchedule->Vibor=false;
		SpisokSprPriceSchedule->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		SpisokSprPriceSchedule->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		SpisokSprPriceSchedule->DM->IdBasEd=glStrToInt64(DM->ElementIDBASEDNOM->AsString);
		SpisokSprPriceSchedule->HeaderText="График цен номенклатуры: "
						+DM->Element->FieldByName("NAMENOM")->AsString;
        SpisokSprPriceSchedule->UpdateForm();
		SpisokSprPriceSchedule->NumberProcVibor=18;
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndEditPriceSchedule(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::NameBrandcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborBrand();	
}
//---------------------------------------------------------------------------
		//Бренд
void TFormaElementaSprNom::ViborBrand(void)
{
if (SpisokBrand==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBrand.1",IID_IFormaSpiskaSprBrand,
													 (void**)&SpisokBrand);
		SpisokBrand->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBrand->Vibor=true;
		SpisokBrand->NumberProcVibor=19;
		}

}
//------------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndViborBrand(void)
{

	DM->Element->Edit();
	DM->ElementIDBRAND_SNOM->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->ElementNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->Element->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMPrice->SaveIsmen()==true)
		{
		Close();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMPrice->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMPrice->SaveIsmen()==true)
		{
		UpdateForm();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMPrice->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::KrNamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::GTDcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::NameNomcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	DM->ElementFNAMENOM->AsString=DM->ElementNAMENOM->AsString;
	UnicodeString t=DM->ElementNAMENOM->AsString;
	DM->ElementKRNAMENOM->AsString=Trim(t).SetLength(39);
	DM->Element->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::FNamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	UnicodeString t=DM->ElementFNAMENOM->AsString;
	DM->ElementKRNAMENOM->AsString=Trim(t).SetLength(39);
	DM->Element->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonOpenSprNomImageClick(TObject *Sender)

{
if (FormaSpiskaSprNomImage==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNomImage,IID_IFormaSpiskaSprNomImage,
													 (void**)&FormaSpiskaSprNomImage);
		FormaSpiskaSprNomImage->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNomImage->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprNomImage->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprNomImage->HeaderText="Изображения номенклатуры: "+DM->ElementNAMENOM->AsString;;
		FormaSpiskaSprNomImage->UpdateForm();
		FormaSpiskaSprNomImage->NumberProcVibor=20;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonOpenSprNomPropertiesClick(TObject *Sender)

{
if (FormaSpiskaSprNomPropertiesValue==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNomPropertiesValue,IID_IFormaSpiskaSprNomPropertiesValue,
													 (void**)&FormaSpiskaSprNomPropertiesValue);
		FormaSpiskaSprNomPropertiesValue->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNomPropertiesValue->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprNomPropertiesValue->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprNomPropertiesValue->HeaderText="Свойства номенклатуры: "+DM->ElementNAMENOM->AsString;
		FormaSpiskaSprNomPropertiesValue->UpdateForm();
		FormaSpiskaSprNomPropertiesValue->NumberProcVibor=21;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonNachislClick(TObject *Sender)
{
if (FormaSpiskaSprNachisl==0)
        {
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNachisl,IID_IFormaSpiskaSprNachisl,
													 (void**)&FormaSpiskaSprNachisl);
		FormaSpiskaSprNachisl->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNachisl->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprNachisl->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString));
		FormaSpiskaSprNachisl->HeaderText="Начисления номенклатуры: "
						+DM->Element->FieldByName("NAMENOM")->AsString
						+" за "+DM->BasEdNAMEED->AsString;
		FormaSpiskaSprNachisl->UpdateForm();
		FormaSpiskaSprNachisl->NumberProcVibor=22;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNom::cxButtonAnalogClick(TObject *Sender)
{
ViborAnalog();
}
//---------------------------------------------------------------------------
void TFormaElementaSprNom::ViborAnalog(void)
{
if (FormaSpiskaSprNomAnalog==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNomAnalog,IID_IFormaSpiskaSprNomAnalog,
													 (void**)&FormaSpiskaSprNomAnalog);
		FormaSpiskaSprNomAnalog->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNomAnalog->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
		FormaSpiskaSprNomAnalog->DM->OpenTable(glStrToInt64(DM->ElementIDNOM->AsString),IdTypePrice);
		FormaSpiskaSprNomAnalog->HeaderText="Аналоги номенклатуры: "
						+DM->Element->FieldByName("NAMENOM")->AsString;
		FormaSpiskaSprNomAnalog->UpdateForm();
		FormaSpiskaSprNomAnalog->NumberProcVibor=23;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNom::EndViborAnalog(void)
{




}
//----------------------------------------------------------------------------


void TFormaElementaSprNom::ViborDepartment(void)
{
if (kasFormSpr==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprDepartment,IID_IkasFormSpr,
													 (void**)&kasFormSpr);
		kasFormSpr->Init(InterfaceMainObject,InterfaceImpl);
		kasFormSpr->UpdateForm();
		kasFormSpr->NumberProcVibor=24;
		kasFormSpr->Vibor=true;
		}

}
//----------------------------------------------------------
void TFormaElementaSprNom::EndViborDepartment(void)
{

	DM->Element->Edit();
	DM->ElementIDDEPARTMENT_SNOM->AsString=kasFormSpr->DM->GetValueFieldAsInt64("ID_SDEPARTMENT",0);
	DM->ElementNAME_SDEPARTMENT->AsString=kasFormSpr->DM->GetValueFieldAsString("NAME_SDEPARTMENT",0);
	DM->Element->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------
void __fastcall TFormaElementaSprNom::cxDBButtonEditNAME_SDEPARTMENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDepartment();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDDEPARTMENT_SNOM->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

