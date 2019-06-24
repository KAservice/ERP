//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//-----------------------------------------------------------------------------
#include "UREM_FormaSpiskaSprProducerSection.h"

#include "IFormaRunExternalModule.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxTreeView"
#pragma link "cxButtonEdit"
#pragma link "cxClasses"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprProducerSection::TREM_FormaSpiskaSprProducerSection(TComponent* Owner)
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
bool TREM_FormaSpiskaSprProducerSection::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerSection,IID_IREM_DMSprProducerSection, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerSectionGrp,IID_IREM_DMSprProducerSectionGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducer,IID_IDMSprProducer, (void**)&DMGroupElement);
DMGroupElement->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGroupElement=0;
flAllElement=false;
flVibor=false;
TypeEvent=0;;
ViborRekvisit=NO;
flPodbor=false;

LabelNameGrp->Caption="Работы\\...";
HintLabel->Caption="";



DMGroupElement->OpenTable();
NameGroupElementcxComboBox->Properties->Items->Clear();
NameGroupElementcxComboBox->Properties->Items->Add("Не задан");
DMGroupElement->Table->First();
while (!DMGroupElement->Table->Eof)
		{
		NameGroupElementcxComboBox->Properties->Items->Add(DMGroupElement->TableNAME_SPRODUCER->AsString);
		DMGroupElement->Table->Next();
		}
NameGroupElementcxComboBox->ItemIndex=0;


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaSpiskaSprProducerSectionImpl),false);
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
int TREM_FormaSpiskaSprProducerSection::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGroupElement,IdGrp,flAllElement);


TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_REM_SPRSECTION",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprProducerSection::FormClose(TObject *Sender,
	  TCloseAction &Action)
{

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
DMGrp->kanRelease();
DMGroupElement->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::UpdateDerevo()
{
//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(IdGroupElement);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Section",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_REM_SPRSECTION_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_REM_SPRSECTION_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_REM_SPRSECTION_GRP->AsString, lpIDGrp);
                         break;
					   }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);

for (int i=0;i<cxTreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
                        break;
                        }
		}
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprProducerSection::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborGroupElement)
        {

        UpdateDerevo();
        }


if (number_procedure_end==ViborElement)
		{
		if (type_event==1)
				{
				 EndEditElement();
				}
		FormaElementa=0;
		}

if (number_procedure_end==ViborGrp)
		{
		if (type_event==1)
				{
				 EndEditGrp();
				}
		FormaGrpElementa=0;
		}

//if(ViborRekvisit!=RekvisitPodborNom)
//        {
        ViborRekvisit=NO;

//        }
return -1;
}
//--------------------------------------------------------------------------

// редактирование групп
void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonNewScaleClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonEdiScaleClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonDeleteScaleClick(
      TObject *Sender)
{
DeleteGrpElement();
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::OpenFormGrpElement()
{

if (FormaGrpElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprProducerSectionGrp,IID_IREM_FormaElementaSprProducerSectionGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				}
		}

}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::OpenFormNewGrpElement()
{
if (FormaGrpElementa==0)
		{
		if(IdGroupElement!=0)
			{
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprProducerSectionGrp,IID_IREM_FormaElementaSprProducerSectionGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
			if (!FormaGrpElementa) return;

			if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGroupElement,IdGrp);
				}
			else
				{
				FormaGrpElementa->DM->NewElement(IdGroupElement,0);
				}
			FormaGrpElementa->NumberProcVibor=ViborGrp;
			}
		else
			{
			 ShowMessage("Необходимо выбрать производителя!");
			}
		}
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::DeleteGrpElement()
{
		UnicodeString V="Вы действительно хотите удалить "
		+LabelNameGrp->Caption+"?";
		UnicodeString Z="Подтверждение удаления группы";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

		if (cxTreeView1->Selected!=NULL)
				{
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
				}

}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::EndEditGrp(void)
{
FormaGrpElementa=0;
UpdateDerevo();
}
//--------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonAllClick(TObject *Sender)
{
if (flAllElement==true)
        {
		flAllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
		flAllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
		}

IdGrp=glStrToInt64(DM->TableIDGRP_REM_SPRSECTION->AsString);

DM->OpenTable(IdGroupElement, IdGrp,flAllElement);
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{  //множественный перенос
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_REM_SPRSECTION->Index];
				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
				}
			}
		}
DM->OpenTable(IdGroupElement, IdGrp,flAllElement);
}
//---------------------------------------------------------------------------











