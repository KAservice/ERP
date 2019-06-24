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
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
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


//�������� ������ ������� �������
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

//����������
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

//������� ICallBack ��� �������� ������� � ���������� �����
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


//������� �� ����� ������
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
//������� ������
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


//��������� ������� ������
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

if (type_module==1 || type_module==2 || type_module==3)
	{  //���� �������� ���������� ������, ��� �������  IDDOC
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
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
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
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}

}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::CreateFullStandartToolBar(int application, __int64 id_grp_user)
{
switch (application)
        {
		case 1 :       //�������� ������
				{
				if (ClearToolBar(application,id_grp_user)==true)
					{
					CreateFullStandartToolBar_PAdmin(id_grp_user);
					}
				} break;

		case 2 :       //������
				{

				} break;
		case 3 :       //������
				{
				if (ClearToolBar(application,id_grp_user)==true)
					{
					CreateFullStandartToolBar_ARMKas(id_grp_user);
					}
				} break;

		default :
				{
				 ShowMessage("����������� ����������!");
				} break;
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfToolBar::CreateFullStandartToolBar_PAdmin(__int64 id_grp_user)
{

InsertItemToolBar(1,id_grp_user,"������������",	Global_CLSID_TFormaSpiskaSprNomImpl,
										"���������� ������������",
										0,
										1);
InsertItemToolBar(1,id_grp_user,"�����������",	Global_CLSID_TFormaSpiskaSprKlientImpl,
										"���������� �����������",
										1,
										2);
InsertItemToolBar(1,id_grp_user,"������� �����",	Global_CLSID_TFormaSpiskaSprBVNomImpl,
										"���������� ������� �����",
										2,
										3);
InsertItemToolBar(1,id_grp_user,"������� ������������",	Global_CLSID_TFormaSpiskaSprVesNomImpl,
										"���������� ������� ������������",
										3,
										4);
InsertItemToolBar(1,id_grp_user,"�����",	Global_CLSID_TFormaSpiskaSprDiscountCard1Impl,
										"���������� �����",
										4,
										5);
InsertItemToolBar(1,id_grp_user,"|",	0,
										"",
										-1,
										6);

InsertItemToolBar(1,id_grp_user,"���. ���� ����.",Global_CLSID_TFormaDocPrihNaklImpl,
										"�������� ��������� ���������",
										5,
										7);

InsertItemToolBar(1,id_grp_user,"���. ����",Global_CLSID_TFormaDocSchetImpl,
										"�������� ����",
										6,
										8);
InsertItemToolBar(1,id_grp_user,"���. ����������",Global_CLSID_TFormaDocRealImpl,
										"�������� ����������",
										7,
										9);

InsertItemToolBar(1,id_grp_user,"���. ���",	Global_CLSID_TFormaDocPKOImpl,
										"�������� ��������� �������� �����",
										8,
										10);

InsertItemToolBar(1,id_grp_user,"|",0,
										"",
										-1,
										11);

InsertItemToolBar(1,id_grp_user,"������ ������",Global_CLSID_TFormaGurAllDocImpl,
										"������ ������",
										9,
										12);

InsertItemToolBar(1,id_grp_user,"|",	0,
										"",
										-1,
										13);
InsertItemToolBar(1,id_grp_user,"����� ������� �������",Global_CLSID_TFormaReportOCBRegGoodsImpl,
										"����� ������� �������",
										10,
										14);

InsertItemToolBar(1,id_grp_user,"����� ������� ������ �������",	Global_CLSID_TFormaReportOCBRegOstNomImpl,
										"����� ������� ������ �������",
										10,
										15);

InsertItemToolBar(1,id_grp_user,"����� �������� �������",Global_CLSID_TFormaReportKartKlientImpl,
										"����� �������� �������",
										10,
										16);

InsertItemToolBar(1,id_grp_user,"����� �����",	Global_CLSID_TFormaReportKassaImpl,
										"����� �����",
										10,
										17);

InsertItemToolBar(1,id_grp_user,"����� ����",Global_CLSID_TFormaReportBankImpl,
										"����� ����",
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
	ShowMessage("������ ��� ������� ������ ������ ������ "+name_tool_bar+" "+dm->TextError);
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
	ShowMessage("������ ��� ������ ������ ������ ������ " + dm->TextError);
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
	ShowMessage("������ ��� ������� ������ " + exception.Message);
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
//__int64 id_grp=InsertGrpMainMenu(3,id_grp_user,0,"���");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"��� �1",	GC_FormaARMKas1);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"��� �2",	GC_FormaARMKas2);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"�������",	GC_FormaPriemPlat);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"�����������");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������������",	GC_FormaViborSprNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������� �����",GC_FormaViborSprBVNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"�����������",	GC_FormaSpiskaSprKlient);
//
//	}
//
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"���������");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"���������� ����.",	GC_FormaDocRealRoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������ ���.",	GC_FormaDocPKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������ ���.",	GC_FormaDocRKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������� �� ����������",GC_FormaVosvratPokForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"�������");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������ ��������",GC_FormaGurPlat);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������ �����",GC_FormaGurCheckForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"��������� ���������",GC_FormaGurRoznDocForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"������");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"�������", GC_FormaReportSaleForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"����� �� �������",	GC_FormaReportDiscountForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������� ������", GC_FormaSpiskaExtModule);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"������");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"������ ��������", GC_FormaPrintPriceForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"��������� ��������",	GC_SheetEditor);
//	}
}
//----------------------------------------------------------------------------
int TFormaSpiskaInterfToolBar::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
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

