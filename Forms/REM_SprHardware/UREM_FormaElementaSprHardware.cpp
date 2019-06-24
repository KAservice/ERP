//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaElementaSprHardware.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IREM_FormaZayavka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxCalc"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLabel"
#pragma link "cxPC"
#pragma link "cxButtonEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxButtons"
#pragma link "cxMemo"
#pragma link "cxImageComboBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxDBLabel"
#pragma link "cxCalendar"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprHardware::TREM_FormaElementaSprHardware(TComponent* Owner)
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
bool TREM_FormaElementaSprHardware::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMSprHardware.1",IID_IREM_DMSprHardware,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

OwnercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SuppliercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

NamecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

NameModelcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
SerNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NameVladcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SalecxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
WarrantycxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

DocPostcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
DocSalecxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
CodecxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;

SerNumbercxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SerNum2cxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
SerNumStrcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;


SrokWarrantycxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
PrimcxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
NecondcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
PricecxDBCalcEdit->DataBinding->DataSource=DM->DataSourceElement;
PrichinacxDBTextEdit->DataBinding->DataSource=DM->DataSourceElement;
FlRemontcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
FlFictRemontcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;

TypeElementacxDBImageComboBox->DataBinding->DataSource=DM->DataSourceElement;
flActcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
flUtilizcxDBCheckBox->DataBinding->DataSource=DM->DataSourceElement;
ProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
BrandcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
ZayavkacxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
ModelProducercxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;

PostupilocxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
UtilizirovanocxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;
HranitDocxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;

ModelZcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
PrefikscxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
PosZcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;
SerNumcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;

IDcxDBLabel->DataBinding->DataSource=DM->DataSourceElement;


cxDBTextEditARTIKUL_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditSERNUM3_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditSERNUM4_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditNUMBAT_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditNUMGARTALON_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditSWCODE_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditHWCODE_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditVERPO_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditPARTNUM_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditMTM_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditFRU_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBTextEditCRU_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;

cxDBCheckBoxFL_OTCH_PROIZV_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;
cxDBCheckBoxFL_NO_RAZBOR_REM_SHARDWARE->DataBinding->DataSource=DM->DataSourceElement;


DM_Connection->GetPrivForm(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

SaveElement=false;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprHardware::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::FormClose(TObject *Sender,
      TCloseAction &Action)
{

if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaGurAllDoc)FormaGurAllDoc->kanRelease();
if(FormaSpiskaSprModel)FormaSpiskaSprModel->kanRelease();

if(FormaSpiskaSprProducerModel) FormaSpiskaSprProducerModel->kanRelease();
if(FormaSpiskaSprBrand) FormaSpiskaSprBrand->kanRelease();
if(FormaSpiskaSprProducer) FormaSpiskaSprProducer->kanRelease();
if(FormaGurZ) FormaGurZ->kanRelease();
if(FormaSpiskaSprHardwareIsp)FormaSpiskaSprHardwareIsp->kanRelease();


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
void TREM_FormaElementaSprHardware::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprHardware::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_ViborSupplier)
	{
	if (type_event==1)
		{
		EndViborSupplier();
		}
	}

if (number_procedure_end==ER_ViborOwner)
	{
	if (type_event==1)
		{
		EndViborOwner();
		}
	}

if (number_procedure_end==ER_ViborDocPost)
	{
	if (type_event==1)
		{
		EndViborDocPost();
		}
	}

if (number_procedure_end==ER_ViborDocSale)
	{
	if (type_event==1)
		{
		EndViborDocSale();
		}
	}

if (number_procedure_end==ER_ViborModel)
	{
	if (type_event==1)
		{
		EndViborModel();
		}
	}

if (number_procedure_end==ER_ViborHardwareIsp)
	{
	if (type_event==1)
		{
		EndViborViborHardwareIsp();
		}
	FormaSpiskaSprHardwareIsp=0;
	}

if (number_procedure_end==ER_ViborBrand)
	{
	if (type_event==1)
		{
		EndViborBrand();
		}
	}

if (number_procedure_end==ER_ViborProducer)
	{
	if (type_event==1)
		{
		EndViborProducer();
		}
	}

if (number_procedure_end==ER_ViborZ)
	{
	if (type_event==1)
		{
		EndViborZ();
		}
	}

if (number_procedure_end==ER_ViborProducerModel)
	{
	if (type_event==1)
		{
		EndViborProducerModel();
		}
	}

