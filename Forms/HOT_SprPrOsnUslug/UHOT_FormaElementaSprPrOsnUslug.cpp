//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaElementaSprPrOsnUslug.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxMaskEdit"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall THOT_FormaElementaSprPrOsnUslug::THOT_FormaElementaSprPrOsnUslug(TComponent* Owner)
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

bool THOT_FormaElementaSprPrOsnUslug::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprPrOsnUslug.1",IID_IHOT_DMSprPrOsnUslug,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


NameTypePosNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCatcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomBrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
IdNom=0;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaElementaSprPrOsnUslug::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (HOT_FormaSpiskaSprCatNom>0) HOT_FormaSpiskaSprCatNom->kanRelease();
if(HOT_FormaSpiskaSprTypePosel>0) HOT_FormaSpiskaSprTypePosel->kanRelease();
if (FormaSpiskaSprNomPr>0) FormaSpiskaSprNomPr->kanRelease();
if(FormaSpiskaSprNomBr>0) FormaSpiskaSprNomBr->kanRelease();


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
int THOT_FormaElementaSprPrOsnUslug::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if ( number_procedure_end==ER_Cat)
	{
	if (type_event==1)
		{
		EndViborCatNom();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if ( number_procedure_end==ER_TypePosel)
	{
	if (type_event==1)
		{
        EndViborTypePosel();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	}

if ( number_procedure_end==ER_NomProg)
	{
	if (type_event==1)
		{
        EndViborNomPr();
		}
	FormaSpiskaSprNomPr=0;
	}


if ( number_procedure_end==ER_NomBron)
	{
	if (type_event==1)
		{
		EndViborNomBr();
		}
    FormaSpiskaSprNomBr=0;
	}

return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaElementaSprPrOsnUslug::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprPrOsnUslug");
}
//---------------------------------------------------------------------------




void THOT_FormaElementaSprPrOsnUslug::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
												 (void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::EndViborCatNom(void)
{

	DM->Element->Edit();
	DM->ElementIDCAT_HOT_SPROSNUSL->AsInt64=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsInt64;
	DM->ElementNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void THOT_FormaElementaSprPrOsnUslug::ViborTypePosel(void)
{
if (HOT_FormaSpiskaSprTypePosel>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
												 (void**)&HOT_FormaSpiskaSprTypePosel);
HOT_FormaSpiskaSprTypePosel->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprTypePosel->Vibor=true;
HOT_FormaSpiskaSprTypePosel->NumberProcVibor=ER_TypePosel;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::EndViborTypePosel(void)
{

	DM->Element->Edit();
	DM->ElementIDTPOS_HOT_SPROSNUSL->AsInt64=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsInt64;
	DM->ElementNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaSprPrOsnUslug::NameCatcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaSprPrOsnUslug::NameTypePosNomcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePosel();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaElementaSprPrOsnUslug::ViborNomPr(void)
{
if (FormaSpiskaSprNomPr>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNomPr);
FormaSpiskaSprNomPr->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNomPr->Vibor=true;
FormaSpiskaSprNomPr->NumberProcVibor=ER_NomProg;
FormaSpiskaSprNomPr->IdNom=IdNom;
FormaSpiskaSprNomPr->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::EndViborNomPr(void)
{

	DM->Element->Edit();
	DM->ElementIDNOMPR_HOT_SPROSNUSL->AsInt64=glStrToInt64(FormaSpiskaSprNomPr->DM->TableIDNOM->AsString);
	DM->ElementNAMENOMPR->AsString=FormaSpiskaSprNomPr->DM->TableNAMENOM->AsString;
	IdNom=FormaSpiskaSprNomPr->DM->TableIDNOM->AsInteger;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::NameNomPrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomPr();	
}
//---------------------------------------------------------------------------
void THOT_FormaElementaSprPrOsnUslug::ViborNomBr(void)
{
if (FormaSpiskaSprNomBr>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNomBr);
FormaSpiskaSprNomBr->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNomBr->Vibor=true;
FormaSpiskaSprNomBr->NumberProcVibor=ER_NomBron;
FormaSpiskaSprNomBr->IdNom=IdNom;
FormaSpiskaSprNomBr->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::EndViborNomBr(void)
{

	DM->Element->Edit();
	DM->ElementIDNOMBR_HOT_SPROSNUSL->AsString=FormaSpiskaSprNomBr->DM->TableIDNOM->AsString;
	DM->ElementNAMENOMBR->AsString=FormaSpiskaSprNomBr->DM->TableNAMENOM->AsString;
	DM->Element->Post();
	IdNom=FormaSpiskaSprNomBr->DM->TableIDNOM->AsInteger;

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaSprPrOsnUslug::NameNomBrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomBr();
}

//-----------------------------------------------------------------------------



void __fastcall THOT_FormaElementaSprPrOsnUslug::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaSprPrOsnUslug::ActionOKExecute(TObject *Sender)

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

void __fastcall THOT_FormaElementaSprPrOsnUslug::ActionSaveExecute(TObject *Sender)

{
__int64 id=DM->ElementID_HOT_SPROSNUSL->AsInt64;
if (DM->SaveElement()==true)
		{
		DM->OpenElement(id);
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

