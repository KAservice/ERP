//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprNomImage.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
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
#pragma link "cxDBRichEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxImage"
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprNomImage::TFormaElementaSprNomImage(TComponent* Owner)
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
bool TFormaElementaSprNomImage::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNomImage,IID_IDMSprNomImage,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameVidImagecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
ImageSmallcxDBImage->DataBinding->DataSource=DM->DataSourceElement;
ImagecxDBImage->DataBinding->DataSource=DM->DataSourceElement;
IndexcxDBSpinEdit->DataBinding->DataSource=DM->DataSourceElement;


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
int TFormaElementaSprNomImage::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprNomImage::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprNomImage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprVidImage)FormaSpiskaSprVidImage->kanRelease();

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


void __fastcall TFormaElementaSprNomImage::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprNomImage");
}
//---------------------------------------------------------------------------



void __fastcall TFormaElementaSprNomImage::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomImage::ActionOKExecute(TObject *Sender)
{

if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprNomImage::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_ViborVidImage)
				{
				if (type_event==1)
					{
					EndViborVidImage();
					}
				FormaSpiskaSprVidImage=0;
				}


FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------

void TFormaElementaSprNomImage::OpenFormaSpiskaSprVidImage(void)
{
if (FormaSpiskaSprVidImage==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprVidImage,IID_IFormaSpiskaSprVidImage,
														(void**)&FormaSpiskaSprVidImage);
		FormaSpiskaSprVidImage->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprVidImage->Vibor=true;
		FormaSpiskaSprVidImage->NumberProcVibor=ER_ViborVidImage;
		FormaSpiskaSprVidImage->IdElement=glStrToInt64(DM->ElementIDVIDIMAGE_SNOMIMAGE->AsString);
        FormaSpiskaSprVidImage->UpdateForm();
		}


}
//-----------------------------------------------------------------------------
void TFormaElementaSprNomImage::EndViborVidImage(void)
{
DM->Element->Edit();
DM->ElementIDVIDIMAGE_SNOMIMAGE->AsString=
						FormaSpiskaSprVidImage->DM->TableID_SVIDIMAGE->AsString;
DM->ElementNAME_SVIDIMAGE->AsString=
					FormaSpiskaSprVidImage->DM->TableNAME_SVIDIMAGE->AsString;

if (DM->ElementNAME_SNOMIMAGE->AsString=="")
	{
	DM->ElementNAME_SNOMIMAGE->AsString=FormaSpiskaSprVidImage->DM->TableNAME_SVIDIMAGE->AsString;
	}

DM->Element->Post();


}
//-----------------------------------------------------------------------------

void __fastcall TFormaElementaSprNomImage::NameVidImagecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprVidImage();
}
//---------------------------------------------------------------------------


