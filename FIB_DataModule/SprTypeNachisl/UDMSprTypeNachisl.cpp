//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprTypeNachisl.h"
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
__fastcall TDMSprTypeNachisl::TDMSprTypeNachisl(TComponent* Owner)
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
bool TDMSprTypeNachisl::Init(void)
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


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_SprTypePrice);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//-----------------------------------------------------------------------------
int TDMSprTypeNachisl::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprTypeNachisl::DataModuleDestroy(TObject *Sender)
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

void  TDMSprTypeNachisl::OpenTable()
{
Table->Active=false;
Table->Open();

}

//---------------------------------------------------------------------------

void  TDMSprTypeNachisl::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();
}
//---------------------------------------------------------------------------

int TDMSprTypeNachisl::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprTypeNachisl::SaveElement()
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
				TextError=exception.Message;
				result=false;
				}
return result;
}
//---------------------------------------------------------------------------

void  TDMSprTypeNachisl::CloseElement()
{

        Element->CancelUpdates();
		IBTr->Rollback();
}
//---------------------------------------------------------------------------
void TDMSprTypeNachisl::DeleteElement(__int64 Id)
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
//-----------------------------------------------------------------------------
__int64 TDMSprTypeNachisl::GetIDTypePrice(String name)
{
int result=0;
TLocateOptions Opt;
Opt<<loCaseInsensitive;
if(Table->Locate("NAME_STNACHISL",name,Opt)==true)
        {
		result=TableID_STNACHISL->AsInt64;
        }

return result;
}
//-----------------------------------------------------------------------------
__int64 TDMSprTypeNachisl::GetIDElement(String gid)
{
__int64 res=0;
pFIBQ->Close();
        if (gid!="" || gid!=" " )
				{
				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select ID_STNACHISL from STNAVHISL where GID_STNACHISL=:PARAM_GID");
				pFIBQ->ParamByName("PARAM_GID")->AsString=Trim(gid);
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("ID_STNACHISL")->AsInt64;
                        }
                else res=0;
                }
pFIBQ->Close();

return res;
}
//-----------------------------------------------------------------------------
AnsiString TDMSprTypeNachisl::GetGIDElement(__int64 id)
{
AnsiString res="";
pFIBQ->Close();

				pFIBQ->SQL->Clear();
				pFIBQ->SQL->Add("select GID_STNACHISL from STNACHISL where ID_TNACHISL=:PARAM_ID");
				pFIBQ->ParamByName("PARAM_ID")->AsString=id;
				pFIBQ->ExecQuery();
				if (pFIBQ->RecordCount==1)
                        {
						res=pFIBQ->FieldByName("GID_STNACHISL")->AsString;
						}
				else res="";

pFIBQ->Close();

return res;
}
//----------------------------------------------------------------------------
int TDMSprTypeNachisl::GetIndexTypePricePoId(__int64 id_type_price)
{
int result=0;
Table->First();
while (!Table->Eof)
        {
        result=result+1;
        if (id_type_price==TableID_STNACHISL->AsInt64)
                {
                return result;
                }
        Table->Next();
        }

return 0;
}
//---------------------------------------------------------------------------

