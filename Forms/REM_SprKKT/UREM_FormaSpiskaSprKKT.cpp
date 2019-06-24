//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprKKT.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IREM_FormaElementaSprKKT.h"
#include "IREM_FormaElementaSprGrpKKT.h"

#include "IFormaRunExternalModule.h"
#include "IREM_FormaSpiskaSprKKTDv.h"






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
__fastcall TREM_FormaSpiskaSprKKT::TREM_FormaSpiskaSprKKT(TComponent* Owner)
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
bool TREM_FormaSpiskaSprKKT::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//������� ����������
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprKKT.1",IID_IREM_DMSprKKT,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprGrpKKT.1",IID_IREM_DMSprGrpKKT,
												 (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

IdGrp=0;
AllElement=false;
Vibor=false;
Podbor=false;

LabelNameGrp->Caption="���\\...";
HintLabel->Caption="";


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaSpiskaSprKKTImpl),false);
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
int TREM_FormaSpiskaSprKKT::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::UpdateForm(void)
{
if (IdElement>0)
        {
		IdGrp=DM->GetIdGrpElementa(IdElement);
		}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_REM_SKKT",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::UpdateDerevo()
{

//������� ������ �� ����������� ������
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

cxTreeView1->Items->AddObject(NULL,"���",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_REM_SGRPKKT->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_REM_SGRPKKT->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_REM_SGRPKKT->AsString, lpIDGrp);
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
void __fastcall TREM_FormaSpiskaSprKKT::FormClose(TObject *Sender,
      TCloseAction &Action)
{

//������� ICallBack ��� �������� ������� � ���������� �����
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

DMGrp->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//--------------------------------------------------------------------------
int TREM_FormaSpiskaSprKKT::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_ViborGrp)
	{
	if (type_event==1)
		{
		EventEndViborGrp();
		}
	}

if (number_procedure_end==ER_ViborElement)
	{
	if (type_event==1)
		{
		EventEndViborElement();
		}
	}
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::EventEndViborGrp(void)
{
UpdateDerevo();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::EventEndViborElement(void)
{

		IdElement=glStrToInt64(DM->TableID_REM_SKKT->AsString);
		IdGrp=0;
		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				}

		if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
			{
			UpdateForm();
			}
}

//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::OpenFormElement()
{

		IREM_FormaElementaSprKKT * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprKKT.1",IID_IREM_FormaElementaSprKKT,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_REM_SKKT->AsString));
		FormaElementa->UpdateForm();
		FormaElementa->NumberProcVibor=ER_ViborElement;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::OpenFormNewElement()
{
		IREM_FormaElementaSprKKT * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprKKT.1",IID_IREM_FormaElementaSprKKT,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=ER_ViborElement;
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::DeleteElement()
{
		String V="�� ������������� ������ ������� "
		+DM->TableNAME_REM_SKKT->AsString+"?";
        String Z="������������� �������� ��������";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_REM_SKKT->AsString))!=true)
	{
	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
				{
				IREM_FormaElementaSprGrpKKT * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpKKT.1",IID_IREM_FormaElementaSprGrpKKT,
												 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				if (!FormaGrpElementa) return;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ER_ViborGrp;
				}

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::OpenFormNewGrpElement()
{

				IREM_FormaElementaSprGrpKKT * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpKKT.1",IID_IREM_FormaElementaSprGrpKKT,
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
		FormaGrpElementa->NumberProcVibor=ER_ViborGrp;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_REM_SKKT->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_REM_SKKT->AsString);
		}
else
		{
		AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdElement=glStrToInt64(DM->TableID_REM_SKKT->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_REM_SKKT->AsString);
		}
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprKKT::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
		}

}

//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprKKT::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("REM_SprKKT");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKKT::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TREM_FormaSpiskaSprKKT::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_REM_SKKT->AsString));
				Close();

		}
else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKKT::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						DM->OpenElement(glStrToInt64(DM->TableID_REM_SKKT->AsString));
						Close();
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaSpiskaSprKKT::cxTreeView1KeyDown(TObject *Sender,
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



void __fastcall TREM_FormaSpiskaSprKKT::ToolButton6Click(TObject *Sender)
{
IdElement=glStrToInt64(DM->TableID_REM_SKKT->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TREM_FormaSpiskaSprKKT::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprKKT::RunExternalModule(__int64 id_module, int type_module)
{
IFormaRunExternalModule * module;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaRunExternalModule.1",IID_IFormaRunExternalModule,
													(void**)&module);
module->Init(InterfaceMainObject,InterfaceImpl);
module->IdModule=id_module;
module->TypeTable=1;

module->ClearModule();
module->LoadModule();


//��������� ������� ������
//TScriptDMDocRealRozn * scr_doc;
if (type_module==1 || type_module==2)
	{
//
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	scr_doc=new TScriptDMDocRealRozn();
//	scr_doc->AddClassesInScript(module);
//	//���� �������� ������� DM
//	scr_doc->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",scr_doc);
	}

if (type_module==3)
	{  //���� �������� ���������� ������, ��� �������  IDDOC
	module->SetInt64Variables("glIdKKT", glStrToInt64(DM->TableID_REM_SKKT->AsString));
	}
	
module->ExecuteModule();




}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKKT::ActionOpenTableIsmExecute(
      TObject *Sender)
{
		IREM_FormaSpiskaSprKKTDv * dv;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpiskaSprKKTDv.1",IID_IREM_FormaSpiskaSprKKTDv,
												 (void**)&dv);
		dv->Init(InterfaceMainObject,InterfaceImpl);
		dv->Vibor=false;
		dv->IdOwner=glStrToInt64(DM->TableID_REM_SKKT->AsString);
		dv->UpdateForm();;
		dv->TextZayavka="���: " +DM->TableNAME_REM_SKKT->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprKKT::ActionCloseExecute(TObject *Sender)
{
TypeEvent=1;
Close();
}
//---------------------------------------------------------------------------

