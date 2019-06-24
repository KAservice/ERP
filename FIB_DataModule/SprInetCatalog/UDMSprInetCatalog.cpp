//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprInetCatalog.h"
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

__fastcall TDMSprInetCatalog::TDMSprInetCatalog(TComponent* Owner)
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
bool TDMSprInetCatalog::Init(void)
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
int TDMSprInetCatalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprInetCatalog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------
void  TDMSprInetCatalog::OpenTable(void)
{
Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprInetCatalog::NewElement(void)
{
bool result=false;
Element->Active=false;


				Element->Open();
				Element->Append();
				result=true;



return result;
}
//---------------------------------------------------------------------------

int TDMSprInetCatalog::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int result=0;
result=Element->RecordCount;
return result;
}

//----------------------------------------------------------------------------
__int64 TDMSprInetCatalog::GetIdPoName(UnicodeString name)
{
__int64 result=0;
IDMQueryRead *q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
												 (void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select sinetcatalog.id_sinetcatalog from sinetcatalog where sinetcatalog.name_sinetcatalog=:PARAM_NAME");
q->pFIBQ->ParamByName("PARAM_NAME")->AsString=name;
q->pFIBQ->ExecQuery();
result=q->pFIBQ->FieldByName("id_sinetcatalog")->AsInt64;
q->pFIBQ->Close();
q->kanRelease();
return result;


}
//---------------------------------------------------------------------------
bool  TDMSprInetCatalog::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_SINETCATALOG->AsString);

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
bool TDMSprInetCatalog::DeleteElement(__int64 id)
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
int TDMSprInetCatalog::GetIndexElementaPoID(__int64 id)
{   //индекс начинается с 1, если 0 то не найден элемент
int result=0;
int index=0;
Table->First();
while(!Table->Eof)
	{
	if(glStrToInt64(TableID_SINETCATALOG->AsString)==id)
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

