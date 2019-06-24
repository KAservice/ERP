//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaDocBron.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMSprKlient.h"
#include "IDMSetup.h"
#include "IHOT_DMSprSostNom.h"
#include "IHOT_DMTableSostNF.h"
#include "IHOT_FormaDocRaschet.h"
#include "IHOT_FormaDocRasm.h"
#include "IHOT_FormaDocOtmenaBron.h"
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaDocBron::THOT_FormaDocBron(TComponent* Owner)
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
bool THOT_FormaDocBron::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocBron.1",IID_IHOT_DMDocBron, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

DescrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THOT_FormaDocBronImpl),false);
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
int THOT_FormaDocBron::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THOT_FormaDocBron::UpdateForm(void)
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
void __fastcall THOT_FormaDocBron::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprFirm) FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprInfBase) FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprKlient) FormaSpiskaSprKlient->kanRelease();
if(HOT_FormaSpiskaSprNF) HOT_FormaSpiskaSprNF->kanRelease();
if(HOT_FormaSpiskaSprSostNom)  HOT_FormaSpiskaSprSostNom->kanRelease();
if(HOT_FormaSpiskaSprTypePosel)  HOT_FormaSpiskaSprTypePosel->kanRelease();

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

void __fastcall THOT_FormaDocBron::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Doc/DocBron");	
}
//---------------------------------------------------------------------------
int THOT_FormaDocBron::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_InfBase)
	{
	if (type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}


if (number_procedure_end==ER_Plat)
	{
	if (type_event==1)
		{
		EndViborPlat();
		}
	FormaSpiskaSprKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}


if (number_procedure_end==ER_Guest)
	{
	if (type_event==1)
		{
		EndViborGuest();
		}
	FormaSpiskaSprKlient=0;
	}

if (number_procedure_end==ER_Nomer)
	{

	if (type_event==1)
		{
		EndViborNomer();
		}
	HOT_FormaSpiskaSprNF=0;
	}



if (number_procedure_end==ER_Cat)
	{

	if (type_event==1)
		{
		EndViborCat();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if (number_procedure_end==ER_TypePos)
	{

	if (type_event==1)
		{
		EndViborTypePosel();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	}

if (number_procedure_end==ER_Sost)
	{

	if (type_event==1)
		{
		EndViborSost();
		}
    HOT_FormaSpiskaSprSostNom=0;
	}

return -1;
}
//----------------------------------------------------------------------------



//выбор фирмы
void THOT_FormaDocBron::ViborFirm(void)
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
void __fastcall THOT_FormaDocBron::EndViborFirm(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDFIRM_HOT_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();


}
//---------------------------------------------------------------------------
//выбор информационной базы
void THOT_FormaDocBron::ViborInfBase(void)
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
void __fastcall THOT_FormaDocBron::EndViborInfBase(void)
{


                DM->DocAll->Edit();
				DM->DocAllIDBASE_HOT_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();


}
//--------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaDocBron::ViborPlat(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Plat;
		FormaSpiskaSprKlient->IdKlient=DM->DocAllIDKL_HOT_GALLDOC->AsInteger;
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborPlat(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDKL_HOT_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();


}
//---------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocBron::ViborGuest(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Guest;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocTIDGUEST_HOT_SOSTNF->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborGuest(void)
{

				DM->DocT->Edit();
				DM->DocTIDGUEST_HOT_SOSTNF->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocTNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocT->Post();

cxGrid1->SetFocus();
}
//----------------------------------------------------------------------------
//выбор номера
void THOT_FormaDocBron::ViborNomer(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
													(void**)&HOT_FormaSpiskaSprNF);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprNF) return;
		HOT_FormaSpiskaSprNF->Vibor=true;
		HOT_FormaSpiskaSprNF->NumberProcVibor=ER_Nomer;
		}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborNomer(void)
{

				DM->DocT->Edit();
				DM->DocTIDNOMER_HOT_SOSTNF->AsString=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsString;
				DM->DocTNAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
				DM->DocTIDCAT_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaSprNF->DM->TableIDCAT_HOT_SNF->AsInteger;
                DM->DocTNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SCATNOM->AsString;
				DM->DocT->Post();
				KolMest=HOT_FormaSpiskaSprNF->DM->TableKOLM_HOT_SNF->AsInteger;
	   cxGrid1->SetFocus();
}
//-----------------------------------------------------------------------------
//выбор состояния
void THOT_FormaDocBron::ViborSost(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprSostNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprSostNom.1",IID_IHOT_FormaSpiskaSprSostNom,
													(void**)&HOT_FormaSpiskaSprSostNom);
		HOT_FormaSpiskaSprSostNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprSostNom) return;
		HOT_FormaSpiskaSprSostNom->Vibor=true;
		HOT_FormaSpiskaSprSostNom->NumberProcVibor=ER_Sost;
		}
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborSost(void)
{

				DM->DocT->Edit();
				DM->DocTIDSOST_HOT_SOSTNF->AsString=HOT_FormaSpiskaSprSostNom->DM->TableID_HOT_SSOSTNOM->AsString;
				DM->DocTNAME_HOT_SSOSTNOM->AsString=HOT_FormaSpiskaSprSostNom->DM->TableNAME_HOT_SSOSTNOM->AsString;
				DM->DocT->Post();


	   cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//выбор типа поселения
void THOT_FormaDocBron::ViborTypePosel(void)
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
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborTypePosel(void)
{

				DM->DocT->Edit();
				DM->DocTIDTPOS_HOT_SOSTNF->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsString;
				DM->DocTNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
				if (HOT_FormaSpiskaSprTypePosel->DM->TableALL_HOT_STYPEPOS->AsInteger==1)
					{
					DM->DocTKOLM_HOT_SOSTNF->AsInteger=KolMest;
					}
				else
					{
					DM->DocTKOLM_HOT_SOSTNF->AsInteger=HOT_FormaSpiskaSprTypePosel->DM->TableKOLM_HOT_STYPEPOS->AsInteger;
					}
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall THOT_FormaDocBron::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborPlat();	
}

//-----------------------------------------------------------------------------


void THOT_FormaDocBron::ViborCat(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;


}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::EndViborCat(void)
{

	DM->DocT->Edit();
	DM->DocTIDCAT_HOT_SOSTNF->AsString=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsString;
	DM->DocTNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//------------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::cxGrid1DBTableView1NAME_HOT_SNFPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomer();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::cxGrid1DBTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCat();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::cxGrid1DBTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePosel();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGuest();
}
//---------------------------------------------------------------------------

void THOT_FormaDocBron::CreateDocRaschet(void)
{
IHOT_FormaDocRaschet *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRaschet.1",IID_IHOT_FormaDocRaschet,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;
//настройка формы
doc->DM->NewDoc();

doc->DM->DocAll->Edit();
doc->DM->DocAllIDBASE_HOT_GALLDOC->AsString=DM->DocAllIDBASE_HOT_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRM_HOT_GALLDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDKL_HOT_GALLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();


doc->DM->Doc->Edit();
doc->DM->DocIDTPRICE_HOT_DRASCHET->AsString=DM->DocIDTPRICE_HOT_DBRON->AsString;
doc->DM->Doc->Post();


DM->DocT->First();
while(!DM->DocT->Eof)
	{
//	doc->DM->AddStringReal(DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime,	DM->DocTPOSCON_HOT_SOSTNF->AsDateTime,
//						DM->DocTIDNOMER_HOT_SOSTNF->AsInt64, DM->DocTNAME_HOT_SNF->AsString,
//						DM->DocTIDCAT_HOT_SOSTNF->AsInt64, DM->DocTNAME_HOT_SCATNOM->AsString,
//						DM->DocTIDTPOS_HOT_SOSTNF->AsInt64, DM->DocTNAME_HOT_STYPEPOS->AsString,
//						DM->DocTIDGUEST_HOT_SOSTNF->AsInt64,DM->DocTNAMEKLIENT->AsString);
	IHOT_RaschetStoimProg * Raschet;
	InterfaceGlobalCom->kanCreateObject("Oberon.HOT_RaschetStoimProg.1",IID_IHOT_RaschetStoimProg,
													(void**)&Raschet);
	Raschet->Init(InterfaceMainObject,InterfaceImpl);
	Raschet->PosNach=DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime;
	Raschet->PosCon=DM->DocTPOSCON_HOT_SOSTNF->AsDateTime;
	Raschet->IdNomer=glStrToInt64(DM->DocTIDNOMER_HOT_SOSTNF->AsString);
	Raschet->IdTypePos=glStrToInt64(DM->DocTIDTPOS_HOT_SOSTNF->AsString);
	Raschet->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_HOT_DBRON->AsString);
	Raschet->GetTableDoc();
	while (Raschet->GetString()==true)
		{
		doc->DM->DocT->Append();
		doc->DM->DocTTUSL_HOT_DRASCHETT->AsInteger=Raschet->StringDoc->TypeUsl;
		if(Raschet->StringDoc->IdNom!=0)
			{
			doc->DM->DocTIDNOM_HOT_DRASCHETT->AsString=Raschet->StringDoc->IdNom;
			}
		doc->DM->DocTNAMENOM->AsString=Raschet->StringDoc->NameNom;

		if(Raschet->StringDoc->IdEd!=0)
			{
			doc->DM->DocTIDED_HOT_DRASCHETT->AsString=Raschet->StringDoc->IdEd;
			}

		doc->DM->DocTKF_HOT_DRASCHETT->AsFloat=Raschet->StringDoc->KF;
		doc->DM->DocTNAMEED->AsString=Raschet->StringDoc->NameEd;
		doc->DM->DocTPRICE_HOT_DRASCHETT->AsFloat=Raschet->StringDoc->Price;

		doc->DM->DocTKOL_HOT_DRASCHETT->AsFloat=Raschet->StringDoc->Kol;
		doc->DM->DocTPOSNACH_HOT_DRASCHETT->AsDateTime=Raschet->StringDoc->PosNach;
		doc->DM->DocTPOSCON_HOT_DRASCHETT->AsDateTime=Raschet->StringDoc->PosCon;
		if(glStrToInt64(DM->DocTIDNOMER_HOT_SOSTNF->AsString)!=0)
			{
			doc->DM->DocTIDNOMER_HOT_DRASCHETT->AsString=DM->DocTIDNOMER_HOT_SOSTNF->AsString;
			}
		if (glStrToInt64(DM->DocTIDCAT_HOT_SOSTNF->AsString)!=0)
			{
			doc->DM->DocTIDCAT_HOT_DRASCHETT->AsString=DM->DocTIDCAT_HOT_SOSTNF->AsString;
			}
		if(glStrToInt64(DM->DocTIDTPOS_HOT_SOSTNF->AsString)!=0)
			{
			doc->DM->DocTIDTPOS_HOT_DRASCHETT->AsString=DM->DocTIDTPOS_HOT_SOSTNF->AsString;
			}
		if(glStrToInt64(DM->DocTIDGUEST_HOT_SOSTNF->AsString)!=0)
			{
			doc->DM->DocTIDGUEST_HOT_DRASCHETT->AsString=DM->DocTIDGUEST_HOT_SOSTNF->AsString;
			}
	
		doc->DM->DocTNAME_HOT_SNF->AsString=DM->DocTNAME_HOT_SNF->AsString;
		doc->DM->DocTNAME_HOT_SCATNOM->AsString=DM->DocTNAME_HOT_SCATNOM->AsString;
		doc->DM->DocTNAME_HOT_STYPEPOS->AsString=DM->DocTNAME_HOT_STYPEPOS->AsString;
		doc->DM->DocTNAMEKLIENT->AsString=DM->DocTNAMEKLIENT->AsString;

		doc->DM->DocT->Post();
		}
	Raschet->kanRelease();
	DM->DocT->Next();
	}
doc->UpdateForm();


}
//------------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::cxButtonCreateDocRaschetClick(
	  TObject *Sender)
{
CreateDocRaschet();
}
//---------------------------------------------------------------------------
void THOT_FormaDocBron::CreateDocRasm(void)
{
IHOT_FormaDocRasm *forma_doc;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocRasm.1",IID_IHOT_FormaDocRasm,
													(void**)&forma_doc);
