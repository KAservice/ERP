//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UREM_FormaZayavkaPredv.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMQueryRead.h"
#include "IAsyncExternalEvent.h"
#include "IREM_FormaZayavka.h"
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
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaZayavkaPredv::TREM_FormaZayavkaPredv(TComponent* Owner)
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
bool TREM_FormaZayavkaPredv::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavkaPredv,IID_IREM_DMZayavkaPredv, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdZ=0;           //идентификатор текущей записи



IDcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KlientNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KlientPhonecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
EmailcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
KlientAdtrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceGurZ;
ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBCalcEditSUMNACHA_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBCalcEditSUMKLIENTA_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBSpinEditSROK_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
SostcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBMemoDOPOPISANIE_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
NeisprcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBMemoPRICHINA_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBImageComboBoxPRICHINA_LIST_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
cxDBImageComboBoxRESULT_REM_Z2->DataBinding->DataSource=DM->DataSourceGurZ;
NameHardwarecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
SerNum2cxDBLabel->DataBinding->DataSource=DM->DataSourceGurZ;
NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameDialercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameSkladPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameproducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
ProducerModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
SellercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceGurZ;
CommentscxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;
DescrcxDBMemo->DataBinding->DataSource=DM->DataSourceGurZ;




ActionOperation=aoNO;
DBTextNameUser->DataSource=DM->DataSourceGurZ;
//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaZayavkaPredvImpl),false);
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
int TREM_FormaZayavkaPredv::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaZayavkaPredv::UpdateForm(void)
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
void __fastcall TREM_FormaZayavkaPredv::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprSklad) FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(REM_FormaSpiskaSprModel) REM_FormaSpiskaSprModel->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();

if(SpisokBrand)SpisokBrand->kanRelease();

if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(SpisokBrand)SpisokBrand->kanRelease();

if(FormaSpiskaSprSeller)FormaSpiskaSprSeller->kanRelease();
if(REM_FormaSpiskaSprActCategory)REM_FormaSpiskaSprActCategory->kanRelease();


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
int TREM_FormaZayavkaPredv::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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



