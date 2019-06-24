//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UHLP_FormaSpiskaSprNaborInfBlock.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IHLP_FormaElementaSprNaborInfBlock.h"
#include "IHLP_FormaElementaSprNaborInfBlockGrp.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxContainer"
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
#pragma link "cxTreeView"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall THLP_FormaSpiskaSprNaborInfBlock::THLP_FormaSpiskaSprNaborInfBlock(TComponent* Owner)
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
bool THLP_FormaSpiskaSprNaborInfBlock::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprNaborInfBlock,IID_IHLP_DMSprNaborInfBlock,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprNaborInfBlockGrp,IID_IHLP_DMSprNaborInfBlockGrp,
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
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THLP_FormaSpiskaSprNaborInfBlockImpl),false);
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
int THLP_FormaSpiskaSprNaborInfBlock::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::UpdateForm(void)
{



DM->DataSourceTable->Enabled=false;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_HLP_N_IB",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::FormClose(TObject *Sender,
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
int THLP_FormaSpiskaSprNaborInfBlock::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborGrp)
        {

        UpdateDerevo();
        }

if(number_procedure_end==ViborElement)
        {
		IdElement=glStrToInt64(DM->TableID_HLP_N_IB->AsString);
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
void THLP_FormaSpiskaSprNaborInfBlock::OpenFormElement()
{


		IHLP_FormaElementaSprNaborInfBlock * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlock,IID_IHLP_FormaElementaSprNaborInfBlock,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_HLP_N_IB->AsString));
		FormaElementa->NumberProcVibor=ViborElement;
		FormaElementa->UpdateForm();
		FormaElementa->SaveElement=true;

}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::OpenFormNewElement()
{
		IHLP_FormaElementaSprNaborInfBlock * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlock,IID_IHLP_FormaElementaSprNaborInfBlock,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->NumberProcVibor=ViborElement;
		if (!FormaElementa) return;
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{

				FormaElementa->UpdateForm();
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}

//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::DeleteElement()
{
		String V="Вы действительно хотите удалить "
		+DM->TableNAME_HLP_N_IB->AsString+"?";
        String Z="Подтверждение удаления элемента";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
				{
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_HLP_N_IB->AsString))!=true)
	{
	ShowMessage("Не удалось удалить елемент справочника!  Ошибка: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}
//-------------------------------------------------------------------
//
void THLP_FormaSpiskaSprNaborInfBlock::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"Набор",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_HLP_N_IB_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_HLP_N_IB_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_HLP_N_IB_GRP->AsString, lpIDGrp);
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
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
				{
				IHLP_FormaElementaSprNaborInfBlockGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlockGrp,IID_IHLP_FormaElementaSprNaborInfBlockGrp,
												 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				}

}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::OpenFormNewGrpElement()
{



IHLP_FormaElementaSprNaborInfBlockGrp * FormaGrpElementa;
InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlockGrp,IID_IHLP_FormaElementaSprNaborInfBlockGrp,
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
void THLP_FormaSpiskaSprNaborInfBlock::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_HLP_N_IB->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_HLP_N_IB->AsString);
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ToolButtonIsmGrpClick(TObject *Sender)
{

if (cxTreeView1->Selected!=NULL)
		{  //множественный перенос
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_HLP_N_IB->Index];
				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
				}
			}
		}
DM->OpenTable(IdGrp,AllElement);
}
//---------------------------------------------------------------------------







//-----------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("Spr/SprNom");
}
//---------------------------------------------------------------------------




void __fastcall THLP_FormaSpiskaSprNaborInfBlock::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(int*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}	
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlock::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_HLP_N_IB->AsString));
				Close();
		}
else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlock::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_HLP_N_IB->AsString));
				Close();
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------


void __fastcall THLP_FormaSpiskaSprNaborInfBlock::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THLP_FormaSpiskaSprNaborInfBlock::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlock::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_HLP_N_IB->AsString));
	}

module->ExecuteModule();




}
//-----------------------------------------------------------------------------
