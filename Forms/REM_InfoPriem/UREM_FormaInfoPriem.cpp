//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaInfoPriem.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaZayavka.h"
#include "IREM_FormaZayavkaPredv.h"
#include "IREM_DMZayavka.h"
#include "IREM_FormaZayavkaDv.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"


#include "IREM_FormaDocZPost.h"
#include "IREM_FormaDocZVid.h"
#include "IREM_FormaDocZPer.h"
#include "IREM_FormaDocZStart.h"
#include "IREM_FormaDocZEnd.h"
#include "IREM_FormaDocZOper.h"
#include "IREM_FormaDocZTreb.h"
#include "IREM_FormaDocZAktPr.h"
#include "IREM_FormaDocZVosvrZap.h"
#include "IREM_FormaGurAllDoc.h"

#include "IREM_FormaCustQuery.h"
#include "IREM_FormaGurCustQuery.h"

#include "IREM_FormaDocVidachaHW.h"
#include "IREM_FormaDocVosvratHW.h"

#include "IAsyncExternalEvent.h"

#include "IART_FormaSpiskaSprInfBlockSostav.h"
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
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxPC"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxMemo"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaInfoPriem::TREM_FormaInfoPriem(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;

ModelcxTextEdit->Text="";
SerNumcxTextEdit->Text="";
SerNum2cxTextEdit->Text="";
KlientNamecxTextEdit->Text="";
NumGarDoccxTextEdit->Text="";

cxLabelSerNum1->Caption="";
cxLabelSerNum2->Caption="";
}
//---------------------------------------------------------------------------
bool TREM_FormaInfoPriem::Init(void)
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



//DM->OpenTable();
//DM->Table->Last();

NameSkladcxButtonEdit->Text="";

Vibor=false;
cxLabelHint->Caption="";

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaGurZImpl),false);
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

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;



InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer, (void**)&DMSprProducer);
DMSprProducer->Init(InterfaceMainObject,InterfaceImpl);
DMSprProducer->OpenTable();
ProducercxLookupComboBox->Properties->ListSource=DMSprProducer->DataSourceTable;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBrand.1",IID_IDMSprBrand, (void**)&DMSprBrand);
DMSprBrand->Init(InterfaceMainObject,InterfaceImpl);
DMSprBrand->OpenTable();
BrandcxLookupComboBox->Properties->ListSource=DMSprBrand->DataSourceTable;


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerModelGrp,IID_IREM_DMSprProducerModelGrp, (void**)&REM_DMSprProducerModelGrp);
REM_DMSprProducerModelGrp->Init(InterfaceMainObject,InterfaceImpl);
GroupcxLookupComboBox->Properties->ListSource=REM_DMSprProducerModelGrp->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerModel,IID_IREM_DMSprProducerModel, (void**)&REM_DMSprProducerModel);
REM_DMSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
PrModelcxLookupComboBox->Properties->ListSource=REM_DMSprProducerModel->DataSourceTable;







InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprTypeDevice,IID_IREM_DMSprTypeDevice, (void**)&REM_DMSprTypeDevice);
REM_DMSprTypeDevice->Init(InterfaceMainObject,InterfaceImpl);
TypeDevice2cxLookupComboBox->Properties->ListSource=REM_DMSprTypeDevice->DataSourceTable;
REM_DMSprTypeDevice->OpenTable();

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel2Grp,IID_IREM_DMSprModel2Grp, (void**)&REM_DMSprModel2Grp);
REM_DMSprModel2Grp->Init(InterfaceMainObject,InterfaceImpl);
GroupModel2cxLookupComboBox->Properties->ListSource=REM_DMSprModel2Grp->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprModel2,IID_IREM_DMSprModel2, (void**)&REM_DMSprModel2);
REM_DMSprModel2->Init(InterfaceMainObject,InterfaceImpl);
Model2cxLookupComboBox->Properties->ListSource=REM_DMSprModel2->DataSourceTable;



InterfaceGlobalCom->kanCreateObject(ProgId_DMDataSet,IID_IDMDataSet, (void**)&DMInfo);
DMInfo->Init(InterfaceMainObject,InterfaceImpl);
InfocxGridDBTableView->DataController->DataSource=DMInfo->DataSource;

InterfaceGlobalCom->kanCreateObject(ProgId_DMDataSet,IID_IDMDataSet, (void**)&DMZip);
DMZip->Init(InterfaceMainObject,InterfaceImpl);
ZipcxGrid3DBTableView->DataController->DataSource=DMZip->DataSource;

