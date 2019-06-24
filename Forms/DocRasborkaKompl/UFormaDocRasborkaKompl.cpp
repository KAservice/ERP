//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UFormaDocRasborkaKompl.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalc"
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
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalendar"
#pragma link "cxLabel"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxDBLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaDocRasborkaKompl::TFormaDocRasborkaKompl(TComponent* Owner)
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
bool TFormaDocRasborkaKompl::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRasborkaKompl.1",IID_IDMDocRasborkaKompl,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PrefiksNumcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
RPricecxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
KolcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceDoc;
NameEdcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //������ ��������
IdDoc=0;           //������������� ������� ������
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;


//��������� ��� ���
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
												 (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypeRPrice->DataSourceTable;

//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
												 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaDocRasborkaKomplImpl),false);
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
DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaDocRasborkaKompl::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::UpdateForm(void)
{

Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}


//if (DM->SkladRozn==true)
//	{
//	cxGrid1DBTableView1RPRICE_DRASBKOMPLT->Visible=true;
//	cxGrid1DBTableView1RSUM_DRASBKOMPLT->Visible=true;
//	TypePricecxDBLookupComboBox->Visible=true;
//	RTPriceLabel->Visible=true;
//	}
//else
//	{
//	cxGrid1DBTableView1RPRICE_DRASBKOMPLT->Visible=false;
//	cxGrid1DBTableView1RSUM_DRASBKOMPLT->Visible=false;
//	TypePricecxDBLookupComboBox->Visible=false;
//	RTPriceLabel->Visible=false;
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

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

DMTableExtPrintForm->kanRelease();
DM->kanRelease();
DMSprTypeRPrice->kanRelease();

Action=caFree;
}
//---------------------------------------------------------------------------
int TFormaDocRasborkaKompl::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_InfBase)
	{
	if(type_event==1)
		{
		EndViborInfBase();
		}
	FormaSpiskaSprInfBase=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_Firm)
	{
	if(type_event==1)
		{
		EndViborFirm();
		}
	FormaSpiskaSprFirm=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_Sklad)
	{
	if(type_event==1)
		{
		EndViborSklad();
		}
	FormaSpiskaSprSklad=0;
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}

if (number_procedure_end==ER_NomKomplekta)
	{
	if(type_event==1)
		{
		EndViborKomplekta();
		}
	FormaSpiskaSprNom=0;
	}


if (number_procedure_end==ER_EdKomplekta)
	{
	if(type_event==1)
		{
		EndViborEdKomplekta();
		}
	FormaSpiskaSprEd=0;
	}


