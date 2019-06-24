//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocZAktPr.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSprPrice.h"
#include "IFormaRunExternalModule.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
#include "IFormaImageEditor.h"
#include "IREM_DMGurAllDoc.h"
#include "IREM_DMDocZStart.h"
#include "IREM_DMDocZEnd.h"
#include "IREM_FormaZayavka.h"
#include "IREM_FormaDocRemont.h"
#include "IDMQueryRead.h"

#include "IREM_DMSprModel.h"
#include "IREM_FormaDocZVosvrZap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxDBLabel"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma link "cxMemo"
#pragma link "cxPC"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocZAktPr::TREM_FormaDocZAktPr(TComponent* Owner)
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
bool TREM_FormaDocZAktPr::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZAktPr,IID_IREM_DMDocZAktPr, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

//cxGrid1DBTableView1
cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

DBTextSUM_REM_GALLDOC->DataSource=DM->DataSourceDocAll;

ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
TypeRemontcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
KEM_SDANOcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
NumGTcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum3cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum4cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
DateVipuskcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
DateProdagicxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumBatcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SOSTcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProducerModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProdaveccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
CFCcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
DFCcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PODOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
POPOSLEcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameSSellercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

OtchetPostcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
NamePostZipcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
cxDBCheckBoxFL_OST_NA_OTV_XRAN_REM_DZAKTPR->DataBinding->DataSource=DM->DataSourceDoc;

//розничный тип цен
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();

TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypeRPrice->DataSourceTable;

NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameKlientcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NeisprcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NeisprZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


FictivcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
SerNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientNаmecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
ClientAdrcxDBMemo->DataBinding->DataSource=DM->DataSourceDoc;

flNeOtchcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
flNadoOtchcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;

PrigKGarRemontucxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;


CodePrModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameGrpCFCcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
CodeNeisprPrcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

PosPriemacxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;

Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;





//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocZAktPrImpl),false);
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

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaDocZAktPr::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(FormaSpiskaSprSeller)FormaSpiskaSprSeller->kanRelease();
if(FormaSpiskaSprProducerModel)FormaSpiskaSprProducerModel->kanRelease();
if(FormaSpiskaSprProducerNeispr)FormaSpiskaSprProducerNeispr->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprProducerDefect)FormaSpiskaSprProducerDefect->kanRelease();
if(FormaSpiskaSprProducerRabota)FormaSpiskaSprProducerRabota->kanRelease();
if(FormaInputText)FormaInputText->kanRelease();
if(FormaElementaSprHW) FormaElementaSprHW->kanRelease();
if (FormaSpiskaSprTypUslov>0) FormaSpiskaSprTypUslov->kanRelease();
if(FormaSpiskaSprStorageLocation)FormaSpiskaSprStorageLocation->kanRelease();

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
DMSprTypeRPrice->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocZAktPr::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)
				{
				EndViborInfBase();
				}
		FormaSpiskaSprInfBase=0;
		}

if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)
				{
				EndViborFirm();
				}
		FormaSpiskaSprFirm=0;
		}

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EndViborKlient();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Zayavka)
		{
		if (type_event==1)
				{
				EndViborRemZ();
				}
		FormaGurZ=0;
		}

if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)
				{
				EndViborNom();
				}
		FormaSpiskaSprNom=0;
		}

if (number_procedure_end==ER_Ed)
		{
		if (type_event==1)
				{
				EndViborEd();
				}
		FormaSpiskaSprEd=0;
		}



if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer();
				}
		FormaSpiskaSprProducer=0;
		}

if (number_procedure_end==ER_ViborSeller)
		{
		if (type_event==1)
				{
				EndViborSeller();
				}
		FormaSpiskaSprSeller=0;
		}

if (number_procedure_end==ER_ViborProducerModel)
		{
		if (type_event==1)
				{
				EndViborProducerModel();
				}
		FormaSpiskaSprProducerModel=0;
		}


if (number_procedure_end==ER_ViborCFC)
		{
		if (type_event==1)
				{
				EndViborCFC();
				}
		FormaSpiskaSprProducerNeispr=0;
		}

if (number_procedure_end==ER_ViborDFC)
		{
		if (type_event==1)
				{
				EndViborDFC();
				}
		FormaSpiskaSprProducerNeispr=0;
		}

if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}


if (number_procedure_end==ER_ProducerDefect)
		{
		if (type_event==1)
				{
				EndViborProducerDefect();
				}
		FormaSpiskaSprProducerDefect=0;
		}

