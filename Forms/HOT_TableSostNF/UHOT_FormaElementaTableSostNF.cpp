//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaElementaTableSostNF.h"
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
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall THOT_FormaElementaTableSostNF::THOT_FormaElementaTableSostNF(TComponent* Owner)
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

bool THOT_FormaElementaTableSostNF::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMTableSostNF.1",IID_IHOT_DMTableSostNF,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

PosNachcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
PosConcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
NamePlatcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameGuestcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCatNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
TypePoscxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSostcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
KolMestcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
NameCelPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

Prosmotr=false;
TypeEvent=0;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int THOT_FormaElementaTableSostNF::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (HOT_FormaSpiskaSprCatNom>0) HOT_FormaSpiskaSprCatNom->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(HOT_FormaSpiskaSprNF) HOT_FormaSpiskaSprNF->kanRelease();
if(HOT_FormaSpiskaSprSostNom)  HOT_FormaSpiskaSprSostNom->kanRelease();
if(HOT_FormaSpiskaSprTypePosel)  HOT_FormaSpiskaSprTypePosel->kanRelease();
if(HOT_FormaSpiskaSprCelPriesda)  HOT_FormaSpiskaSprCelPriesda->kanRelease();

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
int THOT_FormaElementaTableSostNF::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Plat)
	{
	if (type_event==1)
		{
		EndViborPlat();
		}
	FormaSpiskaSprKlient==0;
	Show();
	}

if (number_procedure_end==ER_Guest)
	{
	if (type_event==1)
		{
		EndViborGuest();
		}
	FormaSpiskaSprKlient=0;
	Show();
	}

if (number_procedure_end==ER_Cat)
	{
	if (type_event==1)
		{
		EndViborCatNom();
		}
	HOT_FormaSpiskaSprCatNom=0;
	Show();
	}

if (number_procedure_end==ER_TypePos)
	{
	if (type_event==1)
		{
		EndViborTypePosel();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	Show();
	}



if (number_procedure_end==ER_Nomer)
	{
	if (type_event==1)
		{
		EndViborNomer();
		}
	HOT_FormaSpiskaSprNF=0;
	Show();
	}


if (number_procedure_end==ER_Sost)
	{
	if (type_event==1)
		{
		EndViborSost();
		}
	HOT_FormaSpiskaSprSostNom=0;
	Show();
	}

if (number_procedure_end==ER_Cel)
	{
	if (type_event==1)
		{
		EndViborCelPriesda();
		}
	HOT_FormaSpiskaSprCelPriesda=0;
	Show();
	}


return -1;
}
//--------------------------------------------------------------------------
void THOT_FormaElementaTableSostNF::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Spr/SprNF");
}
//---------------------------------------------------------------------------




