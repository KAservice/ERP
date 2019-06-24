//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaDocVosvratPok.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"

#include "IDMSprPrice.h"
#include "IREM_DMSprModel.h"
#include "IFormaDocVosvratPok.h"
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
__fastcall TREM_FormaDocVosvratPok::TREM_FormaDocVosvratPok(TComponent* Owner)
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
void __fastcall TREM_FormaDocVosvratPok::FormCreate(TObject *Sender)
{



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи



}
//--------------------------------------------------------------------------
bool TREM_FormaDocVosvratPok::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratPok,IID_IREM_DMDocVosvratPok, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

//SumDocDBText->DataSource=DM->DataSourceDocAll;
IdKlientDBText->DataSource=DM->DataSourceDocAll;
NameBaseDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


NameDCardcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientNameStrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientAdrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PassportcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrichinacxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NumDocKlientcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocKlientcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumDocSalecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocSalecxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;




DocOsncxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocOsn;

SumDoccxDBLabel->DataBinding->DataSource=DM->DataSourceDocAll;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
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

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocVosvratPokImpl),false);
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
int TREM_FormaDocVosvratPok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::UpdateForm(void)
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
ProsmotrTextLabel->Caption="";//DM->ProsmotrText;
flNoChangeTypePrice=true;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString));
flNoChangeTypePrice=false;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVosvratPok::FormClose(TObject *Sender,
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
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();


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

void TREM_FormaDocVosvratPok::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString));
		}
}
//-----------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_Nom;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString);
		SpisokNom->UpdateForm();
        }

}

//---------------------------------------------------------------------------
int TREM_FormaDocVosvratPok::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOM_REM_DVPOKT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
				DM->DocTKOL_REM_DVPOKT->AsFloat=1;

				DM->DocTIDED_REM_DVPOKT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DVPOKT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;

				DM->DocTPRICE_REM_DVPOKT->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat
												*DM->DocTKF_REM_DVPOKT->AsFloat;
				DM->DocT->Post();
                }
		SpisokNom=0;

		cxGrid1DBTableView1KOL_REM_DVPOKT->Selected=true;
		cxGrid1->SetFocus();
        }

if (number_procedure_end==ER_Ed)//==ViborEdinica)
        {
		if (type_event==1)
                {
				DM->DocT->Edit();
				DM->DocTIDED_REM_DVPOKT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_REM_DVPOKT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString));
				DM->DocTPRICE_REM_DVPOKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DVPOKT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
				}
		SpisokEd=0;

		cxGrid1DBTableView1PRICE_REM_DVPOKT->Selected=true;
		cxGrid1->SetFocus();
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

if (number_procedure_end==ER_Klient)//EditRekvisit==ViborKlient)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();
				if (glStrToInt64(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsString)!=0)
					{
					TypePriceComboBox->ItemIndex=
						DMSprTypePrice->GetIndexTypePricePoId(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsInt64);
					}
                }
		SpisokKlient=0;
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

if (number_procedure_end==ER_Card)
		{
		if (type_event==1)
				{
				EndViborDiscountCard();
				}
		FormaSpiskaSprDiscountCard=0;
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

if (number_procedure_end==ER_ViborDocOsn)
		{
		if (type_event==1)
				{
				EndInputIdHW();
				}
		FormaInputText=0;
		}

ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------

void TREM_FormaDocVosvratPok::OpenFormSpiskaSprFirm(void)
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
void TREM_FormaDocVosvratPok::OpenFormSpiskaSprSklad(void)
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
void TREM_FormaDocVosvratPok::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
		SpisokKlient->NumberProcVibor=ER_Klient;
		}
}
//--------------------------------------------------------------------------


void TREM_FormaDocVosvratPok::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TREM_FormaDocVosvratPok::ViborBaseButtonClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocVosvratPok::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------








void __fastcall TREM_FormaDocVosvratPok::TypePriceComboBoxPropertiesChange(
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
		DM->DocIDTYPEPRICE_REM_DVPOK->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString));
						DM->DocTPRICE_REM_DVPOKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DVPOKT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
		
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVosvratPok::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();    	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVosvratPok::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------



void TREM_FormaDocVosvratPok::ViborDiscountCard(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprDiscountCard==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
													(void**)&FormaSpiskaSprDiscountCard);
		FormaSpiskaSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDiscountCard->IdKlient=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
		FormaSpiskaSprDiscountCard->DM->OpenTable(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));
		//FormaSpiskaSprDiscountCard->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->NameKlient=DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->Vibor=true;
		FormaSpiskaSprDiscountCard->NumberProcVibor=ER_Card;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVosvratPok::EndViborDiscountCard(void)
{

	DM->Doc->Edit();
	DM->DocIDCARD_REM_DVPOK->AsString=FormaSpiskaSprDiscountCard->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->DocNAME_SDISCOUNT_CARD->AsString=FormaSpiskaSprDiscountCard->DM->TableNAME_SDISCOUNT_CARD->AsString;
    DM->Doc->Post();


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::NameDCardcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborDiscountCard();	
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocVosvratPok::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVosvratPok::OplNalcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::OplPCcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::NalCHKcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::ActionInsertStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}

