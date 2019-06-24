//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMSprUser.h"
#include "UDM.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma link "IB_Services"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern TDM *DM;
extern TDMSprUser * glUser;
//---------------------------------------------------------------------------
__fastcall TDMSprUser::TDMSprUser(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="ќшибок нет!";
UserOK=false;




}
//---------------------------------------------------------------------------
void __fastcall TDMSprUser::DataModuleDestroy(TObject *Sender)
{
pFIBSecurityService1->Active = false ;
Table->Active=false;
Element->Active=false;

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
if (DM->NameUser=="SYSDBA")
	{
	try
		{
		pFIBSecurityService1->Active = false ;
		pFIBSecurityService1->Params->Clear();
		pFIBSecurityService1->Params->Add("user_name="+DM->NameUser);
		pFIBSecurityService1->Params->Add("password="+DM->PasswordUser);
		pFIBSecurityService1->ServerName=DM->NameServer;
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
	ElementIDGRP_USER->AsInt64=id_grp;
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
                TextError="Ќе удалось удалить элемент справочника!";
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
OpenElement(TableID_USER->AsInt64);
Element->Edit();
ElementIDGRP_USER->AsInt64=new_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------
void __fastcall TDMSprUser::TableCalcFields(TDataSet *DataSet)
{
if (DM->NameUser!="SYSDBA")
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
				TextError=TextError+"\nNAME2="+TableNAME2_USER->AsString+" ќшибка:"+TextError+exception.Message;
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
	case 3:   //начало мес€ца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дн€
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
	case 3:   //начало мес€ца
		{
        result=Date()-DayOf(Date())+1;
		}break;
	case 4:  //начало дн€
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
if (glUser->ElementNAME_USER->AsString!="SYSDBA")
	{
	throw Exception("ƒанное поле может редактировать только SYSDBA!",0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TDMSprUser::ElementDEL_CHUG_DOC_SUSERValidate(TField *Sender)
{
if (glUser->ElementNAME_USER->AsString!="SYSDBA")
	{
	throw Exception("ƒанное поле может редактировать только SYSDBA!",0);
	}
}
//---------------------------------------------------------------------------


