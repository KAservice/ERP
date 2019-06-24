//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportSostProd.h"
#include "IDMSprEd.h"
#include "IDMSprNom.h"
#include "IDMSprSostProd.h"
#include "IDMSprPrice.h"
#include "IDMSprNomRest.h"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportSostProd::TFormaReportSostProd(TComponent* Owner)
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
bool TFormaReportSostProd::Init(void)
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

TypePrice->Database=DM_Connection->pFIBData;
IBQNom->Database=DM_Connection->pFIBData;
IBQNomRest->Database=DM_Connection->pFIBData;
BasEd->Database=DM_Connection->pFIBData;
OsnEd->Database=DM_Connection->pFIBData;
EdProd->Database=DM_Connection->pFIBData;

TypePrice->Active=false;
TypePrice->Active=true;
flObrabatChangeTypePrice=false;

TypePriceComboBox->Properties->Items->Clear();
TypePrice->First();
while (!TypePrice->Eof)
		{
		TypePriceComboBox->Properties->Items->Add(TypePriceNAME_TPRICE->AsString);
		TypePrice->Next();
		}

flObrabatChangeTypePrice=true;

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
int  TFormaReportSostProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaReportSostProd::UpdateForm()
{
IBQNom->Active=false;
IBQNom->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;
IBQNom->Active=true;

IBQNomRest->Active=false;
IBQNomRest->ParamByName("PARAM_ID_NOMREST")->AsInt64=IdNomRest;
IBQNomRest->Active=true;


BasEd->Active=false;
OsnEd->Active=false;
EdProd->Active=false;
BasEd->ParamByName("PARAM_IDED")->AsInt64=IBQNomIDBASEDNOM->AsInt64;
OsnEd->ParamByName("PARAM_IDED")->AsInt64=IBQNomIDOSNEDNOM->AsInt64;
EdProd->ParamByName("PARAM_IDED")->AsInt64=IBQNomRestIDEDPROD_NOMREST->AsInt64;

BasEd->Active=true;
OsnEd->Active=true;
EdProd->Active=true;


NameNomDBEdit->Text=NameNom;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSostProd::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(Nom) Nom->kanRelease();



TypePrice->Active=false;
IBQNom->Active=false;
IBQNomRest->Active=false;
BasEd->Active=false;
OsnEd->Active=false;
EdProd->Active=false;
Action=caFree;
}

//----------------------------------------------------------------------------
void  TFormaReportSostProd::OpenFormSpiskaSprNom()
{
if (Nom==NULL)
		{

		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->NumberProcVibor=1;
		Nom->UpdateForm();
        }
}
//-----------------------------------------------------------------------------
int TFormaReportSostProd::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//==ViborFirm)
	{

		if (type_event==1)
				{
				IdNom=glStrToInt64(Nom->DM->TableIDNOM->AsString);
				NameNom=Nom->DM->TableNAMENOM->AsString;
				NameNomDBEdit->Text=Nom->DM->TableNAMENOM->AsString;
				}
		Nom=0;
	}
UpdateForm();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaReportSostProd::OutputZagolovokTable(TSheetEditor *prForm)
{
int numCol=2;
TcxSSCellObject *cell;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//списывать
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Дв.";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//вес нетто
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Нетто";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//вес брутто
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Брутто";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма брутто
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//вес брутто для основной единицы
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Брутто ОЕ "+OsnEdNAMEED->AsString;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма для основной единицы
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма ОЕ "+OsnEdNAMEED->AsString;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//вес брутто для базовой единицы
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Брутто БЕ "+BasEdNAMEED->AsString;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма для базовой единицы
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма БЕ "+BasEdNAMEED->AsString;
cell->Style->WordBreak = true;
cell->Style->Font->Size = 8;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;
}
//---------------------------------------------------------------------------
void TFormaReportSostProd::OutputSostav(__int64 idnom, __int64 id_nom_rest, float K, float K2, TSheetEditor *prForm)
{
float KolEdProd=0;
float KFEdProd=0;
IDMSprNom * DMProd;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMProd);
DMProd->Init(InterfaceMainObject,InterfaceImpl);
if (DMProd->OpenElement(idnom)==0)
        {
		DMProd->kanRelease();
        return;
        }
//-----------------------------------------------
IDMSprNomRest * DMNomRest;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest,
													(void**)&DMNomRest);
DMNomRest->Init(InterfaceMainObject,InterfaceImpl);
DMNomRest->Id=id_nom_rest;
DMNomRest->OpenElement();
//IdNomRest=DMNomRest->ElementID_NOMREST->AsInteger;

if(DMNomRest->ElementKOLEDPROD_NOMREST->AsFloat==0){KolEdProd=1;}
else {KolEdProd=DMNomRest->ElementKOLEDPROD_NOMREST->AsFloat;}

