//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprGrpNom.h"
#include "IFormaSpiskaSprNacenka.h"
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
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprGrpNom::TFormaElementaSprGrpNom(TComponent* Owner)
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
bool TFormaElementaSprGrpNom::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
IdGnDBText->DataSource=DM->DataSourceElement;
NamePropertiesNaborcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameVidImageNaborcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprGrpNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprGrpNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprPropertiesNabor)FormaSpiskaSprPropertiesNabor->kanRelease();



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
void __fastcall TFormaElementaSprGrpNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNom");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprGrpNom::cxButtonNacClick(TObject *Sender)
{
IFormaSpiskaSprNacenka * spr;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNacenka.1",IID_IFormaSpiskaSprNacenka, (void**)&spr);
spr->Init(InterfaceMainObject,InterfaceImpl);
spr->DM->OpenTable(DM->ElementIDGN->AsInteger);
//spr->UpdateForm();
//spr->LabelGrpNom->Caption=DM->ElementNAMEGN->AsString;
spr->NumberProcVibor=1;

}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprGrpNom::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprGrpNom::ActionOKExecute(TObject *Sender)
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
int TFormaElementaSprGrpNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ER_ViborPropNabor)
	{
	if (type_event==1)
		{
		EndViborPropertiesNabor();
		}
	FormaSpiskaSprPropertiesNabor=0;
	}

return -1;
}
//-----------------------------------------------------------------------------
void TFormaElementaSprGrpNom::ViborPropertiesNabor(void)
{

if (FormaSpiskaSprPropertiesNabor==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprPropertiesNabor,IID_IFormaSpiskaSprPropertiesNabor,
												 (void**)&FormaSpiskaSprPropertiesNabor);
	FormaSpiskaSprPropertiesNabor->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprPropertiesNabor) return;
	FormaSpiskaSprPropertiesNabor->NumberProcVibor=ER_ViborPropNabor;
	FormaSpiskaSprPropertiesNabor->Vibor=true;
	FormaSpiskaSprPropertiesNabor->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void TFormaElementaSprGrpNom::EndViborPropertiesNabor(void)
{

	DM->Element->Edit();
	DM->ElementIDPROPNABOR_SGRPNOM->AsString=FormaSpiskaSprPropertiesNabor->DM->TableID_SPROPNABOR->AsString;
	DM->ElementNAME_SPROPNABOR->AsString=FormaSpiskaSprPropertiesNabor->DM->TableNAME_SPROPNABOR->AsString;
	DM->Element->Post();

FormaSpiskaSprPropertiesNabor=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}

//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprGrpNom::NamePropertiesNaborcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborPropertiesNabor();
}
//---------------------------------------------------------------------------

