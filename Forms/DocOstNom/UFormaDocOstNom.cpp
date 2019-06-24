//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//---------------------------------------------------------------------------
#include "UFormaDocOstNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IFormaRunExternalModule.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
#include "IDMQueryRead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxPC"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocOstNom::TFormaDocOstNom(TComponent* Owner)
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
bool TFormaDocOstNom::Init(void)
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

	//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
	if(InterfaceMainObject)
		{
		IAsyncExternalEvent * interf=0;
		InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
		if (interf)
			{
			interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
			interf->kanRelease();
			}
		}
	}
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstNom.1",IID_IDMDocOstNom,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
												 (void**)&DMSprPrice);
DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM,
												 (void**)&DMSprARM);
DMSprARM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
cxGrid2DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;


Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
		}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);

DMSprTypeRPrice->OpenTable();
TypeRPriceComboBox->Properties->Items->Clear();
TypeRPriceComboBox->Properties->Items->Add("Не задан");
DMSprTypeRPrice->Table->First();
while (!DMSprTypeRPrice->Table->Eof)
		{
		TypeRPriceComboBox->Properties->Items->Add(DMSprTypeRPrice->TableNAME_TPRICE->AsString);
        DMSprTypeRPrice->Table->Next();
		}


NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameUserDBText->DataSource=DM->DataSourceDocAll;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameObjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

cxGrid1DBTableView1NDS_DOSNT->Visible=DM_Connection->glShowNDS;
cxGrid1DBTableView1SUMNDS_DOSNT->Visible=DM_Connection->glShowNDS;

VesPrefiksBarCode="23";
VesTypeBarCode=1;
VesTypeSearch=1;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocOstNomImpl),false);
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
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaDocOstNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaDocOstNom::UpdateForm(void)
{
Prosmotr=DM->Prosmotr;


flObrabatChangeTypePrice=false;
flObrabatChangeRoznTypePrice=false;
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICEOSN->AsString));
TypeRPriceComboBox->ItemIndex=DMSprTypeRPrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString));
flObrabatChangeTypePrice=true;
flObrabatChangeRoznTypePrice=true;


if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}

if (glStrToInt64(DM->DocAllIDDOCOSNDOC->AsString)>0)
	{
	DocOsnLabel->Caption="Документ основание: "+glGetNameDoc(DM->DocOsnTDOC->AsString)
				+" №"+DM->DocOsnNUMDOC->AsString+" от "+DM->DocOsnPOSDOC->AsString;
	}
else
	{
    DocOsnLabel->Caption="";
	}

if (DM->SkladRozn==true)
	{
	cxGrid1DBTableView1NAC_DOSNT->Visible=true;
	cxGrid1DBTableView1RPRICE_DOSNT->Visible=true;
	cxGrid1DBTableView1RSUM_DOSNT->Visible=true;


	TypeRPriceLabel->Visible=true;
	TypeRPriceComboBox->Visible=true;
	}
else
	{

	cxGrid1DBTableView1NAC_DOSNT->Visible=false;
	cxGrid1DBTableView1RPRICE_DOSNT->Visible=false;
	cxGrid1DBTableView1RSUM_DOSNT->Visible=false;
	TypeRPriceLabel->Visible=false;
	TypeRPriceComboBox->Visible=false;
	}


}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(FormaSpiskaSprTypePrice)FormaSpiskaSprTypePrice->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(SpisokObject)SpisokObject->kanRelease();

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


DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprTypePrice->kanRelease();
DMSprTypeRPrice->kanRelease();
DMSprPrice->kanRelease();
DMSprARM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
int TFormaDocOstNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Nom)//EditRekvisit==Tovar)
		{
		if (type_event==1)
				{
				if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
						}
                DM->DocT->Edit();
				DM->DocTIDNOMOSNT->AsString=
								VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
				DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=Nom->DM->ElementTNOM->AsInteger;
                DM->DocTKOLOSNT->AsInteger=1;
				DM->DocTIDEDOSNT->AsString=Nom->DM->ElementIDBASEDNOM->AsString;
                DM->DocTNAMEED->AsString=Nom->DM->BasEdNAMEED->AsString;
				DM->DocTKFOSNT->AsFloat=Nom->DM->BasEdKFED->AsFloat;
				//DM->DocTPRICEOSNT->AsFloat=Nom->DM->ElementPRICEZNOM->AsFloat;
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement(glStrToInt64( DM->DocIDTPRICEOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
				DM->DocTPRICEOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;

				if (DM->SkladRozn==true)
					{
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
						DM->DocTRPRICE_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;
					}
				else
					{
					DM->DocTRPRICE_DOSNT->AsFloat=0;
					}
				DMSprPrice->kanRelease();
                DM->DocT->Post();
                }
		Nom=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1KOLOSNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1KOLOSNT->Focused=true;
			}
        }

if (number_procedure_end==ER_Ed)//EditRekvisit==Edinica)
		{
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDEDOSNT->AsString=Ed->DM->ElementIDED->AsString;
				DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKFOSNT->AsFloat=Ed->DM->ElementKFED->AsFloat;

				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICEOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
				DM->DocTPRICEOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;

				if (DM->SkladRozn==true)
					{
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
						DM->DocTRPRICE_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;
					}
				else
					{
					DM->DocTRPRICE_DOSNT->AsFloat=0;
					}
				DMSprPrice->kanRelease();

                DM->DocT->Post();
				}
		Ed=0;
		if (TablecxPageControl->ActivePageIndex==0)
			{
			cxGrid1->SetFocus();
			cxGrid1DBTableView1PRICEOSNT->Selected=true;
			cxGrid1->Focused();
			cxGrid1DBTableView1PRICEOSNT->Focused=true;
			}
        }

if (number_procedure_end==ER_Firm)//EditRekvisit==FirmaRekvisit)
        {
		if (type_event==1)
                {
				DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
				DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//EditRekvisit==SkladRekvisit)
		{
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
				DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
				DM->DocAll->Post();
				UpdateForm();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }


if (number_procedure_end==ER_TypePrice)//EditRekvisit==ViborTypePrice)
		{
		if (type_event==1)
                {
                DM->Doc->Edit();
				DM->DocIDTPRICEOSN->AsString=FormaSpiskaSprTypePrice->DM->TableID_TPRICE->AsString;
				DM->DocNAME_TPRICE->AsString=FormaSpiskaSprTypePrice->DM->TableNAME_TPRICE->AsString;
                DM->Doc->Post();
                }
		FormaSpiskaSprTypePrice=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_InfBase)//EditRekvisit==ViborInfBase)
		{
		if (type_event==1)
				{
				DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
				DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
				DM->DocAll->Post();
				}
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Part)
		{
		if (type_event==1)
				{
				EndEditPart();
				}
		FormaElementaSprPart=0;
		}

if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}

if (number_procedure_end==ER_Object)
		{
		if (type_event==1)
				{
				EndViborObject()  ;
				}
		SpisokObject=0;
		}


ActionOperation=aoNO;
return -1;
}


//----------------------------------------------------------------------------
void  TFormaDocOstNom::OpenFormSpiskaSprNom()
{
if (Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
		Nom->Vibor=true;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOMOSNT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TFormaDocOstNom:: OpenFormSpiskaSprEd()
{
if (Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOMOSNT->AsString));
		Ed->NumberProcVibor=ER_Ed;
        }
}
//----------------------------------------------------------------------------
void TFormaDocOstNom:: OpenFormSpiskaSprTypePrice()
{
if (Prosmotr==true) return;
if (FormaSpiskaSprTypePrice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprTypePrice.1",IID_IFormaSpiskaSprTypePrice,
													(void**)&FormaSpiskaSprTypePrice);
		FormaSpiskaSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprTypePrice->Vibor=true;
		FormaSpiskaSprTypePrice->NumberProcVibor=ER_TypePrice;

        }
}

//----------------------------------------------------------------------------







