//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaDocCheck.h"
#include "IDMSprPrice.h"
#include "IFiskReg.h"
#include "IDMSprOborud.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IkasDMSpr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxPC"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxDBExtLookupComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxCheckGroup"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalc"
#pragma link "cxCalendar"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxDBEdit"
#pragma link "cxDBLabel"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxImageComboBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxPC"
#pragma link "cxStyles"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocCheck::TFormaDocCheck(TComponent* Owner)
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
void __fastcall TFormaDocCheck::FormCreate(TObject *Sender)
{



Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи



}
//--------------------------------------------------------------------------
bool TFormaDocCheck::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMDocCheck,IID_IDMDocCheck, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

//SumDocDBText->DataSource=DM->DataSourceDocAll;
IdKlientDBText->DataSource=DM->DataSourceDocAll;
NameBaseDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
cxGrid2DBTableView1->DataController->DataSource=DM->DataSourceDocOpl;

NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NumKLcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumCheckcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplNalcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplPCcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
NalCHKcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
SdachacxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameDogcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKassacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
SavNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
RegNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameDCardcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplPlatCardcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
OplCreditCardcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
AllOplPlatCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
AllOplCreditCardcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;

DocOsncxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocOsn;

SumDoccxDBLabel->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
AllOplcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
ActionOperation=aoNO;

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

flNoChangeTypePrice=false;

cxGrid1DBTableView1NDS_DCHKT->Visible=DM_Connection->glShowNDS;
cxGrid1DBTableView1SUMNDS_DCHKT->Visible=DM_Connection->glShowNDS;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocCheckImpl),false);
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
result=true;



return result;
}

//--------------------------------------------------------------------------
int TFormaDocCheck::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocCheck::UpdateForm(void)
{

Operation->ItemIndex=DM->DocOPERCHK->AsInteger;

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		cxGrid2DBTableView1->OptionsData->Editing=false;
        }
else
		{
		ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
		cxGrid2DBTableView1->OptionsData->Editing=true;
		}
ProsmotrTextLabel->Caption=DM->ProsmotrText;
flNoChangeTypePrice=true;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE->AsString));
flNoChangeTypePrice=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheck::FormClose(TObject *Sender,
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
if(FormaSpiskaSprDiscountCard)FormaSpiskaSprDiscountCard->kanRelease();
if(SpisokBSchet)SpisokBSchet->kanRelease();
if(SprCardOpl)SprCardOpl->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();
if(kasFormSpr)kasFormSpr->kanRelease();

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

void TFormaDocCheck::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=2;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOMCHKT->AsString));
		}
}
//-----------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=1;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE->AsString);
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
        SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMCHKT->AsString);
		SpisokNom->UpdateForm();
        }

}
//----------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprDogovor(void)
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
		FormaSpiskaSprDogovor->NumberProcVibor=6;
        }
}
//---------------------------------------------------------------------------
int TFormaDocCheck::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//==ViborTovar)
		{

		if (type_event==1)
				{
				if (ActionOperation==aoAddNewString)
						{
						DM->AddDocNewString();
						}
				DM->DocT->Edit();
				DM->DocTIDNOMCHKT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLCHKT->AsFloat=1;

				DM->DocTIDEDCHKT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
                DM->DocTKFCHKT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;

				DM->DocTPRICECHKT->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat
												*DM->DocTKFCHKT->AsFloat;

				DM->DocT->Post();
                }
		SpisokNom=0;

		cxGrid1DBTableView1KOLCHKT->Selected=true;
		cxGrid1->SetFocus();
        }

if (number_procedure_end==2)//==ViborEdinica)
        {
		if (type_event==1)
                {
				DM->DocT->Edit();
				DM->DocTIDEDCHKT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKFCHKT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE->AsString),
											 glStrToInt64(DM->DocTIDNOMCHKT->AsString));
				DM->DocTPRICECHKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFCHKT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
				}
		SpisokEd=0;

		cxGrid1DBTableView1PRICECHKT->Selected=true;
		cxGrid1->SetFocus();
		}