if (DMNomRest->ElementKFED->AsFloat==0){KFEdProd=1;}
else{KFEdProd=DMNomRest->ElementKFED->AsFloat;}

//ShowMessage("Текущий состав:"+DMNomRest->ElementNAME_NOMREST->AsString);
DMNomRest->kanRelease();
//------------------------------------------------
//TDMSprEd *DMEdProd=new TDMSprEd(Application);
//DMEdProd->OpenElement(DMProd->ElementIDEDPRODNOM->AsInteger);

//----------------------------------------------------------------

//if(DMProd->ElementKOLPRODNOM->AsFloat==0){KolEdProd=1;}
//else {KolEdProd=DMProd->ElementKOLPRODNOM->AsFloat;}

//if (DMEdProd->ElementKFED->AsFloat==0){KFEdProd=1;}
//else{KFEdProd=DMEdProd->ElementKFED->AsFloat;}

TcxSSCellObject *cell;

IDMSprSostProd *DMSostav;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSostProd.1",IID_IDMSprSostProd,
													(void**)&DMSostav);
DMSostav->Init(InterfaceMainObject,InterfaceImpl);
DMSostav->KolEdProd=KolEdProd;
DMSostav->KFEdProd=KFEdProd;
DMSostav->Pos =IBQNomRestPOS_NOMREST->AsDateTime;
DMSostav->OpenTable(id_nom_rest);

DMSostav->Table->First();
while (!DMSostav->Table->Eof)
        {
        if (DMSostav->TableTNOM->AsInteger==2)
                {
                float KF=0;
                if (DMSostav->TableKF_SPROD->AsFloat==0){KF=1;}
                else{KF=DMSostav->TableKF_SPROD->AsFloat;}
                numCol=2;
                //порядковый номер строки
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = IntToStr(porNumStr);
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //списывать
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                if (DMSostav->TableSPIS_SPROD->AsInteger==1){cell->Text="Да";}
                else{cell->Text="Нет";}
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //номенклатура
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = DMSostav->TableNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //вес нетто
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                float Netto=DMSostav->TableNKOL_SPROD->AsFloat*KF*K;
                cell->Text=FloatToStrF(Netto,ffFixed,15,3)+" "+DMSostav->TableNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //вес брутто
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
				float Brutto=DMSostav->TableBKOL_SPROD->AsFloat*K;
                cell->Text=FloatToStrF(Brutto,ffFixed,15,3)+" "+DMSostav->TableNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //коэффициенты
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = "k  "+
                        FloatToStrF( DMSostav->TableBKOL_SPROD->AsFloat*KF
                         *K/(KolEdProd*KFEdProd),ffFixed,15,3)+" K2 "
                         +FloatToStr(KolEdProd*KFEdProd);
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numRow++;


                //необходимо получить ID текущего состава полуфабриката---------------------
				IDMSprNomRest * DMNRest;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNomRest.1",IID_IDMSprNomRest,
													(void**)&DMNRest);
				DMNRest->Init(InterfaceMainObject,InterfaceImpl);
				DMNRest->GetTekSostav(DMSostav->TableIDKOMPL_SPROD->AsInt64,Now());

                //-------------------------------------------------------------------------------

				OutputSostav(DMSostav->TableIDKOMPL_SPROD->AsInt64,
						DMNRest->ElementID_NOMREST->AsInt64,     //IDNOM_REST
                        DMSostav->TableBKOL_SPROD->AsFloat*KF
                         *K/(KolEdProd*KFEdProd),
                        (KolEdProd*KFEdProd),
                        prForm); 
                DMNRest->kanRelease();
                numRow++;        
                }

        if (DMSostav->TableTNOM->AsInteger==0)
                {
                float KF=0;
                if (DMSostav->TableKF_SPROD->AsFloat==0){KF=1;}
                else{KF=DMSostav->TableKF_SPROD->AsFloat;}

                SumStr=0;
                SumStrNaOsnEd=0;
                numCol=2;
                //порядковый номер строки
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = IntToStr(porNumStr);
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //списывать
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                if (DMSostav->TableSPIS_SPROD->AsInteger==1){cell->Text="Да";}
                else{cell->Text="Нет";}
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //номенклатура
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = DMSostav->TableNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //вес нетто
                float Netto=DMSostav->TableNNABASED->AsFloat*K*K2;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(Netto,ffFixed,15,3)+" "+DMSostav->TableNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //вес брутто
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                float Brutto=DMSostav->TableNABASED->AsFloat*K*K2;
                cell->Text = FloatToStrF(Brutto,ffFixed,15,3)+" "+DMSostav->TableNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //цена
				IDMSprPrice * DMPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMPrice);
				DMPrice->Init(InterfaceMainObject,InterfaceImpl);
                DMPrice->FindElement(IdTypePrice,DMSostav->TableIDKOMPL_SPROD->AsInteger);
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(DMPrice->ElementZNACH_PRICE->AsFloat,ffFixed,15,2);
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //сумма  брутто
                SumStr=DMPrice->ElementZNACH_PRICE->AsFloat*KF*Brutto;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(SumStr,ffFixed,15,2);
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;

                //найдем нименование базовой единицы комплектующего
				IDMSprNom * DMKompl;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&DMKompl);
				DMKompl->Init(InterfaceMainObject,InterfaceImpl);
				DMKompl->OpenElement(DMSostav->TableIDKOMPL_SPROD->AsInt64);
				IDMSprEd *DMEdKompl;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&DMEdKompl);
				DMEdKompl->Init(InterfaceMainObject,InterfaceImpl);;
				DMEdKompl->OpenElement(glStrToInt64(DMKompl->ElementIDBASEDNOM->AsString));

                //вес брутто на  основную единицу
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                float BruttoOE=DMSostav->TableNABASED->AsFloat*
                                (OsnEdKFED->AsFloat)*K;
                cell->Text = FloatToStrF(BruttoOE,ffFixed,15,3)
                                        +" "+DMEdKompl->ElementNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;

                //сумма  брутто  на  основную единицу
                SumStrNaOsnEd=DMPrice->ElementZNACH_PRICE->AsFloat
                        *(BruttoOE);
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(SumStrNaOsnEd,ffFixed,15,2);
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //вес брутто на  базовую единицу
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                float BruttoBE=DMSostav->TableNABASED->AsFloat*K;
                cell->Text=FloatToStrF(BruttoBE,ffFixed,15,3)
                                +" "+DMEdKompl->ElementNAMEED->AsString;
				cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                //сумма  брутто  на  базовую единицу
                SumStrNaBasEd=DMPrice->ElementZNACH_PRICE->AsFloat*(BruttoBE);
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(SumStrNaBasEd,ffFixed,15,2);
                cell->Style->HorzTextAlign = haRIGHT;
				cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;

                Sum=Sum+SumStr;
                SumNaOsnEd=SumNaOsnEd+SumStrNaOsnEd;
                SumNaBasEd=SumNaBasEd+SumStrNaBasEd;

                numRow++;
				DMEdKompl->kanRelease();
				DMKompl->kanRelease();
				DMPrice->kanRelease();

                }

        DMSostav->Table->Next();
        }

