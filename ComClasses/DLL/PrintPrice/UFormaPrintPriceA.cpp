//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaPrintPriceA.h"

#include "UPrintPriceNumber1.cpp"
#include "UPrintPriceNumber2.h"
#include "UPrintPriceNumber3.h"
#include "UPrintPriceNumber4.h"
#include "UPrintPriceNumber5.h"
#include "UPrintPriceNumber6.h"
#include "UPrintPriceNumber7.h"
#include "IDMDocPer.h"
#include "IDMDocPrihNakl.h"
#include "IDMDocIsmPrice.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"





//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaPrintPriceA::TFormaPrintPriceA(TComponent* Owner)
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
void __fastcall TFormaPrintPriceA::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaPrintPriceA::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
									 (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Items->Clear();
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
        TypePriceComboBox->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
		}
DMSprTypePrice->Table->First();
TypePriceComboBox->ItemIndex=0;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
									 (void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenTable();
FirmaComboBox->Items->Clear();
DMSprFirm->Table->First();
while (!DMSprFirm->Table->Eof)
		{
		FirmaComboBox->Items->Add(DMSprFirm->TableNAMEFIRM->AsString);
		DMSprFirm->Table->Next();
		}

DMSprFirm->Table->First();
FirmaComboBox->ItemIndex=0;



InterfaceGlobalCom->kanCreateObject("Oberon.DMSprScale.1",IID_IDMSprScale,
									 (void**)&DMSprScale);
DMSprScale->Init(InterfaceMainObject,InterfaceImpl);
DMSprScale->OpenTable();
ScaleComboBox->Items->Clear();
DMSprScale->Table->First();
while (!DMSprScale->Table->Eof)
		{
		ScaleComboBox->Items->Add(DMSprScale->TableNAME_SSCALE->AsString);
		DMSprScale->Table->Next();
		}

DMSprScale->Table->First();
ScaleComboBox->ItemIndex=0;

List=new TList;
UpdateGrid();

//заполним список внешних модулей

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaPrintPriceAImpl),false);
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
int TFormaPrintPriceA::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaPrintPriceA::UpdateGrid(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaGurDocPer)FormaGurDocPer->kanRelease();
if(FormaGurDocPrihNakl)FormaGurDocPrihNakl->kanRelease();
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();

for(int i=0;i<List->Count;i++)
		{
		ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[i];
		delete ElementSpiska;
		}
delete List;
DMSprFirm->kanRelease();
DMSprTypePrice->kanRelease();
DMSprScale->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaPrintPriceA::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
if (number_procedure_end==ViborNom)
        {
		if (type_event==1)
				{
				dc->AppendRecord();
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = FormaViborSprNom->DM->ElementIDNOM->AsString;;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = FormaViborSprNom->DM->ElementNAMENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = FormaViborSprNom->DM->ElementIDBASEDNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = FormaViborSprNom->DM->BasEdNAMEED->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1GRP->Index] =  0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] =  1;
				dc->Values[dc->RowCount-1][cxGrid1TableView1CODENOM->Index] = FormaViborSprNom->DM->ElementCODENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1ARTNOM->Index] = FormaViborSprNom->DM->ElementARTNOM->AsString;
				}
		FormaViborSprNom=0;
        }

if (number_procedure_end==ViborGrpNom)
        {
		if (type_event==1)
				{
				dc->AppendRecord();
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = FormaViborGrpNomSpr->DMGrp->ElementIDGN->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = FormaViborGrpNomSpr->DMGrp->ElementNAMEGN->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = "";
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = "";
				dc->Values[dc->RowCount-1][cxGrid1TableView1GRP->Index] =  1;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] =  1;
				dc->Values[dc->RowCount-1][cxGrid1TableView1CODENOM->Index] = "";
				dc->Values[dc->RowCount-1][cxGrid1TableView1ARTNOM->Index] = "";
				}
		FormaViborGrpNomSpr=0;
        }


