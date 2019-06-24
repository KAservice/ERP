//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "math.h"
//------------------------------------------------------------------------
#include "UFormaArmKassir2.h"
#include "IDMSprBVNom.h"
#include "IDMSprDogovor.h"
#include "IDMSprKlient.h"
#include "IDMSprFirm.h"
#include "IDMSprSklad.h"
#include "IDMRegVsRasch.h"

#include "IDMGurOperDiscountCard.h"
#include "IDMSprVidDiscountCard.h"
#include "IDMSprNakSkidok.h"
#include "IDMSprTypePrice.h"
#include "IDMSprPrice.h"
#include "IDMSetup.h"
#include "IDMRegGoods.h"
#include "IDMSprUser.h"
#include "IDMQueryRead.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"






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
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaARMKassir2::TFormaARMKassir2(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
DisplayPok=0;
}
//---------------------------------------------------------------------------
bool TFormaARMKassir2::Init(void)
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

    //���������� �������� ���������� ����������� ����������� � �������
	IDevices * i_dev;
	if (InterfaceMainObject->kanQueryInterface(IID_IDevices,(void**)&i_dev)==-1)
		{
		if (i_dev)
			{
			if(	i_dev->GetDeviceObject(2, (void**) &DisplayPok)!=-1)
				{
				DisplayPok=0;
				}
			i_dev->kanRelease();
			}
		}
	else
		{
        DisplayPok=0;
		}
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

BarCodePrefiks1="";  //������� ��������� ��, ����� �� �� �������
BarCodePrefiks2=""; //�����. ����� �� ���� ������������,  ��� � ������ ��������
BarCodePrefiks3=""; //�����. ����� �� ���� ������������, ��� �� ������ ��������
BarCodePrefiks4=""; //�����. ����� �� �� �������, ��� � ������ ��������
BarCodePrefiks5=""; //�����. ����� �� �� �������, ��� �� ������ ��������


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM,
												 (void**)&DMSprARM);
DMSprARM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&DMSprNom);
DMSprNom->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
												 (void**)&DMSprEd);
DMSprEd->Init(InterfaceMainObject,InterfaceImpl);

//InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
//												 (void**)&DM);
//DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard,
												 (void**)&DMSprDiscountCard);
DMSprDiscountCard->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
												 (void**)&ObBar);
ObBar->Init(InterfaceMainObject,InterfaceImpl);

ObBar->SprNom=DMSprNom;
ObBar->SprEd=DMSprEd;
ObBar->GetValuePrefiksBarCode();


Prosmotr=false;    //������ ��������
Vibor=false;       //��� ������
IdDoc=0;           //������������� ������� ������

CheckSave=false;
CheckPrint=false;
CheckCreate=false;
OutReady=false;

OutProtocol("������ ����� ��� �������");

IdTypePrice=0;
NameTypePrice="";
TypePriceLabel->Caption="��� ���: "+NameTypePrice;

//������� ������� �������� ����
//PrefiksVesCoda="";
//TDMSetup * dm_setup=new TDMSetup(Application);
//dm_setup->OpenElement(22);//�������� �������������� �����
//try     {
//		if(Trim(dm_setup->ElementVALUE_SETUP->AsString)!="")
//			{
//			PrefiksVesCoda=dm_setup->ElementVALUE_SETUP->AsString;
//			}
//		}
//catch(...) 	{ 	}
//delete dm_setup;

NoOtrOstatok=false;

NameKlientLabel->Caption="";
NameDiscountCardLabel->Caption="";
NameNomLabel->Caption="";
KolLabel->Caption="";
KFLabel->Caption="";
PriceLabel->Caption="";
SdachaLabel->Caption="";
NameFirmLabel->Caption="";

OperationCheck=0;
ExternalCreateCheck=false;

VesPrefiksBarCode="23";
VesTypeBarCode=1;
VesTypeSearch=1;

FormaViborOplat_ARM2=0;

	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;

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
int TFormaARMKassir2::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::UpdateForm(void)
{
DMSprARM->OpenElement(IdARM);
DMSprOborud->OpenTable(IdARM);

NameTypePrice=DMSprARM->ElementNAME_TPRICE->AsString;
NameKKMLabel->Caption="���: "+DMSprARM->ElementNAMEKKM->AsString;
TypePriceLabel->Caption="��� ���: "+NameTypePrice;

if (DMSprARM->GetParameter("UchRegime")=="1") UchLabel->Caption="������� �����!";
else UchLabel->Caption="";


IdTypePrice=glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString); 

if (DMSprARM->GetParameter("NoEditPrice")=="1")
	{
	cxGrid1TableView1PRICE->Options->Editing=false;
	}

if (DMSprARM->GetParameter("NoOtrOstatok")=="1")
	{
	NoOtrOstatok=true;
	}

DMSprDiscountAuto->OpenTableDiscountAuto(glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));

}
//-----------------------------------------------------------------------------
void TFormaARMKassir2::UpdateSetup(void)
{
ConnectDisplay();
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::UpdateParameterFR(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SprBV)SprBV->kanRelease();
if(SpisokEd)SpisokEd->kanRelease();
if(FormaViborSprNom)FormaViborSprNom->kanRelease();
if(FormaInputCode)FormaInputCode->kanRelease();

if (FormaGurDocCheckKKM2)FormaGurDocCheckKKM2->kanRelease();
if(FormaInputText)FormaInputText->kanRelease();
if(FormaInputDiscountCard)FormaInputDiscountCard->kanRelease();


DMSprARM->kanRelease();
DMSprOborud->kanRelease();
DMSprNom->kanRelease();
DMSprEd->kanRelease();
DMSprDiscountCard->kanRelease();
DMSprDiscountAuto->kanRelease();
ObBar->kanRelease();

if (DisplayPok>0)
	{
	DisplayPok->Disconnect();
    DisplayPok->kanRelease();
	}
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//-------------------------------------------------------------------------
int TFormaARMKassir2::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{

if (number_procedure_end==ER_VosvratViborIsGur)
		{
		if (type_event==1)
				{
				EndViborCheckForVosvratIsGurnala();
				}
		FormaGurDocCheckKKM2=0;
		}

if (number_procedure_end==ER_ViborIsGur)
		{
		if (type_event==1)
				{
				EndViborDocCheck();
				}
		FormaGurDocCheckKKM2=0;
		}

if (number_procedure_end==ER_ViborNomIsSprBV)
		{
		if (type_event==1)
				{
				EndViborNomIsSprBV();
				}
		SprBV=0;
		}

if (number_procedure_end==ER_ViborNomIsSprNom)
		{
		if (type_event==1)
				{
				EndViborNomIsSprNom();
				}
		FormaViborSprNom=0;
		}

if (number_procedure_end==ER_ViborEd)
		{
		if (type_event==1)
				{
				EndViborEdinica();
				}
		SpisokEd=0;
		}

if (number_procedure_end==ER_InputCodeBV)
		{
		if (type_event==1)
				{
				EndInputCodeBV();
				}
		FormaInputCode=0;
		}

if (number_procedure_end==ER_InputCodeNom)
		{
		if (type_event==1)
				{
				EndInputCodeNom();
				}
		FormaInputCode=0;
		}

if (number_procedure_end==ER_SvobSum)
		{
		if (type_event==1)
				{
				EndAddSvobSum();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_SumSnatie)
		{
		if (type_event==1)
				{
				EndInputSumSnatie();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_OborudSnatie)
		{
		if (type_event==1)
				{
				EndViborOborudSnatie();
				}
		FormaViborOborud=0;
		}

if (number_procedure_end==ER_SumVnesenie)
		{
		if (type_event==1)
				{
				EndInputSumVnesenie();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_OborudVnesenie)
		{
		if (type_event==1)
				{
				EndViborOborudVnesenie();
				}
		FormaViborOborud=0;
		}

if (number_procedure_end==ER_InputBarCode)
		{
		if (type_event==1)
				{
				EndInputBarCode();
				}
		FormaInputText=0;
		}

if (number_procedure_end==ER_ViborOborudXReport)
		{
		if (type_event==1)
				{
				EndViborOborudXReport();
				}
		FormaViborOborud=0;
		}

if (number_procedure_end==ER_ViborOborudZReport)
		{
		if (type_event==1)
				{
				EndViborOborudZReport();
				}
		FormaViborOborud=0;
		}

if (number_procedure_end==ER_ViborDiscountCard)
		{
		if (type_event==1)
				{
				EndViborDiscountCard();
				}
		FormaInputDiscountCard=0;
		}

if (number_procedure_end==ER_ViborOborudForReportTecProdagi)
		{
		if (type_event==1)
				{
				EndViborOborudForReportTecProdagi();
				}
		FormaViborOborud=0;
		}

return -1;
}
//---------------------------------------------------------------------------
//�������� ������ ���������
//--------------------------------------------------------------------------
void TFormaARMKassir2::CreateNewDocCheckSale(void)
{

//������� �����


CheckCreate=false;
CheckPrint=false;
CheckSave=false;
CheckProveden=false;
UpdateForm();
DMSprDiscountCard->OpenElement(0);

//		if(glFR->ProvVosmPrintCheck()==false)
//				{
//				ShowMessage("��� ����������� ������� ���! "+glFR->TextError);
//				return;
//
//				}


TcxCustomDataController *dc = cxGrid1TableView1->DataController;

while (dc->RowCount>0)
	{
	dc->DeleteRecord(0);
	}
//UpdateSetup();
//UpdateParameterFR();

//����������
cxGrid1TableView1->BeginUpdate();
dc->ClearSorting(true);
//cxGrid1TableView1IDFIRM->SortOrder = soNone;
cxGrid1TableView1->EndUpdate();

NameKlientLabel->Caption="";
NameDiscountCardLabel->Caption="";
NameNomLabel->Caption="";
KolLabel->Caption="";
KFLabel->Caption="";
PriceLabel->Caption="";
SdachaLabel->Caption="";
NameFirmLabel->Caption="";

	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;

ShowPrim("������ ����� ��� �������!", false);

CheckCreate=true;
OperationCheck=0;
ExternalCreateCheck=false;
IdDoc=0;
IdDocOsn=0;

if (DisplayPok>0) DisplayPok->ShowString1("����� ��� ",1,0,0);
if (DisplayPok>0) DisplayPok->ShowString2("�������",1,0,0);
}

//----------------------------------------------------------------------------
//����� ��������� �� �������
void TFormaARMKassir2::OpenGurnalCheckVibor(void)
{


if (FormaGurDocCheckKKM2==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM2.1",IID_IFormaGurDocCheckKKM2,
													(void**)&FormaGurDocCheckKKM2);
	FormaGurDocCheckKKM2->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
	//FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
	FormaGurDocCheckKKM2->Vibor=true;
	FormaGurDocCheckKKM2->NumberProcVibor=ER_ViborIsGur;
	FormaGurDocCheckKKM2->UpdateForm();

	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborDocCheck(void)
{

//������� �����
NameKlientLabel->Caption="";
NameDiscountCardLabel->Caption="";
NameNomLabel->Caption="";
KolLabel->Caption="";
KFLabel->Caption="";
PriceLabel->Caption="";
SdachaLabel->Caption="";

	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;


				IdDoc=glStrToInt64(FormaGurDocCheckKKM2->DM->TableIDDOC->AsString);
				IdDocOsn=0;
				ExternalCreateCheck=true;

				CheckCreate=true;
				CheckPrint=false;
				CheckSave=true;

				ShowPrim("������ ��� �������!", false);
				cxGrid1->Focused();
				cxGrid1TableView1KOL->Focused=true;

}        

//---------------------------------------------------------------------------
void TFormaARMKassir2::CreateNewDocCheckReturnSale(void)
{

//������� �����
NameKlientLabel->Caption="";
NameDiscountCardLabel->Caption="";
NameNomLabel->Caption="";
KolLabel->Caption="";
KFLabel->Caption="";
PriceLabel->Caption="";
SdachaLabel->Caption="";
NameFirmLabel->Caption="";

	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;

CheckCreate=false;
CheckPrint=false;
CheckSave=false;
CheckProveden=false;

TcxCustomDataController *dc = cxGrid1TableView1->DataController;

while (dc->RowCount>0)
	{
	dc->DeleteRecord(0);
	}
//����������
cxGrid1TableView1->BeginUpdate();
dc->ClearSorting(true);
//cxGrid1TableView1IDFIRM->SortOrder = soNone;
cxGrid1TableView1->EndUpdate();

ShowPrim("������ ����� ��� �� �������!", false);
CheckCreate=true;
OperationCheck=1;//�������
ExternalCreateCheck=false;
IdDocOsn=0;
IdDoc=0;
DMSprDiscountCard->OpenElement(0);
if (DisplayPok>0) DisplayPok->ShowString1("����� ��� ",1,0,0);
if (DisplayPok>0) DisplayPok->ShowString2("�������",1,0,0);
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::CreateNewDocCheckReturnSaleNaOsnSaleGurnal(void)
{
if (FormaGurDocCheckKKM2==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurDocCheckKKM2.1",IID_IFormaGurDocCheckKKM2,
													(void**)&FormaGurDocCheckKKM2);
	FormaGurDocCheckKKM2->Init(InterfaceMainObject,InterfaceImpl);
	FormaGurDocCheckKKM2->IdKKM=glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString);
	//FormaGurDocCheckKKM2->NameKKMLabel->Caption=DMSprARM->ElementNAMEKKM->AsString;
	FormaGurDocCheckKKM2->Vibor=true;
	FormaGurDocCheckKKM2->NumberProcVibor=ER_VosvratViborIsGur;
	FormaGurDocCheckKKM2->UpdateForm();
	}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborCheckForVosvratIsGurnala(void)
{

//������� �����
NameKlientLabel->Caption="";
NameDiscountCardLabel->Caption="";
NameNomLabel->Caption="";
KolLabel->Caption="";
KFLabel->Caption="";
PriceLabel->Caption="";
SdachaLabel->Caption="";

	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;

TcxCustomDataController *dc = cxGrid1TableView1->DataController;

while (dc->RowCount>0)
	{
	dc->DeleteRecord(0);
	}
	
//����������
cxGrid1TableView1->BeginUpdate();
dc->ClearSorting(true);
cxGrid1TableView1->EndUpdate();


	IdDocOsn=glStrToInt64(FormaGurDocCheckKKM2->DM->TableIDDOC->AsString);
	CheckCreate=true;
	CheckPrint=false;
	CheckSave=false;
	IDMDocCheck * doc;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&doc);
	doc->Init(InterfaceMainObject,InterfaceImpl);
	doc->OpenDoc(IdDocOsn);
	doc->DocT->First();
	while (!doc->DocT->Eof)
		{
		TcxCustomDataController *dc = cxGrid1TableView1->DataController;
		dc->AppendRecord();
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = doc->DocTIDNOMCHKT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index]=doc->DocTNAMENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index]=doc->DocTKRNAMENOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index]=doc->DocTTNOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]=doc->DocTKOLCHKT->AsFloat;

		dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index]=doc->DocTIDEDCHKT->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index]=doc->DocTNAMEED->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]=doc->DocTKFCHKT->AsFloat;

		dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=doc->DocTPRICECHKT->AsFloat;

		DMSprNom->IdTypePrice=IdTypePrice;

		DMSprNom->OpenElement(glStrToInt64(doc->DocTIDNOMCHKT->AsString));
		dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
		dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;

		dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=doc->DocTPRSKCHKT->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=doc->DocTSUMCHKT->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=doc->DocTSKCHKT->AsFloat;
		dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

		doc->DocT->Next();
		}
	doc->kanRelease();

	   