if (number_procedure_end==3)//==ViborFirm)
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

if (number_procedure_end==4)//EditRekvisit==ViborSklad)
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

if (number_procedure_end==5)//EditRekvisit==ViborKlient)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();
				if (SpisokKlient->DM->ElementIDTPRICEKLIENT->AsInt64!=0)
					{
					TypePriceComboBox->ItemIndex=
						DMSprTypePrice->GetIndexTypePricePoId(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsInt64);
					}
                }
		SpisokKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==6)//EditRekvisit==ViborDogovor)
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

if (number_procedure_end==7)//EditRekvisit==ViborKKM)
		{
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDKKMCHK->AsString=SpisokKKM->DM->ElementIDKKM->AsString;
                DM->DocNAMEKKM->AsString=SpisokKKM->DM->ElementNAMEKKM->AsString;
                DM->Doc->Post();
				}
		SpisokKKM=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==8)//EditRekvisit==ViborInfBase)
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

if (number_procedure_end==9)
		{
		if (type_event==1)
				{
				EndViborDiscountCard();
				}
		FormaSpiskaSprDiscountCard=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==10)
		{
		if (type_event==1)
				{
				EndViborDocOsn();
				}
		FormaGurAllDoc=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==11)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}



if (number_procedure_end==12)
		{
		if (type_event==1)
				{
				EndViborBSchet();
				}
        SpisokBSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==13)
		{
		if (type_event==1)
				{
				EndViborCardOpl();
				}
		SprCardOpl=0;
		ActionOperationCardOpl==ActionOperationCardOpl_NO;
		}

if (number_procedure_end==14)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

		if (number_procedure_end==15)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborDepartment();
					}
				kasFormSpr=0;
				}

ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------

void TFormaDocCheck::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=3;
        }

}
//---------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=4;
        }

}
//--------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->NumberProcVibor=5;
		}
}
//--------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprKKM(void)
{
if (Prosmotr==true) return;
if (SpisokKKM==NULL)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&SpisokKKM);
		SpisokKKM->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKKM->Vibor=true;
		SpisokKKM->NumberProcVibor=7;
	}

}
//--------------------------------------------------------------------------






void TFormaDocCheck::OpenFormSpiskaSprInfBase(void)
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
		FormaSpiskaSprInfBase->NumberProcVibor=8;
        }
}
//---------------------------------------------------------------------

void __fastcall TFormaDocCheck::ViborBaseButtonClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------
void TFormaDocCheck::PrintGoodsCheck(void)
{
//
TSheetEditor * SE=new TSheetEditor(Application);

SE->SS->DefaultStyle->Font->Size=10;
SE->SS->DefaultStyle->Font->Name="Arial";
SE->SS->RowsAutoHeight=true;


if (!SE) return;

x = 1;
y = 0;
SE->SS->BeginUpdate();
DM->DataSourceDocT->Enabled=false;
TBookmark BM;
BM=DM->DocT->GetBookmark();
PrintGoodsCheck_OutputHeadline(SE);


DM->DocT->First();
while (!DM->DocT->Eof)
        {
        PrintGoodsCheck_OutputString(SE);
        DM->DocT->Next();
        }

DM->DocT->GotoBookmark(BM);
DM->DocT->FreeBookmark(BM);
DM->DataSourceDocT->Enabled=true;


PrintGoodsCheck_OutputPodval(SE);

SE->SS->EndUpdate();
SE->Show();


}
//---------------------------------------------------------------------------
void TFormaDocCheck::PrintGoodsCheck_OutputHeadline(TSheetEditor *SE)
{
IDMSprFirm *DMSprFirm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
		DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);

DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

IDMSprSklad * DMSprSklad;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSklad.1",IID_IDMSprSklad,
													(void**)&DMSprSklad);
		DMSprSklad->Init(InterfaceMainObject,InterfaceImpl);

