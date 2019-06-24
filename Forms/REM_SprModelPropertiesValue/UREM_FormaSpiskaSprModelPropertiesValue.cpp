//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaSpiskaSprModelPropertiesValue.h"
#include "IREM_FormaElementaSprModelPropertiesValue.h"


#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "IDMSprNom.h"
#include "IDMSprPropertiesNaborSostav.h"
#include "IDMSprGrpNom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprModelPropertiesValue::TREM_FormaSpiskaSprModelPropertiesValue(TComponent* Owner)
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
bool TREM_FormaSpiskaSprModelPropertiesValue::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModelPropertiesValue,IID_IREM_DMSprModelPropertiesValue,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
HintLabel->Caption="";

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprNomPropertiesValueImpl),false);
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
int TREM_FormaSpiskaSprModelPropertiesValue::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::UpdateForm(void)
{
DM->OpenTable(IdOwner);
LabelNom->Caption=HeaderText;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::FormClose(TObject *Sender,
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
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::OpenFormElement()
{
IREM_FormaElementaSprModelPropertiesValue * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprModelPropertiesValue,IID_IREM_FormaElementaSprModelPropertiesValue,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(DM->TableID_REM_SMODEL_PROPVAL->AsLargeInt);
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_Element;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::OpenFormNewElement()
{
IREM_FormaElementaSprModelPropertiesValue * FormaElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprModelPropertiesValue,IID_IREM_FormaElementaSprModelPropertiesValue,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdOwner);
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_Element;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::DeleteElement()
{
DM->DeleteElement(DM->TableID_REM_SMODEL_PROPVAL->AsLargeInt);
DM->OpenTable(IdOwner);
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
		DM->OpenElement(DM->TableID_REM_SMODEL_PROPVAL->AsLargeInt);
		TypeEvent=1;
		Close();
        }
else
        {
        OpenFormElement();
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		DM->OpenElement(DM->TableID_REM_SMODEL_PROPVAL->AsLargeInt);
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
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
						 (void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdOwner", glStrToInt64(DM->TableIDMODEL_REM_SMODEL_PROPVAL->AsString));
	module->SetInt64Variables("glIdModelPropertiesValue", glStrToInt64(DM->TableID_REM_SMODEL_PROPVAL->AsString));
	}

module->ExecuteModule();


}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprModelPropertiesValue::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)
        {
		if (type_event==1)
                {
				EndViborCopyNom();
                }
		//FormaSpiskaSprNom=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


DM->OpenTable(IdOwner);
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ToolButton4Click(TObject *Sender)

{
//получим группу номенклатуры
//__int64 id_grp_nom=0;
//IDMSprNom * dm_nom;
//InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNom,IID_IDMSprNom,
//						 (void**)&dm_nom);
//dm_nom->Init(InterfaceMainObject,InterfaceImpl);
//dm_nom->OpenElement(IdNom);
//id_grp_nom=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);
//dm_nom->kanRelease();
//
//IDMSprGrpNom * dm_grp_nom;
//InterfaceGlobalCom->kanCreateObject(ProgId_DMSprGrpNom,IID_IDMSprGrpNom,
//						 (void**)&dm_grp_nom);
//dm_grp_nom->Init(InterfaceMainObject,InterfaceImpl);
//dm_grp_nom->OpenElement(id_grp_nom);
//__int64 id_nabor=0;
//id_nabor=glStrToInt64(dm_grp_nom->ElementIDPROPNABOR_SGRPNOM->AsString);
//dm_grp_nom->kanRelease();
//
//
//IDMSprPropertiesNaborSostav * dm_sostav;
//InterfaceGlobalCom->kanCreateObject(ProgId_DMSprPropertiesNaborSostav,IID_IDMSprPropertiesNaborSostav,
//						 (void**)&dm_sostav);
//dm_sostav->Init(InterfaceMainObject,InterfaceImpl);
//dm_sostav->OpenTable(id_nabor);
//
//while (!dm_sostav->Table->Eof)
//	{
//	//сначала надо найти элемент, может там уже есть
//	__int64 id_prop=DM->GetIdPoIdNomIdProp(IdNom, glStrToInt64(dm_sostav->TableIDPROP_SPROPNABOR_SOST->AsString));
//	if (id_prop ==0)
//		{
//		DM->NewElement(IdNom);
//		DM->Element->Edit();
//		DM->ElementIDPROP_SNOMPROPVALUE->AsString=dm_sostav->TableIDPROP_SPROPNABOR_SOST->AsString;
//		DM->ElementINDEX_SNOMPROPVALUE->AsInteger=dm_sostav->TableINDEXSORT_SPROPNABOR_SOST->AsInteger;
//		DM->Element->Post();
//		DM->SaveElement();
//		}
//	dm_sostav->Table->Next();
//	}
//dm_sostav->kanRelease();
//
//UpdateForm();
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::OpenFormSpiskaSprNom(void)
{
//if (FormaSpiskaSprNom==NULL)
//		{
//		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
//													(void**)&FormaSpiskaSprNom);
//		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
//		FormaSpiskaSprNom->Vibor=true;
//		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
//		FormaSpiskaSprNom->UpdateForm();
//		}
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprModelPropertiesValue::EndViborCopyNom(void)
{

//IDMSprNomPropertiesValue * dm_properties_value;
//InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNomPropertiesValue,IID_IDMSprNomPropertiesValue,
//											 (void**)&dm_properties_value);
//dm_properties_value->Init(InterfaceMainObject,InterfaceImpl);
//
//__int64 id_nom=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
//
//dm_properties_value->OpenTable(id_nom);
//
//
//while (!dm_properties_value->Table->Eof)
//	{
//
//		DM->NewElement(IdNom);
//		DM->Element->Edit();
//		DM->ElementIDPROP_SNOMPROPVALUE->AsString=dm_properties_value->TableIDPROP_SNOMPROPVALUE->AsString;
//		DM->ElementIDPROPVALLIST_SNOMPROPVALUE->AsString=dm_properties_value->TableIDPROPVALLIST_SNOMPROPVALUE->AsString;
//		DM->ElementVALTEXT_SNOMPROPVALUE->AsString=dm_properties_value->TableVALTEXT_SNOMPROPVALUE->AsString;
//		DM->ElementINDEX_SNOMPROPVALUE->AsInteger=dm_properties_value->TableINDEX_SNOMPROPVALUE->AsInteger;
//		DM->ElementADD1_SNOMPROPVALUE->AsString=dm_properties_value->TableADD1_SNOMPROPVALUE->AsString;
//		DM->ElementADD2_SNOMPROPVALUE->AsString=dm_properties_value->TableADD2_SNOMPROPVALUE->AsString;
//		DM->ElementADD3_SNOMPROPVALUE->AsString=dm_properties_value->TableADD3_SNOMPROPVALUE->AsString;
//		DM->ElementADD4_SNOMPROPVALUE->AsString=dm_properties_value->TableADD4_SNOMPROPVALUE->AsString;
//		DM->ElementADD5_SNOMPROPVALUE->AsString=dm_properties_value->TableADD5_SNOMPROPVALUE->AsString;
//		DM->Element->Post();
//		DM->SaveElement();
//	dm_properties_value->Table->Next();
//	}
//dm_properties_value->kanRelease();
//
//UpdateForm();

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprModelPropertiesValue::ToolButtonCopyClick(TObject *Sender)

{
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------

