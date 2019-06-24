//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop



#include "UREM_FormaDocPrihNakl.h"

#include "IFormaElementaSprNom.h"
#include "IFormaElementaSprEd.h"
#include "IREM_FormaElementaSprHardware.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
#include "IDMDocPrihNakl.h"
#include "IREM_DMSprGrpModel.h"
#include "IREM_DMSprModel.h"
#include "IFormaDocPrihNakl.h"
#include "IREM_DMCustQuery.h"
#include "IDMSprPrice.h"
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
#pragma link "cxPC"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocPrihNakl::TREM_FormaDocPrihNakl(TComponent* Owner)
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
bool TREM_FormaDocPrihNakl::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPrihNakl,IID_IREM_DMDocPrihNakl, (void**)&DM);
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
DBTextSUM_REM_GALLDOC->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NumDocPostcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PosDocPostcxDBDateEdit->DataBinding->DataSource=DM->DataSourceDoc;


OtchetPostcxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;
OtvHrancxDBCheckBox->DataBinding->DataSource=DM->DataSourceDoc;



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
			 (void**)&DMSprTypePrice);
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
//розничный тип цен

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
					(void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprTypeRPrice->Table->First();
while (!DMSprTypeRPrice->Table->Eof)
		{
		TypeRPriceComboBox->Properties->Items->Add(DMSprTypeRPrice->TableNAME_TPRICE->AsString);
		DMSprTypeRPrice->Table->Next();
		}


//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
						 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocPrihNaklImpl),false);
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

//----------------------------------------------------------------------------
void TREM_FormaDocPrihNakl::UpdateForm(void)
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

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_REM_DPRN->AsString));
TypeRPriceComboBox->ItemIndex=DMSprTypeRPrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_REM_DPRN->AsString));
flObrabatChangeTypePrice=true;
flObrabatChangeRoznTypePrice=true;

//if (DM->SkladRozn==true)
//	{
//	cxGrid1DBTableView1RPRICE_DPRNT->Visible=true;
//	cxGrid1DBTableView1NAC_DPRNT->Visible=true;
//	cxGrid1DBTableView1RSUM_DPRNT->Visible=true;
//	TypeRPriceComboBox->Visible=true;
//	RTPriceLabel->Visible=true;
//	}
//else
//	{
//	cxGrid1DBTableView1RPRICE_DPRNT->Visible=false;
//	cxGrid1DBTableView1NAC_DPRNT->Visible=false;
//	cxGrid1DBTableView1RSUM_DPRNT->Visible=false;
//	TypeRPriceComboBox->Visible=false;
//	RTPriceLabel->Visible=false;
//	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocPrihNakl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(FormaGurDocPrihNakl)FormaGurDocPrihNakl->kanRelease();
if(REM_FormaGurCustQuery)REM_FormaGurCustQuery->kanRelease();
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
	i_callback->kanRelease(); i_callback=0;
	}



DMSprTypePrice->kanRelease();
DMSprTypeRPrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject > 0)
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
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

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
void __fastcall TREM_FormaDocPrihNakl::ReadShtrihCodEvent(int number, UnicodeString sh)
{
//


}
//---------------------------------------------------------------
int TREM_FormaDocPrihNakl::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)
        {
		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DPRNT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				if (DM->DocTKOL_REM_DPRNT->AsFloat > 0.001)  //задано количество
					{ //не изменяем
					}
				else
					{
					DM->DocTKOL_REM_DPRNT->AsFloat=1;
					}

				DM->DocTIDED_REM_DPRNT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DPRNT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;


				DM->DocTPRICE_REM_DPRNT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
														*DM->DocTKF_REM_DPRNT->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
						DM->DocTRPRICE_REM_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DPRNT->AsFloat;
					DMSprPrice->kanRelease();


                DM->DocT->Post();
                //DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOL_REM_DPRNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOL_REM_DPRNT->Focused=true;
			}
		}

if (number_procedure_end==ER_PodborNom)//==PodborNom)
		{

        }

if (number_procedure_end==ER_Ed)//==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_REM_DPRNT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_REM_DPRNT->AsFloat=Ed->DM->ElementKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE_REM_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
						DM->DocTPRICE_REM_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DPRNT->AsFloat;
					DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOL_REM_DPRNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOL_REM_DPRNT->Focused=true;
			}
        }

