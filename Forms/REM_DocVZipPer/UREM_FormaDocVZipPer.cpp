//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocVZipPer.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
#include "IREM_FormaDocVZipPer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxDBLabel"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocVZipPer::TREM_FormaDocVZipPer(TComponent* Owner)
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
bool TREM_FormaDocVZipPer::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipPer,IID_IREM_DMDocVZipPer, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameSkladPolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

OperationDoccxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;

Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
ActionOperation=aoNO;





//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocVZipPerImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
		DMTableExtPrintForm->Table->Next();
		}

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaDocVZipPer::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::UpdateForm(void)
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
void __fastcall TREM_FormaDocVZipPer::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

if(SpisokTypeNom)SpisokTypeNom->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokHardware)SpisokHardware->kanRelease();
if(FormaSpiskaSprStorageLocation)FormaSpiskaSprStorageLocation->kanRelease();
if(SpisokHardwareVZip)SpisokHardwareVZip->kanRelease();

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
int TREM_FormaDocVZipPer::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)
				{
				EndViborInfBase();
				}
		FormaSpiskaSprInfBase=0;
		}

if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)
				{
				EndViborFirm();
				}
		FormaSpiskaSprFirm=0;
		}

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_SkladPol)
		{
		if (type_event==1)
				{
				EndViborSkladPol();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EndViborKlient();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Zayavka)
		{
		if (type_event==1)
				{
				EndViborRemZ();
				}
		FormaGurZ=0;
		}

if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}

if (number_procedure_end==ER_KlientProducer)
		{
		if (type_event==1)
				{
				EndViborKlientProducer()  ;
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_TypeNom)
		{
		if (type_event==1)
				{
				EndViborTypeNom()  ;
				}
		SpisokTypeNom=0;
		}


if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)
				{
				EndViborNom()  ;
				}
		SpisokNom=0;
		}

if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware()  ;
				}
		SpisokHardware=0;
		}

if (number_procedure_end==ER_ViborStorageLocationOtpr)
		{
		if (type_event==1)
				{
				EndViborStorageLocationOtpr()  ;
				}
		FormaSpiskaSprStorageLocation=0;
		}

if (number_procedure_end==ER_ViborStorageLocationPol)
		{
		if (type_event==1)
				{
				EndViborStorageLocationPol()  ;
				}
		FormaSpiskaSprStorageLocation=0;
		}

if (number_procedure_end==ER_ViborHWIsSprVosvrZip)
		{
		if (type_event==1)
				{
				EndViborHardwareVZip()  ;
				}
		SpisokHardwareVZip=0;
		}

return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocVZipPer::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprInfBase) return;
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		} 
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();