//реакция на выбор группы
void __fastcall TREM_FormaSpiskaSprProducerSection::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(flAllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGroupElement, IdGrp,flAllElement);
		}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprProducerSection::cxTreeView1KeyPress(TObject *Sender,
	  char &Key)
{
if (Key==VK_RETURN)
		{
		if (cxTreeView1->Selected!=NULL)
			{
			if(flAllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
			IdGrp=*(__int64*)cxTreeView1->Selected->Data;
			DM->OpenTable(IdGroupElement, IdGrp,flAllElement);
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprProducerSection::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (flVibor==true)
		{
		if (flPodbor==true)
				{
				//OpenFormPodboraNom();
				}
		else
				{
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_REM_SPRSECTION->AsString));
				Close();
				}
		}
else
		{
		IdElement=glStrToInt64(DM->TableID_REM_SPRSECTION->AsString);
		OpenFormElement();
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprProducerSection::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		if (flVibor==true)
				{
				if (flPodbor==true)
						{
						//OpenFormPodboraNom();
						}
				else
						{
						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_REM_SPRSECTION->AsString));
						Close();
						}
				}
		else
				{
				OpenFormElement();
				}
		}
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaSpiskaSprProducerSection::ActionOpenHelpExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaSpiskaSprProducerSection::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_REM_SPRSECTION->AsString));
	module->SetInt64Variables("glIdGroupElement", glStrToInt64(DM->TableIDPR_REM_SPRSECTION->AsString));
	module->SetInt64Variables("glIdGrp", IdGrp);
	}

module->ExecuteModule();

}
//-----------------------------------------------------------------------------



void __fastcall TREM_FormaSpiskaSprProducerSection::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprProducerSection::NameGroupElementcxComboBoxPropertiesChange(TObject *Sender)

{
IdGroupElement=0;
if (NameGroupElementcxComboBox->ItemIndex!=0)
		{
		DMGroupElement->Table->First();
		DMGroupElement->Table->MoveBy(NameGroupElementcxComboBox->ItemIndex-1);
		IdGroupElement=glStrToInt64(DMGroupElement->TableID_SPRODUCER->AsString);
		}
UpdateForm();
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::OpenFormElement()
{

if (FormaElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprProducerSection,IID_IREM_FormaElementaSprProducerSection,
													(void**)&FormaElementa);
				FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SPRSECTION->AsString));
				FormaElementa->NumberProcVibor=ViborElement;
				FormaElementa->IdGrp=IdGrp;
				FormaElementa->NameGroupElement=LabelNameGrp->Caption;
				FormaElementa->UpdateForm();
				IdElement=glStrToInt64(DM->TableID_REM_SPRSECTION->AsString);
				}
		}

}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::OpenFormNewElement(void)
{
if (FormaElementa==0)
		{
		if(IdGroupElement!=0)
			{
				InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaElementaSprProducerSection,IID_IREM_FormaElementaSprProducerSection,
													(void**)&FormaElementa);
				FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
			if (!FormaElementa) return;

			if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaElementa->DM->NewElement(IdGroupElement,IdGrp);
				}
			else
				{
				FormaElementa->DM->NewElement(IdGroupElement,0);
				}
			FormaElementa->NumberProcVibor=ViborElement;

			FormaElementa->IdGrp=IdGrp;
			FormaElementa->NameGroupElement=LabelNameGrp->Caption;
			FormaElementa->UpdateForm();
			}
		else
			{
			 ShowMessage("Необходимо выбрать производителя!");
			}
		}
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::DeleteElement(void)
{

		UnicodeString V="Вы действительно хотите удалить "
		+DM->TableNAME_REM_SPRSECTION->AsString+"?";
		UnicodeString Z="Подтверждение удаления элемента";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
				return;
				}

if(DM->DeleteElement(glStrToInt64(DM->TableID_REM_SPRSECTION->AsString))!=true)
	{
	ShowMessage("Не удалось удалить элемент справочника!  Ошибка: "+DM->TextError );
	}


DM->OpenTable(IdGroupElement,IdGrp,flAllElement);

}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprProducerSection::EndEditElement(void)
{
DM->OpenTable(IdGroupElement,IdGrp,flAllElement);
cxGrid1->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonNewClick(TObject *Sender)

{
OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonEditClick(TObject *Sender)

{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprProducerSection::ToolButtonDeleteClick(TObject *Sender)

{
DeleteElement();
}
//---------------------------------------------------------------------------

