//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprKKM.h"
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
__fastcall TDMSprKKM::TDMSprKKM(TComponent* Owner)
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
bool TDMSprKKM::Init(void)
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
int TDMSprKKM::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprKKM::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void  TDMSprKKM::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprKKM::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();


}
//---------------------------------------------------------------------------

int TDMSprKKM::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprKKM::SaveElement()
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
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprKKM::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
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
                }
        }
}

//---------------------------------------------------------------------------


AnsiString TDMSprKKM::GetGIDElement(__int64 id)
{
AnsiString res=0;
TpFIBQuery * query=new TpFIBQuery(0);
try
        {
        if (id!=0 )
				{

				query->Database=DM_Connection->pFIBData;
				query->Transaction=IBTr;
				query->SQL->Add("select GID_SKKM from SKKM where IDKKM=:PARAM_ID");
				query->ParamByName("PARAM_ID")->AsInt64=id;
				if (IBTr->Active==false) IBTr->StartTransaction();
				query->ExecQuery();
				if (query->RecordCount==1)
                        {
						res=Trim(query->FieldByName("GID_SKKM")->AsString);
                        }
				else res="";
                }
        }
__finally
	{
	delete query;
	res="";
	}

return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprKKM::TableCalcFields(TDataSet *DataSet)
{
Table->FieldByName("RECNO")->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------



