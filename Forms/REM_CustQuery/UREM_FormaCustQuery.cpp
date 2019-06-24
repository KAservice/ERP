//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UREM_FormaCustQuery.h"
#include "IREM_FormaCustQueryDv.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMQueryRead.h"
#include "IREM_DMZayavka.h"

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
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxDBLabel"
#pragma link "cxImageComboBox"
#pragma link "cxSpinEdit"
#pragma link "cxPC"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaCustQuery::TREM_FormaCustQuery(TComponent* Owner)
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
bool TREM_FormaCustQuery::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdCQ=0;           //идентификатор текущей записи
IdCQT=0;


cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameSkladPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

KlientNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientAdtrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ModelZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SostcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
cxDBButtonEditPRODAVEC_NAME->DataBinding->DataSource=DM->DataSourceDoc;


ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
KlientUvedomlencxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;

NumZakazacxDBSpinEdit->DataBinding->DataSource=DM->DataSourceDoc;
DateZakazacxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;

TypeCQuerycxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
NameSprHardwarecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNumSprHardwarecxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2SprhardwarecxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

PostupilocxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameProducerModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

PlanPostavkicxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
ZakazanocxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
OtpravlenocxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNUM_STR_ZAK_POST_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;


cxDBTexNUM_STR_ZAK_POST_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBDateEditPOS_ZAK_POST_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNUM_STR_ZAK_SPROV_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBDateEditPOS_ZAK_SPROV_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNUM_DOC_OTPR_POST_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBDateEditPOS_DOC_OTPR_POST_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNUMDOCTK_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditTK_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;

cxDBLabelKLIENT_NAME_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;
cxDBLabelNAME_MODEL_REM_CQUERY->DataBinding->DataSource=DM->DataSourceDoc;



ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaCustQueryImpl),false);
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
int TREM_FormaCustQuery::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaCustQuery::UpdateForm(void)
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
void __fastcall TREM_FormaCustQuery::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprSklad) FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(REM_FormaSpiskaSprModel) REM_FormaSpiskaSprModel->kanRelease();
if(REM_FormaSpiskaSprProducerModel) REM_FormaSpiskaSprProducerModel->kanRelease();
if(REM_FormaSpiskaSprSostCustQuery) REM_FormaSpiskaSprSostCustQuery->kanRelease();

if(FormaGurZ)FormaGurZ->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();

if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(SpisokBrand)SpisokBrand->kanRelease();

if(FormaSpiskaSprProducerNom)FormaSpiskaSprProducerNom->kanRelease();

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

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaCustQuery::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EventEndEditSklad();
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



if (number_procedure_end==ER_Model)
		{
		if (type_event==1)
				{
				EventEndEditModel();
				}
		REM_FormaSpiskaSprModel=0;
		}

if (number_procedure_end==ER_SostCustQuery)
		{
		if (type_event==1)
				{
				EventEndEditSostCustQuery();
				}
		REM_FormaSpiskaSprSostCustQuery=0;
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


if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer();
				}
		FormaSpiskaSprProducer=0;
		}

if (number_procedure_end==ER_ViborBrand)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborBrand();
					}
				SpisokBrand=0;
				}


if (number_procedure_end==ER_ViborProducerNom)
		{
		if (type_event==1)
				{
				EndViborProducerNom();
				}
		FormaSpiskaSprProducerNom=0;
		}


if (number_procedure_end==ER_ViborHardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ProducerModel)
		{
		if (type_event==1)
				{
				EventEndEditProducerModel();
				}
		REM_FormaSpiskaSprProducerModel=0;
		}


