//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprCustomerKlient.h"
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
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprCustomerKlient::TFormaSpiskaSprCustomerKlient(TComponent* Owner)
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
bool TFormaSpiskaSprCustomerKlient::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCustomerKlient,IID_IDMSprCustomerKlient, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
//DM->OpenTable(IdNom);
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
int TFormaSpiskaSprCustomerKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerKlient::FormClose(TObject *Sender,
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
void TFormaSpiskaSprCustomerKlient::UpdateForm(void)
{

LabelHeader->Caption=TextHeader;
DM->OpenTable(IdOwner);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerKlient::ToolButtonNewClick(TObject *Sender)
{
DM->TableAppend(IdOwner);
ViborKlient();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerKlient::ToolButtonDeleteClick(TObject *Sender)
{
DM->TableDelete();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprCustomerKlient::cxGrid1DBTableView1DblClick(
      TObject *Sender)
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



void __fastcall TFormaSpiskaSprCustomerKlient::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        Close();
        }
else
        {
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerKlient::ActionCloseExecute(TObject *Sender)
{
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprCustomerKlient::ActionOKExecute(TObject *Sender)
{
DM->SaveIsmen();
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprCustomerKlient::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
		if (number_procedure_end==ER_EditKlient)
				{
				if (type_event==1)
					{
					EndViborKlient();
					}
				FormaSpiskaSprKlient=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerKlient::DeleteElement()
{


}
//------------------------------------------------------------------------------
void TFormaSpiskaSprCustomerKlient::ViborKlient(void)
{

if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprKlient,IID_IFormaSpiskaSprKlient,
													 (void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		//FormaSpiskaSprKlient->IdPage=glStrToInt64(DM->ElementID_ART_IB->AsString);
		//FormaSpiskaSprInfBlockSostav->DM->OpenTable(glStrToInt64(DM->ElementID_ART_IB->AsString));
		//FormaSpiskaSprInfBlockSostav->HeaderText=DM->ElementNAME_ART_IB->AsString;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->UpdateForm();
		FormaSpiskaSprKlient->NumberProcVibor=ER_EditKlient;
		}

}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprCustomerKlient::EndViborKlient(void)
{
	DM->Table->Edit();
	DM->TableIDKLIENT_CUST_KLIENT->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->TableNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Table->Post();


}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprCustomerKlient::cxGrid1DBTableView1NameKlientPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------

