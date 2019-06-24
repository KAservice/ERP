//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprGrpKlient.h"

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
__fastcall TDMSprGrpKlient::TDMSprGrpKlient(TComponent* Owner)
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
void __fastcall TDMSprGrpKlient::DataModuleCreate(TObject *Sender)
{
Error=false;

ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;

}
//---------------------------------------------------------------------------
bool TDMSprGrpKlient::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_SprGrpKlient);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMSprGrpKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprGrpKlient::DataModuleDestroy(TObject *Sender)
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
bool  TDMSprGrpKlient::OpenTable()
{
bool result=false;
if (ExecPriv==false)
	{
	TextError="Ошибка: Справочник Группы контрагентов! Недостаточно прав доступа для выполнения операции!";
    return result;
	}
try
	{
	Table->Active=false;
	Table->Open();
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

void  TDMSprGrpKlient::NewElement(__int64 IdGrp)
{
Element->Active=false;
Element->Open();
Element->Insert();
if (IdGrp!=0)
        {
		ElementGRPKL->AsInt64=IdGrp;
        Element->Post();
        }
}
//---------------------------------------------------------------------------

int TDMSprGrpKlient::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("ID")->AsInt64=Id;
Element->Active=true;


int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool  TDMSprGrpKlient::SaveElement()
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
			  	//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
		}
return result;
}
//---------------------------------------------------------------------------
void TDMSprGrpKlient::DeleteElement(__int64 Id)
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
				Error=true;
				TextError=exception.Message;
                }
        }
}
//-----------------------------------------------------------------
void __fastcall TDMSprGrpKlient::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------




