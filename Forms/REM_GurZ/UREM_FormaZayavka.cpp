//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UREM_FormaZayavka.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMQueryRead.h"
#include "IREM_FormaDocRemont.h"
#include "IAsyncExternalEvent.h"
#include "IREM_FormaSpiskaZayavkaImage.h"
#include "IREM_FormaCustQuery.h"
#include "IREM_FormaGurCustQuery.h"
#include "IREM_FormaDocZPost.h"
#include "IREM_FormaDocZVid.h"
#include "IDMSetup.h"
#include "IFormaImageEditor.h"
//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxMaskEdit"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxLabel"
#pragma link "cxImageComboBox"
#pragma link "cxPC"
#pragma link "cxDBLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaZayavka::TREM_FormaZayavka(TComponent* Owner)
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
bool TREM_FormaZayavka::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavka.1",IID_IREM_DMZayavka, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdZ=0;           //идентификатор текущей записи



cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceGurZKompl;
cxGrid2DBTableView1->DataController->DataSource=DM->DataSourceGurZNeispr;
cxGrid3DBTableView1->DataController->DataSource=DM->DataSourceDopUsl;
cxGrid4DBTableView1->DataController->DataSource=DM->DataSourcePerformedWork;
cxGrid5DBTableView1->DataController->DataSource=DM->DataSourcePrNeispr;

IDcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;

NameDialercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameTypeRemontcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameSostcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SrokcxDBDateEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SumcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameSostcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
OutcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;
DescrcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;

KlientNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KlientAdtrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KomplcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
NeisprcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
SostcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;

CommentscxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
OtremontcxDBDateEdit->DataBinding->DataSource=DM->DataSourceGurZ;
VidanocxDBDateEdit->DataBinding->DataSource=DM->DataSourceGurZ;
WarrantycxDBCalcEdit->DataBinding->DataSource=DM->DataSourceGurZ;

NameHardwarecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
SerNum2cxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;

KlientUvedomlencxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;
TrebKonsultKlientacxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;
KlientOtvetNaZaproscxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;

AddReportcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;
NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NumGarDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;


FictivcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;

flNeOtchcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;
flNadoOtchcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;


IsmGarDoccxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;
IsmSerNumcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;
IsmSerNum2cxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ;
NewNumGarDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NewSerNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NewSerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
GotovoKVadachecxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;
SostDevicecxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;

FlPovtorcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ;

NameSkladPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameSkladTeccxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;

NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;

DopInfocxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ_1;
EmailcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
NameproducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
ProducerModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
SellercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
FlVklcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
FlDefectDemocxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
FlZipcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
FlKlientPreupregdencxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;

AdrCodeRegioncxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrRegioncxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
RayoncxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrNasPunktcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrPostCodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrStreetcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrDomcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
StroencxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
AdrKVcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;

FlProblemKlientcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
FlProblemDevicecxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
PlombaSetcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
TextPlombacxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;



NeisprEngcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ_1;

DefectEngcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ_1;
SolutionEngcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ_1;
StrCodeVigrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ_1;
OnlyDiagnosticcxDBCheckBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditFAMILIYA_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditIMYA_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditOTCHESTVO_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;


NameGrpCFCcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ_1;
CodeNeisprPrcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBButtonEditNAME_REM_SPRNEISPR->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBLabelNAME_ENG_REM_SPRNEISPR_GRP->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBLabelNAME_ENG_REM_SPRNEISPR->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBDateEditPOS_ZAPROSA_NA_AKT_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
KEM_SDANOcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditNUMBAT_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditPARTNUM_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditREFERENCE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSWCODE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditHWCODE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditPODO_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditPOPOSLE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBDateEditDATE_VIPUSK_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBDateEditDATE_PRODAGI_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSERNUM3_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSERNUM4_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;

cxDBCheckBoxFL_ISM_SERNUM3_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBCheckBoxFL_ISM_SERNUM4_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBCheckBoxFL_ISM_PARTNUM_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBCheckBoxFL_ISM_REFERENCE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBCheckBoxFL_ISM_SWCODE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBCheckBoxFL_ISM_HWCODE_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSERNUM3_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSERNUM4_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditPARTNUM_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditREFERENCE_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditSWCODE_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;
cxDBTextEditHWCODE_NEW_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;

cxDBCalcEditPREDOPLATA_REM_Z_1->DataBinding->DataSource=DM->DataSourceGurZ_1;



ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumber1cxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumber2cxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
NameKlientcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
NameDilercxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
SostcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
NeisprcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
TypeRemontcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;




ActionOperation=aoNO;
DBTextNameUser->DataSource=DM->DataSourceGurZ;
//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaZayavkaImpl),false);
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
//--------------------------------------------------------------------------
int TREM_FormaZayavka::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
		{
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		cxGrid2DBTableView1->OptionsData->Editing=false;
		}
else
		{
		ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		cxGrid2DBTableView1->OptionsData->Editing=true;
		}



}

//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprSklad) FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(REM_FormaSpiskaSprKomplModel) REM_FormaSpiskaSprKomplModel->kanRelease();
if(REM_FormaSpiskaSprModel) REM_FormaSpiskaSprModel->kanRelease();
if(REM_FormaSpiskaSprNeispr) REM_FormaSpiskaSprNeispr->kanRelease();
if(REM_FormaSpiskaSprSost) REM_FormaSpiskaSprSost->kanRelease();
if(REM_FormaSpiskaSprTypeRemont) REM_FormaSpiskaSprTypeRemont->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();

if(FormaSpiskaSprNom) FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprEd) FormaSpiskaSprEd->kanRelease();
if(SpisokBrand)SpisokBrand->kanRelease();

if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(SpisokBrand)SpisokBrand->kanRelease();
if(REM_FormaSpiskaSprProducerModel)REM_FormaSpiskaSprProducerModel->kanRelease();
if(FormaSpiskaSprSeller)FormaSpiskaSprSeller->kanRelease();
if(REM_FormaSpiskaSprActCategory)REM_FormaSpiskaSprActCategory->kanRelease();
if(REM_FormaSpiskaSprTypDefect)REM_FormaSpiskaSprTypDefect->kanRelease();
if(REM_FormaSpiskaSprTypRabot)REM_FormaSpiskaSprTypRabot->kanRelease();
if(FormaElementaSprAddressVibor)FormaElementaSprAddressVibor->kanRelease();
if(FormaSpiskaSprProducerNeispr)FormaSpiskaSprProducerNeispr->kanRelease();
if(FormaSpiskaSprProducerCondition)FormaSpiskaSprProducerCondition->kanRelease();

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

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaZayavka::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)
				{
				EventEndEditInfBase();
				}
		FormaSpiskaSprInfBase=0;
		}

