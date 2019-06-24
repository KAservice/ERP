//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop



#include "UREM_FormaDocOtprPost.h"

#include "IFormaElementaSprNom.h"
#include "IFormaElementaSprEd.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
#include "IDMDocPrihNakl.h"
#include "IREM_DMSprGrpModel.h"
#include "IREM_DMSprModel.h"
#include "IREM_DMGurCustQuery.h"
#include "IREM_DMCustQuery.h"
#include "IDMSprImportNom.h"
#include "IREM_FormaCustQuery.h"
#include "IREM_FormaDocPrihNakl.h"
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
#pragma link "cxPC"
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocOtprPost::TREM_FormaDocOtprPost(TComponent* Owner)
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
bool TREM_FormaDocOtprPost::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOtprPost,IID_IREM_DMDocOtprPost, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceDocT;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;


PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NumDocPostcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;



cxDBButtonEditNAME_SBRAND->DataBinding->DataSource=DM->DataSourceDoc;
cxDBButtonEditNAME_SPRODUCER->DataBinding->DataSource=DM->DataSourceDoc;
DBTextSUM_REM_GALLDOC->DataSource=DM->DataSourceDocAll;

cxDBTextEditTK_REM_DOTPRPOST->DataBinding->DataSource=DM->DataSourceDoc;

cxDBDateEditPLANDOSTAVKI_REM_DOTPRPOST->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //������ ��������
Vibor=false;       //��� ������
IdDoc=0;           //������������� ������� ������
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;

flObrabatChangeTypePrice=false;


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
			 (void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Properties->Items->Clear();
TypePriceComboBox->Properties->Items->Add("�� �����");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
		TypePriceComboBox->Properties->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
        }
//��������� ��� ���




//�������� ������ ������� �������

InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
						 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocOtprPostImpl),false);
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

//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::UpdateForm(void)
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

flObrabatChangeTypePrice=false;

TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(glStrToInt64(DM->DocIDTPRICE_REM_DOTPRPOST->AsString));
flObrabatChangeTypePrice=true;

}
//---------------------------------------------------------------------------
int TREM_FormaDocOtprPost::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocOtprPost::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(Ed)Ed->kanRelease();
if(Nom)Nom->kanRelease();
if(Firma)Firma->kanRelease();
if(Sklad)Sklad->kanRelease();
if(Klient)Klient->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();
if(REM_FormaGurCustQuery)REM_FormaGurCustQuery->kanRelease();
if(FormaSpiskaSprBrand)FormaSpiskaSprBrand->kanRelease();
if(FormaSpiskaSprProducer)FormaSpiskaSprProducer->kanRelease();
if(FormaSpiskaSprProducerNom)FormaSpiskaSprProducerNom->kanRelease();

//������� ICallBack ��� �������� ������� � ���������� �����
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease(); i_callback=0;
	}



DMSprTypePrice->kanRelease();
DMTableExtPrintForm->kanRelease();
DM->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocOtprPost::FormActivate(TObject *Sender)
{
//�������������� ���� IAsyncExternalEvent � ������� ������ ��� ��������� �������
if(InterfaceMainObject > 0)
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

void __fastcall TREM_FormaDocOtprPost::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaDocOtprPost::ReadShtrihCodEvent(int number, UnicodeString sh)
{
//


}
//---------------------------------------------------------------
int TREM_FormaDocOtprPost::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)
                {
                if (ActionOperation==aoAddNewString)
                        {
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DOTPRPOSTT->AsString=Nom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=Nom->DM->ElementNAMENOM->AsString;
				if (DM->DocTKOL_REM_DOTPRPOSTT->AsFloat > 0.001)  //������ ����������
					{ //�� ��������
					}
				else
					{
					DM->DocTKOL_REM_DOTPRPOSTT->AsFloat=1;
					}

				DM->DocTIDED_REM_DOTPRPOSTT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=Nom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DOTPRPOSTT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;


				DM->DocTPRICE_REM_DOTPRPOSTT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
														*DM->DocTKF_REM_DOTPRPOSTT->AsFloat;


                DM->DocT->Post();
                //DBGrid1->SelectedField=DM->DocTKOLPRNT;
				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
				}
		Nom=0;

		}

if (number_procedure_end==ER_PodborNom)//==PodborNom)
		{

        }

if (number_procedure_end==ER_Ed)//==Edinica)
        {
		if (type_event==1)
                {
                DM->DocT->Edit();
				DM->DocTIDED_REM_DOTPRPOSTT->AsString=Ed->DM->ElementIDED->AsString;
                DM->DocTNAMEED->AsString=Ed->DM->Element->FieldByName("NAMEED")->AsString;
				DM->DocTKF_REM_DOTPRPOSTT->AsFloat=Ed->DM->ElementKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
									(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
						DMSprPrice->FindElement(glStrToInt64(DM->DocIDTPRICE_REM_DOTPRPOST->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString));
						DM->DocTPRICE_REM_DOTPRPOSTT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOTPRPOSTT->AsFloat;
					DMSprPrice->kanRelease();

                DM->DocT->Post();
                }
		Ed=0;
		}

if (number_procedure_end==ER_Firm)//==FirmaRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRM_REM_GALLDOC->AsString=Firma->DM->ElementIDFIRM->AsString;
                DM->DocAllNAMEFIRM->AsString=Firma->DM->Element->FieldByName("NAMEFIRM")->AsString;
                DM->DocAll->Post();
                }
		Firma=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Sklad)//==SkladRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLAD_REM_GALLDOC->AsString=Sklad->DM->ElementIDSKLAD->AsString;
                DM->DocAllNAMESKLAD->AsString=Sklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
				DM->DocAll->Post();
				UpdateForm();
                }
		Sklad=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_Klient)//==KlientRekvisit)
        {
		if (type_event==1)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=Klient->DM->ElementIDKLIENT->AsString;
                DM->DocAllNAMEKLIENT->AsString=Klient->DM->Element->FieldByName("NAMEKLIENT")->AsString;
                DM->DocAll->Post();
                }
		Klient=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
        }

