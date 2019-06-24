//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprImportNom.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprImportNom::TFormaElementaSprImportNom(TComponent* Owner)
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
bool TFormaElementaSprImportNom::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEdcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ArtikulcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
int TFormaElementaSprImportNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprImportNom::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprImportNom::FormClose(TObject *Sender,
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
//----------------------------------------------------------------------------
void TFormaElementaSprImportNom::ViborKlient(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	FormaSpiskaSprKlient->NumberProcVibor=1;
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprImportNom::EndViborKlient(void)
{
if (FormaSpiskaSprKlient!=NULL)
		{

                DM->Element->Edit();
				DM->ElementIDKLIENT_SIMPORTNOM->AsInt64=
						FormaSpiskaSprKlient->DM->TableIDKLIENT->AsInt64;
				DM->ElementNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
				DM->Element->Post();
				}
		FormaSpiskaSprKlient=NULL;


FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//----------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprImportNom");
}

//----------------------------------------------------------------------------


void __fastcall TFormaElementaSprImportNom::CodecxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::NameEdcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::ArtikulcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprImportNom::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprImportNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborKlient();
			}
		}

return -1;
}
//-----------------------------------------------------------------------------
