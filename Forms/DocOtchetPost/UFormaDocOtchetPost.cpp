//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop



#include "UFormaDocOtchetPost.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"

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
__fastcall TFormaDocOtchetPost::TFormaDocOtchetPost(TComponent* Owner)
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
bool TFormaDocOtchetPost::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOtchetPost,IID_IDMDocOtchetPost, (void**)&DM);
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
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;


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




//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
						 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocOtchetPostImpl),false);
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
void TFormaDocOtchetPost::UpdateForm(void)
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

TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString));
flObrabatChangeTypePrice=true;


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
int TFormaDocOtchetPost::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOtchetPost::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
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
DMTableExtPrintForm->kanRelease();
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOtchetPost::FormActivate(TObject *Sender)
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

void __fastcall TFormaDocOtchetPost::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaDocOtchetPost::ReadShtrihCodEvent(int number, UnicodeString sh)
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
ob_bar->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString);
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOM_DOTCHPOSTT->AsString = dm_nom->ElementIDNOM->AsString;
	DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
	DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

	DM->DocTIDED_DOTCHPOSTT->AsString = dm_ed->ElementIDED->AsString;
	DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
	DM->DocTKF_DOTCHPOSTT->AsFloat = dm_ed->ElementKFED->AsFloat;

	DM->DocTKOL_DOTCHPOSTT->AsFloat=ob_bar->Kol;

	//получим цену
	IDMSprPrice * dm_price;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
	dm_price->Init(InterfaceMainObject,InterfaceImpl);


		DM->DocTPRICE_DOTCHPOSTT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDED_DOTCHPOSTT->AsString),    // единица
						DM->DocTKF_DOTCHPOSTT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица

	dm_price->kanRelease();

	DM->DocT->Post();

	VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

	if (TablecxPageControl->ActivePageIndex==0)
		{
		cxGrid1->Focused();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DOTCHPOSTT->Focused=true;
		cxGrid1DBTableView1KOL_DOTCHPOSTT->Selected=true;
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
int TFormaDocOtchetPost::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOM_DOTCHPOSTT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;
				if (DM->DocTKOL_DOTCHPOSTT->AsFloat > 0.001)  //задано количество
					{ //не изменяем
					}
				else
					{
					DM->DocTKOL_DOTCHPOSTT->AsFloat=1;
					}

				DM->DocTIDED_DOTCHPOSTT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_DOTCHPOSTT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;


				DM->DocTPRICE_DOTCHPOSTT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
														*DM->DocTKF_DOTCHPOSTT->AsFloat;




                DM->DocT->Post();
                //DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
                }
		Nom=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOL_DOTCHPOSTT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOL_DOTCHPOSTT->Focused=true;
			}
        }

if (number_procedure_end==ER_PodborNom)//==PodborNom)
        {
		if (type_event==1)
                {
                DM->IsmSum=false;
                DM->AddDocNewString();
				DM->DocT->Edit();
				DM->DocTIDNOM_DOTCHPOSTT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;

				if (DM->DocTKOL_DOTCHPOSTT->AsFloat > 0.1)
					{
					}
				else
					{
					DM->DocTKOL_DOTCHPOSTT->AsFloat=Nom->FormaPodboraNom->Kol;
					}

				DM->DocTIDED_DOTCHPOSTT->AsString=Nom->FormaPodboraNom->IdEd;
                DM->DocTNAMEED->AsString=Nom->FormaPodboraNom->NameEd;
				DM->DocTKF_DOTCHPOSTT->AsFloat=Nom->FormaPodboraNom->KFEd;

				DM->DocTPRICE_DOTCHPOSTT->AsFloat=Nom->FormaPodboraNom->Price;
				DM->DocTSUM_DOTCHPOSTT->AsFloat=Nom->FormaPodboraNom->Summa;


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
				DM->DocTIDED_DOTCHPOSTT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_DOTCHPOSTT->AsFloat=Ed->DM->ElementKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString),
											 glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString));
						DM->DocTPRICE_DOTCHPOSTT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DOTCHPOSTT->AsFloat;
					DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1PRICE_DOTCHPOSTT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1PRICE_DOTCHPOSTT->Focused=true;
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
void  TFormaDocOtchetPost::OpenFSSprNom()
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TFormaDocOtchetPost:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString);
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString));
//        Ed->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="Выберите единицу номенклатуры для документа Приходная накладная №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Ed->NumberProcVibor=ER_Ed;

        }
}

//----------------------------------------------------------------------------






void    TFormaDocOtchetPost::OpenFormSpiskaSprFirm(void)
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
void  TFormaDocOtchetPost::OpenFormSpiskaSprSklad(void)
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
void  TFormaDocOtchetPost::OpenFormSpiskaSprKlient(void)
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




void __fastcall TFormaDocOtchetPost::AddNewStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->AddDocNewString();
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::DeleteStringClick(TObject *Sender)
{
DM->DeleteStringDoc();
}

