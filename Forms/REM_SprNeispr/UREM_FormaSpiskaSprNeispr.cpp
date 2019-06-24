//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprNeispr.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

#include "IREM_FormaElementaSprGrpNeispr.h"
#include "IREM_FormaElementaSprNeispr.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTreeView"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprNeispr::TREM_FormaSpiskaSprNeispr(TComponent* Owner)
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
bool TREM_FormaSpiskaSprNeispr::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprNeispr,IID_IREM_DMSprNeispr,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprGrpNeispr,IID_IREM_DMSprGrpNeispr,
												 (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;
ViborRekvisit=NO;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaSpiskaSprNeisprImpl),false);
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
int TREM_FormaSpiskaSprNeispr::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::UpdateForm(void)
{
if (IdNeispr>0)
        {
		IdGrp=DM->GetIdGrpNom(IdNeispr);
		}


DM->DataSourceTable->Enabled=false;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_REM_SNEISPR",IdNeispr,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::FormClose(TObject *Sender,
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
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprNeispr::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (ViborRekvisit==ViborGrp)
        {

        UpdateDerevo();
        }

if(ViborRekvisit==ViborElement)
        {
		IdNeispr=glStrToInt64(DM->TableID_REM_SNEISPR->AsString);
        IdGrp=0;
		if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                }
        UpdateForm();
        }

return -1;
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::OpenFormElement()
{

		IREM_FormaElementaSprNeispr * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprNeispr.1",IID_IREM_FormaElementaSprNeispr,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SNEISPR->AsString));
		FormaElementa->NumberProcVibor=ViborElement;
		FormaElementa->UpdateForm();


}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::OpenFormNewElement()
{

		IREM_FormaElementaSprNeispr * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprNeispr.1",IID_IREM_FormaElementaSprNeispr,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->NumberProcVibor=ViborElement;
				FormaElementa->UpdateForm();
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}

//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::DeleteElement()
{
		String V="Вы действительно хотите удалить "
		+DM->TableNAME_REM_SNEISPR->AsString+"?";
        String Z="Подтверждение удаления элемента";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_REM_SNEISPR->AsString))!=true)
	{
	ShowMessage("Не удалось удалить елемент справочника!  Ошибка: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}
//-------------------------------------------------------------------
//
void TREM_FormaSpiskaSprNeispr::UpdateDerevo()
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
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Неисправности",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_REM_SGRPNEISPR->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->Table->FieldByName("ID_REM_SGRPNEISPR")->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAME_REM_SGRPNEISPR")->AsString, lpIDGrp);
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
                        if(AllElement!=true)
                                {
								LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                                }
                        break;
                        }
        }
}
//---------------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IREM_FormaElementaSprGrpNeispr * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpNeispr.1",IID_IREM_FormaElementaSprGrpNeispr,
												 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				if (!FormaGrpElementa) return;
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				}

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::OpenFormNewGrpElement()
{

				IREM_FormaElementaSprGrpNeispr * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpNeispr.1",IID_IREM_FormaElementaSprGrpNeispr,
												 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGrpElementa) return;

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(0);
				}
		FormaGrpElementa->NumberProcVibor=ViborGrp;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
        LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdNeispr=glStrToInt64(DM->TableID_REM_SNEISPR->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_REM_SNEISPR->AsString);
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprNeispr::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------







//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprNeispr::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprNom");
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaSpiskaSprNeispr::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeispr::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_REM_SNEISPR->AsString));
				Close();
        }
else
        {
        OpenFormElement();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeispr::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_REM_SNEISPR->AsString));
						Close();

				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprNeispr::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TREM_FormaSpiskaSprNeispr::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprNeispr::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdNeispr", glStrToInt64(DM->TableID_REM_SNEISPR->AsString));
	}

module->ExecuteModule();




}
//-----------------------------------------------------------------------------
