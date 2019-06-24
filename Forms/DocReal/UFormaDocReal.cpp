//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaDocReal.h"
#include "IDMSprPrice.h"
#include "IFormaDocSchetFact.h"
#include "IDMSprFirm.h"
#include "IDMSprBankSchet.h"
#include "IDMSprBank.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaDocOtchetPost.h"

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
#pragma link "cxTextEdit"
#pragma link "cxMaskEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocReal::TFormaDocReal(TComponent* Owner)
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
bool TFormaDocReal::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMDocReal,IID_IDMDocReal,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


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

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameGrPolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameRaschScetKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameRaschSchetGrpolcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;

ActionOperation=aoNO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRealImpl),false);
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
int TFormaDocReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocReal::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
NoEdit=DM->NoEdit;
if (Prosmotr==true)
        {
		ProsmotrLabel->Visible=true;
		cxGrid1DBTableView1->OptionsData->Editing=false;
		}
else
        {
        ProsmotrLabel->Visible=false;
		cxGrid1DBTableView1->OptionsData->Editing=true;
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
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICEREA->AsString));
flObrabatChangeTypePrice=true;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocReal::FormActivate(TObject *Sender)
{
//if (glScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::FormDeactivate(TObject *Sender)
{
//if (glScaner) glScaner->ReadSh=ReadShtrihCodEvent;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocReal::ReadShtrihCodEvent(int number, UnicodeString sh)
{
AnsiString s=sh;
//надо учитывать что считан может быть и весовой код
IDMSprNom * DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);

__int64 id_nom=DMSprNom->FindPoShtrihCodu(s);

if (id_nom!=0)
		{
		DMSprNom->IdTypePrice=glStrToInt64(DM->DocIDTPRICEREA->AsString);
        DMSprNom->OpenElement(id_nom);
        DM->AddDocNewString();

        DM->DocT->Edit();
		DM->DocTIDNOMREAT->AsString=DMSprNom->ElementIDNOM->AsString;
        DM->DocTNAMENOM->AsString=DMSprNom->ElementNAMENOM->AsString;
        DM->DocTTNOM->AsInteger=DMSprNom->ElementTNOM->AsInteger;
		DM->DocTKOLREAT->AsInteger=1;
		DM->DocTKFREAT->AsFloat=DMSprNom->OsnEdKFED->AsFloat;
		DM->DocTPRICEREAT->AsFloat=DMSprNom->ElementZNACH_PRICE->AsFloat;

		DM->DocTIDEDREAT->AsString=DMSprNom->ElementIDOSNEDNOM->AsString;
        DM->DocTNAMEED->AsString=DMSprNom->OsnEdNAMEED->AsString;

        DM->DocT->Post();

		cxGrid1->SetFocus();
		//DBGrid1->SelectedField=DM->DocTKOLREAT;

        }
else
        {
        ShowMessage("Товар со штрих кодом "+s+" не найден!");
        return;
        }

delete DMSprNom;

UpdateForm();


}
//---------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormaDocReal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormSpiskaSprBSchet)FormSpiskaSprBSchet->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(FormaSpiskaSprRaschSchet)FormaSpiskaSprRaschSchet->kanRelease();

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




void TFormaDocReal::OpenFormSpiskaSprEd(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_Ed;
		SpisokEd->Vibor=true;
		SpisokEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOMREAT->AsString));
        }
}
//-----------------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprNom(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (SpisokNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->NumberProcVibor=ER_Nom;
		SpisokNom->Vibor=true;
		SpisokNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICEREA->AsString);
		SpisokNom->IdNom=glStrToInt64(DM->DocTIDNOMREAT->AsString);
        SpisokNom->UpdateForm();
        }

}

//---------------------------------------------------------------------------
int TFormaDocReal::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
				DM->DocTIDNOMREAT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLREAT->AsFloat=1;
				DM->DocTIDEDREAT->AsString=SpisokNom->DM->ElementIDOSNEDNOM->AsString;
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
                DM->DocTKFREAT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICEREA->AsString),
											glStrToInt64(DM->DocTIDNOMREAT->AsString));
                        DM->DocTPRICEREAT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKFREAT->AsFloat;
                DMSprPrice->kanRelease();
                DM->DocT->Post();
                }
		SpisokNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLREAT->Selected=true;
        }

