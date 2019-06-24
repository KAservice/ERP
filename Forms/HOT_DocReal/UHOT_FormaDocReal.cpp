//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UHOT_FormaDocReal.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocReal.h"
#include "IDMSprNom.h"
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
#pragma link "cxGroupBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLabel"
#pragma link "cxLookupEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THOT_FormaDocReal::THOT_FormaDocReal(TComponent* Owner)
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
bool THOT_FormaDocReal::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_DMDocReal.1",IID_IHOT_DMDocReal, (void**)&DM);
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
NameKKMcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
ZavNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
RegNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumberKLcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
NumCheckcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
SumDocDBText->DataSource=DM->DataSourceDocAll;
ActionOperation=aoNO;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THOT_FormaDocRealImpl),false);
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
int THOT_FormaDocReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THOT_FormaDocReal::UpdateForm(void)
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

void __fastcall THOT_FormaDocReal::FormClose(TObject *Sender,
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
int THOT_FormaDocReal::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_Nomenkl)
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

if (number_procedure_end==ER_DocCheck)
	{

	if (type_event==1)
		{
		EndCreateDocCheck();
		}
    FormaDocCheck=0;
	}



return -1;
}
//----------------------------------------------------------------------------




//выбор фирмы
void THOT_FormaDocReal::ViborFirm(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborFirm(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDFIRM_HOT_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
				DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
//выбор информационной базы
void THOT_FormaDocReal::ViborInfBase(void)
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
void __fastcall THOT_FormaDocReal::EndViborInfBase(void)
{

                DM->DocAll->Edit();
				DM->DocAllIDBASE_HOT_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();

		FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//-----------------------------------------------------------------------------
//выбор плательщика
void THOT_FormaDocReal::ViborPlat(void)
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
void __fastcall THOT_FormaDocReal::EndViborPlat(void)
{

				DM->DocAll->Edit();
				DM->DocAllIDKL_HOT_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

	   FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//------------------------------------------------------------------------------
//выбор гостя
void THOT_FormaDocReal::ViborGuest(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Guest;
		FormaSpiskaSprKlient->IdKlient=glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString);
		FormaSpiskaSprKlient->UpdateForm();
		}
cxGrid1->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborGuest(void)
{

				DM->DocT->Edit();
				DM->DocTIDGUEST_HOT_DREALT->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocTNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocT->Post();

	   FormaSpiskaSprKlient=0;

}
//----------------------------------------------------------------------------
//выбор номенклатуры
void THOT_FormaDocReal::ViborNom(void)
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
		FormaSpiskaSprNom->NumberProcVibor=ER_Nomenkl;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString);
		FormaSpiskaSprNom->UpdateForm();

		}


}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborNom(void)
{

				if (ActionOperation==aoAddNewString)
						{
						DM->AddDocNewString();
						}
				DM->DocT->Edit();
				DM->DocTIDNOM_HOT_DREALT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
				DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_HOT_DREALT->AsFloat=1;
				DM->DocTIDED_HOT_DREALT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_HOT_DREALT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;
				DM->DocTIDTPRICE_HOT_DREALT->AsString=DM_Connection->UserInfoIDTPRICE_USER->AsString;

				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocTIDTPRICE_HOT_DREALT->AsString),
											 glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
						DM->DocTPRICE_HOT_DREALT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_HOT_DREALT->AsFloat;
				DMSprPrice->kanRelease();
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//выбор единицы измерения
void THOT_FormaDocReal::ViborEd(void)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}   
}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborEd(void)
{

				DM->DocT->Edit();
				DM->DocTIDED_HOT_DREALT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_HOT_DREALT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement( glStrToInt64(DM->DocTIDTPRICE_HOT_DREALT->AsString),
											 glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
						DM->DocTPRICE_HOT_DREALT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_HOT_DREALT->AsFloat;
				DMSprPrice->kanRelease();

				DM->DocT->Post();

		cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSchet(void)
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

IDMSprNom *nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));

						OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DREALT->AsString,
													DM->DocTPOSCON_HOT_DREALT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													nom->ElementFNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DREALT->AsFloat,ffFixed,15,3),
													FloatToStrF(DM->DocTPRICE_HOT_DREALT->AsFloat,ffFixed,15,2),
													FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2));


		DM->DocT->Next();
		}