if (number_procedure_end==ER_ViborVlad)
		{
		if (type_event==1)
				{
				EndViborVlad();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Post_ZIP)
		{
		if (type_event==1)
				{
				EndViborPostZIP();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Hardware_Old)
		{
		if (type_event==1)
				{
				EndViborOldHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_Rabota)
		{
		if (type_event==1)
				{
				EndViborProducerRabota();
				}
		FormaSpiskaSprProducerRabota=0;
		}

if (number_procedure_end==ER_ProducerNeisprTable)
		{
		if (type_event==1)
				{
				EndViborProducerNeisprTable();
				}
		FormaSpiskaSprProducerNeispr=0;
		}

//редактирование параметров оборудования
if (number_procedure_end==ER_ElementHWNew)
		{
		if (type_event==1)
				{

				}

		}

//редактирование параметров оборудования
if (number_procedure_end==ER_ElementHWOld)
		{
		if (type_event==1)
				{

				}

		}

//создание параметров оборудования
if (number_procedure_end==ER_NewElementHWOld)
		{
		if (type_event==1)
				{
				EndCreateNewElementOldHardware();
				}
        FormaElementaSprHW=0;
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

if (number_procedure_end==ER_InputCodeHWOld)
		{
		if (type_event==1)
				{
				EndInputCodeHWOld();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_InputIdHWOld)
		{
		if (type_event==1)
				{
				EndInputIdHWOld();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_InputCodeNom)
		{
		if (type_event==1)
				{
				EndInputCodeNom();
				}
		FormaInputText=0;
		}


if (number_procedure_end==ER_ViborProducerCondition)
		{
		if (type_event==1)
				{
				EndViborProducerCondition();
				}
		FormaSpiskaSprProducerCondition=0;
		}

if (number_procedure_end==ER_ViborProducerSection)
		{
		if (type_event==1)
				{
				EndViborProducerSection();
				}
		FormaSpiskaSprProducerSection=0;
		}



if (number_procedure_end==ER_Hardware_Donor)
		{
		if (type_event==1)
				{
				EndViborDonorHardware();
				}
		FormaSpiskaSprHardware=0;
		}


if ( number_procedure_end==ER_ViborTypUsla)
	{
	if (type_event==1)
		{
		EndViborTypUsla();
		}
	FormaSpiskaSprTypUslov=0;
	}

if (number_procedure_end==ER_ViborStorageLocation)
		{
		if (type_event==1)
				{
				EndViborStorageLocation()  ;
                }
		FormaSpiskaSprStorageLocation=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocZAktPr::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprInfBase) return;
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		} 
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();

FormaSpiskaSprInfBase=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//выбор фирмы
void TREM_FormaDocZAktPr::ViborFirm(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
		//FormaSpiskaSprFirm->HintLabel->Caption="Выберите фирму для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborFirm(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDFIRM_REM_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
	DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	DM->DocAll->Post();

FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();  
}
//----------------------------------------------------------------------------
//выбор склада
void TREM_FormaDocZAktPr::ViborSklad(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLAD_REM_GALLDOC->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->DocAll->Post();
	UpdateForm();

FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор клиента
void TREM_FormaDocZAktPr::ViborKlient(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор заявки
void TREM_FormaDocZAktPr::ViborRemZ(void)
{
if(Prosmotr==true) return;
if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaGurZ.1",IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborRemZ(void)
{

	DM->Doc->Edit();
	DM->DocIDZ_REM_DZAKTPR->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->DocNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocKLIENT_NAME_REM_Z->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	DM->DocMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
	DM->DocSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->DocSERNUM2_REM_Z->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	DM->Doc->Post();
	UpdateForm();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
//выбор номенклатуры
void TREM_FormaDocZAktPr::ViborNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprNom) return;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborNom(void)
{

__int64 id_nom=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);


if (DM->DocFL_OTCHET_POST_REM_DZAKTPR->AsInteger==1)
	{
	if (FormaSpiskaSprNom->DM->ElementTNOM->AsInteger == 0)   //товар
		{
		if (CheckDetalForOtchetPost(id_nom, 1) == -1)

			{ //недостаточно
				UnicodeString V="Добавить запчасть "+FormaSpiskaSprNom->DM->ElementNAMENOM->AsString+"?";
				UnicodeString Z="Подтверждение";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
						{
						ActionOperation=aoNO;
						FormaSpiskaSprNom=0;
						return;
						}

			}
		}
	}
                if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DZAKTPRT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_REM_DZAKTPRT->AsInteger=1;


				DM->DocTIDED_REM_DZAKTPRT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DZAKTPRT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZAKTPRT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString), //тип цен
											glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString),            //номенклатура
											glStrToInt64(DM->DocTIDED_REM_DZAKTPRT->AsString),             //единица
											DM->DocTKF_REM_DZAKTPRT->AsFloat,                              //коэффициент
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //базовая единица
					DMSprPrice->kanRelease();

				DM->DocTIDMHRAN_REM_DZAKTPRT->AsString=FormaSpiskaSprNom->DM->TableOUT_IDMHRAN->AsString;
				DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprNom->DM->TableOUT_NAME_MHRAN->AsString;
				DM->DocTIDTNOM_REM_DZAKTPRT->AsString=FormaSpiskaSprNom->DM->TableIDTNOM->AsString;
				DM->DocTNAME_STNOM->AsString=FormaSpiskaSprNom->DM->TableNAME_STNOM->AsString;


				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);

		FormaSpiskaSprNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBBandedTableView1KOL_REM_DZAKTPRT->Selected=true;

ActionOperation=aoNO;
}
//----------------------------------------------------------------------------
//выбор единицы
void TREM_FormaDocZAktPr::ViborEd(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprEd) return;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborEd(void)
{


	DM->DocT->Edit();
	DM->DocTIDED_REM_DZAKTPRT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTKF_REM_DZAKTPRT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;


					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZAKTPRT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString), //тип цен
											glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString),            //номенклатура
											glStrToInt64(DM->DocTIDED_REM_DZAKTPRT->AsString),             //единица
											DM->DocTKF_REM_DZAKTPRT->AsFloat,                              //коэффициент
											0);            //базовая единица
					DMSprPrice->kanRelease();


	DM->DocT->Post();

	FormaSpiskaSprEd=0;
	cxGrid1->SetFocus();
	cxGrid1DBBandedTableView1PRICE_REM_DZAKTPRT->Selected=true;
}

//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZAktPr::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRemont");
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocZAktPr::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
//if(flObrabatChangeRoznTypePrice==false) return;
//FindNextControl(ActiveControl,true,true,false)->SetFocus();
//
// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
//
// if ( TypeRPriceComboBox->ItemIndex!=0)
//		{
//		DMSprTypeRPrice->Table->First();
//		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
//		DM->Doc->Edit();
//		DM->DocIDRTPRICE_DVIPPROD->AsInt64=DMSprTypeRPrice->TableID_TPRICE->AsInt64;
//		DM->Doc->Post();
//		}
//else
//	{
//	ShowMessage("Тип цен должен быть задан обязательно!");
//	UpdateForm();
//	return;
//	}
//
////проверим есть ли строки
//if((DM->DocT->RecordCount>0) && (DM->SkladRozn==true))
//		{
//		String V="В табличной части документа есть строки. Пересчитать цены?";
//		String Z="Пересчитать цены?";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//				{
//				TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
//				DM->DocT->First();
//				while(!DM->DocT->Eof)
//						{
//						DM->DocT->Edit();
//						DMSprPrice->FindElement( DM->DocIDRTPRICE_DVIPPROD->AsInt64,
//											 DM->DocTIDNOM_DVIPPRODT->AsInt64);
//						DM->DocTRPRICE_DVIPPRODT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
//														DM->DocTKF_DVIPPRODT->AsFloat;
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaDocZAktPr::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZAktPr::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::BeforeSaveDoc(void)
{
//if (DM->DocAllPOSDOC->AsDateTime > Date())
//	{
//	AnsiString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
//	String Z="Внимание!";
//	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//		{
//		DM->DocAll->Edit();
//		DM->DocAllPOSDOC->AsDateTime=Now();
//		DM->DocAll->Post();
//		}
//	}

}
//----------------------------------------------------------------------------




// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
////
////проверим есть ли строки
//if(DM->DocT->RecordCount>0)
//		{
//		String V="В табличной части документа есть строки. Пересчитать цены?";
//		String Z="Пересчитать цены?";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//				{
//				TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
//				DM->DocT->First();
//				while(!DM->DocT->Eof)
//						{
//						DM->DocT->Edit();
//						DM->DocTS_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // тип цен
//														DM->DocTS_IDNOM_DZAMENAT->AsInt64,         //номенклатура
//														DM->DocTS_IDED_DZAMENAT->AsInt64,   //единица
//														DM->DocTS_KF_DZAMENAT->AsFloat,     //кф единицы
//														0);                                  //базовая единица
//
//						DM->DocTP_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // тип цен
//														DM->DocTP_IDNOM_DZAMENAT->AsInt64,         //номенклатура
//														DM->DocTP_IDED_DZAMENAT->AsInt64,   //единица
//														DM->DocTP_KF_DZAMENAT->AsFloat,     //кф единицы
//														0);                                  //базовая единица
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}







void __fastcall TREM_FormaDocZAktPr::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborKlient();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDKLIENT_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
TypeEvent=1;
if (DM->SaveDoc()==true)
		{
        AfterSaveDoc();
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

void __fastcall TREM_FormaDocZAktPr::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
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

void __fastcall TREM_FormaDocZAktPr::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaDocZAktPr::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::RunExternalModule(__int64 id_module, int type_module)
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
module->SetStringVariables("glUserName", DM_Connection->UserInfoFNAME_USER->AsString);
module->SetInt64Variables("glIdString", glStrToInt64(DM->DocTID_REM_DZAKTPRT->AsString));

module->ExecuteModule();
}
//---------------------------------------------------------------------------




void TREM_FormaDocZAktPr::AfterSaveDoc(void)
{
//
}
//-----------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborHardware(void)
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
void TREM_FormaDocZAktPr::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DZAKTPRT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborProducer(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&FormaSpiskaSprProducer);
		FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducer) return;
		FormaSpiskaSprProducer->Vibor=true;
		FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborProducer(void)
{

	DM->Doc->Edit();
	DM->DocIDPR_REM_DZAKTPR->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->DocNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;

IDMSprProducer * dm_producer;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer,
													(void**)&dm_producer);
dm_producer->Init(InterfaceMainObject,0);
dm_producer->OpenElement(glStrToInt64(DM->DocIDPR_REM_DZAKTPR->AsString));

	DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString=dm_producer->ElementIDPOST_ZIP_SPRODUCER->AsString;
	DM->DocPOST_ZIP_NAME->AsString=dm_producer->ElementPOST_ZIP_NAME->AsString;

	DM->DocAll->Edit();
	DM->DocAllIDKLIENT_REM_GALLDOC->AsString=dm_producer->ElementIDKLIENT_SPRODUCER->AsString;
	DM->DocAllNAMEKLIENT->AsString=dm_producer->ElementNAMEKLIENT->AsString;
	DM->DocAll->Post();


dm_producer->kanRelease();

IDMSprKlient * dm_klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_klient);
dm_klient->Init(InterfaceMainObject,0);
dm_klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));

	DM->DocIDTPRICE_REM_DZAKTPR->AsString=dm_klient->ElementIDTPRICEKLIENT->AsString;


