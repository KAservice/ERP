//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDMXVipolnObmen.h"
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

__fastcall TDMXVipolnObmen::TDMXVipolnObmen(TComponent* Owner)
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
bool TDMXVipolnObmen::Init(void)
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
int TDMXVipolnObmen::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMXVipolnObmen::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMXVipolnObmen::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";

//if(all==true)
//		{
//		 result="				select art_ib.*                           \
//				from art_ib                                               \
//				ORDER BY art_ib.idgrp_art_ib, art_ib.index_art_ib";
//
//        }
//else
//        {
//        if (IdGrp==0)
//				{
//		 result="	select art_ib.*                                      \
//					from art_ib                                          \
//					where art_ib.idgrp_art_ib is null                    \
//					ORDER BY art_ib.idgrp_art_ib, art_ib.index_art_ib";
//
//                }
//        else
//                {
//				result="select art_ib.*  \
//							from art_ib  ";
//				result=result+" where art_ib.idgrp_art_ib='"+IntToStr(id_grp)+"' ";
//				result=result+" ORDER BY art_ib.idgrp_art_ib, art_ib.index_art_ib ";
//				}
//		}

return result;
}
//---------------------------------------------------------------------------
void  TDMXVipolnObmen::OpenTable(void)
{

Table->Active=false;
//Table->SelectSQL->Clear();
//Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMXVipolnObmen::NewElement(void)
{
bool result=true;

Element->Active=false;

Element->Open();
Element->Append();

return result;
}
//---------------------------------------------------------------------------

int TDMXVipolnObmen::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
__int64 TDMXVipolnObmen::FindPoName(UnicodeString name)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select art_ib.id_art_ib from art_ib where art_ib.name_art_ib=:PARAM_NAME");
Query->ParamByName("PARAM_NAME")->AsString=name;
Query->ExecQuery();
result=Query->FieldByName("id_art_ib")->AsInt64;
Query->Close();
return result;


}

//---------------------------------------------------------------------------
__int64 TDMXVipolnObmen::FindPoIdBase(__int64 id_base)
{
__int64 result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select xvipoln_obmen.id_xvipoln_obmen from xvipoln_obmen where xvipoln_obmen.idinfbase_xvipoln_obmen=:PARAM_IDBASE");
Query->ParamByName("PARAM_IDBASE")->AsString=id_base;
Query->ExecQuery();
result=Query->FieldByName("id_xvipoln_obmen")->AsInt64;
Query->Close();
return result;


}

//---------------------------------------------------------------------------
bool  TDMXVipolnObmen::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_XVIPOLN_OBMEN->AsString);




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
bool TDMXVipolnObmen::DeleteElement(__int64 id)
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
void TDMXVipolnObmen::ChancheGrp(__int64 id_new_grp,__int64 id_element)
{
//OpenElement(id_element);
//Element->Edit();
//ElementIDGRP_ART_IB->AsString=id_new_grp;
//Element->Post();
//SaveElement();
}
//------------------------------------------------------------------------------


__int64 TDMXVipolnObmen::GetIdGrp(__int64 id_el)
{
__int64 res;
//res=0;
//Query->Close();
//Query->SQL->Clear();
//Query->SQL->Add("select art_ib.idgrp_art_ib from art_ib where art_ib.id_art_ib=:PARAM_ID");
//Query->ParamByName("PARAM_ID")->AsString=id_el;
//Query->ExecQuery();
//res=Query->FieldByName("idgrp_art_ib")->AsInt64;
//Query->Close();
return res;

}
//-----------------------------------------------------------------------------

