//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaStSpr1.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaStSpr1::TFormaSpiskaStSpr1(TComponent* Owner)
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

bool TFormaSpiskaStSpr1::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

Vibor=false;


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaStSpr1::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaStSpr1::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//������� ICallBack ��� �������� ������� � ���������� �����
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
//DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//--------------------------------------------------------------------------



void __fastcall TFormaSpiskaStSpr1::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaStSpr1::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//-----------------------------------------------------------------------------
bool TFormaSpiskaStSpr1::CreateObject(UnicodeString name_object)
{
bool result=true;

//�������� ���������� �� �������, ������� ������
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

//�������� DataModule

InterfaceGlobalCom->kanCreateObject(ProgId_DMStSpr1,IID_IDMStSpr1,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
DM->CreateObject("DMSprSklad");
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
DM->OpenTable();

return result;
}
//----------------------------------------------------------------------------
void TFormaSpiskaStSpr1::ShowObjectInfo(TkasObjectInfo * ob)
{

UnicodeString name_object=ob->NameObject;
UnicodeString type_object=ob->TypeObject;

ShowMessage ("����� ������ - "+name_object+" ��� - "+type_object);

if (ob->ListProperties->Count > 0)
	{
	for (int i=0;i < ob->ListProperties->Count;i++)
		{
		TkasObjectInfoProperties * pr=(TkasObjectInfoProperties*) ob->ListProperties->Items[i];
		UnicodeString name_parameter=pr->NameParameter;
		UnicodeString value_parameter=pr->ValueParameter;
		ShowMessage ("�������� - "+name_parameter+"\n �������� - "+value_parameter);
		}

	}



ShowMessage ("���������� ��������� �������� "+IntToStr(ob->ListObject->Count));

if (ob->ListObject->Count > 0)
	{
	for (int i=0;i < ob->ListObject->Count;i++)
		{
		ShowObjectInfo((TkasObjectInfo*) ob->ListObject->Items[i]);
		}

	}


}
//----------------------------------------------------------------------------
void TFormaSpiskaStSpr1::UpdateParameterForm(TkasObjectInfo * ob)
{
TcxGridDBColumn * �olumn;




UnicodeString name_object=ob->NameObject;
UnicodeString type_object=ob->TypeObject;
//ShowMessage ("����� ������ - "+name_object+" ��� - "+type_object);
//����� ���� ��������� ������

if(type_object == "TFormaSpiskaStSpr1")
	{
	//������ �� ������, ����� ��� �������
	}

if(type_object == "TcxGridDBColumn")
	{
	//������� ����� ������� � ��������� �����
	�olumn = cxGrid1DBTableView1->CreateColumn();
	}

if (ob->ListProperties->Count > 0)
	{
	for (int i=0;i < ob->ListProperties->Count;i++)
		{
		TkasObjectInfoProperties * pr=(TkasObjectInfoProperties*) ob->ListProperties->Items[i];
		UnicodeString name_parameter=pr->NameParameter;
		UnicodeString value_parameter=pr->ValueParameter;
//		ShowMessage ("�������� - "+name_parameter+"\n �������� - "+value_parameter);


		//��������� �����, ������ ��������� ���������
		if(type_object == "TFormaSpiskaStSpr1")
			{
			if (name_parameter== "Caption")
				{
				Caption=value_parameter;
				}

			if (name_parameter== "HintLabel")
				{
				HintLabel->Caption=value_parameter;
				}
			}

		//��������� �������� ��������� �����
		if(type_object == "TcxGridDBColumn")
			{
			if (name_parameter == "Caption")
				{
				�olumn->Caption=value_parameter;
				}

			if (name_parameter == "FieldName")
				{
				�olumn->DataBinding->FieldName=value_parameter;
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




