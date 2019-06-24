//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UART_FormaElementaSprInfBlock.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
__fastcall TART_FormaElementaSprInfBlock::TART_FormaElementaSprInfBlock(TComponent* Owner)
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
bool TART_FormaElementaSprInfBlock::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_ART_DMSprInfBlock,IID_IART_DMSprInfBlock,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_ART_DMSprInfBlockPriv,IID_IART_DMSprInfBlockPriv,
							(void**)&DMPriv);
DMPriv->Init(InterfaceMainObject,InterfaceImpl);


IndexcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KeyWordscxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
TitlecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
GuidcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

WebKeyWordscxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
WebTitlecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
WebDescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

cxDBCheckBoxFL_ADD_SITEMAP_ART_IB->DataBinding->DataSource=DM->DataSourceElement;
cxGrid1DBTableView1->DataController->DataSource=DMPriv->DataSourceTable;
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
int  TART_FormaElementaSprInfBlock::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TART_FormaElementaSprInfBlock::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBlockSostav)FormaSpiskaSprInfBlockSostav->kanRelease();


DMPriv->kanRelease();
DM->kanRelease();


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
void TART_FormaElementaSprInfBlock::UpdateForm(void)
{
DMPriv->OpenTable(glStrToInt64(DM->ElementID_ART_IB->AsString));
NameGrpLabel->Caption=NameGrp;
}
//---------------------------------------------------------------------------


int TART_FormaElementaSprInfBlock::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_EditPageElement)
				{
				if (type_event==1)
					{
					}
				FormaSpiskaSprInfBlockSostav=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------







void __fastcall TART_FormaElementaSprInfBlock::cxButtonOpenFormaSpiskaElementClick(TObject *Sender)
{

if (FormaSpiskaSprInfBlockSostav==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaSpiskaSprInfBlockSostav,IID_IART_FormaSpiskaSprInfBlockSostav,
													 (void**)&FormaSpiskaSprInfBlockSostav);
		FormaSpiskaSprInfBlockSostav->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBlockSostav->IdPage=glStrToInt64(DM->ElementID_ART_IB->AsString);
		FormaSpiskaSprInfBlockSostav->DM->OpenTable(glStrToInt64(DM->ElementID_ART_IB->AsString));
		FormaSpiskaSprInfBlockSostav->HeaderText=DM->ElementNAME_ART_IB->AsString;
		FormaSpiskaSprInfBlockSostav->UpdateForm();
		FormaSpiskaSprInfBlockSostav->NumberProcVibor=ER_EditPageElement;
		}


}
//---------------------------------------------------------------------------


void __fastcall TART_FormaElementaSprInfBlock::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TART_FormaElementaSprInfBlock::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{
    Close();
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TART_FormaElementaSprInfBlock::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
	{

	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------



void __fastcall TART_FormaElementaSprInfBlock::KeyWordscxDBTextEditKeyPress(TObject *Sender,
          wchar_t &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------






void __fastcall TART_FormaElementaSprInfBlock::BitBtnAddClick(TObject *Sender)
{
DMPriv->TableAppend(glStrToInt64(DM->ElementID_ART_IB->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TART_FormaElementaSprInfBlock::BitBtnDelClick(TObject *Sender)
{
DMPriv->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TART_FormaElementaSprInfBlock::BitBtnSaveClick(TObject *Sender)
{
DMPriv->SaveIsmen();
}
//---------------------------------------------------------------------------

