//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaDocOtmenaBron.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMSprKlient.h"
#include "IHOT_DMTableSostNF.h"
#include "IFormaRunExternalModule.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaDocOtmenaBron::THOT_FormaDocOtmenaBron(TComponent* Owner)
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
bool THOT_FormaDocOtmenaBron::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocOtmenaBron.1",IID_IHOT_DMDocOtmenaBron, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THOT_FormaDocOtmenaBronImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		DMTableExtPrintForm->Table->Next();
		}


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------
int THOT_FormaDocOtmenaBron::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THOT_FormaDocOtmenaBron::UpdateForm(void)
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
void __fastcall THOT_FormaDocOtmenaBron::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(HOT_FormaSpiskaTableSostNF)  HOT_FormaSpiskaTableSostNF->kanRelease();

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
DMTableExtPrintForm->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Doc/DocOtmenaBron");
}
//---------------------------------------------------------------------------
int THOT_FormaDocOtmenaBron::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Firm)
	{

	if (type_event==1)
		{
		EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_InfBase)
	{
	if (type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_Plat)
	{
	if (type_event==1)
		{
		EndViborPlat();
		}
	FormaSpiskaSprKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}


if (number_procedure_end==ER_Guest)
	{
	if (type_event==1)
		{
		EndViborGuest();
		}
	FormaSpiskaSprKlient=0;
	}


if (number_procedure_end==ER_Sost)
	{

	if (type_event==1)
		{
		EndAddSostNF();
		}
    HOT_FormaSpiskaTableSostNF=0;
	}

return -1;
}
//----------------------------------------------------------------------------



//выбор фирмы
void THOT_FormaDocOtmenaBron::ViborFirm(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}    
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::EndViborFirm(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDFIRM_HOT_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();

}
//---------------------------------------------------------------------------
//выбор информационной базы
void THOT_FormaDocOtmenaBron::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_HOT_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::EndViborInfBase(void)
{


                DM->DocAll->Edit();
				DM->DocAllIDBASE_HOT_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();


}
//--------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaDocOtmenaBron::ViborPlat(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Plat;
		FormaSpiskaSprKlient->IdKlient=DM->DocAllIDKL_HOT_GALLDOC->AsInteger;
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::EndViborPlat(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDKL_HOT_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();


}
//---------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocOtmenaBron::ViborGuest(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Guest;
//		FormaSpiskaSprKlient->IdKlient=DM->DocTIDGUEST_HOT_SOSTNF->AsInteger;
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::EndViborGuest(void)
{

cxGrid1->SetFocus();
}

//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocOtmenaBron::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborPlat();	
}
//---------------------------------------------------------------------------
//выбор состояния НФ
void THOT_FormaDocOtmenaBron::AddSostNF(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaTableSostNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpTableSostNF.1",IID_IHOT_FormaSpiskaTableSostNF,
													(void**)&HOT_FormaSpiskaTableSostNF);
		HOT_FormaSpiskaTableSostNF->Init(InterfaceMainObject,InterfaceImpl);
		HOT_FormaSpiskaTableSostNF->Vibor=true;
		HOT_FormaSpiskaTableSostNF->DM->IdPlat=glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString);
		HOT_FormaSpiskaTableSostNF->NumberProcVibor=ER_Sost;
		HOT_FormaSpiskaTableSostNF->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::EndAddSostNF(void)
{

	DM->AddString();
	DM->DocT->Edit();
	DM->DocTIDSOST_HOT_DOTMBRONT->AsString=HOT_FormaSpiskaTableSostNF->DM->TableID_HOT_SOSTNF->AsString;

	DM->DocTNAME_HOT_SNF->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_SNF->AsString;
	DM->DocTNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_STYPEPOS->AsString;
	DM->DocTNAMEKLIENT->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAMEGUEST->AsString;
	DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime=HOT_FormaSpiskaTableSostNF->DM->TablePOSNACH_HOT_SOSTNF->AsDateTime;
	DM->DocTPOSCON_HOT_SOSTNF->AsDateTime=HOT_FormaSpiskaTableSostNF->DM->TablePOSCON_HOT_SOSTNF->AsDateTime;
	DM->DocTKOLM_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaTableSostNF->DM->TableKOLM_HOT_SOSTNF->AsInteger;

	//категория номера
	IHOT_DMTableSostNF * dm_table_sost;
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMTableSostNF.1",IID_IHOT_DMTableSostNF,
													(void**)&dm_table_sost);
	dm_table_sost->Init(InterfaceMainObject,InterfaceImpl);
	dm_table_sost->OpenElement(glStrToInt64(HOT_FormaSpiskaTableSostNF->DM->TableID_HOT_SOSTNF->AsString));
	DM->DocTNAME_HOT_SCATNOM->AsString=dm_table_sost->ElementNAME_HOT_SCATNOM->AsString;
	dm_table_sost->kanRelease();

	DM->DocT->Post();

cxGrid1->SetFocus();

}
//---------------------------------------------------------------------------




void __fastcall THOT_FormaDocOtmenaBron::ActionAddStringExecute(TObject *Sender)
{
AddSostNF();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::ActionDeleteStringExecute(
      TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteString();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::NumbercxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::PosDoccxDBDateEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::DescrcxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THOT_FormaDocOtmenaBron::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THOT_FormaDocOtmenaBron::RunExternalModule(__int64 id_module, int type_module)
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

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
    module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_HOT_GALLDOC->AsString));
	}
	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocOtmenaBron::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocOtmenaBron::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true) return;
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

void __fastcall THOT_FormaDocOtmenaBron::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
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

void __fastcall THOT_FormaDocOtmenaBron::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

