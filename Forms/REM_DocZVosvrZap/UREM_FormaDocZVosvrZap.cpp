//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocZVosvrZap.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSprPrice.h"
#include "IFormaRunExternalModule.h"
#include "IFormaDocReal.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocCheck.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
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
__fastcall TREM_FormaDocZVosvrZap::TREM_FormaDocZVosvrZap(TComponent* Owner)
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
bool TREM_FormaDocZVosvrZap::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVosvrZap,IID_IREM_DMDocZVosvrZap, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


//розничный тип цен
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();

TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypeRPrice->DataSourceTable;

NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameKlientcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2cxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;





//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocZVosvrZapImpl),false);
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
int TREM_FormaDocZVosvrZap::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::UpdateForm(void)
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
void __fastcall TREM_FormaDocZVosvrZap::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(FormaSpiskaSprStorageLocation)FormaSpiskaSprStorageLocation->kanRelease();

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
DMSprTypeRPrice->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocZVosvrZap::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)
				{
				EndViborNom();
				}
		FormaSpiskaSprNom=0;
		}

if (number_procedure_end==ER_Ed)
		{
		if (type_event==1)
				{
				EndViborEd();
				}
		FormaSpiskaSprEd=0;
		}



if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ViborStorageLocation)
		{
		if (type_event==1)
				{
				EndViborStorageLocation()  ;
                }
		FormaSpiskaSprStorageLocation=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}
return -1;
}
//---------------------------------------------------------------------------
//выбор информационной базы
void TREM_FormaDocZVosvrZap::ViborInfBase(void)
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
void __fastcall TREM_FormaDocZVosvrZap::EndViborInfBase(void)
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
void TREM_FormaDocZVosvrZap::ViborFirm(void)
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
void __fastcall TREM_FormaDocZVosvrZap::EndViborFirm(void)
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
void TREM_FormaDocZVosvrZap::ViborSklad(void)
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
void __fastcall TREM_FormaDocZVosvrZap::EndViborSklad(void)
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
void TREM_FormaDocZVosvrZap::ViborKlient(void)
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
void __fastcall TREM_FormaDocZVosvrZap::EndViborKlient(void)
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
void TREM_FormaDocZVosvrZap::ViborRemZ(void)
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
void __fastcall TREM_FormaDocZVosvrZap::EndViborRemZ(void)
{

	DM->Doc->Edit();
	DM->DocIDZ_REM_DZVZAP->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
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
//выбор номенклатуры
void TREM_FormaDocZVosvrZap::ViborNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprNom) return;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DZVZAP->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZVZAPT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZVosvrZap::EndViborNom(void)
{

                if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DZVZAPT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_REM_DZVZAPT->AsInteger=1;


				DM->DocTIDED_REM_DZVZAPT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DZVZAPT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZVZAPT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZVZAP->AsString), //тип цен
											glStrToInt64(DM->DocTIDNOM_REM_DZVZAPT->AsString),            //номенклатура
											glStrToInt64(DM->DocTIDED_REM_DZVZAPT->AsString),             //единица
											DM->DocTKF_REM_DZVZAPT->AsFloat,                              //коэффициент
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //базовая единица
					DMSprPrice->kanRelease();


				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);

		FormaSpiskaSprNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_REM_DZVZAPT->Selected=true;

ActionOperation=aoNO;		
}
//----------------------------------------------------------------------------
//выбор единицы
void TREM_FormaDocZVosvrZap::ViborEd(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprEd) return;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZVZAPT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DZVZAPT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Ремонт №"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZVosvrZap::EndViborEd(void)
{


	DM->DocT->Edit();
	DM->DocTIDED_REM_DZVZAPT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTKF_REM_DZVZAPT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;


					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZVZAPT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZVZAP->AsString), //тип цен
											glStrToInt64(DM->DocTIDNOM_REM_DZVZAPT->AsString),            //номенклатура
											glStrToInt64(DM->DocTIDED_REM_DZVZAPT->AsString),             //единица
											DM->DocTKF_REM_DZVZAPT->AsFloat,                              //коэффициент
											0);            //базовая единица
					DMSprPrice->kanRelease();


	DM->DocT->Post();

	FormaSpiskaSprEd=0;
	cxGrid1->SetFocus();
	cxGrid1DBTableView1PRICE_REM_DZVZAPT->Selected=true;
}

//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZVosvrZap::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRemont");
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocZVosvrZap::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
//if(flObrabatChangeRoznTypePrice==false) return;
//FindNextControl(ActiveControl,true,true,false)->SetFocus();
//
// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
//
// if ( TypeRPriceComboBox->ItemIndex!=0)
//		{
//		DMSprTypeRPrice->Table->First();
//		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
//		DM->Doc->Edit();
//		DM->DocIDRTPRICE_DVIPPROD->AsInt64=DMSprTypeRPrice->TableID_TPRICE->AsInt64;
//		DM->Doc->Post();
//		}
//else
//	{
//	ShowMessage("Тип цен должен быть задан обязательно!");
//	UpdateForm();
//	return;
//	}
//
////проверим есть ли строки
//if((DM->DocT->RecordCount>0) && (DM->SkladRozn==true))
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
//						DMSprPrice->FindElement( DM->DocIDRTPRICE_DVIPPROD->AsInt64,
//											 DM->DocTIDNOM_DVIPPRODT->AsInt64);
//						DM->DocTRPRICE_DVIPPRODT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
//														DM->DocTKF_DVIPPRODT->AsFloat;
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaDocZVosvrZap::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZVosvrZap::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::BeforeSaveDoc(void)
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







void __fastcall TREM_FormaDocZVosvrZap::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDNOM_REM_DZVZAPT->Clear();
		DM->DocTIDED_REM_DZVZAPT->Clear();
		DM->DocTNAMENOM->AsString="";
		DM->DocTNAMEED->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocZVosvrZap::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TREM_FormaDocZVosvrZap::ActionSaveExecute(TObject *Sender)
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
void __fastcall TREM_FormaDocZVosvrZap::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdString", glStrToInt64(DM->DocTID_REM_DZVZAPT->AsString));

module->ExecuteModule();
}
//---------------------------------------------------------------------------



void TREM_FormaDocZVosvrZap::AfterSaveDoc(void)
{
//

}

//-----------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::ViborHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DZVZAPT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void  TREM_FormaDocZVosvrZap::ViborStorageLocation(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_REM_DVZAPT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocation;

        }

}
//---------------------------------------------------------------------------
void TREM_FormaDocZVosvrZap::EndViborStorageLocation(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_REM_DVZAPT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocation();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_REM_DVZAPT->Clear();
		DM->DocTNAME_SMHRAN->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZVosvrZap::ToolButtonAddStringClick(TObject *Sender)

{

DM->TableAppend();

}
//---------------------------------------------------------------------------