OperationCheck=1;//�������
ExternalCreateCheck=false;
IdDoc=0;
ShowPrim("������ ����� ��� �� �������!", false);
cxGrid1->Focused();
cxGrid1TableView1KOL->Focused=true;
}
//---------------------------------------------------------------------------
//���������� ����������� � ��������� �����
//----------------------------------------------------------------------------
//����� �� ����������� �������� ������
void TFormaARMKassir2::OpenFormViborSprBVNom(void)
{
if(Prosmotr==true)
	{
	ShowMessage("�������� ������ ������ ��� ���������!");
	return;
	}
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (SprBV==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborBVNom.1",IID_IFormaViborBVNom,
													(void**)&SprBV);
		SprBV->Init(InterfaceMainObject,InterfaceImpl);
		SprBV->NumberProcVibor=ER_ViborNomIsSprBV;
        SprBV->Vibor=true;
        SprBV->Prosmotr=true;
		SprBV->IdPod=glStrToInt64(DMSprARM->ElementIDPODR_SARM->AsString);
		//SprBV->EditPodr->Text=DMSprARM->ElementNAMEPOD->AsString;
        SprBV->UpdateForm();


        }
}
//-------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborNomIsSprBV(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;


				DMSprNom->IdTypePrice=IdTypePrice;
				DMSprNom->OpenElement(SprBV->ViborIdNom);

				dc->AppendRecord();
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index]=DMSprNom->ElementNAMENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index]=DMSprNom->ElementKRNAMENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index]=DMSprNom->ElementTNOM->AsInteger;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]=1;

				dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index]=DMSprNom->ElementIDOSNEDNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index]=DMSprNom->OsnEdNAMEED->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]=DMSprNom->OsnEdKFED->AsFloat;

				//������� ����
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
					dm_price->GetValuePrice(IdTypePrice,                          //��� ���
							glStrToInt64(DMSprNom->ElementIDNOM->AsString),       //������������
							glStrToInt64(DMSprNom->ElementIDOSNEDNOM->AsString),         //�������
							DMSprNom->OsnEdKFED->AsFloat,                        //����������� �������
							glStrToInt64(DMSprNom->ElementIDBASEDNOM->AsString)); //������� �������
				dm_price->kanRelease();

				dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;
				RaschetTekSumStroki(dc->RowCount-1);
				ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
									*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
				//UpdateValuesDiscount();
				OutProtocol("��������� ����� ������������ �� ����������� �������� ������");
				//�������
				AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
				AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
				if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);


cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//����� �� ����������� ������������
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormViborSprNom(void)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (FormaViborSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprNom.1",IID_IFormaViborSprNom,
													(void**)&FormaViborSprNom);
		FormaViborSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborSprNom->NumberProcVibor=ER_ViborNomIsSprNom;
		FormaViborSprNom->Vibor=true;
		FormaViborSprNom->DM->IdTypePrice=glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString);
		//FormaViborSprNom->SpisokTypePrice->ItemIndex=FormaViborSprNom->DM->GetIndexTypePrice()-1;
		FormaViborSprNom->UpdateForm();
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborNomIsSprNom(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

				DMSprNom->IdTypePrice=IdTypePrice;
				DMSprNom->OpenElement(glStrToInt64(FormaViborSprNom->DM->TableIDNOM->AsString));

				dc->AppendRecord();
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] = 1;
				dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprNom->ElementIDOSNEDNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprNom->OsnEdNAMEED->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprNom->OsnEdKFED->AsFloat;

				//������� ����
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
					dm_price->GetValuePrice(IdTypePrice,                          //��� ���
							glStrToInt64(DMSprNom->ElementIDNOM->AsString),       //������������
							glStrToInt64(DMSprNom->ElementIDOSNEDNOM->AsString),         //�������
							DMSprNom->OsnEdKFED->AsFloat,                        //����������� �������
							glStrToInt64(DMSprNom->ElementIDBASEDNOM->AsString)); //������� �������
				dm_price->kanRelease();

				dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;
				RaschetTekSumStroki(dc->RowCount-1);

				ValidateOstatok(VarAsType(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index],varDouble)
															*VarAsType(dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index],varDouble));
				//UpdateValuesDiscount();
				//�������
				AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
				AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
				if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
				OutProtocol("��������� ����� ������������ �� ����������� ������������");


cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//---------------------------------------------------------------------------
// ����� ������� ���������
//-----------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormViborSprEd(void)
{
if(Prosmotr==true) return;
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (SpisokEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborSprEd.1",IID_IFormaViborSprEd,
													(void**)&SpisokEd);
		SpisokEd->Init(InterfaceMainObject,InterfaceImpl);
		SpisokEd->NumberProcVibor=ER_ViborEd;
		SpisokEd->Vibor=true;
		TcxCustomDataController *dc = cxGrid1TableView1->DataController;
		SpisokEd->IdNom=glStrToInt64(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1IDNOM->Index]);
		SpisokEd->UpdateForm();
		//SpisokEd->HintLabel->Caption="�������� ������� ��� ��������� ��� ���";
		//SpisokEd->LabelNom->Caption=dc->Values[dc->FocusedRowIndex][cxGrid1TableView1NAMENOM->Index];
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborEdinica(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

				dc->Values[dc->FocusedRowIndex][cxGrid1TableView1IDED->Index] = SpisokEd->DM->ElementIDED->AsString;
				dc->Values[dc->FocusedRowIndex][cxGrid1TableView1NAMEED->Index] = SpisokEd->DM->ElementNAMEED->AsString;
				dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KFED->Index] = SpisokEd->DM->ElementKFED->AsFloat;
                dc->Values[dc->FocusedRowIndex][cxGrid1TableView1FL_PRINT->Index]=0;

				DMSprNom->IdTypePrice=IdTypePrice;
				DMSprNom->OpenElement(SpisokEd->DM->ElementIDNOMED->AsInt64);

				//������� ����
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				dc->Values[dc->FocusedRowIndex][cxGrid1TableView1PRICE->Index]=
					dm_price->GetValuePrice(IdTypePrice,                          //��� ���
							glStrToInt64(SpisokEd->DM->ElementIDNOMED->AsString),       //������������
							glStrToInt64(SpisokEd->DM->ElementIDED->AsString),         //�������
							SpisokEd->DM->ElementKFED->AsFloat,                        //����������� �������
							0); //������� �������
				dm_price->kanRelease();


				RaschetTekSumStroki(dc->FocusedRowIndex);
				ValidateOstatok(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KOL->Index]
								*dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KFED->Index]);
				//UpdateValuesDiscount();

				//�������
				AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
				AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
				if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
				OutProtocol("�������� ������� ������");


cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//���� ���� �������� ������
//----------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormInputCodeNomBV(void)
{

if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (FormaInputCode==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputCode.1",IID_IFormaInputCode,
													(void**)&FormaInputCode);
		FormaInputCode->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputCode->NumberProcVibor=ER_InputCodeBV;
		//FormaInputCode->NameSprLabel->Caption="���������� �������� ������:";

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndInputCodeBV(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

				//������� ID ������������
				IDMSprBVNom * DMSprBV;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
													(void**)&DMSprBV);
				DMSprBV->Init(InterfaceMainObject,InterfaceImpl);
				DMSprBV->IdPod=glStrToInt64(DMSprARM->ElementIDPODR_SARM->AsString);
                if (DMSprBV->FindPoCoduBV(FormaInputCode->Code)>0)
                        {
						DMSprNom->IdTypePrice=IdTypePrice;
						DMSprNom->OpenElement(DMSprBV->IdNomBV);

						dc->AppendRecord();
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] = FormaInputCode->Kol;
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprNom->ElementIDOSNEDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprNom->OsnEdNAMEED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprNom->OsnEdKFED->AsFloat;

						//������� ����
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
										dm_price->GetValuePrice(IdTypePrice,                          //��� ���
										glStrToInt64(DMSprNom->ElementIDNOM->AsString),       //������������
										glStrToInt64(DMSprNom->ElementIDOSNEDNOM->AsString),         //�������
										DMSprNom->OsnEdKFED->AsFloat,                        //����������� �������
										glStrToInt64(DMSprNom->ElementIDBASEDNOM->AsString)); //������� �������
						dm_price->kanRelease();

						dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

						RaschetTekSumStroki(dc->RowCount-1);
						ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
								*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
						//UpdateValuesDiscount();

						//�������
						AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
						AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
						if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
						OutProtocol("��������� ����� ������������ �� ���� ��");
                        }
                else
                        {
                        ShowMessage("����� �� ������!");
						}
				DMSprBV->kanRelease();


cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//---------------------------------------------------------------------------
//���� ���� ������������
void TFormaARMKassir2::OpenFormInputCodeNom(void)
{
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (FormaInputCode==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputCode.1",IID_IFormaInputCode,
													(void**)&FormaInputCode);
		FormaInputCode->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputCode->NumberProcVibor=ER_InputCodeNom;
		//FormaInputCode->NameSprLabel->Caption="���������� ������������:";
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndInputCodeNom(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

				DMSprNom->IdTypePrice=IdTypePrice;
				if (DMSprNom->FindPoCodu(FormaInputCode->Code)>0)
						{

						dc->AppendRecord();
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] = FormaInputCode->Kol;
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprNom->ElementIDOSNEDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprNom->OsnEdNAMEED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprNom->OsnEdKFED->AsFloat;

						//dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index] = DMSprNom->ElementZNACH_PRICE->AsFloat
						//						*DMSprNom->OsnEdKFED->AsFloat;
						//������� ����
						IDMSprPrice * dm_price;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceImpl);
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
												dm_price->GetValuePrice(IdTypePrice,                     //��� ���
														glStrToInt64(DMSprNom->ElementIDNOM->AsString),  //������������
														glStrToInt64(DMSprNom->ElementIDOSNEDNOM->AsString),    // �������
														DMSprNom->OsnEdKFED->AsFloat,                   // ����������� �������
														0); //������� �������
						dm_price->kanRelease();
						
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

						RaschetTekSumStroki(dc->RowCount-1);
						ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
										*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
						//UpdateValuesDiscount();

						//�������
						AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
						AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
						if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
						OutProtocol("��������� ����� ������������ �� ���� ������������");
						}
				else
						{
						 ShowMessage("����� �� ������!");
						}


cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//----------------------------------------------------------------------------
//��������� �����
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormAddSvobSumm(void)
{
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=ER_SvobSum;
		//FormaInputText->NameLabel->Caption="������� �����:";
		//FormaInputText->Caption="�����";
		}
}
//----------------------------------------------------------
void __fastcall TFormaARMKassir2::EndAddSvobSum(void)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;

				DMSprNom->IdTypePrice=IdTypePrice;
				if (DMSprNom->FindPoCodu(1)>0)
						{

						dc->AppendRecord();
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index] = 1;
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprNom->ElementIDOSNEDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprNom->OsnEdNAMEED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprNom->OsnEdKFED->AsFloat;
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index] = StrToFloat(FormaInputText->InputText);
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]= DMSprNom->ElementIDFIRMNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]= DMSprNom->ElementNAMEFIRM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
						dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

						RaschetTekSumStroki(dc->RowCount-1);
						ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
											*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
						//UpdateValuesDiscount();

						//�������
						AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
						AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
						if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
						OutProtocol("��������� ��������� �����");
						}
				else
						{
						 ShowMessage("�� ������ ����� � ����� ��������� ����� (���=1)!");
						 OutProtocol("�� ������ ����� � ����� ��������� ����� (���=1)!");
						}



