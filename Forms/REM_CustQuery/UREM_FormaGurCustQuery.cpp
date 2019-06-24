//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaGurCustQuery.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaCustQuery.h"
#include "IREM_FormaCustQueryDv.h"
#include "IREM_DMCustQuery.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
#include "IREM_DMZayavka.h"
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
#pragma link "cxCalendar"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurCustQuery::TREM_FormaGurCustQuery(TComponent* Owner)
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
bool TREM_FormaGurCustQuery::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMGurCustQuery,IID_IREM_DMGurCustQuery, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;


PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

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

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaGurCustQueryImpl),false);
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


		NameZayavkacxButtonEdit->Text="";
		NameKlientcxLabel->Caption="";
		NameModelcxLabel->Caption="";
		SerNumcxLabel->Caption="";
		SerNum2cxLabel->Caption="";

		NameProducercxButtonEdit->Text="";

		VibDatecxDateEdit->Date=Now();
result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaGurCustQuery::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurCustQuery::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();


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
void TREM_FormaGurCustQuery::UpdateForm(void)
{


		NameZayavkacxButtonEdit->Text=Zayavka_Name;
		NameKlientcxLabel->Caption=Zayavka_NameKlient;
		NameModelcxLabel->Caption=Zayavka_NameModel;
		SerNumcxLabel->Caption=Zayavka_SerNum;
		SerNum2cxLabel->Caption=Zayavka_SerNum2;

		DM->PosNach=PosNach;
		DM->PosCon=PosCon;
		LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);


}
//---------------------------------------------------------------------------
int TREM_FormaGurCustQuery::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

                }

        if (number_procedure_end==ER_Zayavka)
		{
		if (type_event==1)
				{
				EndViborRemZ();
				}
		FormaGurZ=0;
		}

if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer();
				}
		FormaSpiskaSprProducer=0;
		}

DM->UpdateTable();
return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaGurCustQuery::OpenFormDoc()
{

IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));
REM_FormaCustQuery->UpdateForm();


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::FormResize(TObject *Sender)
{
		int TecSumWidth=cxGrid1->ClientWidth;

StrOtborLabel->Left=cxGrid1->Left+TecSumWidth-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurCustQuery::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurCustQuery::DeleteDoc(void)
{

////******************************************************

		IREM_DMCustQuery * cq;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery,
								 (void**)&cq);
		cq->Init(InterfaceMainObject,InterfaceImpl);
		if (!cq) return;
        //настройка формы
		cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		String V="Вы действительно хотите удалить Запрос №"
		+cq->DocNUM_REM_CQUERY->AsString+" от "+cq->DocPOS_REM_CQUERY->AsString+"?";
		String Z="Подтверждение удаления заявки";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (cq->DeleteDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString))==true)
                        {
                        DM->UpdateTable();
                        }
                else
                        {
						ShowMessage("Не удалось удалить запрос!");
                        }
	   cq->kanRelease();

}

//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurCustQuery::ToolButtonViborPeriodaClick(
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

