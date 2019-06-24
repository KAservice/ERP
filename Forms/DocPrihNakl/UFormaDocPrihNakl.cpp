//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop



#include "UFormaDocPrihNakl.h"
#include "IFormaDocIsmPrice.h"
#include "IDMSprNacenka.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
#include "IFormaDocPer.h"
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
__fastcall TFormaDocPrihNakl::TFormaDocPrihNakl(TComponent* Owner)
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
bool TFormaDocPrihNakl::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
cxGrid2DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

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

cxGrid1DBTableView1SUM1->Visible=false;

//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
						 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocPrihNaklImpl),false);
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
void TFormaDocPrihNakl::UpdateForm(void)
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
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE->AsString));
TypeRPriceComboBox->ItemIndex=DMSprTypeRPrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString));
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
int TFormaDocPrihNakl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
if(FormaElementaSprPart)FormaElementaSprPart->kanRelease();
if(FormaViborGrpNomSpr)FormaViborGrpNomSpr->kanRelease();
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
void __fastcall TFormaDocPrihNakl::FormActivate(TObject *Sender)
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

void __fastcall TFormaDocPrihNakl::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaDocPrihNakl::ReadShtrihCodEvent(int number, UnicodeString sh)
{
//*****************
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	return;
	}

AnsiString s=sh;


IObjectBarCode * ob_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
ob_bar->Init(InterfaceMainObject,InterfaceImpl);

IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);

IDMSprEd * dm_ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
dm_ed->Init(InterfaceMainObject,InterfaceImpl);

ob_bar->SprNom=dm_nom;
ob_bar->SprEd=dm_ed;
ob_bar->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString);
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOMPRNT->AsString = dm_nom->ElementIDNOM->AsString;
	DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
	DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

	DM->DocTIDEDPRNT->AsString = dm_ed->ElementIDED->AsString;
	DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
	DM->DocTKFPRNT->AsFloat = dm_ed->ElementKFED->AsFloat;

	DM->DocTKOLPRNT->AsFloat=ob_bar->Kol;

	//получим цену
	IDMSprPrice * dm_price;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
	dm_price->Init(InterfaceMainObject,InterfaceImpl);
	if (DM->SkladRozn==true)
		{
		DM->DocTRPRICE_DPRNT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOMPRNT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDEDPRNT->AsString),    // единица
						DM->DocTKFPRNT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица
		}
	else
		{
		DM->DocTRPRICE_DPRNT->AsFloat=0;
		}

		DM->DocTPRICEPRNT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTPRICE->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOMPRNT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDEDPRNT->AsString),    // единица
						DM->DocTKFPRNT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица

	dm_price->kanRelease();

	DM->DocT->Post();

	VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

	if (TablecxPageControl->ActivePageIndex==0)
		{
		cxGrid1->Focused();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLPRNT->Focused=true;
		cxGrid1DBTableView1KOLPRNT->Selected=true;
		}
	}
else
	{
	 ShowMessage(ob_bar->TextError);
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();


}
//---------------------------------------------------------------
int TFormaDocPrihNakl::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOMPRNT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;
				if (DM->DocTKOLPRNT->AsFloat > 0.001)  //задано количество
					{ //не изменяем
					}
				else
					{
					DM->DocTKOLPRNT->AsFloat=1;
					}

				DM->DocTIDEDPRNT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKFPRNT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;


				DM->DocTPRICEPRNT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
														*DM->DocTKFPRNT->AsFloat;


				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOMPRNT->AsString));
						DM->DocTRPRICE_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPRNT->AsFloat;
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DPRNT->AsFloat=0;
					}

                DM->DocT->Post();
                //DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOLPRNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOLPRNT->Focused=true;
			}
        }

