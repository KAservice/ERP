//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaDocRaschet.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"
#include "IDMSprUser.h"
#include "IFormaDocCheck.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocReal.h"
#include "IDMSprBankSchet.h"
#include "IDMSprBank.h"
#include "IHOT_FormaDocReal.h"
#include "IFormaRunExternalModule.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBLookupComboBox"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLabel"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaDocRaschet::THOT_FormaDocRaschet(TComponent* Owner)
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
bool THOT_FormaDocRaschet::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocRaschet.1",IID_IHOT_DMDocRaschet, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumberDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;

cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
SumDocDBText->DataSource=DM->DataSourceDocAll;
ActionOperation=aoNO;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THOT_FormaDocRaschetImpl),false);
DMTableExtPrintForm->Table->First();
while (!DMTableExtPrintForm->Table->Eof)
		{
		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
		menu->OnClick = PopupMenuExtModuleClick;
		PopupMenuExtModule->Items->Add(menu);
		DMTableExtPrintForm->Table->Next();
		}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypePrice->DataSourceTable;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//--------------------------------------------------------------------------
int THOT_FormaDocRaschet::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::UpdateForm(void)
{
Prosmotr=DM->Prosmotr;
NoEdit=DM->NoEdit;
if (Prosmotr==true)
        {
		ProsmotrLabel->Visible=true;
		cxGrid1DBBandedTableView1->OptionsData->Editing=false;
		}
else
        {
        ProsmotrLabel->Visible=false;
		cxGrid1DBBandedTableView1->OptionsData->Editing=true;
        }

if (NoEdit==true)
        {
        //ProsmotrLabel->Visible=true;
		cxGrid1DBBandedTableView1->OptionsData->Editing=false;
        }
else
        {
        //ProsmotrLabel->Visible=false;
		cxGrid1DBBandedTableView1->OptionsData->Editing=true;
        }

}
//-----------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();

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
int THOT_FormaDocRaschet::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Firm)
	{

	if (type_event==1)
		{
		EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_InfBase)
	{
	if (type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
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


if (number_procedure_end==ER_Plat)
	{
	if (type_event==1)
		{
		EndViborPlat();
		}
	FormaSpiskaSprKlient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}


if (number_procedure_end==ER_Guest)
	{
	if (type_event==1)
		{
		EndViborGuest();
		}
	FormaSpiskaSprKlient=0;
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


if (number_procedure_end==ER_Nomer)
	{

	if (type_event==1)
		{
		EndViborNomer();
		}
	HOT_FormaSpiskaSprNF=0;
	}



if (number_procedure_end==ER_Cat)
	{

	if (type_event==1)
		{
		EndViborCatNom();
		}
	HOT_FormaSpiskaSprCatNom=0;
	}

if (number_procedure_end==ER_TypePos)
	{

	if (type_event==1)
		{
		EndViborTypePosel();
		}
	HOT_FormaSpiskaSprTypePosel=0;
	}

if (number_procedure_end==ER_BankSchet)
	{

	if (type_event==1)
		{
		EndViborBSchet();
		}
    FormaSpiskaSprBSchet=0;
	}



return -1;
}
//----------------------------------------------------------------------------



//выбор фирмы
void THOT_FormaDocRaschet::ViborFirm(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborFirm(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDFIRM_HOT_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
//выбор информационной базы
void THOT_FormaDocRaschet::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_HOT_GALLDOC->ReadOnly==true) return;
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
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborInfBase(void)
{

                DM->DocAll->Edit();
				DM->DocAllIDBASE_HOT_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//-----------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaDocRaschet::ViborPlat(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Plat;
		FormaSpiskaSprKlient->IdKlient=DM->DocAllIDKL_HOT_GALLDOC->AsInteger;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborPlat(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDKL_HOT_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

	   FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//------------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocRaschet::ViborGuest(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Guest;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocTIDGUEST_HOT_DRASCHETT->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborGuest(void)
{

				DM->DocT->Edit();
				DM->DocTIDGUEST_HOT_DRASCHETT->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocTNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocT->Post();

cxGrid1->SetFocus();

}
//----------------------------------------------------------------------------
//выбор номенклатуры
void THOT_FormaDocRaschet::ViborNom(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=DM->DocTIDTPRICEREA->AsInteger;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_HOT_DRASCHETT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborNom(void)
{

				if (ActionOperation==aoAddNewString)
						{
						DM->AddString();
						}
				DM->DocT->Edit();
				DM->DocTIDNOM_HOT_DRASCHETT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_HOT_DRASCHETT->AsFloat=1;
				DM->DocTIDED_HOT_DRASCHETT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_HOT_DRASCHETT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;
				DM->DocTIDTPRICE_HOT_DRASCHETT->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocTIDTPRICE_HOT_DRASCHETT->AsString),
											 glStrToInt64(DM->DocTIDNOM_HOT_DRASCHETT->AsString));
						DM->DocTPRICE_HOT_DRASCHETT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_HOT_DRASCHETT->AsFloat;
				DMSprPrice->kanRelease();
				DM->DocT->Post();

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//выбор единицы измерения
void THOT_FormaDocRaschet::ViborEd(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprEd) return;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_HOT_DRASCHETT->AsString));
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}   
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborEd(void)
{

				DM->DocT->Edit();
				DM->DocTIDED_HOT_DRASCHETT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_HOT_DRASCHETT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocTIDTPOS_HOT_DRASCHETT->AsString),
											 glStrToInt64(DM->DocTIDNOM_HOT_DRASCHETT->AsString));
						DM->DocTPRICE_HOT_DRASCHETT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_HOT_DRASCHETT->AsFloat;
				DMSprPrice->kanRelease();

				DM->DocT->Post();

		cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::OpenPrintFormSchet(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportSchet(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
		{

						OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DRASCHETT->AsString,
													DM->DocTPOSCON_HOT_DRASCHETT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													DM->DocTNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													FloatToStrF(DM->DocTPRICE_HOT_DRASCHETT->AsFloat,ffFixed,15,2),
													FloatToStrF(DM->DocTSUM_HOT_DRASCHETT->AsFloat,ffFixed,15,2));


		DM->DocT->Next();
		}

OutputPodavalReportSchet(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::OutputZagolovokReportSchet(TSheetEditor *prForm)
{
TRect rect;
IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));

IDMSprBankSchet * DMSprBSchet;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBankSchet.1",IID_IDMSprBankSchet,
													(void**)&DMSprBSchet);
DMSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
DMSprBSchet->OpenElement(glStrToInt64(DM->DocIDBSCHET_HOT_DRASCHET->AsString));

IDMSprBank * DMSprBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBank.1",IID_IDMSprBank,
													(void**)&DMSprBank);
DMSprBank->Init(InterfaceMainObject,InterfaceImpl);
DMSprBank->OpenElement(glStrToInt64(DMSprBSchet->ElementIDBANK->AsString));

numRow=0;
numCol=1;
TcxSSCellObject *cell;
AnsiString s;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
//prForm->SS->AutoRecalc=true;
        TcxSSHeader *cHeader;

		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 10;
		cHeader->Size[1] = 90;
		cHeader->Size[2] = 280;
		cHeader->Size[3] = 60;
		cHeader->Size[4] = 70;
		cHeader->Size[5] = 50;
		cHeader->Size[6] = 60;
		cHeader->Size[7] = 80;


//заголовок таблицы
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Образец заполнения платежного поручения: ";
delete cell;

numRow++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="ИНН  "+DMSprFirm->ElementINNFIRM->AsString+
			"КПП  "+DMSprFirm->ElementKPPFIRM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сч. №  ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+3;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprBSchet->ElementNUMBSCHET->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
s=DMSprFirm->ElementFNAMEFIRM->AsString;
cell->Text=s;
cell->Style->VertTextAlign = vaTOP;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
prForm->SetRowsHeightAuto(numRow, numCol, numCol+1,20,s);
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol=numCol+4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;


numRow++;
numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Получатель";
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numRow++;

numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
s=DMSprBank->ElementNAMEBANK->AsString;
cell->Text=s;
cell->Style->VertTextAlign = vaTOP;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
delete cell;
prForm->SetRowsHeightAuto(numRow, numCol, numCol+1,20,s);
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="БИК";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+3;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprBank->ElementBIKBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
delete cell;
numCol=numCol+3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;

numRow++;

numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Банк получателя";
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Сч. №";
delete cell;
numCol++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+3;
rect.Bottom = numRow;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DMSprBank->ElementKSBANK->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


numRow++;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Счет на оплату №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString+" от "
				+DateToStr(DM->DocAllPOS_HOT_GALLDOC->AsDateTime);

cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

numRow++;


numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Исполнитель: ";
delete cell;
numCol++;


rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+5;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
s=DMSprFirm->ElementFNAMEFIRM->AsString+
				", Адрес: "+DMSprFirm->ElementPADRFIRM->AsString+
				", ИНН "+DMSprFirm->ElementINNFIRM->AsString; 
cell->Text=s;
delete cell;

prForm->SetRowsHeightAuto(numRow, numCol, numCol+5,20,s);

numRow++;

DMSprBSchet->kanRelease();
DMSprBank->kanRelease();
DMSprFirm->kanRelease();


numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Заказчик: ";
delete cell;
numCol++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+5;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
s=DMSprKlient->ElementFNAME->AsString
						+", ИНН "+DMSprKlient->ElementINNKLIENT->AsString+
						" Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
cell->Text=s;
cell->Style->WordBreak = true;
delete cell;

prForm->SetRowsHeightAuto(numRow, numCol, numCol+5,20,s);

numRow++;

DMSprKlient->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(1, numRow);
s="Основание: "+DM->DocPRIM_HOT_DRASCHET->AsString;
cell->Text=s;
delete cell;
prForm->SetRowsHeightAuto(numRow, numCol, numCol+5,20,s);
numRow++;


//заголовок таблицы
numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol;
rect.Bottom = numRow+1;

prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Период";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Номер";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+2;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Гость";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
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
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
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
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
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
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
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
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
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
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма";
cell->Style->Font->Size = 10;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsMedium;
delete cell;
numCol++;

numRow++;




}
//------------------------------------------------------------------------------
void THOT_FormaDocRaschet::OutputStringSchet(TSheetEditor *prForm,
													AnsiString por_number,
													AnsiString pos_nach,
													AnsiString pos_con,
													AnsiString tarif,
													AnsiString nomer,
													AnsiString guest,
													AnsiString name_nom,
													AnsiString kol,
													AnsiString name_ed,
													AnsiString kf_ed,
													AnsiString price,
													AnsiString summa)
{
TcxSSCellObject *cell;

numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol;
rect.Bottom = numRow+1;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=por_number;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="С "+pos_nach+
			" по "+pos_con+
			" Тариф: "+tarif;
cell->Style->Font->Style = TFontStyles() << fsItalic;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+1;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=nomer;
cell->Style->Font->Style = TFontStyles() << fsItalic;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+2;
rect.Bottom = numRow;

prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=guest;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsItalic;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

cell->Style->HorzTextAlign = haRIGHT;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

cell->Style->Borders->Edges [eLeft]->Style=lsMedium;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=name_nom;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=kol;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=name_ed;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=kf_ed;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=price;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=summa;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsMedium;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++; porNumStr++;
}


