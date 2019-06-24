//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop


//------------------------------------------------------------------------------
#include "UFormaReportKartKlient.h"
#include "IDMRegVsRasch.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IFormaRunExternalModule.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaReportKartKlient::TFormaReportKartKlient(TComponent* Owner)
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
void __fastcall TFormaReportKartKlient::FormCreate(TObject *Sender)
{

//

}
//-----------------------------------------------------------------------
bool TFormaReportKartKlient::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;
Dv->Database=DM_Connection->pFIBData;

DateCon->Date=Date()+EncodeTime(23,59,59,999);
DateNach->Date=DM_Connection->GetPosNachReport();

NameFirmEdit->Text="";
NameKlientEdit->Text="";
IdKlient=0;

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaReportKartKlientImpl),false);
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
int  TFormaReportKartKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportKartKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokKlient) SpisokKlient->kanRelease();
if(SpisokFirm)SpisokFirm->kanRelease();

Dv->Active=false;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
int TFormaReportKartKlient::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_ViborKlient)
        {
		if (type_event==1)
                {
				IdKlient=SpisokKlient->DM->ElementIDKLIENT->AsInt64;
                NameKlientEdit->Text=SpisokKlient->DM->ElementNAMEKLIENT->AsString;

				}
		SpisokKlient=0;
        }

if (number_procedure_end==ER_ViborFirm)
		{
		if (type_event==1)
				{
				EndViborFirm();
                }
		SpisokFirm=0;
		}


EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------
void TFormaReportKartKlient::OpenFormSpiskaSprKlient(void)
{
if (SpisokKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
		SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokKlient->Vibor=true;
		SpisokKlient->NumberProcVibor=ER_ViborKlient;
		SpisokKlient->UpdateForm();
        }

}
//----------------------------------------------------------------------------
void TFormaReportKartKlient::OutputStringDv(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;
//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//���� ���
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DvPOSDOC_VSRASCH_DV->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//����� ���
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DvNUMDOC->AsString;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//��� ���
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=glGetNameDoc(DvTDOC->AsString);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_VSRASCH_DV->AsInteger==0)
        {
        cell->Text=FloatToStrF(DvSUM_VSRASCH_DV->AsFloat,ffFixed,10,2);
        TekOstSum=TekOstSum+DvSUM_VSRASCH_DV->AsFloat;
        AllSumPrihod=AllSumPrihod+DvSUM_VSRASCH_DV->AsFloat;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (DvTDV_VSRASCH_DV->AsInteger==1)
        {
        cell->Text=FloatToStrF(DvSUM_VSRASCH_DV->AsFloat,ffFixed,10,2);
        TekOstSum=TekOstSum-DvSUM_VSRASCH_DV->AsFloat;
        AllSumRashod=AllSumRashod+DvSUM_VSRASCH_DV->AsFloat;
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;

//�������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
if (TekOstSum!=0)
        {
        cell->Text=FloatToStrF(TekOstSum,ffFixed,10,2);
        }
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
numCol++;

numRow++;
}

//---------------------------------------------------------------------------
void TFormaReportKartKlient::OutputZagolovokReport(TSheetEditor *prForm)
{
        TcxSSHeader *cHeader;
        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
		cHeader->Size[2] = 50;
		cHeader->Size[3] = 120;
		cHeader->Size[4] = 80;
        cHeader->Size[5] = 180;
        cHeader->Size[6] = 100;

prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";

TcxSSCellObject *cell;
numRow=2;
numCol=3;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "�������� ����������� �� ������ � "+DateToStr(DateNach->Date)
                        +" �� "+DateToStr(DateCon->Date);
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 14;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "�����: "+NameFirmEdit->Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "����������: "+NameKlientEdit->Text;
cell->Style->HorzTextAlign = haLEFT;
cell->Style->Font->Size = 12;
cell->Style->Font->Style = TFontStyles() << fsBold;
prForm->SS->ActiveSheet->Rows->Size[numRow]=25;
delete cell;
numRow++;
numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);

TekOstSum=0;
//������� ������� �� ������ �������
IDMRegVsRasch * DMRegVsRasch;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegVsRasch.1",IID_IDMRegVsRasch,
													(void**)&DMRegVsRasch);
