//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSetupOtborGurRoznDoc.h"
#include "UDM.h"
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
__fastcall TFormaSetupOtborGurRoznDoc::TFormaSetupOtborGurRoznDoc(TComponent* Owner)
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
bool TFormaSetupOtborGurRoznDoc::Init(void)
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

TypeEvent=0;;
NameKlientEdit->Text="";
TypeDocComboBox->ItemIndex=0;


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
int TFormaSetupOtborGurRoznDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupOtborGurRoznDoc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
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

int TFormaSetupOtborGurRoznDoc::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

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
return -1;
}

//---------------------------------------------------------------------------















void __fastcall TFormaSetupOtborGurRoznDoc::TypeDocComboBoxPropertiesChange(
      TObject *Sender)
{
switch (TypeDocComboBox->ItemIndex)
		{

		case 0:
                {
				StringTypeDoc="";
                NameTypeDoc="";
				} break;

		case 1:
                {
				StringTypeDoc="'CHK'";
                NameTypeDoc="Чек ККМ";
				} break;

		case 2:
                {
				StringTypeDoc="'REPKKM'";
                NameTypeDoc="Отчет ККМ";
				} break;

		case 3:
                {
				StringTypeDoc="'REALROZN'";
                NameTypeDoc="Реализация розн.";
				} break;

		case 4:
				{
				StringTypeDoc="'PKOROZN'";
				NameTypeDoc="Приход нал.";
				} break;

		case 5:
				{
				StringTypeDoc="'RKOROZN'";
				NameTypeDoc="Расход нал.";
				} break;

		case 6:
				{
				StringTypeDoc="'REALREST'";
				NameTypeDoc="Акт реализации";
				} break;


		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupOtborGurRoznDoc::NameKlientEditPropertiesButtonClick(
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
			SpisokKlient->Vibor=true;
			SpisokKlient->IdKlient=IdKlient;
			SpisokKlient->NumberProcVibor=ViborKlient;
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

void __fastcall TFormaSetupOtborGurRoznDoc::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetupOtborGurRoznDoc::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
Close();
}
//---------------------------------------------------------------------------

