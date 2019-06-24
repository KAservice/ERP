//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprDiscountCard_1.h"
#include "IDMSprGrpKlient.h"
#include "IFormaElementaSprGrpKlient.h"
#include "IFormaElementaSprDiscountCard.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
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
#pragma link "cxContainer"
#pragma link "cxTreeView"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxCheckBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprDiscountCard_1::TFormaSpiskaSprDiscountCard_1(TComponent* Owner)
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
bool TFormaSpiskaSprDiscountCard_1::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard_1.1",IID_IDMSprDiscountCard_1, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpKlient.1",IID_IDMSprGrpKlient, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrpKlient=0;
AllElement=false;
Vibor=false;
HintLabel->Caption="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",
						IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprDiscountCard1Impl),false);
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
//----------------------------------------------------------------------------
int  TFormaSpiskaSprDiscountCard_1::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDiscountCard_1::FormClose(TObject *Sender,
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
//---------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::UpdateForm(void)
{
if (IdDiscountCard>0)
		{
		IdGrpKlient=DM->GetIdGrpKlient(IdDiscountCard);
		}

DM->OpenTable(IdGrpKlient,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_SDISCOUNT_CARD",IdDiscountCard,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
//
void TFormaSpiskaSprDiscountCard_1::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"Контрагенты",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
		{
		__int64 IDGrp=glStrToInt64(DMGrp->TableGRPKL->AsString);
		__int64 IDData;
		//ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableIDGRPKL->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGRPKL")->AsString, lpIDGrp);
						 break;
					   }

				}
		DMGrp->Table->Next();
		}
cxTreeView1->AlphaSort(true);

for (int i=0;i<cxTreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
				if (IdGrpKlient==IDData)
						{
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
						break;
						}
		}
}
//---------------------------------------------------------------------------------
int TFormaSpiskaSprDiscountCard_1::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//==ViborGrp)
		{
		UpdateDerevo();
		}
if(number_procedure_end==1)//ViborElement)
		{

		}

if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::OpenFormElement()
{

		IFormaElementaSprDiscountCard * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountCard.1",IID_IFormaElementaSprDiscountCard,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
		IdDiscountCard=glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString);
		FormaElementa->UpdateForm();
		FormaElementa->NumberProcVibor=2;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::OpenFormNewElement()
{
		IFormaElementaSprDiscountCard * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprDiscountCard.1",IID_IFormaElementaSprDiscountCard,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->NewElement(IdGrpKlient);
		IdDiscountCard=0;
		FormaElementa->DM->NewElement(glStrToInt64(DM->TableIDKLIENT_SDISCOUNT_CARD->AsString));
		FormaElementa->UpdateForm();
		FormaElementa->DM->ElementNAMEKLIENT->AsString=DM->TableNAMEKLIENT->AsString;
		FormaElementa->UpdateForm();
		FormaElementa->NumberProcVibor=2;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::DeleteElement()
{
DM->DeleteElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
DM->OpenTable(IdGrpKlient,AllElement);
}
//-------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonDeleteClick(
	  TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprGrpKlient * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpKlient.1",IID_IFormaElementaSprGrpKlient,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=1;
                }

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::OpenFormNewGrpElement()
{
int IdGroup=0;

				IFormaElementaSprGrpKlient * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpKlient.1",IID_IFormaElementaSprGrpKlient,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (cxTreeView1->Selected!=NULL)
                {
				IdGroup=*(__int64*)cxTreeView1->Selected->Data;
                FormaGrpElementa->DM->NewElement(IdGroup);
                }
        else
                {
                FormaGrpElementa->DM->NewElement(0);
				}
				FormaGrpElementa->NumberProcVibor=1;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonNewGrpClick(
      TObject *Sender)
{
OpenFormNewGrpElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonEditGrpClick(
      TObject *Sender)
{
OpenFormGrpElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonDelGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonAllElementClick(
      TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
IdGrpKlient=*(__int64*)cxTreeView1->Selected->Data;
DM->OpenTable(IdGrpKlient,AllElement);
}
//---------------------------------------------------------------------------










void __fastcall TFormaSpiskaSprDiscountCard_1::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprDiscountCard");
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprDiscountCard_1::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
        if (Vibor==true)
				{
						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
                        Close();

				}
		else
				{
				OpenFormElement();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
		Close();
		}

else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrpKlient=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrpKlient,AllElement);
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::cxTreeView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrpKlient=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrpKlient,AllElement);
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprDiscountCard_1::ToolButtonUpdateFormClick(
      TObject *Sender)
{
IdDiscountCard=glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString) ;
UpdateForm();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaSprDiscountCard_1::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprDiscountCard_1::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule, (void**)&module);

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
	module->SetInt64Variables("glIdKlient", glStrToInt64(DM->TableIDKLIENT_SDISCOUNT_CARD->AsString));
	module->SetInt64Variables("glIdGrpKlient", IdGrpKlient);
    module->SetInt64Variables("glIdDiscountCard", glStrToInt64(DM->TableID_SDISCOUNT_CARD->AsString));
	//заполним список элементов List для выбранных элементов
//	for(int i=0;i<List->Count;i++)
//		{
//
//		module->ListAddElement(ElementSpiska->Id,ElementSpiska->IdEd,"");
//		}

	TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
	for(int i=0;i<AViewData->RowCount;i++)
		{
		if (AViewData->Records[i]->Selected==true)
			{
			AnsiString id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_SDISCOUNT_CARD->Index];
			module->ListAddElement(id,"","",1);
			}
		}

	}
	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprDiscountCard_1::ActionCloseExecute(TObject *Sender)

{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

