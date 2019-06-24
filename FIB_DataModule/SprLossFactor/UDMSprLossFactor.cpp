//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprLossFactor.h"
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

__fastcall TDMSprLossFactor::TDMSprLossFactor(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprLossFactor::Init(void)
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


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprLossFactor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprLossFactor::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMSprLossFactor::GetTextQuery(__int64 id_grp, bool all)
{
AnsiString result="";
if(all==true)
		{//без групп
		result="select *             \
				from sloss_factor        \
				ORDER BY sloss_factor.name_sloss_factor";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result="select *             \
						from sloss_factor        \
						where idgrp_sloss_factor is null\
						ORDER BY sloss_factor.name_sloss_factor";
				}
		else    //задана группа
				{
				result="select *             \
						from sloss_factor       ";
				result=result+"	where idgrp_sloss_factor=" +IntToStr(id_grp);
				result=result+"	ORDER BY sloss_factor.name_sloss_factor";
				}
        }


return result;
}
//---------------------------------------------------------------------------
bool  TDMSprLossFactor::OpenTable(__int64 grp,bool all)
{
bool result=true;
IdGrp=grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(grp,all));
Table->Open();
return result;
}

//---------------------------------------------------------------------------

bool  TDMSprLossFactor::NewElement(__int64 id_grp)
{
bool result=true;
IdGrp=id_grp;
Element->Active=true;
Element->Append();
if (id_grp!=0)
	{
	Element->Edit();
	ElementIDGRP_SLOSS_FACTOR->AsString=id_grp;
	Element->Post();
	}
return result;
}
//---------------------------------------------------------------------------

bool TDMSprLossFactor::OpenElement(__int64 id)
{
bool result=true;

Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

return result;
}

//----------------------------------------------------------------------------
__int64 TDMSprLossFactor::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SLOSS_FACTOR from SLOSS_FACTOR where NAME_SLOSS_FACTOR=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=glStrToInt64(Query->FieldByName("ID_SLOSS_FACTOR")->AsString);
Query->Close();
return result;
}

//---------------------------------------------------------------------------
bool  TDMSprLossFactor::SaveElement()
{
bool result=false;
IdElement=glStrToInt64(ElementID_SLOSS_FACTOR->AsString);

try
		{
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement(IdElement);
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
bool TDMSprLossFactor::DeleteElement(__int64 id)
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
bool TDMSprLossFactor::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
bool result=true;
OpenElement(id_el);
Element->Edit();
ElementIDGRP_SLOSS_FACTOR->AsString=id_new_grp;
Element->Post();
SaveElement();

return result;
}
//----------------------------------------------------------------------------

__int64 TDMSprLossFactor::GetIDElement(UnicodeString gid)
{
__int64 res=0;
Query->Close();
        if (gid!="" || gid!=" " )
				{
				Query->SQL->Clear();
				Query->SQL->Add("select ID_SLOSS_FACTOR from SLOSS_FACTOR where GID_SLOSS_FACTOR=:PARAM_GID");
				Query->ParamByName("PARAM_GID")->AsString=Trim(gid);
				Query->ExecQuery();

				res=Query->FieldByName("ID_SLOSS_FACTOR")->AsInt64;

				}
Query->Close();

return res;
}
//---------------------------------------------------------------------------
UnicodeString TDMSprLossFactor::GetGIDElement(__int64 id)
{
UnicodeString res="";
Query->Close();
        if (id!=0 )
				{
				Query->SQL->Clear();
				Query->SQL->Add("select GID_SLOSS_FACTOR from SLOSS_FACTOR where ID_SLOSS_FACTOR=:PARAM_ID");
				Query->ParamByName("PARAM_ID")->AsInt64=id;
				Query->ExecQuery();
				if (Query->RecordCount==1)
                        {
						res=Trim(Query->FieldByName("GID_SLOSS_FACTOR")->AsString);
                        }
				else res="";
                }
Query->Close();

return res;
}
//---------------------------------------------------------------------------

__int64 TDMSprLossFactor::GetIdGrp(__int64 id_el)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select IDGRP_SLOSS_FACTOR from SLOSS_FACTOR where ID_SLOSS_FACTOR='"+IntToStr(id_el)+"'");
Query->ExecQuery();
res=Query->FieldByName("IDGRP_SLOSS_FACTOR")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------

