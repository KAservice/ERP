//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocZStart.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
#include "IREM_FormaZayavka.h"
#include "IAsyncExternalEvent.h"
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
__fastcall TREM_FormaDocZStart::TREM_FormaDocZStart(TComponent* Owner)
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
bool TREM_FormaDocZStart::Init(void)
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



	//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}
	}

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZStart,IID_IREM_DMDocZStart, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameKlientcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


TypeRemontcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
ProducerModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
KEM_SDANOcxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;
SerNum3cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum4cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumBatcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
DateVipuskcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
DateProdagicxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProdaveccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
ProdaveccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
CFCPRcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameNeisprcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
SOSTcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PODOcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NumGarDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum1cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;





//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocZStartImpl),false);
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

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaDocZStart::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::UpdateForm(void)
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
void __fastcall TREM_FormaDocZStart::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();

if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(FormaSpiskaSprProducerModel)FormaSpiskaSprProducerModel->kanRelease();
if(FormaSpiskaSprProducerNeispr)FormaSpiskaSprProducerNeispr->kanRelease();


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
int TREM_FormaDocZStart::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer();
				}
		FormaSpiskaSprProducer=0;
		}

if (number_procedure_end==ER_ViborProducerModel)
		{
		if (type_event==1)
				{
				EndViborProducerModel();
				}
		FormaSpiskaSprProducerModel=0;
		}


if (number_procedure_end==ER_ViborCFC)
		{
		if (type_event==1)
				{
				EndViborCFC();
				}
		FormaSpiskaSprProducerNeispr=0;
		}


return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocZStart::ViborInfBase(void)
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
void __fastcall TREM_FormaDocZStart::EndViborInfBase(void)
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
void TREM_FormaDocZStart::ViborFirm(void)
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
void __fastcall TREM_FormaDocZStart::EndViborFirm(void)
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
void TREM_FormaDocZStart::ViborSklad(void)
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
void __fastcall TREM_FormaDocZStart::EndViborSklad(void)
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
//выбор клиента
void TREM_FormaDocZStart::ViborKlient(void)
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
void __fastcall TREM_FormaDocZStart::EndViborKlient(void)
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
void TREM_FormaDocZStart::ViborRemZ(void)
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
void __fastcall TREM_FormaDocZStart::EndViborRemZ(void)
{

	DM->Doc->Edit();
	DM->DocIDZ_REM_DZSTART->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->DocNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocKLIENT_NAME_REM_Z->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	DM->DocMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
	DM->DocSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->DocSERNUM2_REM_Z->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	DM->Doc->Post();
	UpdateForm();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaDocZStart::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZStart::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRemont");
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaDocZStart::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------









void __fastcall TREM_FormaDocZStart::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZStart::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocZStart::BeforeSaveDoc(void)
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







void __fastcall TREM_FormaDocZStart::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocZStart::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocZStart::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocZStart::ActionSaveExecute(TObject *Sender)
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
void __fastcall TREM_FormaDocZStart::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::RunExternalModule(__int64 id_module, int type_module)
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



void TREM_FormaDocZStart::AfterSaveDoc(void)
{
//

}
//-----------------------------------------------------------------------------


void TREM_FormaDocZStart::ViborProducer(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&FormaSpiskaSprProducer);
		FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducer) return;
		FormaSpiskaSprProducer->Vibor=true;
		FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::EndViborProducer(void)
{

	DM->Doc->Edit();
	DM->DocIDPR_REM_DZSTART->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->DocNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::ViborProducerModel(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
													(void**)&FormaSpiskaSprProducerModel);
		FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerModel) return;
		FormaSpiskaSprProducerModel->flVibor=true;
		FormaSpiskaSprProducerModel->NumberProcVibor=ER_ViborProducerModel;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::EndViborProducerModel(void)
{

	DM->Doc->Edit();
	DM->DocIDPRMODEL_REM_DZSTART->AsString=FormaSpiskaSprProducerModel->DM->TableID_REM_SPRMODEL->AsString;
	DM->DocNAME_REM_SPRMODEL->AsString=FormaSpiskaSprProducerModel->DM->TableNAME_REM_SPRMODEL->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducerModel=0;

}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::ViborCFC(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNeispr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerNeispr,IID_IREM_FormaSpiskaSprProducerNeispr,
													(void**)&FormaSpiskaSprProducerNeispr);
		FormaSpiskaSprProducerNeispr->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNeispr) return;
		FormaSpiskaSprProducerNeispr->flVibor=true;
		FormaSpiskaSprProducerNeispr->NumberProcVibor=ER_ViborCFC;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZStart::EndViborCFC(void)
{

	DM->Doc->Edit();
	DM->DocIDCFCPR_REM_DZSTART->AsString=FormaSpiskaSprProducerNeispr->DM->TableID_REM_SPRNEISPR->AsString;
	DM->DocNAME_REM_SPRNEISPR->AsString=FormaSpiskaSprProducerNeispr->DM->TableNAME_REM_SPRNEISPR->AsString;
	DM->Doc->Post();

FormaSpiskaSprProducerNeispr=0;

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducer();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::ProducerModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerModel();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::CFCPRcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborCFC();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDCFCPR_REM_DZSTART->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZStart::ToolButtonOpenZayavkaClick(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DZSTART->AsString));
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::ToolButtonSetOtchitanZayvkaClick(TObject *Sender)

