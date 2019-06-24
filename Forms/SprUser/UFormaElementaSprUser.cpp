//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprUser.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IB_Services"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxPC"
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxGroupBox"
#pragma link "cxRadioGroup"
#pragma link "cxSpinEdit"
#pragma link "cxCheckBox"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprUser::TFormaElementaSprUser(TComponent* Owner)
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

bool TFormaElementaSprUser::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprUser.1",IID_IDMSprUser, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

IdDBText->DataSource=DM->DataSourceElement;
NameKassacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
Name2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FNamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameInfcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NamePodcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameBSchetcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKassacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameTPricecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

TPosGournalcxDBRadioGroup->DataBinding->DataSource=DM->DataSourceElement;
TPosReportcxDBRadioGroup->DataBinding->DataSource=DM->DataSourceElement;

KolDayGurcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;
KolDayRepcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;

ReOpenSprcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
ReOpenGurcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
EditChugDoccxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
DelChugDoccxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
ShowLogcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
DetailedLogcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

SaveNamecxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

NameTPrice1Edit->Text="";
NameTPrice2Edit->Text="";

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaElementaSprUser::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprUser::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprTypePrice)FormaSpiskaSprTypePrice->kanRelease();
if(FormaSpiskaSprPodr)FormaSpiskaSprPodr->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
if(FormSpiskaSprBSchet)FormSpiskaSprBSchet->kanRelease();
if(REM_FormaSpiskaSprActCategory)REM_FormaSpiskaSprActCategory->kanRelease();

//получим ICallBack для передачи события в вызывающую форму
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
Action=caFree;
}
//-----------------------------------------------------------------------------
void TFormaElementaSprUser::UpdateForm(void)
{
IDMSprTypePrice * DMSprTypePrice;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprTypePrice.1",IID_IDMSprTypePrice,
													(void**)&DMSprTypePrice);
DMSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
DMSprTypePrice->OpenElement(glStrToInt64(DM->ElementIDTPRICE1_USER->AsString));
NameTPrice1Edit->Text=DMSprTypePrice->ElementNAME_TPRICE->AsString;

DMSprTypePrice->OpenElement(glStrToInt64(DM->ElementIDTPRICE2_USER->AsString));
NameTPrice2Edit->Text=DMSprTypePrice->ElementNAME_TPRICE->AsString;

DMSprTypePrice->kanRelease();

if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
	{
	EditChugDoccxDBCheckBox->Visible=false;
	DelChugDoccxDBCheckBox->Visible=false;
	ShowLogcxDBCheckBox->Visible=false;
	DetailedLogcxDBCheckBox->Visible=false;
	SaveNamecxDBCheckBox->Visible=false;
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprUser::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ViborPodr)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDPOD_USER->AsString=FormaSpiskaSprPodr->DM->TableIDPOD->AsInt64;
                        DM->ElementNAMEPOD->AsString=FormaSpiskaSprPodr->DM->TableNAMEPOD->AsString;
                        DM->Element->Post();
						}
                FormaSpiskaSprPodr=0;
                }

		if (number_procedure_end==ViborFirm)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDFIRM_USER->AsString=FormaSpiskaSprFirm->DM->ElementIDFIRM->AsInt64;
                        DM->ElementNAMEFIRM->AsString=FormaSpiskaSprFirm->DM->ElementNAMEFIRM->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprFirm=0;
                }

		if (number_procedure_end==ViborSklad)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDSKLAD_USER->AsString=glStrToInt64(FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString);
                        DM->ElementNAMESKLAD->AsString=FormaSpiskaSprSklad->DM->ElementNAMESKLAD->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprSklad=0;
                }

		if (number_procedure_end==ViborTPrice)
                {
				if (type_event==1)
                        {
						DM->Element->Edit();
						DM->ElementIDTPRICE_USER->AsString=FormaSpiskaSprTypePrice->DM->ElementID_TPRICE->AsInt64;
                        DM->ElementNAME_TPRICE->AsString=FormaSpiskaSprTypePrice->DM->ElementNAME_TPRICE->AsString;
						DM->Element->Post();
                        }
                FormaSpiskaSprTypePrice=0;
                }

		if (number_procedure_end==ViborPrice1)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDTPRICE1_USER->AsString=FormaSpiskaSprTypePrice->DM->ElementID_TPRICE->AsInt64;
                        NameTPrice1Edit->Text=FormaSpiskaSprTypePrice->DM->ElementNAME_TPRICE->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprTypePrice=0;
                }

		if (number_procedure_end==ViborPrice2)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDTPRICE2_USER->AsString=FormaSpiskaSprTypePrice->DM->ElementID_TPRICE->AsInt64;
                        NameTPrice2Edit->Text=FormaSpiskaSprTypePrice->DM->ElementNAME_TPRICE->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprTypePrice=0;
                }

		if (number_procedure_end==ViborInfBase)
                {
				if (type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDBASE_SUSER->AsString=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
                        DM->ElementNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                        DM->Element->Post();
                        }
                FormaSpiskaSprInfBase=0;
                }

 if (number_procedure_end==ViborBankSchet)
        {
		if (type_event==1)
				{
                DM->Element->Edit();
				DM->ElementIDBSCHET_USER->AsString=FormSpiskaSprBSchet->DM->TableIDBSCHET->AsInt64;
                DM->ElementNAMEBSCHET->AsString=FormSpiskaSprBSchet->DM->TableNAMEBSCHET->AsString;
                DM->Element->Post();
                }
        FormSpiskaSprBSchet=0;
        }

 if (number_procedure_end==ViborKassaRekv)
        {
		if (type_event==1)
                {
				EndViborKassa();
                }
		FormaSpiskaSprKKM=0;
		}