if (number_procedure_end==ER_Per)
        {
		if (type_event==1)
				{
				EndViborDocPerem();
				}
		FormaGurDocPer=0;
		}

if (number_procedure_end==ER_PrihNakl)
		{
		if (type_event==1)
				{
				 EndViborDocPrihNakl();
				}
		FormaGurDocPrihNakl=0;
		}

if (number_procedure_end==ER_GurAllDoc)
		{
		if (type_event==1)
				{
				 EndViborDocGurAllDoc();
				}
		FormaGurAllDoc=0;
		}

return -1;
}
//---------------------------------------------------------------------------
void TFormaPrintPriceA::OpenFormViborSprNom(void)
{

if (FormaViborSprNom==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaViborSprNom);
		FormaViborSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborSprNom->Vibor=true;
		FormaViborSprNom->NumberProcVibor=ViborNom;
		FormaViborSprNom->DM->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
		FormaViborSprNom->UpdateForm();
        }
}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::AddNomToolButtonClick(TObject *Sender)
{
OpenFormViborSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::DelNomToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
dc->DeleteFocused();
}

//-----------------------------------------------------------------------------
void TFormaPrintPriceA::OpenFormViborGrpNom(void)
{
if (FormaViborGrpNomSpr==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&FormaViborGrpNomSpr);
		FormaViborGrpNomSpr->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborGrpNomSpr->Vibor=true;
		FormaViborGrpNomSpr->NumberProcVibor=ViborGrpNom;
        FormaViborGrpNomSpr->UpdateForm();
        }

}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::AddGrpToolButtonClick(TObject *Sender)
{
OpenFormViborGrpNom();
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrintPriceA::ToolButton4Click(TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber1 * PrintPriceNumber1=new TPrintPriceNumber1();
PrintPriceNumber1->DM_Connection=DM_Connection;
PrintPriceNumber1->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber1->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber1->Init();
PrintPriceNumber1->List=List;
PrintPriceNumber1->NameFirm=FirmaComboBox->Text;
PrintPriceNumber1->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber1->CreatePrice1();
delete PrintPriceNumber1;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintNumber2Click(
      TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber2 * PrintPriceNumber2=new TPrintPriceNumber2();
PrintPriceNumber2->DM_Connection=DM_Connection;
PrintPriceNumber2->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber2->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber2->Init();
PrintPriceNumber2->List=List;
PrintPriceNumber2->NameFirm=FirmaComboBox->Text;
PrintPriceNumber2->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber2->CreatePrice();
delete PrintPriceNumber2;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintNumber3Click(
      TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber3 * PrintPriceNumber3=new TPrintPriceNumber3();
PrintPriceNumber3->DM_Connection=DM_Connection;
PrintPriceNumber3->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber3->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber3->Init();
PrintPriceNumber3->List=List;
PrintPriceNumber3->NameFirm=FirmaComboBox->Text;
PrintPriceNumber3->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber3->CreatePrice();
delete PrintPriceNumber3;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintNumber4Click(
      TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber4 * PrintPriceNumber4=new TPrintPriceNumber4();
PrintPriceNumber4->DM_Connection=DM_Connection;
PrintPriceNumber4->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber4->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber4->Init();
PrintPriceNumber4->List=List;
PrintPriceNumber4->NameFirm=FirmaComboBox->Text;
PrintPriceNumber4->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber4->CreatePrice();
delete PrintPriceNumber4;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintBarCode1Click(
      TObject *Sender)
{
//TPrintBarCode1  *bar_code=new TPrintBarCode1();
//if (!bar_code) return;
//TDMSprNom * nom=new TDMSprNom(Application);
//nom->OpenElement(DM->TableIDNOM->AsInteger);
//TDMSprEd *ed=new TDMSprEd(Application);
//ed->OpenElement(nom->ElementIDBASEDNOM->AsInteger);
//bar_code->BarCodeValue=ed->ElementSHED->AsString;
//bar_code->BottomString=nom->ElementNAMENOM->AsString;
//delete ed; delete nom;
//bar_code->CreateBarCode();
//delete bar_code;

ZapolnitList();
//TclPrintBarCode2 * clPrint=new TclPrintBarCode2();
//clPrint->List=List;
//clPrint->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
//clPrint->CreatePrintBarCode();
//delete clPrint;
}
//---------------------------------------------------------------------------



void __fastcall TFormaPrintPriceA::FirmaComboBoxChange(TObject *Sender)
{
		DMSprFirm->Table->First();
        DMSprFirm->Table->MoveBy(FirmaComboBox->ItemIndex);	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::TypePriceComboBoxChange(TObject *Sender)
{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintPrice5Click(TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber5 * PrintPriceNumber5=new TPrintPriceNumber5();
PrintPriceNumber5->DM_Connection=DM_Connection;
PrintPriceNumber5->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber5->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber5->Init();
PrintPriceNumber5->List=List;
PrintPriceNumber5->NameFirm=FirmaComboBox->Text;
PrintPriceNumber5->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber5->CreatePrice();
delete PrintPriceNumber5;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintPrice6Click(TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber6 * PrintPriceNumber6=new TPrintPriceNumber6();
PrintPriceNumber6->DM_Connection=DM_Connection;
PrintPriceNumber6->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber6->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber6->Init();
PrintPriceNumber6->List=List;
PrintPriceNumber6->NameFirm=FirmaComboBox->Text;
PrintPriceNumber6->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber6->CreatePrice();
delete PrintPriceNumber6;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButtonPrintPrice7Click(TObject *Sender)
{
ZapolnitList();
TPrintPriceNumber7 * PrintPriceNumber7=new TPrintPriceNumber7();
PrintPriceNumber7->DM_Connection=DM_Connection;
PrintPriceNumber7->InterfaceGlobalCom=InterfaceGlobalCom;
PrintPriceNumber7->InterfaceMainObject=InterfaceMainObject;
PrintPriceNumber7->Init();
PrintPriceNumber7->List=List;
PrintPriceNumber7->NameFirm=FirmaComboBox->Text;
PrintPriceNumber7->IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
PrintPriceNumber7->CreatePrice();
delete PrintPriceNumber7;
}
//---------------------------------------------------------------------------

//выбор документа перемещения
void TFormaPrintPriceA::ViborDocPerem(void)
{
if (FormaGurDocPer==0)
	{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocPer.1",IID_IFormaGurDocPer,
													(void**)&FormaGurDocPer);
		FormaGurDocPer->Init(InterfaceMainObject,InterfaceImpl);
		FormaGurDocPer->NumberProcVibor=ER_Per;
	//настройка формы
	FormaGurDocPer->Vibor=true;

	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::EndViborDocPerem(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

	IDMDocPer * doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
	doc->OpenDoc(glStrToInt64(FormaGurDocPer->DM->TableIDDOC->AsString));
	doc->DocT->First();
	while(!doc->DocT->Eof)
		{
		dc->AppendRecord();
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = doc->DocTIDNOMPERT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = doc->DocTNAMENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = doc->DocTIDEDPERT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = doc->DocTNAMEED->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1GRP->Index] =  0;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] =  doc->DocTKOLPERT->AsFloat*
																doc->DocTKFPERT->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1CODENOM->Index] = doc->DocTCODENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1ARTNOM->Index] = doc->DocTARTNOM->AsString;
		doc->DocT->Next();
		}
	doc->kanRelease();

}
//----------------------------------------------------------------------------
//выбор документа Приходная накладная 
void TFormaPrintPriceA::ViborDocPrihNakl(void)
{

if (FormaGurDocPrihNakl==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocPrihNakl.1",IID_IFormaGurDocPrihNakl,
													(void**)&FormaGurDocPrihNakl);
	FormaGurDocPrihNakl->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurDocPrihNakl->NumberProcVibor=ER_PrihNakl;
	FormaGurDocPrihNakl->Vibor=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::EndViborDocPrihNakl(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

	IDMDocPrihNakl * doc;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&doc);
	doc->Init(InterfaceMainObject,InterfaceImpl);
	doc->OpenDoc(glStrToInt64(FormaGurDocPrihNakl->DM->TableIDDOC->AsString));
	doc->DocT->First();
	while(!doc->DocT->Eof)
		{
		dc->AppendRecord();
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = doc->DocTIDNOMPRNT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = doc->DocTNAMENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = doc->DocTIDEDPRNT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = doc->DocTNAMEED->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1GRP->Index] =  0;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] =  doc->DocTKOLPRNT->AsFloat*
																doc->DocTKFPRNT->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1CODENOM->Index] = doc->DocTCODENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1ARTNOM->Index] = doc->DocTARTNOM->AsString;
		doc->DocT->Next();
		}
	doc->kanRelease();




}
//----------------------------------------------------------------------------		
void __fastcall TFormaPrintPriceA::cxGrid1TableView1GRPCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
ToolBar1->Images->GetBitmap(18,ABitmap);
ACanvas->Canvas->FillRect(ARec);
if (ATextToDraw==1)
	{
	ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
	}
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------
void TFormaPrintPriceA::ZapolnitList(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
for(int i=0;i<List->Count;i++)
		{
		ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[i];
		delete ElementSpiska;
		}
List->Clear();

for (int i=0; i<dc->RowCount; i++)
	{
	TElementSpiskaPrintPrice * el=new TElementSpiskaPrintPrice;
	el->Id=glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]);
	el->Name=dc->Values[i][cxGrid1TableView1NAMENOM->Index];
	el->IdEd=glStrToInt64(dc->Values[i][cxGrid1TableView1IDED->Index]);
	el->NameEd=dc->Values[i][cxGrid1TableView1NAMEED->Index];
	if (dc->Values[i][cxGrid1TableView1GRP->Index]==1)
		{
		el->Grp=true;
		}
	else
		{
		el->Grp=false;
		}
	el->Kol=dc->Values[i][cxGrid1TableView1KOL->Index];
	List->Add(el);
	}
}
//----------------------------------------------------------------------------
void TFormaPrintPriceA::ZapolnitListForExtModule(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
for(int i=0;i<List->Count;i++)
		{
		ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[i];
		delete ElementSpiska;
		}
List->Clear();

for (int i=0; i<dc->RowCount; i++)
	{
	if (dc->Values[i][cxGrid1TableView1GRP->Index]==1)
		{     //группа товаров
		IDMSprNom * nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&nom);
		nom->Init(InterfaceMainObject,InterfaceImpl);
		nom->IdTypePrice=glStrToInt64(DMSprTypePrice->TableID_TPRICE->AsString);
		nom->OpenTable(glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]),false);
		nom->Table->First();
		while (!nom->Table->Eof)
			{
			int kol=dc->Values[i][cxGrid1TableView1KOL->Index];
			while(kol > 0)
				{
				TElementSpiskaPrintPrice * el=new TElementSpiskaPrintPrice;
				el->Id=0;
				el->IdEd=0;
				el->Kol=0;
				nom->OpenElement(glStrToInt64(nom->TableIDNOM->AsString));
				el->Id=glStrToInt64(nom->TableIDNOM->AsString);
				el->IdEd=glStrToInt64(nom->ElementIDOSNEDNOM->AsString);
				el->Kol=dc->Values[i][cxGrid1TableView1KOL->Index];
				List->Add(el);
				kol--;
				}
			nom->Table->Next();
			}  
		nom->kanRelease();
		}
	else
		{
		int kol=dc->Values[i][cxGrid1TableView1KOL->Index];
		while(kol > 0)
			{
			TElementSpiskaPrintPrice * el=new TElementSpiskaPrintPrice;
			el->Id=0;
			el->IdEd=0;
			el->Kol=0;
			el->Id=glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]);
			el->IdEd=glStrToInt64(dc->Values[i][cxGrid1TableView1IDED->Index]);
			el->Kol=dc->Values[i][cxGrid1TableView1KOL->Index];
			List->Add(el);
			kol--;
			}
		} 
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::ViborPeremToolButtonClick(TObject *Sender)
{
ViborDocPerem();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ViborPrihNaklToolButtonClick(TObject *Sender)
{
ViborDocPrihNakl();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ClearToolButtonClick(TObject *Sender)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

while (dc->RowCount>0)
	{
	dc->DeleteRecord(0);
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("PrintPriceLabel");		
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ScaleComboBoxChange(TObject *Sender)
{
		DMSprScale->Table->First();
		DMSprScale->Table->MoveBy(ScaleComboBox->ItemIndex);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaPrintPriceA::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaPrintPriceA::RunExternalModule(__int64 id_module, int type_module)
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

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdTypePrice", glStrToInt64(DMSprTypePrice->TableID_TPRICE->AsString));
	module->SetInt64Variables("glIdFirm", glStrToInt64(DMSprFirm->TableIDFIRM->AsString));
	module->SetInt64Variables("glIdScale", glStrToInt64(DMSprScale->TableID_SSCALE->AsString));

	//заполним список элементов List
    ZapolnitListForExtModule();
	for(int i=0;i<List->Count;i++)
		{
		ElementSpiska=(TElementSpiskaPrintPrice*) List->Items[i];
		module->ListAddElement(ElementSpiska->Id,ElementSpiska->IdEd,"",ElementSpiska->Kol);
		}

	}

module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::ToolButtonSetKol1Click(TObject *Sender)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

for (int i=0; i<dc->RowCount; i++)
	{
	dc->Values[i][cxGrid1TableView1KOL->Index]=1;
	}
}
//---------------------------------------------------------------------------
//выбор документа из полного журнала
void TFormaPrintPriceA::ViborDocGurAllDoc(void)
{
if (FormaGurAllDoc==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaGurAllDoc,IID_IFormaGurAllDoc,
													(void**)&FormaGurAllDoc);
	FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurAllDoc->NumberProcVibor=ER_GurAllDoc;
	FormaGurAllDoc->Vibor=true;
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaPrintPriceA::EndViborDocGurAllDoc(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;


if (FormaGurAllDoc->DM->TableTDOC->AsString=="ISMPRICE")
	{

	IDMDocIsmPrice * doc;
	InterfaceGlobalCom->kanCreateObject(ProgId_DMDocIsmPrice,IID_IDMDocIsmPrice,
													(void**)&doc);
	doc->Init(InterfaceMainObject,InterfaceImpl);
	doc->OpenDoc(glStrToInt64(FormaGurAllDoc->DM->TableIDDOC->AsString));
	doc->DocT->First();
	while(!doc->DocT->Eof)
		{
		dc->AppendRecord();
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = doc->DocTIDNOM_DISMPRICET->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = doc->DocTNAMENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = doc->DocTIDED_DISMPRICET->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = doc->DocTNAMEED->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1GRP->Index] =  0;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] =  doc->DocTKOL_DISMPRICET->AsFloat*
																doc->DocTKF_DISMPRICET->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1CODENOM->Index] = "";
		dc->Values[dc->RowCount-1][cxGrid1TableView1ARTNOM->Index] = "";
		doc->DocT->Next();
		}
	doc->kanRelease();
	}

}
//----------------------------------------------------------------------------

void __fastcall TFormaPrintPriceA::ToolButton8Click(TObject *Sender)
{
ViborDocGurAllDoc();
}
//---------------------------------------------------------------------------

