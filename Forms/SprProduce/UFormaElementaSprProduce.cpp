//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprProduce.h"
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
__fastcall TFormaElementaSprProduce::TFormaElementaSprProduce(TComponent* Owner)
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
bool TFormaElementaSprProduce::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProduce,IID_IDMSprProduce, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


//value factor
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprFactorValue,IID_IDMSprFactorValue, (void**)&DMSprFactorValue);
DMSprFactorValue->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DMSprFactorValue->DataSourceTable;

TcxLookupComboBoxProperties  *  AProperties;
AProperties=(TcxLookupComboBoxProperties *) cxGrid1DBTableView1IDFACTOR_SFACTOR_VAL->GetProperties();
AProperties->ListSource=DMSprFactorValue->DataSourceFactorList;


CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CommentcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
BelkicxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
GiricxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
UglcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int  TFormaElementaSprProduce::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProduce::FormClose(TObject *Sender,
      TCloseAction &Action)
{

DM->kanRelease();
DMSprFactorValue->kanRelease();

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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprProduce::UpdateForm(void)
{
DMSprFactorValue->OpenTable(glStrToInt64(DM->ElementID_SPRODUCE->AsString ));

NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TFormaElementaSprProduce::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------










void __fastcall TFormaElementaSprProduce::ToolButtonAddPriceClick(TObject *Sender)
{
DMSprFactorValue->Table->Append();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProduce::ToolButtonDeletePriceClick(
      TObject *Sender)
{
DMSprFactorValue->Table->Delete();
}

//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProduce::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProduce::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMSprFactorValue->SaveIsmen()==true)
		{
		Close();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMSprFactorValue->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProduce::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
	if (DMSprFactorValue->SaveIsmen()==true)
		{
		UpdateForm();
		}
	else
		{
		ShowMessage("Ошибка при записи справочника цен! "+DMSprFactorValue->TextError);
		}
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprProduce::ToolButtonAddAllFactorsClick(TObject *Sender)

{
IDMSprFactor * dm_factor;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprFactor,IID_IDMSprFactor, (void**)&dm_factor);
dm_factor->Init(InterfaceMainObject,InterfaceImpl);

dm_factor->OpenTable();

while(!dm_factor->Table->Eof)
	{
	DMSprFactorValue->Table->Append();
	DMSprFactorValue->TableIDFACTOR_SFACTOR_VAL->AsString=dm_factor->TableID_SFACTOR->AsString;
    DMSprFactorValue->Table->Post();
    dm_factor->Table->Next();
	}

}
//---------------------------------------------------------------------------

