//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//--------------------------------------------------------------------------
#include "UREM_FormaDocZOper.h"
#include "IDMSprPrice.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSprPrice.h"
#include "IFormaRunExternalModule.h"
#include "IFormaDocReal.h"
#include "IFormaDocRealRozn.h"
#include "IFormaDocCheck.h"
#include "IDMSetup.h"
#include "IREM_DMZayavka.h"
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
#pragma link "cxGridBandedTableView"
#pragma link "cxGridDBBandedTableView"
#pragma link "cxLookAndFeels"
#pragma link "cxImageComboBox"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TREM_FormaDocZOper::TREM_FormaDocZOper(TComponent* Owner)
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
bool TREM_FormaDocZOper::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZOper,IID_IREM_DMDocZOper, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBBandedTableView1->DataController->DataSource=DM->DataSourceDocT;

DBTextFNameUser->DataSource=DM->DataSourceDocAll;

NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NumDoccxDBTextEdit->DataBinding->DataSource=DM->DataSourceDocAll;
PosDoccxDBDateEdit->DataBinding->DataSource=DM->DataSourceDocAll;

NameKlientcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameProjectcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;
NameBusinessOpercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDocAll;

//��������� ��� ���
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice, (void**)&DMSprTypeRPrice);
DMSprTypeRPrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypeRPrice->OpenTable();

TypePricecxDBLookupComboBox->DataBinding->DataSource=DM->DataSourceDoc;
TypePricecxDBLookupComboBox->Properties->ListSource=DMSprTypeRPrice->DataSourceTable;

NameZcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceDoc;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceDoc;

NameKlientcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
ModelcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
NumZcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;
SerNum2cxDBLabel->DataBinding->DataSource=DM->DataSourceDoc;


Prosmotr=false;    //������ ��������
IdDoc=0;           //������������� ������� ������
VibTovarId=0;
VibTovarIdGrp=0;
ActionOperation=aoNO;





//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm,
									 (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);

DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TREM_FormaDocZOperImpl),false);
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
int TREM_FormaDocZOper::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaDocZOper::UpdateForm(void)
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


}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormaSpiskaSprEd)FormaSpiskaSprEd->kanRelease();
if(FormaSpiskaSprNom)FormaSpiskaSprNom->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurZ)FormaGurZ->kanRelease();
if(FormaSpiskaSprHardware)FormaSpiskaSprHardware->kanRelease();
if(SpisokBusinessOper)SpisokBusinessOper->kanRelease();
if(SpisokProject)SpisokProject->kanRelease();

if(FormaSpiskaSprStorageLocation)FormaSpiskaSprStorageLocation->kanRelease();
if(FormaSpiskaSprTypeNom)FormaSpiskaSprTypeNom->kanRelease();
if (FormaSpiskaSprTypUslov>0) FormaSpiskaSprTypUslov->kanRelease();

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
DMSprTypeRPrice->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaDocZOper::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==ER_InfBase)
		{
		if (type_event==1)
				{
				EndViborInfBase();
				}
		FormaSpiskaSprInfBase=0;
		}

if (number_procedure_end==ER_Firm)
		{
		if (type_event==1)
				{
				EndViborFirm();
				}
		FormaSpiskaSprFirm=0;
		}

if (number_procedure_end==ER_Sklad)
		{
		if (type_event==1)
				{
				EndViborSklad();
				}
		FormaSpiskaSprSklad=0;
		}

if (number_procedure_end==ER_Klient)
		{
		if (type_event==1)
				{
				EndViborKlient();
				}
		FormaSpiskaSprKlient=0;
		}

if (number_procedure_end==ER_Zayavka)
		{
		if (type_event==1)
				{
				EndViborRemZ();
				}
		FormaGurZ=0;
		}

if (number_procedure_end==ER_Nom)
		{
		if (type_event==1)
				{
				EndViborNom();
				}
		FormaSpiskaSprNom=0;
		}

if (number_procedure_end==ER_Ed)
		{
		if (type_event==1)
				{
				EndViborEd();
				}
		FormaSpiskaSprEd=0;
		}