InterfaceGlobalCom->kanCreateObject(ProgId_DMDataSet,IID_IDMDataSet, (void**)&DMGurZ);
DMGurZ->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DMGurZ->DataSource;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaInfoPriem::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprInfBlockSostav)FormaSpiskaSprInfBlockSostav->kanRelease();

//if(FormaSetupOtbor)FormaSetupOtbor->Close();
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


DMInfo->kanRelease();
DMZip->kanRelease();
DMGurZ->kanRelease();
DMSprProducer->kanRelease();
DMSprBrand->kanRelease();
REM_DMSprProducerModelGrp->kanRelease();
REM_DMSprProducerModel->kanRelease();
REM_DMSprTypeDevice->kanRelease();
REM_DMSprModel2Grp->kanRelease();
REM_DMSprModel2->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaInfoPriem::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ViborPerioda)
                {
				if(type_event==1)
                        {
						PosNach=FormaViborPerioda->PosNach;
                        PosCon=FormaViborPerioda->PosCon;
						//DM->PosNach=PosNach;
					   // DM->PosCon=PosCon;
                        }
                FormaViborPerioda=0;
				//DM->UpdateTable();
                }

if (number_procedure_end==ER_ViborHardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}


if(number_procedure_end==ER_ShowPage)//ViborElement)
		{
		EndCloseFormShow();
		FormaSpiskaSprInfBlockSostav=0;
		}

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaInfoPriem::OpenFormDoc()
{
if (DMGurZ->DataSet->FieldByName("OUT_TYPE_TABLE")->AsInteger==1)
	{
	IREM_FormaZayavka * REM_FormaZayavka;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
									 (void**)&REM_FormaZayavka);
	REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
	if (!REM_FormaZayavka) return;
	REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString));
	REM_FormaZayavka->UpdateForm();
	}


if (DMGurZ->DataSet->FieldByName("OUT_TYPE_TABLE")->AsInteger==2)
	{
	IREM_FormaZayavkaPredv * REM_FormaZayavka;
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
									 (void**)&REM_FormaZayavka);
	REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
	if (!REM_FormaZayavka) return;
	REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString));
	REM_FormaZayavka->UpdateForm();
	}
}
//----------------------------------------------------------------------------







