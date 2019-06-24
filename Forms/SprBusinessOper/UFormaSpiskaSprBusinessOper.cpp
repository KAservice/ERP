//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//----------------------------------------------------------------------------
#include "UFormaSpiskaSprBusinessOper.h"
#include "IFormaElementaSprBusinessOper.h"
#include "IFormaElementaSprGrpBusinessOper.h"
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
__fastcall TFormaSpiskaSprBusinessOper::TFormaSpiskaSprBusinessOper(TComponent* Owner)
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
bool TFormaSpiskaSprBusinessOper::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprBusinessOper,IID_IDMSprBusinessOper, (void**)&DM);

DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprGrpBusinessOper,IID_IDMSprGrpBusinessOper, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;

LabelNameGrp->Caption="Бизнес операции\\...";
HintLabel->Caption="";

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
int TFormaSpiskaSprBusinessOper::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::UpdateForm(void)
{
if (IdElement>0)
        {
		IdGrp=DM->GetIdGrpBusinessOper(IdElement);
		}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_SBUSINESS_OPER",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"Бизнес операции",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_SBUSINESS_OPER_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_SBUSINESS_OPER_GRP->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_SBUSINESS_OPER_GRP->AsString, lpIDGrp);
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
void __fastcall TFormaSpiskaSprBusinessOper::FormClose(TObject *Sender,
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

//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::OpenFormElement()
{
		IFormaElementaSprBusinessOper * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprBusinessOper,IID_IFormaElementaSprBusinessOper, (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString));
		FormaElementa->Vibor=true;
		FormaElementa->NumberProcVibor=2;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::OpenFormNewElement()
{
		IFormaElementaSprBusinessOper * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprBusinessOper,IID_IFormaElementaSprBusinessOper, (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=2;
				}
		else
				{
				delete FormaElementa;
				ShowMessage(FormaElementa->DM->TextError);
				}

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::DeleteElement()
{
		String V="Вы действительно хотите удалить "
		+DM->TableNAME_SBUSINESS_OPER->AsString+"?";
        String Z="Подтверждение удаления элемента";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString))!=true)
	{
	ShowMessage("Не удалось удалить элемент справочника!  Ошибка: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::OpenFormGrpElement()
{

if (cxTreeView1->Selected!=NULL)
	{
	IFormaElementaSprGrpBusinessOper * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprGrpBusinessOper,IID_IFormaElementaSprGrpBusinessOper, (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
		FormaGrpElementa->NumberProcVibor=1;
	}

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::OpenFormNewGrpElement()
{

		IFormaElementaSprGrpBusinessOper * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprGrpBusinessOper,IID_IFormaElementaSprGrpBusinessOper, (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(0);
				}

		FormaGrpElementa->NumberProcVibor=1;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprBusinessOper::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
		{
		AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SBUSINESS_OPER->AsString);
		}
else
		{
		AllElement=true ;
		LabelNameGrp->Caption="Все элементы...";
		IdElement=glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_SBUSINESS_OPER->AsString);
		}
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
		}

}

//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBusinessOper::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprBusinessOper");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBusinessOper::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TFormaSpiskaSprBusinessOper::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString));
				Close();

		}
else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBusinessOper::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString));
						Close();

				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprBusinessOper::cxTreeView1KeyDown(TObject *Sender,
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



void __fastcall TFormaSpiskaSprBusinessOper::ToolButtonUpdateClick(TObject *Sender)
{
IdElement=glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBusinessOper::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprBusinessOper::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		UpdateDerevo();
		}

if(number_procedure_end==2)
		{
		IdElement=glStrToInt64(DM->TableID_SBUSINESS_OPER->AsString);
		IdGrp=0;
		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				}
		}


UpdateForm();

return -1;
}
//-----------------------------------------------------------------------------