if (number_procedure_end==ER_Hardware)
		{
		if (type_event==1)
				{
				EndViborHardware();
				}
		FormaSpiskaSprHardware=0;
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

if (number_procedure_end==ER_ViborStorageLocation)
		{
		if (type_event==1)
				{
				EndViborStorageLocation()  ;
                }
		FormaSpiskaSprStorageLocation=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}


if (number_procedure_end==ER_ViborTypeNom)
		{
		if (type_event==1)
				{
				EndViborTypeNom()  ;
				}
		FormaSpiskaSprTypeNom=0;
		FindNextControl(ActiveControl,true,true,false)->SetFocus();
		}



if (number_procedure_end==ER_ViborHWOld)
		{
		if (type_event==1)
				{
				EndViborHardwareOld();
				}
		FormaSpiskaSprHardware=0;
		}

if (number_procedure_end==ER_ViborHWDonor)
		{
		if (type_event==1)
				{
				EndViborHardwareDonor();
				}
		FormaSpiskaSprHardware=0;
		}


if ( number_procedure_end==ER_ViborTypUsla)
	{
	if (type_event==1)
		{
		EndViborTypUsla();
		}
	FormaSpiskaSprTypUslov=0;
	}

return -1;
}
//---------------------------------------------------------------------------
//����� �������������� ����
void TREM_FormaDocZOper::ViborInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_REM_GALLDOC->ReadOnly==true) return;
if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprInfBase) return;
		FormaSpiskaSprInfBase->NumberProcVibor=ER_InfBase;
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		} 
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborInfBase(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBASE_REM_GALLDOC->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsString;
	DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
	DM->DocAll->Post();

FormaSpiskaSprInfBase=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------
//����� �����
void TREM_FormaDocZOper::ViborFirm(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprFirm) return;
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->DM->OpenTable();
		//FormaSpiskaSprFirm->HintLabel->Caption="�������� ����� ��� ��������� ������ ������������ �"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" �� "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprFirm->NumberProcVibor=ER_Firm;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborFirm(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDFIRM_REM_GALLDOC->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
	DM->DocAllNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
	DM->DocAll->Post();

FormaSpiskaSprFirm=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();  
}
//----------------------------------------------------------------------------
//����� ������
void TREM_FormaDocZOper::ViborSklad(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprSklad) return;
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->DM->OpenTable();
		//FormaSpiskaSprSklad->HintLabel->Caption="�������� ����� ��� ��������� ������ ������������ �"
		//+DM->DocAllNUM_REM_GALLDOC->AsString+" �� "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprSklad->NumberProcVibor=ER_Sklad;
		}
}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborSklad(void)
{


	DM->DocAll->Edit();
	DM->DocAllIDSKLAD_REM_GALLDOC->AsString=FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
	DM->DocAllNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
	DM->DocAll->Post();
	UpdateForm();

FormaSpiskaSprSklad=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//����� �������
void TREM_FormaDocZOper::ViborKlient(void)
{
if (Prosmotr==true) return;
if (FormaSpiskaSprKlient==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
		FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprKlient) return;
		FormaSpiskaSprKlient->Vibor=true;
		FormaSpiskaSprKlient->NumberProcVibor=ER_Klient;
		FormaSpiskaSprKlient->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborKlient(void)
{
if (FormaSpiskaSprKlient==0) return;


				DM->DocAll->Edit();
				DM->DocAllIDKLIENT_REM_GALLDOC->AsString=FormaSpiskaSprKlient->DM->ElementIDKLIENT->AsString;
				DM->DocAllNAMEKLIENT->AsString=FormaSpiskaSprKlient->DM->ElementNAMEKLIENT->AsString;
				DM->DocAll->Post();

		FormaSpiskaSprKlient=0;

FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
//����� ������
void TREM_FormaDocZOper::ViborRemZ(void)
{
if(Prosmotr==true) return;
if (FormaGurZ==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaGurZ.1",IID_IREM_FormaGurZ,
													(void**)&FormaGurZ);
		FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaGurZ) return;
		FormaGurZ->Vibor=true;
		FormaGurZ->NumberProcVibor=ER_Zayavka;
		}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborRemZ(void)
{

	DM->Doc->Edit();
	DM->DocIDZ_REM_DZOPER->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->DocNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->DocKLIENT_NAME_REM_Z->AsString=FormaGurZ->DM->TableKLIENT_NAME_REM_Z->AsString;
	DM->DocMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;
	DM->DocNUM_REM_Z->AsString=FormaGurZ->DM->TableNUM_REM_Z->AsString;
	DM->DocPOS_REM_Z->AsString=FormaGurZ->DM->TablePOS_REM_Z->AsString;
	DM->DocSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->DocSERNUM2_REM_Z->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;
	DM->Doc->Post();
	UpdateForm();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();


}
//----------------------------------------------------------------------------
//����� ������������
void TREM_FormaDocZOper::ViborNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
													(void**)&FormaSpiskaSprNom);
		FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprNom) return;
		FormaSpiskaSprNom->Vibor=true;
		FormaSpiskaSprNom->DM->IdTypePrice=glStrToInt64(DM->DocIDTPRICE_REM_DZOPER->AsString);