if (number_procedure_end==ER_InfBase)//==ViborInfBase)
		{
		if (type_event==1)
				{
                DM->DocAll->Edit();
				DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
		FormaSpiskaSprInfBase=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_Part)
		{

		}


if (number_procedure_end==ER_GrpNom)
		{

		}

//�������������� ���������� ������������
if (number_procedure_end==ER_ElementNom)
		{
		if (type_event==1)
				{

				}

		}

//�������������� ���������� �������
if (number_procedure_end==ER_ElementEd)
		{
		if (type_event==1)
				{

				}

		}

//�������������� ���������� ������������
if (number_procedure_end==ER_ElementHW)
		{
		if (type_event==1)
				{

				}

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


if (number_procedure_end==ER_ViborBrand)
		{
		if (type_event==1)
				{
				EndViborBrand()  ;
				}
		FormaSpiskaSprBrand=0;
		}

if (number_procedure_end==ER_ViborProducer)
		{
		if (type_event==1)
				{
				EndViborProducer()  ;
				}
		FormaSpiskaSprProducer=0;
		}

if (number_procedure_end==ER_ViborCustomerQuery)
		{
		if (type_event==1)
				{
				EndViborCustQuery()  ;
				}
		REM_FormaGurCustQuery=0;
		}


if (number_procedure_end==ER_ViborProducerNom)
		{
		if (type_event==1)
				{
				EndViborProducerNom()  ;
				}
		FormaSpiskaSprProducerNom=0;
		}
return -1;
}
//----------------------------------------------------------------------------
void  TREM_FormaDocOtprPost::OpenFSSprNom(void)
{
if(Prosmotr==true) return;
if (Nom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&Nom);
		Nom->Init(InterfaceMainObject,InterfaceImpl);
        Nom->Vibor=true;
		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DOTPRPOST->AsString);
//        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
//		Nom->HintLabel->Caption="�������� ������������ ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		Nom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString);
		Nom->UpdateForm();
		Nom->NumberProcVibor=ER_Nom;
        }
}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost:: OpenFSSprEd()
{
if(Prosmotr==true) return;
if (Ed==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&Ed);
		Ed->Init(InterfaceMainObject,InterfaceImpl);
		Ed->Vibor=true;
		Ed->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString);
		Ed->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString));
//        Ed->LabelNom->Caption="������� ������������: "+DM->DocTNAMENOM->AsString;
//		Ed->HintLabel->Caption="�������� ������� ������������ ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		Ed->NumberProcVibor=ER_Ed;

        }
}

//----------------------------------------------------------------------------






void    TREM_FormaDocOtprPost::OpenFormSpiskaSprFirm(void)
{
if(Prosmotr==true) return;
if (Firma==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&Firma);
		Firma->Init(InterfaceMainObject,InterfaceImpl);
        Firma->Vibor=true;
        Firma->DM->OpenTable();
//        Firma->HintLabel->Caption="�������� ����� ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		Firma->NumberProcVibor=ER_Firm;
        }

}
//---------------------------------------------------------------------------
void  TREM_FormaDocOtprPost::OpenFormSpiskaSprSklad(void)
{
if(Prosmotr==true) return;
if (Sklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&Sklad);
		Sklad->Init(InterfaceMainObject,InterfaceImpl);
		Sklad->Vibor=true;
		Sklad->DM->OpenTable();
//        Sklad->HintLabel->Caption="�������� ����� ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		Sklad->NumberProcVibor=ER_Sklad;

        }

}
//---------------------------------------------------------------------------
void  TREM_FormaDocOtprPost::OpenFormSpiskaSprKlient(void)
{
if(Prosmotr==true) return;
if (Klient==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&Klient);
		Klient->Init(InterfaceMainObject,InterfaceImpl);
		Klient->Vibor=true;
		Klient->DM->OpenTable(0,false);
//        Klient->HintLabel->Caption="�������� ���������� ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		Klient->IdKlient=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
		Klient->NumberProcVibor=ER_Klient;

		}


}
//-----------------------------------------------------------------------------




void __fastcall TREM_FormaDocOtprPost::AddNewStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableAppend();
OpenFSSprNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::DeleteStringClick(TObject *Sender)
{
DM->TableDelete();
}

//---------------------------------------------------------------------------

void TREM_FormaDocOtprPost::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
        }
}
//---------------------------------------------------------------------




