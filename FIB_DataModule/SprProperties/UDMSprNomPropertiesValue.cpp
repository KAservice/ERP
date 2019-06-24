//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNomPropertiesValue.h"
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
__fastcall TDMSprNomPropertiesValue::TDMSprNomPropertiesValue(TComponent* Owner)
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
bool TDMSprNomPropertiesValue::Init(void)
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
Query->Database=DM_Connection->pFIBData;


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
int TDMSprNomPropertiesValue::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomPropertiesValue::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprNomPropertiesValue::OpenTable(__int64 id_nom)
{
IdNom=id_nom;
Table->Active=false;
Table->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
Table->Open();
}

//---------------------------------------------------------------------------
int TDMSprNomPropertiesValue::OpenElement(__int64 id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;

int Res=0;
Res=Element->RecordCount;
return Res;
}

//----------------------------------------------------------------------------
bool  TDMSprNomPropertiesValue::NewElement(__int64 id_nom)
{
IdNom=id_nom;

bool result=true;

Element->Active=false;

Element->Open();
Element->Append();
if (id_nom!=0)
	{
	ElementIDNOM_SNOMPROPVALUE->AsString=id_nom;
	}


return result;
}

//---------------------------------------------------------------------------
bool  TDMSprNomPropertiesValue::SaveElement()
{
bool res=false;
IdElement=glStrToInt64(ElementID_SNOMPROPVALUE->AsString);

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
bool TDMSprNomPropertiesValue::DeleteElement(__int64 id)
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




void __fastcall TDMSprNomPropertiesValue::TableNewRecord(TDataSet *DataSet)
{
//TableIDNOM_SPROD->AsInteger=IdNom;
TableIDNOM_SNOMPROPVALUE->AsString=IdNom;


}
//---------------------------------------------------------------------------
__int64 TDMSprNomPropertiesValue::GetIdPoIdNomIdProp(__int64 id_nom, __int64 id_prop)
{
__int64 result=0;

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select snompropvalue.id_snompropvalue  \
						from snompropvalue                                       \
						where snompropvalue.idnom_snompropvalue=:PARAM_IDNOM and \
						snompropvalue.idprop_snompropvalue=:PARAM_IDPROP");
Query->ParamByName("PARAM_IDNOM")->AsString=id_nom;
Query->ParamByName("PARAM_IDPROP")->AsString=id_prop;
Query->ExecQuery();

result=glStrToInt64(Query->FieldByName("id_snompropvalue")->AsString);

Query->Close();

return result;
}
//----------------------------------------------------------------------------





