//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprUser.h"
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
__fastcall TDMSprUser::TDMSprUser(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
UserOK=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
bool TDMSprUser::Init(void)
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

pFIBTr->DefaultDatabase=DM_Connection->pFIBData;
pFIBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

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
int TDMSprUser::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprUser::DataModuleDestroy(TObject *Sender)
{
pFIBSecurityService1->Active = false ;
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
AnsiString TDMSprUser::GetTextQuery(__int64 id_grp, bool all)
{
AnsiString result="";
if(all==true)
        {
		result=result+" select * from SUSER ORDER BY NAME_USER ";
		}
else
        {
        if (IdGrp==0)
				{
				result=result+" select * from SUSER  ";
				result=result+" where IDGRP_USER IS NULL";
				result=result+" ORDER BY NAME_USER";
                }
        else
				{
				result=result+" select * from SUSER ";
				result=result+" where IDGRP_USER="+IntToStr(id_grp);
				result=result+" ORDER BY NAME_USER";
                }
        } 

return result;
}
//---------------------------------------------------------------------------
void  TDMSprUser::OpenTable(__int64 id_grp,bool all)
{
TextError="";
Error=false;
if (DM_Connection->NameUser=="SYSDBA")
	{
	try
		{
		pFIBSecurityService1->Active = false ;
		pFIBSecurityService1->Params->Clear();
		pFIBSecurityService1->Params->Add("user_name="+DM_Connection->NameUser);
		pFIBSecurityService1->Params->Add("password="+DM_Connection->PasswordUser);
		pFIBSecurityService1->ServerName=DM_Connection->NameServer;
		pFIBSecurityService1->Protocol=TCP;
		pFIBSecurityService1->Active = true ;
		}
	catch(Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		}
	}

IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();  
}

//---------------------------------------------------------------------------

void  TDMSprUser::NewElement(__int64 id_grp)
{
Element->Active=false;
Element->Open();
Element->Insert();
if (id_grp!=0)
	{
	ElementIDGRP_USER->AsString=id_grp;
	}

ElementREOPEN_GUR_SUSER->AsInteger=1;
ElementREOPEN_SPR_SUSER->AsInteger=1;	
}
//---------------------------------------------------------------------------

int TDMSprUser::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

if (Res==1)
        {
        UserOK=true;
        }
else
        {
        UserOK=false;
        }
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprUser::SaveElement()
{
bool result=false;
try
        {
        Element->ApplyUpdates();
		pFIBTrUpdate->Commit();
		result=true;
        }
catch(Exception &exception)
				{
				//pFIBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMSprUser::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				pFIBTrUpdate->Commit();
                }
        catch(...)
                {
                Error=true;
                TextError="Не удалось удалить элемент справочника!";
                }
        }
}

//---------------------------------------------------------------------------
__int64 TDMSprUser::FindPoName(String NameUser)
{
__int64 Kol;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_USER from SUSER where NAME_USER='"+NameUser+"'");
if (pFIBTr->Active==false) pFIBTr->StartTransaction();
pFIBQ->ExecQuery();
Kol=pFIBQ->RecordCount;

OpenElement(pFIBQ->FieldByName("ID_USER")->AsInt64);
pFIBQ->Close();
return Kol;
}
//---------------------------------------------------------------------------
__int64 TDMSprUser::FindPoPassword(String Password)
{
__int64 Kol;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_USER from SUSER where PASSWORD_USER='"+Password+"'");
if (pFIBTr->Active==false) pFIBTr->StartTransaction();
pFIBQ->ExecQuery();
Kol=pFIBQ->RecordCount;

OpenElement(pFIBQ->FieldByName("ID_USER")->AsInt64);
pFIBQ->Close();
return Kol;

}
//---------------------------------------------------------------------------
__int64 TDMSprUser::GetIdGrpUser(__int64 id_user)
{
__int64 res;
res=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDGRP_USER from SUSER where ID_USER='"+IntToStr(id_user)+"'");
if (pFIBTr->Active==false) pFIBTr->StartTransaction();
pFIBQ->ExecQuery();
res=pFIBQ->FieldByName("IDGRP_USER")->AsInt64;
pFIBQ->Close();
return res; 
}
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void TDMSprUser::ChancheGrp(__int64 new_grp)
{
OpenElement(glStrToInt64(TableID_USER->AsString));
Element->Edit();
ElementIDGRP_USER->AsString=new_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------
void __fastcall TDMSprUser::TableCalcFields(TDataSet *DataSet)
{
if (DM_Connection->NameUser!="SYSDBA")
	{
     TableUSERID->AsInteger=0;
	 return;
	}

try
	{
	if (TableNAME2_USER->AsString!="")
		{
		pFIBSecurityService1->DisplayUser(TableNAME2_USER->AsString);
		TableUSERID->AsInteger=pFIBSecurityService1->UserInfoCount;
		}
	else
		{
		TableUSERID->AsInteger=0;
		}
	}
catch(Exception &exception)
				{
				//pFIBTrUpdate->Rollback();
				Error=true;
				TextError=TextError+"\nNAME2="+TableNAME2_USER->AsString+" Ошибка:"+TextError+exception.Message;
				}
}
//---------------------------------------------------------------------------
TDateTime TDMSprUser::GetPosNachReport(void)
{
TDateTime result=0;
switch (ElementTPOSREPORT_SUSER->AsInteger)
	{
	case 0:  //не задан
		{
		result=Date()-DayOf(Date())+1;
		}break;
	case 1:  //начало года
		{

		}break;
	case 2:   //начало квартала
		{

		}break;
	case 3:   //начало месяца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дня
		{
        result=Date();
		}break;

	case 5:   //количество дней
		{
		result=Date()-ElementKOLDAYREP_SUSER->AsInteger;
		}break;
	}
if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;
}
//----------------------------------------------------------------------------
TDateTime TDMSprUser::GetPosNachGurnal(void)
{
TDateTime result=0;
switch (ElementTPOSGOURNAL_SUSER->AsInteger)
	{
	case 0:  //не задан
		{
		result=Date()-DayOf(Date())+1;
		}break;
	case 1:  //начало года
		{

		}break;
	case 2:   //начало квартала
		{

		}break;
	case 3:   //начало месяца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дня
		{
        result=Date();
		}break;

	case 5:   //количество дней
		{
		result=Date()-ElementKOLDAYGUR_SUSER->AsInteger;
		}break;
	}

if (result<Date()-10000)
	{
	result=Date()-DayOf(Date())+1;
	}
return result;



}
//----------------------------------------------------------------------------

void __fastcall TDMSprUser::ElementEDIT_CHUG_DOC_SUSERValidate(TField *Sender)
{
if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
	{
	throw Exception("Данное поле может редактировать только SYSDBA!",0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprUser::ElementDEL_CHUG_DOC_SUSERValidate(TField *Sender)
{
if (DM_Connection->UserInfoNAME_USER->AsString!="SYSDBA")
	{
	throw Exception("Данное поле может редактировать только SYSDBA!",0);
	}
}
//---------------------------------------------------------------------------