if (number_procedure_end==ER_PodborNom)//==PodborNom)
        {
		if (type_event==1)
                {
                DM->IsmSum=false;
                DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOMPRNT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;

				if (DM->DocTKOLPRNT->AsFloat > 0.1)
					{
					}
				else
					{
					DM->DocTKOLPRNT->AsFloat=Nom->FormaPodboraNom->Kol;
					}

				DM->DocTIDEDPRNT->AsString=Nom->FormaPodboraNom->IdEd;
                DM->DocTNAMEED->AsString=Nom->FormaPodboraNom->NameEd;
				DM->DocTKFPRNT->AsFloat=Nom->FormaPodboraNom->KFEd;

				DM->DocTPRICEPRNT->AsFloat=Nom->FormaPodboraNom->Price;
                DM->DocTSUMPRNT->AsFloat=Nom->FormaPodboraNom->Summa;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOMPRNT->AsString));

						DM->DocTRPRICE_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPRNT->AsFloat;
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DPRNT->AsFloat=0;
					}


                DM->DocT->Post();
				//DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                DM->IsmSum=true;
                }
        else
                {
				Nom=0;
                ActionOperation=aoNO;
                }
        }

if (number_procedure_end==ER_Ed)//==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDPRNT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKFPRNT->AsFloat=Ed->DM->ElementKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOMPRNT->AsString));
						DM->DocTPRICEPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPRNT->AsFloat;
					DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1PRICEPRNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1PRICEPRNT->Focused=true;
			}
        }

if (number_procedure_end==ER_Firm)//==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
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
				DM->DocAllIDSKLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
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
				DM->DocAllIDKLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
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
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Part)
		{
		if (type_event==1)
				{
				EndEditPart();
				}
		FormaElementaSprPart=0;
		}


if (number_procedure_end==ER_GrpNom)
		{
		if (type_event==1)
				{
				EndViborGrpNom();
				}
		FormaViborGrpNomSpr=0;
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
//----------------------------------------------------------------------------
void  TFormaDocPrihNakl::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOMPRNT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TFormaDocPrihNakl:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOMPRNT->AsString);
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Ed->NumberProcVibor=ER_Ed;

        }
}

//----------------------------------------------------------------------------






void    TFormaDocPrihNakl::OpenFormSpiskaSprFirm(void)
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
void  TFormaDocPrihNakl::OpenFormSpiskaSprSklad(void)
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
void  TFormaDocPrihNakl::OpenFormSpiskaSprKlient(void)
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
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		Klient->NumberProcVibor=ER_Klient;

		}


}
//-----------------------------------------------------------------------------




void __fastcall TFormaDocPrihNakl::AddNewStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->AddDocNewString();
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::DeleteStringClick(TObject *Sender)
{
DM->DeleteStringDoc();        
}

//---------------------------------------------------------------------------
void TFormaDocPrihNakl::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);;


numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();

}
//---------------------------------------------------------------------------
void TFormaDocPrihNakl::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=1;
numCol=2;


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
		cHeader->Size[2] = 40;
		cHeader->Size[3] = 230;
		cHeader->Size[4] = 50;
		cHeader->Size[5] = 60;
		cHeader->Size[6] = 50;
		cHeader->Size[7] = 60;
		cHeader->Size[8] = 60;
		cHeader->Size[9] = 60;
		cHeader->Size[10] = 60;
IDMSprFirm *spr_firm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&spr_firm);
spr_firm->Init(InterfaceMainObject,InterfaceImpl);
spr_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=spr_firm->ElementFNAMEFIRM->AsString
		+", ИНН "+spr_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+spr_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

spr_firm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Приходная накладная №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient *spr_klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&spr_klient);
spr_klient->Init(InterfaceMainObject,InterfaceImpl);
spr_klient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Поставщик: "+spr_klient->ElementFNAME->AsString+", ИНН "+spr_klient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+spr_klient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

spr_klient->kanRelease();
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMDOC->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
if(DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Р. цена";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 8;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Р. сумма";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 8;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	}
numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocPrihNakl::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOLPRNT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKFPRNT->AsFloat,ffFixed,10,3);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICEPRNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMPRNT->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if(DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRPRICE_DPRNT->AsFloat,ffFixed,10,2);
	cell->Style->Font->Size = 8;
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRSUM_DPRNT->AsFloat,ffFixed,10,2);
	cell->Style->Font->Size = 8;
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;


	}


}


