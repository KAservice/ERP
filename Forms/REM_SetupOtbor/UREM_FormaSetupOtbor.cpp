//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaSetupOtbor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaSetupOtbor::TREM_FormaSetupOtbor(TComponent* Owner)
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
bool TREM_FormaSetupOtbor::Init(void)
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

NameFirmEdit->Text="";
NameSkladEdit->Text="";
NameKlientEdit->Text="";
TypeDocComboBox->ItemIndex=0;


DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaSetupOtbor::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaSetupOtbor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->kanRelease();
if(SpisokSklad)SpisokSklad->kanRelease();
if(SpisokKlient)SpisokKlient->kanRelease();



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
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TREM_FormaSetupOtbor::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{


if (number_procedure_end==ViborFirm)
        {
		if (type_event==1)
				{
				IdFirm=glStrToInt64(SpisokFirm->DM->ElementIDFIRM->AsString);
                NameFirm=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                NameFirmEdit->Text=NameFirm;
                OtborPoFirm=true;
                }
        SpisokFirm=0;
        }

if (number_procedure_end==ViborSklad)
        {
		if (type_event==1)
                {

				IdSklad=glStrToInt64(SpisokSklad->DM->ElementIDSKLAD->AsString);
                NameSklad=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                NameSkladEdit->Text=NameSklad;
                OtborPoSklad=true;
                }
        SpisokSklad=0;
        }

if (number_procedure_end==ViborKlient)
        {
		if (type_event==1)
                {

                IdKlient=glStrToInt64(SpisokKlient->DM->ElementIDKLIENT->AsString);
                NameKlient=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                NameKlientEdit->Text=NameKlient;
                OtborPoKlient=true;
                }
        SpisokKlient=0;
        }


EditRekvisit=NO;

Visible=true;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

return -1;
}

//---------------------------------------------------------------------------



void __fastcall TREM_FormaSetupOtbor::TypeDocComboBoxPropertiesChange(
	  TObject *Sender)
{
switch (TypeDocComboBox->ItemIndex)
		{

//		case 0:
//				{
//				StringTypeDoc="";
//				NameTypeDoc="";
//				} break;
//
//		case 1:
//				{
//				StringTypeDoc="'REAL_REST'";
//				NameTypeDoc="Акт реализации";
//				} break;
//
//		case 2:
//				{
//				StringTypeDoc="'SPN'";
//				NameTypeDoc="Акт списания";
//				} break;



		}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSetupOtbor::NameKlientEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		if (SpisokKlient==NULL)
			{
			InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&SpisokKlient);
			SpisokKlient->Init(InterfaceMainObject,InterfaceImpl);
			if (!SpisokKlient) return;
			SpisokKlient->Vibor=true;
			SpisokKlient->NumberProcVibor=ViborKlient;
			SpisokKlient->UpdateForm();
			Visible=false;
			}
		}break;
	case 1:
		{
		NameKlient="";
		IdKlient=0;
		NameKlientEdit->Text=NameKlient;
		OtborPoKlient=false;
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSetupOtbor::NameSkladEditPropertiesButtonClick(
	  TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		if (SpisokSklad==NULL)
			{
			InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprSklad.1",IID_IFormaSpiskaSprSklad,
													(void**)&SpisokSklad);
			SpisokSklad->Init(InterfaceMainObject,InterfaceImpl);
			if (!SpisokSklad) return;
			SpisokSklad->Vibor=true;
			SpisokSklad->NumberProcVibor=ViborSklad;
			Visible=false;
			}
		}break;
	case 1:
		{
		NameSklad="";
		IdSklad=0;
		NameSkladEdit->Text=NameSklad;
		OtborPoSklad=false;
		}break;
	}
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaSetupOtbor::NameFirmEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		if (SpisokFirm==NULL)
			{
			InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprFirm.1",IID_IFormaSpiskaSprFirm,
													(void**)&SpisokFirm);
			SpisokFirm->Init(InterfaceMainObject,InterfaceImpl);
			if (!SpisokFirm) return;
			SpisokFirm->Vibor=true;
			SpisokFirm->NumberProcVibor=ViborFirm;
			Visible=false;
			}
		}break;
	case 1:
		{
		NameFirm="";
		IdFirm=0;
		NameFirmEdit->Text=NameFirm;
		OtborPoFirm=false;
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSetupOtbor::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaSetupOtbor::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
Close();
}
//---------------------------------------------------------------------------