void    TFormaDocOstNom::OpenFormSpiskaSprFirm(void)
{
if (Prosmotr==true) return;
if (Firma==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
		Firma->Vibor=true;
		Firma->DM->OpenTable();
		Firma->NumberProcVibor=ER_Firm;

        }

}
//---------------------------------------------------------------------------
void  TFormaDocOstNom::OpenFormSpiskaSprSklad(void)
{
if (Prosmotr==true) return;
if (Sklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->DM->OpenTable();
		Sklad->NumberProcVibor=ER_Sklad;
        }

}
//-----------------------------------------------------------------------------






void __fastcall TFormaDocOstNom::ToolButtonAddPriceClick(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DocT->First();
while(!DM->DocT->Eof)
        {
        if(DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICEOSN->AsString), glStrToInt64(DM->DocTIDNOMOSNT->AsString))>0)
                {
                DM->DocT->Edit();
                DM->DocTPRICEOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat;
                DM->DocT->Post();
                }
        DM->DocT->Next();
        }
}
//---------------------------------------------------------------------------

void TFormaDocOstNom::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;
        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();

PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocOstNom::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
		TcxSSHeader *cHeader;

		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 10;
		cHeader->Size[1] = 10;
		cHeader->Size[2] = 40;
		cHeader->Size[3] = 250;
		cHeader->Size[4] = 60;
		cHeader->Size[5] = 80;
		cHeader->Size[6] = 60;
		cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;
TcxSSCellObject *cell;
numRow=1;
numCol=2;

IDMSprFirm *Firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&Firma);
Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(DM->DocAllIDFIRMDOC->AsInteger);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Firma->ElementFNAMEFIRM->AsString
        +" ИНН "+Firma->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;

numRow++;numRow++;

Firma->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Ввод остатков №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMOSN->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол-во";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Розн. цена";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text="Розн. сумма";
	cell->Style->HorzTextAlign = haCENTER;
	cell->Style->Font->Size = 10;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	}
numRow++;
RoznSummaForPrint=0;
}
//------------------------------------------------------------------------------
void TFormaDocOstNom::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMENOM->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTKOLOSNT->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = DM->DocTNAMEED->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTKFOSNT->AsFloat,ffFixed,10,3);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTPRICEOSNT->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(DM->DocTSUMOSNT->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRPRICE_DOSNT->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;

	cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
	cell->Text=FloatToStrF(DM->DocTRSUM_DOSNT->AsFloat,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	numCol++;
	RoznSummaForPrint=RoznSummaForPrint+ DM->DocTRSUM_DOSNT->AsFloat;
	}
}
//------------------------------------------------------------------------------
void TFormaDocOstNom::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text = "Всего";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text = FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

if (DM->SkladRozn==true)
	{
	cell = prForm->SS->ActiveSheet->GetCellObject(9, numRow);
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;

	cell = prForm->SS->ActiveSheet->GetCellObject(10, numRow);
	cell->Text=FloatToStrF(RoznSummaForPrint,ffFixed,10,2);
	cell->Style->HorzTextAlign = haRIGHT;
	cell->Style->Font->Size = 10;
	cell->Style->Borders->Edges [eLeft]->Style=lsThin;
	cell->Style->Borders->Edges [eRight]->Style=lsThin;
	cell->Style->Borders->Edges [eTop]->Style=lsThin;
	cell->Style->Borders->Edges [eBottom]->Style=lsThin;
	delete cell;
	}


numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->Font->Size = 10;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="             ______________________________________________ ";
delete cell;
numRow++;numRow++;


}
//------------------------------------------------------------------------------

void TFormaDocOstNom::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);

		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
        FormaSpiskaSprInfBase->DM->OpenTable();

		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
        }
}
//---------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocOstNom");	
}
//---------------------------------------------------------------------------





void __fastcall TFormaDocOstNom::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

OpenFormSpiskaSprNom();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;

OpenFormSpiskaSprEd();


}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprFirm();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocOstNom::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (Prosmotr==true) return;
OpenFormSpiskaSprSklad();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
 if (Prosmotr==true)
		{
        UpdateForm();
		 return;
		}

if ( TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICEOSN->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
        {
		String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);

				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICEOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
						DM->DocTPRICEOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeRoznTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
 if (Prosmotr==true)
		{
		UpdateForm();
		 return;
		}

if ( TypeRPriceComboBox->ItemIndex!=0)
		{
		DMSprTypeRPrice->Table->First();
		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDRTPRICE_DOSN->AsString=DMSprTypeRPrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
		{
		String V="В табличной части документа есть строки. Пересчитать цены?";
		String Z="Пересчитать цены?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);

				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString),
											 glStrToInt64(DM->DocTIDNOMOSNT->AsString));
						DM->DocTRPRICE_DOSNT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKFOSNT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::cxButtonPoGrpClick(TObject *Sender)
{
TcxSSCellObject *cell;
TSheetEditor  *prForm=new TSheetEditor(Application);
if (!prForm) return;
prForm->SS->BeginUpdate();

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
		TcxSSHeader *cHeader;

		cHeader = prForm->SS->ActiveSheet->Cols;
		cHeader->Size[0] = 10;
		cHeader->Size[1] = 10;
		cHeader->Size[2] = 40;
		cHeader->Size[3] = 250;
		cHeader->Size[4] = 60;
		cHeader->Size[5] = 80;
		cHeader->Size[6] = 60;
		cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;

numRow=1;
numCol=1;
porNumStr=1;
int porNumStrGrp=1;

//шапка
numRow=1;
numCol=2;

IDMSprFirm *Firma;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&Firma);

Firma->Init(InterfaceMainObject,InterfaceImpl);
Firma->OpenElement(DM->DocAllIDFIRMDOC->AsInteger);
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=Firma->ElementFNAMEFIRM->AsString
        +" ИНН "+Firma->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+Firma->ElementPADRFIRM->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++;numRow++;

Firma->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Ввод остатков №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Основание: "+DM->DocPRIMOSN->AsString;
delete cell;
numRow++;
numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "№";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Наименование";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Кол-во";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Единица";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "К";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Цена";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "Сумма";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->VertTextAlign = vaCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;

//группы

DM->Grp->Active=false;
DM->Grp->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
DM->Grp->Active=true;

DM->Grp->First();
while(!DM->Grp->Eof)
        {
        numCol=2;
        //порядковый номер строки
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Text = IntToStr(porNumStrGrp);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Text = DM->GrpNAMEGN->AsString;
        cell->Style->Brush->BackgroundColor=34;
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
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numCol++;
        cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
        cell->Text = FloatToStrF(DM->GrpSUMMA->AsFloat,ffFixed,10,2);
        cell->Style->Brush->BackgroundColor=34;
        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
        cell->Style->Borders->Edges [eRight]->Style=lsThin;
        cell->Style->Borders->Edges [eTop]->Style=lsThin;
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        numRow++;
        // получим расшифровку группы
        if ( DM->GrpIDGN->AsInteger==0)
                {
                String ZaprosEl="select  NAMENOM, NAMEED, SUM(SUMOSNT)  AS SUMMA, SUM(KFOSNT*KOLOSNT)  AS SUMKOL";
                ZaprosEl=ZaprosEl+" from  DOSNT ";
                ZaprosEl=ZaprosEl+" left outer join SNOM on IDNOMOSNT=IDNOM";
                ZaprosEl=ZaprosEl+" left outer join SGRPNOM on IDGRPNOM=IDGN";
                ZaprosEl=ZaprosEl+" left outer join SED on IDBASEDNOM=IDED";
                ZaprosEl=ZaprosEl+" where (IDDOCOSNT=:PARAM_IDDOC)";
                ZaprosEl=ZaprosEl+" and  (IDGN IS NULL) ";
				ZaprosEl=ZaprosEl+" group by NAMENOM, NAMEED ";
				DM->El->Active=false;
				DM->El->SelectSQL->Clear();
                DM->El->SelectSQL->Add(ZaprosEl);
				DM->El->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
                }
        else
                {
                DM->El->Active=false;
				DM->El->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllIDDOC->AsString;
				DM->El->ParamByName("PARAM_IDGN")->AsString=DM->GrpIDGN->AsString;
                }

        DM->El->Active=true;
        porNumStr=1;
        DM->El->First();
        while(!DM->El->Eof)
                {
                numCol=2;

                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = IntToStr(porNumStr);
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = DM->ElNAMENOM->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;  
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = DM->ElSUMKOL->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = DM->ElNAMEED->AsString;
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = "1";
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
				cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
				if (DM->ElSUMKOL->AsFloat!=0)
					{
					cell->Text = FloatToStrF(DM->ElSUMMA->AsFloat/
								DM->ElSUMKOL->AsFloat,ffFixed,10,2);
					}
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                numCol++;
                cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
                cell->Text = FloatToStrF(DM->ElSUMMA->AsFloat,ffFixed,10,2);
                cell->Style->Borders->Edges [eLeft]->Style=lsThin;
                cell->Style->Borders->Edges [eRight]->Style=lsThin;
                cell->Style->Borders->Edges [eTop]->Style=lsThin;
                cell->Style->Borders->Edges [eBottom]->Style=lsThin;
                delete cell;
                porNumStr++;
                numRow++;
                DM->El->Next();
                }

        porNumStrGrp++;
        DM->Grp->Next();
        }
        
cell = prForm->SS->ActiveSheet->GetCellObject(7, numRow);
cell->Text = "Всего";
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Text = FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "ВСЕГО: "+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat);
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
//cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//cell->Style->Borders->Edges [eRight]->Style=lsThin;
//cell->Style->Borders->Edges [eTop]->Style=lsThin;
//cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text = "Комиссия     ______________________________________________ ";
delete cell;
numRow++;numRow++;

