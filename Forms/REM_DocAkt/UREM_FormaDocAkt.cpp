//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocAkt.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
#include "IDMSprSeller.h"
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
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxPC"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocAkt::TREM_FormaDocAkt(TComponent* Owner)
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
bool TREM_FormaDocAkt::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocAkt,IID_IREM_DMDocAkt, (void**)&DM);
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


NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2ZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
KlSoglasencxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
PodpisancxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
TypecxDBImageComboBox->DataBinding->DataSource=DM->DataSourceDoc;



cxDBTextEditNUM_U_PROISV_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNEISPR_KLIENTA_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNEISPR_SC_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNEISPR_BLOK_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_NAME_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_MODEL_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_SERNUM1_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_SERNUM2_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_SERNUM3_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_NUMUP_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditISD_NUMTEXLIST_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBDateEditISD_DATE_PRODAGI_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditKLIENT_NAME_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditKLIENT_ADR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditKLIENT_PHONE_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditPRODAVEC_NAME_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditRODAVEC_ADR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditPRODAVEC_TEL_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditKOMPL_STR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditNEKOMPL_STR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditMEXPOVR_STR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBImageComboBoxFL_FULL_KOMPL_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBImageComboBoxFL_MEXPOVR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBImageComboBoxFL_PRICHINA_ACTA_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBImageComboBoxFL_MESTONAX_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditPRICHINA_ACTA_DR_STR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBImageComboBoxFL_PRICHINA_SOST_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;
cxDBTextEditPRICHINA_SOST_DR_REM_DAKT->DataBinding->DataSource=DM->DataSourceDoc;



Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
ActionOperation=aoNO;





//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocAktImpl),false);
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
int TREM_FormaDocAkt::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocAkt::UpdateForm(void)
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
void __fastcall TREM_FormaDocAkt::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		i_callback->kanRelease();
		}

	}

DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocAkt::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocAkt::ViborInfBase(void)
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
void __fastcall TREM_FormaDocAkt::EndViborInfBase(void)
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
void TREM_FormaDocAkt::ViborFirm(void)
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
void __fastcall TREM_FormaDocAkt::EndViborFirm(void)
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
void TREM_FormaDocAkt::ViborSklad(void)
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
void __fastcall TREM_FormaDocAkt::EndViborSklad(void)
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
void TREM_FormaDocAkt::ViborKlient(void)
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
void __fastcall TREM_FormaDocAkt::EndViborKlient(void)
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
void TREM_FormaDocAkt::ViborRemZ(void)
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
void __fastcall TREM_FormaDocAkt::EndViborRemZ(void)
{

	DM->Doc->Edit();
	DM->DocIDZ_REM_DAKT->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
    DM->DocNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocNAME_REM_SMODEL->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->DocSERNUM2_REM_Z->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	DM->Doc->Post();

FormaGurZ=0;


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaDocAkt::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaDocAkt::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableAppend();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocAkt::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocAkt::BeforeSaveDoc(void)
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







void __fastcall TREM_FormaDocAkt::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
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
		DM->Doc->Edit();
		DM->DocIDZ_REM_DAKT->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocAkt::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocAkt::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocAkt::ActionSaveExecute(TObject *Sender)
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
void __fastcall TREM_FormaDocAkt::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocAkt::RunExternalModule(__int64 id_module, int type_module)
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



void TREM_FormaDocAkt::AfterSaveDoc(void)
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



void __fastcall TREM_FormaDocAkt::NumDocKlientcxDBTextEditKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::PosDocKlientcxDBDateEditKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocAkt::cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------

void TREM_FormaDocAkt::OpenFormSpiskaSprProject(void)
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
void  TREM_FormaDocAkt::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocAkt::OpenFormSpiskaSprBusinessOper(void)
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
void TREM_FormaDocAkt::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocAkt::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaDocAkt::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaDocAkt::ToolButtonAddDataIsZClick(TObject *Sender)
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
		z->OpenDoc(glStrToInt64(DM->DocIDZ_REM_DAKT->AsString));

			DM->Doc->Edit();
DM->DocNEISPR_KLIENTA_REM_DAKT->AsString=z->GurZNEISPR_REM_Z->AsString;
//DM->DocISD_NAME_REM_DAKT->AsString=DM->DataSourceDoc;
DM->DocISD_MODEL_REM_DAKT->AsString=z->GurZ_1NAME_REM_SPRMODEL->AsString;
DM->DocISD_SERNUM1_REM_DAKT->AsString=z->GurZSERNUM_REM_Z->AsString;
DM->DocISD_SERNUM2_REM_DAKT->AsString=z->GurZSERNUM2_REM_Z->AsString;
DM->DocISD_SERNUM3_REM_DAKT->AsString=z->GurZ_1SERNUM3_REM_Z_1->AsString;

DM->DocISD_DATE_PRODAGI_REM_DAKT->AsString=z->GurZ_1DATE_PRODAGI_REM_Z_1->AsString;

DM->DocKLIENT_NAME_REM_DAKT->AsString=z->GurZKLIENT_NAME_REM_Z->AsString;
DM->DocKLIENT_ADR_REM_DAKT->AsString=z->GurZKLIENT_ADR_REM_Z->AsString;
DM->DocKLIENT_PHONE_REM_DAKT->AsString=z->GurZKLIENT_PHONE_REM_Z->AsString;




		IDMSprSeller * s;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprSeller,IID_IDMSprSeller,
													(void**)&s);
		s->Init(InterfaceMainObject,InterfaceImpl);
		s->OpenElement(glStrToInt64(z->GurZ_1IDSELLER_REM_Z_1->AsString));

DM->DocPRODAVEC_NAME_REM_DAKT->AsString=s->ElementNAME_FOR_PRINT_SSELLER->AsString;
DM->DocPRODAVEC_ADR_REM_DAKT->AsString=s->ElementADR_SSELLER->AsString;
DM->DocPRODAVEC_TEL_REM_DAKT->AsString=s->ElementPHONE_SSELLER->AsString;

		s->kanRelease();
		z->kanRelease();

				DM->Doc->Post();









}
//---------------------------------------------------------------------------

