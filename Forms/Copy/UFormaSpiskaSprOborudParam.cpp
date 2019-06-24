//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprOborudParam.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IkasDMDataSet.h"
#include "IDMSprOborud.h"
#include "IFiskReg.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprOborudParam::TFormaSpiskaSprOborudParam(TComponent* Owner)
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
bool TFormaSpiskaSprOborudParam::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborudParam,IID_IkasDMSpr, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

IkasDMDataSet *i_ds=0;
DM->kanQueryInterface(IID_IkasDMDataSet,(void**) &i_ds);
cxGrid1DBTableView1->DataController->DataSource=i_ds->kanGetDataSource(0);
//DM->OpenTable(IdNom);
Vibor=false;

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
int TFormaSpiskaSprOborudParam::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOborudParam::FormClose(TObject *Sender,
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
void TFormaSpiskaSprOborudParam::UpdateForm(void)
{

//LabelHeader->Caption=TextHeader;
DM->IdOwner=IdOwner;
DM->OpenTable(0);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprOborudParam::ToolButtonNewClick(TObject *Sender)
{
DM->IdOwner=IdOwner;
DM->AppendString();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ToolButtonDeleteClick(TObject *Sender)
{
DM->IdOwner=IdOwner;
DM->DeleteString();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprOborudParam::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprOborudParam::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ActionCloseExecute(TObject *Sender)
{
DM->CancelChanges();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ActionOKExecute(TObject *Sender)
{
DM->SaveChanges();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprOborudParam::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ToolButtonGetParameterIsFiskRegSaveInFileClick(TObject *Sender)

{
IDMSprOborud * dm_oborud;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud, (void**)&dm_oborud);
dm_oborud->Init(InterfaceMainObject,InterfaceImpl);

dm_oborud->OpenElement(IdOwner);

IFiskReg *fr;
AnsiString prog_id=dm_oborud->ElementPROGID_SOBORUD->AsString;
InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
fr->Modul=dm_oborud->ElementMODUL_SOBORUD->AsString;
fr->Init(InterfaceMainObject,InterfaceImpl);

UnicodeString param_str="";
param_str=fr->GetParameters();

ShowMessage(param_str);


TStringList * list=new TStringList();
list->Text=param_str;
if (SaveTextFileDialog1->Execute())
	{
		list->SaveToFile(SaveTextFileDialog1->FileName);
	}

delete list;

fr->Done();
fr->kanRelease();
dm_oborud->kanRelease();


}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ToolButtonSaveInFileDopActionClick(TObject *Sender)

{
IDMSprOborud * dm_oborud;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud, (void**)&dm_oborud);
dm_oborud->Init(InterfaceMainObject,InterfaceImpl);

dm_oborud->OpenElement(IdOwner);

IFiskReg *fr;
AnsiString prog_id=dm_oborud->ElementPROGID_SOBORUD->AsString;
InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
fr->Modul=dm_oborud->ElementMODUL_SOBORUD->AsString;
fr->Init(InterfaceMainObject,InterfaceImpl);

UnicodeString param_str="";
param_str=fr->GetAdditionalActions();

ShowMessage(param_str);

TStringList * list=new TStringList();
list->Text=param_str;
if (SaveTextFileDialog1->Execute())
    {
		list->SaveToFile(SaveTextFileDialog1->FileName);
	}

delete list;

fr->kanRelease();
dm_oborud->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprOborudParam::ToolButtonGetSpisokMetodClick(TObject *Sender)

{


IDMSprOborud * dm_oborud;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborud,IID_IDMSprOborud, (void**)&dm_oborud);
dm_oborud->Init(InterfaceMainObject,InterfaceImpl);

dm_oborud->OpenElement(IdOwner);

IFiskReg *fr;
AnsiString prog_id=dm_oborud->ElementPROGID_SOBORUD->AsString;
InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
fr->Modul=dm_oborud->ElementMODUL_SOBORUD->AsString;
fr->Init(InterfaceMainObject,InterfaceImpl);

TStringList *l = new TStringList;
l->Text=fr->GetMetodsList();

ShowMessage(l->Text);
if (SaveTextFileDialog1->Execute())
	{
	l->SaveToFile(SaveTextFileDialog1->FileName);
	}
delete l;

fr->Done();
fr->kanRelease();
dm_oborud->kanRelease();





}
//---------------------------------------------------------------------------