nom->kanRelease();
OutputPodavalReportSchet(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OutputZagolovokReportSchet(TSheetEditor *prForm)
{
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



cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Счет №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString+" от "
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

TRect rect;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+5;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

IDMSprFirm *DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
s=DMSprFirm->ElementFNAMEFIRM->AsString+
				", Адрес: "+DMSprFirm->ElementPADRFIRM->AsString+
				", ИНН "+DMSprFirm->ElementINNFIRM->AsString; 
cell->Text=s;
delete cell;

prForm->SetRowsHeightAuto(numRow, numCol, numCol+5,20,s);

numRow++;

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
s="Основание: "+DM->DocPRIM_HOT_DREAL->AsString;
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
void THOT_FormaDocReal::OutputPodavalReportSchet(TSheetEditor *prForm)
{
TcxSSCellObject *cell;



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
AnsiString s="Всего оказано услуг на сумму: "+glCurrencyPropis(DM->DocAllSUM_HOT_GALLDOC->AsFloat)+
			", в том числе НДС: Ноль рублей 00 копеек.";
cell->Text=s;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsItalic;
delete cell;
prForm->SetRowsHeightAuto(numRow, numCol, numCol+6,20,s);
numRow++;


numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+6;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
s="Вышеперечисленные услуги выполнены полностью и в срок. Заказчик претензий по объему, качеству и срокам оказания услуг не имеет.";
cell->Text=s;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
delete cell;
prForm->SetRowsHeightAuto(numRow, numCol, numCol+6,20,s);


numRow++;

rect.Left = 1;
rect.Top = numRow;
rect.Right = 3;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(1, numRow);
cell->Text="Администратор:  _________________________ "+DM_Connection->UserInfoFNAME_USER->AsString;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(4, numRow);
cell->Text="Заказчик:  _________________________ ";
delete cell;
numRow++;


numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+6;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);

cell = prForm->SS->ActiveSheet->GetCellObject(1, numRow);
cell->Text="ККМ "+DM->DocNAMEKKM_HOT_DREAL->AsString+
			" заводской №"+DM->DocZAVNUM_HOT_DREAL->AsString+
			", регистрационный №"+DM->DocREGNUM_HOT_DREAL->AsString;
delete cell;
numRow++;
numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+6;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(1, numRow);
cell->Text="Фискальный документ: контрольная лента №"+DM->DocNUMKL_HOT_DREAL->AsString+
			", чек №"+DM->DocNUMCHECK_HOT_DREAL->AsString;
delete cell;
numRow++;
numCol=1;
rect.Left = numCol;
rect.Top = numRow;
rect.Right = numCol+6;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Благодарим Вас за визит и будем рады видеть Вас еще!";
cell->Style->Font->Size = 14;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
}
//---------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ToolButtonPrintNaklClick(TObject *Sender)
{
OutputDopUslug=true;
OpenPrintFormSchet();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ToolButtonPrintAktClick(TObject *Sender)
{ 
OpenPrintFormSchetPoGuest();
}
//-----------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Hotel/Doc/DocReal");
}
//---------------------------------------------------------------------------











void __fastcall THOT_FormaDocReal::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborPlat();	
}
//---------------------------------------------------------------------------

bool THOT_FormaDocReal::CreateDocCheckKKM(void)
{
if (FormaDocCheck==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocCheck.1",IID_IFormaDocCheck,
													(void**)&FormaDocCheck);
	FormaDocCheck->Init(InterfaceMainObject,InterfaceImpl);
	FormaDocCheck->DM->NewDoc();
	FormaDocCheck->DM->DocAll->Edit();
	FormaDocCheck->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
	FormaDocCheck->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
	FormaDocCheck->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
	FormaDocCheck->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
	FormaDocCheck->DM->DocAll->Post();

	FormaDocCheck->DM->Doc->Edit();
	FormaDocCheck->DM->DocPRIMCHK->AsString="Осн.: Реализация (гост.) №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString
							   +" от  "+ DM->DocAllPOS_HOT_GALLDOC->AsString;
	FormaDocCheck->DM->Doc->Post();

	DM->DocT->First();
	while (!DM->DocT->Eof)
		{
		FormaDocCheck->DM->DocT->Append();
		FormaDocCheck->DM->DocTIDNOMCHKT->AsString=DM->DocTIDNOM_HOT_DREALT->AsString;
		FormaDocCheck->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
		FormaDocCheck->DM->DocTIDEDCHKT->AsString=DM->DocTIDED_HOT_DREALT->AsString;
		FormaDocCheck->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
		FormaDocCheck->DM->DocTKOLCHKT->AsFloat=DM->DocTKOL_HOT_DREALT->AsFloat;
		FormaDocCheck->DM->DocTKFCHKT->AsFloat=DM->DocTKF_HOT_DREALT->AsFloat;
		FormaDocCheck->DM->DocTPRICECHKT->AsFloat=DM->DocTPRICE_HOT_DREALT->AsFloat;
		FormaDocCheck->DM->DocT->Post();
		DM->DocT->Next();
		}
	//doc->Operation->ItemIndex=0;
	FormaDocCheck->UpdateForm();
	FormaDocCheck->NumberProcVibor=ER_DocCheck;

	}

