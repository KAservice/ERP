//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprNomAnalog.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBLookupComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprNomAnalog::TFormaSpiskaSprNomAnalog(TComponent* Owner)
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
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------
bool TFormaSpiskaSprNomAnalog::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNomAnalog,IID_IDMSprNomAnalog, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

Vibor=false;

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
int TFormaSpiskaSprNomAnalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomAnalog::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();


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

//--------------------------------------------------------------------------
void TFormaSpiskaSprNomAnalog::UpdateForm(void)
{
LabelNom->Caption=HeaderText;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomAnalog::ToolButtonNewClick(TObject *Sender)
{
DM->Table->Append();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomAnalog::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomAnalog::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNomAnalog");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomAnalog::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        Close();
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprNomAnalog::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomAnalog::ActionCloseExecute(TObject *Sender)
{
DM->TableCancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomAnalog::ActionOKExecute(TObject *Sender)
{
DM->TableSaveIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprNomAnalog::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==VR_ViborNom)
		{
		if (type_event==1)
			{
			EndViborNom() ;
			}
		FormaSpiskaSprNom=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomAnalog::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNom();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomAnalog::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_ViborNom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOMANALOG_SNOM_ANALOG->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomAnalog::EndViborNom(void)
{
	DM->Table->Edit();
	DM->TableIDNOMANALOG_SNOM_ANALOG->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->TableNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->Table->Post();


}
//----------------------------------------------------------------------------
