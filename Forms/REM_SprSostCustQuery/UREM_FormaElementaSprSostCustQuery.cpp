//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprSostCustQuery.h"
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
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprSostCustQuery::TREM_FormaElementaSprSostCustQuery(TComponent* Owner)
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
bool TREM_FormaElementaSprSostCustQuery::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprSostCustQuery,IID_IREM_DMSprSostCustQuery,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
IdcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprSostCustQuery::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprSostCustQuery::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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
int TREM_FormaElementaSprSostCustQuery::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprSostCustQuery::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprSostCustQuery::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprSklad");
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprSostCustQuery::cxButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
Close();  	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprSostCustQuery::cxButtonOKClick(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprSostCustQuery::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaElementaSprSostCustQuery::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

