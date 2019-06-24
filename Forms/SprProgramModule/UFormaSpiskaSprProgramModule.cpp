//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprProgramModule.h"
#include "IFormaElementaSprProgramModule.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMQueryUpdate.h"
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
#pragma link "cxCheckBox"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxStyles"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprProgramModule::TFormaSpiskaSprProgramModule(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
HintLabel->Caption="";
}
//---------------------------------------------------------------------------

bool TFormaSpiskaSprProgramModule::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProgramModule,IID_IDMSprProgramModule, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();
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
int TFormaSpiskaSprProgramModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprProgramModule::FormClose(TObject *Sender,
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

//--------------------------------------------------------------------------
void TFormaSpiskaSprProgramModule::OpenFormElement()
{
IFormaElementaSprProgramModule * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprProgramModule,IID_IFormaElementaSprProgramModule,
																					(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_PROGRAM_MODULE->AsString));
FormaElementa->UpdateForm();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprProgramModule::OpenFormNewElement()
{
IFormaElementaSprProgramModule * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprProgramModule,IID_IFormaElementaSprProgramModule,
																					(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement();
FormaElementa->UpdateForm();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprProgramModule::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_PROGRAM_MODULE->AsString));
DM->OpenTable();
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprProgramModule::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprProgramModule::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprProgramModule::ToolButtonDeleteClick(
      TObject *Sender)
{
DeleteElement();        
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprProgramModule::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_PROGRAM_MODULE->AsString));
		TypeEvent=1;
		Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprProgramModule::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
		DM->OpenElement(glStrToInt64(DM->TableID_PROGRAM_MODULE->AsString));
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

void __fastcall TFormaSpiskaSprProgramModule::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprProgramModule::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable();
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprProgramModule::ToolButtonAddAllProgramModuleClick(TObject *Sender)

{
TStringList * list=new TStringList;
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
list->LoadFromFile(ProgramCatalog+"\\kanGUID.dat");

IDMSprProgramModule * dm_spr;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProgramModule,IID_IDMSprProgramModule, (void**)&dm_spr);
dm_spr->Init(InterfaceMainObject,InterfaceImpl);

for (int i=0; i<list->Count;i++)
		{
		AnsiString str=Trim(list->Strings[i]);
		AnsiString guid=Trim(str.SubString(1,40));
		AnsiString prog_id_file=Trim(str.SubString(41,40));
		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
		GUID g=StringToGUID(Trim(guid));
		//добавляем элемент
		__int64 id=dm_spr->GetIdModuleFromGUID(g);
		if (id==0)
			{
			dm_spr->NewElement();
			dm_spr->Element->Edit();
            dm_spr->ElementNAME_PROGRAM_MODULE->AsString=Trim(prog_id_file);
			dm_spr->ElementGUID_PROGRAM_MODULE->AsString=GUIDToString(g);
			dm_spr->ElementPROGID_PROGRAM_MODULE->AsString=Trim(prog_id_file);
			dm_spr->ElementMODULE_PROGRAM_MODULE->AsString=Trim(modul);
            dm_spr->Element->Post();
			dm_spr->SaveElement();
			}
		}

dm_spr->kanRelease();
delete list;

DM->OpenTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprProgramModule::ToolButtonClearSprClick(TObject *Sender)

{
		UnicodeString V="Вы действительно хотите удалить все модули из списка?" ;
		UnicodeString Z="Подтверждение удаления ";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
				return;
				}

IDMQueryUpdate * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate,
													(void**)&q);
q->Init(InterfaceMainObject,InterfaceImpl);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add(" delete from program_module");

try
	{
	q->pFIBQ->ExecQuery();
	q->pFIBTr->Commit();
	}
catch(Exception &exception)
	{
	q->pFIBTr->Rollback();
	ShowMessage("Ошибка при удалении "+exception.Message);
	}


q->kanRelease();

DM->OpenTable();
}
//---------------------------------------------------------------------------

