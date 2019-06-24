//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportResultReal.h"
#include "IDMSprPrice.h"
#include "IFormaReportGrid.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxDBEdit"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDialogaReportResultReal::TFormaDialogaReportResultReal(TComponent* Owner)
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
void __fastcall TFormaDialogaReportResultReal::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaDialogaReportResultReal::Init(void)
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
IBQ->Database=DM_Connection->pFIBData;
IBQDoc->Database=DM_Connection->pFIBData;


DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";

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

SumOtrSebRealGrp=0;
NumStrGrp=0;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDialogaReportResultRealImpl),false);
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
int  TFormaDialogaReportResultReal::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDialogaReportResultReal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokGrpNom)SpisokGrpNom->kanRelease();
if(SpisokNom)SpisokNom->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

IBQ->Active=false;
TypePrice->Active=false;
IBQDoc->Active=false;

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ViborNom;
        SpisokNom->IdNom=IdNom;
        SpisokNom->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::OpenFormSpiskaSprFirm(void)
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
void TFormaDialogaReportResultReal::OpenFormSpiskaSprGrpNom(void)
{
if (SpisokGrpNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&SpisokGrpNom);
		SpisokGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokGrpNom->Vibor=true;
		SpisokGrpNom->NumberProcVibor=ViborGrpNom;
        SpisokGrpNom->UpdateForm();
		}
}
//---------------------------------------------------------------------------
int TFormaDialogaReportResultReal::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
                }
        SpisokFirm=0;
        }

if (number_procedure_end==ViborGrpNom)
        {
		if (type_event==1)
                {
				IdGrpNom=SpisokGrpNom->DMGrp->ElementIDGN->AsInt64;
                NameGrpNomEdit->Text=SpisokGrpNom->DMGrp->ElementNAMEGN->AsString;
                IdNom=0;
                NameNomEdit->Text="";
                }
        SpisokGrpNom=0;
        }