{
//обновим флаг отчитано

	__int64 idz=glStrToInt64(DM->DocIDZ_REM_DZSTART->AsString);

	if (idz!=0)
		{
		IREM_DMZayavka * dm_z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
		dm_z->Init(InterfaceMainObject,InterfaceImpl);
		dm_z->OpenDoc(idz);

		if (dm_z->GurZFL_ADDREPORT_REM_Z->AsString==1)
			{
            ShowMessage("Флаг отчитан уже установлен!");
			}
		else
			{
			dm_z->GurZ->Edit();
			dm_z->GurZFL_ADDREPORT_REM_Z->AsString=1;
			dm_z->GurZ->Post();
			dm_z->SaveDoc();
			}

		dm_z->kanRelease();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
LabelInfo->Caption="Подключен сканер штрих кода";
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZStart::FormDeactivate(TObject *Sender)
{
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
//событие считывания штрих-кода
void __fastcall TREM_FormaDocZStart::ReadShtrihCodEvent(int number, UnicodeString sh)
{
LabelInfo->Caption="Считан штрих код"+sh;
if (NumGarDoccxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocNUM_GARDOC_REM_Z->AsString=sh;
	DM->Doc->Post();
	}
else if (SerNum1cxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocSERNUM_REM_Z->AsString=sh;
	DM->Doc->Post();
	}
else if (SerNum2cxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocSERNUM2_REM_Z->AsString=sh;
	DM->Doc->Post();
	}
else if (SerNum3cxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocSERNUM3_REM_DZSTART->AsString=sh;
	DM->Doc->Post();
	}
else if (SerNum4cxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocSERNUM4_REM_DZSTART->AsString=sh;
	DM->Doc->Post();
	}
else if (NumBatcxDBTextEdit->Focused()==true)
	{
	DM->Doc->Edit();
	DM->DocNUMBAT_REM_DZSTART->AsString=sh;
	DM->Doc->Post();
	}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZStart::ToolButtonAddDataInZClick(TObject *Sender)
{
		String V="Вы действительно хотите заполнить по существующим данным из заявки?";
		String Z="Подтверждение ";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}



		IREM_DMZayavka * z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka,
													(void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		z->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DZSTART->AsString));

			DM->Doc->Edit();

				DM->DocIDPR_REM_DZSTART->AsString=z->GurZ_1IDPRODUCER_REM_Z_1->AsString;
				DM->DocNAME_SPRODUCER->AsString=z->GurZ_1NAME_SPRODUCER->AsString;

				DM->DocIDPRMODEL_REM_DZSTART->AsString=z->GurZ_1IDPRMODEL_REM_Z_1->AsString;
				DM->DocNAME_REM_SPRMODEL->AsString=z->GurZ_1NAME_REM_SPRMODEL->AsString;

				DM->DocIDCFCPR_REM_DZSTART->AsString=z->GurZ_1IDPRNEISPR_REM_Z_1->AsString;
				DM->DocNAME_REM_SPRNEISPR->AsString=z->GurZ_1NAME_REM_SPRNEISPR->AsString;

				DM->DocSERNUM3_REM_DZSTART->AsString=z->GurZ_1SERNUM3_REM_Z_1->AsString;
				DM->DocSERNUM4_REM_DZSTART->AsString=z->GurZ_1SERNUM4_REM_Z_1->AsString;

				DM->DocNUMBAT_REM_DZSTART->AsString=z->GurZ_1NUMBAT_REM_Z_1->AsString;
				DM->DocSOST_REM_DZSTART->AsString=z->GurZSOST_REM_Z->AsString;
				DM->DocDATEVIPUSK_REM_DZSTART->AsString=z->GurZ_1DATE_VIPUSK_REM_Z_1->AsString;
				DM->DocDATE_PRODAGI_REM_DZSTART->AsString=z->GurZ_1DATE_PRODAGI_REM_Z_1->AsString;
				DM->DocKEM_SDANO_REM_DZSTART->AsString=z->GurZ_1KEMSDANO_REM_Z_1->AsString;
				DM->DocTYPE_REMONT_REM_DZSTART->AsString=3;
				DM->DocPODO_REM_DZSTART->AsString=z->GurZ_1PODO_REM_Z_1->AsString;

				DM->DocIDSELLER_REM_DZSTART->AsString=z->GurZ_1IDSELLER_REM_Z_1->AsString;
				DM->DocNAME_SSELLER->AsString=z->GurZ_1NAME_SSELLER->AsString;
				DM->DocPRODAVEC_REM_DZSTART->AsString=z->GurZ_1NAME_SSELLER->AsString ;



				DM->Doc->Post();







	z->kanRelease();

//если не заполен тип цен, Поставщик ZIP

IDMSprProducer * dm_producer;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer,
													(void**)&dm_producer);
dm_producer->Init(InterfaceMainObject,0);
dm_producer->OpenElement(glStrToInt64(DM->DocIDPR_REM_DZSTART->AsString));


	DM->DocAll->Edit();
	DM->DocAllIDKLIENT_REM_GALLDOC->AsString=dm_producer->ElementIDKLIENT_SPRODUCER->AsString;
	DM->DocAllNAMEKLIENT->AsString=dm_producer->ElementNAMEKLIENT->AsString;
	DM->DocAll->Post();


dm_producer->kanRelease();


}
//---------------------------------------------------------------------------

