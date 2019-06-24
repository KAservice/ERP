//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprVesNom.h"
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
__fastcall TDMSprVesNom::TDMSprVesNom(TComponent* Owner)
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
bool TDMSprVesNom::Init(void)
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
MaxCode->Database=DM_Connection->pFIBData;
SpTPrice->Database=DM_Connection->pFIBData;

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
int TDMSprVesNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprVesNom::DataModuleDestroy(TObject *Sender)
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

void  TDMSprVesNom::OpenTable(__int64 id_scale, __int64 id_grp, __int64 id_type_price, bool all)
{

NumberAddElement=0;
IdScale=id_scale;
IdGrp=id_grp;
IdTypePrice=id_type_price;
AllElement=all;
Table->Active=false;
Table->SelectSQL->Clear();
if(all==true)
        {
		Table->SelectSQL->Add(" select SVESNOM.*, NAMENOM, NAMEED, ZNACH_PRICE");
		Table->SelectSQL->Add(" from SVESNOM");
		Table->SelectSQL->Add(" left outer join SNOM on IDNOM_SVESNOM=IDNOM ");
		Table->SelectSQL->Add(" left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM ");
		Table->SelectSQL->Add("    and IDTYPE_PRICE="+IntToStr(id_type_price));
		Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
		Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
		Table->SelectSQL->Add(" where IDSCALE_SVESNOM="+IntToStr(id_scale));
		Table->SelectSQL->Add(" ORDER BY NAMENOM");
		}
else
        {
		if (id_grp==0)
                {
				Table->SelectSQL->Add(" select SVESNOM.*, NAMENOM, NAMEED, ZNACH_PRICE");
				Table->SelectSQL->Add(" from SVESNOM");
				Table->SelectSQL->Add(" left outer join SNOM on IDNOM_SVESNOM=IDNOM ");
				Table->SelectSQL->Add(" left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM ");
				Table->SelectSQL->Add("    and IDTYPE_PRICE="+IntToStr(id_type_price));
				Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
				Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
				Table->SelectSQL->Add(" where IDSCALE_SVESNOM="+IntToStr(id_scale));
				Table->SelectSQL->Add("    and IDGRP_SVESNOM is null");
				Table->SelectSQL->Add(" ORDER BY NAMENOM");
                }
        else
                {
				Table->SelectSQL->Add(" select SVESNOM.*, NAMENOM, NAMEED, ZNACH_PRICE");
				Table->SelectSQL->Add(" from SVESNOM");
				Table->SelectSQL->Add(" left outer join SNOM on IDNOM_SVESNOM=IDNOM ");
				Table->SelectSQL->Add(" left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM ");
				Table->SelectSQL->Add("    and IDTYPE_PRICE="+IntToStr(id_type_price));
				Table->SelectSQL->Add(" and IDED_SPRICE=IDBASEDNOM");
				Table->SelectSQL->Add(" left outer join SED on  IDBASEDNOM=IDED");
				Table->SelectSQL->Add(" where IDSCALE_SVESNOM="+IntToStr(id_scale));
				Table->SelectSQL->Add("    and IDGRP_SVESNOM="+IntToStr(id_grp));
				Table->SelectSQL->Add(" ORDER BY NAMENOM");
                }
        }

Table->Open();
}

//---------------------------------------------------------------------------

bool  TDMSprVesNom::SaveIsmen()
{
bool result=false;
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable(IdScale, IdGrp, IdTypePrice, AllElement);
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

void  TDMSprVesNom::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
        IBTrUpdate->Commit();
        OpenTable(IdScale, IdGrp, IdTypePrice,AllElement);
        }
        catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------
void  TDMSprVesNom::NewElement(__int64 id_scale, __int64 id_grp)
{
IdScale=id_scale;
IdGrp=id_grp;
Table->Append();

}
//----------------------------------------------------------------------------
bool TDMSprVesNom::OpenElement(__int64 id)
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
void TDMSprVesNom::DeleteElement()
{
Table->Delete();
}
//-----------------------------------------------------------------------------

__int64 TDMSprVesNom::FindElementPoScaleAndNom(__int64 id_scale, __int64 id_nom)
{
__int64 result=0;

TpFIBQuery * query=new TpFIBQuery(0);
query->Database=DM_Connection->pFIBData;
query->Transaction=IBTr;
query->SQL->Add("select ID_SVESNOM from SVESNOM where IDSCALE_SVESNOM=:PARAM_IDSCALE");
query->SQL->Add(" and IDNOM_SVESNOM=:PARAM_IDNOM");
query->ParamByName("PARAM_IDSCALE")->AsInt64=id_scale;
query->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
if (IBTr->Active==false) IBTr->StartTransaction();
query->ExecQuery();

result=query->FieldByName("ID_SVESNOM")->AsInt64;
delete query;
return result;
}
//-----------------------------------------------------------------------------------
bool TDMSprVesNom::InsertElement(__int64 id_scale, __int64 id_grp, __int64 id_nom)
{
bool result=false;
try
        {
		IdScale=id_scale;
		IdGrp=id_grp;
        Table->Active=true;
        Table->Insert();
		TableIDNOM_SVESNOM->AsInt64=id_nom;
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		Table->Active=false;
		result=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				result=false;
				}
return result;
}
//----------------------------------------------------------------------------
void __fastcall TDMSprVesNom::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprVesNom::TableNewRecord(TDataSet *DataSet)
{
TableIDSCALE_SVESNOM->AsInt64=IdScale;
TableIDGRP_SVESNOM->AsInt64=IdGrp;

MaxCode->Active=false;
MaxCode->ParamByName("PARAM_IDSCALE")->AsInt64=IdScale;
MaxCode->Active=true;
TableCODE_SVESNOM->AsInteger=MaxCodeMAXCODE->AsInteger+1+NumberAddElement;
MaxCode->Active=false;
NumberAddElement++;

}
//---------------------------------------------------------------------------
void TDMSprVesNom::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_SVESNOM->AsInt64=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(IdScale, IdGrp, IdTypePrice, AllElement);
}
//-----------------------------------------------------------------------------
