//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaDocSborkaKompl.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"

#include "IDMSprPrice.h"
#include "IREM_DMSprModel.h"
#include "IFormaDocSborkaKompl.h"
#include "IDMQueryRead.h"
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
#pragma link "cxCalendar"
#pragma link "cxPC"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxDBExtLookupComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxCheckGroup"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDBEdit"
#pragma link "cxDBLabel"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxImageComboBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxPC"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaDocSborkaKompl::TREM_FormaDocSborkaKompl(TComponent* Owner)
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
void __fastcall TREM_FormaDocSborkaKompl::FormCreate(TObject *Sender)
{



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи



}
//--------------------------------------------------------------------------
bool TREM_FormaDocSborkaKompl::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSborkaKompl,IID_IREM_DMDocSborkaKompl, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


NameBaseDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;




DocOsncxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocOsn;

SumDoccxDBLabel->DataBinding->DataSource=DM->DataSourceDocAll;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameHWcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
KFcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
KolcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
RPricecxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameEdcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

ActionOperation=aoNO;

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

flNoChangeTypePrice=false;

//cxGrid1DBTableView1NDS_DCHKT->Visible=DM_Connection->glShowNDS;
//cxGrid1DBTableView1SUMNDS_DCHKT->Visible=DM_Connection->glShowNDS;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocSborkaKomplImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}
result=true;


EditRekvisitBarCode=ERBC_Nom;
LabelEditRekvisitBarCode->Caption="ШК: Номенклатура";

return result;
}

//--------------------------------------------------------------------------
int TREM_FormaDocSborkaKompl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::UpdateForm(void)
{


Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		}
else
		{
		ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		}
ProsmotrTextLabel->Caption=DM->ProsmotrText;
flNoChangeTypePrice=true;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString));
flNoChangeTypePrice=false;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprDiscountCard)FormaSpiskaSprDiscountCard->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();

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
DMTableExtPrintForm->kanRelease();



Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}


}
//---------------------------------------------------------------------------

void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString));
		}
}
//-----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_Nom;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString);
		SpisokNom->UpdateForm();
        }

}

//---------------------------------------------------------------------------
int TREM_FormaDocSborkaKompl::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)//==ViborTovar)
		{

		if (type_event==1)
				{
				if (ActionOperation==aoAddNewString)
						{
						DM->AddDocNewString();
						}
				DM->DocT->Edit();
				DM->DocTIDNOM_REM_DSBKOMPLT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_REM_DSBKOMPLT->AsFloat=1;

				DM->DocTIDED_REM_DSBKOMPLT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DSBKOMPLT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;

				DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat
												*DM->DocTKF_REM_DSBKOMPLT->AsFloat;

				DM->DocT->Post();
                }
		SpisokNom=0;

        }

if (number_procedure_end==ER_Ed)//==ViborEdinica)
        {
		if (type_event==1)
                {
				DM->DocT->Edit();
				DM->DocTIDED_REM_DSBKOMPLT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_REM_DSBKOMPLT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString));
				DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DSBKOMPLT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
				}
		SpisokEd=0;

		}

if (number_procedure_end==ER_Firm)//==ViborFirm)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDFIRM_REM_GALLDOC->AsString=SpisokFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
				}
		SpisokFirm=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//EditRekvisit==ViborSklad)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLAD_REM_GALLDOC->AsString=SpisokSklad->DM->ElementIDSKLAD->AsString;
				DM->DocAllNAMESKLAD->AsString=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                DM->DocAll->Post();
                }
		SpisokSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_InfBase)//EditRekvisit==ViborInfBase)
		{
		if (type_event==1)
				{
				DM->DocAll->Edit();
				DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
				DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
				DM->DocAll->Post();
				}
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_InputCodeHW)
		{
		if (type_event==1)
				{
				EndInputCodeHW();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_InputIdHW)
		{
		if (type_event==1)
				{
				EndInputIdHW();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_NomKompl)
		{
		if (type_event==1)
				{
				EndViborNomKompl();
				}
		SpisokNom=0;
		}

if (number_procedure_end==ER_HardwareKompl)
		{
		if (type_event==1)
				{
				EndViborHardwareKompl();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_EdKompl)
		{
		if (type_event==1)
				{
				EndViborEdKompl();
				}
		SpisokEd=0;
		}

ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------

void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ER_Firm;
        }

}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ER_Sklad;
        }

}
//--------------------------------------------------------------------------