cxGrid1->SetFocus();
cxGrid1TableView1KOL->Focused=true;
cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::ToolButtonInsertClick(TObject *Sender)
{
if (CheckCreate==false)
	{
	ShowMessage("���������� ������� ����� ���!");
	return;
	}
}
//---------------------------------------------------------------------------
//������ ���� ����� ����
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormInputBarCode(void)
{
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->NumberProcVibor=ER_InputBarCode;
		//FormaInputText->NameLabel->Caption="������� �����-���:";
		//FormaInputText->Caption="�����-���";
		} 

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndInputBarCode(void)
{

    IObjectBarCode * ob_bar;
	AnsiString s=Trim(FormaInputText->InputText).SetLength(13);

	InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
	ob_bar->Init(InterfaceMainObject,InterfaceImpl);
	ob_bar->SprNom=DMSprNom;
	ob_bar->SprEd=DMSprEd;
	ob_bar->IdTypePrice=IdTypePrice;
	ob_bar->ObrabotatShtrihCod(s.c_str());

	if (ob_bar->OutReady==true)
		{
		TcxCustomDataController *dc = cxGrid1TableView1->DataController;
						dc->AppendRecord();
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;

						dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprEd->ElementIDED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprEd->ElementNAMEED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprEd->ElementKFED->AsFloat;

				//������� ����
						IDMSprPrice * dm_price;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
						dm_price->Init(InterfaceMainObject,InterfaceImpl);
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DMSprNom->ElementIDNOM->AsString),
							glStrToInt64(DMSprEd->ElementIDED->AsString),
							DMSprEd->ElementKFED->AsFloat,
							glStrToInt64(DMSprNom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]=ob_bar->Kol;


				dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

				RaschetTekSumStroki(dc->RowCount-1);
				ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
								*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
				//UpdateValuesDiscount();


				cxGrid1TableView1KOL->Selected=true;
				//�������
				AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
				AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
				if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);

		cxGrid1->SetFocus();
		cxGrid1TableView1KOL->Focused=true;
		cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
		}
	else
		{
		ShowMessage(ObBar->TextError);
		}
	ob_bar->kanRelease();



}
//----------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::FormResize(TObject *Sender)
{
int x=0;

NameKKMLabel->Left=ClientWidth-NameKKMLabel->Width-4;
TypePriceLabel->Left=ClientWidth-TypePriceLabel->Width-4;
PanelPrice->Left=ClientWidth-PanelPrice->Width-4;
x=PanelPrice->Left;
PanelKF->Left=x-PanelKF->Width;
x=PanelKF->Left;
PanelKol->Left=x-PanelKol->Width;
x=PanelKol->Left;
PanelName->Left=4;
PanelName->Width=x-4;
NameNomLabel->Width=x-10;

x=0;
ButtonClose->Left=ClientWidth-ButtonClose->Width-4;
x=ButtonClose->Left;
ButtonPrint->Left=x-ButtonPrint->Width-2;

x=0;
GroupBoxSdacha->Left=ClientWidth-GroupBoxSdacha->Width-4;
x=GroupBoxSdacha->Left;
GroupBoxSum->Left=x-GroupBoxSum->Width-2;
x=GroupBoxSum->Left;
GroupBoxPC->Left=x-GroupBoxPC->Width-2;
x=GroupBoxPC->Left;
GroupBoxNal->Left=x-GroupBoxNal->Width-2;
//x=GroupBoxNal->Left;

}

//---------------------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::DeleteStringClick(TObject *Sender)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
dc->DeleteFocused();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::N4Click(TObject *Sender)
{
OpenFormViborSprEd();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::N9Click(TObject *Sender)
{
NalcxCalcEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::N10Click(TObject *Sender)
{
OplCardcxCalcEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::MenuPrintCheckClick(TObject *Sender)
{
PrintDocCheck();
}
//-----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::N8Click(TObject *Sender)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}
if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}

OpenFormViborSprBVNom();

}
//--------------------------------------------------------------------------
//�������� �� ���������� ������������
//---------------------------------------------------------------------------
// X - �����
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::PrintXreportClick(TObject *Sender)
{
OpenFormViborOborudXReport();
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormViborOborudXReport(void)
{
if (FormaViborOborud==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
	FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
	FormaViborOborud->IdArm=glStrToInt64(DMSprARM->ElementID_SARM->AsString);
	FormaViborOborud->TypeOborud="fr";
	FormaViborOborud->Vibor=true;
	FormaViborOborud->NumberProcVibor=ER_ViborOborudXReport;
	FormaViborOborud->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborOborudXReport(void)
{

	DMSprOborud->Table->First();
	__int64 id_oborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
	while (!DMSprOborud->Table->Eof)
		{
		if(id_oborud==glStrToInt64(DMSprOborud->TableID_OBORUD->AsString))
			{
			PrintXReport();
			break;
			}
		DMSprOborud->Table->Next();
		}

}
//----------------------------------------------------------------------------
void TFormaARMKassir2::PrintXReport(void)
{
IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{
		fr->OpenNoFiscalCheck();
		if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false);
			}
		fr->CloseNoFiscalCheck();
		fr->PrintXReport();
		}
	catch(Exception &exception)
		{
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
}
//----------------------------------------------------------------------------
// Z - �����
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormViborOborudZReport(void)
{
if (FormaViborOborud==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
	FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
	FormaViborOborud->IdArm=glStrToInt64(DMSprARM->ElementID_SARM->AsString);
	FormaViborOborud->TypeOborud="fr";
	FormaViborOborud->Vibor=true;
	FormaViborOborud->NumberProcVibor=ER_ViborOborudZReport;
	FormaViborOborud->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborOborudZReport(void)
{

   //	FormaViborOborud->Visible=false;
	DMSprOborud->Table->First();
	__int64 id_oborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
	while (!DMSprOborud->Table->Eof)
		{
		if(id_oborud==glStrToInt64(DMSprOborud->TableID_OBORUD->AsString))
			{
			PrintZReport();
			break;
			}
		DMSprOborud->Table->Next();
		}


}
//----------------------------------------------------------------------------
void TFormaARMKassir2::PrintZReport(void)
{
IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{
		fr->OpenNoFiscalCheck();
		if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false);
			}
		fr->CloseNoFiscalCheck();
		fr->PrintZReport();
		}
	catch(Exception &exception)
		{
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}


}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::PrintZreportClick(TObject *Sender)
{
OpenFormViborOborudZReport();
}
//--------------------------------------------------------------------------
//��������
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormVnesenie(void)
{
if (FormaInputText==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputText->Vibor=true;
		FormaInputText->NumberProcVibor=ER_SumVnesenie;
		//FormaInputText->NameLabel->Caption="������� �����:";
		//FormaInputText->Caption="��������";
		} 
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndInputSumVnesenie(void)
{

	if (FormaViborOborud==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
		FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborOborud->IdArm=glStrToInt64(DMSprARM->ElementID_SARM->AsString);
		FormaViborOborud->TypeOborud="fr";
		FormaViborOborud->Vibor=true;
		FormaViborOborud->NumberProcVibor=ER_OborudVnesenie;
		FormaViborOborud->UpdateForm();
		} 

}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborOborudVnesenie(void)
{

	DMSprOborud->Table->First();
	__int64 id_oborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
	while (!DMSprOborud->Table->Eof)
		{
		if(id_oborud==glStrToInt64(DMSprOborud->TableID_OBORUD->AsString))
			{
			VnestiSummu(StrToFloat(FormaInputText->InputText));
			break;
			}
		DMSprOborud->Table->Next();
		}

}
//------------------------------------------------------------------------------
void TFormaARMKassir2::VnestiSummu(float sum)
{

IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{
		fr->OpenNoFiscalCheck();
		if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false);
			}
		fr->CloseNoFiscalCheck();
		fr->Vnesenie(sum);
		}
	catch(Exception &exception)
		{
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
}
//---------------------------------------------------------------------------
//������
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormSnatie(void)
{
if (FormaInputText==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputText.1",IID_IFormaInputText,
													(void**)&FormaInputText);
		FormaInputText->Init(InterfaceMainObject,InterfaceImpl);
        FormaInputText->Vibor=true;
		FormaInputText->NumberProcVibor=ER_SumSnatie;
		//FormaInputText->NameLabel->Caption="������� �����:";
		//FormaInputText->Caption="������";
        }
}
//--------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndInputSumSnatie(void)
{


	if (FormaViborOborud==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
		FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
		FormaViborOborud->IdArm=glStrToInt64(DMSprARM->ElementID_SARM->AsString);
		FormaViborOborud->TypeOborud="fr";
		FormaViborOborud->Vibor=true;
		FormaViborOborud->NumberProcVibor=ER_OborudSnatie;
		FormaViborOborud->UpdateForm();
		} 


}
//--------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborOborudSnatie(void)
{

   //	FormaViborOborud->Visible=false;
	DMSprOborud->Table->First();
	__int64 id_oborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
	while (!DMSprOborud->Table->Eof)
		{
		if(id_oborud==glStrToInt64(DMSprOborud->TableID_OBORUD->AsString))
			{
			SnatSummu(StrToFloat(FormaInputText->InputText));
			break;
			}
		DMSprOborud->Table->Next();
		}


}
//---------------------------------------------------------------------------
void TFormaARMKassir2::SnatSummu(float sum)
{
IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{
		fr->OpenNoFiscalCheck();
		if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false);
			}
		fr->CloseNoFiscalCheck();
		fr->Snatie(sum);
		}
	catch(Exception &exception)
		{
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
}
//---------------------------------------------------------------------------
IFiskReg* TFormaARMKassir2::GetFR(void)
{
IFiskReg * fr;
InterfaceGlobalCom->kanCreateObject("Oberon.FiskReg.1",IID_IFiskReg,
												 (void**)&fr);
fr->Init(InterfaceMainObject,0);
//���������� �����������

OutProtocol("������� ���������� ���������� �����������");
fr->Modul=DMSprOborud->TableMODUL_SOBORUD->AsString;
fr->Number=1;
fr->InitDevice();
int number_port=StrToInt(DMSprOborud->TableCOMNAME_OBORUD->AsString);
AnsiString baud_rate=DMSprOborud->TableBAUDRATE_OBORUD->AsString;

AnsiString password=DMSprOborud->GetParameter("password");
if(fr->Connect(number_port, baud_rate, password)==true)
	{
	//glFRConnect=true;
	}
else
	{
   //	glFRConnect=false;
	ShowMessage("������ ��� ����������� ����������� ������������: "+fr->TextError);
	OutProtocol("������ ��� ����������� ����������� ������������: "+fr->TextError);
	}
return fr;
}
//----------------------------------------------------------------------------


void __fastcall TFormaARMKassir2::N11Click(TObject *Sender)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

OpenFormViborSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::MenuInputCodeBVClick(TObject *Sender)
{
OpenFormInputCodeNomBV();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::MenuInputCodeNomClick(TObject *Sender)
{
OpenFormInputCodeNom();
}

//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::AddSvobSumClick(TObject *Sender)
{
OpenFormAddSvobSumm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::VnesenieClick(TObject *Sender)
{
OpenFormVnesenie();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::SnatieClick(TObject *Sender)
{
OpenFormSnatie();
}

//-----------------------------------------------------------------------

void __fastcall TFormaARMKassir2::SaveCheckMainMenuClick(TObject *Sender)
{
//if (DM->SaveDoc()==true)
//        {
//        CheckSave=true;
//        Prim->Caption="��� ��������!";
//        //DM->CloseDoc();
//        }
//else
//        {
//		Prim->Caption="�� ������� �������� ���!";
//		ShowMessage("������: "+DM->TextError);
//        }
}
//---------------------------------------------------------------------------



void __fastcall TFormaARMKassir2::CloseDocClick(TObject *Sender)
{
//DM->CloseDoc();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::FormActivate(TObject *Sender)
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

void __fastcall TFormaARMKassir2::FormDeactivate(TObject *Sender)
{
//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������

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
void __fastcall TFormaARMKassir2::ReadShtrihCodEvent(int number, UnicodeString sh)
{
OutProtocol("��� ������� 2 �������:");
OutProtocol(sh);
//UnicodeString s=sh;

if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}

if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

ObBar->IdTypePrice=IdTypePrice;
ObBar->ObrabotatShtrihCod(sh);

if (ObBar->OutReady==true)
	{
	TcxCustomDataController *dc = cxGrid1TableView1->DataController;
						dc->AppendRecord();
						dc->Values[dc->RowCount-1][cxGrid1TableView1IDNOM->Index] = DMSprNom->ElementIDNOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMENOM->Index] = DMSprNom->ElementNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index] = DMSprNom->ElementKRNAMENOM->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1TNOM->Index] = DMSprNom->ElementTNOM->AsInteger;

						dc->Values[dc->RowCount-1][cxGrid1TableView1IDED->Index] = DMSprEd->ElementIDED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEED->Index] = DMSprEd->ElementNAMEED->AsString;
						dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index] = DMSprEd->ElementKFED->AsFloat;

				//������� ����
				IDMSprPrice * dm_price;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&dm_price);
				dm_price->Init(InterfaceMainObject,InterfaceImpl);
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]=
					dm_price->GetValuePrice(IdTypePrice,
							glStrToInt64(DMSprNom->ElementIDNOM->AsString),
							glStrToInt64(DMSprEd->ElementIDED->AsString),
							DMSprEd->ElementKFED->AsFloat,
							glStrToInt64(DMSprNom->ElementIDBASEDNOM->AsString));
				dm_price->kanRelease();

				dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]=ObBar->Kol;


				dc->Values[dc->RowCount-1][cxGrid1TableView1IDFIRM->Index]=DMSprNom->ElementIDFIRMNOM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1NAMEFIRM->Index]=DMSprNom->ElementNAMEFIRM->AsString;
				dc->Values[dc->RowCount-1][cxGrid1TableView1PRSK->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SUM->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1SKIDKA->Index]=0;
				dc->Values[dc->RowCount-1][cxGrid1TableView1FL_PRINT->Index]=0;

				RaschetTekSumStroki(dc->RowCount-1);
				ValidateOstatok(dc->Values[dc->RowCount-1][cxGrid1TableView1KOL->Index]
								*dc->Values[dc->RowCount-1][cxGrid1TableView1KFED->Index]);
				//UpdateValuesDiscount();


				cxGrid1TableView1KOL->Selected=true;
				//�������
				AnsiString string1=dc->Values[dc->RowCount-1][cxGrid1TableView1KRNAMENOM->Index];
				AnsiString string2="����:"+dc->Values[dc->RowCount-1][cxGrid1TableView1PRICE->Index]
											+"  �����:"+FloatToStr(SummaDoc);
				if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
				if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);

	cxGrid1->SetFocus();
	cxGrid1TableView1KOL->Focused=true;
	cxGrid1TableView1->Controller->FocusedRowIndex=dc->RowCount-1;
	}