return -1;
}
//-----------------------------------------------------------------------------







void __fastcall TREM_FormaElementaSprHardware::ActionCloseElementExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void TREM_FormaElementaSprHardware::ViborSupplier(void)
{

if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprKlient) return;
	FormaSpiskaSprKlient->NumberProcVibor=ER_ViborSupplier;
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::EndViborSupplier(void)
{

	DM->Element->Edit();
	DM->ElementIDPOST_REM_SHARDWARE->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementSUPPLIER_NAME->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

FormaSpiskaSprKlient=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}

//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborOwner(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
												 (void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprKlient) return;
	FormaSpiskaSprKlient->NumberProcVibor=ER_ViborOwner;
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::EndViborOwner(void)
{

	DM->Element->Edit();
	DM->ElementIDVLAD_REM_SHARDWARE->AsString=FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString;
	DM->ElementOWNER_NAME->AsString=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	DM->Element->Post();

FormaSpiskaSprKlient=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------



void __fastcall TREM_FormaElementaSprHardware::SuppliercxDBButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
ViborSupplier();	
}
//---------------------------------------------------------------------------







void __fastcall TREM_FormaElementaSprHardware::ActionSaveElementExecute(TObject *Sender)

{
if (DM->SaveElement()==true)
	{
	SaveElement=true;
	UpdateForm();

	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::ActionOKExecute(TObject *Sender)
{
TypeEvent=1;
if (DM->SaveElement()==true)
	{
	Close();
	}
else
	{
	ShowMessage("Ошибка при записи!"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void TREM_FormaElementaSprHardware::ViborDocPost(void)
{

if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
												 (void**)&FormaGurAllDoc);
	FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaGurAllDoc) return;
	FormaGurAllDoc->NumberProcVibor=ER_ViborDocPost;
	FormaGurAllDoc->Vibor=true;
	FormaGurAllDoc->UpdateForm();
	}
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::EndViborDocPost(void)
{

	DM->Element->Edit();
	DM->ElementIDDOCPOST_REM_SHARDWARE->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
	DM->ElementNUMDOC_DOCPOST->AsInteger=FormaGurAllDoc->DM->TableNUMDOC->AsInteger;
	DM->ElementPOSDOC_DOCPOST->AsDateTime=FormaGurAllDoc->DM->TablePOSDOC->AsDateTime;
    DM->ElementTDOC_DOCPOST->AsString=FormaGurAllDoc->DM->TableTDOC->AsString;
	DM->Element->Post();

FormaGurAllDoc=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}

//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborDocSale(void)
{
if (FormaGurAllDoc==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaGurAllDoc.1",IID_IFormaGurAllDoc,
												 (void**)&FormaGurAllDoc);
	FormaGurAllDoc->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaGurAllDoc) return;
	FormaGurAllDoc->NumberProcVibor=ER_ViborDocSale;
	FormaGurAllDoc->Vibor=true;
	FormaGurAllDoc->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::EndViborDocSale(void)
{

	DM->Element->Edit();
	DM->ElementIDDOCSALE_REM_SHARDWARE->AsString=FormaGurAllDoc->DM->TableIDDOC->AsString;
	DM->ElementNUMDOC_DOCSALE->AsInteger=FormaGurAllDoc->DM->TableNUMDOC->AsInteger;
	DM->ElementPOSDOC_DOCSALE->AsDateTime=FormaGurAllDoc->DM->TablePOSDOC->AsDateTime;
	DM->ElementTDOC_DOCSALE->AsString=FormaGurAllDoc->DM->TableTDOC->AsString;
	DM->Element->Post();

FormaGurAllDoc=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprHardware::DocPostcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborDocPost();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::DocSalecxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborDocSale();
}
//---------------------------------------------------------------------------

void TREM_FormaElementaSprHardware::ViborModel(void)
{
if (FormaSpiskaSprModel==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaSpSprModel.1",IID_IREM_FormaSpiskaSprModel,
												 (void**)&FormaSpiskaSprModel);
	FormaSpiskaSprModel->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprModel) return;
	FormaSpiskaSprModel->NumberProcVibor=ER_ViborModel;
	FormaSpiskaSprModel->Vibor=true;
	FormaSpiskaSprModel->UpdateForm();
	}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::EndViborModel(void)
{
	DM->Element->Edit();
	DM->ElementIDMODEL_REM_SHARDWARE->AsString=FormaSpiskaSprModel->DM->TableID_REM_SMODEL->AsString;
	DM->ElementNAME_REM_SMODEL->AsString=FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
	DM->ElementNAME_REM_SHARDWARE->AsString=FormaSpiskaSprModel->DM->TableNAME_REM_SMODEL->AsString;
	DM->Element->Post();

FormaSpiskaSprModel=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();

}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::NameModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborModel();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject > 0)
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

void __fastcall TREM_FormaElementaSprHardware::FormDeactivate(TObject *Sender)
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
void __fastcall TREM_FormaElementaSprHardware::ReadShtrihCodEvent(int number, UnicodeString sh)
{


if (SerNumbercxDBTextEdit->Focused()==true)
	{
	DM->Element->Edit();
	DM->ElementSERNUM_REM_SHARDWARE->AsString=sh;
	DM->ElementSERNUM_STR_REM_SHARDWARE->AsString=DM->ElementSERNUM_STR_REM_SHARDWARE->AsString
					+sh;
	DM->Element->Post();
	}
else if (SerNum2cxDBTextEdit->Focused()==true)
	{
	DM->Element->Edit();
	DM->ElementSERNUM2_REM_SHARDWARE->AsString=sh;
	DM->ElementSERNUM_STR_REM_SHARDWARE->AsString=DM->ElementSERNUM_STR_REM_SHARDWARE->AsString
					+";"+sh;
	DM->Element->Post();
	}
else if (SerNumStrcxDBTextEdit->Focused()==true)
	{
	DM->Element->Edit();
	DM->ElementSERNUM_STR_REM_SHARDWARE->AsString=DM->ElementSERNUM_STR_REM_SHARDWARE->AsString
					+";"+sh;
	DM->Element->Post();
	}
}
//-----------------------------------------------------------------------------

void TREM_FormaElementaSprHardware::ViborProducerModel(void)
{
if (FormaSpiskaSprProducerModel==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprProducerModel,IID_IREM_FormaSpiskaSprProducerModel,
												 (void**)&FormaSpiskaSprProducerModel);
	FormaSpiskaSprProducerModel->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprProducerModel) return;
	FormaSpiskaSprProducerModel->NumberProcVibor=ER_ViborProducerModel;
	FormaSpiskaSprProducerModel->flVibor=true;
	FormaSpiskaSprProducerModel->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void  TREM_FormaElementaSprHardware::EndViborProducerModel(void)
{

	DM->Element->Edit();
	DM->ElementIDPRMODEL_REM_SHARDWARE->AsString=FormaSpiskaSprProducerModel->DM->TableID_REM_SPRMODEL->AsString;
	DM->ElementNAME_REM_SPRMODEL->AsString=FormaSpiskaSprProducerModel->DM->TableNAME_REM_SPRMODEL->AsString;
	DM->Element->Post();

FormaSpiskaSprProducerModel=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborBrand(void)
{
if (FormaSpiskaSprBrand==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprBrand,IID_IFormaSpiskaSprBrand,
												 (void**)&FormaSpiskaSprBrand);
	FormaSpiskaSprBrand->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprBrand) return;
	FormaSpiskaSprBrand->NumberProcVibor=ER_ViborBrand;
	FormaSpiskaSprBrand->Vibor=true;
	FormaSpiskaSprBrand->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void  TREM_FormaElementaSprHardware::EndViborBrand(void)
{

	DM->Element->Edit();
	DM->ElementIDBRAND_REM_SHARDWARE->AsString=FormaSpiskaSprBrand->DM->TableID_SBRAND->AsString;
	DM->ElementNAME_SBRAND->AsString=FormaSpiskaSprBrand->DM->TableNAME_SBRAND->AsString;
	DM->Element->Post();

FormaSpiskaSprBrand=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborProducer(void)
{
if (FormaSpiskaSprProducer==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_FormaSpiskaSprProducer,IID_IFormaSpiskaSprProducer,
												 (void**)&FormaSpiskaSprProducer);
	FormaSpiskaSprProducer->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaSpiskaSprProducer) return;
	FormaSpiskaSprProducer->NumberProcVibor=ER_ViborProducer;
	FormaSpiskaSprProducer->Vibor=true;
	//FormaSpiskaSprProducer->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void  TREM_FormaElementaSprHardware::EndViborProducer(void)
{

	DM->Element->Edit();
	DM->ElementIDPRODUCER_REM_SHARDWARE->AsString=FormaSpiskaSprProducer->DM->TableID_SPRODUCER->AsString;
	DM->ElementNAME_SPRODUCER->AsString=FormaSpiskaSprProducer->DM->TableNAME_SPRODUCER->AsString;
	DM->Element->Post();

FormaSpiskaSprProducer=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborZ(void)
{
if (FormaGurZ==0)
	{
	InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaGurZ,IID_IREM_FormaGurZ,
												 (void**)&FormaGurZ);
	FormaGurZ->Init(InterfaceMainObject,InterfaceImpl);
	if (!FormaGurZ) return;
	FormaGurZ->NumberProcVibor=ER_ViborZ;
	FormaGurZ->Vibor=true;
	//FormaGurZ->UpdateForm();
	}

}
//----------------------------------------------------------------------------
void  TREM_FormaElementaSprHardware::EndViborZ(void)
{

	DM->Element->Edit();
	DM->ElementIDZ_REM_SHARDWARE->AsString=FormaGurZ->DM->TableID_REM_Z->AsString;
	DM->ElementNAME_REM_Z->AsString=FormaGurZ->DM->TableNAME_REM_Z->AsString;
	DM->ElementSERNUM_REM_SHARDWARE->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->ElementSERNUM2_REM_SHARDWARE->AsString=FormaGurZ->DM->TableSERNUM2_REM_Z->AsString;

	DM->ElementPREFIKS_NUM_REM_Z->AsString=FormaGurZ->DM->TablePREFIKS_NUM_REM_Z->AsString;
	DM->ElementNUM_REM_Z->AsInteger=FormaGurZ->DM->TableNUM_REM_Z->AsInteger;
	DM->ElementPOS_REM_Z->AsDateTime=FormaGurZ->DM->TablePOS_REM_Z->AsDateTime;
	DM->ElementSERNUM_REM_Z->AsString=FormaGurZ->DM->TableSERNUM_REM_Z->AsString;
	DM->ElementMODEL_REM_Z->AsString=FormaGurZ->DM->TableMODEL_REM_Z->AsString;

	DM->Element->Post();

FormaGurZ=0;
FindNextControl(ActiveControl,true,true,false)->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprHardware::BrandcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborBrand();
}
//---------------------------------------------------------------------------


void __fastcall TREM_FormaElementaSprHardware::OwnercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborOwner();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducer();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::ZayavkacxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborZ();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::ModelProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborProducerModel();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::cxButtonIspZapchastiClick(TObject *Sender)

{
ViborHardwareIsp();
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::ViborHardwareIsp(void)

{
///*****
if (SaveElement==false)
		{
		ShowMessage("Необходимо записать элемент!");
		return;
		}


if (FormaSpiskaSprHardwareIsp==NULL)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaSpiskaSprHardwareIsp,IID_IREM_FormaSpiskaSprHardwareIsp,
												 (void**)&FormaSpiskaSprHardwareIsp);
		FormaSpiskaSprHardwareIsp->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprHardwareIsp->Vibor=false;
		FormaSpiskaSprHardwareIsp->IdOwner=glStrToInt64(DM->ElementID_REM_SHARDWARE->AsString);
		FormaSpiskaSprHardwareIsp->DM->OpenTable(glStrToInt64(DM->ElementID_REM_SHARDWARE->AsString));
		FormaSpiskaSprHardwareIsp->TextMessage="Использовнные запчасти: "
		+DM->ElementNAME_REM_SHARDWARE->AsString;
		FormaSpiskaSprHardwareIsp->NumberProcVibor=ER_ViborHardwareIsp;
		}
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprHardware::EndViborViborHardwareIsp(void)
{


}
//----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprHardware::cxButtonOpenZClick(TObject *Sender)
{
IREM_FormaZayavka * REM_FormaZayavka;
InterfaceGlobalCom->kanCreateObject("Oberon.REM_FormaZayavka.1",IID_IREM_FormaZayavka,
								 (void**)&REM_FormaZayavka);
REM_FormaZayavka->Init(InterfaceMainObject,InterfaceImpl);
if (!REM_FormaZayavka) return;
REM_FormaZayavka->DM->OpenDoc(glStrToInt64(DM->ElementIDZ_REM_SHARDWARE->AsString));
REM_FormaZayavka->UpdateForm();
}
//---------------------------------------------------------------------------

