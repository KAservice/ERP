//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprImportNom.h"
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
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprImportNom::TDMSprImportNom(TComponent* Owner)
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
bool TDMSprImportNom::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;
pFIBDataSet1->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprImportNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprImportNom::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TDMSprImportNom::OpenTable(__int64 id_nom)
{

Table->Active=false;
Table->ParamByName("IDNOM")->AsInt64=id_nom;
Table->Active=true;

}
//---------------------------------------------------------------------------

int TDMSprImportNom::OpenElement(__int64 id)  //возвращает количество элементов
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//----------------------------------------------------------------------------

bool TDMSprImportNom::NewElement(__int64 id_nom)
{
bool result=false;
Element->Active=false;

Element->Open();
Element->Insert();
ElementIDNOM_SIMPORTNOM->AsInt64=id_nom;
result=true;

return result;
}

//-----------------------------------------------------------------------------
bool  TDMSprImportNom::SaveElement(void)
{
bool result=false;
__int64 id=ElementID_SIMPORTNOM->AsInt64;

try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

		OpenElement(id);
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

bool TDMSprImportNom::DeleteElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
		{
		Element->Delete();
		try
				{
				Element->ApplyUpdates();
				IBTrUpdate->Commit();
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

void __fastcall TDMSprImportNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
__int64 TDMSprImportNom::FindNomPoArtikulu(__int64 id_post, UnicodeString artikul)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDNOM_SIMPORTNOM from SIMPORTNOM");
pFIBQ->SQL->Add(" where IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT");
pFIBQ->SQL->Add(" and ART_SIMPORTNOM=:PARAM_ART");
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_ART")->AsString=artikul;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("IDNOM_SIMPORTNOM")->AsInt64;
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprImportNom::FindNomPoCodu(__int64 id_post, UnicodeString code)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select IDNOM_SIMPORTNOM from SIMPORTNOM");
pFIBQ->SQL->Add(" where IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT");
pFIBQ->SQL->Add(" and CODE_SIMPORTNOM=:PARAM_CODE");
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_CODE")->AsString=code;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("IDNOM_SIMPORTNOM")->AsInt64;
pFIBQ->Close();
return result;

}
//----------------------------------------------------------------------------
__int64 TDMSprImportNom::FindNomPoName(__int64 id_post, UnicodeString name)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
UnicodeString z="";
z=z+" select IDNOM_SIMPORTNOM from SIMPORTNOM";
z=z+" where NAME_SIMPORTNOM=:PARAM_NAME";
z=z+" and IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT ";


pFIBQ->SQL->Add(z);
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("IDNOM_SIMPORTNOM")->AsInt64;
pFIBQ->Close();

return result;
}
//----------------------------------------------------------------------------
__int64 TDMSprImportNom::FindElementPoArtikulu(__int64 id_post, UnicodeString artikul)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_SIMPORTNOM from SIMPORTNOM");
pFIBQ->SQL->Add(" where IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT");
pFIBQ->SQL->Add(" and ART_SIMPORTNOM=:PARAM_ART");
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_ART")->AsString=artikul;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_SIMPORTNOM")->AsInt64;
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------
__int64 TDMSprImportNom::FindElementPoCodu(__int64 id_post, UnicodeString code)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_SIMPORTNOM from SIMPORTNOM");
pFIBQ->SQL->Add(" where IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT");
pFIBQ->SQL->Add(" and CODE_SIMPORTNOM=:PARAM_CODE");
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_CODE")->AsString=code;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_SIMPORTNOM")->AsInt64;
pFIBQ->Close();
return result;

}
//----------------------------------------------------------------------------
__int64 TDMSprImportNom::FindElementPoName(__int64 id_post, UnicodeString name)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
pFIBQ->SQL->Add("select ID_SIMPORTNOM from SIMPORTNOM");
pFIBQ->SQL->Add(" where IDKLIENT_SIMPORTNOM=:PARAM_IDKLIENT");
pFIBQ->SQL->Add(" and NAME_SIMPORTNOM=:PARAM_NAME");
pFIBQ->ParamByName("PARAM_IDKLIENT")->AsInt64=id_post;
pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
pFIBQ->ExecQuery();
result=pFIBQ->FieldByName("ID_SIMPORTNOM")->AsInt64;
pFIBQ->Close();
return result;
}
//----------------------------------------------------------------------------
