//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportOCBRegCardBalance.h"
#include "math.h"
#include "IDMQueryRead.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxDBEdit"
#pragma link "cxCheckBox"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportOCBRegCardBalance::TFormaReportOCBRegCardBalance(TComponent* Owner)
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
void __fastcall TFormaReportOCBRegCardBalance::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportOCBRegCardBalance::Init(void)
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

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameGrpKlientEdit->Text="";
NameKlientEdit->Text="";
NameCardcxButtonEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportOCBCardBalanceImpl),false);
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
int  TFormaReportOCBRegCardBalance::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegCardBalance::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokGrpKlient)SpisokGrpKlient->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();
if(SprCard) SprCard->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaReportOCBRegCardBalance::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ViborFirm)
		{
		if (type_event==1)
				{
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
				NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
				}
		SpisokFirm=0;
		}

if (number_procedure_end==ViborGrpKlient)
        {
		if (type_event==1)
                {
				IdGrpKlient=SpisokGrpKlient->DM->ElementIDGRPKL->AsInt64;
                NameGrpKlientEdit->Text=SpisokGrpKlient->DM->ElementNAMEGRPKL->AsString;
                }
        SpisokGrpKlient=0;
        }

if (number_procedure_end==ViborKlient)
		{
		if (type_event==1)
				{
				IdKlient=SpisokKlient->DM->ElementIDKLIENT->AsInt64;
                NameKlientEdit->Text=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
				IdGrpKlient=0;
				NameGrpKlientEdit->Text="";
                }
		SpisokKlient=0;
		}

