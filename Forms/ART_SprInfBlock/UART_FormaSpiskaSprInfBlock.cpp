//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UART_FormaSpiskaSprInfBlock.h"
#include "IART_FormaElementaSprInfBlock.h"
#include "IART_FormaElementaSprInfBlockGrp.h"

#include "IDMUserSetup.h"



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
__fastcall TART_FormaSpiskaSprInfBlock::TART_FormaSpiskaSprInfBlock(TComponent* Owner)
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
bool TART_FormaSpiskaSprInfBlock::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_ART_DMSprInfBlock,IID_IART_DMSprInfBlock, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
InterfaceGlobalCom->kanCreateObject(ProgId_ART_DMSprInfBlockGrp,IID_IART_DMSprInfBlockGrp, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrpElement=0;
IdElement=0;
AllElement=false;
Vibor=false;


LabelNameGrp->Caption="�������\\...";
HintLabel->Caption="";



//�������� ������ ������� �������
//InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
//DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
//DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_THLP_FormaSpiskaSprPageImpl),false);
//DMTableExtPrintForm->Table->First();
//while (!DMTableExtPrintForm->Table->Eof)
//		{
//		TMenuItem *menu=new TMenuItem(PopupMenuExtModule);
//		menu->Caption=DMTableExtPrintForm->TableNAME_EXTPRINT_FORM->AsString;
//		menu->OnClick = PopupMenuExtModuleClick;
//		PopupMenuExtModule->Items->Add(menu);
//		//static_cast<TPopupMenu*>(Sender)->Items->Add(Item);
//		DMTableExtPrintForm->Table->Next();
//		}
NoUpdateForm=false;
LoadFormSetup();

UpdateForm();
//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TART_FormaSpiskaSprInfBlock::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::UpdateForm(void)
{


if (IdElement>0)
		{
		IdGrp=DM->GetIdGrp(IdElement);
		}


DM->DataSourceTable->Enabled=false;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_ART_IB",IdElement,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;


}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::UpdateDerevo()
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

cxTreeView1->Items->AddObject(NULL,"�������",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRP_ART_IB_GRP->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_ART_IB_GRP->AsString);
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObject(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_ART_IB_GRP->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
//cxTreeView1->AlphaSort(true);


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
void __fastcall TART_FormaSpiskaSprInfBlock::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBlockSostav)FormaSpiskaSprInfBlockSostav->kanRelease();



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
//DMTableExtPrintForm->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//-------------------------------------------------------------------------------
int TART_FormaSpiskaSprInfBlock::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_GrpForm)//ViborGrp)
		{
        UpdateDerevo();
		}

if(number_procedure_end==ER_ElementForm)//ViborElement)
		{
        cxGrid1->SetFocus();
		}


if(number_procedure_end==ER_ShowPage)//ViborElement)
		{
		EndCloseFormShow();
		FormaSpiskaSprInfBlockSostav=0;
		}


if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::OpenFormElement()
{

		IART_FormaElementaSprInfBlock * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaElementaSprInfBlock,IID_IART_FormaElementaSprInfBlock,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_ART_IB->AsString));
		FormaElementa->NumberProcVibor=ER_ElementForm;
		FormaElementa->IdGrpPage=IdGrp;
		FormaElementa->NameGrp=LabelNameGrp->Caption;
		FormaElementa->UpdateForm();
		IdElement=glStrToInt64(DM->TableID_ART_IB->AsString);
}
//--------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::OpenFormNewElement()
{

		IART_FormaElementaSprInfBlock * FormaElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaElementaSprInfBlock,IID_IART_FormaElementaSprInfBlock,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->IdGrpPage=IdGrp;
				FormaElementa->NameGrp=LabelNameGrp->Caption;
				FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=ER_ElementForm;
				IdElement=glStrToInt64(FormaElementa->DM->ElementID_ART_IB->AsString);
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}
}
//-------------------------------------------------------------------------

