//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprHardwareIsp.h"
 #include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxMemo"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprHardwareIsp::TREM_FormaElementaSprHardwareIsp(TComponent* Owner)
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
bool TREM_FormaElementaSprHardwareIsp::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardwareIsp,IID_IREM_DMSprHardwareIsp,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);




NameTypUslacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
PoscxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
OtchitanocxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
RealnoIspolsovanocxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
DescrcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
KolcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
ZayavkacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
PrefikscxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
ModelZcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;



DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprHardwareIsp::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardwareIsp::FormClose(TObject *Sender,
      TCloseAction &Action)
{


if (FormaSpiskaSprTypUslov>0) FormaSpiskaSprTypUslov->kanRelease();
if(FormaGurZ) FormaGurZ->kanRelease();

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
void TREM_FormaElementaSprHardwareIsp::UpdateForm(void)
{
//


}
//----------------------------------------------------------------------------

int TREM_FormaElementaSprHardwareIsp::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{




if ( number_procedure_end==VR_ViborTypUsla)
	{
	if (type_event==1)
		{
		EndViborTypUsla();
		}
	FormaSpiskaSprTypUslov=0;
	}

if (number_procedure_end==ER_ViborZ)
	{
	if (type_event==1)
		{
		EndViborZ();
		}
	}

return -1;
}
//-----------------------------------------------------------------------------








void __fastcall TREM_FormaElementaSprHardwareIsp::ActionOKExecute(TObject *Sender)

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

//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardwareIsp::ViborTypUsla(void)
{
if (FormaSpiskaSprTypUslov>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypUslov,IID_IREM_FormaSpiskaSprTypUslov,
												 (void**)&FormaSpiskaSprTypUslov);
FormaSpiskaSprTypUslov->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypUslov->flVibor=true;
FormaSpiskaSprTypUslov->NumberProcVibor=VR_ViborTypUsla;
FormaSpiskaSprTypUslov->IdElement=glStrToInt64(DM->ElementIDTYPEUSEL_REM_SHARDWARE_ISP->AsString);
FormaSpiskaSprTypUslov->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardwareIsp::EndViborTypUsla(void)
{

	DM->Element->Edit();
	DM->ElementIDTYPEUSEL_REM_SHARDWARE_ISP->AsString=FormaSpiskaSprTypUslov->DM->TableID_REM_STYPUSLOV->AsString;
	DM->ElementNAME_REM_STYPUSLOV->AsString=FormaSpiskaSprTypUslov->DM->TableNAME_REM_STYPUSLOV->AsString;
	DM->Element->Post();

}
///-------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardwareIsp::NameTypUslacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypUsla();
		}break;
	case 1:
		{
		DM->Element->Edit();
		DM->ElementIDTYPEUSEL_REM_SHARDWARE_ISP->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprHardwareIsp::ActionCloseElementExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardwareIsp::ZayavkacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborZ();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardwareIsp::ViborZ(void)
{
if (FormaGurZ==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,IID_IREM_FormaGurZ,
												 (void**)&FormaGurZ);
	FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaGurZ) return;
	FormaGurZ->NumberProcVibor=ER_ViborZ;
	FormaGurZ->Vibor=true;
	//FormaGurZ->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void  TREM_FormaElementaSprHardwareIsp::EndViborZ(void)
{

	DM->Element->Edit();
	DM->ElementIDZ_REM_SHARDWARE_ISP->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->ElementNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->ElementSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	//DM->ElementSERNUM2_REM_SHARDWARE->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;

	DM->ElementPREFIKS_NUM_REM_Z->AsString=FormaGurZ->DM->TablePREFIKS_NUM_REM_Z->AsString;
	DM->ElementNUM_REM_Z->AsInteger=FormaGurZ->DM->TableNUM_REM_Z->AsInteger;
	DM->ElementPOS_REM_Z->AsDateTime=FormaGurZ->DM->TablePOS_REM_Z->AsDateTime;
	DM->ElementSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->ElementMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;

	DM->Element->Post();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
