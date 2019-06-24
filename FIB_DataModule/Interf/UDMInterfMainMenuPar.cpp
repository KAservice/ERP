//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMInterfMainMenuPar.h"
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
__fastcall TDMInterfMainMenuPar::TDMInterfMainMenuPar(TComponent* Owner)
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
bool TDMInterfMainMenuPar::Init(void)
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
int TDMInterfMainMenuPar::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMInterfMainMenuPar::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMInterfMainMenuPar::OpenTable(__int64 id_owner)
{
IdOwner=id_owner;
Table->Active=false;
Table->ParamByName("PARAM_IDOWNER")->AsInt64=id_owner;
Table->Open();
}

//---------------------------------------------------------------------------
int TDMInterfMainMenuPar::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
bool  TDMInterfMainMenuPar::NewElement(__int64 id_owner)
{
IdOwner=id_owner;

bool result=true;

Element->Active=false;

Element->Open();
Element->Append();
if (id_owner!=0)
	{
	ElementIDMAINMENU_INTERF_MAINMENU_PAR->AsString=id_owner;
	}


return result;
}

//---------------------------------------------------------------------------
bool  TDMInterfMainMenuPar::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_INTERF_MAINMENU_PAR->AsString);

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
bool TDMInterfMainMenuPar::DeleteElement(__int64 id)
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




void __fastcall TDMInterfMainMenuPar::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDMAINMENU_INTERF_MAINMENU_PAR->AsString=IdOwner;


}
//---------------------------------------------------------------------------
bool TDMInterfMainMenuPar::SaveIsmen(void)
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdOwner);
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
bool TDMInterfMainMenuPar::CancelIsmen(void)
{
bool result=true;
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdOwner);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
return result;

}
//---------------------------------------------------------------------------
bool TDMInterfMainMenuPar::TableAppend(__int64 id_owner)
{
bool result=true;

Table->Append();
if (id_owner!=0)
	{
	TableIDMAINMENU_INTERF_MAINMENU_PAR->AsString=id_owner;
	}
return result;

}
//---------------------------------------------------------------------------
bool TDMInterfMainMenuPar::TableDelete(void)
{
bool result=true;
Table->Delete();
return result;

}
//---------------------------------------------------------------------------