//------------------------------------------------------------------------------
void TFormaDocPrihNakl::OutputPodavalReport(TSheetEditor *prForm)
{

TcxSSCellObject *cell;

numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Всего";
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(DM->DocTKFPRNT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text=FloatToStrF(DM->DocTPRICEPRNT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if(DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	//cell->Text=FloatToStrF(DM->DocTRPRICE_DPRNT->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Style->Font->Size = 8;
	cell->Style->Font->Style = TFontStyles() << fsBold;
	cell->Text=FloatToStrF(DM->DocRSUM_DPRN->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;


	}




numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Text="Всего наименований "+IntToStr(DM->DocT->RecordCount)+
                " на сумму "+FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,10,2);
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="("+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat)+" )";
delete cell;
numRow++;

for (int i=2;i<=8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Сдал  __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Принял  __________________________ ";
delete cell;
}
//---------------------------------------------------------------
//----------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::ToolButtonPodborClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->Podbor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//        Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//        +DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_PodborNom;
        }
}
//---------------------------------------------------------------------------

void TFormaDocPrihNakl::OpenFormSpiskaSprInfBase(void)
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




void __fastcall TFormaDocPrihNakl::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPrihNakl");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonUpdatePriceClick(TObject *Sender)
{
		String V="Обновить цены согласно заданной наценке?";
		String Z="Обновление цен";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				DM->UpdatePrice();
				ShowMessage("Обновление цен завершено!");
				}
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPrihNakl::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::TypeRPriceComboBoxPropertiesChange(
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
		DM->DocIDRTPRICE_DPRN->AsString=DMSprTypeRPrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),
											 glStrToInt64(DM->DocTIDNOMPRNT->AsString));
						DM->DocTRPRICE_DPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPRNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::TypePriceComboBoxPropertiesChange(
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
		DM->DocIDTPRICE->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOMPRNT->AsString));
						DM->DocTPRICEPRNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFPRNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------