void __fastcall THOT_FormaElementaTableSostNF::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatNom();
}
//---------------------------------------------------------------------------
void THOT_FormaElementaTableSostNF::ViborCatNom(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprCatNom==NULL)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
												 (void**)&HOT_FormaSpiskaSprCatNom);
	HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	HOT_FormaSpiskaSprCatNom->Vibor=true;
	HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;
	Hide();
    }
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborCatNom(void)
{

	DM->Element->Edit();
	DM->ElementIDCAT_HOT_SOSTNF->AsInt64=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsInt64;
	DM->ElementNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->Element->Post();


}
//---------------------------------------------------------------------------
///--------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaElementaTableSostNF::ViborPlat(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		//FormaSpiskaSprKlient->FormStyle=fsNormal;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Plat;
		Hide();
		}

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborPlat(void)
{

				DM->Element->Edit();
				DM->ElementIDPLAT_HOT_SOSTNF->AsInt64=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInt64;
				DM->ElementNAMEPLAT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->Element->Post();

}
//---------------------------------------------------------------------------
//выбор гостя
void THOT_FormaElementaTableSostNF::ViborGuest(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Guest;
		Hide();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborGuest(void)
{

				DM->Element->Edit();
				DM->ElementIDGUEST_HOT_SOSTNF->AsInt64=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsInt64;
				DM->ElementNAMEGUEST->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->Element->Post();

}
//----------------------------------------------------------------------------
//выбор номера
void THOT_FormaElementaTableSostNF::ViborNomer(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
												 (void**)&HOT_FormaSpiskaSprNF);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		HOT_FormaSpiskaSprNF->Vibor=true;
		HOT_FormaSpiskaSprNF->NumberProcVibor=ER_Nomer;
		Hide();
		}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborNomer(void)
{

				DM->Element->Edit();
				DM->ElementIDNOMER_HOT_SOSTNF->AsInt64=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsInt64;
				DM->ElementNAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
				DM->Element->Post();
				KolMest=HOT_FormaSpiskaSprNF->DM->TableKOLM_HOT_SNF->AsInteger;

	   Show();
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор типа поселения
void THOT_FormaElementaTableSostNF::ViborTypePosel(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprTypePosel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
												 (void**)&HOT_FormaSpiskaSprTypePosel);
		HOT_FormaSpiskaSprTypePosel->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprTypePosel) return;
		HOT_FormaSpiskaSprTypePosel->Vibor=true;
		HOT_FormaSpiskaSprTypePosel->NumberProcVibor=ER_TypePos;
		Hide();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborTypePosel(void)
{

				DM->Element->Edit();
				DM->ElementIDTPOS_HOT_SOSTNF->AsInt64=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsInt64;
				DM->ElementNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;

				if (HOT_FormaSpiskaSprTypePosel->DM->TableALL_HOT_STYPEPOS->AsInteger==1)
					{
					DM->ElementKOLM_HOT_SOSTNF->AsInteger=KolMest;
					}
				else
					{
					DM->ElementKOLM_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaSprTypePosel->DM->TableKOLM_HOT_STYPEPOS->AsInteger ;
					}
				DM->Element->Post();

	   Show();
}
//------------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::NamePlatcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborPlat();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::NameGuestcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGuest();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::TypePoscxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePosel();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::NameNomercxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomer();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::NameSostcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSost();
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//выбор состояния
void THOT_FormaElementaTableSostNF::ViborSost(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprSostNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
												 (void**)&HOT_FormaSpiskaSprSostNom);
		HOT_FormaSpiskaSprSostNom->Init(InterfaceMainObject,InterfaceImpl);
		HOT_FormaSpiskaSprSostNom->Vibor=true;
		HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_Sost;
		Hide();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborSost(void)
{

				DM->Element->Edit();
				DM->ElementIDSOST_HOT_SOSTNF->AsInt64=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsInt64;
				DM->ElementNAME_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;
				DM->Element->Post();

	   Show();
}
//---------------------------------------------------------------------------
//выбор цели приезда
void THOT_FormaElementaTableSostNF::ViborCelPriesda(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprCelPriesda==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCelPriesda.1",IID_IHOT_FormaSpiskaSprCelPriesda,
												 (void**)&HOT_FormaSpiskaSprCelPriesda);
		HOT_FormaSpiskaSprCelPriesda->Init(InterfaceMainObject,InterfaceImpl);
		HOT_FormaSpiskaSprCelPriesda->Vibor=true;
		HOT_FormaSpiskaSprCelPriesda->NumberProcVibor=ER_Cel;
		Hide();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaElementaTableSostNF::EndViborCelPriesda(void)
{

				DM->Element->Edit();
				DM->ElementIDCEL_HOT_SOSTNF->AsInt64=HOT_FormaSpiskaSprCelPriesda->DM->TableID_HOT_SCELPR->AsInt64;
				DM->ElementNAME_HOT_SCELPR->AsString=HOT_FormaSpiskaSprCelPriesda->DM->TableNAME_HOT_SCELPR->AsString;
				DM->Element->Post();

	   Show();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::NameCelPrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCelPriesda();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaElementaTableSostNF::ActionOKExecute(TObject *Sender)
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