if (number_procedure_end==ER_Ed)//EditRekvisit==ViborEdinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDREAT->AsString=SpisokEd->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKFREAT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICEREA->AsString),
											 glStrToInt64(DM->DocTIDNOMREAT->AsString));
                        DM->DocTPRICEREAT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKFREAT->AsFloat;
				DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		SpisokEd=0;

		cxGrid1->SetFocus();
		cxGrid1DBTableView1PRICEREAT->Selected=true;
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
                
                DM->Doc->Edit();
				DM->DocIDGRPOLREA->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->Doc->Post();

				if (glStrToInt64(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsString)!=0)
					{
					TypePriceComboBox->ItemIndex=
						DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(SpisokKlient->DM->ElementIDTPRICEKLIENT->AsString));
					}  
                }
		SpisokKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_GrPol)//EditRekvisit==ViborGrPol)
        {
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDGRPOLREA->AsString=SpisokKlient->DM->ElementIDKLIENT->AsString;
                DM->DocNAMEKLIENT->AsString=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->Doc->Post();
                }
		SpisokKlient=0;
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

 if (number_procedure_end==ER_BankSchet)//EditRekvisit==ViborBankSchet)
        {
        if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDBSCHETREA->AsString=FormSpiskaSprBSchet->DM->TableIDBSCHET->AsString;
                DM->DocNAMEBSCHET->AsString=FormSpiskaSprBSchet->DM->TableNAMEBSCHET->AsString;
                DM->Doc->Post();
                }
		FormSpiskaSprBSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

 if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_RaschSchetKlient)
		{
		if (type_event==1)
				{
				EndViborRaschSchetKlient()  ;
				}
		FormaSpiskaSprRaschSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_RaschSchetGrpol)
		{
		if (type_event==1)
				{
				EndViborRaschSchetGrpol()  ;
				}
		FormaSpiskaSprRaschSchet=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

ActionOperation=aoNO;
return -1;
}

//---------------------------------------------------------------------------


void TFormaDocReal::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (SpisokFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->NumberProcVibor=ER_Firm;
		SpisokFirm->Vibor=true;
        }

}
//------------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprBSchet(void)
{
if (FormSpiskaSprBSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&FormSpiskaSprBSchet);
	FormSpiskaSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormSpiskaSprBSchet->NumberProcVibor=ER_BankSchet;
	FormSpiskaSprBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
	FormSpiskaSprBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRMDOC->AsString);
	FormSpiskaSprBSchet->DM->OpenTable();
	//FormSpiskaSprBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
	FormSpiskaSprBSchet->Vibor=true;
	}
}
//---------------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (SpisokSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->NumberProcVibor=ER_Sklad;
        SpisokSklad->Vibor=true;
        }

}
//--------------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprKlient(void)
{
if (Prosmotr==true) return;
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ER_Klient;
		SpisokKlient->Vibor=true;
		SpisokKlient->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
		SpisokKlient->UpdateForm();
    }
}

//--------------------------------------------------------------------------





void TFormaDocReal::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
        }
}
//---------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprGrPol(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
		SpisokKlient->NumberProcVibor=ER_GrPol;
        SpisokKlient->Vibor=true;
	}
}
//-------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TFormaDocReal::OpenPrintFormNakl(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportNakl(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputStringNakl(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReportNakl(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocReal::OutputZagolovokReportNakl(TSheetEditor *prForm)
{
numRow=1;
numCol=2;
TcxSSCellObject *cell;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
        cHeader->Size[8] = 80;


IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprFirm->ElementFNAMEFIRM->AsString+
                "ИНН "+DMSprFirm->ElementINNFIRM->AsString;
delete cell;
numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+DMSprFirm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++;
numRow++;

DMSprFirm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Расходная накладная №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Покупатель: "+DMSprKlient->ElementFNAME->AsString
						+", ИНН "+DMSprKlient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMREA->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocReal::OutputStringNakl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOLREAT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKFREAT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICEREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocReal::OutputPodavalReportNakl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="Всего";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Отпустил:  _________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Text="Получил:  _________________________ ";
delete cell;
numRow++;numRow++;

}
//---------------------------------------------------------------

