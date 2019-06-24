//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprKlient.h"
#include "IFormaSpiskaSprRaschSchet.h"
#include "IFormaSpiskaSprNumTel.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IFormaSpiskaSprDocKlient.h"
#include "IFormaSpiskaSprDiscountCard.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


#include "UDM.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxPC"
#pragma link "cxMemo"
#pragma link "cxCalc"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaElementaSprKlient::TFormaElementaSprKlient(TComponent* Owner)
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
//------------------------------------------------------------------------
bool TFormaElementaSprKlient::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
IDKlientDBText->DataSource=DM->DataSourceElement;

VidKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCountrycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
AdresscxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
OKPOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
INNcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KPPcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

KrNameKlientcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

DescrcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
MessagecxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
MaxCreditcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
EmailcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
WWWcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


PochtAdresscxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
YurAdresscxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
cxDBImageComboBoxTYPE_POISK_SKLIENT->DataBinding->DataSource=DM->DataSourceElement;

cxDBButtonEditNAMEGN->DataBinding->DataSource=DM->DataSourceElement;
cxDBButtonEditNAME_REM_SGRP_HARDWARE->DataBinding->DataSource=DM->DataSourceElement;

flObrabatChangeTypeKlient=false;

flObrabatChangeTypePrice=false;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
		{
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
		DMSprTypePrice->Table->Next();
		}

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
void TFormaElementaSprKlient::UpdateForm(void)
{
flObrabatChangeTypeKlient=false;
TKlient->ItemIndex=DM->Element->FieldByName("TKLIENT")->AsInteger;
flObrabatChangeTypeKlient=true;

flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->ElementIDTPRICEKLIENT->AsString));
flObrabatChangeTypePrice=true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int TFormaElementaSprKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaElementaSprKlientDopFisL)FormaElementaSprKlientDopFisL->kanRelease();
if(FormaElementaSprKlientDopUrL)FormaElementaSprKlientDopUrL->kanRelease();
if(FormaSpiskaSprVidKlient)FormaSpiskaSprVidKlient->kanRelease();
if(FormaSpiskaSprCountry)FormaSpiskaSprCountry->kanRelease();
if(FormaKladr)FormaKladr->kanRelease();
if(FormaSpiskaSprGrpNom)FormaSpiskaSprGrpNom->kanRelease();

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
DMSprTypePrice->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//-----------------------------------------------------------------------
int TFormaElementaSprKlient::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_DopFisL)
		{
		FormaElementaSprKlientDopFisL=0;
		}

if (number_procedure_end==ER_DopUrL)
		{
		FormaElementaSprKlientDopUrL=0;
		}


if (number_procedure_end==ER_VidKlient)
		{
		if (type_event==1)
			{
			EndViborVidKlient();
			}
		FormaSpiskaSprVidKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Country)
		{
		if (type_event==1)
			{
			EndViborCountry() ;
			}
		FormaSpiskaSprCountry=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_Kladr)
		{
		if (type_event==1)
			{
			EndViborAdressByKladr();
			}
		FormaKladr=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_GrpNom)
	{
	if (type_event==1)
		{
		EndViborGrpNom();
		}
	FormaSpiskaSprGrpNom=0;
	}

return -1;
}
//-----------------------------------------------------------------------------





void __fastcall TFormaElementaSprKlient::NameKlientKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
        {
        DM->Element->Edit();
        DM->ElementFNAME->AsString=DM->ElementNAMEKLIENT->AsString;
        DM->Element->Post();
        }
}
//---------------------------------------------------------------------------



void TFormaElementaSprKlient::OpenFormaElementaSprKlientFisL(void)
{
if (DM->elSave==false)
        {
        ShowMessage("Необходимо записать элемент!");
        return;
        }

if (FormaElementaSprKlientDopFisL==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprKlientDopFisL.1",IID_IFormaElementaSprKlientDopFisL,
													(void**)&FormaElementaSprKlientDopFisL);
		FormaElementaSprKlientDopFisL->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaSprKlientDopFisL->DM->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
        FormaElementaSprKlientDopFisL->NameKlient=DM->ElementNAMEKLIENT->AsString;
		FormaElementaSprKlientDopFisL->UpdateForm();
		FormaElementaSprKlientDopFisL->NumberProcVibor=ER_DopFisL;
		}

}
//--------------------------------------------------------------------------
void TFormaElementaSprKlient::OpenFormaElementaSprKlientUrL(void)
{
if (DM->elSave==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
if (FormaElementaSprKlientDopUrL==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprKlientDopUrL.1",IID_IFormaElementaSprKlientDopUrL,
													(void**)&FormaElementaSprKlientDopUrL);
		FormaElementaSprKlientDopUrL->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaSprKlientDopUrL->DM->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
		FormaElementaSprKlientDopUrL->NameKlient=DM->ElementNAMEKLIENT->AsString;
		FormaElementaSprKlientDopUrL->UpdateForm();
		FormaElementaSprKlientDopUrL->NumberProcVibor=ER_DopUrL;
		}
}
//--------------------------------------------------------------------------


