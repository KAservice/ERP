//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaSpiskaSprModelTypRabot.h"
#include "IREM_FormaElementaSprModelTypRabot.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "IDMSprNom.h"
#include "IDMSprPropertiesNaborSostav.h"
#include "IDMSprGrpNom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckBox"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprModelTypRabot::TREM_FormaSpiskaSprModelTypRabot(TComponent* Owner)
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
bool TREM_FormaSpiskaSprModelTypRabot::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModelTypRabot,IID_IREM_DMSprModelTypRabot,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaSpiskaSprModelTypRabotImpl),false);
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
int TREM_FormaSpiskaSprModelTypRabot::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelTypRabot::UpdateForm(void)
{
DM->OpenTable(IdOwner);
LabelNom->Caption=HeaderText;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelTypRabot::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelTypRabot::OpenFormElement()
{
IREM_FormaElementaSprModelTypRabot * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprModelTypRabot,IID_IREM_FormaElementaSprModelTypRabot,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(DM->TableID_REM_SMODEL_TRAB->AsLargeInt);
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_Element;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelTypRabot::OpenFormNewElement()
{
IREM_FormaElementaSprModelTypRabot * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprModelTypRabot,IID_IREM_FormaElementaSprModelTypRabot,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdOwner);
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_Element;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelTypRabot::DeleteElement()
{
DM->DeleteElement(DM->TableID_REM_SMODEL_TRAB->AsLargeInt);
DM->OpenTable(IdOwner);
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprModelTypRabot::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelTypRabot::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelTypRabot::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaSpiskaSprModelTypRabot::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(DM->TableID_REM_SMODEL_TRAB->AsLargeInt);
		TypeEvent=1;
		Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprModelTypRabot::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(DM->TableID_REM_SMODEL_TRAB->AsLargeInt);
		TypeEvent=1;
        Close();
		}
else
		{
		OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TREM_FormaSpiskaSprModelTypRabot::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelTypRabot::RunExternalModule(__int64 id_module, int type_module)
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
//
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//���� �������� ������� DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

if (type_module==3)
	{  //���� �������� ���������� ������, ��� �������  IDDOC
	module->SetInt64Variables("glIdOwner", glStrToInt64(DM->TableIDMODEL_REM_SMODEL_TRAB->AsString));
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_REM_SMODEL_TRAB->AsString));
	}

module->ExecuteModule();


}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprModelTypRabot::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprModelTypRabot::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{


DM->OpenTable(IdOwner);
return -1;
}
//-----------------------------------------------------------------------------