return true;
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndCreateDocCheck(void)
{
DM->Doc->Edit();
DM->DocNAMEKKM_HOT_DREAL->AsString=FormaDocCheck->DM->DocMODELCHK->AsString;
DM->DocZAVNUM_HOT_DREAL->AsString=FormaDocCheck->DM->DocSAVNUMCHK->AsString;
DM->DocREGNUM_HOT_DREAL->AsString=FormaDocCheck->DM->DocREGNUMCHK->AsString;
DM->DocNUMKL_HOT_DREAL->AsString=FormaDocCheck->DM->DocNKLCHK->AsString;
DM->DocNUMCHECK_HOT_DREAL->AsString=FormaDocCheck->DM->DocNCHECKCHK->AsString;
DM->Doc->Post();
DM->SaveDoc();
FormaDocCheck=0;
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::cxButton1Click(TObject *Sender)
{
CreateDocCheckKKM();
}
//---------------------------------------------------------------------------
bool THOT_FormaDocReal::CreateDocRealRozn(void)
{
IFormaDocRealRozn * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocRealRozn.1",IID_IFormaDocRealRozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocPRIM_DREALROZN->AsString="Осн.: Реализация (гост.) №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString
							   +" от  "+ DM->DocAllPOS_HOT_GALLDOC->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while (!DM->DocT->Eof)
	{
	doc->DM->DocT->Append();
	doc->DM->DocTIDNOM_DREALROZNT->AsString=DM->DocTIDNOM_HOT_DREALT->AsString;
	doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
	doc->DM->DocTIDED_DREALROZNT->AsString=DM->DocTIDED_HOT_DREALT->AsString;
	doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
	doc->DM->DocTKOL_DREALROZNT->AsFloat=DM->DocTKOL_HOT_DREALT->AsFloat;
	doc->DM->DocTKF_DREALROZNT->AsFloat=DM->DocTKF_HOT_DREALT->AsFloat;
	doc->DM->DocTPRICE_DREALROZNT->AsFloat=DM->DocTPRICE_HOT_DREALT->AsFloat;
	doc->DM->DocT->Post();
	DM->DocT->Next();
	}
//doc->Operation->ItemIndex=0;
doc->UpdateForm();
return true;
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::cxButton2Click(TObject *Sender)
{
CreateDocRealRozn();
}
//---------------------------------------------------------------------------
bool THOT_FormaDocReal::CreateDocReal(void)
{
bool result=true;
IFormaDocReal * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaDocReal.1",IID_IFormaDocReal,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
doc->DM->NewDoc();
doc->DM->DocAll->Edit();
doc->DM->DocAllIDFIRMDOC->AsString=DM->DocAllIDFIRM_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
doc->DM->DocAllIDKLDOC->AsString=DM->DocAllIDKL_HOT_GALLDOC->AsString;
doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
doc->DM->DocAll->Post();

doc->DM->Doc->Edit();
doc->DM->DocPRIMREA->AsString="Осн.: Реализация (гост.) №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString
							   +" от  "+ DM->DocAllPOS_HOT_GALLDOC->AsString;
doc->DM->Doc->Post();

DM->DocT->First();
while (!DM->DocT->Eof)
	{
	doc->DM->DocT->Append();
	doc->DM->DocTIDNOMREAT->AsString=DM->DocTIDNOM_HOT_DREALT->AsString;
	doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
	doc->DM->DocTIDEDREAT->AsString=DM->DocTIDED_HOT_DREALT->AsString;
	doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;
	doc->DM->DocTKOLREAT->AsFloat=DM->DocTKOL_HOT_DREALT->AsFloat;
	doc->DM->DocTKFREAT->AsFloat=DM->DocTKF_HOT_DREALT->AsFloat;
	doc->DM->DocTPRICEREAT->AsFloat=DM->DocTPRICE_HOT_DREALT->AsFloat;
	doc->DM->DocT->Post();
	DM->DocT->Next();
	}
//doc->Operation->ItemIndex=0;
doc->UpdateForm();
return result;
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::cxButton3Click(TObject *Sender)
{
CreateDocReal();
}
//---------------------------------------------------------------------------
//выбор склада
void THOT_FormaDocReal::ViborSklad(void)
{ 
if (Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
	FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
	}
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLAD_HOT_GALLDOC->AsString=FormaSpiskaSprSklad->DM->TableIDSKLAD->AsString;
    DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->TableNAMESKLAD->AsString;
	DM->DocAll->Post();

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocReal::ViborCatNom(void)
{
if (HOT_FormaSpiskaSprCatNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.HOT_FormaSpSprCatNom.1",IID_IHOT_FormaSpiskaSprCatNom,
													(void**)&HOT_FormaSpiskaSprCatNom);
HOT_FormaSpiskaSprCatNom->Init(InterfaceMainObject,InterfaceImpl);
//настройка формы
HOT_FormaSpiskaSprCatNom->Vibor=true;
HOT_FormaSpiskaSprCatNom->NumberProcVibor=ER_Cat;


}
//--------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::EndViborCatNom(void)
{

	DM->DocT->Edit();
	DM->DocTIDCAT_HOT_DREALT->AsString=HOT_FormaSpiskaSprCatNom->DM->TableID_HOT_SCATNOM->AsString;
	DM->DocTNAME_HOT_SCATNOM->AsString=HOT_FormaSpiskaSprCatNom->DM->TableNAME_HOT_SCATNOM->AsString;
	DM->DocT->Post();

cxGrid1->SetFocus();
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
//выбор номера
void THOT_FormaDocReal::ViborNomer(void)
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
void __fastcall THOT_FormaDocReal::EndViborNomer(void)
{

				DM->DocT->Edit();
				DM->DocTIDNOMER_HOT_DREALT->AsString=HOT_FormaSpiskaSprNF->DM->TableID_HOT_SNF->AsString;
				DM->DocTNAME_HOT_SNF->AsString=HOT_FormaSpiskaSprNF->DM->TableNAME_HOT_SNF->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор типа поселения
void THOT_FormaDocReal::ViborTypePosel(void)
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
void __fastcall THOT_FormaDocReal::EndViborTypePosel(void)
{

				DM->DocT->Edit();
				DM->DocTIDTPOS_HOT_DREALT->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableID_HOT_STYPEPOS->AsString;
				DM->DocTNAME_HOT_STYPEPOS->AsString=HOT_FormaSpiskaSprTypePosel->DM->TableNAME_HOT_STYPEPOS->AsString;
				DM->DocT->Post();

	   cxGrid1->SetFocus();

}
//----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAME_HOT_SNFPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborNomer();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAME_HOT_SCATNOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborCatNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAMEKLIENTPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborGuest();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::cxGrid1DBBandedTableView1NAME_HOT_STYPEPOSPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborTypePosel();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSF(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokSF(PrintForm);

//таблица
SumNDS=0;
IDMSprNom *nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		AnsiString country="";
		AnsiString gtd="";
		IDMSprNom *DMSprNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
		DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
		DMSprNom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		if (DMSprNom->ElementNAME_SCOUNTRY->AsString=="")
			{
			country="----";
			}
		else
			{
			country=DMSprNom->ElementNAME_SCOUNTRY->AsString;
			}
		if (DMSprNom->ElementGTDNOM->AsString=="")
			{
			gtd="----";
			}
		else
			{
			gtd=DMSprNom->ElementGTDNOM->AsString;
			}
		DMSprNom->kanRelease();

		OutputStringSF(PrintForm,
										IntToStr(porNumStr),
										nom->ElementFNAMENOM->AsString,
										DM->DocTNAMEED->AsString,
										FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,12,3),
										FloatToStrF(DM->DocTPRICE_HOT_DREALT->AsFloat,ffFixed,15,2),
										FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2),
										"----",
										"Без НДС",
										"----",
										FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2),
										country,
										gtd) ;

        DM->DocT->Next();
        }
nom->kanRelease();
OutputPodavalSF(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OutputZagolovokSF(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
prForm->SS->DefaultRowHeight=16;
prForm->SS->ShowGrid=false;
//prForm->dxComponentPrinter1Link1->PrinterPage->Orientation=poLandscape;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 250;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 50;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
        cHeader->Size[8] = 40;
        cHeader->Size[9] = 55;
        cHeader->Size[10] = 50;
        cHeader->Size[11] = 80;
        cHeader->Size[12] = 100;
        cHeader->Size[13] = 100;

TcxSSCellObject *cell;
numRow=0;

numCol=13;
//prForm->dxComponentPrinter1->CurrentLink->PrinterPage->Orientation=poLandscape;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="Приложение №1";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="к правилам ведения журналов учета полученных и выставленных счетов-фактур,";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="книг покупок и книг продаж при расчетах по налогу на добавленную стоимость,";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="утвержденным постановлением Правительства Российской Федерации от 2 декабря 2000г. №914";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="(в редакции постановлений Правительства оссийской Федерации";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 6;
cell->Text="(от 15 марта 2001г. №189, от 27 июля 2002г. №575, от 16 февраля 2004г. №84, от 11 мая 2006г. №283)";
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Счет-фактура №"+DM->DocAllNUMBER_HOT_GALLDOC->AsString+" от "
				+DateToStr(DM->DocAllPOS_HOT_GALLDOC->AsDateTime);
delete cell;
numRow++;

IDMSprFirm *Firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&Firma);
Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Продавец: "+Firma->ElementFNAMEFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="ИНН/КПП продавца: "+Firma->ElementINNFIRM->AsString+"/"+
                                      Firma->ElementKPPFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Грузоотправитель и его адрес: "+Firma->ElementFNAMEFIRM->AsString+
                        " Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;
Firma->kanRelease();

IDMSprKlient * DMSprKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&DMSprKlient);
DMSprKlient->Init(InterfaceMainObject,InterfaceImpl);
DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Грузополучатель и его адрес: "+DMSprKlient->ElementFNAME->AsString
        +", Адрес:" +DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="К платежно-расчетному документу № ";
delete cell;
numRow++;

DMSprKlient->OpenElement(glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Покупатель: "+DMSprKlient->ElementFNAME->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="Адрес: "+DMSprKlient->ElementADRKLIENT->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text="ИНН/КПП покупателя: "+DMSprKlient->ElementINNKLIENT->AsString
        +"/"+DMSprKlient->ElementKPPKLIENT->AsString;
delete cell;
numRow++;
numRow++;

DMSprKlient->kanRelease();

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование товара (описание выполненных работ, оказанных услуг), имущественного права";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Единица измерения";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Коли- чество";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Цена (тариф) за единицу измерения";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Стоимость товаров (работ, услуг), имущественных прав, всего без налога";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="В том числе акциз";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Налоговая ставка";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Сумма налога";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Стоимость товаров (работ, услуг), имущественных прав, всего с учетом налога";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Страна происхождения";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Номер таможенной декларации";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

prForm->SS->ActiveSheet->Rows->Size[numRow]=130;

numRow++;

//номера столбцов
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="1";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="2";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="3";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="4";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="5";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="6";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="7";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="8";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="9";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="10";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="11";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;

}
//------------------------------------------------------------------------------
void THOT_FormaDocReal::OutputStringSF(TSheetEditor *prForm,
										AnsiString por_number,
										AnsiString name_nom,
										AnsiString name_ed,
										AnsiString kol,
										AnsiString price_bes_nds,
										AnsiString sum_bes_nds,
										AnsiString akciz,
										AnsiString stavka_nds,
										AnsiString sum_nds,
										AnsiString sum_all,
										AnsiString country,
										AnsiString gtd)
{
TcxSSCellObject *cell;

numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Text=por_number;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Text=name_nom;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Text=name_ed;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text=kol;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text=price_bes_nds;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text=sum_bes_nds;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Text=akciz;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
//if (DM->DocTSTNDS_DSCHFACTT->AsFloat==0)
//        {
		cell->Text=stavka_nds;
//        }
//else
//        {
		//cell->Text=DM->DocTSTNDS_DSCHFACTT->AsString;
//        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
//if (DM->DocTSUMNDS_DSCHFACTT->AsFloat==0)
//        {
		cell->Text=sum_nds;
//        }
//else
//        {
//        cell->Text=FloatToStrF(DM->DocTSTNDS_DSCHFACTT->AsFloat,ffFixed,10,2);
//        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text=sum_all;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

IDMSprNom *DMSprNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
DMSprNom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;

cell->Text=country;


cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 8;
cell->Text=gtd;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
porNumStr++;
}
//------------------------------------------------------------------------------
void THOT_FormaDocReal::OutputPodavalSF(TSheetEditor *prForm)
{
TcxSSCellObject *cell;

numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->Size = 8;
cell->Text="Всего к оплате:";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
if (SumNDS==0)
        {
        cell->Text="----";
        }
else
        {
        cell->Text=FloatToStrF(SumNDS,ffFixed,10,2);
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text=FloatToStrF(DM->DocAllSUM_HOT_GALLDOC->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numRow++;
numCol=3;

IDMSprFirm * DMSprFirm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenElement(glStrToInt64(DM->DocAllIDFIRM_HOT_GALLDOC->AsString));


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text="Руководитель организации";
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
cell->Style->Font->Size = 8;
if (DMSprFirm->ElementTYPEFIRM->AsInteger==0)
        {
        cell->Text=DMSprFirm->ElementDIRFIRM->AsString;
        }
numCol++;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numCol++;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text="Главный бухгалтер";
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
cell->Style->Font->Size = 8;
if (DMSprFirm->ElementTYPEFIRM->AsInteger==0)
        {
        cell->Text=DMSprFirm->ElementBUHFIRM->AsString;
        }
delete cell;
numCol++;


numRow++; numRow++;
numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Text="Индивидуальный предприниматель";
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
cell->Style->Font->Size = 8;
if (DMSprFirm->ElementTYPEFIRM->AsInteger==1)
        {
        cell->Text=DMSprFirm->ElementFNAMEFIRM->AsString;
        }
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol++;


numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
if (DMSprFirm->ElementTYPEFIRM->AsInteger==1)
        {
        cell->Text="№"+Trim(DMSprFirm->ElementNUMDOCREGFIRM->AsString)+
                " от "+Trim(DMSprFirm->ElementDATEDOCREGFIRM->AsString);
        }
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

numRow++;numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Примечание. Первый экземпляр - покупателю, второй - продавцу";
delete cell;
DMSprFirm->kanRelease();

}
//------------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::ToolButtonPrintSFClick(TObject *Sender)
{
OutputDopUslug=true;
OpenPrintFormSF();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ToolButtonPrintSFNoDopUslugClick(
      TObject *Sender)
{
OpenPrintFormSFPoGuest();
}
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSchetPoGuest(void)
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
IDMSprNom *nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);
DM->DocT->First();
while(!DM->DocT->Eof)
		{
		switch (DM->DocTTUSL_HOT_DREALT->AsInteger)
			{
			case  1  :   //основная услуга
				{
				double kol_osn_uslug=DM->GetKolOsnUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString));
				double sum_dop_uslug=DM->GetSumDopUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString));
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_dop_uslug/kol_osn_uslug) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}
				nom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DREALT->AsString,
													DM->DocTPOSCON_HOT_DREALT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													nom->ElementFNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DREALT->AsFloat,ffFixed,15,3),
													FloatToStrF(price,ffFixed,15,2),
													FloatToStrF(sum,ffFixed,15,2));

				}break;

			case  2  :   //бронирование
				{
				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DREALT->AsString,
													DM->DocTPOSCON_HOT_DREALT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													nom->ElementFNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DREALT->AsFloat,ffFixed,15,3),
													FloatToStrF(DM->DocTPRICE_HOT_DREALT->AsFloat,ffFixed,15,2),
													FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2));


				}break;


			default  :
				{ 
				}
           }


		DM->DocT->Next();
		}
