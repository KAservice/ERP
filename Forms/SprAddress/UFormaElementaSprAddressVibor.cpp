//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaElementaSprAddressVibor.h"
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
#pragma link "cxCalendar"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxCheckBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaElementaSprAddressVibor::TFormaElementaSprAddressVibor(TComponent* Owner)
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
bool TFormaElementaSprAddressVibor::Init(void)
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

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressRegion,IID_IDMSprAddressRegion, (void**)&DM_Region);
DM_Region->Init(InterfaceMainObject,InterfaceImpl);
RegioncxLookupComboBox->Properties->ListSource=DM_Region->DataSourceTable;



InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressRayon,IID_IDMSprAddressRayon, (void**)&DM_Rayon);
DM_Rayon->Init(InterfaceMainObject,InterfaceImpl);
RayoncxLookupComboBox->Properties->ListSource=DM_Rayon->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressNasPunkt,IID_IDMSprAddressNasPunkt, (void**)&DM_NasPunkt);
DM_NasPunkt->Init(InterfaceMainObject,InterfaceImpl);
NasPunktcxLookupComboBox->Properties->ListSource=DM_NasPunkt->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressStreet,IID_IDMSprAddressStreet, (void**)&DM_Street);
DM_Street->Init(InterfaceMainObject,InterfaceImpl);
StreetcxLookupComboBox->Properties->ListSource=DM_Street->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressDom,IID_IDMSprAddressDom, (void**)&DM_Dom);
DM_Dom->Init(InterfaceMainObject,InterfaceImpl);
DomcxLookupComboBox->Properties->ListSource=DM_Dom->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressStroen,IID_IDMSprAddressStroen, (void**)&DM_Stroen);
DM_Stroen->Init(InterfaceMainObject,InterfaceImpl);
StroencxLookupComboBox->Properties->ListSource=DM_Stroen->DataSourceTable;

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressKV,IID_IDMSprAddressKV, (void**)&DM_KV);
DM_KV->Init(InterfaceMainObject,InterfaceImpl);
KVcxLookupComboBox->Properties->ListSource=DM_KV->DataSourceTable;



//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//--------------------------------------------------------------------------
int TFormaElementaSprAddressVibor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaElementaSprAddressVibor::UpdateForm(void)
{
DM_Region->OpenTable();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprAddressVibor::FormClose(TObject *Sender,
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

DM_Region->kanRelease();
DM_Rayon->kanRelease();
DM_NasPunkt->kanRelease();
DM_Street->kanRelease();
DM_Dom->kanRelease();
DM_Stroen->kanRelease();
DM_KV->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------






void __fastcall TFormaElementaSprAddressVibor::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ActionOKExecute(TObject *Sender)
{

		if (DM_KV->Table->Active==true)
			{
			DM_KV->Table->First();
			DM_KV->Table->MoveBy(KVcxLookupComboBox->ItemIndex);
			if (glStrToInt64(DM_KV->TableID_SADR_KV->AsString) > 0)  //выбрана квартира
				{
				TypeEvent=1;
				}
			}

Close();


//if (DM->SaveElement()==true)
//		{
//		Close();
//		}
//else
//	{
//	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
//	}
}
//---------------------------------------------------------------------------
int TFormaElementaSprAddressVibor::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

if (number_procedure_end==ER_UpdateRegion)
		{

				//обновим регионы
				DM_Region->OpenTable();


		}

if (number_procedure_end==ER_UpdateRayon)
		{

				//обновим районы
				DM_Rayon->OpenTable(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString));


		}

if (number_procedure_end==ER_UpdateNasPunkt)
		{
				//обновим районы
				DM_NasPunkt->OpenTable(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString));
		}

if (number_procedure_end==ER_UpdateStreet)
		{
				//обновим районы
				DM_Street->OpenTable(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString));
		}

if (number_procedure_end==ER_UpdateDom)
		{
				//обновим районы
				DM_Dom->OpenTable(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString));
		}

if (number_procedure_end==ER_UpdateStroen)
		{
				//обновим районы
				DM_Stroen->OpenTable(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString));
		}

if (number_procedure_end==ER_UpdateKV)
		{
				//обновим районы
				DM_KV->OpenTable(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString));
		}
return -1;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaElementaSprAddressVibor::ButtonInsRegionClick(TObject *Sender)