DMSprSklad->OpenElement(glStrToInt64(DM->DocAllIDSKLDOC->AsString));
x=1;
y=0;
TcxSSCellObject *cell;
cell = SE->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = DMSprFirm->ElementFNAMEFIRM->AsString
                +", ИНН: "+DMSprFirm->ElementINNFIRM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Name = "Times New Roman";
cell->Style->Font->Size = 10;
SE->SS->ActiveSheet->Rows->Size[y]=20;
delete cell;
y++;
cell = SE->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Адрес: "+DMSprSklad->ElementADRSKLAD->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Name = "Times New Roman";
cell->Style->Font->Size = 10;
SE->SS->ActiveSheet->Rows->Size[y]=20;
delete cell;
y++;
cell = SE->SS->ActiveSheet->GetCellObject(x, y);
cell->Text = "Телефон: "+DMSprFirm->ElementTELFIRM->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Name = "Times New Roman";
cell->Style->Font->Size = 10;
SE->SS->ActiveSheet->Rows->Size[y]=20;
delete cell;
y++;
SE->SS->ActiveSheet->Rows->Size[y]=10;
y++;
cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
cell->Text = "Товарный чек №"+DM->DocAllNUMDOC->AsString
                +" от "+DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Name = "Times New Roman";
cell->Style->Font->Size = 16;
delete cell;
y++; y++;

        TcxSSHeader *cHeader;
        cHeader = SE->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 250;
        cHeader->Size[3] = 80;
        cHeader->Size[4] = 80;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 80;
        cHeader->Size[7] = 80;

        x=1;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "№";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Наименование";
        cell->Style->HorzTextAlign = haCENTER;;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Кол-во";
        cell->Style->HorzTextAlign = haCENTER;;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Ед.";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "К";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Цена";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Сумма";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y-1);
        cell->Text = "Чек ККМ №:"+DM->DocNCHECKCHK->AsString
                        +", контрольная лента №"+DM->DocNKLCHK->AsString;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        delete cell;
        x++;

        y++;
DMSprFirm->kanRelease();
DMSprSklad->kanRelease();
}
//-----------------------------------------------------------------------------
void TFormaDocCheck::PrintGoodsCheck_OutputString(TSheetEditor *SE)
{
        x=1;
        TcxSSCellObject *cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = DM->DocT->RecNo;
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = DM->DocTNAMENOM->AsString;
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = FloatToStrF(DM->DocTKOLCHKT->AsFloat,ffFixed,10,3);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = DM->DocTNAMEED->AsString;
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = FloatToStrF(DM->DocTKFCHKT->AsFloat,ffFixed,10,3);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		if (DM->DocTKOLCHKT->AsFloat!=0)
			{
			cell->Text = FloatToStrF(DM->DocTSUMCHKT->AsFloat/DM->DocTKOLCHKT->AsFloat,ffFixed,10,2);
			}

		else
			{
			cell->Text = FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,10,2);
			}
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        x++;

        y++;


}
//---------------------------------------------------------------------------
void TFormaDocCheck::PrintGoodsCheck_OutputPodval(TSheetEditor *SE)
{
        x=1;
        TcxSSCellObject *cell;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges[eLeft]->Style =lsThin;
        cell->Style->Borders->Edges[eRight]->Style =lsThin;                
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Всего: ";
        cell->Style->HorzTextAlign = haCENTER;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges[eLeft]->Style =lsThin;
        cell->Style->Borders->Edges[eRight]->Style =lsNone;
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
        cell->Style->Borders->Edges[eRight]->Style =lsNone;
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
        cell->Style->Borders->Edges[eRight]->Style =lsNone;
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
        cell->Style->Borders->Edges[eRight]->Style =lsNone;
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
        cell->Style->Borders->Edges[eRight]->Style =lsNone;                  
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        cell->Style->Borders->Edges[eLeft]->Style =lsThin;
        cell->Style->Borders->Edges[eRight]->Style =lsThin;                
        cell->Style->Borders->Edges[eTop]->Style =lsThin;
        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
        delete cell;
        x++;
        y++;y++;

        x=2;
        TRect rect;
        rect.Left = x;
        rect.Top = y;
        rect.Right = x+5;
        rect.Bottom = y;
        SE->SS->ActiveSheet->SetMergedState(rect, true);

        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
		cell->Text = "ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        cell->Style->Font->Size = 10;
        cell->Style->WordBreak = true;
        delete cell;
        x++;
        y++; y++;
        x=2;
        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
        cell->Text = "Продавец:________________________________ ";
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->VertTextAlign = vaCENTER;
        cell->Style->Font->Size = 12;
        x++;
		y++;
}
//----------------------------------------------------------------------------


