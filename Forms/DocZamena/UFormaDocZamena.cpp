//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UFormaDocZamena.h"
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
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocZamena::TFormaDocZamena(TComponent* Owner)
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
bool TFormaDocZamena::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocZamena.1",IID_IDMDocZamena,
							(void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
SumSpiscxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SumPostcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

Prosmotr=false;    //только просмотр
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;


//розничный тип цен
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
									 (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();

TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypeRPrice->DataSourceTable;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocZamenaImpl),false);
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
//---------------------------------------------------------------------------
int TFormaDocZamena::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaDocZamena::UpdateForm(void)
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


if (DM->SkladRozn==true)
	{
	cxGrid1DBBandedTableView1S_RPRICE_DZAMENAT->Visible=true;
	cxGrid1DBBandedTableView1S_RSUM_DZAMENAT->Visible=true;
	cxGrid1DBBandedTableView1P_RPRICE_DZAMENAT->Visible=true;
	cxGrid1DBBandedTableView1P_RSUM_DZAMENAT->Visible=true;
	TypePricecxDBLookupComboBox->Visible=true;
	RTPriceLabel->Visible=true;
	}
else
	{
	cxGrid1DBBandedTableView1S_RPRICE_DZAMENAT->Visible=false;
	cxGrid1DBBandedTableView1S_RSUM_DZAMENAT->Visible=false;
	cxGrid1DBBandedTableView1P_RPRICE_DZAMENAT->Visible=false;
	cxGrid1DBBandedTableView1P_RSUM_DZAMENAT->Visible=false;
	TypePricecxDBLookupComboBox->Visible=false;
	RTPriceLabel->Visible=false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocZamena::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
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
DMSprTypeRPrice->kanRelease();

Action=caFree;
}
//---------------------------------------------------------------------------

int TFormaDocZamena::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_Firm)
	{
	if (type_event==1)
		{
		EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_Sklad)
	{
	if (type_event==1)
		{
        EndViborSklad();
		}
	FormaSpiskaSprSklad=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_NomSpis)
	{
	if (type_event==1)
		{
		EndViborNomSpis();
		}
		FormaSpiskaSprNom=0;
		cxGrid1->SetFocus();
		//cxGrid1DBTableView1KOL_DZAMENAT->Selected=true;
	}

if (number_procedure_end==ER_EdSpis)
	{
	if (type_event==1)
		{
		EndViborEdSpis();
		}
	FormaSpiskaSprEd=0;
	cxGrid1->SetFocus();
	//cxGrid1DBTableView1RPRICE_DZAMENAT->Selected=true;
	}

if (number_procedure_end==ER_NomPost)
	{
	if (type_event==1)
		{
		EndViborNomPost();
		}
		FormaSpiskaSprNom=0;
		cxGrid1->SetFocus();
		//cxGrid1DBTableView1KOL_DZAMENAT->Selected=true;
	}

if (number_procedure_end==ER_EdPost)
	{
	if (type_event==1)
		{
		EndViborEdPost();
		}
	FormaSpiskaSprEd=0;
	cxGrid1->SetFocus();
	//cxGrid1DBTableView1RPRICE_DZAMENAT->Selected=true;
	}

if (number_procedure_end==ER_Part)
	{
	if (type_event==1)
		{
		EndEditPart();
		}
	FormaElementaSprPart=0;
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
//-----------------------------------------------------------------------------
//выбор информационной базы
void TFormaDocZamena::ViborInfBase(void)
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
//---------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();

}
//---------------------------------------------------------------------------
//выбор фирмы
void TFormaDocZamena::ViborFirm(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
//		FormaSpiskaSprFirm->HintLabel->Caption="Выберите фирму для документа Замена №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborFirm(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDFIRMDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
	DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
//выбор склада
void TFormaDocZamena::ViborSklad(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		FormaSpiskaSprSklad->DM->OpenTable();
//        Sklad->HintLabel->Caption="Выберите склад для документа Ввод остатков №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLDOC->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->DocAll->Post();
	UpdateForm();

}
//----------------------------------------------------------------------------
//выбор номенклатуры
void TFormaDocZamena::ViborNomSpis(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Замена №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTS_IDNOM_DZAMENAT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_NomSpis;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborNomSpis(void)
{

                if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTS_IDNOM_DZAMENAT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTS_NAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTS_KOL_DZAMENAT->AsInteger=1;


				DM->DocTS_IDED_DZAMENAT->AsString=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString);
				DM->DocTS_NAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTS_KF_DZAMENAT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTS_RPRICE_DZAMENAT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString), //тип цен
											glStrToInt64(DM->DocTS_IDNOM_DZAMENAT->AsString),            //номенклатура
											glStrToInt64(DM->DocTS_IDED_DZAMENAT->AsString),             //единица
											DM->DocTS_KF_DZAMENAT->AsFloat,                              //коэффициент
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //базовая единица
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTS_RPRICE_DZAMENAT->AsFloat=0;
					}

				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);