//		FormaSpiskaSprNom->SpisokTypePrice->ItemIndex=FormaSpiskaSprNom->DM->GetIndexTypePrice()-1;
//		FormaSpiskaSprNom->HintLabel->Caption="�������� ������������ ��� ��������� ������ �"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" �� "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprNom->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZOPERT->AsString);
		FormaSpiskaSprNom->UpdateForm();
		FormaSpiskaSprNom->NumberProcVibor=ER_Nom;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborNom(void)
{

                if (ActionOperation==aoAddNewString)
						{
						DM->TableAppend();
						}
                DM->DocT->Edit();
				DM->DocTIDNOM_REM_DZOPERT->AsString=FormaSpiskaSprNom->DM->ElementIDNOM->AsString;
				DM->DocTNAMENOM->AsString=FormaSpiskaSprNom->DM->ElementNAMENOM->AsString;
			 //	DM->DocTTNOM->AsInteger=FormaSpiskaSprNom->DM->ElementTNOM->AsInteger;
				DM->DocTKOL_REM_DZOPERT->AsInteger=1;


				DM->DocTIDED_REM_DZOPERT->AsString=FormaSpiskaSprNom->DM->ElementIDOSNEDNOM->AsString;
				DM->DocTNAMEED->AsString=FormaSpiskaSprNom->DM->OsnEdNAMEED->AsString;
				DM->DocTKF_REM_DZOPERT->AsFloat=FormaSpiskaSprNom->DM->OsnEdKFED->AsFloat;

					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZOPERT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZOPER->AsString), //��� ���
											glStrToInt64(DM->DocTIDNOM_REM_DZOPERT->AsString),            //������������
											glStrToInt64(DM->DocTIDED_REM_DZOPERT->AsString),             //�������
											DM->DocTKF_REM_DZOPERT->AsFloat,                              //�����������
											glStrToInt64(FormaSpiskaSprNom->DM->ElementIDBASEDNOM->AsString));            //������� �������
					DMSprPrice->kanRelease();

				DM->DocTIDMHRAN_REM_DZOPERT->AsString=FormaSpiskaSprNom->DM->TableOUT_IDMHRAN->AsString;
				DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprNom->DM->TableOUT_NAME_MHRAN->AsString;
				DM->DocTIDTNOM_REM_DZOPERT->AsString=FormaSpiskaSprNom->DM->TableIDTNOM->AsString;
				DM->DocTNAME_STNOM->AsString=FormaSpiskaSprNom->DM->TableNAME_STNOM->AsString;

				DM->DocT->Post();
				VibTovarId=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDNOM->AsString);
				VibTovarIdGrp=glStrToInt64(FormaSpiskaSprNom->DM->ElementIDGRPNOM->AsString);

		FormaSpiskaSprNom=0;
		cxGrid1->SetFocus();
		cxGrid1DBBandedTableView1KOL_REM_DZOPERT->Selected=true;

ActionOperation=aoNO;		
}
//----------------------------------------------------------------------------
//����� �������
void TREM_FormaDocZOper::ViborEd(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprEd==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprEd.1",IID_IFormaSpiskaSprEd,
													(void**)&FormaSpiskaSprEd);
		FormaSpiskaSprEd->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprEd) return;
		FormaSpiskaSprEd->Vibor=true;
		FormaSpiskaSprEd->IdNom=glStrToInt64(DM->DocTIDNOM_REM_DZOPERT->AsString);
		FormaSpiskaSprEd->DM->OpenTable(glStrToInt64(DM->DocTIDNOM_REM_DZOPERT->AsString));
