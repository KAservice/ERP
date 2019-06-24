//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMSprModel2.h"
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
__fastcall TREM_DMSprModel2::TREM_DMSprModel2(TComponent* Owner)
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
bool TREM_DMSprModel2::Init(void)
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
int TREM_DMSprModel2::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMSprModel2::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

bool  TREM_DMSprModel2::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
{
bool result=false;
IdGroupElement=id_group_element;
IdGrp=id_grp;
AllElement=all;


Table->Active=false;
Table->SelectSQL->Clear();

UnicodeString text_zaprosa="";
if(all==true)
		{
		text_zaprosa=" 	select rem_smodel2.*,                                                                     \
						rem_smodel.strcode_rem_smodel,                                                            \
						rem_smodel.name_rem_smodel                                                                \
						from rem_smodel2                                                                          \
						left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smodel2.idmodel_rem_smodel2    \
						where                                                                                     \
							rem_smodel2.idtypedev_rem_smodel2=:PARAM_ID_GROUP_ELEMENT                             \
						order by rem_smodel2.name_rem_smodel2 ";
		Table->SelectSQL->Add(text_zaprosa);
        }
else
        {
        if (id_grp==0)
				{
				text_zaprosa=" 	select rem_smodel2.*,                                                             \
						rem_smodel.strcode_rem_smodel,                                                            \
						rem_smodel.name_rem_smodel                                                                \
						from rem_smodel2                                                                          \
						left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smodel2.idmodel_rem_smodel2    \
						where                                                                                     \
							rem_smodel2.idtypedev_rem_smodel2=:PARAM_ID_GROUP_ELEMENT                             \
							AND rem_smodel2.idgrp_rem_smodel2 is null                                             \
						order by rem_smodel2.name_rem_smodel2";
				Table->SelectSQL->Add(text_zaprosa);
				}
        else
                {
				text_zaprosa="	select rem_smodel2.*,                                                               \
						rem_smodel.strcode_rem_smodel,                                                              \
						rem_smodel.name_rem_smodel                                                                  \
						from rem_smodel2                                                                            \
						left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_smodel2.idmodel_rem_smodel2      \
						where                                                                                       \
							rem_smodel2.idtypedev_rem_smodel2=:PARAM_ID_GROUP_ELEMENT                               \
							AND rem_smodel2.idgrp_rem_smodel2=:PARAM_IDGRP                                          \
						order by rem_smodel2.name_rem_smodel2 ";
				Table->SelectSQL->Add(text_zaprosa);
                Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
                }
		}

Table->ParamByName("PARAM_ID_GROUP_ELEMENT")->AsInt64=id_group_element;




try
		{
		Table->Open();
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

bool  TREM_DMSprModel2::NewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=false;

IdGroupElement=id_group_element;
IdGrp=id_grp;

try
		{
		Element->Active=true;
		Element->Append();
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
bool TREM_DMSprModel2::InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_model)
{
bool result=false;
IdGroupElement=id_group_element;
IdGrp=id_grp;

if (NewElement(id_group_element,id_grp)==true)
	{
	Element->Edit();
	ElementIDMODEL_REM_SMODEL2->AsString=id_model;
	Element->Post();
	if (SaveElement()==true)
		{
        result=true;
		}
	else
		{
		result=false;
		}
	}
else
	{
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------
bool TREM_DMSprModel2::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
bool result=false;

if (OpenElement(id_element)==true)
	{
	Element->Edit();
	ElementIDGRP_REM_SMODEL2->AsString=id_new_grp;
	Element->Post();
	if (SaveElement()==true)
		{
		result=true;
		}
	else
		{
		result=false;
		}
	}
else
	{
	result=false;
	}
return result;
}
//----------------------------------------------------------------------------


bool TREM_DMSprModel2::OpenElement(__int64 id)
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
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprModel2::SaveElement(void)
{
bool res=false;
IdElement=glStrToInt64(ElementID_REM_SMODEL2->AsString);

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
		res=false;
		}

return res;

}
//--------------------------------------------------------------------------
bool TREM_DMSprModel2::DeleteElement(__int64 id)
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





bool  TREM_DMSprModel2::TableSaveIsmen(void)
{
bool result=false;

try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable(IdGroupElement,IdGrp,AllElement);
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

bool  TREM_DMSprModel2::TableCancelIsmen()
{
bool result=false;
try
		{
		Table->CancelUpdates();
	   // IBTrUpdate->Commit();
		OpenTable(IdGroupElement,IdGrp,AllElement);
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
bool TREM_DMSprModel2::TableDelete(void)
{

bool result=false;
try
		{
		Table->Delete();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprModel2::TableAppend(void)
{

bool result=false;
try
		{
		Table->Append();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//----------------------------------------------------------------------------
bool TREM_DMSprModel2::TableEdit(void)
{

bool result=false;
try
		{
		Table->Edit();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//-----------------------------------------------------------------------------
bool TREM_DMSprModel2::TablePost(void)
{

bool result=false;
try
		{
		Table->Post();
		result=true;
		}
catch(Exception &exception)
		{
		result=false;
		TextError=exception.Message;
		}
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TREM_DMSprModel2::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;   	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMSprModel2::TableNewRecord(TDataSet *DataSet)
{
TableIDMODEL_REM_SMODEL2->AsString=IdGroupElement;
TableIDGRP_REM_SMODEL2->AsString=IdGrp;

}
//---------------------------------------------------------------------------


void __fastcall TREM_DMSprModel2::ElementNewRecord(TDataSet *DataSet)
{
ElementIDMODEL_REM_SMODEL2->AsString=IdGroupElement;
ElementIDGRP_REM_SMODEL2->AsString=IdGrp;
}
//---------------------------------------------------------------------------
bool TREM_DMSprModel2::TableNewElement(__int64 id_group_element, __int64 id_grp)
{
bool result=false;

IdGroupElement=id_group_element;
IdGrp=id_grp;

try
		{
		Element->Active=false;
		Element->Append();
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
