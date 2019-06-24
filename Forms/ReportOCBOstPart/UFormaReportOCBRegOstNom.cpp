//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaReportOCBRegOstNom.h"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportOCBRegOstNom::TFormaReportOCBRegOstNom(TComponent* Owner)
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
void __fastcall TFormaReportOCBRegOstNom::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportOCBRegOstNom::Init(void)
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

flObrabatChangeTypePrice=false ;

TypePriceComboBox->Properties->Items->Clear();
TypePrice->First();
while (!TypePrice->Eof)
        {
		TypePriceComboBox->Properties->Items->Add(TypePriceNAME_TPRICE->AsString);
        TypePrice->Next();
        }
IdTypePrice=0;


NumStrGrp=0;
flObrabatChangeTypePrice=true;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportOCBRegOstNomImpl),false);
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
int  TFormaReportOCBRegOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegOstNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm) SpisokFirm->kanRelease();
if(SpisokGrpNom) SpisokGrpNom->kanRelease();
if(SpisokNom) SpisokNom->kanRelease();
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
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprNom(void)
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
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
	SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
	SpisokFirm->Vibor=true;
	SpisokFirm->NumberProcVibor=ViborFirm;
	}
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprGrpNom(void)
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
int TFormaReportOCBRegOstNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprSklad(void)
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








