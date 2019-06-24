//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "UFormaSpiskaInterfToolBar.h"
#include "IDMQueryUpdate.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxTreeView"
#pragma link "cxButtonEdit"
#pragma link "cxClasses"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLabel"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaInterfToolBar::TFormaSpiskaInterfToolBar(TComponent* Owner)
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
bool TFormaSpiskaInterfToolBar::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfToolBar.1",IID_IDMInterfToolBar, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpUser.1",IID_IDMSprGrpUser, (void**)&DMGrpUser);
DMGrpUser->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

DMGrpUser->OpenTable();
NameGrpUsercxLookupComboBox->Properties->ListSource=DMGrpUser->DataSourceTable;


IdGrpUser=0;
NumApplication=0;
Vibor=false;
TypeEvent=0;

HintLabel->Caption="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaInterfToolBarImpl),false);
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
int TFormaSpiskaInterfToolBar::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;
DM->OpenTable(NumApplication, IdGrpUser);
TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_INTERF_TOOLBAR",IdElement,Opt);
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfToolBar::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(SpisokProgramModule) SpisokProgramModule->kanRelease();

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
DMGrpUser->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::DeleteElement()
{
//
}

//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::ToolButtonNewClick(TObject *Sender)
{
DM->Table_AppendString(NumApplication, IdGrpUser);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfToolBar::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table_Delete();
}
//---------------------------------------------------------------------------


//реакция на выбор группы
void __fastcall TFormaSpiskaInterfToolBar::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {

        }
else
        {
        //OpenFormElement();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
        if (Vibor==true)
				{
				TypeEvent=1;
				Close();
				}
		else
				{
				//OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("InterfToolBar");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaInterfToolBar::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::RunExternalModule(__int64 id_module, int type_module)
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
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

if (type_module==1 || type_module==2 || type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_INTERF_TOOLBAR->AsString));
	module->SetInt64Variables("glNumModule", NumApplication);
	module->SetInt64Variables("glIdGrpUser", IdGrpUser);
	}

module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
	}
