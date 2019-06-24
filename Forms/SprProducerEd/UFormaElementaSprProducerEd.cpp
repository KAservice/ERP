//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprProducerEd.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprProducerEd::TFormaElementaSprProducerEd(TComponent* Owner)
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
bool TFormaElementaSprProducerEd::Init(void)
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

//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerEd,IID_IDMSprProducerEd, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameEdcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KFEdcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
SHcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


flObrabatChangeTypeSH=false;
flObrabatChangeNeIsp=false;


SaveElement=false;


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
int TFormaElementaSprProducerEd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprProducerEd::UpdateForm(void)
{
flObrabatChangeTypeSH=false;
flObrabatChangeNeIsp=false;
flObrabatChangeTypeSH=true;
flObrabatChangeNeIsp=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerEd::FormClose(TObject *Sender,
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
void __fastcall TFormaElementaSprProducerEd::FormActivate(TObject *Sender)
{

//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducerEd::FormDeactivate(TObject *Sender)
{
//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
//������� ���������� �����-����
void __fastcall TFormaElementaSprProducerEd::ReadShtrihCodEvent(int number, UnicodeString sh)
{

AnsiString s=glDelSymbolOfBarCode(sh);


        String V="�� ������ ������������ ����� ���?";
        String Z="����� ��� ��� �����";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Element->Edit();
DM->ElementBARCODE_SPRED->AsString=Trim(s).SetLength(13);
DM->Element->Post();
}
//----------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducerEd::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprProducerEd");
}
//---------------------------------------------------------------------------







void __fastcall TFormaElementaSprProducerEd::NameEdcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerEd::KFEdcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerEd::SHcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerEd::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//-----------------------------------------------------------------------------




void __fastcall TFormaElementaSprProducerEd::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducerEd::ActionOKExecute(TObject *Sender)
{

if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		SaveElement=true;

		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprProducerEd::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{



FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
