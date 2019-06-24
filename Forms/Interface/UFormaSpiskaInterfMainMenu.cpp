//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-----------------------------------------------------------------------------
#include "UFormaSpiskaInterfMainMenu.h"
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
__fastcall TFormaSpiskaInterfMainMenu::TFormaSpiskaInterfMainMenu(TComponent* Owner)
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
void __fastcall TFormaSpiskaInterfMainMenu::FormCreate(TObject *Sender)
{

//
}
//-----------------------------------------------------------------------
bool TFormaSpiskaInterfMainMenu::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenu.1",IID_IDMInterfMainMenu, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenuGrp.1",IID_IDMInterfMainMenuGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpUser.1",IID_IDMSprGrpUser, (void**)&DMGrpUser);
DMGrpUser->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

DMGrpUser->OpenTable();
NameGrpUsercxLookupComboBox->Properties->ListSource=DMGrpUser->DataSourceTable;


IdGrpUser=0;
NumApplication=0;
AllElement=false;
Vibor=false;


LabelNameGrp->Caption="������� ����\\...";
HintLabel->Caption="";


//�������� ������ ������� �������
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
int TFormaSpiskaInterfMainMenu::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;
DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement); 
TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_INTERF_MAINMENU",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::FormClose(TObject *Sender,
	  TCloseAction &Action)
{

if(SpisokProgramModule) SpisokProgramModule->kanRelease();
if(SpisokParameter) SpisokParameter->kanRelease();

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
DMGrp->kanRelease();
DMGrpUser->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::UpdateDerevo()
{
//������� ������ �� ����������� ������
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(NumApplication, IdGrpUser);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"������� ����",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_INTERF_MAINMENU_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_INTERF_MAINMENU_GRP->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_INTERF_MAINMENU_GRP->AsString, lpIDGrp);
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
void TFormaSpiskaInterfMainMenu::DeleteElement()
{
//
}
//-------------------------------------------------------------------
// �������������� �����
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonNewScaleClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonEdiScaleClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonDeleteScaleClick(
      TObject *Sender)
{
DeleteGrpElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::OpenFormGrpElement()
{

if (FormaGrpElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElInterfMainMenuGrp.1",IID_IFormaElementaInterfMainMenuGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->Vibor=true;
				FormaGrpElementa->NumberProcVibor=ER_Grp;
                }
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::OpenFormNewGrpElement()
{
if (FormaGrpElementa==0)
		{
		if(IdGrpUser!=0 && NumApplication!=0)
			{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElInterfMainMenuGrp.1",IID_IFormaElementaInterfMainMenuGrp,
													(void**)&FormaGrpElementa);
			FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
			if (!FormaGrpElementa) return;

			if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(NumApplication,IdGrpUser,IdGrp);
                }
			else
                {
				FormaGrpElementa->DM->NewElement(NumApplication,IdGrpUser,0);
                }
			}
		else
			{
             ShowMessage("������ �� ��� ���������!");
			}
		}
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
				}

}
//----------------------------------------------------------------------------
int TFormaSpiskaInterfMainMenu::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
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
				EndViborSpisokParameter();
				}
		SpisokParameter=0;
		}

return -1;
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonNewClick(TObject *Sender)
{
//OpenFormNewElement();
DM->Table_AppendString(NumApplication, IdGrpUser, IdGrp);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table_Delete();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="��� ��������...";
		}

IdGrp=glStrToInt64(DM->TableIDGRP_INTERF_MAINMENU->AsString);

DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------











//������� �� ����� ������
void __fastcall TFormaSpiskaInterfMainMenu::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::cxTreeView1KeyPress(TObject *Sender,
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
			DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);;
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::cxGrid1DBTableView1DblClick(
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

void __fastcall TFormaSpiskaInterfMainMenu::cxGrid1DBTableView1KeyPress(
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





void __fastcall TFormaSpiskaInterfMainMenu::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("InterfMainMenu");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaSpiskaInterfMainMenu::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_INTERF_MAINMENU->AsString));
	module->SetInt64Variables("glNumModule", NumApplication);
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


