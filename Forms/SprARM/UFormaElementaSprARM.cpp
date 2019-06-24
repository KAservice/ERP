//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprARM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "cxPC"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprARM::TFormaElementaSprARM(TComponent* Owner)
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
bool TFormaElementaSprARM::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprARM.1",IID_IDMSprARM, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamePodcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKKMcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

StrParcxDBMemo->DataBinding->DataSource=DM->DataSourceElement;
NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

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
int TFormaElementaSprARM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprARM::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprARM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprPodr)FormaSpiskaSprPodr->kanRelease();
if(FormaSpiskaSprKKM)FormaSpiskaSprKKM->kanRelease();
if(FormaSpiskaSprOborud)FormaSpiskaSprOborud->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();
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
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
int TFormaElementaSprARM::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
		if (number_procedure_end==1)//==ViborFirm)
                {
                DM->Element->Edit();
				DM->ElementIDFIRM_SARM->AsString=
						FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
                DM->ElementNAMEFIRM->AsString
                                =FormaSpiskaSprFirm->DM->Element->FieldByName("NAMEFIRM")->AsString;
				DM->Element->Post();
				FormaSpiskaSprFirm=0;
                }

		if (number_procedure_end==2)//==ViborSklad)
                {
                DM->Element->Edit();
				DM->ElementIDSKLAD_SARM->AsString=
						FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
                DM->ElementNAMESKLAD->AsString=
                                FormaSpiskaSprSklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
                DM->Element->Post();
				FormaSpiskaSprSklad=0;
                }

		if (number_procedure_end==3)//==ViborPodr)
				{
                DM->Element->Edit();
				DM->ElementIDPODR_SARM->AsString=FormaSpiskaSprPodr->DM->ElementIDPOD->AsString;
				DM->ElementNAMEPOD->AsString=FormaSpiskaSprPodr->DM->ElementNAMEPOD->AsString;
				DM->Element->Post();
                FormaSpiskaSprPodr=0;
                }


		if (number_procedure_end==4)//==ViborKKM)
                {
                DM->Element->Edit();
				DM->ElementIDKKM_SARM->AsString=FormaSpiskaSprKKM->DM->ElementIDKKM->AsString;
                DM->ElementNAMEKKM->AsString=FormaSpiskaSprKKM->DM->ElementNAMEKKM->AsString;
                DM->Element->Post();
                FormaSpiskaSprKKM=0;
				}

		if (number_procedure_end==5)//==ViborInfBase)
                {
				if(type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDBASE_SARM->AsString=FormaSpiskaSprInfBase->DM->ElementID_SINFBASE_OBMEN->AsString;
						DM->ElementNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->ElementNAME_SINFBASE_OBMEN->AsString;
                        DM->Element->Post();
                        }
				FormaSpiskaSprInfBase=0;
				}

		if (number_procedure_end==6)//==ViborOborud)
				{
				FormaSpiskaSprOborud=0;
				}


if (number_procedure_end==7)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborActCategory();
					}
				REM_FormaSpiskaSprActCategory=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaElementaSprARM::OpenFormSpiskaSprInfBase(void)
{
if (FormaSpiskaSprInfBase==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprInfBase.1",IID_IFormaSpiskaSprInfBase,
													(void**)&FormaSpiskaSprInfBase);
		FormaSpiskaSprInfBase->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBase->Vibor=true;
		FormaSpiskaSprInfBase->DM->OpenTable();
		FormaSpiskaSprInfBase->NumberProcVibor=5;
		}
}
//---------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprARM");
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprARM::cxButtonOborudClick(TObject *Sender)
{
if (DM->flSaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}
if (FormaSpiskaSprOborud==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprOborud.1",IID_IFormaSpiskaSprOborud,
													(void**)&FormaSpiskaSprOborud);

		FormaSpiskaSprOborud->Init(InterfaceMainObject,InterfaceImpl);
        FormaSpiskaSprOborud->IdKKM=glStrToInt64(DM->ElementID_SARM->AsString);
        //FormaSpiskaSprOborud->ZagolovokLabel->Caption="АРМ: "+DM->ElementNAME_SARM->AsString;
		FormaSpiskaSprOborud->UpdateForm();
		FormaSpiskaSprOborud->NumberProcVibor=6;
        }	
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprARM::NamePodcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprPodr==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprPodr.1",IID_IFormaSpiskaSprPodr,
													(void**)&FormaSpiskaSprPodr);
		FormaSpiskaSprPodr->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprPodr->Vibor=true;
		FormaSpiskaSprPodr->NumberProcVibor=3;
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::NameFirmcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprFirm==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&FormaSpiskaSprFirm);
		FormaSpiskaSprFirm->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprFirm->Vibor=true;
		FormaSpiskaSprFirm->NumberProcVibor=1;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::NameSkladcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprSklad==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&FormaSpiskaSprSklad);
		FormaSpiskaSprSklad->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprSklad->Vibor=true;
		FormaSpiskaSprSklad->NumberProcVibor=2;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::NameKKMcxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprKKM==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKKM.1",IID_IFormaSpiskaSprKKM,
													(void**)&FormaSpiskaSprKKM);
		FormaSpiskaSprKKM->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprKKM->Vibor=true;
		FormaSpiskaSprKKM->NumberProcVibor=4;
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprARM::NamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprARM::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprARM::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void TFormaElementaSprARM::ViborActCategory(void)
{

if (REM_FormaSpiskaSprActCategory==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprActCategory,IID_IREM_FormaSpiskaSprActCategory,
													(void**)&REM_FormaSpiskaSprActCategory);
		REM_FormaSpiskaSprActCategory->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprActCategory) return;
		REM_FormaSpiskaSprActCategory->Vibor=true;
		REM_FormaSpiskaSprActCategory->NumberProcVibor=7;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TFormaElementaSprARM::EndViborActCategory(void)
{

	DM->Element->Edit();
	DM->ElementIDACTCATEGORY_SARM->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
	DM->ElementNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprARM::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDACTCATEGORY_SARM->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

