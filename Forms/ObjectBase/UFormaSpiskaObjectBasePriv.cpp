//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//-----------------------------------------------------------------------------
#include "UFormaSpiskaObjectBasePriv.h"
#include "UGlobalConstant.h"
#include "IDMQueryUpdate.h"
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLabel"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaSpiskaObjectBasePriv::TFormaSpiskaObjectBasePriv(TComponent* Owner)
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
bool TFormaSpiskaObjectBasePriv::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMObjectBasePriv.1",IID_IDMObjectBasePriv, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMObjectBaseGrp.1",IID_IDMObjectBaseGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpUser.1",IID_IDMSprGrpUser, (void**)&DMGrpUser);
DMGrpUser->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

DMGrpUser->OpenTable();
NameGrpUsercxLookupComboBox->Properties->ListSource=DMGrpUser->DataSourceTable;


IdGrpUser=0;
AllElement=false;
Vibor=false;


LabelNameGrp->Caption="Привелегии\\...";
HintLabel->Caption="";


//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaObjectBasePrivImpl),false);
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
int TFormaSpiskaObjectBasePriv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::UpdateForm(void)
{

DM->DataSourceTable->Enabled=false;
DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);
TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_OBJECT_BASE_PRIV",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::FormClose(TObject *Sender,
	  TCloseAction &Action)
{

if(SpisokProgramModule) SpisokProgramModule->kanRelease();


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
DMGrpUser->kanRelease();
DMTableExtPrintForm->kanRelease();
Action=caFree;
}
//----------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"Привелегии",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_OBJECT_BASE_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_OBJECT_BASE_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_OBJECT_BASE_GRP->AsString, lpIDGrp);
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
//--------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::DeleteElement()
{
//
}
//-------------------------------------------------------------------
// редактирование групп
void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonNewScaleClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonEdiScaleClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonDeleteScaleClick(
      TObject *Sender)
{
DeleteGrpElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::OpenFormGrpElement()
{

if (FormaGrpElementa==0)
		{
		if (cxTreeView1->Selected!=NULL)
				{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaObjectBaseGrp.1",IID_IFormaElementaObjectBaseGrp,
										(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->Vibor=true;
				FormaGrpElementa->NumberProcVibor=ER_Grp;
				}
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::OpenFormNewGrpElement()
{
if (FormaGrpElementa==0)
		{
		if(IdGrpUser!=0)
			{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaObjectBaseGrp.1",IID_IFormaElementaObjectBaseGrp,
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
				FormaGrpElementa->Vibor=true;
				FormaGrpElementa->NumberProcVibor=ER_Grp;
			}
		else
			{
             ShowMessage("Заданы не все параметры!");
			}
		}
}
//----------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
				}

}
//----------------------------------------------------------------------------
int TFormaSpiskaObjectBasePriv::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_Grp)
		{
		if (type_event==1)
				{
				UpdateDerevo();
				}
		FormaGrpElementa=0;
		}

if (number_procedure_end==ER_ProgramModule)
		{
		if (type_event==1)
				{
				EndViborProgramModule();
				}
		SpisokProgramModule=0;
		}

return -1;
}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonNewClick(TObject *Sender)
{
//OpenFormNewElement();
DM->Table_AppendString(NumApplication, IdGrpUser, IdGrp);;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonDeleteClick(TObject *Sender)
{
DM->Table_Delete();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonAllClick(TObject *Sender)
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

IdGrp=glStrToInt64(DM->TableIDGRP_OBJECT_BASE_PRIV->AsString);

DM->OpenTable(NumApplication,IdGrpUser, IdGrp, AllElement);
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaObjectBasePriv::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------











//реакция на выбор группы
void __fastcall TFormaSpiskaObjectBasePriv::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::cxTreeView1KeyPress(TObject *Sender,
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
			DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);;
			}
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
        {
		TypeEvent=1;
		Close();
        }
else
        {
        //OpenFormElement();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaObjectBasePriv::cxGrid1DBTableView1KeyPress(
      TObject *Sender, char &Key)
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
				//OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------





void __fastcall TFormaSpiskaObjectBasePriv::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ObjectBase");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaObjectBasePriv::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//добавляем текущий модуль
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

if (type_module==1 || type_module==2 || type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdElement", glStrToInt64(DM->TableID_OBJECT_BASE_PRIV->AsString));
	module->SetInt64Variables("glIdGrp", IdGrp);
	module->SetInt64Variables("glIdGrpUser", IdGrpUser);
	}

module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
	}
