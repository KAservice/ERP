//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaUnReport.h"
#include "IkasDMDataSet.h"
#include "UGlobalConstant.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaUnReport::TFormaUnReport(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;

InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaUnReport::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
bool TFormaUnReport::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_DMRepDataSet,IID_IkasDM,(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaUnReport::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
//из этой формы открыта другая для выбора
//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
int TFormaUnReport::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}

//----------------------------------------------------------------------


//IkasForm
void TFormaUnReport::UpdateForm(void)
{
IkasDMDataSet * dm_ds=0;
DM->kanQueryInterface(IID_IkasDMDataSet,(void**) &dm_ds);
cxGrid1DBTableView1->DataController->DataSource=dm_ds->kanGetDataSource(1);
DM->SetParameterAsInt64 (IdHw, "PARAM_IDHW", 1);
DM->OpenDataSet(0);
CreateColumn();

LabelHeader->Caption=NameHardware;
}
//---------------------------------------------------------------------------
void TFormaUnReport::CreateColumn(void)
{
//cxGrid1DBTableView1->DataController->CreateAllItems();
//    OUT_IDZ DOMAIN_FK_KEY,
//	OUT_IDDOC DOMAIN_FK_KEY,
//    OUT_TDOC DOMAIN_TYPE_DOC,
//    OUT_FL_REAL DOMAIN_BOOL,
//    OUT_FL_OTCH DOMAIN_BOOL,
//    OUT_POS DOMAIN_POS,
//    OUT_KOL DOMAIN_KOL,
//    OUT_DESCR DOMAIN_DESCR,
//	OUT_IDUSER DOMAIN_FK_KEY,
//	OUT_NAME_USER DOMAIN_NAME,
//    OUT_Z_PREFIKS_NUM DOMAIN_PREFIKS_DOC,
//    OUT_Z_NUM DOMAIN_NUMBER_DOC,
//    OUT_Z_POS DOMAIN_POS,
//    OUT_Z_MODEL DOMAIN_SYMBOL_40,
//    OUT_Z_SERNUM DOMAIN_SERNUMBER,
//    OUT_Z_SERNUM2 DOMAIN_SERNUMBER,
//	OUT_Z_IDTYPE_REMONT DOMAIN_FK_KEY,
//	OUT_Z_NAME_TYPE_REMONT DOMAIN_NAME,
//	OUT_Z_KLIENT_NAME DOMAIN_NAME,
//	OUT_IDTYPE_USEL DOMAIN_FK_KEY,
//	OUT_NAME_TYPE_USEL DOMAIN_NAME
//
//
TcxGridDBColumn * column;
column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_POS";
column->Caption = "Дата ";
column->Width=50;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_FL_REAL";
column->Caption = "Реально";
column->Width=20;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_FL_OTCH";
column->Caption = "Отчитано";
column->Width=20;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_TDOC";
column->Caption = "Документ";
column->Width=50;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_NAME_TYPE_USEL";
column->Caption = "Тип. узел";
column->Width=50;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_DESCR";
column->Caption = "Описание";
column->Width=100;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_NAME_TYPE_REMONT";
column->Caption = "Тип. ремонта";
column->Width=50;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_PREFIKS_NUM";
column->Caption = "Пр";
column->Width=20;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_NUM";
column->Caption = "Номер";
column->Width=20;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_POS";
column->Caption = "Дата заявки";
column->Width=30;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_MODEL";
column->Caption = "Модель";
column->Width=30;

column=cxGrid1DBTableView1->CreateColumn();
column->DataBinding->FieldName = "OUT_Z_SERNUM";
column->Caption = "№";
column->Width=50;

}
//---------------------------------------------------------------------------