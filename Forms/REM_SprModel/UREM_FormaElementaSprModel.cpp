//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprModel.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxButtonEdit"
#pragma link "cxLabel"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprModel::TREM_FormaElementaSprModel(TComponent* Owner)
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
bool TREM_FormaElementaSprModel::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprModel.1",IID_IREM_DMSprModel,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);
NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameNomcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
StrCodeModelcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameModelNeisprcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameBrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameActivecategorycxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
NameTypeDevicecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;



SaveElement=false;

DM_Connection->GetPrivForm(GCPRIV_FormaDocCheck);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprModel::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if (FormaSpiskaSprNom>0) FormaSpiskaSprNom->kanRelease();
if (FormaSpiskaSprModel>0) FormaSpiskaSprModel->kanRelease();
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
void TREM_FormaElementaSprModel::UpdateForm(void)
{
///


}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprModel::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if ( number_procedure_end==EditKomplModel)
	{
	if (type_event==1)
		{

		}
	REM_FormaSpiskaSprKomplModel=0;
	}

if ( number_procedure_end==VR_Nom)
	{
	if (type_event==1)
		{
		EndViborNom();
		}
	FormaSpiskaSprNom=0;
	}

if ( number_procedure_end==VR_ModelDetal)
	{
	if (type_event==1)
		{

		}
	REM_FormaSpiskaSprModelDetal=0;
	}

if ( number_procedure_end==VR_NeisprModel)
	{
	if (type_event==1)
		{

		}
	REM_FormaSpiskaSprNeisprModel=0;
	}



if ( number_procedure_end==VR_Model)
	{
	if (type_event==1)
		{
		EndViborModel();
		}
	FormaSpiskaSprModel=0;
	}

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
//-----------------------------------------------------------------------------









void __fastcall TREM_FormaElementaSprModel::cxButtonKolmplClick(TObject *Sender)
{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprKomplModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprKomplModel.1",IID_IREM_FormaSpiskaSprKomplModel,
												 (void**)&REM_FormaSpiskaSprKomplModel);
		REM_FormaSpiskaSprKomplModel->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprKomplModel->Vibor=false;
		REM_FormaSpiskaSprKomplModel->IdModel=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprKomplModel->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprKomplModel->TextMessage="Комплектация модели номенклатуры: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprKomplModel->NumberProcVibor=EditKomplModel;
		}	
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprModel::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::ActionOKExecute(TObject *Sender)
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

