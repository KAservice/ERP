//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//-----------------------------------------------------------------------------
#include "UFormaSpiskaSprVesNom.h"
#include "IFormaElementaSprScale.h"
#include "IDMSprUser.h"

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
__fastcall TFormaSpiskaSprVesNom::TFormaSpiskaSprVesNom(TComponent* Owner)
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
bool TFormaSpiskaSprVesNom::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprVesNom.1",IID_IDMSprVesNom, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpVesNom.1",IID_IDMSprGrpVesNom, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprScale.1",IID_IDMSprScale, (void**)&DMScale);
DMScale->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdScale=0;
AllElement=false;
Vibor=false;
TypeEvent=0;;
ViborRekvisit=NO;
Podbor=false;

LabelNameGrp->Caption="Весы\\...";
HintLabel->Caption="";


DMSprTypePrice->OpenTable();
NameTypePricecxComboBox->Properties->Items->Clear();
NameTypePricecxComboBox->Properties->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
		{
		NameTypePricecxComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
		DMSprTypePrice->Table->Next();
		}


DMScale->OpenTable();
NameScalecxComboBox->Properties->Items->Clear();
NameScalecxComboBox->Properties->Items->Add("Не задан");
DMScale->Table->First();
while (!DMScale->Table->Eof)
		{
		NameScalecxComboBox->Properties->Items->Add(DMScale->TableNAME_SSCALE->AsString);
		DMScale->Table->Next();
		}
NameScalecxComboBox->ItemIndex=0;
NameTypePricecxComboBox->ItemIndex=0;

//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprVesNomImpl),false);
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
int TFormaSpiskaSprVesNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdScale,IdGrp, IdTypePrice,AllElement);


TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_SVESNOM",IdVesNom,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::FormClose(TObject *Sender,
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
DMScale->kanRelease();
DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::UpdateDerevo()
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
DMGrp->OpenTable(IdScale);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Товары в весах",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=DMGrp->TableIDGRP_SGRPVESNOM->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableID_SGRPVESNOM->AsInt64;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->TableNAME_SGRPVESNOM->AsString, lpIDGrp);
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
int TFormaSpiskaSprVesNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborScale)
        {

        UpdateDerevo();
        }

if(number_procedure_end==ViborElement)
        {
        //IdNom=DM->TableIDNOM->AsInteger;
        //IdGrp=0;
        //if (TreeView1->Selected!=NULL)
        //        {
        //        IdGrp=*(int*)TreeView1->Selected->Data;
        //        }
        //UpdateForm();
        }

if (number_procedure_end==ViborNom)
		{
		if (type_event==1)
				{
				DM->Table->Edit();
				DM->TableIDNOM_SVESNOM->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
                DM->TableNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
				DM->Table->Post();
				}
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
//--------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::DeleteElement()
{
//
}
//-------------------------------------------------------------------
// редактирование групп
void __fastcall TFormaSpiskaSprVesNom::ToolButtonNewScaleClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::ToolButtonEdiScaleClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::ToolButtonDeleteScaleClick(
      TObject *Sender)
{
DeleteGrpElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::OpenFormGrpElement()
{

if (FormaGrpElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpVesNom.1",IID_IFormaElementaSprGrpVesNom,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
                }
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::OpenFormNewGrpElement()
{
if (FormaGrpElementa==0)
		{
		if(IdScale!=0)
			{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpVesNom.1",IID_IFormaElementaSprGrpVesNom,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
			if (!FormaGrpElementa) return;

			if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                FormaGrpElementa->DM->NewElement(IdScale,IdGrp);
                }
			else
                {
                FormaGrpElementa->DM->NewElement(IdScale,0);
                }
			FormaGrpElementa->NumberProcVibor=ViborGrp;
			}
		else
			{
             ShowMessage("Необходимо выбрать весы!");
			}
		}
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
				}

}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::EndEditGrp(void)
{
FormaGrpElementa=0;
UpdateDerevo();
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::ToolButtonNewClick(TObject *Sender)
{
//OpenFormNewElement();
DM->NewElement(IdScale, IdGrp);
OpenFormSpiskaSprNom();
}
//--------------------------------------------------------------------------
void  TFormaSpiskaSprVesNom::OpenFormSpiskaSprNom()
{
if (FormaSpiskaSprNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->NumberProcVibor=ViborNom;
        FormaSpiskaSprNom->UpdateForm();
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::ToolButtonEditClick(TObject *Sender)
{
//OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::ToolButtonDeleteClick(TObject *Sender)
{
//DeleteElement();
DM->DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::ToolButtonAllClick(TObject *Sender)
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

IdGrp=DM->TableIDGRP_SVESNOM->AsInt64;

DM->OpenTable(IdScale, IdGrp,IdTypePrice,AllElement);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::FormResize(TObject *Sender)
{

NameTypePricecxComboBox->Left=cxGrid1->Left+cxGrid1->Width-NameTypePricecxComboBox->Width;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------











//реакция на выбор группы
void __fastcall TFormaSpiskaSprVesNom::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdScale, IdGrp,IdTypePrice,AllElement);
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::cxTreeView1KeyPress(TObject *Sender,
	  char &Key)
{
if (Key==VK_RETURN)
		{
		if (cxTreeView1->Selected!=NULL)
			{
			if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
			IdGrp=*(__int64*)cxTreeView1->Selected->Data;
			DM->OpenTable(IdScale, IdGrp,IdTypePrice,AllElement);
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprVesNom::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
        if (Podbor==true)
                {
               // OpenFormPodboraNom();
                }
        else
                {
               // OutReady=true;
               // DM->OpenElement(DM->TableIDNOM->AsInteger);
               // Close();
                }
        }
else
        {
        //OpenFormElement();
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
        if (Vibor==true)
				{
				if (Podbor==true)
						{
						//OpenFormPodboraNom();
						}
				else
						{
						//OutReady=true;
					   // DM->OpenElement(DM->TableIDNOM->AsInteger);
						Close();
						}
				}
		else
				{
				//OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

        OpenFormSpiskaSprNom();

}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprVesNom::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprVesNom");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::NameScalecxComboBoxPropertiesChange(
      TObject *Sender)
{
IdScale=0;
if (NameScalecxComboBox->ItemIndex!=0)
		{
		DMScale->Table->First();
		DMScale->Table->MoveBy(NameScalecxComboBox->ItemIndex-1);
		IdScale=DMScale->TableID_SSCALE->AsInt64;
		}
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::NameTypePricecxComboBoxPropertiesChange(
      TObject *Sender)
{
IdTypePrice=0;
if (NameTypePricecxComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(NameTypePricecxComboBox->ItemIndex-1);
		IdTypePrice=DMSprTypePrice->TableID_TPRICE->AsInt64;
		}
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaSprVesNom::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprVesNom::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdVesNom", glStrToInt64(DM->TableID_SVESNOM->AsString));
	module->SetInt64Variables("glIdNom", glStrToInt64(DM->TableIDNOM_SVESNOM->AsString));
	module->SetInt64Variables("glIdTypePrice", IdTypePrice);
	module->SetInt64Variables("glIdGrp", IdGrp);
	module->SetInt64Variables("glIdScale", IdScale);
	}

module->ExecuteModule();

}
//-----------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprVesNom::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::ActionOKExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	Close();
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprVesNom::ActionSaveExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	DM->OpenTable(IdScale, IdGrp,IdTypePrice,AllElement);
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

