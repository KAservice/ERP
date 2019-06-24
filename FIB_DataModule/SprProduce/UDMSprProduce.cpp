//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprProduce.h"
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

__fastcall TDMSprProduce::TDMSprProduce(TComponent* Owner)
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
bool TDMSprProduce::Init(void)
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
int TDMSprProduce::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProduce::DataModuleDestroy(TObject *Sender)
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
UnicodeString TDMSprProduce::GetTextQuery(__int64 id_grp, bool all)
{
AnsiString result="";
if(all==true)
		{//без групп
		result="select *             \
				from sproduce        \
				ORDER BY sproduce.name_sproduce";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result="select *             \
						from sproduce        \
						where idgrp_sproduce is null\
						ORDER BY sproduce.name_sproduce";
				}
		else    //задана группа
				{
				result="select *             \
						from sproduce        ";
				result=result+"	where idgrp_sproduce=" +IntToStr(id_grp);
				result=result+"	ORDER BY sproduce.name_sproduce";
				}
        }


return result;
}
//---------------------------------------------------------------------------
bool  TDMSprProduce::OpenTable(__int64 grp,bool all)
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

bool  TDMSprProduce::NewElement(__int64 id_grp)
{
bool result=true;
IdGrp=id_grp;
Element->Active=true;
Element->Append();
if (id_grp!=0)
	{
	Element->Edit();
	ElementIDGRP_SPRODUCE->AsString=id_grp;
	Element->Post();
	}
return result;
}
//---------------------------------------------------------------------------

bool TDMSprProduce::OpenElement(__int64 id)
{
bool result=true;

Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

return result;
}

//----------------------------------------------------------------------------
__int64 TDMSprProduce::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select ID_SPRODUCE from SPRODUCE where NAME_SPRODUCE=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=glStrToInt64(Query->FieldByName("ID_SPRODUCE")->AsString);
Query->Close();
return result;
}

//---------------------------------------------------------------------------
bool  TDMSprProduce::SaveElement()
{
bool result=false;
IdElement=glStrToInt64(ElementID_SPRODUCE->AsString);

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
bool TDMSprProduce::DeleteElement(__int64 id)
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
bool TDMSprProduce::ChancheGrp(__int64 id_new_grp, __int64 id_el)
{
bool result=true;
OpenElement(id_el);
Element->Edit();
ElementIDGRP_SPRODUCE->AsString=id_new_grp;
Element->Post();
SaveElement();

return result;
}
//----------------------------------------------------------------------------

__int64 TDMSprProduce::GetIDElement(UnicodeString gid)
{
__int64 res=0;
Query->Close();
        if (gid!="" || gid!=" " )
				{
				Query->SQL->Clear();
				Query->SQL->Add("select ID_SPRODUCE from SPRODUCE where GID_SPRODUCE=:PARAM_GID");
				Query->ParamByName("PARAM_GID")->AsString=Trim(gid);
				Query->ExecQuery();

				res=Query->FieldByName("ID_SPRODUCE")->AsInt64;

				}
Query->Close();

return res;
}
//---------------------------------------------------------------------------
UnicodeString TDMSprProduce::GetGIDElement(__int64 id)
{
UnicodeString res="";
Query->Close();
        if (id!=0 )
				{
				Query->SQL->Clear();
				Query->SQL->Add("select GID_SPRODUCE from SPRODUCE where ID_SPRODUCE=:PARAM_ID");
				Query->ParamByName("PARAM_ID")->AsInt64=id;
				Query->ExecQuery();
				if (Query->RecordCount==1)
                        {
						res=Trim(Query->FieldByName("GID_SPRODUCE")->AsString);
                        }
				else res="";
                }
Query->Close();

return res;
}
//---------------------------------------------------------------------------

__int64 TDMSprProduce::GetIdGrp(__int64 id_el)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select IDGRP_SPRODUCE from SPRODUCE where ID_SPRODUCE='"+IntToStr(id_el)+"'");
Query->ExecQuery();
res=Query->FieldByName("IDGRP_SPRODUCE")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------