void __fastcall TREM_FormaElementaSprModel::ActionSaveExecute(TObject *Sender)
{
if (DM->SaveElement()==true)
		{
		SaveElement=true;
		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModel::ViborNom(void)
{
if (FormaSpiskaSprNom>0) return;

InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprNom.1",IID_IFormaSpiskaSprNom,
												 (void**)&FormaSpiskaSprNom);
FormaSpiskaSprNom->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprNom->Vibor=true;
FormaSpiskaSprNom->NumberProcVibor=VR_Nom;
FormaSpiskaSprNom->IdNom=glStrToInt64(DM->ElementIDNOM_REM_SMODEL->AsString);
FormaSpiskaSprNom->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::EndViborNom(void)
{

	DM->Element->Edit();
	DM->ElementIDNOM_REM_SMODEL->AsString=FormaSpiskaSprNom->DM->TableIDNOM->AsString;
	DM->ElementNAMENOM->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->ElementNAME_REM_SMODEL->AsString=FormaSpiskaSprNom->DM->TableNAMENOM->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborNom();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprModel::cxButtonOpenSprModelDetalClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprModelDetal==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModelDetal,IID_IREM_FormaSpiskaSprModelDetal,
												 (void**)&REM_FormaSpiskaSprModelDetal);
		REM_FormaSpiskaSprModelDetal->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprModelDetal->Vibor=false;
		REM_FormaSpiskaSprModelDetal->IdModel=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprModelDetal->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprModelDetal->TextMessage="Детализация модели номенклатуры: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprModelDetal->NumberProcVibor=VR_ModelDetal;
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::cxButtonNeisprClick(TObject *Sender)
{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprNeisprModel==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprNeisprModel,IID_IREM_FormaSpiskaSprNeisprModel,
												 (void**)&REM_FormaSpiskaSprNeisprModel);
		REM_FormaSpiskaSprNeisprModel->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprNeisprModel->Vibor=false;
		REM_FormaSpiskaSprNeisprModel->IdModel=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprNeisprModel->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprNeisprModel->TextMessage="Неисправности модели номенклатуры: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprNeisprModel->NumberProcVibor=VR_ModelDetal;
		}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModel::ViborModel(void)
{
if (FormaSpiskaSprModel>0) return;

InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModel,IID_IREM_FormaSpiskaSprModel,
												 (void**)&FormaSpiskaSprModel);
FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
FormaSpiskaSprModel->Vibor=true;
FormaSpiskaSprModel->NumberProcVibor=VR_Model;
FormaSpiskaSprModel->IdModel=glStrToInt64(DM->ElementIDMODELNEISPR_REM_SMODEL->AsString);
FormaSpiskaSprModel->UpdateForm();

}
//--------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::EndViborModel(void)
{

	DM->Element->Edit();
	DM->ElementIDMODELNEISPR_REM_SMODEL->AsString=FormaSpiskaSprModel->DM->TableID_REM_SMODEL->AsString;
	DM->ElementNAME_REM_SMODEL_NEISPR->AsString=FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
	DM->Element->Post();

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::NameModelNeisprcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborModel();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::cxButtonOpenPropertiesClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprModelPropertiesValue==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModelPropertiesValue,IID_IREM_FormaSpiskaSprModelPropertiesValue,
												 (void**)&REM_FormaSpiskaSprModelPropertiesValue);
		REM_FormaSpiskaSprModelPropertiesValue->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprModelPropertiesValue->Vibor=false;
		REM_FormaSpiskaSprModelPropertiesValue->IdOwner=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprModelPropertiesValue->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprModelPropertiesValue->HeaderText="Свойства модели: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprModelPropertiesValue->NumberProcVibor=VR_ModelPropertiesValue	;
		}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::cxButtonOpenInfBlockClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprModelInfBlock==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModelInfBlock,IID_IREM_FormaSpiskaSprModelInfBlock,
												 (void**)&REM_FormaSpiskaSprModelInfBlock);
		REM_FormaSpiskaSprModelInfBlock->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprModelInfBlock->Vibor=false;
		REM_FormaSpiskaSprModelInfBlock->IdOwner=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprModelInfBlock->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprModelInfBlock->HeaderText="Инф. блоки модели: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprModelInfBlock->NumberProcVibor=VR_ModelInfBlock	;
		}
}
//---------------------------------------------------------------------------
//Бренд
void TREM_FormaElementaSprModel::ViborBrand(void)
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
void __fastcall TREM_FormaElementaSprModel::EndViborBrand(void)
{

	DM->Element->Edit();
	DM->ElementIDBRAND_REM_SMODEL->AsString=SpisokBrand->DM->ElementID_SBRAND->AsString;
	DM->ElementNAME_SBRAND->AsString=SpisokBrand->DM->ElementNAME_SBRAND->AsString;
	DM->Element->Post();


FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprModel::ViborProducer(void)
{
if(Prosmotr==true) return;
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
void TREM_FormaElementaSprModel::EventEndEditProdcer(void)
{

	DM->Element->Edit();
	DM->ElementIDPRODUCER_REM_SMODEL->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->ElementNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->Element->Post();

FormaSpiskaSprProducer=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::NameBrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDBRAND_REM_SMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::NameProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDPRODUCER_REM_SMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TREM_FormaElementaSprModel::ViborTypeDevice(void)
{
if(Prosmotr==true) return;
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
void TREM_FormaElementaSprModel::EndViborTypeDevice(void)
{

	DM->Element->Edit();
	DM->ElementIDTYPEDEVICE_REM_SMODEL->AsString=REM_FormaSpiskaSprTypeDevice->DM->TableID_REM_STYPEDEVICE->AsString;
	DM->ElementNAME_REM_STYPEDEVICE->AsString=REM_FormaSpiskaSprTypeDevice->DM->TableNAME_REM_STYPEDEVICE->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprTypeDevice=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::NameTypeDevicecxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDTYPEDEVICE_REM_SMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprModel::ViborActCategory(void)
{
if(Prosmotr==true) return;
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
void TREM_FormaElementaSprModel::EndViborActCategory(void)
{

	DM->Element->Edit();
	DM->ElementIDACTCATEGORY_REM_SMODEL->AsString=REM_FormaSpiskaSprActCategory->DM->TableID_REM_SACTCATEGORY->AsString;
	DM->ElementNAME_REM_SACTCATEGORY->AsString=REM_FormaSpiskaSprActCategory->DM->TableNAME_REM_SACTCATEGORY->AsString;
	DM->Element->Post();

REM_FormaSpiskaSprActCategory=0;

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprModel::NameActivecategorycxDBButtonEditPropertiesButtonClick(TObject *Sender,
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
		DM->ElementIDACTCATEGORY_REM_SMODEL->Clear();
		DM->Element->Post();
		}break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprModel::cxButtonTypRabotClick(TObject *Sender)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (REM_FormaSpiskaSprModelTypRabot==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprModelTypRabot,IID_IREM_FormaSpiskaSprModelTypRabot,
												 (void**)&REM_FormaSpiskaSprModelTypRabot);
		REM_FormaSpiskaSprModelTypRabot->Init(InterfaceMainObject,InterfaceImpl);
		REM_FormaSpiskaSprModelTypRabot->Vibor=false;
		REM_FormaSpiskaSprModelTypRabot->IdOwner=glStrToInt64(DM->ElementID_REM_SMODEL->AsString);
		REM_FormaSpiskaSprModelTypRabot->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SMODEL->AsString));
		REM_FormaSpiskaSprModelTypRabot->HeaderText="Свойства модели: "
		+DM->ElementNAME_REM_SMODEL->AsString;
		REM_FormaSpiskaSprModelTypRabot->NumberProcVibor=VR_ModelTypRabot	;
		}
}
//---------------------------------------------------------------------------