DM->Grp->Active=false;
DM->El->Active=false;

prForm->SS->EndUpdate();
prForm->Show();	
}
//---------------------------------------------------------------------------






void __fastcall TFormaDocOstNom::ActionAddRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionDeleteRecordExecute(TObject *Sender)
{
if (Prosmotr==true) return;
DM->DeleteStringDoc();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void TFormaDocOstNom::OpenFormElementaSprPart(void)
{
if (glStrToInt64(DM->DocTIDNOMOSNT->AsString)>0)
	{
	if (FormaElementaSprPart==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementeSprPart.1",IID_IFormaElementaSprPart,
													(void**)&FormaElementaSprPart);

		FormaElementaSprPart->Init(InterfaceMainObject,InterfaceImpl);

		FormaElementaSprPart->NumberProcVibor=7;
		
		if (glStrToInt64(DM->DocTIDPARTOSNT->AsString)>0)
			{
			FormaElementaSprPart->DM->OpenElement(glStrToInt64(DM->DocTIDPARTOSNT->AsString));
			if ((glStrToInt64(FormaElementaSprPart->DM->ElementIDDOCPART->AsString)==glStrToInt64(DM->DocAllIDDOC->AsString))
						&&(glStrToInt64(FormaElementaSprPart->DM->ElementIDNOMPART->AsString)==glStrToInt64(DM->DocTIDNOMOSNT->AsString)))
				{ //этот же документ и номеклатура
				}
			else
				{ //создаем новый элемент
				FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOMOSNT->AsString));
				if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
					{
					FormaElementaSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
					}
				}
			}
		else
			{ //создаем новый элемент
			FormaElementaSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOMOSNT->AsString));
			if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
				}
			}

		FormaElementaSprPart->DM->Element->Edit();
		if(glStrToInt64(DM->DocAllIDFIRMDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDFIRMPART->AsString=DM->DocAllIDFIRMDOC->AsString;
				}
		if(glStrToInt64(DM->DocAllIDKLDOC->AsString)>0)
				{
				FormaElementaSprPart->DM->ElementIDKLPART->AsString=DM->DocAllIDKLDOC->AsString;
				}
		FormaElementaSprPart->DM->ElementPRICEZPART->AsFloat=DM->DocTPRICEOSNT->AsFloat;
		FormaElementaSprPart->DM->ElementDOCPART->AsString="Ввод остатков "+DM->DocAllNUMDOC->AsString+" от " +DM->DocAllPOSDOC->AsString;

		FormaElementaSprPart->DM->ElementGTDPART->AsString=DM->DocTGTDPART->AsString;
		FormaElementaSprPart->DM->ElementSERTPART->AsString=DM->DocTSERTPART->AsString;
		if (DM->DocTSRGODNPART->AsFloat!=0)
				{
				FormaElementaSprPart->DM->ElementSRGODNPART->AsDateTime=DM->DocTSRGODNPART->AsDateTime;
				}
		FormaElementaSprPart->DM->Element->Post();
		}
	}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::EndEditPart(void)
{

	DM->DocT->Edit();
	DM->DocTIDPARTOSNT->AsString=FormaElementaSprPart->DM->ElementIDPART->AsString;

	DM->DocTGTDPART->AsString=FormaElementaSprPart->DM->ElementGTDPART->AsString;
	DM->DocTSERTPART->AsString=FormaElementaSprPart->DM->ElementSERTPART->AsString;
	if (FormaElementaSprPart->DM->ElementSRGODNPART->AsFloat!=0)
		{
		DM->DocTSRGODNPART->AsDateTime=FormaElementaSprPart->DM->ElementSRGODNPART->AsDateTime;
		}
	DM->DocT->Post();


}
//-----------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::EditPropPartcxButtonClick(TObject *Sender)
{
OpenFormElementaSprPart();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::ReadShtrihCodEvent(int number, UnicodeString sh)
{

//*****************
if (Prosmotr==true)
	{
	 ShowMessage("Документ открыт только для просмотра!");
	return;
	}

AnsiString s=sh;


IObjectBarCode * ob_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
ob_bar->Init(InterfaceMainObject,InterfaceImpl);

IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);

IDMSprEd * dm_ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
dm_ed->Init(InterfaceMainObject,InterfaceImpl);

ob_bar->SprNom=dm_nom;
ob_bar->SprEd=dm_ed;
ob_bar->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString);
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOMOSNT->AsString = dm_nom->ElementIDNOM->AsString;
	DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
	DM->DocTTNOM->AsInteger=dm_nom->ElementTNOM->AsInteger;

	DM->DocTIDEDOSNT->AsString = dm_ed->ElementIDED->AsString;
	DM->DocTNAMEED->AsString = dm_ed->ElementNAMEED->AsString;
	DM->DocTKFOSNT->AsFloat = dm_ed->ElementKFED->AsFloat;

	DM->DocTKOLOSNT->AsFloat=ob_bar->Kol;

	//получим цену
	IDMSprPrice * dm_price;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
	dm_price->Init(InterfaceMainObject,InterfaceImpl);
	if (DM->SkladRozn==true)
		{
		DM->DocTRPRICE_DOSNT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDRTPRICE_DOSN->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOMOSNT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDEDOSNT->AsString),    // единица
						DM->DocTKFOSNT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица
		}
	else
		{
        DM->DocTRPRICE_DOSNT->AsFloat=0;
		}

		DM->DocTPRICEOSNT->AsFloat=dm_price->GetValuePrice(
						glStrToInt64(DM->DocIDTPRICEOSN->AsString),                     //тип цен
						glStrToInt64(DM->DocTIDNOMOSNT->AsString),  //номенклатура
						glStrToInt64(DM->DocTIDEDOSNT->AsString),    // единица
						DM->DocTKFOSNT->AsFloat,                   // коэффициент единицы
						glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)); //базовая единица

	dm_price->kanRelease();

	DM->DocT->Post();

	VibTovarId=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	VibTovarIdGrp=glStrToInt64(dm_nom->ElementIDGRPNOM->AsString);

	if (TablecxPageControl->ActivePageIndex==0)
		{
		cxGrid1->Focused();
		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOLOSNT->Focused=true;
		cxGrid1DBTableView1KOLOSNT->Selected=true;
		}
	}