void __fastcall TFormaDocCheck::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocCheck");	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocCheck::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
//if (Prosmotr==true) return;

OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------
void TFormaDocCheck::PrintCheckFR(void)
{
if (Prosmotr==true) return;
if (FormaViborFR==NULL)
		{
		FormaViborFR=new TFormaViborFR(Application);
		FormaViborFR->DM_Connection=DM_Connection;
		FormaViborFR->Init();
		if (!FormaViborFR) return;
		FormaViborFR->IdArm=glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString);
		FormaViborFR->Vibor=true;
		FormaViborFR->UpdateForm();
		FormaViborFR->FOnCloseForm=EndViborFR;
		if (FormaViborFR->DM->Table->RecordCount<=1)
			{
			FormaViborFR->OutReady=true;
			FormaViborFR->Close();
			}
		else
			{
			FormaViborFR->ShowModal();
			}
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborFR(TObject *Sender)
{

if (FormaViborFR->OutReady==true)
	{
	FormaViborFR->Visible=false;
	IDMSprOborud *DMSprOborud;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
													(void**)&DMSprOborud);
		DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);

	DMSprOborud->OpenElement(FormaViborFR->DM->TableID_OBORUD->AsInt64);
	UnicodeString print_fiscal_check=DMSprOborud->GetParameter("PrintFiscalCheck");

	if (DMSprOborud->ElementID_OBORUD->AsInteger>0)
		{
		IFiskReg *fr;
		AnsiString prog_id=DMSprOborud->ElementPROGID_SOBORUD->AsString;
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Init(InterfaceMainObject,InterfaceImpl);
		fr->Number=1;
		//fr->InitDevice();
		int number_port=0;
		if (DMSprOborud->ElementCOMNAME_OBORUD->AsString!="")
			{
			number_port=StrToFloat(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
			}
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");







				IkasDMSpr * oborud_param;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborudParam,IID_IkasDMSpr,
																 (void**)&oborud_param);
				oborud_param->Init(InterfaceMainObject,0);
				oborud_param->IdOwner=glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString);
				oborud_param->OpenTable(0);
				//установим параметры подключения
				oborud_param->First(0);
				while(!oborud_param->GetEof(0))
					{
					TkasVariant * kv=new TkasVariant;
					if (oborud_param->GetValueFieldAsBool("ON_CONNECT_SOBORUD_PAR", 0)==true &&
									oborud_param->GetValueFieldAsBool("BEFORE_CONNECT_SOBORUD_PAR", 0)==true)
						{ //устанавливаем данный параметр
						int type_value=oborud_param->GetValueFieldAsInt("TYPE_PARAMETER_SOBORUD_PAR", 0);
						if (type_value == 1) //int
							{
							kv->type=1; kv->int_value=oborud_param->GetValueFieldAsInt("VALUE_SOBORUD_PAR", 0);
							}
						if (type_value == 2) //string
							{
							kv->type=2; kv->string_value=oborud_param->GetValueFieldAsString("VALUE_SOBORUD_PAR", 0).c_str(); kv->len_string=wcslen(kv->string_value);
							}
						if (type_value == 4) //booulean
							{
							kv->type=4; kv->bool_value=oborud_param->GetValueFieldAsBool("VALUE_SOBORUD_PAR", 0);
							}

						if (fr->SetParameter(oborud_param->GetValueFieldAsString("NAME_SOBORUD_PAR", 0), kv) == false)
							{
							ShowMessage("Ошибка при установке параметра подключения");
							}
						}
					oborud_param->Next(0);
					delete kv;
					}

				oborud_param->kanRelease();





		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			FormaViborFR=0;
			fr->kanRelease();
			return;
			}

		try
			{
				if (DM->DocT->RecordCount==0)
					{
					throw Exception("Нет строк в табличной части!",0);
					}

				if(fr->ProvVosmPrintCheck()==false)
					{
					throw Exception("Нет возможности напечатать чек! "+fr->TextError);
					}

			 if (print_fiscal_check=="1")
				{
				fr->InitDocument(2);
				if (DMSprOborud->GetParameter("TaxVariant") != "")
					{
					fr->TaxVariant=StrToInt(DMSprOborud->GetParameter("TaxVariant"));
					}
				}
			 else
				{
				fr->InitDocument(1);
				}

				fr->OpenNoFiscalCheck();


				if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
							}

				if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
							{
							fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
							}

				fr->PrintString(" ",1,0,0,true,false, false);


				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
			 	fr->PrintString(DM->DocPRIMCHK->AsString,1,0,1,true,false,true);