void __fastcall TFormaElementaSprKlient::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprKlient");	
}
//---------------------------------------------------------------------------

void TFormaElementaSprKlient::ViborVidKlient(void)
{ 

if (FormaSpiskaSprVidKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidKlient.1",IID_IFormaSpiskaSprVidKlient,
													(void**)&FormaSpiskaSprVidKlient);
		FormaSpiskaSprVidKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprVidKlient->Vibor=true;
		FormaSpiskaSprVidKlient->UpdateForm();
		FormaSpiskaSprVidKlient->NumberProcVibor=ER_VidKlient;
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::EndViborVidKlient(void)
{

	DM->Element->Edit();
	DM->ElementIDVIDKLIENT->AsString=FormaSpiskaSprVidKlient->DM->TableID_SVIDKLIENT->AsString;
	DM->ElementNAME_SVIDKLIENT->AsString=FormaSpiskaSprVidKlient->DM->TableNAME_SVIDKLIENT->AsString;
	DM->Element->Post();



}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::VidKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborVidKlient();
}
//---------------------------------------------------------------------------
//выбор страны
void TFormaElementaSprKlient::ViborCountry(void)
{
if (FormaSpiskaSprCountry==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprCountry.1",IID_IFormaSpiskaSprCountry,
													(void**)&FormaSpiskaSprCountry);

		FormaSpiskaSprCountry->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprCountry->Vibor=true;
		FormaSpiskaSprCountry->UpdateForm();
		FormaSpiskaSprCountry->NumberProcVibor=ER_Country;
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::EndViborCountry(void)
{

	DM->Element->Edit();
	DM->ElementIDCOUNTRYKLIENT->AsString=FormaSpiskaSprCountry->DM->TableID_SCOUNTRY->AsString;
	DM->ElementNAME_SCOUNTRY->AsString=FormaSpiskaSprCountry->DM->TableNAME_SCOUNTRY->AsString;
	DM->Element->Post();



}//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::NameCountrycxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCountry();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxButtonOpenSprDiscountCardClick(
      TObject *Sender)
{
if (DM->elSave==false)
        {
        ShowMessage("Необходимо записать элемент!");
        return;
        }
IFormaSpiskaSprDiscountCard * SpisokDiscountCard;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
													(void**)&SpisokDiscountCard);
SpisokDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
SpisokDiscountCard->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
SpisokDiscountCard->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT->AsString));
//SpisokDiscountCard->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
SpisokDiscountCard->NameKlient=DM->ElementNAMEKLIENT->AsString;
SpisokDiscountCard->NumberProcVibor=0;

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::AdresscxDBButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborAdressByKladr();
}
//---------------------------------------------------------------------------

void TFormaElementaSprKlient::ViborAdressByKladr(void)
{
if (FormaKladr==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaKladr.1",IID_IFormaKladr,
													(void**)&FormaKladr);
		FormaKladr->Init(InterfaceMainObject,InterfaceImpl);
		FormaKladr->Vibor=true;
		FormaKladr->NumberProcVibor=ER_Kladr;
	}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::EndViborAdressByKladr(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::cxButtonDogovoraClick(TObject *Sender)
{
if (DM->elSave==false)
        {
        ShowMessage("Необходимо записать элемент!");
        return;
        }
IFormaSpiskaSprDogovor * SpisokDogovor;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&SpisokDogovor);

SpisokDogovor->Init(InterfaceMainObject,InterfaceImpl);
SpisokDogovor->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
SpisokDogovor->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT->AsString));
//SpisokDogovor->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;