dm_klient->kanRelease();



	DM->Doc->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborProducerModel(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
													(void**)&FormaSpiskaSprProducerModel);
		FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerModel) return;
		FormaSpiskaSprProducerModel->flVibor=true;
		FormaSpiskaSprProducerModel->NumberProcVibor=ER_ViborProducerModel;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborProducerModel(void)
{

	DM->Doc->Edit();
	DM->DocIDPRMODEL_REM_DZAKTPR->AsString=FormaSpiskaSprProducerModel->DM->TableID_REM_SPRMODEL->AsString;
	DM->DocNAME_REM_SPRMODEL->AsString=FormaSpiskaSprProducerModel->DM->TableNAME_REM_SPRMODEL->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducerModel=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborCFC(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
													(void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ViborCFC;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborCFC(void)
{

	DM->Doc->Edit();
	DM->DocIDCFC_REM_DZAKTPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
	DM->DocCFC_NAME->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducerNeispr=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborDFC(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
													(void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ViborDFC;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborDFC(void)
{

	DM->Doc->Edit();
	DM->DocIDDFC_REM_DZAKTPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
	DM->DocDFC_NAME->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducerNeispr=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducer();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDPR_REM_DZAKTPR->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerModel();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::CFCcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborCFC();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDCFC_REM_DZAKTPR->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::DFCcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborDFC();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDDFC_REM_DZAKTPR->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxButtonCopyNeisprClick(TObject *Sender)
{
DM->Doc->Edit();
DM->DocNEISPR_REM_DZAKTPR->AsString=DM->DocNEISPR_REM_Z->AsString;
DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxButtonCopyNemGTClick(TObject *Sender)
{
DM->Doc->Edit();
DM->DocNUMGARTALON_REM_DZAKTPR->AsString=DM->DocSERNUM_REM_Z->AsString;
DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenGarTalonClick(TObject *Sender)

{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
UnicodeString file_name="";
DMSetup->OpenElement(330);
file_name=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();
WORD Year;
WORD Month;
WORD Day;
DecodeDate(DM->DocAllPOS_REM_GALLDOC->AsDateTime,Year,Month,Day);
file_name=file_name+"\\"+DM->DocNAME_SPRODUCER->AsString         // Производитель
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->DocNUMGARTALON_REM_DZAKTPR->AsString
					+".jpg";                                                  //месяц

ShowMessage(file_name);

IFormaImageEditor * ed;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaImageEditor,IID_IFormaImageEditor,
													(void**)&ed);
ed->Init(InterfaceMainObject,0);
ed->LoadFromFile(file_name);

}
//---------------------------------------------------------------------------

void TREM_FormaDocZAktPr::OpenFormSpiskaSprProject(void)
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
void  TREM_FormaDocZAktPr::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::OpenFormSpiskaSprBusinessOper(void)
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
void TREM_FormaDocZAktPr::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaDocZAktPr::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
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

void __fastcall TREM_FormaDocZAktPr::ToolButtonZapolnitClick(TObject *Sender)
{


		String V="Вы действительно хотите заполнить по существующим данным?";
		String Z="Подтверждение ";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}



		IREM_DMGurAllDoc * gur;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMGurAllDoc,IID_IREM_DMGurAllDoc,
													(void**)&gur);
		gur->Init(InterfaceMainObject,InterfaceImpl);
		gur->PosNach=DM->DocAllPOS_REM_GALLDOC->AsDateTime-100;
		gur->PosCon=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
		gur->OpenTableOnlyZayavka(glStrToInt64(DM->DocIDZ_REM_DZAKTPR->AsString));
		gur->Table->First();

		while(!gur->Table->Eof)
			{

			// начало ремонта
			if (gur->TableTDOC_REM_GALLDOC->AsString=="REMZSTART")
				{

				IREM_DMDocZStart * doc;
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZStart,IID_IREM_DMDocZStart,
													(void**)&doc);
				doc->Init(InterfaceMainObject,InterfaceImpl);

				doc->OpenDoc(glStrToInt64(gur->TableID_REM_GALLDOC->AsString));
				DM->Doc->Edit();


				DM->DocIDPR_REM_DZAKTPR->AsString=doc->DocIDPR_REM_DZSTART->AsString;
				DM->DocNAME_SPRODUCER->AsString=doc->DocNAME_SPRODUCER->AsString;

				DM->DocIDPRMODEL_REM_DZAKTPR->AsString=doc->DocIDPRMODEL_REM_DZSTART->AsString;
				DM->DocNAME_REM_SPRMODEL->AsString=doc->DocNAME_REM_SPRMODEL->AsString;

				DM->DocIDCFC_REM_DZAKTPR->AsString=doc->DocIDCFCPR_REM_DZSTART->AsString;
				DM->DocCFC_NAME->AsString=doc->DocNAME_REM_SPRNEISPR->AsString;

				DM->DocSERNUM3_REM_DZAKTPR->AsString=doc->DocSERNUM3_REM_DZSTART->AsString;
				DM->DocSERNUM4_REM_DZAKTPR->AsString=doc->DocSERNUM4_REM_DZSTART->AsString;

				DM->DocNUMBAT_REM_DZAKTPR->AsString=doc->DocNUMBAT_REM_DZSTART->AsString;
				DM->DocSOST_REM_DZAKTPR->AsString=doc->DocSOST_REM_DZSTART->AsString;
				DM->DocDATEVIPUSK_REM_DZAKTPR->AsString=doc->DocDATEVIPUSK_REM_DZSTART->AsString;
				DM->DocDATE_PRODAGI_REM_DZAKTPR->AsString=doc->DocDATE_PRODAGI_REM_DZSTART->AsString;
				DM->DocKEM_SDANO_REM_DZAKTPR->AsString=doc->DocKEM_SDANO_REM_DZSTART->AsString;
				DM->DocTYPE_REMONT_REM_DZAKTPR->AsString=doc->DocTYPE_REMONT_REM_DZSTART->AsString;
				DM->DocPODO_REM_DZAKTPR->AsString=doc->DocPODO_REM_DZSTART->AsString;
                DM->DocPRODAVEC_REM_DZAKTPR->AsString=doc->DocPRODAVEC_REM_DZSTART->AsString;

				DM->Doc->Post();
				doc->kanRelease();
				}


			//конец ремонта
			if (gur->TableTDOC_REM_GALLDOC->AsString=="REMZEND")
				{
				IREM_DMDocZEnd * doc;
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZEnd,IID_IREM_DMDocZEnd,
													(void**)&doc);
				doc->Init(InterfaceMainObject,InterfaceImpl);

				doc->OpenDoc(glStrToInt64(gur->TableID_REM_GALLDOC->AsString));


				DM->Doc->Edit();


				DM->DocIDDFC_REM_DZAKTPR->AsString=doc->DocIDDFCPR_REM_DZEND->AsString;
				DM->DocDFC_NAME->AsString=doc->DocNAME_REM_SPRNEISPR->AsString;

				DM->DocPOPOSLE_REM_DZAKTPR->AsString=doc->DocPOPOSLE_REM_DZEND->AsString;


				DM->Doc->Post();
				doc->kanRelease();
				}


            gur->Table->Next();
			}






	gur->kanRelease();

//если не заполен тип цен, Поставщик ZIP

IDMSprProducer * dm_producer;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer,
													(void**)&dm_producer);
dm_producer->Init(InterfaceMainObject,0);
dm_producer->OpenElement(glStrToInt64(DM->DocIDPR_REM_DZAKTPR->AsString));


	DM->DocAll->Edit();
	DM->DocAllIDKLIENT_REM_GALLDOC->AsString=dm_producer->ElementIDKLIENT_SPRODUCER->AsString;
	DM->DocAllNAMEKLIENT->AsString=dm_producer->ElementNAMEKLIENT->AsString;
	DM->DocAll->Post();


DM->Doc->Edit();
	DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString=dm_producer->ElementIDPOST_ZIP_SPRODUCER->AsString;
	DM->DocPOST_ZIP_NAME->AsString=dm_producer->ElementPOST_ZIP_NAME->AsString;




dm_producer->kanRelease();

IDMSprKlient * dm_klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_klient);
dm_klient->Init(InterfaceMainObject,0);
dm_klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));

	DM->DocIDTPRICE_REM_DZAKTPR->AsString=dm_klient->ElementIDTPRICEKLIENT->AsString;

DM->Doc->Post();
dm_klient->kanRelease();




}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZAktPr::cxButtonZapolnIsZayvkiClick(TObject *Sender)

{
IREM_DMZayavka * z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka,
													(void**)&z);
z->Init(InterfaceMainObject,0);
z->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DZAKTPR->AsString));

