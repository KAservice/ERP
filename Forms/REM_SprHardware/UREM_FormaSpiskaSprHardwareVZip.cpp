//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSpiskaSprHardwareVZip.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IREM_FormaElementaSprHardware.h"
#include "IREM_FormaElementaSprGrpHardware.h"
#include "IFormaRunExternalModule.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"


#include "IFormaUnReport.h"
#include "IREM_FormaZayavka.h"

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
#pragma link "cxLabel"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaSpiskaSprHardwareVZip::TREM_FormaSpiskaSprHardwareVZip(TComponent* Owner)
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
bool TREM_FormaSpiskaSprHardwareVZip::Init(void)
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

//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprHardwareVZip,IID_IREM_DMSprHardwareVZip,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprGrpHardware.1",IID_IREM_DMSprGrpHardware,
												 (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

IdGrp=0;
AllElement=false;
Vibor=false;
Podbor=false;

LabelNameGrp->Caption="������������\\...";
HintLabel->Caption="";

UpdateForm();
//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaSpiskaSprHardwareVZipImpl),false);
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
int TREM_FormaSpiskaSprHardwareVZip::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZip::UpdateForm(void)
{
if (IdHardware>0)
        {
		IdGrp=DM->GetIdGrpElementa(IdHardware);
		}


DM->DataSourceTable->Enabled=false;

DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("OUT_IDHW",IdHardware,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;

if (AllElement==false)
		{
		LabelNameGrp->Caption="��� ��������...";

		}
else
		{
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
		}

SerNumcxTextEdit->Text=SerNumber1;
SerNum2cxTextEdit->Text=SerNumber2;
}
//---------------------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareVZip::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
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
	UpdateDerevo();
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
void TREM_FormaSpiskaSprHardwareVZip::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"������������",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_REM_SGRP_HARDWARE->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_REM_SGRP_HARDWARE->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_REM_SGRP_HARDWARE->AsString, lpIDGrp);
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
void __fastcall TREM_FormaSpiskaSprHardwareVZip::FormClose(TObject *Sender,
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

DM->kanRelease();
DMGrp->kanRelease();
DMTableExtPrintForm->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::EventEndViborGrp(void)
{
//UpdateDerevo();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::EventEndViborElement(void)
{

		IdHardware=glStrToInt64(DM->TableOUT_IDHW->AsString);
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
void TREM_FormaSpiskaSprHardwareVZip::OpenFormElement()
{

		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprHardware.1",IID_IREM_FormaElementaSprHardware,
												 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementa) return;
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableOUT_IDHW->AsString));
		FormaElementa->UpdateForm();
		FormaElementa->SaveElement=true;
		FormaElementa->NumberProcVibor=ER_ViborElement;

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZip::OpenFormNewElement()
{

		IREM_FormaElementaSprHardware * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprHardware.1",IID_IREM_FormaElementaSprHardware,
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
void TREM_FormaSpiskaSprHardwareVZip::DeleteElement()
{
//		String V="�� ������������� ������ ������� "
//		+DM->TableOUT_NAME_HW->AsString+"?";
//		String Z="������������� �������� ��������";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
//                {
//				return;
//				}
//
//if(DM->DeleteElement(glStrToInt64(DM->TableOUT_IDHW->AsString))!=true)
//	{
//	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
//	}
//
//
//DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZip::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
				{
				IREM_FormaElementaSprGrpHardware * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpHardware.1",IID_IREM_FormaElementaSprGrpHardware,
												 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				if (!FormaGrpElementa) return;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ER_ViborGrp;
				}

}
//--------------------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZip::OpenFormNewGrpElement()
{

IREM_FormaElementaSprGrpHardware * FormaGrpElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaElSprGrpHardware.1",IID_IREM_FormaElementaSprGrpHardware,
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
void TREM_FormaSpiskaSprHardwareVZip::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdHardware=glStrToInt64(DM->TableOUT_IDHW->AsString);
		IdGrp=glStrToInt64(DM->TableOUT_IDGRPHW->AsString);
		}
else
		{
		AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdHardware=glStrToInt64(DM->TableOUT_IDHW->AsString);
		IdGrp=glStrToInt64(DM->TableOUT_IDGRPHW->AsString);
		}

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonIsmGrpClick(TObject *Sender)
{
//if (cxTreeView1->Selected!=NULL)
//		{  //������������� �������
//		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
//		for(int i=0;i<AViewData->RowCount;i++)
//			{
//			if (AViewData->Records[i]->Selected==true)
//				{
//				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_REM_SHARDWARE->Index];
//				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
//				}
//			}
//		}
//DM->OpenTable(IdGrp,AllElement);
}

//-----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("REM_SprHardware");
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				//DM->OpenElement(glStrToInt64(DM->TableID_REM_SHARDWARE->AsString));
				Close();

		}
else
		{
		OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

						TypeEvent=1;
						//DM->OpenElement(glStrToInt64(DM->TableID_REM_SHARDWARE->AsString));
						Close();
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxTreeView1KeyDown(TObject *Sender,
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



void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButton6Click(TObject *Sender)
{
IdHardware=glStrToInt64(DM->TableOUT_IDHW->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TREM_FormaSpiskaSprHardwareVZip::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaSpiskaSprHardwareVZip::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdHardware", glStrToInt64(DM->TableOUT_IDHW->AsString));
	}


	TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
	for(int i=0;i<AViewData->RowCount;i++)
		{
		if (AViewData->Records[i]->Selected==true)
			{
			AnsiString id=AViewData->Records[i]->Values[cxGrid1DBTableView1OUT_IDHW->Index];
			module->ListAddElement(id,"","",1);
			}
		}
	
module->ExecuteModule();




}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxButtonPoiskPoSerNumClick(TObject *Sender)

{
DM->Table_FindPoSerNum1Like(IdGrp,AllElement,SerNumcxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxButtonPoiskPoSerNum2Click(TObject *Sender)

{
DM->Table_FindPoSerNum2Like(IdGrp,AllElement,SerNum2cxTextEdit->Text);
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::cxButtonPoiskPoSerNumStrClick(TObject *Sender)

{
DM->Table_FindPoSerNumStrLike(IdGrp,AllElement,SerNumcxTextEdit->Text);
}
//---------------------------------------------------------------------------
//������� ���������� �����-����
void __fastcall TREM_FormaSpiskaSprHardwareVZip::ReadShtrihCodEvent(int number, UnicodeString sh)
{

if (SerNumcxTextEdit->Focused()==true)
	{
	SerNumcxTextEdit->Text=sh;
	}
else if (SerNum2cxTextEdit->Focused()==true)
	{
	SerNum2cxTextEdit->Text=sh;
	}
else
	{//���� �� id ������������
    ShowMessage("��������� ������ �� �� �� ������������� ��:"+sh);

	}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaSpiskaSprHardwareVZip::FormActivate(TObject *Sender)
{
//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::FormDeactivate(TObject *Sender)
{
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		interf->kanRelease();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonRepIspDonorClick(TObject *Sender)

{
IFormaUnReport * rep;
InterfaceGlobalCom->kanCreateObject(ProgId_FormaUnReport,IID_IFormaUnReport,
												 (void**)&rep);
rep->Init(InterfaceMainObject,InterfaceImpl);
rep->IdHw=glStrToInt64(DM->TableOUT_IDHW->AsString);

rep->NameHardware="������������� ������: "+DM->TableOUT_NAME_HW->AsString
								+" "+DM->TableOUT_SERNUM1_HW->AsString;
rep->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSpiskaSprHardwareVZip::ToolButtonOpenZClick(TObject *Sender)

{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->TableOUT_IDZ->AsString));
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------

