//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop


//----------------------------------------------------------------------------
#include "UREM_FormaGurProverok.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IREM_FormaDocProverka.h"


#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"

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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaGurProverok::TREM_FormaGurProverok(TComponent* Owner)
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
bool TREM_FormaGurProverok::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMGurProverok,IID_IREM_DMGurProverok, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

PosCon=Date()+EncodeTime(23,59,59,999);
PosNach=DM_Connection->GetPosNachGurnal();

DM->PosNach=PosNach;
DM->PosCon=PosCon;



//DM->OtborPoKlient=false;
//DM->OtborPoFirm=false;
//DM->OtborPoSklad=false;
//DM->OtborPoTypeDoc=false;
DM->OpenTable();



DM->Table->Last();
Vibor=false;
LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);

Vibor=false;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaGurProverokImpl),false);
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

DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaGurProverok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaGurProverok::UpdateForm(void)
{


		DM->PosNach=PosNach;
		DM->PosCon=PosCon;
		LabelInterval->Caption=DateTimeToStr(PosNach)+" - "+DateTimeToStr(PosCon);


}
//---------------------------------------------------------------------------
void TREM_FormaGurProverok::OpenTable(void)
{

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurProverok::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
if(FormaViborPerioda)FormaViborPerioda->kanRelease();
if(FormaSetupOtbor)FormaSetupOtbor->kanRelease();


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
int TREM_FormaGurProverok::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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

		if (number_procedure_end==SetupOtborRekv)
                {
				if(type_event==1)
                        {

						}
                FormaSetupOtbor=0;

				}




if (DM_Connection->UserInfoREOPEN_GUR_SUSER->AsInteger==1)
	{

		DM->UpdateTable();

	}

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaGurProverok::OpenFormDoc()
{


		IREM_FormaDocProverka * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocProverka,IID_IREM_FormaDocProverka,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//doc->IdRodForm=Handle;
		//настройка формы
		doc->DM->OpenDoc(glStrToInt64(DM->TableID_REM_GUR_PROV->AsString));
		doc->UpdateForm();

}
//----------------------------------------------------------------------------



void __fastcall TREM_FormaGurProverok::ToolButtonDeleteClick(TObject *Sender)
{
DeleteDoc();
}
//---------------------------------------------------------------------------
void TREM_FormaGurProverok::DeleteDoc(void)
{

		IREM_DMDocProverka * doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocProverka,IID_IREM_DMDocProverka,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceImpl);
		if (!doc) return;
		//настройка формы
		doc->OpenDoc(glStrToInt64(DM->TableID_REM_GUR_PROV->AsString));

		String V="Вы действительно хотите удалить документ Проверка №"
		+doc->DocAllNUM_REM_GUR_PROV->AsString+" от "+doc->DocAllPOS_REM_GUR_PROV->AsString+"?";
		String Z="Подтверждение удаления документа";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

				if (doc->DeleteDoc(glStrToInt64(DM->TableID_REM_GUR_PROV->AsString))==true)
						{
						DM->UpdateTable();
						}
				else
						{
						ShowMessage("Не удалось удалить документ! Ошибка:"+doc->TextError);
						}


		doc->kanRelease();
		return;

}

//----------------------------------------------------------------------------
void __fastcall TREM_FormaGurProverok::ToolButton3Click(TObject *Sender)
{
//if (DM->CancelDvRegDoc(Trim(DM->TableTDOC_REM_GUR_PROV->AsString), glStrToInt64(DM->TableID_REM_GUR_PROV->AsString))==true)
//	{
//	DM->UpdateTable();
//	}
//else
//	{
//	ShowMessage("Не удалось отменить проведение документа. Ошибка: "+DM->TextError);
//	}

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaGurProverok::ToolButtonViborPeriodaClick(
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

        }
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaGurProverok::ToolButtonOpenDocClick(TObject *Sender)
{
OpenFormDoc();        
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaGurProverok::ToolButtonOtborClick(TObject *Sender)
{

//AnsiString s="";
//if (ToolButtonOtbor->Down==true)  // включить отбор
//        {
//        DM->OtborVkl=true;
//
//                        if (IdKlient>0) s=s+" Контрагент: "+NameKlient;
//                        if (IdFirm>0) s=s+" Фирма: "+NameFirm;
//                        if (IdSklad>0) s=s+" Склад: "+NameSklad;
//                        if (StringTypeDoc!="") s=s+" Тип документов : "+NameTypeDoc;
//                        StrOtborLabel->Caption=s;
//        }
//else
//        {
//        DM->OtborVkl=false;
//        StrOtborLabel->Caption=s;
//        }
//
//DM->IdKlient=IdKlient;
//DM->IdSklad=IdSklad;
//DM->IdFirm=IdFirm;
//DM->StringTypeDoc=StringTypeDoc;
//
////DM->OtborPoKlient=OtborPoKlientu;
////DM->OtborPoFirm=OtborPoFirm;
////DM->OtborPoSklad=OtborPoSklad;
////DM->OtborPoTypeDoc=OtborPoTypeDoc;
//DM->UpdateTable();


}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaGurProverok::ToolButtonParamOtborClick(TObject *Sender)
{

		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSetupOtbor.1",IID_IREM_FormaSetupOtbor,
													(void**)&FormaSetupOtbor);
		FormaSetupOtbor->Init(InterfaceMainObject,InterfaceImpl);
        if (!FormaSetupOtbor ) return;
		//FormaSetupOtbor->IdRodForm=Handle;
        FormaSetupOtbor->NumberProcVibor=SetupOtborRekv;

}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaGurProverok::ToolButtonRefreshClick(TObject *Sender)
{
DM->UpdateTable();
}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------

void __fastcall TREM_FormaGurProverok::cxGrid1DBTableView1DblClick(TObject *Sender)
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


void __fastcall TREM_FormaGurProverok::cxGrid1DBTableView1KeyPress(TObject *Sender,
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
void __fastcall TREM_FormaGurProverok::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaGurProverok::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->TableID_REM_GUR_PROV->AsString));
module->SetDateTimeVariables("glPosBegin", PosNach);
module->SetDateTimeVariables("glPosEnd", PosCon);

module->ExecuteModule();
}
//---------------------------------------------------------------------------





