nom->kanRelease();
OutputPodavalReportSchet(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();


}

//------------------------------------------------------------------------------
void THOT_FormaDocReal::OutputStringSchet(TSheetEditor *prForm,
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
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSFPoGuest(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokSF(PrintForm);

//таблица
SumNDS=0;
DM->GetSpisokGuest();
DM->DocT->First();
while(!DM->DocT->Eof)
		{
		AnsiString country="";
		AnsiString gtd="";
		IDMSprNom *DMSprNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMSprNom);
		DMSprNom->Init(InterfaceMainObject,InterfaceImpl);
		DMSprNom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		if (DMSprNom->ElementNAME_SCOUNTRY->AsString=="")
			{
			country="----";
			}
		else
			{
			country=DMSprNom->ElementNAME_SCOUNTRY->AsString;
			}
		if (DMSprNom->ElementGTDNOM->AsString=="")
			{
			gtd="----";
			}
		else
			{
			gtd=DMSprNom->ElementGTDNOM->AsString;
			}


		switch (DM->DocTTUSL_HOT_DREALT->AsInteger)
			{
			case  1  :   //основная услуга
				{
				double kol_osn_uslug=DM->GetKolOsnUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString));
				double sum_dop_uslug=DM->GetSumDopUslugGuest(glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString));
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_dop_uslug/kol_osn_uslug) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}
					
				OutputStringSF(PrintForm,
										IntToStr(porNumStr),
										DMSprNom->ElementFNAMENOM->AsString,
										DM->DocTNAMEED->AsString,
										FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,12,3),
										FloatToStrF(price,ffFixed,15,2),
										FloatToStrF(sum,ffFixed,15,2),
										"----",
										"Без НДС",
										"----",
										FloatToStrF(sum,ffFixed,15,2),
										country,
										gtd) ;

				}break;

			case  2  :   //бронирование
				{
				OutputStringSF(PrintForm,
										IntToStr(porNumStr),
										DMSprNom->ElementFNAMENOM->AsString,
										DM->DocTNAMEED->AsString,
										FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,12,3),
										FloatToStrF(DM->DocTPRICE_HOT_DREALT->AsFloat,ffFixed,15,2),
										FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2),
										"----",
										"Без НДС",
										"----",
										FloatToStrF(DM->DocTSUM_HOT_DREALT->AsFloat,ffFixed,15,2),
										country,
										gtd) ;

				}break;


			default  :
				{ 
				}
		   }
		DMSprNom->kanRelease();
        DM->DocT->Next();
        }

