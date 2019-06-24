//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprDiscountAuto.h"

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
__fastcall TDMSprDiscountAuto::TDMSprDiscountAuto(TComponent* Owner)
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
bool TDMSprDiscountAuto::Init(void)
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
TableDiscountAuto->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprDiscountAuto::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprDiscountAuto::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TDMSprDiscountAuto::OpenTable()
{
Table->Active=false;
Table->Open();

}
//---------------------------------------------------------------------------
void TDMSprDiscountAuto::OpenTableDiscountAuto(__int64 id_sklad)
{
TableDiscountAuto->Active=false;
TableDiscountAuto->ParamByName("PARAM_IDSKLAD")->AsInt64=id_sklad;
TableDiscountAuto->Open(); 
}
//---------------------------------------------------------------------------

void  TDMSprDiscountAuto::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMSprDiscountAuto::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprDiscountAuto::SaveElement()
{
bool result;
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
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

void  TDMSprDiscountAuto::CloseElement()
{

        Element->CancelUpdates();
        IBTr->Rollback();   
}
//---------------------------------------------------------------------------
void TDMSprDiscountAuto::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
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
				TextError=exception.Message;
				}
        }
}
//---------------------------------------------------------------------------

__int64 TDMSprDiscountAuto::GetIDElement(String gid)
{
__int64 res=0;

        if (gid!="" || gid!=" " )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_SDISCOUNT_AUTO from SDISCOUNT_AUTO where GID_SDISCOUNT_AUTO=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("ID_SDISCOUNT_AUTO")->AsInt64;
						}
				else res=0;
                }
				pFIBQ->Close();


return res;
}
//---------------------------------------------------------------------------
AnsiString TDMSprDiscountAuto::GetGIDElement(__int64 id)
{
AnsiString res=0;

		if (id!=0 )
				{
				pFIBQ->Close();
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select GID_SDISCOUNT_AUTO from SDISCOUNT_AUTO where ID_SDISCOUNT_AUTO=:PARAM_ID");
				pFIBQ->ParamByName("PARAM_ID")->AsInt64=id;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=Trim(pFIBQ->FieldByName("GID_SDISCOUNT_AUTO")->AsString);
                        }
				else res="";
				pFIBQ->Close();
                }



return res;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprDiscountAuto::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

int TDMSprDiscountAuto::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(glStrToInt64(TableID_SDISCOUNT_AUTO->AsString)==id)
		{
		result=index+1;
		break;
		}
	index++;
	Table->Next();
	}
return result;
}
//----------------------------------------------------------------------------