forma_doc->Init(InterfaceMainObject,InterfaceImpl);
forma_doc->DM->NewDoc();
forma_doc->DM->DocAll->Edit();
forma_doc->DM->DocAllIDFIRM_HOT_GALLDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
forma_doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
forma_doc->DM->DocAllIDKL_HOT_GALLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
forma_doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
forma_doc->DM->DocAllIDDOCOSN_HOT_GALLDOC->AsString=DM->DocAllID_HOT_GALLDOC->AsString;
forma_doc->DM->DocAll->Post();

forma_doc->DM->Doc->Edit();
forma_doc->DM->DocDESCR_HOT_DRASM->AsString="На основании Бронирования №"+
							DM->DocAllNUMBER_HOT_GALLDOC->AsString +" от "+
							DM->DocAllPOS_HOT_GALLDOC->AsString;

forma_doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	forma_doc->DM->AddString();
	forma_doc->DM->DocT->Edit();
	//бронирование
	forma_doc->DM->DocTIDSOSTBR_HOT_DRASMT->AsString=DM->DocTIDSOST_HOT_DBRONT->AsString;
	forma_doc->DM->DocTBR_NAME_HOT_SNF->AsString=DM->DocTNAME_HOT_SNF->AsString;
	forma_doc->DM->DocTBR_NAME_HOT_SCATNOM->AsString=DM->DocTNAME_HOT_SCATNOM->AsString;
	forma_doc->DM->DocTBR_NAME_HOT_STYPEPOS->AsString=DM->DocTNAME_HOT_STYPEPOS->AsString;
	forma_doc->DM->DocTBR_NAMEGUEST->AsString=DM->DocTNAMEKLIENT->AsString;
	forma_doc->DM->DocTBR_NAME_HOT_SSOSTNOM->AsString=DM->DocTNAME_HOT_SSOSTNOM->AsString;
	forma_doc->DM->DocTBR_POSNACH_HOT_SOSTNF->AsDateTime=DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime;
	forma_doc->DM->DocTBR_POSCON_HOT_SOSTNF->AsDateTime=DM->DocTPOSCON_HOT_SOSTNF->AsDateTime;
	forma_doc->DM->DocTBR_KOLM_HOT_SOSTNF->AsInteger=DM->DocTKOLM_HOT_SOSTNF->AsInteger;

	//размещение
	forma_doc->DM->DocTRASM_ID_HOT_SNF->AsString=DM->DocTIDNOMER_HOT_SOSTNF->AsString;
	forma_doc->DM->DocTRASM_NAME_HOT_SNF->AsString=DM->DocTNAME_HOT_SNF->AsString;
	forma_doc->DM->DocTRASM_ID_HOT_SCATNOM->AsString=DM->DocTIDCAT_HOT_SOSTNF->AsString;
	forma_doc->DM->DocTRASM_NAME_HOT_SCATNOM->AsString=DM->DocTNAME_HOT_SCATNOM->AsString;
	forma_doc->DM->DocTRASM_ID_HOT_STYPEPOS->AsString=DM->DocTIDTPOS_HOT_SOSTNF->AsString;
	forma_doc->DM->DocTRASM_NAME_HOT_STYPEPOS->AsString=DM->DocTNAME_HOT_STYPEPOS->AsString;
	forma_doc->DM->DocTRASM_IDGUEST->AsString=DM->DocTIDGUEST_HOT_SOSTNF->AsString;
	forma_doc->DM->DocTRASM_NAMEGUEST->AsString=DM->DocTNAMEKLIENT->AsString;
	forma_doc->DM->DocTRASM_POSNACH_HOT_SOSTNF->AsDateTime=DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime;
	forma_doc->DM->DocTRASM_POSCON_HOT_SOSTNF->AsDateTime=DM->DocTPOSCON_HOT_SOSTNF->AsDateTime;
	forma_doc->DM->DocTRASM_KOLM_HOT_SOSTNF->AsInteger=DM->DocTKOLM_HOT_SOSTNF->AsInteger;


	forma_doc->DM->DocT->Post(); 
	DM->DocT->Next();
    }

