//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMStSpr1.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMStSpr1::TDMStSpr1(TComponent* Owner)
	: TDataModule(Owner)
{

FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
bool TDMStSpr1::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;



Table->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMStSpr1::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMStSpr1::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
bool TDMStSpr1::CreateObject(UnicodeString name_object)
{
bool result=true;

//получить информацию об объекте, создать объект
TkasObjectInfoBuilder *b=new TkasObjectInfoBuilder ();
TkasObjectInfo * ob_info;

ob_info=b->GetObjectInfo(name_object);
if (b->Error==false)
	{
	//ShowObjectInfo(ob_info);
	UpdateParameterForm(ob_info);
	}
else
	{
    ShowMessage(b->TextError);
	}


delete b;
delete ob_info;
return result;
}
//---------------------------------------------------------------------------
bool TDMStSpr1::OpenTable(void)
{
bool result=false;
try
        {
		Table->Active=false;
		Table->Open();
		result=true;
        }
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}

//---------------------------------------------------------------------------
void TDMStSpr1::UpdateParameterForm(TkasObjectInfo * ob)
{
//TFIBfWideStringField * field;
TFieldDef * field_def;



UnicodeString name_object=ob->NameObject;
UnicodeString type_object=ob->TypeObject;
//ShowMessage ("Новый объект - "+name_object+" тип - "+type_object);
//здесь надо создавать объект

if(type_object == "TDMStSpr1")
	{
	//ничего не делаем, форма уже создана
	}

if(type_object == "TFIBWideStringField")
	{ //создаем поле
	field_def=Table->FieldDefs->AddFieldDef();;
	}

if (ob->ListProperties->Count > 0)
	{
	for (int i=0;i < ob->ListProperties->Count;i++)
		{
		TkasObjectInfoProperties * pr=(TkasObjectInfoProperties*) ob->ListProperties->Items[i];
		UnicodeString name_parameter=pr->NameParameter;
		UnicodeString value_parameter=pr->ValueParameter;
//		ShowMessage ("Свойство - "+name_parameter+"\n значение - "+value_parameter);


		//настройки формы, просто применяем параметры
		if(type_object == "TDMStSpr1")
			{
			if (name_parameter == "SelectSQL")
				{
				Table->Active=false;
				Table->SelectSQL->Clear();
				Table->SelectSQL->Add(value_parameter);
				}
			}


		if(type_object == "TFIBWideStringField")
			{
			if (name_parameter == "FieldName")
				{
				field_def->Name=value_parameter;
				}
			if (name_parameter == "Size")
				{
				field_def->Size=StrToInt(value_parameter);
				}

			}

		}

	}


if (ob->ListObject->Count > 0)
	{
	for (int i=0;i < ob->ListObject->Count;i++)
		{
		UpdateParameterForm((TkasObjectInfo*) ob->ListObject->Items[i]);
		}

	}
}
//----------------------------------------------------------------------------