void __fastcall TREM_FormaDocOtprPost::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{


if(Prosmotr==true) return;


switch (AButtonIndex)
	{
	case 0:
		{
		OpenFSSprNom();
		}break;
	case 1:
		{

		}break;
	case 2:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDNOM_REM_DOTPRPOSTT->Clear();
		DM->DocTNAMENOM->AsString="";
		DM->DocTIDED_REM_DOTPRPOSTT->Clear();;
		DM->DocTNAMEED->AsString="";
		DM->DocTKF_REM_DOTPRPOSTT->AsFloat=0;
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if(Prosmotr==true) return;

		OpenFSSprEd();


}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::TypePriceComboBoxPropertiesChange(
      TObject *Sender)
{
if (flObrabatChangeTypePrice==false) return;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

 if (Prosmotr==true)
        {
		UpdateForm();
         return;
		}

 if ( TypePriceComboBox->ItemIndex!=0)
		{
		DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_REM_DOTPRPOST->AsString=DMSprTypePrice->TableID_TPRICE->AsString;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("��� ��� ������ ���� ����� �����������!");
	UpdateForm();
	return;
	}

//�������� ���� �� ������
if(DM->DocT->RecordCount>0)
		{
		String V="� ��������� ����� ��������� ���� ������. ����������� ����?";
		String Z="����������� ����?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				IDMSprPrice * DMSprPrice;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
				DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						DMSprPrice->FindElement( glStrToInt64(DM->DocIDTPRICE_REM_DOTPRPOST->AsString),
											 glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString));
						DM->DocTPRICE_REM_DOTPRPOSTT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
														DM->DocTKF_REM_DOTPRPOSTT->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				DMSprPrice->kanRelease();
				}
		}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprKlient();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------




void TREM_FormaDocOtprPost::BeforeSaveDoc(void)
{
if (DM->DocAllPOS_REM_GALLDOC->AsDateTime < Now())
	{
	UnicodeString V="����� ���� �������� ������������������ ���������� ����������! �������� ����� ��������� �� �������?";
	UnicodeString Z="��������!";
	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
		{
		DM->DocAll->Edit();
		DM->DocAllPOS_REM_GALLDOC->AsDateTime=Now();
		DM->DocAll->Post();
		}
	}

}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaDocOtprPost::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFSSprNom();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::IsmPriceCheckBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::PrimcxDBTextEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaDocOtprPost::NumDocPostcxDBTextEditKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::cxDBDateEditPLANDOSTAVKI_REM_DOTPRPOSTKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TREM_FormaDocOtprPost::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::RunExternalModule(__int64 id_module, int type_module)
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
module->SetInt64Variables("glIdDoc", glStrToInt64(DM->DocAllID_REM_GALLDOC->AsString));
	
module->ExecuteModule();

}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::ActionCloseExecute(TObject *Sender)
{
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
BeforeSaveDoc();
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

void __fastcall TREM_FormaDocOtprPost::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;

BeforeSaveDoc();

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

void __fastcall TREM_FormaDocOtprPost::ActionSaveExecute(TObject *Sender)
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


void __fastcall TREM_FormaDocOtprPost::ActionEditNomExecute(TObject *Sender)
{
		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString));
		FormaElementa->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DOTPRPOST->AsString);
		FormaElementa->IdFirm=glStrToInt64(DM->DocAllIDFIRM_REM_GALLDOC->AsString);
		FormaElementa->NumberProcVibor=ER_ElementNom;
		//FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom="";
		FormaElementa->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ActionEditEdExecute(TObject *Sender)
{
IFormaElementaSprEd * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprEd.1",IID_IFormaElementaSprEd,
						 (void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->DocTIDED_REM_DOTPRPOSTT->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ER_ElementEd;
}
//---------------------------------------------------------------------------

void TREM_FormaDocOtprPost::OpenFormSpiskaSprProject(void)
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
void __fastcall TREM_FormaDocOtprPost::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::OpenFormSpiskaSprBusinessOper(void)
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
void __fastcall TREM_FormaDocOtprPost::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocOtprPost::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDBUSINOP_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->DocAllIDPROJECT_REM_GALLDOC->Clear();
		DM->DocAll->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaDocOtprPost::ViborBrand(void)
{
if (FormaSpiskaSprBrand==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBrand,IID_IFormaSpiskaSprBrand,
													 (void**)&FormaSpiskaSprBrand);
		FormaSpiskaSprBrand->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprBrand->Vibor=true;
		FormaSpiskaSprBrand->NumberProcVibor=ER_ViborBrand;
		}
}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::EndViborBrand(void)
{
 	DM->Doc->Edit();
	DM->DocIDBRAND_REM_DOTPRPOST->AsString=FormaSpiskaSprBrand->DM->ElementID_SBRAND->AsString;
	DM->DocNAME_SBRAND->AsString=FormaSpiskaSprBrand->DM->ElementNAME_SBRAND->AsString;
	DM->Doc->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------

void TREM_FormaDocOtprPost::ViborProducer(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducer==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
													(void**)&FormaSpiskaSprProducer);
		FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducer) return;
		FormaSpiskaSprProducer->Vibor=true;
		FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
		//FormaSpiskaSprProducer->UpdateForm();
		}
}
//---------------------------------------------------------------------------
void TREM_FormaDocOtprPost::EndViborProducer(void)
{
	DM->Doc->Edit();
	DM->DocIDPRODUCER_REM_DOTPRPOST->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->DocNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;

	DM->Doc->Post();

FormaSpiskaSprProducer=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//void TREM_FormaDocZakazPost::OpenFormSpiskaSprNomZak(void)
//{
//if(Prosmotr==true) return;
//if (Nom==NULL)
//		{
//		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprNom,IID_IFormaSpiskaSprNom,
//													(void**)&Nom);
//		Nom->Init(InterfaceMainObject,InterfaceImpl);
//		Nom->Vibor=true;
//		Nom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DZAKPOST->AsString);
////        Nom->SpisokTypePrice->ItemIndex=Nom->DM->GetIndexTypePrice()-1;
////		Nom->HintLabel->Caption="�������� ������������ ��� ��������� ��������� ��������� �"
////		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
//		Nom->IdNom=glStrToInt64(DM->DocTIDNOMZ_REM_DZAKPOSTT->AsString);
//		Nom->UpdateForm();
//		Nom->NumberProcVibor=ER_ViborNomZak;
//		}
//}
//---------------------------------------------------------------------------
//void TREM_FormaDocZakazPost::EndViborNomZak(void)
//{
//
//				if (ActionOperation==aoAddNewString)
//						{
//						DM->TableAppend();
//						}
//				DM->DocT->Edit();
//				DM->DocTIDNOMZ_REM_DZAKPOSTT->AsString=Nom->DM->ElementIDNOM->AsString;
//				DM->DocTNAMENOM_ZAK->AsString=Nom->DM->ElementNAMENOM->AsString;
//				if (DM->DocTKOLZ_REM_DZAKPOSTT->AsFloat > 0.001)  //������ ����������
//					{ //�� ��������
//					}
//				else
//					{
//					DM->DocTKOLZ_REM_DZAKPOSTT->AsFloat=1;
//					}
//
//				DM->DocTIDEDZ_REM_DZAKPOSTT->AsString=Nom->DM->ElementIDOSNEDNOM->AsString;
//				DM->DocTNAMEED_ZAK->AsString=Nom->DM->OsnEdNAMEED->AsString;
//				DM->DocTKFZ_REM_DZAKPOSTT->AsFloat=Nom->DM->OsnEdKFED->AsFloat;
//
//
//				DM->DocTPRICEZ_REM_DZAKPOSTT->AsFloat=Nom->DM->ElementZNACH_PRICE->AsFloat
//														*DM->DocTKFZ_REM_DZAKPOSTT->AsFloat;
//
//
//				DM->DocT->Post();
//				//DBGrid1->SelectedField=DM->DocTKOLPRNT;
//				VibTovarId=glStrToInt64(Nom->DM->ElementIDNOM->AsString);
//				VibTovarIdGrp=glStrToInt64(Nom->DM->ElementIDGRPNOM->AsString);
//
//		Nom=0;
//
//}
//----------------------------------------------------------------------------

void TREM_FormaDocOtprPost::OpenFormGurCustQuery(void)
{
if(Prosmotr==true) return;
if (REM_FormaGurCustQuery==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurCustQueryDetal,IID_IREM_FormaGurCustQueryDetal,
													(void**)&REM_FormaGurCustQuery);
		REM_FormaGurCustQuery->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaGurCustQuery) return;
		REM_FormaGurCustQuery->Vibor=true;
		REM_FormaGurCustQuery->NumberProcVibor=ER_ViborCustomerQuery;
		//FormaSpiskaSprProducer->UpdateForm();
		}


}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::EndViborCustQuery(void)
{

				DM->DocT->Edit();
				DM->DocTIDCQT_REM_DOTPRPOSTT->AsString=REM_FormaGurCustQuery->DM->TableID_REM_CQUERYT->AsString;
				DM->DocTNUM_REM_CQUERY->AsString=REM_FormaGurCustQuery->DM->TableNUM_REM_CQUERY->AsString;
                DM->DocT->Post();

}
//----------------------------------------------------------------------------