//forma_doc->Show();
}
//---------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::cxButtonCreateDocRasmClick(TObject *Sender)
{
CreateDocRasm();	
}
//---------------------------------------------------------------------------
void THOT_FormaDocBron::OpenPrintFormPotvBron(void)
{
TRect rect;
AnsiString s;
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
prForm->SS->BeginUpdate();

int x=1;
int y=0;
TcxSSCellObject *cell;

prForm->SS->DefaultStyle->Font->Size=14;
prForm->SS->DefaultStyle->Font->Name="Times New Roman";
prForm->SS->RowsAutoHeight=true;
		TcxSSHeader *cHeader;

		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 20;
		cHeader->Size[1] = 30;
		cHeader->Size[2] = 90;
		cHeader->Size[3] = 90;
		cHeader->Size[4] = 200;
		cHeader->Size[5] = 40;
		cHeader->Size[6] = 80;
		cHeader->Size[7] = 60;
		cHeader->Size[8] = 60;


IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));

x=1;


rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=DMSprFirm->ElementFNAMEFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
delete cell;

y++;

rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s=DMSprFirm->ElementPADRFIRM->AsString+
				" Телефон: "+DMSprFirm->ElementTELFIRM->AsString;
cell->Text=s;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
prForm->SetRowsHeightAuto(y, x, x+2,20,s);

