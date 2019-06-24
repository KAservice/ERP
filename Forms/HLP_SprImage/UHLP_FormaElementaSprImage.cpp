//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UHLP_FormaElementaSprImage.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxDBRichEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxImage"
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THLP_FormaElementaSprImage::THLP_FormaElementaSprImage(TComponent* Owner)
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
bool THLP_FormaElementaSprImage::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprImage,IID_IHLP_DMSprImage,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

GuidcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ImagecxDBImage->DataBinding->DataSource=DM->DataSourceElement;


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
int THLP_FormaElementaSprImage::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THLP_FormaElementaSprImage::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaElementaSprImage::FormClose(TObject *Sender,
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





void __fastcall THLP_FormaElementaSprImage::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaElementaSprImage::ActionOKExecute(TObject *Sender)
{

if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();

		}
else
	{
	ShowMessage("������ ��� ������ �������� �����������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int THLP_FormaElementaSprImage::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{




FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------




