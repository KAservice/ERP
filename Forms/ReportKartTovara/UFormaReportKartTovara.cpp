//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportKartTovara.h"
#include "IDMSprPrice.h"
#include "IDMSprEd.h"
#include "IDMRegOstNom.h"
#include "IDMSprUser.h"
#include "IDMRegGoods.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaReportKartTovara::TFormaReportKartTovara(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportKartTovara::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportKartTovara::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;
Dv->Database=DM_Connection->pFIBData;
DvRegGoods->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmcxButtonEdit->Text="";
NameSkladEdit->Text="";
NameNomEdit->Text="";

IdNom=0;
NameBasEdLabel->Caption="";

if(DM_Connection->UserInfoIDFIRM_USER->AsInt64!=0)
	{
	IdFirm=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
	NameFirmcxButtonEdit->Text=DM_Connection->UserInfoNAMEFIRM->AsString;
	}

if(DM_Connection->UserInfoIDSKLAD_USER->AsInt64!=0)
	{
	IdSklad=DM_Connection->UserInfoIDSKLAD_USER->AsInt64;
	NameSkladEdit->Text=DM_Connection->UserInfoNAMESKLAD->AsString;
	}


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportKartTovaraImpl),false);
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
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int  TFormaReportKartTovara::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportKartTovara::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad)SpisokSklad->kanRelease();
if(Nom)Nom->kanRelease();

Dv->Active=false;


Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TFormaReportKartTovara::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborSklad)
		{
		if (type_event==1)
				{
				IdSklad=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
				NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
				if (SpisokSklad->DM->ElementTSKLAD->AsInteger==1)
					{
                    RoznSklad=true;
					}
				else
					{
					RoznSklad=false;
					}
                }
        SpisokSklad=0;
        }

if (number_procedure_end==ViborNom)
        {
		if (type_event==1)
				{
				IdNom=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
                NameNomEdit->Text=Nom->DM->ElementNAMENOM->AsString;
				IDMSprEd *DMSprEd;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
									 (void**)&DMSprEd);
				DMSprEd->Init(InterfaceMainObject,InterfaceImpl);
				if(DMSprEd->OpenElement(glStrToInt64(Nom->DM->ElementIDBASEDNOM->AsString))>0)
                        {
                        NameBasEdLabel->Caption=DMSprEd->ElementNAMEED->AsString;
                        }
				else
                        {
                        NameBasEdLabel->Caption="";
                        }
                DMSprEd->kanRelease();
                }
        Nom=0;
		}

if(number_procedure_end==ER_ViborFirm)
	{
	if (type_event==1)
		{
        EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportKartTovara::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
		}

}
//----------------------------------------------------------------------------

void  TFormaReportKartTovara::OpenFormSpiskaSprNom()
{
if (Nom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->NumberProcVibor=ViborNom;
		Nom->IdNom=IdNom;
		Nom->UpdateForm();
		}
}
//-----------------------------------------------------------------------------



void TFormaReportKartTovara::NewCreateReport(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

Dv->Active=false;
Dv->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
Dv->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
Dv->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
Dv->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;
Dv->Active=true;

PrintForm->SS->BeginUpdate();
NewOutputZagolovokReport(PrintForm);

AllKolPrihod=0;
AllKolRashod=0;

AllSumPrihod=0;
AllSumRashod=0;

//таблица
Dv->First();
porNumStr=1;
while(!Dv->Eof)
        {
        NewOutputStringDv(PrintForm);

        Dv->Next();
        porNumStr++;
        }

NewOutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
Dv->Active=false;
PrintForm->Show();


}
//--------------------------------------------------------------------------
void TFormaReportKartTovara::NewOutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 130;
        cHeader->Size[3] = 70;
        cHeader->Size[4] = 150;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Карточка номенклатуры за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Фирма: "+NameFirmcxButtonEdit->Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Склад: "+NameSkladEdit->Text;;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Номенклатура: "+NameNomEdit->Text+" ("+NameBasEdLabel->Caption+")";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;


numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);

TekOstKol=0;
//получим остаток на начало периода
IDMRegOstNom * DMRegOstNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegOstNom.1",IID_IDMRegOstNom,
													(void**)&DMRegOstNom);
DMRegOstNom->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegOstNom->GetOstatokNa(DateNach->Date,IdFirm,IdSklad,IdNom)==true)
		{
		cell->Text ="Остаток на начало периода: "+FloatToStrF(DMRegOstNom->KolOstNa,ffFixed,15,3)+" "+NameBasEdLabel->Caption
        +" на сумму "+FloatToStrF(DMRegOstNom->SumOstNa,ffFixed,10,2)+"руб.";
		TekOstKol=DMRegOstNom->KolOstNa;
        TekOstSum=DMRegOstNom->SumOstNa;;
        }
else
        {
        cell->Text ="Номенклатура: Ошибка!";
		}
if (DMRegOstNom->KolOstNa<0)
	{
	cell->Style->Font->FontColor=2;
	}

DMRegOstNom->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата док.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Дата док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Номер док.";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№ док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Тип док.";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Тип док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//"Приход";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Приход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Расход";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Расход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Остаток";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Остаток";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


}
//-------------------------------------------------------------------------
void TFormaReportKartTovara::NewOutputStringDv(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//№ номер  строки
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
// дата док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvPOSDOC_OSTNOMDV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номер док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvNUMDOC->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//тип док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DvTDOC->AsString);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_OSTNOMDV->AsInteger==0)
        {
        if (DvKOL_OSTNOMDV->AsFloat!=0)
                {
				cell->Text =FloatToStrF(DvKOL_OSTNOMDV->AsFloat,ffFixed,15,3)+" "+NameBasEdLabel->Caption;
                }
        TekOstKol=TekOstKol+DvKOL_OSTNOMDV->AsFloat;
        AllKolPrihod=AllKolPrihod+DvKOL_OSTNOMDV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (DvTDV_OSTNOMDV->AsInteger==0)
        {
        if (DvSUM_OSTNOMDV->AsFloat!=0)
                {
                cell->Text=FloatToStrF(DvSUM_OSTNOMDV->AsFloat,ffFixed,10,2);
                }
        TekOstSum=TekOstSum+DvSUM_OSTNOMDV->AsFloat;
        AllSumPrihod=AllSumPrihod+DvSUM_OSTNOMDV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_OSTNOMDV->AsInteger==1)
        {
        if(DvKOL_OSTNOMDV->AsFloat!=0)
                {
				cell->Text=FloatToStrF(DvKOL_OSTNOMDV->AsFloat,ffFixed,15,3)+" "+NameBasEdLabel->Caption;
                }
        TekOstKol=TekOstKol-DvKOL_OSTNOMDV->AsFloat;
        AllKolRashod=AllKolRashod+DvKOL_OSTNOMDV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (DvTDV_OSTNOMDV->AsInteger==1)
        {
        if (DvSUM_OSTNOMDV->AsFloat!=0)
                {
                cell->Text=FloatToStrF(DvSUM_OSTNOMDV->AsFloat,ffFixed,10,2);
                }
        TekOstSum=TekOstSum-DvSUM_OSTNOMDV->AsFloat;
        AllSumRashod=AllSumRashod+DvSUM_OSTNOMDV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (TekOstKol!=0)
        {
        if (TekOstKol!=0)
                {
				cell->Text=FloatToStrF(TekOstKol, ffFixed, 15,3)+" "+NameBasEdLabel->Caption;
                }
		}

if (TekOstKol<0)
	{
	cell->Style->Font->FontColor=2;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (TekOstSum!=0)
        {
        if (TekOstSum>0.001 || TekOstSum<-0.001)
                {
				cell->Text=FloatToStrF(TekOstSum,ffFixed,10,2);
                }
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numRow++;
}
//--------------------------------------------------------------------------
void TFormaReportKartTovara::NewOutputPodavalReport(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//порядковый номер строки
//№ номер  строки
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//кномер
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//етип
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllKolPrihod, ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(AllSumPrihod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllKolRashod,ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(AllSumRashod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


//остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(TekOstKol, ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(TekOstSum,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
numRow++;
numRow++;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
//получим остаток на конец периода
IDMRegOstNom * DMRegOstNom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegOstNom.1",IID_IDMRegOstNom,
													(void**)&DMRegOstNom);
DMRegOstNom->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegOstNom->GetOstatokNa(DateCon->Date,IdFirm,IdSklad,IdNom)==true)
        {
		cell->Text="Остаток на конец периода: "+FloatToStrF(DMRegOstNom->KolOstNa, ffFixed,15,3)+" "+NameBasEdLabel->Caption
        +" на сумму "+FloatToStrF(DMRegOstNom->SumOstNa,ffFixed,10,2)+"руб.";
        }
else
        {
        cell->Text="Номенклатура: Ошибка!";
		}

if (DMRegOstNom->KolOstNa<0)
	{
	cell->Style->Font->FontColor=2;
	}

DMRegOstNom->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;



}
//-------------------------------------------------------------------------

void __fastcall TFormaReportKartTovara::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepKartNom");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKartTovara::cxButtonCreateClick(TObject *Sender)
{
NewCreateReport();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportKartTovara::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKartTovara::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprSklad();
		}break;
	case 1:
		{
		IdSklad=0;
		NameSkladEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaReportKartTovara::ViborFirm(void)
{
if (FormaSpiskaSprFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
	FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprFirm->Vibor=true;
	FormaSpiskaSprFirm->NumberProcVibor=ER_ViborFirm;
	}

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportKartTovara::EndViborFirm(void)
{

	IdFirm=FormaSpiskaSprFirm->DM->TableIDFIRM->AsInt64;
	NameFirmcxButtonEdit->Text=FormaSpiskaSprFirm->DM->TableNAMEFIRM->AsString; 


}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportKartTovara::NameFirmcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborFirm();
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------



void TFormaReportKartTovara::RegistrGoodsCreateReport(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

DvRegGoods->Active=false;
DvRegGoods->SelectSQL->Clear();


DvRegGoods->SelectSQL->Add(" select rggoods_dv .* , TDOC, NUMDOC    ");
DvRegGoods->SelectSQL->Add(" from                                   ");
DvRegGoods->SelectSQL->Add(" rggoods_dv                             ");
DvRegGoods->SelectSQL->Add(" left outer join galldoc on rggoods_dv.iddoc_rggoods_dv= galldoc.iddoc     ");
DvRegGoods->SelectSQL->Add(" where                                               ");
DvRegGoods->SelectSQL->Add(" ( :PARAM_POSNACH < rggoods_dv.posdoc_rggoods_dv     ");
DvRegGoods->SelectSQL->Add(" and rggoods_dv.posdoc_rggoods_dv < :PARAM_POSCON)   ");
DvRegGoods->SelectSQL->Add(" and rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM      ");
DvRegGoods->SelectSQL->Add(" and rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD    ");
DvRegGoods->SelectSQL->Add(" and rggoods_dv.idnom_rggoods_dv=:PARAM_IDNOM        ");
if (RoznSklad==true)
	{
	if (AllPricecxCheckBox->Checked==true)
		{

		}
	else
		{
		if (RoznPricecxCalcEdit->Text!="")
			{
			DvRegGoods->SelectSQL->Add(" and rggoods_dv.rprice_rggoods_dv=:PARAM_RPRICE  ");
			}
		}
	}
DvRegGoods->SelectSQL->Add(" order by rggoods_dv.posdoc_rggoods_dv               ");

DvRegGoods->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
DvRegGoods->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
DvRegGoods->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
DvRegGoods->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSklad;
DvRegGoods->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;

if (RoznSklad==true)
	{
		if (AllPricecxCheckBox->Checked==true)
		{

		}
	else
		{
		if (RoznPricecxCalcEdit->Text!="")
			{
			DvRegGoods->ParamByName("PARAM_RPRICE")->AsFloat=StrToFloat(RoznPricecxCalcEdit->Text);
			}
		}
	}
DvRegGoods->Active=true;

PrintForm->SS->BeginUpdate();
RegistrGoodsOutputZagolovokReport(PrintForm);

AllKolPrihod=0;
AllKolRashod=0;

AllSumPrihod=0;
AllSumRashod=0;

//таблица
DvRegGoods->First();
porNumStr=1;
while(!DvRegGoods->Eof)
        {
		RegistrGoodsOutputStringDv(PrintForm);

		DvRegGoods->Next();
        porNumStr++;
        }

RegistrGoodsOutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
DvRegGoods->Active=false;
PrintForm->Show();


}
//--------------------------------------------------------------------------
void TFormaReportKartTovara::RegistrGoodsOutputZagolovokReport(TSheetEditor *prForm)
{
		TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 130;
        cHeader->Size[3] = 70;
        cHeader->Size[4] = 150;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Карточка номенклатуры за период с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Фирма: "+NameFirmcxButtonEdit->Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Склад: "+NameSkladEdit->Text;;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Номенклатура: "+NameNomEdit->Text+" ("+NameBasEdLabel->Caption+")";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;


numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);

TekOstKol=0;
//получим остаток на начало периода
IDMRegGoods * reg;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
reg->Init(InterfaceMainObject,InterfaceImpl);
double rozn_price=0;
double kol=0;
if (RoznSklad==true)
	{
	if (AllPricecxCheckBox->Checked==true)
		{//без учета розничной цены
		kol=reg->GetOstatokNaRoznSkladeNa(DateNach->Date,IdFirm,IdSklad,IdNom,false, rozn_price);
		}
	else
		{
		if (RoznPricecxCalcEdit->Text!="")
			{
			rozn_price=StrToFloat(RoznPricecxCalcEdit->Text);
			}
		kol=reg->GetOstatokNaRoznSkladeNa(DateNach->Date,IdFirm,IdSklad,IdNom,RoznSklad, rozn_price);
		}
	}



cell->Text ="Остаток на начало периода: "+FloatToStrF(kol,ffFixed,15,3)+" "+NameBasEdLabel->Caption;
TekOstKol=kol;

if (kol<0)
	{
	cell->Style->Font->FontColor=2;
	}

reg->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата док.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Дата док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Номер док.";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№ док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Тип док.";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Тип док.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//"Приход";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Приход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Расход";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Расход";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//"Остаток";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Остаток";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


}
//-------------------------------------------------------------------------
void TFormaReportKartTovara::RegistrGoodsOutputStringDv(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//№ номер  строки
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
// дата док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvRegGoodsPOSDOC_RGGOODS_DV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номер док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvRegGoodsNUMDOC->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//тип док
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DvRegGoodsTDOC->AsString);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvRegGoodsTDV_RGGOODS_DV->AsInteger==0)
		{
		if (DvRegGoodsKOL_RGGOODS_DV->AsFloat!=0)
                {
				cell->Text =FloatToStrF(DvRegGoodsKOL_RGGOODS_DV->AsFloat,ffFixed,15,3)+" "+NameBasEdLabel->Caption;
                }
		TekOstKol=TekOstKol+DvRegGoodsKOL_RGGOODS_DV->AsFloat;
		AllKolPrihod=AllKolPrihod+DvRegGoodsKOL_RGGOODS_DV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (DvRegGoodsTDV_RGGOODS_DV->AsInteger==0)
        {
		if (DvRegGoodsRPRICE_RGGOODS_DV->AsFloat!=0)
                {
				cell->Text=FloatToStrF(DvRegGoodsRPRICE_RGGOODS_DV->AsFloat,ffFixed,10,2);
                }
		//TekOstSum=TekOstSum+DvSUM_OSTNOMDV->AsFloat;
		//AllSumPrihod=AllSumPrihod+DvSUM_OSTNOMDV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvRegGoodsTDV_RGGOODS_DV->AsInteger==1)
        {
		if(DvRegGoodsKOL_RGGOODS_DV->AsFloat!=0)
                {
				cell->Text=FloatToStrF(DvRegGoodsKOL_RGGOODS_DV->AsFloat,ffFixed,15,3)+" "+NameBasEdLabel->Caption;
                }
		TekOstKol=TekOstKol-DvRegGoodsKOL_RGGOODS_DV->AsFloat;
		AllKolRashod=AllKolRashod+DvRegGoodsKOL_RGGOODS_DV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (DvRegGoodsTDV_RGGOODS_DV->AsInteger==1)
        {
		if (DvRegGoodsRPRICE_RGGOODS_DV->AsFloat!=0)
                {
				cell->Text=FloatToStrF(DvRegGoodsRPRICE_RGGOODS_DV->AsFloat,ffFixed,10,2);
				}
//        TekOstSum=TekOstSum-DvSUM_OSTNOMDV->AsFloat;
//		AllSumRashod=AllSumRashod+DvSUM_OSTNOMDV->AsFloat;
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (TekOstKol!=0)
        {
		if (TekOstKol!=0)
				{
				cell->Text=FloatToStrF(TekOstKol, ffFixed, 15,3)+" "+NameBasEdLabel->Caption;
				}
		}

if (TekOstKol<0)
	{
	cell->Style->Font->FontColor=2;
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (TekOstSum!=0)
		{
		if (TekOstSum>0.001 || TekOstSum<-0.001)
				{
				cell->Text=FloatToStrF(TekOstSum,ffFixed,10,2);
				}
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
numRow++;
}
//--------------------------------------------------------------------------
void TFormaReportKartTovara::RegistrGoodsOutputPodavalReport(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//порядковый номер строки
//№ номер  строки
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//кномер
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//етип
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllKolPrihod, ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(AllSumPrihod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllKolRashod,ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(AllSumRashod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


//остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(TekOstKol, ffFixed,15,3)+" "+NameBasEdLabel->Caption;;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Text =FloatToStrF(TekOstSum,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
numRow++;
numRow++;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
//получим остаток на конец периода

IDMRegGoods * reg;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
reg->Init(InterfaceMainObject,InterfaceImpl);
double rozn_price=0;
double kol=0;
if (RoznSklad==true)
	{
	if (AllPricecxCheckBox->Checked==true)
		{//без учета розничной цены
		kol=reg->GetOstatokNaRoznSkladeNa(DateCon->Date,IdFirm,IdSklad,IdNom,false, rozn_price);
		}
	else
		{
		if (RoznPricecxCalcEdit->Text!="")
			{
			rozn_price=StrToFloat(RoznPricecxCalcEdit->Text);
			}
		kol=reg->GetOstatokNaRoznSkladeNa(DateNach->Date,IdFirm,IdSklad,IdNom,RoznSklad, rozn_price);
		}
	}
cell->Text ="Остаток на конец периода: "+FloatToStrF(kol,ffFixed,15,3)+" "+NameBasEdLabel->Caption;

if (kol<0)
	{
	cell->Style->Font->FontColor=2;
	}

reg->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
}
//-------------------------------------------------------------------------
void __fastcall TFormaReportKartTovara::cxButton1Click(TObject *Sender)
{
RegistrGoodsCreateReport();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKartTovara::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaReportKartTovara::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportKartTovara::RunExternalModule(__int64 id_module, int type_module)
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
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}


	module->SetInt64Variables("glIdFirm", IdFirm);
    module->SetInt64Variables("glIdSklad", IdSklad);
	module->SetInt64Variables("glIdNom", IdNom);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);


module->ExecuteModule();

}
//-----------------------------------------------------------------------------
