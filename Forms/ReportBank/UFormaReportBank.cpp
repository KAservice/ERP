//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//---------------------------------------------------------------------------
#include "UFormaReportBank.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSprPrice.h"
#include "IDMRegBank.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaReportBank::TFormaReportBank(TComponent* Owner)
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
void __fastcall TFormaReportBank::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportBank::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;
Dv->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameBSchetEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";

IdFirm=0;
IdBSchet=0;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportBankImpl),false);
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
int  TFormaReportBank::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportBank::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokBSchet)SpisokBSchet->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

DMTableExtPrintForm->kanRelease();
Dv->Active=false;
IBQ->Active=false;

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}

//---------------------------------------------------------------------------
int TFormaReportBank::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
				IdFirm=SpisokFirm->DM->ElementIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->ElementNAMEFIRM->AsString;

				}
        SpisokFirm=0;
        }

if (number_procedure_end==ViborBSchet)
        {
        if (type_event==1)
                {
				IdBSchet=SpisokBSchet->DM->TableIDBSCHET->AsInt64;
                NameBSchetEdit->Text=SpisokBSchet->DM->TableNAMEBSCHET->AsString;
                }
        SpisokBSchet=0;
        }

if (number_procedure_end==ER_ViborProject)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_ViborBusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------

void TFormaReportBank::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
        }

}
//--------------------------------------------------------------------------
void TFormaReportBank::OpenFormSpiskaSprBSchet(void)
{

if (SpisokBSchet==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&SpisokBSchet);
		SpisokBSchet->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBSchet->Vibor=true;
		SpisokBSchet->NumberProcVibor=ViborBSchet;
        SpisokBSchet->DM->IdFirm=IdFirm;
        SpisokBSchet->DM->OpenTable();
		//SpisokBSchet->LabelFirma->Caption="Фирма: "+NameFirmEdit->Text;
     }
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------




void TFormaReportBank::NewCreateReport(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

Dv->Active=false;
AnsiString zapros="";
zapros=zapros+" select RGBANK_DV .* , TDOC, NUMDOC";
zapros=zapros+" from RGBANK_DV ";
zapros=zapros+" left outer join GALLDOC on IDDOC_RGBANK_DV= IDDOC";
zapros=zapros+" where POSDOC_RGBANK_DV  between :PARAM_POSNACH and :PARAM_POSCON";
zapros=zapros+" and  IDFIRM_RGBANK_DV=:PARAM_IDFIRM";
zapros=zapros+" and  IDBSCHET_RGBANK_DV=:PARAM_IDBSCHET";
if (OnlyOperationCheckBox->Checked==true)
        {
        zapros=zapros+" and OPER_RGBANK_DV="+OperationComboBox->ItemIndex;
        }
zapros=zapros+" order by POSDOC_RGBANK_DV";

Dv->SelectSQL->Clear();
Dv->SelectSQL->Add(zapros);
Dv->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
Dv->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
Dv->ParamByName("PARAM_IDBSCHET")->AsInt64=IdBSchet;
Dv->Active=true;

PrintForm->SS->BeginUpdate();
NewOutputZagolovokReport(PrintForm);


AllSumPrihod=0;
AllSumRashod=0;
TekOstSum=0;


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
void TFormaReportBank::NewOutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
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
cell->Text = "Отчет по банку с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Фирма: "+NameFirmEdit->Text;;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Банк. счет: "+NameBSchetEdit->Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;


numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);

TekOstSum=0;
//получим остаток на начало периода
IDMRegBank * DMRegBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegBank.1",IID_IDMRegBank,
													(void**)&DMRegBank);
DMRegBank->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegBank->GetOstatokNa(DateNach->Date,IdFirm,IdBSchet)==true)
        {
        cell->Text ="Остаток на начало периода: "+FloatToStrF(DMRegBank->SumOstNa,ffFixed,10,2)+"руб.";
        TekOstSum=DMRegBank->SumOstNa;;
        }
else
        {
        cell->Text ="Номенклатура: Ошибка!";
        }
DMRegBank->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
if (OnlyOperationCheckBox->Checked==true)
        {
        switch(OperationComboBox->ItemIndex)
                {
                case  0  :
                        {
                        cell->Text ="Операции движения: прочее";
                        break;
                        }
                case  1  :
                        {
                        cell->Text ="Операции движения: Расчеты с контрагентами";
                        break;
                        }
                case  2  :
                        {
                        cell->Text ="Операции движения: Расчеты с бюджетом";
                        break;
                        }

                }




        }
else
        {
        cell->Text ="Все операции движения";
        }
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
numRow++;


}
//-------------------------------------------------------------------------
void TFormaReportBank::NewOutputStringDv(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//№ номер  строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
// дата док
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvPOSDOC_RGBANK_DV->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номер док
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DvNUMDOC->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//тип док
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DvTDOC->AsString);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_RGBANK_DV->AsInteger==0)
        {
        if (DvSUM_RGBANK_DV->AsFloat!=0)
                {
                cell->Text =FloatToStrF(DvSUM_RGBANK_DV->AsFloat, ffFixed,10,2);
                }
        TekOstSum=TekOstSum+DvSUM_RGBANK_DV->AsFloat;
        AllSumPrihod=AllSumPrihod+DvSUM_RGBANK_DV->AsFloat;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 10;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_RGBANK_DV->AsInteger==1)
        {
        if (DvSUM_RGBANK_DV->AsFloat!=0)
                {
                cell->Text=FloatToStrF(DvSUM_RGBANK_DV->AsFloat,ffFixed,10,2);
                }
        TekOstSum=TekOstSum-DvSUM_RGBANK_DV->AsFloat;
        AllSumRashod=AllSumRashod+DvSUM_RGBANK_DV->AsFloat;
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
}
//--------------------------------------------------------------------------
void TFormaReportBank::NewOutputPodavalReport(TSheetEditor *prForm)
{
numCol=1;
TcxSSCellObject *cell;
//порядковый номер строки
//№ номер  строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//дата

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//кномер
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//етип
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Всего: ";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllSumPrihod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text =FloatToStrF(AllSumRashod,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


numRow++;
numRow++;
numRow++;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
//получим остаток на конец периода
IDMRegBank * DMRegBank;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegBank.1",IID_IDMRegBank,
													(void**)&DMRegBank);
