//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-------------------------------------------------------------------------
#include "UHLP_FormaSpiskaSprNaborInfBlockSostav.h"
#include "IHLP_FormaElementaSprNaborInfBlockSostavGrp.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::THLP_FormaSpiskaSprNaborInfBlockSostav(TComponent* Owner)
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
bool THLP_FormaSpiskaSprNaborInfBlockSostav::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprNaborInfBlockSostav,IID_IHLP_DMSprNaborInfBlockSostav, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprNaborInfBlockSostavGrp,IID_IHLP_DMSprNaborInfBlockSostavGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprNaborInfBlock,IID_IHLP_DMSprNaborInfBlock, (void**)&DMGroupElement);
DMGroupElement->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

IdGrp=0;
IdGroupElement=0;
AllElement=false;

Vibor=false;
TypeEvent=0;
Prosmotr=false;
ViborRekvisit=NO;
LabelNameGrp->Caption="Модели\\...";
NameGroupElementcxButtonEdit->Text="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THLP_FormaSpiskaSprNaborInfBlockSostavImpl),false);
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
int THLP_FormaSpiskaSprNaborInfBlockSostav::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::UpdateForm(void)
{

DM->OpenTable(IdGroupElement,IdGrp,AllElement);
DMGrp->OpenTable(IdGroupElement);
UpdateDerevo(IdGroupElement);
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaViborOsnSpr)FormaViborOsnSpr->kanRelease();
if(FormaViborGroupElement)FormaViborGroupElement->kanRelease();

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
//---------------------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockSostav::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==VR_ViborGrp)
        {
		UpdateDerevo(IdGroupElement);
		}

if(number_procedure_end==VR_ViborOsnSpr)
        {
		if (type_event==1)
                {
                DM->Table->Edit();
				DM->TableIDNABOR_HLP_N_IB_S->AsString=IdGroupElement;
				if (IdGrp !=0)
					{
					DM->TableIDGRP_HLP_N_IB_S->AsString=IdGrp;
					}
				DM->TableIDIB_HLP_N_IB_S->AsString=FormaViborOsnSpr->DM->TableID_HLP_IB->AsString;
				DM->TableNAME_HLP_IB->AsString=FormaViborOsnSpr->DM->TableNAME_HLP_IB->AsString;
                // DM->TablePRICE1NOM->AsFloat=SpisokNom->DM->TablePRICE1NOM->AsFloat;
                //DM->OpenTable(IdPod,IdGrp,AllElement);
				DM->Table->Post();

				}
		else if (type_event==2)
			{
			if (KolAddElement==0)
				{
				FormaViborOsnSprCopy=FormaViborOsnSpr;
				}

			IHLP_DMSprInfBlock * dm_osn_spr;
			InterfaceGlobalCom->kanCreateObject(ProgId_HLP_DMSprInfBlock,IID_IHLP_DMSprInfBlock,
									 (void**)&dm_osn_spr);
			dm_osn_spr->Init(InterfaceMainObject,InterfaceImpl);
			dm_osn_spr->OpenElement(FormaViborOsnSprCopy->IdElement);
			if (KolAddElement > 0)
				{
				DM->NewElement(IdGroupElement,IdGrp);
				}
                DM->Table->Edit();
				DM->TableIDNABOR_HLP_N_IB_S->AsString=IdGroupElement;
				if (IdGrp !=0)
					{
					DM->TableIDGRP_HLP_N_IB_S->AsString=IdGrp;
					}
				DM->TableIDIB_HLP_N_IB_S->AsString=dm_osn_spr->ElementID_HLP_IB->AsString;
				DM->TableNAME_HLP_IB->AsString=dm_osn_spr->ElementNAME_HLP_IB->AsString;
				//DM->TableCODENOM->AsString=dm_osn_spr->ElementCODENOM->AsString;
				//DM->TableARTNOM->AsString=dm_osn_spr->ElementARTNOM->AsString;
				DM->Table->Post();
			dm_osn_spr->kanRelease();
			KolAddElement++;
			}
		FormaViborOsnSpr=0;
        }
if(number_procedure_end==VR_ViborGroupElement)
        {
        if (type_event==1)
                {
				IdGroupElement=glStrToInt64(FormaViborGroupElement->DM->TableID_HLP_N_IB->AsString);
				NameGroupElementcxButtonEdit->Text=FormaViborGroupElement->DM->TableNAME_HLP_N_IB->AsString;
				UpdateDerevo(IdGroupElement);
                IdGrp=0;
				DM->OpenTable(IdGroupElement,IdGrp,AllElement);
                LabelNameGrp->Caption="Модели\\...";
                }
		FormaViborGroupElement=0;
        }