void TFormaDocPrihNakl::BeforeSaveDoc(void)
{
if (DM->DocAllPOSDOC->AsDateTime > Date())
	{
	UnicodeString V="Может быть нарушена последовательность проведения документов! Изменить время документа на текущее?";
	UnicodeString Z="Внимание!";
	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
		{
		DM->DocAll->Edit();
		DM->DocAllPOSDOC->AsDateTime=Now();
		DM->DocAll->Post();
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TFormaDocPrihNakl::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::IsmPriceCheckBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void TFormaDocPrihNakl::OpenFormElementaSprPart(void)
{
if (glStrToInt64(DM->DocTIDNOMPRNT->AsString)>0)
	{
	if (FormaElementaSprPart==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprPart.1",IID_IFormaElementaSprPart,
													(void**)&FormaElementaSprPart);
		FormaElementaSprPart->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaSprPart->NumberProcVibor=8;

		if (glStrToInt64(DM->DocTIDPARTPRNT->AsString)>0)
			{
			FormaElementaSprPart->DM->OpenElement(glStrToInt64(DM->DocTIDPARTPRNT->AsString));
			if ((glStrToInt64(FormaElementaSprPart->DM->ElementIDDOCPART->AsString)==glStrToInt64(DM->DocAllIDDOC->AsString))
						&&(glStrToInt64(FormaElementaSprPart->DM->ElementIDNOMPART->AsString)==glStrToInt64(DM->DocTIDNOMPRNT->AsString)))
				{ //этот же документ и номеклатура
				}
			else
				{ //создаем новый элемент
				FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
				if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
					{
					FormaElementaSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
					}
				}
			}
		else
			{ //создаем новый элемент
			FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
			if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
				}
			}

		FormaElementaSprPart->DM->Element->Edit();
		if(glStrToInt64(DM->DocAllIDFIRMDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDFIRMPART->AsString=DM->DocAllIDFIRMDOC->AsString;
				}
		if(glStrToInt64(DM->DocAllIDKLDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDKLPART->AsString=DM->DocAllIDKLDOC->AsString;
				}
		FormaElementaSprPart->DM->ElementPRICEZPART->AsFloat=DM->DocTPRICEPRNT->AsFloat;
		FormaElementaSprPart->DM->ElementDOCPART->AsString="Прих. накл. "+DM->DocAllNUMDOC->AsString+" от " +DM->DocAllPOSDOC->AsString;

		FormaElementaSprPart->DM->ElementGTDPART->AsString=DM->DocTGTDPART->AsString;
		FormaElementaSprPart->DM->ElementSERTPART->AsString=DM->DocTSERTPART->AsString;
		if (DM->DocTSRGODNPART->AsFloat!=0)
				{
				FormaElementaSprPart->DM->ElementSRGODNPART->AsDateTime=DM->DocTSRGODNPART->AsDateTime;
				}
		FormaElementaSprPart->DM->Element->Post();
		}
	}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::EndEditPart(void)
{

	DM->DocT->Edit();
	DM->DocTIDPARTPRNT->AsString=FormaElementaSprPart->DM->ElementIDPART->AsString;

	DM->DocTGTDPART->AsString=FormaElementaSprPart->DM->ElementGTDPART->AsString;
	DM->DocTSERTPART->AsString=FormaElementaSprPart->DM->ElementSERTPART->AsString;
	if (FormaElementaSprPart->DM->ElementSRGODNPART->AsFloat!=0)
		{
		DM->DocTSRGODNPART->AsDateTime=FormaElementaSprPart->DM->ElementSRGODNPART->AsDateTime;
		}
	DM->DocT->Post();


}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::EditPropPartcxButtonClick(TObject *Sender)
{
OpenFormElementaSprPart();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::ActionSetMainTabSheetExecute(TObject *Sender)
{
TablecxPageControl->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ActionSetAdditionallyTabSheetExecute(
      TObject *Sender)
{
TablecxPageControl->ActivePageIndex=1;
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::ToolButtonCheckPriceNaRoznSkladeClick(
      TObject *Sender)
{
bool doc_create=false;
DM->DocT->First();
IFormaDocIsmPrice * doc=0;
while (!DM->DocT->Eof)
	{
	DM->pFIBQ->Close();
	DM->pFIBQ->SQL->Clear();
	DM->pFIBQ->SQL->Add(" select rggoods.idnom_rggoods,  ");
	DM->pFIBQ->SQL->Add(" rggoods.kol_rggoods,           ");
	DM->pFIBQ->SQL->Add(" rggoods.rprice_rggoods,        ");
	DM->pFIBQ->SQL->Add(" snom.namenom,                  ");
	DM->pFIBQ->SQL->Add(" sed.ided,                    ");
	DM->pFIBQ->SQL->Add(" sed.nameed                     ");
	DM->pFIBQ->SQL->Add(" from rggoods                   ");
	DM->pFIBQ->SQL->Add(" left outer join snom on rggoods.idnom_rggoods=snom.idnom   ");
	DM->pFIBQ->SQL->Add(" left outer join sed on snom.idbasednom=sed.ided    ");
	DM->pFIBQ->SQL->Add(" where rggoods.idfirm_rggoods=:PARAM_IDFIRM         ");
	DM->pFIBQ->SQL->Add(" 	and rggoods.idsklad_rggoods=:PARAM_IDSKLAD       ");
	DM->pFIBQ->SQL->Add("   and rggoods.idnom_rggoods=:PARAM_IDNOM         ");
	DM->pFIBQ->SQL->Add(" 	and rggoods.rprice_rggoods!=:PARAM_RPRICE        ");

	DM->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=
											DM->DocAllIDFIRMDOC->AsString;
	DM->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=
											DM->DocAllIDSKLDOC->AsString;
	DM->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=
											DM->DocTIDNOMPRNT->AsString;
	DM->pFIBQ->ParamByName("PARAM_RPRICE")->AsFloat=
											DM->DocTRPRICE_DPRNT->AsFloat;
	DM->pFIBQ->ExecQuery();
	if (DM->pFIBQ->RecordCount>0)
		{
		while (!DM->pFIBQ->Eof)
			{
			if (DM->pFIBQ->FieldByName("kol_rggoods")->AsFloat>0)
				{
				if (doc_create==false)
					{ //создаем новый документ
					InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocIsmPrice.1",IID_IFormaDocIsmPrice,
													(void**)&doc);
					doc->Init(InterfaceMainObject,InterfaceImpl);
					doc->DM->NewDoc();
					doc_create=true;
					doc->DM->DocAll->Edit();
					doc->DM->DocAllIDBASE_GALLDOC->AsString=
											DM->DocAllIDBASE_GALLDOC->AsString;
					doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=
											DM->DocAllNAME_SINFBASE_OBMEN->AsString;
					doc->DM->DocAllIDFIRMDOC->AsString=
											DM->DocAllIDFIRMDOC->AsString;
					doc->DM->DocAllNAMEFIRM->AsString=
											DM->DocAllNAMEFIRM->AsString;
					doc->DM->DocAllIDSKLDOC->AsString=
											DM->DocAllIDSKLDOC->AsString;
					doc->DM->DocAllNAMESKLAD->AsString=
											DM->DocAllNAMESKLAD->AsString;
					doc->DM->DocAll->Post();

					doc->DM->Doc->Edit();
					doc->DM->DocDESCR_DISMPRICE->AsString="На основании Приходной накладной №"+
								 DM->DocAllNUMDOC->AsString+" от "+
								 DM->DocAllPOSDOC->AsString;
					doc->DM->DocIDNEWTPRICE_DISMPRICE->AsString=
									DM->DocIDRTPRICE_DPRN->AsString;
					doc->DM->Doc->Post();


					doc->UpdateForm();

					}

				doc->DM->DocT->Append();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDNOM_DISMPRICET->AsString=
									DM->pFIBQ->FieldByName("idnom_rggoods")->AsString;
				doc->DM->DocTNAMENOM->AsString=
									DM->pFIBQ->FieldByName("namenom")->AsString;
				doc->DM->DocTIDED_DISMPRICET->AsString=
									DM->pFIBQ->FieldByName("ided")->AsString;
				doc->DM->DocTKOL_DISMPRICET->AsFloat=
									DM->pFIBQ->FieldByName("kol_rggoods")->AsFloat;
				doc->DM->DocTKF_DISMPRICET->AsFloat=1;
				doc->DM->DocTNAMEED->AsString=
									DM->pFIBQ->FieldByName("nameed")->AsString;
				doc->DM->DocTOLDPRICE_DISMPRICET->AsFloat=
									DM->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;
				doc->DM->DocTNEWPRICE_DISMPRICET->AsFloat=
									DM->DocTRPRICE_DPRNT->AsFloat;  
				doc->DM->DocT->Post();
                }
            DM->pFIBQ->Next();
            }
		}
    DM->pFIBQ->Close();
    DM->DocT->Next();
	}

if (doc==0)
	{
    ShowMessage("Нет товаров для переоценки!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocPrihNakl::ToolButtonShowSUM1Click(TObject *Sender)
{
if (ToolButtonShowSUM1->Down==true)
	{
	cxGrid1DBTableView1SUM1->Visible=true;
	}
else
	{
	cxGrid1DBTableView1SUM1->Visible=false;
	}
}
//---------------------------------------------------------------------------




void __fastcall TFormaDocPrihNakl::cxGrid1DBTableView1SUM1PropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{

double sum1=(double)VarAsType(DisplayValue,varDouble);
DM->DocT->Edit();
DM->DocTPRICEPRNT->AsFloat=sum1/DM->DocTKOLPRNT->AsFloat;
DM->DocT->Post();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::NumDocPostcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::PosDocPostcxDBDateEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonUpdatePriceBasEdClick(
      TObject *Sender)
{
IDMSprPrice * dm_price;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
dm_price->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);
//изменим цены в справочнике

	DM->DocT->First();
	while (!DM->DocT->Eof)
		{
		__int64 id_bas_ed=dm_nom->GetIdBasEd(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
		
				if (glStrToInt64(DM->DocIDTPRICE->AsString)!=0 && DM->DocTPRICEPRNT->AsFloat!=0)
					{
					//изменим закупочную цену в справочнике
					__int64 id_price=dm_price->FindElementPoEd(glStrToInt64(DM->DocIDTPRICE->AsString),
								glStrToInt64(DM->DocTIDNOMPRNT->AsString), id_bas_ed);
					if (id_price==0)
						{
						dm_price->IdBasEd=id_bas_ed;
						dm_price->IdNom=glStrToInt64(DM->DocTIDNOMPRNT->AsString);
						dm_price->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
						dm_price->NewElement();
						}
					else
						{
						dm_price->OpenElement(id_price);
						}

					dm_price->Element->Edit();
					dm_price->ElementZNACH_PRICE->AsFloat=DM->DocTPRICEPRNT->AsFloat/DM->DocTKFPRNT->AsFloat;
					dm_price->Element->Post();
					dm_price->SaveElement();
					}

				if (glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString)!=0 && DM->DocTRPRICE_DPRNT->AsFloat!=0)
					{
					//изменим розничную цену в справочнике
					__int64 id_price=dm_price->FindElementPoEd(glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),
								glStrToInt64(DM->DocTIDNOMPRNT->AsString), id_bas_ed);
					if (id_price==0)
						{
						dm_price->IdBasEd=id_bas_ed;
						dm_price->IdNom=glStrToInt64(DM->DocTIDNOMPRNT->AsString);
						dm_price->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString);
						dm_price->NewElement();
						}
					else
						{
                        dm_price->OpenElement(id_price);
						}

					dm_price->Element->Edit();
					dm_price->ElementZNACH_PRICE->AsFloat=DM->DocTRPRICE_DPRNT->AsFloat/DM->DocTKFPRNT->AsFloat;
					dm_price->Element->Post();
					dm_price->SaveElement();
					}
		DM->DocT->Next();
		}
dm_nom->kanRelease();
dm_price->kanRelease();

ShowMessage("Цены обновлены!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::cxGrid1DBTableView1NAC_DPRNTPropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
double procent=(double)VarAsType(DisplayValue,varDouble);
DM->DocT->Edit();
DM->DocTRPRICE_DPRNT->AsFloat=DM->DocTPRICEPRNT->AsFloat*((100+procent)/100);
DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::UpdatePriceDocPoNacToolButtonClick(TObject *Sender)
{
DM->DataSourceDocT->Enabled=false;
TBookmark BM;
BM=DM->DocT->GetBookmark();

IDMSprNacenka * dm_nac;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNacenka.1",IID_IDMSprNacenka,
													(void**)&dm_nac);
dm_nac->Init(InterfaceMainObject,InterfaceImpl);

IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);
DM->DocT->First();
while (!DM->DocT->Eof)
		{
		dm_nom->OpenElement(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
		__int64 id_grp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);
		dm_nac->OpenTable(id_grp);
		dm_nac->Table->First();
		while(!dm_nac->Table->Eof)
			{
			if (glStrToInt64(dm_nac->TableIDTPRICE_SNACENKA->AsString)==
						 glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString) )
				{
				DM->DocT->Edit();
				DM->DocTRPRICE_DPRNT->AsFloat=glRoundValue((DM->DocTPRICEPRNT->AsFloat
										/DM->DocTKFPRNT->AsFloat)
										*((dm_nac->TableVALUE_SNACENKA->AsFloat+100)/100),
										dm_nac->TableOKR_SNACENKA->AsInteger);
				DM->DocT->Post();
				}
			dm_nac->Table->Next();
			}

		DM->DocT->Next();
		}
DM->DocT->GotoBookmark(BM);
DM->DocT->FreeBookmark(BM);
DM->DataSourceDocT->Enabled=true;

dm_nac->kanRelease();
dm_nom->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaDocPrihNakl::OpenFormViborGrpNom(void)
{
if (FormaViborGrpNomSpr==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaViborGrpNomSpr);
		FormaViborGrpNomSpr->Init(InterfaceMainObject,InterfaceImpl);
        FormaViborGrpNomSpr->Vibor=true;
		FormaViborGrpNomSpr->UpdateForm();
		FormaViborGrpNomSpr->NumberProcVibor=ER_GrpNom;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::EndViborGrpNom(void)
{


	__int64 id_grp=glStrToInt64(FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString);
	IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);
	dm_nom->OpenTable(id_grp,false);
	dm_nom->Table->First();
	while (!dm_nom->Table->Eof)
		{
		dm_nom->OpenElement(glStrToInt64(dm_nom->TableIDNOM->AsString));

		DM->DocT->Append();
		DM->DocTIDNOMPRNT->AsString=dm_nom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

		DM->DocTIDEDPRNT->AsString=dm_nom->ElementIDOSNEDNOM->AsString;
		DM->DocTNAMEED->AsString=dm_nom->OsnEdNAMEED->AsString;
		DM->DocTKFPRNT->AsFloat=dm_nom->OsnEdKFED->AsFloat;

		DM->DocTKOLPRNT->AsInteger=1;

		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		DM->DocTPRICEPRNT->AsFloat=DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE->AsString),
							glStrToInt64(dm_nom->ElementIDNOM->AsString),
							glStrToInt64(DM->DocTIDEDPRNT->AsString),
							DM->DocTKFPRNT->AsFloat,
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
		if (DM->SkladRozn==true)
			{
			DM->DocTRPRICE_DPRNT->AsFloat=DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DPRN->AsString),
							glStrToInt64(dm_nom->ElementIDNOM->AsString),
							glStrToInt64(DM->DocTIDEDPRNT->AsString),
							DM->DocTKFPRNT->AsFloat,
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
			}
		else
			{
			DM->DocTRPRICE_DPRNT->AsFloat=0;
			}
					
		DMSprPrice->kanRelease();
		DM->DocT->Post();
		dm_nom->Table->Next();
		}

dm_nom->kanRelease();

		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOLPRNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOLPRNT->Focused=true;
			}


}
//---------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::ToolButton4Click(TObject *Sender)
{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocPrihNakl::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocPrihNakl::RunExternalModule(__int64 id_module, int type_module)
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


void __fastcall TFormaDocPrihNakl::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocPrihNakl::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocPrihNakl::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocPrihNakl::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ActionEditNomExecute(TObject *Sender)
{
		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
		FormaElementa->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
		FormaElementa->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		FormaElementa->NumberProcVibor=ER_ElementNom;
		//FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom="";
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ActionEditEdExecute(TObject *Sender)
{
IFormaElementaSprEd * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDEDPRNT->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_ElementEd;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonUpdateGtdSprClick(TObject *Sender)
{
IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);
//изменим ГТД в справочнике

	DM->DocT->First();
	while (!DM->DocT->Eof)
		{
		if (Trim(DM->DocTGTDPART->AsString) != "")
			{
			dm_nom->OpenElement(glStrToInt64(DM->DocTIDNOMPRNT->AsString));
			dm_nom->Element->Edit();
			dm_nom->ElementGTDNOM->AsString=DM->DocTGTDPART->AsString;
			dm_nom->Element->Post();
			dm_nom->SaveElement();
			}
		DM->DocT->Next();
		}
dm_nom->kanRelease();


ShowMessage("ГТД обновлены!");
}
//---------------------------------------------------------------------------
void TFormaDocPrihNakl::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocPrihNakl::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocPrihNakl::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocPrihNakl::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocPrihNakl::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocPrihNakl::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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


void __fastcall TFormaDocPrihNakl::ToolButtonMoveInDocPerClick(TObject *Sender)
{
  //множественный перенос
  IFormaDocPer * doc_per;
  InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocPer,IID_IFormaDocPer,
													(void**)&doc_per);
  doc_per->Init(InterfaceMainObject,InterfaceImpl);
  doc_per->DM->NewDoc();
  doc_per->UpdateForm();

		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				doc_per->DM->DocT->Append();
				__int64 id_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOMPRNT->Index];
				doc_per->DM->DocTIDNOMPERT->AsString=id_nom;
				__int64 id_ed=AViewData->Records[i]->Values[cxGrid1DBTableView1IDEDPRNT->Index];
				doc_per->DM->DocTIDEDPERT->AsString=id_ed;

				UnicodeString name_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1NAMENOM->Index];
				doc_per->DM->DocTNAMENOM->AsString=name_nom;
				UnicodeString name_ed=AViewData->Records[i]->Values[cxGrid1DBTableView1NAMEED->Index];
				doc_per->DM->DocTNAMEED->AsString=name_ed;

				double kol=AViewData->Records[i]->Values[cxGrid1DBTableView1KOLPRNT->Index];
				doc_per->DM->DocTKOLPERT->AsFloat=kol;
				double price=AViewData->Records[i]->Values[cxGrid1DBTableView1RPRICE_DPRNT->Index];
				doc_per->DM->DocTPRICEPERT->AsFloat=price;
				double kf=AViewData->Records[i]->Values[cxGrid1DBTableView1KFPRNT->Index];
				doc_per->DM->DocTKFPERT->AsFloat=kf;
				double sum=AViewData->Records[i]->Values[cxGrid1DBTableView1RSUM_DPRNT->Index];
				doc_per->DM->DocTSUMPERT->AsFloat=sum;


				doc_per->DM->DocT->Post();
				}
			}

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonSetFlagDvUchetAddOborudClick(TObject *Sender)

{
  //множественный перенос
  IDMSprNom * nom;
  InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNom,IID_IDMSprNom,
													(void**)&nom);
  nom->Init(InterfaceMainObject,InterfaceImpl);

		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOMPRNT->Index];
				nom->OpenElement(id_nom);
				nom->Element->Edit();
				nom->ElementFL_ADD_IN_SOBORUD_SNOM->AsInteger=1;
				nom->ElementFL_DVREG_SNOM->AsInteger=1;
				nom->Element->Post();
				nom->SaveElement();

				}
			}

