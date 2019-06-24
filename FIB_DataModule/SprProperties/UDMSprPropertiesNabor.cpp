//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMSprPropertiesNabor.h"
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

__fastcall TDMSprPropertiesNabor::TDMSprPropertiesNabor(TComponent* Owner)
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
bool TDMSprPropertiesNabor::Init(void)
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
int TDMSprPropertiesNabor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprPropertiesNabor::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMSprPropertiesNabor::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";

if(all==true)
		{
		 result="select spropnabor.*             \
				from spropnabor                  \
				ORDER BY spropnabor.name_spropnabor";


        }
else
        {
        if (IdGrp==0)
                {
				result="select spropnabor.*                    \
					from spropnabor                      \
					where spropnabor.idgrp_spropnabor is null \
					ORDER BY spropnabor.name_spropnabor ";


                }
        else
				{
				result="select spropnabor.*  \
							from spropnabor ";
				result=result+" where spropnabor.idgrp_spropnabor='"+IntToStr(id_grp)+"' ";
				result=result+" ORDER BY spropnabor.name_spropnabor ";
				}
		}

return result;
}
//---------------------------------------------------------------------------
void  TDMSprPropertiesNabor::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprPropertiesNabor::NewElement(__int64 id_grp)
{
bool result=true;
IdGrp=id_grp;
Element->Active=false;

Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_SPROPNABOR->AsString=IdGrp;
	}


return result;
}
//---------------------------------------------------------------------------

int TDMSprPropertiesNabor::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
__int64 TDMSprPropertiesNabor::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select spropnabor.id_spropnabor from spropnabor where spropnabor.name_spropnabor=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=Query->FieldByName("id_spropnabor")->AsInt64;
Query->Close();
return result;


}

//---------------------------------------------------------------------------
bool  TDMSprPropertiesNabor::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_SPROPNABOR->AsString);




try
        {

        Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(IdElement);
        res=true;
        }
catch(Exception &exception)
        {
        Error=true;
		TextError=exception.Message;
		//ShowMessage(TextError);
        }

return res;
}
//---------------------------------------------------------------------------
bool TDMSprPropertiesNabor::DeleteElement(__int64 id)
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
void TDMSprPropertiesNabor::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
OpenElement(id_element);
Element->Edit();
ElementIDGRP_SPROPNABOR->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//------------------------------------------------------------------------------


__int64 TDMSprPropertiesNabor::GetIdGrp(__int64 id_el)
{
__int64 res;
res=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select spropnabor.idgrp_spropnabor from spropnabor where spropnabor.id_spropnabor=:PARAM_ID");
Query->ParamByName("PARAM_ID")->AsString=id_el;
Query->ExecQuery();
res=Query->FieldByName("idgrp_spropnabor")->AsInt64;
Query->Close();
return res;

}
//-----------------------------------------------------------------------------

