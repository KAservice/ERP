//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprProducerPrice.h"
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
__fastcall TDMSprProducerPrice::TDMSprProducerPrice(TComponent* Owner)
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
bool TDMSprProducerPrice::Init(void)
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
TPrice->Database=DM_Connection->pFIBData;


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
int TDMSprProducerPrice::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProducerPrice::DataModuleDestroy(TObject *Sender)
{

Table->Active=false;
Element->Close();
TPrice->Close();
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMSprProducerPrice::OpenTable(__int64 id_producer_nom)
{
IdProducerNom=id_producer_nom;

Table->Active=false;
Table->ParamByName("PARAM_IDPRNOM")->AsInt64=IdProducerNom;
Table->Active=true;


}
//----------------------------------------------------------------------------
bool TDMSprProducerPrice::SaveIsmen(void)
{
bool result=false;
if (Table->Active==true )
	{
	try
        {
		Table->ApplyUpdates();
		if (IBTrUpdate->Active==true)
			{
			IBTrUpdate->Commit();
			}
		OpenTable(IdProducerNom);
		result=true;
        }
	catch(Exception &exception)
		{
		result=false;
				TextError=exception.Message;
		}
	}
return result;
}
//----------------------------------------------------------------------------

void  TDMSprProducerPrice::NewElement()
{
Element->Active=false;
Element->Open();
Element->Append();
}
//---------------------------------------------------------------------------

int TDMSprProducerPrice::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

bool TDMSprProducerPrice::SaveElement()
{
bool result=false;

__int64 Id=glStrToInt64(ElementID_SPRPRICE->AsString);
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenElement(Id);
		result=true;
        }
catch(Exception &exception)
		{
				TextError=exception.Message;
				result=false;
		}
		
return result;
}
//----------------------------------------------------------------------------
void TDMSprProducerPrice::CancelIsmen(void)
{
Table->CancelUpdates();

}
//---------------------------------------------------------------------------
bool TDMSprProducerPrice::DeleteElement(__int64 id)
{
bool result=false;
OpenElement(id);
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
//---------------------------------------------------------------------------
__int64 TDMSprProducerPrice::FindElement(__int64 id_producer_type_price, __int64 id_producer_nom)
{
__int64 result=0;
pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select sprprice.id_sprprice from sprprice ");
		pFIBQ->SQL->Add(" where sprprice.idprnom_sprprice=:PARAM_IDPRNOM and sprprice.idprtprice_sprprice=:PARAM_IDTYPE ");
		pFIBQ->ParamByName("PARAM_IDPRNOM")->AsInt64=id_producer_type_price;
		pFIBQ->ParamByName("PARAM_IDTYPE")->AsInt64=id_producer_nom;
		pFIBQ->ExecQuery();
		result=pFIBQ->RecordCount;
		OpenElement(pFIBQ->FieldByName("id_sprprice")->AsInt64);
pFIBQ->Close();
return result;
}
//---------------------------------------------------------------------------

void __fastcall TDMSprProducerPrice::TableNewRecord(TDataSet *DataSet)
{
TableIDPRNOM_SPRPRICE->AsString=IdProducerNom;

}
//---------------------------------------------------------------------------

void __fastcall TDMSprProducerPrice::ElementNewRecord(TDataSet *DataSet)
{
ElementIDPRNOM_SPRPRICE->AsInt64=IdProducerNom;
ElementIDPRTPRICE_SPRPRICE->AsInt64=IdProducerTypePrice;

}
//---------------------------------------------------------------------------







