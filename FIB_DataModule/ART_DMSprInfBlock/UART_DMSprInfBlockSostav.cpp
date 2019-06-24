//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UART_DMSprInfBlockSostav.h"
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
__fastcall TART_DMSprInfBlockSostav::TART_DMSprInfBlockSostav(TComponent* Owner)
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
bool TART_DMSprInfBlockSostav::Init(void)
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
int TART_DMSprInfBlockSostav::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TART_DMSprInfBlockSostav::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TART_DMSprInfBlockSostav::OpenTable(__int64 id_ib)
{
IdIB=id_ib;
Table->Active=false;
Table->ParamByName("PARAM_ID_IB")->AsInt64=id_ib;
Table->Open();
}

//---------------------------------------------------------------------------
int TART_DMSprInfBlockSostav::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
bool  TART_DMSprInfBlockSostav::NewElement(__int64 id_ib)
{
IdIB=id_ib;

bool result=true;

Element->Active=false;

Element->Open();
Element->Append();
if (id_ib!=0)
	{
	ElementIDIB_ART_IB_S->AsString=id_ib;
	}


return result;
}

//---------------------------------------------------------------------------
bool  TART_DMSprInfBlockSostav::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_ART_IB_S->AsString);

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
bool TART_DMSprInfBlockSostav::DeleteElement(__int64 id)
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




void __fastcall TART_DMSprInfBlockSostav::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDIB_ART_IB_S->AsString=IdIB;


}
//---------------------------------------------------------------------------
bool TART_DMSprInfBlockSostav::SaveIsmen(void)
{
bool result=false;
try
		{
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdIB);
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
bool TART_DMSprInfBlockSostav::CancelIsmen(void)
{
bool result=true;
try
        {
		Table->CancelUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdIB);
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
bool TART_DMSprInfBlockSostav::TableAppend(__int64 id_ib)
{
bool result=true;

Table->Append();
if (id_ib!=0)
	{
	TableIDIB_ART_IB_S->AsString=id_ib;
	}
return result;

}
//---------------------------------------------------------------------------
bool TART_DMSprInfBlockSostav::TableDelete(void)
{
bool result=true;
Table->Delete();
return result;

}
//---------------------------------------------------------------------------