void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		}
}
//---------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ViborBaseButtonClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocSborkaKompl::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------








void __fastcall TREM_FormaDocSborkaKompl::TypePriceComboBoxPropertiesChange(
	  TObject *Sender)
{
if (flNoChangeTypePrice==true) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

//if (NoEdit==true)
//        {
//        UpdateForm();
//         return;
//        }

if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_REM_DSBKOMPL->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString));
						DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DSBKOMPLT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
		
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocSborkaKompl::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();    	
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocSborkaKompl::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------




//----------------------------------------------------------------------------




void __fastcall TREM_FormaDocSborkaKompl::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocSborkaKompl::OplNalcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::OplPCcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::NalCHKcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionInsertStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}

//----------------------------------------------------------------------------

//Внешние модули
void __fastcall TREM_FormaDocSborkaKompl::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_REM_GALLDOC->AsString));

	
module->ExecuteModule();
}


//----------------------------------------------------------------------------

//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocSborkaKompl::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}

if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}

if (DM->SaveDoc()==true)
		{
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::NameProjectcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}

}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::ViborHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DSBKOMPLT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::ReadShtrihCodEvent(int number, UnicodeString sh)
{
//*****************
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	return;
	}

UnicodeString bar_code=sh;

if (EditRekvisitBarCode==ERBC_Nom)
	{
	//если считали обычный штрих код EAN13
	IObjectBarCode * ob_bar;
	InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
	ob_bar->Init(InterfaceMainObject,InterfaceImpl);

	IDMSprNom * dm_nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
	dm_nom->Init(InterfaceMainObject,InterfaceImpl);

	IDMSprEd * dm_ed;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
	dm_ed->Init(InterfaceMainObject,InterfaceImpl);

	ob_bar->SprNom=dm_nom;
	ob_bar->SprEd=dm_ed;
	ob_bar->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString);
	ob_bar->ObrabotatShtrihCod(bar_code);

	if (ob_bar->OutReady==true)
		{
		DM->AddDocNewString();
		DM->DocT->Edit();

		DM->DocTIDNOM_REM_DSBKOMPLT->AsString = dm_nom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

		DM->DocTIDED_REM_DSBKOMPLT->AsString = dm_ed->ElementIDED->AsString;
		DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
		DM->DocTKF_REM_DSBKOMPLT->AsFloat = dm_ed->ElementKFED->AsFloat;

		DM->DocTKOL_REM_DSBKOMPLT->AsFloat=ob_bar->Kol;

		//получим цену
		IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
		dm_price->Init(InterfaceMainObject,InterfaceImpl);

		DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DSBKOMPLT->AsString),    // единица
						DM->DocTKF_REM_DSBKOMPLT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


		dm_price->kanRelease();

		DM->DocT->Post();

		VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
		VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

		}
	else
		{
		 ShowMessage(ob_bar->TextError);
		}
	ob_bar->kanRelease();
	dm_nom->kanRelease();
	dm_ed->kanRelease();
	}

if (EditRekvisitBarCode==ERBC_HW)
	{
	ObrabotatReadBarCodeHardware(bar_code);
	}

}
//---------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject > 0)
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

void __fastcall TREM_FormaDocSborkaKompl::FormDeactivate(TObject *Sender)
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