void __fastcall TFormaDocReal::ToolButtonPrintNaklClick(TObject *Sender)
{
OpenPrintFormNakl();
}
//---------------------------------------------------------------------------
void TFormaDocReal::OpenPrintFormAkt(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportAkt(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {
        if(DM->DocTTNOM->AsInteger==1)
                {
                OutputStringAkt(PrintForm);numRow++; porNumStr++;
                }
        DM->DocT->Next();
        }

OutputZagolovokReportAktKompl(PrintForm);

DM->DocT->First();
while(!DM->DocT->Eof)
        {
        if(DM->DocTTNOM->AsInteger!=1)
                {
                OutputStringAkt(PrintForm);numRow++; porNumStr++;
                }
        DM->DocT->Next();
        }

OutputPodavalReportAkt(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocReal::OutputZagolovokReportAkt(TSheetEditor *prForm)
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
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
        cHeader->Size[8] = 80;




IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Исполнитель: "+DMSprFirm->ElementFNAMEFIRM->AsString+
                "ИНН "+DMSprFirm->ElementINNFIRM->AsString;
delete cell;
numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+DMSprFirm->ElementPADRFIRM->AsString;
delete cell;

numRow++;
numRow++;

DMSprFirm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Акт на выполненные работы №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Заказчик: "+DMSprKlient->ElementFNAME->AsString
                        +", ИНН "+DMSprKlient->ElementINNKLIENT->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMREA->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Выполненные работы";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocReal::OutputZagolovokReportAktKompl(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Израсходованные комплектующие";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Кол-во";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="К";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;


numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocReal::OutputStringAkt(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->WordBreak = true;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOLREAT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKFREAT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICEREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

}


//------------------------------------------------------------------------------
void TFormaDocReal::OutputPodavalReportAkt(TSheetEditor *prForm)
{
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="ВСЕГО : "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
delete cell;
numRow++;numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Вышеперечисленные услуги оказаны полностью и в срок.";
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Заказчик претензий по объему, качеству и срокам оказания услуг не имеет.";
delete cell;
numRow++;
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Исполнитель:  _________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Text="Заказчик  ________________________ ";
delete cell;
numRow++;numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text="М.П.";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="М.П.";
delete cell;
}
//---------------------------------------------------------------
void __fastcall TFormaDocReal::ToolButtonPrintAktClick(TObject *Sender)
{
OpenPrintFormAkt();        
}
//-----------------------------------------------------------------------------
void TFormaDocReal::OpenPrintFormTORG12(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=0;
numCol=1;
porNumStr=1;
HeightPage=640;
TecHeight=0;
HeightPodval=270;
HeightString=20;
//шапка   5850
TecHeight=0;
PrintForm->SS->EndUpdate();
OutputShapkaReportTORG12(PrintForm);

//таблица

NumPage=1;

SizeShapka=0;
SizePodval=0;



ItogoKolNaPage=0;
ItogoSumNaPage=0;
ItogoNDSNaPage=0;
ItogoSumSNDSNaPage=0;

ItigoKol=0;
ItogoSum=0;
ItogoNDS=0;
ItogoSumSNDS=0;

PrintForm->SS->BeginUpdate();
PrintForm->SS->ActiveSheet->Caption= "Стр.1";
OutputZagolovokPageTORG12(PrintForm);

DM->DocT->First();
while(!DM->DocT->Eof)
        {
        int NadoHeight=(DM->DocT->RecordCount-porNumStr)*HeightString+HeightPodval;
        if ((HeightPage-TecHeight-NadoHeight)>0)
                {  //войдет остакток

                }
        else
                {//не войдет
                if ((HeightPage-TecHeight-HeightString)<0)
                        { //строка не войдет
                        OutputItogiPageTORG12(PrintForm);
                        //PrintForm->F1->Row=numRow;
                        //PrintForm->F1->Col=numCol;
                        //PrintForm->F1->AddPageBreak();
                        PrintForm->SS->AddSheetPage("Стр."+IntToStr(NumPage+1));
                        PrintForm->SS->ActivePage++;
                        numRow=0;
                        numCol=1;
                        ItogoKolNaPage=0;
                        ItogoSumNaPage=0;
                        ItogoNDSNaPage=0;
                        ItogoSumSNDSNaPage=0;
                        NumPage=NumPage+1;
                        TecHeight=0;
                        OutputZagolovokPageTORG12(PrintForm);
                        }
                else
                        { //войдет строка
                        if (DM->DocT->RecordCount==porNumStr)
                                { //последняя строка, переносим на новую страницу
                                OutputItogiPageTORG12(PrintForm);
                                //PrintForm->F1->Row=numRow;
                                //PrintForm->F1->Col=numCol;
                               // PrintForm->F1->AddPageBreak();
                                PrintForm->SS->AddSheetPage("Стр."+IntToStr(NumPage+1));
                                PrintForm->SS->ActivePage++;
                                numRow=0;
                                numCol=1;
                                ItogoKolNaPage=0;
                                ItogoSumNaPage=0;
                                ItogoNDSNaPage=0;
                                ItogoSumSNDSNaPage=0;
                                NumPage=NumPage+1;
                                TecHeight=0;
                                OutputZagolovokPageTORG12(PrintForm);
                                }
                        }
                }


        OutputStringTORG12(PrintForm); porNumStr++;
        ItogoSumSNDSNaPage=ItogoSumSNDSNaPage+DM->DocTSUMREAT->AsFloat;
        ItogoSumSNDS=ItogoSumSNDS+DM->DocTSUMREAT->AsFloat;

        DM->DocT->Next();
        }

OutputItogiPageTORG12(PrintForm);
OutputVsegoTORG12(PrintForm);

OutputPodavalReportTORG12(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();

}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputShapkaReportTORG12(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
TcxSSHeader *cHeader;
prForm->SS->DefaultStyle->Font->Size=8;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->DefaultRowHeight=14;
prForm->SS->ShowGrid=false;
//prForm->dxComponentPrinter1->Pag<<poLandscape;



numCol=16;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="Унифицированная форма №ТОРГ-12";
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="Утверждена постановлением Госкомстата России от 25.12.98 №132";
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 6;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Коды";
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="0330212";
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol-1, numRow+1);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Форма по ОКУД";
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//------------------новая строка---------------------------------------
//***************************

//100 символов
IDMSprFirm * DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));
FioDir=DMSprFirm->ElementDIRFIRM->AsString;
FioBuh=DMSprFirm->ElementBUHFIRM->AsString;


IDMSprBankSchet * DMSprBSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet,
													(void**)&DMSprBSchet);
DMSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
DMSprBSchet->OpenElement(glStrToInt64(DM->DocIDBSCHETREA->AsString));
IDMSprBank * DMSprBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBank.1",IID_IDMSprBank,
													(void**)&DMSprBank);