//		FormaSpiskaSprEd->LabelNom->Caption="������� ������������: "+DM->DocTNAMENOM->AsString;
//		FormaSpiskaSprEd->HintLabel->Caption="�������� ������� ������������ ��� ��������� ������ �"
//		+DM->DocAllNUM_REM_GALLDOC->AsString+" �� "+DM->DocAllPOS_REM_GALLDOC->AsString;
		FormaSpiskaSprEd->NumberProcVibor=ER_Ed;
		}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborEd(void)
{


	DM->DocT->Edit();
	DM->DocTIDED_REM_DZOPERT->AsString=FormaSpiskaSprEd->DM->ElementIDED->AsString;
	DM->DocTNAMEED->AsString=FormaSpiskaSprEd->DM->ElementNAMEED->AsString;
	DM->DocTKF_REM_DZOPERT->AsFloat=FormaSpiskaSprEd->DM->ElementKFED->AsFloat;


					IDMSprPrice * DMSprPrice;
					InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
					DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);

					DM->DocTPRICE_REM_DZOPERT->AsFloat=
							DMSprPrice->GetValuePrice(glStrToInt64(DM->DocIDTPRICE_REM_DZOPER->AsString), //��� ���
											glStrToInt64(DM->DocTIDNOM_REM_DZOPERT->AsString),            //������������
											glStrToInt64(DM->DocTIDED_REM_DZOPERT->AsString),             //�������
											DM->DocTKF_REM_DZOPERT->AsFloat,                              //�����������
											0);            //������� �������
					DMSprPrice->kanRelease();


	DM->DocT->Post();

	FormaSpiskaSprEd=0;
	cxGrid1->SetFocus();
	cxGrid1DBBandedTableView1PRICE_REM_DZOPERT->Selected=true;
}

//----------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NumberDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::FDateDocKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::PrimKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN) FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();
}
//---------------------------------------------------------------------------