if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)
				{
				EventEndEditFirm();
				}
		FormaSpiskaSprFirm=0;
		}

if (number_procedure_end==ER_SkladPr)
		{
		if (type_event==1)
				{
				EventEndEditSkladPr();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_SkladTec)
		{
		if (type_event==1)
				{
				EventEndEditSkladTec();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EventEndEditKlient();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Diler)
		{
		if (type_event==1)
				{
				EventEndEditDiler();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Model)
		{
		if (type_event==1)
				{
				EventEndEditModel();
				}
		REM_FormaSpiskaSprModel=0;
		}

if (number_procedure_end==ER_TypeRemont)
		{
		if (type_event==1)
				{
				EventEndEditTypeRemont();
				}
		REM_FormaSpiskaSprTypeRemont=0;
		}

if (number_procedure_end==ER_TecSost)
		{
		if (type_event==1)
				{
				EventEndEditTecSost();
				}
		REM_FormaSpiskaSprSost=0;
		}


if (number_procedure_end==ER_Kompl)
		{
		if (type_event==1)
				{
				EventEndEditZkompl();
				}
		REM_FormaSpiskaSprKomplModel=0;
		}

if (number_procedure_end==ER_Neispr)
		{
		if (type_event==1)
				{
				EventEndEditZNeispr();
				}
		REM_FormaSpiskaSprNeispr=0;
		}

if (number_procedure_end==ER_CloseDocRemont)
	{
  //обновим форму так как ремонт может изменить часть реквизитов
	__int64 idz=glStrToInt64(DM->GurZID_REM_Z->AsString);
	DM->OpenDoc(idz);
	UpdateForm();
	}


if (number_procedure_end==ER_ViborNomDopUsl)
		{
		if (type_event==1)
				{
				EventEndEditNom();
				}
		FormaSpiskaSprNom=0;
		}

if (number_procedure_end==ER_ViborEdDopUsl)
		{
		if (type_event==1)
				{
				EventEndEditEd();
				}
		FormaSpiskaSprEd=0;
		}

if (number_procedure_end==ER_ViborNomPerfWork)
		{
		if (type_event==1)
				{
				EventEndEditNomPerfWork();
				}
		FormaSpiskaSprNom=0;
		}

if (number_procedure_end==ER_ViborEdPerfWork)
		{
		if (type_event==1)
				{
				EventEndEditEdPerfWork();
				}
		FormaSpiskaSprEd=0;
		}

if (number_procedure_end==ER_ViborHardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ViborBrand)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborBrand();
					}
				SpisokBrand=0;
				}

if (number_procedure_end==ER_ViborProducer)
				{
				if (type_event==1)    //выбор сделан
					{
					EventEndEditProdcer();
					}
				FormaSpiskaSprProducer=0;
				}

if (number_procedure_end==ER_ViborProducerModel)
				{
				if (type_event==1)    //выбор сделан
					{
					EventEndEditProdcerModel();
					}
				REM_FormaSpiskaSprProducerModel=0;
				}


if (number_procedure_end==ER_ViborSeller)
		{
		if (type_event==1)
				{
				EndViborSeller();
				}
		FormaSpiskaSprSeller=0;
		}

if (number_procedure_end==ER_ViborActCategory)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborActCategory();
					}
				REM_FormaSpiskaSprActCategory=0;
				}

if (number_procedure_end==ER_ViborEngTypRabot)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborTypRabot();
					}
				REM_FormaSpiskaSprTypRabot=0;
				}

if (number_procedure_end==ER_ViborEngTypDefect)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborTypDefect();
					}
				REM_FormaSpiskaSprTypDefect=0;
				}

if (number_procedure_end==ER_ViborAddress)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborAddress();
					}
				FormaElementaSprAddressVibor=0;
				}
if (number_procedure_end==ER_ViborProducerNeispr)
		{
		if (type_event==1)
				{
				EndViborProducerNeispr();
				}
		FormaSpiskaSprProducerNeispr=0;
		}

if (number_procedure_end==ER_ViborProducerNesprInTable)
		{
		if (type_event==1)
				{
				EndViborProducerNeisprInTable();
				}
		FormaSpiskaSprProducerNeispr=0;
		}


if (number_procedure_end==ER_ViborProducerCondition)
		{
		if (type_event==1)
				{
				EndViborProducerCondition();
				}
		FormaSpiskaSprProducerCondition=0;
		}


