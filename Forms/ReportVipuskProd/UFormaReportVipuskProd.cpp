//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaReportVipuskProd.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckBox"
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
__fastcall TFormaReportVipuskProd::TFormaReportVipuskProd(TComponent* Owner)
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
void __fastcall TFormaReportVipuskProd::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportVipuskProd::Init(void)
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

Grp->Database=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;
IBQSebProd->Database=DM_Connection->pFIBData;
IBQRealGrp->Database=DM_Connection->pFIBData;
IBQRealEl->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameNomEdit->Text="";

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

SumOtrSebRealGrp=0;
NumStrGrp=0;
SumOtrSebRealNom=0;
NumStrNom=0;
flObrabatChangeTypePrice=true;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportVipuskProdImpl),false);
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
int  TFormaReportVipuskProd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportVipuskProd::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(Nom)Nom->kanRelease();



Grp->Active=false;
El->Active=false;
IBQSebProd->Active=false;
TypePrice->Active=false;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TFormaReportVipuskProd::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

EditRekvisit=NO;
return -1;
}
//----------------------------------------------------------------------------
void TFormaReportVipuskProd::OpenFormSpiskaSprFirm(void)
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
void TFormaReportVipuskProd::OpenFormSpiskaSprSklad(void)
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
void TFormaReportVipuskProd::CreateReport(TSheetEditor  *PrintForm, TDateTime pos_nach, TDateTime pos_con)
{

if (!PrintForm) return;

SebProdReport=0;

RegRealSebReal=0;
RegRealSumReal=0;
RegRealResReal=0;

porNumStrGrp=1;
String ZaprosGrp="";
ZaprosGrp=          " select  NAMEGN, IDGN," ;
ZaprosGrp=ZaprosGrp+" SUM(SEB_RGVIPPROD_DV)  AS SEBPROD ";
ZaprosGrp=ZaprosGrp+" from   RGVIPPROD_DV ";
ZaprosGrp=ZaprosGrp+" left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM";
ZaprosGrp=ZaprosGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";
ZaprosGrp=ZaprosGrp+" where POSDOC_RGVIPPROD_DV  between :PARAM_POSNACH and :PARAM_POSCON ";

if (IdFirm!=0)
		{
		ZaprosGrp=ZaprosGrp+" and  IDFIRM_RGVIPPROD_DV="+IntToStr(IdFirm);
		}

if (IdSkl!=0)
		{
		ZaprosGrp=ZaprosGrp+" and  IDSKLAD_RGVIPPROD_DV="+IntToStr(IdSkl);
		}

if (IdNom>0)
        {
        ZaprosGrp=ZaprosGrp+" and  IDNOM_RGVIPPROD_DV="+IntToStr(IdNom);
        }


ZaprosGrp=ZaprosGrp+" group by NAMEGN, IDGN ";



Grp->Active=false;
Grp->SelectSQL->Clear();
Grp->SelectSQL->Add(ZaprosGrp);
Grp->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
Grp->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
Grp->Active=true;

//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm,pos_nach,pos_con);

//таблица

Grp->First();
while(!Grp->Eof)
        {

        OutputStringGrp(PrintForm);numRow++;
        if (StrRealCheckBox->Checked==true)
                {
				OutputStringRealGrpProd(PrintForm, GrpIDGN->AsInt64, IdSkl,pos_nach,pos_con);
                }
        SebProdReport=SebProdReport+GrpSEBPROD->AsFloat;

        porNumStr=1;
        El->Active=false;

        String ZaprosEl=" select  NAMENOM, NAMEED,IDNOM,";
        ZaprosEl=ZaprosEl+" SUM(SEB_RGVIPPROD_DV)  AS SEBPROD,";
        ZaprosEl=ZaprosEl+" SUM(KOL_RGVIPPROD_DV)  AS KOLPROD ";
        ZaprosEl=ZaprosEl+" from  RGVIPPROD_DV ";
        ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM";
        ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosEl=ZaprosEl+" where (POSDOC_RGVIPPROD_DV  between :PARAM_POSNACH and :PARAM_POSCON)";

        if (GrpIDGN->AsInteger==0)
                {
                ZaprosEl=ZaprosEl+" and  (IDGN IS NULL )";
                }
        else
                {
				ZaprosEl=ZaprosEl+" and  (IDGN= "+IntToStr(GrpIDGN->AsInt64)+")";
				}

		if (IdFirm!=0)
                {
				ZaprosEl=ZaprosEl+" and  IDFIRM_RGVIPPROD_DV="+IntToStr(IdFirm);
				}

        if (IdSkl!=0)
                {
                ZaprosEl=ZaprosEl+" and  IDSKLAD_RGVIPPROD_DV="+IntToStr(IdSkl);
                }

        if (IdNom>0)
                {
                ZaprosEl=ZaprosEl+" and  IDNOM_RGVIPPROD_DV="+IntToStr(IdNom);
                }

        ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED, IDNOM ";

		El->SelectSQL->Clear();
		El->SelectSQL->Add(ZaprosEl);
        El->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
        El->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
        El->Active=true;
        El->First();
        while(!El->Eof)
                {
                OutputString(PrintForm);numRow++;

                if (StrRealCheckBox->Checked==true)
                        {
						OutputStringRealProd(PrintForm, ElIDNOM->AsInt64, IdSkl,pos_nach,pos_con);
                        }

                        
				CreateReportPoProd(ElIDNOM->AsInt64, PrintForm,pos_nach,pos_con);
                porNumStr++;
                El->Next();
                }

        porNumStrGrp++;
        Grp->Next();
        }

OutputPodavalReport(PrintForm);

if (StrRealCheckBox->Checked==true)
        {
        OutputStringRealProdPodval(PrintForm);
        }
        
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//-----------------------------------------------------------------------------
void TFormaReportVipuskProd::CreateReportPoProd(__int64 idnom, TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con)
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

if (IdFirm!=0)
        {
        Zapros=Zapros+" and  IDFIRM_RGSEBPROD_DV="+IntToStr(IdFirm);
		}

if (IdSkl!=0)
        {
        Zapros=Zapros+" and  IDSKLAD_RGSEBPROD_DV="+IntToStr(IdSkl);
        }

Zapros=Zapros+" group by NAMENOM, NAMEED, IDNOM ";

IBQSebProd->SelectSQL->Clear();
IBQSebProd->SelectSQL->Add(Zapros);
IBQSebProd->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
IBQSebProd->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
IBQSebProd->ParamByName("PARAM_IDNOM")->AsInt64=idnom;
IBQSebProd->Active=true;
IBQSebProd->First();
while(!IBQSebProd->Eof)
        {
        OutputStringSebProd(prForm);numRow++;

        porNumStr++;
        IBQSebProd->Next();
        }
}
//------------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputStringSebProd(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
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
cell->Text = IBQSebProdNAMENOM->AsString;
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
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQSebProdNAMEED->AsString;
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
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество  отриц.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( IBQSebProdKOLOTRPROD->AsFloat!=0)
        {
        cell->Text=FloatToStrF(IBQSebProdKOLOTRPROD->AsFloat,ffFixed,10,3);
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;

float Price=0;
float OtrSeb=0;
if(IdTypePrice!=0 && IBQSebProdKOLOTRPROD->AsFloat!=0)
        {
		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
		if (DMSprPrice->FindElement(IdTypePrice,IBQSebProdIDNOM->AsInt64)>0)
                {
                Price=DMSprPrice->ElementZNACH_PRICE->AsFloat;
                OtrSeb=Price*IBQSebProdKOLOTRPROD->AsFloat;
                OtrSebProdReport=OtrSebProdReport+OtrSeb;
                }
        DMSprPrice->kanRelease();
        }

//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( Price!=0)
        {
        cell->Text=FloatToStrF(Price,ffFixed,10,2);
		}
cell->Style->Font->FontColor=2;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц. себест
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if( OtrSeb!=0)
        {
        cell->Text=FloatToStrF(OtrSeb,ffFixed,10,2);
		}
cell->Style->Font->FontColor=2;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
SumOtrSebRealGrp=SumOtrSebRealGrp+OtrSeb;
SumOtrSebRealNom=SumOtrSebRealNom+OtrSeb;
}
//------------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputString(TSheetEditor *prForm)
{
//выведем сумму отрицательной себестоимости номенклатуры
//сумма  отриц.
TcxSSCellObject *cell;
if (SumOtrSebRealNom>0 && NumStrNom>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(9, NumStrNom);
        cell->Text=FloatToStrF(SumOtrSebRealNom,ffFixed,10,2);
        delete cell;
        }

numCol=2;
NumStrNom=numRow;
SumOtrSebRealNom=0;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text=ElNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text=FloatToStrF(ElKOLPROD->AsFloat,ffFixed,10,3);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text=ElNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//себестоимость продукции
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text=FloatToStrF(ElSEBPROD->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц колич.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц себест.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}
//------------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputStringGrp(TSheetEditor *prForm)
{
//выведем сумму отрицательной себестоимости группы
//сумма  отриц.
TcxSSCellObject *cell;
if (SumOtrSebRealGrp>0 && NumStrGrp>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(9, NumStrGrp);
        cell->Text=FloatToStrF(SumOtrSebRealGrp,ffFixed,10,2);
        delete cell;
        }


numCol=2;
NumStrGrp=numRow;
SumOtrSebRealGrp=0;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=IntToStr(porNumStrGrp);
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
cell->Text=GrpNAMEGN->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=FloatToStrF(GrpSEBPROD->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц себестоим
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

}
//---------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputZagolovokReport(TSheetEditor *prForm, TDateTime pos_nach, TDateTime pos_con)
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
TcxSSCellObject *cell;
numCol=1;

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
if(PoDateCheckBox->Checked==true)
        {
        cell->Text="Выпуск продукции за  "+DateToStr(pos_nach);
        }
else
        {
        cell->Text="Выпуск продукции за период с "+DateToStr(pos_nach)
                        +" по "+DateToStr(pos_con);
        }
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
if (IdFirm==0)
        {
		cell->Text="Фирма: по всем фирмам. ";
        }
else
        {
		cell->Text="Фирма: "+NameFirmEdit->Text;;
        }
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
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
cell->Text="Кол.";
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
cell->Text="Ед.";
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
cell->Text="Себест.";
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
cell->Text="Кол. -";
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
cell->Text="Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма отриц. списан
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Сумма -";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
//выведем сумму отрицательной себестоимости группы
//сумма  отриц.

if (SumOtrSebRealGrp>0 && NumStrGrp>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(9, NumStrGrp);
        cell->Text=FloatToStrF(SumOtrSebRealGrp,ffFixed,10,2);
        delete cell;
        }

//выведем сумму отрицательной себестоимости номенклатуры
//сумма  отриц.

if (SumOtrSebRealNom>0 && NumStrNom>0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(9, NumStrNom);
		cell->Text=FloatToStrF(SumOtrSebRealNom,ffFixed,10,2);
		cell->Style->Font->FontColor=2;
        delete cell;
        }

        

numCol=2;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
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
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=FloatToStrF(SebProdReport,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц.кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//отриц.себест.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text=FloatToStrF(OtrSebProdReport,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
numRow++;
}
//---------------------------------------------------------------


void  TFormaReportVipuskProd::OpenFormSpiskaSprNom()
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
void TFormaReportVipuskProd::OutputStringRealGrpProd(TSheetEditor *prForm, __int64 id_grp, __int64 id_sklad, TDateTime pos_nach, TDateTime pos_con)
{
TcxSSCellObject *cell;
String ZaprosRealGrp="";

ZaprosRealGrp=          " select  NAMEGN, IDGN," ;
ZaprosRealGrp=ZaprosRealGrp+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL, ";
ZaprosRealGrp=ZaprosRealGrp+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL, ";
ZaprosRealGrp=ZaprosRealGrp+" SUM(RESREAL_RGREAL_DV)  AS RESREAL,";
ZaprosRealGrp=ZaprosRealGrp+" SUM(KOL_RGREAL_DV)  AS KOLREAL";

ZaprosRealGrp=ZaprosRealGrp+" from   RGREAL_DV ";
ZaprosRealGrp=ZaprosRealGrp+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM";
ZaprosRealGrp=ZaprosRealGrp+" left outer join SGRPNOM on IDGRPNOM=IDGN";
ZaprosRealGrp=ZaprosRealGrp+" where POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON ";

if (id_sklad==0)
        {

        }
else
        {
        ZaprosRealGrp=ZaprosRealGrp+" and  IDSKLAD_RGREAL_DV="+IntToStr(id_sklad);
        }

if (id_grp==0)
        {
        ZaprosRealGrp=ZaprosRealGrp+" and  IDGN IS NULL";
        }
else
        {
        ZaprosRealGrp=ZaprosRealGrp+" and  IDGN="+IntToStr(id_grp);
        }

ZaprosRealGrp=ZaprosRealGrp+" group by NAMEGN, IDGN ";



IBQRealGrp->Active=false;
IBQRealGrp->SelectSQL->Clear();
IBQRealGrp->SelectSQL->Add(ZaprosRealGrp);
IBQRealGrp->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;;
IBQRealGrp->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
IBQRealGrp->Active=true;


//таблица

IBQRealGrp->First();
while(!IBQRealGrp->Eof)
        {
        //SumRealReport=SumRealReport+GrpSUMREAL->AsFloat;
        //SebRealReport=SebRealReport+GrpSEBREAL->AsFloat;
        //ResRealReport=ResRealReport+GrpRESREAL->AsFloat;
        numCol=2;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        //сумма
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Font->FontColor = 48;
        cell->Text="Сумма реализации: "+FloatToStrF(IBQRealGrpSUMREAL->AsFloat,ffFixed,10,2)
                        +"; Себестоимость: "+FloatToStrF(IBQRealGrpSEBREAL->AsFloat,ffFixed,10,2)
                        +"; Результат: "+FloatToStrF(IBQRealGrpRESREAL->AsFloat,ffFixed,10,2)
                        +"; Наценка: "+FloatToStrF(IBQRealGrpRESREAL->AsFloat/(IBQRealGrpSEBREAL->AsFloat/100),ffFixed,10,0)+"%";
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;


        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;

        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
		delete cell;
        numCol++;
        numRow++;

        RegRealSebReal=RegRealSebReal+IBQRealGrpSEBREAL->AsFloat;
        RegRealSumReal=RegRealSumReal+IBQRealGrpSUMREAL->AsFloat;
        RegRealResReal=RegRealResReal+IBQRealGrpRESREAL->AsFloat;

        IBQRealGrp->Next();
        }




}
//-----------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputStringRealProd(TSheetEditor *prForm, __int64 id_nom, __int64 id_sklad, TDateTime pos_nach, TDateTime pos_con)
{
TcxSSCellObject *cell;

        IBQRealEl->Active=false;

        String ZaprosRealEl=" select  NAMENOM, NAMEED, IDNOM,";
        ZaprosRealEl=ZaprosRealEl+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL, ";
        ZaprosRealEl=ZaprosRealEl+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL, ";
        ZaprosRealEl=ZaprosRealEl+" SUM(RESREAL_RGREAL_DV)  AS RESREAL, ";
        ZaprosRealEl=ZaprosRealEl+" SUM(KOL_RGREAL_DV)  AS KOLREAL,  ";
        ZaprosRealEl=ZaprosRealEl+" SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL ";
        ZaprosRealEl=ZaprosRealEl+" from  RGREAL_DV ";
        ZaprosRealEl=ZaprosRealEl+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM";
        ZaprosRealEl=ZaprosRealEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
        ZaprosRealEl=ZaprosRealEl+" left outer join SED on IDBASEDNOM=IDED";
        ZaprosRealEl=ZaprosRealEl+" where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON)";

        ZaprosRealEl=ZaprosRealEl+" and  IDNOM="+IntToStr(id_nom);


        if (id_sklad!=0)
                {
                ZaprosRealEl=ZaprosRealEl+" and  IDSKLAD_RGREAL_DV="+IntToStr(id_sklad);
                }

        ZaprosRealEl=ZaprosRealEl+" group by NAMENOM, NAMEED, IDNOM ";

		IBQRealEl->SelectSQL->Clear();
        IBQRealEl->SelectSQL->Add(ZaprosRealEl);
        IBQRealEl->ParamByName("PARAM_POSNACH")->AsDateTime=pos_nach;
        IBQRealEl->ParamByName("PARAM_POSCON")->AsDateTime=pos_con;
        IBQRealEl->Active=true;
        IBQRealEl->First();

        while(!IBQRealEl->Eof)
                {
        numCol=2;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        //сумма
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
      //  prForm->F1->SetPattern(1,clSilver,clSilver);
      //  prForm->F1->SetAlignment( 4, 0, 2, 0);
		cell->Style->Font->FontColor = 48;
		if ( IBQRealElSEBREAL->AsFloat!=0)
			{
			cell->Text="Сумма реализации: "+FloatToStrF(IBQRealElSUMREAL->AsFloat,ffFixed,10,2)
						+"; Себестоимость: "+FloatToStrF(IBQRealElSEBREAL->AsFloat,ffFixed,10,2)
						+"; Результат: "+FloatToStrF(IBQRealElRESREAL->AsFloat,ffFixed,10,2)
						+"; Наценка: "+FloatToStrF(IBQRealElRESREAL->AsFloat/(IBQRealElSEBREAL->AsFloat/100),ffFixed,10,0)+"%";
			 }
		else
			{
			cell->Text="Сумма реализации: "+FloatToStrF(IBQRealElSUMREAL->AsFloat,ffFixed,10,2)
						+"; Себестоимость: "+FloatToStrF(IBQRealElSEBREAL->AsFloat,ffFixed,10,2)
						+"; Результат: "+FloatToStrF(IBQRealElRESREAL->AsFloat,ffFixed,10,2)
						+"; Наценка: --- %"; 
			}
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;


       //prForm->F1->SetPattern(1,clSilver,clSilver);
        numCol++;


       // prForm->F1->SetPattern(1,clSilver,clSilver);
        numCol++;


       // prForm->F1->SetPattern(1,clSilver,clSilver);
        numCol++;


       // prForm->F1->SetPattern(1,clSilver,clSilver);
        numCol++;


        //prForm->F1->SetPattern(1,clSilver,clSilver);
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        //prForm->F1->SetPattern(1,clSilver,clSilver);
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        numRow++;
                IBQRealEl->Next();
                }


}
//------------------------------------------------------------------------------------------------
void TFormaReportVipuskProd::OutputStringRealProdPodval(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
        numCol=2;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        //сумма
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
      //  prForm->F1->SetAlignment( 4, 0, 2, 0);
		cell->Style->Font->FontColor = 48;
		if( RegRealSebReal!=0)
			{
			cell->Text="Сумма реализации: "+FloatToStrF(RegRealSumReal,ffFixed,10,2)
						+"; Себестоимость: "+FloatToStrF(RegRealSebReal,ffFixed,10,2)
						+"; Результат: "+FloatToStrF(RegRealResReal,ffFixed,10,2)
						+"; Наценка: "+FloatToStrF(RegRealResReal/(RegRealSebReal/100),ffFixed,10,0)+"%";
			}
		else
			{
			cell->Text="Сумма реализации: "+FloatToStrF(RegRealSumReal,ffFixed,10,2)
						+"; Себестоимость: "+FloatToStrF(RegRealSebReal,ffFixed,10,2)
						+"; Результат: "+FloatToStrF(RegRealResReal,ffFixed,10,2)
						+"; Наценка: --- %";
			}
		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;


        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;

        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=14;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        numRow++;

}
//--------------------------------------------------------------------------------




void __fastcall TFormaReportVipuskProd::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepVipProd");
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportVipuskProd::cxButtonCreateClick(TObject *Sender)
{
numRow=1;
numCol=1;

TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

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


void __fastcall TFormaReportVipuskProd::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
		TypePrice->First();
		TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
		IdTypePrice=TypePriceID_TPRICE->AsInt64;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportVipuskProd::NameNomEditPropertiesButtonClick(
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

void __fastcall TFormaReportVipuskProd::NameSkladEditPropertiesButtonClick(
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

void __fastcall TFormaReportVipuskProd::NameFirmEditPropertiesButtonClick(
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
//Внешние модули
void __fastcall TFormaReportVipuskProd::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportVipuskProd::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportVipuskProd::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