void __fastcall TREM_FormaDocOtprPost::cxDBButtonEditNAME_SBRANDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborBrand();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::cxDBButtonEditNAME_SPRODUCERPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{
ViborProducer();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::cxGrid1DBTableView1NUM_REM_CQUERYPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{
OpenFormGurCustQuery();
}
//---------------------------------------------------------------------------


//����� ������������
void TREM_FormaDocOtprPost::ViborProducerNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprProducerNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducerNom,IID_IFormaSpiskaSprProducerNom,
													(void**)&FormaSpiskaSprProducerNom);
		FormaSpiskaSprProducerNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprProducerNom) return;
		FormaSpiskaSprProducerNom->Vibor=true;
//		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DREMONT->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="�������� ������������ ��� ��������� ������ �"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" �� "+DM->DocAllPOS_REM_GALLDOC->AsString;
//		FormaSpiskaSprProducerNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_CQUERYT->AsString);
		FormaSpiskaSprProducerNom->UpdateForm();
		FormaSpiskaSprProducerNom->NumberProcVibor=ER_ViborProducerNom;
		}
}
//----------------------------------------------------------------------------
void TREM_FormaDocOtprPost::EndViborProducerNom(void)
{

                DM->DocT->Edit();
				DM->DocTIDPRNOM_REM_DOTPRPOSTT->AsString=FormaSpiskaSprProducerNom->DM->ElementID_SPRNOM->AsString;
				DM->DocTNAME_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementNAME_SPRNOM->AsString;

				DM->DocTART_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementART_SPRNOM->AsString;
				DM->DocTFL_DOSTUPNO_SPRNOM->AsString=FormaSpiskaSprProducerNom->DM->ElementFL_DOSTUPNO_SPRNOM->AsString;
				DM->DocT->Post();


		FormaSpiskaSprProducerNom=0;


}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocOtprPost::cxGrid1DBTableView1NAME_SPRNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerNom();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocOtprPost::ToolButtonAddPriceIsNomProducerClick(TObject *Sender)

