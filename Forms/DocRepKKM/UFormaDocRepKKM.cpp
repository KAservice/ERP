//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocRepKKM.h"
#include "IFormaSpiskaSprKKM.h"
#include "IFormaSpiskaSprDogovor.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxDBEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckBox"
#pragma link "cxPC"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRepKKM::TFormaDocRepKKM(TComponent* Owner)
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
bool TFormaDocRepKKM::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRepKKM.1",IID_IDMDocRepKKM, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogovorcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKKMcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumKLcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplNalcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplPCcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
DvRegcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

flObrabatChangeTypePrice=false;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
        TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
		}

ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRepKKMImpl),false);
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


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaDocRepKKM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocRepKKM::UpdateForm(void)
{
Prosmotr=DM->Prosmotr;
NoEdit=DM->NoEdit;

if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}
		
if (NoEdit==true)
        {
        //ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
        }
else
        {
        //ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		}

flObrabatChangeTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DREPKKM->AsString));
flObrabatChangeTypePrice=true;
		
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRepKKM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(SpisokKKM)SpisokKKM->kanRelease();
if(FormaSpiskaSprDogovor)FormaSpiskaSprDogovor->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(SpisokBSchet)SpisokBSchet->kanRelease();
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
		}
	i_callback->kanRelease();
	}

DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprTypePrice->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------




void TFormaDocRepKKM::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
        SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DREPKKMT->AsString));
        }
}
//-----------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DREPKKM->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->IdNom=DM->DocTIDNOM_DREPKKMT->AsInteger;
		SpisokNom->UpdateForm();
		SpisokNom->NumberProcVibor=ER_Nom;
        }

}
//----------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprDogovor(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprDogovor==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDogovor.1",IID_IFormaSpiskaSprDogovor,
													(void**)&FormaSpiskaSprDogovor);
		FormaSpiskaSprDogovor->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDogovor->Vibor=true;
		FormaSpiskaSprDogovor->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
        FormaSpiskaSprDogovor->DM->OpenTable(DM->DocAllIDKLDOC->AsInteger);
		//FormaSpiskaSprDogovor->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDogovor->NumberProcVibor=ER_Dogovor;
        }
}
//---------------------------------------------------------------------------
int TFormaDocRepKKM::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)//EditRekvisit==ViborTovar)
        {

		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
						}
                DM->DocT->Edit();
                DM->DocTIDNOM_DREPKKMT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOL_DREPKKMT->AsFloat=1;

				DM->DocTIDED_DREPKKMT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
                DM->DocTKF_DREPKKMT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;



                //DM->DocTZNACH_PRICE->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat;
                //DM->DocTPRICECHKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                //                                *DM->DocTKFCHKT->AsFloat;

                DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DREPKKMT->Selected=true;
        }

if (number_procedure_end==ER_Ed)//EditRekvisit==ViborEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_DREPKKMT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
                DM->DocTKF_DREPKKMT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
                
                //DM->DocTPRICECHKT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                //                                *DM->DocTKFCHKT->AsFloat;

                DM->DocT->Post();
                }
		SpisokEd=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICE_DREPKKMT->Selected=true;
        }

if (number_procedure_end==ER_Firm)//EditRekvisit==ViborFirm)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=SpisokFirm->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
                }
		SpisokFirm=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//EditRekvisit==ViborSklad)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=SpisokSklad->DM->ElementIDSKLAD->AsString;
                DM->DocAllNAMESKLAD->AsString=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                DM->DocAll->Post();
                }
		SpisokSklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Klient)//EditRekvisit==ViborKlient)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->DocAll->Post();
                }
		SpisokKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Dogovor)//EditRekvisit==ViborDogovor)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDDOGDOC->AsString=FormaSpiskaSprDogovor->DM->TableID_SDOG->AsString;
                DM->DocAllNAME_SDOG->AsString=FormaSpiskaSprDogovor->DM->TableNAME_SDOG->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprDogovor=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Kassa)//EditRekvisit==ViborKKM)
        {
		if (type_event==1)
				{
				DM->Doc->Edit();
				DM->DocIDKKM_DREPKKM->AsString=SpisokKKM->DM->ElementIDKKM->AsString;
                DM->DocNAMEKKM->AsString=SpisokKKM->DM->ElementNAMEKKM->AsString;
                DM->Doc->Post();
                }
		SpisokKKM=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }


if (number_procedure_end==ER_InfBase)//EditRekvisit==ViborInfBase)
        {
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
				}
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_BankSchet)
		{
		if (type_event==1)
				{
                EndViborBSchet();
				}
		SpisokBSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
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







ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------







void TFormaDocRepKKM::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ER_Firm;
        }

}
//---------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ER_Sklad;
        }

}
//--------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->NumberProcVibor=ER_Klient;
		}
}
//--------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprKKM(void)
{
if (Prosmotr==true) return;
if (SpisokKKM==NULL)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&SpisokKKM);
		SpisokKKM->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKKM->Vibor=true;
		SpisokKKM->NumberProcVibor=ER_Kassa;
	}
}
//--------------------------------------------------------------------------






void TFormaDocRepKKM::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
        }
}
//---------------------------------------------------------------------


void __fastcall TFormaDocRepKKM::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprNom();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

		OpenFormSpiskaSprEd();
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocRepKKM::NameKKMcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKKM();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NameDogovorcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRepKKM::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NumKLcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRepKKM::OplNalcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::OplPCcxDBCalcEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocRepKKM::TypePriceComboBoxPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
//if(flObrabatChangeTypePrice==false)return;
//FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
        }

if (NoEdit==true)
		{
		UpdateForm();
		 return;
		}

if (TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_DREPKKM->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
		{
		String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DREPKKM->AsString),
											 glStrToInt64(DM->DocTIDNOM_DREPKKMT->AsString));
						DM->DocTPRICE_DREPKKMT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DREPKKMT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				delete DMSprPrice;
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocRepKKM");
}
//---------------------------------------------------------------------------

void TFormaDocRepKKM::OpenFormSpiskaSprBSchet(void)
{ 
if (Prosmotr==true) return;
if (SpisokBSchet==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&SpisokBSchet);
		SpisokBSchet->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBSchet->NumberProcVibor=ER_BankSchet;
		SpisokBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBSchet->DM->OpenTable();
		//SpisokBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
		SpisokBSchet->Vibor=true;

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRepKKM::EndViborBSchet(void)
{

	DM->Doc->Edit();
	DM->DocIDBSCHET_DREPKKM->AsString=SpisokBSchet->DM->TableIDBSCHET->AsString;
	DM->DocNAMEBSCHET->AsString=SpisokBSchet->DM->TableNAMEBSCHET->AsString;
    DM->Doc->Post();


}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocRepKKM::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocRepKKM::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRepKKM::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocRepKKM::ActionDvRegExecute(TObject *Sender)
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
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocRepKKM::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocRepKKM::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocRepKKM::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRepKKM::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRepKKM::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

