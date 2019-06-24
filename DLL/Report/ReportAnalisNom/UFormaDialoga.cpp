//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDialoga.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxGraphics"
#pragma link "cxLookupEdit"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialoga::TFormaDialoga(TComponent* Owner)
	: TForm(Owner)
{

FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
bool TFormaDialoga::Init(void)
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


//������������ DataBase

pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;
SpisokGrpNom->Database=DM_Connection->pFIBData;


//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;





PosNachcxDateEdit->Date=Date()-DayOf(Date())+1;
PosConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);


UpdateForm();

return result;
}

//---------------------------------------------------------------------------
int TFormaDialoga::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialoga::FormClose(TObject *Sender, TCloseAction &Action)
{
SpisokGrpNom->Active=false;
if(FormaReport)FormaReport->Close();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaDialoga::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{



return -1;
}
//-----------------------------------------------------------------------------
void TFormaDialoga::UpdateForm(void)
{
SpisokGrpNom->Active=true;


}
//-----------------------------------------------------------------------------
void __fastcall TFormaDialoga::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialoga::cxButtonRunClick(TObject *Sender)
{
if (FormaReport==0)
	{
	SpisokGrpNom->First();
	SpisokGrpNom->MoveBy(cxLookupComboBox1->ItemIndex);

	FormaReport=new TFormaReport(Application);

	FormaReport->PosNach=PosNachcxDateEdit->Date;
	FormaReport->PosCon=PosConcxDateEdit->Date;
	FormaReport->IdGrp=StrToInt64(SpisokGrpNomIDGN->AsString);
	FormaReport->NameGrp=SpisokGrpNomNAMEGN->AsString;
	FormaReport->FOnCloseForm=EventCloseFormReport;

    //Database
	FormaReport->ReportDataSet->Database=DM_Connection->pFIBData;
	FormaReport->pFIBTransaction1->DefaultDatabase=DM_Connection->pFIBData;

    FormaReport->DM_Connection=DM_Connection;

	FormaReport->UpdateForm();
	FormaReport->Show();
	}
//ShowMessage(SpisokGrpNomIDGN->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialoga::EventCloseFormReport(TObject *Sender)
{

FormaReport=0;

}
//----------------------------------------------------------------------------