//-------------------------***************************************************

//
//




			DM->DocT->First();
			while(!DM->DocT->Eof)
					{

					fr->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код
					fr->NameNom=DM->DocTKRNAMENOM->AsString;
					fr->Quantity=DM->DocTKOLCHKT->AsFloat;
					fr->Price=DM->DocTPRICECHKT->AsFloat;
					fr->Amount=DM->DocTSUMCHKT->AsFloat;
					fr->Department=DM->DocTNUMOTDKKT_SDEPARTMENT->AsInteger;
					fr->Tax=1;  //без ндс

					if (fr->AddFiscalString()==false)
						{
						throw Exception(fr->TextError);
						}

//							if (fr->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==true)
//								{}
//							else{ }
//							AnsiString StrPr="";
//							StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
//								+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
//								+DM->DocTNAMEED->AsString+" = "
//								+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);
//
//							if(fr->PrintString(StrPr,1,0,2,true,false, false)==true)
//								{}
//							else {}



							DM->DocT->Next();
					}

				fr->PrintLine();//("------------------------------------",1,0,0,true,false);
				fr->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);

				fr->CloseNoFiscalCheck();

				if (print_fiscal_check=="1")
					{
							if(fr->PrintFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //сумма продажи
													1,                            //отдел
													DM->DocNALCHK->AsFloat,       //наличные
													DM->DocOPLPCCHK->AsFloat,     //банковская карта
													DM->DocOPLPLATCARD_ALL_DCHK->AsFloat,     //платежная карта
													DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat,	   //кредит
													DM->DocOPERCHK->AsInteger)==true)
								{}
							else {}

					}
				else
					{
							//0 продажа 1 возврат
							if(fr->PrintNoFiscalCheck(DM->DocAllSUMDOC->AsFloat,  //сумма продажи
													1,                            //отдел
													DM->DocNALCHK->AsFloat,       //наличные
													DM->DocOPLPCCHK->AsFloat,     //банковская карта
													DM->DocOPLPLATCARD_ALL_DCHK->AsFloat,     //платежная карта
													DM->DocOPLCREDITCARD_ALL_DCHK->AsFloat,	   //кредит
													DM->DocOPERCHK->AsInteger)==true)
								{}
							else {}

					}
			//получим номер чека
			fr->GetSostKKM();
			DM->Doc->Edit();
			DM->DocNKLCHK->AsInteger=fr->NumberKL;
			DM->DocNCHECKCHK->AsInteger=fr->NumberCheck;
			DM->DocREGNUMCHK->AsString=fr->RegNumberKKM;
			DM->DocSAVNUMCHK->AsString=fr->SerialNumberKKM;
			DM->DocMODELCHK->AsString=fr->ModelKKM;
			DM->Doc->Post();
			if (DM->SaveDoc()!=true)
				{
				ShowMessage("Ошибка при записи документа: "+DM->TextError);
				} 
			}
		catch(Exception &exception)
			{
			ShowMessage("Ошибка! "+exception.Message);
			}
		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}
	DMSprOborud->kanRelease();
	}
