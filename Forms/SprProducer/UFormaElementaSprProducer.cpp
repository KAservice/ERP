//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprProducer.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxMaskEdit"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaElementaSprProducer::TFormaElementaSprProducer(TComponent* Owner)
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

bool TFormaElementaSprProducer::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
IdDBText->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
PostZipcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

PosZagrNomcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

TypePoiskcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
UslNameInetCatalogcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
UslNameGrpInetcatalogcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprProducer::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducer::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();


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
void __fastcall TFormaElementaSprProducer::ActionOpenHelpExecute(
      TObject *Sender)
{
//
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprProducer::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducer::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprProducer::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaElementaSprProducer::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EndViborKlient();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Post_ZIP)
		{
		if (type_event==1)
				{
				EndViborPostZIP();
				}
		FormaSpiskaSprKlient=0;
		}


if(number_procedure_end==ER_ViborInetCatalog)
		{
        if (type_event==1)
				{
				DM->Element->Edit();
				DM->ElementIDINETCAT_USL_SPRODUCER->AsString=SpisokInetCatalog->DM->TableID_SINETCATALOG->AsString;
				DM->ElementNAME_SINETCATALOG->AsString=SpisokInetCatalog->DM->TableNAME_SINETCATALOG->AsString;
				DM->Element->Post();
                }
		SpisokInetCatalog=0;
		}

return -1;
}
//-----------------------------------------------------------------------------
//выбор клиента
void TFormaElementaSprProducer::ViborKlient(void)
{

if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducer::EndViborKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->Element->Edit();
				DM->ElementIDKLIENT_SPRODUCER->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->ElementNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->Element->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор клиента
void TFormaElementaSprProducer::ViborPostZIP(void)
{

if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Post_ZIP;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducer::EndViborPostZIP(void)
{
if (FormaSpiskaSprKlient==0) return;


	DM->Element->Edit();
	DM->ElementPOST_ZIP_NAME->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
	DM->ElementIDPOST_ZIP_SPRODUCER->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
	DM->Element->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducer::NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprProducer::PostZipcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborPostZIP();
}
//---------------------------------------------------------------------------
void TFormaElementaSprProducer::OpenFormSpiskaSprInetCatalog()
{

if (SpisokInetCatalog==NULL)
        {
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprInetCatalog,IID_IFormaSpiskaSprInetCatalog,
													(void**)&SpisokInetCatalog);
		SpisokInetCatalog->Init(InterfaceMainObject,InterfaceImpl);
		SpisokInetCatalog->Vibor=true;
		SpisokInetCatalog->NumberProcVibor=ER_ViborInetCatalog;
        }
}
//--------------------------------------------------------------------------------------
void __fastcall TFormaElementaSprProducer::UslNameInetCatalogcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprInetCatalog();
}
//---------------------------------------------------------------------------