else
	{
		ShowMessage(ObBar->TextError);
	}

}
//---------------------------------------------------------------
void __fastcall TFormaARMKassir2::N12Click(TObject *Sender)
{
PrintGoodsCheck();
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::PrintGoodsCheck(void)
{
//
//SE=new TSheetEditor(Application);
//SE->SS->RowsAutoHeight=false;
//if (!SE) return;
//
//x = 1;
//y = 0;
//SE->SS->BeginUpdate();
//DM->DataSourceDocT->Enabled=false;
//TBookmark BM;
//BM=DM->DocT->GetBookmark();
//PrintGoodsCheck_OutputHeadline();
//
//
//DM->DocT->First();
//while (!DM->DocT->Eof)
//        {
//        PrintGoodsCheck_OutputElement();
//        DM->DocT->Next();
//        }
//
//DM->DocT->GotoBookmark(BM);
//DM->DocT->FreeBookmark(BM);
//DM->DataSourceDocT->Enabled=true;
//
//
//PrintGoodsCheck_OutputPodval();
//
//SE->SS->EndUpdate();
//SE->Show();


}
//---------------------------------------------------------------------------
void TFormaARMKassir2::PrintGoodsCheck_OutputHeadline(void)
{
//		TcxSSHeader *cHeader;
//        cHeader = SE->SS->ActiveSheet->Cols;
//		cHeader->Size[0] = 10;
//		cHeader->Size[1] = 50;
//		cHeader->Size[2] = 250;
//		cHeader->Size[3] = 70;
//		cHeader->Size[4] = 70;
//		cHeader->Size[5] = 70;
//		cHeader->Size[6] = 70;
//		cHeader->Size[7] = 80;
//
//TDMSprFirm *DMSprFirm=new TDMSprFirm(Application);
//DMSprFirm->OpenElement(DMSprARM->ElementIDFIRM_SARM->AsInteger);
//TDMSprSklad * DMSprSklad=new TDMSprSklad(Application);
//DMSprSklad->OpenElement(DMSprARM->ElementIDSKLAD_SARM->AsInteger);
//x=1;
//y=0;
//TcxSSCellObject *cell;
//		TRect rect;
//        rect.Left = x;
//		rect.Top = y;
//		rect.Right = x+6;
//		rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);
//
//cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = DMSprFirm->ElementFNAMEFIRM->AsString
//                +", ���: "+DMSprFirm->ElementINNFIRM->AsString;
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Name = "Times New Roman";
//cell->Style->Font->Size = 10;
//SE->SS->ActiveSheet->Rows->Size[y]=20;
//delete cell;
//y++;
//
//        rect.Left = x;
//		rect.Top = y;
//		rect.Right = x+6;
//		rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);
//
//cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "�����: "+DMSprSklad->ElementADRSKLAD->AsString;
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Name = "Times New Roman";
//cell->Style->Font->Size = 10;
//SE->SS->ActiveSheet->Rows->Size[y]=20;
//delete cell;
//y++;
//        rect.Left = x;
//		rect.Top = y;
//		rect.Right = x+5;
//		rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);
//
//cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//cell->Text = "�������: "+DMSprFirm->ElementTELFIRM->AsString;
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Name = "Times New Roman";
//cell->Style->Font->Size = 10;
//SE->SS->ActiveSheet->Rows->Size[y]=20;
//delete cell;
//y++;
//SE->SS->ActiveSheet->Rows->Size[y]=10;
//y++;
//
//        rect.Left = x+1;
//        rect.Top = y;
//		rect.Right = x+6;
//        rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);
//
//cell = SE->SS->ActiveSheet->GetCellObject(x+1, y);
//cell->Text = "�������� ��� �"+DM->DocAllNUMDOC->AsString
//                +" �� "+DateToStr(DM->DocAllPOSDOC->AsDateTime);
//cell->Style->HorzTextAlign = haLEFT;
//cell->Style->Font->Name = "Times New Roman";
//cell->Style->Font->Size = 16;
//delete cell;
//y++; y++;
//
//
//
//		x=1;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = "�";
//        cell->Style->HorzTextAlign = haCENTER;
//        cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = "������������";
//		cell->Style->HorzTextAlign = haCENTER;;
//        cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//		x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = "���-��";
//        cell->Style->HorzTextAlign = haCENTER;;
//        cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//		cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Text = "��.";
//        cell->Style->HorzTextAlign = haCENTER;
//        cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//		delete cell;
//        x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = "�";
//        cell->Style->HorzTextAlign = haCENTER;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//		cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = "����";
//        cell->Style->HorzTextAlign = haCENTER;
//        cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//		cell->Style->WordBreak = true;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Text = "�����";
//		cell->Style->HorzTextAlign = haCENTER;
//		cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Size = 10;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//		cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//		cell->Style->Borders->Edges [eRight]->Style=lsThin;
//		cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//		delete cell;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y-1);
//		cell->Text = "��� ��� �:"+DM->DocNCHECKCHK->AsString
//						+", ����������� ����� �"+DM->DocNKLCHK->AsString;
//		cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Size = 10;
//		delete cell;
//		x++;
//
//		y++;
//delete DMSprFirm;
//delete DMSprSklad;
}
//-----------------------------------------------------------------------------
void TFormaARMKassir2::PrintGoodsCheck_OutputElement(void)
{
//		x=1;
//		TcxSSCellObject *cell;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = DM->DocT->RecNo;
//		cell->Style->HorzTextAlign = haCENTER;
//        cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = DM->DocTNAMENOM->AsString;
//        cell->Style->HorzTextAlign = haLEFT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = FloatToStrF(DM->DocTKOLCHKT->AsFloat,ffFixed,10,3);
//        cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = DM->DocTNAMEED->AsString;
//        cell->Style->HorzTextAlign = haLEFT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = FloatToStrF(DM->DocTKFCHKT->AsFloat,ffFixed,10,3);
//        cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//		cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,10,2);
//        cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//		cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//        x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,10,2);
//        cell->Style->HorzTextAlign = haRIGHT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//        cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges [eLeft]->Style=lsThin;
//        cell->Style->Borders->Edges [eRight]->Style=lsThin;
//        cell->Style->Borders->Edges [eTop]->Style=lsThin;
//        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
//        delete cell;
//		x++;
//
//		y++;


}
//---------------------------------------------------------------------------
void TFormaARMKassir2::PrintGoodsCheck_OutputPodval(void)
{
//        x=1;
//		TcxSSCellObject *cell;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Style->Borders->Edges[eLeft]->Style =lsThin;
//        cell->Style->Borders->Edges[eRight]->Style =lsThin;                
//		cell->Style->Borders->Edges[eTop]->Style =lsThin;
//        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//		delete cell;
//		x++;
//
//
//
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Text = "�����: ";
//        cell->Style->HorzTextAlign = haCENTER;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Size = 10;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->WordBreak = true;
//		cell->Style->Borders->Edges[eLeft]->Style =lsThin;
//        cell->Style->Borders->Edges[eRight]->Style =lsNone;
//		cell->Style->Borders->Edges[eTop]->Style =lsThin;
//        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//		delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
//		cell->Style->Borders->Edges[eRight]->Style =lsNone;
//        cell->Style->Borders->Edges[eTop]->Style =lsThin;
//		cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//        delete cell;
//		x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Style->Borders->Edges[eLeft]->Style =lsNone;
//        cell->Style->Borders->Edges[eRight]->Style =lsNone;
//		cell->Style->Borders->Edges[eTop]->Style =lsThin;
//        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//		delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Style->Borders->Edges[eLeft]->Style =lsNone;
//		cell->Style->Borders->Edges[eRight]->Style =lsNone;
//        cell->Style->Borders->Edges[eTop]->Style =lsThin;
//		cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//        delete cell;
//		x++;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Style->Borders->Edges[eLeft]->Style =lsNone;
//        cell->Style->Borders->Edges[eRight]->Style =lsNone;                  
//		cell->Style->Borders->Edges[eTop]->Style =lsThin;
//        cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//		delete cell;
//        x++;
//		cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//        cell->Text = FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
//		cell->Style->HorzTextAlign = haRIGHT;
//        cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Style = TFontStyles() << fsBold;
//        cell->Style->Font->Size = 10;
//		cell->Style->WordBreak = true;
//        cell->Style->Borders->Edges[eLeft]->Style =lsThin;
//		cell->Style->Borders->Edges[eRight]->Style =lsThin;
//        cell->Style->Borders->Edges[eTop]->Style =lsThin;
//		cell->Style->Borders->Edges[eBottom]->Style =lsThin;
//        delete cell;
//		x++;
//        y++;y++;
//
//        x=2;
//
//		TRect rect;
//		rect.Left = x;
//		rect.Top = y;
//		rect.Right = x+5;
//		rect.Bottom = y;
//		SE->SS->ActiveSheet->SetMergedState(rect, true);
//        SE->SS->ActiveSheet->SetMergedState(rect, true);
//
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Text = "�����: "+CurrencyPropis(DM->DocAllSUMDOC->AsFloat);
//        cell->Style->HorzTextAlign = haLEFT;
//		cell->Style->VertTextAlign = vaCENTER;
//        cell->Style->Font->Style = TFontStyles() << fsBold;
//		cell->Style->Font->Size = 10;
//		cell->Style->WordBreak = true;
//		delete cell;
//		x++;
//        y++; y++;
//		x=2;
//        cell = SE->SS->ActiveSheet->GetCellObject(x, y);
//		cell->Text = "��������:________________________________ ";
//        cell->Style->HorzTextAlign = haLEFT;
//        cell->Style->VertTextAlign = vaCENTER;
//		cell->Style->Font->Size = 12;
//        x++;
//		y++;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir2::PrintGoodsCheckOnFR(void)
{
bool Res=false;
//if(glFRConnect==false)
//		{
//        Prim->Caption="���������� ����������� �� ���������!";
//		return Res;
//
//		}
//
//if (DM->DocOPERCHK->AsInteger!=3)
//        {
//		if (DM->DocT->RecordCount==0)
//                {
//				Prim->Caption="��� ����� � ��������� �����!";
//                return Res;
//				}
//        }
//
//if(glFR->ProvVosmPrintCheck()==false)
//		{
//		ShowMessage("��� ����������� ���������� ��������  ���! "+glFR->TextError);
//		return Res;
//        }
//
//glFR->OpenNoFiscalCheck();
//
//
//String StrPr="  ";
//
//if (DMSprARM->GetParameter("STR_ZAG_1")!="")
//        {
//		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_1"),1,1,0,true,false, false);
//        }
//
//if (DMSprARM->GetParameter("STR_ZAG_2")!="")
//		{
//		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_2"),1,1,0,true,false, false);
//		}
//
//if (DMSprARM->GetParameter("STR_ZAG_3")!="")
//        {
//		glFR->PrintString(DMSprARM->GetParameter("STR_ZAG_3"),1,1,0,true,false, false);
//        }
//
//glFR->PrintString(" ",1,0,0,true,false, false);
//
//
//
//
//glFR->PrintString("�������� ��� ",3,0,1,true,false, false);
//
//glFR->PrintString("N"+DM->DocAllNUMDOC->AsString
//				+" �� "+DateToStr(DM->DocAllPOSDOC->AsDateTime),2,0,1,true,false, false);
//
//glFR->PrintLine();//String("------------------------------------",1,0,0,true,false);
//glFR->PrintString(DM->DocPRIMCHK->AsString,1,0,0,true,false, false);
//
//DM->DocT->First();
//while(!DM->DocT->Eof)
//		{
//
//		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,false, false)==true){Res=true;}else{ Res=false;}
//		if (DM->DocTSKCHKT->AsFloat>0)
//			{  //�� �������
//			StrPr="";
//			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
//				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
//				+DM->DocTNAMEED->AsString+" = "
//				+FloatToStrF(DM->DocTPRICECHKT->AsFloat*DM->DocTKOLCHKT->AsFloat,ffFixed,15,2);
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
//
//			StrPr="-"+FloatToStr(DM->DocTPRSKCHKT->AsFloat)+" % "
//				+FloatToStrF(DM->DocTSKCHKT->AsFloat,ffFixed,15,2)+
//				" = "+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);
//
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
//			}
//		else
//			{//��� ������
//
//			StrPr="";
//			StrPr=FloatToStrF(DM->DocTPRICECHKT->AsFloat,ffFixed,15,2)
//				+" x "+FloatToStr(DM->DocTKOLCHKT->AsFloat)+" "
//				+DM->DocTNAMEED->AsString+" = "
//				+FloatToStrF(DM->DocTSUMCHKT->AsFloat,ffFixed,15,2);
//
//			if(glFR->PrintString(StrPr,1,0,2,true,false, false)==true) {Res=true;}else {Res=false;}
//			}
//        DM->DocT->Next();
//        }
//glFR->PrintLine();//("------------------------------------",1,0,0,true,false);
//StrPr="�����: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,15,2);
//glFR->PrintString(StrPr,1,0,2,true,false, false);
//
//glFR->PrintString(DM->DocAllFNAME_USER->AsString,1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//
//glFR->PrintString("�������  ___________________",1,0,0,true,false, false);
//
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->PrintString(" ",1,0,0,true,false, false);
//glFR->CloseNoFiscalCheck();
//
//glFR->Cut(1);
return Res;
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::mmPrintCoodsCheckOnFRClick(
	  TObject *Sender)
{
PrintGoodsCheckOnFR();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::PoBarCodeClick(TObject *Sender)
{
OpenFormInputBarCode();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}
 OpenFormViborSprBVNom() ;

}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}
OpenFormViborSprEd() ;
}
//---------------------------------------------------------------------------


//����� ���������� �����
void  TFormaARMKassir2::ViborDiscountCard(void)
{

if (CheckCreate==false)
		{
		ShowMessage("���������� ������� ����� ���!");
		return;
		}
if (CheckPrint==true)
	{
	ShowMessage("������ �������� ������������ ���!!");
	return;
	}
if (CheckSave==true)
	{
	ShowMessage("������ �������� ����������� ���!!");
	return;
	}

if (FormaInputDiscountCard==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaInputDiscountCard.1",IID_IFormaInputDiscountCard,
													(void**)&FormaInputDiscountCard);
		FormaInputDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
		FormaInputDiscountCard->Vibor=true;
		FormaInputDiscountCard->NumberProcVibor=ER_ViborDiscountCard;
		//FormaInputDiscountCard->NameLabel->Caption="������� ��� ��������� �����:";
		//FormaInputDiscountCard->Caption="��� ���������� �����";
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborDiscountCard(void)
{


				AnsiString s=FormaInputDiscountCard->InputText;
				if (s.Length()>13) {s.SetLength(13);}
				__int64 id_card=0;
				if (s.Length()>6)
					{ //���� ����� �� ����� ����
					id_card=DMSprDiscountCard->PoiskPoShCodu(s);
					}
				else
					{ //���� ����� �� ����
					id_card=DMSprDiscountCard->PoiskPoCodu(s);
					}

				if (id_card>0)
					{
					DMSprDiscountCard->OpenElement(id_card);
					if (DMSprDiscountCard->ElementACT_SDISCOUNT_CARD->AsInteger==1)
						{   //����� �������
						NameKlientLabel->Caption=DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						NameDiscountCardLabel->Caption=DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;

						//�������
						AnsiString string1=DMSprDiscountCard->ElementNAMEKLIENT->AsString;
						AnsiString string2=DMSprDiscountCard->ElementNAME_SDISCOUNT_CARD->AsString;
						if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
						if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);

						UpdateValuesDiscount();
						}
					else
						{
                        DMSprDiscountCard->Element->Active=false;
						ShowMessage("����� �� �������!");
						}
					}
			else
					{

						ShowMessage("����� �� �������!");
					}

}

//---------------------------------------------------------------------------
void TFormaARMKassir2::UpdateValuesDiscount(void)
{
//if (DM->DocT->Active==false) return;
//DM->DataSourceDocT->Enabled=false;
OutProtocol("������ ��������� ������� ������");

TBookmark BM;
double summa_doc=0;

TcxCustomDataController *dc = cxGrid1TableView1->DataController;
dc->GotoFirst();
for (int i=0; i<dc->RowCount; i++)
	{
	summa_doc=summa_doc+dc->Values[i][cxGrid1TableView1SUM->Index];
	}

GetProcentPoDiscountCard();
GetProcentAuto(summa_doc);

//����������� �������� ������
for (int i=0; i<dc->RowCount; i++)
		{  //�� �����         //����
		if (dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]>dc->Values[i][cxGrid1TableView1PRSK_AUTO->Index])
			{
			dc->Values[i][cxGrid1TableView1PRSK->Index]=dc->Values[i][cxGrid1TableView1PRSK_CARD->Index];
			}
		else
			{
			dc->Values[i][cxGrid1TableView1PRSK->Index]=dc->Values[i][cxGrid1TableView1PRSK_AUTO->Index];
			}
        RaschetTekSumStroki(i);
		}

OutProtocol("����� ��������� ������� ������");
}
//----------------------------------------------------------------------------
void TFormaARMKassir2::GetProcentPoDiscountCard(void)
{
OutProtocol("������ ������� �������� �� ���������� �����");
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
//*****************************************************************************
//����� �� ������ ��� �� �������, ������ ������� ������� ������ �� �����
if (DMSprDiscountCard->Element->Active==false ||
			glStrToInt64(DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString)==0)
	{
	for (int i=0; i<dc->RowCount; i++)
		{
		dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=0;
		}
	}
//****************************************************************************
//�������������------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==1)
	{
	for (int i=0; i<dc->RowCount; i++)
		{
		dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=DMSprDiscountCard->ElementPRSK_SDISCOUNT_CARD->AsFloat;
		}
	}
//****************************************************************************
//�������������------------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==2)
	{
	double proc=0;
		IDMSprNakSkidok * dm_snak_skidok;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNakSkidok.1",IID_IDMSprNakSkidok,
													(void**)&dm_snak_skidok);
		dm_snak_skidok->Init(InterfaceMainObject,InterfaceImpl);

		IDMGurOperDiscountCard * gur_oper;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMGurOperDiscountCard.1",IID_IDMGurOperDiscountCard,
													(void**)&gur_oper);
		gur_oper->Init(InterfaceMainObject,InterfaceImpl);

		dm_snak_skidok->GetSpisokSkidok( glStrToInt64(DMSprDiscountCard->ElementIDVID_SDISCOUNT_CARD->AsString),
									 glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString));

		AnsiString text_descr="";
		
		while(!dm_snak_skidok->Query->Eof)
			{
			int kol_day=dm_snak_skidok->Query->FieldByName("PERIOD_SNAK_SKIDOK")->AsInteger;
			//������� ����� �������
			TDateTime pos_nach=Now()-kol_day;
			double sum_pokupok=gur_oper->GetSumPokupok(glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString),pos_nach)
														+SummaDoc;
			double tek_procent=0;
			if (sum_pokupok>=dm_snak_skidok->Query->FieldByName("SUM_SNAK_SKIDOK")->AsFloat)
				{
				tek_procent=dm_snak_skidok->Query->FieldByName("PROCENT_SNAK_SKIDOK")->AsFloat;
				}

			if (proc<tek_procent)
				{
				proc=tek_procent;
				text_descr="����������� ����� �� "+IntToStr(kol_day)+" ���� :"+FloatToStr(sum_pokupok);
				}

			dm_snak_skidok->Query->Next();
			}

		dm_snak_skidok->kanRelease();
		gur_oper->kanRelease();
		Prim->Caption=text_descr;

	for (int i=0; i<dc->RowCount; i++)
		{
		dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=proc;
		}
	}