DMRegBank->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegBank->GetOstatokNa(DateCon->Date,IdFirm,IdBSchet)==true)
        {
        cell->Text="Остаток на конец периода: "+FloatToStrF(DMRegBank->SumOstNa,ffFixed,10,2)+"руб.";
        }
else
        {
        cell->Text="Номенклатура: Ошибка!";
        }
DMRegBank->kanRelease();

cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;



}
//-------------------------------------------------------------------------
void TFormaReportBank::CreateReportOCB( TSheetEditor *prForm)
{
                IBQ->Active=false;
				IBQ->ParamByName("DATENACH")->AsDateTime=DateNach->Date;
				IBQ->ParamByName("DATECON")->AsDateTime=DateCon->Date;

                IBQ->Active=true;
                porNumStr=1;
                IBQ->First();

IdTecFirm=0;
num_row_firm=numRow;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

sum_nach_ost_firm=0;
sum_prihod_firm=0;
sum_rashod_firm=0;
sum_con_ost_firm=0;


                while(!IBQ->Eof)
                        {
                        //фирма
                        if (IBQIDFIRM_PROC->AsInt64==IdTecFirm)
                                {   //эта же фирма
                                sum_nach_ost_firm=sum_nach_ost_firm+IBQNACHOSTSUM->AsFloat;
                                sum_prihod_firm=sum_prihod_firm+IBQPRIHODSUM->AsFloat;
                                sum_rashod_firm=sum_rashod_firm+IBQRASHODSUM->AsFloat;
                                sum_con_ost_firm=sum_con_ost_firm+IBQCONOSTSUM->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiFirmOCB(prForm);
                                num_row_firm=numRow;
                                OutputStringFirmOCB(prForm);
                                IdTecFirm=IBQIDFIRM_PROC->AsInteger;

                                sum_nach_ost_firm=IBQNACHOSTSUM->AsFloat;
                                sum_prihod_firm=IBQPRIHODSUM->AsFloat;
                                sum_rashod_firm=IBQRASHODSUM->AsFloat;
                                sum_con_ost_firm=IBQCONOSTSUM->AsFloat;

                                }



                        OutputStringOCB(prForm);


                        AllNachOst=AllNachOst+IBQNACHOSTSUM->AsFloat;
                        AllPrihod=AllPrihod+IBQPRIHODSUM->AsFloat;
                        AllRashod=AllRashod+IBQRASHODSUM->AsFloat;
                        AllConOst=AllConOst+IBQCONOSTSUM->AsFloat;

                        IBQ->Next();
                        }

OutputStringItogiFirmOCB(prForm);




}
//-------------------------------------------------------------------------
void TFormaReportBank::OutputZagolovokReportOCB(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 120;
        cHeader->Size[4] = 120;
        cHeader->Size[5] = 120;
        cHeader->Size[6] = 120;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "ОСВ по банку с "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;
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
cell->Text = "Фирма \\ банк. счет";
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
cell->Text = "Нач. остаток";
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

//"Приход";
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
//"Расход";
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кон. остаток";
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
//---------------------------------------------------------------------------
void TFormaReportBank::OutputStringFirmOCB(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;

//фирма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Фирма:"+IBQNAMEFIRM_PROC->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportBank::OutputStringItogiFirmOCB(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
if(sum_nach_ost_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_firm);
        cell->Text = FloatToStrF(sum_nach_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_firm);
        cell->Text = FloatToStrF(sum_prihod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(sum_rashod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(sum_con_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//-----------------------------------------------------------------------------
void TFormaReportBank::OutputStringOCB(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//касса
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEBSCHET_PROC->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQNACHOSTSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQNACHOSTSUM->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQPRIHODSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQPRIHODSUM->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQRASHODSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQRASHODSUM->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQCONOSTSUM->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQCONOSTSUM->AsFloat,ffFixed,10,2);
        }

cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;


}
//----------------------------------------------------------------------------
void TFormaReportBank::OutputPodavalReportOCB(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllRashod, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllConOst, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;


}
//----------------------------------------------------------------------------

void __fastcall TFormaReportBank::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("RepBank");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportBank::NameBSchetEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBSchet();
		}break;
	case 1:
		{
		IdBSchet=0;
		NameBSchetEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormaReportBank::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprFirm();
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportBank::cxButtonOCBClick(TObject *Sender)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

PrintForm->SS->BeginUpdate();

//шапка
OutputZagolovokReportOCB(PrintForm);

//таблица

CreateReportOCB( PrintForm);


OutputPodavalReportOCB(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportBank::cxButtonDvClick(TObject *Sender)
{
NewCreateReport();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportBank::DateNachKeyPress(TObject *Sender, char &Key)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportBank::DateConKeyPress(TObject *Sender, char &Key)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaReportBank::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportBank::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdBSchet", IdBSchet);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportBank::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TFormaReportBank::OpenFormSpiskaSprProject(void)
{

if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_ViborProject;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void  TFormaReportBank::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportBank::OpenFormSpiskaSprBusinessOper(void)
{

if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_ViborBusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TFormaReportBank::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportBank::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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
		IdBusinessOper=0;
		NameBusinessOpercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportBank::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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
		IdProject=0;
		NameProjectcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------


