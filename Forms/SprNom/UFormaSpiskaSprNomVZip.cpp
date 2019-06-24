//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprNomVZip.h"
#include "IFormaElementaSprNom.h"
#include "IFormaElementaSprGrpNom.h"
#include "IDMSprTypePrice.h"
#include "IDMSprSezKF.h"
#include "IDMSprNomRest.h"
#include "IDMSprMod.h"
#include "IDMSprSostProd.h"
#include "IDMSprSezKFSProd.h"
#include "IDMSprEd.h"
//#include "UScaner.h"
#include "ISheetEditor.h"
#include "IDMSprBVNom.h"
#include "IDMSprVesNom.h"
#include "IFormaSpiskaSprNacenka.h"
#include "IDMSprGrpVesNom.h"
#include "IDMUserSetup.h"

#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IObjectBarCode.h"
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
__fastcall TFormaSpiskaSprNomVZip::TFormaSpiskaSprNomVZip(TComponent* Owner)
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
bool TFormaSpiskaSprNomVZip::Init(void)
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
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNomVZip,IID_IDMSprNomVZip, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;

Podbor=false;
FlagOstatok=false;
OnlyChange=false;
OnlyOstatok=false;
PriceSklad=false;
DM->SpTPrice->Active=true;

SpisokTypePrice->Properties->Items->Clear();
DM->SpTPrice->First();
while (!DM->SpTPrice->Eof)
        {
		SpisokTypePrice->Properties->Items->Add(DM->SpTPriceNAME_TPRICE->AsString);
        DM->SpTPrice->Next();
		}

LabelNameGrp->Caption="������������\\...";
HintLabel->Caption="";
LabelFirma->Caption="";
LabelSklad->Caption="";
LabelInetCatalog->Caption="";
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm, (void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSklad.1",IID_IDMSprSklad, (void**)&DMSprSklad);
DMSprSklad->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprInetCatalog,IID_IDMSprInetCatalog, (void**)&DMSprInetCatalog);
DMSprInetCatalog->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprScale.1",IID_IDMSprScale, (void**)&DMSprScale);
DMSprScale->Init(InterfaceMainObject,InterfaceImpl);

IdFirm=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
NameFirm=DM_Connection->UserInfoNAMEFIRM->AsString;