DM->Doc->Edit();
DM->DocKLIENT_NAME_REM_DZAKTPR->AsString=z->GurZKLIENT_NAME_REM_Z->AsString;
DM->DocKLIENT_ADR_REM_DZAKTPR->AsString=z->GurZKLIENT_ADR_REM_Z->AsString;
DM->DocKLIENT_PHONE_REM_DZAKTPR->AsString=z->GurZKLIENT_PHONE_REM_Z->AsString;
DM->Doc->Post();

z->kanRelease();

}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
//выбор
void TREM_FormaDocZAktPr::ViborProducerDefect(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerDefect==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerDefect,IID_IREM_FormaSpiskaSprProducerDefect,
													(void**)&FormaSpiskaSprProducerDefect);
		FormaSpiskaSprProducerDefect->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerDefect) return;
		FormaSpiskaSprProducerDefect->flVibor=true;
 //		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprProducerDefect->IdElement=glStrToInt64(DM->DocTIDPRDEFECT_REM_DZAKTPR->AsString);
		FormaSpiskaSprProducerDefect->UpdateForm();
		FormaSpiskaSprProducerDefect->NumberProcVibor=ER_ProducerDefect;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborProducerDefect(void)
{

//				if (ActionOperation==aoAddNewString)
//						{
//						DM->TableAppend();
//						}
				DM->DocT->Edit();
				DM->DocTIDPRDEFECT_REM_DZAKTPR->AsString=FormaSpiskaSprProducerDefect->DM->TableID_REM_SPRDEFECT->AsString;
				DM->DocTNAME_REM_SPRDEFECT->AsString=FormaSpiskaSprProducerDefect->DM->TableNAME_REM_SPRDEFECT->AsString;
				DM->DocTCODE_REM_SPRDEFECT->AsString=FormaSpiskaSprProducerDefect->DM->TableCODE_REM_SPRDEFECT->AsString;


				DM->DocT->Post();


		FormaSpiskaSprProducerDefect=0;
		cxGrid1->SetFocus();
		cxGrid1DBBandedTableView1KOL_REM_DZAKTPRT->Selected=true;

ActionOperation=aoNO;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAME_REM_SPRDEFECTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerDefect();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenZayavkaClick(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DZAKTPR->AsString));
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonSetOtchitanZayvkaClick(TObject *Sender)