OutputPodavalSF(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSchetPoOneGuest(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReportSchet(PrintForm);

double kol_osn_uslug_guest=0;
double sum_uslug_dr_guest=0;
double kol_bron_usl_guest=0;
double sum_uslug_bron_dr_guest=0;

DM->DocT->First();
while(!DM->DocT->Eof)
		{
		if (glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString)==
					glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString))
			{
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==1)
				{
				kol_osn_uslug_guest=kol_osn_uslug_guest+
					DM->DocTKOL_HOT_DREALT->AsFloat*DM->DocTKF_HOT_DREALT->AsFloat;
				}
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)
				{
				kol_bron_usl_guest=kol_bron_usl_guest+
					DM->DocTKOL_HOT_DREALT->AsFloat*DM->DocTKF_HOT_DREALT->AsFloat;
				}

			if (DM->DocTTUSL_HOT_DREALT->AsInteger==3 || DM->DocTTUSL_HOT_DREALT->AsInteger==4)
					{
					sum_uslug_dr_guest=sum_uslug_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}



			}
		else
			{
				if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)
					{
					sum_uslug_bron_dr_guest=sum_uslug_bron_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}
				else
					{
					sum_uslug_dr_guest=sum_uslug_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}
			}

			
		DM->DocT->Next();
		}