ViborRekvisit=NO;
return -1;
}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::OpenFormViborOsnSpr()
{
if (Prosmotr==true)return;
if (FormaViborOsnSpr==NULL)
        {
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaSpiskaSprInfBlock,IID_IHLP_FormaSpiskaSprInfBlock,
													(void**)&FormaViborOsnSpr);
		FormaViborOsnSpr->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborOsnSpr->Vibor=true;
		//FormaViborOsnSpr->IdInetCatalog=IdGroupElement;
		//FormaViborOsnSpr->NameInetCatalog=NameGroupElementcxButtonEdit->Text;

		FormaViborOsnSpr->UpdateForm();
		FormaViborOsnSpr->NumberProcVibor=VR_ViborOsnSpr;
		KolAddElement=0;
		}
}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::OpenFormSpiskaSprGroupElement()
{
if (Prosmotr==true)return;
if (FormaViborGroupElement==NULL)
        {
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaSpiskaSprNaborInfBlock,IID_IHLP_FormaSpiskaSprNaborInfBlock,
													(void**)&FormaViborGroupElement);
		FormaViborGroupElement->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborGroupElement->Vibor=true;
		FormaViborGroupElement->NumberProcVibor=VR_ViborGroupElement;
        FormaViborGroupElement->UpdateForm();
        }
}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::DeleteElement()
{
if (Prosmotr==true)return;
DM->TableDelete();

}
//------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::UpdateDerevo(int id_group_element)
{
IdGroupElement=id_group_element;
//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(id_group_element);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Модели",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_HLP_N_IB_S_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_HLP_N_IB_S_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_HLP_N_IB_S_GRP->AsString, lpIDGrp);
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
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
if (Prosmotr==true)return;
DeleteGrpElement();
UpdateDerevo(IdGroupElement);
}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::OpenFormGrpElement()
{
if (Prosmotr==true)return;

		if (cxTreeView1->Selected!=NULL)
                {
				IHLP_FormaElementaSprNaborInfBlockSostavGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlockSostavGrp,IID_IHLP_FormaElementaSprNaborInfBlockSostavGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=VR_ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				}

}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::OpenFormNewGrpElement()
{
if (Prosmotr==true)return;

		IHLP_FormaElementaSprNaborInfBlockSostavGrp* FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_HLP_FormaElementaSprNaborInfBlockSostavGrp,IID_IHLP_FormaElementaSprNaborInfBlockSostavGrp,
													(void**)&FormaGrpElementa);
        FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGrpElementa) return;
		if(IdGroupElement==0) return;
		if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGroupElement,IdGrp);
                }
        else
                {
				FormaGrpElementa->DM->NewElement(IdGroupElement,0);
				}
		FormaGrpElementa->NumberProcVibor=VR_ViborGrp;

}
//--------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::DeleteGrpElement()
{
if (Prosmotr==true)return;
		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo(IdGroupElement);
                }

}
//-------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonNewClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->IdGroupElement=IdGroupElement;
DM->IdGrp=IdGrp;
DM->TableAppend();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonAllClick(TObject *Sender)
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
IdGrp=*(__int64*)cxTreeView1->Selected->Data;
DM->OpenTable(IdGroupElement,IdGrp,AllElement);
}
//---------------------------------------------------------------------------





void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ToolButtonChancheGrpClick(
      TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data, glStrToInt64(DM->TableID_HLP_N_IB_S->AsString));
        }

}
//---------------------------------------------------------------------------


void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                }
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGroupElement,IdGrp,AllElement);
        }	
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		ViborIdOsnElement=glStrToInt64(DM->TableIDIB_HLP_N_IB_S->AsString);
		TypeEvent=1;
        Close();
        }
else
        {
        }	
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormViborOsnSpr();
}
//---------------------------------------------------------------------------



void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::EditPodrPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprGroupElement();
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
		ViborIdOsnElement=glStrToInt64(DM->TableIDIB_HLP_N_IB_S->AsString);
		TypeEvent=1;
        Close();
        }
else
        {
		}
		}	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void THLP_FormaSpiskaSprNaborInfBlockSostav::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glId", glStrToInt64(DM->TableID_HLP_N_IB_S->AsString));
	module->SetInt64Variables("glIdOsnElement", glStrToInt64(DM->TableIDIB_HLP_N_IB_S->AsString));
	module->SetInt64Variables("glIdGrp", IdGrp);
	module->SetInt64Variables("glIdGroupElement", IdGroupElement);
	}

module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
	}
//delete module;
}
//-----------------------------------------------------------------------------
void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
DM->TableCancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true)return;

if (DM->TableSaveIsmen() == false)
	{
    ShowMessage(DM->TextError);

	}
}
//---------------------------------------------------------------------------


void __fastcall THLP_FormaSpiskaSprNaborInfBlockSostav::cxGrid1DBTableView1NAME_ART_IBPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormViborOsnSpr();
}
//---------------------------------------------------------------------------