{
IFormaElementaSprAddressRegion *FormaElementaSprAddressRegion;
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressRegion,IID_IFormaElementaSprAddressRegion,
													(void**)&FormaElementaSprAddressRegion);
		FormaElementaSprAddressRegion->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressRegion) return;
		FormaElementaSprAddressRegion->Vibor=true;
		FormaElementaSprAddressRegion->NumberProcVibor=ER_UpdateRegion;
		if (FormaElementaSprAddressRegion->DM->NewElement()==true)
			{
			FormaElementaSprAddressRegion->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressRegion->DM->TextError);
			}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdRegionClick(TObject *Sender)

{
IFormaElementaSprAddressRegion *FormaElementaSprAddressRegion;

		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressRegion,IID_IFormaElementaSprAddressRegion,
													(void**)&FormaElementaSprAddressRegion);
		FormaElementaSprAddressRegion->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressRegion) return;
		FormaElementaSprAddressRegion->Vibor=true;
		FormaElementaSprAddressRegion->NumberProcVibor=ER_UpdateRegion;

		if (DM_Region->Table->Active==true)
			{
			DM_Region->Table->First();
			DM_Region->Table->MoveBy(RegioncxLookupComboBox->ItemIndex);
			}

		if (FormaElementaSprAddressRegion->DM->OpenElement(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString))==true)
			{
			FormaElementaSprAddressRegion->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressRegion->DM->TextError);
			}

}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelRegionClick(TObject *Sender)

{
IDMSprAddressRegion *DMSprAddressRegion;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressRegion,IID_IDMSprAddressRegion,
													(void**)&DMSprAddressRegion);
		DMSprAddressRegion->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressRegion) return;

		if (DM_Region->Table->Active==true)
			{
			DM_Region->Table->First();
			DM_Region->Table->MoveBy(RegioncxLookupComboBox->ItemIndex);
			}

		if (DMSprAddressRegion->DeleteElement(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressRegion->TextError);
			}
DMSprAddressRegion->kanRelease();
DM_Region->OpenTable();
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprAddressVibor::RegioncxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_Region->Table->Active==true)
	{
	DM_Region->Table->First();
	DM_Region->Table->MoveBy(RegioncxLookupComboBox->ItemIndex);
	DM_Rayon->OpenTable(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString));
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaElementaSprAddressVibor::ButtonInsRayonClick(TObject *Sender)

{


if (DM_Region->Table->Active==false)  return;

DM_Region->Table->First();
DM_Region->Table->MoveBy(RegioncxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Region->TableID_SADR_REGION->AsString) == 0) return;


		IFormaElementaSprAddressRayon *FormaElementaSprAddressRayon;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressRayon,IID_IFormaElementaSprAddressRayon,
													(void**)&FormaElementaSprAddressRayon);
		FormaElementaSprAddressRayon->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressRayon) return;
		FormaElementaSprAddressRayon->Vibor=true;
		FormaElementaSprAddressRayon->NumberProcVibor=ER_UpdateRayon;
		if (FormaElementaSprAddressRayon->DM->NewElement(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString))==true)
			{
			FormaElementaSprAddressRayon->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressRayon->DM->TextError);
			}


}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdRayonClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;

DM_Rayon->Table->First();
DM_Rayon->Table->MoveBy(RayoncxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString) == 0) return;


		IFormaElementaSprAddressRayon *FormaElementaSprAddressRayon;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressRayon,IID_IFormaElementaSprAddressRayon,
													(void**)&FormaElementaSprAddressRayon);
		FormaElementaSprAddressRayon->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressRayon) return;
		FormaElementaSprAddressRayon->Vibor=true;
		FormaElementaSprAddressRayon->NumberProcVibor=ER_UpdateRayon;
		if (FormaElementaSprAddressRayon->DM->OpenElement(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString))==true)
			{
			FormaElementaSprAddressRayon->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressRayon->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelRayonClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;


DM_Rayon->Table->First();
DM_Rayon->Table->MoveBy(RayoncxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString) == 0) return;

IDMSprAddressRayon *DMSprAddressRayon;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressRayon,IID_IDMSprAddressRayon,
													(void**)&DMSprAddressRayon);
		DMSprAddressRayon->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressRayon) return;

		if (DMSprAddressRayon->DeleteElement(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressRayon->TextError);
			}
DMSprAddressRayon->kanRelease();