void TREM_FormaDocSborkaKompl::ObrabotatReadBarCodeHardware(UnicodeString sh)
{

UnicodeString bar_code=sh;


__int64 id_hw=glStrToInt64(glDelSymbolOfBarCode(bar_code));

if (id_hw > 0)
	{
	IREM_DMSprHardware * dm_hw;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&dm_hw);
	dm_hw->Init(InterfaceMainObject,InterfaceImpl);
	if (dm_hw->OpenElement(id_hw) > 0)
		{
		__int64 id_model=glStrToInt64(dm_hw->ElementIDMODEL_REM_SHARDWARE->AsString);
		if (id_model > 0)
			{
			IREM_DMSprModel * dm_model;
			InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel,IID_IREM_DMSprModel,
													(void**)&dm_model);
			dm_model->Init(InterfaceMainObject,InterfaceImpl);
			if (dm_model->OpenElement(id_model) > 0)
				{
				__int64 id_nom=glStrToInt64(dm_model->ElementIDNOM_REM_SMODEL->AsString);
				if (id_nom > 0)
					{
					//добавляем строку
					IDMSprNom * dm_nom;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
					dm_nom->Init(InterfaceMainObject,InterfaceImpl);
					dm_nom->OpenElement(id_nom);

					IDMSprEd * dm_ed;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
					dm_ed->Init(InterfaceMainObject,InterfaceImpl);
					dm_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
					DM->AddDocNewString();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DSBKOMPLT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DSBKOMPLT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DSBKOMPLT->AsFloat = dm_ed->ElementKFED->AsFloat;
                	DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DSBKOMPLT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DSBKOMPLT->AsString),    // единица
						DM->DocTKF_REM_DSBKOMPLT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DSBKOMPLT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

					dm_nom->kanRelease();
					dm_ed->kanRelease();
					}
				else
					{
                    ShowMessage("У найденной модели не задан реквизит Номенклатура! IDModel - "+IntToStr(id_model));
					}
				}
			else
				{
                ShowMessage("Не найден элемент справочника Модели! ID - "+IntToStr(id_model));
				}
            dm_model->kanRelease();
			}
		else
			{
			ShowMessage("У найденного элемента не задан реквизит Модель! IDHW - "+IntToStr(id_hw));
			}
		 }
	else
		{
		ShowMessage("Не найден элемент в справочнике Оборудование! IDHW - "+IntToStr(id_hw));
		}
	dm_hw->kanRelease();
	}
else
	{
    ShowMessage("Ощибка при получении IDHW! IDHW - "+IntToStr(id_hw));
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::ActionChangeERBCExecute(TObject *Sender)
{
if (EditRekvisitBarCode==ERBC_Nom)
	{
	EditRekvisitBarCode=ERBC_HW;
	LabelEditRekvisitBarCode->Caption="ШК: Оборудование";
	}
else
	{
	EditRekvisitBarCode=ERBC_Nom;
	LabelEditRekvisitBarCode->Caption="ШК: Номенклатура";
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocSborkaKompl::ActionAddHWPoCoduExecute(TObject *Sender)
{
OpenFormInputCodeHW();
}
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocSborkaKompl::OpenFormInputCodeHW(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
//ActionOperation=aoAddNewString;

if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=ER_InputCodeHW;
		FormaInputText->Vibor=true;
		FormaInputText->TextMessage="Код оборудования:";
		FormaInputText->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndInputCodeHW(void)
{
__int64 id_hw=0;
int code=0;

if (FormaInputText->InputText !="")
	{
	code=StrToInt(FormaInputText->InputText);
	}


	IREM_DMSprHardware * dm_hw;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&dm_hw);
	dm_hw->Init(InterfaceMainObject,InterfaceImpl);
    //ищем по коду, получаем id
	id_hw=dm_hw->GetIdPoCodu(code);
if (id_hw !=0)
	{
	if (dm_hw->OpenElement(id_hw) > 0)
		{
		__int64 id_model=glStrToInt64(dm_hw->ElementIDMODEL_REM_SHARDWARE->AsString);
		if (id_model > 0)
			{
			IREM_DMSprModel * dm_model;
			InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel,IID_IREM_DMSprModel,
													(void**)&dm_model);
			dm_model->Init(InterfaceMainObject,InterfaceImpl);
			if (dm_model->OpenElement(id_model) > 0)
				{
				__int64 id_nom=glStrToInt64(dm_model->ElementIDNOM_REM_SMODEL->AsString);
				if (id_nom > 0)
					{
					//добавляем строку
					IDMSprNom * dm_nom;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
					dm_nom->Init(InterfaceMainObject,InterfaceImpl);
					dm_nom->OpenElement(id_nom);

					IDMSprEd * dm_ed;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
					dm_ed->Init(InterfaceMainObject,InterfaceImpl);
                    dm_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));

					DM->AddDocNewString();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DSBKOMPLT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DSBKOMPLT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DSBKOMPLT->AsFloat = dm_ed->ElementKFED->AsFloat;
					DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DSBKOMPLT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DSBKOMPLT->AsString),    // единица
						DM->DocTKF_REM_DSBKOMPLT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DSBKOMPLT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);


					dm_nom->kanRelease();
					dm_ed->kanRelease();
					}
				else
					{
					ShowMessage("У найденной модели не задан реквизит Номенклатура! IDModel - "+IntToStr(id_model));
					}
				}
			else
				{
                ShowMessage("Не найден элемент справочника Модели! ID - "+IntToStr(id_model));
				}
			dm_model->kanRelease();
			}
		else
			{
			ShowMessage("У найденного элемента не задан реквизит Модель! IDHW - "+IntToStr(id_hw));
			}
		 }
	else
		{
		ShowMessage("Не найден элемент в справочнике Оборудование! IDHW - "+IntToStr(id_hw));
		}
	}
