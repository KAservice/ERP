//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprDepartment.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IkasDMDataSet.h"
#include "IDMSprOborud.h"
#include "IFiskReg.h"
#include "IkasFormSpr.h"
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
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprDepartment::TFormaSpiskaSprDepartment(TComponent* Owner)
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
bool TFormaSpiskaSprDepartment::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprDepartment,IID_IkasDMSpr, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

IkasDMDataSet *i_ds=0;
DM->kanQueryInterface(IID_IkasDMDataSet,(void**) &i_ds);
cxGrid1DBTableView1->DataController->DataSource=i_ds->kanGetDataSource(0);
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
int TFormaSpiskaSprDepartment::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDepartment::FormClose(TObject *Sender,
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
void TFormaSpiskaSprDepartment::UpdateForm(void)
{

DM->OpenTable(0);

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDepartment::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDepartment::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprDepartment::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
        Close();
        }
else
		{
		OpenFormElement();
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprDepartment::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{
				TypeEvent=1;
				Close();
				}
		else
				{
				OpenFormElement();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDepartment::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

int TFormaSpiskaSprDepartment::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
UpdateForm();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprDepartment::OpenFormNewElement(void)
{
		IkasFormSpr * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprDepartment,IID_IkasFormSpr,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement()==true)
			{
			FormaElementa->UpdateForm();
			}
		else
			{
			ShowMessage(FormaElementa->DM->TextError);
			FormaElementa->kanRelease();
			}
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprDepartment::OpenFormElement(void)
{
		IkasFormSpr * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprDepartment,IID_IkasFormSpr,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->IdEl=DM->GetValueFieldAsInt64("ID_SDEPARTMENT",0);
		if (FormaElementa->DM->OpenElement(DM->GetValueFieldAsInt64("ID_SDEPARTMENT",0))==true)
			{
			FormaElementa->UpdateForm();
			}
		else
			{
			ShowMessage(FormaElementa->DM->TextError);
			FormaElementa->kanRelease();
			}

}
//----------------------------------------------------------------------------
void TFormaSpiskaSprDepartment::DeleteElement(void)
{

		if (DM->DeleteElement(DM->GetValueFieldAsInt64("ID_SDEPARTMENT",0))==true)
			{
			UpdateForm();
			}
		else
			{
			ShowMessage(DM->TextError);
			}
}
//-----------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprDepartment::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