//----------------------------------------------------------------------------

//Внешние модули
void __fastcall TREM_FormaDocVosvratPok::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::RunExternalModule(__int64 id_module, int type_module)
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



void __fastcall TREM_FormaDocVosvratPok::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocVosvratPok::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocVosvratPok::ActionSaveExecute(TObject *Sender)
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

void TREM_FormaDocVosvratPok::OpenFormSpiskaSprProject(void)
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
void __fastcall TREM_FormaDocVosvratPok::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TREM_FormaDocVosvratPok::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVosvratPok::NameProjectcxDBButtonEditPropertiesButtonClick(
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
void __fastcall TREM_FormaDocVosvratPok::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void TREM_FormaDocVosvratPok::ViborHardware(void)
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
void TREM_FormaDocVosvratPok::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DVPOKT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVosvratPok::ReadShtrihCodEvent(int number, UnicodeString sh)
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
	ob_bar->IdTypePrice=glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString);
	ob_bar->ObrabotatShtrihCod(bar_code);

	if (ob_bar->OutReady==true)
		{
		DM->AddDocNewString();
		DM->DocT->Edit();

		DM->DocTIDNOM_REM_DVPOKT->AsString = dm_nom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;

		DM->DocTIDED_REM_DVPOKT->AsString = dm_ed->ElementIDED->AsString;
		DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
		DM->DocTKF_REM_DVPOKT->AsFloat = dm_ed->ElementKFED->AsFloat;

		DM->DocTKOL_REM_DVPOKT->AsFloat=ob_bar->Kol;

		//получим цену
		IDMSprPrice * dm_price;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
		dm_price->Init(InterfaceMainObject,InterfaceImpl);

		DM->DocTPRICE_REM_DVPOKT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DVPOKT->AsString),    // единица
						DM->DocTKF_REM_DVPOKT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


		dm_price->kanRelease();
		DM->DocT->Post();

		VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
		VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

		cxGrid1->Focused();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_REM_DVPOKT->Focused=true;
		cxGrid1DBTableView1KOL_REM_DVPOKT->Selected=true;
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
void __fastcall TREM_FormaDocVosvratPok::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaDocVosvratPok::FormDeactivate(TObject *Sender)
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

void TREM_FormaDocVosvratPok::ObrabotatReadBarCodeHardware(UnicodeString sh)
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

					DM->DocTIDNOM_REM_DVPOKT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DVPOKT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DVPOKT->AsFloat = dm_ed->ElementKFED->AsFloat;
                	DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DVPOKT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DVPOKT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DVPOKT->AsString),    // единица
						DM->DocTKF_REM_DVPOKT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DVPOKT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

					cxGrid1->Focused();
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOL_REM_DVPOKT->Focused=true;
					cxGrid1DBTableView1KOL_REM_DVPOKT->Selected=true;

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
void __fastcall TREM_FormaDocVosvratPok::ActionChangeERBCExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocVosvratPok::ActionOpenFormArmKassirExecute(TObject *Sender)

{
//	IFormaArmKassir * form_kas;
//	InterfaceGlobalCom->kanCreateObject(ProgId_FormaArmKassir,IID_IFormaArmKassir,
//													(void**)&form_kas);
//	form_kas->Init(InterfaceMainObject,InterfaceImpl);
//
//	form_kas->CreateNewDocCheck();
//	form_kas->CreateCheckNaOsnRealRemont(glStrToInt64(DM->DocAllID_REM_GALLDOC->AsString));
//	form_kas->DM->DocAll->Edit();
//	form_kas->DM->DocAllIDEXTDOC->AsString=DM->DocAllID_REM_GALLDOC->AsString;
//    form_kas->DM->DocAllTYPEEXTDOC->AsInteger=GC_TypeSubSystem_Remont;
//	form_kas->DM->DocAll->Post();

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVosvratPok::ActionAddHWPoCoduExecute(TObject *Sender)
{
OpenFormInputCodeHW();
}
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocVosvratPok::OpenFormInputCodeHW(void)
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
void TREM_FormaDocVosvratPok::EndInputCodeHW(void)
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

					DM->DocTIDNOM_REM_DVPOKT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DVPOKT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DVPOKT->AsFloat = dm_ed->ElementKFED->AsFloat;
					DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DVPOKT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DVPOKT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DVPOKT->AsString),    // единица
						DM->DocTKF_REM_DVPOKT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DVPOKT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

					cxGrid1->Focused();
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOL_REM_DVPOKT->Focused=true;
					cxGrid1DBTableView1KOL_REM_DVPOKT->Selected=true;

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
void TREM_FormaDocVosvratPok::OpenFormInputIdHW(void)
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
void __fastcall TREM_FormaDocVosvratPok::ActionAddPoIdExecute(TObject *Sender)
{
OpenFormInputIdHW();
}
//---------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::EndInputIdHW(void)
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

					DM->DocTIDNOM_REM_DVPOKT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;

					DM->DocTIDED_REM_DVPOKT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DVPOKT->AsFloat = dm_ed->ElementKFED->AsFloat;
                	DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DVPOKT->AsFloat=1;

					//получим цену
					IDMSprPrice * dm_price;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
					dm_price->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DVPOKT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTYPEPRICE_REM_DVPOK->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_REM_DVPOKT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_REM_DVPOKT->AsString),    // единица
						DM->DocTKF_REM_DVPOKT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


					dm_price->kanRelease();

					DM->DocTIDHW_REM_DVPOKT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
                    DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;
					DM->DocT->Post();

					VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
					VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

					cxGrid1->Focused();
					cxGrid1->SetFocus();
					cxGrid1DBTableView1KOL_REM_DVPOKT->Focused=true;
					cxGrid1DBTableView1KOL_REM_DVPOKT->Selected=true;

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