if (number_procedure_end==ER_Nom)
	{
	if(type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}

if (number_procedure_end==ER_Ed)
	{
	if(type_event==1)
		{
		EndViborEd();
		}
	FormaSpiskaSprEd=0;
	}

if (number_procedure_end==ER_Part)
	{
	if(type_event==1)
		{
		EndEditPart() ;
		}
	 FormaElementeSprPart=0;
	}

if (number_procedure_end==ER_Project)
		{
		if (type_event==1)
				{
				EndViborProject()  ;
				}
		SpisokProject=0;
		}

if (number_procedure_end==ER_BusinessOper)
		{
		if (type_event==1)
				{
				EndViborBusinessOper()  ;
				}
		SpisokBusinessOper=0;
		}
return -1;
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//����� �������������� ����
void TFormaDocRasborkaKompl::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
												 (void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		} 
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();


}
//---------------------------------------------------------------------------
//����� �����
void TFormaDocRasborkaKompl::ViborFirm(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
												 (void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
//		FormaSpiskaSprFirm->HintLabel->Caption="�������� ����� ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborFirm(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDFIRMDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
	DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	DM->DocAll->Post();


}
//----------------------------------------------------------------------------
//����� ������
void TFormaDocRasborkaKompl::ViborSklad(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
//		FormaSpiskaSprSklad->HintLabel->Caption="�������� ����� ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLDOC->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->DocAll->Post();
	UpdateForm();


}
//-----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::ViborKomplekta(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->NumberProcVibor=ER_NomKomplekta;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="�������� ������������ ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocIDNOM_DRASBKOMPL->AsString);
		FormaSpiskaSprNom->UpdateForm();

		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborKomplekta(void)
{

				DM->Doc->Edit();
				DM->DocIDNOM_DRASBKOMPL->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocKOL_DRASBKOMPL->AsInteger=1;


				DM->DocIDED_DRASBKOMPL->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocKF_DRASBKOMPL->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
					DM->DocRPRICE_DRASBKOMPL->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString), //��� ���
											glStrToInt64(DM->DocIDNOM_DRASBKOMPL->AsString),            //������������
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString),             //�������
											DM->DocKF_DRASBKOMPL->AsFloat,                              //�����������
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //������� �������
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocRPRICE_DRASBKOMPL->AsFloat=0;
					}

				DM->Doc->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);


}
//----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::ViborEdKomplekta(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->NumberProcVibor=ER_EdKomplekta;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocIDNOM_DRASBKOMPL->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocIDNOM_DRASBKOMPL->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="������� ������������: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="�������� ������� ������������ ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;

		}

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborEdKomplekta(void)
{

	DM->Doc->Edit();
	DM->DocIDED_DRASBKOMPL->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocKF_DRASBKOMPL->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
					DM->DocRPRICE_DRASBKOMPL->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString), //��� ���
											glStrToInt64(DM->DocIDNOM_DRASBKOMPL->AsString),            //������������
											glStrToInt64(DM->DocIDED_DRASBKOMPL->AsString),             //�������
											DM->DocKF_DRASBKOMPL->AsFloat,                              //�����������
											0);            //������� �������
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocRPRICE_DRASBKOMPL->AsFloat=0;
					}

	DM->Doc->Post();



}
//----------------------------------------------------------------------------
//����� ������������
void TFormaDocRasborkaKompl::ViborNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="�������� ������������ ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborNom(void)
{

                if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTIDNOM_DRASBKOMPLT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_DRASBKOMPLT->AsInteger=1;


				DM->DocTIDED_DRASBKOMPLT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_DRASBKOMPLT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
					DM->DocTRPRICE_DRASBKOMPLT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString), //��� ���
											glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString),            //������������
											glStrToInt64(DM->DocTIDED_DRASBKOMPLT->AsString),             //�������
											DM->DocTKF_DRASBKOMPLT->AsFloat,                              //�����������
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //������� �������
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DRASBKOMPLT->AsFloat=0;
					}

				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);


		cxGrid1->SetFocus();
		cxGrid1DBTableView1KOL_DRASBKOMPLT->Selected=true;
}
//----------------------------------------------------------------------------
//����� �������
void TFormaDocRasborkaKompl::ViborEd(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="������� ������������: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="�������� ������� ������������ ��� ��������� ������ ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborEd(void)
{


	DM->DocT->Edit();
	DM->DocTIDED_DRASBKOMPLT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTKF_DRASBKOMPLT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;

				if (DM->SkladRozn==true)
					{
					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
					DM->DocTRPRICE_DRASBKOMPLT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDRTPRICE_DRASBKOMPL->AsString), //��� ���
											glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString),            //������������
											glStrToInt64(DM->DocTIDED_DRASBKOMPLT->AsString),             //�������
											DM->DocTKF_DRASBKOMPLT->AsFloat,                              //�����������
											0);            //������� �������
					DMSprPrice->kanRelease();
					}
				else
					{
					DM->DocTRPRICE_DRASBKOMPLT->AsFloat=0;
					}

	DM->DocT->Post();


	cxGrid1->SetFocus();
	cxGrid1DBTableView1RPRICE_DRASBKOMPLT->Selected=true;
}

//---------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//�����
PrintForm->SS->EndUpdate();
OutputZagolovokReport(PrintForm);

//�������

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
		}

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OutputZagolovokReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow=1;
numCol=2;


prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;
IDMSprFirm *spr_firm;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm,
													(void**)&spr_firm);
		spr_firm->Init(InterfaceMainObject,InterfaceImpl);
spr_firm->OpenElement(glStrToInt64(DM->DocAllIDFIRMDOC->AsString));

cell = prForm->SS->ActiveSheet->GetCellObject(2, 1);
cell->Text=spr_firm->ElementFNAMEFIRM->AsString
		+", ��� "+spr_firm->ElementINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�����: "+spr_firm->ElementPADRFIRM->AsString;
delete cell;
numRow++;

spr_firm->kanRelease();

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�����: "+DM->DocAllNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;


cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="�������� ��������� �"+DM->DocAllNUMDOC->AsString+" �� "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;



cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="��������: "+DM->DocNAMENOM->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="�������: "+DM->DocNAMEED->AsString+
			" ����������: "+DM->DocKOL_DRASBKOMPL->AsString+
			" ����. ����: "+DM->DocRPRICE_DRASBKOMPL->AsString;
delete cell;
numRow++;
cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="���������: "+DM->DocDESCR_DRASBKOMPL->AsString;
delete cell;
numRow++;
numRow++;

//��������� �������
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="������������";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="���-��";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�������";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="����";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="�����";
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Font->Size = 10;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=IntToStr(porNumStr);
cell->Style->HorzTextAlign = haCENTER;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMENOM->AsString;
//cell->Style->HorzTextAlign = haCENTER;
cell->Style->WordBreak = true;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTKOL_DRASBKOMPLT->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->DocTNAMEED->AsString;
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTKF_DRASBKOMPLT->AsFloat,ffFixed,10,3);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRPRICE_DRASBKOMPLT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=FloatToStrF(DM->DocTRSUM_DRASBKOMPLT->AsFloat,ffFixed,10,2);
cell->Style->HorzTextAlign = haRIGHT;
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
}


//------------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OutputPodavalReport(TSheetEditor *prForm)
{
numRow++;
numCol=8;
TcxSSCellObject *cell;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="�����: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
delete cell;
 numRow++;
numCol=8;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="����� ���: 0.00 ";
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->HorzTextAlign = haLEFT;
cell->Text="����� ������������ "+IntToStr(DM->DocT->RecordCount)+
                " �� ����� "+FloatToStrF(DM->DocAllSUMDOC->AsFloat, ffFixed,10,2);
delete cell;
numRow++;

numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="("+glCurrencyPropis(DM->DocAllSUMDOC->AsFloat)+" )";
delete cell;
numRow++;

for (int i=2;i<=8;i++)
        {
        cell = prForm->SS->ActiveSheet->GetCellObject(i, numRow);
        cell->Style->Borders->Edges [eBottom]->Style=lsThin;
        delete cell;
        }
numRow++;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="����  __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(8, numRow);
cell->Style->HorzTextAlign = haRIGHT;
cell->Text="������  __________________________ ";
delete cell;
}
//---------------------------------------------------------------
//----------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRasborkaKompl::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("DocSborkaKompl");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborNom();

}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;
ViborEd(); 
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::TypeRPriceComboBoxPropertiesChange(
      TObject *Sender)
{
//if(flObrabatChangeRoznTypePrice==false) return;
//FindNextControl(ActiveControl,true,true,false)->SetFocus();
//
// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
//
// if ( TypeRPriceComboBox->ItemIndex!=0)
//		{
//		DMSprTypeRPrice->Table->First();
//		DMSprTypeRPrice->Table->MoveBy(TypeRPriceComboBox->ItemIndex-1);
//		DM->Doc->Edit();
//		DM->DocIDRTPRICE_DVIPPROD->AsInt64=DMSprTypeRPrice->TableID_TPRICE->AsInt64;
//		DM->Doc->Post();
//		}
//else
//	{
//	ShowMessage("��� ��� ������ ���� ����� �����������!");
//	UpdateForm();
//	return;
//	}
//
////�������� ���� �� ������
//if((DM->DocT->RecordCount>0) && (DM->SkladRozn==true))
//		{
//		String V="� ��������� ����� ��������� ���� ������. ����������� ����?";
//		String Z="����������� ����?";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//				{
//				TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
//				DM->DocT->First();
//				while(!DM->DocT->Eof)
//						{
//						DM->DocT->Edit();
//						DMSprPrice->FindElement( DM->DocIDRTPRICE_DVIPPROD->AsInt64,
//											 DM->DocTIDNOM_DVIPPRODT->AsInt64);
//						DM->DocTRPRICE_DVIPPRODT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
//														DM->DocTKF_DVIPPRODT->AsFloat;
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRasborkaKompl::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TFormaDocRasborkaKompl::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborNom();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRasborkaKompl::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NameNomcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKomplekta();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NameEdcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();	
}
//---------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OpenFormElementaSprPart(void)
{
if (glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString)>0)
	{
	if (FormaElementeSprPart==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementeSprPart.1",IID_IFormaElementaSprPart,
													(void**)&FormaElementeSprPart);
		FormaElementeSprPart->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementeSprPart->NumberProcVibor=ER_Part;
		
		if (glStrToInt64(DM->DocTIDPART_DRASBKOMPLT->AsString)>0)
			{
			FormaElementeSprPart->DM->OpenElement(glStrToInt64(DM->DocTIDPART_DRASBKOMPLT->AsString));
			if ((glStrToInt64(FormaElementeSprPart->DM->ElementIDDOCPART->AsString)==glStrToInt64(DM->DocAllIDDOC->AsString))
						&&(glStrToInt64(FormaElementeSprPart->DM->ElementIDNOMPART->AsString)==glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString)))
				{ //���� �� �������� � �����������
				}
			else
				{ //������� ����� �������
				FormaElementeSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString));
				if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
					{
					FormaElementeSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
					}
				}
			}
		else
			{ //������� ����� �������
			FormaElementeSprPart->DM->NewElement(glStrToInt64(DM->DocTIDNOM_DRASBKOMPLT->AsString));
			if(glStrToInt64(DM->DocAllIDDOC->AsString)>0)
				{
				FormaElementeSprPart->DM->ElementIDDOCPART->AsString=DM->DocAllIDDOC->AsString;
				}
			}

		FormaElementeSprPart->DM->Element->Edit();
		if(glStrToInt64(DM->DocAllIDFIRMDOC->AsString)>0)
				{
				FormaElementeSprPart->DM->ElementIDFIRMPART->AsString=DM->DocAllIDFIRMDOC->AsString;
				}
		if(glStrToInt64(DM->DocAllIDKLDOC->AsString)>0)
				{
				FormaElementeSprPart->DM->ElementIDKLPART->AsString=DM->DocAllIDKLDOC->AsString;
				}
		FormaElementeSprPart->DM->ElementDOCPART->AsString="�������� ��������� �"+DM->DocAllNUMDOC->AsString+" �� " +DM->DocAllPOSDOC->AsString;

		FormaElementeSprPart->DM->Element->Post();
		}
	}
}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndEditPart(void)
{

	DM->DocT->Edit();
	DM->DocTIDPART_DRASBKOMPLT->AsString=FormaElementeSprPart->DM->ElementIDPART->AsString;

	DM->DocT->Post();


}
//----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::BeforeSaveDoc(void)
{
if (DM->DocAllPOSDOC->AsDateTime > Date())
	{
	UnicodeString V="����� ���� �������� ������������������ ���������� ����������! �������� ����� ��������� �� �������?";
	UnicodeString Z="��������!";
	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
		{
		DM->DocAll->Edit();
		DM->DocAllPOSDOC->AsDateTime=Now();
		DM->DocAll->Post();
		}
	}

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EditPropPartcxButtonClick(TObject *Sender)
{
OpenFormElementaSprPart();	
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaDocRasborkaKompl::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::RunExternalModule(__int64 id_module, int type_module)
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


//���� �������� ���������� ������, ��� �������  IDDOC
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllIDDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("������ ��� ���������� ���������: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("������ ��� ���������� ���������: "+DM->TextError);
			}
		UpdateForm();
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		UpdateForm();
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::ActionPrintExecute(TObject *Sender)
{
OpenPrintForm() ;
}
//---------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OpenFormSpiskaSprProject(void)
{
if (Prosmotr==true) return;
if (SpisokProject==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprProject.1",IID_IFormaSpiskaSprProject,
													(void**)&SpisokProject);
		SpisokProject->Init(InterfaceMainObject,InterfaceImpl);
		SpisokProject->NumberProcVibor=ER_Project;
		SpisokProject->Vibor=true;
		SpisokProject->UpdateForm();

		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TFormaDocRasborkaKompl::OpenFormSpiskaSprBusinessOper(void)
{
if (Prosmotr==true) return;
if (SpisokBusinessOper==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBusinessOper,IID_IFormaSpiskaSprBusinessOper,
													(void**)&SpisokBusinessOper);
		SpisokBusinessOper->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBusinessOper->NumberProcVibor=ER_BusinessOper;
		SpisokBusinessOper->Vibor=true;
		SpisokBusinessOper->UpdateForm();
		}
}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TFormaDocRasborkaKompl::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDBUSINOP_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRasborkaKompl::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocAll->Edit();
		DM->DocAllIDPROJECT_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