return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::EventEndEditInfBase(void)
{
if(FormaSpiskaSprInfBase==0) return;


				DM->GurZ->Edit();
				DM->GurZIDBASE_REM_Z2->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
				DM->GurZNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;

				DM->GurZNAME_REM_Z2->AsString="Заявка №"+DM->GurZNUM_REM_Z2->AsString+
				" от "+DM->GurZPOS_REM_Z2->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprInfBase=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::EventEndEditFirm(void)
{
if (FormaSpiskaSprFirm==0)  return;


				DM->GurZ->Edit();
				DM->GurZIDFIRM_REM_Z2->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->GurZNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;

				DM->GurZNAME_REM_Z2->AsString="Заявка №"+DM->GurZNUM_REM_Z2->AsString+
				" от "+DM->GurZPOS_REM_Z2->AsString;

				DM->GurZ->Post();





		FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::EventEndEditSkladPr(void)
{
if (FormaSpiskaSprSklad==0)  return;


				DM->GurZ->Edit();
				DM->GurZIDSKLPR_REM_Z2->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
				DM->GurZNAME_SKLAD_PR->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;

				DM->GurZNAME_REM_Z2->AsString="Заявка №"+DM->GurZNUM_REM_Z2->AsString+
				" от "+DM->GurZPOS_REM_Z2->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::EventEndEditKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->GurZ->Edit();
				DM->GurZIDKLIENT_REM_Z2->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->GurZNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZKLIENT_NAME_REM_Z2->AsString=DM->GurZKLIENT_NAME_REM_Z2->AsString+
										FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZKLIENT_ADR_REM_Z2->AsString=DM->GurZKLIENT_ADR_REM_Z2->AsString+
										FormaSpiskaSprKlient->DM->ElementADRKLIENT->AsString;
				DM->GurZKLIENT_PHONE_REM_Z2->AsString=DM->GurZKLIENT_PHONE_REM_Z2->AsString+
										FormaSpiskaSprKlient->DM->ElementTELKLIENT->AsString;

				DM->GurZ->Post();

		FormaSpiskaSprKlient=0;
 FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::EventEndEditDiler(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->GurZ->Edit();
				DM->GurZIDDILER_REM_Z2->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->GurZNAMEDILER->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->GurZ->Post();

		FormaSpiskaSprKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::EventEndEditModel(void)
{
if (REM_FormaSpiskaSprModel==0) return;


				DM->GurZ->Edit();
				DM->GurZIDMODEL_REM_Z2->AsString=REM_FormaSpiskaSprModel->DM->ElementID_REM_SMODEL->AsString;
				DM->GurZNAME_REM_SMODEL->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->GurZMODEL_STR_REM_Z2->AsString=REM_FormaSpiskaSprModel->DM->ElementNAME_REM_SMODEL->AsString;
				DM->GurZ->Post();

		REM_FormaSpiskaSprModel=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaZayavkaPredv::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Doc/DocReal");
}
//---------------------------------------------------------------------------













void __fastcall TREM_FormaZayavkaPredv::NameInfBasecxDBButtonEditPropertiesButtonClick(
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


void __fastcall TREM_FormaZayavkaPredv::cxDBButtonEdit1PropertiesButtonClick(
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

void __fastcall TREM_FormaZayavkaPredv::NameSkladPrcxDBButtonEditPropertiesButtonClick(
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

void __fastcall TREM_FormaZayavkaPredv::NameDialercxDBButtonEditPropertiesButtonClick(
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

void __fastcall TREM_FormaZayavkaPredv::NameKlientcxDBButtonEditPropertiesButtonClick(
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


void __fastcall TREM_FormaZayavkaPredv::NameModelcxDBButtonEditPropertiesButtonClick(
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






void __fastcall TREM_FormaZayavkaPredv::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaZayavkaPredv::ActionSaveExecute(TObject *Sender)
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
void __fastcall TREM_FormaZayavkaPredv::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaZayavkaPredv::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdZayvka", glStrToInt64(DM->GurZID_REM_Z2->AsString));


module->ExecuteModule();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::NumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->GurZ->Edit();
	DM->GurZNAME_REM_Z2->AsString="Заявка №"+DM->GurZNUM_REM_Z2->AsString+
				" от "+DM->GurZPOS_REM_Z2->AsString;
	DM->GurZ->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::PoscxDBDateEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	DM->GurZ->Edit();
	DM->GurZNAME_REM_Z2->AsString="Заявка №"+DM->GurZNUM_REM_Z2->AsString+
				" от "+DM->GurZPOS_REM_Z2->AsString;
	DM->GurZ->Post();
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaZayavkaPredv::KlientNamecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{

	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::KlientAdtrcxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::KlientPhonecxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::ModelcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::SerNumcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::SerNum2cxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::NamecxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaZayavkaPredv::DescrcxDBTextEditKeyPress(TObject *Sender, wchar_t &Key)

{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaZayavkaPredv::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaZayavkaPredv::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaZayavkaPredv::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM1_REM_Z2->AsString=sh;
	DM->GurZ->Post();
	}
else if (SerNum2cxDBTextEdit->Focused()==true)
	{
	DM->GurZ->Edit();
	DM->GurZSERNUM2_REM_Z2->AsString=sh;
	DM->GurZ->Post();
	}


}
//----------------------------------------------------------------------------


//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------






//выбор заявки
void TREM_FormaZayavkaPredv::ViborHardware(void)
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
void __fastcall TREM_FormaZayavkaPredv::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));

	DM->GurZ->Edit();
	DM->GurZIDHW_REM_Z2->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->GurZNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->GurZSERNUM_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	DM->GurZSERNUM2_REM_SHARDWARE->AsString=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;

	DM->GurZSERNUM1_REM_Z2->AsString=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
	DM->GurZSERNUM2_REM_Z2->AsString=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
	DM->GurZIDMODEL_REM_Z2->AsString=spr_hw->ElementIDMODEL_REM_SHARDWARE->AsString;
	DM->GurZNAME_REM_SMODEL->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;
	DM->GurZMODEL_STR_REM_Z2->AsString=spr_hw->ElementNAME_REM_SMODEL->AsString;
	DM->GurZ->Post();

spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::NameHardwarecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
		//Бренд
void TREM_FormaZayavkaPredv::ViborBrand(void)
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
void __fastcall TREM_FormaZayavkaPredv::EndViborBrand(void)
{

	DM->GurZ->Edit();
	DM->GurZIDBRAND_REM_Z2->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->GurZNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->GurZ->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborBrand();
}
//---------------------------------------------------------------------------


void TREM_FormaZayavkaPredv::ViborProducer(void)
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
void TREM_FormaZayavkaPredv::EventEndEditProdcer(void)
{

//	DM->GurZ->Edit();
//	DM->GurZIDPRODUCER_REM_Z2->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
//	DM->GurZNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
//	DM->GurZ->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------








void __fastcall TREM_FormaZayavkaPredv::NameproducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
//		DM->GurZ->Edit();
//		DM->GurZIDPRODUCER_REM_Z2->Clear();
//		DM->GurZ->Post();
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaZayavkaPredv::SellercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->GurZ->Edit();
		DM->GurZIDSELLER_REM_Z2->Clear();
		DM->GurZ->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaZayavkaPredv::ViborSeller(void)
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
void TREM_FormaZayavkaPredv::EndViborSeller(void)
{

//	DM->GurZ->Edit();
//	DM->GurZIDSELLER_REM_Z2->AsString=FormaSpiskaSprSeller->DM->TableID_SSELLER->AsString;
//	DM->GurZNAME_SSELLER->AsString=FormaSpiskaSprSeller->DM->TableNAME_SSELLER->AsString;
//
//
//	DM->GurZ->Post();

FormaSpiskaSprSeller=0;

}
//----------------------------------------------------------------------------
void TREM_FormaZayavkaPredv::ViborActCategory(void)
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
void TREM_FormaZayavkaPredv::EndViborActCategory(void)
{

//	DM->GurZ->Edit();
//	DM->GurZIDACTCAT_REM_Z2->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
//	DM->GurZNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
//	DM->GurZ->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaZayavkaPredv::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
//		DM->GurZ->Edit();
//		DM->GurZIDACTCAT_REM_Z->Clear();
//		DM->GurZ->Post();
		}break;
	}
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaZayavkaPredv::ToolButtonCreateZayavkuClick(TObject *Sender)

{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();

REM_FormaZayavka->DM->GurZ->Edit();

//REM_FormaZayavka->DM->GurZIDTYPEREM_REM_Z->AsString=z->GurZIDTYPEREM_REM_Z->AsString;
//REM_FormaZayavka->DM->GurZNAME_STREMONT->AsString=z->GurZNAME_STREMONT->AsString;
//REM_FormaZayavka->DM->GurZIDSOST_REM_Z->AsString=z->GurZIDSOST_REM_Z->AsString;
//REM_FormaZayavka->DM->GurZNAME_REMSSOST->AsString=z->GurZNAME_REMSSOST->AsString;

REM_FormaZayavka->DM->GurZIDKLIENT_REM_Z->AsString=DM->GurZIDKLIENT_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZNAMEKLIENT->AsString=DM->GurZNAMEKLIENT->AsString;
REM_FormaZayavka->DM->GurZKLIENT_NAME_REM_Z->AsString=DM->GurZKLIENT_NAME_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZKLIENT_ADR_REM_Z->AsString=DM->GurZKLIENT_ADR_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZKLIENT_PHONE_REM_Z->AsString=DM->GurZKLIENT_PHONE_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZIDMODEL_REM_Z->AsString=DM->GurZIDMODEL_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZNAME_REM_SMODEL->AsString=DM->GurZNAME_REM_SMODEL->AsString;
REM_FormaZayavka->DM->GurZMODEL_REM_Z->AsString=DM->GurZMODEL_STR_REM_Z2->AsString;
//REM_FormaZayavka->DM->GurZNUM_GARDOC_REM_Z->AsString=z->GurZNUM_GARDOC_REM_Z->AsString;
REM_FormaZayavka->DM->GurZSERNUM_REM_Z->AsString=DM->GurZSERNUM1_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZSERNUM2_REM_Z->AsString=DM->GurZSERNUM2_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZSOST_REM_Z->AsString=DM->GurZSOST_REM_Z2->AsString;
//REM_FormaZayavka->DM->GurZKOMPLECT_REM_Z->AsString=z->GurZKOMPLECT_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNEISPR_REM_Z->AsString=DM->GurZNEISPR_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZ->Post();

REM_FormaZayavka->UpdateForm();


}
//---------------------------------------------------------------------------

