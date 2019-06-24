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
int TFormaSpiskaSetup::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSetup::FormClose(TObject *Sender,
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
int TFormaSpiskaSetup::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
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
AddValue(2,"����������� - 1, ������������ 0","1",0, 0);
AddValue(3,"������� �������������� ����","1",0,0);
AddValue(4,"��������� ������� ��������� ","1",0,0);
AddValue(5,"��������� ������� ��������� ���������� ������","1",0,0);
AddValue(6,"��������� ������� ��������� ���������","",0,0);

AddValue(12,"��������� ������������� �������","",0,0);
AddValue(13,"���� ������� ��������������","",0,0);
AddValue(14,"�� ��������� ���������","",0,0);
AddValue(15,"������� ������������������ ���. �� ������","",0,0);
AddValue(16,"������� ������ � 1�:�����������.���  9.2 ","",0,0);
AddValue(17,"������� ������ � 1�:�����������.���.","",0,0);
AddValue(18,"����������� �������� ���� ������������ � ���. ���� ","0",0,0);
AddValue(19,"������. �������� ���� ������������ � ���. ���� ","100000",0,0);
AddValue(20,"������� �����������. ���. �� � ���. ���� ��� ���. ������� 1 ","20",0,0);
AddValue(21,"������� ���������. ���. �� � ���. ���� ��� �����. ������� 2. ","23",0,0);
AddValue(22,"��������, ����������� �������������� ��        ","",0,0);
AddValue(23,"������� 3.","",0,0);
AddValue(24,"������� 4.","",0,0);
AddValue(25,"������� 5.","",0,0);
AddValue(29,"������� ����� ","",0,0);
AddValue(30,"ID ���� ��� ������������ ","",0,0);
AddValue(31,"ID ���� ��� ���������� ","",0,0);
AddValue(33,"���������� ���","",0,0);
AddValue(35,"Web site      ","",0,0);
AddValue(40,"������������� ���� ��������� ������������  ","",0,0);
AddValue(42,"����������� ���� ������� �������������� (���.����)","",0,0);
AddValue(43,"��������� ��������� ����� 100 ���� - 1","",0,0);
AddValue(51,"ID �������� ��������� �������. ��� ��� ","",0,0);
AddValue(52,"ID �������� ��������� �������. ��� ��� ","",0,0);
AddValue(101,"ID ��������� ������������ ������� � ��������� ","",0,0);
AddValue(102,"ID ��������� ���������� ������� � ���������","",0,0);
AddValue(103,"���������� �����  ","",0,0);
AddValue(104,"������� ������������������ ���������� (���������)","",0,0);
AddValue(105,"���� ������� �������������� (���������)","",0,0);
AddValue(201,"����. �������� ���� ������������      ","100000",0,0);
AddValue(202,"����. �������� ���� ��������� ������������ ","100000",0,0);
AddValue(203,"����. �������� ���� ���������� ����� ","100000",0,0);
AddValue(313,"���� ������� �������������� ���������� ������","",0,0);
AddValue(314,"�� ��������� ��������� ","",0,0);
AddValue(315,"������� ������������������ ���������� ������ ","",0,0);
AddValue(320,"��������� ��������������� ","",0,0);
AddValue(321,"������ ��� �������      ","",0,0);
AddValue(322,"������ ��������� (���������������)","",0,0);
AddValue(323,"������ ��������� (��� �������)","",0,0);
AddValue(330,"������� � ����������� ��������.","",0,0);
AddValue(331,"������� �������            ","",0,0);
AddValue(335,"��� ���������� ������ Fly","",0,0);
AddValue(336,"��� �������� Fly","",0,0);
AddValue(343,"��������� ��������� ����� 100 ����","",0,0);
AddValue(401,"������� � �����������","",0,0);
AddValue(402,"������� � ������������� �������","",0,0);
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