//�������� ������ ������� �������
InterfaceGlobalCom->kanCreateObject("Oberon.DMTableExtPrintForm.1",IID_IDMTableExtPrintForm, (void**)&DMTableExtPrintForm);
DMTableExtPrintForm->Init(InterfaceMainObject,InterfaceImpl);
DMTableExtPrintForm->OpenTable(StringToGUID(Global_CLSID_TFormaSpiskaSprNomVZipImpl),false);
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
int TFormaSpiskaSprNomVZip::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::UpdateForm(void)
{
if(Vibor==true)
	{
	cxButtonVibor->Visible=true;
	}
else
	{
	cxButtonVibor->Visible=false;
	}

if (IdNom>0)
        {
		IdGrp=DM->GetIdGrpNom(IdNom);
		}


DM->DataSourceTable->Enabled=false;
//SpisokTypePrice->ItemIndex=DM->GetIndexTypePrice()-1;
if (IdFirm==0)
	{
	DM->IdFirm=DM_Connection->UserInfoIDFIRM_USER->AsInt64;
	}
else
	{
	DM->IdFirm=IdFirm;
	}
if (IdSklad==0)
	{
	DM->IdSklad=DM_Connection->UserInfoIDSKLAD_USER->AsInt64;
	}
else
	{
	DM->IdSklad=IdSklad;
	}

//DM->IdInetCatalog=IdInetCatalog;
	
DM->CheckOst=FlagOstatok;
DM->OnlyChange=OnlyChange;
DM->OnlyOstatok=OnlyOstatok;
DM->PriceSklad=PriceSklad;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("OUT_IDNOM",IdNom,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;

		if (IdFirm==0)
			{
			LabelFirma->Caption="�����: "+DM_Connection->UserInfoNAMEFIRM->AsString;
			}
		else
			{
			LabelFirma->Caption="�����: "+NameFirm;
			}
			
		if (IdSklad==0)
			{
			LabelSklad->Caption="�����: "+DM_Connection->UserInfoNAMESKLAD->AsString;
			}
		else
			{
			LabelSklad->Caption="�����: "+NameSklad;
			}

		if (IdInetCatalog==0)
			{
			LabelInetCatalog->Caption="";
			}
		else
			{
			LabelInetCatalog->Caption="�������� �������: "+NameInetCatalog;
			}

if (FlagOstatok==true)
        {
		cxGrid1DBTableView1OUT_OST->Visible=true;
		}
else
        {
		cxGrid1DBTableView1OUT_OST->Visible=false;
		}

RegimLabel->Caption="";
AnsiString s="";

if (OnlyChange==true)
	{
	s=s+"\\������ ����������";
	}
if (OnlyOstatok==true)
	{
	s=s+"\\������ ������� ";
	}
if (PriceSklad==true)
	{
	s=s+"\\���� ������ ";
	}

RegimLabel->Caption=s;

DMSprScale->OpenTable();

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::UpdateDerevo()
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
		__int64 IDGrp=DMGrp->TableIDGRPGN->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableIDGN->AsInt64;
                         // ShowMessage(" ������� ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGN")->AsString, lpIDGrp);
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
void __fastcall TFormaSpiskaSprNomVZip::FormClose(TObject *Sender,
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


DMSprFirm->kanRelease();
DMSprSklad->kanRelease();
DMSprInetCatalog->kanRelease();
DMSprScale->kanRelease();
DM->kanRelease();
DMGrp->kanRelease();
DMTableExtPrintForm->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//-------------------------------------------------------------------------------
int TFormaSpiskaSprNomVZip::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{
if (number_procedure_end==1)//ViborGrp)
		{
        UpdateDerevo();
		}

if(number_procedure_end==2)//ViborElement)
		{
        cxGrid1->SetFocus();
        }

if(number_procedure_end==3)//RekvisitPodborNom)
        {
	   if (type_event==1)
				{
               if (Vibor==true)
                        {
						TypeEvent=1;
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
						}
                }
        else
				{
				TypeEvent=0;

				}
		FormaPodboraNom=0;
		}


if (DM_Connection->UserInfoREOPEN_SPR_SUSER->AsInteger==1)
	{
	UpdateForm();
	}
return -1;
}

//--------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormElement()
{

		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		FormaElementa->DM->OpenElement(glStrToInt64(DM->TableOUT_IDNOM->AsString));
		FormaElementa->IdTypePrice=IdTypePrice;
		FormaElementa->IdFirm=IdFirm;
		FormaElementa->NumberProcVibor=2;
		FormaElementa->IdGrpNom=IdGrp;
		FormaElementa->NameGrpNom=LabelNameGrp->Caption;
		FormaElementa->UpdateForm();
		IdNom=glStrToInt64(DM->TableOUT_IDNOM->AsString);
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormNewElement()
{

		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
										 (void**)&FormaElementa);
		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->IdTypePrice=IdTypePrice;
				FormaElementa->IdFirm=IdFirm;
				FormaElementa->IdGrpNom=IdGrp;
				FormaElementa->NameGrpNom=LabelNameGrp->Caption;
				FormaElementa->UpdateForm();
				FormaElementa->NumberProcVibor=2;
				IdNom=glStrToInt64(FormaElementa->DM->ElementIDNOM->AsString);
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}
}
//-------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormPodboraNom(void)
{
//if (FormaPodboraNom==0)
//		{
//		InterfaceGlobalCom->kanCreateObject("Oberon.FormaPodboraNom.1",IID_IFormaPodboraNom,
//										 (void**)&FormaPodboraNom);
//		FormaPodboraNom->Init(InterfaceMainObject,InterfaceImpl);
//		DM->OpenElement(glStrToInt64(DM->TableIDNOM->AsString));
//		FormaPodboraNom->IdNom=glStrToInt64(DM->ElementIDNOM->AsString);
//		FormaPodboraNom->NameNom=DM->ElementNAMENOM->AsString;
//		FormaPodboraNom->IdEd=DM->OsnEdIDED->AsInt64;
//		FormaPodboraNom->NameEd=DM->OsnEdNAMEED->AsString;
//		FormaPodboraNom->KFEd=DM->OsnEdKFED->AsFloat;
//		FormaPodboraNom->Kol=1;
//		FormaPodboraNom->PriceBasEd=DM->ElementZNACH_PRICE->AsFloat;
//		FormaPodboraNom->Price=FormaPodboraNom->PriceBasEd*FormaPodboraNom->KFEd;
//		FormaPodboraNom->Summa=FormaPodboraNom->Price*FormaPodboraNom->Kol;
//		FormaPodboraNom->UpdateForm();
//		FormaPodboraNom->NumberProcVibor=3;
//		}
//else
//		{
//		//ShowWindow(IdDochForm,SW_SHOWNA);
//		//SendMessage(IdDochForm,WM_ACTIVATE,0,0);
//		//SetForegroundWindow(IdDochForm);
//		}
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::DeleteElement()
{
//		String V="�� ������������� ������ ������� "
//		+DM->TableNAMENOM->AsString+"?";
//		String Z="������������� �������� ��������";
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
//				{
//				return;
//				}
//
//if(DM->DeleteNom(glStrToInt64(DM->TableIDNOM->AsString))!=true)
//	{
//	ShowMessage("�� ������� ������� ������� �����������!  ������: "+DM->TextError );
//	}
//
//
//DM->OpenTable(IdGrp,AllElement);
}

//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormGrpElement()
{

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprGrpNom * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpNom.1",IID_IFormaElementaSprGrpNom,
										 (void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
				FormaGrpElementa->NumberProcVibor=1;
				}
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormNewGrpElement()
{

		IFormaElementaSprGrpNom * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpNom.1",IID_IFormaElementaSprGrpNom,
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
		FormaGrpElementa->NumberProcVibor=1;

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::DeleteGrpElement()
{

        if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonNewClick(TObject *Sender)
{
OpenFormNewElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonEditClick(TObject *Sender)
{
OpenFormElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonDeleteClick(TObject *Sender)
{
DeleteElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdNom=glStrToInt64(DM->TableOUT_IDNOM->AsString);
		IdGrp=glStrToInt64(DM->TableOUT_IDGRPNOM->AsString);
        }
else
        {
        AllElement=true ;
		LabelNameGrp->Caption="��� ��������...";
		IdNom=glStrToInt64(DM->TableOUT_IDNOM->AsString);
		IdGrp=glStrToInt64(DM->TableOUT_IDGRPNOM->AsString);
        }
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::FormResize(TObject *Sender)
{

SpisokTypePrice->Left=cxGrid1->Left+cxGrid1->ClientWidth-SpisokTypePrice->Width;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonIsmGrpClick(TObject *Sender)
{
//if (cxTreeView1->Selected!=NULL)
//		{  //������������� �������
//		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
//		for(int i=0;i<AViewData->RowCount;i++)
//			{
//			if (AViewData->Records[i]->Selected==true)
//				{
//				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1IDNOM->Index];
//				DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data,id);
//				}
//			}
//		}
//DM->OpenTable(IdGrp,AllElement);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::FormActivate(TObject *Sender)
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

void __fastcall TFormaSpiskaSprNomVZip::FormDeactivate(TObject *Sender)
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
void __fastcall TFormaSpiskaSprNomVZip::ReadShtrihCodEvent(int number, UnicodeString sh)
{

AnsiString s=sh;

IObjectBarCode * ob_bar;
InterfaceGlobalCom->kanCreateObject("Oberon.ObjectBarCode.1",IID_IObjectBarCode,
													(void**)&ob_bar);
ob_bar->Init(InterfaceMainObject,InterfaceImpl);

IDMSprNom * dm_nom;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&dm_nom);
dm_nom->Init(InterfaceMainObject,InterfaceImpl);

IDMSprEd * dm_ed;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
													(void**)&dm_ed);
dm_ed->Init(InterfaceMainObject,InterfaceImpl);

ob_bar->SprNom=dm_nom;
ob_bar->SprEd=dm_ed;
ob_bar->IdTypePrice=0;
ob_bar->ObrabotatShtrihCod(sh);

if (ob_bar->OutReady==true)
	{
	IdNom=glStrToInt64(dm_nom->ElementIDNOM->AsString);
	UpdateForm();
	cxGrid1->SetFocus();
	}
else
	{
	 ShowMessage(ob_bar->TextError);
	}
ob_bar->kanRelease();
dm_nom->kanRelease();
dm_ed->kanRelease();


}
//---------------------------------------------------------------
//���������� �������� ������
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprBVClick(TObject *Sender)
{
//  if (((TMenuItem*)Sender)->MenuIndex < ((TPopupMenu*)((TMenuItem*)Sender)->Owner)->Items->Count - 1)
//        {
//        int i= ((TMenuItem*)Sender)->MenuIndex;
//        DMSprPodr->Table->First();
//        DMSprPodr->Table->MoveBy(i);
//        ShowMessage(IntToStr(i));
//        CreateExternalPrintForm(DMTableExtPrintForm->TableFILE_NAME_EXTPRINT_FORM->AsString);
//        }
   // SheetBook->History->Undo(((TMenuItem*)Sender)->MenuIndex + 1);
}
//------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprBVClickSubMenu(TObject *Sender)
{
//if (DM->TableIDNOM->AsInteger==0) return;
//		int i= ((TMenuItem*)Sender)->Tag;
//		DM->IBQSprGrpBV->First();
//		DM->IBQSprGrpBV->MoveBy(i-1);
//		//ShowMessage(DM->IBQSprGrpBVNAME_GBVNOM->AsString+" SubMenu "+IntToStr(i));
//		//�������� � ��� �� ��� ������ �������� ��� ����� �������������
//IDMSprBVNom * DMSprBVNom;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
//										 (void**)&DMSprBVNom);
//DMSprBVNom->Init(InterfaceMainObject,InterfaceImpl);
//if (DMSprBVNom->FindPoPodrAndNom(DM->IBQSprGrpBVIDPOD_GBVNOM->AsInt64,
//								glStrToInt64(DM->TableIDNOM->AsString)) ==true)
//		{
//		IDMSprGrpBVNom *DMSprGrpBVNom;
//		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpBVNom.1",IID_IDMSprGrpBVNom,
//										 (void**)&DMSprGrpBVNom);
//		DMSprGrpBVNom->Init(InterfaceMainObject,InterfaceImpl);
//		DMSprGrpBVNom->OpenElement(DMSprBVNom->ElementIDGRP_BVNOM->AsInt64);
//
//		String V="������ ������� ��� ������������ � ����������� �������� ������ � ������ "
//		+DMSprGrpBVNom->ElementNAME_GBVNOM->AsString+"! �������� ���?";
//		String Z="��������!";
//		DMSprGrpBVNom->kanRelease();
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
//				{
//				DMSprBVNom->kanRelease();
//				return;
//				}
//		}
////��������� �������
//DMSprBVNom->InsertElement(DM->IBQSprGrpBVIDPOD_GBVNOM->AsInt64,
//						  DM->IBQSprGrpBVID_GBVNOM->AsInt64,
//						  glStrToInt64(DM->TableIDNOM->AsString));
//
//
//DMSprBVNom->kanRelease();
}
//-----------------------------------------------------------------------------
//���������� ������� ������������
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprScalePopup(TObject *Sender)
{
////������� ����
//PopupMenuSprScale->Items->Clear();
//
////�������� ������ �������������
//DM->SprScaleAndGrpVesNom->Active=false;
//DM->SprScaleAndGrpVesNom->Active=true;
//__int64 id_tec_scale=0;
//TMenuItem *menu;
//TMenuItem *menu1;
//DM->SprScaleAndGrpVesNom->First();
//while ( !DM->SprScaleAndGrpVesNom->Eof)
//		{
//
//		if (DM->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM->AsInt64!=id_tec_scale)
//				{
//				id_tec_scale=DM->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM->AsInt64;
//				menu=new TMenuItem(PopupMenuSprScale);
//				menu->Caption=DM->SprScaleAndGrpVesNomNAME_SSCALE->AsString;
//				menu->OnClick = PopupMenuSprScaleClick;
//				PopupMenuSprScale->Items->Add(menu);
//				}
//
//	   // ShowMessage(DM->IBQSprGrpBVIDGRP_GBVNOM->AsString);
//		menu1=new TMenuItem(PopupMenuSprScale);
//		menu1->Caption=DM->SprScaleAndGrpVesNomNAME_SGRPVESNOM->AsString;
//		menu1->OnClick = PopupMenuSprScaleClickSubMenu;
//		menu1->Tag=DM->SprScaleAndGrpVesNom->RecNo;
//		menu->Insert(menu->Count,menu1);
//
//		DM->SprScaleAndGrpVesNom->Next();
//		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprScaleClick(TObject *Sender)
{
//

}
//--------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprScaleClickSubMenu(TObject *Sender)
{
//if (DM->TableIDNOM->AsInteger==0) return;
//		int i= ((TMenuItem*)Sender)->Tag;
//		DM->SprScaleAndGrpVesNom->First();
//		DM->SprScaleAndGrpVesNom->MoveBy(i-1);
//		//ShowMessage(DM->IBQSprGrpBVNAME_GBVNOM->AsString+" SubMenu "+IntToStr(i));
//		//�������� � ��� �� ��� ������ �������� ��� ����� �������������
//IDMSprVesNom * DMSprVesNom;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprVesNom.1",IID_IDMSprVesNom,
//										 (void**)&DMSprVesNom);
//DMSprVesNom->Init(InterfaceMainObject,InterfaceImpl);
//__int64 id_ves_nom=DMSprVesNom->FindElementPoScaleAndNom(DM->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM->AsInt64,
//								glStrToInt64(DM->TableIDNOM->AsString));
//if (id_ves_nom>0)
//		{
//		DMSprVesNom->OpenElement(id_ves_nom);
//		IDMSprGrpVesNom *DMSprGrpVesNom;
//		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpVesNom.1",IID_IDMSprGrpVesNom,
//										 (void**)&DMSprGrpVesNom);
//		DMSprGrpVesNom->Init(InterfaceMainObject,InterfaceImpl);
//		DMSprGrpVesNom->OpenElement(DMSprVesNom->ElementIDGRP_SVESNOM->AsInt64);
//
//		String V="������ ������� ��� ������������ � ����������� �������� ������ � ������ "
//		+DMSprGrpVesNom->ElementNAME_SGRPVESNOM->AsString+"! �������� ���?";
//		String Z="��������!";
//		DMSprGrpVesNom->kanRelease();
//
//		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
//				{
//				DMSprVesNom->kanRelease();
//				return;
//				}
//		}
////��������� �������
//DMSprVesNom->InsertElement(DM->SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM->AsInt64,
//						  DM->SprScaleAndGrpVesNomID_SGRPVESNOM->AsInt64,
//						  glStrToInt64(DM->TableIDNOM->AsString));
//
//
//DMSprVesNom->kanRelease();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButtonOstClick(TObject *Sender)
{
if (ToolButtonOst->Down==true)  // ��� �����
		{
		FlagOstatok=true;
		}
else
		{
		FlagOstatok=false;
		}

if (NoUpdateForm==false)
	{
	UpdateForm();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonPrintClick(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenPrintForm(void)
{
ISheetEditor  *PrintForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1",IID_ISheetEditor,
										 (void**)&PrintForm);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//�����
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

//������� ������������ � �������� ��������
TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM->Table->Database;
		query->Transaction=DM->IBTr;
		query->SQL->Add(" select CODENOM, NAMENOM, NAMEED, ZNACH_PRICE");
		query->SQL->Add(" from SNOM ");
		query->SQL->Add(" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(DM->SpTPriceID_TPRICE->AsInt64));
		query->SQL->Add(" left outer join SED on IDBASEDNOM=IDED");
		query->SQL->Add(" where IDGRPNOM IS NULL");
		query->SQL->Add(" ORDER BY NAMENOM");
		if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
		query->ExecQuery();
		while (!query->Eof)
			{
			OutputString( PrintForm,
						query->FieldByName("CODENOM")->AsString,
						query->FieldByName("NAMENOM")->AsString,
						query->FieldByName("NAMEED")->AsString,
						FloatToStrF(query->FieldByName("ZNACH_PRICE")->AsFloat,ffFixed,15,2));

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
void TFormaSpiskaSprNomVZip::CreateReport(ISheetEditor *prForm, __int64 id_grp)
{
TpFIBQuery * query=new TpFIBQuery(0);
try {    
		query->Database=DM->Table->Database;
		query->Transaction=DM->IBTr;
		if (id_grp==0)
			{
			query->SQL->Add(" select IDGN, NAMEGN");
			query->SQL->Add(" from SGRPNOM ");
			query->SQL->Add(" where IDGRPGN IS NULL");
			query->SQL->Add(" ORDER BY NAMEGN");
			}
		else
			{
			query->SQL->Add(" select IDGN, NAMEGN");
			query->SQL->Add(" from SGRPNOM ");
			query->SQL->Add(" where IDGRPGN="+IntToStr(id_grp));
			query->SQL->Add(" ORDER BY NAMEGN");
			}
		if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
		query->ExecQuery();

			while (!query->Eof)
				{
				OutputStringGrp( prForm,
						query->FieldByName("NAMEGN")->AsString);
				CreateReport(prForm, query->FieldByName("IDGN")->AsInt64);
				query->Next();
				}


				
				TpFIBQuery * query1=new TpFIBQuery(0);
				try {

					query1->Database=DM->Table->Database;
					query1->Transaction=DM->IBTr;
					query1->SQL->Add(" select CODENOM, NAMENOM, NAMEED, ZNACH_PRICE");
					query1->SQL->Add(" from SNOM ");
					query1->SQL->Add(" left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE="+IntToStr(DM->SpTPriceID_TPRICE->AsInt64));
					query1->SQL->Add(" left outer join SED on IDBASEDNOM=IDED");
					query1->SQL->Add(" where IDGRPNOM="+IntToStr(id_grp));
					query1->SQL->Add(" ORDER BY NAMENOM");
					if (DM->IBTr->Active==false) DM->IBTr->StartTransaction();
					query1->ExecQuery();
					while (!query1->Eof)
							{
							OutputString( prForm,
										query1->FieldByName("CODENOM")->AsString,
										query1->FieldByName("NAMENOM")->AsString,
										query1->FieldByName("NAMEED")->AsString,
										FloatToStrF(query1->FieldByName("ZNACH_PRICE")->AsFloat,ffFixed,15,2));

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
void TFormaSpiskaSprNomVZip::OutputZagolovokReport(ISheetEditor *prForm)
{

prForm->RowsAutoHeight=true;

prForm->SetColumnWidth(0,10);
prForm->SetColumnWidth(1,10);
prForm->SetColumnWidth(2,80);
prForm->SetColumnWidth(3,80);
prForm->SetColumnWidth(4,300);
prForm->SetColumnWidth(5,80);
prForm->SetColumnWidth(6,80);


prForm->TecCell_GetObject(3,numRow);
prForm->TecCell_SetFontSize(16);
prForm->TecCell_SetFontStyle(TFontStyles() << fsBold);
prForm->TecCell_SetText("������ � ������");
prForm->TecCell_DeleteObject();
numRow++;

}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OutputStringGrp(ISheetEditor *prForm,
											AnsiString name_grp)
{
numCol=2;


prForm->TecCell_GetObject(numCol, numRow);
//cell->Text=IntToStr(porNumStr);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
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
//cell->Text=name_ed;
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;


prForm->TecCell_GetObject(numCol, numRow);
//cell->Text=price;
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_SetBackgroundColor(34);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OutputString(ISheetEditor *prForm,
							AnsiString code_nom,
							AnsiString name_nom,
							AnsiString name_ed,
							AnsiString price)
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
prForm->TecCell_SetText(code_nom);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(name_nom);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetWordBreake(true);
prForm->TecCell_DeleteObject();
numCol++;


prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(name_ed);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haCENTER);
prForm->TecCell_DeleteObject();
numCol++;

prForm->TecCell_GetObject(numCol, numRow);
prForm->TecCell_SetText(price);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eLeft,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eRight,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eTop,ISheetEditor::lsThin);
prForm->TecCell_SetBordersEdgesStyle(ISheetEditor::eBottom,ISheetEditor::lsThin);
prForm->TecCell_SetHorzTextAlign(ISheetEditor::haRIGHT);
prForm->TecCell_DeleteObject();
numCol++;
numRow++;
porNumStr++;

}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OutputPodavalReport(ISheetEditor *prForm)
{

}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButton5Click(TObject *Sender)
{
OpenPrintFormOnlyGrp();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenPrintFormOnlyGrp(void)
{
__int64 id_grp=*(__int64*)cxTreeView1->Selected->Data;

ISheetEditor  *PrintForm;
InterfaceGlobalCom->kanCreateObject("Oberon.SheetEditor.1",IID_ISheetEditor,
										 (void**)&PrintForm);

if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//�����
PrintForm->BeginUpdate();
OutputZagolovokReport(PrintForm);

OutputStringGrp( PrintForm,cxTreeView1->Selected->Text);

CreateReport(PrintForm,id_grp);

OutputPodavalReport(PrintForm);
PrintForm->EndUpdate();

}
//-----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNom");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonCheckOnlyChangeClick(
      TObject *Sender)
{
if (ToolButtonCheckOnlyChange->Down==true)  // ��� �����
		{
		OnlyChange=true;
		}
else
		{
		OnlyChange=false;
		}

if (NoUpdateForm==false)
	{
	UpdateForm();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonClearChangeClick(TObject *Sender)
{
//if (DM->ClearFlagChange()==true)
//	{
//	ShowMessage("����� ��������� ���� ��������!");
//	}
//else
//	{
//	ShowMessage("�� ������� �������� ����� ���������! ������:  "+DM->TextError);
//	}
//UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonOpenSprNacenkaClick(
      TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		IFormaSpiskaSprNacenka * spr;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNacenka.1",IID_IFormaSpiskaSprNacenka,
														 (void**)&spr);
		spr->Init(InterfaceMainObject,InterfaceImpl);
		__int64 id_grp=*(__int64*)cxTreeView1->Selected->Data;;
		spr->DM->OpenTable(id_grp);
		//spr->UpdateForm();
		//spr->LabelGrpNom->Caption=cxTreeView1->Selected->Text;

		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprNomVZip::ToolButtonOnlyOstatokClick(TObject *Sender)
{
if (ToolButtonOnlyOstatok->Down==true)  // ������ �������
		{
		OnlyOstatok=true;
		}
else
		{
		OnlyOstatok=false;
		}

if (NoUpdateForm==false)
	{
	UpdateForm();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonPriceSkladClick(TObject *Sender)
{
 if (ToolButtonPriceSklad->Down==true)  // ���� ������
		{
		PriceSklad=true;
		}
else
		{
		PriceSklad=false;
		}

if (NoUpdateForm==false)
	{
	UpdateForm();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprFirmPopup(TObject *Sender)
{
PopupMenuSprFirm->Items->Clear();
//�������� ������ ����
//TDMSprFirm * DMSprScale=new TDMSprScale(Application);
DMSprFirm->OpenTable();

TMenuItem *menu;
DMSprFirm->Table->First();
while ( !DMSprFirm->Table->Eof)
		{
		menu=new TMenuItem(PopupMenuSprFirm);
		menu->Caption=DMSprFirm->TableNAMEFIRM->AsString;
		menu->OnClick = PopupMenuSprFirmClick;
		menu->Tag=DMSprFirm->TableIDFIRM->AsInt64;
		PopupMenuSprFirm->Items->Add(menu);
		DMSprFirm->Table->Next();
		}

//delete DMSprScale;
}

//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprFirmClick(TObject *Sender)
{
__int64 i= ((TMenuItem*)Sender)->Tag; //
IdFirm=i;

if (DMSprFirm->GetIndexElementaPoID(IdFirm)>0)
	{
	NameFirm=DMSprFirm->TableNAMEFIRM->AsString;
	}
	
UpdateForm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprSkladPopup(TObject *Sender)
{
PopupMenuSprSklad->Items->Clear();
//�������� ������ �����
//TDMSprFirm * DMSprScale=new TDMSprScale(Application);
DMSprSklad->OpenTable();

TMenuItem *menu;
DMSprSklad->Table->First();
while ( !DMSprSklad->Table->Eof)
		{
		menu=new TMenuItem(PopupMenuSprSklad);
		menu->Caption=DMSprSklad->TableNAMESKLAD->AsString;
		menu->OnClick = PopupMenuSprSkladClick;
		menu->Tag=glStrToInt64(DMSprSklad->TableIDSKLAD->AsString);
		PopupMenuSprSklad->Items->Add(menu);
		DMSprSklad->Table->Next();
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprSkladClick(TObject *Sender)
{
__int64 i= ((TMenuItem*)Sender)->Tag; //
IdSklad=i;
if (DMSprSklad->GetIndexElementaPoID(IdSklad)>0)
	{
	NameSklad=DMSprSklad->TableNAMESKLAD->AsString;
	if (DMSprSklad->TableTSKLAD->AsInteger==1)
		{
		NameSklad=NameSklad+" (����.)";
		}
	else
		{
		NameSklad=NameSklad+" (���.)";
		}
	}

UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::cxTreeView1DblClick(TObject *Sender)
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


void __fastcall TFormaSpiskaSprNomVZip::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{
		if (Podbor==true)
				{
				OpenFormPodboraNom();
				}
		else
				{
				TypeEvent=1;
				//DM->OpenElement(glStrToInt64(DM->TableIDNOM->AsString));
				Close();
				}
		}
else
		{
		IdNom=glStrToInt64(DM->TableOUT_IDNOM->AsString);
		OpenFormElement();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{
				if (Podbor==true)
						{
						OpenFormPodboraNom();
						}
				else
						{
						TypeEvent=1;
						//DM->OpenElement(glStrToInt64(DM->TableIDNOM->AsString));
						Close();
						}
				}
		else
				{
				OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprNomVZip::cxTreeView1KeyDown(TObject *Sender,
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



void __fastcall TFormaSpiskaSprNomVZip::ToolButton6Click(TObject *Sender)
{
IdNom=glStrToInt64(DM->TableOUT_IDNOM->AsString);
UpdateForm();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//������� ������
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuExtModuleClick(TObject *Sender)
{
int i= ((TMenuItem*)Sender)->MenuIndex;
DMTableExtPrintForm->Table->First();
DMTableExtPrintForm->Table->MoveBy(i);
RunExternalModule(glStrToInt64(DMTableExtPrintForm->TableID_EXTPRINT_FORM->AsString),
					DMTableExtPrintForm->TableTYPEMODULE_EXTPRINT_FORM->AsInteger);
}
//----------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::RunExternalModule(__int64 id_module, int type_module)
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
	module->SetInt64Variables("glIdNom", glStrToInt64(DM->TableOUT_IDNOM->AsString));
	module->SetInt64Variables("glIdTypePrice", DM->IdTypePrice);
	module->SetInt64Variables("glIdFirm", IdFirm);
	module->SetInt64Variables("glIdSklad", IdSklad);
	module->SetInt64Variables("glIdGrpNom", IdGrp);
	}
	
module->ExecuteModule();


if (type_module==1 || type_module==2)
	{
//	delete scr_doc;
//	delete module;
	}


}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::OpenFormNewCopyElement()
{

		IFormaElementaSprNom * FormaElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprNom.1",IID_IFormaElementaSprNom,
													(void**)&FormaElementa);

		FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
		if (FormaElementa->DM->NewElement(IdGrp)==true)
				{
				FormaElementa->NumberProcVibor=2;

				IDMSprNom * n;
				InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
													(void**)&n);
				n->Init(InterfaceMainObject,InterfaceImpl);
				n->OpenElement(glStrToInt64(DM->TableOUT_IDNOM->AsString));
				FormaElementa->DM->Element->Edit();
				FormaElementa->DM->ElementTNOM->AsString=
												n->ElementTNOM->AsString;
				FormaElementa->DM->ElementARTNOM->AsString=
												n->ElementARTNOM->AsString;
				FormaElementa->DM->ElementNAMENOM->AsString=
												n->ElementNAMENOM->AsString;
				FormaElementa->DM->ElementFNAMENOM->AsString=
												n->ElementFNAMENOM->AsString;
				FormaElementa->DM->ElementKRNAMENOM->AsString=
												n->ElementKRNAMENOM->AsString;
				FormaElementa->DM->ElementDESCR_SNOM->AsString=
												n->ElementDESCR_SNOM->AsString;
				FormaElementa->DM->ElementIDFIRMNOM->AsString=
												n->ElementIDFIRMNOM->AsString;
				FormaElementa->DM->ElementNAMEFIRM->AsString=
												n->ElementNAMEFIRM->AsString;
				FormaElementa->DM->ElementIDCOUNTRYNOM->AsString=
												n->ElementIDCOUNTRYNOM->AsString;
				FormaElementa->DM->ElementNAME_SCOUNTRY->AsString=
												n->ElementNAME_SCOUNTRY->AsString;
				n->kanRelease();

				FormaElementa->DM->Element->Post();
				FormaElementa->IdTypePrice=IdTypePrice;
				FormaElementa->IdFirm=IdFirm;
				FormaElementa->UpdateForm();
				}
		else
				{
				FormaElementa->kanRelease();
				ShowMessage(FormaElementa->DM->TextError);
				}

}
//--------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ToolButtonCopyRecordClick(TObject *Sender)
{
OpenFormNewCopyElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);

dm->SaveSetupInt("FormaSpiskaSprNom","IndexTypePrice", SpisokTypePrice->ItemIndex);
dm->SaveSetupInt64("FormaSpiskaSprNom","IdFirm",IdFirm);
dm->SaveSetup("FormaSpiskaSprNom","NameFirm",NameFirm);
dm->SaveSetupInt64("FormaSpiskaSprNom","IdSklad",IdSklad);
dm->SaveSetup("FormaSpiskaSprNom","NameSklad",NameSklad);
dm->SaveSetupBool("FormaSpiskaSprNom","FlagOstatok",FlagOstatok);
dm->SaveSetupBool("FormaSpiskaSprNom","OnlyChange",OnlyChange);
dm->SaveSetupBool("FormaSpiskaSprNom","OnlyOstatok",OnlyOstatok);
dm->SaveSetupBool("FormaSpiskaSprNom","PriceSklad",PriceSklad);

dm->SaveSetupBool("FormaSpiskaSprNom","AllElement",AllElement);
dm->SaveSetupInt64("FormaSpiskaSprNom","IdInetcatalog",IdInetCatalog);
dm->SaveSetup("FormaSpiskaSprNom","NameInetCatalog",NameInetCatalog);
dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprNomVZip::LoadFormSetup(void)
{
NoUpdateForm=true;

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);

SpisokTypePrice->ItemIndex=dm->LoadSetupInt("FormaSpiskaSprNom","IndexTypePrice");


DM->SpTPrice->First();
DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;

IdFirm=dm->LoadSetupInt64("FormaSpiskaSprNom","IdFirm");
NameFirm=dm->LoadSetup("FormaSpiskaSprNom","NameFirm");
IdSklad=dm->LoadSetupInt64("FormaSpiskaSprNom","IdSklad");
NameSklad=dm->LoadSetup("FormaSpiskaSprNom","NameSklad");

IdInetCatalog=dm->LoadSetupInt64("FormaSpiskaSprNom","IdInetCatalog");
NameInetCatalog=dm->LoadSetup("FormaSpiskaSprNom","NameInetCatalog");

FlagOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","FlagOstatok");
ToolButtonOst->Down=FlagOstatok;

OnlyChange=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyChange");
ToolButtonCheckOnlyChange->Down=OnlyChange;

OnlyOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyOstatok");
ToolButtonOnlyOstatok->Down=OnlyOstatok;

PriceSklad=dm->LoadSetupBool("FormaSpiskaSprNom","PriceSklad");
ToolButtonPriceSklad->Down=PriceSklad;

AllElement=dm->LoadSetupBool("FormaSpiskaSprNom","AllElement");
ToolButtonAll->Down=AllElement;
dm->kanRelease();

NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::ToolButton7Click(TObject *Sender)
{
SaveFormSetup();	
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprNomVZip::SpisokTypePricePropertiesValidate(
      TObject *Sender, Variant &DisplayValue, TCaption &ErrorText, bool &Error)
{
		DM->SpTPrice->First();
		DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
		DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::cxButtonViborClick(TObject *Sender)
{
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		TcxGridViewData * AViewData=cxGrid1DBTableView1->ViewData;
		for(int i=0;i<AViewData->RowCount;i++)
			{
			if (AViewData->Records[i]->Selected==true)
				{
				__int64 id=AViewData->Records[i]->Values[cxGrid1DBTableView1OUT_IDNOM->Index];
				IdNom=id;
				TypeEvent=2;
				i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
				}
			}

		}
	i_callback->kanRelease();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprInetCatalogPopup(TObject *Sender)
{
PopupMenuSprInetCatalog->Items->Clear();
//�������� ������ ����
//TDMSprFirm * DMSprScale=new TDMSprScale(Application);
DMSprInetCatalog->OpenTable();

TMenuItem *menu;
DMSprInetCatalog->Table->First();
while ( !DMSprInetCatalog->Table->Eof)
		{
		menu=new TMenuItem(PopupMenuSprInetCatalog);
		menu->Caption=DMSprInetCatalog->TableNAME_SINETCATALOG->AsString;
		menu->OnClick = PopupMenuSprInetCatalogClick;
		menu->Tag=glStrToInt64(DMSprInetCatalog->TableID_SINETCATALOG->AsString);
		PopupMenuSprInetCatalog->Items->Add(menu);
		DMSprInetCatalog->Table->Next();
		}

//delete DMSprScale;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::PopupMenuSprInetCatalogClick(TObject *Sender)
{
__int64 i= ((TMenuItem*)Sender)->Tag; //
IdInetCatalog=i;
if (DMSprInetCatalog->GetIndexElementaPoID(IdInetCatalog)>0)
	{
	NameInetCatalog=DMSprInetCatalog->TableNAME_SINETCATALOG->AsString;
	}

UpdateForm();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprNomVZip::cxGrid1DBTableView1ID_SNOMINETCATCustomDrawCell(TcxCustomGridTableView *Sender,
          TcxCanvas *ACanvas, TcxGridTableDataCellViewInfo *AViewInfo,
          bool &ADone)
{
if(IdInetCatalog > 0)
	{
UnicodeString ATextToDraw;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

__int64 id=glStrToInt64(ATextToDraw);

TRect ARec = AViewInfo->Bounds;
Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (id > 0)
	{
	ToolBar1->Images->GetBitmap(60,ABitmap);
	}
else
	{

	}
ACanvas->Canvas->FillRect(ARec);
ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
ABitmap->Free();
ADone = true;
	}
}
//---------------------------------------------------------------------------