void TART_FormaSpiskaSprInfBlock::DeleteElement()
{
		String V="�� ������������� ������ ������� "
		+DM->TableNAME_ART_IB->AsString+"?";
        String Z="������������� �������� ��������";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

if(DM->DeleteElement(glStrToInt64(DM->TableID_ART_IB->AsString))!=true)
	{
	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
	}


DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IART_FormaElementaSprInfBlockGrp * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaElementaSprInfBlockGrp,IID_IART_FormaElementaSprInfBlockGrp,
										 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=ER_GrpForm;
				}
}
//--------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::OpenFormNewGrpElement()
{

		IART_FormaElementaSprInfBlockGrp * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaElementaSprInfBlockGrp,IID_IART_FormaElementaSprInfBlockGrp,
										 (void**)&FormaGrpElementa);
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
		FormaGrpElementa->NumberProcVibor=ER_GrpForm;

}
//--------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdElement=glStrToInt64(DM->TableID_ART_IB->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_ART_IB->AsString);
        }
else
        {
        AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdElement=glStrToInt64(DM->TableID_ART_IB->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_ART_IB->AsString);
        }
UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TART_FormaSpiskaSprInfBlock::ToolButtonIsmGrpClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{  //������������� �������
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1ID_HLP_PAGE->Index];
				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
				}
			}
		}
DM->OpenTable(IdGrp,AllElement);
}

//-----------------------------------------------------------------------------

void __fastcall TART_FormaSpiskaSprInfBlock::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TART_FormaSpiskaSprInfBlock::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_ART_IB->AsString));
				Close();

		}
else
		{
		ShowPage();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TART_FormaSpiskaSprInfBlock::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{

				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableID_ART_IB->AsString));
				Close();

				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TART_FormaSpiskaSprInfBlock::cxTreeView1KeyDown(TObject *Sender,
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



//---------------------------------------------------------------------------
//������� ������
void __fastcall TART_FormaSpiskaSprInfBlock::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::RunExternalModule(__int64 id_module, int type_module)
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
//	//���� �������� ����� TScriptDMDocRealRozn
//	//������ ��� ������ � ����������
//	module->AddClassesInScript_DMDocRealRozn();
//	module->ScriptDMDocRealRozn->DM=DM;
//	module->fsScript1->AddObject("TecDMDocRealRozn",module->ScriptDMDocRealRozn);
	}

if (type_module==3)
	{  //���� �������� ���������� ������, ��� �������  IDDOC
	module->SetInt64Variables("glIdPage", glStrToInt64(DM->TableID_ART_IB->AsString));
	module->SetInt64Variables("glIdGrpPage", IdGrp);
	}
	
module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
//	delete module;
	}


}

//--------------------------------------------------------------------------

void TART_FormaSpiskaSprInfBlock::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);



dm->SaveSetupBool("FormaSpiskaSprNom","AllElement",AllElement);

dm->kanRelease();
}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::LoadFormSetup(void)
{
NoUpdateForm=true;

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);


AllElement=dm->LoadSetupBool("HLP_FormaSpiskaSprPage","AllElement");
ToolButtonAll->Down=AllElement;
dm->kanRelease();

NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TART_FormaSpiskaSprInfBlock::ToolButton7Click(TObject *Sender)
{
SaveFormSetup();	
}
//---------------------------------------------------------------------------




void __fastcall TART_FormaSpiskaSprInfBlock::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::ShowPage(void)
{

if (FormaSpiskaSprInfBlockSostav==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaSpiskaSprInfBlockSostav,IID_IART_FormaSpiskaSprInfBlockSostav,
													 (void**)&FormaSpiskaSprInfBlockSostav);
		FormaSpiskaSprInfBlockSostav->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBlockSostav->IdPage=glStrToInt64(DM->TableID_ART_IB->AsString);
		FormaSpiskaSprInfBlockSostav->DM->OpenTable(glStrToInt64(DM->TableID_ART_IB->AsString));
		FormaSpiskaSprInfBlockSostav->HeaderText=DM->TableNAME_ART_IB->AsString;
		FormaSpiskaSprInfBlockSostav->UpdateForm();
		FormaSpiskaSprInfBlockSostav->NumberProcVibor=ER_ShowPage;
		}



}
//---------------------------------------------------------------------------
void TART_FormaSpiskaSprInfBlock::EndCloseFormShow(void)
{



}
//--------------------------------------------------------------------------