if (number_procedure_end==ViborNom)
        {
		if (type_event==1)
                {
                IdNom=glStrToInt64(SpisokNom->DM->TableIDNOM->AsString);
                NameNomEdit->Text=SpisokNom->DM->TableNAMENOM->AsString;
                IdGrpNom=0;
                NameGrpNomEdit->Text="";
                }
        SpisokNom=0;
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


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportResultReal::OpenFormSpiskaSprSklad(void)
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

void TFormaDialogaReportResultReal::NewCreateReport(void)
{

if (DocCheckBox->Checked==true && IdNom==0)
        {
		UnicodeString V="Не выбрана номенклатура! Для построения отчета потребуется время. Продолжить?";
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

PrintForm->SS->BeginUpdate();

NewOutputZagolovokReport(PrintForm);
NewCreateReportResultReal(PrintForm);
NewOutputPodavalReport(PrintForm);

PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//----------------------------------------------------------------------------
AnsiString TFormaDialogaReportResultReal::GetTextQuery(void)
{
AnsiString zapros="";
zapros=zapros+"select  sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED,";
zapros=zapros+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,";
zapros=zapros+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,";
zapros=zapros+" SUM(RESREAL_RGREAL_DV)  AS RESREAL,";
zapros=zapros+" SUM(KOL_RGREAL_DV)  AS KOLREAL,";
zapros=zapros+" SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL";
zapros=zapros+" from  RGREAL_DV";
zapros=zapros+" left outer join sfirm on rgreal_dv.idfirm_rgreal_dv=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.idsklad";
zapros=zapros+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM";
zapros=zapros+" left outer join SGRPNOM on IDGRPNOM=IDGN";
zapros=zapros+" left outer join SED on IDBASEDNOM=IDED";

zapros=zapros+" where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON)";

        if (IdFirm!=0)
                {
                zapros=zapros+" and  IDFIRM_RGREAL_DV="+IntToStr(IdFirm);
                }

        if (IdSkl!=0)
                {
                zapros=zapros+" and  IDSKLAD_RGREAL_DV="+IntToStr(IdSkl);
                }

        if (IdGrpNom!=0)
                {
                zapros=zapros+" and  sgrpnom.idgn="+IntToStr(IdGrpNom);;
                }

        if (IdNom!=0)
                {
                zapros=zapros+" and  IDNOM_RGREAL_DV="+IntToStr(IdNom);
                }

        if (OnlyCheckBox->Checked==true)
                {
                zapros=zapros+" and  TNOM="+IntToStr(TypeNomComboBox->ItemIndex);
                }

        if (OnlyOperationCheckBox->Checked==true)
                {
                zapros=zapros+" and  OPER_RGREAL_DV="+IntToStr(OperationComboBox->ItemIndex);
                }

zapros=zapros+" group by sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED";

return zapros;
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewCreateReportResultReal(TSheetEditor *prForm)
{
IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(GetTextQuery());
IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
IBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
IBQ->Active=true;


IBQ->First();

IdTecFirm=0;//IBQIDFIRM->AsInteger;
//num_row_firm=numRow;
//NewOutputStringFirm(prForm);


IdTecSklad=0;//IBQIDSKLAD->AsInteger;
//num_row_sklad=numRow;
//NewOutputStringSklad(prForm);


IdTecGrpNom=0;//;IBQIDGN->AsInteger;
//num_row_grp_nom=numRow;
//NewOutputStringGrpNom(prForm);


SumRealReport=0;
SebRealReport=0;
ResRealReport=0;
OtrSebRealReport=0;

SumRealFirm=0;
SebRealFirm=0;
ResRealFirm=0;
OtrSebRealFirm=0;

SumRealSklad=0;
SebRealSklad=0;
ResRealSklad=0;
OtrSebRealSklad=0;

SumRealGrpNom=0;
SebRealGrpNom=0;
ResRealGrpNom=0;
OtrSebRealGrpNom=0;

                while(!IBQ->Eof)
                        {
                        //фирма
						if (IBQIDFIRM->AsInt64==IdTecFirm)
                                {   //эта же фирма
                                SumRealFirm=SumRealFirm+IBQSUMREAL->AsFloat;
                                SebRealFirm=SebRealFirm+IBQSEBREAL->AsFloat;
                                ResRealFirm=ResRealFirm+IBQRESREAL->AsFloat;
                                }
                        else
                                {
                                NewOutputStringItogiFirm(prForm);
                                OtrSebRealFirm=0;

                                NewOutputStringFirm(prForm);
								IdTecFirm=IBQIDFIRM->AsInt64;
                                IdTecSklad=0;
                                IdTecGrpNom=0;

                                SumRealFirm=IBQSUMREAL->AsFloat;
                                SebRealFirm=IBQSEBREAL->AsFloat;
                                ResRealFirm=IBQRESREAL->AsFloat;

                                }

                        //склад
						if (IBQIDSKLAD->AsInt64==IdTecSklad)
                                {   //эта же склад
                                SumRealSklad=SumRealSklad+IBQSUMREAL->AsFloat;
                                SebRealSklad=SebRealSklad+IBQSEBREAL->AsFloat;
                                ResRealSklad=ResRealSklad+IBQRESREAL->AsFloat;
                                }
                        else
                                {
                                NewOutputStringItogiSklad(prForm);
                                OtrSebRealSklad=0;


                                NewOutputStringSklad(prForm);
                                //NewOutputStringGrpNom(prForm);

								IdTecSklad=IBQIDSKLAD->AsInt64;
                                IdTecGrpNom=0;
                                
                                SumRealSklad=IBQSUMREAL->AsFloat;
                                SebRealSklad=IBQSEBREAL->AsFloat;
                                ResRealSklad=IBQRESREAL->AsFloat;

                                }

                        //группа номенклатуры
						if (IBQIDGN->AsInt64==IdTecGrpNom)
                                {   //этот же группа
                                SumRealGrpNom=SumRealGrpNom+IBQSUMREAL->AsFloat;
                                SebRealGrpNom=SebRealGrpNom+IBQSEBREAL->AsFloat;
                                ResRealGrpNom=ResRealGrpNom+IBQRESREAL->AsFloat;
                                }
                        else
                                {

                                NewOutputStringItogiGrpNom(prForm);
                                OtrSebRealGrpNom=0;

                                NewOutputStringGrpNom(prForm);
								IdTecGrpNom=IBQIDGN->AsInt64;

                                SumRealGrpNom=IBQSUMREAL->AsFloat;
                                SebRealGrpNom=IBQSEBREAL->AsFloat;
                                ResRealGrpNom=IBQRESREAL->AsFloat;
                                }


                        NewOutputStringNom(prForm);

                        SumRealReport=SumRealReport+IBQSUMREAL->AsFloat;
                        SebRealReport=SebRealReport+IBQSEBREAL->AsFloat;
                        ResRealReport=ResRealReport+IBQRESREAL->AsFloat;
                     //   OtrSebRealReport=SumRealReport+IBQNACHOSTSUM->AsFloat;

                        if (DocCheckBox->Checked==true)
                                {
                                CreateReportDoc(prForm);
                                }

                        porNumStrGrp++;
                        porNumStr++;
                        IBQ->Next();
                        }

NewOutputStringItogiFirm(prForm);
NewOutputStringItogiSklad(prForm);
NewOutputStringItogiGrpNom(prForm);

IBQ->Active=false;
}
//---------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 70;
        cHeader->Size[4] = 50;
        cHeader->Size[5] = 100;
        cHeader->Size[6] = 100;
        cHeader->Size[7] = 100;
        cHeader->Size[8] = 50;
        cHeader->Size[9] = 70;
        cHeader->Size[10] = 70;
        cHeader->Size[11] = 70;
numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Реализация товаров и услуг  "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        if (OnlyCheckBox->Checked==true)
                {
                switch (TypeNomComboBox->ItemIndex)
                        {
                        case 0:
                                {
                                cell->Text ="Только товары";
                                break;
                                }
                        case 1:
                                {
                                cell->Text ="Только услуги";
                                break;
                                }
                        case 2:
                                {
                                cell->Text ="Только продукция";
                                break;
                                }


                        }
                }
        else
                {
                cell->Text ="Все типы номенклатур";
                }
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        if (OnlyOperationCheckBox->Checked==true)
                {
                switch (OperationComboBox->ItemIndex)
                        {
                        case 0:
                                {
                                cell->Text ="Операции движения: прочее (0)";
                                break;
                                }
                        case 1:
                                {
                                cell->Text ="Операции движения: Розничная торговля (1)";
                                break;
                                }
                        case 2:
                                {
                                cell->Text ="Операции движения: Розничная торговля в кредит(2)";
                                break;
                                }
                        case 3:
                                {
                                cell->Text ="Операции движения: Оптовая торговля  (3)";
                                break;
                                }
                        }
                }
        else
                {
                cell->Text ="Все операции";
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

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->WordBreak = true;
cell->Text = "Номенклатура";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//количество
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//единица
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Ед.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//себестоимость
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Себестоим.";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//срезультат
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Результат";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "%";
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол. отр.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол. -";
cell->Style->Font->Size = 12;
cell->Style->Font->FontColor=2;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//цена отр.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена -";
cell->Style->Font->Size = 12;
cell->Style->Font->FontColor=2;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//Сумма -
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма -";
cell->Style->Font->Size = 12;
cell->Style->Font->FontColor=2;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
	}
numRow++;



}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringFirm(TSheetEditor *prForm)
{
num_row_firm=numRow;

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
cell->Text ="Фирма: "+ IBQNAMEFIRM->AsString;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haLEFT;;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//рез
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
	}
numRow++;



}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringItogiFirm(TSheetEditor *prForm)
{
if (num_row_firm==0) return;
TcxSSCellObject *cell;
if(SumRealFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(SumRealFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SebRealFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(SebRealFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ResRealFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_firm);
        cell->Text = FloatToStrF(ResRealFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(OtrSebRealFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(11, num_row_firm);
        cell->Text = FloatToStrF(OtrSebRealFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringSklad(TSheetEditor *prForm)
{
num_row_sklad=numRow;

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

//склад
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Склад: "+IBQNAMESKLAD->AsString;
cell->Style->Font->Size = 16;
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
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//рез
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//цена
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=34;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
	}
numRow++;

}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringItogiSklad(TSheetEditor *prForm)
{
if (num_row_sklad==0) return;
TcxSSCellObject *cell;
if(SumRealSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
        cell->Text = FloatToStrF(SumRealSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SebRealSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_sklad);
        cell->Text = FloatToStrF(SebRealSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ResRealSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_sklad);
        cell->Text = FloatToStrF(ResRealSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(OtrSebRealSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(11, num_row_sklad);
        cell->Text = FloatToStrF(OtrSebRealSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_sklad] = 30;


}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringGrpNom(TSheetEditor *prForm)
{
num_row_grp_nom=numRow;

TcxSSCellObject *cell;
numCol=1;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
///cell->Text = IntToStr(porNumKlient);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//группа номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEGN->AsString;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//себ
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//рез
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//цена-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//сумма-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Brush->BackgroundColor=14;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
	}
numRow++;



}
//-----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringItogiGrpNom(TSheetEditor *prForm)
{
if (num_row_grp_nom==0) return;
TcxSSCellObject *cell;
if(SumRealGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
        cell->Text = FloatToStrF(SumRealGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SebRealGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_nom);
        cell->Text = FloatToStrF(SebRealGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ResRealGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(7, num_row_grp_nom);
        cell->Text = FloatToStrF(ResRealGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(OtrSebRealGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(11, num_row_grp_nom);
        cell->Text = FloatToStrF(OtrSebRealGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringNom(TSheetEditor *prForm)
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
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQKOLREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQKOLREAL->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEED->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQSUMREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQSUMREAL->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//результ.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQSEBREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQSEBREAL->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//рез
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQRESREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQRESREAL->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQSEBREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF((IBQRESREAL->AsFloat/(IBQSEBREAL->AsFloat)*100),ffFixed,10,0)+"%";
        }

cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQKOLOTRREAL->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQKOLOTRREAL->AsFloat, ffFixed, 10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


float Price=0;
float OtrSeb=0;
if(IdTypePrice!=0 && IBQKOLOTRREAL->AsFloat!=0)
        {
		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
        if (DMSprPrice->FindElement(IdTypePrice,IBQIDNOM->AsInteger)>0)
                {
                Price=DMSprPrice->ElementZNACH_PRICE->AsFloat;
                OtrSeb=Price*IBQKOLOTRREAL->AsFloat;
                }
        DMSprPrice->kanRelease();
        }
//цена-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (OtrSeb!=0)
        {
        cell->Text = FloatToStrF(Price,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (Price!=0)
        {
        cell->Text = FloatToStrF(OtrSeb,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
if (DocCheckBox->Checked==true)
        {
        cell->Style->Font->Style = TFontStyles() << fsBold;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


OtrSebRealFirm=OtrSebRealFirm+OtrSeb;
OtrSebRealSklad=OtrSebRealSklad+OtrSeb;
OtrSebRealGrpNom=OtrSebRealGrpNom+OtrSeb;
OtrSebRealReport=OtrSebRealReport+OtrSeb;
}
numRow++;


}
//---------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
//порядковый номер строки
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
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

//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(AllNachOst, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(AllPrihod, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SumRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//себ.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(SebRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//себ.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(ResRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(ResRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(ResRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//цена-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//cell->Text = FloatToStrF(ResRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
//сумма-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(OtrSebRealReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
cell->Style->Font->FontColor=2;
delete cell;
numCol++;
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportResultReal::Button1Click(
      TObject *Sender)
{
NewCreateReport();        
}
//---------------------------------------------------------------------------




AnsiString TFormaDialogaReportResultReal::GetTextZaprosDoc(void)
{
AnsiString zapros="";
zapros=zapros+" select  rgreal_dv.kol_rgreal_dv,";
zapros=zapros+" rgreal_dv.sumreal_rgreal_dv,";
zapros=zapros+" rgreal_dv.sebreal_rgreal_dv,";
zapros=zapros+" rgreal_dv.resreal_rgreal_dv,";
zapros=zapros+" rgreal_dv.kolotr_rgreal_dv,";
zapros=zapros+" galldoc.posdoc, galldoc.numdoc, galldoc.tdoc";
zapros=zapros+" from rgreal_dv";
zapros=zapros+" left outer join galldoc on rgreal_dv.iddoc_rgreal_dv=galldoc.iddoc";

zapros=zapros+" where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON)";
zapros=zapros+" and rgreal_dv.idnom_rgreal_dv='"+IBQIDNOM->AsString+"'";
zapros=zapros+" and  IDFIRM_RGREAL_DV='"+IBQIDFIRM->AsString+"'";
zapros=zapros+" and  IDSKLAD_RGREAL_DV='"+IBQIDSKLAD->AsString+"'";

zapros=zapros+" order by galldoc.posdoc";

return zapros;
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::CreateReportDoc(TSheetEditor *prForm)
{
IBQDoc->Active=false;
IBQDoc->SelectSQL->Clear();
IBQDoc->SelectSQL->Add(GetTextZaprosDoc());
IBQDoc->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
IBQDoc->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
IBQDoc->Active=true;

IBQDoc->First();

while(!IBQDoc->Eof)
        {
        NewOutputStringDoc(prForm);
        IBQDoc->Next();
        }

IBQDoc->Active=false;
}
//-----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::NewOutputStringDoc(TSheetEditor *prForm)
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
//номенлатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(IBQDocTDOC->AsString)+" №"+
                IBQDocNUMDOC->AsString+" от "+
                IBQDocPOSDOC->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//кол
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDocKOL_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQDocKOL_RGREAL_DV->AsFloat,ffFixed,10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//ед
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEED->AsString;
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDocSUMREAL_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQDocSUMREAL_RGREAL_DV->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//результ.
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDocSEBREAL_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQDocSEBREAL_RGREAL_DV->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//рез
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDocRESREAL_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQDocRESREAL_RGREAL_DV->AsFloat, ffFixed, 10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//процент
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if(IBQDocSEBREAL_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF((IBQDocRESREAL_RGREAL_DV->AsFloat/(IBQDocSEBREAL_RGREAL_DV->AsFloat)*100),ffFixed,10,0)+"%";
        }

cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
if (cxCheckBoxVisibleOtrOst->Checked==true)
	{
//кол-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQDocKOLOTR_RGREAL_DV->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQDocKOLOTR_RGREAL_DV->AsFloat, ffFixed, 10,3);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;


float Price=0;
float OtrSeb=0;
if(IdTypePrice!=0 && IBQDocKOLOTR_RGREAL_DV->AsFloat!=0)
        {
		IDMSprPrice * DMSprPrice;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
		DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
        if (DMSprPrice->FindElement(IdTypePrice,IBQIDNOM->AsInt64)>0)
                {
                Price=DMSprPrice->ElementZNACH_PRICE->AsFloat;
                OtrSeb=Price*IBQDocKOLOTR_RGREAL_DV->AsFloat;
                }
		DMSprPrice->kanRelease();
        }
//цена-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (OtrSeb!=0)
        {
        cell->Text = FloatToStrF(Price,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//сумма-
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (Price!=0)
        {
        cell->Text = FloatToStrF(OtrSeb,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->FontColor=2;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
	}
numRow++;


}
//-----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportResultReal::ActionOpenHelpExecute(
      TObject *Sender)
{
Application->HelpJump("ReportResReal");
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportResultReal::NameFirmEditPropertiesButtonClick(
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

void __fastcall TFormaDialogaReportResultReal::NameSkladEditPropertiesButtonClick(
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


void __fastcall TFormaDialogaReportResultReal::NameGrpNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();
		}break;
	case 1:
		{
		IdGrpNom=0;
		NameGrpNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::NameNomEditPropertiesButtonClick(
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



void __fastcall TFormaDialogaReportResultReal::cxButtonCreateReportClick(
      TObject *Sender)
{
NewCreateReport();	
}
//---------------------------------------------------------------------------






void __fastcall TFormaDialogaReportResultReal::DateNachKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::DateConKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportResultReal::OnlyCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::OnlyOperationCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::DocCheckBoxKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportResultReal::TypeNomComboBoxPropertiesChange(
      TObject *Sender)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::OperationComboBoxPropertiesChange(
      TObject *Sender)
{
FindNextControl(ActiveControl,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
TypePrice->First();
TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
IdTypePrice=TypePriceID_TPRICE->AsInt64;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDialogaReportResultReal::cxCheckBoxVisibleOtrOstKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDialogaReportResultReal::cxButtonCreateReportGridClick(
	  TObject *Sender)
{
IFormaReportGrid * f;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaReportGrid.1",IID_IFormaReportGrid,
													(void**)&f);
f->Init(InterfaceMainObject,InterfaceImpl);
AnsiString zapros="";
zapros=zapros+"select  sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED,";
zapros=zapros+" SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,";
zapros=zapros+" SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,";
zapros=zapros+" SUM(RESREAL_RGREAL_DV)  AS RESREAL,";
zapros=zapros+" SUM(KOL_RGREAL_DV)  AS KOLREAL,";
zapros=zapros+" SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL";
zapros=zapros+" from  RGREAL_DV";
zapros=zapros+" left outer join sfirm on rgreal_dv.idfirm_rgreal_dv=sfirm.idfirm";
zapros=zapros+" left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.idsklad";
zapros=zapros+" left outer join SNOM on IDNOM_RGREAL_DV=IDNOM";
zapros=zapros+" left outer join SGRPNOM on IDGRPNOM=IDGN";
zapros=zapros+" left outer join SED on IDBASEDNOM=IDED";

zapros=zapros+" where POSDOC_RGREAL_DV  between '"+DateTimeToStr(DateNach->Date)+"' and '"+DateTimeToStr(DateCon->Date)+"'";

        if (IdFirm!=0)
                {
                zapros=zapros+" and  IDFIRM_RGREAL_DV="+IntToStr(IdFirm);
                }

        if (IdSkl!=0)
                {
                zapros=zapros+" and  IDSKLAD_RGREAL_DV="+IntToStr(IdSkl);
                }

        if (IdGrpNom!=0)
                {
                zapros=zapros+" and  sgrpnom.idgn="+IntToStr(IdGrpNom);;
                }

        if (IdNom!=0)
                {
                zapros=zapros+" and  IDNOM_RGREAL_DV="+IntToStr(IdNom);
                }

        if (OnlyCheckBox->Checked==true)
                {
                zapros=zapros+" and  TNOM="+IntToStr(TypeNomComboBox->ItemIndex);
                }

        if (OnlyOperationCheckBox->Checked==true)
                {
                zapros=zapros+" and  OPER_RGREAL_DV="+IntToStr(OperationComboBox->ItemIndex);
                }

zapros=zapros+" group by sfirm.namefirm, sfirm.idfirm,";
zapros=zapros+" ssklad.namesklad, ssklad.idsklad,";
zapros=zapros+" sgrpnom.namegn, sgrpnom.idgn,";
zapros=zapros+" NAMENOM, IDNOM, TNOM,";
zapros=zapros+" NAMEED";

f->SetTextQuery(zapros);

f->AddColumn("NAMEFIRM","Фирма",200,0,false,"",false,"");
f->AddColumn("NAMESKLAD","Склад",200,1,false,"",false,"");
f->AddColumn("NAMEGN","Группа",200,3,false,"",false,"");
f->AddColumn("NAMENOM","Номенклатура",200,-1,false,"",false,"");
f->AddColumn("KOLREAL","Кол.",50,-1,false,"",false,"");
f->AddColumn("NAMEED","Единица",50,-1,false,"",false,"");
f->AddColumn("SUMREAL","Сумма реал.",50,-1,true,"$,0.00",true,"$,0.00");
f->AddColumn("SEBREAL","Себестоимость",50,-1,true,"$,0.00",true,"$,0.00");
f->AddColumn("RESREAL","Сумма дохода",50,-1,true,"$,0.00",true,"$,0.00");
//f->AddColumn("NACENKA","Наценка (%)",50,-1,false,"$,0.00",false,"$,0.00");

f->CreateSeries("SUMREAL", "Сум. реал.");
f->CreateSeries("SEBREAL", "Себест.");
f->CreateSeries("RESREAL", "Доход");
f->AddDataGroups("NAMEFIRM","Фирма");
f->AddDataGroups("NAMESKLAD","Склад");
f->AddDataGroups("NAMEGN","Группа");
f->AddDataGroups("NAMENOM","Номенклатура");

f->OpenReport();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDialogaReportResultReal::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdGrpNom", IdGrpNom);
	module->SetInt64Variables("glIdNom", IdNom);
	module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportResultReal::ActionCloseExecute(TObject *Sender)

{
Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaDialogaReportResultReal::OpenFormSpiskaSprProject(void)
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
void  TFormaDialogaReportResultReal::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaDialogaReportResultReal::OpenFormSpiskaSprBusinessOper(void)
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
void TFormaDialogaReportResultReal::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaDialogaReportResultReal::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaDialogaReportResultReal::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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