void __fastcall TREM_FormaDocZOper::TypeRPriceComboBoxPropertiesChange(
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

void __fastcall TREM_FormaDocZOper::PosDoccxDBDateEditPropertiesChange(
      TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborFirm();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborInfBase();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSklad();
FindNextControl((TWinControl *) Sender,true,true,false)->SetFocus();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaDocZOper::ActionAddStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
ViborNom();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::ActionDeleteStringExecute(TObject *Sender)
{
if(Prosmotr==true) return;
DM->TableDelete();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NumDoccxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::PosDoccxDBDateEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZOper::PrimcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}

//----------------------------------------------------------------------------
void TREM_FormaDocZOper::BeforeSaveDoc(void)
{
//if (DM->DocAllPOSDOC->AsDateTime > Date())
//	{
//	AnsiString V="����� ���� �������� ������������������ ���������� ����������! �������� ����� ��������� �� �������?";
//	String Z="��������!";
//	if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
//		{
//		DM->DocAll->Edit();
//		DM->DocAllPOSDOC->AsDateTime=Now();
//		DM->DocAll->Post();
//		}
//	}

}
//----------------------------------------------------------------------------




// if (Prosmotr==true)
//		{
//		UpdateForm();
//		 return;
//		}
////
////�������� ���� �� ������
//if(DM->DocT->RecordCount>0)
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
//						DM->DocTS_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // ��� ���
//														DM->DocTS_IDNOM_DZAMENAT->AsInt64,         //������������
//														DM->DocTS_IDED_DZAMENAT->AsInt64,   //�������
//														DM->DocTS_KF_DZAMENAT->AsFloat,     //�� �������
//														0);                                  //������� �������
//
//						DM->DocTP_RPRICE_DZAMENAT->AsFloat=DMSprPrice->GetValuePrice(
//														DM->DocIDRTPRICE_DZAMENA->AsInt64,           // ��� ���
//														DM->DocTP_IDNOM_DZAMENAT->AsInt64,         //������������
//														DM->DocTP_IDED_DZAMENAT->AsInt64,   //�������
//														DM->DocTP_KF_DZAMENAT->AsFloat,     //�� �������
//														0);                                  //������� �������
//						DM->DocT->Post();
//						DM->DocT->Next();
//						}
//				delete DMSprPrice;
//				}
//		}







void __fastcall TREM_FormaDocZOper::NameKlientcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKlient();	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::NameZcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborRemZ();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZOper::cxGrid1DBTableView1NAMEEDPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborEd();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
		DM->DocAll->CancelUpdates();
		DM->Doc->CancelUpdates();
		DM->DocT->CancelUpdates();
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::ActionOKExecute(TObject *Sender)
{
if(Prosmotr==true) return;
TypeEvent=1;
if (DM->SaveDoc()==true)
		{
        AfterSaveDoc();
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

void __fastcall TREM_FormaDocZOper::ActionDvRegExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
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

void __fastcall TREM_FormaDocZOper::ActionSaveExecute(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		AfterSaveDoc();
		UpdateForm();
		}
else
	{
	ShowMessage("������ ��� ������ ���������: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
//������� ������
void __fastcall TREM_FormaDocZOper::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TREM_FormaDocZOper::RunExternalModule(__int64 id_module, int type_module)
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
module->SetStringVariables("glUserName", DM_Connection->UserInfoFNAME_USER->AsString);


module->ExecuteModule();
}
//---------------------------------------------------------------------------



void TREM_FormaDocZOper::AfterSaveDoc(void)
{


}
//-----------------------------------------------------------------------------

void TREM_FormaDocZOper::ViborHardware(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_Hardware;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaDocZOper::EndViborHardware(void)
{

	DM->DocT->Edit();
	DM->DocTIDHW_REM_DZOPERT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTNAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;

}
//----------------------------------------------------------------------------


void TREM_FormaDocZOper::OpenFormSpiskaSprProject(void)
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
void  TREM_FormaDocZOper::EndViborProject(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDPROJECT_REM_GALLDOC->AsString=SpisokProject->DM->TableID_SPROJECT->AsString;
	DM->DocAllNAME_SPROJECT->AsString=SpisokProject->DM->TableNAME_SPROJECT->AsString;
	DM->DocAll->Post();




}
//----------------------------------------------------------------------------
void TREM_FormaDocZOper::OpenFormSpiskaSprBusinessOper(void)
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
void TREM_FormaDocZOper::EndViborBusinessOper(void)
{

	DM->DocAll->Edit();
	DM->DocAllIDBUSINOP_REM_GALLDOC->AsString=SpisokBusinessOper->DM->TableID_SBUSINESS_OPER->AsString;
	DM->DocAllNAME_SBUSINESS_OPER->AsString=SpisokBusinessOper->DM->TableNAME_SBUSINESS_OPER->AsString;
	DM->DocAll->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::NameBusinessOpercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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

void __fastcall TREM_FormaDocZOper::NameProjectcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
void  TREM_FormaDocZOper::ViborStorageLocation(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprStorageLocation==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprStorageLocation,IID_IFormaSpiskaSprStorageLocation,
													(void**)&FormaSpiskaSprStorageLocation);
		FormaSpiskaSprStorageLocation->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprStorageLocation->Vibor=true;
		FormaSpiskaSprStorageLocation->IdGroupElement=glStrToInt64(DM->DocAllIDSKLAD_REM_GALLDOC->AsString);
		FormaSpiskaSprStorageLocation->IdElement=glStrToInt64(DM->DocTIDMHRAN_REM_DZOPERT->AsString);
		FormaSpiskaSprStorageLocation->UpdateForm();
//        Sklad->HintLabel->Caption="�������� ����� ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprStorageLocation->NumberProcVibor=ER_ViborStorageLocation;

		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocZOper::EndViborStorageLocation(void)
{

DM->DocT->Edit();

DM->DocTIDMHRAN_REM_DZOPERT->AsString=FormaSpiskaSprStorageLocation->DM->TableID_SMHRAN->AsString;
DM->DocTNAME_SMHRAN->AsString=FormaSpiskaSprStorageLocation->DM->TableNAME_SMHRAN->AsString;

DM->DocT->Post();

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborStorageLocation();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDMHRAN_REM_DZOPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void  TREM_FormaDocZOper::ViborTypeNom(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprTypeNom==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprTypeNom,IID_IFormaSpiskaSprTypeNom,
													(void**)&FormaSpiskaSprTypeNom);
		FormaSpiskaSprTypeNom->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprTypeNom->Vibor=true;
		//FormaSpiskaSprTypeNom->IdElement=glStrToInt64(DM->DocTIDTNOM_DREALT->AsString);
	  //	FormaSpiskaSprTypeNom->UpdateForm();
//        Sklad->HintLabel->Caption="�������� ����� ��� ��������� ��������� ��������� �"
//		+DM->DocAllNUMDOC->AsString+" �� "+DM->DocAllPOSDOC->AsString;
		FormaSpiskaSprTypeNom->NumberProcVibor=ER_ViborTypeNom;

		}

}
//---------------------------------------------------------------------------
void TREM_FormaDocZOper::EndViborTypeNom(void)
{

DM->DocT->Edit();

DM->DocTIDTNOM_REM_DZOPERT->AsString=FormaSpiskaSprTypeNom->DM->TableID_STNOM->AsString;
DM->DocTNAME_STNOM->AsString=FormaSpiskaSprTypeNom->DM->TableNAME_STNOM->AsString;

DM->DocT->Post();

}
//-----------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1NAME_STNOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypeNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDTNOM_REM_DZOPERT->Clear();
		DM->DocTNAME_STNOM->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborHardware();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDHW_REM_DZOPERT->Clear();
		DM->DocTNAME_REM_SHARDWARE->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{


switch (AButtonIndex)
	{
	case 0:
		{
		ViborNom();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDNOM_REM_DZOPERT->Clear();
		DM->DocTNAMENOM->AsString="";
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::ToolButtonAddStringClick(TObject *Sender)
{
DM->DocT->Append();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborHardwareDonor();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDHW_DONOR_REM_DZOPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{

switch (AButtonIndex)
	{
	case 0:
		{
		ViborHardwareOld();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDHWOLD_REM_DZOPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaDocZOper::ViborHardwareOld(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHWOld;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//--------------------------------------------------------------------------
void TREM_FormaDocZOper::EndViborHardwareOld(void)
{
	DM->DocT->Edit();
	DM->DocTIDHWOLD_REM_DZOPERT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTOLD_NAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;
}
//---------------------------------------------------------------------------

void TREM_FormaDocZOper::ViborHardwareDonor(void)
{
if(Prosmotr==true) return;
if (FormaSpiskaSprHardware==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprHardware.1",IID_IREM_FormaSpiskaSprHardware,
													(void**)&FormaSpiskaSprHardware);
		FormaSpiskaSprHardware->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaSpiskaSprHardware) return;
		FormaSpiskaSprHardware->Vibor=true;
		FormaSpiskaSprHardware->NumberProcVibor=ER_ViborHWDonor;
		FormaSpiskaSprHardware->UpdateForm();
		}

}
//--------------------------------------------------------------------------
void TREM_FormaDocZOper::EndViborHardwareDonor(void)
{
	DM->DocT->Edit();
	DM->DocTIDHW_DONOR_REM_DZOPERT->AsString=FormaSpiskaSprHardware->DM->TableID_REM_SHARDWARE->AsString;
	DM->DocTDONOR_NAME_REM_SHARDWARE->AsString=FormaSpiskaSprHardware->DM->TableNAME_REM_SHARDWARE->AsString;
	DM->DocT->Post();

FormaSpiskaSprHardware=0;
}
//---------------------------------------------------------------------------
void TREM_FormaDocZOper::ViborTypUsla(void)
{
if (FormaSpiskaSprTypUslov>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypUslov,IID_IREM_FormaSpiskaSprTypUslov,
												 (void**)&FormaSpiskaSprTypUslov);
FormaSpiskaSprTypUslov->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprTypUslov->flVibor=true;
FormaSpiskaSprTypUslov->NumberProcVibor=ER_ViborTypUsla;
FormaSpiskaSprTypUslov->IdElement=glStrToInt64(DM->DocTIDTYP_USEL_REM_DZOPERT->AsString);
FormaSpiskaSprTypUslov->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::EndViborTypUsla(void)
{

	DM->DocT->Edit();
	DM->DocTIDTYP_USEL_REM_DZOPERT->AsString=FormaSpiskaSprTypUslov->DM->TableID_REM_STYPUSLOV->AsString;
	DM->DocTNAME_REM_STYPUSLOV->AsString=FormaSpiskaSprTypUslov->DM->TableNAME_REM_STYPUSLOV->AsString;
	DM->DocT->Post();

}
///-------------------------------------------------------------------------
void __fastcall TREM_FormaDocZOper::cxGrid1DBBandedTableView1NAME_REM_STYPUSLOVPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypUsla();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->DocT->Edit();
		DM->DocTIDTYP_USEL_REM_DZOPERT->Clear();
		DM->DocT->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

