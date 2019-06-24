//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprProgramModule.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprProgramModule::TDMSprProgramModule(TComponent* Owner)
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
bool TDMSprProgramModule::Init(void)
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
Query->Database=DM_Connection->pFIBData;

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
int TDMSprProgramModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProgramModule::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProgramModule::Table1CalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void  TDMSprProgramModule::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprProgramModule::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprProgramModule::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprProgramModule::SaveElement()
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
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMSprProgramModule::DeleteElement(__int64 id)
{
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
                }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
        }
}
//-----------------------------------------------------------------
__int64 TDMSprProgramModule::GetIDElement(String gid)
{
__int64 res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {
        if (gid!="" || gid!=" " )
                {
				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select ID_PROGRAM_MODULE from PROGRAM_MODULE where GID_PROGRAM_MODULE=:PARAM_GID");
				query->ParamByName("PARAM_GID")->AsString=Trim(gid);
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=query->FieldByName("ID_SSCALE")->AsInt64;
                        }
				else res=0;
				}
        }
__finally
	{
	delete query;
	res=0;
	}

return res;
}
//---------------------------------------------------------------------------
//получить GUID по ProgId
GUID TDMSprProgramModule::GetCLSIDFromProgID(UnicodeString prog_id)
{
GUID result=StringToGUID("");

Query->Close();
UnicodeString zapros="select program_module.guid_program_module    \
						from program_module                        \
						where program_module.progid_program_module=:PARAM_PROGID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_PROGID")->AsString=prog_id;

try
	{
	Query->ExecQuery();
	result=StringToGUID(Query->FieldByName("guid_program_module")->AsString);
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=StringToGUID("");
	}

Query->Close();
return result;
}
//---------------------------------------------------------------------------
//получить ProgId по GUID
UnicodeString TDMSprProgramModule::GetProgIDFromCLSID (GUID guid)
{
UnicodeString result="";

Query->Close();
UnicodeString zapros="select program_module.progid_program_module  \
						from program_module   \
						where program_module.guid_program_module=:PARAM_GUID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_GUID")->AsString=GUIDToString(guid);

try
	{
	Query->ExecQuery();
	result=Query->FieldByName("progid_program_module")->AsString;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result="";
	}

Query->Close();
return result;
}
//---------------------------------------------------------------------------
//получить модуль по GUID
UnicodeString TDMSprProgramModule::GetNameModuleFromCLSID(GUID guid)
{
UnicodeString result="";

Query->Close();
UnicodeString zapros="select program_module.module_program_module  \
						from program_module   \
						where program_module.guid_program_module=:PARAM_GUID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_GUID")->AsString=GUIDToString(guid);

try
	{
	Query->ExecQuery();
	result=Query->FieldByName("module_program_module")->AsString;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result="";
	}

Query->Close();
return result;
}
//-------------------------------------------------------------------
	   //получить путь по GUID
UnicodeString TDMSprProgramModule::GetFullPatchFromCLSID(GUID guid)
{
UnicodeString result="";

Query->Close();
UnicodeString zapros="select program_module.patch_program_module  \
						from program_module   \
						where program_module.guid_program_module=:PARAM_GUID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_GUID")->AsString=GUIDToString(guid);

try
	{
	Query->ExecQuery();
	result=Query->FieldByName("patch_program_module")->AsString;
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result="";
	}

Query->Close();
return result;
}
//-------------------------------------------------------------------
__int64 TDMSprProgramModule::GetIdModuleFromGUID(GUID guid)
{
__int64 result=0;

Query->Close();
UnicodeString zapros="select program_module.id_program_module  \
						from program_module   \
						where program_module.guid_program_module=:PARAM_GUID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_GUID")->AsString=GUIDToString(guid);

try
	{
	Query->ExecQuery();
	result=glStrToInt64(Query->FieldByName("id_program_module")->AsString);
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=0;
	}

Query->Close();
return result;

}
//-------------------------------------------------------------------
__int64 TDMSprProgramModule::GetIdModuleFromProgId(UnicodeString prog_id)
{
__int64 result=0;

Query->Close();
UnicodeString zapros="select program_module.id_program_module    \
						from program_module                        \
						where program_module.progid_program_module=:PARAM_PROGID";
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ParamByName("PARAM_PROGID")->AsString=prog_id;

try
	{
	Query->ExecQuery();
	result=glStrToInt64(Query->FieldByName("id_program_module")->AsString);
	}
catch(Exception &exception)
	{
	TextError=exception.Message;
	result=0;
	}

Query->Close();
return result;


}
//-------------------------------------------------------------------
void __fastcall TDMSprProgramModule::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------