FormaViborFR=0;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::cxButtonPrintCheckFRClick(TObject *Sender)
{

	if (DM->DocNCHECKCHK->AsInteger>0)
		{
		String V="Кассовый чек уже пробит! Пробить ещё один?";
		String Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
			{
			PrintCheckFR();
			}
		}
	else
		{
		PrintCheckFR();
		}

}
//---------------------------------------------------------------------------







void __fastcall TFormaDocCheck::TypePriceComboBoxPropertiesChange(
	  TObject *Sender)
{
if (flNoChangeTypePrice==true) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

//if (NoEdit==true)
//        {
//        UpdateForm();
//         return;
//        }

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
											 glStrToInt64(DM->DocTIDNOMCHKT->AsString));
						DM->DocTPRICECHKT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFCHKT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
		
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::OperationPropertiesChange(TObject *Sender)
{
DM->Doc->Edit();
DM->Doc->FieldByName("OPERCHK")->AsInteger=Operation->ItemIndex;
DM->Doc->Post();
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();    	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocCheck::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NameDogcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprDogovor();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NameKassacxDBButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprKKM();
}
//---------------------------------------------------------------------------

void TFormaDocCheck::ViborDiscountCard(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprDiscountCard==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard.1",IID_IFormaSpiskaSprDiscountCard,
													(void**)&FormaSpiskaSprDiscountCard);
		FormaSpiskaSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprDiscountCard->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		FormaSpiskaSprDiscountCard->DM->OpenTable(DM->DocAllIDKLDOC->AsInteger);
		//FormaSpiskaSprDiscountCard->LabelKlient->Caption="Контрагент: "+DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->NameKlient=DM->DocAllNAMEKLIENT->AsString;
		FormaSpiskaSprDiscountCard->Vibor=true;
		FormaSpiskaSprDiscountCard->NumberProcVibor=9;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborDiscountCard(void)
{

	DM->Doc->Edit();
	DM->DocIDDCARDCHK->AsString=FormaSpiskaSprDiscountCard->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->DocNAME_SDISCOUNT_CARD->AsString=FormaSpiskaSprDiscountCard->DM->TableNAME_SDISCOUNT_CARD->AsString;
    DM->Doc->Post();


}
//----------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NameDCardcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborDiscountCard();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocCheck::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocCheck::OplNalcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::OplPCcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::NalCHKcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::ActionInsertStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();
}
//---------------------------------------------------------------------------

void TFormaDocCheck::ViborDocOsn(void)
{

if (Prosmotr==true) return;
if (FormaGurAllDoc==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
		FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
		FormaGurAllDoc->Vibor=true;
		FormaGurAllDoc->NumberProcVibor=10;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborDocOsn(void)
{


				DM->DocAll->Edit();
				DM->DocAllIDDOCOSNDOC->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
				DM->DocAll->Post();
				DM->OpenDocOsn();



}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::DocOsncxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDocOsn();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDDOCOSNDOC->Clear();
		DM->DocAll->Post();
		DM->OpenDocOsn();
		}break;
	}
}
//---------------------------------------------------------------------------

//Внешние модули
void __fastcall TFormaDocCheck::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocCheck::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;

	InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
														(void**)&module);
	module->Init(InterfaceMainObject,InterfaceImpl);
	module->IdModule=id_module;
	module->TypeTable=1;

	module->ClearModule();
	module->LoadModule();

	//надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));
	module->ExecuteModule();

}
//---------------------------------------------------------------------------