void __fastcall TREM_FormaGurCustQuery::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurCustQuery::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Gur/GurAllDoc");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonAddNewZClick(TObject *Sender)
{
IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->NewDoc();
REM_FormaCustQuery->UpdateForm();

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurCustQuery::ToolButton3Click(TObject *Sender)
{


//TREM_FormaZayavka * REM_FormaZayavka=new TREM_FormaZayavka(Application);

//
//		IREM_FormaCustQueryDv * REM_FormaCustqueryDv;
//		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQueryDv,IID_IREM_FormaCustQueryDv,
//								 (void**)&REM_FormaCustQueryDv);
//		REM_FormaCustQueryDv->Init(InterfaceMainObject,InterfaceImpl);
//		REM_FormaCustQueryDv->Vibor=false;
//		REM_FormaCustQueryDv->IdCQT=glStrToInt64(DM->TableID_REM_Z->AsString);
//		REM_FormaCustQueryDv->TextMessage="Запрос № "
//		+DM->TableNUM_REM_Z->AsString+" от "+DM->TablePOS_REM_Z->AsString;
//		REM_FormaCustQueryDv->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::cxGrid1DBTableView1DblClick(TObject *Sender)
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




void __fastcall TREM_FormaGurCustQuery::cxGrid1DBTableView1KeyPress(TObject *Sender,
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

//Внешние модули
void __fastcall TREM_FormaGurCustQuery::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurCustQuery::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_CQUERY->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);
module->SetInt64Variables("glIdProducer", IdVibProducer);
module->SetIntegerVariables("glNumberZakaza", StrToInt64(NumberZakazcxSpinEdit->Text));
module->SetDateTimeVariables("glDateZakaza", DateZakazcxDateEdit->Date);

module->ExecuteModule();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::cxGrid1DBTableView1RUN_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
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

void __fastcall TREM_FormaGurCustQuery::cxButtonPoiskPoModelClick(TObject *Sender)

{
DM->PoiskPoModel(ModelcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::cxButtonPoiskPoKlientuClick(TObject *Sender)

{
DM->PoiskPoModel(KlientNamecxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::cxButtonOtborPoZayavkaClick(TObject *Sender)

{
DM->OpenTableOnlyZayavka(IdVibZayavka);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//выбор заявки
void TREM_FormaGurCustQuery::ViborRemZ(void)
{

if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurCustQuery::EndViborRemZ(void)
{

IREM_DMZayavka *dm_z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavka,IID_IREM_DMZayavka, (void**)&dm_z);
dm_z->Init(InterfaceMainObject,InterfaceImpl);
dm_z->OpenDoc(glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString));

IdVibZayavka=glStrToInt64(FormaGurZ->DM->TableID_REM_Z->AsString);
NameZayavkacxButtonEdit->Text=FormaGurZ->DM->TableNAME_REM_Z->AsString;

NameKlientcxLabel->Caption=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
NameModelcxLabel->Caption=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
SerNumcxLabel->Caption=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
SerNum2cxLabel->Caption=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;

dm_z->kanRelease();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurCustQuery::NameZayavkacxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborRemZ();
		}break;
	case 1:
		{
		IdVibZayavka=0;
		NameZayavkacxButtonEdit->Text="";
		NameKlientcxLabel->Caption="";
		NameModelcxLabel->Caption="";
		SerNumcxLabel->Caption="";
		SerNum2cxLabel->Caption="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::cxGrid1DBTableView1FL_KLIENT_UVEDOML_REM_CQUERYCustomDrawCell(TcxCustomGridTableView *Sender,
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

void TREM_FormaGurCustQuery::ViborProducer(void)
{

if (FormaSpiskaSprProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&FormaSpiskaSprProducer);
		FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducer) return;
		FormaSpiskaSprProducer->Vibor=true;
		FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaGurCustQuery::EndViborProducer(void)
{


	IdVibProducer=glStrToInt64(FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString);
	NameProducercxButtonEdit->Text=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;


FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurCustQuery::NameProducercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducer();
		}break;
	case 1:
		{
		IdVibProducer=0;
		NameProducercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonOpenTrebZakazClick(TObject *Sender)

{
DM->OpenTableGur (0, 4,0,0,"",IdVibProducer);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonOpenPoNumberZakazClick(TObject *Sender)

{
DM->OpenTablePoNumZakaza (0,IdVibProducer, StrToInt(NumberZakazcxSpinEdit->Text), DateZakazcxDateEdit->Date);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetNumberDateZakazaClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);


//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=0)
		{
		ShowMessage("Ошибка! Номер заказа уже установлен! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (Trim(dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString)!="")
		{
		ShowMessage("Ошибка! Дата заказа уже установлена! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger=StrToInt(NumberZakazcxSpinEdit->Text);
		dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime=DateZakazcxDateEdit->Date;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetPredvZakazanoClick(TObject *Sender)
{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocRUN_REM_CQUERY->AsInteger=4; /*предварительно заказано*/
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetVipolnenoClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocRUN_REM_CQUERY->AsInteger=1; /*выполнено*/
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetOtpravlenoClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocRUN_REM_CQUERY->AsInteger=5; /*отправлено поставщиком*/
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}

	}
dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetTecPostupiloClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocPOSTUPILO_REM_CQUERY->AsDateTime=VibDatecxDateEdit->Date;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetPlanPostavkiClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocPLAN_POSTAVKI_REM_CQUERY->AsDateTime=VibDatecxDateEdit->Date;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurCustQuery::ToolButtonSetZakazanoClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocZAKAZANO_REM_CQUERY->AsDateTime=VibDatecxDateEdit->Date;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurCustQuery::ToolButtonSetDateOtpravlenoClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);

//необходимо проверить нет ли ошибки

bool err=false;
DM->Table->First();

while (!DM->Table->Eof)
	{
	dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));


	if (dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsInteger!=StrToInt(NumberZakazcxSpinEdit->Text))
		{
		ShowMessage("Ошибка! В запросе другой номер заказа! "+dm_cq->DocNUM_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}


	if (dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsDateTime!=DateZakazcxDateEdit->Date)
		{
		ShowMessage("Ошибка! В запросе другая дата заказа! "+dm_cq->DocDATE_ZAKAZA_REM_CQUERY->AsString);
		err=true;
		}

	if (glStrToInt64(dm_cq->DocIDPRODUCER_REM_CQUERY->AsString)!=IdVibProducer)
		{
		ShowMessage("Ошибка! В заказе не тот производитель, который выбран! ");
		err=true;
		}

	DM->Table->Next();
	}

if (err==false)
	{
	DM->Table->First();

	while (!DM->Table->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->TableID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocOTPRAVLENO_REM_CQUERY->AsDateTime=VibDatecxDateEdit->Date;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->Table->Next();
		}
	}

dm_cq->kanRelease();
}
//---------------------------------------------------------------------------

