//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaXSetupObmen.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
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
#pragma link "cxMaskEdit"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaXSetupObmen::TFormaElementaXSetupObmen(TComponent* Owner)
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
bool TFormaElementaXSetupObmen::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMXSetupObmen.1",IID_IDMXSetupObmen, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprInfBase.1",IID_IDMSprInfBase, (void**)&DMSprInfBase);
DMSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
DMSprInfBase->OpenTable();

//очистим меню
InfBasePopupMenu->Items->Clear();

//заполним список инф. баз
//__int64 id_tec_podr=0;
TMenuItem *menu;
DMSprInfBase->Table->First();
while ( !DMSprInfBase->Table->Eof)
		{
//		id_tec_podr=DM->IBQSprGrpBVIDPOD_GBVNOM->AsInt64;
		menu=new TMenuItem(InfBasePopupMenu);
		menu->Caption=DMSprInfBase->TableNAME_SINFBASE_OBMEN->AsString;
		menu->OnClick = InfBasePopupMenuClick;
		menu->Tag=DMSprInfBase->TableID_SINFBASE_OBMEN->AsInt64;
		InfBasePopupMenu->Items->Add(menu);
		DMSprInfBase->Table->Next();
		}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
//очистим меню
TypePricePopupMenu->Items->Clear();

//заполним список инф. баз
//__int64 id_tec_podr=0;
//TMenuItem *menu;
DMSprTypePrice->Table->First();
while ( !DMSprTypePrice->Table->Eof)
		{
		menu=new TMenuItem(TypePricePopupMenu);
		menu->Caption=DMSprTypePrice->TableNAME_TPRICE->AsString;
		menu->OnClick = TypePricePopupMenuClick;
		menu->Tag=DMSprTypePrice->TableID_TPRICE->AsInt64;
		TypePricePopupMenu->Items->Add(menu);
		DMSprTypePrice->Table->Next();
		}

NameBaseObmencxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
cxGrid1DBTableViewBase->DataController->DataSource=DM->DataSourceBaseForObmen;
cxGrid2DBTableViewTypePrice->DataController->DataSource=DM->DataSourceTypePriceForObmen;
IdStardIdXTismcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;

AllDoccxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
OutZakPricecxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaXSetupObmen::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaXSetupObmen::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();

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

DMSprInfBase->kanRelease();
DMSprTypePrice->kanRelease();
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}


}
//---------------------------------------------------------------------------
void TFormaElementaXSetupObmen::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaXSetupObmen::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("XSetupObmen");
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaXSetupObmen::NameBaseObmencxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------
void TFormaElementaXSetupObmen::OpenFormSpiskaSprInfBase(void)
{
if (FormaSpiskaSprInfBase==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
												 (void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->NumberProcVibor=1;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaXSetupObmen::InfBasePopupMenuClick(TObject *Sender)
{
__int64 i= ((TMenuItem*)Sender)->Tag;

//добавляем элемент
DM->AddBase(i, ((TMenuItem*)Sender)->Caption);

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaXSetupObmen::TypePricePopupMenuClick(TObject *Sender)
{
__int64 i= ((TMenuItem*)Sender)->Tag;

//добавляем элемент
DM->AddTypePrice(i, ((TMenuItem*)Sender)->Caption);

}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaXSetupObmen::cxButton2Click(TObject *Sender)
{
DM->DeleteBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaXSetupObmen::cxButton4Click(TObject *Sender)
{
DM->DeleteTypePrice();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaXSetupObmen::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaXSetupObmen::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента : "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaXSetupObmen::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (type_event==1)    //выбор сделан
		{
		DM->Element->Edit();
		DM->ElementIDBASE_OBMEN_XSETUP_OBMEN->AsInt64=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
		DM->ElementNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
		DM->Element->Post();

		FormaSpiskaSprInfBase=0;
		}


FindNextControl(ActiveControl,true,true,false)->SetFocus();


return -1;
}
//-----------------------------------------------------------------------------
