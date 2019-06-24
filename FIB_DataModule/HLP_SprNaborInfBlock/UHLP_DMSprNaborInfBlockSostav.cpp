//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UHLP_DMSprNaborInfBlockSostav.h"
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
__fastcall THLP_DMSprNaborInfBlockSostav::THLP_DMSprNaborInfBlockSostav(TComponent* Owner)
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
bool THLP_DMSprNaborInfBlockSostav::Init(void)
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
int THLP_DMSprNaborInfBlockSostav::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall THLP_DMSprNaborInfBlockSostav::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

bool  THLP_DMSprNaborInfBlockSostav::OpenTable(__int64 id_group_element, __int64 id_grp, bool all)
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

		text_zaprosa=" 	select hlp_n_ib_s.*,                                                             \
						   hlp_ib.name_hlp_ib                                                            \
					from hlp_n_ib_s                                                                      \
					left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n_ib_s                \
					where                                                                                \
							hlp_n_ib_s.idnabor_hlp_n_ib_s=:PARAM_ID_GROUP_ELEMENT                        \
					order by hlp_ib.name_hlp_ib ";
		Table->SelectSQL->Add(text_zaprosa);
        }
else
        {
        if (id_grp==0)
				{
				text_zaprosa=" 	select hlp_n_ib_s.*,                                                       \
									   hlp_ib.name_hlp_ib                                                  \
								from hlp_n_ib_s                                                            \
								left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n_ib_s      \
								where                                                                      \
										hlp_n_ib_s.idnabor_hlp_n_ib_s=:PARAM_ID_GROUP_ELEMENT              \
								 AND hlp_n_ib_s.idgrp_hlp_n_ib_s is null                                   \
								order by hlp_ib.name_hlp_ib";
				Table->SelectSQL->Add(text_zaprosa);
				}
        else
				{
				text_zaprosa="	select hlp_n_ib_s.*,                                                       \
									   hlp_ib.name_hlp_ib                                                  \
								from hlp_n_ib_s                                                            \
								left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n_ib_s      \
								where                                                                      \
										hlp_n_ib_s.idnabor_hlp_n_ib_s=:PARAM_ID_GROUP_ELEMENT              \
								 AND hlp_n_ib_s.idgrp_hlp_n_ib_s=:PARAM_IDGRP                              \
								order by hlp_ib.name_hlp_ib ";
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

bool  THLP_DMSprNaborInfBlockSostav::NewElement(__int64 id_group_element, __int64 id_grp)
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
bool THLP_DMSprNaborInfBlockSostav::InsertElement(__int64 id_group_element, __int64 id_grp, __int64 id_ib)
{
bool result=false;
IdGroupElement=id_group_element;
IdGrp=id_grp;

if (NewElement(id_group_element,id_grp)==true)
	{
	Element->Edit();
	ElementIDIB_HLP_N_IB_S->AsString=id_ib;

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
bool THLP_DMSprNaborInfBlockSostav::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
bool result=false;

if (OpenElement(id_element)==true)
	{
	Element->Edit();
	ElementIDGRP_HLP_N_IB_S->AsString=id_new_grp;
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


bool THLP_DMSprNaborInfBlockSostav::OpenElement(__int64 id)
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
bool THLP_DMSprNaborInfBlockSostav::SaveElement(void)
{
bool res=false;
IdElement=glStrToInt64(ElementID_HLP_N_IB_S->AsString);

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
bool THLP_DMSprNaborInfBlockSostav::DeleteElement(__int64 id)
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





bool  THLP_DMSprNaborInfBlockSostav::TableSaveIsmen(void)
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

bool  THLP_DMSprNaborInfBlockSostav::TableCancelIsmen()
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
bool THLP_DMSprNaborInfBlockSostav::TableDelete(void)
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
bool THLP_DMSprNaborInfBlockSostav::TableAppend(void)
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
bool THLP_DMSprNaborInfBlockSostav::TableEdit(void)
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
bool THLP_DMSprNaborInfBlockSostav::TablePost(void)
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

void __fastcall THLP_DMSprNaborInfBlockSostav::TableNewRecord(TDataSet *DataSet)
{

TableIDNABOR_HLP_N_IB_S->AsString=IdGroupElement;

if (IdGrp !=0 )
	{
	TableIDGRP_HLP_N_IB_S->AsString=IdGrp;
	}

GUID guid;
CoCreateGuid(&guid);
ElementGUID_HLP_N_IB_S->AsString=GUIDToString(guid);
}
//---------------------------------------------------------------------------


void __fastcall THLP_DMSprNaborInfBlockSostav::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNABOR_HLP_N_IB_S->AsString=IdGroupElement;

if (IdGrp !=0 )
	{
	ElementIDGRP_HLP_N_IB_S->AsString=IdGrp;
	}
GUID guid;
CoCreateGuid(&guid);
ElementGUID_HLP_N_IB_S->AsString=GUIDToString(guid);
}
//---------------------------------------------------------------------------
bool THLP_DMSprNaborInfBlockSostav::TableNewElement(__int64 id_group_element, __int64 id_grp)
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
