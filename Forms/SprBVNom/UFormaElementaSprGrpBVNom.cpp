//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprGrpBVNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprGrpBVNom::TFormaElementaSprGrpBVNom(TComponent* Owner)
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
bool TFormaElementaSprGrpBVNom::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpBVNom.1",IID_IDMSprGrpBVNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprGrpBVNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprGrpBVNom::FormClose(TObject *Sender,
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
void __fastcall TFormaElementaSprGrpBVNom::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("SprBVNom");	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprGrpBVNom::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpBVNom::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpBVNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaElementaSprGrpBVNom::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{


return -1;
}