return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditInfBase(void)
{
if(FormaSpiskaSprInfBase==0) return;


				DM->GurZ->Edit();
				DM->GurZIDBASE_REM_Z->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
				DM->GurZNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;

				DM->GurZNAME_REM_Z->AsString="Заявка №"+DM->GurZNUM_REM_Z->AsString+
				" от "+DM->GurZPOS_REM_Z->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprInfBase=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditFirm(void)
{
if (FormaSpiskaSprFirm==0)  return;


				DM->GurZ->Edit();
				DM->GurZIDFIRM_REM_Z->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->GurZNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;

				DM->GurZNAME_REM_Z->AsString="Заявка №"+DM->GurZNUM_REM_Z->AsString+
				" от "+DM->GurZPOS_REM_Z->AsString;

				DM->GurZ->Post();





		FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditSkladPr(void)
{
if (FormaSpiskaSprSklad==0)  return;


				DM->GurZ->Edit();
				DM->GurZIDSKLPR_REM_Z->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
				DM->GurZNAME_SKLAD_PR->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;

				DM->GurZNAME_REM_Z->AsString="Заявка №"+DM->GurZNUM_REM_Z->AsString+
				" от "+DM->GurZPOS_REM_Z->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditSkladTec(void)
{
if (FormaSpiskaSprSklad==0)  return;


				DM->GurZ->Edit();
				DM->GurZIDTECSKL_REM_Z->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
				DM->GurZNAME_SKLAD_TEC->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
				DM->GurZ->Post();

		FormaSpiskaSprSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->GurZ->Edit();
				DM->GurZIDKLIENT_REM_Z->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->GurZNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString+
										FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZKLIENT_ADR_REM_Z->AsString=DM->GurZKLIENT_ADR_REM_Z->AsString+
										FormaSpiskaSprKlient->DM->ElementADRKLIENT->AsString;
				DM->GurZKLIENT_PHONE_REM_Z->AsString=DM->GurZKLIENT_PHONE_REM_Z->AsString+
										FormaSpiskaSprKlient->DM->ElementTELKLIENT->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprKlient=0;
 FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditDiler(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->GurZ->Edit();
				DM->GurZIDDILER_REM_Z->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->GurZNAMEDILER->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZ->Post();

		FormaSpiskaSprKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditModel(void)
{
if (REM_FormaSpiskaSprModel==0) return;


				DM->GurZ->Edit();
				DM->GurZIDMODEL_REM_Z->AsString=REM_FormaSpiskaSprModel->DM->ElementID_REM_SMODEL->AsString;
				DM->GurZNAME_REM_SMODEL->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->GurZMODEL_REM_Z->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->GurZ->Post();

		REM_FormaSpiskaSprModel=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditTypeRemont(void)
{
if (REM_FormaSpiskaSprTypeRemont==0) return;


				DM->GurZ->Edit();
				DM->GurZIDTYPEREM_REM_Z->AsString=REM_FormaSpiskaSprTypeRemont->DM->ElementID_STREMONT->AsString;
				DM->GurZNAME_STREMONT->AsString=REM_FormaSpiskaSprTypeRemont->DM->ElementNAME_STREMONT->AsString;
				DM->GurZ->Post();

		REM_FormaSpiskaSprTypeRemont=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditTecSost(void)
{
if (REM_FormaSpiskaSprSost==0) return;


				DM->GurZ->Edit();
				DM->GurZIDSOST_REM_Z->AsString=REM_FormaSpiskaSprSost->DM->ElementID_REMSSOST->AsString;
				DM->GurZNAME_REMSSOST->AsString=REM_FormaSpiskaSprSost->DM->ElementNAME_REMSSOST->AsString;
				DM->GurZ->Post();

		REM_FormaSpiskaSprSost=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::EventEndEditZkompl(void)
{
if (REM_FormaSpiskaSprKomplModel==0) return;


				if (ActionOperation==aoAddNewString)
                        {
						DM->GurZKompl->Append();
                        }
				DM->GurZKompl->Edit();
				DM->GurZKomplIDKOMPL_REM_ZKOMPL->AsString=REM_FormaSpiskaSprKomplModel->DM->TableID_REM_SKOMPLMODEL->AsString;
				DM->GurZKomplNAME_REM_SKOMPLMODEL->AsString=REM_FormaSpiskaSprKomplModel->DM->TableNAME_REM_SKOMPLMODEL->AsString;
				DM->GurZKompl->Post();

		REM_FormaSpiskaSprKomplModel=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditZNeispr(void)
{
if (REM_FormaSpiskaSprNeispr==0) return;


				if (ActionOperation==aoAddNewString)
                        {
						DM->GurZNeispr->Append();
						}
				DM->GurZNeispr->Edit();
				DM->GurZNeisprIDNEISPR_REM_ZNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->TableID_REM_SNEISPR->AsString;
				DM->GurZNeisprNAME_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->TableNAME_REM_SNEISPR->AsString;
				DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->TableNAME_ENG_REM_SNEISPR->AsString;
				//DM->GurZNeisprNAME_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SNEISPR->AsString;
				DM->GurZNeispr->Post();


				if (DM->GurZNEISPR_REM_Z->AsString =="")
					{
					DM->GurZ->Edit();
					DM->GurZNEISPR_REM_Z->AsString = REM_FormaSpiskaSprNeispr->DM->TableNAME_REM_SNEISPR->AsString;
					DM->GurZ->Post();
					}

				DM->GurZ_1->Edit();
				if (DM->GurZ_1NEISPR_ENG_REM_Z_1->AsString=="")
					{
					DM->GurZ_1NEISPR_ENG_REM_Z_1->AsString = REM_FormaSpiskaSprNeispr->DM->TableNAME_ENG_REM_SNEISPR->AsString;
					}
				else
					{
					 DM->GurZ_1NEISPR_ENG_REM_Z_1->AsString = DM->GurZ_1NEISPR_ENG_REM_Z_1->AsString +". " + REM_FormaSpiskaSprNeispr->DM->TableNAME_ENG_REM_SNEISPR->AsString;
					}
				DM->GurZ_1->Post();
				//NeisprEngcxDBMemo->Refresh();

		REM_FormaSpiskaSprNeispr=0;
}
//---------------------------------------------------------------------------



////---------------------------------------------------------------------------






void __fastcall TREM_FormaZayavka::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Doc/DocReal");
}
//---------------------------------------------------------------------------











void __fastcall TREM_FormaZayavka::ActionAddNewKomplExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprKomplModel==0)
		{
		ActionOperation=aoAddNewString;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprKomplModel.1",IID_IREM_FormaSpiskaSprKomplModel,
								 (void**)&REM_FormaSpiskaSprKomplModel);
		REM_FormaSpiskaSprKomplModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprKomplModel) return;
		REM_FormaSpiskaSprKomplModel->Vibor=true;
		REM_FormaSpiskaSprKomplModel->NumberProcVibor=ER_Kompl;
		REM_FormaSpiskaSprKomplModel->IdModel=glStrToInt64(DM->GurZIDMODEL_REM_Z->AsString);
		//REM_FormaSpiskaSprKomplModel->LabelModel->Caption=DM->GurZNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprKomplModel->UpdateForm();
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionEditKomplExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprKomplModel==0)
		{
		ActionOperation=aoNO;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprKomplModel.1",IID_IREM_FormaSpiskaSprKomplModel,
								 (void**)&REM_FormaSpiskaSprKomplModel);
		REM_FormaSpiskaSprKomplModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprKomplModel) return;
		REM_FormaSpiskaSprKomplModel->Vibor=true;
		REM_FormaSpiskaSprKomplModel->NumberProcVibor=ER_Kompl;
		REM_FormaSpiskaSprKomplModel->IdModel=glStrToInt64(DM->GurZIDMODEL_REM_Z->AsString);
		//REM_FormaSpiskaSprKomplModel->LabelModel->Caption=DM->GurZNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprKomplModel->UpdateForm();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionAddNeisprExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprNeispr==0)
		{
		ActionOperation=aoAddNewString;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprNeispr.1",IID_IREM_FormaSpiskaSprNeispr,
								 (void**)&REM_FormaSpiskaSprNeispr);
		REM_FormaSpiskaSprNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprNeispr) return;
		REM_FormaSpiskaSprNeispr->Vibor=true;
		REM_FormaSpiskaSprNeispr->NumberProcVibor=ER_Neispr;
		REM_FormaSpiskaSprNeispr->UpdateForm();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionEditNeisprExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprNeispr==0)
		{
		ActionOperation=aoNO;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprNeispr.1",IID_IREM_FormaSpiskaSprNeispr,
								 (void**)&REM_FormaSpiskaSprNeispr);
		REM_FormaSpiskaSprNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprNeispr) return;
		REM_FormaSpiskaSprNeispr->Vibor=true;
		REM_FormaSpiskaSprNeispr->NumberProcVibor=ER_Neispr;
		REM_FormaSpiskaSprNeispr->UpdateForm();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionDeleteKomplExecute(TObject *Sender)
{
DM->GurZKompl->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionDeleteNeisprExecute(TObject *Sender)
{
DM->GurZNeispr->Delete();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaZayavka::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprInfBase==0)
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


void __fastcall TREM_FormaZayavka::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprFirm==0)
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
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameSkladPrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprSklad==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_SkladPr;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameDialercxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Diler;
		FormaSpiskaSprKlient->UpdateForm();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
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
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameStrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprTypeRemont==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprTypeRemont.1",IID_IREM_FormaSpiskaSprTypeRemont,
													(void**)&REM_FormaSpiskaSprTypeRemont);
		REM_FormaSpiskaSprTypeRemont->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprTypeRemont) return;
		REM_FormaSpiskaSprTypeRemont->Vibor=true;
		REM_FormaSpiskaSprTypeRemont->NumberProcVibor=ER_TypeRemont;
		REM_FormaSpiskaSprTypeRemont->DM->OpenTable();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameModelcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprModel==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprModel.1",IID_IREM_FormaSpiskaSprModel,
													(void**)&REM_FormaSpiskaSprModel);
		REM_FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprModel) return;
		REM_FormaSpiskaSprModel->Vibor=true;
		REM_FormaSpiskaSprModel->NumberProcVibor=ER_Model;
		REM_FormaSpiskaSprModel->UpdateForm();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameSostcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprSost==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprSost.1",IID_IREM_FormaSpiskaSprSost,
													(void**)&REM_FormaSpiskaSprSost);
		REM_FormaSpiskaSprSost->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprSost) return;
		REM_FormaSpiskaSprSost->Vibor=true;
		REM_FormaSpiskaSprSost->NumberProcVibor=ER_TecSost;
		REM_FormaSpiskaSprSost->DM->OpenTable();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NameSkladTeccxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprSklad==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_SkladTec;
		}	
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaZayavka::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaZayavka::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdZayvka", glStrToInt64(DM->GurZID_REM_Z->AsString));