x=5;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="ИНН "+DMSprFirm->ElementINNFIRM->AsString;
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

DMSprFirm->kanRelease();
y++;

x=5;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="\"____\" _________________200  г.";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haLEFT;
delete cell;

y++;
y++;
y++;

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Отдел бронирования";
cell->Style->HorzTextAlign = haCENTER;
delete cell;
y++;
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="подтверждение брони";
cell->Style->HorzTextAlign = haCENTER;
delete cell;
y++;
y++;
y++;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString));

x=1;

rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s="Организация: "+DMSprKlient->ElementNAMEKLIENT->AsString;
cell->Text=s;
cell->Style->WordBreak = true;
delete cell;
prForm->SetRowsHeightAuto(y, x, x+3,20,s);


x=6;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Дата: "+DateToStr(DM->DocAllPOS_HOT_GALLDOC->AsDateTime);
delete cell;

y++;
x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+3;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s="Адресовано: __________________________";
cell->Text=s;
delete cell;
prForm->SetRowsHeightAuto(y, x, x+2,20,s);

x=6;
cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="Номер брони: "+DM->DocAllNUMBER_HOT_GALLDOC->AsString;
delete cell;

y++; y++;
x=1;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s="Благодарим Вас за то, что Вы выбрали нашу гостиницу.";
cell->Text=s;
delete cell;

