//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNacenka.h"
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
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSprNacenka::TDMSprNacenka(TComponent* Owner)
        : TDataModule(Owner)
{
Error=false;
TextError="Ошибок нет!";
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//----------------------------------------------------------------------------
bool TDMSprNacenka::Init(void)
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
TPrice->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNacenka::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNacenka::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMSprNacenka::OpenTable(__int64 id_grp_nom)
{
IdGrpNom=id_grp_nom;
Table->Active=false;
Table->ParamByName("IDGRPNOM")->AsInt64=id_grp_nom;
Table->Active=true;

}
//----------------------------------------------------------------------------
void TDMSprNacenka::SaveIsmen(void)
{

try
        {
		Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable(IdGrpNom);
        }
catch(Exception &exception)
		{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
		}
}
//----------------------------------------------------------------------------
void TDMSprNacenka::CancelIsmen(void)
{
Table->CancelUpdates();

}
//----------------------------------------------------------------------------
void  TDMSprNacenka::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();
}
//---------------------------------------------------------------------------

int TDMSprNacenka::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMSprNacenka::SaveElement()
{
int Id=ElementID_SNACENKA->AsInt64;
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenElement(Id);
        }
catch(Exception &exception)
		{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
		}
}
//---------------------------------------------------------------------------
void TDMSprNacenka::DeleteElement(__int64 id)
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
				Error=true;
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------
int TDMSprNacenka::FindElement(__int64 id_type_price, __int64 id_grp_nom)
{
int result=0;
TpFIBQuery * query=new TpFIBQuery(0);
try {

		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add("select ID_SNACENKA from SNACENKA ");
		query->SQL->Add(" where IDGRPNOM_SNACENKA=:PARAM_IDGRPNOM and IDTPRICE_SNACENKA=:PARAM_IDTYPE ");
		query->ParamByName("PARAM_IDGRPNOM")->AsInt64=id_grp_nom;
		query->ParamByName("PARAM_IDTYPE")->AsInt64=id_type_price;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		result=query->RecordCount;
		OpenElement(query->FieldByName("ID_SNACENKA")->AsInt64);
	}
__finally
	{
	delete query;
	}
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNacenka::TableAfterInsert(TDataSet *DataSet)
{
TableIDGRPNOM_SNACENKA->AsInt64=IdGrpNom;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNacenka::TableNewRecord(TDataSet *DataSet)
{
TableIDGRPNOM_SNACENKA->AsInt64=IdGrpNom;

}
//---------------------------------------------------------------------------

void __fastcall TDMSprNacenka::ElementNewRecord(TDataSet *DataSet)
{
ElementIDGRPNOM_SNACENKA->AsInt64=IdGrpNom;
ElementIDTPRICE_SNACENKA->AsInt64=IdTypePrice;

}
//---------------------------------------------------------------------------