void TFormaDocCheck::OpenFormSpiskaSprBSchet(void)
{ 
if (Prosmotr==true) return;
if (SpisokBSchet==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&SpisokBSchet);
		SpisokBSchet->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBSchet->NumberProcVibor=12;
		SpisokBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
		SpisokBSchet->DM->OpenTable();
		//SpisokBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
		SpisokBSchet->Vibor=true;

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborBSchet(void)
{

	DM->Doc->Edit();
	DM->DocIDBSCHET_DCHK->AsString=SpisokBSchet->DM->TableIDBSCHET->AsString;
	DM->DocNAMEBSCHET->AsString=SpisokBSchet->DM->TableNAMEBSCHET->AsString;
    DM->Doc->Post();


}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::NameBSchetcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprBSchet();
}
//---------------------------------------------------------------------------

void TFormaDocCheck::ViborCardOpl(void)
{
if (Prosmotr==true) return;
if (SprCardOpl==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard_1.1",IID_IFormaSpiskaSprDiscountCard_1,
													(void**)&SprCardOpl);
		SprCardOpl->Init(InterfaceMainObject,InterfaceImpl);
		SprCardOpl->Vibor=true;
		SprCardOpl->IdDiscountCard=glStrToInt64(DM->DocOplIDCARD_DCHK_OPL->AsString);
		SprCardOpl->UpdateForm();
		SprCardOpl->NumberProcVibor=13;
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborCardOpl(void)
{

	if (ActionOperationCardOpl==ActionOperationCardOpl_New)
		{
		DM->DocOpl->Append();
		}

	DM->DocOpl->Edit();
	DM->DocOplIDCARD_DCHK_OPL->AsString=SprCardOpl->DM->TableID_SDISCOUNT_CARD->AsString;
	DM->DocOplNAME_SDISCOUNT_CARD->AsString=SprCardOpl->DM->TableNAME_SDISCOUNT_CARD->AsString;
    DM->DocOpl->Post();


}
//---------------------------------------------------------------------------
void __fastcall TFormaDocCheck::ToolButtonAddPriceClick(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperationCardOpl=ActionOperationCardOpl_New;
ViborCardOpl();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::ToolButtonDeletePriceClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DocOpl->Delete();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::cxGrid2DBTableView1NAME_SDISCOUNT_CARDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
ActionOperationCardOpl=ActionOperationCardOpl_NO;
ViborCardOpl();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocCheck::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}

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

void __fastcall TFormaDocCheck::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}
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

void __fastcall TFormaDocCheck::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	 return;
	}

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

void __fastcall TFormaDocCheck::ActionPrintExecute(TObject *Sender)
{
PrintGoodsCheck();
}
//---------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=11;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocCheck::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=14;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void __fastcall TFormaDocCheck::NameProjectcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
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
void __fastcall TFormaDocCheck::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocCheck::PrefiksNumcxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------




void TFormaDocCheck::ViborDepartment(void)
{
if (kasFormSpr==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprDepartment,IID_IkasFormSpr,
													 (void**)&kasFormSpr);
		kasFormSpr->Init(InterfaceMainObject,InterfaceImpl);
		kasFormSpr->UpdateForm();
		kasFormSpr->NumberProcVibor=15;
		kasFormSpr->Vibor=true;
		}

}
//----------------------------------------------------------
void TFormaDocCheck::EndViborDepartment(void)
{

	DM->DocT->Edit();
	DM->DocTIDDEPARTMENT_DCHKT->AsString=kasFormSpr->DM->GetValueFieldAsInt64("ID_SDEPARTMENT",0);
	DM->DocTNAME_SDEPARTMENT->AsString=kasFormSpr->DM->GetValueFieldAsString("NAME_SDEPARTMENT",0);
	DM->DocT->Post();


//FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------

void __fastcall TFormaDocCheck::cxGrid1DBTableView1NAME_SDEPARTMENTPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborDepartment();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDDEPARTMENT_DCHKT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

