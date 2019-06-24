//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNomAnalog.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprNomAnalog::TDMSprNomAnalog(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprNomAnalog::Init(void)
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
IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;


Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
SpisokTypeAnalog->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNomAnalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomAnalog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

bool  TDMSprNomAnalog::OpenTable(__int64 id_rod_element, __int64 id_type_price)
{
bool result=false;
IdRodElement=id_rod_element;

SpisokTypeAnalog->Active=false;
SpisokTypeAnalog->Active=true;


Table->Active=false;

Table->ParamByName("PARAM_ID_VLAD")->AsInt64=id_rod_element;
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=id_type_price;



try
		{
		Table->Open();
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

bool  TDMSprNomAnalog::NewElement(__int64 id_rod_element)
{
bool result=false;

IdRodElement=id_rod_element;


try
		{
		Element->Active=true;
		Element->Append();
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomAnalog::InsertElement(__int64 id_rod_element, __int64 id_nom)
{
bool result=false;
IdRodElement=id_rod_element;


if (NewElement(id_rod_element)==true)
	{
	Element->Edit();
	ElementIDNOM_SNOM_ANALOG->AsString=id_nom;
	Element->Post();
	if (SaveElement()==true)
		{
        result=true;
		}
	else
		{
		result=false;
		}
	}
else
	{
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------



bool TDMSprNomAnalog::OpenElement(__int64 id)
{
bool result=false;

        try
                {
				Element->Active=false;
				Element->ParamByName("PARAM_ID")->AsInt64=id;
				Element->Active=true;
				result=true;
                }
		catch(Exception &exception)
				{
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprNomAnalog::SaveElement(void)
{
bool res=false;
IdElement=glStrToInt64(ElementID_SNOM_ANALOG->AsString);

try
        {

		Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(IdElement);
		res=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		res=false;
		}

return res;

}
//--------------------------------------------------------------------------
bool TDMSprNomAnalog::DeleteElement(__int64 id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
				result=true;
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				result=false;
				}
		}

return result;
}
//----------------------------------------------------------------------------





bool  TDMSprNomAnalog::TableSaveIsmen(void)
{
bool result=false;

try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable(IdRodElement,IdTypePrice);
		result=true;
		}
catch(Exception &exception)
        {
		result=false;
		TextError=exception.Message;
		}

return result;
}
//---------------------------------------------------------------------------

bool  TDMSprNomAnalog::TableCancelIsmen()
{
bool result=false;
try
		{
		Table->CancelUpdates();
	   // IBTrUpdate->Commit();
		OpenTable(IdRodElement,IdTypePrice);
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//---------------------------------------------------------------------------
bool TDMSprNomAnalog::TableDelete(void)
{

bool result=false;
try
		{
		Table->Delete();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprNomAnalog::TableAppend(void)
{

bool result=false;
try
		{
		Table->Append();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprNomAnalog::TableEdit(void)
{

bool result=false;
try
		{
		Table->Edit();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//-----------------------------------------------------------------------------
bool TDMSprNomAnalog::TablePost(void)
{

bool result=false;
try
		{
		Table->Post();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TDMSprNomAnalog::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;   	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNomAnalog::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_SNOM_ANALOG->AsString=IdRodElement;


}
//---------------------------------------------------------------------------


void __fastcall TDMSprNomAnalog::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNOM_SNOM_ANALOG->AsString=IdRodElement;

}
//---------------------------------------------------------------------------
bool TDMSprNomAnalog::TableNewElement(__int64 id_rod_element)
{
bool result=false;

IdRodElement=id_rod_element;


try
		{
		Element->Active=false;
		Element->Append();
		result=true;
		}
catch(Exception &exception)
		{
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
