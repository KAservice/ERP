//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportRashodProduct.h"
#include "IDMSprPrice.h"
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
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportRashodProduct::TFormaReportRashodProduct(TComponent* Owner)
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
void __fastcall TFormaReportRashodProduct::FormCreate(TObject *Sender)
{
//
}

//-----------------------------------------------------------------------
bool TFormaReportRashodProduct::Init(void)
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
TypePrice->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameNomEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";

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
IdTypePrice=0;


IdNom=0;

flObrabatChangeTypePrice=false;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportRashodProductImpl),false);
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
int  TFormaReportRashodProduct::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportRashodProduct::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(Nom)Nom->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

IBQ->Active=false;
TypePrice->Active=false;
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TFormaReportRashodProduct::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
                }
        Nom=0;
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
//----------------------------------------------------------------------------
void TFormaReportRashodProduct::OpenFormSpiskaSprFirm(void)
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
void TFormaReportRashodProduct::OpenFormSpiskaSprSklad(void)
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
void TFormaReportRashodProduct::CreateReport(TSheetEditor  *PrintForm, TDateTime pos_nach, TDateTime pos_con)
{

if (!PrintForm) return;

String Zapros=" select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.idnom,sed.nameed,";
Zapros=Zapros+" sum(rgsebprod_dv.kol_rgsebprod_dv) as KOLSUM," ;
Zapros=Zapros+" sum(rgsebprod_dv.sum_rgsebprod_dv) as SUM_SEB, " ;
Zapros=Zapros+" sum(rgsebprod_dv.kolotr_rgsebprod_dv) as KOLSUM_OTR,";
Zapros=Zapros+" snom_VP.namenom as NAME_PROD, sed_VP.nameed as NAMEED_PROD, ";
Zapros=Zapros+" sum(rgvipprod_dv.kol_rgvipprod_dv) as KOL_PROD";
Zapros=Zapros+" from     rgsebprod_dv";
Zapros=Zapros+" left outer join snom on snom.idnom=rgsebprod_dv.idnom_rgsebprod_dv " ;
Zapros=Zapros+" left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn";
Zapros=Zapros+" left outer join sed on sed.ided=snom.idbasednom ";
Zapros=Zapros+" left outer join rgvipprod_dv on  rgvipprod_dv.id_rgvipprod_dv=rgsebprod_dv.idvipprod_rgsebprod_dv";
Zapros=Zapros+" left outer join snom as snom_VP on rgvipprod_dv.idnom_rgvipprod_dv=snom_VP.idnom";
Zapros=Zapros+" left outer join sed as sed_VP on snom_VP.idbasednom=sed_VP.ided";
Zapros=Zapros+" where POSDOC_RGSEBPROD_DV  between :PARAM_POSNACH and :PARAM_POSCON ";

if (IdFirm!=0)
		{
		Zapros=Zapros+" and  IDFIRM_RGSEBPROD_DV="+IntToStr(IdFirm);
		}

if (IdSkl!=0)
		{
		Zapros=Zapros+" and  IDSKLAD_RGSEBPROD_DV="+IntToStr(IdSkl);
		}

if (IdNom>0)
        {
        Zapros=Zapros+" and  IDNOM_RGSEBPROD_DV="+IntToStr(IdNom);
        }


Zapros=Zapros+" group by sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.idnom, sed.nameed, snom_VP.namenom, sed_VP.nameed ";
Zapros=Zapros+"  order by  sgrpnom.namegn, snom.namenom ";


IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(Zapros);
IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
IBQ->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
IBQ->Active=true;

//шапка
OutputZagolovokReport(PrintForm,pos_nach,pos_con);

//таблица
__int64 IdTekGrp=0;
__int64 IdTekNom=0;

IBQ->First();
while(!IBQ->Eof)
        {
					   if (IBQIDGN->AsInt64==IdTekGrp)
                                {     //эта же группа

                                }
                        else
                                {   //новая группа
                                //OutputItogiGrp(prForm);
                                //num_row_grp=numRow;
                                OutputStringGrp(PrintForm);
								IdTekGrp=IBQIDGN->AsInt64;

                                }



						if (IBQIDNOM->AsInt64==IdTekNom)
                                {     //эта же номенклатура
                                 kol_product=kol_product+IBQKOLSUM->AsFloat;
                                 kol_otr_product=kol_otr_product+IBQKOLSUM_OTR->AsFloat;
                                 sum_product=sum_product+IBQSUM_SEB->AsFloat;
                                 sum_otr_product=sum_otr_product+price_product*IBQKOLSUM_OTR->AsFloat;
                                }
                        else
                                {   //новая новая номенклатура
                                OutputItogiNom(PrintForm);
                                num_row_nom=numRow;
                                OutputStringNom(PrintForm);
                                IdTekNom=IBQIDNOM->AsInteger;
                               // NameEdTecNom=IBQNAMEED_PROC->AsString;
                              //  porNumStr=1;
                                 kol_product=IBQKOLSUM->AsFloat;
                                 kol_otr_product=IBQKOLSUM_OTR->AsFloat;
                                 sum_product=IBQSUM_SEB->AsFloat;
                                 sum_otr_product=price_product*IBQKOLSUM_OTR->AsFloat;
                                }


        OutputString(PrintForm);
        IBQ->Next();
        }

//OutputPodavalReport(PrintForm);
IBQ->Active=false;
PrintForm->SS->EndUpdate();
PrintForm->Show();
}

