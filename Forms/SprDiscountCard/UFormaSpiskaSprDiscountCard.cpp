//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprDiscountCard.h"
#include "IFormaElementaSprDiscountCard.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
 #include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxCheckBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprDiscountCard::TFormaSpiskaSprDiscountCard(TComponent* Owner)
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
bool TFormaSpiskaSprDiscountCard::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard, (void**)&DM);

DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
																 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountCardImpl),false);
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
int  TFormaSpiskaSprDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard::UpdateForm(void)
{
DM->OpenTable(IdKlient);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard::FormClose(TObject *Sender,
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
DM->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprDiscountCard::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
DM->OpenTable(IdKlient);

return -1;
}
//-----------------------------------------------------------------------------

void TFormaSpiskaSprDiscountCard::OpenFormElement()
{
IFormaElementaSprDiscountCard * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountCard.1",IID_IFormaElementaSprDiscountCard,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard::OpenFormNewElement()
{
IFormaElementaSprDiscountCard * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountCard.1",IID_IFormaElementaSprDiscountCard,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdKlient);
FormaElementa->UpdateForm();
FormaElementa->DM->ElementNAMEKLIENT->AsString=NameKlient;
FormaElementa->NumberProcVibor=1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
DM->OpenTable(IdKlient);
}
//--------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDiscountCard::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDiscountCard");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
        Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprDiscountCard::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
		TypeEvent=1;
        DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
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
void __fastcall TFormaSpiskaSprDiscountCard::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",
								IID_IFormaRunExternalModule, (void**)&module);
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

 //���� �������� ���������� ������, ��� �������  IDDOC
	module->SetInt64Variables("glIdKlient", glStrToInt64(DM->TableIDKLIENT_SDISCOUNT_CARD->AsString));
	module->SetInt64Variables("glIdDiscountCard", glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));

module->ExecuteModule();


}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDiscountCard::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