if (number_procedure_end==ER_Firm)//==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRM_REM_GALLDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//==SkladRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLAD_REM_GALLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
                DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
				DM->DocAll->Post();
				UpdateForm();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Klient)//==KlientRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=Klient->DM->Element->FieldByName("NAMEKLIENT")->AsString;
                DM->DocAll->Post();
                }
		Klient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_InfBase)//==ViborInfBase)
		{
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Part)
		{

		}


if (number_procedure_end==ER_GrpNom)
		{

		}

//редактирование параметров номенклатуры
if (number_procedure_end==ER_ElementNom)
		{
		if (type_event==1)
				{

				}

		}

//редактирование параметров единицы
if (number_procedure_end==ER_ElementEd)
		{
		if (type_event==1)
				{

				}

		}

//редактирование параметров оборудования
if (number_procedure_end==ER_ElementHW)
		{
		if (type_event==1)
				{

				}

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

if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_PrihNakl)
		{
		if (type_event==1)
				{
				 EndViborDocPrihNakl();
				}
		FormaGurDocPrihNakl=0;
		}

if (number_procedure_end==ER_ViborCustomerQuery)
		{
		if (type_event==1)
				{
				EndViborCustQuery()  ;
				}
		REM_FormaGurCustQuery=0;
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
//----------------------------------------------------------------------------
void  TREM_FormaDocPrihNakl::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DPRN->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TREM_FormaDocPrihNakl:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString);
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Ed->NumberProcVibor=ER_Ed;

        }
}

//----------------------------------------------------------------------------






void    TREM_FormaDocPrihNakl::OpenFormSpiskaSprFirm(void)
{
if(Prosmotr==true) return;
if (Firma==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
        Firma->Vibor=true;
        Firma->DM->OpenTable();
//        Firma->HintLabel->Caption="Выберите фирму для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Firma->NumberProcVibor=ER_Firm;
        }

}
//---------------------------------------------------------------------------
void  TREM_FormaDocPrihNakl::OpenFormSpiskaSprSklad(void)
{
if(Prosmotr==true) return;
if (Sklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->DM->OpenTable();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Sklad->NumberProcVibor=ER_Sklad;

        }

}
//---------------------------------------------------------------------------
void  TREM_FormaDocPrihNakl::OpenFormSpiskaSprKlient(void)
{
if(Prosmotr==true) return;
if (Klient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&Klient);
		Klient->Init(InterfaceMainObject,InterfaceImpl);
		Klient->Vibor=true;
		Klient->DM->OpenTable(0,false);
//        Klient->HintLabel->Caption="Выберите поставщика для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
		Klient->NumberProcVibor=ER_Klient;

		}


}
//-----------------------------------------------------------------------------




void __fastcall TREM_FormaDocPrihNakl::AddNewStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->AddDocNewString();
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::DeleteStringClick(TObject *Sender)
{
DM->DeleteStringDoc();        
}

//---------------------------------------------------------------------------

void TREM_FormaDocPrihNakl::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
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