//------------------------------------------------------------------------------
void TFormaReportRashodProduct::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
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
cell->Text=IBQNAME_PROD->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(IBQKOL_PROD->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQNAMEED_PROD->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//израсходовано ингридиента
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (  IBQKOLSUM->AsFloat!=0)
{
cell->Text=FloatToStrF(IBQKOLSUM->AsFloat,ffFixed,10,3);
}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//на сумму
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(  IBQSUM_SEB->AsFloat!=0)
{
cell->Text=FloatToStrF(IBQSUM_SEB->AsFloat,ffFixed,10,2);
}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц колич.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if ( IBQKOLSUM_OTR->AsFloat!=0)
{
cell->Text=FloatToStrF(IBQKOLSUM_OTR->AsFloat,ffFixed,10,3);
}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;

//отриц колич.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (price_product*IBQKOLSUM_OTR->AsFloat!=0)
        {
        cell->Text=FloatToStrF(price_product*IBQKOLSUM_OTR->AsFloat,ffFixed,10,2);
		}
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;

numRow++;

}
//------------------------------------------------------------------------------
void TFormaReportRashodProduct::OutputStringGrp(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQNAMEGN->AsString;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц себестоим
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

}
//--------------------------------------------------------------------------
void TFormaReportRashodProduct::OutputStringNom(TSheetEditor *prForm)
{
price_product=0;

if(IdTypePrice!=0)
        {
		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		if (DMSprPrice->FindElement(IdTypePrice,IBQIDNOM->AsInt64)>0)
                {
                price_product=DMSprPrice->ElementZNACH_PRICE->AsFloat;

                }
		DMSprPrice->kanRelease();
        }


numCol=2;
TcxSSCellObject *cell;

//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IBQNAMENOM->AsString+"\nЕд.:"+IBQNAMEED->AsString
        +" Цена справ.:"+FloatToStr(price_product);
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц себестоим
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;



numRow++;

}
//---------------------------------------------------------------------------
void TFormaReportRashodProduct::OutputZagolovokReport(TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
		cHeader->Size[2] = 40;
		cHeader->Size[3] = 300;
//		cHeader->Size[4] = 60;
//		cHeader->Size[5] = 80;
//		cHeader->Size[6] = 60;
//		cHeader->Size[7] = 70;
//		cHeader->Size[8] = 80;
numCol=3;
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(PoDateCheckBox->Checked==true)
        {
        cell->Text="расход продуктов за  "+DateToStr(pos_nach);
        }
else
        {
		cell->Text="Расход продуктов за период с "+DateToStr(pos_nach)
                        +" по "+DateToStr(pos_con);
        }
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IdFirm==0)
		{
		cell->Text="Фирма: по всем фирмам. ";
		}