{

 if (Prosmotr==true)
        {
		UpdateForm();
         return;
		}

//�������� ���� �� ������
if(DM->DocT->RecordCount>0)
		{

				IDMSprProducerNom * dm;
				InterfaceGlobalCom->kanCreateObject(ProgId_DMSprProducerNom,IID_IDMSprProducerNom,
													(void**)&dm);
				dm->Init(InterfaceMainObject,InterfaceImpl);
				DM->DocT->First();
				while(!DM->DocT->Eof)
						{
						DM->DocT->Edit();
						dm->OpenElement(glStrToInt64(DM->DocTIDPRNOM_REM_DOTPRPOSTT->AsString));
						DM->DocTPRICE_REM_DOTPRPOSTT->AsFloat=dm->ElementPRICE_ZAKUP_SPRNOM->AsFloat;
						DM->DocT->Post();
						DM->DocT->Next();
						}
				dm->kanRelease();

		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonSynchroSNomClick(TObject *Sender)

{
if (glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString)==0)
	{
	ShowMessage("���������� ������� ����������!");
	return;
	}

int type_poisk=0;
IDMSprKlient * klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&klient);
klient->Init(InterfaceMainObject,InterfaceImpl);
klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));
type_poisk=klient->ElementTYPE_POISK_SKLIENT->AsInteger;
klient->kanRelease();

if (type_poisk==0)
		{
		ShowMessage("���������� ������ ��� ������ ������������ � ����������� ������������!");
		return;
		}

if (type_poisk==1)
		{
		ShowMessage("�� ���� �� ����!");
		return;
		}


IDMSprImportNom * dm_import_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);

DM->DocT->First();
while (!DM->DocT->Eof)
	{
	__int64 id_nom=0;


	if (type_poisk==2)
		{
		if(Trim(DM->DocTNAME_SPRNOM->AsString)!="")
			{//���� �� ������������
			UnicodeString name_n=Trim(DM->DocTNAME_SPRNOM->AsString);

			//name_n="��������� ������� Explay B200 ׸����";
			//ShowMessage("�����-"+IntToStr(name_n.Length())+" "+name_n );
			id_nom=dm_import_nom->FindNomPoName(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString),
													name_n);
			}

		}

	//�� ��������
	if (type_poisk==3)
		{
		if(Trim(DM->DocTART_SPRNOM->AsString)!="")
			{//���� �� ��������
			id_nom=dm_import_nom->FindNomPoArtikulu(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString),
															Trim(DM->DocTART_SPRNOM->AsString));
			}
		}


	if(id_nom!=0)
		{
		DM->DocT->Edit();
		IDMSprNom * dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
		dm_nom->OpenElement(id_nom);
		DM->DocTIDNOM_REM_DOTPRPOSTT->AsString=id_nom;
		DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
		DM->DocTARTNOM->AsString=dm_nom->ElementARTNOM->AsString;
		DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
		DM->DocTIDED_REM_DOTPRPOSTT->AsString=dm_nom->ElementIDOSNEDNOM->AsString;
		DM->DocTNAMEED->AsString=dm_nom->OsnEdNAMEED->AsString;
		DM->DocTKF_REM_DOTPRPOSTT->AsFloat=dm_nom->OsnEdKFED->AsFloat;
		dm_nom->kanRelease();
		DM->DocT->Post();
		}
	DM->DocT->Next();
	}
dm_import_nom->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonAddNomNeSynchroClick(TObject *Sender)

{
//bool fl_model=true;
//DM->DocT->First();
//
//while(!DM->DocT->Eof)
//		{
//		if (glStrToInt64(DM->DocTIDNOM_REM_DZAKPOSTT->AsString)==0
//				&& Trim(DM->DocTNAME_REM_SPRMODEL->AsString)=="")
//			{
//			fl_model=false;
//			}
//        DM->DocT->Next();
//		}
//if (fl_model==false)
//	{
//	ShowMessage("���������� ������ ������ ���� ������������� (� ������� ���������)!");
//	return;
//	}


AnsiString text_error="";
IDMSprGrpNom *dm_grp_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom,
													(void**)&dm_grp_nom);
		dm_grp_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom *dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprEd * dm_spr_ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_spr_ed);
		dm_spr_ed->Init(InterfaceMainObject,InterfaceImpl);
IDMSprImportNom * dm_import_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
		dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_grp=0;
int type_poisk=0;
//�������� ���� �� ������ ���� ��������� ������

IDMSprKlient * klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&klient);
klient->Init(InterfaceMainObject,InterfaceImpl);
klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));
id_grp=glStrToInt64(klient->ElementIDGRPNOM_SKLIENT->AsString);
type_poisk=klient->ElementTYPE_POISK_SKLIENT->AsInteger;
klient->kanRelease();
if (id_grp==0)
	{
	id_grp=dm_grp_nom->FindPoName(Trim(DM->DocNAME_SPRODUCER->AsString));
	if (id_grp==0)
		{
		dm_grp_nom->NewElement(0);
		dm_grp_nom->ElementNAMEGN->AsString=Trim(DM->DocNAME_SPRODUCER->AsString);
		dm_grp_nom->SaveElement();
		id_grp=dm_grp_nom->ElementIDGN->AsInt64;
		}
	}


