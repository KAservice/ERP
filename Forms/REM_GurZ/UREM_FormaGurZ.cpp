//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaGurZ.h"
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
#include "IREM_FormaGurAllDoc.h"

#include "IREM_FormaCustQuery.h"
#include "IREM_FormaGurCustQueryDetal.h"

#include "IREM_FormaDocVidachaHW.h"
#include "IREM_FormaDocVosvratHW.h"

#include "IAsyncExternalEvent.h"
#include "IDMSetup.h"
#include "IFormaImageEditor.h"
#include "IDMQueryRead.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurZ::TREM_FormaGurZ(TComponent* Owner)
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
bool TREM_FormaGurZ::Init(void)
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

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;

DM->OpenTable();
DM->Table->Last();
StrOtborLabel->Caption="";
NameSkladcxButtonEdit->Text="";

Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);
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

LoadFormSetup();

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaGurZ::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZ::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();

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
int TREM_FormaGurZ::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaGurZ::OpenFormDoc()
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

void __fastcall TREM_FormaGurZ::FormResize(TObject *Sender)
{
		int TecSumWidth=cxGrid1->ClientWidth;

StrOtborLabel->Left=cxGrid1->Left+TecSumWidth-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurZ::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurZ::DeleteDoc(void)
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
void __fastcall TREM_FormaGurZ::ToolButtonViborPeriodaClick(
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

void __fastcall TREM_FormaGurZ::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurZ::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Gur/GurAllDoc");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonAddNewZClick(TObject *Sender)
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


void __fastcall TREM_FormaGurZ::ToolButton3Click(TObject *Sender)
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1DblClick(TObject *Sender)
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




void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1KeyPress(TObject *Sender,
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

void __fastcall TREM_FormaGurZ::ToolButton5Click(TObject *Sender)
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
void __fastcall TREM_FormaGurZ::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurZ::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdZayvka", glStrToInt64(DM->TableID_REM_Z->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1OUT_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else if (ATextToDraw==4)  //отремонтировано
	{
	ToolBar1->Images->GetBitmap(58,ABitmap);  //к выдаче без ремонта
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1FL_TREB_KONS_KL_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZ::PMCreateDocZPostClick(TObject *Sender)
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
		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->TableIDBASE_REM_Z->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->TableNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->TableIDFIRM_REM_Z->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->TableNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->TableIDSKLPR_REM_Z->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->TableNAME_SKLAD_PR->AsString;
		doc->DM->DocAll->Post();

		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZPOSTT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocTNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->DocTKOL_REM_DZPOSTT->AsFloat=1;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZVidClick(TObject *Sender)
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
		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->TableIDBASE_REM_Z->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->TableNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->TableIDFIRM_REM_Z->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->TableNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->TableIDSKLPR_REM_Z->AsString;
		doc->DM->DocAllNAMESKLAD->AsString=DM->TableNAME_SKLAD_PR->AsString;
		doc->DM->DocAll->Post();

		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZVIDT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocTNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->DocTKOL_REM_DZVIDT->AsFloat=1;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZPerClick(TObject *Sender)
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

		doc->DM->DocAll->Edit();
		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->TableIDBASE_REM_Z->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->TableNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->TableIDFIRM_REM_Z->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->TableNAMEFIRM->AsString;
		//doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=DM->TableIDSKLPR_REM_Z->AsString;
		//doc->DM->DocAllNAMESKLAD->AsString=DM->TableNAME_SKLAD_PR->AsString;
		doc->DM->DocAll->Post();

		doc->DM->DocT->Append();
		doc->DM->DocT->Edit();
		doc->DM->DocTIDZ_REM_DZPERT->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocTNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocTPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocTSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocTMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocTKLIENT_NAME_REM_Z->AsString=DM->TableKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocTNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->DocTKOL_REM_DZPERT->AsFloat=1;
		doc->DM->DocT->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZStartClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZEndClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZOperClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZTrebClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZAktPrClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->DocPOSPRIEMA_REM_DZAKTPR->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocZVosvrZapClick(TObject *Sender)
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
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonOpenGurAllDocClick(TObject *Sender)
{
		IREM_FormaGurAllDoc * gur;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurAllDoc,IID_IREM_FormaGurAllDoc,
													(void**)&gur);
		gur->Init(InterfaceMainObject,InterfaceImpl);


		if (!gur) return;

		gur->PosNach=0;
        gur->PosCon=100000;

		gur->IdVibZayavka=glStrToInt64(DM->TableID_REM_Z->AsString);
		gur->Zayavka_Name=DM->TableNAME_REM_Z->AsString;

		gur->Zayavka_NameKlient=DM->TableKLIENT_NAME_REM_Z->AsString;
		gur->Zayavka_NameModel=DM->TableMODEL_REM_Z->AsString;
		gur->Zayavka_SerNum=DM->TableSERNUM_REM_Z->AsString;
		gur->Zayavka_SerNum2=DM->TableSERNUM2_REM_Z->AsString;
		gur->UpdateForm();
		gur->DM->OpenTableOnlyZayavka(glStrToInt64(DM->TableID_REM_Z->AsString));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TREM_FormaGurZ::ViborHardware(void)
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
void __fastcall TREM_FormaGurZ::EndViborHardware(void)
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
void __fastcall TREM_FormaGurZ::cxButtonPoiskPoSerNumClick(TObject *Sender)
{
DM->PoiskPoSerNum1(SerNumcxTextEdit->Text);
cxLabelHint->Caption="";
if (cxCheckBoxIspSprHardware->Checked==true)
	{ //ищем в справочнике Оборудование
	IREM_DMSprHardware *h;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&h);
	h->Init(InterfaceMainObject,InterfaceImpl);

	h->Table_FindPoSerNum1Like(0,true, SerNumcxTextEdit->Text);
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
	}


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaGurZ::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaGurZ::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxTextEdit->Focused()==true)
	{
	SerNumcxTextEdit->Text=Trim(sh);
	}
else if(SerNum2cxTextEdit->Focused()==true)
	{
    SerNum2cxTextEdit->Text=Trim(sh);
	}


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZ::cxButtonPoiskPoSerNum2Click(TObject *Sender)
{
DM->PoiskPoSerNum2(SerNum2cxTextEdit->Text);

cxLabelHint->Caption="";
if (cxCheckBoxIspSprHardware->Checked==true)
	{ //ищем в справочнике Оборудование
	IREM_DMSprHardware *h;
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&h);
	h->Init(InterfaceMainObject,InterfaceImpl);

	h->Table_FindPoSerNum2Like(0,true, SerNum2cxTextEdit->Text);
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
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxButtonPoiskPoModelClick(TObject *Sender)
{
DM->PoiskPoModel(ModelcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxButtonPoiskPoKlientuClick(TObject *Sender)
{
DM->PoiskPoKlient(KlientNamecxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxButtonPoiskPoHardwareClick(TObject *Sender)
{
DM->PoiskPoIdHardware(IdVibHardware);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxButtonPoNumGarDocClick(TObject *Sender)
{
DM->PoiskPoNumGarDoc(NumGarDoccxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonCreateNewNaOsnDanFormClick(TObject *Sender)

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

void __fastcall TREM_FormaGurZ::ToolButtonCopyZayavkaClick(TObject *Sender)
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

z->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));

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

void __fastcall TREM_FormaGurZ::ToolButtonZapShapkuNaOsnZayavkiClick(TObject *Sender)

{
IREM_DMZayavka *z;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavka.1",IID_IREM_DMZayavka, (void**)&z);
z->Init(InterfaceMainObject,InterfaceImpl);

z->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));

SerNumcxTextEdit->Text=z->GurZSERNUM_REM_Z->AsString;
SerNum2cxTextEdit->Text=z->GurZSERNUM2_REM_Z->AsString;
NumGarDoccxTextEdit->Text=z->GurZNUM_GARDOC_REM_Z->AsString;

z->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonOpenNewClick(TObject *Sender)
{

DM->PosNach=PosNach;
DM->PosCon=PosCon;

DM->OpenTable();
DM->Table->Last();
StrOtborLabel->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonCreateNaOsnSprHardwareClick(TObject *Sender)

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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1SOST_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZ::ToolButtonOpenCQueryClick(TObject *Sender)
{
IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));
REM_FormaCustQuery->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1ID_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
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

if (glStrToInt64(ATextToDraw) > 0) //есть запрос
	{
	ToolBar1->Images->GetBitmap(70,ABitmap);
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

void __fastcall TREM_FormaGurZ::ToolButtonOpenGurCQueryClick(TObject *Sender)
{
IREM_FormaGurCustQueryDetal * REM_FormaGurCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurCustQueryDetal,IID_IREM_FormaGurCustQueryDetal,
								 (void**)&REM_FormaGurCustQuery);
REM_FormaGurCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaGurCustQuery) return;
REM_FormaGurCustQuery->PosNach=DM->TablePOS_REM_Z->AsDateTime;
REM_FormaGurCustQuery->DM->OpenTableOnlyZayavka(glStrToInt64(DM->TableID_REM_Z->AsString));

REM_FormaGurCustQuery->Zayavka_NameKlient=DM->TableKLIENT_NAME_REM_Z->AsString;
REM_FormaGurCustQuery->Zayavka_NameModel=DM->TableMODEL_REM_Z->AsString;
REM_FormaGurCustQuery->Zayavka_SerNum=DM->TableSERNUM_REM_Z->AsString;
REM_FormaGurCustQuery->Zayavka_SerNum2=DM->TableSERNUM2_REM_Z->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1IDREC_RGOTPRZCustomDrawCell(TcxCustomGridTableView *Sender,
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

if (glStrToInt64(ATextToDraw) > 0) //есть запрос
	{
	ToolBar1->Images->GetBitmap(79,ABitmap);
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
void TREM_FormaGurZ::ViborSklad(void)
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
void __fastcall TREM_FormaGurZ::EndViborSklad(void)
{


	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZ::NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaGurZ::ToolButtonOpenOnlySkladClick(TObject *Sender)
{
DM->OpenTableOtbor(0,0,7,"",IdSklad);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonOpenVPutiClick(TObject *Sender)
{
DM->OpenTableOtbor(0,0,8,"",0);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonOpenAllSkladClick(TObject *Sender)
{
DM->OpenTableOtbor(0,0,9,"",0);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocVidachaHWClick(TObject *Sender)
{
		IREM_FormaDocVidachaHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVidachaHW,IID_IREM_FormaDocVidachaHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;

		IREM_DMZayavka * z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka,
													(void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		z->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DVIDACHA_HW->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->DocKLIENT_NAME_REM_DVIDACHA_HW->AsString=z->GurZKLIENT_NAME_REM_Z->AsString;
		doc->DM->DocKLIENT_ADR_REM_DVIDACHA_HW->AsString=z->GurZKLIENT_ADR_REM_Z->AsString;
		doc->DM->DocKLIENT_PHONE_REM_DVIDACHA_HW->AsString=z->GurZKLIENT_PHONE_REM_Z->AsString;
		doc->DM->Doc->Post();

	   z->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::PMCreateDocVosvratHWClick(TObject *Sender)
{
		IREM_FormaDocVosvratHW * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocVosvratHW,IID_IREM_FormaDocVosvratHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
	   //	doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->NewDoc();
		doc->UpdateForm();
		doc->DM->Doc->Edit();
		doc->DM->DocIDZ_REM_DVOSVRAT_HW->AsString=DM->TableID_REM_Z->AsString;
		doc->DM->DocNUM_REM_Z->AsInteger=DM->TableNUM_REM_Z->AsInteger;
		doc->DM->DocPOS_REM_Z->AsDateTime=DM->TablePOS_REM_Z->AsDateTime;
		doc->DM->DocSERNUM_REM_Z->AsString=DM->TableSERNUM_REM_Z->AsString;
		doc->DM->DocMODEL_REM_Z->AsString=DM->TableMODEL_REM_Z->AsString;
		doc->DM->DocNAME_REM_Z->AsString=DM->TableNAME_REM_Z->AsString;
		doc->DM->Doc->Post();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1IDDOC_VIDACHA_HWCustomDrawCell(TcxCustomGridTableView *Sender,
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

if (glStrToInt64(ATextToDraw) > 0) //есть запрос
	{
	ToolBar1->Images->GetBitmap(80,ABitmap);
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1IDDOC_VOSVRAT_HWCustomDrawCell(TcxCustomGridTableView *Sender,
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

if (glStrToInt64(ATextToDraw) > 0) //есть запрос
	{
	ToolBar1->Images->GetBitmap(81,ABitmap);
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

void __fastcall TREM_FormaGurZ::cxGrid1DBTableView1FL_POVTORCustomDrawCell(TcxCustomGridTableView *Sender,
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

if (ATextToDraw==1) //повтор
	{
	ToolBar1->Images->GetBitmap(56,ABitmap);
	}
else if (ATextToDraw==2) // обратить внимание
	{
	ToolBar1->Images->GetBitmap(57,ABitmap);
	}
else if (ATextToDraw==3)  //санкции
	{
	ToolBar1->Images->GetBitmap(58,ABitmap);
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

void __fastcall TREM_FormaGurZ::ToolButtonCopyInClipboardClick(TObject *Sender)
{
		IREM_DMZayavka * z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka,
													(void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		z->OpenDoc(glStrToInt64(DM->TableID_REM_Z->AsString));

UnicodeString s="";

s=s+"ID заявки: "+DM->TableID_REM_Z->AsString+" Номер: "+z->GurZPREFIKS_NUM_REM_Z->AsString+z->GurZNUM_REM_Z->AsString+" Дата поступления: "+z->GurZPOS_REM_Z->AsString+"\n";
s=s+"Модель: "+z->GurZMODEL_REM_Z->AsString+" "+z->GurZSERNUM_REM_Z->AsString+" "+z->GurZSERNUM2_REM_Z->AsString+" "+z->GurZ_1SERNUM3_REM_Z_1->AsString+"\n";
s=s+"Клиент: "+z->GurZKLIENT_NAME_REM_Z->AsString+" Адрес: "+z->GurZKLIENT_ADR_REM_Z->AsString+" Телефон: "+z->GurZKLIENT_PHONE_REM_Z->AsString+"\n";


int v_remonte=Now() - z->GurZPOS_REM_Z->AsDateTime+1;
s=s+"Продавец: "+z->GurZ_1NAME_SSELLER->AsString+" Продан: "+z->GurZ_1DATE_PRODAGI_REM_Z_1->AsString+" В ремонте "+IntToStr(v_remonte)+"дн.\n";

s=s+"Жалоба: "+z->GurZNEISPR_REM_Z->AsString+"\n";

if (z->GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1->AsInteger==1)
	{
	s=s+"Диагностика: ДА \n";
	}
else
	{
	s=s+"Диагностика: НЕТ \n";
	}

s=s+"Мастер:\n";
z->PerformedWork->First();
while(!z->PerformedWork->Eof)
	{
	s=s+z->PerformedWorkPOS_REM_ZPERFWORK->AsString+"  "+z->PerformedWorkTEXTNOM_REM_ZPERFWORK->AsString+"\n";
	z->PerformedWork->Next();
	}

s=s+"  "+z->GurZDESCR_REM_Z->AsString+"\n";



	   z->kanRelease();

Clipboard()->AsText=s;


}
//---------------------------------------------------------------------------
void TREM_FormaGurZ::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);

dm->SaveSetupInt("REM_FormaGurZ","flSave", 1);

dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z",
				 cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z",
				 cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z",
				 cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_POVTOR",
				 cxGrid1DBTableView1FL_POVTOR->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_ADDREPORT",
				 cxGrid1DBTableView1FL_ADDREPORT->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_NADO_OTCH_REM_Z",
				 cxGrid1DBTableView1FL_NADO_OTCH_REM_Z->Visible);

dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_NE_OTCH_REM_Z",
				 cxGrid1DBTableView1FL_NE_OTCH_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SBRAND",
				 cxGrid1DBTableView1NAME_SBRAND->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_STREMONT",
				 cxGrid1DBTableView1NAME_STREMONT->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SINFBASE_OBMEN",
				 cxGrid1DBTableView1NAME_SINFBASE_OBMEN->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEFIRM",
				 cxGrid1DBTableView1NAMEFIRM->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1PREFIKS_NUM_REM_Z",
				 cxGrid1DBTableView1PREFIKS_NUM_REM_Z->Visible);

dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NUM_REM_Z",
				 cxGrid1DBTableView1NUM_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1POS_REM_Z",
				 cxGrid1DBTableView1POS_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SKLAD_PR",
				 cxGrid1DBTableView1NAME_SKLAD_PR->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SKLAD_OST",
				 cxGrid1DBTableView1NAME_SKLAD_OST->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDREC_RGOTPRZ",
				 cxGrid1DBTableView1IDREC_RGOTPRZ->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_REM_SMODEL",
				 cxGrid1DBTableView1NAME_REM_SMODEL->Visible);

dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1MODEL_REM_Z",
				 cxGrid1DBTableView1MODEL_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SERNUM_REM_Z",
				 cxGrid1DBTableView1SERNUM_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SERNUM2_REM_Z",
				 cxGrid1DBTableView1SERNUM2_REM_Z->Visible);



dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_REMSSOST",
				 cxGrid1DBTableView1NAME_REMSSOST->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SUM_REM_Z",
				 cxGrid1DBTableView1SUM_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEKLIENT",
				 cxGrid1DBTableView1NAMEKLIENT->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1KLIENT_NAME_REM_Z",
				 cxGrid1DBTableView1KLIENT_NAME_REM_Z->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEDILER",
				 cxGrid1DBTableView1NAMEDILER->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SOST_CQUERY",
				 cxGrid1DBTableView1SOST_CQUERY->Visible);

dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1ID_REM_CQUERY",
				 cxGrid1DBTableView1ID_REM_CQUERY->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDDOC_VIDACHA_HW",
				 cxGrid1DBTableView1IDDOC_VIDACHA_HW->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDDOC_VOSVRAT_HW",
				 cxGrid1DBTableView1IDDOC_VOSVRAT_HW->Visible);


dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SROK_REMONTA",
				 cxGrid1DBTableView1SROK_REMONTA->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SROK_REMONTA_NOW",
				 cxGrid1DBTableView1SROK_REMONTA_NOW->Visible);
dm->SaveSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_FICTIV_REM_Z",
				 cxGrid1DBTableView1FL_FICTIV_REM_Z->Visible);






				 dm->kanRelease();
}
//---------------------------------------------------------------------------
void TREM_FormaGurZ::LoadFormSetup(void)
{
//NoUpdateForm=true;

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);

int fl_save=dm->LoadSetupInt64("REM_FormaGurZ","flSave");

if (fl_save==1)
	{

	cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_Z");
	cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_TREB_KONS_KL_REM_Z");
	cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_KL_OTV_NA_ZAPROS_REM_Z");

	cxGrid1DBTableView1FL_POVTOR->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_POVTOR");
	cxGrid1DBTableView1FL_ADDREPORT->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_ADDREPORT");
	cxGrid1DBTableView1FL_NADO_OTCH_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_NADO_OTCH_REM_Z");

	cxGrid1DBTableView1FL_NE_OTCH_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_NE_OTCH_REM_Z");
	cxGrid1DBTableView1NAME_SBRAND->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SBRAND");
	cxGrid1DBTableView1NAME_STREMONT->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_STREMONT");


	cxGrid1DBTableView1NAME_SINFBASE_OBMEN->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SINFBASE_OBMEN");
	cxGrid1DBTableView1NAMEFIRM->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEFIRM");
	cxGrid1DBTableView1PREFIKS_NUM_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1PREFIKS_NUM_REM_Z");

	cxGrid1DBTableView1NUM_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NUM_REM_Z");
	cxGrid1DBTableView1POS_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1POS_REM_Z");
	cxGrid1DBTableView1NAME_SKLAD_PR->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SKLAD_PR");

	cxGrid1DBTableView1NAME_SKLAD_OST->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_SKLAD_OST");
	cxGrid1DBTableView1IDREC_RGOTPRZ->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDREC_RGOTPRZ");
	cxGrid1DBTableView1NAME_REM_SMODEL->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_REM_SMODEL");


	cxGrid1DBTableView1MODEL_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1MODEL_REM_Z");
	cxGrid1DBTableView1SERNUM_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SERNUM_REM_Z");
	cxGrid1DBTableView1SERNUM_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SERNUM_REM_Z");


	cxGrid1DBTableView1SERNUM2_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SERNUM2_REM_Z");
	cxGrid1DBTableView1NAME_REMSSOST->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAME_REMSSOST");
	cxGrid1DBTableView1SUM_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SUM_REM_Z");

	cxGrid1DBTableView1NAMEKLIENT->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEKLIENT");
	cxGrid1DBTableView1KLIENT_NAME_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1KLIENT_NAME_REM_Z");
	cxGrid1DBTableView1NAMEDILER->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1NAMEDILER");


	cxGrid1DBTableView1SOST_CQUERY->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SOST_CQUERY");
	cxGrid1DBTableView1ID_REM_CQUERY->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1ID_REM_CQUERY");
	cxGrid1DBTableView1IDDOC_VIDACHA_HW->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDDOC_VIDACHA_HW");


	cxGrid1DBTableView1IDDOC_VOSVRAT_HW->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1IDDOC_VOSVRAT_HW");
	cxGrid1DBTableView1SROK_REMONTA->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SROK_REMONTA");
	cxGrid1DBTableView1SROK_REMONTA_NOW->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1SROK_REMONTA_NOW");


	cxGrid1DBTableView1FL_FICTIV_REM_Z->Visible=
		dm->LoadSetupBool("REM_FormaGurZ","cxGrid1DBTableView1FL_FICTIV_REM_Z");






	}

dm->kanRelease();
//NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZ::ToolButtonSaveUserSetupClick(TObject *Sender)
{
SaveFormSetup();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonOpenGarTalonClick(TObject *Sender)
{
IDMSetup * DMSetup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
													(void**)&DMSetup);
DMSetup->Init(InterfaceMainObject,0);
UnicodeString file_name="";
DMSetup->OpenElement(330);
file_name=DMSetup->ElementVALUE_SETUP->AsString;
DMSetup->kanRelease();

WORD Year;
WORD Month;
WORD Day;
DecodeDate(DM->TablePOS_REM_Z->AsDateTime,Year,Month,Day);


file_name=file_name+"\\"+DM->TableIDBASE_REM_Z->AsString         // база заявки
					+"\\Garant"
					+"\\"+DM->TableNAME_SBRAND->AsString
					+"\\"+IntToStr(Month)+"_"+IntToStr(Year)
					+"\\"+DM->TableSERNUM_REM_Z->AsString
					+".jpg";                                                  //месяц

ShowMessage(file_name);

IFormaImageEditor * ed;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaImageEditor,IID_IFormaImageEditor,
													(void**)&ed);
ed->Init(InterfaceMainObject,0);
ed->LoadFromFile(file_name);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZ::ToolButtonSetNullInCustQueryClick(TObject *Sender)

{
IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

REM_FormaCustQuery->DM->Doc->Edit();
REM_FormaCustQuery->DM->DocIDZ_REM_CQUERY->Clear();
REM_FormaCustQuery->DM->Doc->Post();

REM_FormaCustQuery->DM->SaveDoc();
REM_FormaCustQuery->UpdateForm();
}
//---------------------------------------------------------------------------