else
		{
		cell->Text="Фирма: "+NameSkladEdit->Text;;
		}

delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IdSkl==0)
		{
		cell->Text="Склад: по всем складам. ";
		}
else
		{
		cell->Text="Склад: "+NameSkladEdit->Text;;
		}

delete cell;
numRow++;



numCol=2;

//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Наименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Кол-во продукции";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Ед. продукции";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Кол-во продукта";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц. кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Себест. продукта";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="-Кол. продукта";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="-Сумма продукта";
cell->Style->WordBreak=true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;

//prForm->F1->FixedRows=numRow;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaReportRashodProduct::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Всего: ";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц.кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц.себест.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}
//---------------------------------------------------------------


void  TFormaReportRashodProduct::OpenFormSpiskaSprNom()
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

void TFormaReportRashodProduct::OutputItogiNom(TSheetEditor *prForm)
{
if (num_row_nom==0) return;
TcxSSCellObject *cell;

if(kol_product!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_nom);
		cell->Text=FloatToStrF(kol_product,ffFixed,10,3);
		cell->Style->HorzTextAlign = haRIGHT;
        delete cell;
        } 

if(sum_product!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_nom);
		cell->Text=FloatToStrF(sum_product,ffFixed,10,2);
		cell->Style->HorzTextAlign = haRIGHT;
        delete cell;
        }

if(kol_otr_product!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(8, num_row_nom);
		cell->Text=FloatToStrF(kol_otr_product,ffFixed,10,3);
		cell->Style->Font->FontColor=2;
		cell->Style->HorzTextAlign = haRIGHT;
        delete cell;
        }

if(sum_otr_product!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(9, num_row_nom);
		cell->Text=FloatToStrF(sum_otr_product,ffFixed,10,2);
		cell->Style->Font->FontColor=2;
		cell->Style->HorzTextAlign = haRIGHT;
        delete cell;
        }

}
//--------------------------------------------------------------------------




void __fastcall TFormaReportRashodProduct::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("Report/RepRashodProd");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRashodProduct::cxButtonCreateClick(TObject *Sender)
{
numRow=1;
numCol=1;

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;
PrintForm->SS->BeginUpdate();

if (PoDateCheckBox->Checked==true)
        {
		TDateTime TekDateTime=DateNach->Date;
        while (DateCon->Date>=TekDateTime)
                {
                CreateReport(PrintForm, TekDateTime, TekDateTime+1);
                TekDateTime=TekDateTime+1;
                numRow++;numRow++;numRow++;
                }
        }
else
        {
        CreateReport(PrintForm, DateNach->Date, DateCon->Date);
        }	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportRashodProduct::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeTypePrice==false) return;
		TypePrice->First();
		TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
		IdTypePrice=TypePriceID_TPRICE->AsInt64;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRashodProduct::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		IdNom=0;
		NameNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRashodProduct::NameSkladEditPropertiesButtonClick(
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
		IdSkl=0;
		NameSkladEdit->Text="";
		}break;
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportRashodProduct::NameFirmEditPropertiesButtonClick(
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

void __fastcall TFormaReportRashodProduct::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaReportRashodProduct::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportRashodProduct::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdSklad", IdSkl);
	module->SetInt64Variables("glIdNom", IdNom);
	module->SetInt64Variables("glIdTypePrice", IdTypePrice);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);


module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void TFormaReportRashodProduct::OpenFormSpiskaSprProject(void)
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
void  TFormaReportRashodProduct::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportRashodProduct::OpenFormSpiskaSprBusinessOper(void)
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
void TFormaReportRashodProduct::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportRashodProduct::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaReportRashodProduct::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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