{
//обновим флаг отчитано

	__int64 idz=glStrToInt64(DM->DocIDZ_REM_DZAKTPR->AsString);

	if (idz!=0)
		{
		IREM_DMZayavka * dm_z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
		dm_z->Init(InterfaceMainObject,InterfaceImpl);
		dm_z->OpenDoc(idz);

		if (dm_z->GurZFL_ADDREPORT_REM_Z->AsString==1)
			{
            ShowMessage("Флаг отчитан уже установлен!");
			}
		else
			{
			dm_z->GurZ->Edit();
			dm_z->GurZFL_ADDREPORT_REM_Z->AsString=1;
			dm_z->GurZ->Post();
			dm_z->SaveDoc();
			}

		dm_z->kanRelease();
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonCopyPrimkaGarantClick(TObject *Sender)

{

IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
AnsiString file_name_garant="";
DMSetup->OpenElement(330);
file_name_garant=DMSetup->ElementVALUE_SETUP->AsString;

WORD Year;
WORD Month;
WORD Day;
DecodeDate(DM->DocAllPOS_REM_GALLDOC->AsDateTime,Year,Month,Day);
file_name_garant=file_name_garant+"\\"+DM->DocNAME_SPRODUCER->AsString         // Производитель
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->DocNUMGARTALON_REM_DZAKTPR->AsString
					+".jpg";                                                  //месяц


AnsiString file_name_priemka="";
DMSetup->OpenElement(331);
file_name_priemka=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();

file_name_priemka=file_name_priemka+"\\"+DM->DocNAME_SPRODUCER->AsString         // Производитель
					+"\\"+DM->DocNUMGARTALON_REM_DZAKTPR->AsString
					+".jpg";                                                  //месяц



//проверим есть ли файл в каталоге Приемка
if (FileExists(file_name_priemka)==true)
		{
		if (FileExists(file_name_garant)==true)
			{
			UnicodeString V="Файл в каталоге Гарант уже существует. Заменить?";
			UnicodeString Z="Внимание!";
			if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				if (MoveFile(file_name_priemka.c_str(),file_name_garant.c_str())==false)
					{
					ShowMessage("Ошибка копирования файла \n Файл приемки "+file_name_priemka
							+"\n Файл Гарант "+file_name_garant);
					}

				}
			}
		else
			{
				if (MoveFile(file_name_priemka.c_str(),file_name_garant.c_str())==false)
					{
					ShowMessage("Ошибка копирования файла \n Файл приемки "+file_name_priemka
							+"\n Файл Гарант "+file_name_garant);
					}
			}


		}
else
	{
	ShowMessage("Нет файла в каталоге приемки \n Файл "+file_name_priemka);
	}



}
//---------------------------------------------------------------------------
//выбор клиента
void TREM_FormaDocZAktPr::ViborVlad(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_ViborVlad;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborVlad(void)
{
if (FormaSpiskaSprKlient==0) return;


	DM->Doc->Edit();
	DM->DocKLIENT_NAME_REM_DZAKTPR->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
	DM->DocKLIENT_ADR_REM_DZAKTPR->AsString=FormaSpiskaSprKlient->DM->ElementADRKLIENT->AsString;
	DM->DocKLIENT_PHONE_REM_DZAKTPR->AsString=FormaSpiskaSprKlient->DM->ElementTELKLIENT->AsString;
	DM->Doc->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxButtonViborIsSprClick(TObject *Sender)
{
ViborVlad();
}
//---------------------------------------------------------------------------
//выбор клиента
void TREM_FormaDocZAktPr::ViborPostZIP(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Post_ZIP;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborPostZIP(void)
{
if (FormaSpiskaSprKlient==0) return;


	DM->Doc->Edit();
	DM->DocPOST_ZIP_NAME->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
	DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
	DM->Doc->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::NamePostZipcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborPostZIP();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDPOST_ZIP_REM_DZAKTPR->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonCreateDocRemontClick(TObject *Sender)

{

//ищем ремонт

IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"select rem_galldoc.id_rem_galldoc                                                        \
from rem_galldoc                                                                          \
left outer join rem_dremont on rem_galldoc.id_rem_galldoc=rem_dremont.iddoc_rem_dremont   \
where rem_galldoc.tdoc_rem_galldoc='REMONT'                                               \
		and rem_dremont.idz_rem_dremont=:PARAM_IDZ ";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDZ")->AsString=DM->DocIDZ_REM_DZAKTPR->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_doc_remont=0;
id_doc_remont=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_galldoc")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();


IREM_FormaDocRemont* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRemont,IID_IREM_FormaDocRemont,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);


if (id_doc_remont!=0)
	{
	//откроем документ
	doc->DM->OpenDoc(id_doc_remont);
	}
else
	{
	// ищем базу для док Ремонт
	InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
	dm_qr->Init(InterfaceMainObject,0);
	dm_qr->pFIBQ->Close();
	dm_qr->pFIBQ->SQL->Clear();

	UnicodeString zapros=
		"               select rem_z.idbase_rem_z,                                                                \
							   sinfbase_obmen.name_sinfbase_obmen                                                 \
						from rem_z                                                                                \
						left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obmen=rem_z.idbase_rem_z     \
						where rem_z.id_rem_z=:PARAM_IDZ";

		dm_qr->pFIBQ->SQL->Add(zapros);
		dm_qr->pFIBQ->ParamByName("PARAM_IDZ")->AsString=DM->DocIDZ_REM_DZAKTPR->AsString;
		dm_qr->pFIBQ->ExecQuery();
		__int64 id_base=0;
		UnicodeString name_base=dm_qr->pFIBQ->FieldByName("name_sinfbase_obmen")->AsString;
		id_base=glStrToInt64(dm_qr->pFIBQ->FieldByName("idbase_rem_z")->AsString);
		dm_qr->pFIBQ->Close();
		dm_qr->kanRelease();


	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	if (id_base >0)
		{
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=id_base;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=name_base;
		}
	doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
	doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
	doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->DocAllIDSKLAD_REM_GALLDOC->AsString;
	doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
	doc->DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=DM->DocAllIDBUSINOP_REM_GALLDOC->AsString;
	doc->DM->DocAllNAME_SBUSINESS_OPER->AsString=DM->DocAllNAME_SBUSINESS_OPER->AsString;

	doc->DM->DocAll->Post();

	doc->DM->Doc->Edit();
	doc->DM->DocIDZ_REM_DREMONT->AsString=DM->DocIDZ_REM_DZAKTPR->AsString;
	doc->DM->DocNAME_REM_Z->AsString=DM->DocNAME_REM_Z->AsString;
	doc->DM->DocNUM_REM_Z->AsString=DM->DocNUM_REM_Z->AsString;
	doc->DM->DocPOS_REM_Z->AsString=DM->DocPOS_REM_Z->AsString;
	doc->DM->DocSERNUM_REM_Z->AsString=DM->DocSERNUM_REM_Z->AsString;
	doc->DM->DocSERNUM2_REM_Z->AsString=DM->DocSERNUM2_REM_Z->AsString;
	//doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->KLIENT_NAME_REM_Z->AsString;
	//doc->DM->DocMODEL_REM_Z->AsString=DM->GurZMODEL_REM_Z->AsString;

	doc->DM->DocTYPE_REMONT_REM_DREMONT->AsString=DM->DocTYPE_REMONT_REM_DZAKTPR->AsString;
	doc->DM->Doc->Post();

	DM->DocT->First();

	while(!DM->DocT->Eof)
		{
		doc->DM->TableAppend();
		doc->DM->DocT->Edit();
		doc->DM->DocTDVREG_REM_DREMONTT->AsInteger=0;
		doc->DM->DocTIDNOM_REM_DREMONTT->AsString=DM->DocTIDNOM_REM_DZAKTPRT->AsString;
		doc->DM->DocTARTNOM->AsString=DM->DocTARTNOM->AsString;
		doc->DM->DocTCODENOM->AsString=DM->DocTCODENOM->AsString;
		doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDED_REM_DREMONTT->AsString=DM->DocTIDED_REM_DZAKTPRT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		doc->DM->DocTSHED->AsString=DM->DocTSHED->AsString;
		doc->DM->DocTKF_REM_DREMONTT->AsFloat=DM->DocTKF_REM_DZAKTPRT->AsFloat;
		doc->DM->DocTKOL_REM_DREMONTT->AsFloat=DM->DocTKOL_REM_DZAKTPRT->AsFloat;
        doc->DM->DocTPRICE_REM_DREMONTT->AsFloat=0;

		doc->DM->DocT->Post();
		DM->DocT->Next();
		}

	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocZAktPr::CheckDetalForOtchetPost(__int64 id_nom, double kol)
{
int result=0;

IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"        select sum(rem_rgotchpost.kol_rem_rgotchpost)  as kol                     \
		from rem_rgotchpost                                                        \
																				   \
		where rem_rgotchpost.idfirm_rem_rgotchpost=:PARAM_IDFIRM                   \
				and rem_rgotchpost.idsklad_rem_rgotchpost=:PARAM_IDSKLAD           \
				and rem_rgotchpost.idpost_rem_rgotchpost=:PARAM_IDPOST             \
				and rem_rgotchpost.idnom_rem_rgotchpost=:PARAM_IDNOM";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLAD_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ParamByName("PARAM_IDPOST")->AsString=DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString;
dm_qr->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=id_nom;
dm_qr->pFIBQ->ExecQuery();
double ost=0;
ost=dm_qr->pFIBQ->FieldByName("kol")->AsFloat;
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();


if (glCompareDoubleValue(ost, kol, 0.001) == -1)
	{ //недостаточно
	result = -1;
	UnicodeString s="Недостаточно для отчета Поставщику! Можно отчитать  "+ FloatToStr(ost)+" ед.  !";
	ShowMessage(s);
	}
else
	{
	result=1;
	}

return result;
}
//---------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborSeller(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSeller==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprSeller,IID_IFormaSpiskaSprSeller,
													(void**)&FormaSpiskaSprSeller);
		FormaSpiskaSprSeller->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSeller) return;
		FormaSpiskaSprSeller->Vibor=true;
		FormaSpiskaSprSeller->NumberProcVibor=ER_ViborSeller;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborSeller(void)
{

	DM->Doc->Edit();
	DM->DocIDSELLER_REM_DZAKTPR->AsString=FormaSpiskaSprSeller->DM->TableID_SSELLER->AsString;
	DM->DocNAME_SSELLER->AsString=FormaSpiskaSprSeller->DM->TableNAME_SSELLER->AsString;
    DM->DocPRODAVEC_REM_DZAKTPR->AsString=FormaSpiskaSprSeller->DM->TableNAME_FOR_PRINT_SSELLER->AsString;

	DM->Doc->Post();

FormaSpiskaSprSeller=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::NameSSellercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborSeller();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDSELLER_REM_DZAKTPR->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonAddDataIsZayavkiClick(TObject *Sender)

{
		String V="Вы действительно хотите заполнить по существующим данным из заявки?";
		String Z="Подтверждение ";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}



		IREM_DMZayavka * z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka,
													(void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		z->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DZAKTPR->AsString));

			DM->Doc->Edit();

				DM->DocIDPR_REM_DZAKTPR->AsString=z->GurZ_1IDPRODUCER_REM_Z_1->AsString;
				DM->DocNAME_SPRODUCER->AsString=z->GurZ_1NAME_SPRODUCER->AsString;

				DM->DocIDPRMODEL_REM_DZAKTPR->AsString=z->GurZ_1IDPRMODEL_REM_Z_1->AsString;
				DM->DocNAME_REM_SPRMODEL->AsString=z->GurZ_1NAME_REM_SPRMODEL->AsString;

				DM->DocIDCFC_REM_DZAKTPR->AsString=z->GurZ_1IDPRNEISPR_REM_Z_1->AsString;
				DM->DocCFC_NAME->AsString=z->GurZ_1NAME_REM_SPRNEISPR->AsString;

				DM->DocSERNUM3_REM_DZAKTPR->AsString=z->GurZ_1SERNUM3_REM_Z_1->AsString;
				DM->DocSERNUM4_REM_DZAKTPR->AsString=z->GurZ_1SERNUM4_REM_Z_1->AsString;

				DM->DocNUMBAT_REM_DZAKTPR->AsString=z->GurZ_1NUMBAT_REM_Z_1->AsString;
				DM->DocSOST_REM_DZAKTPR->AsString=z->GurZSOST_REM_Z->AsString;
				DM->DocDATEVIPUSK_REM_DZAKTPR->AsString=z->GurZ_1DATE_VIPUSK_REM_Z_1->AsString;
				DM->DocDATE_PRODAGI_REM_DZAKTPR->AsString=z->GurZ_1DATE_PRODAGI_REM_Z_1->AsString;
				DM->DocKEM_SDANO_REM_DZAKTPR->AsString=z->GurZ_1KEMSDANO_REM_Z_1->AsString;
				DM->DocTYPE_REMONT_REM_DZAKTPR->AsString=3;
				DM->DocPODO_REM_DZAKTPR->AsString=z->GurZ_1PODO_REM_Z_1->AsString;

				DM->DocIDSELLER_REM_DZAKTPR->AsString=z->GurZ_1IDSELLER_REM_Z_1->AsString;
				DM->DocNAME_SSELLER->AsString=z->GurZ_1NAME_SSELLER->AsString;
				DM->DocPRODAVEC_REM_DZAKTPR->AsString=z->GurZ_1NAME_SSELLER->AsString ;



				DM->DocPOPOSLE_REM_DZAKTPR->AsString=z->GurZ_1POPOSLE_REM_Z_1->AsString;


				DM->Doc->Post();







	z->kanRelease();

//если не заполен тип цен, Поставщик ZIP

IDMSprProducer * dm_producer;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer,
													(void**)&dm_producer);
dm_producer->Init(InterfaceMainObject,0);
dm_producer->OpenElement(glStrToInt64(DM->DocIDPR_REM_DZAKTPR->AsString));


	DM->DocAll->Edit();
	DM->DocAllIDKLIENT_REM_GALLDOC->AsString=dm_producer->ElementIDKLIENT_SPRODUCER->AsString;
	DM->DocAllNAMEKLIENT->AsString=dm_producer->ElementNAMEKLIENT->AsString;
	DM->DocAll->Post();


DM->Doc->Edit();
	DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString=dm_producer->ElementIDPOST_ZIP_SPRODUCER->AsString;
	DM->DocPOST_ZIP_NAME->AsString=dm_producer->ElementPOST_ZIP_NAME->AsString;




dm_producer->kanRelease();

IDMSprKlient * dm_klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_klient);
dm_klient->Init(InterfaceMainObject,0);
dm_klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));

	DM->DocIDTPRICE_REM_DZAKTPR->AsString=dm_klient->ElementIDTPRICEKLIENT->AsString;

