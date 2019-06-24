//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprTypeAnalog.h"
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
__fastcall TDMSprTypeAnalog::TDMSprTypeAnalog(TComponent* Owner)
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
bool TDMSprTypeAnalog::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprTypeAnalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprTypeAnalog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

bool  TDMSprTypeAnalog::OpenTable(void)
{
bool result=false;


Table->Active=false;

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

bool  TDMSprTypeAnalog::NewElement(void)
{
bool result=false;


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
bool TDMSprTypeAnalog::InsertElement(UnicodeString name)
{
bool result=false;

if (NewElement()==true)
	{
	Element->Edit();
	ElementNAME_STYPE_ANALOG->AsString=name;
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


bool TDMSprTypeAnalog::OpenElement(__int64 id)
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
bool TDMSprTypeAnalog::SaveElement(void)
{
bool res=false;
IdElement=glStrToInt64(ElementID_STYPE_ANALOG->AsString);

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
bool TDMSprTypeAnalog::DeleteElement(__int64 id)
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





bool  TDMSprTypeAnalog::TableSaveIsmen(void)
{
bool result=false;

try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable();
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

bool  TDMSprTypeAnalog::TableCancelIsmen()
{
bool result=false;
try
		{
		Table->CancelUpdates();
	   // IBTrUpdate->Commit();
		OpenTable();
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
bool TDMSprTypeAnalog::TableDelete(void)
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
bool TDMSprTypeAnalog::TableAppend(void)
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
bool TDMSprTypeAnalog::TableEdit(void)
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
bool TDMSprTypeAnalog::TablePost(void)
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
void __fastcall TDMSprTypeAnalog::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;   	
}
//---------------------------------------------------------------------------



bool TDMSprTypeAnalog::TableNewElement()
{
bool result=false;

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
