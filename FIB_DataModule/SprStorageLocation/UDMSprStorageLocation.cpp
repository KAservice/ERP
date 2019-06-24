//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprStorageLocation.h"
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
__fastcall TDMSprStorageLocation::TDMSprStorageLocation(TComponent* Owner)
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
bool TDMSprStorageLocation::Init(void)
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
int TDMSprStorageLocation::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprStorageLocation::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

bool  TDMSprStorageLocation::OpenTable(__int64 id_sklad, __int64 id_grp, bool all)
{
bool result=false;

IdSklad=id_sklad;
IdGrp=id_grp;
AllElement=all;


Table->Active=false;
Table->SelectSQL->Clear();

UnicodeString zapros="";

if(all==true)
		{
		zapros=" select smhran.*                          \
			from smhran                                   \
			where                                         \
				smhran.idsklad_smhran=:PARAM_IDSKLAD";
		Table->SelectSQL->Add(zapros);
        }
else
        {
        if (IdGrp==0)
                {
				zapros="select smhran.*                                \
					from smhran                                        \
					where                                              \
						smhran.idsklad_smhran=:PARAM_IDSKLAD  AND      \
						smhran.idgrp_smhran is null                    \
					order by smhran.name_smhran";
				 Table->SelectSQL->Add(zapros);

                }
		else
                {
				zapros="select smhran.*                                 \
					from smhran                                         \
					where                                               \
						smhran.idsklad_smhran=:PARAM_IDSKLAD  AND       \
						smhran.idgrp_smhran=:PARAM_IDGRP                \
					order by smhran.name_smhran";
				Table->SelectSQL->Add(zapros);
				Table->ParamByName("PARAM_IDGRP")->AsString=id_grp;
                }
		}

Table->ParamByName("PARAM_IDSKLAD")->AsString=id_sklad;

try
		{
		Table->Open();
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

bool  TDMSprStorageLocation::NewElement(__int64 id_sklad, __int64 id_grp)
{
bool result=false;

IdSklad=id_sklad;
IdGrp=id_grp;

try
		{
		Element->Active=false;
		Element->Open();
		Element->Append();
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
//---------------------------------------------------------------------------
bool TDMSprStorageLocation::DeleteElement(__int64 id)
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
//----------------------------------------------------------------------------
bool TDMSprStorageLocation::ChangeGrp(__int64 id_new_grp,__int64 id_mhran)
{
bool result=false;
		try
				{
				OpenElement(id_mhran);
				Element->Edit();
				ElementIDGRP_SMHRAN->AsString=id_new_grp;
				Element->Post();
				SaveElement();
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
bool TDMSprStorageLocation::OpenElement(__int64 id)
{
bool result=false;


		try
				{
				Element->Active=false;
				Element->ParamByName("PARAM_ID")->AsInt64=id;
				Element->Active=true;
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

//-----------------------------------------------------------------------------


void __fastcall TDMSprStorageLocation::ElementNewRecord(TDataSet *DataSet)
{
ElementIDSKLAD_SMHRAN->AsString=IdSklad;
ElementIDGRP_SMHRAN->AsString=IdGrp;
}
//---------------------------------------------------------------------------
bool  TDMSprStorageLocation::SaveElement()
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

				TextError=exception.Message;
				result=false;

		}
return result;
}
//---------------------------------------------------------------------------