DMSprBank->Init(InterfaceMainObject,InterfaceImpl);
DMSprBank->OpenElement(glStrToInt64(DMSprBSchet->ElementIDBANKBSCHET->AsString));

Text=Trim(DMSprFirm->ElementFNAMEFIRM->AsString)+
        ", ИНН"+Trim(DMSprFirm->ElementINNFIRM->AsString)+
        ", "+Trim(DMSprFirm->ElementUADRFIRM->AsString)+
        ", Расч. счет №"+DMSprBSchet->ElementNUMBSCHET->AsString+
        " в "+DMSprBank->ElementNAMEBANK->AsString+
        ", г."+DMSprBank->ElementGORBANK->AsString+
        ", корр. счет №"+DMSprBank->ElementKSBANK->AsString+
        ", БИК "+DMSprBank->ElementBIKBANK->AsString;

DMSprBSchet->kanRelease();
DMSprBank->kanRelease();

numCol=2;
        TRect rect;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+10;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;

        TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
        numRow++;
        TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
        numRow++;
//********************************************

for (int i=2;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Font->Size = 6;
cell->Text="организация-грузоотправитель, адрес, телефон, факс, банковские реквизиты";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow-1);
cell->Text="по ОКПО";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow-1);
cell->Text=DMSprFirm->ElementOKPOSFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//--------------------------следующая строка---------------------------
//********************************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

for (int i=2;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Font->Size = 6;
cell->Text="структурное подразделение";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//--------------------------следующая строка---------------------------
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Вид деятельности по ОКДП";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;
//------------------новая строка---------------------------------------
//***************************

//100 символов
IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient ,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocIDGRPOLREA->AsString));
Text="ГРУЗОПОЛУЧАТЕЛЬ:  "+Trim(DMSprKlient->ElementNAMEKLIENT->AsString)+
        "; ИНН "+Trim(DMSprKlient->ElementINNKLIENT->AsString)+
        "; "+Trim(DMSprKlient->ElementADRKLIENT->AsString);