DMRegVsRasch->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegVsRasch->GetOstatokNa(DateNach->Date,IdFirm,IdKlient)==true)
        {
        cell->Text="�� ������ �������: "+FloatToStrF(DMRegVsRasch->SumOstNa,ffFixed,10,2);
        TekOstSum=DMRegVsRasch->SumOstNa;
        }
else
        {
        cell->Text="����������: ������!";
        }
DMRegVsRasch->kanRelease();
delete cell;
numRow++;
numRow++;

numCol=2;

//���������� ����� ������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

//���� ���������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���� ���.";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//����� ���������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����� ���.";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//��� ��������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="��� ���.";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���������� �����";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���������� �����";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//�������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaReportKartKlient::OutputPodavalReport(TSheetEditor *prForm)
{

numCol=2;

//���������� ����� ������
TcxSSCellObject *cell;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//����
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "�����: ";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//����
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = "";
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllSumPrihod,ffFixed,10,2);
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(AllSumRashod,ffFixed,10,2);
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;
//�������
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text = FloatToStrF(TekOstSum,ffFixed,10,2);
cell->Style->Brush->BackgroundColor=14;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;



numRow++;
numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
//������� ������� �� ����� �������
IDMRegVsRasch * DMRegVsRasch;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegVsRasch.1",IID_IDMRegVsRasch,
													(void**)&DMRegVsRasch);
DMRegVsRasch->Init(InterfaceMainObject,InterfaceImpl);
if (DMRegVsRasch->GetOstatokNa(DateCon->Date,IdFirm,IdKlient)==true)
        {
        cell->Text="�� ����� �������: "+FloatToStrF(DMRegVsRasch->SumOstNa,ffFixed,10,2);
        }
else
        {
        cell->Text="������������: ������!";
        }
DMRegVsRasch->kanRelease();
delete cell;
numRow++;
numRow++;
}
//---------------------------------------------------------------





void __fastcall TFormaReportKartKlient::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Report/RepKartKlient");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKartKlient::cxButtonCreateClick(TObject *Sender)
{
TSheetEditor *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
TekOstSum=0;
AllSumPrihod=0;
AllSumRashod=0;

Dv->Active=false;
Dv->ParamByName("PARAM_POSNACH")->AsDateTime=DateNach->Date;
Dv->ParamByName("PARAM_POSCON")->AsDateTime=DateCon->Date;
Dv->ParamByName("PARAM_IDKLIENT")->AsInt64=IdKlient;
Dv->ParamByName("PARAM_IDFIRM")->AsInt64=IdFirm;
Dv->Active=true;

//�����
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//�������
Dv->First();
porNumStr=1;
while(!Dv->Eof)
        {
        OutputStringDv(PrintForm);

        Dv->Next();
        porNumStr++;

        }


OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();

PrintForm->Show();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaReportKartKlient::NameKlientEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		OpenFormSpiskaSprKlient();
		}break;
	case 1:
		{
		IdKlient=0;
		NameKlientEdit->Text="";
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaReportKartKlient::NameFirmEditPropertiesButtonClick(
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
void __fastcall TFormaReportKartKlient::EndViborFirm(void)
{


				IdFirm=SpisokFirm->DM->TableIDFIRM->AsInt64;
                NameFirmEdit->Text=SpisokFirm->DM->TableNAMEFIRM->AsString;


}
//----------------------------------------------------------------------------
void TFormaReportKartKlient::OpenFormSpiskaSprFirm(void)
{
if (SpisokFirm==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
	SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
	SpisokFirm->Vibor=true;
	SpisokFirm->NumberProcVibor=ER_ViborFirm;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaReportKartKlient::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaReportKartKlient::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaReportKartKlient::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdKlient", IdKlient);
	module->SetDateTimeVariables("glPosBegin", DateNach->Date);
	module->SetDateTimeVariables("glPosEnd", DateCon->Date);


module->ExecuteModule();

}
//-----------------------------------------------------------------------------

