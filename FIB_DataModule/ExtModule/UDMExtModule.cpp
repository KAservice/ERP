//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMExtModule.h"

//#include "UDMSetup.h"
//#include "UDMQueryUpdate.h"
#include "IDMQueryRead.h"
#include "UGlobalConstant.h"
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

__fastcall TDMExtModule::TDMExtModule(TComponent* Owner)
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
bool TDMExtModule::Init(void)
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
int TDMExtModule::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMExtModule::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
AnsiString TDMExtModule::GetTextQuery(__int64 id_grp, bool all)
{
AnsiString result="";
if(all==true)
		{//без групп
		result=result+" select *";
		result=result+" from EXT_MODULE";
		result=result+" ORDER BY NAME_EXT_MODULE";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+" select *";
				result=result+" from EXT_MODULE";
				result=result+" where IDGRP_EXT_MODULE IS NULL";
				result=result+" ORDER BY NAME_EXT_MODULE";
				}
		else    //задана группа
				{
				result=result+" select *";
				result=result+" from EXT_MODULE";
				result=result+" where IDGRP_EXT_MODULE="+IntToStr(id_grp);
				result=result+" ORDER BY NAME_EXT_MODULE";
				}
		}
return result;
}
//---------------------------------------------------------------------------
void  TDMExtModule::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMExtModule::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;


		Element->Open();
		Element->Insert();
		if (id_grp!=0)
			{
			ElementIDGRP_EXT_MODULE->AsInt64=id_grp;
			}
		result=true;

return result;
}
//---------------------------------------------------------------------------

int TDMExtModule::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int result=0;
result=Element->RecordCount;
return result;
}
//----------------------------------------------------------------------------
__int64 TDMExtModule::FindPoName(AnsiString name)
{
__int64 result=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&q);
q->Init(InterfaceMainObject,InterfaceImpl);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select ID_EXT_MODULE from EXT_MODULE where NAME_EXT_MODULE=:PARAM_NAME");
q->pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
q->pFIBQ->ExecQuery();
result=q->pFIBQ->FieldByName("ID_EXT_MODULE")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return result;


}
//---------------------------------------------------------------------------
bool  TDMExtModule::SaveElement()
{
bool res=false;
IdElement=ElementID_EXT_MODULE->AsInt64;

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
		//ShowMessage(TextError);
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMExtModule::DeleteElement(__int64 id)
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
void TDMExtModule::ChancheGrp(__int64 new_id_grp)
{
OpenElement(TableID_EXT_MODULE->AsInt64);
Element->Edit();
ElementIDGRP_EXT_MODULE->AsInt64=new_id_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------

__int64 TDMExtModule::GetIdGrpExtModule(__int64 id_ext_module)
{
__int64 res;
res=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
									 (void**)&q);
q->Init(InterfaceMainObject,InterfaceImpl);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select IDGRP_EXT_MODULE from EXT_MODULE where ID_EXT_MODULE='"+IntToStr(id_ext_module)+"'");
q->pFIBQ->ExecQuery();
res=q->pFIBQ->FieldByName("IDGRP_EXT_MODULE")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return res;

}
//---------------------------------------------------------------------------

