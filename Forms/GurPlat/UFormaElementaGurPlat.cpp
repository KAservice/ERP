//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaGurPlat.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxDBLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaGurPlat::TFormaElementaGurPlat(TComponent* Owner)
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
bool TFormaElementaGurPlat::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMGurPlat,IID_IDMGurPlat, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeOpercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NumKvcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeTelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NumTelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SumcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
ProcentcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
SummKlientcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
NameUsercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
OutcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

NameCodeTelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeOperatorcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;

 //ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaElementaGurPlat::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaGurPlat::UpdateForm(void)
{
      

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaGurPlat::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokCodeTel)SpisokCodeTel->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
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
int TFormaElementaGurPlat::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ViborKlient)
		{
		if (type_event==1)
				{
				DM->Element->Edit();
				DM->ElementIDKLIENT_GURNALPLAT->AsString=SpisokKlient->DM->TableIDKLIENT->AsString;
				DM->ElementNAMEKLIENT->AsString=SpisokKlient->DM->TableNAMEKLIENT->AsString;
				DM->Element->Post();
                }
		SpisokKlient=0;
		}

if (number_procedure_end==ViborCodeTel)
		{
		if (type_event==1)
				{
				DM->Element->Edit();
				DM->ElementIDCODETEL_GURNALPLAT->AsString=SpisokCodeTel->DM->TableID_CODETEL->AsString;
				DM->ElementNAME_CODETEL->AsString=SpisokCodeTel->DM->TableNAME_CODETEL->AsString;
				DM->ElementCODOPER_GURNALPLAT->AsString=SpisokCodeTel->DM->TableCODOPER_CODETEL->AsString;
				DM->Element->Post();
				}
		SpisokCodeTel=0;
		}


EditRekvisit=NO;
return -1;

}

//--------------------------------------------------------------------------
void TFormaElementaGurPlat::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;

if (SpisokKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->ElementIDKLIENT_GURNALPLAT->AsString);
		SpisokKlient->NumberProcVibor=ViborKlient;
		}
}

//--------------------------------------------------------------------------




void __fastcall TFormaElementaGurPlat::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurPlat::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("GurPlat");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurPlat::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaGurPlat::ActionOKExecute(TObject *Sender)
{
DM->SaveElement();
Close();
}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------
void TFormaElementaGurPlat::OpenFormSpiskaSprCodeTel(void)
{
if (Prosmotr==true) return;

if (SpisokCodeTel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprCodeTel,IID_IFormaSpiskaSprCodeTel,
													(void**)&SpisokCodeTel);
		SpisokCodeTel->Init(InterfaceMainObject,InterfaceImpl);
		SpisokCodeTel->Vibor=true;
		SpisokCodeTel->NumberProcVibor=ViborCodeTel;
		}
}

//--------------------------------------------------------------------------
void __fastcall TFormaElementaGurPlat::NameCodeTelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprCodeTel();
}
//---------------------------------------------------------------------------