try
	{

DM->DocT->First();

while(!DM->DocT->Eof)
		{
		//AnsiString code=dc->Values[i][1];
		__int64 id_nom=glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString);

		if(id_nom==0) //������� ����� ������������
			{
			dm_nom->NewElement(id_grp);
			dm_nom->Element->Edit();
			dm_nom->ElementTNOM->AsInteger=0;
			dm_nom->ElementNAMENOM->AsString=DM->DocNAME_SPRODUCER->AsString+
									" "+DM->DocTMODEL_STR_SPRNOM->AsString+
									" "+DM->DocTNAME_SPRNOM->AsString+
									" "+DM->DocTART_SPRNOM->AsString;
			UnicodeString   kr_name=dm_nom->ElementNAMENOM->AsString;
			dm_nom->ElementKRNAMENOM->AsString=kr_name.SetLength(40);
			dm_nom->ElementFNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
			dm_nom->ElementARTNOM->AsString=DM->DocTART_SPRNOM->AsString;
			dm_nom->Element->Post();

			if (dm_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������������: "+dm_nom->TextError+"\n";
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}

			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_spr_ed->NewElement(glStrToInt64(dm_nom->ElementIDNOM->AsString));
				}
			else
				{
				dm_spr_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
				}
			dm_spr_ed->Element->Edit();

			dm_spr_ed->ElementNAMEED->AsString="��.";
			dm_spr_ed->Element->Post();

			if (dm_spr_ed->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������� ���������: "+dm_spr_ed->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}

			dm_nom->Element->Edit();
			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_nom->ElementIDBASEDNOM->AsString=dm_spr_ed->ElementIDED->AsString;
				}
			dm_nom->ElementIDOSNEDNOM->AsString=glStrToInt64(dm_spr_ed->ElementIDED->AsString);
			dm_nom->Element->Post();

			if (dm_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������������ ����� �������� ������� �������: "+dm_nom->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}
			id_nom=glStrToInt64(dm_nom->ElementIDNOM->AsString);




			__int64 id_import=0;

			//���� ���� ������� ������� ��� ������������� ������
			//��� ��� ���� �� �������, ������ ���, ���� ��������� �����


			if (id_import==0)
			{
			dm_import_nom->NewElement(id_nom);
			dm_import_nom->Element->Edit();
			dm_import_nom->ElementNAME_SIMPORTNOM->AsString=DM->DocTNAME_SPRNOM->AsString;
			//dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			dm_import_nom->ElementART_SIMPORTNOM->AsString=DM->DocTART_SPRNOM->AsString;
			dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
			dm_import_nom->Element->Post();
			if (dm_import_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����������� ������ ������������: "+dm_import_nom->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}
			}


			//���������� ������ ������� �������
			//����� �� ��������� �.�. ��� �������� ��
			DM->DocT->Edit();
			DM->DocTIDNOM_REM_DOTPRPOSTT->AsString=id_nom;
			DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
			DM->DocTARTNOM->AsString=dm_nom->ElementNAMENOM->AsString;
			DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
			DM->DocTIDED_REM_DOTPRPOSTT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
			DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;

			DM->DocT->Post();

			}
		DM->DocT->Next();
		}

	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}

dm_import_nom->kanRelease();
dm_spr_ed->kanRelease();
dm_nom->kanRelease();
dm_grp_nom->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonOpenCustQueryClick(TObject *Sender)

{

__int64 id_cq=glStrToInt64(DM->DocTID_REM_CQUERY->AsString);


IREM_FormaCustQuery * REM_FormaCustQuery;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaCustQuery,IID_IREM_FormaCustQuery,
								 (void**)&REM_FormaCustQuery);
REM_FormaCustQuery->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaCustQuery) return;
REM_FormaCustQuery->DM->OpenDoc(id_cq);
REM_FormaCustQuery->UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonSetPredvZakNumDateZakClick(TObject *Sender)

{
IREM_DMCustQuery *dm_cq;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMCustQuery,IID_IREM_DMCustQuery, (void**)&dm_cq);
dm_cq->Init(InterfaceMainObject,InterfaceImpl);


	DM->DocT->First();

	while (!DM->DocT->Eof)
		{
		dm_cq->OpenDoc(glStrToInt64(DM->DocTID_REM_CQUERY->AsString));

		dm_cq->Doc->Edit();
		dm_cq->DocRUN_REM_CQUERY->AsInteger=5; /*���������� �����������*/
		dm_cq->DocOTPRAVLENO_REM_CQUERY->AsDateTime=DM->DocAllPOS_REM_GALLDOC->AsDateTime;
		dm_cq->Doc->Post();
		dm_cq->SaveDoc();

		DM->DocT->Next();
		}


dm_cq->kanRelease();

}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonCreateDocPrihNaklClick(TObject *Sender)

{
IREM_FormaDocPrihNakl * doc;

//���� ��������� ����� ��� ����

DM->pFIBQ->Close();
DM->pFIBQ->SQL->Clear();
DM->pFIBQ->SQL->Add("select rem_galldoc.id_rem_galldoc from rem_galldoc");
DM->pFIBQ->SQL->Add(" where rem_galldoc.iddocosn_rem_galldoc=:PARAM_IDDOC and  rem_galldoc.tdoc_rem_galldoc='REMPRN'");
DM->pFIBQ->ParamByName("PARAM_IDDOC")->AsString=DM->DocAllID_REM_GALLDOC->AsString;
DM->pFIBQ->ExecQuery();

__int64 id_doc=glStrToInt64(DM->pFIBQ->FieldByName("id_rem_galldoc")->AsString);



InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPrihNakl,IID_IREM_FormaDocPrihNakl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);
if (!doc) return;

bool fl_create_doc=true;

if (id_doc > 0)
{
		UnicodeString V="��������� ��������� ��� ����, ������� ��� ����?";
		UnicodeString Z="������������� �������� ���������";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{
				fl_create_doc=true;
				}
		else
			{
			fl_create_doc=false;
			}
}



if (fl_create_doc == false)
		{
		 //������� ��������
		doc->DM->OpenDoc(id_doc);
		doc->UpdateForm();
		}