nom->kanRelease();

ShowMessage("Выполнено!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonSetAddOborudClick(TObject *Sender)
{
  //множественный перенос
  IDMSprNom * nom;
  InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNom,IID_IDMSprNom,
													(void**)&nom);
  nom->Init(InterfaceMainObject,InterfaceImpl);

		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOMPRNT->Index];
				nom->OpenElement(id_nom);
				nom->Element->Edit();
				nom->ElementFL_ADD_IN_SOBORUD_SNOM->AsInteger=1;
				nom->Element->Post();
				nom->SaveElement();

				}
			}

nom->kanRelease();

ShowMessage("Выполнено!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocPrihNakl::ToolButtonSetDvUchetClick(TObject *Sender)
{
  //множественный перенос
  IDMSprNom * nom;
  InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNom,IID_IDMSprNom,
													(void**)&nom);
  nom->Init(InterfaceMainObject,InterfaceImpl);

		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id_nom=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOMPRNT->Index];
				nom->OpenElement(id_nom);
				nom->Element->Edit();
				nom->ElementFL_DVREG_SNOM->AsInteger=1;
				nom->Element->Post();
				nom->SaveElement();

				}
			}

nom->kanRelease();

ShowMessage("Выполнено!");
}
//---------------------------------------------------------------------------

