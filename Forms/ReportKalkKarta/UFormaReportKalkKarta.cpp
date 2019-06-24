//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportKalkKarta.h"
#include "IDMSprPrice.h"
#include "IDMSprFirm.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportKalkKarta::TFormaReportKalkKarta(TComponent* Owner)
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
void __fastcall TFormaReportKalkKarta::FormCreate(TObject *Sender)
{
//

}
//-----------------------------------------------------------------------
bool TFormaReportKalkKarta::Init(void)
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

El1->Database=DM_Connection->pFIBData;
TypePrice->Database=DM_Connection->pFIBData;
Grp->Database=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;
IBQSebProd->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameSkladEdit->Text="";
NameNomEdit->Text="";

TypePrice->Active=false;
TypePrice->Active=true;

TypePriceComboBox->Properties->Items->Clear();
TypePrice->First();
while (!TypePrice->Eof)
		{
		TypePriceComboBox->Properties->Items->Add(TypePriceNAME_TPRICE->AsString);
		TypePrice->Next();
		}
IdTypePrice=0;
IdNom=0;

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
int   TFormaReportKalkKarta::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportKalkKarta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad)SpisokSklad->kanRelease();
if(Nom)Nom->kanRelease();



Grp->Active=false;
El->Active=false;
El1->Active=false;
IBQSebProd->Active=false;
TypePrice->Active=false;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TFormaReportKalkKarta::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborSklad)
        {
		if (type_event==1)
                {
				IdSkl=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
		}

if (number_procedure_end==ViborNom)
        {
        if (type_event==1)
                {
				IdNom=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
                NameNomEdit->Text=Nom->DM->ElementNAMENOM->AsString;
                NameNom=Nom->DM->ElementFNAMENOM->AsString;
                }
        Nom=0;
        }

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportKalkKarta::OpenFormSpiskaSprSklad(void)
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
void TFormaReportKalkKarta::CreateReportPoProd(__int64 idnom, TSheetEditor *prForm)
{
IBQSebProd->Active=false;
String Zapros=" select  NAMENOM, NAMEED, IDNOM,";
Zapros=Zapros+" SUM(SUM_RGSEBPROD_DV)  AS SEBPROD,";
Zapros=Zapros+" SUM(KOL_RGSEBPROD_DV)  AS KOLPROD,";
Zapros=Zapros+" SUM(KOLOTR_RGSEBPROD_DV)  AS KOLOTRPROD";
Zapros=Zapros+" from  RGSEBPROD_DV ";
Zapros=Zapros+" left outer join RGVIPPROD_DV on IDVIPPROD_RGSEBPROD_DV=ID_RGVIPPROD_DV";
Zapros=Zapros+" left outer join SNOM on IDNOM_RGSEBPROD_DV=IDNOM";
Zapros=Zapros+" left outer join SED on IDBASEDNOM=IDED";
Zapros=Zapros+" where (POSDOC_RGSEBPROD_DV  between :PARAM_POSNACH and :PARAM_POSCON)";
Zapros=Zapros+" and  (IDNOM_RGVIPPROD_DV=:PARAM_IDNOM) ";


if (IdSkl!=0)
        {
        Zapros=Zapros+" and  IDSKLAD_RGSEBPROD_DV="+IntToStr(IdSkl);
        }

Zapros=Zapros+" group by NAMENOM, NAMEED, IDNOM ";

IBQSebProd->SelectSQL->Clear();
IBQSebProd->SelectSQL->Add(Zapros);
IBQSebProd->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
IBQSebProd->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
IBQSebProd->ParamByName("PARAM_IDNOM")->AsInt64=idnom;
IBQSebProd->Active=true;
IBQSebProd->First();
porNumStr=1;
while(!IBQSebProd->Eof)
        {
        OutputStringSebProd(prForm);numRow++;

        porNumStr++;
        SebProdReport=SebProdReport+IBQSebProdSEBPROD->AsFloat;
        IBQSebProd->Next();
        }
}
//------------------------------------------------------------------------------
void TFormaReportKalkKarta::OutputStringSebProd(TSheetEditor *prForm)
{

numCol=2;
TcxSSCellObject *cell;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQSebProdNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQSebProdKOLPROD->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQSebProdKOLPROD->AsFloat,ffFixed,10,3);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQSebProdNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQSebProdKOLPROD->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQSebProdSEBPROD->AsFloat/
                                IBQSebProdKOLPROD->AsFloat,ffFixed,10,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//себестоимость продукции
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQSebProdSEBPROD->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQSebProdSEBPROD->AsFloat,ffFixed,10,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

}

