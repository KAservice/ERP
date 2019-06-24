//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprProducerNom.h"
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
__fastcall TDMSprProducerNom::TDMSprProducerNom(TComponent* Owner)
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
bool TDMSprProducerNom::Init(void)
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
SpTPrice->Database=DM_Connection->pFIBData;


pFIBQuery->Database=DM_Connection->pFIBData;
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
int TDMSprProducerNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprProducerNom::DataModuleDestroy(TObject *Sender)
{
SpTPrice->Active=false;
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprProducerNom::OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all,
												UnicodeString in_str, int fl_poisk)
{
IdProducer=id_producer;
IdGrp=id_grp;
IdProducerTypePrice=id_producer_type_price;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();

		UnicodeString zapros="select  * from SPRNOM_GET_LIST              \
		(:PARAM_IDUSER, :PARAM_IDGRP, :PARAM_ALL,:PARAM_IDPRODUCER,:PARAM_IDTYPE_PRICE, \
		:PARAM_STR,:PARAM_FL_POISK) ";
		Table->SelectSQL->Add(zapros);

		Table->ParamByName("PARAM_IDUSER")->AsInt64=0;
		Table->ParamByName("PARAM_IDGRP")->AsInt64=id_grp;
		Table->ParamByName("PARAM_ALL")->AsInteger=all;
		Table->ParamByName("PARAM_IDPRODUCER")->AsInt64=id_producer;
		Table->ParamByName("PARAM_IDTYPE_PRICE")->AsInt64=id_producer_type_price;
		Table->ParamByName("PARAM_STR")->AsString=in_str;
		Table->ParamByName("PARAM_FL_POISK")->AsInteger=fl_poisk;

Table->Open();
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool  TDMSprProducerNom::NewElement(__int64 id_producer, __int64 id_grp)
{
bool result=true;
IdProducer=id_producer;
IdGrp=id_grp;
Element->Active=true;
Element->Append();
ElementIDPROD_SPRNOM->AsString=id_producer;

if (id_grp!=0)
	{
    ElementIDGRP_SPRNOM->AsString=id_grp;
	}
return result;
}
//----------------------------------------------------------------------------
bool TDMSprProducerNom::OpenElement(__int64 id)
{
bool result=false;
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        result=true;
        }
return result;
}
//---------------------------------------------------------------------------
bool TDMSprProducerNom::DeleteElement(__int64 id)
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
void __fastcall TDMSprProducerNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void TDMSprProducerNom::ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom)
{
OpenElement(id_producer_nom);
Element->Edit();
ElementIDGRP_SPRNOM->AsString=id_new_grp;
Element->Post();
SaveElement();
}
//-----------------------------------------------------------------------------

bool  TDMSprProducerNom::SaveElement(void)
{
bool result;
__int64 id=glStrToInt64(ElementID_SPRNOM->AsString);
try
        {
		Element->ApplyUpdToBase();
		IBTrUpdate->Commit();
		Element->CommitUpdToCach();
		OpenElement(id);
		result=true;
        }
catch(Exception &exception)
        {
		IBTrUpdate->Rollback();
		TextError=exception.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------
__int64 TDMSprProducerNom::FindPoName(__int64 id_producer, UnicodeString model,UnicodeString name)
{
__int64 result=0;
//pFIBQuery->Close();
//pFIBQuery->SQL->Clear();
//pFIBQuery->SQL->Add("select IDNOM from SNOM where NAMENOM=:PARAM_NAME");
//pFIBQuery->ParamByName("PARAM_NAME")->AsString=name;
//pFIBQuery->ExecQuery();
//result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
//pFIBQuery->Close();
return result;


}
//---------------------------------------------------------------------------
__int64 TDMSprProducerNom::FindPoArtikulu(__int64 id_producer, UnicodeString model,UnicodeString artikul)
{
__int64 result=0;
pFIBQuery->Close();
pFIBQuery->SQL->Clear();
if (Trim(model) == "")
	{
	pFIBQuery->SQL->Add("select sprnom.id_sprnom from sprnom where sprnom.idprod_sprnom=:PARAM_IDPRODUCER and sprnom.art_sprnom=:PARAM_ART");
	}
else
	{
	pFIBQuery->SQL->Add("select sprnom.id_sprnom from sprnom where sprnom.idprod_sprnom=:PARAM_IDPRODUCER and sprnom.art_sprnom=:PARAM_ART and sprnom.model_str_sprnom=:PARAM_MODEL");
    pFIBQuery->ParamByName("PARAM_MODEL")->AsString=model;
	}
pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
pFIBQuery->ParamByName("PARAM_IDPRODUCER")->AsString=id_producer;
pFIBQuery->ExecQuery();
result=pFIBQuery->FieldByName("id_sprnom")->AsInt64;
pFIBQuery->Close();
return result;

}
//---------------------------------------------------------------------------
__int64 TDMSprProducerNom::FindPoCodu(__int64 id_producer, UnicodeString model,int Code)
{
__int64 result=0;
//pFIBQuery->Close();
//pFIBQuery->SQL->Clear();
//pFIBQuery->SQL->Add("select IDNOM from SNOM where ARTNOM=:PARAM_ART");
//pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
//pFIBQuery->ExecQuery();
//result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
//pFIBQuery->Close();
return result;

}
//---------------------------------------------------------------------------
__int64 TDMSprProducerNom::FindPoShtrihCodu(__int64 id_producer, UnicodeString model,UnicodeString shtrih_cod)
{
__int64 result=0;
//pFIBQuery->Close();
//pFIBQuery->SQL->Clear();
//pFIBQuery->SQL->Add("select IDNOM from SNOM where ARTNOM=:PARAM_ART");
//pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
//pFIBQuery->ExecQuery();
//result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
//pFIBQuery->Close();
return result;

}
//---------------------------------------------------------------------------
__int64 TDMSprProducerNom::GetIdGrpNom(__int64 id_nom)
{
__int64 result=0;
//pFIBQuery->Close();
//pFIBQuery->SQL->Clear();
//pFIBQuery->SQL->Add("select IDNOM from SNOM where ARTNOM=:PARAM_ART");
//pFIBQuery->ParamByName("PARAM_ART")->AsString=artikul;
//pFIBQuery->ExecQuery();
//result=pFIBQuery->FieldByName("IDNOM")->AsInt64;
//pFIBQuery->Close();
return result;

}
//---------------------------------------------------------------------------