//таблица
IDMSprNom *nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);
DM->DocT->First();
while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		if (glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString)==
						glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString))
			{
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==1)      //проживание
				{
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_uslug_dr_guest/kol_osn_uslug_guest) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}

				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DREALT->AsString,
													DM->DocTPOSCON_HOT_DREALT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													nom->ElementFNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DREALT->AsFloat,ffFixed,15,3),
													FloatToStrF(price,ffFixed,15,2),
													FloatToStrF(sum,ffFixed,15,2));

				}

			if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)  //бронирование
				{
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_uslug_bron_dr_guest/kol_bron_usl_guest) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}

				OutputStringSchet(PrintForm,
													IntToStr(porNumStr),
													DM->DocTPOSNACH_HOT_DREALT->AsString,
													DM->DocTPOSCON_HOT_DREALT->AsString,
													DM->DocTNAME_TPRICE->AsString,
													DM->DocTNAME_HOT_SNF->AsString,
													DM->DocTNAMEKLIENT->AsString,
													nom->ElementFNAMENOM->AsString,
													FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,15,3),
													DM->DocTNAMEED->AsString,
													FloatToStrF(DM->DocTKF_HOT_DREALT->AsFloat,ffFixed,15,3),
													FloatToStrF(price,ffFixed,15,2),
													FloatToStrF(sum,ffFixed,15,2));

				}  

		  	}

		DM->DocT->Next();
		}