void __fastcall TREM_FormaDocVosvratPok::ToolButtonCreateDocVosvratPokClick(TObject *Sender)

{
DM->SaveDoc();
//проверим а нет ли уже счета
IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add("select IDDOC from GALLDOC where TDOC='VPOK'");
DMQueryRead->pFIBQ->SQL->Add(" and IDEXTDOC="+DM->DocAllID_REM_GALLDOC->AsString);
DMQueryRead->pFIBQ->SQL->Add(" and TYPEEXTDOC=2");
DMQueryRead->pFIBQ->ExecQuery();

IFormaDocVosvratPok* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocVosvratPok,IID_IFormaDocVosvratPok,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

if (DMQueryRead->pFIBQ->RecordCount!=0)
        {
		 //откроем документ
		doc->DM->OpenDoc(DMQueryRead->pFIBQ->FieldByName("IDDOC")->AsInt64);
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
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLIENT_REM_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDRTPRICE_DVPOK->AsString=DM->DocIDTYPEPRICE_REM_DVPOK->AsString;
doc->DM->DocDESCR_DVPOK->AsString="Возрат покупателя (ремонт) №"+DM->DocAllNUM_REM_GALLDOC->AsString+
						" от "+ DM->DocAllPOS_REM_GALLDOC->AsString;
doc->DM->DocKLIENT_NAME_DVPOK->AsString=DM->DocKLIENT_NAME_REM_DVPOK->AsString;
doc->DM->DocKLIENT_ADR_DVPOK->AsString=DM->DocKLIENT_ADR_REM_DVPOK->AsString;
doc->DM->DocKLIENT_PHONE_DVPOK->AsString=DM->DocKLIENT_PHONE_REM_DVPOK->AsString;
doc->DM->DocKLIENT_PASSPORT_DVPOK->AsString=DM->DocKLIENT_PASSPORT_REM_DVPOK->AsString;
doc->DM->DocNUMDOCKL_DVPOK->AsString=DM->DocNUMDOCKL_REM_DVPOK->AsString;
doc->DM->DocPOSDOCKL_DVPOK->AsDateTime=DM->DocPOSDOCKL_REM_DVPOK->AsDateTime;
doc->DM->DocNUMDOCSALE_DVPOK->AsString=DM->DocNUMDOCSALE_REM_DVPOK->AsString;
doc->DM->DocPOSDOCSALE_DVPOK->AsDateTime=DM->DocPOSDOCSALE_REM_DVPOK->AsDateTime;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		doc->DM->DocT->Append();
		doc->DM->DocTIDNOM_DVPOKT->AsString=DM->DocTIDNOM_REM_DVPOKT->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDED_DVPOKT->AsString=DM->DocTIDED_REM_DVPOKT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTKOL_DVPOKT->AsFloat=DM->DocTKOL_REM_DVPOKT->AsFloat;
		doc->DM->DocTKF_DVPOKT->AsFloat=DM->DocTKF_REM_DVPOKT->AsFloat;
		doc->DM->DocTPRICE_DVPOKT->AsFloat=DM->DocTPRICE_REM_DVPOKT->AsFloat;
		doc->DM->DocT->Post();
		DM->DocT->Next();
		}
		}
doc->UpdateForm();

DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVosvratPok::DocOsncxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDocOsn();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDDOCOSN_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		DM->OpenDocOsn();
		}break;
	}
}
//---------------------------------------------------------------------------

void TREM_FormaDocVosvratPok::ViborDocOsn(void)
{

if (Prosmotr==true) return;
if (FormaGurAllDoc==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
		FormaGurAllDoc->Vibor=true;
		FormaGurAllDoc->NumberProcVibor=ER_ViborDocOsn;
		}
}
//----------------------------------------------------------------------------
void TREM_FormaDocVosvratPok::EndViborDocOsn(void)
{


	DM->DocAll->Edit();
				DM->DocAllIDDOCOSN_REM_GALLDOC->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
				DM->DocAll->Post();
				DM->OpenDocOsn();



}
//----------------------------------------------------------------------------