if (fl_create_doc == true)
		{
		//�������� ��������
		doc->DM->NewDoc();
		doc->DM->DocAll->Edit();

		doc->DM->DocAllIDDOCOSN_REM_GALLDOC->AsString=DM->DocAllID_REM_GALLDOC->AsString;


		doc->DM->DocAllIDBASE_REM_GALLDOC->AsString=DM->DocAllIDBASE_REM_GALLDOC->AsString;
		doc->DM->DocAllNAME_SINFBASE_OBMEN->AsString=DM->DocAllNAME_SINFBASE_OBMEN->AsString;
		doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=DM->DocAllIDFIRM_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEFIRM->AsString=DM->DocAllNAMEFIRM->AsString;
		doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsInteger=DM->DocAllIDSKLAD_REM_GALLDOC->AsInteger;
		doc->DM->DocAllNAMESKLAD->AsString=DM->DocAllNAMESKLAD->AsString;
		doc->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=DM->DocAllIDKLIENT_REM_GALLDOC->AsString;
		doc->DM->DocAllNAMEKLIENT->AsString=DM->DocAllNAMEKLIENT->AsString;
		doc->DM->DocAll->Post();

		doc->DM->Doc->Edit();
		doc->DM->DocIDTPRICE_REM_DPRN->AsString=DM->DocIDTPRICE_REM_DOTPRPOST->AsString;
		doc->DM->DocPRIM_REM_DPRN->AsString="�� ��������� �������� �����������(������) �"+DM->DocAllNUM_REM_GALLDOC->AsString+
								" �� "+ DM->DocAllPOS_REM_GALLDOC->AsString;
		doc->DM->Doc->Post();

		DM->DocT->First();
		while(!DM->DocT->Eof)
			{
			int kol=1;
			if (doc->DM->DocTFL_ADD_IN_SOBORUD_SNOM->AsInteger==1)
				{
				kol=DM->DocTKOL_REM_DOTPRPOSTT->AsFloat;
				}

			while(kol>0)
				{
				doc->DM->DocT->Append();
				doc->DM->DocTIDNOM_REM_DPRNT->AsString=DM->DocTIDNOM_REM_DOTPRPOSTT->AsString;
				doc->DM->DocTNAMENOM->AsString=DM->DocTNAMENOM->AsString;
				doc->DM->DocTIDED_REM_DPRNT->AsString=DM->DocTIDED_REM_DOTPRPOSTT->AsString;
				doc->DM->DocTNAMEED->AsString=DM->DocTNAMEED->AsString;

				if (doc->DM->DocTFL_ADD_IN_SOBORUD_SNOM->AsInteger==1)
					{
					doc->DM->DocTKOL_REM_DPRNT->AsFloat=1;
					}
				else
					{
					doc->DM->DocTKOL_REM_DPRNT->AsFloat=DM->DocTKOL_REM_DOTPRPOSTT->AsFloat;
					}

				doc->DM->DocTKF_REM_DPRNT->AsFloat=DM->DocTKF_REM_DOTPRPOSTT->AsFloat;
				doc->DM->DocTPRICE_REM_DPRNT->AsFloat=DM->DocTPRICE_REM_DOTPRPOSTT->AsFloat;

				doc->DM->DocTIDCQT_REM_DPRNT->AsString=DM->DocTIDCQT_REM_DOTPRPOSTT->AsString;
				doc->DM->DocTNUM_REM_CQUERY->AsString=DM->DocTNUM_REM_CQUERY->AsString;
				doc->DM->DocTPOS_REM_CQUERY->AsString=DM->DocTPOS_REM_CQUERY->AsString;
				doc->DM->DocTKLIENT_NAME_REM_CQUERY->AsString=DM->DocTKLIENT_NAME_REM_CQUERY->AsString;
				doc->DM->DocTNAME_MODEL_REM_CQUERY->AsString=DM->DocTIDCQT_REM_DOTPRPOSTT->AsString;
				doc->DM->DocTNUM_STR_ZAK_POST_REM_CQUERY->AsString=DM->DocTNUM_STR_ZAK_POST_REM_CQUERY->AsString;


				doc->DM->DocTPREFIKS_NUM_REM_Z->AsString=DM->DocTPREFIKS_NUM_REM_Z->AsString;
				doc->DM->DocTNUM_REM_Z->AsString=DM->DocTNUM_REM_Z->AsString;
				doc->DM->DocTPOS_REM_Z->AsString=DM->DocTPOS_REM_Z->AsString;
				doc->DM->DocTMODEL_REM_Z->AsString=DM->DocTMODEL_REM_Z->AsString;
				doc->DM->DocTSERNUM_REM_Z->AsString=DM->DocTSERNUM_REM_Z->AsString;
				doc->DM->DocTSERNUM2_REM_Z->AsString=DM->DocTSERNUM2_REM_Z->AsString;
				doc->DM->DocTSTR_CODE_VIGR_REM_Z_1->AsString=DM->DocTSTR_CODE_VIGR_REM_Z_1->AsString;

				doc->DM->DocT->Post();

				kol--;
				}
			DM->DocT->Next();
			}
		doc->UpdateForm();
		}






}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonAddStringClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableAppend();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocOtprPost::ToolButtonAddNeSynchroNomTecStrClick(TObject *Sender)

{
//bool fl_model=true;
//DM->DocT->First();
//
//while(!DM->DocT->Eof)
//		{
//		if (glStrToInt64(DM->DocTIDNOM_REM_DZAKPOSTT->AsString)==0
//				&& Trim(DM->DocTNAME_REM_SPRMODEL->AsString)=="")
//			{
//			fl_model=false;
//			}
//		DM->DocT->Next();
//		}
//if (fl_model==false)
//	{
//	ShowMessage("���������� ������ ������ ���� ������������� (� ������� ���������)!");
//	return;
//	}


AnsiString text_error="";
IDMSprGrpNom *dm_grp_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom,
													(void**)&dm_grp_nom);
		dm_grp_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprNom *dm_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
		dm_nom->Init(InterfaceMainObject,InterfaceImpl);