//---------------------------------------------------------------------------

//----------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::ToolButtonPodborClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->Podbor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//        Nom->HintLabel->Caption="Выберите номенклатуру для документа Приходная накладная №"
//        +DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_PodborNom;
        }
}
//---------------------------------------------------------------------------

void TFormaDocOtchetPost::OpenFormSpiskaSprInfBase(void)
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




void __fastcall TFormaDocOtchetPost::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocPrihNakl");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::ToolButtonUpdatePriceClick(TObject *Sender)
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



void __fastcall TFormaDocOtchetPost::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();


}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::TypePriceComboBoxPropertiesChange(
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
		DM->DocIDTPRICE_DOTCHPOST->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString),
											 glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString));
						DM->DocTPRICE_DOTCHPOSTT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_DOTCHPOSTT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------




void TFormaDocOtchetPost::BeforeSaveDoc(void)
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



void __fastcall TFormaDocOtchetPost::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::IsmPriceCheckBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

//-----------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::ActionSetMainTabSheetExecute(TObject *Sender)
{
TablecxPageControl->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::ActionSetAdditionallyTabSheetExecute(
      TObject *Sender)
{
TablecxPageControl->ActivePageIndex=1;
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocOtchetPost::ToolButtonCheckPriceNaRoznSkladeClick(
      TObject *Sender)
{
//bool doc_create=false;
//DM->DocT->First();
//IFormaDocIsmPrice * doc=0;
//while (!DM->DocT->Eof)
//	{
//	DM->pFIBQ->Close();
//	DM->pFIBQ->SQL->Clear();
//	DM->pFIBQ->SQL->Add(" select rggoods.idnom_rggoods,  ");
//	DM->pFIBQ->SQL->Add(" rggoods.kol_rggoods,           ");
//	DM->pFIBQ->SQL->Add(" rggoods.rprice_rggoods,        ");
//	DM->pFIBQ->SQL->Add(" snom.namenom,                  ");
//	DM->pFIBQ->SQL->Add(" sed.ided,                    ");
//	DM->pFIBQ->SQL->Add(" sed.nameed                     ");
//	DM->pFIBQ->SQL->Add(" from rggoods                   ");
//	DM->pFIBQ->SQL->Add(" left outer join snom on rggoods.idnom_rggoods=snom.idnom   ");
//	DM->pFIBQ->SQL->Add(" left outer join sed on snom.idbasednom=sed.ided    ");
//	DM->pFIBQ->SQL->Add(" where rggoods.idfirm_rggoods=:PARAM_IDFIRM         ");
//	DM->pFIBQ->SQL->Add(" 	and rggoods.idsklad_rggoods=:PARAM_IDSKLAD       ");
//	DM->pFIBQ->SQL->Add("   and rggoods.idnom_rggoods=:PARAM_IDNOM         ");
//	DM->pFIBQ->SQL->Add(" 	and rggoods.rprice_rggoods!=:PARAM_RPRICE        ");
//
//	DM->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=
//											DM->DocAllIDFIRMDOC->AsString;
//	DM->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=
//											DM->DocAllIDSKLDOC->AsString;
//	DM->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=
//											DM->DocTIDNOMPRNT->AsString;
//	DM->pFIBQ->ParamByName("PARAM_RPRICE")->AsFloat=
//											DM->DocTRPRICE_DPRNT->AsFloat;
//	DM->pFIBQ->ExecQuery();
//	if (DM->pFIBQ->RecordCount>0)
//		{
//		while (!DM->pFIBQ->Eof)
//			{
//			if (DM->pFIBQ->FieldByName("kol_rggoods")->AsFloat>0)
//				{
//				if (doc_create==false)
//					{ //создаем новый документ
//					InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocIsmPrice.1",IID_IFormaDocIsmPrice,
//													(void**)&doc);
//					doc->Init(InterfaceMainObject,InterfaceImpl);
//					doc->DM->NewDoc();
//					doc_create=true;
//					doc->DM->DocAll->Edit();
//					doc->DM->DocAllIDBASE_GALLDOC->AsString=
//											DM->DocAllIDBASE_GALLDOC->AsString;
//					doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=
//											DM->DocAllNAME_SINFBASE_OBMEN->AsString;
//					doc->DM->DocAllIDFIRMDOC->AsString=
//											DM->DocAllIDFIRMDOC->AsString;
//					doc->DM->DocAllNAMEFIRM->AsString=
//											DM->DocAllNAMEFIRM->AsString;
//					doc->DM->DocAllIDSKLDOC->AsString=
//											DM->DocAllIDSKLDOC->AsString;
//					doc->DM->DocAllNAMESKLAD->AsString=
//											DM->DocAllNAMESKLAD->AsString;
//					doc->DM->DocAll->Post();
//
//					doc->DM->Doc->Edit();
//					doc->DM->DocDESCR_DISMPRICE->AsString="На основании Приходной накладной №"+
//								 DM->DocAllNUMDOC->AsString+" от "+
//								 DM->DocAllPOSDOC->AsString;
//					doc->DM->DocIDNEWTPRICE_DISMPRICE->AsString=
//									DM->DocIDRTPRICE_DPRN->AsString;
//					doc->DM->Doc->Post();
//
//
//					doc->UpdateForm();
//
//					}
//
//				doc->DM->DocT->Append();
//				doc->DM->DocT->Edit();
//				doc->DM->DocTIDNOM_DISMPRICET->AsString=
//									DM->pFIBQ->FieldByName("idnom_rggoods")->AsString;
//				doc->DM->DocTNAMENOM->AsString=
//									DM->pFIBQ->FieldByName("namenom")->AsString;
//				doc->DM->DocTIDED_DISMPRICET->AsString=
//									DM->pFIBQ->FieldByName("ided")->AsString;
//				doc->DM->DocTKOL_DISMPRICET->AsFloat=
//									DM->pFIBQ->FieldByName("kol_rggoods")->AsFloat;
//				doc->DM->DocTKF_DISMPRICET->AsFloat=1;
//				doc->DM->DocTNAMEED->AsString=
//									DM->pFIBQ->FieldByName("nameed")->AsString;
//				doc->DM->DocTOLDPRICE_DISMPRICET->AsFloat=
//									DM->pFIBQ->FieldByName("rprice_rggoods")->AsFloat;
//				doc->DM->DocTNEWPRICE_DISMPRICET->AsFloat=
//									DM->DocTRPRICE_DPRNT->AsFloat;
//				doc->DM->DocT->Post();
//                }
//            DM->pFIBQ->Next();
//            }
//		}
//    DM->pFIBQ->Close();
//    DM->DocT->Next();
//	}
//
//if (doc==0)
//	{
//    ShowMessage("Нет товаров для переоценки!");
//	}
}
//---------------------------------------------------------------------------







void __fastcall TFormaDocOtchetPost::NumDocPostcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::PosDocPostcxDBDateEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------



void TFormaDocOtchetPost::OpenFormViborGrpNom(void)
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
void __fastcall TFormaDocOtchetPost::EndViborGrpNom(void)
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
		DM->DocTIDNOM_DOTCHPOSTT->AsString=dm_nom->ElementIDNOM->AsString;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

		DM->DocTIDED_DOTCHPOSTT->AsString=dm_nom->ElementIDOSNEDNOM->AsString;
		DM->DocTNAMEED->AsString=dm_nom->OsnEdNAMEED->AsString;
		DM->DocTKF_DOTCHPOSTT->AsFloat=dm_nom->OsnEdKFED->AsFloat;

		DM->DocTKOL_DOTCHPOSTT->AsInteger=1;

		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		DM->DocTPRICE_DOTCHPOSTT->AsFloat=DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString),
							glStrToInt64(dm_nom->ElementIDNOM->AsString),
							glStrToInt64(DM->DocTIDED_DOTCHPOSTT->AsString),
							DM->DocTKF_DOTCHPOSTT->AsFloat,
							glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));

					
		DMSprPrice->kanRelease();
		DM->DocT->Post();
		dm_nom->Table->Next();
		}