y++;  y++;
x=1;

rect.Left = x;
rect.Top = y;
rect.Right = x+6;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s="Подтверждаем следующее бронирование:";
cell->Text=s;
delete cell;


y++;  y++;
//табличная часть

//№
x=1;
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="№";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//заезд
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Заезд";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//выезд
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Выезд";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//категория
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Категория";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//количество мест
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Мест";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
//гость
rect.Left = x;
rect.Top = y;
rect.Right = x+2;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Гость";
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
x++;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

y++;
int num=1;
//*********************
DM->DocT->First();
while(!DM->DocT->Eof)
	{
	//№
	x=1;
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=IntToStr(num);
	cell->Style->Font->Size = 10;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	//заезд
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=DM->DocTPOSNACH_HOT_SOSTNF->AsString;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	//выезд
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=DM->DocTPOSCON_HOT_SOSTNF->AsString;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	//категория
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=DM->DocTNAME_HOT_SCATNOM->AsString;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	//количество мест
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=DM->DocTKOLM_HOT_SOSTNF->AsString;
	cell->Style->Font->Size = 10;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	//гость
	rect.Left = x;
	rect.Top = y;
	rect.Right = x+2;
	rect.Bottom = y;
	prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->HorzTextAlign = haCENTER;
	cell->Text=DMSprKlient->ElementFNAME->AsString;
	cell->Style->Font->Size = 10;
	cell->Style->WordBreak = true;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	x++;
	prForm->SS->ActiveSheet->SetMergedState(rect, true);
	cell = prForm->SS->ActiveSheet->GetCellObject(x,y);
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;





	DM->DocT->Next();
	y++;
	num++;
	}
//***********************

y++;





//подвал

x=1;
rect.Left = x;
rect.Top = y;
rect.Right = x+7;
rect.Bottom = y;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
s="     Информируем Вас о том, что в случае не заезда или поздней аннуляции заказа (менее 48 часов) Вам будет предьявлен штраф в размере 100% стоимости номера.";
cell->Text=s;
cell->Style->WordBreak = true;
delete cell;

prForm->SetRowsHeightAuto(y, x, x+7,20,s);
y++; y++;

x=1;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="С уважением  ";
delete cell;

y++;

x=4;

cell = prForm->SS->ActiveSheet->GetCellObject(x, y);
cell->Text="отдел бронирования  ";
delete cell;