DM_Rayon->OpenTable(glStrToInt64(DM_Region->TableID_SADR_REGION->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::RayoncxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_Rayon->Table->Active==true)
	{
	DM_Rayon->Table->First();
	DM_Rayon->Table->MoveBy(RayoncxLookupComboBox->ItemIndex);
	DM_NasPunkt->OpenTable(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonInsNasPunktClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;

DM_Rayon->Table->First();
DM_Rayon->Table->MoveBy(RayoncxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString) == 0) return;


		IFormaElementaSprAddressNasPunkt *FormaElementaSprAddressNasPunkt;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressNasPunkt,IID_IFormaElementaSprAddressNasPunkt,
													(void**)&FormaElementaSprAddressNasPunkt);
		FormaElementaSprAddressNasPunkt->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressNasPunkt) return;
		FormaElementaSprAddressNasPunkt->Vibor=true;
		FormaElementaSprAddressNasPunkt->NumberProcVibor=ER_UpdateNasPunkt;
		if (FormaElementaSprAddressNasPunkt->DM->NewElement(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString))==true)
			{
			FormaElementaSprAddressNasPunkt->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressNasPunkt->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdNasPunktClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;

DM_NasPunkt->Table->First();
DM_NasPunkt->Table->MoveBy(NasPunktcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString) == 0) return;


		IFormaElementaSprAddressNasPunkt *FormaElementaSprAddressNasPunkt;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressNasPunkt,IID_IFormaElementaSprAddressNasPunkt,
													(void**)&FormaElementaSprAddressNasPunkt);
		FormaElementaSprAddressNasPunkt->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressNasPunkt) return;
		FormaElementaSprAddressNasPunkt->Vibor=true;
		FormaElementaSprAddressNasPunkt->NumberProcVibor=ER_UpdateNasPunkt;
		if (FormaElementaSprAddressNasPunkt->DM->OpenElement(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString))==true)
			{
			FormaElementaSprAddressNasPunkt->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressNasPunkt->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelNasPunktClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;

DM_NasPunkt->Table->First();
DM_NasPunkt->Table->MoveBy(NasPunktcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString) == 0) return;

IDMSprAddressNasPunkt *DMSprAddressNasPunkt;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressNasPunkt,IID_IDMSprAddressNasPunkt,
													(void**)&DMSprAddressNasPunkt);
		DMSprAddressNasPunkt->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressNasPunkt) return;

		if (DMSprAddressNasPunkt->DeleteElement(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressNasPunkt->TextError);
			}
DMSprAddressNasPunkt->kanRelease();

DM_NasPunkt->OpenTable(glStrToInt64(DM_Rayon->TableID_SADR_RAYON->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::NasPunktcxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_NasPunkt->Table->Active==true)
	{
	DM_NasPunkt->Table->First();
	DM_NasPunkt->Table->MoveBy(NasPunktcxLookupComboBox->ItemIndex);
	DM_Street->OpenTable(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonInsStreetClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;

DM_NasPunkt->Table->First();
DM_NasPunkt->Table->MoveBy(NasPunktcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString) == 0) return;


		IFormaElementaSprAddressStreet *FormaElementaSprAddressStreet;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressStreet,IID_IFormaElementaSprAddressStreet,
													(void**)&FormaElementaSprAddressStreet);
		FormaElementaSprAddressStreet->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressStreet) return;
		FormaElementaSprAddressStreet->Vibor=true;
		FormaElementaSprAddressStreet->NumberProcVibor=ER_UpdateStreet;
		if (FormaElementaSprAddressStreet->DM->NewElement(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString))==true)
			{
			FormaElementaSprAddressStreet->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressStreet->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdStreetClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;

DM_Street->Table->First();
DM_Street->Table->MoveBy(StreetcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Street->TableID_SADR_STREET->AsString) == 0) return;


		IFormaElementaSprAddressStreet *FormaElementaSprAddressStreet;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressStreet,IID_IFormaElementaSprAddressStreet,
													(void**)&FormaElementaSprAddressStreet);
		FormaElementaSprAddressStreet->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressStreet) return;
		FormaElementaSprAddressStreet->Vibor=true;
		FormaElementaSprAddressStreet->NumberProcVibor=ER_UpdateStreet;
		if (FormaElementaSprAddressStreet->DM->OpenElement(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString))==true)
			{
			FormaElementaSprAddressStreet->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressStreet->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelStreetClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;

DM_Street->Table->First();
DM_Street->Table->MoveBy(StreetcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Street->TableID_SADR_STREET->AsString) == 0) return;

