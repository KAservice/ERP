//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDMSprNomInetCatalog.h"
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
__fastcall TDMSprNomInetCatalog::TDMSprNomInetCatalog(TComponent* Owner)
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
bool TDMSprNomInetCatalog::Init(void)
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

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TDMSprNomInetCatalog::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSprNomInetCatalog::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSprNomInetCatalog::OpenTable(__int64 id_inet_catalog, __int64 id_grp, bool all)
{

IdInetCatalog=id_inet_catalog;
IdGrp=id_grp;
AllElement=all;


Table->Active=false;
Table->SelectSQL->Clear();

UnicodeString zapros="";

if(all==true)
		{
		 zapros="select snominetcat.*,        \
					snom.namenom,      \
					snom.codenom,      \
					snom.artnom,       \
					sprice.znach_price,\
					sed.nameed,         \
					sed.shed                                                                \
			from snominetcat                                                               \
			left outer join SNOM on snom.idnom=snominetcat.idnom_snominetcat               \
			left outer join SPRICE on sprice.idnom_price=snominetcat.idnom_snominetcat    \
							and sprice.idtype_price=:PARAM_IDTYPE_PRICE                   \
			left outer join SED on  snom.idbasednom=sed.ided                              \
			where                                                                         \
					snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG            \
			order by snom.namenom  ";



        }
else
        {
        if (IdGrp==0)
                {
		 zapros="select snominetcat.*,        \
					snom.namenom,      \
					snom.codenom,      \
					snom.artnom,       \
					sprice.znach_price, \
					sed.nameed,         \
					sed.shed                                                                    \
			from snominetcat                                                               \
			left outer join SNOM on snom.idnom=snominetcat.idnom_snominetcat               \
			left outer join SPRICE on sprice.idnom_price=snominetcat.idnom_snominetcat    \
							and sprice.idtype_price=:PARAM_IDTYPE_PRICE                   \
			left outer join SED on  snom.idbasednom=sed.ided                              \
			where                                                                         \
					snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG  AND           \
					snominetcat.idgrp_snominetcat is null                                 \
			order by snom.namenom  ";


                }
        else
                {
		 zapros="select snominetcat.*,        \
					snom.namenom,      \
					snom.codenom,      \
					snom.artnom,       \
					sprice.znach_price,\
					sed.nameed,         \
					sed.shed                                                                    \
			from snominetcat                                                               \
			left outer join SNOM on snom.idnom=snominetcat.idnom_snominetcat               \
			left outer join SPRICE on sprice.idnom_price=snominetcat.idnom_snominetcat    \
							and sprice.idtype_price=:PARAM_IDTYPE_PRICE                   \
			left outer join SED on  snom.idbasednom=sed.ided                              \
			where                                                                         \
					snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG  AND           \
					snominetcat.idgrp_snominetcat=' ";
			zapros=zapros+IntToStr(id_grp)+"' ";
			zapros=zapros+"order by snom.namenom  ";
                }
		}
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_IDTYPE_PRICE")->AsString=IdTypePrice;
Table->ParamByName("PARAM_IDINETCATALOG")->AsString=id_inet_catalog;
Table->Open();
}
//---------------------------------------------------------------------------

void  TDMSprNomInetCatalog::NewElement(__int64 id_inet_catalog, __int64 id_grp)
{
IdInetCatalog=id_inet_catalog;
IdGrp=id_grp;
Table->Append();
}
//---------------------------------------------------------------------------
void TDMSprNomInetCatalog::InsertElement(__int64 id_inet_catalog, __int64 id_grp, __int64 id_nom)
{

try
        {
		IdInetCatalog=id_inet_catalog;
		IdGrp=id_grp;
        Table->Active=true;
		Table->Append();
		TableIDNOM_SNOMINETCAT->AsString=id_nom;
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        Table->Active=false;
        }
catch(Exception &exception)
		{
		Table->CancelUpdates();
		IBTrUpdate->Rollback();
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------
void  TDMSprNomInetCatalog::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
		OpenTable(IdInetCatalog,IdGrp,AllElement);
        }
catch(Exception &exception)
        {
		Error=true;
		TextError=exception.Message;
        }
}
//---------------------------------------------------------------------------

void  TDMSprNomInetCatalog::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
	   // IBTrUpdate->Commit();
		OpenTable(IdInetCatalog,IdGrp,AllElement);
        }
catch(Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		}
}
//---------------------------------------------------------------------------
void TDMSprNomInetCatalog::DeleteElement()
{
Table->Delete();
}
//----------------------------------------------------------------------------
void TDMSprNomInetCatalog::ChancheGrp(__int64 id_new_grp)
{
Table->Edit();
TableIDGRP_SNOMINETCAT->AsString=id_new_grp;
Table->Post();
SaveIsmen();
OpenTable(IdInetCatalog,IdGrp,AllElement);
}

//----------------------------------------------------------------------------
bool TDMSprNomInetCatalog::OpenElement(__int64 id)
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
//----------------------------------------------------------------------------
bool TDMSprNomInetCatalog::FindPoInetCatalogAndNom(__int64 id_inet_catalog, __int64 id_nom)
{
bool result=false;

TpFIBQuery * query=new TpFIBQuery(0);
try {  
		query->Database=DM_Connection->pFIBData;
		query->Transaction=IBTr;
		query->SQL->Add(" select snominetcat.id_snominetcat ");
		query->SQL->Add(" from snominetcat ");
		query->SQL->Add(" where snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG ");
		query->SQL->Add(" and snominetcat.idnom_snominetcat=:PARAM_IDNOM ");
		query->ParamByName("PARAM_IDINETCATALOG")->AsInt64=id_inet_catalog;
		query->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
		if (IBTr->Active==false) IBTr->StartTransaction();
		query->ExecQuery();
		if(OpenElement(query->FieldByName("id_snominetcat")->AsInt64)==true)
			{
			result=true;
			}
	}
__finally
	{
	delete query;
	}
return result;
}
//-----------------------------------------------------------------------------
void __fastcall TDMSprNomInetCatalog::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;   	
}
//---------------------------------------------------------------------------

void __fastcall TDMSprNomInetCatalog::TableNewRecord(TDataSet *DataSet)
{
TableIDINETCAT_SNOMINETCAT->AsString=IdInetCatalog;
TableIDGRP_SNOMINETCAT->AsString=IdGrp;

}
//---------------------------------------------------------------------------
bool  TDMSprNomInetCatalog::SaveElement()
{
bool res=false;
__int64 id=glStrToInt64(ElementID_SNOMINETCAT->AsString);

try
        {
		Element->ApplyUpdates();
		IBTrUpdate->Commit();

        OpenElement(id);
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
bool TDMSprNomInetCatalog::DeleteElement(__int64 id)
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
