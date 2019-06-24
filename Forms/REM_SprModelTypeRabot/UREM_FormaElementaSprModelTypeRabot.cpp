//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprModelTypeRabot.h"
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
#pragma link "cxSpinEdit"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprModelTypRabot::TREM_FormaElementaSprModelTypRabot(TComponent* Owner)
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
bool TREM_FormaElementaSprModelTypRabot::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModelTypRabot,IID_IREM_DMSprModelTypRabot,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxDBButtonEditNAME_REM_STYPRABOT->DataBinding->DataSource=DM->DataSourceElement;



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
int TREM_FormaElementaSprModelTypRabot::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModelTypRabot::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModelTypRabot::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(REM_FormaSpiskaSprTypRabot)REM_FormaSpiskaSprTypRabot->kanRelease();


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





void __fastcall TREM_FormaElementaSprModelTypRabot::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModelTypRabot::ActionOKExecute(TObject *Sender)
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
int TREM_FormaElementaSprModelTypRabot::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_ViborTypRabot)
				{
				if (type_event==1)
					{
					EndViborTypRabot();
					}
				REM_FormaSpiskaSprTypRabot=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------

void TREM_FormaElementaSprModelTypRabot::OpenFormaSpiskaSprTypRabot(void)
{
if (REM_FormaSpiskaSprTypRabot==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypRabot,IID_IREM_FormaSpiskaSprTypRabot,
														(void**)&REM_FormaSpiskaSprTypRabot);
		REM_FormaSpiskaSprTypRabot->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprTypRabot->flVibor=true;
		REM_FormaSpiskaSprTypRabot->NumberProcVibor=ER_ViborTypRabot;
		REM_FormaSpiskaSprTypRabot->IdElement=glStrToInt64(DM->ElementIDTR_REM_SMODEL_TRAB->AsString);
		REM_FormaSpiskaSprTypRabot->UpdateForm();
		}


}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprModelTypRabot::EndViborTypRabot(void)
{
DM->Element->Edit();
DM->ElementIDTR_REM_SMODEL_TRAB->AsString=
						REM_FormaSpiskaSprTypRabot->DM->TableID_REM_STYPRABOT->AsString;
DM->ElementNAME_REM_STYPRABOT->AsString=
					REM_FormaSpiskaSprTypRabot->DM->TableNAME_REM_STYPRABOT->AsString;
DM->Element->Post();


}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprModelTypRabot::cxDBButtonEditNAME_REM_STYPRABOTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprTypRabot();
}
//---------------------------------------------------------------------------