dm_nom->kanRelease();

		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOL_DOTCHPOSTT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOL_DOTCHPOSTT->Focused=true;
			}


}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOtchetPost::ToolButton4Click(TObject *Sender)
{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocOtchetPost::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocOtchetPost::RunExternalModule(__int64 id_module, int type_module)
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


void __fastcall TFormaDocOtchetPost::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocOtchetPost::ActionDvRegExecute(TObject *Sender)
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

void __fastcall TFormaDocOtchetPost::ActionSaveExecute(TObject *Sender)
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


void __fastcall TFormaDocOtchetPost::ActionEditNomExecute(TObject *Sender)
{
		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDNOM_DOTCHPOSTT->AsString));
		FormaElementa->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_DOTCHPOST->AsString);
		FormaElementa->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		FormaElementa->NumberProcVibor=ER_ElementNom;
		//FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom="";
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOtchetPost::ActionEditEdExecute(TObject *Sender)
{
IFormaElementaSprEd * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDED_DOTCHPOSTT->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_ElementEd;
}
//---------------------------------------------------------------------------

void TFormaDocOtchetPost::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocOtchetPost::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocOtchetPost::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocOtchetPost::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOtchetPost::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocOtchetPost::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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



void __fastcall TFormaDocOtchetPost::ToolButtonSetFlagDvUchetAddOborudClick(TObject *Sender)

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

void __fastcall TFormaDocOtchetPost::ToolButtonSetAddOborudClick(TObject *Sender)
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

void __fastcall TFormaDocOtchetPost::ToolButtonSetDvUchetClick(TObject *Sender)
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


