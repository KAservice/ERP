//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-------------------------------------------------------------------------
#include "UFormaSpiskaSprBVNom.h"
#include "IFormaElementaSprGrpBVNom.h"
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
__fastcall TFormaSpiskaSprBVNom::TFormaSpiskaSprBVNom(TComponent* Owner)
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
bool TFormaSpiskaSprBVNom::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpBVNom.1",IID_IDMSprGrpBVNom, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPodr.1",IID_IDMSprPodr, (void**)&DMPodr);
DMPodr->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

IdGrp=0;
IdPod=0;
AllElement=false;

Vibor=false;
TypeEvent=0;
Prosmotr=false;
ViborRekvisit=NO;
LabelNameGrp->Caption="Номенклатура\\...";
EditPodr->Text="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprBVNomImpl),false);
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
int TFormaSpiskaSprBVNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::UpdateForm(void)
{

DM->OpenTable(IdPod,IdGrp,AllElement);
DMGrp->OpenTable(IdPod);
UpdateDerevo(IdPod);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::FormClose(TObject *Sender,
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
DMPodr->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprBVNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborGrp)
        {
        UpdateDerevo(IdPod);
        }
if(number_procedure_end==ViborNom)
        {
		if (type_event==1)
                {
                DM->Table->Edit();
				DM->TableIDPOD_BVNOM->AsInt64=IdPod;
				DM->TableIDGRP_BVNOM->AsInt64=IdGrp;
				DM->TableIDNOM_BVNOM->AsString=SpisokNom->DM->TableIDNOM->AsString;
                DM->TableNAMENOM->AsString=SpisokNom->DM->TableNAMENOM->AsString;
                // DM->TablePRICE1NOM->AsFloat=SpisokNom->DM->TablePRICE1NOM->AsFloat;
                //DM->OpenTable(IdPod,IdGrp,AllElement);
				DM->Table->Post();
                }
        SpisokNom=0;
        }
if(number_procedure_end==ViborPodr)
        {
        if (type_event==1)
                {
                IdPod=SpisokPodr->DM->TableIDPOD->AsInt64;
                EditPodr->Text=SpisokPodr->DM->TableNAMEPOD->AsString;
                UpdateDerevo(IdPod);
                IdGrp=0;
                DM->OpenTable(IdPod,IdGrp,AllElement);
                LabelNameGrp->Caption="Номенклатура\\...";
                }
        SpisokPodr=0;
        }

ViborRekvisit=NO;
return -1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::OpenFormSpiskaSprNom()
{
if (Prosmotr==true)return;
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
        SpisokNom->Vibor=true;
        //тип цен берем из справочника подразделений
        //SpisokNom->DM->IdTypePrice=glUser->ElementIDTPRICE_USER->AsInteger;
		//SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->UpdateForm();
		SpisokNom->NumberProcVibor=ViborNom;
        }
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::OpenFormSpiskaSprPodr()
{
if (Prosmotr==true)return;
if (SpisokPodr==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPodr.1",IID_IFormaSpiskaSprPodr,
													(void**)&SpisokPodr);
		SpisokPodr->Init(InterfaceMainObject,InterfaceImpl);
		SpisokPodr->Vibor=true;
		SpisokPodr->NumberProcVibor=ViborPodr;
        }
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::DeleteElement()
{
if (Prosmotr==true)return;
DM->DeleteElement();

}
//------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::UpdateDerevo(int Pod)
{
IdPod=Pod;
//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(Pod);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=DMGrp->TableIDGRP_GBVNOM->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableID_GBVNOM->AsInt64;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->TableNAME_GBVNOM->AsString, lpIDGrp);
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
void __fastcall TFormaSpiskaSprBVNom::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
if (Prosmotr==true)return;
DeleteGrpElement();
UpdateDerevo(IdPod);
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::OpenFormGrpElement()
{
if (Prosmotr==true)return;

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprGrpBVNom * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpBVNom.1",IID_IFormaElementaSprGrpBVNom,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				}

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::OpenFormNewGrpElement()
{
if (Prosmotr==true)return;

		IFormaElementaSprGrpBVNom * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpBVNom.1",IID_IFormaElementaSprGrpBVNom,
													(void**)&FormaGrpElementa);
        FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGrpElementa) return;
        if(IdPod==0) return;
		if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                FormaGrpElementa->DM->NewElement(IdPod,IdGrp);
                }
        else
                {
                FormaGrpElementa->DM->NewElement(IdPod,0);
				}
		FormaGrpElementa->NumberProcVibor=ViborGrp;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::DeleteGrpElement()
{
if (Prosmotr==true)return;
		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo(IdPod);
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ToolButtonNewClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->NewElement(IdPod,IdGrp);
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ToolButtonDeleteClick(TObject *Sender)
{
if (Prosmotr==true)return;
DM->DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ToolButtonAllClick(TObject *Sender)
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
DM->OpenTable(IdPod,IdGrp,AllElement);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::FormResize(TObject *Sender)
{
        DBTextTypePrice->Left=cxGrid1->Left+cxGrid1->ClientWidth-DBTextTypePrice->Width;
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprBVNom::ToolButtonChancheGrpClick(
      TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprBVNom");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                }
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
        DM->OpenTable(IdPod,IdGrp,AllElement);
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		ViborIdNom=DM->TableIDNOM_BVNOM->AsInt64;
		TypeEvent=1;
        Close();
        }
else
        {
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprBVNom::EditPodrPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprPodr();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
        ViborIdNom=DM->TableIDNOM_BVNOM->AsInt64;
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
void __fastcall TFormaSpiskaSprBVNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprBVNom::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdBVNom", glStrToInt64(DM->TableID_BVNOM->AsString));
	module->SetInt64Variables("glIdNom", glStrToInt64(DM->TableIDNOM_BVNOM->AsString));
	module->SetInt64Variables("glIdTypePrice", DM->IdTypePrice);
	module->SetInt64Variables("glIdGrp", IdGrp);
	module->SetInt64Variables("glIdPodr", IdPod);
	}

module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
	}
//delete module;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNom::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNom::ActionOKExecute(TObject *Sender)
{
if (Prosmotr==true)return;
DM->SaveIsmen();
}
//---------------------------------------------------------------------------