IDMSprEd * dm_spr_ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_spr_ed);
		dm_spr_ed->Init(InterfaceMainObject,InterfaceImpl);
IDMSprImportNom * dm_import_nom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprImportNom.1",IID_IDMSprImportNom,
													(void**)&dm_import_nom);
		dm_import_nom->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_grp=0;
int type_poisk=0;
//�������� ���� �� ������ ���� ��������� ������

IDMSprKlient * klient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient,
													(void**)&klient);
klient->Init(InterfaceMainObject,InterfaceImpl);
klient->OpenElement(glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString));
id_grp=glStrToInt64(klient->ElementIDGRPNOM_SKLIENT->AsString);
type_poisk=klient->ElementTYPE_POISK_SKLIENT->AsInteger;
klient->kanRelease();
if (id_grp==0)
	{

	ShowMessage("���������� ������ � ����������� ������ ������������, ���� ��������� ������!");
	return;

	}


try
	{


		//AnsiString code=dc->Values[i][1];
		__int64 id_nom=glStrToInt64(DM->DocTIDNOM_REM_DOTPRPOSTT->AsString);

		if(id_nom==0) //������� ����� ������������
			{
			dm_nom->NewElement(id_grp);
			dm_nom->Element->Edit();
			dm_nom->ElementTNOM->AsInteger=0;
			UnicodeString name=DM->DocNAME_SPRODUCER->AsString+
									" "+DM->DocTMODEL_STR_SPRNOM->AsString+
									" "+DM->DocTNAME_SPRNOM->AsString+
									" "+DM->DocTART_SPRNOM->AsString;
			if (name.Length() > 200 )name.SetLength(200);
			dm_nom->ElementNAMENOM->AsString=name;

			UnicodeString   kr_name=dm_nom->ElementNAMENOM->AsString;
			dm_nom->ElementKRNAMENOM->AsString=kr_name.SetLength(40);
			dm_nom->ElementFNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
			dm_nom->ElementARTNOM->AsString=DM->DocTART_SPRNOM->AsString;
			dm_nom->Element->Post();

			if (dm_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������������: "+dm_nom->TextError+"\n";
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}

			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_spr_ed->NewElement(glStrToInt64(dm_nom->ElementIDNOM->AsString));
				}
			else
				{
				dm_spr_ed->OpenElement(glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString));
				}
			dm_spr_ed->Element->Edit();

			dm_spr_ed->ElementNAMEED->AsString="��.";
			dm_spr_ed->Element->Post();

			if (dm_spr_ed->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������� ���������: "+dm_spr_ed->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}

			dm_nom->Element->Edit();
			if (glStrToInt64(dm_nom->ElementIDBASEDNOM->AsString)==0)
				{
				dm_nom->ElementIDBASEDNOM->AsString=dm_spr_ed->ElementIDED->AsString;
				}
			dm_nom->ElementIDOSNEDNOM->AsString=glStrToInt64(dm_spr_ed->ElementIDED->AsString);
			dm_nom->Element->Post();

			if (dm_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����� ������������ ����� �������� ������� �������: "+dm_nom->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}
			id_nom=glStrToInt64(dm_nom->ElementIDNOM->AsString);




			__int64 id_import=0;

			//���� ���� ������� ������� ��� ������������� ������
			//��� ��� ���� �� �������, ������ ���, ���� ��������� �����


			if (id_import==0)
			{
			dm_import_nom->NewElement(id_nom);
			dm_import_nom->Element->Edit();
			dm_import_nom->ElementNAME_SIMPORTNOM->AsString=DM->DocTNAME_SPRNOM->AsString;
			//dm_import_nom->ElementCODE_SIMPORTNOM->AsString=dc->Values[i][cxGrid1BandedTableView1CODENOM->Index];
			dm_import_nom->ElementART_SIMPORTNOM->AsString=DM->DocTART_SPRNOM->AsString;
			dm_import_nom->ElementIDKLIENT_SIMPORTNOM->AsString=glStrToInt64(DM->DocAllIDKLIENT_REM_GALLDOC->AsString);
			dm_import_nom->Element->Post();
			if (dm_import_nom->SaveElement()==false)
				{
				text_error="������ ��� ������ ����������� ������ ������������: "+dm_import_nom->TextError;
				text_error=text_error+" ������������: "+DM->DocTNAME_SPRNOM->AsString;
				throw Exception(text_error,0);
				}
			}


			//���������� ������ ������� �������
			//����� �� ��������� �.�. ��� �������� ��
			DM->DocT->Edit();
			DM->DocTIDNOM_REM_DOTPRPOSTT->AsString=id_nom;
			DM->DocTNAMENOM->AsString=dm_nom->ElementNAMENOM->AsString;
			DM->DocTARTNOM->AsString=dm_nom->ElementNAMENOM->AsString;
			DM->DocTCODENOM->AsString=dm_nom->ElementCODENOM->AsString;
			DM->DocTIDED_REM_DOTPRPOSTT->AsString=dm_nom->ElementIDBASEDNOM->AsString;
			DM->DocTNAMEED->AsString=dm_nom->BasEdNAMEED->AsString;

			DM->DocT->Post();

			}


	}
catch(Exception &exception)
		{
		ShowMessage(exception.Message);
		}

dm_import_nom->kanRelease();
dm_spr_ed->kanRelease();
dm_nom->kanRelease();
dm_grp_nom->kanRelease();
}
//---------------------------------------------------------------------------