nom->kanRelease();
OutputPodavalReportSchet(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();



}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::ToolButtonPrintOneGuestClick(TObject *Sender)
{
OpenPrintFormSchetPoOneGuest();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void THOT_FormaDocReal::OpenPrintFormSFPoOneGuest(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokSF(PrintForm);

double kol_osn_uslug_guest=0;
double sum_uslug_dr_guest=0;
double kol_bron_usl_guest=0;
double sum_uslug_bron_dr_guest=0;


DM->DocT->First();
while(!DM->DocT->Eof)
		{
		if (glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString)==
					glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString))
			{
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==1)
				{
				kol_osn_uslug_guest=kol_osn_uslug_guest+
					DM->DocTKOL_HOT_DREALT->AsFloat*DM->DocTKF_HOT_DREALT->AsFloat;
				}
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)
				{
				kol_bron_usl_guest=kol_bron_usl_guest+
					DM->DocTKOL_HOT_DREALT->AsFloat*DM->DocTKF_HOT_DREALT->AsFloat;
				}

			if (DM->DocTTUSL_HOT_DREALT->AsInteger==3 || DM->DocTTUSL_HOT_DREALT->AsInteger==4)
					{
					sum_uslug_dr_guest=sum_uslug_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}



			}
		else
			{
				if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)
					{
					sum_uslug_bron_dr_guest=sum_uslug_bron_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}
				else
					{
					sum_uslug_dr_guest=sum_uslug_dr_guest+
					DM->DocTSUM_HOT_DREALT->AsFloat;
					}
			}

			
		DM->DocT->Next();
		}

