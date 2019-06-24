//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprLossFactor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "IDMSprFactor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxSpinEdit"
#pragma link "cxCurrencyEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaElementaSprLossFactor::TFormaElementaSprLossFactor(TComponent* Owner)
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
bool TFormaElementaSprLossFactor::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprLossFactor,IID_IDMSprLossFactor, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


//value factor
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprLossFactorValue,IID_IDMSprLossFactorValue, (void**)&DMSprLossFactorValue);
DMSprLossFactorValue->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DMSprLossFactorValue->DataSourceTable;

TcxLookupComboBoxProperties  *  AProperties;
AProperties=(TcxLookupComboBoxProperties *) cxGrid1DBTableView1IDFACTOR_SLOSS_FACTOR_VAL->GetProperties();
AProperties->ListSource=DMSprLossFactorValue->DataSourceFactorList;


CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CommentcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
BelkicxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
GiricxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
UglcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int  TFormaElementaSprLossFactor::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprLossFactor::FormClose(TObject *Sender,
      TCloseAction &Action)
{

DM->kanRelease();
DMSprLossFactorValue->kanRelease();

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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprLossFactor::UpdateForm(void)
{
DMSprLossFactorValue->OpenTable(glStrToInt64(DM->ElementID_SLOSS_FACTOR->AsString ));

NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TFormaElementaSprLossFactor::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------










void __fastcall TFormaElementaSprLossFactor::ToolButtonAddPriceClick(TObject *Sender)
{
DMSprLossFactorValue->Table->Append();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprLossFactor::ToolButtonDeletePriceClick(
      TObject *Sender)
{
DMSprLossFactorValue->Table->Delete();
}

//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprLossFactor::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprLossFactor::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMSprLossFactorValue->SaveIsmen()==true)
		{
		Close();
		}
	else
		{
		ShowMessage("������ ��� ������ ����������� ���! "+DMSprLossFactorValue->TextError);
		}
	}
else
	{
	ShowMessage("������ ��� ������!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprLossFactor::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMSprLossFactorValue->SaveIsmen()==true)
		{
		UpdateForm();
		}
	else
		{
		ShowMessage("������ ��� ������ ����������� ���! "+DMSprLossFactorValue->TextError);
		}
	}
else
	{
	ShowMessage("������ ��� ������!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprLossFactor::ToolButtonAddAllFactorsClick(TObject *Sender)

{
IDMSprFactor * dm_factor;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprFactor,IID_IDMSprFactor, (void**)&dm_factor);
dm_factor->Init(InterfaceMainObject,InterfaceImpl);

dm_factor->OpenTable();

while(!dm_factor->Table->Eof)
	{
	DMSprLossFactorValue->Table->Append();
	DMSprLossFactorValue->TableIDFACTOR_SLOSS_FACTOR_VAL->AsString=dm_factor->TableID_SFACTOR->AsString;
    DMSprLossFactorValue->Table->Post();
    dm_factor->Table->Next();
	}

}
//---------------------------------------------------------------------------

