//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNachisl.h"
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
__fastcall TDMSprNachisl::TDMSprNachisl(TComponent* Owner)
        : TDataModule(Owner)
{
TextError="Ошибок нет!";

FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TDMSprNachisl::Init(void)
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
TypeNachisl->Database=DM_Connection->pFIBData;

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_SprPrice);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNachisl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNachisl::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;

Element->Close();
TypeNachisl->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMSprNachisl::OpenTable(__int64 id_nom)
{
IdNom=id_nom;


Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=IdNom;
Table->Active=true;


}
//----------------------------------------------------------------------------
bool TDMSprNachisl::SaveIsmen(void)
{
bool result=false;
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdNom);
		result=true;
        }
	catch(Exception &exception)
		{
		result=false;
				//IBTrUpdate->Rollback();
				TextError=exception.Message;
		}
	}
return result;
}
//----------------------------------------------------------------------------

void  TDMSprNachisl::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();
}
//---------------------------------------------------------------------------

int TDMSprNachisl::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool TDMSprNachisl::SaveElement()
{
bool result=false;

__int64 Id=ElementID_SNACHISL->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
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
void TDMSprNachisl::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------
void TDMSprNachisl::DeleteElement(__int64 id)
{
OpenElement(id);
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
				}
        }
}
//---------------------------------------------------------------------------
__int64 TDMSprNachisl::FindElement(__int64 id_type_nachisl, __int64 id_nom)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select snachisl.id_snachisl from snachisl ");
		pFIBQ->SQL->Add(" where snachisl.idnom_snachisl=:PARAM_IDNOM and snachisl.idtnach_snachisl=:PARAM_IDTYPE ");
		pFIBQ->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
		pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=id_type_nachisl;
		pFIBQ->ExecQuery();
		result=pFIBQ->RecordCount;
		OpenElement(pFIBQ->FieldByName("id_snachisl")->AsInt64);
pFIBQ->Close();
return result;
}
//--------------------------------------------------------------------------

void __fastcall TDMSprNachisl::TableNewRecord(TDataSet *DataSet)
{
TableIDNOM_SNACHISL->AsString=IdNom;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNachisl::ElementNewRecord(TDataSet *DataSet)
{
ElementIDNOM_SNACHISL->AsInt64=IdNom;
ElementIDTNACH_SNACHISL->AsInt64=IdTypeNachisl;

}
//---------------------------------------------------------------------------







