//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprCustomerUser.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "DateUtils.hpp"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma link "IB_Services"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "IB_Services"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprCustomerUser::TDMSprCustomerUser(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
bool TDMSprCustomerUser::Init(void)
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

Element->Database=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;

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
int TDMSprCustomerUser::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprCustomerUser::DataModuleDestroy(TObject *Sender)
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
UnicodeString TDMSprCustomerUser::GetTextQuery(__int64 id_account,__int64 id_grp, bool all)
{
UnicodeString result="";




if(all==true)
        {
		result=" select *                                                  \
						from cust_user                                            \
						where cust_user.idaccount_cust_user=:PARAM_IDACCOUNT     \
						ORDER BY cust_user.name_cust_user ";
		}
else
        {
		if (IdGrp==0)
				{
				result=" select *                                                  \
								from cust_user                                            \
								where cust_user.idaccount_cust_user=:PARAM_IDACCOUNT      \
										and cust_user.idgrp_cust_user is null            \
								ORDER BY cust_user.name_cust_user";
				}
        else
				{
				result=" select *                                               \
							from cust_user                                             \
							where cust_user.idaccount_cust_user=:PARAM_IDACCOUNT       \
									and cust_user.idgrp_cust_user=:PARAM_IDGRP         \
							ORDER BY cust_user.name_cust_user";
                }
        } 

return result;
}
//---------------------------------------------------------------------------
void  TDMSprCustomerUser::OpenTable(__int64 id_account,__int64 id_grp,bool all)
{


IdGrp=id_grp;
AllElement=all;
IdAccount=id_account;

Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_account,id_grp,all));
Table->ParamByName("PARAM_IDACCOUNT")->AsInt64=id_account;
if(all==true)
        {

		}
else
        {
		if (IdGrp==0)
				{

				}
        else
				{
				Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
                }
		}
Table->Open();  
}

//---------------------------------------------------------------------------

bool  TDMSprCustomerUser::NewElement(__int64 id_account,__int64 id_grp)
{
bool result=true;
Element->Active=false;
Element->Open();
Element->Append();
if (id_grp!=0)
	{
	ElementIDGRP_CUST_USER->AsString=id_grp;
	ElementIDACCOUNT_CUST_USER->AsString=id_account;
	}

return result;
}
//---------------------------------------------------------------------------

int TDMSprCustomerUser::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprCustomerUser::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_CUST_USER->AsString);

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
bool TDMSprCustomerUser::DeleteElement(__int64 id)
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
                }
        catch(...)
                {
                Error=true;
                TextError="Не удалось удалить элемент справочника!";
                }
		}

return result;
}

//---------------------------------------------------------------------------
__int64 TDMSprCustomerUser::FindPoName(String NameUser)
{
__int64 Kol;
//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select ID_USER from SUSER where NAME_USER='"+NameUser+"'");
//if (pFIBTr->Active==false) pFIBTr->StartTransaction();
//pFIBQ->ExecQuery();
//Kol=pFIBQ->RecordCount;
//
//OpenElement(pFIBQ->FieldByName("ID_USER")->AsInt64);
//pFIBQ->Close();
return Kol;
}
//---------------------------------------------------------------------------
__int64 TDMSprCustomerUser::FindPoPassword(String Password)
{
__int64 Kol;
//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select ID_USER from SUSER where PASSWORD_USER='"+Password+"'");
//if (pFIBTr->Active==false) pFIBTr->StartTransaction();
//pFIBQ->ExecQuery();
//Kol=pFIBQ->RecordCount;
//
//OpenElement(pFIBQ->FieldByName("ID_USER")->AsInt64);
//pFIBQ->Close();
return Kol;

}
//---------------------------------------------------------------------------
__int64 TDMSprCustomerUser::GetIdGrpUser(__int64 id_user)
{
__int64 res;
res=0;
//pFIBQ->Close();
//pFIBQ->SQL->Clear();
//pFIBQ->SQL->Add("select IDGRP_USER from SUSER where ID_USER='"+IntToStr(id_user)+"'");
//if (pFIBTr->Active==false) pFIBTr->StartTransaction();
//pFIBQ->ExecQuery();
//res=pFIBQ->FieldByName("IDGRP_USER")->AsInt64;
//pFIBQ->Close();
return res;
}
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TDMSprCustomerUser::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{

OpenElement(id_element);
Element->Edit();
ElementIDGRP_CUST_USER->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//----------------------------------------------------------------------------





void __fastcall TDMSprCustomerUser::ElementNewRecord(TDataSet *DataSet)
{
//ElementID
}
//---------------------------------------------------------------------------

