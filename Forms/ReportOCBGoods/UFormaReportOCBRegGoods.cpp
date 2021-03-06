//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop
//----------------------------------------------------------------------------
#include "UFormaReportOCBRegGoods.h"
#include "IDMSprPrice.h"
#include "UReportOCBRegGoods.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaReportOCBRegGoods::TFormaReportOCBRegGoods(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegGoods::FormCreate(TObject *Sender)
{
//
}
//-----------------------------------------------------------------------
bool TFormaReportOCBRegGoods::Init(void)
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

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameGrpNomEdit->Text="";
NameNomEdit->Text="";
NameBusinessOpercxButtonEdit->Text="";
NameProjectcxButtonEdit->Text="";

flObrabatChangeTypePrice=false;

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportOCBRegGoodsImpl),false);
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
int  TFormaReportOCBRegGoods::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegGoods::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokSklad) SpisokSklad->kanRelease();
if(SpisokFirm) SpisokFirm->kanRelease();
if(SpisokGrpNom) SpisokGrpNom->kanRelease();
if(SpisokNom) SpisokNom->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprNom(void)
{
if (SpisokNom==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&SpisokNom);
		SpisokNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokNom->Vibor=true;
		SpisokNom->NumberProcVibor=ViborNom;
        SpisokNom->IdNom=IdNom;
        SpisokNom->UpdateForm();
        }
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
		SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
		SpisokFirm->Vibor=true;
		SpisokFirm->NumberProcVibor=ViborFirm;
        }
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprGrpNom(void)
{
if (SpisokGrpNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpNom.1",IID_IFormaSpiskaSprGrpNom,
													(void**)&SpisokGrpNom);
		SpisokGrpNom->Init(InterfaceMainObject,InterfaceImpl);
		SpisokGrpNom->Vibor=true;
		SpisokGrpNom->NumberProcVibor=ViborGrpNom;
        SpisokGrpNom->UpdateForm();
		}
}
//---------------------------------------------------------------------------
int TFormaReportOCBRegGoods::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ViborSklad)
        {
		if (type_event==1)
                {
				IdSkl=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSkladEdit->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                }
        SpisokSklad=0;
        }

if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
                {
				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;
                }
        SpisokFirm=0;
        }

if (number_procedure_end==ViborGrpNom)
        {
		if (type_event==1)
                {
				IdGrpNom=SpisokGrpNom->DMGrp->ElementIDGN->AsInt64;
                NameGrpNomEdit->Text=SpisokGrpNom->DMGrp->ElementNAMEGN->AsString;
                IdNom=0;
                NameNomEdit->Text="";
                }
        SpisokGrpNom=0;
        }


if (number_procedure_end==ViborNom)
        {
        if (type_event==1)
                {
				IdNom=glStrToInt64(SpisokNom->DM->TableIDNOM->AsString);
                NameNomEdit->Text=SpisokNom->DM->TableNAMENOM->AsString;
                IdGrpNom=0;
                NameGrpNomEdit->Text="";
                }
        SpisokNom=0;
        }

if (number_procedure_end==ER_ViborProject)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

if (number_procedure_end==ER_ViborBusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}

EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprSklad(void)
{
if (SpisokSklad==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
		SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
		SpisokSklad->Vibor=true;
		SpisokSklad->NumberProcVibor=ViborSklad;
        }

}
//----------------------------------------------------------------------------













void __fastcall TFormaReportOCBRegGoods::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepOstNom");
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegGoods::CreateReport(void)
{

if (DocDvcxCheckBox->Checked==true && IdNom==0)
        {
		UnicodeString V="�� ������� ������������! ��� ���������� ������ ����������� �����. ����������?";
		UnicodeString Z="��������!";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                }
        else
                {
                return;
                }
		}

TReportOCBRegGoods * report=new TReportOCBRegGoods();
report->DM_Connection=DM_Connection;
report->InterfaceGlobalCom=InterfaceGlobalCom;
report->InterfaceMainObject=InterfaceMainObject;


report->Init();
report->DateNach=DateNach->Date;
report->DateCon=DateCon->Date;
report->IdFirm=IdFirm;
report->IdSkl=IdSkl;
report->IdGrpNom=IdGrpNom;
report->IdNom=IdNom;
report->OutputDocDv=DocDvcxCheckBox->Checked;
report->CreateReport();
delete report;

}
//---------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegGoods::cxButtonCreateClick(TObject *Sender)
{
CreateReport();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaReportOCBRegGoods::NameNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprNom();
		}break;
	case 1:
		{
		IdNom=0;
		NameNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegGoods::NameGrpNomEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprGrpNom();
		}break;
	case 1:
		{
		IdGrpNom=0;
		NameGrpNomEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegGoods::NameSkladEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprSklad();
		}break;
	case 1:
		{
		IdSkl=0;
		NameSkladEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegGoods::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprFirm();   
		}break;
	case 1:
		{
		IdFirm=0;
		NameFirmEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaReportOCBRegGoods::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegGoods::RunExternalModule(__int64 id_module, int type_module)
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


	module->SetInt64Variables("glIdFirm", IdFirm);
	module->SetInt64Variables("glIdSklad", IdSkl);
	module->SetInt64Variables("glIdGrpNom", IdGrpNom);
	module->SetInt64Variables("glIdNom", IdNom);
		module->SetInt64Variables("glIdBusinessOper", IdBusinessOper);
	module->SetInt64Variables("glIdProject", IdProject);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);

	
module->ExecuteModule();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegGoods::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprProject(void)
{

if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_ViborProject;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void  TFormaReportOCBRegGoods::EndViborProject(void)
{


		IdProject=glStrToInt64(SpisokProject->DM->TableID_SPROJECT->AsString);
		NameProjectcxButtonEdit->Text=SpisokProject->DM->TableNAME_SPROJECT->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportOCBRegGoods::OpenFormSpiskaSprBusinessOper(void)
{

if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_ViborBusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void TFormaReportOCBRegGoods::EndViborBusinessOper(void)
{


		IdBusinessOper=glStrToInt64(SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString);
		NameBusinessOpercxButtonEdit->Text=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;


}
//----------------------------------------------------------------------------
void __fastcall TFormaReportOCBRegGoods::NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprBusinessOper();
		}break;
	case 1:
		{
		IdBusinessOper=0;
		NameBusinessOpercxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportOCBRegGoods::NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprProject();
		}break;
	case 1:
		{
		IdProject=0;
		NameProjectcxButtonEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

