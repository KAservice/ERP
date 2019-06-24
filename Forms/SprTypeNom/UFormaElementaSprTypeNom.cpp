//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFormaElementaSprTypeNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprTypeNom::TFormaElementaSprTypeNom(TComponent* Owner)
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
bool TFormaElementaSprTypeNom::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprTypeNom,IID_IDMSprTypeNom,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

SaveElement=false;

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaElementaSprTypeNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprTypeNom::FormClose(TObject *Sender,
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
void TFormaElementaSprTypeNom::UpdateForm(void)
{
///


}
//---------------------------------------------------------------------------
int TFormaElementaSprTypeNom::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if ( number_procedure_end==EditKomplModel)
	{
	if (type_event==1)
		{

		}
	//REM_FormaSpiskaSprKomplModel=0;
	}

if ( number_procedure_end==VR_Nom)
	{
	if (type_event==1)
		{

		}
	//FormaSpiskaSprNom=0;
	}

if ( number_procedure_end==VR_ModelDetal)
	{
	if (type_event==1)
		{

		}
	//REM_FormaSpiskaSprModelDetal=0;
	}

if ( number_procedure_end==VR_NeisprModel)
	{
	if (type_event==1)
		{

		}
	//REM_FormaSpiskaSprNeisprModel=0;
	}




return -1;
}
//-----------------------------------------------------------------------------



void __fastcall TFormaElementaSprTypeNom::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("REM_SprModel");
}
//---------------------------------------------------------------------------








void __fastcall TFormaElementaSprTypeNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprTypeNom::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprTypeNom::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		SaveElement=true;
		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------






