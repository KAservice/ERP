//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprCountry.h"
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
__fastcall TDMSprCountry::TDMSprCountry(TComponent* Owner)
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
bool TDMSprCountry::Init(void)
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
int TDMSprCountry::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCountry::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TDMSprCountry::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprCountry::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMSprCountry::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprCountry::SaveElement()
{
bool result=false;
try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
        {
        Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprCountry::CloseElement()
{

        Element->CancelUpdates();
	   // IBTr->Rollback();
}
//---------------------------------------------------------------------------
bool TDMSprCountry::DeleteElement(__int64 Id)
{
bool result=true;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
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
				result=false;
                Error=true;
				TextError=exception.Message;
                }
		}
return result;
}
//---------------------------------------------------------------------------

__int64 TDMSprCountry::GetIDElement(String gid)
{
__int64 res=0;
        if (gid!="" || gid!=" " )
                {
				TpFIBQuery * query=new TpFIBQuery(0);
				try {

					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select ID_SCOUNTRY from SCOUNTRY where GID_SCOUNTRY=:PARAM_GID");
					query->ParamByName("PARAM_GID")->AsString=Trim(gid);
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					if (query->RecordCount==1)
						{
						res=query->FieldByName("ID_SCOUNTRY")->AsInt64;
						}
					else res=0;
					}
				__finally
					{
					delete query;
					}
				}  
return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprCountry::GetGIDElement(__int64 id)
{
AnsiString res=0;

		if (id!=0 )
				{
				TpFIBQuery * query=new TpFIBQuery(0);
				try {
					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select GID_SCOUNTRY from SCOUNTRY where ID_SCOUNTRY=:PARAM_ID");
					query->ParamByName("PARAM_ID")->AsInt64=id;
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					if (query->RecordCount==1)
						{
						res=Trim(query->FieldByName("GID_SCOUNTRY")->AsString);
						}
					else res="";
					}
				__finally
					{
					delete query;
					}
				}
return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCountry::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TDMSprCountry::GetIdPoName(UnicodeString name)
{
__int64 result=0;


				TpFIBQuery * query=new TpFIBQuery(0);
				try {
					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select ID_SCOUNTRY from SCOUNTRY where NAME_SCOUNTRY=:PARAM_NAME");
					query->ParamByName("PARAM_NAME")->AsString=name;
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					if (query->RecordCount==1)
						{
						result=glStrToInt64(Trim(query->FieldByName("ID_SCOUNTRY")->AsString));
						}
					else result=0;
					}
				__finally
					{
					delete query;
					}
return result;


}
//----------------------------------------------------------------------------