numCol=3;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+9;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text=Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
for (int i=3;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
//numRow++;

//********************************************


//cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
//cell->Style->Font->Size = 6;
//cell->Text="организация, адрес, телефон, факс, банковские реквизиты";
//delete cell;

//cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;

//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Text="по ОКПО";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Text=DMSprKlient->ElementOKPOKLIENT->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************

//100 символов
Text="ПОСТАВЩИК:  "+Trim(DMSprFirm->ElementFNAMEFIRM->AsString)+
        ", ИНН"+Trim(DMSprFirm->ElementINNFIRM->AsString)+
        ", "+Trim(DMSprFirm->ElementUADRFIRM->AsString);

numCol=3;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+9;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text=Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
delete cell;


        //***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];

for (int i=3;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
//numRow++;

//********************************************


//cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
//cell->Style->Font->Size = 6;
//cell->Text="организация, адрес, телефон, факс, банковские реквизиты";
//delete cell;

//cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;

//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Text="по ОКПО";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Text=DMSprFirm->ElementOKPOSFIRM->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************


DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKLDOC->AsString));
Text="ПЛАТЕЛЬЩИК:  :  "+Trim(DMSprKlient->ElementNAMEKLIENT->AsString)+
        "; ИНН "+Trim(DMSprKlient->ElementINNKLIENT->AsString)+
        "; "+Trim(DMSprKlient->ElementADRKLIENT->AsString);

numCol=3;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+9;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text=Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
delete cell;


        //***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];

for (int i=3;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
//numRow++;

//********************************************



//cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
//cell->Style->Font->Size = 6;
//cell->Text="организация, адрес, телефон, факс, банковские реквизиты";
//delete cell;

//cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//delete cell;

//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Text="по ОКПО";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Text=DMSprKlient->ElementOKPOKLIENT->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************
numCol=3;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+9;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

//100 символов
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Text="ОСНОВАНИЕ:   "+DM->DocPRIMREA->AsString;
delete cell;


//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow-1);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="номер";
//cell->Style->Font->Size = 16;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//********************************************

for (int i=3;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Font->Size = 6;
cell->Text="договор, наряд-заказ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="дата";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Text="Номер документа ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text="Дата составления ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(9, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(14, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Транспортная накладная";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="номер";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
prForm->SS->ActiveSheet->Rows->Size[numRow]=20;
//***************************
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="ТОВАРНАЯ НАКЛАДНАЯ  ";
delete cell;

        rect.Left = 6;
        rect.Top = numRow;
        rect.Right = 7;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=DM->DocAllNUMDOC->AsString;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

        rect.Left = 8;
        rect.Top = numRow;
        rect.Right = 9;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=DateToStr(DM->DocAllPOSDOC->AsDateTime);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(9, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="дата";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
//***************************
prForm->SS->ActiveSheet->Rows->Size[numRow]=20;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

//------------------новая строка---------------------------------------
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="вид операции";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
//***************************
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;



DMSprKlient->kanRelease();
DMSprFirm->kanRelease();

}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputZagolovokPageTORG12(TSheetEditor *prForm)
{

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 180;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 60;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 50;
        cHeader->Size[8] = 55;
        cHeader->Size[9] = 55;
        cHeader->Size[10] = 50;
        cHeader->Size[11] = 60;
        cHeader->Size[12] = 60;
        cHeader->Size[13] = 60;
		cHeader->Size[14] = 55;
        cHeader->Size[15] = 55;
        cHeader->Size[16] = 80;

TcxSSCellObject *cell;
numCol=16;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Страница №"+IntToStr(NumPage);
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];
numRow++;

numCol=2;
        TRect rect;
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Но- мер по по- рядку";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Товар";

cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="Наименование, характеристика, сорт, артикул товара";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="код";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица измерения";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="наиме- нование";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="код по ОКЕИ";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

//*************************

        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Вид упаковки";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Количество";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="в одном месте";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="7";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
//*************************

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="мест, штук";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="8";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Масса брутто";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="9";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Количество (масса нетто)";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="10";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Text="Цена, руб. коп.";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="11";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text="Сумма без учета НДС, руб. коп.";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="12";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol+1;
        rect.Bottom = numRow;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="НДС";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="ставка %";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="13";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text="Сумма руб. коп.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="14";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

//*************************
        rect.Left = numCol;
        rect.Top = numRow;
        rect.Right = numCol;
        rect.Bottom = numRow+1;
        prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма с учетом НДС руб. коп.";
cell->Style->WordBreak = true;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);

cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+2);
cell->Text="15";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