if (number_procedure_end==ER_ViborProdavec)
		{
		if (type_event==1)
				{
				EndViborProdavec();
				}
		FormaSpiskaSprKlient=0;
		}

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EventEndEditInfBase(void)
{
if(FormaSpiskaSprInfBase==0) return;


				DM->Doc->Edit();
				DM->DocIDBASE_REM_CQUERY->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
				DM->DocNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
				DM->Doc->Post();

		FormaSpiskaSprInfBase=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EventEndEditFirm(void)
{
if (FormaSpiskaSprFirm==0)  return;


				DM->Doc->Edit();
				DM->DocIDFIRM_REM_CQUERY->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->Doc->Post();

		FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EventEndEditSklad(void)
{
if (FormaSpiskaSprSklad==0)  return;


				DM->Doc->Edit();
				DM->DocIDSKLAD_REM_CQUERY->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
				DM->DocNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
				DM->Doc->Post();

		FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EventEndEditKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->Doc->Edit();
				DM->DocIDKLIENT_REM_CQUERY->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocKLIENT_NAME_REM_CQUERY->AsString=DM->DocKLIENT_NAME_REM_CQUERY->AsString+
										FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocKLIENT_ADR_REM_CQUERY->AsString=DM->DocKLIENT_ADR_REM_CQUERY->AsString+
										FormaSpiskaSprKlient->DM->ElementADRKLIENT->AsString;
				DM->DocKLIENT_PHONE_REM_CQUERY->AsString=DM->DocKLIENT_PHONE_REM_CQUERY->AsString+
										FormaSpiskaSprKlient->DM->ElementTELKLIENT->AsString;

				DM->Doc->Post();

		FormaSpiskaSprKlient=0;
 FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::EventEndEditModel(void)
{
if (REM_FormaSpiskaSprModel==0) return;


				DM->Doc->Edit();
				DM->DocIDMODEL_REM_CQUERY->AsString=REM_FormaSpiskaSprModel->DM->ElementID_REM_SMODEL->AsString;
				DM->DocNAME_REM_SMODEL->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->DocMODEL_REM_Z->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->Doc->Post();

		REM_FormaSpiskaSprModel=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::EventEndEditSostCustQuery(void)
{
if (REM_FormaSpiskaSprSostCustQuery==0) return;


				DM->DocT->Edit();
				DM->DocTIDSOST_REM_CQUERYT->AsString=REM_FormaSpiskaSprSostCustQuery->DM->ElementID_REM_SSOST_CQUERY->AsString;
				DM->DocTNAME_REM_SSOST_CQUERY->AsString=REM_FormaSpiskaSprSostCustQuery->DM->ElementNAME_REM_SSOST_CQUERY->AsString;
				DM->DocT->Post();

		REM_FormaSpiskaSprSostCustQuery=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::NameInfBasecxDBButtonEditPropertiesButtonClick(
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


void __fastcall TREM_FormaCustQuery::cxDBButtonEdit1PropertiesButtonClick(
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

void __fastcall TREM_FormaCustQuery::NameSkladPrcxDBButtonEditPropertiesButtonClick(
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
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaCustQuery::NameKlientcxDBButtonEditPropertiesButtonClick(
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



void __fastcall TREM_FormaCustQuery::NameModelcxDBButtonEditPropertiesButtonClick(
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


void __fastcall TREM_FormaCustQuery::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaCustQuery::ActionSaveExecute(TObject *Sender)
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
void __fastcall TREM_FormaCustQuery::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaCustQuery::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdCustQuery", glStrToInt64(DM->DocID_REM_CQUERY->AsString));


module->ExecuteModule();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaCustQuery::KlientNamecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::KlientAdtrcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::KlientPhonecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::ModelcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::SerNumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::SerNum2cxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::DescrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaCustQuery::ToolButton1Click(TObject *Sender)
{
DM->DocT->Append();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::cxGrid1DBBandedTableView1NAME_REM_SSOST_CQUERYPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprSostCustQuery==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprSostCustQuery,IID_IREM_FormaSpiskaSprSostCustQuery,
													(void**)&REM_FormaSpiskaSprSostCustQuery);
		REM_FormaSpiskaSprSostCustQuery->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprSostCustQuery) return;
		REM_FormaSpiskaSprSostCustQuery->Vibor=true;
		REM_FormaSpiskaSprSostCustQuery->NumberProcVibor=ER_SostCustQuery;
		//REM_FormaSpiskaSprSostCustQuery->UpdateForm();
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaCustQuery::ToolButton6Click(TObject *Sender)
{
DM->DocT->Delete();
}
//---------------------------------------------------------------------------
//выбор заявки
void TREM_FormaCustQuery::ViborRemZ(void)
{
if(Prosmotr==true) return;
if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EndViborRemZ(void)
{

IREM_DMZayavka *dm_z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
dm_z->Init(InterfaceMainObject,InterfaceImpl);
dm_z->OpenDoc(glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString));

	DM->Doc->Edit();
	DM->DocIDZ_REM_CQUERY->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->DocNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocKLIENT_NAME_REM_Z->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	DM->DocMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;

	if (glStrToInt64(FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString) > 0)
		{
		DM->DocIDKLIENT_REM_CQUERY->AsString=FormaGurZ->DM->TableIDKLIENT_REM_Z->AsString;
		DM->DocNAMEKLIENT->AsString=FormaGurZ->DM->TableNAMEKLIENT->AsString;
		}

	DM->DocNAME_MODEL_REM_CQUERY->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;

	if (DM->DocKLIENT_NAME_REM_CQUERY->AsString=="")
		{
		DM->DocKLIENT_NAME_REM_CQUERY->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
		}
	if (DM->DocKLIENT_ADR_REM_CQUERY->AsString=="")
		{
		DM->DocKLIENT_ADR_REM_CQUERY->AsString=dm_z->GurZKLIENT_ADR_REM_Z->AsString;
		}

	if (DM->DocKLIENT_PHONE_REM_CQUERY->AsString=="")
		{
		DM->DocKLIENT_PHONE_REM_CQUERY->AsString=dm_z->GurZKLIENT_PHONE_REM_Z->AsString;
		}

	DM->Doc->Post();
	UpdateForm();

dm_z->kanRelease();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
//выбор номенклатуры
void TREM_FormaCustQuery::ViborNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNom,IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprNom) return;
		FormaSpiskaSprNom->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DREMONT->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_CQUERYT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EndViborNom(void)
{

                DM->DocT->Edit();
				DM->DocTIDNOM_REM_CQUERYT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_REM_CQUERYT->AsInteger=1;


				DM->DocTIDED_REM_CQUERYT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_CQUERYT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

//					IDMSprPrice * DMSprPrice;
//					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
//													(void**)&DMSprPrice);
//					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
//
//					DM->DocTPRICE_REM_DREMONTT->AsFloat=
//							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DREMONT->AsString), //тип цен
//											glStrToInt64(DM->DocTIDNOM_REM_DREMONTT->AsString),            //номенклатура
//											glStrToInt64(DM->DocTIDED_REM_DREMONTT->AsString),             //единица
//											DM->DocTKF_REM_DREMONTT->AsFloat,                              //коэффициент
//											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //базовая единица
//					DMSprPrice->kanRelease();


				DM->DocT->Post();
			   //	VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
			   //	VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);

		FormaSpiskaSprNom=0;
//		cxGrid1->SetFocus();
//		cxGrid1DBTableView1KOL_REM_DREMONTT->Selected=true;

}
//----------------------------------------------------------------------------
//выбор единицы
void TREM_FormaCustQuery::ViborEd(void)
{
if(Prosmotr==true) return;
//if (FormaSpiskaSprEd==NULL)
//		{
//		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
//													(void**)&FormaSpiskaSprEd);
//		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
//		if (!FormaSpiskaSprEd) return;
//		FormaSpiskaSprEd->Vibor=true;
//		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DREMONTT->AsString);
//		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DREMONTT->AsString));
////		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
////		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Ремонт №"
////		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
//		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
//		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EndViborEd(void)
{

//
//	DM->DocT->Edit();
//	DM->DocTIDED_REM_DREMONTT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
//	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
//	DM->DocTKF_REM_DREMONTT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;
//
//
//					IDMSprPrice * DMSprPrice;
//					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
//													(void**)&DMSprPrice);
//					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
//
//					DM->DocTPRICE_REM_DREMONTT->AsFloat=
//							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DREMONT->AsString), //тип цен
//											glStrToInt64(DM->DocTIDNOM_REM_DREMONTT->AsString),            //номенклатура
//											glStrToInt64(DM->DocTIDED_REM_DREMONTT->AsString),             //единица
//											DM->DocTKF_REM_DREMONTT->AsFloat,                              //коэффициент
//											0);            //базовая единица
//					DMSprPrice->kanRelease();
//
//
//	DM->DocT->Post();
//
//	FormaSpiskaSprEd=0;
//	cxGrid1->SetFocus();
//	cxGrid1DBTableView1PRICE_REM_DREMONTT->Selected=true;
}

//----------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNom();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaCustQuery::NameZcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::ToolButtonShowHistoriClick(TObject *Sender)
{
		IREM_FormaCustQueryDv * REM_FormaCustQueryDv;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQueryDv,IID_IREM_FormaCustQueryDv,
								 (void**)&REM_FormaCustQueryDv);
		REM_FormaCustQueryDv->Init(InterfaceMainObject,InterfaceImpl);
		//REM_FormaCustQueryDv->Vibor=false;
		REM_FormaCustQueryDv->IdCQT=glStrToInt64(DM->DocTID_REM_CQUERYT->AsString);
		REM_FormaCustQueryDv->TextMessage="Запрос № "
		+DM->DocNUM_REM_CQUERY->AsString+" от "+DM->DocPOS_REM_CQUERY->AsString+
		" "+DM->DocTNAMENOM_REM_CQUERYT->AsString+
		" "+DM->DocTNAMENOM->AsString;
		REM_FormaCustQueryDv->UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TREM_FormaCustQuery::ViborProducer(void)
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
void TREM_FormaCustQuery::EndViborProducer(void)
{

	DM->Doc->Edit();
	DM->DocIDPRODUCER_REM_CQUERY->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->DocNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;

	DM->Doc->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
		//Бренд
void TREM_FormaCustQuery::ViborBrand(void)
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
void TREM_FormaCustQuery::EndViborBrand(void)
{

	DM->Doc->Edit();
	DM->DocIDBRAND_REM_CQUERY->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->DocNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->Doc->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocIDPRODUCER_REM_CQUERY->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborBrand();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDBRAND_REM_CQUERY->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
//выбор номенклатуры
void TREM_FormaCustQuery::ViborProducerNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerNom,IID_IFormaSpiskaSprProducerNom,
													(void**)&FormaSpiskaSprProducerNom);
		FormaSpiskaSprProducerNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNom) return;
		FormaSpiskaSprProducerNom->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DREMONT->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
//		FormaSpiskaSprProducerNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_CQUERYT->AsString);
		FormaSpiskaSprProducerNom->UpdateForm();
		FormaSpiskaSprProducerNom->NumberProcVibor=ER_ViborProducerNom;
		}
}
//----------------------------------------------------------------------------
void TREM_FormaCustQuery::EndViborProducerNom(void)
{

                DM->DocT->Edit();
				DM->DocTIDPRNOM_REM_CQUERYT->AsString=FormaSpiskaSprProducerNom->DM->ElementID_SPRNOM->AsString;
				DM->DocTNAME_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementNAME_SPRNOM->AsString;

				DM->DocTART_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementART_SPRNOM->AsString;
				DM->DocTCODE_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementCODE_SPRNOM->AsString;
				DM->DocT->Post();


		FormaSpiskaSprProducerNom=0;


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::cxGrid1DBBandedTableView1NAME_REM_SPRNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerNom();
}
//---------------------------------------------------------------------------
//выбор оборудования
void TREM_FormaCustQuery::ViborHardware(void)
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
void __fastcall TREM_FormaCustQuery::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));

	DM->Doc->Edit();
	DM->DocIDHW_REM_CQUERY->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocSERNUM_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	DM->DocSERNUM2_REM_SHARDWARE->AsString=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;

	DM->DocIDMODEL_REM_CQUERY->AsString=spr_hw->ElementIDMODEL_REM_SHARDWARE->AsString;
	DM->DocNAME_REM_SMODEL->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;
	DM->DocNAME_MODEL_REM_CQUERY->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;

	DM->DocTYPE_REM_CQUERY->AsInteger=2;

	DM->Doc->Post();

spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::NameSprHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborHardware();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDHW_REM_CQUERY->Clear();
		DM->DocTYPE_REM_CQUERY->AsInteger=0;
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EventEndEditProducerModel(void)
{
if (REM_FormaSpiskaSprProducerModel==0) return;


				DM->Doc->Edit();
				DM->DocIDPRMODEL_REM_CQUERY->AsString=REM_FormaSpiskaSprProducerModel->DM->ElementID_REM_SPRMODEL->AsString;
				DM->DocNAME_REM_SPRMODEL->AsString=REM_FormaSpiskaSprProducerModel->DM->ElementNAME_REM_SPRMODEL->AsString;
				DM->Doc->Post();

		REM_FormaSpiskaSprProducerModel=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaCustQuery::NameProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->Doc->Edit();
		DM->DocIDPRMODEL_REM_CQUERY->Clear();
		DM->DocNAME_REM_SPRMODEL->AsString="";
		DM->DocCODE_REM_SPRMODEL->AsString="";
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::ViborProducerModel(void)
{
if (Prosmotr==true) return;
if (REM_FormaSpiskaSprProducerModel==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
													(void**)&REM_FormaSpiskaSprProducerModel);
		REM_FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprProducerModel) return;
		REM_FormaSpiskaSprProducerModel->flVibor=true;
		REM_FormaSpiskaSprProducerModel->NumberProcVibor=ER_ProducerModel;
		REM_FormaSpiskaSprProducerModel->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::EndViborProdavec(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->Doc->Edit();
				DM->DocIDPRODAVEC_REM_CQUERY->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocPRODAVEC_NAME->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;


				DM->Doc->Post();

		FormaSpiskaSprKlient=0;
 FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void TREM_FormaCustQuery::ViborProdavec(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_ViborProdavec;
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaCustQuery::cxDBButtonEditPRODAVEC_NAMEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProdavec();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDPRODAVEC_REM_CQUERY->Clear();
		DM->DocPRODAVEC_NAME->AsString="";
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