//------------------------------------------------------------------------------
void THOT_FormaDocRaschet::OutputPodavalReportSchet(TSheetEditor *prForm)
{
TcxSSCellObject *cell;


//дополнительные услуги
if (OutputDopUslug==false)
	{
		if (KolStrokDopUslug>0)
			{    //исправляем сумму основной услуги
			cell = prForm->SS->ActiveSheet->GetCellObject(7, NumStrOsnUslugi);
			cell->Text=FloatToStr(SummaOsnUslug);
			delete cell;

			cell = prForm->SS->ActiveSheet->GetCellObject(6, NumStrOsnUslugi);
			if (KolOsnUslug==0)
				{
				cell->Text="";
				}
			else
				{
				cell->Text=FloatToStrF(SummaOsnUslug/KolOsnUslug,ffFixed,14,2);
				}
			delete cell;
			}
	 } 





numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Text="Итого:";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;

delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text=FloatToStrF(DM->DocAllSUM_HOT_GALLDOC->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eTop]->Style=lsMedium;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(6, numRow);
cell->Text="В том числе НДС:";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;

delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
delete cell;


numRow++;

TRect rect;

numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+6;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
AnsiString s="Всего стоимость услуг: "+glCurrencyPropis(DM->DocAllSUM_HOT_GALLDOC->AsFloat)+
			", в том числе НДС: Ноль рублей 00 копеек.";
cell->Text=s;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsItalic;
delete cell;

prForm->SetRowsHeightAuto(numRow, numCol, numCol+5,20,s);
numRow++;



cell = prForm->SS->ActiveSheet->GetCellObject(1, numRow);
cell->Text="Администратор:  _________________________ "+DM_Connection->UserInfoFNAME_USER->AsString;
delete cell;

}
//---------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::ToolButtonPrintNaklClick(TObject *Sender)
{
OutputDopUslug=true;
OpenPrintFormSchet();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::OpenPrintFormAkt(void)
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
void THOT_FormaDocRaschet::OutputZagolovokReportAkt(TSheetEditor *prForm)
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
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));
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
cell->Text="Акт на выполненные работы №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString+" от "
				+DateToStr(DM->DocAllPOS_HOT_GALLDOC->AsDateTime);