prForm->SS->ActiveSheet->Rows->Size[numRow+1]=45;
prForm->SS->ActiveSheet->Rows->Size[numRow+2]=15;

TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow]; numRow++;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow]; numRow++;
TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow]; numRow++;
}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputStringTORG12(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
cell->Style->WordBreak = true;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DM->DocTKOLREAT->AsFloat!=0)
        {
        cell->Text=FloatToStrF(DM->DocTKOLREAT->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICEREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Без НДС";
cell->Style->HorzTextAlign = haCENTER;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="0";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUMREAT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

TecHeight=TecHeight+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;
}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputItogiPageTORG12(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//***************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Итого";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="0";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(ItogoSumSNDSNaPage,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputVsegoTORG12(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=9;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Всего по накладной";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="0";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//*************************
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(ItogoSumSNDS,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

}
//-----------------------------------------------------------------------------
void TFormaDocReal::OutputPodavalReportTORG12(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
//*************************
AnsiString slovo="";

if ((NumPage>10) && (NumPage<20) )
        {
        slovo=" листах";
        }
else
        {
        AnsiString strNumPage=IntToStr(NumPage);
        if (strNumPage[strNumPage.Length()]=='1')
                {
                slovo=" листе";
                }
        else
                {
                slovo=" листах";
                }
        }


cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Товарная накладная имеет приложение на ";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Text=glIntegerValuePropis(NumPage)+slovo;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(9, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(10, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;



SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];numRow++;
//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=" и содержит ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Text=glIntegerValuePropis(porNumStr-1);
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Text=" порядковых номеров записей";
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];    numRow++;
//------новая строка------------

for (int i=4;i<=12;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Font->Size = 6;
cell->Text="прописью";
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];numRow++;
//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Масса груза (нетто)";
delete cell;

for (int i=9;i<=14;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;


SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow]; numRow++;

//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Всего мест";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Масса груза (брутто)";
delete cell;

for (int i=9;i<=14;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }

cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];numRow++;
SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];numRow++;