void __fastcall TREM_FormaDocPrihNakl::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeRoznTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

 if ( TypeRPriceComboBox->ItemIndex!=0)
		{
		DMSprTypeRPrice->Table->First();
		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_REM_DPRN->AsString=DMSprTypeRPrice->TableID_TPRICE->AsString;
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
				IDMSprPrice *DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_REM_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
						DM->DocTRPRICE_REM_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DPRNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
        {
		UpdateForm();
         return;
		}

 if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_REM_DPRN->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_REM_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
						DM->DocTPRICE_REM_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DPRNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------




void TREM_FormaDocPrihNakl::BeforeSaveDoc(void)
{
if (DM->DocAllPOS_REM_GALLDOC->AsDateTime > Date())
	{
	UnicodeString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
	UnicodeString Z="Внимание!";
	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
		{
		DM->DocAll->Edit();
		DM->DocAllPOS_REM_GALLDOC->AsDateTime=Now();
		DM->DocAll->Post();
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocPrihNakl::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::IsmPriceCheckBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::PrimcxDBTextEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaDocPrihNakl::NumDocPostcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::PosDocPostcxDBDateEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaDocPrihNakl::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocPrihNakl::RunExternalModule(__int64 id_module, int type_module)
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
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocPrihNakl::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
BeforeSaveDoc();
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

void __fastcall TREM_FormaDocPrihNakl::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;

BeforeSaveDoc();

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

void __fastcall TREM_FormaDocPrihNakl::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
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


void __fastcall TREM_FormaDocPrihNakl::ActionEditNomExecute(TObject *Sender)
{
		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
		FormaElementa->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DPRN->AsString);
		FormaElementa->IdFirm=glStrToInt64(DM->DocAllIDFIRM_REM_GALLDOC->AsString);
		FormaElementa->NumberProcVibor=ER_ElementNom;
		//FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom="";
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ActionEditEdExecute(TObject *Sender)
{
IFormaElementaSprEd * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDED_REM_DPRNT->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_ElementEd;
}
//---------------------------------------------------------------------------

void TREM_FormaDocPrihNakl::OpenFormSpiskaSprProject(void)
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
void __fastcall TREM_FormaDocPrihNakl::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocPrihNakl::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TREM_FormaDocPrihNakl::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaDocPrihNakl::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void TREM_FormaDocPrihNakl::ViborHardware(void)
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
void TREM_FormaDocPrihNakl::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DPRNT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------





void __fastcall TREM_FormaDocPrihNakl::cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------
//выбор документа Приходная накладная
void TREM_FormaDocPrihNakl::ViborDocPrihNakl(void)
{

if (FormaGurDocPrihNakl==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocPrihNakl.1",IID_IFormaGurDocPrihNakl,
													(void**)&FormaGurDocPrihNakl);
	FormaGurDocPrihNakl->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurDocPrihNakl->NumberProcVibor=ER_PrihNakl;
	FormaGurDocPrihNakl->Vibor=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::EndViborDocPrihNakl(void)
{
	IDMSprNom * nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
	nom->Init(InterfaceMainObject,InterfaceImpl);

	IDMDocPrihNakl * doc;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&doc);
	doc->Init(InterfaceMainObject,InterfaceImpl);
	doc->OpenDoc(glStrToInt64(FormaGurDocPrihNakl->DM->TableIDDOC->AsString));
	doc->DocT->First();
	while(!doc->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(doc->DocTIDNOMPRNT->AsString));

		int kol=1;
		if (nom->ElementFL_ADD_IN_SOBORUD_SNOM->AsInteger == 1)
			{  //учет по серийным номерам
			kol=doc->DocTKOLPRNT->AsInteger;
			while (kol>0)
				{
				DM->DocT->Append();
				DM->DocT->Edit();
				DM->DocTDVREG_REM_DPRNT->AsInteger = nom->ElementFL_DVREG_SNOM->AsInteger;
				DM->DocTIDNOM_REM_DPRNT->AsString = doc->DocTIDNOMPRNT->AsString;
				DM->DocTNAMENOM->AsString = doc->DocTNAMENOM->AsString;
				DM->DocTARTNOM->AsString = doc->DocTARTNOM->AsString;
				DM->DocTCODENOM->AsString = doc->DocTCODENOM->AsString;
				DM->DocTIDED_REM_DPRNT->AsString = doc->DocTIDEDPRNT->AsString;
				DM->DocTNAMEED->AsString= doc->DocTNAMEED->AsString;
				DM->DocTKOL_REM_DPRNT->AsString = 1;
				DM->DocTKF_REM_DPRNT->AsFloat=doc->DocTKFPRNT->AsFloat;
				DM->DocTPRICE_REM_DPRNT->AsFloat=doc->DocTPRICEPRNT->AsFloat;
				DM->DocT->Post();
				kol--;
				}
			}
		else
			{
				DM->DocT->Append();
				DM->DocT->Edit();
                DM->DocTDVREG_REM_DPRNT->AsInteger = nom->ElementFL_DVREG_SNOM->AsInteger;
				DM->DocTIDNOM_REM_DPRNT->AsString = doc->DocTIDNOMPRNT->AsString;
				DM->DocTNAMENOM->AsString = doc->DocTNAMENOM->AsString;
				DM->DocTARTNOM->AsString = doc->DocTARTNOM->AsString;
				DM->DocTCODENOM->AsString = doc->DocTCODENOM->AsString;
				DM->DocTIDED_REM_DPRNT->AsString = doc->DocTIDEDPRNT->AsString;
				DM->DocTNAMEED->AsString= doc->DocTNAMEED->AsString;
				DM->DocTKOL_REM_DPRNT->AsString = doc->DocTKOLPRNT->AsFloat;
				DM->DocTKF_REM_DPRNT->AsFloat=doc->DocTKFPRNT->AsFloat;
				DM->DocTPRICE_REM_DPRNT->AsFloat=doc->DocTPRICEPRNT->AsFloat;
				DM->DocT->Post();
			}



		doc->DocT->Next();
		}

	DM->DocAll->Edit();
	DM->DocAllIDEXTDOC_REM_GALLDOC->AsString=doc->DocAllIDDOC->AsString;
	DM->DocAllTYPEEXTDOC_REM_GALLDOC->AsString=GC_TypeSubSystem_MainModul;
	DM->DocAll->Post();

	doc->kanRelease();
	nom->kanRelease();





}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonLoadNaOsnPrihNaklClick(TObject *Sender)

{
ViborDocPrihNakl();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonAddSprHWClick(TObject *Sender)
{
	IDMSprNom * nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
	nom->Init(InterfaceMainObject,InterfaceImpl);

	IREM_DMSprModel * dm_model;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel,IID_IREM_DMSprModel,
													(void**)&dm_model);
	dm_model->Init(InterfaceMainObject,InterfaceImpl);

	//получим группу куда будем добавлять новые элементы
	__int64 id_grp_hw=0;

	IREM_DMSprGrpHardware * grp_hw;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprGrpHardware.1",IID_IREM_DMSprGrpHardware,
													(void**)&grp_hw);
	grp_hw->Init(InterfaceMainObject,InterfaceImpl);

	id_grp_hw=grp_hw->FindPoName(DM->DocAllNAMEKLIENT->AsString);
	if (id_grp_hw==0)
		{//создаем новую группу
		grp_hw->NewElement(0);
		grp_hw->Element->Edit();
		grp_hw->ElementNAME_REM_SGRP_HARDWARE->AsString=DM->DocAllNAMEKLIENT->AsString;
		grp_hw->Element->Post();
		if (grp_hw->SaveElement()==false)
			{
			ShowMessage("Ошибка при создании группы оборудования: "+grp_hw->TextError);
			return;
			}
		id_grp_hw=glStrToInt64(grp_hw->ElementID_REM_SGRP_HARDWARE->AsString);
		}

	grp_hw->kanRelease();


	//получим группу моделей куда будем добавлять новые модели
	__int64 id_grp_model=0;

	IREM_DMSprGrpModel * grp_model;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprGrpModel,IID_IREM_DMSprGrpModel,
													(void**)&grp_model);
	grp_model->Init(InterfaceMainObject,InterfaceImpl);

	id_grp_model=grp_model->FindPoName(DM->DocAllNAMEKLIENT->AsString);
	if (id_grp_model==0)
		{//создаем новую группу
		grp_model->NewElement(0);
		grp_model->Element->Edit();
		grp_model->ElementNAME_REM_SGRPMODEL->AsString=DM->DocAllNAMEKLIENT->AsString;
		grp_model->Element->Post();
		id_grp_model=glStrToInt64(grp_model->ElementID_REM_SGRPMODEL->AsString);

		if (grp_model->SaveElement()==false)
			{
			ShowMessage("Ошибка при создании группы оборудования: "+grp_model->TextError);
			return;
			}
		}


	grp_model->kanRelease();

	//

	IREM_DMSprHardware * dm_hw;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
													(void**)&dm_hw);
	dm_hw->Init(InterfaceMainObject,InterfaceImpl);


	DM->DocT->First();
	while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));

		if (nom->ElementFL_ADD_IN_SOBORUD_SNOM->AsInteger == 1
						&& glStrToInt64(DM->DocTIDHW_REM_DPRNT->AsString)==0)
			{  //учет по серийным номерам
			   //для начала получим модель
			__int64 id_model=0;
			id_model=dm_model->FindPoNom(glStrToInt64(DM->DocTIDNOM_REM_DPRNT->AsString));
			if (id_model==0)
				{
				dm_model->NewElement(id_grp_model);
				dm_model->Element->Edit();
				dm_model->ElementNAME_REM_SMODEL->AsString=DM->DocTNAMENOM->AsString;
				dm_model->ElementIDNOM_REM_SMODEL->AsString=DM->DocTIDNOM_REM_DPRNT->AsString;
				dm_model->Element->Post();
				id_model=glStrToInt64(dm_model->ElementID_REM_SMODEL->AsString);
				dm_model->SaveElement();

				}


			DM->DocT->Edit();
			dm_hw->NewElement(id_grp_hw);
			dm_hw->Element->Edit();
			dm_hw->ElementNAME_REM_SHARDWARE->AsString=
					DM->DocTNAMENOM->AsString;
			dm_hw->ElementPOSDOC_DOCPOST->AsDateTime=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
			dm_hw->ElementIDMODEL_REM_SHARDWARE->AsString=id_model;
			dm_hw->ElementIDPOST_REM_SHARDWARE->AsString=DM->DocAllIDKLIENT_REM_GALLDOC->AsString;
            dm_hw->ElementIDDOCPOST_REM_SHARDWARE->AsString=DM->DocAllIDEXTDOC_REM_GALLDOC->AsString;
			dm_hw->Element->Post();
			dm_hw->SaveElement();

			DM->DocTIDHW_REM_DPRNT->AsString=dm_hw->ElementID_REM_SHARDWARE->AsString;
			DM->DocTNAME_REM_SHARDWARE->AsString=dm_hw->ElementNAME_REM_SHARDWARE->AsString;
			DM->DocTCODE_REM_SHARDWARE->AsString=dm_hw->ElementCODE_REM_SHARDWARE->AsString;
			DM->DocTSERNUM_REM_SHARDWARE->AsString=dm_hw->ElementSERNUM_REM_SHARDWARE->AsString;

            DM->DocT->Post();
			}

		DM->DocT->Next();
		}

    dm_hw->kanRelease();
	nom->kanRelease();
	dm_model->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ActionEditOborudExecute(TObject *Sender)
{
		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprHardware.1",IID_IREM_FormaElementaSprHardware,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDHW_REM_DPRNT->AsString));
		FormaElementa->NumberProcVibor=ER_ElementHW;
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonSetDvRegAllClick(TObject *Sender)

{
DM->DocT->First();

while (!DM->DocT->Eof)
	{
	DM->DocT->Edit();
	DM->DocTDVREG_REM_DPRNT->AsInteger=1;
	DM->DocT->Post();
	DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonCancelDvRegAllClick(TObject *Sender)

{
DM->DocT->First();

while (!DM->DocT->Eof)
	{
	DM->DocT->Edit();
	DM->DocTDVREG_REM_DPRNT->AsInteger=0;
	DM->DocT->Post();
	DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------

void TREM_FormaDocPrihNakl::OpenFormGurCustQuery(void)
{
if(Prosmotr==true) return;
if (REM_FormaGurCustQuery==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurCustQueryDetal,IID_IREM_FormaGurCustQueryDetal,
													(void**)&REM_FormaGurCustQuery);
		REM_FormaGurCustQuery->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaGurCustQuery) return;
		REM_FormaGurCustQuery->Vibor=true;
		REM_FormaGurCustQuery->NumberProcVibor=ER_ViborCustomerQuery;
		//FormaSpiskaSprProducer->UpdateForm();
		}


}
//----------------------------------------------------------------------------
void TREM_FormaDocPrihNakl::EndViborCustQuery(void)
{

				DM->DocT->Edit();
				DM->DocTIDCQT_REM_DPRNT->AsString=REM_FormaGurCustQuery->DM->TableID_REM_CQUERYT->AsString;
				DM->DocTNUM_REM_CQUERY->AsString=REM_FormaGurCustQuery->DM->TableNUM_REM_CQUERY->AsString;

                DM->DocT->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::cxGrid1DBTableView1NAME_REM_CQUERYPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormGurCustQuery();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonCreateDocPrihNaklClick(TObject *Sender)

{
UnicodeString zapros="select rem_dprnt.idnom_rem_dprnt,             \
	   snom.namenom,                                                \
	   rem_dprnt.ided_rem_dprnt,                                     \
	   sed.nameed,                                                  \
	   rem_dprnt.kf_rem_dprnt,                                      \
	   rem_dprnt.price_rem_dprnt,                                   \
	   sum(rem_dprnt.kol_rem_dprnt) as sum_kol                      \
from rem_dprnt                                                      \
left outer join snom on rem_dprnt.idnom_rem_dprnt=snom.idnom        \
left outer join sed on rem_dprnt.ided_rem_dprnt=sed.ided            \
where rem_dprnt.iddoc_rem_dprnt=:PARAM_IDDOC                        \
group by                                                            \
		rem_dprnt.idnom_rem_dprnt,                                  \
		snom.namenom,                                               \
		rem_dprnt.ided_rem_dprnt,                                   \
		sed.nameed,                                                \
		rem_dprnt.kf_rem_dprnt,                                    \
		rem_dprnt.price_rem_dprnt ";

IFormaDocPrihNakl * doc;

//надо проверить может уже есть

DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select galldoc.iddoc from galldoc");
DM->pFIBQ->SQL->Add(" where galldoc.idextdoc=:PARAM_IDDOC and  galldoc.tdoc='PRN'");


DM->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
DM->pFIBQ->ExecQuery();

__int64 id_doc=glStrToInt64(DM->pFIBQ->FieldByName("iddoc")->AsString);



InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocPrihNakl,IID_IFormaDocPrihNakl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

bool fl_create_doc=false;

if (id_doc > 0)
	{
	fl_create_doc=false;
	}
else
	{
    fl_create_doc=true;
	}

if (fl_create_doc == false)
		{
		 //откроем документ
		doc->DM->OpenDoc(id_doc);
		doc->UpdateForm();
		}


if (fl_create_doc == true)
		{
		//создадим документ


		doc->DM->NewDoc();
		doc->DM->DocAll->Edit();

		doc->DM->DocAllIDEXTDOC->AsString=DM->DocAllID_REM_GALLDOC->AsString;
		doc->DM->DocAllTYPEEXTDOC->AsInteger=2;


		doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_REM_GALLDOC->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLDOC->AsInteger=DM->DocAllIDSKLAD_REM_GALLDOC->AsInteger;
		doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
		doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLIENT_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
		doc->DM->DocAll->Post();

		doc->DM->Doc->Edit();
		doc->DM->DocIDTPRICE->AsString=DM->DocIDTPRICE_REM_DPRN->AsString;
		doc->DM->DocPRIMDOC->AsString="На основании Приходной накладной (ремонт) №"+DM->DocAllNUM_REM_GALLDOC->AsString+
								" от "+ DM->DocAllPOS_REM_GALLDOC->AsString;
		doc->DM->Doc->Post();

		DM->pFIBQ->Close();
		DM->pFIBQ->SQL->Clear();
		DM->pFIBQ->SQL->Add(zapros);
		DM->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
		DM->pFIBQ->ExecQuery();


		while(!DM->pFIBQ->Eof)
			{

				doc->DM->DocT->Append();
				doc->DM->DocTIDNOMPRNT->AsString=DM->pFIBQ->FieldByName("idnom_rem_dprnt")->AsString;
				doc->DM->DocTNAMENOM->AsString=DM->pFIBQ->FieldByName("NAMENOM")->AsString;
				doc->DM->DocTIDEDPRNT->AsString=DM->pFIBQ->FieldByName("ided_rem_dprnt")->AsString;
				doc->DM->DocTNAMEED->AsString=DM->pFIBQ->FieldByName("NAMEED")->AsString;
				doc->DM->DocTKOLPRNT->AsFloat=DM->pFIBQ->FieldByName("sum_kol")->AsFloat;
				doc->DM->DocTKFPRNT->AsFloat=DM->pFIBQ->FieldByName("kf_rem_dprnt")->AsFloat;
				doc->DM->DocTPRICEPRNT->AsFloat=DM->pFIBQ->FieldByName("price_rem_dprnt")->AsFloat;


				doc->DM->DocT->Post();

			DM->pFIBQ->Next();
			}
		doc->UpdateForm();
		}




}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocPrihNakl::ToolButtonSetPostupiloClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);


	DM->DocT->First();

	while (!DM->DocT->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->DocTID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocRUN_REM_CQUERY->AsInteger=1; /*не активно выполнено*/
		dm_cq->DocPOSTUPILO_REM_CQUERY->AsDateTime=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->DocT->Next();
		}


dm_cq->kanRelease();
}
//---------------------------------------------------------------------------
void  TREM_FormaDocPrihNakl::ViborStorageLocation(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_REM_DPRNT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="Выберите склад для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocation;

        }

}
//---------------------------------------------------------------------------
void TREM_FormaDocPrihNakl::EndViborStorageLocation(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_REM_DPRNT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocPrihNakl::cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
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
		DM->DocTIDMHRAN_REM_DPRNT->Clear();
		DM->DocTNAME_SMHRAN->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

