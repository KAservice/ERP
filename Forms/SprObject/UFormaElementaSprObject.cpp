//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprObject.h"
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
__fastcall TFormaElementaSprObject::TFormaElementaSprObject(TComponent* Owner)
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
bool TFormaElementaSprObject::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprObject,IID_IDMSprObject, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NamePodcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameFirmcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameSkladcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameKKMcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameInfBasecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int TFormaElementaSprObject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprObject::UpdateForm(void)
{
//


}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprObject::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprSklad)FormaSpiskaSprSklad->kanRelease();
if(FormaSpiskaSprFirm)FormaSpiskaSprFirm->kanRelease();
if(FormaSpiskaSprPodr)FormaSpiskaSprPodr->kanRelease();
if(FormaSpiskaSprKKM)FormaSpiskaSprKKM->kanRelease();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->kanRelease();



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
int TFormaElementaSprObject::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
		if (number_procedure_end==1)//==ViborFirm)
                {
                DM->Element->Edit();
				DM->ElementIDFIRM_SOBJECT->AsString=
						FormaSpiskaSprFirm->DM->ElementIDFIRM->AsString;
                DM->ElementNAMEFIRM->AsString
                                =FormaSpiskaSprFirm->DM->Element->FieldByName("NAMEFIRM")->AsString;
				DM->Element->Post();
				FormaSpiskaSprFirm=0;
                }

		if (number_procedure_end==2)//==ViborSklad)
                {
                DM->Element->Edit();
				DM->ElementIDSKLAD_SOBJECT->AsString=
						FormaSpiskaSprSklad->DM->ElementIDSKLAD->AsString;
                DM->ElementNAMESKLAD->AsString=
                                FormaSpiskaSprSklad->DM->Element->FieldByName("NAMESKLAD")->AsString;
                DM->Element->Post();
				FormaSpiskaSprSklad=0;
                }

		if (number_procedure_end==3)//==ViborPodr)
				{
                DM->Element->Edit();
				DM->ElementIDPODR_SOBJECT->AsString=FormaSpiskaSprPodr->DM->ElementIDPOD->AsString;
				DM->ElementNAMEPOD->AsString=FormaSpiskaSprPodr->DM->ElementNAMEPOD->AsString;
				DM->Element->Post();
                FormaSpiskaSprPodr=0;
                }


		if (number_procedure_end==4)//==ViborKKM)
                {
                DM->Element->Edit();
				DM->ElementIDKASSA_SOBJECT->AsString=FormaSpiskaSprKKM->DM->ElementIDKKM->AsString;
                DM->ElementNAMEKKM->AsString=FormaSpiskaSprKKM->DM->ElementNAMEKKM->AsString;
                DM->Element->Post();
                FormaSpiskaSprKKM=0;
				}

		if (number_procedure_end==5)//==ViborInfBase)
                {
				if(type_event==1)
                        {
                        DM->Element->Edit();
						DM->ElementIDINFBASE_SOBJECT->AsString=FormaSpiskaSprInfBase->DM->ElementID_SINFBASE_OBMEN->AsString;
						DM->ElementNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->ElementNAME_SINFBASE_OBMEN->AsString;
                        DM->Element->Post();
                        }
				FormaSpiskaSprInfBase=0;
				}





FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
void TFormaElementaSprObject::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TFormaElementaSprObject::ActionOpenHelpExecute(TObject *Sender)
{
//Application->HelpJump("SprARM");
}
//---------------------------------------------------------------------------





void __fastcall TFormaElementaSprObject::NamePodcxDBButtonEditPropertiesButtonClick(
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

void __fastcall TFormaElementaSprObject::NameFirmcxDBButtonEditPropertiesButtonClick(
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

void __fastcall TFormaElementaSprObject::NameSkladcxDBButtonEditPropertiesButtonClick(
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

void __fastcall TFormaElementaSprObject::NameKKMcxDBButtonEditPropertiesButtonClick(
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

void __fastcall TFormaElementaSprObject::NameInfBasecxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
OpenFormSpiskaSprInfBase();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprObject::NamecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprObject::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprObject::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprObject::ActionOKExecute(TObject *Sender)
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

void __fastcall TFormaElementaSprObject::ActionSaveExecute(TObject *Sender)
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
//----------------------------------------------------------------------------

