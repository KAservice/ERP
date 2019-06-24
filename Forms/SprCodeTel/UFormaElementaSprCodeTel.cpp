//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprCodeTel.h"

#include "UFormaSpiskaSprNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprCodeTel::TFormaElementaSprCodeTel(TComponent* Owner)
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
bool TFormaElementaSprCodeTel::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprCodeTel,IID_IDMSprCodeTel, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodeOpercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameComcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
ProcentComissioncxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprCodeTel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprCodeTel::FormClose(TObject *Sender,
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
}
//---------------------------------------------------------------------------
int TFormaElementaSprCodeTel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

        
		if (number_procedure_end==ViborNom)
                {
				if(type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDNOM_CODETEL->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
						DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprNom=0;
                }


		if (number_procedure_end==ViborNomCommission)
                {
                if(type_event==1)
                        {
                        DM->Element->Edit();
                        DM->ElementIDNOMCOM_CODETEL->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
                        DM->ElementNAMENOMCOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprNom=0;
                }



        ViborRekv=NO;

return -1;
}
//----------------------------------------------------------------------------


void TFormaElementaSprCodeTel::OpenFormSpiskaSprNom(void)
{
if (FormaSpiskaSprNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprNom->Vibor=true;
        FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ViborNom;
        }
}
//-------------------------------------------------------------------------
void TFormaElementaSprCodeTel::OpenFormSpiskaSprNomCommission(void)
{
if (FormaSpiskaSprNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->UpdateForm();
        FormaSpiskaSprNom->NumberProcVibor=ViborNomCommission;
		}

}
//-------------------------------------------------------------------------

void __fastcall TFormaElementaSprCodeTel::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprCodeTel");	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprCodeTel::NameComcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNomCommission(); 	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCodeTel::NameNomcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprCodeTel::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprCodeTel::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