FormaSpiskaSprInfBase=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//выбор фирмы
void TREM_FormaDocVZipPer::ViborFirm(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
		//FormaSpiskaSprFirm->HintLabel->Caption="Выберите фирму для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborFirm(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDFIRM_REM_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
	DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	DM->DocAll->Post();

FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();  
}
//----------------------------------------------------------------------------
//выбор склада
void TREM_FormaDocVZipPer::ViborSklad(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLAD_REM_GALLDOC->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->DocAll->Post();
	UpdateForm();

FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор склада
void TREM_FormaDocVZipPer::ViborSkladPol(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_SkladPol;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborSkladPol(void)
{


	DM->Doc->Edit();
	DM->DocIDSKLADPOL_REM_DVZPER->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->Doc->Post();
	UpdateForm();

FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор клиента
void TREM_FormaDocVZipPer::ViborKlient(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//выбор заявки
void TREM_FormaDocVZipPer::ViborRemZ(void)
{
if(Prosmotr==true) return;
if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaGurZ.1",IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::EndViborRemZ(void)
{
if (ActionOperation==aoAddNewString)
	{
	DM->TableAppend();
	}

	DM->DocT->Edit();
	DM->DocTIDZ_REM_DVZPERT->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->DocTNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocTKLIENT_NAME_REM_Z->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	DM->DocTMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocTNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	DM->DocTPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
	DM->DocTSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->DocTSERNUM2_REM_Z->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	DM->DocT->Post();

FormaGurZ=0;


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVZipPer::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPostOtDilera");
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocVZipPer::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaDocVZipPer::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborRemZ();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocVZipPer::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::BeforeSaveDoc(void)
{
//if (DM->DocAllPOSDOC->AsDateTime > Date())
//	{
//	AnsiString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
//	String Z="Внимание!";
//	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//		{
//		DM->DocAll->Edit();
//		DM->DocAllPOSDOC->AsDateTime=Now();
//		DM->DocAll->Post();
//		}
//	}

}
//----------------------------------------------------------------------------




// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
////
////проверим есть ли строки
//if(DM->DocT->RecordCount>0)
//		{
//		String V="В табличной части документа есть строки. Пересчитать цены?";
//		String Z="Пересчитать цены?";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//				{
//				TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
//				DM->DocT->First();
//				while(!DM->DocT->Eof)
//						{
//						DM->DocT->Edit();
//						DM->DocTS_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // тип цен
//														DM->DocTS_IDNOM_DZAMENAT->AsInt64,         //номенклатура
//														DM->DocTS_IDED_DZAMENAT->AsInt64,   //единица
//														DM->DocTS_KF_DZAMENAT->AsFloat,     //кф единицы
//														0);                                  //базовая единица
//
//						DM->DocTP_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // тип цен
//														DM->DocTP_IDNOM_DZAMENAT->AsInt64,         //номенклатура
//														DM->DocTP_IDED_DZAMENAT->AsInt64,   //единица
//														DM->DocTP_KF_DZAMENAT->AsFloat,     //кф единицы
//														0);                                  //базовая единица
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}







void __fastcall TREM_FormaDocVZipPer::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocVZipPer::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
TypeEvent=1;
if (DM->SaveDoc()==true)
		{
        AfterSaveDoc();
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

void __fastcall TREM_FormaDocVZipPer::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaDocVZipPer::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::RunExternalModule(__int64 id_module, int type_module)
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

//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_REM_GALLDOC->AsString));
module->SetStringVariables("glUserName", DM_Connection->UserInfoFNAME_USER->AsString);


module->ExecuteModule();
}
//---------------------------------------------------------------------------



void TREM_FormaDocVZipPer::AfterSaveDoc(void)
{
////обновим дату ремонта и состояние в заявке  на Отремонтировано
//UnicodeString V="Обновить состояние и дату ремонта в заявке?";
//UnicodeString Z="Внимание!";
//if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//	{
//	__int64 idz=glStrToInt64(DM->DocIDZ_REM_DREMONT->AsString);
//
//	if (idz!=0)
//		{
//		IDMSetup * DMSetup;
//		InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//		DMSetup->Init(InterfaceMainObject,0);
//		__int64 id_new_sost=0;
//		DMSetup->OpenElement(320);
//		id_new_sost=glStrToInt64(DMSetup->ElementVALUE_SETUP->AsString);
//		DMSetup->kanRelease();
//
//
//		IREM_DMZayavka * dm_z;
//		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
//		dm_z->Init(InterfaceMainObject,InterfaceImpl);
//		dm_z->OpenDoc(idz);
//		dm_z->GurZ->Edit();
//		if (id_new_sost !=0)
//			{
//			dm_z->GurZIDSOST_REM_Z->AsString=id_new_sost;
//			}
//		dm_z->GurZPOSREMONT_REM_Z->AsDateTime=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
//		dm_z->GurZOUT_REM_Z->AsInteger=3; //отремонтировано
//		dm_z->GurZ->Post();
//		dm_z->SaveDoc();
//		dm_z->kanRelease();
//		}
//
//	}

}
//-----------------------------------------------------------------------------



void __fastcall TREM_FormaDocVZipPer::NumDocKlientcxDBTextEditKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::PosDocKlientcxDBDateEditKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRemZ();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDZ_REM_DVZPERT->Clear();
		DM->DocT->Post();
		}break;
	}

}
//---------------------------------------------------------------------------

void TREM_FormaDocVZipPer::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void  TREM_FormaDocVZipPer::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::NameSkladPolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborSkladPol();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ToolButtonCreatePostClick(TObject *Sender)
{
		IREM_FormaDocVZipPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVZipPer,IID_IREM_FormaDocVZipPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();

		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->DocAllIDBASE_REM_GALLDOC->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->DocAllIDSKLAD_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
		doc->DM->DocAll->Post();

		doc->DM->Doc->Edit();
		doc->DM->DocIDSKLADPOL_REM_DVZPER->AsString=DM->DocIDSKLADPOL_REM_DVZPER->AsString;
		doc->DM->DocNAMESKLAD->AsString=DM->DocNAMESKLAD->AsString;
		doc->DM->DocOPER_REM_DVZPER->AsString=3;  /*Получение*/
		doc->DM->Doc->Post();


		DM->DocT->First();
		while (!DM->DocT->Eof)
			{
			doc->DM->DocT->Append();
			doc->DM->DocT->Edit();
			doc->DM->DocTIDZ_REM_DVZPERT->AsString=DM->DocTIDZ_REM_DVZPERT->AsString;
			doc->DM->DocTNUM_REM_Z->AsInteger=DM->DocTNUM_REM_Z->AsInteger;
			doc->DM->DocTPOS_REM_Z->AsDateTime=DM->DocTPOS_REM_Z->AsDateTime;
			doc->DM->DocTSERNUM_REM_Z->AsString=DM->DocTSERNUM_REM_Z->AsString;
			doc->DM->DocTMODEL_REM_Z->AsString=DM->DocTMODEL_REM_Z->AsString;
			doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->DocTKLIENT_NAME_REM_Z->AsString;
			doc->DM->DocTNAME_REM_Z->AsString=DM->DocTNAME_REM_Z->AsString;
			doc->DM->DocTKOL_REM_DVZPERT->AsFloat=1;

			doc->DM->DocTIDKLIENT_REM_DVZPERT->AsString=DM->DocTIDKLIENT_REM_DVZPERT->AsString;
			doc->DM->DocTNAMEKLIENT->AsString=DM->DocTNAMEKLIENT->AsString;
			doc->DM->DocTIDTNOM_REM_DVZPERT->AsString=DM->DocTIDTNOM_REM_DVZPERT->AsString;
			doc->DM->DocTNAME_STNOM->AsString=DM->DocTNAME_STNOM->AsString;
			doc->DM->DocTIDNOM_REM_DVZPERT->AsString=DM->DocTIDNOM_REM_DVZPERT->AsString;
			doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;

			doc->DM->DocTIDHW_REM_DVZPERT->AsString=DM->DocTIDHW_REM_DVZPERT->AsString;
			doc->DM->DocTNAME_REM_SHARDWARE->AsString=DM->DocTNAME_REM_SHARDWARE->AsString;

			doc->DM->DocTIDTVZIP_REM_DVZPERT->AsString=DM->DocTIDTVZIP_REM_DVZPERT->AsString;
			doc->DM->DocTNAME_REM_STVZIP->AsString=DM->DocTNAME_REM_STVZIP->AsString;

			doc->DM->DocT->Post();
			DM->DocT->Next();
			}
}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::ViborKlientProducer(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_KlientProducer;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborKlientProducer(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->DocT->Edit();
				DM->DocTIDKLIENT_REM_DVZPERT->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocTNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocT->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::OpenFormSpiskaSprTypeNom(void)
{
if (Prosmotr==true) return;
if (SpisokTypeNom==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprTypeNom,IID_IFormaSpiskaSprTypeNom,
													(void**)&SpisokTypeNom);
		SpisokTypeNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!SpisokTypeNom) return;
		SpisokTypeNom->Vibor=true;
		SpisokTypeNom->NumberProcVibor=ER_KlientProducer;
		//SpisokTypeNom->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborTypeNom(void)
{
if (SpisokTypeNom==0) return;

DM->DocT->Edit();
DM->DocTIDTNOM_REM_DVZPERT->AsString=SpisokTypeNom->DM->TableID_STNOM->AsString;
DM->DocTNAME_STNOM->AsString=SpisokTypeNom->DM->TableNAME_STNOM->AsString;
DM->DocT->Post();

SpisokTypeNom=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void TREM_FormaDocVZipPer::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNom,IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!SpisokNom) return;
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ER_Nom;
		SpisokNom->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborNom(void)
{
if (SpisokNom==0) return;

DM->DocT->Edit();
DM->DocTIDNOM_REM_DVZPERT->AsString=SpisokNom->DM->TableIDNOM->AsString;
DM->DocTNAMENOM->AsString=SpisokNom->DM->TableNAMENOM->AsString;
DM->DocT->Post();

SpisokNom=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//----------------------------------------------------------------------------
void TREM_FormaDocVZipPer::OpenFormSpiskaSprHardware(void)
{
if (Prosmotr==true) return;
if (SpisokHardware==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprHardware,IID_IREM_FormaSpiskaSprHardware,
													(void**)&SpisokHardware);
		SpisokHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!SpisokHardware) return;
		SpisokHardware->Vibor=true;
		SpisokHardware->NumberProcVibor=ER_Hardware;
		SpisokHardware->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborHardware(void)
{
if (SpisokHardware==0) return;

DM->DocT->Edit();
DM->DocTIDHW_REM_DVZPERT->AsString=SpisokHardware->DM->TableID_REM_SHARDWARE->AsString;
DM->DocTNAME_REM_SHARDWARE->AsString=SpisokHardware->DM->TableNAME_REM_SHARDWARE->AsString;
DM->DocT->Post();

SpisokHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborKlientProducer();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDKLIENT_REM_DVZPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAME_STNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprTypeNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDTNOM_REM_DVZPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDNOM_REM_DVZPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprHardware();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDHW_REM_DVZPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ToolButtonAddAllOstatkiClick(TObject *Sender)

{


DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();

UnicodeString z=
																								   \
"select rem_rgvzost.*,                                                                           \
		rem_z.name_rem_z,                                                                         \
		rem_z.num_rem_z,                                                                           \
		rem_z.pos_rem_z,                                                                           \
		rem_z.sernum_rem_z,                                                                        \
		rem_z.sernum2_rem_z,                                                                       \
		rem_z.klient_name_rem_z,                                                                   \
		rem_z.model_rem_z,                                                                         \
		sklient.nameklient,                                                                        \
		stnom.name_stnom,                                                                          \
		snom.namenom,                                                                              \
		rem_shardware.name_rem_shardware,                                                          \
		rem_shardware.sernum_rem_shardware,                                                        \
		rem_shardware.sernum2_rem_shardware,                                                       \
		rem_sprmodel.name_rem_sprmodel,                                                            \
		rem_rgvzost.kol_rem_rgvzost                                                                \
from  rem_rgvzost                                                                                  \
left outer join sklient on rem_rgvzost.idklient_rem_rgvzost=sklient.idklient                       \
left outer join stnom on rem_rgvzost.idtnom_rem_rgvzost=stnom.id_stnom                             \
left outer join snom on rem_rgvzost.idnom_rem_rgvzost=snom.idnom                                   \
left outer join rem_z on rem_rgvzost.idz_rem_rgvzost=rem_z.id_rem_z                                \
left outer join rem_shardware on rem_rgvzost.idhw_rem_rgvzost=rem_shardware.id_rem_shardware       \
left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shardware=rem_sprmodel.id_rem_sprmodel ";

DM->pFIBQ->SQL->Add(z);
DM->pFIBQ->ExecQuery();



while(!DM->pFIBQ->Eof)
		{
		DM->DocT->Append();
		DM->DocTIDZ_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDZ_REM_RGVZOST")->AsInt64;
		DM->DocTNUM_REM_Z->AsInteger=DM->pFIBQ->FieldByName("num_rem_z")->AsInteger;
		DM->DocTPOS_REM_Z->AsDateTime=DM->pFIBQ->FieldByName("pos_rem_z")->AsDateTime;
		DM->DocTSERNUM_REM_Z->AsString=DM->pFIBQ->FieldByName("sernum_rem_z")->AsString;
		DM->DocTMODEL_REM_Z->AsString=DM->pFIBQ->FieldByName("model_rem_z")->AsString;
		DM->DocTKLIENT_NAME_REM_Z->AsString=DM->pFIBQ->FieldByName("klient_name_rem_z")->AsString;
		DM->DocTNAME_REM_Z->AsString=DM->pFIBQ->FieldByName("name_rem_z")->AsString;
		DM->DocTKOL_REM_DVZPERT->AsFloat=DM->pFIBQ->FieldByName("kol_rem_rgvzost")->AsFloat;

		DM->DocTIDKLIENT_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDKLIENT_REM_RGVZOST")->AsString;
		DM->DocTNAMEKLIENT->AsString=DM->pFIBQ->FieldByName("nameklient")->AsString;
		DM->DocTIDTNOM_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDTNOM_REM_RGVZOST")->AsString;
		DM->DocTNAME_STNOM->AsString=DM->pFIBQ->FieldByName("name_stnom")->AsString;
		DM->DocTIDNOM_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDNOM_REM_RGVZOST")->AsString;
		DM->DocTNAMENOM->AsString=DM->pFIBQ->FieldByName("namenom")->AsString;

		DM->DocTIDHW_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDHW_REM_RGVZOST")->AsString;
		DM->DocTNAME_REM_SHARDWARE->AsString=DM->pFIBQ->FieldByName("name_rem_shardware")->AsString;

		DM->DocT->Post();
		DM->pFIBQ->Next();
		}


DM->pFIBQ->Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_FormaDocVZipPer::ViborStorageLocationOtpr(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_OTPR_REM_DVZPERT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocationOtpr;

		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborStorageLocationOtpr(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_OTPR_REM_DVZPERT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN_OTPR->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}

//---------------------------------------------------------------------------
void  TREM_FormaDocVZipPer::ViborStorageLocationPol(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_POL_REM_DVZPERT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocationPol;

		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborStorageLocationPol(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_POL_REM_DVZPERT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN_POL->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAME_SMHRAN_OTPRPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocationOtpr();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_OTPR_REM_DVZPERT->Clear();
		DM->DocTNAME_SMHRAN_OTPR->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::cxGrid1DBTableView1NAME_SMHRAN_POLPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocationPol();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_POL_REM_DVZPERT->Clear();
		DM->DocTNAME_SMHRAN_POL->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::OpenFormSpiskaSprHardwareVZip(void)
{
if (Prosmotr==true) return;
if (SpisokHardwareVZip==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprHardwareVZip,IID_IREM_FormaSpiskaSprHardwareVZip,
													(void**)&SpisokHardwareVZip);
		SpisokHardwareVZip->Init(InterfaceMainObject,InterfaceImpl);
		if (!SpisokHardwareVZip) return;
		SpisokHardwareVZip->Vibor=true;
		SpisokHardwareVZip->IdHardware=glStrToInt64(DM->DocTIDHW_REM_DVZPERT->AsString);
		SpisokHardwareVZip->NumberProcVibor=ER_ViborHWIsSprVosvrZip;
		SpisokHardwareVZip->UpdateForm();
		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocVZipPer::EndViborHardwareVZip(void)
{
if (SpisokHardwareVZip==0) return;

DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();

UnicodeString z=
																										  \
"select rem_rgvzost.*,                                                                                    \
		rem_z.name_rem_z,                                                                                 \
		rem_z.num_rem_z,                                                                                  \
		rem_z.pos_rem_z,                                                                                  \
		rem_z.sernum_rem_z,                                                                               \
		rem_z.sernum2_rem_z,                                                                              \
		rem_z.klient_name_rem_z,                                                                          \
		rem_z.model_rem_z,                                                                                \
		sklient.nameklient,                                                                               \
		stnom.name_stnom,                                                                                 \
		snom.namenom,                                                                                     \
		rem_shardware.name_rem_shardware,                                                                 \
		rem_shardware.sernum_rem_shardware,                                                               \
		rem_shardware.sernum2_rem_shardware,                                                              \
		rem_sprmodel.name_rem_sprmodel,                                                                   \
		rem_rgvzost.kol_rem_rgvzost,                                                                      \
		smhran.name_smhran                                                                                \
from  rem_rgvzost                                                                                         \
left outer join sklient on rem_rgvzost.idklient_rem_rgvzost=sklient.idklient                              \
left outer join stnom on rem_rgvzost.idtnom_rem_rgvzost=stnom.id_stnom                                    \
left outer join snom on rem_rgvzost.idnom_rem_rgvzost=snom.idnom                                          \
left outer join rem_z on rem_rgvzost.idz_rem_rgvzost=rem_z.id_rem_z                                       \
left outer join rem_shardware on rem_rgvzost.idhw_rem_rgvzost=rem_shardware.id_rem_shardware              \
left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shardware=rem_sprmodel.id_rem_sprmodel        \
left outer join smhran on rem_rgvzost.idmhran_rem_rgvzost=smhran.id_smhran                                \
where rem_rgvzost.idhw_rem_rgvzost=:PARAM_IDHW ";

DM->pFIBQ->SQL->Add(z);

DM->pFIBQ->ParamByName("PARAM_IDHW")->AsString=SpisokHardwareVZip->DM->TableOUT_IDHW->AsString;

DM->pFIBQ->ExecQuery();



while(!DM->pFIBQ->Eof)
		{
		DM->DocT->Append();
		DM->DocTIDZ_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDZ_REM_RGVZOST")->AsInt64;
		DM->DocTNUM_REM_Z->AsInteger=DM->pFIBQ->FieldByName("num_rem_z")->AsInteger;
		DM->DocTPOS_REM_Z->AsDateTime=DM->pFIBQ->FieldByName("pos_rem_z")->AsDateTime;
		DM->DocTSERNUM_REM_Z->AsString=DM->pFIBQ->FieldByName("sernum_rem_z")->AsString;
		DM->DocTMODEL_REM_Z->AsString=DM->pFIBQ->FieldByName("model_rem_z")->AsString;
		DM->DocTKLIENT_NAME_REM_Z->AsString=DM->pFIBQ->FieldByName("klient_name_rem_z")->AsString;
		DM->DocTNAME_REM_Z->AsString=DM->pFIBQ->FieldByName("name_rem_z")->AsString;
		DM->DocTKOL_REM_DVZPERT->AsFloat=DM->pFIBQ->FieldByName("kol_rem_rgvzost")->AsFloat;

		DM->DocTIDKLIENT_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDKLIENT_REM_RGVZOST")->AsString;
		DM->DocTNAMEKLIENT->AsString=DM->pFIBQ->FieldByName("nameklient")->AsString;
		DM->DocTIDTNOM_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDTNOM_REM_RGVZOST")->AsString;
		DM->DocTNAME_STNOM->AsString=DM->pFIBQ->FieldByName("name_stnom")->AsString;
		DM->DocTIDNOM_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDNOM_REM_RGVZOST")->AsString;
		DM->DocTNAMENOM->AsString=DM->pFIBQ->FieldByName("namenom")->AsString;

		DM->DocTIDHW_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("IDHW_REM_RGVZOST")->AsString;
		DM->DocTNAME_REM_SHARDWARE->AsString=DM->pFIBQ->FieldByName("name_rem_shardware")->AsString;

		DM->DocTIDMHRAN_OTPR_REM_DVZPERT->AsString=DM->pFIBQ->FieldByName("idmhran_rem_rgvzost")->AsString;
		DM->DocTNAME_SMHRAN_OTPR->AsString=DM->pFIBQ->FieldByName("name_smhran")->AsString;

		DM->DocT->Post();
		DM->pFIBQ->Next();
		}


DM->pFIBQ->Close();

SpisokHardwareVZip=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocVZipPer::ToolButtonViborOborudClick(TObject *Sender)

{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;

OpenFormSpiskaSprHardwareVZip();

}
//---------------------------------------------------------------------------