//----------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaInfoPriem::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Gur/GurAllDoc");
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::ToolButtonAddNewZClick(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->DM->GurZ->Edit();
REM_FormaZayavka->DM->GurZSERNUM_REM_Z->AsString=SerNumcxTextEdit->Text;
REM_FormaZayavka->DM->GurZSERNUM2_REM_Z->AsString=SerNum2cxTextEdit->Text;
REM_FormaZayavka->DM->GurZNUM_GARDOC_REM_Z->AsString=NumGarDoccxTextEdit->Text;
REM_FormaZayavka->DM->GurZ->Post();
REM_FormaZayavka->UpdateForm();

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
	{
	TypeEvent=1;
	Close();
	}
else
	{
	OpenFormDoc();
	}
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
			{
			TypeEvent=1;
			Close();
			}
		else
			{
			OpenFormDoc();
			}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::ToolButton5Click(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaInfoPriem::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaInfoPriem::RunExternalModule(__int64 id_module, int type_module)
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
//module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_Z->AsString));
//module->SetInt64Variables("glIdZayvka", glStrToInt64(DM->TableID_REM_Z->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1OUT_OUTCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //выдано отремонтировано
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else if (ATextToDraw==2)  //выдано не отремонтировано
	{
	ToolBar1->Images->GetBitmap(58,ABitmap);
	}
else if (ATextToDraw==3)  //отремонтировано
	{
	ToolBar1->Images->GetBitmap(57,ABitmap);
	}
else if (ATextToDraw==4)  //отремонтировано
	{
	ToolBar1->Images->GetBitmap(59,ABitmap);  //к выдаче без ремонта
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
		  TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
		  bool &ADone)
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

if (ATextToDraw==1) //прочее
	{
	ToolBar1->Images->GetBitmap(66,ABitmap);
	}
else if (ATextToDraw==2)  //думает
	{
	ToolBar1->Images->GetBitmap(64,ABitmap);
	}
else if (ATextToDraw==3)  //согласовал
	{
	ToolBar1->Images->GetBitmap(61,ABitmap);
	}
else if (ATextToDraw==4)  //не согласовал
	{
	ToolBar1->Images->GetBitmap(62,ABitmap);  //к выдаче без ремонта
	}


ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1FL_TREB_KONS_KL_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //прочее
	{
	ToolBar1->Images->GetBitmap(63,ABitmap);
	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //прочее
	{
	ToolBar1->Images->GetBitmap(66,ABitmap);
	}
else if (ATextToDraw==2)  //СМС
	{
	ToolBar1->Images->GetBitmap(67,ABitmap);
	}
else if (ATextToDraw==3)  //по телефону
	{
	ToolBar1->Images->GetBitmap(65,ABitmap);
	}
else if (ATextToDraw==4)  //электронная почта
	{
	ToolBar1->Images->GetBitmap(68,ABitmap);
	}
else if (ATextToDraw==5)  //лично приходил
	{
	ToolBar1->Images->GetBitmap(69,ABitmap);  //к выдаче без ремонта
	}


ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------










//---------------------------------------------------------------------------
void TREM_FormaInfoPriem::ViborHardware(void)
{

if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHardware;
		FormaSpiskaSprHardware->SerNumber1=SerNumcxTextEdit->Text;
		FormaSpiskaSprHardware->SerNumber2=SerNum2cxTextEdit->Text;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));


IdVibHardware=glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString);
NameHardwarecxButtonEdit->Text=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
//SerNumcxTextEdit->Text=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
//SerNum2cxTextEdit->Text=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
//ModelcxTextEdit->Text=spr_hw->ElementNAME_REM_SMODEL->AsString;

cxLabelSerNum1->Caption=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
cxLabelSerNum2->Caption=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;

spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::cxButtonPoiskPoSerNumClick(TObject *Sender)
{
if (Trim(SerNumcxTextEdit->Text)!="")
	{
cxLabelHint->Caption="";
 //ищем в справочнике Оборудование
	IREM_DMSprHardware *h;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&h);
	h->Init(InterfaceMainObject,InterfaceImpl);

	h->Table_FindPoSerNum1Like(0,true, Trim(SerNumcxTextEdit->Text));
	h->Table->Last();
	if (h->Table->RecNo == 0)
		{
		cxLabelHint->Caption="";
		}
	else
		{
		cxLabelHint->Caption="Найдено совпадений "+ IntToStr(h->Table->RecNo);
		}
	h->kanRelease();




		DMGurZ->DataSet->Active=false;
		DMGurZ->DataSet->SelectSQL->Clear();
		DMGurZ->DataSet->SelectSQL->Add("select * from rem_info_priem_get_gur_z_all (0,'30.12.1899','30.12.1899',1,:PARAM_SERNUM,0)");
		DMGurZ->DataSet->SelectSQL->Add(" order by rem_info_priem_get_gur_z_all.out_pos");
		DMGurZ->DataSet->ParamByName("PARAM_SERNUM")->AsString=Trim(SerNumcxTextEdit->Text);
		DMGurZ->DataSet->Active=true;
		DMGurZ->DataSet->Last();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaInfoPriem::FormDeactivate(TObject *Sender)
{
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
//событие считывания штрих-кода
void __fastcall TREM_FormaInfoPriem::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxTextEdit->Focused()==true)
	{
	SerNumcxTextEdit->Text=Trim(sh);
	}
else if(SerNum2cxTextEdit->Focused()==true)
	{
    SerNum2cxTextEdit->Text=Trim(sh);
	}
else if(NumGarDoccxTextEdit->Focused()==true)
	{
    NumGarDoccxTextEdit->Text=Trim(sh);
	}


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::cxButtonPoiskPoSerNum2Click(TObject *Sender)
{
if (Trim(SerNum2cxTextEdit->Text)!="")
	{

cxLabelHint->Caption="";
 //ищем в справочнике Оборудование
	IREM_DMSprHardware *h;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&h);
	h->Init(InterfaceMainObject,InterfaceImpl);

	h->Table_FindPoSerNum2Like(0,true, Trim(SerNum2cxTextEdit->Text));
	h->Table->Last();
	if (h->Table->RecNo == 0)
		{
		cxLabelHint->Caption="";
		}
	else
		{
		cxLabelHint->Caption="Найдено совпадений "+ IntToStr(h->Table->RecNo);
		}
	h->kanRelease();


		DMGurZ->DataSet->Active=false;
		DMGurZ->DataSet->SelectSQL->Clear();
		DMGurZ->DataSet->SelectSQL->Add("select * from rem_info_priem_get_gur_z_all (0,'30.12.1899','30.12.1899',2,:PARAM_SERNUM,0)");
		DMGurZ->DataSet->SelectSQL->Add(" order by rem_info_priem_get_gur_z_all.out_pos");
		DMGurZ->DataSet->ParamByName("PARAM_SERNUM")->AsString=Trim(SerNum2cxTextEdit->Text);
		DMGurZ->DataSet->Active=true;
		DMGurZ->DataSet->Last();
	}
}
//---------------------------------------------------------------------------






void __fastcall TREM_FormaInfoPriem::ToolButtonCopyZayavkaClick(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();

IREM_DMZayavka *z;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavka.1",IID_IREM_DMZayavka, (void**)&z);
z->Init(InterfaceMainObject,InterfaceImpl);

z->OpenDoc(glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString));

REM_FormaZayavka->DM->GurZ->Edit();

REM_FormaZayavka->DM->GurZIDTYPEREM_REM_Z->AsString=z->GurZIDTYPEREM_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNAME_STREMONT->AsString=z->GurZNAME_STREMONT->AsString;
REM_FormaZayavka->DM->GurZIDSOST_REM_Z->AsString=z->GurZIDSOST_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNAME_REMSSOST->AsString=z->GurZNAME_REMSSOST->AsString;

REM_FormaZayavka->DM->GurZIDKLIENT_REM_Z->AsString=z->GurZIDKLIENT_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNAMEKLIENT->AsString=z->GurZNAMEKLIENT->AsString;
REM_FormaZayavka->DM->GurZKLIENT_NAME_REM_Z->AsString=z->GurZKLIENT_NAME_REM_Z->AsString;
REM_FormaZayavka->DM->GurZKLIENT_ADR_REM_Z->AsString=z->GurZKLIENT_ADR_REM_Z->AsString;
REM_FormaZayavka->DM->GurZKLIENT_PHONE_REM_Z->AsString=z->GurZKLIENT_PHONE_REM_Z->AsString;

REM_FormaZayavka->DM->GurZIDMODEL_REM_Z->AsString=z->GurZIDMODEL_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNAME_REM_SMODEL->AsString=z->GurZNAME_REM_SMODEL->AsString;
REM_FormaZayavka->DM->GurZMODEL_REM_Z->AsString=z->GurZMODEL_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNUM_GARDOC_REM_Z->AsString=z->GurZNUM_GARDOC_REM_Z->AsString;
REM_FormaZayavka->DM->GurZSERNUM_REM_Z->AsString=z->GurZSERNUM_REM_Z->AsString;
REM_FormaZayavka->DM->GurZSERNUM2_REM_Z->AsString=z->GurZSERNUM2_REM_Z->AsString;

REM_FormaZayavka->DM->GurZSOST_REM_Z->AsString=z->GurZSOST_REM_Z->AsString;
REM_FormaZayavka->DM->GurZKOMPLECT_REM_Z->AsString=z->GurZKOMPLECT_REM_Z->AsString;
REM_FormaZayavka->DM->GurZNEISPR_REM_Z->AsString=z->GurZNEISPR_REM_Z->AsString;

REM_FormaZayavka->DM->GurZ->Post();

REM_FormaZayavka->UpdateForm();

z->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::ToolButtonZapShapkuNaOsnZayavkiClick(TObject *Sender)

{
IREM_DMZayavka *z;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavka.1",IID_IREM_DMZayavka, (void**)&z);
z->Init(InterfaceMainObject,InterfaceImpl);

z->OpenDoc(glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString));

SerNumcxTextEdit->Text=z->GurZSERNUM_REM_Z->AsString;
SerNum2cxTextEdit->Text=z->GurZSERNUM2_REM_Z->AsString;
NumGarDoccxTextEdit->Text=z->GurZNUM_GARDOC_REM_Z->AsString;

z->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::ToolButtonCreateNaOsnSprHardwareClick(TObject *Sender)

{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->DM->GurZ->Edit();

	IREM_DMSprHardware *h;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&h);
	h->Init(InterfaceMainObject,InterfaceImpl);
	h->OpenElement(IdVibHardware);

	REM_FormaZayavka->DM->GurZ->Edit();
	REM_FormaZayavka->DM->GurZIDHW_REM_Z->AsString=h->ElementID_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZNAME_REM_SHARDWARE->AsString=h->ElementNAME_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM_REM_SHARDWARE->AsString=h->ElementSERNUM_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM2_REM_SHARDWARE->AsString=h->ElementSERNUM2_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM_REM_Z->AsString=h->ElementSERNUM_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM2_REM_Z->AsString=h->ElementSERNUM2_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZIDMODEL_REM_Z->AsString=h->ElementIDMODEL_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZNAME_REM_SMODEL->AsString=h->ElementNAME_REM_SMODEL->AsString;
	REM_FormaZayavka->DM->GurZMODEL_REM_Z->AsString=h->ElementNAME_REM_SMODEL->AsString;
	REM_FormaZayavka->DM->GurZ->Post();


h->kanRelease();
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1SOST_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //не активно выполнено
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else if (ATextToDraw==2)  //не активно не выполнено
	{
	ToolBar1->Images->GetBitmap(58,ABitmap);
	}
else if (ATextToDraw==3)  //ждем выполнения
	{
	ToolBar1->Images->GetBitmap(57,ABitmap);
	}
else if (ATextToDraw==4)  //предварительно заказано
	{
	ToolBar1->Images->GetBitmap(72,ABitmap);
	}
else if (ATextToDraw==5)  //отправлено поставщиком
	{
	ToolBar1->Images->GetBitmap(57,ABitmap);
	}
else if (ATextToDraw==6)  //недоступно к заказу
	{
	ToolBar1->Images->GetBitmap(73,ABitmap);
	}
else if (ATextToDraw==7)  //выполнено частично
	{
	ToolBar1->Images->GetBitmap(45,ABitmap);
	}
else
	{
	//ToolBar1->Images->GetBitmap(17,ABitmap);
	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------





//выбор склада
void TREM_FormaInfoPriem::ViborSklad(void)
{

if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="Выберите склад для документа Ремонт оборудования №"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" от "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::EndViborSklad(void)
{


	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaInfoPriem::NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborSklad();
		}break;
	case 1:
		{
		IdSklad=0;
		NameSkladcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------








void __fastcall TREM_FormaInfoPriem::ProducercxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DMSprProducer->Table->Active==true)
	{
	DMSprProducer->Table->First();
	DMSprProducer->Table->MoveBy(ProducercxLookupComboBox->ItemIndex);
	REM_DMSprProducerModelGrp->OpenTable(DMSprProducer->TableID_SPRODUCER->AsLargeInt);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::GroupcxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (REM_DMSprProducerModelGrp->Table->Active==true)
	{
	REM_DMSprProducerModelGrp->Table->First();
	REM_DMSprProducerModelGrp->Table->MoveBy(GroupcxLookupComboBox->ItemIndex);
	REM_DMSprProducerModel->OpenTable(DMSprProducer->TableID_SPRODUCER->AsLargeInt, REM_DMSprProducerModelGrp->TableID_REM_SPRMODEL_GRP->AsLargeInt, false);
	}
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaInfoPriem::TypeDevice2cxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (REM_DMSprTypeDevice->Table->Active==true)
	{
	REM_DMSprTypeDevice->Table->First();
	REM_DMSprTypeDevice->Table->MoveBy(TypeDevice2cxLookupComboBox->ItemIndex);
	REM_DMSprModel2Grp->OpenTable(REM_DMSprTypeDevice->TableID_REM_STYPEDEVICE->AsLargeInt);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::GroupModel2cxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (REM_DMSprModel2Grp->Table->Active==true)
	{
	REM_DMSprModel2Grp->Table->First();
	REM_DMSprModel2Grp->Table->MoveBy(GroupModel2cxLookupComboBox->ItemIndex);
	REM_DMSprModel2->OpenTable(REM_DMSprTypeDevice->TableID_REM_STYPEDEVICE->AsLargeInt,REM_DMSprModel2Grp->TableID_REM_SMODEL2_GRP->AsLargeInt, false);
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::cxButtonUpdateInfblockClick(TObject *Sender)

{

if (REM_DMSprModel2->Table->Active==true)
	{
	REM_DMSprModel2->Table->First();
	REM_DMSprModel2->Table->MoveBy(Model2cxLookupComboBox->ItemIndex);
	}

if (REM_DMSprProducerModel->Table->Active==true)
	{
	REM_DMSprProducerModel->Table->First();
	REM_DMSprProducerModel->Table->MoveBy(PrModelcxLookupComboBox->ItemIndex);
	}

if (DMSprProducer->Table->Active==true)
		{
		DMSprProducer->Table->First();
		DMSprProducer->Table->MoveBy(ProducercxLookupComboBox->ItemIndex);
		}

if (DMSprBrand->Table->Active==true)
		{
		DMSprBrand->Table->First();
		DMSprBrand->Table->MoveBy(BrandcxLookupComboBox->ItemIndex);
		}


		DMInfo->DataSet->Active=false;
		DMInfo->DataSet->SelectSQL->Clear();
		DMInfo->DataSet->SelectSQL->Add("select *  ");
		DMInfo->DataSet->SelectSQL->Add("from rem_info_priem_get_info (:PARAM_IDMODEL2,:PARAM_IDPRMODEL,:PARAM_IDPRODUCER,:PARAM_IDBRAND,:PARAM_MODEL_TEXT) ");
		DMInfo->DataSet->ParamByName("PARAM_IDMODEL2")->AsString=REM_DMSprModel2->TableID_REM_SMODEL2->AsString;
		DMInfo->DataSet->ParamByName("PARAM_IDPRMODEL")->AsString=REM_DMSprProducerModel->TableID_REM_SPRMODEL->AsString;
		DMInfo->DataSet->ParamByName("PARAM_IDPRODUCER")->AsString=DMSprProducer->TableID_SPRODUCER->AsString;
		DMInfo->DataSet->ParamByName("PARAM_IDBRAND")->AsString=DMSprBrand->TableID_SBRAND->AsString;
		DMInfo->DataSet->ParamByName("PARAM_MODEL_TEXT")->AsString=ModelcxTextEdit->Text;
		DMInfo->DataSet->Active=true;

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::InfocxGridDBTableViewDblClick(TObject *Sender)

{
ShowPage();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::cxButtonUpdatePrInfBlockClick(TObject *Sender)

{

if (REM_DMSprModel2->Table->Active==true)
	{
	REM_DMSprModel2->Table->First();
	REM_DMSprModel2->Table->MoveBy(Model2cxLookupComboBox->ItemIndex);
	}

if (REM_DMSprProducerModel->Table->Active==true)
	{
	REM_DMSprProducerModel->Table->First();
	REM_DMSprProducerModel->Table->MoveBy(PrModelcxLookupComboBox->ItemIndex);
	}

if (DMSprProducer->Table->Active==true)
		{
		DMSprProducer->Table->First();
		DMSprProducer->Table->MoveBy(ProducercxLookupComboBox->ItemIndex);
		}

if (DMSprBrand->Table->Active==true)
		{
		DMSprBrand->Table->First();
		DMSprBrand->Table->MoveBy(BrandcxLookupComboBox->ItemIndex);
		}


		DMZip->DataSet->Active=false;
		DMZip->DataSet->SelectSQL->Clear();
		DMZip->DataSet->SelectSQL->Add("select *  ");
		DMZip->DataSet->SelectSQL->Add("from REM_INFO_PRIEM_GET_ZIP (:PARAM_IDMODEL2,:PARAM_IDPRMODEL,:PARAM_IDPRODUCER,:PARAM_IDBRAND,:PARAM_MODEL_TEXT) ");
		DMZip->DataSet->ParamByName("PARAM_IDMODEL2")->AsString=REM_DMSprModel2->TableID_REM_SMODEL2->AsString;
		DMZip->DataSet->ParamByName("PARAM_IDPRMODEL")->AsString=REM_DMSprProducerModel->TableID_REM_SPRMODEL->AsString;
		DMZip->DataSet->ParamByName("PARAM_IDPRODUCER")->AsString=DMSprProducer->TableID_SPRODUCER->AsString;
		DMZip->DataSet->ParamByName("PARAM_IDBRAND")->AsString=DMSprBrand->TableID_SBRAND->AsString;
		DMZip->DataSet->ParamByName("PARAM_MODEL_TEXT")->AsString=ModelcxTextEdit->Text;
		DMZip->DataSet->Active=true;

}
//---------------------------------------------------------------------------

void TREM_FormaInfoPriem::ShowPage(void)
{

if (glStrToInt64(DMInfo->DataSet->FieldByName("OUT_ISTOCHNIK")->AsString) == 304 ||
		glStrToInt64(DMInfo->DataSet->FieldByName("OUT_ISTOCHNIK")->AsString) == 302	)
	{
	if (FormaSpiskaSprInfBlockSostav==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaSpiskaSprInfBlockSostav,IID_IART_FormaSpiskaSprInfBlockSostav,
													 (void**)&FormaSpiskaSprInfBlockSostav);
		FormaSpiskaSprInfBlockSostav->Init(InterfaceMainObject,InterfaceImpl);


			FormaSpiskaSprInfBlockSostav->IdPage=glStrToInt64(DMInfo->DataSet->FieldByName("OUT_ID_INF_BLOCK")->AsString);
			FormaSpiskaSprInfBlockSostav->DM->OpenTable(glStrToInt64(DMInfo->DataSet->FieldByName("OUT_ID_INF_BLOCK")->AsString));
			FormaSpiskaSprInfBlockSostav->HeaderText=DMInfo->DataSet->FieldByName("OUT_ID_INF_BLOCK")->AsString;


			FormaSpiskaSprInfBlockSostav->UpdateForm();
			FormaSpiskaSprInfBlockSostav->NumberProcVibor=ER_ShowPage;
		}
	}



}
//---------------------------------------------------------------------------
void TREM_FormaInfoPriem::EndCloseFormShow(void)
{



}
//--------------------------------------------------------------------------

void __fastcall TREM_FormaInfoPriem::ToolButtonCreateZayavkaPredvClick(TObject *Sender)

{
IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->DM->GurZ->Edit();
REM_FormaZayavka->DM->GurZSERNUM1_REM_Z2->AsString=SerNumcxTextEdit->Text;
REM_FormaZayavka->DM->GurZSERNUM2_REM_Z2->AsString=SerNum2cxTextEdit->Text;
REM_FormaZayavka->DM->GurZ->Post();
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------














void __fastcall TREM_FormaInfoPriem::cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
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

if (ATextToDraw==1) //можно выдавать
	{
	ToolBar1->Images->GetBitmap(75,ABitmap);
	}
else if (ATextToDraw==2)  //выдано
	{
	ToolBar1->Images->GetBitmap(74,ABitmap);
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}

ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::cxButtonPoNumGarDocClick(TObject *Sender)
{
if (Trim(NumGarDoccxTextEdit->Text)!="")
	{
cxLabelHint->Caption="";

		DMGurZ->DataSet->Active=false;
		DMGurZ->DataSet->SelectSQL->Clear();
		DMGurZ->DataSet->SelectSQL->Add("select * from rem_info_priem_get_gur_z_all (0,'30.12.1899','30.12.1899',1,:PARAM_SERNUM,0)");
		DMGurZ->DataSet->SelectSQL->Add(" order by rem_info_priem_get_gur_z_all.out_pos");
		DMGurZ->DataSet->ParamByName("PARAM_SERNUM")->AsString=Trim(NumGarDoccxTextEdit->Text);
		DMGurZ->DataSet->Active=true;
		DMGurZ->DataSet->Last();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaInfoPriem::ToolButtonOpenGurAllDocClick(TObject *Sender)

{
if (DMGurZ->DataSet->FieldByName("OUT_TYPE_TABLE")->AsInteger==1)
	{

		IREM_FormaGurAllDoc * gur;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurAllDoc,IID_IREM_FormaGurAllDoc,
													(void**)&gur);
		gur->Init(InterfaceMainObject,InterfaceImpl);


		if (!gur) return;

		gur->PosNach=0;
        gur->PosCon=100000;

		gur->IdVibZayavka=glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString);
		gur->Zayavka_NameKlient=DMGurZ->DataSet->FieldByName("OUT_KLIENT_NAME")->AsString;
		gur->Zayavka_NameModel=DMGurZ->DataSet->FieldByName("OUT_MODEL")->AsString;
		gur->Zayavka_SerNum=DMGurZ->DataSet->FieldByName("OUT_SERNUM1")->AsString;
		gur->Zayavka_SerNum2=DMGurZ->DataSet->FieldByName("OUT_SERNUM2")->AsString;
		gur->UpdateForm();
		gur->DM->OpenTableOnlyZayavka(glStrToInt64(DMGurZ->DataSet->FieldByName("OUT_IDZ")->AsString));
	}
}
//---------------------------------------------------------------------------