//таблица
IDMSprNom *nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
nom->Init(InterfaceMainObject,InterfaceImpl);
DM->DocT->First();
while(!DM->DocT->Eof)
		{
		nom->OpenElement(glStrToInt64(DM->DocTIDNOM_HOT_DREALT->AsString));
		if (glStrToInt64(DM->DocTIDGUEST_HOT_DREALT->AsString)==
						glStrToInt64(DM->DocAllIDKL_HOT_GALLDOC->AsString))
			{
			if (DM->DocTTUSL_HOT_DREALT->AsInteger==1)      //проживание
				{
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_uslug_dr_guest/kol_osn_uslug_guest) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}


				OutputStringSF(PrintForm,
										IntToStr(porNumStr),
										nom->ElementFNAMENOM->AsString,
										DM->DocTNAMEED->AsString,
										FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,12,3),
										FloatToStrF(price,ffFixed,15,2),
										FloatToStrF(sum,ffFixed,15,2),
										"----",
										"Без НДС",
										"----",
										FloatToStrF(sum,ffFixed,15,2),
										"----",
										"----") ;



				}

			if (DM->DocTTUSL_HOT_DREALT->AsInteger==2)  //бронирование
				{
				double price=0;
				double sum=0;

				sum=DM->DocTSUM_HOT_DREALT->AsFloat+
						(sum_uslug_bron_dr_guest/kol_bron_usl_guest) * DM->DocTKOL_HOT_DREALT->AsFloat
													  * DM->DocTKF_HOT_DREALT->AsFloat;

				if (DM->DocTKOL_HOT_DREALT->AsFloat!=0)
					{
					price=sum/DM->DocTKOL_HOT_DREALT->AsFloat;
					}

				OutputStringSF(PrintForm,
										IntToStr(porNumStr),
										nom->ElementFNAMENOM->AsString,
										DM->DocTNAMEED->AsString,
										FloatToStrF(DM->DocTKOL_HOT_DREALT->AsFloat,ffFixed,12,3),
										FloatToStrF(price,ffFixed,15,2),
										FloatToStrF(sum,ffFixed,15,2),
										"----",
										"Без НДС",
										"----",
										FloatToStrF(sum,ffFixed,15,2),
										"----",
										"----") ;

				}  

		  	}

		DM->DocT->Next();
		}
nom->kanRelease();
OutputPodavalSF(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();



}
//-----------------------------------------------------------------------------
void __fastcall THOT_FormaDocReal::ToolButtonPrintSFOneGuestClick(
      TObject *Sender)
{
OpenPrintFormSFPoOneGuest();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::NumberDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::NameKKMcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ZavNumbercxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::RegNumbercxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::NumberKLcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::NumCheckcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ActionAddStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
ActionOperation=aoAddNewString;
ViborNom();	
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ActionDeleteStringExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (NoEdit==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THOT_FormaDocReal::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THOT_FormaDocReal::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall THOT_FormaDocReal::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall THOT_FormaDocReal::ActionOKExecute(TObject *Sender)
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

void __fastcall THOT_FormaDocReal::ActionDvRegExecute(TObject *Sender)
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

void __fastcall THOT_FormaDocReal::ActionSaveExecute(TObject *Sender)
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

