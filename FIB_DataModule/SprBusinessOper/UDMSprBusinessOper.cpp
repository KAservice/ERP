//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprBusinessOper.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IDMSetup.h"
#include "IDMQueryRead.h"
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

__fastcall TDMSprBusinessOper::TDMSprBusinessOper(TComponent* Owner)
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
bool TDMSprBusinessOper::Init(void)
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
int TDMSprBusinessOper::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprBusinessOper::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
UnicodeString TDMSprBusinessOper::GetTextQuery(__int64 id_grp, bool all)
{
UnicodeString result="";
if(all==true)
		{//без групп
		result=result+" select *";
		result=result+" from sbusiness_oper";
		result=result+" ORDER BY name_sbusiness_oper";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+" select *";
				result=result+" from sbusiness_oper";
				result=result+" where sbusiness_oper.idgrp_sbusiness_oper IS NULL";
				result=result+" ORDER BY sbusiness_oper.name_sbusiness_oper";
				}
		else    //задана группа
				{
				result=result+" select *";
				result=result+" from sbusiness_oper";
				result=result+" where sbusiness_oper.idgrp_sbusiness_oper="+IntToStr(id_grp);
				result=result+" ORDER BY sbusiness_oper.name_sbusiness_oper";
				}
		}
return result;
}
//---------------------------------------------------------------------------
void  TDMSprBusinessOper::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprBusinessOper::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;


				Element->Open();
				Element->Insert();
				if (id_grp!=0)
						{
						ElementIDGRP_SBUSINESS_OPER->AsString=id_grp;
						}
				result=true;



return result;
}
//---------------------------------------------------------------------------

int TDMSprBusinessOper::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int result=0;
result=Element->RecordCount;
return result;
}

//----------------------------------------------------------------------------
__int64 TDMSprBusinessOper::GetIdPoName(UnicodeString name)
{
__int64 result=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select sbusiness_oper.id_sbusiness_oper from sbusiness_oper where sbusiness_oper.name_sbusiness_oper=:PARAM_NAME");
q->pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
q->pFIBQ->ExecQuery();
result=q->pFIBQ->FieldByName("ID_SPROJECT")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return result;


}
//---------------------------------------------------------------------------
bool  TDMSprBusinessOper::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_SBUSINESS_OPER->AsString);

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
bool TDMSprBusinessOper::DeleteElement(__int64 id)
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
void TDMSprBusinessOper::ChancheGrp(__int64 new_id_grp)
{
OpenElement(glStrToInt64(TableID_SBUSINESS_OPER->AsString));
Element->Edit();
ElementIDGRP_SBUSINESS_OPER->AsString=new_id_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------

__int64 TDMSprBusinessOper::GetIdGrpBusinessOper(__int64 id_bo)
{
__int64 res;
res=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select sbusiness_oper.idgrp_sbusiness_oper from sbusiness_oper where sbusiness_oper.id_sbusiness_oper='"+IntToStr(id_bo)+"'");
q->pFIBQ->ExecQuery();
res=q->pFIBQ->FieldByName("idgrp_sbusiness_oper")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return res;

}

//------------------------------------------------------------------------------

