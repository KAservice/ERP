//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSetup.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDropDownEdit"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDropDownEdit"
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
__fastcall TFormaSpiskaSetup::TFormaSpiskaSetup(TComponent* Owner)
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
bool TFormaSpiskaSetup::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
Vibor=false;


if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
		{
		cxButtonOK->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		}


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
int TFormaSpiskaSetup::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSetup::FormClose(TObject *Sender,
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

void __fastcall TFormaSpiskaSetup::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table->Delete();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSetup::ToolButtonNewClick(TObject *Sender)
{
DM->Table->Insert();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSetup::cxGrid1DBTableView1DblClick(TObject *Sender)
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



void __fastcall TFormaSpiskaSetup::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Setup");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSetup::ActionOKExecute(TObject *Sender)
{
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSetup::ActionCloseExecute(TObject *Sender)
{
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSetup::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSetup::DeleteElement()
{


}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSetup::ToolButtonAddStandartValueClick(TObject *Sender)

{
AddValue(2,"Центральная - 1, периферийная 0","1",0, 0);
AddValue(3,"Префикс информационной базы","1",0,0);
AddValue(4,"Заполнять таблицу изменений ","1",0,0);
AddValue(5,"Заполнять таблицу изменений подсистемы Ремонт","1",0,0);
AddValue(6,"Заполнять таблицу изменений регистров","",0,0);

AddValue(12,"Запретить отрицательные остатки","",0,0);
AddValue(13,"Дата запрета редактирования","",0,0);
AddValue(14,"Не проводить документы","",0,0);
AddValue(15,"Граница последовательности док. по складу","",0,0);
AddValue(16,"Каталог обмена с 1С:Предприятие.ТиС  9.2 ","",0,0);
AddValue(17,"Каталог обмена с 1С:Предприятие.УСН.","",0,0);
AddValue(18,"Минимальное значение кода номенклатуры в тек. базе ","0",0,0);
AddValue(19,"Максим. значение кода номенклатуры в тек. базе ","100000",0,0);
AddValue(20,"Префикс неколичеств. лок. ШК в тек. базе для нов. Префикс 1 ","20",0,0);
AddValue(21,"Префикс количеств. лок. ШК в тек. базе для новых. Префикс 2. ","23",0,0);
AddValue(22,"Префиксы, использемых количественных ШК        ","",0,0);
AddValue(23,"Префикс 3.","",0,0);
AddValue(24,"Префикс 4.","",0,0);
AddValue(25,"Префикс 5.","",0,0);
AddValue(29,"Каталог КЛАДР ","",0,0);
AddValue(30,"ID типа цен приобретения ","",0,0);
AddValue(31,"ID типа цен реализации ","",0,0);
AddValue(33,"Показывать НДС","",0,0);
AddValue(35,"Web site      ","",0,0);
AddValue(40,"устанавливать флаг изменения номенклатуры  ","",0,0);
AddValue(42,"Передвигать дату запрета редактирования (кол.дней)","",0,0);
AddValue(43,"Проводить документы ранее 100 дней - 1","",0,0);
AddValue(51,"ID операции розничная продажа. Чек ККМ ","",0,0);
AddValue(52,"ID операции розничный возврат. Чек ККМ ","",0,0);
AddValue(101,"ID состояния бронирования номеров в гостинице ","",0,0);
AddValue(102,"ID состояния размещения номеров в гостинице","",0,0);
AddValue(103,"Количество брони  ","",0,0);
AddValue(104,"Граница последовательности документов (гостиница)","",0,0);
AddValue(105,"Дата запрета редактирования (гостиница)","",0,0);
AddValue(201,"Макс. значение кода номенклатуры      ","100000",0,0);
AddValue(202,"Макс. значение кода едининицы номенклатуры ","100000",0,0);
AddValue(203,"Макс. значение кода дисконтной карты ","100000",0,0);
AddValue(313,"Дата запрета редактирования подсистемы Ремонт","",0,0);
AddValue(314,"Не проводить документы ","",0,0);
AddValue(315,"Граница последовательности подсистемы Ремонт ","",0,0);
AddValue(320,"Состояние отремонтировано ","",0,0);
AddValue(321,"Выдача без ремонта      ","",0,0);
AddValue(322,"Выдано владельцу (отремонтировано)","",0,0);
AddValue(323,"Выдано владельцу (без ремонта)","",0,0);
AddValue(330,"Каталог с гаратийными талонами.","",0,0);
AddValue(331,"Каталог Приемка            ","",0,0);
AddValue(335,"Код сервисного центра Fly","",0,0);
AddValue(336,"Имя инженера Fly","",0,0);
AddValue(343,"Проводить документы ранее 100 дней","",0,0);
AddValue(401,"Каталог с программами","",0,0);
AddValue(402,"Каталог с изображениями отказов","",0,0);
}
//---------------------------------------------------------------------------
void TFormaSpiskaSetup::AddValue(__int64 id,UnicodeString descr,UnicodeString str_value,int type_value, TDateTime dt_value)
{

DM->OpenElement(id);
if (DM->Element->RecordCount==0)
	{
	DM->Table->Append();
	DM->TableID_SETUP->AsString=IntToStr(id);
	DM->TableDESCRIPTION_SETUP->AsString=descr;
	DM->TableVALUE_SETUP->AsString=str_value;
	DM->TableTYPE_VALUE_SETUP->AsInteger=type_value;
	if (dt_value > StrToDateTime("01.01.2000 00:00:00"))
		{
		DM->TableVALUE_TIMESTAMP_SETUP->AsDateTime=dt_value;
		}
	DM->Table->Post();
	}

}
//------------------------------------------------------------------------------