module->ExecuteModule();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->GurZ->Edit();
	DM->GurZNAME_REM_Z->AsString="Заявка №"+DM->GurZNUM_REM_Z->AsString+
				" от "+DM->GurZPOS_REM_Z->AsString;
	DM->GurZ->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::PoscxDBDateEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->GurZ->Edit();
	DM->GurZNAME_REM_Z->AsString="Заявка №"+DM->GurZNUM_REM_Z->AsString+
				" от "+DM->GurZPOS_REM_Z->AsString;
	DM->GurZ->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaZayavka::KlientNamecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{

	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::KlientAdtrcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::KlientPhonecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ModelcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::SerNumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::SerNum2cxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::DescrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonOpenDocRemontClick(TObject *Sender)
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
dm_qr->pFIBQ->ParamByName("PARAM_IDZ")->AsString=DM->GurZID_REM_Z->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_z=0;
id_z=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_galldoc")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();




if (id_z!=0)
		{
		 //откроем документ
		IREM_FormaDocRemont* doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRemont,IID_IREM_FormaDocRemont,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		doc->Vibor=true;
		doc->NumberProcVibor=ER_CloseDocRemont;
		doc->DM->OpenDoc(id_z);
		}
else
		{
		ShowMessage("Нет документа Ремонт");
		}


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonCreateDocRemontClick(TObject *Sender)

{
if (DM->SaveDoc()==false)
	{
	ShowMessage("Не удалось записать заявку!");
	return;
	}


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
dm_qr->pFIBQ->ParamByName("PARAM_IDZ")->AsString=DM->GurZID_REM_Z->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_z=0;
id_z=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_galldoc")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();


IREM_FormaDocRemont* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocRemont,IID_IREM_FormaDocRemont,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
doc->Vibor=true;
doc->NumberProcVibor=ER_CloseDocRemont;

if (id_z!=0)
	{
	//откроем документ
	doc->DM->OpenDoc(id_z);
	}
else
	{
	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->GurZIDBASE_REM_Z->AsString;
	doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->GurZNAME_SINFBASE_OBMEN->AsString;
	doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->GurZIDFIRM_REM_Z->AsString;
	doc->DM->DocAllNAMEFIRM->AsString=DM->GurZNAMEFIRM->AsString;
	doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->GurZIDTECSKL_REM_Z->AsString;
	doc->DM->DocAllNAMESKLAD->AsString=DM->GurZNAME_SKLAD_TEC->AsString;
	doc->DM->DocAll->Post();

	doc->DM->Doc->Edit();
	doc->DM->DocIDZ_REM_DREMONT->AsString=DM->GurZID_REM_Z->AsString;
	doc->DM->DocNAME_REM_Z->AsString=DM->GurZNAME_REM_Z->AsString;
	doc->DM->DocNUM_REM_Z->AsString=DM->GurZNUM_REM_Z->AsString;
	doc->DM->DocPOS_REM_Z->AsString=DM->GurZPOS_REM_Z->AsString;
	doc->DM->DocSERNUM_REM_Z->AsString=DM->GurZSERNUM_REM_Z->AsString;
	doc->DM->DocSERNUM2_REM_Z->AsString=DM->GurZSERNUM2_REM_Z->AsString;
	doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
	doc->DM->DocMODEL_REM_Z->AsString=DM->GurZMODEL_REM_Z->AsString;
	doc->DM->Doc->Post();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaZayavka::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaZayavka::FormDeactivate(TObject *Sender)
{
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
//событие считывания штрих-кода
void __fastcall TREM_FormaZayavka::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM_REM_Z->AsString=sh;
	DM->GurZ->Post();
	}
else if (SerNum2cxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM2_REM_Z->AsString=sh;
	DM->GurZ->Post();
	}
else if (KomplcxDBMemo->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZKOMPLECT_REM_Z->AsString=DM->GurZKOMPLECT_REM_Z->AsString+sh;
	DM->GurZ->Post();
	}
else if (cxDBTextEditSERNUM3_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1SERNUM3_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditSERNUM4_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1SERNUM4_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditNUMBAT_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1NUMBAT_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditPARTNUM_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1PARTNUM_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (NewNumGarDoccxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZNUM_GARDOC_NEW_REM_Z->AsString=sh;
	DM->GurZ->Post();
	}
else if (NewSerNumcxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM_NEW_REM_Z->AsString=sh;
	DM->GurZ->Post();
	}
else if (NewSerNum2cxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM2_NEW_REM_Z->AsString=sh;
	DM->GurZ->Post();
	}
else if (cxDBTextEditSERNUM3_NEW_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1SERNUM3_NEW_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditSERNUM4_NEW_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1SERNUM4_NEW_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditPARTNUM_NEW_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1PARTNUM_NEW_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}
else if (cxDBTextEditREFERENCE_NEW_REM_Z_1->Focused()==true)
	{
	DM->GurZ_1->Edit();
	DM->GurZ_1REFERENCE_NEW_REM_Z_1->AsString=sh;
	DM->GurZ_1->Post();
	}




}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::ActionAddNewDopUslExecute(TObject *Sender)
{
DM->DopUsl->Append();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionDeleteDopUslExecute(TObject *Sender)
{
DM->DopUsl->Delete();
}
//---------------------------------------------------------------------------

void TREM_FormaZayavka::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL && glStrToInt64(DM->DopUslIDNOM_REM_ZDOPUSL->AsString) > 0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->NumberProcVibor=ER_ViborEdDopUsl;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DopUslIDNOM_REM_ZDOPUSL->AsString));
		}
}
//-----------------------------------------------------------------------------
void TREM_FormaZayavka::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->NumberProcVibor=ER_ViborNomDopUsl;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DopUslIDNOM_REM_ZDOPUSL->AsString);
		FormaSpiskaSprNom->UpdateForm();
        }

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditNom(void)
{
				DM->DopUsl->Edit();
				DM->DopUslIDNOM_REM_ZDOPUSL->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DopUslNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
				if (DM->DopUslTEXTNOM_REM_ZDOPUSL->AsString == "")
					{
					DM->DopUslTEXTNOM_REM_ZDOPUSL->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
                    }


				DM->DopUslKOL_REM_ZDOPUSL->AsFloat=1;

				DM->DopUslIDED_REM_ZDOPUSL->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DopUslNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DopUslKF_REM_ZDOPUSL->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				DM->DopUslPRICE_REM_ZDOPUSL->AsFloat=FormaSpiskaSprNom->DM->ElementZNACH_PRICE->AsFloat
												*DM->DopUslKF_REM_ZDOPUSL->AsFloat;

				DM->DopUsl->Post();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditEd(void)
{
				DM->DopUsl->Edit();
				DM->DopUslIDED_REM_ZDOPUSL->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
				DM->DopUslNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
				DM->DopUslKF_REM_ZDOPUSL->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				DM->DopUsl->Post();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::cxGrid3DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxGrid3DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprEd();
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::OpenFormSpiskaSprEdPerfWork(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL && glStrToInt64(DM->PerformedWorkIDNOM_REM_ZPERFWORK->AsString) > 0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->NumberProcVibor=ER_ViborEdPerfWork;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->PerformedWorkIDNOM_REM_ZPERFWORK->AsString));
		}
}
//-----------------------------------------------------------------------------
void TREM_FormaZayavka::OpenFormSpiskaSprNomPerfWork(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->NumberProcVibor=ER_ViborNomPerfWork;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM_Connection->UserInfoIDTPRICE_USER->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->PerformedWorkIDNOM_REM_ZPERFWORK->AsString);
		FormaSpiskaSprNom->UpdateForm();
        }

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditNomPerfWork(void)
{
				DM->PerformedWork->Edit();
				DM->PerformedWorkIDNOM_REM_ZPERFWORK->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->PerformedWorkNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
				if (DM->PerformedWorkTEXTNOM_REM_ZPERFWORK->AsString == "")
					{
					DM->PerformedWorkTEXTNOM_REM_ZPERFWORK->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
                    }


				DM->PerformedWorkKOL_REM_ZPERFWORK->AsFloat=1;

				DM->PerformedWorkIDED_REM_ZPERFWORK->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->PerformedWorkNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->PerformedWorkKF_REM_ZPERFWORK->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				DM->PerformedWorkPRICE_REM_ZPERFWORK->AsFloat=FormaSpiskaSprNom->DM->ElementZNACH_PRICE->AsFloat
												*DM->DopUslKF_REM_ZDOPUSL->AsFloat;

				DM->PerformedWork->Post();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EventEndEditEdPerfWork(void)
{
				DM->PerformedWork->Edit();
				DM->PerformedWorkIDED_REM_ZPERFWORK->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
				DM->PerformedWorkNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
				DM->PerformedWorkKF_REM_ZPERFWORK->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				DM->PerformedWork->Post();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::ActionAddPerformedWorkExecute(TObject *Sender)

{
DM->PerformedWork->Append();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ActionDeletePerformedWorkExecute(TObject *Sender)

{
DM->PerformedWork->Delete();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaZayavka::cxGrid4DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprNomPerfWork();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxGrid4DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprEdPerfWork();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxButtonOpenSpisokImageClick(TObject *Sender)
{
IREM_FormaSpiskaZayavkaImage * FormaSpiska;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaZayavkaImage,IID_IREM_FormaSpiskaZayavkaImage,
						 (void**)&FormaSpiska);
FormaSpiska->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiska->IdZ=DM->GurZID_REM_Z->AsLargeInt;
FormaSpiska->UpdateForm();
FormaSpiska->NumberProcVibor=ER_ViborFoto;
}
//---------------------------------------------------------------------------
//выбор заявки
void TREM_FormaZayavka::ViborHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));

	DM->GurZ->Edit();
	DM->GurZIDHW_REM_Z->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->GurZNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->GurZSERNUM_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	DM->GurZSERNUM2_REM_SHARDWARE->AsString=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;

	DM->GurZSERNUM_REM_Z->AsString=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	DM->GurZSERNUM2_REM_Z->AsString=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
	DM->GurZIDMODEL_REM_Z->AsString=spr_hw->ElementIDMODEL_REM_SHARDWARE->AsString;
	DM->GurZNAME_REM_SMODEL->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;
    DM->GurZMODEL_REM_Z->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;
	DM->GurZ->Post();

spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::NameHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
		//Бренд
void TREM_FormaZayavka::ViborBrand(void)
{
if (SpisokBrand==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBrand.1",IID_IFormaSpiskaSprBrand,
													 (void**)&SpisokBrand);
		SpisokBrand->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBrand->Vibor=true;
		SpisokBrand->NumberProcVibor=ER_ViborBrand;
		}

}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::EndViborBrand(void)
{

	DM->GurZ->Edit();
	DM->GurZIDBRAND_REM_Z->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->GurZNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->GurZ->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborBrand();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonCreateCQueryClick(TObject *Sender)
{
IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->NewDoc();


	REM_FormaCustQuery->DM->Doc->Edit();
	REM_FormaCustQuery->DM->DocIDZ_REM_CQUERY->AsString=DM->GurZID_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocNAME_REM_Z->AsString=DM->GurZNAME_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocMODEL_REM_Z->AsString=DM->GurZMODEL_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocNUM_REM_Z->AsString=DM->GurZNUM_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocPOS_REM_Z->AsString=DM->GurZPOS_REM_Z->AsString;

	if (glStrToInt64(DM->GurZIDKLIENT_REM_Z->AsString) > 0)
		{
		REM_FormaCustQuery->DM->DocIDKLIENT_REM_CQUERY->AsString=DM->GurZIDKLIENT_REM_Z->AsString;
		REM_FormaCustQuery->DM->DocNAMEKLIENT->AsString=DM->GurZNAMEKLIENT->AsString;
		}

	if (glStrToInt64(DM->GurZIDBASE_REM_Z->AsString) > 0)
		{
		REM_FormaCustQuery->DM->DocIDBASE_REM_CQUERY->AsString=DM->GurZIDBASE_REM_Z->AsString;
		REM_FormaCustQuery->DM->DocNAME_SINFBASE_OBMEN->AsString=DM->GurZNAME_SINFBASE_OBMEN->AsString;
		}

	REM_FormaCustQuery->DM->DocNAME_MODEL_REM_CQUERY->AsString=DM->GurZMODEL_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocKLIENT_NAME_REM_CQUERY->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocKLIENT_ADR_REM_CQUERY->AsString=DM->GurZKLIENT_ADR_REM_Z->AsString;
	REM_FormaCustQuery->DM->DocKLIENT_PHONE_REM_CQUERY->AsString=DM->GurZKLIENT_PHONE_REM_Z->AsString;

REM_FormaCustQuery->DM->Doc->Post();
REM_FormaCustQuery->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::AddComplClick(TObject *Sender)
{

TMenuItem *menu=(TMenuItem*) Sender;
	DM->GurZ->Edit();
	DM->GurZKOMPLECT_REM_Z->AsString=menu->Caption+" "+DM->GurZKOMPLECT_REM_Z->AsString;
	DM->GurZ->Post();

}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborProducerModel(void)
{
if(Prosmotr==true) return;
if (REM_FormaSpiskaSprProducerModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
													(void**)&REM_FormaSpiskaSprProducerModel);
		REM_FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprProducerModel) return;
		REM_FormaSpiskaSprProducerModel->flVibor=true;
		REM_FormaSpiskaSprProducerModel->NumberProcVibor=ER_ViborProducerModel;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::EventEndEditProdcerModel(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1IDPRMODEL_REM_Z_1->AsString=REM_FormaSpiskaSprProducerModel->DM->TableID_REM_SPRMODEL->AsString;
	DM->GurZ_1NAME_REM_SPRMODEL->AsString=REM_FormaSpiskaSprProducerModel->DM->TableNAME_REM_SPRMODEL->AsString;
	DM->GurZ_1->Post();

REM_FormaSpiskaSprProducerModel=0;

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::ViborProducer(void)
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
void TREM_FormaZayavka::EventEndEditProdcer(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1IDPRODUCER_REM_Z_1->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->GurZ_1NAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->GurZ_1->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------








void __fastcall TREM_FormaZayavka::NameproducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->GurZ_1->Edit();
		DM->GurZ_1IDPRODUCER_REM_Z_1->Clear();
		DM->GurZ_1->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducerModel();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->GurZ_1->Edit();
		DM->GurZ_1IDPRMODEL_REM_Z_1->Clear();
		DM->GurZ_1->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::SellercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->GurZ_1->Edit();
		DM->GurZ_1IDSELLER_REM_Z_1->Clear();
		DM->GurZ_1->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborSeller(void)
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
void TREM_FormaZayavka::EndViborSeller(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1IDSELLER_REM_Z_1->AsString=FormaSpiskaSprSeller->DM->TableID_SSELLER->AsString;
	DM->GurZ_1NAME_SSELLER->AsString=FormaSpiskaSprSeller->DM->TableNAME_SSELLER->AsString;


	DM->GurZ_1->Post();

FormaSpiskaSprSeller=0;

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::ViborActCategory(void)
{

if (REM_FormaSpiskaSprActCategory==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprActCategory,IID_IREM_FormaSpiskaSprActCategory,
													(void**)&REM_FormaSpiskaSprActCategory);
		REM_FormaSpiskaSprActCategory->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprActCategory) return;
		REM_FormaSpiskaSprActCategory->Vibor=true;
		REM_FormaSpiskaSprActCategory->NumberProcVibor=ER_ViborActCategory;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborActCategory(void)
{

	DM->GurZ->Edit();
	DM->GurZIDACTCAT_REM_Z->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
	DM->GurZNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
	DM->GurZ->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborActCategory();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->GurZ->Edit();
		DM->GurZIDACTCAT_REM_Z->Clear();
		DM->GurZ->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborTypDefect(void)
{

if (REM_FormaSpiskaSprTypDefect==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypDefect,IID_IREM_FormaSpiskaSprTypDefect,
													(void**)&REM_FormaSpiskaSprTypDefect);
		REM_FormaSpiskaSprTypDefect->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprTypDefect) return;
		REM_FormaSpiskaSprTypDefect->flVibor=true;
		REM_FormaSpiskaSprTypDefect->NumberProcVibor=ER_ViborEngTypDefect;
		REM_FormaSpiskaSprTypDefect->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborTypDefect(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1DEFECT_ENG_REM_Z_1->AsString=DM->GurZ_1DEFECT_ENG_REM_Z_1->AsString +".  "+
	REM_FormaSpiskaSprTypDefect->DM->TableNAME_ENG_REM_STYPDEFECT->AsString;
	DM->GurZ_1->Post();

REM_FormaSpiskaSprTypDefect=0;

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::ViborTypRabot(void)
{

if (REM_FormaSpiskaSprTypRabot==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypRabot,IID_IREM_FormaSpiskaSprTypRabot,
													(void**)&REM_FormaSpiskaSprTypRabot);
		REM_FormaSpiskaSprTypRabot->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprTypRabot) return;
		REM_FormaSpiskaSprTypRabot->flVibor=true;
		REM_FormaSpiskaSprTypRabot->NumberProcVibor=ER_ViborEngTypRabot;
		REM_FormaSpiskaSprTypRabot->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborTypRabot(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1SOLUTION_ENG_REM_Z_1->AsString=DM->GurZ_1SOLUTION_ENG_REM_Z_1->AsString +".  "+
	REM_FormaSpiskaSprTypRabot->DM->TableNAME_ENG_REM_STYPRABOT->AsString;
	DM->GurZ_1->Post();

REM_FormaSpiskaSprTypRabot=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::ViborTypDefectcxButtonClick(TObject *Sender)
{
ViborTypDefect();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::VibortyprabotcxButtonClick(TObject *Sender)
{
ViborTypRabot();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxDBTextEditOTCHESTVO_REM_Z_1KeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	DM->GurZ->Edit();
	DM->GurZKLIENT_NAME_REM_Z->AsString=
				DM->GurZ_1FAMILIYA_REM_Z_1->AsString+" "+ DM->GurZ_1IMYA_REM_Z_1->AsString+
					" "+DM->GurZ_1OTCHESTVO_REM_Z_1->AsString;


	DM->GurZ->Edit();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborAddress(void)
{

if (FormaElementaSprAddressVibor==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressVibor,IID_IFormaElementaSprAddressVibor,
													(void**)&FormaElementaSprAddressVibor);
		FormaElementaSprAddressVibor->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressVibor) return;
		FormaElementaSprAddressVibor->Vibor=true;
		FormaElementaSprAddressVibor->NumberProcVibor=ER_ViborAddress;
		FormaElementaSprAddressVibor->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborAddress(void)
{
	DM->GurZ_1->Edit();
	DM->GurZ_1IDADRKV_REM_Z_1->AsString=FormaElementaSprAddressVibor->DM_KV->TableID_SADR_KV->AsString;
	DM->GurZ_1->Post();



}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::ButtonAddressViborClick(TObject *Sender)
{
ViborAddress();
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborProducerNeispr(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
													(void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ViborProducerNeispr;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborProducerNeispr(void)
{

	DM->GurZ_1->Edit();
	DM->GurZ_1IDPRNEISPR_REM_Z_1->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
	DM->GurZ_1NAME_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->GurZ_1NAME_ENG_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_ENG_REM_SPRNEISPR->AsString;
	DM->GurZ_1CODE_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableCODE_REM_SPRNEISPR->AsString;
	//DM->GurZ_1NAME_REM_SPRNEISPR_GRP->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR_GRP->AsString;
	//DM->GurZ_1NAME_ENG_REM_SPRNEISPR_GRP->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->GurZ_1->Post();

FormaSpiskaSprProducerNeispr=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::CFCcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducerNeispr();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->GurZ_1->Edit();
		DM->GurZ_1IDPRNEISPR_REM_Z_1->Clear();
		DM->GurZ_1->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonCreateDocPostClick(TObject *Sender)
{
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();
UnicodeString zapros="select rem_z.id_rem_z from rem_z where rem_z.id_rem_z=:PARAM_ID ";
dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_ID")->AsString=DM->GurZID_REM_Z->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_z=0;
id_z=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_z")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();

if (id_z == 0)
	{
    ShowMessage("Необходимо сохранить заявку!");
	return;
	}



		IREM_FormaDocZPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPost,IID_IREM_FormaDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->GurZIDBASE_REM_Z->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->GurZNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->GurZIDFIRM_REM_Z->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->GurZNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->GurZIDSKLPR_REM_Z->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->GurZNAME_SKLAD_PR->AsString;
		doc->DM->DocAll->Post();

		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZPOSTT->AsString=DM->GurZID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->GurZNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->GurZPOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->GurZSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->GurZMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocTNAME_REM_Z->AsString=DM->GurZNAME_REM_Z->AsString;
		doc->DM->DocTKOL_REM_DZPOSTT->AsFloat=1;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonCreateDocZVidachaClick(TObject *Sender)

{
IDMQueryRead * dm_qr;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_qr);
dm_qr->Init(InterfaceMainObject,0);
dm_qr->pFIBQ->Close();
dm_qr->pFIBQ->SQL->Clear();
UnicodeString zapros="select rem_z.id_rem_z from rem_z where rem_z.id_rem_z=:PARAM_ID ";
dm_qr->pFIBQ->SQL->Add(zapros);
dm_qr->pFIBQ->ParamByName("PARAM_ID")->AsString=DM->GurZID_REM_Z->AsString;
dm_qr->pFIBQ->ExecQuery();
__int64 id_z=0;
id_z=glStrToInt64(dm_qr->pFIBQ->FieldByName("id_rem_z")->AsString);
dm_qr->pFIBQ->Close();
dm_qr->kanRelease();

if (id_z == 0)
	{
    ShowMessage("Необходимо сохранить заявку!");
	return;
	}



		IREM_FormaDocZVid * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVid,IID_IREM_FormaDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->GurZIDBASE_REM_Z->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->GurZNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->GurZIDFIRM_REM_Z->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->GurZNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->GurZIDSKLPR_REM_Z->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->GurZNAME_SKLAD_PR->AsString;
		doc->DM->DocAll->Post();

		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZVIDT->AsString=DM->GurZID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->GurZNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->GurZPOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->GurZSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->GurZMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocTNAME_REM_Z->AsString=DM->GurZNAME_REM_Z->AsString;
		doc->DM->DocTKOL_REM_DZVIDT->AsFloat=1;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::ViborProducerNeisprInTable(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==0)
		{

		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
								 (void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ViborProducerNesprInTable;
		FormaSpiskaSprProducerNeispr->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TREM_FormaZayavka::EndViborProducerNeisprInTable(void)
{
if (FormaSpiskaSprProducerNeispr==0) return;


				if (ActionOperation==aoAddNewString)
						{
						DM->GurZPrNeispr->Append();
						}
				DM->GurZPrNeispr->Edit();
				DM->GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
				DM->GurZPrNeisprNAME_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
				DM->GurZPrNeisprNAME_ENG_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_ENG_REM_SPRNEISPR->AsString;
				//DM->GurZNeisprNAME_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SNEISPR->AsString;
				DM->GurZPrNeispr->Post();


		FormaSpiskaSprProducerNeispr=0;

}
//---------------------------------------------------------------------------

void TREM_FormaZayavka::ViborProducerCondition(void)
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
void TREM_FormaZayavka::EndViborProducerCondition(void)
{
if (FormaSpiskaSprProducerCondition==0) return;

				DM->GurZPrNeispr->Edit();
				DM->GurZPrNeisprIDPRCOND_REM_ZPRNEISPR->AsString=FormaSpiskaSprProducerCondition->DM->TableID_REM_SPRCONDITION->AsString;
				DM->GurZPrNeisprNAME_REM_SPRCONDITION->AsString=FormaSpiskaSprProducerCondition->DM->TableNAME_REM_SPRCONDITION->AsString;
				DM->GurZPrNeisprNAME_ENG_REM_SPRCONDITION->AsString=FormaSpiskaSprProducerCondition->DM->TableNAME_ENG_REM_SPRCONDITION->AsString;
				//DM->GurZNeisprNAME_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SGRPNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SGRPNEISPR->AsString;
				//DM->GurZNeisprNAME_ENG_REM_SNEISPR->AsString=REM_FormaSpiskaSprNeispr->DM->ElementNAME_ENG_REM_SNEISPR->AsString;
				DM->GurZPrNeispr->Post();


		FormaSpiskaSprProducerCondition=0;

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavka::ToolButtonAddProducerNeisprClick(TObject *Sender)

{
ActionOperation=aoAddNewString;
ViborProducerNeisprInTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxGrid5DBTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerCondition();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::cxGrid5DBTableView1NAME_REM_SPRNEISPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ActionOperation=aoNO;
ViborProducerNeisprInTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonOpenGarTalonClick(TObject *Sender)
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
DecodeDate(DM->GurZPOS_REM_Z->AsDateTime,Year,Month,Day);

file_name=file_name+"\\"+DM->GurZIDBASE_REM_Z->AsString         // база заявки
					+"\\Garant"
					+"\\"+DM->GurZNAME_SBRAND->AsString
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->GurZSERNUM_REM_Z->AsString
					+".jpg";                                                  //месяц

ShowMessage(file_name);

IFormaImageEditor * ed;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaImageEditor,IID_IFormaImageEditor,
													(void**)&ed);
ed->Init(InterfaceMainObject,0);
ed->LoadFromFile(file_name);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonCreateDocPrihNalClick(TObject *Sender)

{
if (DM->SaveDoc()==false)
	{
	ShowMessage("Не удалось записать заявку!");
	return;
	}



IFormaDocPKORozn* doc;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocPKORozn,IID_IFormaDocPKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
doc->NumberProcVibor=ER_CloseDocPKORozn;


	doc->DM->NewDoc();
	doc->DM->DocAll->Edit();
	doc->DM->DocAllIDFIRMDOC->AsString=DM->GurZIDFIRM_REM_Z->AsString;
	doc->DM->DocAllNAMEFIRM->AsString=DM->GurZNAMEFIRM->AsString;
	doc->DM->DocAllSUMDOC->AsFloat=DM->GurZ_1PREDOPLATA_REM_Z_1->AsFloat;
	doc->DM->DocAll->Post();

	doc->DM->Doc->Edit();
	doc->DM->DocPROT_DPKOROZN->AsString=DM->GurZKLIENT_NAME_REM_Z->AsString;
	doc->DM->DocOSN_DPKOROZN->AsString="Предоплата за ремонт по заявке: "+DM->GurZNUM_REM_Z->AsString
										+" от "+DM->GurZPOS_REM_Z->AsString
										+", "+DM->GurZMODEL_REM_Z->AsString
										+", " + DM->GurZSERNUM_REM_Z->AsString
										+", " + DM->GurZSERNUM2_REM_Z->AsString;

	doc->DM->DocOPERATION_DPKOROZN->AsString= 0; //прочее
	doc->DM->Doc->Post();
	doc->UpdateForm();

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavka::ToolButtonDelProducerneisprClick(TObject *Sender)

{
DM->GurZPrNeispr->Delete();
}
//---------------------------------------------------------------------------



