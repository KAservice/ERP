//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaGurZDop.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaZayavka.h"
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
#include "IAsyncExternalEvent.h"
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
#pragma link "cxContainer"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxButtonEdit"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurZDop::TREM_FormaGurZDop(TComponent* Owner)
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
}
//---------------------------------------------------------------------------
bool TREM_FormaGurZDop::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMGurZ.1",IID_IREM_DMGurZ, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

PosNach=0;
PosCon=Date();
unsigned short Year;
unsigned short Month;
unsigned short Day;
PosCon.DecodeDate(&Year,&Month,&Day);
PosNach=PosCon-Day+1;
PosCon++;
DM->PosNach=PosNach;
DM->PosCon=PosCon;

DM->OpenTable();
DM->Table->Last();
StrOtborLabel->Caption="";


Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);

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

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaGurZDop::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
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
DM->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaGurZDop::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
                        DM->PosNach=PosNach;
                        DM->PosCon=PosCon;
                        LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
                        }
                FormaViborPerioda=0;
                DM->UpdateTable();
                }

if (number_procedure_end==ER_ViborHardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
		}


return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaGurZDop::OpenFormDoc()
{

IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));
REM_FormaZayavka->UpdateForm();


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::FormResize(TObject *Sender)
{
		int TecSumWidth=cxGrid1->ClientWidth;

StrOtborLabel->Left=cxGrid1->Left+TecSumWidth-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurZDop::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurZDop::DeleteDoc(void)
{

////******************************************************

		IREM_DMZayavka * z;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavka.1",IID_IREM_DMZayavka,
								 (void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		if (!z) return;
        //настройка формы
		z->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));

		String V="Вы действительно хотите удалить Заявку №"
        +z->GurZNUM_REM_Z->AsString+" от "+z->GurZPOS_REM_Z->AsString+"?";
		String Z="Подтверждение удаления заявки";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (z->DeleteDoc(glStrToInt64(DM->TableID_REM_Z->AsString))==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить заявку!");
                        }
       z->kanRelease();

}

//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::ToolButtonViborPeriodaClick(
      TObject *Sender)
{

if (FormaViborPerioda==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborPerioda.1",IID_IFormaViborPerioda,
													(void**)&FormaViborPerioda);
		FormaViborPerioda->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborPerioda->NumberProcVibor=ViborPerioda;
		FormaViborPerioda->PosNach=PosNach;
		FormaViborPerioda->PosCon=PosCon;
//        FormaViborPerioda->Time1->Time=FormaViborPerioda->DateTimePicker1->Time;
//		FormaViborPerioda->Time2->Time=FormaViborPerioda->DateTimePicker2->Time;
		}

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurZDop::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Gur/GurAllDoc");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::ToolButtonAddNewZClick(TObject *Sender)
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


void __fastcall TREM_FormaGurZDop::ToolButton3Click(TObject *Sender)
{


//TREM_FormaZayavka * REM_FormaZayavka=new TREM_FormaZayavka(Application);


		IREM_FormaZayavkaDv * REM_FormaZayavkaDv;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavkaDv.1",IID_IREM_FormaZayavkaDv,
								 (void**)&REM_FormaZayavkaDv);
		REM_FormaZayavkaDv->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaZayavkaDv->Vibor=false;
		REM_FormaZayavkaDv->IdZ=glStrToInt64(DM->TableID_REM_Z->AsString);
		REM_FormaZayavkaDv->TextMessage="Заявка № "
		+DM->TableNUM_REM_Z->AsString+" от "+DM->TablePOS_REM_Z->AsString;
		REM_FormaZayavkaDv->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1DblClick(TObject *Sender)
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




void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1KeyPress(TObject *Sender,
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

void __fastcall TREM_FormaGurZDop::ToolButton5Click(TObject *Sender)
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
void __fastcall TREM_FormaGurZDop::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurZDop::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_Z->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1OUT_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1FL_TREB_KONS_KL_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZDop::cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZDop::PMCreateDocZPostClick(TObject *Sender)
{
		IREM_FormaDocZPost * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPost,IID_IREM_FormaDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZPOSTT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZVidClick(TObject *Sender)
{
		IREM_FormaDocZVid * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVid,IID_IREM_FormaDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZVIDT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZPerClick(TObject *Sender)
{
		IREM_FormaDocZPer * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZPer,IID_IREM_FormaDocZPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZPERT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZStartClick(TObject *Sender)
{
		IREM_FormaDocZStart * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZStart,IID_IREM_FormaDocZStart,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZSTART->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZEndClick(TObject *Sender)
{
		IREM_FormaDocZEnd * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZEnd,IID_IREM_FormaDocZEnd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZEND->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZOperClick(TObject *Sender)
{
		IREM_FormaDocZOper * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZOper,IID_IREM_FormaDocZOper,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZOPER->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZTrebClick(TObject *Sender)
{
		IREM_FormaDocZTreb * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZTreb,IID_IREM_FormaDocZTreb,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZTREB->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZAktPrClick(TObject *Sender)
{
		IREM_FormaDocZAktPr * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZAktPr,IID_IREM_FormaDocZAktPr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZAKTPR->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::PMCreateDocZVosvrZapClick(TObject *Sender)
{
		IREM_FormaDocZVosvrZap * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocZVosvrZap,IID_IREM_FormaDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DZVZAP->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::cxButtonPoiskPoSerNumClick(TObject *Sender)
{
DM->PoiskPoSerNum1(SerNumcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaGurZDop::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaGurZDop::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxTextEdit->Focused()==true)
	{
	SerNumcxTextEdit->Text=sh;
	}
else if(SerNum2cxTextEdit->Focused()==true)
	{
    SerNum2cxTextEdit->Text=sh;
	}


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::cxButtonPoiskPoSerNum2Click(TObject *Sender)
{
DM->PoiskPoSerNum2(SerNum2cxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::cxButtonPoiskPoModelClick(TObject *Sender)
{
DM->PoiskPoModel(ModelcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZDop::cxButtonPoiskPoKlientuClick(TObject *Sender)
{
DM->PoiskPoKlient(KlientNamecxTextEdit->Text);
}
//---------------------------------------------------------------------------
void TREM_FormaGurZDop::ViborHardware(void)
{

if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::EndViborHardware(void)
{

IREM_DMSprHardware * spr_hw;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardware,IID_IREM_DMSprHardware,
													(void**)&spr_hw);
spr_hw->Init(InterfaceMainObject,InterfaceImpl);
spr_hw->OpenElement(glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString));


IdVibHardware=glStrToInt64(FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString);
NameHardwarecxButtonEdit->Text=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
SerNumcxTextEdit->Text=FormaSpiskaSprHardware->DM->TableSERNUM_REM_SHARDWARE->AsString;
SerNum2cxTextEdit->Text=spr_hw->ElementSERNUM2_REM_SHARDWARE->AsString;
ModelcxTextEdit->Text=spr_hw->ElementNAME_REM_SMODEL->AsString;



spr_hw->kanRelease();
FormaSpiskaSprHardware=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZDop::cxButtonPoiskPoHardwareClick(TObject *Sender)
{
DM->PoiskPoIdHardware(IdVibHardware);
}
//---------------------------------------------------------------------------

