//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop


#include "UFormaSpiskaSprKlient.h"
#include "IFormaElementaSprKlient.h"
#include "IDMSprGrpKlient.h"
#include "IFormaElementaSprGrpKlient.h"


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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprKlient::TFormaSpiskaSprKlient(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;

IdGrp=0;
AllElement=false;
Vibor=false;
HintLabel->Caption="";
}
//---------------------------------------------------------------------------
bool TFormaSpiskaSprKlient::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpKlient.1",IID_IDMSprGrpKlient, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;



//заполним список внешних модулей
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprKlientImpl),false);
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

UpdateForm();
result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprKlient::FormClose(TObject *Sender,
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

DMTableExtPrintForm->kanRelease();
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
void TFormaSpiskaSprKlient::UpdateForm(void)
{
if (IdKlient>0)
		{
		IdGrp=DM->GetIdGrpKlient(IdKlient);
		}

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("IDKLIENT",IdKlient,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
//
void TFormaSpiskaSprKlient::UpdateDerevo()
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
				if (IdGrp==IDData)
						{
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
						break;
						}
		}
}
//---------------------------------------------------------------------------------
int TFormaSpiskaSprKlient::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		UpdateDerevo();
		}

if (number_procedure_end==2)
		{

		}

if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OpenFormElement()
{

		IFormaElementaSprKlient * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprKlient.1",IID_IFormaElementaSprKlient,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableIDKLIENT->AsString));
		IdKlient=glStrToInt64(DM->TableIDKLIENT->AsString);
		FormaElementa->UpdateForm();
		FormaElementa->NumberProcVibor=2;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OpenFormNewElement()
{

		IFormaElementaSprKlient * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprKlient.1",IID_IFormaElementaSprKlient,
													(void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->NewElement(IdGrp);
		IdKlient=0;
		FormaElementa->UpdateForm();
		FormaElementa->NumberProcVibor=2;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprKlient::DeleteElement()
{
if (DM->DeleteElement(glStrToInt64(DM->TableIDKLIENT->AsString))==false)
	{
    ShowMessage("Ошибка при удалении элемента: "+DM->TextError);
	}

DM->OpenTable(IdGrp,AllElement);
}
//-------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonDeleteClick(
	  TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------

//--------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OpenFormGrpElement()
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
void TFormaSpiskaSprKlient::OpenFormNewGrpElement()
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
void TFormaSpiskaSprKlient::DeleteGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprKlient::ToolButtonNewGrpClick(
      TObject *Sender)
{
OpenFormNewGrpElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonEditGrpClick(
      TObject *Sender)
{
OpenFormGrpElement();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonDelGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonAllElementClick(
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
IdGrp=*(__int64*)cxTreeView1->Selected->Data;
DM->OpenTable(IdGrp,AllElement);
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprKlient::ToolButtonChancheGrpClick(
      TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }

}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprKlient::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprKlient");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprKlient::cxGrid1DBTableView1KeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
        if (Vibor==true)
				{
						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableIDKLIENT->AsString));
                        Close();

				}
		else
				{
				OpenFormElement();
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableIDKLIENT->AsString));
		Close();
		}

else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::cxTreeView1DblClick(TObject *Sender)
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

void __fastcall TFormaSpiskaSprKlient::cxTreeView1KeyDown(TObject *Sender,
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

void __fastcall TFormaSpiskaSprKlient::ToolButtonUpdateFormClick(
      TObject *Sender)
{
IdKlient=glStrToInt64(DM->TableIDKLIENT->AsString) ;
UpdateForm();
}
//---------------------------------------------------------------------------

//ПЕЧАТЬ
void TFormaSpiskaSprKlient::OpenPrintFormOnlyGrp(void)
{
__int64 id_grp=*(__int64*)cxTreeView1->Selected->Data;

IkanClassFactory * i_cf;     ISheetEditor *  PrintForm;      CLSID clsid;
InterfaceGlobalCom->kanCLSIDFromProgID("Oberon.SheetEditor.1",&clsid);
if (InterfaceGlobalCom->kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) !=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_IkanClassFactory объекта CLSID_TSheetEditorImpl!");
	}

if (i_cf->kanCreateInstance(IID_ISheetEditor,(void**)&PrintForm)!=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_ISheetEditor!");
	return;
	}
i_cf->kanRelease();

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

OutputStringGrp(PrintForm,cxTreeView1->Selected->Text);

CreateReport(PrintForm,id_grp);

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OpenPrintForm(void)
{
IkanClassFactory * i_cf;     ISheetEditor *  PrintForm;      CLSID clsid;
InterfaceGlobalCom->kanCLSIDFromProgID("Oberon.SheetEditor.1",&clsid);
if (InterfaceGlobalCom->kanGetClassObject(clsid,IID_IkanClassFactory,(void**)&i_cf) !=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_IkanClassFactory объекта CLSID_TSheetEditorImpl!");
	}
if (i_cf->kanCreateInstance(IID_ISheetEditor,(void**)&PrintForm)!=-1)
	{
	ShowMessage("Ошибка при получении интерфейса IID_ISheetEditor!");
	return;
	}
i_cf->kanRelease();

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);


TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM->Table->Database;
		query->Transaction=DM->IBTr;
		query->SQL->Add(" select NAMEKLIENT, ADRKLIENT, INNKLIENT, TELKLIENT");
		query->SQL->Add(" from SKLIENT ");
		query->SQL->Add(" where IDGRPKLIENT IS NULL");
		query->SQL->Add(" ORDER BY NAMEKLIENT");
		if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
		query->ExecQuery();
		while (!query->Eof)
			{
			OutputString( PrintForm,
						query->FieldByName("NAMEKLIENT")->AsString,
						query->FieldByName("ADRKLIENT")->AsString,
						query->FieldByName("INNKLIENT")->AsString,
						query->FieldByName("TELKLIENT")->AsString);

			query->Next();
			}
	}
__finally
	{
	delete query;
	}

CreateReport(PrintForm,0);

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();

}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::CreateReport(ISheetEditor *prForm, __int64 id_grp)
{
TpFIBQuery * query=new TpFIBQuery(0);
try {    
		query->Database=DM->Table->Database;
		query->Transaction=DM->IBTr;
		if (id_grp==0)
			{
			query->SQL->Add(" select IDGRPKL, NAMEGRPKL");
			query->SQL->Add(" from SGRPKL ");
			query->SQL->Add(" where GRPKL IS NULL");
			query->SQL->Add(" ORDER BY NAMEGRPKL");
			}
		else
			{
			query->SQL->Add(" select IDGRPKL, NAMEGRPKL");
			query->SQL->Add(" from SGRPKL ");
			query->SQL->Add(" where GRPKL="+IntToStr(id_grp));
			query->SQL->Add(" ORDER BY NAMEGRPKL");
			}
		if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
		query->ExecQuery();

			while (!query->Eof)
				{
				OutputStringGrp( prForm,
						query->FieldByName("NAMEGRPKL")->AsString);
				CreateReport(prForm, query->FieldByName("IDGRPKL")->AsInt64);
				query->Next();
				}


				
				TpFIBQuery * query1=new TpFIBQuery(0);
				try {

					query1->Database=DM->Table->Database;
					query1->Transaction=DM->IBTr;
					query1->SQL->Add(" select NAMEKLIENT, ADRKLIENT, INNKLIENT, TELKLIENT");
					query1->SQL->Add(" from SKLIENT ");
					query1->SQL->Add(" where IDGRPKLIENT="+IntToStr(id_grp));
					query1->SQL->Add(" ORDER BY NAMEKLIENT");
					if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
					query1->ExecQuery();
					while (!query1->Eof)
							{
							OutputString( prForm,
										query1->FieldByName("NAMEKLIENT")->AsString,
										query1->FieldByName("ADRKLIENT")->AsString,
										query1->FieldByName("INNKLIENT")->AsString,
										query1->FieldByName("TELKLIENT")->AsString);

								query1->Next();
							}
					}
				__finally
					{
					delete query1;
					}
	}
__finally
	{
	delete query;
	}



}
//----------------------------------------------------------------------
void TFormaSpiskaSprKlient::OutputZagolovokReport(ISheetEditor *prForm)
{
prForm->DefaultFontName="Arial";
prForm->DefaultFontSize=10;

prForm->RowsAutoHeight=true;


prForm->SetColumnWidth(0,10);
prForm->SetColumnWidth(1,10);
prForm->SetColumnWidth(2,50);
prForm->SetColumnWidth(3,200);
prForm->SetColumnWidth(4,100);
prForm->SetColumnWidth(5,100);

		
prForm->TecCell_GetObject(3,numRow);
prForm->TecCell_SetFontSize(16);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetText("Контрагенты");
prForm->TecCell_DeleteObject();
numRow++;

}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OutputStringGrp(ISheetEditor * prForm,
											AnsiString name_grp)
{
numCol=2;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(name_grp);
prForm->TecCell_SetFontSize(12);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;




prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
prForm->ClearHistory();
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OutputString(ISheetEditor * prForm,
							AnsiString name,
							AnsiString adr,
							AnsiString inn,
							AnsiString tel)
{
numCol=2;
prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(IntToStr(porNumStr));
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(name);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(adr);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_DeleteObject();
numCol++;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(inn);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(tel);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
porNumStr++;
prForm->ClearHistory();
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::OutputPodavalReport(ISheetEditor * prForm)
{

}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprKlient::ToolButtonPrintOnlyGrpClick(
      TObject *Sender)
{
OpenPrintFormOnlyGrp();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprKlient::ToolButtonPrintAllClick(TObject *Sender)
{
OpenPrintForm();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Внешние модули
void __fastcall TFormaSpiskaSprKlient::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprKlient::RunExternalModule(__int64 id_module, int type_module)
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
//	//надо добавить класс TScriptDMDocRealRozn
//	//методы для работы с документом
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

if (type_module==3)
	{  //надо добавить переменные модуля, как минимум  IDDOC
	module->SetInt64Variables("glIdKlient", glStrToInt64(DM->TableIDKLIENT->AsString));
	module->SetInt64Variables("glIdGrpKlient", IdGrp);
	}
	
module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
//	delete module;
	}


}
//-----------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprKlient::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