//**************************************************************************
//�������� ��� ���---------------------------------------------------------
if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==3)
	{
	for (int i=0; i<dc->RowCount; i++)
		{
		dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=0;
		}
		//������� ��� ���

		IDMSprKlient * dm_spr_klient;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&dm_spr_klient);
		dm_spr_klient->Init(InterfaceMainObject,InterfaceImpl);
		dm_spr_klient->OpenElement(glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString));

		if (glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString)!=0)
			{
			IdTypePrice=glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString);
			IDMSprTypePrice * dm_spr_type_price;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
													(void**)&dm_spr_type_price);
			dm_spr_type_price->Init(InterfaceMainObject,InterfaceImpl);
			dm_spr_type_price->OpenElement(glStrToInt64(dm_spr_klient->ElementIDTPRICEKLIENT->AsString));
			NameTypePrice=dm_spr_type_price->ElementNAME_TPRICE->AsString;
			dm_spr_type_price->kanRelease();

			//�������� ���� �� ������
			if(dc->RowCount>0)
				{
				String V="� ��������� ����� ��������� ���� ������. ����������� ����?";
				String Z="����������� ����?";
				if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						IDMSprPrice * DMSprPrice;
						InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
						DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						for (int i=0; i<dc->RowCount; i++)
							{
							DMSprPrice->FindElement(IdTypePrice,
											 glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]));
								if(DMSprPrice->ElementZNACH_PRICE->AsFloat==0)
									{
									DMSprPrice->FindElement(glStrToInt64(DMSprARM->ElementIDTPRICEPOD->AsString),
											 glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]));
									}
							dc->Values[i][cxGrid1TableView1PRICE->Index]=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														dc->Values[i][cxGrid1TableView1KFED->Index];
							}
						 DMSprPrice->kanRelease();
						}
				}

			}

	dm_spr_klient->kanRelease();
	}

//**************************************************************************
//������ �� ����������� ������������  --------------------------------------

if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5
			  ||		DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
	{
	IDMSprNom * spr_nom;
	InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&spr_nom);
	spr_nom->Init(InterfaceMainObject,InterfaceImpl);

	for (int i=0; i<dc->RowCount; i++)
		{
		spr_nom->OpenElement(glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]));
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==4)
			{
			dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==5)
			{
			dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
			}
		if (DMSprDiscountCard->ElementTYPE_SDISCOUNT_CARD->AsInteger==6)
			{
			dc->Values[i][cxGrid1TableView1PRSK_CARD->Index]=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
			}
		}
	spr_nom->kanRelease();
	}

OutProtocol("����� ������� �������� �� ���������� �����");
}
//----------------------------------------------------------------------------
void TFormaARMKassir2::GetProcentAuto(double sum_doc)
{ //���������� ��� ������ ������������
OutProtocol("������ ������� �������� �������������� ������");
double tek_skidka=0;
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
for (int i=0; i<dc->RowCount; i++)
	{
	DMSprDiscountAuto->TableDiscountAuto->First();
	while (!DMSprDiscountAuto->TableDiscountAuto->Eof)
		{
		bool  ok=true;
		tek_skidka=0;
		if (DMSprDiscountAuto->TableDiscountAutoACT_SDISCOUNT_AUTO->AsInteger==1)
			{
			//������ ���������� ������
			if (DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsFloat>1000)
				{
				if (Now()<DMSprDiscountAuto->TableDiscountAutoNACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//������ ���������� �����
			if (DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsFloat>1000)
				{
				if (Now()>DMSprDiscountAuto->TableDiscountAutoCON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//�����
			if (DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (sum_doc<DMSprDiscountAuto->TableDiscountAutoSUM_SDISCOUNT_AUTO->AsFloat)
					{
					ok=false;
					}
				}

			//���� ������
			if (DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger>0)
				{
				if (DayOfTheWeek(Now())!=DMSprDiscountAuto->TableDiscountAutoDAY_SDISCOUNT_AUTO->AsInteger)
					{
					ShowMessage(DayOfTheWeek(Now()));
					ok=false;
					}
				}

			//����� �������� ������
			if (DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()<DMSprDiscountAuto->TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//����� �������� �����
			if (DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsFloat>0)
				{
				if (Time()>DMSprDiscountAuto->TableDiscountAutoTIME_CON_SDISCOUNT_AUTO->AsDateTime)
					{
					ok=false;
					}
				}

			//��� ������������
			if (glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString)>0)
				{
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&spr_nom);
				spr_nom->Init(InterfaceMainObject,InterfaceImpl);
				spr_nom->OpenElement(glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]));
				if (glStrToInt64(spr_nom->ElementIDVID_SNOM->AsString)!=
						glStrToInt64(DMSprDiscountAuto->TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO->AsString))
					{
					ok=false;
					}
				spr_nom->kanRelease();
				}
			}

		double proc_tec_skidki_auto=0;
		if (ok==true)
			{
			//���������� ���������� ������� ������ �� ������� �������
			//������ ���������� �� ��� �������

			if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==0)
				{
				proc_tec_skidki_auto=DMSprDiscountAuto->TableDiscountAutoPRSK_SDISCOUNT_AUTO->AsFloat;
				}

			//������ ������ �� ������� (�� ����������� ������������)
			if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger>0)
				{
				IDMSprNom *spr_nom;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&spr_nom);
				spr_nom->Init(InterfaceMainObject,InterfaceImpl);
				spr_nom->OpenElement(glStrToInt64(dc->Values[i][cxGrid1TableView1IDNOM->Index]));
				//������ 1
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==1)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA1_SNOM->AsFloat;
					}
				//������ 2
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==2)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA2_SNOM->AsFloat;
					}
				//������ 3
				if (DMSprDiscountAuto->TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO->AsInteger==3)
					{
					proc_tec_skidki_auto=spr_nom->ElementSKIDKA3_SNOM->AsFloat;
					}
				spr_nom->kanRelease();
				}
			}

		if (proc_tec_skidki_auto>tek_skidka)
			{
			tek_skidka=proc_tec_skidki_auto;
			}
		DMSprDiscountAuto->TableDiscountAuto->Next();
		} 

	dc->Values[i][cxGrid1TableView1PRSK_AUTO->Index]=tek_skidka;

	}
