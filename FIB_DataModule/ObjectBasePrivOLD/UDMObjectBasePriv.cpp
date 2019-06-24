//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UDMObjectBasePriv.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMObjectBasePriv::TDMObjectBasePriv(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMObjectBasePriv::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Active=false;
}

//---------------------------------------------------------------------------

void  TDMObjectBasePriv::OpenTable(int num_application, __int64 id_grp_user, __int64 id_grp, bool all)
{

IdGrpUser=id_grp_user;
IdGrp=id_grp;
AllElement=all;
NumApplication=num_application;

Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
		{

			   AnsiString zapros="	select INTERF_MAINMENU.*, NAME_SGRPUSER    \
									from INTERF_MAINMENU                                           \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU \
									where                                                                 \
										interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \
										interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER  ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;
		}
else
        {
		if (id_grp==0)
                {
			   AnsiString zapros="	select INTERF_MAINMENU.*, NAME_SGRPUSER    \
									from INTERF_MAINMENU                                           \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU \
									where                                                                 \
										interf_mainmenu.idgrp_interf_mainmenu is null and        \
										interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \
										interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER  ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;


                }
        else
				{
			   AnsiString zapros="	select INTERF_MAINMENU.*, NAME_SGRPUSER    \
									from INTERF_MAINMENU                                           \
									left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMENU \
									where                                                                 \
										interf_mainmenu.idgrp_interf_mainmenu=:PARAM_IDGRP and        \
										interf_mainmenu.application_interf_mainmenu=:PARAM_MODUL and        \
										interf_mainmenu.idgrpuser_interf_mainmenu=:PARAM_GRPUSER  ";
			   Table->SelectSQL->Add(zapros);
			   Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
			   Table->ParamByName("PARAM_MODUL")->AsInteger=num_application;
			   Table->ParamByName("PARAM_GRPUSER")->AsInt64=id_grp_user;
			   }
		}

Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMObjectBasePriv::SaveIsmen()
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
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

void  TDMObjectBasePriv::CancelIsmen()
{
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
bool TDMObjectBasePriv::Table_Delete(void)
{
bool result=true;
try
        {
		Table->Delete();
        }
catch(Exception &exception)
	{
	Error=true;
	TextError=exception.Message;
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------
bool TDMObjectBasePriv::Table_AppendString(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=num_application;

try
	{
	Table->Append();
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
//------------------------------------------------------------------------------
bool  TDMObjectBasePriv::NewElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
IdGrpUser=id_grp_user;
IdGrp=id_grp;
NumApplication=num_application;

try
	{
	Element->Active=true;
	Element->Append();

	ElementAPPLICATION_INTERF_MAINMENU->AsInteger=num_application;
	ElementIDGRPUSER_INTERF_MAINMENU->AsString=id_grp_user;
	if(id_grp!=0)
		{
		ElementIDGRP_INTERF_MAINMENU->AsString=id_grp;
		}
	Element->Post();
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
//----------------------------------------------------------------------------
bool TDMObjectBasePriv::OpenElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        result=true;
        }
return result;
}
//---------------------------------------------------------------------------
bool TDMObjectBasePriv::DeleteElement(__int64 id)
{
bool result=false;
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
				Error=true;
				TextError=exception.Message;
				result=false;
				}
		}
return result;
}

//-----------------------------------------------------------------------------------
bool TDMObjectBasePriv::InsertElement(int num_application, __int64 id_grp_user, __int64 id_grp)
{
bool result=false;
try
        {
		IdGrpUser=id_grp_user;
		IdGrp=id_grp;
		NumApplication=num_application;
        Table->Active=true;
        Table->Insert();
		Table->ApplyUpdates();
		IBTrUpdate->Commit();
		Table->Active=false;
		result=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------
void __fastcall TDMObjectBasePriv::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMObjectBasePriv::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPUSER_INTERF_MAINMENU->AsInt64=IdGrpUser;
TableIDGRP_INTERF_MAINMENU->AsInt64=IdGrp;
TableAPPLICATION_INTERF_MAINMENU->AsInteger=NumApplication;
}

//---------------------------------------------------------------------------
void TDMObjectBasePriv::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_INTERF_MAINMENU->AsInt64=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(NumApplication,IdGrpUser,IdGrp,AllElement);
}
//-----------------------------------------------------------------------------
void TDMObjectBasePriv::Element_Edit(void)
{
Element->Edit();
}
//-----------------------------------------------------------------------------
void TDMObjectBasePriv::Element_Post(void)
{
Element->Post();
}
//-----------------------------------------------------------------------------
bool  TDMObjectBasePriv::SaveElement()
{
bool result=false;
__int64 id=glStrToInt64(ElementID_INTERF_MAINMENU->AsString);
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
        {
		   //		IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//-----------------------------------------------------------------------------
