//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprSezKFSProd.h"
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
__fastcall TFormaSpiskaSprSezKFSProd::TFormaSpiskaSprSezKFSProd(TComponent* Owner)
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
bool TFormaSpiskaSprSezKFSProd::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSezKFSProd.1",IID_IDMSprSezKFSProd, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
DBGrid1->DataSource=DM->DataSourceTable;
//DM->OpenTable(IdNom);
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
int TFormaSpiskaSprSezKFSProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprSezKFSProd::FormClose(TObject *Sender,
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
void __fastcall TFormaSpiskaSprSezKFSProd::DBGrid1DblClick(TObject *Sender)
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
void __fastcall TFormaSpiskaSprSezKFSProd::ToolButtonNewClick(TObject *Sender)
{
DM->NewElement(IdSProd);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSezKFSProd::ToolButtonDeleteClick(TObject *Sender)
{
DM->DeleteElement();
}
//---------------------------------------------------------------------------





void __fastcall TFormaSpiskaSprSezKFSProd::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprSezKFSProd::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprSezKFSProd::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprSezKFSProd::DeleteElement()
{


}
//--------------------------------------------------------------------------