OutProtocol("����� ������� �������� �������������� ������");
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::ViborDiscCardMainmenuClick(TObject *Sender)
{
ViborDiscountCard();
}
//---------------------------------------------------------------------------
//
//               ������ ���� �� �������� ��� ��
//
//---------------------------------------------------------------------------
void TFormaARMKassir2::PrintDocCheck(void)
{
ShowPrim("", false);

//ShowPrim("������ ����: ", false);
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
TextError="";
//if (DM->DocSDACHA->AsFloat<0)
//	{
//	ShowMessage("������������ ������!");
//	return;
//	}
//
//if (DM->DocOPLPCCHK->AsFloat>DM->DocAllSUMDOC->AsFloat)
//	{
//	ShowMessage("������ ��������� ������ �� ����� ���� ������ ����� ����!!");
//	return;
//	}

if (dc->RowCount==0)
	{
	Prim->Caption="��� ����� � ��������� �����!";
	OutProtocol("��� ����� � ��������� �����!");
	return ;
	}


//��������� ����� �� ���������
__int64 id_default_firm=0;
id_default_firm=glStrToInt64(DMSprARM->GetParameter("DefaultIdFirm"));
if (id_default_firm==0)
	{
	ShowMessage("�� ������� ����� �� ��������� ��� ������ �������, � ������� �� ����� �������� �����!");
	return;
	}

cxGrid1TableView1->BeginUpdate();
for (int i=0; i<dc->RowCount; i++)
	{
	if (glStrToInt64(dc->Values[i][cxGrid1TableView1IDFIRM->Index])==0)
		{
		dc->Values[i][cxGrid1TableView1IDFIRM->Index]=IntToStr(id_default_firm);
		
		}
	}
cxGrid1TableView1->EndUpdate();


//����������
cxGrid1TableView1->BeginUpdate();
dc->ClearSorting(true);
cxGrid1TableView1IDFIRM->SortOrder = soAscending;
cxGrid1TableView1->EndUpdate();


__int64 id_tek_firm=-1;

TList * list=new TList();

TcxGridViewData * AViewData=cxGrid1TableView1->ViewData;
for(int i=0;i<AViewData->RowCount;i++)
	{
	if (AViewData->Records[i]->Values[cxGrid1TableView1FL_PRINT->Index]!=1)
		{
		if(id_tek_firm!=glStrToInt64(AViewData->Records[i]->Values[cxGrid1TableView1IDFIRM->Index]))
			{ //����� �����
			if (list->Count>0)
				{ //������ ���� �� ��
				PrintCheckNaTecFR(list);
				}
			ClearList(list);
			id_tek_firm=glStrToInt64(AViewData->Records[i]->Values[cxGrid1TableView1IDFIRM->Index]);
			int * lp_index_string=new int;
			* lp_index_string=i;
			list->Add(lp_index_string);
			}
		else
			{ //���������� ������ �� ������ �����
			int * lp_index_string=new int;
			* lp_index_string=i;
			list->Add(lp_index_string);
			}
		}
	}

if (list->Count>0)
	{ //������ ����
	PrintCheckNaTecFR(list) ;
	}

ClearList(list);
delete list;
}
//--------------------------------------------------------------------------
void TFormaARMKassir2::ClearList(TList * list)
{
for (int i=0;i<list->Count;i++)
	{
    delete (int *) list->Items[i];
	}
list->Clear();
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::PrintCheckNaTecFR(TList * list)
{
//������� ��������� ��
TcxGridViewData * AViewData=cxGrid1TableView1->ViewData;

//������ ������� � ������
int num=*(int *)list->Items[0];
__int64 id_firm=glStrToInt64(AViewData->Records[num]->Values[cxGrid1TableView1IDFIRM->Index]);
bool est_fr=false;

//���� ��

	DMSprOborud->Table->First();
	while(!DMSprOborud->Table->Eof)
		{

		if (glStrToInt64(DMSprOborud->GetParameterPoTable("IdFirm"))==id_firm)
			{
			est_fr=true;
			break;
			}
		DMSprOborud->Table->Next();
		}

	
if (est_fr==false)
	{
	//�� ����� �� ��� ������
	ShowMessage("�� ������ �� ��� ������ ���� ����� ID="+IntToStr(id_firm));
    return;
	}

if(DMSprOborud->GetParameterPoTable("PrintFiscalCheck")=="1")
	{
	// �������� ���� ���������� ���� ������������ ���
	if (PrintFiscalCheck(list,id_firm)==true)
		{
		SaveCheck(list,id_firm);
		}
	}
else
	{
	if (PrintNoFiscalCheck(list,id_firm)==true)
		{
		SaveCheck(list,id_firm);
		}
	}

}
//--------------------------------------------------------------------------
bool TFormaARMKassir2::PrintFiscalCheck(TList * list,__int64 id_firm)
{
//glSaveProtocol("������� ���������� ��� "+DM->DocAllNUMDOC->AsString);
bool Res=false;
TcxGridViewData * view_data=cxGrid1TableView1->ViewData;
NumberKL=0;
NumberCheck=0;
RegNumberKKM="";
SerialNumberKKM="";
ModelKKM="";
NumberDoc=0;
IDMDocCheck * check;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&check);
check->Init(InterfaceMainObject,InterfaceImpl);
NumberDoc=check->GetNumberNewDoc();
check->kanRelease();
PosDoc=Now();

double summa_check=0;
double oplata_nal=0;
double oplata_plat_card=0;

if (FormaViborOplat_ARM2!=0)
	{
	TcxCustomDataController *dc_opl = FormaViborOplat_ARM2->cxGrid1TableView1->DataController;
	for (int i=0; i<dc_opl->RowCount; i++)
		{
		if (id_firm==glStrToInt64(dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1IDFIRM->Index]))
			{
			oplata_nal=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index];
			oplata_plat_card=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index];
			}
		} 
	}

if (DMSprOborud->GetParameterPoTable("NoPrintFR")=="1")
	{
	Res=true;
	return Res;
	}


IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{


		String StrPr="  ";
		for (int i=0;i<list->Count;i++)
			{
			int num=*(int *)list->Items[i];
			TcxCustomGridRecord * record=view_data->Records[num];

			StrPr="###"+record->Values[cxGrid1TableView1KRNAMENOM->Index]+";";
			StrPr=StrPr+record->Values[cxGrid1TableView1PRICE->Index]+";"
				+record->Values[cxGrid1TableView1KOL->Index]+";"
				+record->Values[cxGrid1TableView1NAMEED->Index]+";"
				+record->Values[cxGrid1TableView1SUM->Index];
			DM_Connection->glSaveProtocol(StrPr);
			}

			if(fr->ProvVosmPrintCheck()==false)
				{
				throw Exception(fr->TextError);
				}

			if (fr->OpenNoFiscalCheck()==false )
				{
				throw Exception(fr->TextError);
				}

			ShowPrim("������ ����:"+ DMSprOborud->GetParameterPoTable("StrZag1"), true);
			if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (fr->PrintLine()==false)
				{
				throw Exception(fr->TextError);
				}

			for (int i=0;i<list->Count;i++)
				{
				int num=*(int *)list->Items[i];
				TcxCustomGridRecord * record=view_data->Records[num];
				if (fr->PrintString(record->Values[cxGrid1TableView1KRNAMENOM->Index],1,0,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}

				if (record->Values[cxGrid1TableView1SKIDKA->Index]>0)
					{  //�� �������
					StrPr="";
					StrPr=FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index],ffFixed,15,2)
						+" x "+FloatToStr((double)record->Values[cxGrid1TableView1KOL->Index])+" "
						+record->Values[cxGrid1TableView1NAMEED->Index]+" = "
						+FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index]
									*(double)record->Values[cxGrid1TableView1KOL->Index],ffFixed,15,2);
					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}

					StrPr="-"+FloatToStr((double)record->Values[cxGrid1TableView1PRSK->Index])+" % "
						+FloatToStrF((double)record->Values[cxGrid1TableView1SKIDKA->Index],ffFixed,15,2)+
						" = "+FloatToStrF((double)record->Values[cxGrid1TableView1SUM->Index],ffFixed,15,2);

					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}
					}
				else
					{//��� ������

					StrPr="";
					StrPr=FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index],ffFixed,15,2)
						+" x "+FloatToStr((double)record->Values[cxGrid1TableView1KOL->Index])+" "
						+record->Values[cxGrid1TableView1NAMEED->Index]+" = "
						+FloatToStrF((double)record->Values[cxGrid1TableView1SUM->Index],ffFixed,15,2);

					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}
					}
				summa_check=summa_check+(double)record->Values[cxGrid1TableView1SUM->Index];
				if (FormaViborOplat_ARM2==0)
					{
					oplata_nal=oplata_nal+(double)record->Values[cxGrid1TableView1SUM->Index];
					}
				}

			if (fr->PrintLine()==false)
				{
				throw Exception(fr->TextError);
				}
			if(fr->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}

			if(fr->CloseNoFiscalCheck()==false)
				{
				throw Exception(fr->TextError);
				}


				double SumCheck=summa_check;
				double OplataNal=oplata_nal;
				double OplataPlatCard=oplata_plat_card;

				if(fr->PrintFiscalCheck(SumCheck,
											1,
											OplataNal,
											OplataPlatCard,
											0,
											0,
											OperationCheck)==false)
					{
					throw Exception(fr->TextError);
					}

			Res=true;

		NumberKL=fr->NumberKL;
		NumberCheck=fr->NumberCheck;
		RegNumberKKM=fr->RegNumberKKM;
		SerialNumberKKM=fr->SerialNumberKKM;
		ModelKKM=fr->ModelKKM;
		}
	catch(Exception &exception)
		{
		Res=false;
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
return Res;
}
//--------------------------------------------------------------------------
bool TFormaARMKassir2::PrintNoFiscalCheck(TList * list,__int64 id_firm)
{
//glSaveProtocol("������� ���������� ��� "+DM->DocAllNUMDOC->AsString);
bool Res=false;
TcxGridViewData * view_data=cxGrid1TableView1->ViewData;
NumberKL=0;
NumberCheck=0;
RegNumberKKM="";
SerialNumberKKM="";
ModelKKM="";
NumberDoc=0;
IDMDocCheck * check;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&check);
check->Init(InterfaceMainObject,InterfaceImpl);
NumberDoc=check->GetNumberNewDoc();
check->kanRelease();
PosDoc=Now();

double summa_check=0;
double oplata_nal=0;
double oplata_plat_card=0;
double sdacha=0;

if (FormaViborOplat_ARM2!=0)
	{
	TcxCustomDataController *dc_opl = FormaViborOplat_ARM2->cxGrid1TableView1->DataController;
	for (int i=0; i<dc_opl->RowCount; i++)
		{
		if (id_firm==glStrToInt64(dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1IDFIRM->Index]))
			{
			oplata_nal=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index];
			oplata_plat_card=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index];
            sdacha=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1SDACHA->Index];
			}
		} 
	}

if (DMSprOborud->GetParameterPoTable("NoPrintFR")=="1")
	{
	Res=true;
	return Res;
	}

IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{


		String StrPr="  ";
		for (int i=0;i<list->Count;i++)
			{
			int num=*(int *)list->Items[i];
			TcxCustomGridRecord * record=view_data->Records[num];

			StrPr="###"+record->Values[cxGrid1TableView1KRNAMENOM->Index]+";";
			StrPr=StrPr+record->Values[cxGrid1TableView1PRICE->Index]+";"
				+record->Values[cxGrid1TableView1KOL->Index]+";"
				+record->Values[cxGrid1TableView1NAMEED->Index]+";"
				+record->Values[cxGrid1TableView1SUM->Index];
			DM_Connection->glSaveProtocol(StrPr);
			}

			if(fr->ProvVosmPrintCheck()==false)
				{
				throw Exception(fr->TextError);
				}

			if (fr->OpenNoFiscalCheck()==false )
				{
				throw Exception(fr->TextError);
				}

			ShowPrim("������ ����:"+ DMSprOborud->GetParameterPoTable("StrZag1"), true);

			if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
				{
				if (fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (fr->PrintString("�������� ��� �"+IntToStr(NumberDoc),1,0,1,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}

			if (fr->PrintString("�� "+DateTimeToStr(PosDoc),1,0,1,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}

			if (OperationCheck==0)
				{   //�������
				if (fr->PrintString("�������",1,0,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}    
				}
			else
				{ //�������
				if (fr->PrintString("�������",1,0,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}
				}

			if (fr->PrintLine()==false)
				{
				throw Exception(fr->TextError);
				}

			for (int i=0;i<list->Count;i++)
				{
				int num=*(int *)list->Items[i];
				TcxCustomGridRecord * record=view_data->Records[num];
				if (fr->PrintString(record->Values[cxGrid1TableView1KRNAMENOM->Index],1,0,0,true,false, false)==false)
					{
					throw Exception(fr->TextError);
					}

				if (record->Values[cxGrid1TableView1SKIDKA->Index]>0)
					{  //�� �������
					StrPr="";
					StrPr=FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index],ffFixed,15,2)
						+" x "+FloatToStr((double)record->Values[cxGrid1TableView1KOL->Index])+" "
						+record->Values[cxGrid1TableView1NAMEED->Index]+" = "
						+FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index]
									*(double)record->Values[cxGrid1TableView1KOL->Index],ffFixed,15,2);
					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}

					StrPr="-"+FloatToStr((double)record->Values[cxGrid1TableView1PRSK->Index])+" % "
						+FloatToStrF((double)record->Values[cxGrid1TableView1SKIDKA->Index],ffFixed,15,2)+
						" = "+FloatToStrF((double)record->Values[cxGrid1TableView1SUM->Index],ffFixed,15,2);

					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}
					}
				else
					{//��� ������

					StrPr="";
					StrPr=FloatToStrF((double)record->Values[cxGrid1TableView1PRICE->Index],ffFixed,15,2)
						+" x "+FloatToStr((double)record->Values[cxGrid1TableView1KOL->Index])+" "
						+record->Values[cxGrid1TableView1NAMEED->Index]+" = "
						+FloatToStrF((double)record->Values[cxGrid1TableView1SUM->Index],ffFixed,15,2);

					if(fr->PrintString(StrPr,1,0,2,true,false, false)==false)
						{
						throw Exception(fr->TextError);
						}
					}
				summa_check=summa_check+(double)record->Values[cxGrid1TableView1SUM->Index];

				if (FormaViborOplat_ARM2==0)
					{
					oplata_nal=oplata_nal+(double)record->Values[cxGrid1TableView1SUM->Index];
					}
				}

			if (fr->PrintLine()==false)
				{
				throw Exception(fr->TextError);
				}


		if(fr->PrintString("����: "+FloatToStrF(summa_check,ffFixed,15,2),4,1,2,true,false,false)==false)
				{
				throw Exception(fr->TextError);
				}


		if (FormaViborOplat_ARM2!=0)
			{ ///������
				if(fr->PrintString("���������: "+FloatToStrF(oplata_nal,ffFixed,15,2),1,1,2,true,false,false)==false)
					{
					throw Exception(fr->TextError);
					}
				if(fr->PrintString("������: "+FloatToStrF(oplata_plat_card,ffFixed,15,2),1,1,2,true,false,false)==false)
					{
					throw Exception(fr->TextError);
					}
				if(fr->PrintString("�����: "+FloatToStrF(sdacha,ffFixed,15,2),1,1,2,true,false,false)==false)
					{
					throw Exception(fr->TextError);
					}
			}


		if(fr->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false,false)==false)
				{
				throw Exception(fr->TextError);
				}

		for (int i=0;i<3;i++)
			{
			if(fr->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}
			 }

		if(fr->PrintString("������� _____________ ",1,0,1,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}

		for (int i=0;i<6;i++)
			{
			if(fr->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}
			 }

		if(fr->CloseNoFiscalCheck()==false)
				{
				throw Exception(fr->TextError);
				}

		fr->Cut(1);


			Res=true;

		NumberKL=fr->NumberKL;
		NumberCheck=fr->NumberCheck;
		RegNumberKKM=fr->RegNumberKKM;
		SerialNumberKKM=fr->SerialNumberKKM;
		ModelKKM=fr->ModelKKM;
		}
	catch(Exception &exception)
		{
		Res=false;
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
return Res;
}
//----------------------------------------------------------------------------
bool TFormaARMKassir2::SaveCheck(TList * list,__int64 id_firm)
{
bool result=false;
TcxGridViewData * view_data=cxGrid1TableView1->ViewData;

double summa_check=0;
double oplata_nal=0;
double oplata_plat_card=0;

if (FormaViborOplat_ARM2!=0)
	{
	TcxCustomDataController *dc_opl = FormaViborOplat_ARM2->cxGrid1TableView1->DataController;
	for (int i=0; i<dc_opl->RowCount; i++)
		{
		if (id_firm==glStrToInt64(dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1IDFIRM->Index]))
			{
			oplata_nal=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index];
			oplata_plat_card=dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index];
			}
		} 
	}