DM->Doc->Post();
dm_klient->kanRelease();



}
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborOldHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprHardware,IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware_Old;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------

void TREM_FormaDocZAktPr::EndViborOldHardware(void)
{


	DM->DocT->Edit();
	DM->DocTIDHWOLD_REM_DZAKTPRT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTOLD_NAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;


}
//----------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborProducerNeisprTable(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
													(void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ProducerNeisprTable;
		//FormaSpiskaSprProducer->UpdateForm();
		}




}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborProducerNeisprTable(void)
{


	DM->DocT->Edit();
	DM->DocTIDPRNEISPR_REM_DZAKTPRT->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
	DM->DocTNAME_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->DocTCODE_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableCODE_REM_SPRNEISPR->AsString;
	DM->DocT->Post();

FormaSpiskaSprProducerNeispr=0;

}

//----------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborProducerRabota(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerRabota==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerRabota,IID_IREM_FormaSpiskaSprProducerRabota,
													(void**)&FormaSpiskaSprProducerRabota);
		FormaSpiskaSprProducerRabota->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerRabota) return;
		FormaSpiskaSprProducerRabota->flVibor=true;
		FormaSpiskaSprProducerRabota->IdElement=glStrToInt64(DM->DocTIDPRDEFECT_REM_DZAKTPR->AsString);
		FormaSpiskaSprProducerRabota->UpdateForm();
		FormaSpiskaSprProducerRabota->NumberProcVibor=ER_Rabota;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborProducerRabota(void)
{
				DM->DocT->Edit();
				DM->DocTIDPRRABOTA_REM_DZAKTPRT->AsString=FormaSpiskaSprProducerRabota->DM->TableID_REM_SPRRABOTA->AsString;
				DM->DocTNAME_REM_SPRRABOTA->AsString=FormaSpiskaSprProducerRabota->DM->TableNAME_REM_SPRRABOTA->AsString;
				DM->DocTCODE_REM_SPRRABOTA->AsString=FormaSpiskaSprProducerRabota->DM->TableCODE_REM_SPRRABOTA->AsString;


				DM->DocT->Post();


		FormaSpiskaSprProducerRabota=0;

ActionOperation=aoNO;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerNeisprTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1NAME_REM_SPRRABOTAPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerRabota();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborOldHardware();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenFormNewHWClick(TObject *Sender)
{
		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprHardware,IID_IREM_FormaElementaSprHardware,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDHW_REM_DZAKTPRT->AsString));
		FormaElementa->NumberProcVibor=ER_ElementHWNew;
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenFormOldHWClick(TObject *Sender)
{
		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprHardware,IID_IREM_FormaElementaSprHardware,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDHWOLD_REM_DZAKTPRT->AsString));
		FormaElementa->NumberProcVibor=ER_ElementHWOld;
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonNewOldHWClick(TObject *Sender)
{

		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprHardware,IID_IREM_FormaElementaSprHardware,
										 (void**)&FormaElementaSprHW);
		FormaElementaSprHW->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaSprHW->DM->NewElement(0);
		FormaElementaSprHW->NumberProcVibor=ER_NewElementHWOld;
		FormaElementaSprHW->UpdateForm();
		FormaElementaSprHW->Vibor=true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocZAktPr::OpenFormInputCodeHW(void)
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
void TREM_FormaDocZAktPr::EndInputCodeHW(void)
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

					DM->TableAppend();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DZAKTPRT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					//DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;
					//DM->DocTWARRANTY_REM_DREALT->AsInteger=dm_nom->ElementWARRANTY_SNOM->AsInteger;

					DM->DocTIDED_REM_DZAKTPRT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DZAKTPRT->AsFloat = dm_ed->ElementKFED->AsFloat;
					DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DZAKTPRT->AsFloat=1;

					DM->DocTIDHW_REM_DZAKTPRT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
					DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;

						//получим цену
						IDMSprPrice * dm_price;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceImpl);

						DM->DocTPRICE_REM_DZAKTPRT->AsFloat=dm_price->GetValuePrice(
							glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString),                     //тип цен
							glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString),  //номенклатура
							glStrToInt64(DM->DocTIDED_REM_DZAKTPRT->AsString),    // единица
							DM->DocTKF_REM_DZAKTPRT->AsFloat,                   // коэффициент единицы
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


						dm_price->kanRelease();


					//SetFlagDvUchet();
					DM->DocT->Post();


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
void TREM_FormaDocZAktPr::OpenFormInputIdHW(void)
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
void TREM_FormaDocZAktPr::EndInputIdHW(void)
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

					DM->TableAppend();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DZAKTPRT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					//DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;
					//DM->DocTWARRANTY_REM_DREALT->AsInteger=dm_nom->ElementWARRANTY_SNOM->AsInteger;

					DM->DocTIDED_REM_DZAKTPRT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DZAKTPRT->AsFloat = dm_ed->ElementKFED->AsFloat;
					DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DZAKTPRT->AsFloat=1;

					DM->DocTIDHW_REM_DZAKTPRT->AsString=id_hw;
					DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
					DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;


						//получим цену
						IDMSprPrice * dm_price;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceImpl);

						DM->DocTPRICE_REM_DZAKTPRT->AsFloat=dm_price->GetValuePrice(
							glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString),                     //тип цен
							glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString),  //номенклатура
							glStrToInt64(DM->DocTIDED_REM_DZAKTPRT->AsString),    // единица
							DM->DocTKF_REM_DZAKTPRT->AsFloat,                   // коэффициент единицы
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


						dm_price->kanRelease();


				   //	SetFlagDvUchet();
					DM->DocT->Post();


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
void TREM_FormaDocZAktPr::EndCreateNewElementOldHardware(void)
{


	DM->DocT->Edit();
	DM->DocTIDHWOLD_REM_DZAKTPRT->AsString=FormaElementaSprHW->DM->ElementID_REM_SHARDWARE->AsString;
	DM->DocTOLD_NAME_REM_SHARDWARE->AsString=FormaElementaSprHW->DM->ElementNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;
}
//-----------------------------------------------------------------------------


void __fastcall TREM_FormaDocZAktPr::ToolButtonAddPoCodHWClick(TObject *Sender)
{
OpenFormInputCodeHW();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonAddPoIdHWClick(TObject *Sender)
{
OpenFormInputIdHW();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocZAktPr::OpenFormInputCodeHWOld(void)
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
		FormaInputText->NumberProcVibor=ER_InputCodeHWOld;
		FormaInputText->Vibor=true;
		FormaInputText->TextMessage="Код оборудования:";
		FormaInputText->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndInputCodeHWOld(void)
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

					DM->DocT->Edit();
					DM->DocTIDHWOLD_REM_DZAKTPRT->AsString=id_hw;
					DM->DocTOLD_NAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
					DM->DocTOLD_SERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;

					DM->DocT->Post();
	}
else
	{
	ShowMessage("Не найден элемент в справочнике Оборудование с кодом "+IntToStr(code)+"!");
	}

	dm_hw->kanRelease();


}
//---------------------------------------------------------------------------
//ввод кода номенклатуры
void TREM_FormaDocZAktPr::OpenFormInputIdHWOld(void)
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
		FormaInputText->NumberProcVibor=ER_InputIdHWOld;
		FormaInputText->Vibor=true;
		FormaInputText->TextMessage="ID оборудования:";
		FormaInputText->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndInputIdHWOld(void)
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
		DM->DocT->Edit();

		DM->DocTIDHWOLD_REM_DZAKTPRT->AsString=id_hw;
		DM->DocTOLD_NAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
		DM->DocTOLD_SERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;

		 DM->DocT->Post();

		 }
	else
		{
		ShowMessage("Не найден элемент в справочнике Оборудование! IDHW - "+IntToStr(id_hw));
		}
	dm_hw->kanRelease();
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::ToolButtonAddOldPoCoduHWClick(TObject *Sender)

