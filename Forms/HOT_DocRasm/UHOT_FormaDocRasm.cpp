//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaDocRasm.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMSprKlient.h"
#include "IHOT_FormaDocReal.h"
#include "IDMSprKlientDopFisL.h"
#include "IDMSprDocKlient.h"
#include "IDMSetup.h"
#include "IHOT_DMSprNF.h"
#include "IHOT_FormaDocViezd.h"
#include "IFormaRunExternalModule.h"
#include "IHOT_RaschetStoimProg.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxPC"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaDocRasm::THOT_FormaDocRasm(TComponent* Owner)
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
bool THOT_FormaDocRasm::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRasm.1",IID_IHOT_DMDocRasm, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;

DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OrgcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
CelPrcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THOT_FormaDocRasmImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		DMTableExtPrintForm->Table->Next();
		}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypePrice->DataSourceTable;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------
int THOT_FormaDocRasm::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
        }

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(HOT_FormaSpiskaSprNF) HOT_FormaSpiskaSprNF->kanRelease();
if(HOT_FormaSpiskaSprSostNom)  HOT_FormaSpiskaSprSostNom->kanRelease();
if(HOT_FormaSpiskaSprTypePosel)  HOT_FormaSpiskaSprTypePosel->kanRelease();
if(HOT_FormaSpiskaTableSostNF)  HOT_FormaSpiskaTableSostNF->kanRelease();

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
DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Doc/DocRasm");	
}
//---------------------------------------------------------------------------
int THOT_FormaDocRasm::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Firm)
	{

	if (type_event==1)
		{
		EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	}

if (number_procedure_end==ER_InfBase)
	{

	if (type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
	}

if (number_procedure_end==ER_SostBron)
	{
	if (type_event==1)
		{
		EndViborSostBron();
		}
	HOT_FormaSpiskaTableSostNF=0;
	}

if (number_procedure_end==ER_Plat)
	{
	if (type_event==1)
		{
		EndViborPlat();
		}
	FormaSpiskaSprKlient=0;
	}


if (number_procedure_end==ER_Guest)
	{
	if (type_event==1)
		{
		EndViborGuest();
		}
	FormaSpiskaSprKlient=0;
	}

if (number_procedure_end==ER_GuestRasm)
	{
	if (type_event==1)
		{
		EndViborGuestRasm();
		}
	FormaSpiskaSprKlient=0;
	}

if (number_procedure_end==ER_GuestBr2)
	{
	if (type_event==1)
		{
		EndViborGuestBr2();
		}
	FormaSpiskaSprKlient=0;
	}


if (number_procedure_end==ER_NomerRasm)
	{
	if (type_event==1)
		{
		EndViborNomerRasm();
		}
	HOT_FormaSpiskaSprNF=0;
	}


if (number_procedure_end==ER_NomerBr2)
	{
	if (type_event==1)
		{
		EndViborNomerBr2();
		}
	HOT_FormaSpiskaSprNF=0;
	}

if (number_procedure_end==ER_SostRasm)
	{
	if (type_event==1)
		{
		EndViborSostRasm();
		}
	HOT_FormaSpiskaSprSostNom=0;
	}

if (number_procedure_end==ER_SostBr2)
	{
	if (type_event==1)
		{
		EndViborSostBr2();
		}
	HOT_FormaSpiskaSprSostNom=0;
	}


if (number_procedure_end==ER_TypePoselRasm)
	{
	if (type_event==1)
		{
		EndViborTypePoselRasm();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	}

if (number_procedure_end==ER_TypePoselBr2)
	{
	if (type_event==1)
		{
		EndViborTypePoselBr2();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	}


if (number_procedure_end==ER_ParamPosel)
	{
	if (type_event==1)
		{
		EndViborParamPosel();
		}
	HOT_FormaElementaTableSostNF=0;
	}

if (number_procedure_end==ER_ParamBron2)
	{
	if (type_event==1)
		{
		EndViborParamBron2();
		}
	HOT_FormaElementaTableSostNF=0;
	}

if (number_procedure_end==ER_CatRasm)
	{
	if (type_event==1)
		{
		EndViborCatRasm();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if (number_procedure_end==ER_CatBr2)
	{
	if (type_event==1)
		{
		EndViborCatBr2();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if (number_procedure_end==ER_CelPriesda)
	{
	if (type_event==1)
		{
		EndViborCelPriesda();
		}
	HOT_FormaSpiskaSprCelPriesda=0;
	}


return -1;
}
//-----------------------------------------------------------------------------

//выбор фирмы
void THOT_FormaDocRasm::ViborFirm(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}    
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborFirm(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDFIRM_HOT_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//выбор информационной базы
void THOT_FormaDocRasm::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_HOT_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborInfBase(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDBASE_HOT_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//--------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaDocRasm::ViborPlat(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Plat;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborPlat(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDKL_HOT_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

	   FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocRasm::ViborGuestRasm(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_GuestRasm;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocTRASM_IDGUEST->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborGuestRasm(void)
{

	DM->DocT->Edit();
	DM->DocTRASM_IDGUEST->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
	DM->DocTRASM_NAMEGUEST->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocRasm::ViborGuestBr2(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_GuestBr2;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocTBR2_IDGUEST->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborGuestBr2(void)
{

	DM->DocT->Edit();
	DM->DocTBR2_IDGUEST->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
	DM->DocTBR2_NAMEGUEST->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//----------------------------------------------------------------------------
//выбор номера
void THOT_FormaDocRasm::ViborNomerRasm(void)
{
if (Prosmotr==true) return;

		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
													(void**)&HOT_FormaSpiskaSprNF);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprNF) return;
		HOT_FormaSpiskaSprNF->Vibor=true;
		HOT_FormaSpiskaSprNF->NumberProcVibor=ER_NomerRasm;

}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborNomerRasm(void)
{

	DM->DocT->Edit();
	DM->DocTRASM_ID_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsString;
	DM->DocTRASM_NAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
	DM->DocTRASM_ID_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprNF->DM->TableIDCAT_HOT_SNF->AsString;
	DM->DocTRASM_NAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();
	KolMest=HOT_FormaSpiskaSprNF->DM->TableKOLM_HOT_SNF->AsInteger;

cxGrid1->SetFocus();
}

//-----------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborNomerBr2(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
													(void**)&HOT_FormaSpiskaSprNF);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprNF) return;
		HOT_FormaSpiskaSprNF->Vibor=true;
		HOT_FormaSpiskaSprNF->NumberProcVibor=ER_NomerBr2;
		}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborNomerBr2(void)
{

	DM->DocT->Edit();
	DM->DocTBR2_ID_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsString;
	DM->DocTBR2_NAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//-----------------------------------------------------------------------------
//выбор состояния
void THOT_FormaDocRasm::ViborSostRasm(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprSostNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
													(void**)&HOT_FormaSpiskaSprSostNom);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprSostNom) return;
		HOT_FormaSpiskaSprSostNom->Vibor=true;
		HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_SostRasm;
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborSostRasm(void)
{

				DM->DocT->Edit();
				DM->DocTRASM_ID_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsString;
				DM->DocTRASM_NAME_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborSostBr2(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprSostNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
													(void**)&HOT_FormaSpiskaSprSostNom);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprSostNom) return;
		HOT_FormaSpiskaSprSostNom->Vibor=true;
		HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_SostBr2;
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborSostBr2(void)
{

				DM->DocT->Edit();
				DM->DocTRASM_ID_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsString;
				DM->DocTRASM_NAME_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//выбор типа поселения
void THOT_FormaDocRasm::ViborTypePoselRasm(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprTypePosel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
													(void**)&HOT_FormaSpiskaSprTypePosel);
		HOT_FormaSpiskaSprTypePosel->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprTypePosel) return;
		HOT_FormaSpiskaSprTypePosel->Vibor=true;
		HOT_FormaSpiskaSprTypePosel->NumberProcVibor=ER_TypePoselRasm;
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborTypePoselRasm(void)
{

	DM->DocT->Edit();
	DM->DocTRASM_ID_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsString;
	DM->DocTRASM_NAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
	if (HOT_FormaSpiskaSprTypePosel->DM->TableALL_HOT_STYPEPOS->AsInteger==1)
		{
		DM->DocTRASM_KOLM_HOT_SOSTNF->AsInteger=KolMest;
		}
	else
		{
		DM->DocTRASM_KOLM_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaSprTypePosel->DM->TableKOLM_HOT_STYPEPOS->AsInteger;
		}
	DM->DocT->Post();

cxGrid1->SetFocus();

}
//----------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborTypePoselBr2(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprTypePosel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
													(void**)&HOT_FormaSpiskaSprTypePosel);
		HOT_FormaSpiskaSprTypePosel->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprTypePosel) return;
		HOT_FormaSpiskaSprTypePosel->Vibor=true;
		HOT_FormaSpiskaSprTypePosel->NumberProcVibor=ER_TypePoselBr2;
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborTypePoselBr2(void)
{

	DM->DocT->Edit();
	DM->DocTBR2_ID_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsString;
	DM->DocTBR2_NAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborPlat();	
}
//---------------------------------------------------------------------------
//выбор состояния бронирования
void THOT_FormaDocRasm::ViborSostBron(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaTableSostNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpTableSostNF.1",IID_IHOT_FormaSpiskaTableSostNF,
													(void**)&HOT_FormaSpiskaTableSostNF);
		HOT_FormaSpiskaTableSostNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaTableSostNF) return;
		HOT_FormaSpiskaTableSostNF->Vibor=true;
		HOT_FormaSpiskaTableSostNF->DM->IdPlat=glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString);
		HOT_FormaSpiskaTableSostNF->NumberProcVibor=ER_SostBron;
		HOT_FormaSpiskaTableSostNF->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborSostBron(void)
{

				DM->DocT->Edit();
				//состояние бронирования
				DM->DocTIDSOSTBR_HOT_DRASMT->AsString=HOT_FormaSpiskaTableSostNF->DM->TableID_HOT_SOSTNF->AsString;
				DM->DocTBR_NAME_HOT_SNF->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_SNF->AsString;
		  //		DM->DocTBR_NAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_SCATNOM->AsString;
				DM->DocTBR_NAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_STYPEPOS->AsString;
				DM->DocTBR_NAMEGUEST->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAMEGUEST->AsString;
				DM->DocTBR_NAME_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaTableSostNF->DM->TableNAME_HOT_SSOSTNOM->AsString;
				DM->DocTBR_POSNACH_HOT_SOSTNF->AsDateTime=HOT_FormaSpiskaTableSostNF->DM->TablePOSNACH_HOT_SOSTNF->AsDateTime;
				DM->DocTBR_POSCON_HOT_SOSTNF->AsDateTime=HOT_FormaSpiskaTableSostNF->DM->TablePOSCON_HOT_SOSTNF->AsDateTime;
				DM->DocTBR_KOLM_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaTableSostNF->DM->TableKOLM_HOT_SOSTNF->AsInteger;
          
				//DM->DocTIDSOSTRASM_HOT_DRASMT->AsInteger=DM->DocTIDSOSTBR_HOT_DRASMT->AsInteger;
				//категория номера
				IHOT_DMTableSostNF * dm_table_sost;
				InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMTableSostNF.1",IID_IHOT_DMTableSostNF,
													(void**)&dm_table_sost);
				dm_table_sost->Init(InterfaceMainObject,InterfaceImpl);
				dm_table_sost->OpenElement(glStrToInt64(HOT_FormaSpiskaTableSostNF->DM->TableID_HOT_SOSTNF->AsString));
				DM->DocTBR_NAME_HOT_SCATNOM->AsString=dm_table_sost->ElementNAME_HOT_SCATNOM->AsString;


				// заполнить размещение на основании бронирования
				if (glStrToInt64(dm_table_sost->ElementIDCAT_HOT_SOSTNF->AsString))
					{
					DM->DocTRASM_ID_HOT_SCATNOM->AsString=dm_table_sost->ElementIDCAT_HOT_SOSTNF->AsString;
					DM->DocTRASM_NAME_HOT_SCATNOM->AsString=dm_table_sost->ElementNAME_HOT_SCATNOM->AsString;
					}
			   dm_table_sost->kanRelease();

				if (glStrToInt64(HOT_FormaSpiskaTableSostNF->DM->TableIDNOMER_HOT_SOSTNF->AsString)!=0)
					{
					DM->DocTRASM_ID_HOT_SNF->AsString=HOT_FormaSpiskaTableSostNF->DM->TableIDNOMER_HOT_SOSTNF->AsString;
					DM->DocTRASM_NAME_HOT_SNF->AsString=DM->DocTBR_NAME_HOT_SNF->AsString;
					}

				if(glStrToInt64(HOT_FormaSpiskaTableSostNF->DM->TableIDGUEST_HOT_SOSTNF->AsString)!=0)
					{
					DM->DocTRASM_IDGUEST->AsString=HOT_FormaSpiskaTableSostNF->DM->TableIDGUEST_HOT_SOSTNF->AsString;
					DM->DocTRASM_NAMEGUEST->AsString=DM->DocTBR_NAMEGUEST->AsString;
					}

				if (glStrToInt64(HOT_FormaSpiskaTableSostNF->DM->TableIDTPOS_HOT_SOSTNF->AsString)!=0)
					{
					DM->DocTRASM_ID_HOT_STYPEPOS->AsString=HOT_FormaSpiskaTableSostNF->DM->TableIDTPOS_HOT_SOSTNF->AsString;
					DM->DocTRASM_NAME_HOT_STYPEPOS->AsString=DM->DocTBR_NAME_HOT_STYPEPOS->AsString;
					}

				DM->DocTRASM_KOLM_HOT_SOSTNF->AsInteger=DM->DocTBR_KOLM_HOT_SOSTNF->AsInteger;
				DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime=DM->DocTBR_POSNACH_HOT_SOSTNF->AsDateTime;
				DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime=DM->DocTBR_POSCON_HOT_SOSTNF->AsDateTime;
				DM->DocT->Post();

	   cxGrid1->SetFocus();

}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::cxButtonViborSostNFClick(TObject *Sender)
{
ViborSostBron();
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1BRPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSostBron();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1RASM_NAME_HOT_SNFPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomerRasm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1BR2_NAME_HOT_SNFPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomerBr2();	
}
//---------------------------------------------------------------------------
//выбор категории номера
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborCatRasm(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_CatRasm;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborCatRasm(void)
{

	DM->DocT->Edit();
	DM->DocTRASM_ID_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsString;
	DM->DocTRASM_NAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();


HOT_FormaSpiskaSprCatNom=0;
cxGrid1->SetFocus();
}

//---------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborCatBr2(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_CatBr2;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborCatBr2(void)
{

	DM->DocT->Edit();
	DM->DocTBR2_ID_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsString;
	DM->DocTBR2_NAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1RASM_NAME_HOT_SCATNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatRasm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1BR2_NAME_HOT_SCATNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatBr2();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1RASM_NAME_HOT_STYPEPOSPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePoselRasm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1RASM_NAME_HOT_SSOSTNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSostRasm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::cxGrid1DBBandedTableView1RASM_NAMEGUESTPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGuestRasm();	
}
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::CreateDocReal(void)
{
IHOT_FormaDocReal *doc;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocReal.1",IID_IHOT_FormaDocReal,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;
//настройка формы
doc->DM->NewDoc();

doc->DM->DocAll->Edit();
doc->DM->DocAllIDKL_HOT_GALLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICE_HOT_DREAL->AsString=DM->DocIDTPRICE_HOT_DRASM->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	IHOT_RaschetStoimProg * Raschet;
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_RaschetStoimProg.1",IID_IHOT_RaschetStoimProg,
													(void**)&Raschet);
	Raschet->Init(InterfaceMainObject,InterfaceImpl);
	Raschet->PosNach=DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime;
	Raschet->PosCon=DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime;
	Raschet->IdNomer=glStrToInt64(DM->DocTRASM_ID_HOT_SNF->AsString);
	Raschet->IdTypePos=glStrToInt64(DM->DocTRASM_ID_HOT_STYPEPOS->AsString);
	Raschet->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_HOT_DRASM->AsString);

	if (glStrToInt64(DM->DocTIDSOSTBR_HOT_DRASMT->AsString)>0)
		{
		Raschet->AddBron=true;
		Raschet->PosNachBron=DM->DocTBR_POSNACH_HOT_SOSTNF->AsDateTime;
		Raschet->PosConBron=DM->DocTBR_POSCON_HOT_SOSTNF->AsDateTime;
        }


	Raschet->GetTableDoc();
	while (Raschet->GetString()==true)
		{

		doc->DM->DocT->Append();
		doc->DM->DocTTUSL_HOT_DREALT->AsInteger=Raschet->StringDoc->TypeUsl;

		if(Raschet->StringDoc->IdNom!=0)
			{
			doc->DM->DocTIDNOM_HOT_DREALT->AsString=Raschet->StringDoc->IdNom;
			}
		doc->DM->DocTNAMENOM->AsString=Raschet->StringDoc->NameNom;

		if(Raschet->StringDoc->IdEd!=0)
			{
			doc->DM->DocTIDED_HOT_DREALT->AsString=Raschet->StringDoc->IdEd;
			}

		doc->DM->DocTKF_HOT_DREALT->AsFloat=Raschet->StringDoc->KF;
		doc->DM->DocTNAMEED->AsString=Raschet->StringDoc->NameEd;
		doc->DM->DocTPRICE_HOT_DREALT->AsFloat=Raschet->StringDoc->Price;

		doc->DM->DocTKOL_HOT_DREALT->AsFloat=Raschet->StringDoc->Kol;
		doc->DM->DocTPOSNACH_HOT_DREALT->AsDateTime=Raschet->StringDoc->PosNach;
		doc->DM->DocTPOSCON_HOT_DREALT->AsDateTime=Raschet->StringDoc->PosCon;
		if(glStrToInt64(DM->DocTRASM_ID_HOT_SNF->AsString)!=0)
			{
			doc->DM->DocTIDNOMER_HOT_DREALT->AsString=DM->DocTRASM_ID_HOT_SNF->AsString;
			}
		if (glStrToInt64(DM->DocTRASM_ID_HOT_SCATNOM->AsString)!=0)
			{
			doc->DM->DocTIDCAT_HOT_DREALT->AsString=DM->DocTRASM_ID_HOT_SCATNOM->AsString;
			}
		if(glStrToInt64(DM->DocTRASM_ID_HOT_STYPEPOS->AsString)!=0)
			{
			doc->DM->DocTIDTPOS_HOT_DREALT->AsString=DM->DocTRASM_ID_HOT_STYPEPOS->AsString;
			}
		if(glStrToInt64(DM->DocTRASM_IDGUEST->AsString)!=0)
			{
			doc->DM->DocTIDGUEST_HOT_DREALT->AsString=DM->DocTRASM_IDGUEST->AsString;
			}
	
		doc->DM->DocTNAME_HOT_SNF->AsString=DM->DocTRASM_NAME_HOT_SNF->AsString;
		doc->DM->DocTNAME_HOT_SCATNOM->AsString=DM->DocTRASM_NAME_HOT_SCATNOM->AsString;
		doc->DM->DocTNAME_HOT_STYPEPOS->AsString=DM->DocTRASM_NAME_HOT_STYPEPOS->AsString;
		doc->DM->DocTNAMEKLIENT->AsString=DM->DocTRASM_NAMEGUEST->AsString;

		doc->DM->DocT->Post();
		}
	Raschet->kanRelease();
	DM->DocT->Next();
	}
doc->UpdateForm();


}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::cxButtonCreateDocRealClick(TObject *Sender)
{
CreateDocReal();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::PrintAnketa(void)
{
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
prForm->SS->BeginUpdate();

int x=1;
int y=0;
TcxSSCellObject *cell;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
		TcxSSHeader *cHeader;

		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 10;
//		cHeader->Size[1] = 10;
//		cHeader->Size[2] = 40;
//		cHeader->Size[3] = 10;
//		cHeader->Size[4] = 60;
//		cHeader->Size[5] = 80;
//		cHeader->Size[6] = 60;
//		cHeader->Size[7] = 70;
//		cHeader->Size[8] = 80;


IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=DMSprFirm->ElementFNAMEFIRM->AsString+
				" ИНН "+DMSprFirm->ElementINNFIRM->AsString;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text=DMSprFirm->ElementPADRFIRM->AsString;
delete cell;

DMSprFirm->kanRelease();
y++;


cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Комната №: "+DM->DocTRASM_NAME_HOT_SNF->AsString;
delete cell;

x=x+3;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Прибыл: "+DM->DocTRASM_POSNACH_HOT_SOSTNF->AsString;
delete cell;
y++;

x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Этаж ___________________ ";
delete cell;
x=x+3;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Выбыл:  \"____\" _________________________ 200___г.";
delete cell;
y++;



x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(2, y);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="АНКЕТА НА ПРОЖИВАЮЩЕГО В ГОСТИНИЦЕ";
delete cell;
y++;

x=1;
TRect rect;
rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
IDMSprKlient *DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocTRASM_IDGUEST->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Гость (ФИО): "+DMSprKlient->ElementFNAME->AsString;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Font->Size = 12;
cell->Style->WordBreak = true;
delete cell;
y++;

IDMSprKlientDopFisL * DMSprKlientDopFisL;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprKlientDopFisL.1",IID_IDMSprKlientDopFisL,
													(void**)&DMSprKlientDopFisL);
DMSprKlientDopFisL->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlientDopFisL->IdKlient=glStrToInt64(DM->DocTRASM_IDGUEST->AsString);
DMSprKlientDopFisL->OpenElement();

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Дата рождения: "+DMSprKlientDopFisL->ElementDATEROG_SKLIENT_DOPFISL->AsString;
delete cell;
y++;
DMSprKlientDopFisL->kanRelease();

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

IDMSprDocKlient * DMSprDocKlient;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDocKlient.1",IID_IDMSprDocKlient,
													(void**)&DMSprDocKlient);
DMSprDocKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprDocKlient->OpenTable(glStrToInt64(DM->DocTRASM_IDGUEST->AsString));

AnsiString s="Документ: "+DMSprDocKlient->TableNAME_SDOCKLIENT->AsString+
				" серия "+DMSprDocKlient->TableSER_SDOCKLIENT->AsString+
				" № " +DMSprDocKlient->TableNUM_SDOCKLIENT->AsString+
				" выдан "+DMSprDocKlient->TableDATEVID_SDOCKLIENT->AsString+
				"  " +DMSprDocKlient->TableVID_SDOCKLIENT->AsString;
DMSprDocKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->WordBreak = true;
cell->Text=s;
delete cell;

prForm->SetRowsHeightAuto(y, x, x+6,20,s);
y++;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Адрес постоянного места жительства: "+DMSprKlient->ElementADRKLIENT->AsString;
cell->Style->WordBreak = true;
delete cell;
y++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Цель приезда: "+DM->DocNAME_HOT_SCELPR->AsString;

delete cell;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="В какую организацию прибыл: "+DM->DocORG_HOT_DRASM->AsString;

delete cell;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Срок проживания в гостинице до : "+DM->DocTRASM_POSCON_HOT_SOSTNF->AsString;

delete cell;
y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="С правилами пожарной безопасности ознакомлен.";

delete cell;
y++; y++;y++;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Подпись проживающего в гостинице: ______________________________";

delete cell;
y++;y++;y++;


cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Подпись дежурного администратора: _____________________________ ";
delete cell;

////заголовок таблицы
//numCol=2;
//cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text="№";
//cell->Style->Font->Size = 10;
//cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;
//numCol++;




prForm->SS->EndUpdate();
prForm->Show();

}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::cxButtonPrintAnketaClick(TObject *Sender)
{
PrintAnketa();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::CelPrcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCelPriesda();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRasm::ViborCelPriesda(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprCelPriesda==NULL)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCelPriesda.1",IID_IHOT_FormaSpiskaSprCelPriesda,
													(void**)&HOT_FormaSpiskaSprCelPriesda);
	HOT_FormaSpiskaSprCelPriesda->Init(InterfaceMainObject,InterfaceImpl);
	if (!HOT_FormaSpiskaSprCelPriesda) return;
	//настройка формы
	HOT_FormaSpiskaSprCelPriesda->Vibor=true;
	HOT_FormaSpiskaSprCelPriesda->NumberProcVibor=ER_CelPriesda;
	HOT_FormaSpiskaSprCelPriesda->UpdateForm();
	}
}
//-------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborCelPriesda(void)
{

				DM->Doc->Edit();
				DM->DocIDCELPR_HOT_DRASM->AsString=HOT_FormaSpiskaSprCelPriesda->DM->TableID_HOT_SCELPR->AsString;
				DM->DocNAME_HOT_SCELPR->AsString=HOT_FormaSpiskaSprCelPriesda->DM->TableNAME_HOT_SCELPR->AsString;
				DM->Doc->Post();
	   FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//-------------------------------------------------------------------------
void THOT_FormaDocRasm::CreateDocViesd(void)
{
IHOT_FormaDocViezd * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocViezd.1",IID_IHOT_FormaDocViezd,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;
//настройка формы
doc->DM->NewDoc();

doc->DM->DocAll->Edit();
doc->DM->DocAllIDFIRM_HOT_GALLDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDKL_HOT_GALLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAllIDDOCOSN_HOT_GALLDOC->AsString=DM->DocAllID_HOT_GALLDOC->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocDESCR_HOT_DVIESD->AsString="Основание: Размещение №" +
					DM->DocAllNUMBER_HOT_GALLDOC->AsString+
					" от "+DM->DocAllPOS_HOT_GALLDOC->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	doc->DM->AddString();
	doc->DM->DocT->Edit();
	doc->DM->DocTIDSOST_HOT_DVIESDT->AsString=DM->DocTIDSOSTRASM_HOT_DRASMT->AsString;
	doc->DM->DocTIDNOMER_HOT_SOSTNF->AsString=DM->DocTRASM_ID_HOT_SNF->AsString;
	doc->DM->DocTNAME_HOT_SNF->AsString=DM->DocTRASM_NAME_HOT_SNF->AsString;
	doc->DM->DocTIDGUEST_HOT_SOSTNF->AsString=DM->DocTRASM_IDGUEST->AsString;
	doc->DM->DocTNAMEKLIENT->AsString=DM->DocTRASM_NAMEGUEST->AsString;
	doc->DM->DocTIDTPOS_HOT_SOSTNF->AsString=DM->DocTRASM_ID_HOT_STYPEPOS->AsString;
	doc->DM->DocTNAME_HOT_STYPEPOS->AsString=DM->DocTRASM_NAME_HOT_STYPEPOS->AsString;
	doc->DM->DocTIDCAT_HOT_SOSTNF->AsString=DM->DocTRASM_ID_HOT_SCATNOM->AsString;
	doc->DM->DocTNAME_HOT_SCATNOM->AsString=DM->DocTRASM_NAME_HOT_SCATNOM->AsString;
	doc->DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime=DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime;
	doc->DM->DocTPOSCON_HOT_SOSTNF->AsDateTime=DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime;
	doc->DM->DocTKOLM_HOT_SOSTNF->AsInteger=DM->DocTRASM_KOLM_HOT_SOSTNF->AsInteger;

    doc->DM->DocT->Post();
	DM->DocT->Next();
	}

doc->UpdateForm();	
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::cxButtonCreateDocViezdClick(TObject *Sender)
{
CreateDocViesd();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionAddStringExecute(TObject *Sender)
{
TDateTime pos_nach;
TDateTime pos_con;
int id_nom;
AnsiString name_nom;
int id_cat;
AnsiString name_cat;

pos_nach=DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime;
pos_con=DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime;
id_nom=glStrToInt64(DM->DocTRASM_ID_HOT_SNF->AsString);
name_nom=DM->DocTRASM_NAME_HOT_SNF->AsString;
id_cat=glStrToInt64(DM->DocTRASM_ID_HOT_SCATNOM->AsString);
name_cat=DM->DocTRASM_NAME_HOT_SCATNOM->AsString;



DM->AddString();
//получим состояние размещения
IDMSetup *s;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&s);
s->Init(InterfaceMainObject,InterfaceImpl);
s->OpenElement(102);
if (s->ElementVALUE_SETUP->AsString!="")
	{
	IHOT_DMSprSostNom * sost;
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprSostNom.1",IID_IHOT_DMSprSostNom,
													(void**)&sost);
	sost->Init(InterfaceMainObject,InterfaceImpl);
	sost->OpenElement(glStrToInt64(s->ElementVALUE_SETUP->AsString));
	if (glStrToInt64(sost->ElementID_HOT_SSOSTNOM->AsString)>0)
		{
		DM->DocT->Edit();
		DM->DocTRASM_ID_HOT_SSOSTNOM->AsString=sost->ElementID_HOT_SSOSTNOM->AsString;
		DM->DocTRASM_NAME_HOT_SSOSTNOM->AsString=sost->ElementNAME_HOT_SSOSTNOM->AsString;
		DM->DocT->Post();
		}
	sost->kanRelease();
	}
else
	{
    ShowMessage("Ошибка! Не задано состояние размещения в таблице настроек! (Настройка 102)");
	}
s->kanRelease();

if(DM->DocT->RecordCount==1)  //1строка
	{  //добавим только позицию заезда //добавим плательщика гостем
	DM->DocT->Edit();
	DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime=Now();
	DM->DocTRASM_IDGUEST->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
	DM->DocTRASM_NAMEGUEST->AsString=DM->DocAllNAMEKLIENT->AsString;
	DM->DocT->Post();
	}
else
	{//скопируем текущую строку
	DM->DocT->Edit();
	DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime=pos_nach;
	DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime=pos_con;
	if (id_nom!=0)
		{
		DM->DocTRASM_ID_HOT_SNF->AsString=id_nom;
		DM->DocTRASM_NAME_HOT_SNF->AsString=name_nom;
		}
	if (id_cat!=0)
		{
		DM->DocTRASM_ID_HOT_SCATNOM->AsString=id_cat;
		DM->DocTRASM_NAME_HOT_SCATNOM->AsString=name_cat;
		}
	DM->DocT->Post();
	}

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::NumbercxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::OrgcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::DescrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteString();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THOT_FormaDocRasm::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THOT_FormaDocRasm::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//надо добавить текущий DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
    module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_HOT_GALLDOC->AsString));
	}
	
module->ExecuteModule();


}
//-----------------------------------------------------------------------------


void __fastcall THOT_FormaDocRasm::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRasm::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	ShowMessage("Документ открыт только для просмотра!");
	return;
	}
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborGuest(void)
{


}
//-------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborParamPosel(void)
{

}
//------------------------------------------------------------------------
void __fastcall THOT_FormaDocRasm::EndViborParamBron2(void)
{


}
//--------------------------------------------------------------------------