if (list->Count==0)
	{
	return result;
	}

IDMDocCheck * doc;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (ExternalCreateCheck==false) //���� ��� ������ �� �������
	{                           //�� �� ������� ����� ���
	doc->NewDoc();
	doc->DocAll->Edit();

	if(NumberDoc!=0)
		{
		doc->DocAllNUMDOC->AsInteger=NumberDoc;
		}

	doc->DocAllPOSDOC->AsString=PosDoc;


	if(id_firm!=0)
		{
		doc->DocAllIDFIRMDOC->AsString=id_firm;
		}
	if(glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString)!=0)
		{
		doc->DocAllIDSKLDOC->AsString=DMSprARM->ElementIDSKLAD_SARM->AsString;
		}
	if(glStrToInt64(DMSprARM->ElementIDBASE_SARM->AsString)!=0)
		{
		doc->DocAllIDBASE_GALLDOC->AsString=DMSprARM->ElementIDBASE_SARM->AsString;
		}

	if (glStrToInt64(DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString)!=0)
		{
		doc->DocAllIDKLDOC->AsString=DMSprDiscountCard->ElementIDKLIENT_SDISCOUNT_CARD->AsString;
		}

	if (IdDocOsn!=0)
		{
		doc->DocAllIDDOCOSNDOC->AsString=IdDocOsn;
		}

	doc->DocAll->Post();

	doc->Doc->Edit();
	if (glStrToInt64(DMSprARM->ElementIDKKM_SARM->AsString)!=0)
		{
		doc->DocIDKKMCHK->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
		}
	if ( IdTypePrice!=0)
		{
		doc->DocIDTPRICE->AsString=IdTypePrice;
		}

	if (glStrToInt64(DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString)!=0)
		{
		doc->DocIDDCARDCHK->AsString=DMSprDiscountCard->ElementID_SDISCOUNT_CARD->AsString;
		}
    doc->DocOPERCHK->AsInteger=OperationCheck;
	doc->Doc->Post();

//��������� �����
			for (int i=0;i<list->Count;i++)
				{
				int num=*(int *)list->Items[i];
				TcxCustomGridRecord * record=view_data->Records[num];
				doc->DocT->Append();
				doc->DocTIDNOMCHKT->AsString=record->Values[cxGrid1TableView1IDNOM->Index];
				doc->DocTKOLCHKT->AsFloat=record->Values[cxGrid1TableView1KOL->Index];
				doc->DocTKFCHKT->AsFloat=record->Values[cxGrid1TableView1KFED->Index];
				doc->DocTIDEDCHKT->AsFloat=record->Values[cxGrid1TableView1IDED->Index];
				doc->DocTPRSKCHKT->AsFloat=record->Values[cxGrid1TableView1PRSK->Index];
				doc->DocTPRICECHKT->AsFloat=record->Values[cxGrid1TableView1PRICE->Index];
				if (record->Values[cxGrid1TableView1PRSK_CARD->Index].IsNull()==false)
					{
					doc->DocTPRSK_CARD_DCHKT->AsFloat=record->Values[cxGrid1TableView1PRSK_CARD->Index];
					}
				if (record->Values[cxGrid1TableView1PRSK_AUTO->Index].IsNull()==false)
					{
					doc->DocTPRSK_AUTO_DCHKT->AsFloat=record->Values[cxGrid1TableView1PRSK_AUTO->Index];
					}

				doc->DocT->Post();
				summa_check=summa_check+(double)record->Values[cxGrid1TableView1SUM->Index];
				
				if (FormaViborOplat_ARM2==0)
					{
					oplata_nal=oplata_nal+(double)record->Values[cxGrid1TableView1SUM->Index];
					}
				//TcxCustomDataController *dc = cxGrid1TableView1->DataController;
				//dc->Values[num][cxGrid1TableView1FL_PRINT->Index]=1;
				record->Values[cxGrid1TableView1FL_PRINT->Index]=1;

				}

	doc->DocAll->Edit();
	doc->DocAllSUMDOC->AsFloat=summa_check;
	doc->DocAll->Post();
	}
else //��������� ���
	{
	doc->OpenDoc(IdDoc);
	}

	doc->Doc->Edit();
	doc->DocOPLNALCHK->AsFloat=summa_check-oplata_plat_card;
	doc->DocOPLPCCHK->AsFloat=oplata_plat_card;
	doc->DocNALCHK->AsFloat=oplata_nal;

	if (oplata_plat_card>0)
		{
		if (DMSprOborud->GetParameterPoTable("IdBankSchet")!="")
			{
			doc->DocIDBSCHET_DCHK->AsString=glStrToInt64(DMSprOborud->GetParameterPoTable("IdBankSchet"));
			}
		}

	//doc->DocNKLCHK->AsInteger=NumberKL;
	//doc->DocNCHECKCHK->AsInteger=NumberCheck;
	//doc->DocREGNUMCHK->AsString=RegNumberKKM;
	//doc->DocSAVNUMCHK->AsString=SerialNumberKKM;
	//doc->DocMODELCHK->AsString=ModelKKM;
	doc->Doc->Post();


	if (doc->SaveDoc()==true)
		{
		result=true;
		doc->DvRegDoc();
		ShowPrim("��� ��������!\n", true);
		}
	else
		{
		TextError=doc->TextError;
		ShowMessage("������ ��� ���������� ����: "+TextError);
		ShowPrim("��� �� ��������! \n", true);
		result=false;
		}

doc->kanRelease();
return result;
}
//-----------------------------------------------------------------------------


void __fastcall TFormaARMKassir2::cxGrid1DBTableView1KOLCHKTPropertiesValidate(
	  TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
ValidateOstatok(DisplayValue);
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::ValidateOstatok(double treb_kol)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
if (NoOtrOstatok==true && VarAsType(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1TNOM->Index],varInteger)==0)
	{   //�������� ������� � �� ����� �������� ������ ��� ���� �� ������
		//��������� ������ ������
	double tec_ostatok=0;
	IDMRegGoods * reg;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
	reg->Init(InterfaceMainObject,InterfaceImpl);
	tec_ostatok=reg->GetOstatok(glStrToInt64(DMSprARM->ElementIDFIRM_SARM->AsString),
								glStrToInt64(DMSprARM->ElementIDSKLAD_SARM->AsString),
								glStrToInt64(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1IDNOM->Index]));

	if (tec_ostatok<treb_kol)
		{
		ShowMessage("������������ ������ �� ������!\n\n ���������:   "+
							FloatToStrF(treb_kol,ffFixed,14,3)+
							"\n\n �� ������:   "+FloatToStrF(tec_ostatok,ffFixed,14,3));
		if (VarAsType(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KFED->Index],varDouble)!=0)
			{
			dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KOL->Index]=
									tec_ostatok/VarAsType(dc->Values[dc->FocusedRowIndex][cxGrid1TableView1KFED->Index],varDouble);
			RaschetTekSumStroki(dc->FocusedRowIndex);
			}
		}
	reg->kanRelease();
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::cxGrid1Exit(TObject *Sender)
{
UpdateValuesDiscount();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::NalcxCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN) OplCardcxCalcEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::OplCardcxCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN) ButtonPrint->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::NewCheckSaleClick(TObject *Sender)
{
CreateNewDocCheckSale();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::NewCheckReturnSaleClick(TObject *Sender)
{
CreateNewDocCheckReturnSale();
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::OpenCheckClick(TObject *Sender)
{
OpenGurnalCheckVibor();
}
//---------------------------------------------------------------------------



void __fastcall TFormaARMKassir2::cxGrid1TableView1NAMENOMGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
      AnsiString &AText)
{
NameNomLabel->Caption=AText;
if (ARecord->Values[cxGrid1TableView1NAMEFIRM->Index].IsNull()!=true)
	{
	NameFirmLabel->Caption="�����: "+ARecord->Values[cxGrid1TableView1NAMEFIRM->Index];
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1TableView1KOLGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
      AnsiString &AText)
{
KolLabel->Caption=AText;

}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1TableView1KFEDGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
      AnsiString &AText)
{
KFLabel->Caption=AText;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1TableView1PRICEGetDisplayText(
      TcxCustomGridTableItem *Sender, TcxCustomGridRecord *ARecord,
      AnsiString &AText)
{
PriceLabel->Caption=AText;
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1TableView1TcxGridDataControllerTcxDataSummaryFooterSummaryItems0GetText(
      TcxDataSummaryItem *Sender, const Variant &AValue, bool AIsFooter,
      AnsiString &AText)
{
SumDocLabel->Caption=AText;

if (AText=="")
	{
	SummaDoc=0;
	NalcxCalcEdit->Text=0;
	OplCardcxCalcEdit->Text=0;
	}
else
	{
	double s=StrToFloat(AText);
	double sum=SummaDoc-s;

	if (sum>0 && sum>0.001)
		{
		SummaDoc=StrToFloat(AText);
		NalcxCalcEdit->Text=AText;
		}

	if (sum<0 && sum<-0.001 )
		{
		SummaDoc=StrToFloat(AText);
		NalcxCalcEdit->Text=AText; 
		}

	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaARMKassir2::cxGrid1TableView1DataControllerAfterPost(
	  TcxCustomDataController *ADataController)
{
//������
double skidka=
		VarAsType(ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1KOL->Index],varDouble)*
		VarAsType(ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1PRICE->Index],varDouble)*
		VarAsType(ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1PRSK->Index],varDouble)/100;
//�����
	ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1SUM->Index]=
		VarAsType(ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1KOL->Index],varDouble)*
		VarAsType(ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1PRICE->Index],varDouble)-
		skidka;
