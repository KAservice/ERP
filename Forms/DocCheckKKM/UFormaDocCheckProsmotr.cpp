//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop 

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "UFormaDocCheckProsmotr.h"
#include "IDMSprTypePrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//-----------------------------------------------------------------------------
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
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxDropDownEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
//---------------------------------------------------------------------------
__fastcall TFormaDocCheckProsmotr::TFormaDocCheckProsmotr(TComponent* Owner)
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
bool TFormaDocCheckProsmotr::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

SumDocDBText->DataSource=DM->DataSourceDocAll;
IdKlientDBText->DataSource=DM->DataSourceDocAll;
NameBaseDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameFirmcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSDogovorcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKKMcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NKlcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NCheckcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplNalcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplPCcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaDocCheckProsmotr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocCheckProsmotr::UpdateForm(void)
{
LabelDateDoc->Caption=DateToStr(DM->DocAllPOSDOC->AsDateTime);

IDMSprTypePrice *DMSprTypePrice;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

DMSprTypePrice->OpenElement(glStrToInt64(DM->DocIDTPRICE->AsString));
NamePriceLabel->Caption=DMSprTypePrice->ElementNAME_TPRICE->AsString;
DMSprTypePrice->kanRelease();

Operation->ItemIndex=DM->DocOPERCHK->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheckProsmotr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaDocCheckProsmotr::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------



void __fastcall TFormaDocCheckProsmotr::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