ActionOperation=aoNO;		
}
//----------------------------------------------------------------------------
//выбор единицы
void TFormaDocZamena::ViborEdSpis(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTS_IDNOM_DZAMENAT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTS_IDNOM_DZAMENAT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTS_NAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Выпуск продукции №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprEd->NumberProcVibor=ER_EdSpis;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborEdSpis(void)
{


	DM->DocT->Edit();
	DM->DocTS_IDED_DZAMENAT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTS_NAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTS_KF_DZAMENAT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTS_RPRICE_DZAMENAT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString), //тип цен
											glStrToInt64(DM->DocTS_IDNOM_DZAMENAT->AsString),            //номенклатура
											glStrToInt64(DM->DocTS_IDED_DZAMENAT->AsString),             //единица
											DM->DocTS_KF_DZAMENAT->AsFloat,                              //коэффициент
											0);            //базовая единица
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTS_RPRICE_DZAMENAT->AsFloat=0;
					}


}
//----------------------------------------------------------------------------
//выбор номенклатуры
void TFormaDocZamena::ViborNomPost(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="Выберите номенклатуру для документа Замена №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_NomPost;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborNomPost(void)
{

                DM->DocT->Edit();
				DM->DocTP_IDNOM_DZAMENAT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTP_NAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTP_KOL_DZAMENAT->AsInteger=1;


				DM->DocTP_IDED_DZAMENAT->AsString=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString);
				DM->DocTP_NAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTP_KF_DZAMENAT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTP_RPRICE_DZAMENAT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString), //тип цен
											glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString),            //номенклатура
											glStrToInt64(DM->DocTP_IDED_DZAMENAT->AsString),             //единица
											DM->DocTP_KF_DZAMENAT->AsFloat,                              //коэффициент
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //базовая единица
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTP_RPRICE_DZAMENAT->AsFloat=0;
					}

				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);

}
//----------------------------------------------------------------------------
//выбор единицы
void TFormaDocZamena::ViborEdPost(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="Единицы номенклатуры: "+DM->DocTP_NAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="Выберите единицу номенклатуры для документа Замена №"
//		+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprEd->NumberProcVibor=ER_EdPost;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndViborEdPost(void)
{


	DM->DocT->Edit();
	DM->DocTP_IDED_DZAMENAT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTP_NAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTP_KF_DZAMENAT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTP_RPRICE_DZAMENAT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DZAMENA->AsString), //тип цен
											glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString),            //номенклатура
											glStrToInt64(DM->DocTP_IDED_DZAMENAT->AsString),             //единица
											DM->DocTP_KF_DZAMENAT->AsFloat,                              //коэффициент
											0);            //базовая единица
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTP_RPRICE_DZAMENAT->AsFloat=0;
					}

	DM->DocT->Post();

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDocZamena::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->EndUpdate();
OutputZagolovokReport(PrintForm);

//таблица
RoznSummaSpis=0;
RoznSummaPost=0;

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocZamena::OutputZagolovokReport(TSheetEditor *prForm)
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
        cHeader->Size[1] = 20;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 250;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;
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
cell->Text="Замена №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;




cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocDESCR_DZAMENA->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
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