ADataController->Values[ADataController->FocusedRowIndex][cxGrid1TableView1SKIDKA->Index]=skidka;
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::NalcxCalcEditPropertiesEditValueChanged(
      TObject *Sender)
{
double nal=StrToFloat(NalcxCalcEdit->Text);
double plat_card=StrToFloat(OplCardcxCalcEdit->Text);
Oplata=nal+plat_card;
Sdacha=Oplata-SummaDoc;
SdachaLabel->Caption=FloatToStrF(nal+plat_card-SummaDoc,ffFixed,15,2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::OplCardcxCalcEditPropertiesEditValueChanged(
      TObject *Sender)
{
double nal=StrToFloat(NalcxCalcEdit->Text);
double plat_card=StrToFloat(OplCardcxCalcEdit->Text);
SdachaLabel->Caption=FloatToStrF(nal+plat_card-SummaDoc,ffFixed,15,2);
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::RaschetTekSumStroki(int number_string)
{
TcxCustomDataController *dc = cxGrid1TableView1->DataController;
//������
double skidka=glRoundValue(
		VarAsType(dc->Values[number_string][cxGrid1TableView1KOL->Index],varDouble)*
		VarAsType(dc->Values[number_string][cxGrid1TableView1PRICE->Index],varDouble)*
		VarAsType(dc->Values[number_string][cxGrid1TableView1PRSK->Index],varDouble)/100,2);
//�����
	dc->Values[number_string][cxGrid1TableView1SUM->Index]=glRoundValue(
		VarAsType(dc->Values[number_string][cxGrid1TableView1KOL->Index],varDouble)*
		VarAsType(dc->Values[number_string][cxGrid1TableView1PRICE->Index],varDouble)-
		skidka, 2);
dc->Values[number_string][cxGrid1TableView1SKIDKA->Index]=skidka;

}
//----------------------------------------------------------------------------





void __fastcall TFormaARMKassir2::cxGrid1TableView1NAMEEDPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
OpenFormViborSprEd();
}

//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::NalcxCalcEditExit(TObject *Sender)
{
//�������
AnsiString string1="�����:"+FloatToStr(SummaDoc)+"  ���:"+FloatToStr(Oplata);
AnsiString string2="�����:"+FloatToStr(Sdacha);
if (DisplayPok>0) DisplayPok->ShowString1(string1.c_str(),1,0,0);
if (DisplayPok>0) DisplayPok->ShowString2(string2.c_str(),1,0,0);
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::OpenCheckForVosvratMainMenuClick(
      TObject *Sender)
{
CreateNewDocCheckReturnSaleNaOsnSaleGurnal();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::cxGrid1TableView1FL_PRINTCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (ATextToDraw=="1")
	{
	ImageList1->GetBitmap(0,ABitmap);
	}
else
	{
	ImageList1->GetBitmap(1,ABitmap);
	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// ������
//---------------------------------------------------------------------------
//������� �������

//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::ReportTecProdagiMainMenuClick(TObject *Sender)
{
OpenFormViborOborudForReportTecProdagi();
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::OpenFormViborOborudForReportTecProdagi(void)
{
if (FormaViborOborud==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaViborOborud.1",IID_IFormaViborOborud,
													(void**)&FormaViborOborud);
	FormaViborOborud->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaViborOborud) return;
	FormaViborOborud->IdArm=glStrToInt64(DMSprARM->ElementID_SARM->AsString);
	FormaViborOborud->TypeOborud="fr";
	FormaViborOborud->Vibor=true;
	FormaViborOborud->NumberProcVibor=ER_ViborOborudForReportTecProdagi;
	FormaViborOborud->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::EndViborOborudForReportTecProdagi(void)
{

   //	FormaViborOborud->Visible=false;
	DMSprOborud->Table->First();
	__int64 id_oborud=glStrToInt64(FormaViborOborud->DM->TableID_OBORUD->AsString);
	while (!DMSprOborud->Table->Eof)
		{
		if(id_oborud==glStrToInt64(DMSprOborud->TableID_OBORUD->AsString))
			{
			PrintReportTecProdagi();
			break;
			}
		DMSprOborud->Table->Next();
		}

}
//----------------------------------------------------------------------------
void TFormaARMKassir2::PrintReportTecProdagi(void)
{
IFiskReg* fr=GetFR();
if (fr>0)
	{
	try
		{
		double sum_sale=0;
		double sale_oplata_nal=0;
		double sale_oplata_pc=0;
		double sum_return_sale=0;
		double return_sale_oplata_nal=0;
		double return_sale_oplata_pc=0;
		__int64 id_firm=glStrToInt64(DMSprOborud->GetParameterPoTable("IdFirm"));

	   IDMQueryRead *dm_q;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&dm_q);
		dm_q->Init(InterfaceMainObject,InterfaceImpl);
	   dm_q->pFIBQ->Close();

	   ///�������
	   dm_q->pFIBQ->SQL->Clear();
	   dm_q->pFIBQ->SQL->Add("  select sum(galldoc.sumdoc) as SUMMA, ");
	   dm_q->pFIBQ->SQL->Add("       sum(dchk.oplnalchk) as OPL_NAL,                                     ");
	   dm_q->pFIBQ->SQL->Add("       sum(dchk.oplpcchk) as OPL_PC                                        ");
	   dm_q->pFIBQ->SQL->Add("  from dchk                                                                ");
	   dm_q->pFIBQ->SQL->Add("  left outer join galldoc on dchk.iddocchk=galldoc.iddoc                   ");
	   dm_q->pFIBQ->SQL->Add("  where dchk.operchk=0 and                                                 ");
	   dm_q->pFIBQ->SQL->Add("          (galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON) and    ");
	   dm_q->pFIBQ->SQL->Add("          dchk.idkkmchk=:PARAM_IDKASSA  and                                ");
	   dm_q->pFIBQ->SQL->Add("  		galldoc.idfirmdoc=:PARAM_IDFIRM                                  ");

	   dm_q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=id_firm;
	   dm_q->pFIBQ->ParamByName("PARAM_IDKASSA")->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
	   dm_q->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=Date()+EncodeTime(0,0,0,0);
	   dm_q->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime= Date()+EncodeTime(23,59,59,999);
	   dm_q->pFIBQ->ExecQuery();

	   sum_sale=dm_q->pFIBQ->FieldByName("SUMMA")->AsFloat;
	   sale_oplata_nal=dm_q->pFIBQ->FieldByName("OPL_NAL")->AsFloat;
	   sale_oplata_pc=dm_q->pFIBQ->FieldByName("OPL_PC")->AsFloat;
	   dm_q->pFIBQ->Close();

	   //��������
	   dm_q->pFIBQ->SQL->Clear();
	   dm_q->pFIBQ->SQL->Add("  select sum(galldoc.sumdoc) as SUMMA, ");
	   dm_q->pFIBQ->SQL->Add("       sum(dchk.oplnalchk) as OPL_NAL,                                     ");
	   dm_q->pFIBQ->SQL->Add("       sum(dchk.oplpcchk) as OPL_PC                                        ");
	   dm_q->pFIBQ->SQL->Add("  from dchk                                                                ");
	   dm_q->pFIBQ->SQL->Add("  left outer join galldoc on dchk.iddocchk=galldoc.iddoc                   ");
	   dm_q->pFIBQ->SQL->Add("  where dchk.operchk=1 and                                                 ");
	   dm_q->pFIBQ->SQL->Add("          (galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON) and    ");
	   dm_q->pFIBQ->SQL->Add("          dchk.idkkmchk=:PARAM_IDKASSA  and                                ");
	   dm_q->pFIBQ->SQL->Add("  		galldoc.idfirmdoc=:PARAM_IDFIRM                                  ");

	   dm_q->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=id_firm;
	   dm_q->pFIBQ->ParamByName("PARAM_IDKASSA")->AsString=DMSprARM->ElementIDKKM_SARM->AsString;
	   dm_q->pFIBQ->ParamByName("PARAM_POSNACH")->AsDateTime=Date()+EncodeTime(0,0,0,0);
	   dm_q->pFIBQ->ParamByName("PARAM_POSCON")->AsDateTime= Date()+EncodeTime(23,59,59,999);
	   dm_q->pFIBQ->ExecQuery();

	   sum_return_sale=dm_q->pFIBQ->FieldByName("SUMMA")->AsFloat;
	   return_sale_oplata_nal=dm_q->pFIBQ->FieldByName("OPL_NAL")->AsFloat;
	   return_sale_oplata_pc=dm_q->pFIBQ->FieldByName("OPL_PC")->AsFloat;
	   dm_q->pFIBQ->Close();
	   dm_q->kanRelease();

	   
		fr->OpenNoFiscalCheck();
		if (DMSprOborud->GetParameterPoTable("StrZag1")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag1"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag2")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag2"),1,1,0,true,false, false);
			}

		if (DMSprOborud->GetParameterPoTable("StrZag3")!="")
			{
			fr->PrintString(DMSprOborud->GetParameterPoTable("StrZag3"),1,1,0,true,false, false);
			}

		fr->PrintString("�����",1,1,1,true,false, false);    //�����
		AnsiString s="    c  "+DateTimeToStr(Date()+EncodeTime(0,0,0,0));
		fr->PrintString(s,1,1,0,true,false, false);
		s="    �� "+DateTimeToStr(Date()+Time());
		fr->PrintString(s,1,1,0,true,false, false);
		fr->PrintString("    �����: "+DMSprARM->ElementNAMEKKM->AsString,1,1,0,true,false, false);
		fr->PrintString("�������:",1,1,0,true,false, false);    //����
		fr->PrintLine();
		fr->PrintString("�����:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(sum_sale,ffFixed,15,2),1,1,2,true,false, false);    //�����
		fr->PrintString("������ ���������:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(sale_oplata_nal,ffFixed,15,2),1,1,2,true,false, false);    //�����
		fr->PrintString("������ ������:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(sale_oplata_pc,ffFixed,15,2),1,1,2,true,false, false);    //�����

		fr->PrintString("��������:",1,1,0,true,false, false);    //����
		fr->PrintLine();
		fr->PrintString("�����:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(sum_return_sale,ffFixed,15,2),1,1,2,true,false, false);    //�����
		fr->PrintString("������ ���������:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(return_sale_oplata_nal,ffFixed,15,2),1,1,2,true,false, false);    //�����
		fr->PrintString("������ ������:",1,1,0,true,false, false);    //����
		fr->PrintString(FloatToStrF(return_sale_oplata_pc,ffFixed,15,2),1,1,2,true,false, false);    //�����

		if(fr->PrintString(DM_Connection->UserInfoFNAME_USER->AsString,1,0,0,true,false,false)==false)
				{
				throw Exception(fr->TextError);
				}


		for (int i=0;i<3;i++)
			{
			if(fr->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}
			 }

		if(fr->PrintString("������� _____________ ",1,0,1,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}

		for (int i=0;i<6;i++)
			{
			if(fr->PrintString(" ",1,0,0,true,false, false)==false)
				{
				throw Exception(fr->TextError);
				}
			 }
        fr->CloseNoFiscalCheck();
		fr->Cut(1);
		}
	catch(Exception &exception)
		{
		ShowMessage("������: "+exception.Message);
		}
	fr->Disconnect();
	fr->kanRelease();
	}
}
//----------------------------------------------------------------------------


void __fastcall TFormaARMKassir2::OpalataPoFirmMainMenuClick(TObject *Sender)
{

FormaViborOplat_ARM2=new TFormaViborOplat_ARM2(Application);
FormaViborOplat_ARM2->FOnPrintCheck = PrintCheckEvent;
FormaViborOplat_ARM2->FOnCloseForm = CloseFormInOplEvent;

TcxCustomDataController *dc = cxGrid1TableView1->DataController;


//��������� ����� �� ���������
__int64 id_default_firm=0;
id_default_firm=glStrToInt64(DMSprARM->GetParameter("DefaultIdFirm"));
if (id_default_firm==0)
	{
	ShowMessage("�� ������� ����� �� ��������� ��� ������ �������, � ������� �� ����� �������� �����!");
	return;
	}

cxGrid1TableView1->BeginUpdate();
for (int i=0; i<dc->RowCount; i++)
	{
	if (glStrToInt64(dc->Values[i][cxGrid1TableView1IDFIRM->Index])==0)
		{
		dc->Values[i][cxGrid1TableView1IDFIRM->Index]=IntToStr(id_default_firm);

		}
	}
cxGrid1TableView1->EndUpdate();


//����������
cxGrid1TableView1->BeginUpdate();
dc->ClearSorting(true);
cxGrid1TableView1IDFIRM->SortOrder = soAscending;
cxGrid1TableView1->EndUpdate();


__int64 id_tek_firm=-1;

TcxGridViewData * AViewData=cxGrid1TableView1->ViewData;
for(int i=0;i<AViewData->RowCount;i++)
	{
	TcxCustomDataController *dc_opl = FormaViborOplat_ARM2->cxGrid1TableView1->DataController;
		if(id_tek_firm!=glStrToInt64(AViewData->Records[i]->Values[cxGrid1TableView1IDFIRM->Index]))
			{ //����� �����
			  //��������� ����� ������
			dc_opl->AppendRecord();
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index]=0.00;
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index]=0.00;
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index]=0.00;
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SDACHA->Index]=0.00;

			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1IDFIRM->Index]=
							AViewData->Records[i]->Values[cxGrid1TableView1IDFIRM->Index];
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1NAMEFIRM->Index]=
							AViewData->Records[i]->Values[cxGrid1TableView1NAMEFIRM->Index];
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index]=
							(double) dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index]+
							(double) AViewData->Records[i]->Values[cxGrid1TableView1SUM->Index];
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index]=
							dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index];
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index]=0;
			id_tek_firm=glStrToInt64(AViewData->Records[i]->Values[cxGrid1TableView1IDFIRM->Index]);
			}
		else
			{ //���������
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index]=
							(double) dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index]+
							(double) AViewData->Records[i]->Values[cxGrid1TableView1SUM->Index];
			dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index]=
							dc_opl->Values[dc_opl->RowCount-1][FormaViborOplat_ARM2->cxGrid1TableView1SUMCHECK->Index];
			}
	}
	
FormaViborOplat_ARM2->UpdateForm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::PrintCheckEvent(TObject *Sender)
{
TcxCustomDataController *dc_opl = FormaViborOplat_ARM2->cxGrid1TableView1->DataController;
	double nal=0;
	double oplata_pc=0;

	for (int i=0; i<dc_opl->RowCount; i++)
		{
		nal=nal+dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1NAL->Index];
		oplata_pc=oplata_pc+dc_opl->Values[i][FormaViborOplat_ARM2->cxGrid1TableView1OPLPLATCARD->Index];
		}

	NalcxCalcEdit->Text=FloatToStr(nal);
	OplCardcxCalcEdit->Text=FloatToStr(oplata_pc);
	PrintDocCheck();
	FormaViborOplat_ARM2->Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::CloseFormInOplEvent(TObject *Sender)
{
FormaViborOplat_ARM2=0;
}
//---------------------------------------------------------------------------
void TFormaARMKassir2::OutProtocol(AnsiString s)
{
DM_Connection->glSaveProtocol(s);
}
//----------------------------------------------------------------------------
void TFormaARMKassir2::ShowPrim(AnsiString s, bool add)
{
if (add==true)
	{
	Prim->Caption=Prim->Caption+s;
	}
else
	{
	Prim->Caption=s;
	}
}
//----------------------------------------------------------------------------
void TFormaARMKassir2::CheckDateTimeFR(void)
{

DMSprOborud->Table->First();
while(!DMSprOborud->Table->Eof)
	{
	if (DMSprOborud->TableTYPE_OBORUD->AsString=="fr")
		{
		if (DMSprOborud->GetParameterPoTable("PrintFiscalCheck")=="1")
			{  //������������� ���� � ����� ������ � ���������� �����������
			bool set_date_time=false;
			IFiskReg* fr=GetFR();
			try
				{
				//����� � ����
				TTime time_fr=fr->GetTime();
				TTime time_pc=Time();
				TDate date_fr=fr->GetDate();
				TDate date_pc=Date();
				if (date_fr==date_pc)
					{ //�������� �����
					//ShowMessage(TimeToStr(fabs(time_fr-time_pc))+"  "+TimeToStr(EncodeTime(0,5,0,0)));
					if (fabs(time_fr-time_pc) > EncodeTime(0,5,0,0))
						{ //������� ������ 5 �����
						set_date_time=true;
						}
					}
				else
					{
					set_date_time=true;
					}

				if (set_date_time==true && fr->ConnectFR==true)
					{
					UnicodeString V="������� � ���������� ����� ���������� � ����������� ������������ ����� 5 �����.\n\n";
					V=V+DateToStr(date_pc)+"  "+TimeToStr(time_pc)+" - ���������\n";
					V=V+DateToStr(date_fr)+"  "+TimeToStr(time_fr)+" - ���������� �����������\n\n";
					V=V+"���������� ���� � ����� � ���������� ������������ �� ���������� ����� ����������?";
					UnicodeString Z="��������!";
					if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
						{
						V="����� ����������� ��������� �������� "+DateTimeToStr(Now())+
								". �������������� ��������� � ���������� ������������?";
						if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
							{
							if  (fr->SetTime(Time())==true)
								{
								}
							else
								{
								ShowMessage("������ ��� ��������� �������: "+fr->TextError);
								}

							if(fr->SetDate(Date())==true)
								{
								}
							else
								{
								ShowMessage("������ ��� ��������� ����: "+fr->TextError);
								}
							}
						}
					}
				}
			catch (Exception &exception)
				{
				ShowMessage(DMSprOborud->TableNAME_OBORUD->AsString+
						": ������ ��� �������� ���� � ������� ����������� ������������ - "+
						exception.Message);
				}
			fr->Disconnect();
			delete fr;
			}
		}
	DMSprOborud->Table->Next();
	}


}
//----------------------------------------------------------------------------
void __fastcall TFormaARMKassir2::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaARMKassir2::ActionPrintExecute(TObject *Sender)
{
PrintDocCheck();
}
//---------------------------------------------------------------------------