else
	{
	 ShowMessage(ob_bar->TextError);
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();
}
//---------------------------------------------------------------------------
double  TFormaDocOstNom::ObrabotatVesBarCode(AnsiString bar_code,
										 IDMSprNom * nom,
										 IDMSprEd * ed,
										 AnsiString ves_prefiks_bar_code,
										 int ves_type_bar_code,
										 int ves_type_search)
{
double result=-1;
AnsiString code_for_poisk="";
AnsiString barcode_for_poisk="";

		switch (ves_type_bar_code)
			{
			case 1 :  // ППКККККВВВВВ
				{
				result=StrToFloat(AnsiString(bar_code[8])+
					AnsiString(bar_code[9])+
					AnsiString(bar_code[10])+
					AnsiString(bar_code[11])+
					AnsiString(bar_code[12]))/1000;
				//	ShowMessage("Получен вес товара"+FloatToStr(ves));

				code_for_poisk=AnsiString(bar_code[3])+
					AnsiString(bar_code[4])+
					AnsiString(bar_code[5])+
					AnsiString(bar_code[6])+
					AnsiString(bar_code[7]);

				barcode_for_poisk=AnsiString(bar_code[1])+
									AnsiString(bar_code[2])+
									AnsiString(bar_code[3])+
									AnsiString(bar_code[4])+
									AnsiString(bar_code[5])+
									AnsiString(bar_code[6])+
									AnsiString(bar_code[7])+
									"0"+"0"+"0"+"0"+"0";
				break;
				}
			case 2 :  //ППВВВВВККККК
				{
				result=StrToFloat(AnsiString(bar_code[3])+
					AnsiString(bar_code[4])+
					AnsiString(bar_code[5])+
					AnsiString(bar_code[6])+
					AnsiString(bar_code[7]))/1000;
				//	ShowMessage("Получен вес товара"+FloatToStr(ves));

				code_for_poisk=AnsiString(bar_code[8])+
					AnsiString(bar_code[9])+
					AnsiString(bar_code[10])+
					AnsiString(bar_code[11])+
					AnsiString(bar_code[12]);

				barcode_for_poisk=AnsiString(bar_code[1])+
									AnsiString(bar_code[2])+
									"0"+"0"+"0"+"0"+"0"+
									AnsiString(bar_code[8])+
									AnsiString(bar_code[9])+
									AnsiString(bar_code[10])+
									AnsiString(bar_code[11])+
									AnsiString(bar_code[12]);
				break;
				}
			}

		switch (ves_type_search)
			{
			case 1 :  // по коду номенклатуры
				{
				if (nom->FindPoCodu(StrToInt(code_for_poisk))>0) //открывает элемент
					{
					ed->OpenElement(glStrToInt64(nom->ElementIDBASEDNOM->AsString));
					}
				else
					{
					ShowMessage("Не найден весовой товар с кодом номенклатуры "+code_for_poisk+"!");
					result=-1;
					}
				break;
				}
			case 2 :  //по коду единицы
				{
				__int64 id_ed=ed->FindEdPoCodu(StrToInt(code_for_poisk)); //не открывает элемент
				if (id_ed>0)
					{
					ed->OpenElement(id_ed);
					nom->OpenElement(glStrToInt64(ed->ElementIDNOMED->AsString));
					}
				else
					{
					ShowMessage("Не найден весовой товар с кодом единицы "+code_for_poisk+"!");
					result=-1;
					}
					
				break;
				}

			case 3 :  //по штрих коду единицы  без веса
				{
				barcode_for_poisk=glAddEAN13(barcode_for_poisk.SetLength(12));
				if (ed->FindEdPoSh(barcode_for_poisk)>0)
					{
					nom->OpenElement(glStrToInt64(ed->ElementIDNOMED->AsString));
					}
				else
					{
					ShowMessage("Не найден весовой товар с штрих-кодом единицы"+barcode_for_poisk+"!");
					result=-1;
					}
				break;
				}
			}

 //конец обработки весового кода
return result;

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::ActionSetMainTabSheetExecute(TObject *Sender)
{
TablecxPageControl->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionSetAdditionallyTabSheetExecute(
      TObject *Sender)
{
TablecxPageControl->ActivePageIndex=1;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ToolButton5Click(TObject *Sender)
{
DM->DocT->First();
while (!DM->DocT->Eof)
	{ 
	if (DM->DocTSRGODNPART->AsDateTime<EncodeDate(2000,01,01))
		{

		IDMSprNom * n;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&n);

		n->Init(InterfaceMainObject,InterfaceImpl);
		n->OpenElement(glStrToInt64(DM->DocTIDNOMOSNT->AsString));
		if (n->ElementGODEN_DO_SNOM->AsDateTime > EncodeDate(2000,01,01))
			{
			DM->DocT->Edit();
			DM->DocTSRGODNPART->AsDateTime= n->ElementGODEN_DO_SNOM->AsDateTime;
			DM->DocT->Post();
			}
		n->kanRelease();

		}
    DM->DocT->Next();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaDocOstNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocOstNom::RunExternalModule(__int64 id_module, int type_module)
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


//надо добавить переменные модуля, как минимум  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::ActionCloseExecute(TObject *Sender)
{
DM->CloseDoc();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaDocOstNom::ActionDvRegExecute(TObject *Sender)
{
if (Prosmotr==true) return;
__int64 id_doc=glStrToInt64(DM->DocAllIDDOC->AsString);
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				DM->OpenDoc(id_doc);
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionSaveExecute(TObject *Sender)
{
if (Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		 UpdateForm();
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocOstNom::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocOstNom::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::ToolButtonAddOstatkiClick(TObject *Sender)
{
UnicodeString zapros="select IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED,sum(rgostnom.kolostnom) as OSTKOL, sum(rgostnom.sumostnom) as OSTSUM        \
					from rgostnom                                                         \
					left outer join SNOM on IDNOM=rgostnom.idnomostnom                    \
					left outer join sed on sed.ided=snom.idbasednom                       \
					where rgostnom.idsklostnom=:PARAM_IDSKLAD                             \
							and rgostnom.idfirmostnom=:PARAM_IDFIRM                       \
					group by IDNOM, CODENOM, NAMENOM, IDED, NAMEED, KFED                  \
					order by NAMENOM ";

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add(zapros);
DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=DM->DocAllIDSKLDOC->AsString;
DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=DM->DocAllIDFIRMDOC->AsString;
DMQueryRead->pFIBQ->ExecQuery();

while(!DMQueryRead->pFIBQ->Eof)
	{
	DM->AddDocNewString();
	DM->DocT->Edit();

	DM->DocTIDNOMOSNT->AsString=DMQueryRead->pFIBQ->FieldByName("IDNOM")->AsString;
	//DM->DocTCODENOM->AsInteger=DMQueryRead->pFIBQ->FieldByName("CODENOM")->AsInteger;
	DM->DocTNAMENOM->AsString=DMQueryRead->pFIBQ->FieldByName("NAMENOM")->AsString;

	DM->DocTIDEDOSNT->AsString=DMQueryRead->pFIBQ->FieldByName("IDED")->AsString;
	DM->DocTNAMEED->AsString=DMQueryRead->pFIBQ->FieldByName("NAMEED")->AsString;
	DM->DocTKFOSNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("KFED")->AsFloat;
	DM->DocTKOLOSNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("OSTKOL")->AsFloat;
	DM->DocTPRICEOSNT->AsFloat=DMQueryRead->pFIBQ->FieldByName("OSTSUM")->AsFloat/
							DMQueryRead->pFIBQ->FieldByName("OSTKOL")->AsFloat;

    DM->DocT->Post();
	DMQueryRead->pFIBQ->Next();
	}


DMQueryRead->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocOstNom::cxGrid1DBTableView1NAC_DOSNTPropertiesValidate(TObject *Sender,
          Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
double procent=(double)VarAsType(DisplayValue,varDouble);
DM->DocT->Edit();
DM->DocTRPRICE_DOSNT->AsFloat=DM->DocTPRICEOSNT->AsFloat*((100+procent)/100);
DM->DocT->Post();
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TFormaDocOstNom::OpenFormSpiskaSprObject(void)
{
if (Prosmotr==true) return;
if (SpisokObject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprObject,IID_IFormaSpiskaSprObject,
													(void**)&SpisokObject);
		SpisokObject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokObject->NumberProcVibor=ER_Object;
		SpisokObject->Vibor=true;
		//SpisokObject->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::EndViborObject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDOBJECT_GALLDOC->AsString=SpisokObject->DM->TableID_SOBJECT->AsString;
	DM->DocAllNAME_SOBJECT->AsString=SpisokObject->DM->TableNAME_SOBJECT->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocOstNom::NameObjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprObject();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDOBJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

