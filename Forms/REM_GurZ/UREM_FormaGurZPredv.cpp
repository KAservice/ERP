//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaGurZPredv.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaZayavkaPredv.h"
#include "IREM_DMZayavka.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"


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
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurZPredv::TREM_FormaGurZPredv(TComponent* Owner)
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
bool TREM_FormaGurZPredv::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMGurZPredv,IID_IREM_DMGurZPredv, (void**)&DM);
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

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaGurZPredvImpl),false);
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
int TREM_FormaGurZPredv::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZPredv::FormClose(TObject *Sender,
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
int TREM_FormaGurZPredv::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
void TREM_FormaGurZPredv::OpenFormDoc()
{

IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->TableID_REM_Z2->AsString));
REM_FormaZayavka->UpdateForm();


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::FormResize(TObject *Sender)
{
		int TecSumWidth=cxGrid1->ClientWidth;

StrOtborLabel->Left=cxGrid1->Left+TecSumWidth-StrOtborLabel->Width ;

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurZPredv::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurZPredv::DeleteDoc(void)
{

////******************************************************

		IREM_DMZayavkaPredv * z;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_DMZayavkaPredv,
								 (void**)&z);
		z->Init(InterfaceMainObject,InterfaceImpl);
		if (!z) return;
        //настройка формы
		z->OpenDoc(glStrToInt64(DM->TableID_REM_Z2->AsString));

		String V="Вы действительно хотите удалить Заявку №"
		+z->GurZNUM_REM_Z2->AsString+" от "+z->GurZPOS_REM_Z2->AsString+"?";
		String Z="Подтверждение удаления заявки";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }


				if (z->DeleteDoc(glStrToInt64(DM->TableID_REM_Z2->AsString))==true)
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
void __fastcall TREM_FormaGurZPredv::ToolButtonViborPeriodaClick(
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

void __fastcall TREM_FormaGurZPredv::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurZPredv::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Gur/GurAllDoc");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonAddNewZClick(TObject *Sender)
{
IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->UpdateForm();

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaGurZPredv::cxGrid1DBTableView1DblClick(TObject *Sender)
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




void __fastcall TREM_FormaGurZPredv::cxGrid1DBTableView1KeyPress(TObject *Sender,
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

void __fastcall TREM_FormaGurZPredv::ToolButton5Click(TObject *Sender)
{
IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaGurZPredv::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurZPredv::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_Z2->AsString));
module->SetInt64Variables("glIdZayvka", glStrToInt64(DM->TableID_REM_Z2->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------













//---------------------------------------------------------------------------
void TREM_FormaGurZPredv::ViborHardware(void)
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
void __fastcall TREM_FormaGurZPredv::EndViborHardware(void)
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
void __fastcall TREM_FormaGurZPredv::cxButtonPoiskPoSerNumClick(TObject *Sender)
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

void __fastcall TREM_FormaGurZPredv::FormActivate(TObject *Sender)
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

void __fastcall TREM_FormaGurZPredv::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaGurZPredv::ReadShtrihCodEvent(int number, UnicodeString sh)
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
void __fastcall TREM_FormaGurZPredv::cxButtonPoiskPoSerNum2Click(TObject *Sender)
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

void __fastcall TREM_FormaGurZPredv::cxButtonPoiskPoModelClick(TObject *Sender)
{
DM->PoiskPoModel(ModelcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::cxButtonPoiskPoKlientuClick(TObject *Sender)
{
DM->PoiskPoKlient(KlientNamecxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::cxButtonPoiskPoHardwareClick(TObject *Sender)
{
DM->PoiskPoIdHardware(IdVibHardware);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::cxButtonPoNumGarDocClick(TObject *Sender)
{
DM->PoiskPoNumGarDoc(NumGarDoccxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonCreateNewNaOsnDanFormClick(TObject *Sender)

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

void __fastcall TREM_FormaGurZPredv::ToolButtonCopyZayavkaClick(TObject *Sender)
{
IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->NewDoc();

IREM_DMZayavkaPredv *z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavkaPredv,IID_IREM_DMZayavkaPredv, (void**)&z);
z->Init(InterfaceMainObject,InterfaceImpl);

z->OpenDoc(glStrToInt64(DM->TableID_REM_Z2->AsString));

REM_FormaZayavka->DM->GurZ->Edit();


REM_FormaZayavka->DM->GurZIDKLIENT_REM_Z2->AsString=z->GurZIDKLIENT_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZNAMEKLIENT->AsString=z->GurZNAMEKLIENT->AsString;
REM_FormaZayavka->DM->GurZKLIENT_NAME_REM_Z2->AsString=z->GurZKLIENT_NAME_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZKLIENT_ADR_REM_Z2->AsString=z->GurZKLIENT_ADR_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZKLIENT_PHONE_REM_Z2->AsString=z->GurZKLIENT_PHONE_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZIDMODEL_REM_Z2->AsString=z->GurZIDMODEL_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZNAME_REM_SMODEL->AsString=z->GurZNAME_REM_SMODEL->AsString;
REM_FormaZayavka->DM->GurZMODEL_STR_REM_Z2->AsString=z->GurZMODEL_STR_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZSERNUM1_REM_Z2->AsString=z->GurZSERNUM1_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZSERNUM2_REM_Z2->AsString=z->GurZSERNUM2_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZSOST_REM_Z2->AsString=z->GurZSOST_REM_Z2->AsString;
REM_FormaZayavka->DM->GurZNEISPR_REM_Z2->AsString=z->GurZNEISPR_REM_Z2->AsString;

REM_FormaZayavka->DM->GurZ->Post();

REM_FormaZayavka->UpdateForm();

z->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonZapShapkuNaOsnZayavkiClick(TObject *Sender)

{
IREM_DMZayavkaPredv *z;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavkaPredv,IID_IREM_DMZayavkaPredv, (void**)&z);
z->Init(InterfaceMainObject,InterfaceImpl);

z->OpenDoc(glStrToInt64(DM->TableID_REM_Z2->AsString));

SerNumcxTextEdit->Text=z->GurZSERNUM1_REM_Z2->AsString;
SerNum2cxTextEdit->Text=z->GurZSERNUM2_REM_Z2->AsString;
//NumGarDoccxTextEdit->Text=z->GurZNUM_GARDOC_REM_Z2->AsString;

z->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonOpenNewClick(TObject *Sender)
{

DM->PosNach=PosNach;
DM->PosCon=PosCon;

DM->OpenTable();
DM->Table->Last();
StrOtborLabel->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::NameHardwarecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborHardware();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurZPredv::ToolButtonCreateNaOsnSprHardwareClick(TObject *Sender)

{
IREM_FormaZayavkaPredv * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaZayavkaPredv,IID_IREM_FormaZayavkaPredv,
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
	REM_FormaZayavka->DM->GurZIDHW_REM_Z2->AsString=h->ElementID_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZNAME_REM_SHARDWARE->AsString=h->ElementNAME_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM_REM_SHARDWARE->AsString=h->ElementSERNUM_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM2_REM_SHARDWARE->AsString=h->ElementSERNUM2_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM1_REM_Z2->AsString=h->ElementSERNUM_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZSERNUM2_REM_Z2->AsString=h->ElementSERNUM2_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZIDMODEL_REM_Z2->AsString=h->ElementIDMODEL_REM_SHARDWARE->AsString;
	REM_FormaZayavka->DM->GurZNAME_REM_SMODEL->AsString=h->ElementNAME_REM_SMODEL->AsString;
	REM_FormaZayavka->DM->GurZMODEL_STR_REM_Z2->AsString=h->ElementNAME_REM_SMODEL->AsString;
	REM_FormaZayavka->DM->GurZ->Post();


h->kanRelease();
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------






//выбор склада
void TREM_FormaGurZPredv::ViborSklad(void)
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
void __fastcall TREM_FormaGurZPredv::EndViborSklad(void)
{


	IdSklad=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
	NameSkladcxButtonEdit->Text=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;


FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurZPredv::NameSkladcxButtonEditPropertiesButtonClick(TObject *Sender,
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









