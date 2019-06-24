//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprEd.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprEd::TFormaElementaSprEd(TComponent* Owner)
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
bool TFormaElementaSprEd::Init(void)
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

//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameOkeicxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameEdcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KFEdcxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
SHcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
KF2cxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
VescxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
cxDBImageComboBoxTypeBarCode->DataBinding->DataSource=DM->DataSourceElement;

flObrabatChangeTypeSH=false;
flObrabatChangeNeIsp=false;


SaveElement=false;


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
int TFormaElementaSprEd::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprEd::UpdateForm(void)
{
flObrabatChangeTypeSH=false;
flObrabatChangeNeIsp=false;
NeIspEdComboBox->ItemIndex=DM->ElementNEISPED->AsInteger;
flObrabatChangeTypeSH=true;
flObrabatChangeNeIsp=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprEd::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprOKEI)FormaSpiskaSprOKEI->kanRelease();
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
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprEd::FormActivate(TObject *Sender)
{

//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
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
void __fastcall TFormaElementaSprEd::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий

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
//событие считывания штрих-кода
void __fastcall TFormaElementaSprEd::ReadShtrihCodEvent(int number, UnicodeString sh)
{

AnsiString s=glDelSymbolOfBarCode(sh);


        String V="Вы хотите перезаписать штрих код?";
        String Z="Штрих код уже задан";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)!=IDYES)
                {
                return;
                }

DM->Element->Edit();
DM->ElementSHED->AsString=Trim(s).SetLength(13);
DM->Element->Post();
}
//----------------------------------------------------------------------------


void __fastcall TFormaElementaSprEd::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprEd");
}
//---------------------------------------------------------------------------
bool TFormaElementaSprEd::CheckBarCode(void)
{
bool result=false;
result= DM->CheckBarCode(DM->ElementIDED->AsInt64,DM->ElementSHED->AsString);
return result;
}
//----------------------------------------------------------------------------
void __fastcall TFormaElementaSprEd::cxButtonNewSHClick(TObject *Sender)
{

DM->NewShtrihCod();
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprEd::NameOkeicxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
if (FormaSpiskaSprOKEI==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprOKEI.1",IID_IFormaSpiskaSprOKEI,
														(void**)&FormaSpiskaSprOKEI);
		FormaSpiskaSprOKEI->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprOKEI->Vibor=true;
		FormaSpiskaSprOKEI->NumberProcVibor=1;
		}
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprEd::NeIspEdComboBoxPropertiesChange(
      TObject *Sender)
{
if(flObrabatChangeNeIsp==false) return;

DM->Element->Edit();
DM->ElementNEISPED->AsInteger=NeIspEdComboBox->ItemIndex;
DM->Element->Post();

	FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprEd::NameEdcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::KFEdcxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	DM->Element->Edit();
	DM->ElementKF2_SED->AsFloat=1/DM->ElementKFED->AsFloat;
	DM->Element->Post();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::SHcxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::CodecxDBTextEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::cxButtonOpenFormSpiskaImportEdClick(
      TObject *Sender)
{
if (SaveElement==false)
        {
        ShowMessage("Необходимо записать элемент!");
        return;
        }
if (FormaSpiskaSprImportEd==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprImportEd.1",IID_IFormaSpiskaSprImportEd,
														(void**)&FormaSpiskaSprImportEd);
	FormaSpiskaSprImportEd->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprImportEd->Vibor=false;
	FormaSpiskaSprImportEd->IdNom=DM->ElementIDNOMED->AsInt64;
	FormaSpiskaSprImportEd->IdEd=DM->ElementIDED->AsInt64;
	FormaSpiskaSprImportEd->UpdateForm();
	FormaSpiskaSprImportEd->NumberProcVibor=2;
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprEd::EndViborImportEd(TObject *Sender)
{

}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprEd::KF2cxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::VescxDBCalcEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaElementaSprEd::cxDBImageComboBoxTypeBarCodeKeyPress(
      TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprEd::ActionOKExecute(TObject *Sender)
{
if (CheckBarCode()==true)
	{
	ShowMessage("Штрих код не уникальный!");
	return;
	}




if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();
		SaveElement=true;

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprEd::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==1)
				{
				if (type_event==1)
					{
					DM->Element->Edit();
					DM->ElementIDOKEIED->AsInt64=
						FormaSpiskaSprOKEI->DM->ElementIDOKEI->AsInt64;
					DM->ElementNAMEOKEI->AsString=FormaSpiskaSprOKEI->DM->Element->FieldByName("NAMEOKEI")->AsString;
					DM->ElementNAMEED->AsString=FormaSpiskaSprOKEI->DM->ElementNAMEOKEI->AsString;
					DM->Element->Post();
					}
				FormaSpiskaSprOKEI=0;
				}

		if (number_procedure_end==2)
				{
				FormaSpiskaSprImportEd=0;
				}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------