//delete module;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaSpiskaObjectBasePriv::ToolButton5Click(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaObjectBasePriv::NameGrpUsercxLookupComboBoxPropertiesEditValueChanged(
      TObject *Sender)
{
IdGrpUser=NameGrpUsercxLookupComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaObjectBasePriv::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaObjectBasePriv::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaSpiskaObjectBasePriv::ActionSaveExecute(TObject *Sender)
{
if(DM->SaveIsmen()==true)
	{
	DM->OpenTable(NumApplication, IdGrpUser, IdGrp, AllElement);;
	}
else
	{
	ShowMessage("Ошибка при записи изменений: "+DM->TextError);
	}

}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::CreateFullStandartPriv(int application, __int64 id_grp_user)
{
switch (application)
		{
		case 1 :       //обычное приложение
				{
				if (ClearPriv(application, id_grp_user)==true)
					{
					CreateFullStandartPriv_Appl(id_grp_user);
					}
				} break;

		case 2 :       //WEB приложение
				{
				if (ClearPriv(application, id_grp_user)==true)
					{
					CreateFullStandartPriv_WebAppl(id_grp_user);
					}
				} break;

		default :
				{
				 ShowMessage("Неизвестное приложение!");
				} break;
		}

}
//----------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::CreateFullStandartPriv_Appl(__int64 id_grp_user)
{
//__int64 id_grp=InsertGrpMainMenu(1,id_grp_user,0,"Справочники");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Номенклатура",	GC_FormaSpiskaSprNom);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Контрагенты",	GC_FormaSpiskaSprKlient);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Быстрый вызов",	GC_FormaSpiskaSprBVNom);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Весовая номенклатура",	GC_FormaSpiskaSprVesNom);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Карты",	GC_FormaSpiskaSprDiscountCard1);
//	}
//
//id_grp=InsertGrpMainMenu(1,id_grp_user,0,"Документы");
//if (id_grp!=0)
//	{
//	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Поставщики");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Поступление товаров", GC_FormaDocPrihNakl);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Возврат поставщику",	GC_FormaDocVosvratPost);
//		}
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Оптовая торговля");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Реализация", GC_FormaDocReal);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Счет на оплату",	GC_FormaDocSchet);
//		}
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Розничная торговля");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Чек ККМ", GC_FormaDocCheck);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Отчет ККМ",	GC_FormaDocRepKKM);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Реализация розн.", GC_FormaDocRealRozn);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Приход нал.",	GC_FormaDocPKORozn);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Расход нал.",	GC_FormaDocRKORozn);
//		}
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Касса");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Прих. кассовый ордер", GC_FormaDocPKO);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Расх. кассовый ордер",	GC_FormaDocRKO);
//		}
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Банк");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Платежное поручение", GC_FormaDocPlatPor);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Поступление на счет",	GC_FormaDocPostNaSchet);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Выписка банка", GC_FormaDocVipBanka);
//		}
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Склад");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Перемещение", GC_FormaDocPer);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Переоценка",	GC_FormaDocIsmPrice);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Ревизия", GC_FormaDocRev);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Списание отр. остатков",	GC_FormaDocSpOtrOst);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Инвентаризация",	GC_FormaDocInv);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Ввод остатков номенклатуры", GC_FormaDocOstNom);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Акт списания",	GC_FormaDocSpisNom);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Выпуск продукции", GC_FormaDocVipuskProd);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Сборка комплекта",	GC_FormaDocSborkaKompl);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Разборка комплекта",	GC_FormaDocRasborkaKompl);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Замена",	GC_FormaDocZamena);
//		}
//
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Корректировка взаиморасчетов",	GC_FormaDocOstVs);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Корректировка взаиморасчетов 2",	GC_FormaDocKorrVs);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Возврат от покупателя",	GC_FormaDocVosvratPok);
//
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Сервисные документы");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Авансы", GC_FormaDocRegAdvCust);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Банк",	GC_FormaDocRegBank);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Остатки товаров",GC_FormaDocRegGoods);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Остатки партий товаров",GC_FormaDocRegOstNom);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Касса",	GC_FormaDocRegKassa);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Оплата реализации", GC_FormaDocRegPaySale);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Взаиморасчеты",	GC_FormaDocRegVsRasch);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Движения регистра Средства на картах", GC_FormaDocRegCardBal);
//		}
//
//	}
//
//
//id_grp=InsertGrpMainMenu(1,id_grp_user,0,"Журналы");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Полный",	GC_FormaGurAllDoc);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Прих. накладные",	GC_FormaGurDocPrihNakl);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Чеки ККМ",	GC_FormaGurDocCheckKKM);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Перемещения",	GC_FormaGurDocPer);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Операции с накопительными картами",	GC_FormaGurOperDiscountCard);
//	}
//
//id_grp=InsertGrpMainMenu(1,id_grp_user,0,"Отчеты");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Остатки и движения товаров",GC_FormaReportOCBRegGoods);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Остатки и движения партий товаров",GC_FormaReportOCBRegOstNom);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Карточка товара",	GC_FormaReportKartTovara);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Розничные продажи",GC_FormaDialogaReportSaleCheck);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Взаиморасчеты",	GC_FormaReportOCBRegVSRasch);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Карточка контрагента",	GC_FormaReportKartKlient);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Доход от реализации",	GC_FormaDialogaReportResultReal);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Выпуск продукции",	GC_FormaReportVipuskProd);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Раход продуктов",	GC_FormaReportRashodProduct);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Калькул. карта",	GC_FormaReportKalkKarta);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Отчет по кредитам",GC_FormaReportOCBPaySale);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Отчет по кассе",	GC_FormaReportKassa);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Отчет по банку",	GC_FormaReportBank);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Отчет о скидках",	GC_FormaReportDiscountDocCheck);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Товарный отчет",	GC_FormaReportGoodsReport);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Отчет по проектам",GC_FormaDialogaReportPoProject);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Ост. и дв. средств на плат. картах",GC_FormaReportOCBCardBalance);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Внешние модули",	GC_FormaSpiskaExtModule);
//	}
//
//id_grp=InsertGrpMainMenu(1,id_grp_user,0,"Сервис");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Настройка меню", GC_FormaSpiskaInterfMainMenu);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Пользователи",	GC_FormaSpiskaSprUser);
//
//	__int64 id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Файловый обмен");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Загрузка приходных накладных", GC_FormaImportDocPrihNakl);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Настройки импорта (Excel)",	GC_FormaSpiskaSprImportSet);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Обмен XML",GC_FormaExportDoc);
//		}
//
//	id_grp1=InsertGrpMainMenu(1,id_grp_user,id_grp,"Предприятие");
//	if(id_grp1!=0)
//		{
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Информационные базы", GC_FormaSpiskaSprInfBase);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Фирмы",	GC_FormaSpiskaSprFirm);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Типы цен",GC_FormaSpiskaSprTypePrice);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Кассы", GC_FormaSpiskaSprKKM);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Структура ресторана",	GC_FormaSpiskaSprStrObject);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Склады",GC_FormaSpiskaSprSklad);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Подразделения", GC_FormaSpiskaSprPodr);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Места изготовления",	GC_FormaSpiskaSprMPrig);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Телефонные коды",GC_FormaSpiskaSprCodeTel);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Инвентаризации", GC_FormaSpiskaSprInv);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Виды контрагентов",	GC_FormaSpiskaSprVidKlient);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Виды номенклатуры",GC_FormaSpiskaSprVidNom);
//
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Автомат. скидки", GC_FormaImportDocPrihNakl);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Виды дисконтных карт",	GC_FormaSpiskaSprVidDiscountCard);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Накопительныйе скидки",GC_FormaSpiskaSprNakSkidok);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Весы", GC_FormaSpiskaSprScale);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Проекты",	GC_FormaSpiskaSprProject);
//		InsertItemMainMenu(1,id_grp_user,id_grp1,"Бренды",GC_FormaSpiskaSprBrand);
//		}
//
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Настройки", GC_FormaSpiskaSetup);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"АРМ",	GC_FormaSpiskaSprARM);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Журнал событий", GC_FormaGurLog);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Табличный редактор",	GC_SheetEditor);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Печать ценников и этикеток", GC_FormaPrintPriceA);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Типы нумерации документов",	GC_FormaSpiskaTableNumberDoc);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Настройка параметров обмена", GC_FormaSpiskaXSetupObmen);
//	InsertItemMainMenu(1,id_grp_user,id_grp,"Внешние модули объектов",	GC_FormaSpiskaTableExtPrintForm);
//	}

}
//----------------------------------------------------------------------------
__int64 TFormaSpiskaObjectBasePriv::InsertGrpObject(__int64 id_grp, UnicodeString name_main_menu)
{
__int64 result=0;
//TDMObjectBaseGrp * dm_grp=new TDMObjectGrp(Application);
//dm_grp->NewElement(id_grp_user,id_grp);
//dm_grp->Element_Edit();
//dm_grp->ElementNAME_OBJECT_BASE_GRP->AsString=name_main_menu;
//
//if (id_grp!=0)
//	{
//	dm_grp->ElementIDGRP_INTERF_MAINMENU_GRP->AsString=id_grp;
//	}
//dm_grp->Element_Post();
//
//result=glStrToInt64(dm_grp->ElementID_INTERF_MAINMENU_GRP->AsString);
//if (dm_grp->SaveElement()==false)
//	{
//	ShowMessage("Ошибка при вставке группы меню " + dm_grp->TextError);
//	result=0;
//	}
//delete dm_grp;
return result;
}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::InsertItemPriv(int application, __int64 id_grp_user,
									__int64 id_grp,
									int number_form)
{
//TDMInterfMainMenu * dm=new TDMInterfMainMenu(Application);
//if (dm->NewElement(application,id_grp_user,id_grp)==false)
//	{
//	ShowMessage("Ошибка при вставке пункта меню "+name_main_menu+" "+dm->TextError);
//	}
//
//dm->Element_Edit();
//dm->ElementNAME_INTERF_MAINMENU->AsString=name_main_menu;
//dm->ElementAPPLICATION_INTERF_MAINMENU->AsInteger=application;
//dm->ElementIDGRPUSER_INTERF_MAINMENU->AsString=id_grp_user;
//dm->ElementMODUL_INTERF_MAINMENU->AsString=number_form;
//if (id_grp!=0)
//	{
//	dm->ElementIDGRP_INTERF_MAINMENU->AsString=id_grp;
//	}
//dm->Element_Post();
//
//if (dm->SaveElement()==false)
//	{
//	ShowMessage("Ошибка при записи пункта меню " + dm->TextError);
//	}
//delete dm;

}
//----------------------------------------------------------------------------
bool TFormaSpiskaObjectBasePriv::ClearPriv(int application, __int64 id_grp_user)
{
bool result=true;
//TDMInterfMainMenu * dm=new TDMInterfMainMenu(Application);
//dm->OpenTable(application,id_grp_user,0,true);
//dm->Table->First();
//
//while(!dm->Table->Eof)
//	{
//	dm->Table_Delete();
//	}
//
//dm->SaveIsmen();
//delete dm;
//
//TDMQueryUpdate * q=new TDMQueryUpdate(Application);
//q->pFIBQ->SQL->Clear();
//q->pFIBQ->SQL->Add("update interf_mainmenu_grp set interf_mainmenu_grp.idgrp_interf_mainmenu_grp=null   \
//					where interf_mainmenu_grp.idgrpuser_interf_mainmenu_grp=:PARAM_IDGRPUSER     \
//							and interf_mainmenu_grp.application_interf_mainmenu_grp=:PARAM_APP ");
//q->pFIBQ->ParamByName("PARAM_IDGRPUSER")->AsString=id_grp_user;
//q->pFIBQ->ParamByName("PARAM_APP")->AsInteger=application;
//try
//	{
//	q->pFIBQ->ExecQuery();
//	q->pFIBTr->Commit();
//	}
//catch(Exception &exception)
//	{
//	q->pFIBTr->Rollback();
//	result=false;
//	ShowMessage("Ошибка при удалении ссылок в группах меню "+exception.Message);
//	}
//
//if (result==true)
//	{
//	q->pFIBQ->SQL->Clear();
//	q->pFIBQ->SQL->Add("delete from interf_mainmenu_grp      \
//					where interf_mainmenu_grp.idgrpuser_interf_mainmenu_grp=:PARAM_IDGRPUSER  \
//					and interf_mainmenu_grp.application_interf_mainmenu_grp=:PARAM_APP ");
//	q->pFIBQ->ParamByName("PARAM_IDGRPUSER")->AsString=id_grp_user;
//	q->pFIBQ->ParamByName("PARAM_APP")->AsInteger=application;
//
//	try
//		{
//		q->pFIBQ->ExecQuery();
//		q->pFIBTr->Commit();
//		}
//	catch(Exception &exception)
//		{
//		q->pFIBTr->Rollback();
//		result=false;
//		ShowMessage("Ошибка при удалении группы меню "+exception.Message);
//		}
//	}
//delete q;
//
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaObjectBasePriv::ActionCreateFullStandartMainMenuExecute(TObject *Sender)

{
IdGrpUser=NameGrpUsercxLookupComboBox->EditValue;
NumApplication=ApplicationcxImageComboBox->EditValue;
CreateFullStandartPriv(NumApplication,IdGrpUser);
UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::CreateFullStandartPriv_WebAppl(__int64 id_grp_user)
{
//__int64 id_grp=InsertGrpMainMenu(3,id_grp_user,0,"АРМ");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"АРМ №1",	GC_FormaARMKas1);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"АРМ №2",	GC_FormaARMKas2);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Платежи",	GC_FormaPriemPlat);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Справочники");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Номенклатура",	GC_FormaViborSprNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Быстрый вызов",GC_FormaViborSprBVNom);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Контрагенты",	GC_FormaSpiskaSprKlient);
//
//	}
//
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Документы");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Реализация розн.",	GC_FormaDocRealRoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Приход нал.",	GC_FormaDocPKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Расход нал.",	GC_FormaDocRKORoznForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Возврат от покупателя",GC_FormaVosvratPokForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Журналы");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Журнал платежей",GC_FormaGurPlat);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Журнал чеков",GC_FormaGurCheckForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Розничные документы",GC_FormaGurRoznDocForCashiers);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Отчеты");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Продажи", GC_FormaReportSaleForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Отчет по скидкам",	GC_FormaReportDiscountForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Внешние модули", GC_FormaSpiskaExtModule);
//	}
//
//id_grp=InsertGrpMainMenu(3,id_grp_user,0,"Сервис");
//if (id_grp!=0)
//	{
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Печать ценников", GC_FormaPrintPriceForCashiers);
//	InsertItemMainMenu(3,id_grp_user,id_grp,"Табличный редактор",	GC_SheetEditor);
//	}
}
//----------------------------------------------------------------------------


void __fastcall TFormaSpiskaObjectBasePriv::ApplicationcxImageComboBoxPropertiesEditValueChanged(TObject *Sender)

{
NumApplication=ApplicationcxImageComboBox->EditValue;
UpdateForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::ViborProgramModule(void)
{
if (SpisokProgramModule==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProgramModule,IID_IFormaSpiskaSprProgramModule,
													(void**)&SpisokProgramModule);
		SpisokProgramModule->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProgramModule->Vibor=true;
		SpisokProgramModule->NumberProcVibor=ER_ProgramModule;
		}

}
//---------------------------------------------------------------------------
void TFormaSpiskaObjectBasePriv::EndViborProgramModule(void)
{

	DM->Table->Edit();
	DM->TableGUID_OBJECT_BASE_PRIV->AsString=SpisokProgramModule->DM->TableGUID_PROGRAM_MODULE->AsString;
	DM->TableNAME_PROGRAM_MODULE->AsString=SpisokProgramModule->DM->TableNAME_PROGRAM_MODULE->AsString;
	DM->Table->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaObjectBasePriv::cxGrid1DBTableView1NAME_PROGRAM_MODULEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProgramModule();
}
//---------------------------------------------------------------------------

