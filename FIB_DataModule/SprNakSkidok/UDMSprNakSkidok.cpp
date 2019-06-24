//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNakSkidok.h"
#include "UGlobalConstant.h"
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
__fastcall TDMSprNakSkidok::TDMSprNakSkidok(TComponent* Owner)
        : TDataModule(Owner)
{
elSave=false;
FunctionDeleteImpl=0;
flDeleteImpl=true;
}
//----------------------------------------------------------------------------
bool TDMSprNakSkidok::Init(void)
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
TableNakSkidok->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNakSkidok::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNakSkidok::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
Query->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMSprNakSkidok::OpenTable(void)
{

Table->Active=false;

Table->Active=true;


}
//---------------------------------------------------------------------------

int TDMSprNakSkidok::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;

if (Res>0) elSave=true;
return Res;
}
//----------------------------------------------------------------------------

void TDMSprNakSkidok::NewElement(void)
{
elSave=false;
Element->Active=false;
Element->Open();
Element->Insert();
}
//-----------------------------------------------------------------------------
bool TDMSprNakSkidok::SaveElement(void)
{
bool result=false;
int id=ElementID_SNAK_SKIDOK->AsInt64;
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
        elSave=true;
		OpenElement(id);
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

void TDMSprNakSkidok::DeleteElement(__int64 Id)
{
elSave=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
				Element->ApplyUpdToBase();
				IBTrUpdate->Commit();
				Element->CommitUpdToCach();
                }
		catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
                Error=true;
                TextError=exception.Message;
                }
        }
}
//----------------------------------------------------------------------------
void __fastcall TDMSprNakSkidok::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void TDMSprNakSkidok::GetSpisokSkidok(__int64 id_vid, __int64 id_sklad)
{
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select * ");
Query->SQL->Add(" from SNAK_SKIDOK ");
Query->SQL->Add(" where snak_skidok.idvid_snak_skidok=:PARAM_VID ");
Query->SQL->Add(" and snak_skidok.idsklad_snak_skidok=:PARAM_IDSKLAD ");
Query->ParamByName("PARAM_VID")->AsInt64=id_vid;
Query->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
Query->ExecQuery();
}
//-----------------------------------------------------------------------------
void TDMSprNakSkidok::OpenTableNakSkidok(__int64 id_vid,__int64 id_sklad)
{
TableNakSkidok->Close();
TableNakSkidok->ParamByName("PARAM_VID")->AsInt64=id_vid;
TableNakSkidok->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
TableNakSkidok->Open();
}
//------------------------------------------------------------------------------