y++;
DMSprKlient->kanRelease();
prForm->SS->EndUpdate();
prForm->Show();
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::ToolButton4Click(TObject *Sender)
{
OpenPrintFormPotvBron();	
}
//---------------------------------------------------------------------------
//-------------------------------------------------------------------------
void THOT_FormaDocBron::CreateDocOtmenaBron(void)
{
IHOT_FormaDocOtmenaBron * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocOtmenaBron.1",IID_IHOT_FormaDocOtmenaBron,
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
doc->DM->DocDESCR_HOT_DOTMBRON->AsString="Основание: Размещение №" +
					DM->DocAllNUMBER_HOT_GALLDOC->AsString+
					" от "+DM->DocAllPOS_HOT_GALLDOC->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	doc->DM->AddString();
	doc->DM->DocT->Edit();
	doc->DM->DocTIDSOST_HOT_DOTMBRONT->AsString=DM->DocTIDSOST_HOT_DBRONT->AsString;
	doc->DM->DocTNAME_HOT_SNF->AsString=DM->DocTNAME_HOT_SNF->AsString;
	doc->DM->DocTNAMEKLIENT->AsString=DM->DocTNAMEKLIENT->AsString;
	doc->DM->DocTNAME_HOT_STYPEPOS->AsString=DM->DocTNAME_HOT_STYPEPOS->AsString;
	doc->DM->DocTNAME_HOT_SCATNOM->AsString=DM->DocTNAME_HOT_SCATNOM->AsString;
	doc->DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime=DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime;
	doc->DM->DocTPOSCON_HOT_SOSTNF->AsDateTime=DM->DocTPOSCON_HOT_SOSTNF->AsDateTime;
	doc->DM->DocTKOLM_HOT_SOSTNF->AsInteger=DM->DocTKOLM_HOT_SOSTNF->AsInteger;

    doc->DM->DocT->Post();
	DM->DocT->Next();
	}

doc->UpdateForm();	
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocBron::cxButtonCreateDocOtmenaBronClick(
      TObject *Sender)
{
CreateDocOtmenaBron();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
TDateTime pos_nach;
TDateTime pos_con;
__int64 id_nom;
AnsiString name_nom;
__int64 id_cat;
AnsiString name_cat;

pos_nach=DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime;
pos_con=DM->DocTPOSCON_HOT_SOSTNF->AsDateTime;
id_nom=glStrToInt64(DM->DocTIDNOMER_HOT_SOSTNF->AsString);
name_nom=DM->DocTNAME_HOT_SNF->AsString;
id_cat=glStrToInt64(DM->DocTIDCAT_HOT_SOSTNF->AsString);
name_cat=DM->DocTNAME_HOT_SCATNOM->AsString;

DM->AddString();
//получим состояние бронирования
IDMSetup *s;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&s);
		s->Init(InterfaceMainObject,InterfaceImpl);
s->OpenElement(101);
if (s->ElementVALUE_SETUP->AsString!="")
	{
	IHOT_DMSprSostNom * sost;
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMSprSostNom.1",IID_IHOT_DMSprSostNom,
													(void**)&sost);
	sost->Init(InterfaceMainObject,InterfaceImpl);
	sost->OpenElement(s->ElementVALUE_SETUP->AsInteger);
	if (glStrToInt64(sost->ElementID_HOT_SSOSTNOM->AsString)>0)
		{
		DM->DocT->Edit();
		DM->DocTIDSOST_HOT_SOSTNF->AsString=sost->ElementID_HOT_SSOSTNOM->AsString;
		DM->DocTNAME_HOT_SSOSTNOM->AsString=sost->ElementNAME_HOT_SSOSTNOM->AsString;
		DM->DocT->Post();
		}
	sost->kanRelease();
	}
else
	{
    ShowMessage("Ошибка! Не задано состояние бронирования в таблице настроек! (Настройка 101)");
	}

s->kanRelease();

if(DM->DocT->RecordCount==1)  //1строка
	{  //добавим только позицию заезда //добавим плательщика гостем
	DM->DocT->Edit();
	DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime=Now();
		DM->DocTIDGUEST_HOT_SOSTNF->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
	DM->DocTNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
	DM->DocT->Post();
	}
else
	{//скопируем текущую строку
	DM->DocT->Edit();
	DM->DocTPOSNACH_HOT_SOSTNF->AsDateTime=pos_nach;
	DM->DocTPOSCON_HOT_SOSTNF->AsDateTime=pos_con;
	if (id_nom!=0)
		{
		DM->DocTIDNOMER_HOT_SOSTNF->AsString=id_nom;
		DM->DocTNAME_HOT_SNF->AsString=name_nom;
		}
	if (id_cat!=0)
		{
		DM->DocTIDCAT_HOT_SOSTNF->AsString=id_cat;
		DM->DocTNAME_HOT_SCATNOM->AsString=name_cat;
		}
	DM->DocT->Post();
	}	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteString();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::NumbercxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::DescrcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THOT_FormaDocBron::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THOT_FormaDocBron::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall THOT_FormaDocBron::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocBron::ActionOKExecute(TObject *Sender)
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

void __fastcall THOT_FormaDocBron::ActionDvRegExecute(TObject *Sender)
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

void __fastcall THOT_FormaDocBron::ActionSaveExecute(TObject *Sender)
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