if (DM->SkladRozn==true)
	{
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Розн. цена";
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
cell->Text="Розн. сумма";
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
void TFormaDocZamena::OutputString(TSheetEditor *prForm)
{
numRow ++;

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="-";
cell->Style->Font->Size =12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTS_NAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTS_KOL_DZAMENAT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTS_NAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTS_KF_DZAMENAT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if (DM->SkladRozn==true)
	{
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTS_RPRICE_DZAMENAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTS_RSUM_DZAMENAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

RoznSummaSpis=RoznSummaSpis+DM->DocTS_RSUM_DZAMENAT->AsFloat;
	}
//вторая строка

numRow++;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="+";
cell->Style->Font->Size =12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTP_NAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTP_KOL_DZAMENAT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTP_NAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTP_KF_DZAMENAT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if (DM->SkladRozn==true)
	{
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTP_RPRICE_DZAMENAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTP_RSUM_DZAMENAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

RoznSummaPost=RoznSummaPost+DM->DocTP_RSUM_DZAMENAT->AsFloat;
	}
}


//------------------------------------------------------------------------------
void TFormaDocZamena::OutputPodavalReport(TSheetEditor *prForm)
{
numRow++;
numCol=2;
TcxSSCellObject *cell;

if (DM->SkladRozn==true)
	{
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
//cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего розн. сумма списаний:     "+FloatToStrF(RoznSummaSpis,ffFixed,10,2);
delete cell;

 numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
//cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего розн. сумма поступлений:     "+FloatToStrF(RoznSummaPost,ffFixed,10,2);
delete cell;
numRow++;
	}
	
numRow++;
numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Ответственные лица: ";
delete cell;
numRow++;
numRow++;

numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=" __________________________ ";
delete cell;

numRow++;
numRow++;
numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="  __________________________ ";
delete cell;
}

//----------------------------------------------------------------------------

void __fastcall TFormaDocZamena::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocZamena::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocZamena");
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocZamena::TypeRPriceComboBoxPropertiesChange(
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


void __fastcall TFormaDocZamena::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TFormaDocZamena::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborNomSpis();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocZamena::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------


void TFormaDocZamena::OpenFormElementaSprPart(void)
{
if (glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString)>0)
	{
	if (FormaElementaSprPart==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprPart.1",IID_IFormaElementaSprPart,
													(void**)&FormaElementaSprPart);
		FormaElementaSprPart->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementaSprPart->NumberProcVibor=ER_Part;
		
		if (glStrToInt64(DM->DocTP_IDPART_DZAMENAT->AsString)>0)
			{
			FormaElementaSprPart->DM->OpenElement(glStrToInt64(DM->DocTP_IDPART_DZAMENAT->AsString));
			if ((glStrToInt64(FormaElementaSprPart->DM->ElementIDDOCPART->AsString)==glStrToInt64(DM->DocAllIDDOC->AsString))
						&&(glStrToInt64(FormaElementaSprPart->DM->ElementIDNOMPART->AsString)==glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString)))
				{ //этот же документ и номеклатура
				}
			else
				{ //создаем новый элемент
				FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString));
				if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
					{
					FormaElementaSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
					}
				}
			}
		else
			{ //создаем новый элемент
			FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTP_IDNOM_DZAMENAT->AsString));
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
		FormaElementaSprPart->DM->ElementDOCPART->AsString="Замена №"+DM->DocAllNUMDOC->AsString+" от " +DM->DocAllPOSDOC->AsString;

		FormaElementaSprPart->DM->Element->Post();
		}
	}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EndEditPart(void)
{

	DM->DocT->Edit();
	DM->DocTP_IDPART_DZAMENAT->AsString=FormaElementaSprPart->DM->ElementIDPART->AsString;

	DM->DocT->Post();


}
//----------------------------------------------------------------------------
void TFormaDocZamena::BeforeSaveDoc(void)
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
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::EditPropPartcxButtonClick(TObject *Sender)
{
OpenFormElementaSprPart();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::cxGrid1DBBandedTableView1S_NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborNomSpis();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::cxGrid1DBBandedTableView1P_NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborNomPost();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::cxGrid1DBBandedTableView1S_NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborEdSpis();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::cxGrid1DBBandedTableView1P_NAMEEDPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborEdPost();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocZamena::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocZamena::RunExternalModule(__int64 id_module, int type_module)
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







void __fastcall TFormaDocZamena::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocZamena::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
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

void __fastcall TFormaDocZamena::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
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

void __fastcall TFormaDocZamena::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocZamena::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------
void TFormaDocZamena::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocZamena::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocZamena::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocZamena::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocZamena::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocZamena::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