else
	{
	ShowMessage("Не найден элемент в справочнике Оборудование с кодом "+IntToStr(code)+"!");
	}

	dm_hw->kanRelease();


}
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocSborkaKompl::OpenFormInputIdHW(void)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
//ActionOperation=aoAddNewString;

if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=ER_InputIdHW;
		FormaInputText->Vibor=true;
		FormaInputText->TextMessage="Номер стикера:";
		FormaInputText->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::ActionAddPoIdExecute(TObject *Sender)
{
OpenFormInputIdHW();
}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndInputIdHW(void)
{
__int64 id_hw=glStrToInt64(FormaInputText->InputText);

if (id_hw > 0)
	{
	IREM_DMSprHardware * dm_hw;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&dm_hw);
	dm_hw->Init(InterfaceMainObject,InterfaceImpl);
	if (dm_hw->OpenElement(id_hw) > 0)
		{
		__int64 id_model=glStrToInt64(dm_hw->ElementIDMODEL_REM_SHARDWARE->AsString);
		if (id_model > 0)
			{
			IREM_DMSprModel * dm_model;
			InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel,IID_IREM_DMSprModel,
													(void**)&dm_model);
			dm_model->Init(InterfaceMainObject,InterfaceImpl);
			if (dm_model->OpenElement(id_model) > 0)
				{
				__int64 id_nom=glStrToInt64(dm_model->ElementIDNOM_REM_SMODEL->AsString);
				if (id_nom > 0)
					{
					//добавляем строку
					IDMSprNom * dm_nom;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
					dm_nom->Init(InterfaceMainObject,InterfaceImpl);
					dm_nom->OpenElement(id_nom);

					IDMSprEd * dm_ed;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
					dm_ed->Init(InterfaceMainObject,InterfaceImpl);
                    dm_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));

					DM->AddDocNewString();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DSBKOMPLT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DSBKOMPLT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DSBKOMPLT->AsFloat = dm_ed->ElementKFED->AsFloat;
                	DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DSBKOMPLT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTRPRICE_REM_DSBKOMPLT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DSBKOMPLT->AsString),    // единица
						DM->DocTKF_REM_DSBKOMPLT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DSBKOMPLT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);


					dm_nom->kanRelease();
					dm_ed->kanRelease();
					}
				else
					{
                    ShowMessage("У найденной модели не задан реквизит Номенклатура! IDModel - "+IntToStr(id_model));
					}
				}
			else
				{
                ShowMessage("Не найден элемент справочника Модели! ID - "+IntToStr(id_model));
				}
            dm_model->kanRelease();
			}
		else
			{
			ShowMessage("У найденного элемента не задан реквизит Модель! IDHW - "+IntToStr(id_hw));
			}
		 }
	else
		{
		ShowMessage("Не найден элемент в справочнике Оборудование! IDHW - "+IntToStr(id_hw));
		}
	dm_hw->kanRelease();
	}

}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::ViborHardwareKompl(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_HardwareKompl;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndViborHardwareKompl(void)
{

	DM->Doc->Edit();
	DM->DocIDHW_REM_DSBKOMPL->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->Doc->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::ViborNomKompl(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_NomKompl;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString);
		SpisokNom->UpdateForm();
        }

}
//-----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndViborNomKompl(void)
{

	DM->Doc->Edit();
	DM->DocIDNOM_REM_DSBKOMPL->AsString=SpisokNom->DM->TableIDNOM->AsString;
	DM->DocNAMENOM->AsString=SpisokNom->DM->TableNAMENOM->AsString;
	DM->DocIDED_REM_DSBKOMPL->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
	DM->DocNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
	DM->DocKF_REM_DSBKOMPL->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
	DM->Doc->Post();

SpisokNom=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNomKompl();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::NameHWcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardwareKompl();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocSborkaKompl::ActionCreateDocSborkaKomplExecute(TObject *Sender)

{
DM->SaveDoc();
//проверим а нет ли уже счета
IDMQueryRead * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='SBKOMPL'");
q->pFIBQ->SQL->Add(" and IDEXTDOC="+DM->DocAllID_REM_GALLDOC->AsString);
q->pFIBQ->SQL->Add(" and TYPEEXTDOC=2");
q->pFIBQ->ExecQuery();

__int64 id_doc_sborka_kompl=glStrToInt64(q->pFIBQ->FieldByName("IDDOC")->AsString);
q->kanRelease();

IFormaDocSborkaKompl* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocSborkaKompl,IID_IFormaDocSborkaKompl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;


//doc->Vibor=true;
//doc->NumberProcVibor=ER_CreateCheck;

if (id_doc_sborka_kompl!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(id_doc_sborka_kompl);
		}
else
		{
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();

doc->DM->DocAllIDEXTDOC->AsString=DM->DocAllID_REM_GALLDOC->AsString;
doc->DM->DocAllTYPEEXTDOC->AsInteger=2;

doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_REM_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;

doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLAD_REM_GALLDOC->AsInteger;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDRTPRICE_DSBKOMPL->AsString=DM->DocIDRTPRICE_REM_DSBKOMPL->AsString;
doc->DM->DocDESCR_DSBKOMPL->AsString="Сборка комплекта Ремонт №"+DM->DocAllNUM_REM_GALLDOC->AsString+
						" от "+ DM->DocAllPOS_REM_GALLDOC->AsString;

doc->DM->DocIDNOM_DSBKOMPL->AsString=DM->DocIDNOM_REM_DSBKOMPL->AsString;
doc->DM->DocNAMENOM->AsString=DM->DocNAMENOM->AsString;
doc->DM->DocIDED_DSBKOMPL->AsString=DM->DocIDED_REM_DSBKOMPL->AsString;
doc->DM->DocNAMEED->AsString=DM->DocNAMEED->AsString;
doc->DM->DocKOL_DSBKOMPL->AsFloat=DM->DocKOL_REM_DSBKOMPL->AsFloat;
doc->DM->DocKF_DSBKOMPL->AsFloat=DM->DocKF_REM_DSBKOMPL->AsFloat;
doc->DM->DocRPRICE_DSBKOMPL->AsFloat=DM->DocRPRICE_REM_DSBKOMPL->AsFloat;

doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		doc->DM->DocT->Append();
		doc->DM->DocTIDNOM_DSBKOMPLT->AsString=DM->DocTIDNOM_REM_DSBKOMPLT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDED_DSBKOMPLT->AsString=DM->DocTIDED_REM_DSBKOMPLT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOL_DSBKOMPLT->AsFloat=DM->DocTKOL_REM_DSBKOMPLT->AsFloat;
		doc->DM->DocTKF_DSBKOMPLT->AsFloat=DM->DocTKF_REM_DSBKOMPLT->AsFloat;

		//получим цену
		IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
		dm_price->Init(InterfaceMainObject,InterfaceImpl);

		doc->DM->DocTRPRICE_DSBKOMPLT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_REM_DSBKOMPL->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DSBKOMPLT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DSBKOMPLT->AsString),    // единица
						DM->DocTKF_REM_DSBKOMPLT->AsFloat,                   // коэффициент единицы
						0); //базовая единица


		dm_price->kanRelease();
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

}
//---------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::ViborEdKompl(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_EdKompl;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocIDNOM_REM_DSBKOMPL->AsString));
		}
}
//-----------------------------------------------------------------------------
void TREM_FormaDocSborkaKompl::EndViborEdKompl(void)
{

	DM->Doc->Edit();
	DM->DocIDED_REM_DSBKOMPL->AsString=SpisokEd->DM->TableIDED->AsString;
    DM->DocKF_REM_DSBKOMPL->AsFloat=SpisokEd->DM->TableKFED->AsFloat;
	DM->DocNAMEED->AsString=SpisokEd->DM->TableNAMEED->AsString;
	DM->Doc->Post();

SpisokEd=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocSborkaKompl::NameEdcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborEdKompl();
}
//---------------------------------------------------------------------------

