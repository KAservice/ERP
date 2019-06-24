//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//----------------------------------------------------------------------------
#include "UFormaSpiskaExtModule.h"
#include "IFormaElementaExtModule.h"
#include "IFormaElementaExtModuleGrp.h"
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
__fastcall TFormaSpiskaExtModule::TFormaSpiskaExtModule(TComponent* Owner)
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
bool TFormaSpiskaExtModule::Init(void)
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

IdGrp=0;
AllElement=false;
Vibor=false;
TypeEvent=0;
ViborRekvisit=NO;

LabelNameGrp->Caption="Внешние модули\\...";
HintLabel->Caption="";

InterfaceGlobalCom->kanCreateObject("Oberon.DMExtModule.1",IID_IDMExtModule, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMExtModuleGrp.1",IID_IDMExtModuleGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

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
int TFormaSpiskaExtModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaExtModule::UpdateForm(void)
{
if (IdExtModule>0)
        {
		IdGrp=DM->GetIdGrpExtModule(IdExtModule);
		}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_EXT_MODULE",IdExtModule,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------
void TFormaSpiskaExtModule::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (__int64 i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 * lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Внешние модули",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=DMGrp->TableIDGRP_EXT_MODULE_GRP->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableID_EXT_MODULE_GRP->AsInt64;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->TableNAME_EXT_MODULE_GRP->AsString, lpIDGrp);
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
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::FormClose(TObject *Sender,
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
}
//---------------------------------------------------------------------------
int TFormaSpiskaExtModule::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
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
		IdExtModule=DM->TableID_EXT_MODULE->AsInt64;
        IdGrp=0;
		if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				}
        }


UpdateForm();
return -1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::OpenFormElement()
{
		if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
			{
			ShowMessage("Редактирование внешних модулей доступно только пользователю SYSDBA!");
			return;
			}

		IFormaElementaExtModule * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaExtModule.1",IID_IFormaElementaExtModule,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(DM->TableID_EXT_MODULE->AsInt64);
		FormaElementa->NumberProcVibor=ViborElement;
		FormaElementa->IdModule=DM->TableID_EXT_MODULE->AsInt64;
		FormaElementa->UpdateForm();

}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::OpenFormNewElement()
{

		if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
			{
			ShowMessage("Редактирование внешних модулей доступно только пользователю SYSDBA!");
			return;
			}

		IFormaElementaExtModule * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaExtModule.1",IID_IFormaElementaExtModule,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->NumberProcVibor=ViborElement;
				FormaElementa->IdModule=DM->TableID_EXT_MODULE->AsInt64;
				FormaElementa->UpdateForm();
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::DeleteElement()
{
		if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
			{
			ShowMessage("Редактирование внешних модулей доступно только пользователю SYSDBA!");
			return;
			}
			
		String V="Вы действительно хотите удалить "
		+DM->TableNAME_EXT_MODULE->AsString+"?";
        String Z="Подтверждение удаления элемента";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

if(DM->DeleteElement(DM->TableID_EXT_MODULE->AsInt64)!=true)
	{
	ShowMessage("Не удалось удалить элемент справочника!  Ошибка: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
				{
				IFormaElementaExtModuleGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaExtModuleGrp.1",IID_IFormaElementaExtModuleGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
                }

}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::OpenFormNewGrpElement()
{

				IFormaElementaExtModuleGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaExtModuleGrp.1",IID_IFormaElementaExtModuleGrp,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=ViborGrp;

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(0);
				}


}
//--------------------------------------------------------------------------
void TFormaSpiskaExtModule::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
		{
		AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdExtModule=DM->TableID_EXT_MODULE->AsInt64;
		IdGrp=DM->TableIDGRP_EXT_MODULE->AsInt64;
		}
else
		{
		AllElement=true ;
		LabelNameGrp->Caption="Все элементы...";
		IdExtModule=DM->TableID_EXT_MODULE->AsInt64;
		IdGrp=DM->TableIDGRP_EXT_MODULE->AsInt64;
		}
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
		}

}

//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaExtModule::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("ExtModules");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TFormaSpiskaExtModule::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(DM->TableID_EXT_MODULE->AsInt64);
				Close();

		}
else
		{
		RunExternalModule();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(DM->TableID_EXT_MODULE->AsInt64);
						Close();

				}
		else
				{
				RunExternalModule();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaExtModule::cxTreeView1KeyDown(TObject *Sender,
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
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::ToolButtonUpdateClick(TObject *Sender)
{
IdExtModule=DM->TableID_EXT_MODULE->AsInt64;
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::cxButtonOpenDesignerClick(
	  TObject *Sender)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->OpenDesignerFastReport();
}
//---------------------------------------------------------------------------
void TFormaSpiskaExtModule::RunExternalModule(void)
{
//проверим права на запуск данного отчета
if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
	{
	IDMExtModulePriv *priv;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMExtModulePriv.1",IID_IDMExtModulePriv,
													(void**)&priv);
	priv->Init(InterfaceMainObject,InterfaceImpl);
	bool enable=priv->CheckPriv(glStrToInt64(DM->TableID_EXT_MODULE->AsString),
		glStrToInt64(DM_Connection->UserInfoIDGRP_USER->AsString));

	priv->kanRelease();

	if (enable==false)
		{
		ShowMessage("У Вас нет прав на запуск данного модуля!");
		return;
		}
    }

IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);

module->IdModule=glStrToInt64(DM->TableID_EXT_MODULE->AsString);
module->TypeTable=2;

module->ClearModule();
module->LoadModule();

module->ExecuteModule();

//delete module;
}
//-----------------------------------------------------------------------------

void __fastcall TFormaSpiskaExtModule::cxButtonRunReportClick(TObject *Sender)
{
RunExternalModule();
}
//---------------------------------------------------------------------------






void __fastcall TFormaSpiskaExtModule::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

