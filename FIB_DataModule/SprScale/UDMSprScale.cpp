//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprScale.h"
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
__fastcall TDMSprScale::TDMSprScale(TComponent* Owner)
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
bool TDMSprScale::Init(void)
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
int TDMSprScale::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprScale::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDMSprScale::Table1CalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void  TDMSprScale::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprScale::NewElement(void)
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprScale::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprScale::SaveElement()
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
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------
void TDMSprScale::DeleteElement(__int64 id)
{
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
                }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
        }
}
//-----------------------------------------------------------------
__int64 TDMSprScale::GetIDElement(String gid)
{
__int64 res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {
        if (gid!="" || gid!=" " )
                {
				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select ID_SSCALE from SSCALE where GID_SSCALE=:PARAM_GID");
				query->ParamByName("PARAM_GID")->AsString=Trim(gid);
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=query->FieldByName("ID_SSCALE")->AsInt64;
                        }
				else res=0;
				}
        }
__finally
	{
	delete query;
	res=0;
	}

return res;
}
//---------------------------------------------------------------------------