delete cell;
numRow++; numRow++;

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString));
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
cell->Text="Основание: "+DM->DocPRIM_HOT_DRASCHET->AsString;
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
void THOT_FormaDocRaschet::OutputZagolovokReportAktKompl(TSheetEditor *prForm)
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
void THOT_FormaDocRaschet::OutputStringAkt(TSheetEditor *prForm)
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
cell->Text=DM->DocTKOL_HOT_DRASCHETT->AsString;
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
cell->Text=FloatToStrF(DM->DocTKF_HOT_DRASCHETT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTPRICE_HOT_DRASCHETT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTSUM_HOT_DRASCHETT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

}


//------------------------------------------------------------------------------
void THOT_FormaDocRaschet::OutputPodavalReportAkt(TSheetEditor *prForm)
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
cell->Text=FloatToStrF(DM->DocAllSUM_HOT_GALLDOC->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="ВСЕГО : "+glCurrencyPropis(DM->DocAllSUM_HOT_GALLDOC->AsFloat);
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
void __fastcall THOT_FormaDocRaschet::ToolButtonPrintAktClick(TObject *Sender)
{
OpenPrintFormSchetPoGuest();
}
//-----------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Doc/DocRaschet");
}
//---------------------------------------------------------------------------











void __fastcall THOT_FormaDocRaschet::NameKlientcxDBButtonEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
ViborPlat();
}
//---------------------------------------------------------------------------
//выбор склада
void THOT_FormaDocRaschet::ViborSklad(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
	FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprSklad) return;
	//настройка формы
	FormaSpiskaSprSklad->Vibor=true;
	FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
	}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLAD_HOT_GALLDOC->AsString=FormaSpiskaSprSklad->DM->TableIDSKLAD->AsString;
    DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->TableNAMESKLAD->AsString;
	DM->DocAll->Post();

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
if (!HOT_FormaSpiskaSprCatNom) return;
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;

}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborCatNom(void)
{

	DM->DocT->Edit();
	DM->DocTIDCAT_HOT_DRASCHETT->AsString=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsString;
	DM->DocTNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
//выбор номера
void THOT_FormaDocRaschet::ViborNomer(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprNF==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprNF.1",IID_IHOT_FormaSpiskaSprNF,
													(void**)&HOT_FormaSpiskaSprNF);
		HOT_FormaSpiskaSprNF->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprNF) return;
		HOT_FormaSpiskaSprNF->Vibor=true;
		HOT_FormaSpiskaSprNF->NumberProcVibor=ER_Nomer;
		}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborNomer(void)
{

				DM->DocT->Edit();
				DM->DocTIDNOMER_HOT_DRASCHETT->AsString=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsString;
				DM->DocTNAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор типа поселения
void THOT_FormaDocRaschet::ViborTypePosel(void)
{
if (Prosmotr==true) return;
if (HOT_FormaSpiskaSprTypePosel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprTypePosel.1",IID_IHOT_FormaSpiskaSprTypePosel,
													(void**)&HOT_FormaSpiskaSprTypePosel);
		HOT_FormaSpiskaSprTypePosel->Init(InterfaceMainObject,InterfaceImpl);
		if (!HOT_FormaSpiskaSprTypePosel) return;
		HOT_FormaSpiskaSprTypePosel->Vibor=true;
		HOT_FormaSpiskaSprTypePosel->NumberProcVibor=ER_TypePos;
		}
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborTypePosel(void)
{

				DM->DocT->Edit();
				DM->DocTIDTPOS_HOT_DRASCHETT->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsString;
				DM->DocTNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAME_HOT_SNFPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomer();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAMEKLIENTPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGuest();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::cxGrid1DBBandedTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePosel();
}
//---------------------------------------------------------------------------
//выбор банковского счета
void THOT_FormaDocRaschet::ViborBSchet(void)
{
if (FormaSpiskaSprBSchet==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&FormaSpiskaSprBSchet);
	FormaSpiskaSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprBSchet->IdFirm=glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString);
	FormaSpiskaSprBSchet->DM->IdFirm=glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString);
	FormaSpiskaSprBSchet->DM->OpenTable();
	//FormaSpiskaSprBSchet->LabelFirma->Caption="Фирма: "+DM->DocAllNAMEFIRM->AsString;
	FormaSpiskaSprBSchet->Vibor=true;
	FormaSpiskaSprBSchet->NumberProcVibor=ER_BankSchet;
	}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::EndViborBSchet(void)
{

	DM->Doc->Edit();
	DM->DocIDBSCHET_HOT_DRASCHET->AsString=FormaSpiskaSprBSchet->DM->TableIDBSCHET->AsString;
	DM->DocNAMEBSCHET->AsString=FormaSpiskaSprBSchet->DM->TableNAMEBSCHET->AsString;
	DM->Doc->Post();

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::NameBSchetcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborBSchet();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::CreateDocRealNaOsnRaschet(void)
{
IHOT_FormaDocReal *forma_doc;
InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaDocReal.1",IID_IHOT_FormaDocReal,
													(void**)&forma_doc);
forma_doc->Init(InterfaceMainObject,InterfaceImpl);
forma_doc->DM->NewDoc();
forma_doc->DM->DocAll->Edit();
forma_doc->DM->DocAllIDFIRM_HOT_GALLDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
forma_doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
forma_doc->DM->DocAllIDKL_HOT_GALLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
forma_doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
forma_doc->DM->DocAllIDSKLAD_HOT_GALLDOC->AsString=DM->DocAllIDSKLAD_HOT_GALLDOC->AsString;
forma_doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
forma_doc->DM->DocAllIDDOCOSN_HOT_GALLDOC->AsString=DM->DocAllID_HOT_GALLDOC->AsString;
forma_doc->DM->DocAll->Post();

forma_doc->DM->Doc->Edit();
forma_doc->DM->DocPRIM_HOT_DREAL->AsString="На основании Расчета №"+
							DM->DocAllNUMBER_HOT_GALLDOC->AsString +" от "+
							DM->DocAllPOS_HOT_GALLDOC->AsString;
forma_doc->DM->DocIDTPRICE_HOT_DREAL->AsString=DM->DocIDTPRICE_HOT_DRASCHET->AsString;
forma_doc->DM->Doc->Post();

DM->DocT->First();
while(!DM->DocT->Eof)
	{
	forma_doc->DM->AddDocNewString();
	forma_doc->DM->DocT->Edit();
	forma_doc->DM->DocTIDNOMER_HOT_DREALT->AsString=DM->DocTIDNOMER_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAME_HOT_SNF->AsString=DM->DocTNAME_HOT_SNF->AsString;
	forma_doc->DM->DocTIDCAT_HOT_DREALT->AsString=DM->DocTIDCAT_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAME_HOT_SCATNOM->AsString=DM->DocTNAME_HOT_SCATNOM->AsString;
	forma_doc->DM->DocTIDGUEST_HOT_DREALT->AsString=DM->DocTIDGUEST_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAMEKLIENT->AsString=DM->DocTNAMEKLIENT->AsString;
	forma_doc->DM->DocTIDTPOS_HOT_DREALT->AsString=DM->DocTIDTPOS_HOT_DRASCHETT->AsString;
    forma_doc->DM->DocTNAME_HOT_STYPEPOS->AsString=DM->DocTNAME_HOT_STYPEPOS->AsString;
	forma_doc->DM->DocTTUSL_HOT_DREALT->AsInteger=DM->DocTTUSL_HOT_DRASCHETT->AsInteger;
	forma_doc->DM->DocTIDNOM_HOT_DREALT->AsString=DM->DocTIDNOM_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
	forma_doc->DM->DocTIDED_HOT_DREALT->AsString=DM->DocTIDED_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
	forma_doc->DM->DocTIDTPRICE_HOT_DREALT->AsString=DM->DocTIDTPRICE_HOT_DRASCHETT->AsString;
	forma_doc->DM->DocTNAME_TPRICE->AsString=DM->DocTNAME_TPRICE->AsString;
	forma_doc->DM->DocTPRICE_HOT_DREALT->AsFloat=DM->DocTPRICE_HOT_DRASCHETT->AsFloat;
	forma_doc->DM->DocTKOL_HOT_DREALT->AsFloat=DM->DocTKOL_HOT_DRASCHETT->AsFloat;
	forma_doc->DM->DocTKF_HOT_DREALT->AsFloat=DM->DocTKF_HOT_DRASCHETT->AsFloat;
	forma_doc->DM->DocTSUM_HOT_DREALT->AsFloat=DM->DocTSUM_HOT_DRASCHETT->AsFloat;
	forma_doc->DM->DocTPOSNACH_HOT_DREALT->AsDateTime=DM->DocTPOSNACH_HOT_DRASCHETT->AsDateTime;
    forma_doc->DM->DocTPOSCON_HOT_DREALT->AsDateTime=DM->DocTPOSCON_HOT_DRASCHETT->AsDateTime;


	forma_doc->DM->DocT->Post(); 
	DM->DocT->Next();
	}
forma_doc->UpdateForm();
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::cxButtonCreateDocRealClick(
      TObject *Sender)
{
CreateDocRealNaOsnRaschet();
}
//---------------------------------------------------------------------------
void THOT_FormaDocRaschet::OpenPrintFormSchetPoGuest(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportSchet(PrintForm);


DM->GetSpisokGuest();


//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		switch (DM->DocTTUSL_HOT_DRASCHETT->AsInteger)
			{
			case  1  :   //основная услуга
				{
				double kol_osn_uslug=DM->GetKolOsnUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DRASCHETT->AsString));
				double sum_dop_uslug=DM->GetSumDopUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DRASCHETT->AsString));
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DRASCHETT->AsFloat+
						(sum_dop_uslug/kol_osn_uslug) * DM->DocTKOL_HOT_DRASCHETT->AsFloat
													  * DM->DocTKF_HOT_DRASCHETT->AsFloat;

				if (DM->DocTKOL_HOT_DRASCHETT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DRASCHETT->AsFloat;
					}
					
				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DRASCHETT->AsString,
													DM->DocTPOSCON_HOT_DRASCHETT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													DM->DocTNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													FloatToStrF(price,ffFixed,15,2),
													FloatToStrF(sum,ffFixed,15,2));

				}break;

			case  2  :   //бронирование
				{
				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DRASCHETT->AsString,
													DM->DocTPOSCON_HOT_DRASCHETT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													DM->DocTNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DRASCHETT->AsFloat,ffFixed,15,3),
													FloatToStrF(DM->DocTPRICE_HOT_DRASCHETT->AsFloat,ffFixed,15,2),
													FloatToStrF(DM->DocTSUM_HOT_DRASCHETT->AsFloat,ffFixed,15,2));


				}break;


			default  :
				{ 
				}
           }


		DM->DocT->Next();
		}

OutputPodavalReportSchet(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();


}
//-------------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
ActionOperation=aoAddNewString;
ViborNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
DM->DeleteString();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::NumberDoccxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::PrimcxDBTextEditKeyDown(TObject *Sender,
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
void __fastcall THOT_FormaDocRaschet::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THOT_FormaDocRaschet::RunExternalModule(__int64 id_module, int type_module)
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

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
    module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_HOT_GALLDOC->AsString));
	}
	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocRaschet::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::ActionOKExecute(TObject *Sender)
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

void __fastcall THOT_FormaDocRaschet::ActionDvRegExecute(TObject *Sender)
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
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::NameFirmcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborFirm();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocRaschet::NameInfBasecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborInfBase();
}
//---------------------------------------------------------------------------