//---------------------------------------------------------------------------
void TFormaReportKalkKarta::OutputZagolovokReport(TSheetEditor *prForm)
{
numRow=1;
TcxSSCellObject *cell;

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 50;
        cHeader->Size[3] = 150;
        cHeader->Size[4] = 80;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 80;
        cHeader->Size[7] = 80;
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";






//..............................................................................
numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Унифицированная форма №ОП-1";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numRow++;
//..............................................................................
numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Утверждена постановлением Госкомстата";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numRow++;
//..............................................................................
numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="России от 25.12.98 №132";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numRow++;
//..............................................................................
numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Код";
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haCENTER;
delete cell;
numRow++;
//..............................................................................
numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Форма по ОКУД";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
//numRow++;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="0330501";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//numRow++;

//..................................................................
IDMSprFirm *F;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&F);
F->Init(InterfaceMainObject,InterfaceImpl);
F->OpenElement(glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString));
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=F->ElementFNAMEFIRM->AsString;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
F->kanRelease();

numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Text="по ОКПО";
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//..............................................................................
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//..............................................................................

numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Вид деятельности по ОКДП";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//..............................................................................


numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = NameNom;
delete cell;



numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;

//..............................................................................
numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Номер блюда по сборнику рецептур, ТТК, СТП";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
//..............................................................................
numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Вид операции";
cell->Style->HorzTextAlign = haRIGHT;
delete cell;

numCol=7;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
numRow++;
//..............................................................................

numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Номер документа";
delete cell;

numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text = "Дата составления";
delete cell;
numRow++;
//..............................................................................
numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "КАЛЬКУЛЯЦИОННАЯ КАРТОЧКА";
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol=5;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol=6;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DateToStr(DateCon->Date);
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++; 

//..............................................................................

numRow++;
//..............................................................................
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Продукты";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Количество";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Ед.";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaReportKalkKarta::OutputPodavalReport(TSheetEditor *prForm)
{
El1->Active=false;
El1->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
El1->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
El1->ParamByName("PARAM_IDNOM")->AsInteger=IdNom;
El1->Active=true;
//............................................................................
numCol=2;
TcxSSCellObject *cell;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Общая стоимость сырьевого набора ";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SebProdReport,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
//.............................................................................
numCol=2;
//порядковый номер строки 
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if ( El1SEBREAL->AsFloat!=0)
        {
        cell->Text="Наценка  "+FloatToStrF(El1RESREAL->AsFloat/(El1SEBREAL->AsFloat/100),ffFixed,10,0)+"%";
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;


numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if ( El1RESREAL->AsFloat!=0)
        {
        cell->Text=FloatToStrF(El1RESREAL->AsFloat,ffFixed,10,2);
        }
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
numCol++;

numRow++;


//............................................................................
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Cумма ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(El1SUMREAL->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
delete cell;
numCol++;

numRow++;

//............................................................................
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Количество проданных единиц ("+El1NAMEED->AsString+")";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(El1KOLREAL->AsFloat,ffFixed,10,3);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
delete cell;
numCol++;

numRow++;
//............................................................................
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Выход одного блюда в готовом виде";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
//............................................................................

numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Заведующий производством";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


//............................................................................

numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Калькуляцию составил ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = "Калькуляцию составил ";
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


//............................................................................

numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "УТВЕРЖДАЮ Руководитель организации";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;


//............................................................................

}
//---------------------------------------------------------------


void  TFormaReportKalkKarta::OpenFormSpiskaSprNom()
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




void __fastcall TFormaReportKalkKarta::cxButtonCreateClick(TObject *Sender)
{
if (IdSkl==0)
        {
        ShowMessage("Необходимо выбрать склад!");
        return;
        }

if (IdNom==0)
        {
        ShowMessage("Необходимо выбрать номенклатуру!");
        return;
        }


TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
SebProdReport=0;



//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица
CreateReportPoProd(IdNom, PrintForm);
OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();

PrintForm->Show();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportKalkKarta::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
		TypePrice->First();
		TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
		IdTypePrice=TypePriceID_TPRICE->AsInt64;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKalkKarta::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKalkKarta::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKalkKarta::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