if (number_procedure_end==ER_ViborCard)
		{
		if (type_event==1)
				{
				EndViborCard();
                }
		SprCard=0;
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
//---------------------------------------------------------------
void TFormaReportOCBRegCardBalance::CreateReport( TSheetEditor *prForm)
{
porNumKlient=1;

                IBQ->Active=false;
				IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
                IBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
				IBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
				IBQ->ParamByName("PARAM_IDGRPKLIENT")->AsInt64=IdGrpKlient;
                IBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=IdKlient;
				IBQ->ParamByName("PARAM_IDCARD")->AsInt64=IdCard;

                IBQ->Active=true;
                porNumStr=1;
                IBQ->First();

IdTecFirm=0;
//num_row_firm=numRow;
//OutputStringFirm(prForm);


IdTecGrpKlient=0;
//num_row_grp_klient=numRow;
//OutputStringGrpKlient(prForm);

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

sum_nach_ost_firm=0;
sum_prihod_firm=0;
sum_rashod_firm=0;
sum_con_ost_firm=0;

sum_nach_ost_grp=0;
sum_prihod_grp=0;
sum_rashod_grp=0;
sum_con_ost_grp=0;

sum_nach_ost_klient=0;
sum_prihod_klient=0;
sum_rashod_klient=0;
sum_con_ost_klient=0;

num_row_firm=0;
num_row_grp_klient=0;
num_row_klient=0;

                while(!IBQ->Eof)
                        {
                        //фирма
						if (IBQIDFIRM_PROC->AsInt64==IdTecFirm)
                                {   //эта же фирма
                                sum_nach_ost_firm=sum_nach_ost_firm+IBQNACHOST_PROC->AsFloat;
                                sum_prihod_firm=sum_prihod_firm+IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_firm=sum_rashod_firm+IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_firm=sum_con_ost_firm+IBQCONOST_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiFirm(prForm);
                                num_row_firm=numRow;
                                OutputStringFirm(prForm);
								IdTecFirm=IBQIDFIRM_PROC->AsInt64;

                                sum_nach_ost_firm=IBQNACHOST_PROC->AsFloat;
                                sum_prihod_firm=IBQPRIHOD_PROC->AsFloat;
                                sum_rashod_firm=IBQRASHOD_PROC->AsFloat;
                                sum_con_ost_firm=IBQCONOST_PROC->AsFloat;

                                }

						//группа клиентов
						if (IBQIDGRP_PROC->AsInt64==IdTecGrpKlient)
								{   //эта же группа
								sum_nach_ost_grp=sum_nach_ost_grp+IBQNACHOST_PROC->AsFloat;
								sum_prihod_grp=sum_prihod_grp+IBQPRIHOD_PROC->AsFloat;
								sum_rashod_grp=sum_rashod_grp+IBQRASHOD_PROC->AsFloat;
								sum_con_ost_grp=sum_con_ost_grp+IBQCONOST_PROC->AsFloat;
								}
						else
								{
								OutputStringItogiGrpKlient(prForm);
								num_row_grp_klient=numRow;
								OutputStringGrpKlient(prForm);
								IdTecGrpKlient=IBQIDGRP_PROC->AsInt64;

								sum_nach_ost_grp=IBQNACHOST_PROC->AsFloat;
								sum_prihod_grp=IBQPRIHOD_PROC->AsFloat;
								sum_rashod_grp=IBQRASHOD_PROC->AsFloat;
								sum_con_ost_grp=IBQCONOST_PROC->AsFloat;
								porNumKlient=1;
								}

						//клиент
						if (IBQIDKLIENT_PROC->AsInt64==IdTecKlient)
								{   //эта же группа
								sum_nach_ost_klient=sum_nach_ost_klient+IBQNACHOST_PROC->AsFloat;
								sum_prihod_klient=sum_prihod_klient+IBQPRIHOD_PROC->AsFloat;
								sum_rashod_klient=sum_rashod_klient+IBQRASHOD_PROC->AsFloat;
								sum_con_ost_klient=sum_con_ost_klient+IBQCONOST_PROC->AsFloat;
								}
						else
								{
								OutputStringItogiKlient(prForm);
								num_row_klient=numRow;
								OutputStringKlient(prForm);
								IdTecKlient=IBQIDKLIENT_PROC->AsInt64;

								sum_nach_ost_klient=IBQNACHOST_PROC->AsFloat;
								sum_prihod_klient=IBQPRIHOD_PROC->AsFloat;
								sum_rashod_klient=IBQRASHOD_PROC->AsFloat;
								sum_con_ost_klient=IBQCONOST_PROC->AsFloat;
								porNumCard=1;
								}

           
						OutputStringCard(prForm);
						if (cxCheckBoxSDoc->Checked==true)
							{
                            OutputDocDvReport(prForm);
							}
						
                        porNumKlient++;

                        AllNachOst=AllNachOst+IBQNACHOST_PROC->AsFloat;
                        AllPrihod=AllPrihod+IBQPRIHOD_PROC->AsFloat;
                        AllRashod=AllRashod+IBQRASHOD_PROC->AsFloat;
                        AllConOst=AllConOst+IBQCONOST_PROC->AsFloat;

                        IBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiGrpKlient(prForm);
OutputStringItogiKlient(prForm);
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 50;
        cHeader->Size[2] = 300;
        cHeader->Size[3] = 80;
        cHeader->Size[4] = 80;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 80;


numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Остатки и движения средств на плат. картах";
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "c "+DateToStr(DateNach->Date)+" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;

numRow++;
numRow++;

if (IdFirm>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "Фирма: "+NameFirmEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

if (IdGrpKlient>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "Группа: "+NameGrpKlientEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }

if (IdKlient>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "Контрагент: "+NameKlientEdit->Text;
        cell->Style->Font->Size = 12;
        delete cell;
        numRow++;
        }


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

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Фирма / Контрагент / Карта";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Нач. остаток";
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
cell->Text = "Приход";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Расход";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кон. остаток";
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

//----------------------------------------------------------------------------
//***************   ФИРМА     *********
//----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringFirm(TSheetEditor *prForm)
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
cell->Text = "Фирма:"+IBQNAMEFIRM_PROC->AsString;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
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
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringItogiFirm(TSheetEditor *prForm)
{
if(num_row_firm==0) return;

TcxSSCellObject *cell;
if(sum_nach_ost_firm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_firm);
        cell->Text = FloatToStrF(sum_nach_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_firm);
        cell->Text = FloatToStrF(sum_prihod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(sum_rashod_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_firm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(sum_con_ost_firm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;
//sum_nach_ost_grp=IBQNACHOSTSUM->AsFloat;
//sum_prihod_grp=IBQPRIHODSUM->AsFloat;
//sum_rashod_grp=IBQRASHODSUM->AsFloat;
//sum_con_ost_grp=IBQCONOSTSUM->AsFloat;



}
//----------------------------------------------------------------------------
// группа клиентов
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringGrpKlient(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//группа ном.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEGRP_PROC->AsString;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringItogiGrpKlient(TSheetEditor *prForm)
{
if(num_row_grp_klient==0) return;
TcxSSCellObject *cell;
if(sum_nach_ost_grp!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_nach_ost_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_prihod_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_prihod_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_rashod_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_grp!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_klient);
        cell->Text = FloatToStrF(sum_con_ost_grp,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_grp_klient] = 30;
//sum_nach_ost_grp=IBQNACHOSTSUM->AsFloat;
//sum_prihod_grp=IBQPRIHODSUM->AsFloat;
//sum_rashod_grp=IBQRASHODSUM->AsFloat;
//sum_con_ost_grp=IBQCONOSTSUM->AsFloat;



}
//-----------------------------------------------------------------------------
//  клиенты
//-----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringKlient(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumKlient);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//клиент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEKLIENT_PROC->AsString;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//if (IBQNACHOST_PROC->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(IBQNACHOST_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//if (IBQPRIHOD_PROC->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(IBQPRIHOD_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Style = TFontStyles() << fsBold;
//if (IBQRASHOD_PROC->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(IBQRASHOD_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Style = TFontStyles() << fsBold;
//if (IBQCONOST_PROC->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(IBQCONOST_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
numCol++;
numRow++;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringItogiKlient(TSheetEditor *prForm)
{
if(num_row_klient==0) return;

TcxSSCellObject *cell;
if(sum_nach_ost_klient!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_klient);
		cell->Text = FloatToStrF(sum_nach_ost_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
		}

if(sum_prihod_klient!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_klient);
		cell->Text = FloatToStrF(sum_prihod_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_rashod_klient!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_klient);
		cell->Text = FloatToStrF(sum_rashod_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(sum_con_ost_klient!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_klient);
		cell->Text = FloatToStrF(sum_con_ost_klient,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Style = TFontStyles() << fsBold;
		delete cell;
		}

prForm->SS->ActiveSheet->Rows->Size[num_row_klient] = 30;
//sum_nach_ost_grp=IBQNACHOSTSUM->AsFloat;
//sum_prihod_grp=IBQPRIHODSUM->AsFloat;
//sum_rashod_grp=IBQRASHODSUM->AsFloat;
//sum_con_ost_grp=IBQCONOSTSUM->AsFloat;



}
//-----------------------------------------------------------------------------

void TFormaReportOCBRegCardBalance::OutputStringCard(TSheetEditor *prForm)
{

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumCard);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//клиент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMECARD_PROC->AsString;
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQNACHOST_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQNACHOST_PROC->AsFloat,ffFixed,15,2);
		}
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
if (IBQPRIHOD_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQPRIHOD_PROC->AsFloat,ffFixed,15,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
if (IBQRASHOD_PROC->AsFloat!=0)
		{
		cell->Text = FloatToStrF(IBQRASHOD_PROC->AsFloat,ffFixed,15,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
if (IBQCONOST_PROC->AsFloat!=0)
		{
		cell->Text = FloatToStrF(IBQCONOST_PROC->AsFloat,ffFixed,15,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
numCol++;
numRow++;
}
//-----------------------------------------------------------------------------

void TFormaReportOCBRegCardBalance::OutputPodavalReport(TSheetEditor *prForm)
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
cell->Style->Font->Style = TFontStyles() << fsBold;
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
cell->Style->Font->Style = TFontStyles() << fsBold;
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
cell->Style->Font->Style = TFontStyles() << fsBold;
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
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
}
//-----------------------------------------------------------------------------



void TFormaReportOCBRegCardBalance::OpenFormSpiskaSprFirm(void)
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
//---------------------------------------------------------------------------


void TFormaReportOCBRegCardBalance::OpenFormSpiskaSprGrpKlient(void)
{
if (SpisokGrpKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpKlient.1",IID_IFormaSpiskaSprGrpKlient,
													(void**)&SpisokGrpKlient);
		SpisokGrpKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokGrpKlient->Vibor=true;
		SpisokGrpKlient->NumberProcVibor=ViborGrpKlient;
		}

}
//--------------------------------------------------------------------------

void TFormaReportOCBRegCardBalance::OpenFormSpiskaSprKlient(void)
{
if (SpisokKlient==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpKlient.1",IID_IFormaSpiskaSprGrpKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ViborKlient;
		SpisokKlient->UpdateForm();
	}
}

//-----------------------------------------------------------------------------




void __fastcall TFormaReportOCBRegCardBalance::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Report/RepVs");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegCardBalance::cxButtonCreateClick(TObject *Sender)
{

if (cxCheckBoxSDoc->Checked==true && IdCard==0)
        {
		UnicodeString V="Не выбрана карта! Для построения отчета потребуется время. Продолжить?";
		UnicodeString Z="Внимание!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
				}
        else
                {
                return;
                }
		}

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;

AllNachOst=0;
AllPrihod=0;
AllRashod=0;
AllConOst=0;

PrintForm->SS->BeginUpdate();

//шапка
OutputZagolovokReport(PrintForm);

//таблица

CreateReport( PrintForm);


OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportOCBRegCardBalance::NameKlientEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprKlient();
		}break;
	case 1:
		{
		IdKlient=0;
		NameKlientEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegCardBalance::NameGrpKlientEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpKlient();
		}break;
	case 1:
		{
		IdGrpKlient=0;
		NameGrpKlientEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegCardBalance::NameFirmEditPropertiesButtonClick(
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

void TFormaReportOCBRegCardBalance::ViborCard(void)
{
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprDiscountCard_1.1",IID_IFormaSpiskaSprDiscountCard_1,
													(void**)&SprCard);
SprCard->Init(InterfaceMainObject,InterfaceImpl);
SprCard->Vibor=true;
SprCard->NumberProcVibor=ER_ViborCard;
SprCard->UpdateForm();

}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegCardBalance::EndViborCard(void)
{

				IdCard=glStrToInt64(SprCard->DM->TableID_SDISCOUNT_CARD->AsString);
				NameCardcxButtonEdit->Text=SprCard->DM->TableNAME_SDISCOUNT_CARD->AsString;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegCardBalance::NameCardcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborCard();
		}break;
	case 1:
		{
		IdCard=0;
		NameCardcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputDocDvReport( TSheetEditor *prForm)
{
//TecConOstatokPoDocKol=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat;
//TecConOstatokPoDocSum=DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
//			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat;


		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryReadDoc);
DMQueryReadDoc->Init(InterfaceMainObject,InterfaceImpl);
DMQueryReadDoc->pFIBQ->Close();
DMQueryReadDoc->pFIBQ->SQL->Clear();
DMQueryReadDoc->pFIBQ->SQL->Add(GetTextZaprosDoc());
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=
						IBQIDFIRM_PROC->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDCARD")->AsString=
						IBQIDCARD_PROC->AsString;


DMQueryReadDoc->pFIBQ->ExecQuery();
while(!DMQueryReadDoc->pFIBQ->Eof)
		{
		OutputStringDocDvReport(prForm);
		DMQueryReadDoc->pFIBQ->Next();
		}

DMQueryReadDoc->pFIBQ->Close();
DMQueryReadDoc->kanRelease();



}
//----------------------------------------------------------------------------
AnsiString TFormaReportOCBRegCardBalance::GetTextZaprosDoc(void)
{
AnsiString zapros= " select rgcard_balance_dv.pos_rgcard_balance_dv,   \
		 rgcard_balance_dv.tdv_rgcard_balance_dv,                      \
		 galldoc.numdoc,                                               \
		 galldoc.tdoc,                                                 \
		 rgcard_balance_dv.sum_rgcard_balance_dv                       \
 from rgcard_balance_dv                                                \
 left outer join galldoc on galldoc.iddoc=rgcard_balance_dv.iddoc_rgcard_balance_dv            \
 where (rgcard_balance_dv.pos_rgcard_balance_dv  between :PARAM_POSNACH and :PARAM_POSCON)     \
		 and rgcard_balance_dv.idfirm_rgcard_balance_dv=:PARAM_IDFIRM                          \
         and rgcard_balance_dv.idcard_rgcard_balance_dv=:PARAM_IDCARD                          \
 order by rgcard_balance_dv.pos_rgcard_balance_dv                                             ";

return zapros;
}
//-----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OutputStringDocDvReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//клиент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DMQueryReadDoc->pFIBQ->FieldByName("TDOC")->AsString)+"  №"+
				DMQueryReadDoc->pFIBQ->FieldByName("NUMDOC")->AsString+" от "+
				DMQueryReadDoc->pFIBQ->FieldByName("pos_rgcard_balance_dv")->AsString;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//if (IBQNACHOST_PROC->AsFloat!=0)
//        {
//        cell->Text = FloatToStrF(IBQNACHOST_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
if (DMQueryReadDoc->pFIBQ->FieldByName("tdv_rgcard_balance_dv")->AsInteger==0)
	{
	if (IBQPRIHOD_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQPRIHOD_PROC->AsFloat,ffFixed,15,2);
		}
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
if (DMQueryReadDoc->pFIBQ->FieldByName("tdv_rgcard_balance_dv")->AsInteger==1)
	{
	if (IBQRASHOD_PROC->AsFloat!=0)
		{
		cell->Text = FloatToStrF(IBQRASHOD_PROC->AsFloat,ffFixed,15,2);
		}
	}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
//кон. остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
//if (IBQCONOST_PROC->AsFloat!=0)
//		{
//		cell->Text = FloatToStrF(IBQCONOST_PROC->AsFloat,ffFixed,15,2);
//		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

delete cell;
numCol++;
numCol++;
numRow++;


}
//----------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaReportOCBRegCardBalance::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdGrpKlient", IdKlient);
	module->SetInt64Variables("glIdKlient", IdKlient);
	module->SetInt64Variables("glIdCard", IdCard);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegCardBalance::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OpenFormSpiskaSprProject(void)
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
void  TFormaReportOCBRegCardBalance::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportOCBRegCardBalance::OpenFormSpiskaSprBusinessOper(void)
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
void TFormaReportOCBRegCardBalance::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegCardBalance::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaReportOCBRegCardBalance::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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