if (number_procedure_end==ER_ViborActCategory)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborActCategory();
					}
				REM_FormaSpiskaSprActCategory=0;
				}



        ViborRekv=NO;


	FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//----------------------------------------------------------------------------

//------------------------------------------------------------------------
void TFormaElementaSprUser::OpenFormSpiskaSprBSchet(void)
{
InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBankSchet.1",IID_IFormaSpiskaSprBankSchet,
													(void**)&FormSpiskaSprBSchet);
FormSpiskaSprBSchet->Init(InterfaceMainObject,InterfaceImpl);
FormSpiskaSprBSchet->IdFirm=glStrToInt64(DM->ElementIDFIRM_USER->AsString);
FormSpiskaSprBSchet->DM->IdFirm=glStrToInt64(DM->ElementIDFIRM_USER->AsString);
FormSpiskaSprBSchet->DM->OpenTable();
//FormSpiskaSprBSchet->LabelFirma->Caption="Фирма: "+DM->ElementNAMEFIRM->AsString;
FormSpiskaSprBSchet->NumberProcVibor=ViborBankSchet;
FormSpiskaSprBSchet->Vibor=true;

}
//---------------------------------------------------------------------------







void TFormaElementaSprUser::OpenFormaSpiskaSprInfBase(void)
{

if (FormaSpiskaSprInfBase==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->NumberProcVibor=ViborInfBase;
		FormaSpiskaSprInfBase->DM->OpenTable();
        }

}
//--------------------------------------------------------------------------


void __fastcall TFormaElementaSprUser::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprUser");	
}
//---------------------------------------------------------------------------
void TFormaElementaSprUser::ViborKassa(void)
{
if (FormaSpiskaSprKKM==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&FormaSpiskaSprKKM);
		FormaSpiskaSprKKM->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKKM->Vibor=true;
		FormaSpiskaSprKKM->NumberProcVibor=ViborKassaRekv;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprUser::EndViborKassa(void)
{

	DM->Element->Edit();
	DM->ElementIDKASSA_USER->AsString=FormaSpiskaSprKKM->DM->ElementIDKKM->AsInt64;
	DM->ElementNAMEKKM->AsString=FormaSpiskaSprKKM->DM->ElementNAMEKKM->AsString;
	DM->Element->Post(); 

}
//-----------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameKassacxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborKassa();
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprUser::NameInfcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormaSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NamePodcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprPodr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPodr.1",IID_IFormaSpiskaSprPodr,
													(void**)&FormaSpiskaSprPodr);
		FormaSpiskaSprPodr->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPodr->Vibor=true;
		FormaSpiskaSprPodr->NumberProcVibor=ViborPodr;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=ViborFirm;

		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::cxDBButtonEdit1PropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprBSchet();	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->NumberProcVibor=ViborSklad;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameTPricecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprTypePrice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprTypePrice.1",IID_IFormaSpiskaSprTypePrice,
													(void**)&FormaSpiskaSprTypePrice);
		FormaSpiskaSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprTypePrice->Vibor=true;
		FormaSpiskaSprTypePrice->NumberProcVibor=ViborTPrice;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameTPrice1EditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprTypePrice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprTypePrice.1",IID_IFormaSpiskaSprTypePrice,
													(void**)&FormaSpiskaSprTypePrice);
		FormaSpiskaSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprTypePrice->Vibor=true;
		FormaSpiskaSprTypePrice->NumberProcVibor=ViborPrice1;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NameTPrice2EditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprTypePrice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprTypePrice.1",IID_IFormaSpiskaSprTypePrice,
													(void**)&FormaSpiskaSprTypePrice);
		FormaSpiskaSprTypePrice->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprTypePrice->Vibor=true;
		FormaSpiskaSprTypePrice->NumberProcVibor=ViborPrice2;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::NamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::Name2cxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::FNamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprUser::ActionOKExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		Close();
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprUser::ViborActCategory(void)
{

if (REM_FormaSpiskaSprActCategory==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprActCategory,IID_IREM_FormaSpiskaSprActCategory,
													(void**)&REM_FormaSpiskaSprActCategory);
		REM_FormaSpiskaSprActCategory->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprActCategory) return;
		REM_FormaSpiskaSprActCategory->Vibor=true;
		REM_FormaSpiskaSprActCategory->NumberProcVibor=ER_ViborActCategory;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TFormaElementaSprUser::EndViborActCategory(void)
{

	DM->Element->Edit();
	DM->ElementIDACTCATEGORY_SUSER->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
	DM->ElementNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprUser::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborActCategory();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDACTCATEGORY_SUSER->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

