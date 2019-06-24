//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprKlientDopUrL.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprKlientDopUrL::TFormaElementaSprKlientDopUrL(TComponent* Owner)
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
bool TFormaElementaSprKlientDopUrL::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprKlientDopUrL.1",IID_IDMSprKlientDopUrL, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------
int TFormaElementaSprKlientDopUrL::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprKlientDopUrL::UpdateForm(void)
{
if (DM->OpenElement()==0)
        {
		DM->NewElement();
        DM->ElementNAMEKLIENT->AsString=NameKlient;  
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientDopUrL::FormClose(TObject *Sender,
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


void __fastcall TFormaElementaSprKlientDopUrL::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("SprKlientDopUrL");
}
//---------------------------------------------------------------------------




void __fastcall TFormaElementaSprKlientDopUrL::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprKlientDopUrL::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprKlientDopUrL::ActionSaveExecute(TObject *Sender)

{
if (DM->SaveElement()==true)
		{
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprKlientDopUrL::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
return -1;
}
//-----------------------------------------------------------------------------
