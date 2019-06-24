//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprInv.h"
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
__fastcall TDMSprInv::TDMSprInv(TComponent* Owner)
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
bool TDMSprInv::Init(void)
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
int TDMSprInv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprInv::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------


void  TDMSprInv::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprInv::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
ElementDATE_SINV->AsDateTime=Date();

}
//---------------------------------------------------------------------------

int TDMSprInv::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprInv::SaveElement()
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
        Error=true;
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprInv::CloseElement()
{

        Element->CancelUpdates();
	   // IBTr->Rollback();
}
//---------------------------------------------------------------------------
void TDMSprInv::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
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
                Error=true;
				TextError=exception.Message;
                }
		}
}
//---------------------------------------------------------------------------

__int64 TDMSprInv::GetIDElement(String gid)
{
__int64 res=0;
        if (gid!="" || gid!=" " )
                {
				TpFIBQuery * query=new TpFIBQuery(0);
				try {

					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select ID_SINV from SINV where GID_SINV=:PARAM_GID");
					query->ParamByName("PARAM_GID")->AsString=Trim(gid);
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					if (query->RecordCount==1)
						{
						res=query->FieldByName("ID_SINV")->AsInt64;
						}
					else res=0;
					}
				__finally
					{
					res=0;
					delete query;
					}
				}  
return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprInv::GetGIDElement(__int64 id)
{
AnsiString res=0;

        if (id!=0 )
				{
				TpFIBQuery * query=new TpFIBQuery(0);
				try {
					query->Database=DM_Connection->pFIBData;
					query->Transaction=IBTr;
					query->SQL->Add("select GID_SINV from SINV where ID_SINV=:PARAM_ID");
					query->ParamByName("PARAM_ID")->AsInt64=id;
					if (IBTr->Active==false) IBTr->StartTransaction();
					query->ExecQuery();
					if (query->RecordCount==1)
						{
						res=Trim(query->FieldByName("GID_SINV")->AsString);
						}
					else res="";
					}
				__finally
					{
					res="";
					delete query;
					}
                }
return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprInv::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------


