//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprProducerModel.h"
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
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxDBLabel"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprProducerModel::TREM_FormaElementaSprProducerModel(TComponent* Owner)
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
bool TREM_FormaElementaSprProducerModel::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerModel,IID_IREM_DMSprProducerModel, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);



IdcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameTypeDevicecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;


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
//---------------------------------------------------------------------------
int TREM_FormaElementaSprProducerModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::UpdateForm(void)
{



}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprProducer>0)FormaSpiskaSprProducer->kanRelease();
if(SpisokBrand>0)SpisokBrand->kanRelease();
if(REM_FormaSpiskaSprTypeDevice)REM_FormaSpiskaSprTypeDevice->kanRelease();
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
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModel::ActionOpenHelpExecute(
      TObject *Sender)
{
//
}
//---------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprProducerModel::NamecxDBTextEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
	FindNextControl(ActiveControl,true,true,false)->SetFocus();
	}	
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::ActionOKExecute(TObject *Sender)
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
int TREM_FormaElementaSprProducerModel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_ViborBrand)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborBrand();
					}
				SpisokBrand=0;
				}

if (number_procedure_end==ER_ViborProducer)
				{
				if (type_event==1)    //выбор сделан
					{
					EventEndEditProdcer();
					}
				FormaSpiskaSprProducer=0;
				}

if (number_procedure_end==ER_ViborTypeDevice)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborTypeDevice();
					}
				REM_FormaSpiskaSprTypeDevice=0;
				}

if (number_procedure_end==ER_ViborActCategory)
				{
				if (type_event==1)    //выбор сделан
					{
					EndViborActCategory();
					}
				REM_FormaSpiskaSprActCategory=0;
				}
return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModel::cxButtonOpenPropertiesClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprProducerModelPropertiesValue==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModelPropertiesValue,IID_IREM_FormaSpiskaSprProducerModelPropertiesValue,
												 (void**)&REM_FormaSpiskaSprProducerModelPropertiesValue);
		REM_FormaSpiskaSprProducerModelPropertiesValue->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprProducerModelPropertiesValue->Vibor=false;
		REM_FormaSpiskaSprProducerModelPropertiesValue->IdOwner=glStrToInt64(DM->ElementID_REM_SPRMODEL->AsString);
		REM_FormaSpiskaSprProducerModelPropertiesValue->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SPRMODEL->AsString));
		REM_FormaSpiskaSprProducerModelPropertiesValue->HeaderText="Свойства модели: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprProducerModelPropertiesValue->NumberProcVibor=VR_ModelPropertiesValue	;
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::cxButtonOpenInfBlockClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprProducerModelInfBlock==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModelInfBlock,IID_IREM_FormaSpiskaSprProducerModelInfBlock,
												 (void**)&REM_FormaSpiskaSprProducerModelInfBlock);
		REM_FormaSpiskaSprProducerModelInfBlock->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprProducerModelInfBlock->Vibor=false;
		REM_FormaSpiskaSprProducerModelInfBlock->IdOwner=glStrToInt64(DM->ElementID_REM_SPRMODEL->AsString);
		REM_FormaSpiskaSprProducerModelInfBlock->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SPRMODEL->AsString));
		REM_FormaSpiskaSprProducerModelInfBlock->HeaderText="Инф. блоки модели: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprProducerModelInfBlock->NumberProcVibor=VR_ModelInfBlock	;
		}
}
//---------------------------------------------------------------------------
//Бренд
void TREM_FormaElementaSprProducerModel::ViborBrand(void)
{
if (SpisokBrand==0)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprBrand.1",IID_IFormaSpiskaSprBrand,
													 (void**)&SpisokBrand);
		SpisokBrand->Init(InterfaceMainObject,InterfaceImpl);
		SpisokBrand->Vibor=true;
		SpisokBrand->NumberProcVibor=ER_ViborBrand;
		}

}
//------------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModel::EndViborBrand(void)
{

	DM->Element->Edit();
	DM->ElementIDBRAND_REM_SPRMODEL->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->ElementNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->Element->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::ViborProducer(void)
{

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
//----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::EventEndEditProdcer(void)
{

	DM->Element->Edit();
	DM->ElementIDPR_REM_SPRMODEL->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->ElementNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->Element->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::ViborTypeDevice(void)
{

if (REM_FormaSpiskaSprTypeDevice==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprTypeDevice,IID_IREM_FormaSpiskaSprTypeDevice,
													(void**)&REM_FormaSpiskaSprTypeDevice);
		REM_FormaSpiskaSprTypeDevice->Init(InterfaceMainObject,InterfaceImpl);
		if (!REM_FormaSpiskaSprTypeDevice) return;
		REM_FormaSpiskaSprTypeDevice->Vibor=true;
		REM_FormaSpiskaSprTypeDevice->NumberProcVibor=ER_ViborTypeDevice;
		//FormaSpiskaSprProducer->UpdateForm();
		}

}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::EndViborTypeDevice(void)
{

	DM->Element->Edit();
	DM->ElementIDTYPEDEVICE_REM_SPRMODEL->AsString=REM_FormaSpiskaSprTypeDevice->DM->TableID_REM_STYPEDEVICE->AsString;
	DM->ElementNAME_REM_STYPEDEVICE->AsString=REM_FormaSpiskaSprTypeDevice->DM->TableNAME_REM_STYPEDEVICE->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprTypeDevice=0;

}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModel::ViborActCategory(void)
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
void TREM_FormaElementaSprProducerModel::EndViborActCategory(void)
{

	DM->Element->Edit();
	DM->ElementIDACTCATEGORY_REM_SPRMODEL->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
	DM->ElementNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModel::NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborBrand();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDBRAND_REM_SPRMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::NameProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborProducer();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDPR_REM_SPRMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDACTCATEGORY_REM_SPRMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModel::NameTypeDevicecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
switch (AButtonIndex)
	{
	case 0:
		{
		ViborTypeDevice();
		}break;
	case 1:
		{
		//IdNom=0;
		//NameNomEdit->Text="";
		DM->Element->Edit();
		DM->ElementIDTYPEDEVICE_REM_SPRMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