IDMSprAddressStreet *DMSprAddressStreet;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressStreet,IID_IDMSprAddressStreet,
													(void**)&DMSprAddressStreet);
		DMSprAddressStreet->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressStreet) return;

		if (DMSprAddressStreet->DeleteElement(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressStreet->TextError);
			}
DMSprAddressStreet->kanRelease();

DM_Street->OpenTable(glStrToInt64(DM_NasPunkt->TableID_SADR_NASPUNKT->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::StreetcxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_Street->Table->Active==true)
	{
	DM_Street->Table->First();
	DM_Street->Table->MoveBy(StreetcxLookupComboBox->ItemIndex);
	DM_Dom->OpenTable(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonAddDomClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;

DM_Street->Table->First();
DM_Street->Table->MoveBy(StreetcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Street->TableID_SADR_STREET->AsString) == 0) return;


		IFormaElementaSprAddressDom *FormaElementaSprAddressDom;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressDom,IID_IFormaElementaSprAddressDom,
													(void**)&FormaElementaSprAddressDom);
		FormaElementaSprAddressDom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressDom) return;
		FormaElementaSprAddressDom->Vibor=true;
		FormaElementaSprAddressDom->NumberProcVibor=ER_UpdateDom;
		if (FormaElementaSprAddressDom->DM->NewElement(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString))==true)
			{
			FormaElementaSprAddressDom->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressDom->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdDomClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;

DM_Dom->Table->First();
DM_Dom->Table->MoveBy(DomcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString) == 0) return;


		IFormaElementaSprAddressDom *FormaElementaSprAddressDom;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressDom,IID_IFormaElementaSprAddressDom,
													(void**)&FormaElementaSprAddressDom);
		FormaElementaSprAddressDom->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressDom) return;
		FormaElementaSprAddressDom->Vibor=true;
		FormaElementaSprAddressDom->NumberProcVibor=ER_UpdateDom;
		if (FormaElementaSprAddressDom->DM->OpenElement(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString))==true)
			{
			FormaElementaSprAddressDom->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressDom->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelDomClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;

DM_Dom->Table->First();
DM_Dom->Table->MoveBy(DomcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString) == 0) return;

IDMSprAddressDom *DMSprAddressDom;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressDom,IID_IDMSprAddressDom,
													(void**)&DMSprAddressDom);
		DMSprAddressDom->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressDom) return;

		if (DMSprAddressDom->DeleteElement(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressDom->TextError);
			}
DMSprAddressDom->kanRelease();

DM_Dom->OpenTable(glStrToInt64(DM_Street->TableID_SADR_STREET->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::DomcxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_Dom->Table->Active==true)
	{
	DM_Dom->Table->First();
	DM_Dom->Table->MoveBy(DomcxLookupComboBox->ItemIndex);
	DM_Stroen->OpenTable(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonInsStroenClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;

DM_Dom->Table->First();
DM_Dom->Table->MoveBy(DomcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString) == 0) return;


		IFormaElementaSprAddressStroen *FormaElementaSprAddressStroen;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressStroen,IID_IFormaElementaSprAddressStroen,
													(void**)&FormaElementaSprAddressStroen);
		FormaElementaSprAddressStroen->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressStroen) return;
		FormaElementaSprAddressStroen->Vibor=true;
		FormaElementaSprAddressStroen->NumberProcVibor=ER_UpdateStroen;
		if (FormaElementaSprAddressStroen->DM->NewElement(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString))==true)
			{
			FormaElementaSprAddressStroen->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressStroen->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdStroenClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;
if (DM_Stroen->Table->Active==false)  return;

DM_Stroen->Table->First();
DM_Stroen->Table->MoveBy(StroencxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString) == 0) return;


		IFormaElementaSprAddressStroen *FormaElementaSprAddressStroen;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressStroen,IID_IFormaElementaSprAddressStroen,
													(void**)&FormaElementaSprAddressStroen);
		FormaElementaSprAddressStroen->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressStroen) return;
		FormaElementaSprAddressStroen->Vibor=true;
		FormaElementaSprAddressStroen->NumberProcVibor=ER_UpdateStroen;
		if (FormaElementaSprAddressStroen->DM->OpenElement(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString))==true)
			{
			FormaElementaSprAddressStroen->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressStroen->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelStroenClick(TObject *Sender)

{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;
if (DM_Stroen->Table->Active==false)  return;

DM_Stroen->Table->First();
DM_Stroen->Table->MoveBy(StroencxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString) == 0) return;

IDMSprAddressStroen *DMSprAddressStroen;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressStroen,IID_IDMSprAddressStroen,
													(void**)&DMSprAddressStroen);
		DMSprAddressStroen->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressStroen) return;

		if (DMSprAddressStroen->DeleteElement(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressStroen->TextError);
			}