//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="Приложение (паспорта, сертификаты и т.п.) на";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="листах";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="По доверенности №";
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(12, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text=" от ";
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(14, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(15, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Font->Size = 6;
cell->Text="прописью";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;


SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];numRow++;
//------новая строка------------

String Text="Всего отпущено на сумму: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
String Stroka="";
bool a;
int KolStrok=0;

a=true;
while (a==true && KolStrok<=2)
        {
         if (Text.Length()<64)
                {
                cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
                cell->Style->Font->Size = 8;
                cell->Text=Text;
                cell->Style->Font->Style = TFontStyles() << fsBold;
                delete cell;
                a=false;
                }
        else
                {
                Stroka=Text;
                Stroka.SetLength(64);
                int i=Stroka.Length();
                while(Stroka[i]!=' ')
                        {
                        Stroka.Delete(i,1);
                        i--;
                        }
                Text=Text.Delete(1,Stroka.Length());
                cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
                cell->Style->Font->Size = 8;
                cell->Text=Stroka;
                cell->Style->Font->Style = TFontStyles() << fsBold;
                delete cell;
                KolStrok++;
                }
        //***************************
        cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        delete cell;

        SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow]; numRow++;
        }
//********************************************
//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Отпуск разрешил  _____________________";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text=FioDir;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="выданной";
delete cell;

for(int i=12; i<=16;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];   numRow++;



//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="должность             ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Font->Size = 6;
cell->Text="   подпись";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="расшифровка подписи      ";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell; 

cell = prForm->SS->ActiveSheet->GetCellObject(14, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 6;
cell->Text="кем, кому (организация, должность, ФИО)";
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;
//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Главный (старший) бухгалтер";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text=FioBuh;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Груз принял";
delete cell;

for(int i=12; i<=16;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;

//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Font->Size = 6;
cell->Text="    подпись";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="расшифровка подписи      ";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(12, numRow);
cell->Style->Font->Size = 6;
cell->Text="    должность";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(14, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="подпись";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="    расшифровка подписи";
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;

//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Отпуск груза произвел  ________________";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="Груз получил";
delete cell;


for(int i=12; i<=16;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        }
SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];   numRow++;

//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="должность        ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Style->Font->Size = 6;
cell->Text="   подпись";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="расшифровка подписи      ";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(11, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="грузополучатель";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(12, numRow);
cell->Text="    должность";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(14, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="подпись";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(16, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="    расшифровка подписи";
delete cell;

SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];  numRow++;
//------новая строка------------
cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="М.П.";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Style->Font->Size = 6;
cell->Text="\"         \" ___________ 200 ___года";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(12, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Text="М.П.";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(13, numRow);
cell->Text="\"         \" ___________ 200 ___года";
delete cell;
SizePodval=SizePodval+prForm->SS->ActiveSheet->Rows->Size[numRow];
//ShowMessage(IntToStr(SizePodval));
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocReal::ToolButtonPrintTorg12Click(TObject *Sender)
{
OpenPrintFormTORG12();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocReal::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocReal");
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocReal::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

		OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;

		OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::cxButtonCreateSFClick(TObject *Sender)
{
DM->SaveDoc();

IFormaDocSchetFact* doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocSchetFact.1",IID_IFormaDocSchetFact,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;
//проверим а нет ли уже счета
int id_doc_schet_fact=DM->GetIDDocSchetFact() ;
if (id_doc_schet_fact!=0)
        {
         //откроем документ
		doc->DM->OpenDoc(id_doc_schet_fact);
        }
else
        {
//создадим документ
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDDOCOSNDOC->AsString=DM->DocAllIDDOC->AsString;
doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDSKLDOC->AsString=DM->DocAllIDSKLDOC->AsString;
doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocIDTPRICE_DSCHFACT->AsString=DM->DocIDTPRICEREA->AsString;
doc->DM->DocPRIM_DSCHFACT->AsString="Релизация №"+DM->DocAllNUMDOC->AsString+
                        " от "+ DM->DocAllPOSDOC->AsString;
doc->DM->DocIDGRPOL_DSCHFACT->AsString=DM->DocIDGRPOLREA->AsString;
doc->DM->DocNAMEKLIENT->AsString=DM->DocNAMEKLIENT->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
        {
        doc->DM->DocT->Insert();
		doc->DM->DocTIDNOM_DSCHFACTT->AsString=DM->DocTIDNOMREAT->AsString;
        doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		doc->DM->DocTIDED_DSCHFACTT->AsString=DM->DocTIDEDREAT->AsString;
		doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
        doc->DM->DocTKOL_DSCHFACTT->AsFloat=DM->DocTKOLREAT->AsFloat;
        doc->DM->DocTKF_DSCHFACTT->AsFloat=DM->DocTKFREAT->AsFloat;
        doc->DM->DocTPRICE_DSCHFACTT->AsFloat=DM->DocTPRICEREAT->AsFloat;
        doc->DM->DocT->Post();
        DM->DocT->Next();
        }
        }
doc->UpdateForm();

}
//---------------------------------------------------------------------------





void __fastcall TFormaDocReal::NameGrPolcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprGrPol();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprKlient();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocReal::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
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

if ( TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICEREA->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
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
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICEREA->AsString),
											 glStrToInt64(DM->DocTIDNOMREAT->AsString));
						DM->DocTPRICEREAT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFREAT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				delete DMSprPrice;
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NameBSchetcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprBSchet();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocReal::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocReal::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocReal::RunExternalModule(__int64 id_module, int type_module)
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


void __fastcall TFormaDocReal::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocReal::ActionSaveExecute(TObject *Sender)
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

void __fastcall TFormaDocReal::ActionDvRegExecute(TObject *Sender)
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
void TFormaDocReal::OpenFormSpiskaSprProject(void)
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
void __fastcall TFormaDocReal::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocReal::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TFormaDocReal::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocReal::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDocReal::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void TFormaDocReal::ViborRaschSchetKlient(void)
{

if (FormaSpiskaSprRaschSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&FormaSpiskaSprRaschSchet);
	FormaSpiskaSprRaschSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprRaschSchet->IdKlient=glStrToInt64(DM->DocAllIDKLDOC->AsString);
	FormaSpiskaSprRaschSchet->DM->OpenTable(glStrToInt64(DM->DocAllIDKLDOC->AsString));
	//SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprRaschSchet->NumberProcVibor=ER_RaschSchetKlient;
	FormaSpiskaSprRaschSchet->Vibor=true;
	}

}
//---------------------------------------------------------------------------
void TFormaDocReal::ViborRaschSchetGrpol(void)
{
if (FormaSpiskaSprRaschSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprRaschSchet.1",IID_IFormaSpiskaSprRaschSchet,
													(void**)&FormaSpiskaSprRaschSchet);
	FormaSpiskaSprRaschSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprRaschSchet->IdKlient=glStrToInt64(DM->DocIDGRPOLREA->AsString);
	FormaSpiskaSprRaschSchet->DM->OpenTable(glStrToInt64(DM->DocIDGRPOLREA->AsString));
	//SpisokRSchet->LabelKlient->Caption="Контрагент: "+DM->ElementNAMEKLIENT->AsString;
	FormaSpiskaSprRaschSchet->NumberProcVibor=ER_RaschSchetGrpol;
	FormaSpiskaSprRaschSchet->Vibor=true;
	}


}
//---------------------------------------------------------------------------
void TFormaDocReal::EndViborRaschSchetKlient(void)
{

	DM->Doc->Edit();
	DM->DocIDRSCHETKLIENT_DREA->AsString=FormaSpiskaSprRaschSchet->DM->TableIDRSCHET->AsString;
	DM->DocNAME_RSCHET_KLIENT->AsString=FormaSpiskaSprRaschSchet->DM->TableNAMERSCHET->AsString;
	DM->Doc->Post();

}
//---------------------------------------------------------------------------
void TFormaDocReal::EndViborRaschSchetGrpol(void)
{


	DM->Doc->Edit();
	DM->DocIDRSCHETGRPOL_DREA->AsString=FormaSpiskaSprRaschSchet->DM->TableIDRSCHET->AsString;
	DM->DocNAME_RSCHET_GRPOL->AsString=FormaSpiskaSprRaschSchet->DM->TableNAMERSCHET->AsString;
	DM->Doc->Post();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocReal::NameRaschScetKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRaschSchetKlient();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDRSCHETKLIENT_DREA->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::NameRaschSchetGrpolcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRaschSchetGrpol();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Doc->Edit();
		DM->DocIDRSCHETGRPOL_DREA->Clear();
		DM->Doc->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocReal::ToolButtonCreateOtchetPostClick(TObject *Sender)
{

			IFormaDocOtchetPost * doc;
			InterfaceGlobalCom->kanCreateObject(ProgId_FormaDocOtchetPost,
								IID_IFormaDocOtchetPost, (void**) & doc);
			doc->Init(InterfaceMainObject, InterfaceImpl);
			doc->DM->NewDoc();
			doc->UpdateForm();

			doc->DM->DocAll->Edit();
			doc->DM->DocAllIDBASE_GALLDOC->AsString=DM->DocAllIDBASE_GALLDOC->AsString;
			doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
			doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRMDOC->AsString;
			doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
			doc->DM->DocAllIDSKLDOC->AsString=DM->DocAllIDSKLDOC->AsString;
			doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
			doc->DM->DocAll->Post();

			while (!DM->DocT->Eof)
				{
				doc->DM->AddDocNewString();
				doc->DM->DocT->Edit();
				doc->DM->DocTIDNOM_DOTCHPOSTT->AsString=DM->DocTIDNOMREAT->AsString;
				doc->DM->DocTIDED_DOTCHPOSTT->AsString=DM->DocTIDEDREAT->AsString;
				doc->DM->DocTARTNOM->AsString=DM->DocTARTNOM->AsString;
				doc->DM->DocTCODENOM->AsString=DM->DocTCODENOM->AsString;
				doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
				doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
				doc->DM->DocTSHED->AsString=DM->DocTSHED->AsString;

				doc->DM->DocTKF_DOTCHPOSTT->AsFloat=1;
                doc->DM->DocTKOL_DOTCHPOSTT->AsFloat=DM->DocTKOLREAT->AsFloat;
				doc->DM->DocTPRICE_DOTCHPOSTT->AsFloat=DM->DocTPRICEREAT->AsFloat;
				doc->DM->DocT->Post();
				DM->DocT->Next();
				}




}
//---------------------------------------------------------------------------