void TFormaReportOCBRegOstNom::CreateReport(void)
{


TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;

porNumStrGrp=1;
//PrintForm->Visible=false;
FormIndicator=new TFormIndicator(Application);
FormIndicator->LabelInfo->Caption="Выполнение запроса...";
FormIndicator->Caption="Выполнение запроса...";
FormIndicator->Show();
//PrintForm->SS->Visible=false;
PrintForm->SS->BeginUpdate();

OutputZagolovokReport(PrintForm);
CreateReportOCB(PrintForm);
OutputPodavalReport(PrintForm);

PrintForm->SS->EndUpdate();
delete FormIndicator;
//PrintForm->SS->Visible=true;
PrintForm->Show();
}
//----------------------------------------------------------------------------
AnsiString TFormaReportOCBRegOstNom::GetTextQuery(void)
{
AnsiString zapros="";

if (PriceCheckBox->Checked==true)
        {
        zapros=zapros+" select  *";
        zapros=zapros+" from  OCB_RGOSTNOM_FULL_ROZNPRICE (:PARAM_POSNACH, :PARAM_POSCON, :PARAM_IDFIRM, :PARAM_IDSKLAD, :PARAM_IDGRP, :PARAM_IDNOM, :PARAM_IDTPRICE)";
        }
else
        {
        zapros=zapros+" select  *";
        zapros=zapros+" from  OCB_RGOSTNOM_FULL_REPORT  (:PARAM_POSNACH, :PARAM_POSCON, :PARAM_IDFIRM, :PARAM_IDSKLAD, :PARAM_IDGRP, :PARAM_IDNOM)";
        }

return zapros;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::CreateReportOCB(TSheetEditor *prForm)
{
if (DocDvcxCheckBox->Checked==true && IdNom==0)
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


IBQ->Active=false;
IBQ->SelectSQL->Clear();
IBQ->SelectSQL->Add(GetTextQuery());
IBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
IBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
IBQ->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
IBQ->ParamByName("PARAM_IDSKLAD")->AsInt64=IdSkl;
IBQ->ParamByName("PARAM_IDGRP")->AsInt64=IdGrpNom;
IBQ->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;

if (PriceCheckBox->Checked==true)
        {
		IBQ->ParamByName("PARAM_IDTPRICE")->AsInt64=IdTypePrice;
        }

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

IdTecNom=0;

NachOstReport=0;
PrihodReport=0;
RashodReport=0;
ConOstReport=0;

NachOstFirm=0;
PrihodFirm=0;
RashodFirm=0;
ConOstFirm=0;

NachOstSklad=0;
PrihodSklad=0;
RashodSklad=0;
ConOstSklad=0;

NachOstGrpNom=0;
PrihodGrpNom=0;
RashodGrpNom=0;
ConOstGrpNom=0;

FormIndicator->Max=IBQ->RecordCount;
FormIndicator->Step=1;
FormIndicator->LabelInfo->Caption="Построение печатной формы...";
FormIndicator->Caption="Построение печатной формы...";
FormIndicator->Start();

                while(!IBQ->Eof)
						{

                        //фирма
						if (IBQIDFIRM_PROC->AsInt64==IdTecFirm)
                                {   //эта же фирма
                                NachOstFirm=NachOstFirm+IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodFirm=PrihodFirm+IBQPRIHODSUM_PROC->AsFloat;
                                RashodFirm=RashodFirm+IBQRASHODSUM_PROC->AsFloat;
                                ConOstFirm=ConOstFirm+IBQCONOSTSUM_PROC->AsFloat;

                                }
                        else
                                {
                                OutputStringItogiFirm(prForm);
                                OutputStringFirm(prForm);
								IdTecFirm=IBQIDFIRM_PROC->AsInt64;
                                IdTecSklad=0;
                                IdTecGrpNom=0;
                                IdTecNom=0;

                                NachOstFirm=IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodFirm=IBQPRIHODSUM_PROC->AsFloat;
                                RashodFirm=IBQRASHODSUM_PROC->AsFloat;
                                ConOstFirm=IBQCONOSTSUM_PROC->AsFloat;
                                }

                        //склад
						if (IBQIDSKLAD_PROC->AsInt64==IdTecSklad)
                                {   //эта же склад
                                NachOstSklad=NachOstSklad+IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodSklad=PrihodSklad+IBQPRIHODSUM_PROC->AsFloat;
                                RashodSklad=RashodSklad+IBQRASHODSUM_PROC->AsFloat;
                                ConOstSklad=ConOstSklad+IBQCONOSTSUM_PROC->AsFloat;
                                }
                        else
                                {
                                OutputStringItogiSklad(prForm);


                                OutputStringSklad(prForm);
                                //NewOutputStringGrpNom(prForm);

								IdTecSklad=IBQIDSKLAD_PROC->AsInt64;
                                IdTecGrpNom=0;
                                IdTecNom=0;
                                
                                NachOstSklad=IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodSklad=IBQPRIHODSUM_PROC->AsFloat;
                                RashodSklad=IBQRASHODSUM_PROC->AsFloat;
                                ConOstSklad=IBQCONOSTSUM_PROC->AsFloat;

                                }

                        //группа номенклатуры
                        if (IBQIDGRP_PROC->AsInt64==IdTecGrpNom)
                                {   //этот же группа
                                NachOstGrpNom=NachOstGrpNom+IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodGrpNom=PrihodGrpNom+IBQPRIHODSUM_PROC->AsFloat;
                                RashodGrpNom=RashodGrpNom+IBQRASHODSUM_PROC->AsFloat;
                                ConOstGrpNom=ConOstGrpNom+IBQCONOSTSUM_PROC->AsFloat;
                                }
                        else
                                {

                                OutputStringItogiGrpNom(prForm);


                                OutputStringGrpNom(prForm);
								IdTecGrpNom=IBQIDGRP_PROC->AsInt64;
                                IdTecNom=0;

                                NachOstGrpNom=IBQNACHOSTSUM_PROC->AsFloat;
                                PrihodGrpNom=IBQPRIHODSUM_PROC->AsFloat;
                                RashodGrpNom=IBQRASHODSUM_PROC->AsFloat;
                                ConOstGrpNom=IBQCONOSTSUM_PROC->AsFloat;
                                }

                        //группа номенклатуры
                        if (IBQIDNOM_PROC->AsInt64==IdTecNom)
                                {   //этот же группа
                                SumNachOstNom=SumNachOstNom+IBQNACHOSTSUM_PROC->AsFloat;
                                SumPrihodNom=SumPrihodNom+IBQPRIHODSUM_PROC->AsFloat;
                                SumRashodNom=SumRashodNom+IBQRASHODSUM_PROC->AsFloat;
                                SumConOstNom=SumConOstNom+IBQCONOSTSUM_PROC->AsFloat;
                                KolNachOstNom=KolNachOstNom+IBQNACHOSTKOL_PROC->AsFloat;
                                KolPrihodNom=KolPrihodNom+IBQPRIHODKOL_PROC->AsFloat;
                                KolRashodNom=KolRashodNom+IBQRASHODKOL_PROC->AsFloat;
                                KolConOstNom=KolConOstNom+IBQCONOSTKOL_PROC->AsFloat;
                                }
                        else
                                {

                                OutputStringItogiNom(prForm);


                                OutputStringNom(prForm);
                                IdTecNom=IBQIDNOM_PROC->AsInt64;

                                SumNachOstNom=IBQNACHOSTSUM_PROC->AsFloat;
                                SumPrihodNom=IBQPRIHODSUM_PROC->AsFloat;
                                SumRashodNom=IBQRASHODSUM_PROC->AsFloat;
                                SumConOstNom=IBQCONOSTSUM_PROC->AsFloat;
                                KolNachOstNom=IBQNACHOSTKOL_PROC->AsFloat;
                                KolPrihodNom=IBQPRIHODKOL_PROC->AsFloat;
                                KolRashodNom=IBQRASHODKOL_PROC->AsFloat;
                                KolConOstNom=IBQCONOSTKOL_PROC->AsFloat;
                                }

                        OutputStringPart(prForm);

                        NachOstReport=NachOstReport+IBQNACHOSTSUM_PROC->AsFloat;
                        PrihodReport=PrihodReport+IBQPRIHODSUM_PROC->AsFloat;
                        RashodReport=RashodReport+IBQRASHODSUM_PROC->AsFloat;
                        ConOstReport=ConOstReport+IBQCONOSTSUM_PROC->AsFloat;
                     //   OtrSebRealReport=SumRealReport+IBQNACHOSTSUM->AsFloat;

                    //    if (DocCheckBox->Checked==true)
                    //            {
                    //            CreateReportDoc(prForm);
					//            }
					
					if (DocDvcxCheckBox->Checked==true)
                                {
								CreateReportDoc(prForm);
								}
                        porNumStrGrp++;
						porNumStr++;
						FormIndicator->StepIt();
                        IBQ->Next();
                        }

OutputStringItogiFirm(prForm);
OutputStringItogiSklad(prForm);
OutputStringItogiGrpNom(prForm);
OutputStringItogiNom(prForm);

IBQ->Active=false;
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputZagolovokReport(TSheetEditor *prForm)
{

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 30;
        cHeader->Size[2] = 200;
        cHeader->Size[3] = 120;
        cHeader->Size[4] = 120;
        cHeader->Size[5] = 120;
        cHeader->Size[6] = 120;

numRow=2;
numCol=1;

TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Остатки и движения партий товаров  "+DateToStr(DateNach->Date)
                        +" по "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;



numRow++;
numRow++;

if (PriceCheckBox->Checked==true)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
        cell->Text = "Тип цен: "+TypePriceComboBox->Text;
        cell->Style->HorzTextAlign = haLEFT;
        cell->Style->Font->Size = 16;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
        delete cell;
        }


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
//нач. остаток
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
//приход
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

//расход
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
//кон. остаток
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
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringFirm(TSheetEditor *prForm)
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

//номенклатура
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text ="Фирма: "+ IBQNAMEFIRM_PROC->AsString;
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
void TFormaReportOCBRegOstNom::OutputStringItogiFirm(TSheetEditor *prForm)
{
if (num_row_firm==0) return;
TcxSSCellObject *cell;
if(NachOstFirm!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_firm);
        cell->Text = FloatToStrF(NachOstFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_firm);
        cell->Text = FloatToStrF(PrihodFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_firm);
        cell->Text = FloatToStrF(RashodFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstFirm!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_firm);
        cell->Text = FloatToStrF(ConOstFirm,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_firm] = 30;

}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringSklad(TSheetEditor *prForm)
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
cell->Text = "Склад: "+IBQNAMESKLAD_PROC->AsString;
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
//кон остаток
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
void TFormaReportOCBRegOstNom::OutputStringItogiSklad(TSheetEditor *prForm)
{
if (num_row_sklad==0) return;
TcxSSCellObject *cell;
if(NachOstSklad!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_sklad);
        cell->Text = FloatToStrF(NachOstSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_sklad);
        cell->Text = FloatToStrF(PrihodSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_sklad);
        cell->Text = FloatToStrF(RashodSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstSklad!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_sklad);
        cell->Text = FloatToStrF(ConOstSklad,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 12;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
prForm->SS->ActiveSheet->Rows->Size[num_row_sklad] = 30;


}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringGrpNom(TSheetEditor *prForm)
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
cell->Text = IBQNAMEGRP_PROC->AsString;
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
//нач. остаток
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
//кон остаток
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
//-----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringItogiGrpNom(TSheetEditor *prForm)
{
if (num_row_grp_nom==0) return;
TcxSSCellObject *cell;
if(NachOstGrpNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_grp_nom);
        cell->Text = FloatToStrF(NachOstGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(PrihodGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_grp_nom);
        cell->Text = FloatToStrF(PrihodGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(RashodGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_grp_nom);
        cell->Text = FloatToStrF(RashodGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(ConOstGrpNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_grp_nom);
        cell->Text = FloatToStrF(ConOstGrpNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringNom(TSheetEditor *prForm)
{
num_row_nom=numRow;
TcxSSCellObject *cell;
numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
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
//номенлатура
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMENOM_PROC->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач лстаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
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
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
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
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
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
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
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



numRow++;
numRow++;

}
//-----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringItogiNom(TSheetEditor *prForm)
{
if (num_row_nom==0) return;
TcxSSCellObject *cell;
if(SumNachOstNom!=0)
        {
		cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_nom);
        cell->Text = FloatToStrF(SumNachOstNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
		cell->Style->Font->Size = 10;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		if (SumNachOstNom<0)
			{
			cell->Style->Font->FontColor=2;
			}
        delete cell;
        }
if(KolNachOstNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(3, num_row_nom+1);
		cell->Text = FloatToStrF(KolNachOstNom,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		if (KolNachOstNom<0)
			{
			cell->Style->Font->FontColor=2;
			}
		delete cell;
        }

if(SumPrihodNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_nom);
        cell->Text = FloatToStrF(SumPrihodNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
if(KolPrihodNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(4, num_row_nom+1);
        cell->Text = FloatToStrF(KolPrihodNom,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }

if(SumRashodNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_nom);
        cell->Text = FloatToStrF(SumRashodNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
if(KolRashodNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(5, num_row_nom+1);
        cell->Text = FloatToStrF(KolRashodNom,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
        cell->Style->Font->Style = TFontStyles() << fsBold;
        delete cell;
        }
if(SumConOstNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_nom);
        cell->Text = FloatToStrF(SumConOstNom,ffFixed,10,2);
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		if (SumConOstNom<0)
			{
			cell->Style->Font->FontColor=2;
			}
        delete cell;
        }
        
if(KolConOstNom!=0)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(6, num_row_nom+1);
		cell->Text = FloatToStrF(KolConOstNom,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        cell->Style->HorzTextAlign = haRIGHT;
        cell->Style->Font->Size = 10;
		cell->Style->Font->Style = TFontStyles() << fsBold;
		if (KolConOstNom<0)
			{
			cell->Style->Font->FontColor=2;
			}
        delete cell;
        }

prForm->SS->ActiveSheet->Rows->Size[num_row_grp_nom] = 20;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom:: OutputStringPart(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
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
//номенлатура
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IBQNAMEPART_PROC->AsString;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 8;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}
	
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//нач лстаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQNACHOSTSUM_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQNACHOSTSUM_PROC->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
if (IBQNACHOSTSUM_PROC->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=24;
	}
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (IBQNACHOSTKOL_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQNACHOSTKOL_PROC->AsFloat,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
if (IBQNACHOSTKOL_PROC->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=24;
	}
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQPRIHODSUM_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQPRIHODSUM_PROC->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (IBQPRIHODKOL_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQPRIHODKOL_PROC->AsFloat,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQRASHODSUM_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQRASHODSUM_PROC->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (IBQRASHODKOL_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQRASHODKOL_PROC->AsFloat,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=24;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
numCol++;
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (IBQCONOSTSUM_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQCONOSTSUM_PROC->AsFloat,ffFixed,10,2);
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
if (IBQCONOSTSUM_PROC->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=24;
	}
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}

delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
if (IBQCONOSTKOL_PROC->AsFloat!=0)
        {
        cell->Text = FloatToStrF(IBQCONOSTKOL_PROC->AsFloat,ffFixed,10,3)+IBQNAMEED_PROC->AsString;
        }
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Size = 8;
if (IBQCONOSTKOL_PROC->AsFloat<0)
	{
	cell->Style->Font->FontColor=2;
	}
else
	{
	cell->Style->Font->FontColor=24;
	}
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;

if ( DocDvcxCheckBox->Checked==true)
	{
	cell->Style->Font->Style = TFontStyles() << fsBold;
	}
	
delete cell;
numCol++;



numRow++;
numRow++;



}
//---------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputPodavalReport(TSheetEditor *prForm)
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

//нач остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(NachOstReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(PrihodReport, ffFixed,15,2);
cell->Style->Font->Size = 12;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThick;
cell->Style->Borders->Edges [eRight]->Style=lsThick;
cell->Style->Borders->Edges [eTop]->Style=lsThick;
cell->Style->Borders->Edges [eBottom]->Style=lsThick;
delete cell;
numCol++;
//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(RashodReport, ffFixed,15,2);
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
//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(ConOstReport, ffFixed,15,2);
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


numCol++;
//prForm->SS->History->Clear();
}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegOstNom::Button1Click(
      TObject *Sender)
{
CreateReport();
}
//---------------------------------------------------------------------------




void __fastcall TFormaReportOCBRegOstNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepOstPartNom");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegOstNom::cxButtonCreateClick(TObject *Sender)
{
CreateReport();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegOstNom::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegOstNom::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
		TypePrice->First();
		TypePrice->MoveBy(TypePriceComboBox->ItemIndex);
		IdTypePrice=TypePriceID_TPRICE->AsInt64;
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegOstNom::NameNomEditPropertiesButtonClick(
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

void __fastcall TFormaReportOCBRegOstNom::NameGrpNomEditPropertiesButtonClick(
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

void __fastcall TFormaReportOCBRegOstNom::NameSkladEditPropertiesButtonClick(
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

void __fastcall TFormaReportOCBRegOstNom::NameFirmEditPropertiesButtonClick(
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
//----------------------------------------------------------------------------
AnsiString TFormaReportOCBRegOstNom::GetTextZaprosDoc(void)
{
AnsiString zapros="";

zapros=zapros+" select rgostnom_dv.posdoc_ostnomdv,       ";
zapros=zapros+"         rgostnom_dv.tdv_ostnomdv,         ";
zapros=zapros+"         galldoc.numdoc,                   ";
zapros=zapros+"         galldoc.tdoc,                     ";
zapros=zapros+"         rgostnom_dv.kol_ostnomdv,         ";
zapros=zapros+"         rgostnom_dv.sum_ostnomdv          ";
zapros=zapros+" from rgostnom_dv                          ";
zapros=zapros+" left outer join galldoc on galldoc.iddoc=rgostnom_dv.iddoc_ostnomdv                 ";
zapros=zapros+" where (rgostnom_dv.posdoc_ostnomdv  between :PARAM_POSNACH and :PARAM_POSCON)       ";
zapros=zapros+"         and rgostnom_dv.idfirm_ostnomdv=:PARAM_IDFIRM                               ";
zapros=zapros+"         and rgostnom_dv.idskl_ostnomdv=:PARAM_IDSKLAD                               ";
zapros=zapros+"         and rgostnom_dv.idnom_ostnomdv=:PARAM_IDNOM                                 ";
if (IBQIDPART_PROC->AsString=="")
	{
	zapros=zapros+"         and rgostnom_dv.idpart_ostnomdv is null                            ";
	}
else
	{
	zapros=zapros+"         and rgostnom_dv.idpart_ostnomdv=:PARAM_IDPART                            ";
	}
zapros=zapros+" order by rgostnom_dv.posdoc_ostnomdv                                                ";
return zapros;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::CreateReportDoc(TSheetEditor *prForm)
{
TecConOstatokPoDocSum=IBQNACHOSTSUM_PROC->AsFloat;
TecConOstatokPoDocKol=IBQNACHOSTKOL_PROC->AsFloat;


InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryReadDoc);
DMQueryReadDoc->Init(InterfaceMainObject,InterfaceImpl);
DMQueryReadDoc->pFIBQ->Close();
DMQueryReadDoc->pFIBQ->SQL->Clear();
DMQueryReadDoc->pFIBQ->SQL->Add(GetTextZaprosDoc());
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=IBQIDFIRM_PROC->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=IBQIDSKLAD_PROC->AsString;
DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=IBQIDNOM_PROC->AsString;
if (IBQIDPART_PROC->AsString=="")
	{

	}
else
	{
    DMQueryReadDoc->pFIBQ->ParamByName("PARAM_IDPART")->AsString=IBQIDPART_PROC->AsString;
	}

DMQueryReadDoc->pFIBQ->ExecQuery();
while(!DMQueryReadDoc->pFIBQ->Eof)
		{
		OutputStringDoc(prForm);
		DMQueryReadDoc->pFIBQ->Next();
        }

DMQueryReadDoc->pFIBQ->Close();
delete  DMQueryReadDoc;
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OutputStringDoc(TSheetEditor *prForm)
{
prForm->SS->ActiveSheet->Rows->Size[numRow]=15;
prForm->SS->ActiveSheet->Rows->Size[numRow+1]=15;

TcxSSCellObject *cell;
numCol=1;
TRect rect;
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
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
//номенлатура
//glGetNameDoc(IBQDocTDOC->AsString)
rect.Left = numCol;
rect.Top = numRow+1;
rect.Right = numCol;
rect.Bottom = numRow;
prForm->SS->ActiveSheet->SetMergedState(rect, true);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = glGetNameDoc(DMQueryReadDoc->pFIBQ->FieldByName("TDOC")->AsString)+"  №"+
				DMQueryReadDoc->pFIBQ->FieldByName("NUMDOC")->AsString+" от "+
				DMQueryReadDoc->pFIBQ->FieldByName("POSDOC_OSTNOMDV")->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->WordBreak = true;
cell->Style->Font->FontColor=10;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
//cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//нач лстаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
//			*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat!=0)
//	{
//	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat
//						*DMQueryRead->pFIBQ->FieldByName("RPRICE_PROC")->AsFloat,ffFixed,10,2);
//	}
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
//	{
//	cell->Style->Font->FontColor=2;
//	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat!=0)
//	{
//	cell->Text = FloatToStrF(DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat,ffFixed,10,3)
//										+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
//	}
//
//if (DMQueryRead->pFIBQ->FieldByName("NACHOSTKOL_PROC")->AsFloat<0)
//	{
//	cell->Style->Font->FontColor=2;
//	}
delete cell;
numCol++;


//приход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_OSTNOMDV")->AsInteger==0)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat,ffFixed,10,2);
		TecConOstatokPoDocSum=TecConOstatokPoDocSum+DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_OSTNOMDV")->AsInteger==0)
	{
	if(DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat,ffFixed,10,3);
									   //	+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
		TecConOstatokPoDocKol=TecConOstatokPoDocKol+DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	cell->Style->HorzTextAlign = haRIGHT;
	}
delete cell;
numCol++;

//расход
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_OSTNOMDV")->AsInteger==1)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat,ffFixed,10,2);
		TecConOstatokPoDocSum=TecConOstatokPoDocSum-DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("SUM_OSTNOMDV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Size = 8;
cell->Style->Font->FontColor=10;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (DMQueryReadDoc->pFIBQ->FieldByName("TDV_OSTNOMDV")->AsInteger==1)
	{
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat!=0)
		{
		cell->Text = FloatToStrF(DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat,ffFixed,10,3);
									   //	+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
		TecConOstatokPoDocKol=TecConOstatokPoDocKol-DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat;
		}
	if (DMQueryReadDoc->pFIBQ->FieldByName("KOL_OSTNOMDV")->AsFloat<0)
		{
		cell->Style->Font->FontColor=2;
		}
	}


delete cell;
numCol++;

//кон остаток
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 8;

if (TecConOstatokPoDocSum!=0)
	{
	cell->Text = FloatToStrF(TecConOstatokPoDocSum,ffFixed,10,2);
	}
if (TecConOstatokPoDocSum<0)
	{
	cell->Style->Font->FontColor=2;
	}
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow+1);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Style->Font->FontColor=10;
cell->Style->Font->Size = 8;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Font->Style = TFontStyles() << fsBold;

if (TecConOstatokPoDocKol!=0)
	{
	cell->Text = FloatToStrF(TecConOstatokPoDocKol,ffFixed,10,3);
										//+DMQueryRead->pFIBQ->FieldByName("NAMEED_PROC")->AsString;
	}
if (TecConOstatokPoDocKol<0)
	{
	cell->Style->Font->FontColor=2;
	}

delete cell;
numCol++;



numRow++;
numRow++;

}
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaReportOCBRegOstNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::RunExternalModule(__int64 id_module, int type_module)
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
void __fastcall TFormaReportOCBRegOstNom::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprProject(void)
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
void  TFormaReportOCBRegOstNom::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportOCBRegOstNom::OpenFormSpiskaSprBusinessOper(void)
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
void TFormaReportOCBRegOstNom::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegOstNom::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TFormaReportOCBRegOstNom::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
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