{
OpenFormInputCodeHWOld();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonAddOldHWPoIDClick(TObject *Sender)

{
OpenFormInputIdHWOld();
}
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::OpenFormInputCodeNom(void)
{
if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=ER_InputCodeNom;
		FormaInputText->Vibor=true;
		FormaInputText->TextMessage="Код номенклатуры:";
		FormaInputText->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndInputCodeNom(void)
{
int code_nom=glStrToInt64(FormaInputText->InputText);

//добавляем строку
IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);

IDMSprEd * dm_ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
dm_ed->Init(InterfaceMainObject,InterfaceImpl);

dm_nom->FindPoCodu(code_nom);  //открыт найденный  элемент

if (glStrToInt64(dm_nom->ElementIDNOM->AsString) !=0)
	{

					dm_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));

					DM->TableAppend();
					DM->DocT->Edit();

					DM->DocTIDNOM_REM_DZAKTPRT->AsString = dm_nom->ElementIDNOM->AsString;
					DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
					//DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;
					DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
					DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;
					//DM->DocTWARRANTY_REM_DREALT->AsInteger=dm_nom->ElementWARRANTY_SNOM->AsInteger;

					DM->DocTIDED_REM_DZAKTPRT->AsString = dm_ed->ElementIDED->AsString;
					DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
					DM->DocTKF_REM_DZAKTPRT->AsFloat = dm_ed->ElementKFED->AsFloat;
					DM->DocTSHED->AsString = dm_ed->ElementSHED->AsString;

					DM->DocTKOL_REM_DZAKTPRT->AsFloat=1;


						//получим цену
						IDMSprPrice * dm_price;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceImpl);

						DM->DocTPRICE_REM_DZAKTPRT->AsFloat=dm_price->GetValuePrice(
							glStrToInt64(DM->DocIDTPRICE_REM_DZAKTPR->AsString),                     //тип цен
							glStrToInt64(DM->DocTIDNOM_REM_DZAKTPRT->AsString),  //номенклатура
							glStrToInt64(DM->DocTIDED_REM_DZAKTPRT->AsString),    // единица
							DM->DocTKF_REM_DZAKTPRT->AsFloat,                   // коэффициент единицы
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица


						dm_price->kanRelease();


				   //	SetFlagDvUchet();
					DM->DocT->Post();
	}

dm_nom->kanRelease();
dm_ed->kanRelease();
}
//--------------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::ToolButtonAddPoCoduNomClick(TObject *Sender)

{
OpenFormInputCodeNom();
}
//---------------------------------------------------------------------------

