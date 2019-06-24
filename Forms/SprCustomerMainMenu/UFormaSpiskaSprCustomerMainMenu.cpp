//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-----------------------------------------------------------------------------
#include "UFormaSpiskaSprCustomerMainMenu.h"
#include "UGlobalConstant.h"
#include "IDMQueryUpdate.h"
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
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprCustomerMainMenu::TFormaSpiskaSprCustomerMainMenu(TComponent* Owner)
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
void __fastcall TFormaSpiskaSprCustomerMainMenu::FormCreate(TObject *Sender)
{

//
}
//-----------------------------------------------------------------------
bool TFormaSpiskaSprCustomerMainMenu::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerMainMenu,IID_IDMSprCustomerMainMenu, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerMainMenuGrp,IID_IDMSprCustomerMainMenuGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerUserGrp,IID_IDMSprCustomerUserGrp, (void**)&DMGrpUser);
DMGrpUser->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

//DMGrpUser->OpenTable(IdAccount);
NameGrpUsercxLookupComboBox->Properties->ListSource=DMGrpUser->DataSourceTable;


IdGrpUser=0;
IdAccount=0;
AllElement=false;
Vibor=false;


LabelNameGrp->Caption="Главное меню\\...";
HintLabel->Caption="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaInterfMainMenuImpl),false);
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
int TFormaSpiskaSprCustomerMainMenu::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;
DM->OpenTable(IdAccount, IdGrpUser, IdGrp, AllElement);
TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_CUST_MAINMENU",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::FormClose(TObject *Sender,
	  TCloseAction &Action)
{

if(SpisokProgramModule) SpisokProgramModule->kanRelease();
if(SpisokAccount) SpisokAccount->kanRelease();
//if(SpisokParameter) SpisokParameter->kanRelease();

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
DMGrp->kanRelease();
DMGrpUser->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::UpdateDerevo()
{
//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(IdAccount, IdGrpUser);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Главное меню",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_CUST_MAINMENU_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_CUST_MAINMENU_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_CUST_MAINMENU_GRP->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);

for (int i=0;i<cxTreeView1->Items->Count;i++)
		{
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
				if (IdGrp==IDData)
						{
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
						break;
						}
		}
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::DeleteElement()
{
//
}
//-------------------------------------------------------------------
// редактирование групп
void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonNewScaleClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonEdiScaleClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonDeleteScaleClick(
      TObject *Sender)
{
DeleteGrpElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::OpenFormGrpElement()
{

if (FormaGrpElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprCustomerMainMenuGrp,IID_IFormaElementaSprCustomerMainMenuGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				//FormaGrpElementa->Vibor=true;
				//FormaGrpElementa->NumberProcVibor=ER_Grp;
                }
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::OpenFormNewGrpElement()
{
if (FormaGrpElementa==0)
		{
		if(IdGrpUser!=0 && IdAccount!=0)
			{
				InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprCustomerMainMenuGrp,IID_IFormaElementaSprCustomerMainMenuGrp,
													(void**)&FormaGrpElementa);
			FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
			if (!FormaGrpElementa) return;

			if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdAccount,IdGrpUser,IdGrp);
                }
			else
                {
				FormaGrpElementa->DM->NewElement(IdAccount,IdGrpUser,0);
                }
			}
		else
			{
             ShowMessage("Заданы не все параметры!");
			}
		}
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
				}

}
//----------------------------------------------------------------------------
int TFormaSpiskaSprCustomerMainMenu::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ER_Grp)
		{
		if (type_event==1)
				{
				UpdateDerevo();
				}
		FormaGrpElementa=0;
		}

if (number_procedure_end==ER_ProgramModule)
		{
		if (type_event==1)
				{
				EndViborProgramModule();
				}
		SpisokProgramModule=0;
		}

if (number_procedure_end==ER_SpisokParameter)
		{
		if (type_event==1)
				{
				//EndViborSpisokParameter();
				}
		//SpisokParameter=0;
		}

if (number_procedure_end==ER_Account)
		{
		if (type_event==1)
				{
				EndViborAccount();
				}
		SpisokAccount=0;
		}

return -1;
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonNewClick(TObject *Sender)
{
//OpenFormNewElement();
DM->Table_AppendString(IdAccount, IdGrpUser, IdGrp);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table_Delete();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
		}

IdGrp=glStrToInt64(DM->TableIDGRP_CUST_MAINMENU->AsString);

DM->OpenTable(IdAccount, IdGrpUser, IdGrp, AllElement);
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------











//реакция на выбор группы
void __fastcall TFormaSpiskaSprCustomerMainMenu::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdAccount, IdGrpUser, IdGrp, AllElement);
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::cxTreeView1KeyPress(TObject *Sender,
	  char &Key)
{
if (Key==VK_RETURN)
		{
		if (cxTreeView1->Selected!=NULL)
			{
			if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
			IdGrp=*(__int64*)cxTreeView1->Selected->Data;
			DM->OpenTable(IdAccount, IdGrpUser, IdGrp, AllElement);;
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerMainMenu::cxGrid1DBTableView1DblClick(
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

void __fastcall TFormaSpiskaSprCustomerMainMenu::cxGrid1DBTableView1KeyPress(
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







//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaSprCustomerMainMenu::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_CUST_MAINMENU->AsString));
	module->SetInt64Variables("glIdAccount", IdAccount);
	module->SetInt64Variables("glIdGrp", IdGrp);
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


void __fastcall TFormaSpiskaSprCustomerMainMenu::ToolButton5Click(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprCustomerMainMenu::NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
IdGrpUser=NameGrpUsercxLookupComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerMainMenu::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerMainMenu::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaSpiskaSprCustomerMainMenu::ActionSaveExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	DM->OpenTable(IdAccount, IdGrpUser, IdGrp, AllElement);;
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}

}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerMainMenu::cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProgramModule();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::ViborProgramModule(void)
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
void TFormaSpiskaSprCustomerMainMenu::EndViborProgramModule(void)
{

	DM->Table->Edit();
	DM->TableGUIDMOD_CUST_MAINMENU->AsString=SpisokProgramModule->DM->TableGUID_PROGRAM_MODULE->AsString;
	DM->TableNAME_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TableNAME_PROGRAM_MODULE->AsString;
	DM->TableIDMOD_CUST_MAINMENU->AsString=SpisokProgramModule->DM->TableID_PROGRAM_MODULE->AsString;
	DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger=SpisokProgramModule->DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger;
	DM->TablePATCH_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TablePATCH_PROGRAM_MODULE->AsString;
	DM->Table->Post();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::ViborAccount(void)
{

if (SpisokAccount==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprCustomerAccount,IID_IFormaSpiskaSprCustomerAccount,
													(void**)&SpisokAccount);
		SpisokAccount->Init(InterfaceMainObject,InterfaceImpl);
		SpisokAccount->Vibor=true;
		SpisokAccount->NumberProcVibor=ER_Account;
		}

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprCustomerMainMenu::EndViborAccount(void)
{


	IdAccount=glStrToInt64(SpisokAccount->DM->TableID_CUST_ACCOUNT->AsString);
	NameAccountcxButtonEdit->Text=SpisokAccount->DM->TableNAME_CUST_ACCOUNT->AsString;

   	DMGrpUser->OpenTable(IdAccount);
	//NameGrpUsercxLookupComboBox->Properties->ListSource=DMGrpUser->DataSourceTable;

}

//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerMainMenu::NameAccountcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborAccount();
}
//---------------------------------------------------------------------------