//delete module;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaSpiskaInterfToolBar::ToolButton5Click(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaInterfToolBar::NameModulcxImageComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
NumApplication=NameModulcxImageComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
IdGrpUser=NameGrpUsercxLookupComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::ActionOKExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	Close();
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfToolBar::ActionSaveExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	DM->OpenTable(NumApplication, IdGrpUser);;
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}

}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::CreateFullStandartToolBar(int application, __int64 id_grp_user)
{
switch (application)
        {
		case 1 :       //Основной модуль
				{
				if (ClearToolBar(application,id_grp_user)==true)
					{
					CreateFullStandartToolBar_PAdmin(id_grp_user);
					}
				} break;

		case 2 :       //Ремонт
				{

				} break;
		case 3 :       //Ремонт
				{
				if (ClearToolBar(application,id_grp_user)==true)
					{
					CreateFullStandartToolBar_ARMKas(id_grp_user);
					}
				} break;

		default :
				{
				 ShowMessage("Неизвестное приложение!");
				} break;
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::CreateFullStandartToolBar_PAdmin(__int64 id_grp_user)
{

InsertItemToolBar(1,id_grp_user,"Номенклатура",	Global_CLSID_TFormaSpiskaSprNomImpl,
										"Справочник Номенклатура",
										0,
										1);
InsertItemToolBar(1,id_grp_user,"Контрагенты",	Global_CLSID_TFormaSpiskaSprKlientImpl,
										"Справочник Контрагенты",
										1,
										2);
InsertItemToolBar(1,id_grp_user,"Быстрый вызов",	Global_CLSID_TFormaSpiskaSprBVNomImpl,
										"Справочник Быстрый вызов",
										2,
										3);
InsertItemToolBar(1,id_grp_user,"Весовая номенклатура",	Global_CLSID_TFormaSpiskaSprVesNomImpl,
										"Справочник Весовая номенклатура",
										3,
										4);
InsertItemToolBar(1,id_grp_user,"Карты",	Global_CLSID_TFormaSpiskaSprDiscountCard1Impl,
										"Справочник Карты",
										4,
										5);
InsertItemToolBar(1,id_grp_user,"|",	0,
										"",
										-1,
										6);

InsertItemToolBar(1,id_grp_user,"Док. Прих накл.",Global_CLSID_TFormaDocPrihNaklImpl,
										"Документ Приходная накладная",
										5,
										7);

InsertItemToolBar(1,id_grp_user,"Док. Счет",Global_CLSID_TFormaDocSchetImpl,
										"Документ Счет",
										6,
										8);
InsertItemToolBar(1,id_grp_user,"Док. Реализация",Global_CLSID_TFormaDocRealImpl,
										"Документ Реализация",
										7,
										9);

InsertItemToolBar(1,id_grp_user,"Док. ПКО",	Global_CLSID_TFormaDocPKOImpl,
										"Документ Приходный кассовый ордер",
										8,
										10);

InsertItemToolBar(1,id_grp_user,"|",0,
										"",
										-1,
										11);

InsertItemToolBar(1,id_grp_user,"Полный журнал",Global_CLSID_TFormaGurAllDocImpl,
										"Полный журнал",
										9,
										12);

InsertItemToolBar(1,id_grp_user,"|",	0,
										"",
										-1,
										13);
InsertItemToolBar(1,id_grp_user,"Отчет Остатки товаров",Global_CLSID_TFormaReportOCBRegGoodsImpl,
										"Отчет Остатки товаров",
										10,
										14);

InsertItemToolBar(1,id_grp_user,"Отчет Остатки партий товаров",	Global_CLSID_TFormaReportOCBRegOstNomImpl,
										"Отчет Остатки партий товаров",
										10,
										15);

InsertItemToolBar(1,id_grp_user,"Отчет Карточка клиента",Global_CLSID_TFormaReportKartKlientImpl,
										"Отчет Карточка клиента",
										10,
										16);

InsertItemToolBar(1,id_grp_user,"Отчет Касса",	Global_CLSID_TFormaReportKassaImpl,
										"Отчет Касса",
										10,
										17);

InsertItemToolBar(1,id_grp_user,"Отчет Банк",Global_CLSID_TFormaReportBankImpl,
										"Отчет Банк",
										10,
										18);


}

//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::InsertItemToolBar(int application, __int64 id_grp_user,
									UnicodeString name_tool_bar,
									UnicodeString str_guid,
									UnicodeString hint,
									int image_index,
									int index_sort)
{
IDMInterfToolBar * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfToolBar.1",IID_IDMInterfToolBar, (void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);
if (dm->NewElement(application,id_grp_user)==false)
	{
	ShowMessage("Ошибка при вставке пункта кнопки панели "+name_tool_bar+" "+dm->TextError);
	}

dm->Element_Edit();
dm->ElementNAME_INTERF_TOOLBAR->AsString=name_tool_bar;
dm->ElementAPPLICATION_INTERF_TOOLBAR->AsInteger=application;
dm->ElementIDGRPUSER_INTERF_TOOLBAR->AsString=id_grp_user;
dm->ElementGUIDMOD_INTERF_TOOLBAR->AsString=str_guid;
dm->ElementHINT_INTERF_TOOLBAR->AsString=hint;
dm->ElementIMAGEINDEX_INTERF_TOOLBAR->AsInteger=image_index;
dm->ElementINDEX_INTERF_TOOLBAR->AsInteger=index_sort;
dm->Element_Post();

if (dm->SaveElement()==false)
	{
	ShowMessage("Ошибка при записи пункта кнопки панели " + dm->TextError);
	}
dm->kanRelease();

}
//----------------------------------------------------------------------------
bool TFormaSpiskaInterfToolBar::ClearToolBar(int application, __int64 id_grp_user)
{
bool result=true;
IDMInterfToolBar * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfToolBar.1",IID_IDMInterfToolBar, (void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);
dm->OpenTable(application,id_grp_user);
dm->Table->First();

while(!dm->Table->Eof)
	{
	dm->Table_Delete();
	}

try
	{
	dm->SaveIsmen();
	}
catch(Exception &exception)
	{
	result=false;
	ShowMessage("Ошибка при очистке панели " + exception.Message);
	}

dm->kanRelease();

return result;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfToolBar::ActionCreateFullStandartMainMenuExecute(TObject *Sender)

{
int appl=NameModulcxImageComboBox->EditValue;
__int64 id_grp_user=NameGrpUsercxLookupComboBox->EditValue;
CreateFullStandartToolBar(appl,id_grp_user);
UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::CreateFullStandartToolBar_ARMKas(__int64 id_grp_user)
{
//__int64 id_grp=InsertGrpMainMenu(3,id_grp_user,0,"АРМ");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"АРМ №1",	GC_FormaARMKas1);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"АРМ №2",	GC_FormaARMKas2);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Платежи",	GC_FormaPriemPlat);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Справочники");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Номенклатура",	GC_FormaViborSprNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Быстрый вызов",GC_FormaViborSprBVNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Контрагенты",	GC_FormaSpiskaSprKlient);
//
//	}
//
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Документы");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Реализация розн.",	GC_FormaDocRealRoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Приход нал.",	GC_FormaDocPKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Расход нал.",	GC_FormaDocRKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Возврат от покупателя",GC_FormaVosvratPokForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Журналы");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Журнал платежей",GC_FormaGurPlat);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Журнал чеков",GC_FormaGurCheckForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Розничные документы",GC_FormaGurRoznDocForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Отчеты");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Продажи", GC_FormaReportSaleForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Отчет по скидкам",	GC_FormaReportDiscountForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Внешние модули", GC_FormaSpiskaExtModule);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Сервис");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Печать ценников", GC_FormaPrintPriceForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Табличный редактор",	GC_SheetEditor);
//	}
}
//----------------------------------------------------------------------------
int TFormaSpiskaInterfToolBar::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ER_ProgramModule)
		{
		if (type_event==1)
				{
				EndViborProgramModule();
				}
		SpisokProgramModule=0;
		}

return -1;
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::ViborProgramModule(void)
{
if (SpisokProgramModule==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProgramModule,IID_IFormaSpiskaSprProgramModule,
													(void**)&SpisokProgramModule);
		SpisokProgramModule->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProgramModule->Vibor=true;
		SpisokProgramModule->NumberProcVibor=ER_ProgramModule;
		}

}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::EndViborProgramModule(void)
{

	DM->Table->Edit();
	DM->TableGUIDMOD_INTERF_TOOLBAR->AsString=SpisokProgramModule->DM->TableGUID_PROGRAM_MODULE->AsString;
	DM->TableNAME_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TableNAME_PROGRAM_MODULE->AsString;
	DM->TableIDMOD_INTERF_TOOLBAR->AsString=SpisokProgramModule->DM->TableID_PROGRAM_MODULE->AsString;
	//DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger=SpisokProgramModule->DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger;
	DM->TablePATCH_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TablePATCH_PROGRAM_MODULE->AsString;
	DM->Table->Post();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfToolBar::cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProgramModule();
}
//---------------------------------------------------------------------------