DMSprAddressStroen->kanRelease();

DM_Stroen->OpenTable(glStrToInt64(DM_Dom->TableID_SADR_DOM->AsString));
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::StroencxLookupComboBoxPropertiesChange(TObject *Sender)

{
if (DM_Stroen->Table->Active==true)
	{
	DM_Stroen->Table->First();
	DM_Stroen->Table->MoveBy(StroencxLookupComboBox->ItemIndex);
	DM_KV->OpenTable(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonInsKVClick(TObject *Sender)
{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;
if (DM_Stroen->Table->Active==false)  return;

DM_Stroen->Table->First();
DM_Stroen->Table->MoveBy(StroencxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString) == 0) return;


		IFormaElementaSprAddressKV *FormaElementaSprAddressKV;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressKV,IID_IFormaElementaSprAddressKV,
													(void**)&FormaElementaSprAddressKV);
		FormaElementaSprAddressKV->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressKV) return;
		FormaElementaSprAddressKV->Vibor=true;
		FormaElementaSprAddressKV->NumberProcVibor=ER_UpdateKV;
		if (FormaElementaSprAddressKV->DM->NewElement(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString))==true)
			{
			FormaElementaSprAddressKV->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressKV->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonUpdKVClick(TObject *Sender)
{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;
if (DM_Stroen->Table->Active==false)  return;
if (DM_KV->Table->Active==false)  return;

DM_KV->Table->First();
DM_KV->Table->MoveBy(KVcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_KV->TableID_SADR_KV->AsString) == 0) return;


		IFormaElementaSprAddressKV *FormaElementaSprAddressKV;
		InterfaceGlobalCom->kanCreateObject(ProgId_FormaElementaSprAddressKV,IID_IFormaElementaSprAddressKV,
													(void**)&FormaElementaSprAddressKV);
		FormaElementaSprAddressKV->Init(InterfaceMainObject,InterfaceImpl);
		if (!FormaElementaSprAddressKV) return;
		FormaElementaSprAddressKV->Vibor=true;
		FormaElementaSprAddressKV->NumberProcVibor=ER_UpdateKV;
		if (FormaElementaSprAddressKV->DM->OpenElement(glStrToInt64(DM_KV->TableID_SADR_KV->AsString))==true)
			{
			FormaElementaSprAddressKV->UpdateForm();
			}
		else
			{
			ShowMessage("Ошибка "+FormaElementaSprAddressKV->DM->TextError);
			}
}
//---------------------------------------------------------------------------

void __fastcall TFormaElementaSprAddressVibor::ButtonDelKVClick(TObject *Sender)
{
if (DM_Region->Table->Active==false)  return;
if (DM_Rayon->Table->Active==false)  return;
if (DM_NasPunkt->Table->Active==false)  return;
if (DM_Street->Table->Active==false)  return;
if (DM_Dom->Table->Active==false)  return;
if (DM_Stroen->Table->Active==false)  return;
if (DM_KV->Table->Active==false)  return;

DM_KV->Table->First();
DM_KV->Table->MoveBy(KVcxLookupComboBox->ItemIndex);
if (glStrToInt64(DM_KV->TableID_SADR_KV->AsString) == 0) return;

IDMSprAddressKV *DMSprAddressKV;

		InterfaceGlobalCom->kanCreateObject(ProgId_DMSprAddressKV,IID_IDMSprAddressKV,
													(void**)&DMSprAddressKV);
		DMSprAddressKV->Init(InterfaceMainObject,InterfaceImpl);
		if (!DMSprAddressKV) return;

		if (DMSprAddressKV->DeleteElement(glStrToInt64(DM_KV->TableID_SADR_KV->AsString))==true)
			{

			}
		else
			{
			ShowMessage("Ошибка "+DMSprAddressKV->TextError);
			}
DMSprAddressKV->kanRelease();

DM_KV->OpenTable(glStrToInt64(DM_Stroen->TableID_SADR_STROEN->AsString));
}
//---------------------------------------------------------------------------

