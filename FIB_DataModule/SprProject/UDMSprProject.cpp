//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprProject.h"
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

__fastcall TDMSprProject::TDMSprProject(TComponent* Owner)
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
bool TDMSprProject::Init(void)
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
Code->Database=DM_Connection->pFIBData;


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
int TDMSprProject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProject::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Code->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
AnsiString TDMSprProject::GetTextQuery(__int64 id_grp, bool all)
{
AnsiString result="";
if(all==true)
		{//без групп
		result=result+" select *";
		result=result+" from SPROJECT";
		result=result+" ORDER BY NAME_SPROJECT";
		} //без групп
else
		{ //по группам
		if (id_grp==0)
				{ //корневой каталог
				result=result+" select *";
				result=result+" from SPROJECT";
				result=result+" where IDGRP_SPROJECT IS NULL";
				result=result+" ORDER BY NAME_SPROJECT";
				}
		else    //задана группа
				{
				result=result+" select *";
				result=result+" from SPROJECT";
				result=result+" where IDGRP_SPROJECT="+IntToStr(id_grp);
				result=result+" ORDER BY NAME_SPROJECT";
				}
		}
return result;
}
//---------------------------------------------------------------------------
void  TDMSprProject::OpenTable(__int64 id_grp,bool all)
{
IdGrp=id_grp;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
Table->SelectSQL->Add(GetTextQuery(id_grp,all));
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprProject::NewElement(__int64 id_grp)
{
bool result=false;
Element->Active=false;
Code->Active=false;


		int code=GetCodeProject();

		if (code!=0)
				{
				Element->Open();
				Element->Insert();
				if (id_grp!=0)
						{
						ElementIDGRP_SPROJECT->AsInt64=id_grp;
						}
				ElementCODE_SPROJECT->AsInteger=code+1;
				result=true;
				}
		else
				{
				Error=true;
				result=false;
				TextError="Не удалось сформировать код элемента!";

				}


return result;
}
//---------------------------------------------------------------------------

int TDMSprProject::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int result=0;
result=Element->RecordCount;
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprProject::FindPoCodu(int code)
{

__int64 result=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);

q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select ID_SPROJECT from SPROJECT where CODE_SPROJECT=:PARAM_CODE");
q->pFIBQ->ParamByName("PARAM_CODE")->AsInteger=code;
q->pFIBQ->ExecQuery();
result=OpenElement(q->pFIBQ->FieldByName("ID_SPROJECT")->AsInt64);
q->pFIBQ->Close();
q->kanRelease();
return result;


}
//----------------------------------------------------------------------------
__int64 TDMSprProject::FindPoName(AnsiString name)
{
__int64 result=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select ID_SPROJECT from SPROJECT where NAME_SPROJECT=:PARAM_NAME");
q->pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
q->pFIBQ->ExecQuery();
result=q->pFIBQ->FieldByName("ID_SPROJECT")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return result;


}
//---------------------------------------------------------------------------
bool  TDMSprProject::SaveElement()
{
bool res=false;
IdElement=ElementID_SPROJECT->AsInt64;

//проверить код на уникальность
if (CheckCode(glStrToInt64(ElementID_SPROJECT->AsString),
			 ElementCODE_SPROJECT->AsInteger)==true)
	{
	res=false;
	TextError="Код товара не уникальный !";
	return res;
	}



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
bool TDMSprProject::DeleteElement(__int64 id)
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
void TDMSprProject::ChancheGrp(__int64 new_id_grp)
{
OpenElement(TableID_SPROJECT->AsInt64);
Element->Edit();
ElementIDGRP_SPROJECT->AsInt64=new_id_grp;
Element->Post();
SaveElement();
OpenTable(IdGrp,AllElement);
}
//----------------------------------------------------------------------------

__int64 TDMSprProject::GetIdGrpProject(__int64 id_project)
{
__int64 res;
res=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select IDGRP_SPROJECT from SPROJECT where ID_SPROJECT='"+IntToStr(id_project)+"'");
q->pFIBQ->ExecQuery();
res=q->pFIBQ->FieldByName("IDGRP_SPROJECT")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return res;

}

//------------------------------------------------------------------------------
int TDMSprProject::GetCodeProject(void)
{
int result=0;
IDMSetup * setup;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
												 (void**)&setup);
setup->Init(InterfaceMainObject,0);
setup->OpenElement(2);
if (setup->ElementVALUE_SETUP->AsString=="1")
	{
	 Code->Active=false;
	 Code->Active=true;
	 result=CodeMAXCODE->AsInteger;
	 if(result==0) result=1;
	}
else
	{
	ShowMessage("Элементы справочника Проекты можно создавать только в центральной базе!");
	result=0;
	}
setup->kanRelease();
return result;
}
//---------------------------------------------------------------------------
bool TDMSprProject::CheckCode(__int64 id_project, int code)
{
//возвращает true если код не уникальный
bool result=false;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select ID_SPROJECT");
q->pFIBQ->SQL->Add(" from SPROJECT");
q->pFIBQ->SQL->Add(" where CODE_SPROJECT=:PARAM_CODE");
q->pFIBQ->ParamByName("PARAM_CODE")->AsString=code;
q->pFIBQ->ExecQuery();
		while(!q->pFIBQ->Eof)
			{
			if (id_project==glStrToInt64(q->pFIBQ->FieldByName("ID_SPROJECT")->AsString))
				{
				result=true;
				break;
				}
			q->pFIBQ->Next();
			}
q->pFIBQ->Close();
q->kanRelease();
return result;
}
//----------------------------------------------------------------------------