void TREM_FormaDocZAktPr::ViborProducerCondition(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprProducerCondition==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerCondition,IID_IREM_FormaSpiskaSprProducerCondition,
								 (void**)&FormaSpiskaSprProducerCondition);
		FormaSpiskaSprProducerCondition->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerCondition) return;
		FormaSpiskaSprProducerCondition->flVibor=true;
		FormaSpiskaSprProducerCondition->NumberProcVibor=ER_ViborProducerCondition;
		FormaSpiskaSprProducerCondition->UpdateForm();
		}


}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborProducerCondition(void)
{
if (FormaSpiskaSprProducerCondition==0) return;

				DM->DocT->Edit();
				DM->DocTIDPRCOND_REM_DZAKTPRT->AsString=FormaSpiskaSprProducerCondition->DM->TableID_REM_SPRCONDITION->AsString;
				DM->DocTNAME_REM_SPRCONDITION->AsString=FormaSpiskaSprProducerCondition->DM->TableNAME_REM_SPRCONDITION->AsString;
				DM->DocTNAME_ENG_REM_SPRCONDITION->AsString=FormaSpiskaSprProducerCondition->DM->TableNAME_ENG_REM_SPRCONDITION->AsString;
				//DM->GurZNeisprNAME_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SNEISPR->AsString;
				DM->DocT->Post();


		FormaSpiskaSprProducerCondition=0;

}
//-----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborProducerSection(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprProducerSection==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerSection,IID_IREM_FormaSpiskaSprProducerSection,
								 (void**)&FormaSpiskaSprProducerSection);
		FormaSpiskaSprProducerSection->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerSection) return;
		FormaSpiskaSprProducerSection->flVibor=true;
		FormaSpiskaSprProducerSection->NumberProcVibor=ER_ViborProducerSection;
		FormaSpiskaSprProducerSection->UpdateForm();
		}


}
//----------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborProducerSection(void)
{
if (FormaSpiskaSprProducerSection==0) return;

				DM->DocT->Edit();
				DM->DocTIDPRSECTION_REM_DZAKTPRT->AsString=FormaSpiskaSprProducerSection->DM->TableID_REM_SPRSECTION->AsString;
				DM->DocTNAME_REM_SPRSECTION->AsString=FormaSpiskaSprProducerSection->DM->TableNAME_REM_SPRSECTION->AsString;
				DM->DocTNAME_ENG_REM_SPRSECTION->AsString=FormaSpiskaSprProducerSection->DM->TableNAME_ENG_REM_SPRSECTION->AsString;
				//DM->GurZNeisprNAME_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SNEISPR->AsString;
				DM->DocT->Post();


		FormaSpiskaSprProducerSection=0;

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerCondition();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerNeisprTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SPRSECTIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerSection();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SPRDEFECTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerDefect();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SPRRABOTAPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerRabota();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{


switch (AButtonIndex)
	{
	case 0:
		{
		ViborNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDNOM_REM_DZAKTPRT->Clear();
		DM->DocTARTNOM->AsString="";
		DM->DocTNAMENOM->AsString="";
		DM->DocTKOL_REM_DZAKTPRT->AsFloat=0;
		DM->DocTKF_REM_DZAKTPRT->AsFloat=0;
		DM->DocTPRICE_REM_DZAKTPRT->AsFloat=0;
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborOldHardware();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZAktPr::ToolButton9Click(TObject *Sender)
{
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
"        select snom.artnom,                    \
		snom.namenom,                           \
		rem_cqueryt.idnom_rem_cqueryt,                            \
		rem_cqueryt.kol_rem_cqueryt             \
		from rem_cqueryt                                                        \
		left outer join rem_cquery on rem_cquery.id_rem_cquery=rem_cqueryt.idcq_rem_cqueryt   \
		left outer join snom on snom.idnom=rem_cqueryt.idnom_rem_cqueryt                      \
		where rem_cquery.idz_rem_cquery=:PARAM_IDZ";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDZ")->AsString=DM->DocIDZ_REM_DZAKTPR->AsString;
dm_qr->pFIBQ->ExecQuery();
//dm_qr->pFIBQ->First();
while (!dm_qr->pFIBQ->Eof)
	{
	DM->TableAppend();
	DM->DocT->Edit();
	DM->DocTIDNOM_REM_DZAKTPRT->AsString=dm_qr->pFIBQ->FieldByName("idnom_rem_cqueryt")->AsString;
	DM->DocTARTNOM->AsString=dm_qr->pFIBQ->FieldByName("artnom")->AsString;
	DM->DocTNAMENOM->AsString=dm_qr->pFIBQ->FieldByName("namenom")->AsString;
	DM->DocTKOL_REM_DZAKTPRT->AsString=dm_qr->pFIBQ->FieldByName("kol_rem_cqueryt")->AsFloat;
	DM->DocTFL_ISP_REM_DZAKTPRT->AsInteger=1;  //использована в ремонте
	DM->DocT->Post();
	dm_qr->pFIBQ->Next();
	}

dm_qr->pFIBQ->Close();

dm_qr->kanRelease();



}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonAddStrinClick(TObject *Sender)
{
DM->TableAppend();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenGarTalonIsZayavkiPoNumGarTalonaClick(TObject *Sender)

{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
UnicodeString file_name="";
DMSetup->OpenElement(330);
file_name=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();

WORD Year;
WORD Month;
WORD Day;
DecodeDate(DM->DocPOS_REM_Z->AsDateTime,Year,Month,Day);

IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
					"select sbrand.name_sbrand,                                          \
					rem_z.idbase_rem_z                                                   \
					from rem_dzaktpr                                                     \
					left outer join rem_z on rem_z.id_rem_z=rem_dzaktpr.idz_rem_dzaktpr  \
					left outer join sbrand on rem_z.idbrand_rem_z=sbrand.id_sbrand       \
					where rem_dzaktpr.iddoc_rem_dzaktpr=:PARAM_IDDOC";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ExecQuery();

UnicodeString id_base=dm_qr->pFIBQ->FieldByName("idbase_rem_z")->AsString;
UnicodeString name_brand=dm_qr->pFIBQ->FieldByName("name_sbrand")->AsString;
dm_qr->pFIBQ->Close();

dm_qr->kanRelease();




file_name=file_name+"\\"+id_base         // база заявки
					+"\\Garant"
					+"\\"+name_brand
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->DocNUMGARTALON_REM_DZAKTPR->AsString
					+".jpg";                                                  //месяц

ShowMessage(file_name);

IFormaImageEditor * ed;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaImageEditor,IID_IFormaImageEditor,
													(void**)&ed);
ed->Init(InterfaceMainObject,0);
ed->LoadFromFile(file_name);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonOpenFilePoZayavkePoSerNum1Click(TObject *Sender)

{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
UnicodeString file_name="";
DMSetup->OpenElement(330);
file_name=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();

WORD Year;
WORD Month;
WORD Day;
DecodeDate(DM->DocPOS_REM_Z->AsDateTime,Year,Month,Day);

IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=
					"select sbrand.name_sbrand,                                          \
					rem_z.idbase_rem_z                                                   \
					from rem_dzaktpr                                                     \
					left outer join rem_z on rem_z.id_rem_z=rem_dzaktpr.idz_rem_dzaktpr  \
					left outer join sbrand on rem_z.idbrand_rem_z=sbrand.id_sbrand       \
					where rem_dzaktpr.iddoc_rem_dzaktpr=:PARAM_IDDOC";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ExecQuery();

UnicodeString id_base=dm_qr->pFIBQ->FieldByName("idbase_rem_z")->AsString;
UnicodeString name_brand=dm_qr->pFIBQ->FieldByName("name_sbrand")->AsString;
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();




file_name=file_name+"\\"+id_base         // база заявки
					+"\\Garant"
					+"\\"+name_brand
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->DocSERNUM_REM_Z->AsString
					+".jpg";                                                  //месяц

ShowMessage(file_name);

IFormaImageEditor * ed;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaImageEditor,IID_IFormaImageEditor,
													(void**)&ed);
ed->Init(InterfaceMainObject,0);
ed->LoadFromFile(file_name);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborDonorHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprHardware,IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware_Donor;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------

void TREM_FormaDocZAktPr::EndViborDonorHardware(void)
{


	DM->DocT->Edit();
	DM->DocTIDHW_DONOR_REM_DZAKTPRT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTOLD_NAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDonorHardware();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDHW_DONOR_REM_DZAKTPRT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::ViborTypUsla(void)
{
if (FormaSpiskaSprTypUslov>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypUslov,IID_IREM_FormaSpiskaSprTypUslov,
												 (void**)&FormaSpiskaSprTypUslov);
FormaSpiskaSprTypUslov->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypUslov->flVibor=true;
FormaSpiskaSprTypUslov->NumberProcVibor=ER_ViborTypUsla;
FormaSpiskaSprTypUslov->IdElement=glStrToInt64(DM->DocTIDTYP_USEL_REM_DZAKTPRT->AsString);
FormaSpiskaSprTypUslov->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::EndViborTypUsla(void)
{

	DM->DocT->Edit();
	DM->DocTIDTYP_USEL_REM_DZAKTPRT->AsString=FormaSpiskaSprTypUslov->DM->TableID_REM_STYPUSLOV->AsString;
	DM->DocTNAME_REM_STYPUSLOV->AsString=FormaSpiskaSprTypUslov->DM->TableNAME_REM_STYPUSLOV->AsString;
	DM->DocT->Post();

}
///-------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_REM_STYPUSLOVPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypUsla();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDTYP_USEL_REM_DZAKTPRT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZAktPr::ToolButtonCreateDocVzipClick(TObject *Sender)

{
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();

UnicodeString zapros=                                                                       \
"        select snom.artnom,                                                                \
		snom.namenom,                                                                       \
		snom.codenom,                                                                       \
		snom.tnom,                                                                       \
		sed.nameed,                                                                         \
		rem_dzaktprt.idnom_rem_dzaktprt,                                                    \
		rem_dzaktprt.ided_rem_dzaktprt,                                                     \
		rem_dzaktprt.kol_rem_dzaktprt,                                                      \
		rem_dzaktprt.kf_rem_dzaktprt                                                        \
		from rem_dzaktprt                                                                  \
		left outer join snom on snom.idnom=rem_dzaktprt.idnom_rem_dzaktprt                 \
		left outer join sed on sed.ided=rem_dzaktprt.ided_rem_dzaktprt                     \
		where rem_dzaktprt.iddoc_rem_dzaktprt=:PARAM_IDDOC";

dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
dm_qr->pFIBQ->ExecQuery();

if (dm_qr->pFIBQ->RecordCount >= 1) //найден документ
{
		IREM_FormaDocZVosvrZap * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVosvrZap,IID_IREM_FormaDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->DocAllIDBASE_REM_GALLDOC->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->DocAllIDSKLAD_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
		doc->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=DM->DocIDPOST_ZIP_REM_DZAKTPR->AsString;
		doc->DM->DocAllNAMEKLIENT->AsString=DM->DocPOST_ZIP_NAME->AsString;
		doc->DM->DocAll->Post();


		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZVZAP->AsString=DM->DocIDZ_REM_DZAKTPR->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->DocNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->DocPOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->DocSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->DocMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->DocKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocNAME_REM_Z->AsString=DM->DocNAME_REM_Z->AsString;
		doc->DM->Doc->Post();


while (!dm_qr->pFIBQ->Eof)
	{
	if (dm_qr->pFIBQ->FieldByName("tnom")->AsInteger ==0)      //товар
		{
	doc->DM->TableAppend();
	doc->DM->DocT->Edit();
	doc->DM->DocTIDNOM_REM_DZVZAPT->AsString=dm_qr->pFIBQ->FieldByName("idnom_rem_dzaktprt")->AsString;
	doc->DM->DocTIDED_REM_DZVZAPT->AsString=dm_qr->pFIBQ->FieldByName("ided_rem_dzaktprt")->AsString;
	doc->DM->DocTARTNOM->AsString=dm_qr->pFIBQ->FieldByName("artnom")->AsString;
	doc->DM->DocTNAMENOM->AsString=dm_qr->pFIBQ->FieldByName("namenom")->AsString;
	doc->DM->DocTNAMEED->AsString=dm_qr->pFIBQ->FieldByName("nameed")->AsString;
	doc->DM->DocTKOL_REM_DZVZAPT->AsFloat=dm_qr->pFIBQ->FieldByName("kol_rem_dzaktprt")->AsFloat;
	doc->DM->DocTKF_REM_DZVZAPT->AsFloat=dm_qr->pFIBQ->FieldByName("kf_rem_dzaktprt")->AsFloat;
	//doc->DM->DocTFL_ISP_REM_DZAKTPRT->AsInteger=1;  //использована в ремонте
	doc->DM->DocT->Post();
		}
	dm_qr->pFIBQ->Next();
	}
}


dm_qr->pFIBQ->Close();
dm_qr->kanRelease();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_FormaDocZAktPr::ViborStorageLocation(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_REM_DZAKTPRT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocation;

        }

}
//---------------------------------------------------------------------------
void TREM_FormaDocZAktPr::EndViborStorageLocation(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_REM_DZAKTPRT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZAktPr::cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocation();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_REM_DZAKTPRT->Clear();
		DM->DocTNAME_SMHRAN->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