void __fastcall TFormaSpiskaInterfMainMenu::ToolButton5Click(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaInterfMainMenu::NameModulcxImageComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
NumApplication=NameModulcxImageComboBox->EditValue;

if (NumApplication==2 || NumApplication==5 || NumApplication==3)  //������ � ���������   � ��� �������
	{
    NumApplication=1;
	}
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenu::NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
IdGrpUser=NameGrpUsercxLookupComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenu::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenu::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaSpiskaInterfMainMenu::ActionSaveExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);;
	}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}

}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu(int application, __int64 id_grp_user)
{
switch (application)
        {
		case 1 :       //�������� ������
				{
				if (ClearMainMenu(application,id_grp_user)==true)
					{
					CreateFullStandartMainMenu_PAdmin(id_grp_user);
					}
				} break;

		case GC_TypeProgMod_Remont :       //������
				{
				if (ClearMainMenu(1,id_grp_user)==true)
					{
					CreateFullStandartMainMenu_Remont(id_grp_user);
					}
				} break;
		case 3 :       //��� �������
				{
				if (ClearMainMenu(application,id_grp_user)==true)
					{
					CreateFullStandartMainMenu_ARMKas(id_grp_user);
					}
				} break;
		case GC_TypeProgMod_WebArmKas :       //WEB ��� �������
				{
				if (ClearMainMenu(application,id_grp_user)==true)
					{
					CreateFullStandartMainMenu_WebARMKas(id_grp_user);
					}
				} break;
		case GC_TypeProgMod_AdmHotel :       //������������� ���������
				{
				if (ClearMainMenu(1,id_grp_user)==true)
					{
					CreateFullStandartMainMenu_AdmHotel(id_grp_user);
					}
				} break;
		default :
                {
                 ShowMessage("����������� ����������!");
                } break;
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu_PAdmin(__int64 id_grp_user)
{
__int64 id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�����������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",	StringToGUID(Global_CLSID_TFormaSpiskaSprKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �����",	StringToGUID(Global_CLSID_TFormaSpiskaSprBVNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprVesNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����",	StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountCard1Impl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���������");
if (id_grp!=0)
	{
	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �������", StringToGUID(Global_CLSID_TFormaDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� ����������",	StringToGUID(Global_CLSID_TFormaDocVosvratPostImpl));
		}
	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������", StringToGUID(Global_CLSID_TFormaDocRealImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �� ������",	StringToGUID(Global_CLSID_TFormaDocSchetImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ���", StringToGUID(Global_CLSID_TFormaDocCheckImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ���",	StringToGUID(Global_CLSID_TFormaDocRepKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����.", StringToGUID(Global_CLSID_TFormaDocRealRoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",	StringToGUID(Global_CLSID_TFormaDocPKORoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",	StringToGUID(Global_CLSID_TFormaDocRKORoznImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����", StringToGUID(Global_CLSID_TFormaDocPKOImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����",	StringToGUID(Global_CLSID_TFormaDocRKOImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������", StringToGUID(Global_CLSID_TFormaDocPlatPorImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �� ����",	StringToGUID(Global_CLSID_TFormaDocPostNaSchetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� �����", StringToGUID(Global_CLSID_TFormaDocVipBankaImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����������", StringToGUID(Global_CLSID_TFormaDocPerImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",	StringToGUID(Global_CLSID_TFormaDocIsmPriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������", StringToGUID(Global_CLSID_TFormaDocRevImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���. ��������",	StringToGUID(Global_CLSID_TFormaDocSpOtrOstImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������",	StringToGUID(Global_CLSID_TFormaDocInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �������� ������������", StringToGUID(Global_CLSID_TFormaDocOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ��������",	StringToGUID(Global_CLSID_TFormaDocSpisNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������", StringToGUID(Global_CLSID_TFormaDocVipuskProdImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������",	StringToGUID(Global_CLSID_TFormaDocSborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���������",	StringToGUID(Global_CLSID_TFormaDocRasborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",	StringToGUID(Global_CLSID_TFormaDocZamenaImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� ��������������",	StringToGUID(Global_CLSID_TFormaDocOstVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� �������������� 2",	StringToGUID(Global_CLSID_TFormaDocKorrVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �� ����������",	StringToGUID(Global_CLSID_TFormaDocVosvratPokImpl));


	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ���������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������", StringToGUID(Global_CLSID_TFormaDocRegAdvCustImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ����",	StringToGUID(Global_CLSID_TFormaDocRegBankImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� �������",StringToGUID(Global_CLSID_TFormaDocRegGoodsImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� ������ �������",StringToGUID(Global_CLSID_TFormaDocRegOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �����",	StringToGUID(Global_CLSID_TFormaDocRegKassaImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������ ����������",StringToGUID(Global_CLSID_TFormaDocRegPaySaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������������",	StringToGUID(Global_CLSID_TFormaDocRegVsRaschImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������� �� ������", StringToGUID(Global_CLSID_TFormaDocRegCardBalImpl));
		}

	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������",	StringToGUID(Global_CLSID_TFormaGurAllDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����. ���������",	StringToGUID(Global_CLSID_TFormaGurDocPrihNaklImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ���",	StringToGUID(Global_CLSID_TFormaGurDocCheckKKMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",	StringToGUID(Global_CLSID_TFormaGurDocPerImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� � �������������� �������",StringToGUID(Global_CLSID_TFormaGurOperDiscountCardImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� �������",StringToGUID(Global_CLSID_TFormaReportOCBRegGoodsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� ������ �������",StringToGUID(Global_CLSID_TFormaReportOCBRegOstNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� ������",	StringToGUID(Global_CLSID_TFormaReportKartTovaraImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� �������",StringToGUID(Global_CLSID_TFormaDialogaReportSaleCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������������",	StringToGUID(Global_CLSID_TFormaReportOCBRegVSRaschImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����������",	StringToGUID(Global_CLSID_TFormaReportKartKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ����������",	StringToGUID(Global_CLSID_TFormaDialogaReportResultRealImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ���������",	StringToGUID(Global_CLSID_TFormaReportVipuskProdImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� ���������",	StringToGUID(Global_CLSID_TFormaReportRashodProductImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������. �����",	StringToGUID(Global_CLSID_TFormaReportKalkKartaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaReportOCBPaySaleImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",	StringToGUID(Global_CLSID_TFormaReportKassaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",	StringToGUID(Global_CLSID_TFormaReportBankImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� � �������",	StringToGUID(Global_CLSID_TFormaReportDiscountDocCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����",	StringToGUID(Global_CLSID_TFormaReportGoodsReportImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaDialogaReportPoProjectImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���. � ��. ������� �� ����. ������",StringToGUID(Global_CLSID_TFormaReportOCBCardBalanceImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������",	StringToGUID(Global_CLSID_TFormaSpiskaExtModuleImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ����", StringToGUID(Global_CLSID_TFormaSpiskaInterfMainMenuImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ������ ������", StringToGUID(Global_CLSID_TFormaSpiskaInterfToolBarImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���� ������� (��� WEB)", StringToGUID(Global_CLSID_TFormaSpiskaObjectBasePrivImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprUserImpl));

	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�������� �����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ��������� ���������", StringToGUID(Global_CLSID_TFormaImportDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ������� (Excel)",	StringToGUID(Global_CLSID_TFormaSpiskaSprImportSetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� XML",StringToGUID(Global_CLSID_TFormaExportDocImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ����", StringToGUID(Global_CLSID_TFormaSpiskaSprInfBaseImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����",	StringToGUID(Global_CLSID_TFormaSpiskaSprFirmImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���",StringToGUID(Global_CLSID_TFormaSpiskaSprTypePriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����", StringToGUID(Global_CLSID_TFormaSpiskaSprKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������",StringToGUID(Global_CLSID_TFormaSpiskaSprStrObjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprSkladImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������", StringToGUID(Global_CLSID_TFormaSpiskaSprPodrImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprMPrigImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����",StringToGUID(Global_CLSID_TFormaSpiskaSprCodeTelImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������", StringToGUID(Global_CLSID_TFormaSpiskaSprInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVidKlientImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVidNomImpl));

		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������. ������",StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountAutoImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���������� ����",StringToGUID(Global_CLSID_TFormaSpiskaSprVidDiscountCardImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ������",StringToGUID(Global_CLSID_TFormaSpiskaSprNakSkidokImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����",StringToGUID(Global_CLSID_TFormaSpiskaSprScaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������",StringToGUID(Global_CLSID_TFormaSpiskaSprProjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprBrandImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"���������",StringToGUID(Global_CLSID_TFormaSpiskaSetupImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���",StringToGUID(Global_CLSID_TFormaSpiskaSprARMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������",StringToGUID(Global_CLSID_TFormaGurLogImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ��������",StringToGUID(Global_CLSID_TSheetEditorImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������� � ��������",StringToGUID(Global_CLSID_TFormaPrintPriceAImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ��������� ����������",StringToGUID(Global_CLSID_TFormaSpiskaTableNumberDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���������� ������",StringToGUID(Global_CLSID_TFormaSpiskaXSetupObmenImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������ ��������",StringToGUID(Global_CLSID_TFormaSpiskaTableExtPrintFormImpl));
	}

}
//----------------------------------------------------------------------------
__int64 TFormaSpiskaInterfMainMenu::InsertGrpMainMenu(int application, __int64 id_grp_user,
											__int64 id_grp, UnicodeString name_main_menu)
{
__int64 result=0;
IDMInterfMainMenuGrp * dm_grp;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenuGrp.1",IID_IDMInterfMainMenuGrp,
													(void**)&dm_grp);
dm_grp->Init(InterfaceMainObject,InterfaceImpl);
dm_grp->NewElement(application,id_grp_user,id_grp);
dm_grp->Element_Edit();
dm_grp->ElementNAME_INTERF_MAINMENU_GRP->AsString=name_main_menu;
dm_grp->ElementAPPLICATION_INTERF_MAINMENU_GRP->AsInteger=application;
dm_grp->ElementIDGRPUSER_INTERF_MAINMENU_GRP->AsString=id_grp_user;

if (id_grp!=0)
	{
	dm_grp->ElementIDGRP_INTERF_MAINMENU_GRP->AsString=id_grp;
	}
dm_grp->Element_Post();

result=glStrToInt64(dm_grp->ElementID_INTERF_MAINMENU_GRP->AsString);
if (dm_grp->SaveElement()==false)
	{
	ShowMessage("������ ��� ������� ������ ���� " + dm_grp->TextError);
	result=0;
	}
dm_grp->kanRelease();
return result;
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::InsertItemMainMenu(int application, __int64 id_grp_user,
									__int64 id_grp, UnicodeString name_main_menu,
									GUID guid_module)
{
IDMInterfMainMenu * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenu.1",IID_IDMInterfMainMenu,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);
if (dm->NewElement(application,id_grp_user,id_grp)==false)
	{
	ShowMessage("������ ��� ������� ������ ���� "+name_main_menu+" "+dm->TextError);
	}

dm->Element_Edit();
dm->ElementNAME_INTERF_MAINMENU->AsString=name_main_menu;
dm->ElementAPPLICATION_INTERF_MAINMENU->AsInteger=application;
dm->ElementIDGRPUSER_INTERF_MAINMENU->AsString=id_grp_user;
dm->ElementGUIDMOD_INTERF_MAINMENU->AsString=GUIDToString(guid_module);
if (id_grp!=0)
	{
	dm->ElementIDGRP_INTERF_MAINMENU->AsString=id_grp;
	}
dm->Element_Post();

if (dm->SaveElement()==false)
	{
	ShowMessage("������ ��� ������ ������ ���� " + dm->TextError);
	}
dm->kanRelease();

}
//----------------------------------------------------------------------------
bool TFormaSpiskaInterfMainMenu::ClearMainMenu(int application, __int64 id_grp_user)
{
bool result=true;
IDMInterfMainMenu * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMInterfMainMenu.1",IID_IDMInterfMainMenu,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);
dm->OpenTable(application,id_grp_user,0,true);
dm->Table->First();

while(!dm->Table->Eof)
	{
	dm->Table_Delete();
	}

dm->SaveIsmen();
delete dm;

IDMQueryUpdate * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate,
													(void**)&q);
q->Init(InterfaceMainObject,InterfaceImpl);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("update interf_mainmenu_grp set interf_mainmenu_grp.idgrp_interf_mainmenu_grp=null   \
					where interf_mainmenu_grp.idgrpuser_interf_mainmenu_grp=:PARAM_IDGRPUSER     \
							and interf_mainmenu_grp.application_interf_mainmenu_grp=:PARAM_APP ");
q->pFIBQ->ParamByName("PARAM_IDGRPUSER")->AsString=id_grp_user;
q->pFIBQ->ParamByName("PARAM_APP")->AsInteger=application;
try
	{
	q->pFIBQ->ExecQuery();
	q->pFIBTr->Commit();
	}
catch(Exception &exception)
	{
	q->pFIBTr->Rollback();
	result=false;
	ShowMessage("������ ��� �������� ������ � ������� ���� "+exception.Message);
	}

if (result==true)
	{
	q->pFIBQ->SQL->Clear();
	q->pFIBQ->SQL->Add("delete from interf_mainmenu_grp      \
					where interf_mainmenu_grp.idgrpuser_interf_mainmenu_grp=:PARAM_IDGRPUSER  \
					and interf_mainmenu_grp.application_interf_mainmenu_grp=:PARAM_APP ");
	q->pFIBQ->ParamByName("PARAM_IDGRPUSER")->AsString=id_grp_user;
	q->pFIBQ->ParamByName("PARAM_APP")->AsInteger=application;

	try
		{
		q->pFIBQ->ExecQuery();
		q->pFIBTr->Commit();
		}
	catch(Exception &exception)
		{
		q->pFIBTr->Rollback();
		result=false;
		ShowMessage("������ ��� �������� ������ ���� "+exception.Message);
		}
	}
q->kanRelease();

return result;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ActionCreateFullStandartMainMenuExecute(TObject *Sender)

{
int appl=NameModulcxImageComboBox->EditValue;
__int64 id_grp_user=NameGrpUsercxLookupComboBox->EditValue;
CreateFullStandartMainMenu(appl,id_grp_user);
UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu_ARMKas(__int64 id_grp_user)
{
__int64 id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"��� �1",StringToGUID(Global_CLSID_TFormaArmKassirImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��� �2",StringToGUID(Global_CLSID_TFormaARMKas2Impl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������",StringToGUID(Global_CLSID_TFormaPriemPlatImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� � ���������� �������",StringToGUID(Global_CLSID_TFormaOperCreditCardImpl));
	//InsertItemMainMenu(3,id_grp_user,id_grp,"�������� � ���������� �������",StringToGUID(Global_CLSID_TFormaOperPlatCardImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�����������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",StringToGUID(Global_CLSID_TFormaViborSprNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �����",StringToGUID(Global_CLSID_TFormaViborSprBVNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",StringToGUID(Global_CLSID_TFormaSpiskaSprKlientImpl));

	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"���������� ����.",StringToGUID(Global_CLSID_TFormaDocRealRoznForCashiersImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ���.",StringToGUID(Global_CLSID_TFormaDocPKORoznForCashiersImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ���.",StringToGUID(Global_CLSID_TFormaDocRKORoznForCashiersImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �� ����������",StringToGUID(Global_CLSID_TFormaVosvratPokForCashiersImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ��������",StringToGUID(Global_CLSID_TFormaGurPlatImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �����",StringToGUID(Global_CLSID_TFormaGurCheckKKM2Impl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���������",StringToGUID(Global_CLSID_TFormaGurRoznDocImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������",StringToGUID(Global_CLSID_TFormaReportSaleForCashiersImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �������",StringToGUID(Global_CLSID_TFormaReportDiscountForCashiersImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������",StringToGUID(Global_CLSID_TFormaSpiskaExtModuleImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ��������",StringToGUID(Global_CLSID_TFormaPrintPriceAImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ��������",StringToGUID(Global_CLSID_TSheetEditorImpl));
	}
}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu_WebARMKas(__int64 id_grp_user)
{
__int64 id_grp=InsertGrpMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,0,"���");
if (id_grp!=0)
	{
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"��� �1",StringToGUID(Global_CLSID_TFormaArmKassirImpl));
	}

id_grp=InsertGrpMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,0,"�����������");
if (id_grp!=0)
	{
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"������������",StringToGUID(Global_CLSID_TFormaViborSprNomImpl));
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"������� �����",StringToGUID(Global_CLSID_TFormaViborSprBVNomImpl));
	}

id_grp=InsertGrpMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,0,"�������");
if (id_grp!=0)
	{
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"������ �����",StringToGUID(Global_CLSID_TFormaGurCheckKKM2Impl));
	}

id_grp=InsertGrpMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"�������",StringToGUID(Global_CLSID_TFormaReportSaleForCashiersImpl));
	InsertItemMainMenu(GC_TypeProgMod_WebArmKas,id_grp_user,id_grp,"����� �� �������",StringToGUID(Global_CLSID_TFormaReportDiscountForCashiersImpl));
	}

}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu_AdmHotel(__int64 id_grp_user)
{
__int64 id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���������");


if (id_grp!=0)
	{
	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprPrOsnUslImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprCatNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprCelPriesdaImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ����",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprNFImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprObjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� �������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprSostNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���������",StringToGUID(Global_CLSID_THOT_FormaSpiskaSprTypePosImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� ���������",StringToGUID(Global_CLSID_THOT_FormaTableSostNFImpl));
		}
	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"���������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������������",StringToGUID(Global_CLSID_THOT_FormaDocBronImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ �����",StringToGUID(Global_CLSID_THOT_FormaDocOtmenaBronImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_THOT_FormaDocRaschetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_THOT_FormaDocRasmImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_THOT_FormaDocRealImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����",StringToGUID(Global_CLSID_THOT_FormaDocViesdImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ������",StringToGUID(Global_CLSID_THOT_GurAllDocImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ��������� �����",StringToGUID(Global_CLSID_THOT_FormaReportDvNomFondaImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_THOT_FormaReportRasmImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� (�����/�����)",StringToGUID(Global_CLSID_THOT_FormaReportRasmK_SImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ��������� �����",StringToGUID(Global_CLSID_THOT_FormaReportSostNFImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ������",StringToGUID(Global_CLSID_THOT_FormaReportSvobodNFImpl));
		}
	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�����������");

if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",StringToGUID(Global_CLSID_TFormaSpiskaSprNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",StringToGUID(Global_CLSID_TFormaSpiskaSprKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �����",StringToGUID(Global_CLSID_TFormaSpiskaSprBVNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVesNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����",StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountCard1Impl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���������");
if (id_grp!=0)
	{
	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �������",StringToGUID(Global_CLSID_TFormaDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� ����������",StringToGUID(Global_CLSID_TFormaDocVosvratPostImpl));
		}
	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_TFormaDocRealImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �� ������",StringToGUID(Global_CLSID_TFormaDocSchetImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ���",StringToGUID(Global_CLSID_TFormaDocCheckImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ���",StringToGUID(Global_CLSID_TFormaDocRepKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����.",StringToGUID(Global_CLSID_TFormaDocRealRoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",StringToGUID(Global_CLSID_TFormaDocPKORoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",StringToGUID(Global_CLSID_TFormaDocRKORoznImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����",StringToGUID(Global_CLSID_TFormaDocPKOImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����",StringToGUID(Global_CLSID_TFormaDocRKOImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������",StringToGUID(Global_CLSID_TFormaDocPlatPorImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �� ����",StringToGUID(Global_CLSID_TFormaDocPostNaSchetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� �����",StringToGUID(Global_CLSID_TFormaDocVipBankaImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����������",StringToGUID(Global_CLSID_TFormaDocPerImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_TFormaDocIsmPriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������",StringToGUID(Global_CLSID_TFormaDocRevImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���. ��������",StringToGUID(Global_CLSID_TFormaDocSpOtrOstImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������",StringToGUID(Global_CLSID_TFormaDocInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �������� ������������",StringToGUID(Global_CLSID_TFormaDocOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ��������",StringToGUID(Global_CLSID_TFormaDocSpisNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������",StringToGUID(Global_CLSID_TFormaDocVipuskProdImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������",StringToGUID(Global_CLSID_TFormaDocSborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���������",StringToGUID(Global_CLSID_TFormaDocRasborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaDocZamenaImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� ��������������",StringToGUID(Global_CLSID_TFormaDocOstVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� �������������� 2",StringToGUID(Global_CLSID_TFormaDocKorrVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �� ����������",StringToGUID(Global_CLSID_TFormaDocVosvratPokImpl));


	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ���������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������",StringToGUID(Global_CLSID_TFormaDocRegAdvCustImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ����",StringToGUID(Global_CLSID_TFormaDocRegBankImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� �������",StringToGUID(Global_CLSID_TFormaDocRegGoodsImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� ������ �������",StringToGUID(Global_CLSID_TFormaDocRegOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �����",StringToGUID(Global_CLSID_TFormaDocRegKassaImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������ ����������",StringToGUID(Global_CLSID_TFormaDocRegPaySaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������������",StringToGUID(Global_CLSID_TFormaDocRegVsRaschImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������� �� ������",StringToGUID(Global_CLSID_TFormaDocRegCardBalImpl));
		}

	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������",StringToGUID(Global_CLSID_TFormaGurAllDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����. ���������",StringToGUID(Global_CLSID_TFormaGurDocPrihNaklImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ���",StringToGUID(Global_CLSID_TFormaGurDocCheckKKMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",StringToGUID(Global_CLSID_TFormaGurDocPerImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� � �������������� �������",StringToGUID(Global_CLSID_TFormaGurOperDiscountCardImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� �������",StringToGUID(Global_CLSID_TFormaReportOCBRegGoodsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� ������ �������",StringToGUID(Global_CLSID_TFormaReportOCBRegOstNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� ������",StringToGUID(Global_CLSID_TFormaReportKartTovaraImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� �������",StringToGUID(Global_CLSID_TFormaDialogaReportSaleCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������������",StringToGUID(Global_CLSID_TFormaReportOCBRegVSRaschImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����������",StringToGUID(Global_CLSID_TFormaReportKartKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ����������",StringToGUID(Global_CLSID_TFormaDialogaReportResultRealImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ���������",StringToGUID(Global_CLSID_TFormaReportVipuskProdImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� ���������",StringToGUID(Global_CLSID_TFormaReportRashodProductImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������. �����",StringToGUID(Global_CLSID_TFormaReportKalkKartaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaReportOCBPaySaleImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",StringToGUID(Global_CLSID_TFormaReportKassaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",StringToGUID(Global_CLSID_TFormaReportBankImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� � �������",StringToGUID(Global_CLSID_TFormaReportDiscountDocCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����",StringToGUID(Global_CLSID_TFormaReportGoodsReportImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaDialogaReportPoProjectImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���. � ��. ������� �� ����. ������",StringToGUID(Global_CLSID_TFormaReportOCBCardBalanceImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������",StringToGUID(Global_CLSID_TFormaSpiskaExtModuleImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ����",StringToGUID(Global_CLSID_TFormaSpiskaInterfMainMenuImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ������ ������",StringToGUID(Global_CLSID_TFormaSpiskaInterfToolBarImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���� ������� (��� WEB)",StringToGUID(Global_CLSID_TFormaSpiskaObjectBasePrivImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",StringToGUID(Global_CLSID_TFormaSpiskaSprUserImpl));

	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�������� �����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ��������� ���������", StringToGUID(Global_CLSID_TFormaImportDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ������� (Excel)",	StringToGUID(Global_CLSID_TFormaSpiskaSprImportSetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� XML",StringToGUID(Global_CLSID_TFormaExportDocImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ����", StringToGUID(Global_CLSID_TFormaSpiskaSprInfBaseImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����",	StringToGUID(Global_CLSID_TFormaSpiskaSprFirmImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���",StringToGUID(Global_CLSID_TFormaSpiskaSprTypePriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����", StringToGUID(Global_CLSID_TFormaSpiskaSprKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������",StringToGUID(Global_CLSID_TFormaSpiskaSprStrObjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprSkladImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������", StringToGUID(Global_CLSID_TFormaSpiskaSprPodrImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprMPrigImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����",StringToGUID(Global_CLSID_TFormaSpiskaSprCodeTelImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������", StringToGUID(Global_CLSID_TFormaSpiskaSprInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVidKlientImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVidNomImpl));

		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������. ������", StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountAutoImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���������� ����",StringToGUID(Global_CLSID_TFormaSpiskaSprVidDiscountCardImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ������",StringToGUID(Global_CLSID_TFormaSpiskaSprNakSkidokImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����", StringToGUID(Global_CLSID_TFormaSpiskaSprScaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������",	StringToGUID(Global_CLSID_TFormaSpiskaSprProjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprBrandImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"���������", StringToGUID(Global_CLSID_TFormaSpiskaSetupImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���",	StringToGUID(Global_CLSID_TFormaSpiskaSprARMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������", StringToGUID(Global_CLSID_TFormaGurLogImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ��������",StringToGUID(Global_CLSID_TSheetEditorImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������� � ��������",StringToGUID(Global_CLSID_TFormaPrintPriceAImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ��������� ����������",StringToGUID(Global_CLSID_TFormaSpiskaTableNumberDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���������� ������",StringToGUID(Global_CLSID_TFormaSpiskaXSetupObmenImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������ ��������",StringToGUID(Global_CLSID_TFormaSpiskaTableExtPrintFormImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ � ���",	StringToGUID(Global_CLSID_THOT_FormaKKTOperationImpl));
	}


}
//----------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::CreateFullStandartMainMenu_Remont(__int64 id_grp_user)
{
__int64 id_grp=InsertGrpMainMenu(1,id_grp_user,0,"��������� �����");


if (id_grp!=0)
	{
	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������", StringToGUID(Global_CLSID_TREM_FormaSpiskaSprNeisprImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",	StringToGUID(Global_CLSID_TREM_FormaSpiskaSprModelImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������",StringToGUID(Global_CLSID_TREM_FormaSpiskaSprSostImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �������",StringToGUID(Global_CLSID_TREM_FormaSpiskaSprTypeRemontImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������������",StringToGUID(Global_CLSID_TREM_FormaSpiskaSprHardwareImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���",StringToGUID(Global_CLSID_TREM_FormaSpiskaSprKKTImpl));
		}
	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"���������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TREM_FormaDocRemontImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ������������",	StringToGUID(Global_CLSID_TREM_FormaDocRemontHWImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���", StringToGUID(Global_CLSID_TREM_FormaSpiskaSprKKTImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��-1",StringToGUID(Global_CLSID_TREM_FormaDocKM1Impl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��-2",StringToGUID(Global_CLSID_TREM_FormaDocKM2Impl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���",StringToGUID(Global_CLSID_TREM_FormaDocSetServKKTImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ������������",StringToGUID(Global_CLSID_TREM_FormaDocSetServHWImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ������", StringToGUID(Global_CLSID_TREM_FormaGurAllDocImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������", StringToGUID(Global_CLSID_TREM_FormaGurZImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� ����������", StringToGUID(Global_CLSID_TREM_FormaGurCustQueryImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"������");
	if(id_grp1!=0)
		{

		}
	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�����������");

if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",StringToGUID(Global_CLSID_TFormaSpiskaSprKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �����",StringToGUID(Global_CLSID_TFormaSpiskaSprBVNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprVesNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����",StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountCard1Impl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"���������");
if (id_grp!=0)
	{
	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �������",StringToGUID(Global_CLSID_TFormaDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� ����������",StringToGUID(Global_CLSID_TFormaDocVosvratPostImpl));
		}
	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",StringToGUID(Global_CLSID_TFormaDocRealImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �� ������",StringToGUID(Global_CLSID_TFormaDocSchetImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ��������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ���",StringToGUID(Global_CLSID_TFormaDocCheckImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ���",StringToGUID(Global_CLSID_TFormaDocRepKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����.", StringToGUID(Global_CLSID_TFormaDocRealRoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",	StringToGUID(Global_CLSID_TFormaDocPKORoznImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���.",	StringToGUID(Global_CLSID_TFormaDocRKORoznImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����", StringToGUID(Global_CLSID_TFormaDocPKOImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����. �������� �����",StringToGUID(Global_CLSID_TFormaDocRKOImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������", StringToGUID(Global_CLSID_TFormaDocPlatPorImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������� �� ����",	StringToGUID(Global_CLSID_TFormaDocPostNaSchetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������� �����", StringToGUID(Global_CLSID_TFormaDocVipBankaImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����������",StringToGUID(Global_CLSID_TFormaDocPerImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����������",	StringToGUID(Global_CLSID_TFormaDocIsmPriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������", StringToGUID(Global_CLSID_TFormaDocRevImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���. ��������",StringToGUID(Global_CLSID_TFormaDocSpOtrOstImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������",	StringToGUID(Global_CLSID_TFormaDocInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� �������� ������������", StringToGUID(Global_CLSID_TFormaDocOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��� ��������",	StringToGUID(Global_CLSID_TFormaDocSpisNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������", StringToGUID(Global_CLSID_TFormaDocVipuskProdImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������ ���������",	StringToGUID(Global_CLSID_TFormaDocSborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ���������",	StringToGUID(Global_CLSID_TFormaDocRasborkaKomplImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",	StringToGUID(Global_CLSID_TFormaDocZamenaImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� ��������������",	StringToGUID(Global_CLSID_TFormaDocOstVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������� �������������� 2",	StringToGUID(Global_CLSID_TFormaDocKorrVsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� �� ����������",	StringToGUID(Global_CLSID_TFormaDocVosvratPokImpl));


	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"��������� ���������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������", StringToGUID(Global_CLSID_TFormaDocRegAdvCustImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ����",	StringToGUID(Global_CLSID_TFormaDocRegBankImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� �������",StringToGUID(Global_CLSID_TFormaDocRegGoodsImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������� ������ �������",StringToGUID(Global_CLSID_TFormaDocRegOstNomImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �����",	StringToGUID(Global_CLSID_TFormaDocRegKassaImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� ������ ����������", StringToGUID(Global_CLSID_TFormaDocRegPaySaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������������",	StringToGUID(Global_CLSID_TFormaDocRegVsRaschImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� �������� �������� �� ������", StringToGUID(Global_CLSID_TFormaDocRegCardBalImpl));
		}

	}


id_grp=InsertGrpMainMenu(1,id_grp_user,0,"�������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������",StringToGUID(Global_CLSID_TFormaGurAllDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����. ���������",StringToGUID(Global_CLSID_TFormaGurDocPrihNaklImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ���",	StringToGUID(Global_CLSID_TFormaGurDocCheckKKMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�����������",StringToGUID(Global_CLSID_TFormaGurDocPerImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� � �������������� �������",StringToGUID(Global_CLSID_TFormaGurOperDiscountCardImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� �������",StringToGUID(Global_CLSID_TFormaReportOCBRegGoodsImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� � �������� ������ �������",StringToGUID(Global_CLSID_TFormaReportOCBRegOstNomImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� ������",	StringToGUID(Global_CLSID_TFormaReportKartTovaraImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� �������",StringToGUID(Global_CLSID_TFormaDialogaReportSaleCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������������",	StringToGUID(Global_CLSID_TFormaReportOCBRegVSRaschImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����������",	StringToGUID(Global_CLSID_TFormaReportKartKlientImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ����������",	StringToGUID(Global_CLSID_TFormaDialogaReportResultRealImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ ���������",	StringToGUID(Global_CLSID_TFormaReportVipuskProdImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� ���������",	StringToGUID(Global_CLSID_TFormaReportRashodProductImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������. �����",	StringToGUID(Global_CLSID_TFormaReportKalkKartaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaReportOCBPaySaleImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",	StringToGUID(Global_CLSID_TFormaReportKassaImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� �����",	StringToGUID(Global_CLSID_TFormaReportBankImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� � �������",	StringToGUID(Global_CLSID_TFormaReportDiscountDocCheckImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"�������� �����",	StringToGUID(Global_CLSID_TFormaReportGoodsReportImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"����� �� ��������",StringToGUID(Global_CLSID_TFormaDialogaReportPoProjectImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���. � ��. ������� �� ����. ������",StringToGUID(Global_CLSID_TFormaReportOCBCardBalanceImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������",	StringToGUID(Global_CLSID_TFormaSpiskaExtModuleImpl));
	}

id_grp=InsertGrpMainMenu(1,id_grp_user,0,"������");
if (id_grp!=0)
	{
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ����", StringToGUID(Global_CLSID_TFormaSpiskaInterfMainMenuImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ������ ������", StringToGUID(Global_CLSID_TFormaSpiskaInterfToolBarImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���� ������� (��� WEB)", StringToGUID(Global_CLSID_TFormaSpiskaObjectBasePrivImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprUserImpl));

	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�������� �����");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������� ��������� ���������", StringToGUID(Global_CLSID_TFormaImportDocPrihNaklImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ������� (Excel)",	StringToGUID(Global_CLSID_TFormaSpiskaSprImportSetImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� XML",StringToGUID(Global_CLSID_TFormaExportDocImpl));
		}

	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"�����������");
	if(id_grp1!=0)
		{
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ����", StringToGUID(Global_CLSID_TFormaSpiskaSprInfBaseImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����",StringToGUID(Global_CLSID_TFormaSpiskaSprFirmImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���",StringToGUID(Global_CLSID_TFormaSpiskaSprTypePriceImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�����", StringToGUID(Global_CLSID_TFormaSpiskaSprKKMImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������� ���������",	StringToGUID(Global_CLSID_TFormaSpiskaSprStrObjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprSkladImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������", StringToGUID(Global_CLSID_TFormaSpiskaSprPodrImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����� ������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprMPrigImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���������� ����",StringToGUID(Global_CLSID_TFormaSpiskaSprCodeTelImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"��������������", StringToGUID(Global_CLSID_TFormaSpiskaSprInvImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",	StringToGUID(Global_CLSID_TFormaSpiskaSprVidKlientImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ������������",StringToGUID(Global_CLSID_TFormaSpiskaSprVidNomImpl));

		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������. ������", StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountAutoImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"���� ���������� ����",	StringToGUID(Global_CLSID_TFormaSpiskaSprVidDiscountCardImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������������� ������",StringToGUID(Global_CLSID_TFormaSpiskaSprNakSkidokImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"����", StringToGUID(Global_CLSID_TFormaSpiskaSprScaleImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"�������",	StringToGUID(Global_CLSID_TFormaSpiskaSprProjectImpl));
		InsertItemMainMenu(1,id_grp_user,id_grp1,"������",StringToGUID(Global_CLSID_TFormaSpiskaSprBrandImpl));
		}

	InsertItemMainMenu(1,id_grp_user,id_grp,"���������", StringToGUID(Global_CLSID_TFormaSpiskaSetupImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���",	StringToGUID(Global_CLSID_TFormaSpiskaSprARMImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������", StringToGUID(Global_CLSID_TFormaGurLogImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ��������",	StringToGUID(Global_CLSID_TSheetEditorImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ �������� � ��������", StringToGUID(Global_CLSID_TFormaPrintPriceAImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"���� ��������� ����������",	StringToGUID(Global_CLSID_TFormaSpiskaTableNumberDocImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"��������� ���������� ������", StringToGUID(Global_CLSID_TFormaSpiskaXSetupObmenImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������� ������ ��������",	StringToGUID(Global_CLSID_TFormaSpiskaTableExtPrintFormImpl));
	InsertItemMainMenu(1,id_grp_user,id_grp,"������ � ���",	StringToGUID(Global_CLSID_THOT_FormaKKTOperationImpl));
	}



}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonClearMenuClick(TObject *Sender)

{
int appl=NameModulcxImageComboBox->EditValue;
__int64 id_grp_user=NameGrpUsercxLookupComboBox->EditValue;

if (appl==GC_TypeProgMod_AdmHotel) appl=1;
if (appl==GC_TypeProgMod_Remont) appl=1;
if (appl== GC_TypeProgMod_ArmKas) appl=1;


//�������� ������ WEB ����������
//��� ���� ����� WEB 1

ClearMainMenu(appl,id_grp_user);
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaInterfMainMenu::cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProgramModule();
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::ViborProgramModule(void)
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
void TFormaSpiskaInterfMainMenu::EndViborProgramModule(void)
{

	DM->Table->Edit();
	DM->TableGUIDMOD_INTERF_MAINMENU->AsString=SpisokProgramModule->DM->TableGUID_PROGRAM_MODULE->AsString;
	DM->TableNAME_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TableNAME_PROGRAM_MODULE->AsString;
	DM->TableIDMOD_INTERF_MAINMENU->AsString=SpisokProgramModule->DM->TableID_PROGRAM_MODULE->AsString;
	DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger=SpisokProgramModule->DM->TableTYPEMOD_PROGRAM_MODULE->AsInteger;
	DM->TablePATCH_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TablePATCH_PROGRAM_MODULE->AsString;
	DM->Table->Post();
}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::ViborSpisokParameter(void)
{
if (SpisokParameter==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaInterfMainMenuPar,IID_IFormaSpiskaInterfMainMenuPar,
													(void**)&SpisokParameter);
		SpisokParameter->Init(InterfaceMainObject,InterfaceImpl);
		SpisokParameter->NumberProcVibor=ER_SpisokParameter;
		SpisokParameter->TextHeader=DM->TableNAME_INTERF_MAINMENU->AsString;
		SpisokParameter->IdOwner=glStrToInt64(DM->TableID_INTERF_MAINMENU->AsString);
		SpisokParameter->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TFormaSpiskaInterfMainMenu::EndViborSpisokParameter(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaInterfMainMenu::ToolButtonOpenSpisokParamClick(TObject *Sender)

{
ViborSpisokParameter();
}
//---------------------------------------------------------------------------