SpisokDogovor->NumberProcVibor=0;

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxButtonTelNumClick(TObject *Sender)
{
if (DM->elSave==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
IFormaSpiskaSprNumTel * SpisokNumTel;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNumTel.1",IID_IFormaSpiskaSprNumTel,
													(void**)&SpisokNumTel);
SpisokNumTel->Init(InterfaceMainObject,InterfaceImpl);
SpisokNumTel->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
SpisokNumTel->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT->AsString));
//SpisokNumTel->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
SpisokNumTel->NumberProcVibor=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxButtonRaschSchetaClick(
      TObject *Sender)
{
if (DM->elSave==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
IFormaSpiskaSprRaschSchet * SpisokRSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&SpisokRSchet);
SpisokRSchet->Init(InterfaceMainObject,InterfaceImpl);
SpisokRSchet->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
SpisokRSchet->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT->AsString));
//SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
SpisokRSchet->NumberProcVibor=0;
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprKlient::cxButtonDocClick(TObject *Sender)
{
if (DM->elSave==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
IFormaSpiskaSprDocKlient * SpisokDocKlient;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDocKlient.1",IID_IFormaSpiskaSprDocKlient,
													(void**)&SpisokDocKlient);
SpisokDocKlient->Init(InterfaceMainObject,InterfaceImpl);
SpisokDocKlient->IdKlient=glStrToInt64(DM->ElementIDKLIENT->AsString);
SpisokDocKlient->DM->OpenTable(glStrToInt64(DM->ElementIDKLIENT->AsString));
//SpisokDocKlient->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
SpisokDocKlient->NumberProcVibor=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxButtonDopFLClick(TObject *Sender)
{
if (DM->elSave==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
OpenFormaElementaSprKlientFisL();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxButtonDopULClick(TObject *Sender)
{
OpenFormaElementaSprKlientUrL();	
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprKlient::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	DM->Element->Edit();
	DM->ElementFNAME->AsString=DM->ElementNAMEKLIENT->AsString;
	DM->ElementKRNAME_SKLIENT->AsString=DM->ElementNAMEKLIENT->AsString;
	DM->Element->Post();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprKlient::FNamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprKlient::TelcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::INNcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::OKPOcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::KPPcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}		
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus(); 

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Element->Edit();
		DM->ElementIDTPRICEKLIENT->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Element->Post();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::KrNameKlientcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::ActionOKExecute(TObject *Sender)
{
DM->Element->Edit();
DM->Element->FieldByName("TKLIENT")->AsInteger=TKlient->ItemIndex;
//DM->Element->FieldByName("TPRICEKLIENT")->AsInteger=TPriceKlient->ItemIndex;
DM->Element->Post();
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::ActionSaveExecute(TObject *Sender)
{
DM->Element->Edit();
DM->Element->FieldByName("TKLIENT")->AsInteger=TKlient->ItemIndex;
//DM->Element->FieldByName("TPRICEKLIENT")->AsInteger=TPriceKlient->ItemIndex;
DM->Element->Post();
if (DM->SaveElement()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//выбор группы номенклатуры

void TFormaElementaSprKlient::ViborGrpNom(void)
{
if (FormaSpiskaSprGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaSpiskaSprGrpNom);
		FormaSpiskaSprGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprGrpNom->Vibor=true;
		FormaSpiskaSprGrpNom->UpdateForm();
		FormaSpiskaSprGrpNom->NumberProcVibor=ER_GrpNom;
		}

}
//---------------------------------------------------------------------------
void  TFormaElementaSprKlient::EndViborGrpNom(void)
{
DM->Element->Edit();
DM->ElementIDGRPNOM_SKLIENT->AsString=FormaSpiskaSprGrpNom->DMGrp->ElementIDGN->AsString;
DM->ElementNAMEGN->AsString=FormaSpiskaSprGrpNom->DMGrp->ElementNAMEGN->AsString;
DM->Element->Post();
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprKlient::cxDBButtonEditNAMEGNPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborGrpNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDGRPNOM_SKLIENT->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlient::cxDBButtonEditNAME_REM_SGRP_HARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
//switch (AButtonIndex)
//	{
//	case 0:
//		{
//		ViborCFC();
//		}break;
//	case 1:
//		{
//		//IdNom=0;
//		//NameNomEdit->Text="";
//		DM->Doc->Edit();
//		DM->DocIDCFC_REM_DZAKTPR->Clear();
//		DM->Doc->Post();
//		}break;
//	}
}
//---------------------------------------------------------------------------