DMSostav->kanRelease();
//delete DMEdProd;
DMProd->kanRelease();

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportSostProd::cxButtonCreateClick(TObject *Sender)
{
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
prForm->SS->BeginUpdate();

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 50;
        cHeader->Size[3] = 50;
        cHeader->Size[4] = 200;
        cHeader->Size[5] = 70;
        cHeader->Size[6] = 70;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;

numRow=1;
numCol=2;
porNumStr=1;
Sum=0;
SumNaOsnEd=0;
//шапка
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Состав продукции. ";
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Номенклатура: "+IBQNomNAMENOM->AsString;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Тип цен: "+TypePriceNAME_TPRICE->AsString;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Базовая единица: "+BasEdNAMEED->AsString+" КФ="+BasEdKFED->AsString;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Основная единица: "+OsnEdNAMEED->AsString+" КФ="+OsnEdKFED->AsString;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Состав задан на : "+IBQNomRestKOLEDPROD_NOMREST->AsString
                +" "+EdProdNAMEED->AsString
                +" КФ="+EdProdKFED->AsString;
delete cell;
numRow++;numRow++;

OutputZagolovokTable(prForm);


SumNaOsnEd=0;
SumNaBasEd=0;
SumStr=0;
SumStrNaOsnEd=0;
SumStrNaBasEd=0;

float KolEd=IBQNomRestKOLEDPROD_NOMREST->AsFloat;
float KFEd=EdProdKFED->AsFloat;

if(KolEd==0) KolEd=1;
if(KFEd==0) KFEd=1;

OutputSostav(IBQNomIDNOM->AsInteger,IdNomRest, 1,KolEd*KFEd, prForm);


//подвал
numRow++;

numCol=4;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
cell->Text = "Всего: ";
delete cell;


numCol=8;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
cell->Text = FloatToStrF(Sum,ffFixed,15,2);
delete cell;

numCol=10;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
cell->Text = FloatToStrF(SumNaOsnEd,ffFixed,15,2);
delete cell;

numCol=12;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 14;
cell->Text = FloatToStrF(SumNaBasEd,ffFixed,15,2);
delete cell;

prForm->SS->EndUpdate();
prForm->Show();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportSostProd::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;
		TypePrice->First();
		TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
		IdTypePrice=TypePriceID_TPRICE->AsInt64;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportSostProd::NameNomDBEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportSostProd::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

